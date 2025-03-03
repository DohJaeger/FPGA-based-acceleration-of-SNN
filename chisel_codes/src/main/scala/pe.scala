import chisel3._
import chisel3.util._
import chisel3.util.Decoupled
import java.io.{File, PrintWriter, BufferedWriter, FileWriter}

import PE_IO_Defs._
import PE_IO_Defs.NetworkUtils

class BoundaryCheck(dim_width: Int, aeq_width: Int) extends Module {
  val io = IO(new Bundle {
    val i = Input(UInt(((aeq_width - 2)/2).W))
    val se_blk = Input(UInt(dim_width.W))
    val se_col = Input(UInt(dim_width.W))
    val se_col1 = Input(UInt(dim_width.W))
    val col = Input(UInt(4.W))
    val isNorth = Output(Bool())
    val isSouth = Output(Bool())
    val isNorth1 = Output(Bool())
    val isSouth1 = Output(Bool())
  })

  val p1 = (col(2) & col(1)) | col(3)
  val p0 = (~col(2) & col(1) & col(0)) | (col(2) & ~col(1))
  val new_col = Cat(0.U(2.W), p1, p0)

  io.isNorth := (io.i === 0.U)
  io.isSouth := (io.i === io.se_blk) && (new_col === io.se_col)
  io.isNorth1 := (io.i === 0.U)
  io.isSouth1 := (io.i === io.se_blk) && (new_col === io.se_col1)
}

class pe(kernel5: Bool, kernel7: Bool, max_local_rows: Int, num_col: Int, mempot_width: Int, mempot_depth: Int, aeq_width: Int, aeq_depth: Int, kernel_width: Int, num_interlac: Int, bias_width: Int, dim_width: Int) extends Module {
    val io = IO(new Bundle {
        val pe_io = new PE_IO(num_col, aeq_depth, aeq_width, mempot_depth, mempot_width, bias_width, kernel_width, dim_width)
    })
    
    NetworkUtils.initNetworkIO(io.pe_io, num_col)

    io.pe_io.conv_done := conv_done_reg
    io.pe_io.thresh_done := thresh_done_reg
    
    val conv_done_reg = RegInit(false.B)
    val thresh_done_reg = RegInit(false.B)

    val tot_hor_blk = (io.pe_io.N - 1)/3
    val se_blk = (io.pe_io.T - 1) / 3   //south edge blk detect
    val se_col = (io.pe_io.T - 1) % 3     //south edge col detect
    val se_col1 = (io.pe_io.T - 2) % 3     //south edge col detect

    val local_mem_row_bits = log2Ceil(max_local_rows + 1)   // used in the addr calc
    val kernel_radius = (io.pe_io.kSize - 1.U) >> 1
    val num_blocks_per_spike = MuxLookup(io.pe_io.kSize, 0.U(5.W))(Seq( 3.U -> 1.U(5.W), 5.U -> 4.U(5.W), 7.U -> 9.U(5.W)))

    val pipe_stall = false.B

    // --- Stage 0: Read AEQ ---
    val aeq_read_col_sel_counter = RegInit(0.U(log2Ceil(9).W))
    val aeq_read_addr = RegInit(0.U(log2Ceil(aeq_depth).W))

    val spike_event = RegInit(0.U((aeq_width).W))
    val spike_event_s1 = RegNext(RegNext(chiselTypeOf(spike_event)))
    spike_event_s1 := spike_event

    val spike_valid = RegInit(false.B)

    val eoq_bit = spike_event(aeq_width - 1)

    io.pe_io.aeq_portA_rdaddr.valid := !pipe_stall && !((aeq_read_col_sel_counter === 8.U) && eoq_bit)
    io.pe_io.aeq_portA_rdaddr.bits := aeq_read_addr
    io.pe_io.aeq_portA_rddata.ready := !pipe_stall && !((aeq_read_col_sel_counter === 8.U) && eoq_bit)

    when(io.pe_io.aeq_portA_rdaddr.fire && io.pe_io.aeq_portA_rddata.fire) {
        spike_event := io.pe_io.aeq_portA_rddata.bits
        spike_valid := true.B

        when(block_counter === (num_blocks_per_spike - 1).U || eoq_bit) {
            aeq_read_addr := aeq_read_addr + 1.U
        }

        when(aeq_read_col_sel_counter === 8.U && eoq_bit) {
            aeq_read_col_sel_counter := 0.U
        }.otherwise {
            aeq_read_col_sel_counter := aeq_read_col_sel_counter + 1.U
        }

    }.otherwise {
        spike_valid := false.B
    }

    
    // --- stage - 0.5: calculate the reference addresses
    val i = (spike_event(aeq_width - 2, aeq_width / 2)).asUInt
    val j = (spike_event(aeq_width / 2 - 1, 1)).asUInt
    val Cs = aeq_col_select_counter

    val Cs_s1 = RegNext(Cs)

    val boundaryCheck = Module(new BoundaryCheck(i, se_blk, se_col, se_col1, col, aeq_width, dim_width))
    val isNorth = boundaryCheck.io.north
    val isSouth = boundaryCheck.io.south
    val isNorth1 = boundaryCheck.io.north1
    val isSouth1 = boundaryCheck.io.south1
    val isNorth2 = boundaryCheck.io.north2
    val isSouth2 = boundaryCheck.io.south2

    val ref_pixel = Wire(Vec(9, UInt((4 + aeq_width - 2).W))) // col + i_new + j_new
    val ref_pixel_s1 = RegNext(ref_pixel)

    val col_map_7 = VecInit(Seq(
        VecInit(4.U, 3.U, 5.U, 1.U, 0.U, 2.U, 7.U, 6.U, 8.U),
        VecInit(5.U, 4.U, 3.U, 2.U, 1.U, 0.U, 8.U, 7.U, 6.U),
        VecInit(3.U, 5.U, 4.U, 0.U, 2.U, 1.U, 6.U, 8.U, 7.U),

        VecInit(7.U, 6.U, 8.U, 4.U, 3.U, 5.U, 1.U, 0.U, 2.U),
        VecInit(8.U, 7.U, 6.U, 5.U, 4.U, 3.U, 2.U, 1.U, 0.U),
        VecInit(6.U, 8.U, 7.U, 3.U, 5.U, 4.U, 0.U, 2.U, 1.U),

        VecInit(1.U, 0.U, 2.U, 7.U, 6.U, 8.U, 4.U, 3.U, 5.U),
        VecInit(2.U, 1.U, 0.U, 8.U, 7.U, 6.U, 5.U, 4.U, 3.U),
        VecInit(0.U, 2.U, 1.U, 6.U, 8.U, 7.U, 3.U, 5.U, 4.U)
    ))

    val col_map_5 = VecInit(Seq(
        VecInit(8.U, 7.U, 5.U, 4.U),    // 0
        VecInit(6.U, 8.U, 3.U, 5.U),    // 1
        VecInit(7.U, 6.U, 4.U, 3.U),    // 2

        VecInit(2.U, 1.U, 8.U, 7.U),    // 3
        VecInit(0.U, 2.U, 6.U, 8.U),    // 4
        VecInit(1.U, 0.U, 7.U, 6.U),    // 5

        VecInit(5.U, 4.U, 2.U, 1.U),    // 6
        VecInit(3.U, 5.U, 0.U, 2.U),    // 7
        VecInit(4.U, 3.U, 1.U, 0.U)     // 8
    ))

    val offset_7 = VecInit(Seq(
        VecInit((-1.S, -1.S), (-1.S, 0.S), (-1.S, 1.S), (0.S, -1.S), (0.S, 0.S), (0.S, 1.S), (1.S, -1.S), (1.S, 0.S), (1.S, 1.S)),  // 0
        VecInit((-1.S, -1.S), (-1.S, 0.S), (-1.S, 1.S), (0.S, -1.S), (0.S, 0.S), (0.S, 1.S), (1.S, -1.S), (1.S, 0.S), (1.S, 1.S)),  // 1
        VecInit((-1.S,  0.S), (-1.S, 1.S), (-1.S, 2.S), (0.S,  0.S), (0.S, 1.S), (0.S, 2.S), (1.S,  0.S), (1.S, 1.S), (1.S, 2.S)),  // 2
        VecInit((-1.S, -1.S), (-1.S, 0.S), (-1.S, 1.S), (0.S, -1.S), (0.S, 0.S), (0.S, 1.S), (1.S, -1.S), (1.S, 0.S), (1.S, 1.S)),  // 3
        VecInit((-1.S, -1.S), (-1.S, 0.S), (-1.S, 1.S), (0.S, -1.S), (0.S, 0.S), (0.S, 1.S), (1.S, -1.S), (1.S, 0.S), (1.S, 1.S)),  // 4
        VecInit((-1.S,  0.S), (-1.S, 1.S), (-1.S, 2.S), (0.S,  0.S), (0.S, 1.S), (0.S, 2.S), (1.S,  0.S), (1.S, 1.S), (1.S, 2.S)),  // 5
        VecInit(( 0.S, -1.S), ( 0.S, 0.S), ( 0.S, 1.S), (1.S, -1.S), (1.S, 0.S), (1.S, 1.S), (2.S, -1.S), (2.S, 0.S), (2.S, 1.S)),  // 6
        VecInit(( 0.S, -1.S), ( 0.S, 0.S), ( 0.S, 1.S), (1.S, -1.S), (1.S, 0.S), (1.S, 1.S), (2.S, -1.S), (2.S, 0.S), (2.S, 1.S)),  // 7
        VecInit(( 0.S,  0.S), ( 0.S, 1.S), ( 0.S, 2.S), (1.S,  0.S), (1.S, 1.S), (1.S, 2.S), (2.S,  0.S), (2.S, 1.S), (2.S, 2.S))   // 8
    ))

    val offset_5 = VecInit(Seq(
        VecInit((-1.S, -1.S), (-1.S, 0.S), (0.S, -1.S), (0.S, 0.S)),  // 0
        VecInit((-1.S,  0.S), (-1.S, 1.S), (0.S,  0.S), (0.S, 1.S)),  // 1
        VecInit((-1.S,  0.S), (-1.S, 1.S), (0.S,  0.S), (0.S, 1.S)),  // 2
        VecInit(( 0.S, -1.S), ( 0.S, 0.S), (1.S, -1.S), (1.S, 0.S)),  // 3
        VecInit(( 0.S,  0.S), ( 0.S, 1.S), (1.S,  0.S), (1.S, 1.S)),  // 4
        VecInit(( 0.S,  0.S), ( 0.S, 1.S), (1.S,  0.S), (1.S, 1.S)),  // 5
        VecInit(( 1.S, -1.S), ( 0.S, 0.S), (1.S, -1.S), (1.S, 0.S)),  // 6
        VecInit(( 0.S,  0.S), ( 0.S, 1.S), (1.S,  0.S), (1.S, 1.S)),  // 7
        VecInit(( 0.S,  0.S), ( 0.S, 1.S), (1.S,  0.S), (1.S, 1.S))   // 8
    ))

    // 5x5 spike locations
    val ref_pixel_5x5 = Wire(Vec(4, UInt((3 + aeq_width / 2).W)))
    val isLocal5 = Wire(Vec(4, Bool()))
    val isLocal5_s1 = RegNext(isLocal5)
    val isMain5 = Wire(Vec(4, Bool()))
    val isMain5_s1 = RegNext(isMain5)
    val isEdge5 = Wire(Vec(4, Bool()))
    val isEdge5_s1 = RegNext(isEdge5)

    when(kernel5.B) {
        for (idx <- 0 until 4) {
            val (off_i, off_j) = offset_5(Cs)(idx)
            val i_new = (i.asSInt + off_i.S).asUInt
            val j_new = (j.asSInt + off_j.S).asUInt

            ref_pixel_5x5(idx) := Cat(col_map_5(Cs), i_new, j_new)

            isEdge5(idx) := (isNorth && off_i === -1.S) || (isSouth && off_i === 1.S)
            isLocal5(idx) := !isEdge5(idx) && (isNorth1 || isSouth1)
            isMain5(idx) := !isLocal5(idx)
        }
    }

    // 7x7 spike locations
    val ref_pixel_7x7 = Wire(Vec(9, UInt((3 + aeq_width / 2).W)))
    val isLocal7 = Wire(Vec(9, Bool()))
    val isLocal7_s1 = RegNext(isLocal7)
    val isMain7 = Wire(Vec(9, Bool()))
    val isMain7_s1 = RegNext(isMain7)
    val isEdge7 = Wire(Vec(9, Bool()))
    val isEdge7_s1 = RegNext(isEdge7)

    when(kernel7.B) {
        for (idx <- 0 until 9) {
            val (off_i, off_j) = offset_7(Cs)(idx)
            val i_new = (i.asSInt + off_i.S).asUInt
            val j_new = (j.asSInt + off_j.S).asUInt

            ref_pixel_7x7(idx) := Cat(col_map_7(Cs), i_new, j_new)

            isEdge7(idx) := (isNorth2 && off_i === -2.S) || (isSouth2 && off_i === 2.S)
            isLocal7(idx) := (isNorth1 || isSouth1) && !isEdge7(idx) // Within local memory
            isMain7(idx) := !isLocal7(idx) // Otherwise, in main memory
        }
    }

    
    when(io.PE_IO.kSize === 5.U) {
        ref_pixel := ref_pixel_5x5 ++ VecInit(Seq.fill(5)(0.U((3 + aeq_width / 2).W)))
    }.elsewhen(io.PE_IO.kSize === 7.U) {
        ref_pixel := ref_pixel_7x7
    }

    // --- stage - 1: calculate the neighbor address ---
    val s1_valid = Wire(Bool())
    val ref_pixel_s2 = Wire(Vec(9, UInt((aeq_width - 2).W)))

    val block_counter = RegInit(0.U(log2Ceil(num_blocks_per_spike).W))
    val block_counter_s2 = RegNext(block_counter)

    val compute_sub_block = Wire(Bool())

    when(block_counter === (num_blocks_per_spike - 1.U)) {
        block_counter := 0.U
    }.otherwise {
        block_counter := block_counter + 1.U
    }

    compute_sub_block := (block_counter < num_blocks_per_spike)

    // neighbour pixels' address calc
    val new_i = Wire(UInt((aeq_width/2 - 1).W))
    val new_j = Wire(UInt((aeq_width/2 - 1).W))
    val input_idx = Wire(UInt(4.W))
    val input_idx_s2 = RegNext(input_idx)

    val totalW_ref_pix = ref_pixel_s1(block_counter).getWidth
    when(io.PE_IO.kSize === 5.U || io.PE_IO.kSize === 7.U){
        input_idx := ref_pixel_s1(block_counter)(totalW_ref_pix - 1, totalW_ref_pix - 4)
        i_in := ref_pixel_s1(block_counter)(totalW_ref_pix - 5, totalW_ref_pix/2 - 2)
        j_in := ref_pixel_s1(block_counter)(totalW_ref_pix/2 - 3, 0)
    }.otherwise{
        input_idx := Cs_s1
        i_in := spike_event_s1(aeq_width - 2, aeq_width/2)
        j_in := ref_pixel_s1(aeq_width - 3, 1)
    }


    val boundaryCheck_s1 = Module(new BoundaryCheck(new_i, se_blk, se_col, se_col1, col, aeq_width, dim_width))
    val flagReg = RegInit(VecInit(Seq.fill(9)(0.U(3.W))))

    when(compute_sub_block && !pipe_stall) {
        for (col <- 0 until 9) {
            new_i := i_in
            new_j := j_in

            when(col === 0.U || col === 3.U || col === 6.U) {
                when(input_idx === 2.U || input_idx === 5.U || input_idx === 8.U) {
                    new_j := j_in + 1.U
                }
            }
            when(col === 2.U || col === 5.U || col === 8.U) {
                when(input_idx === 0.U || input_idx === 3.U || input_idx === 6.U) {
                    new_j := j_in - 1.U
                }
            }

            when(col === 0.U || col === 1.U || col === 2.U) {
                when(input_idx === 6.U || input_idx === 7.U || input_idx === 8.U) {
                    new_i := i_in + 1.U
                }
            }
            when(col === 6.U || col === 7.U || col === 8.U) {
                when(input_idx === 0.U || input_idx === 1.U || input_idx === 2.U) {
                    new_i := i_in - 1.U
                }
            }

            flagReg(col)(2) := boundaryCheck_s1.io.isNorth || boundaryCheck_s1.io.isSouth
            flagReg(col)(1) := boundaryCheck_s1.io.isNorth
            flagReg(col)(0) := 1.U
            ref_pixel_s2(col) := Cat(new_i, new_j)
        }
        s1_valid := true.B
    }

    
    // stage - 2: mempot read
    val validity_map5 = VecInit(Seq(
        // Validity map for blk1
        VecInit(Seq(
            VecInit(true.B, false.B, true.B, true.B, false.B, true.B, true.B, false.B, true.B), 
            VecInit(true.B, true.B, false.B, true.B, true.B, false.B, true.B, true.B, false.B),  
            VecInit(false.B, true.B, true.B, false.B, true.B, true.B, false.B, true.B, true.B), 
    
            VecInit(true.B, false.B, true.B, true.B, false.B, true.B, true.B, false.B, true.B),  
            VecInit(true.B, true.B, false.B, true.B, true.B, false.B, true.B, true.B, false.B),     
            VecInit(false.B, true.B, true.B, false.B, true.B, true.B, false.B, true.B, true.B),  
    
            VecInit(true.B, false.B, true.B, true.B, false.B, true.B, true.B, false.B, true.B),
            VecInit(true.B, true.B, false.B, true.B, true.B, false.B, true.B, true.B, false.B), 
            VecInit(false.B, true.B, true.B, false.B, true.B, true.B, false.B, true.B, true.B) 
        )),
        
        // Validity map for blk2
        VecInit(Seq(
            VecInit(true.B, true.B, true.B, true.B, true.B, true.B, false.B, false.B, false.B), 
            VecInit(true.B, true.B, true.B, true.B, true.B, true.B, false.B, false.B, false.B),  
            VecInit(true.B, true.B, true.B, true.B, true.B, true.B, false.B, false.B, false.B),  
    
            VecInit(false.B, false.B, false.B, true.B, true.B, true.B, true.B, true.B, true.B), 
            VecInit(false.B, false.B, false.B, true.B, true.B, true.B, true.B, true.B, true.B),     
            VecInit(false.B, false.B, false.B, true.B, true.B, true.B, true.B, true.B, true.B),    
    
            VecInit(true.B, true.B, true.B, false.B, false.B, false.B, true.B, true.B, true.B),  
            VecInit(true.B, true.B, true.B, false.B, false.B, false.B, true.B, true.B, true.B),   
            VecInit(true.B, true.B, true.B, false.B, false.B, false.B, true.B, true.B, true.B)  
        )),
        
        // Validity map for blk3
        VecInit(Seq(
            VecInit(true.B, true.B, false.B, true.B, true.B, false.B, false.B, false.B, false.B), 
            VecInit(false.B, true.B, true.B, false.B, true.B, true.B, false.B, false.B, false.B),  
            VecInit(true.B, false.B, true.B, true.B, false.B, true.B, false.B, false.B, false.B), 
    
            VecInit(false.B, false.B, false.B, true.B, true.B, false.B, true.B, true.B, false.B),  
            VecInit(false.B, false.B, false.B, false.B, true.B, true.B, false.B, true.B, true.B), 
            VecInit(false.B, false.B, false.B, true.B, false.B, true.B, true.B, false.B, true.B), 
                 
            VecInit(true.B, true.B, false.B, false.B, false.B, false.B, true.B, true.B, false.B), 
            VecInit(false.B, true.B, true.B, false.B, false.B, false.B, false.B, true.B, true.B), 
            VecInit(true.B, false.B, true.B, false.B, false.B, false.B, true.B, false.B, true.B)  
        ))
    ))

    val validity_map7 = VecInit(Seq(
        // Validity map for blk1
        VecInit(Seq(
            VecInit(true.B, false.B, false.B, true.B, false.B, false.B, true.B, false.B, false.B),  // 0
            VecInit(false.B, true.B, false.B, false.B, true.B, false.B, false.B, true.B, false.B),  // 1
            VecInit(false.B, false.B, true.B, false.B, false.B, true.B, false.B, false.B, true.B)   // 2

            VecInit(true.B, false.B, false.B, true.B, false.B, false.B, true.B, false.B, false.B),  // 3
            VecInit(false.B, true.B, false.B, false.B, true.B, false.B, false.B, true.B, false.B),  // 4
            VecInit(false.B, false.B, true.B, false.B, false.B, true.B, false.B, false.B, true.B)   // 5

            VecInit(true.B, false.B, false.B, true.B, false.B, false.B, true.B, false.B, false.B),  // 6
            VecInit(false.B, true.B, false.B, false.B, true.B, false.B, false.B, true.B, false.B),  // 7
            VecInit(false.B, false.B, true.B, false.B, false.B, true.B, false.B, false.B, true.B)   // 8
        )),
        
        // Validity map for blk3
        VecInit(Seq(
            VecInit(true.B, true.B, true.B, false.B, false.B, false.B, false.B, false.B, false.B), 
            VecInit(true.B, true.B, true.B, false.B, false.B, false.B, false.B, false.B, false.B),  
            VecInit(true.B, true.B, true.B, false.B, false.B, false.B, false.B, false.B, false.B), 

            VecInit(false.B, false.B, false.B, true.B, true.B, true.B, false.B, false.B, false.B), 
            VecInit(false.B, false.B, false.B, true.B, true.B, true.B, false.B, false.B, false.B),  
            VecInit(false.B, false.B, false.B, true.B, true.B, true.B, false.B, false.B, false.B),

            VecInit(false.B, false.B, false.B, false.B, false.B, false.B, true.B, true.B, true.B),  
            VecInit(false.B, false.B, false.B, false.B, false.B, false.B, true.B, true.B, true.B),
            VecInit(false.B, false.B, false.B, false.B, false.B, false.B, true.B, true.B, true.B)
        )),
        
        // Validity map for blk5
        VecInit(Seq(
            VecInit(true.B, true.B, true.B, false.B, false.B, false.B, false.B, false.B, false.B), 
            VecInit(true.B, true.B, true.B, false.B, false.B, false.B, false.B, false.B, false.B),  
            VecInit(true.B, true.B, true.B, false.B, false.B, false.B, false.B, false.B, false.B), 

            VecInit(false.B, false.B, false.B, true.B, true.B, true.B, false.B, false.B, false.B), 
            VecInit(false.B, false.B, false.B, true.B, true.B, true.B, false.B, false.B, false.B),  
            VecInit(false.B, false.B, false.B, true.B, true.B, true.B, false.B, false.B, false.B),

            VecInit(false.B, false.B, false.B, false.B, false.B, false.B, true.B, true.B, true.B),  
            VecInit(false.B, false.B, false.B, false.B, false.B, false.B, true.B, true.B, true.B),
            VecInit(false.B, false.B, false.B, false.B, false.B, false.B, true.B, true.B, true.B)
        )),
        
        // Validity map for blk7
        VecInit(Seq(
            VecInit(true.B, false.B, false.B, true.B, false.B, false.B, true.B, false.B, false.B),  // 0
            VecInit(false.B, true.B, false.B, false.B, true.B, false.B, false.B, true.B, false.B),  // 1
            VecInit(false.B, false.B, true.B, false.B, false.B, true.B, false.B, false.B, true.B)   // 2

            VecInit(true.B, false.B, false.B, true.B, false.B, false.B, true.B, false.B, false.B),  // 3
            VecInit(false.B, true.B, false.B, false.B, true.B, false.B, false.B, true.B, false.B),  // 4
            VecInit(false.B, false.B, true.B, false.B, false.B, true.B, false.B, false.B, true.B)   // 5

            VecInit(true.B, false.B, false.B, true.B, false.B, false.B, true.B, false.B, false.B),  // 6
            VecInit(false.B, true.B, false.B, false.B, true.B, false.B, false.B, true.B, false.B),  // 7
            VecInit(false.B, false.B, true.B, false.B, false.B, true.B, false.B, false.B, true.B)   // 8
        ))
    ))

    val kernel_s2 = Reg(Vec(9, UInt(kernel_width.W)))
        switch(input_idx_s2) {
            is(0.U) { kernel_s2 := VecInit( io.pe_io.rotated_kernel(4), io.pe_io.rotated_kernel(5), io.pe_io.rotated_kernel(3),
                                            io.pe_io.rotated_kernel(7), io.pe_io.rotated_kernel(8), io.pe_io.rotated_kernel(6),
                                            io.pe_io.rotated_kernel(1), io.pe_io.rotated_kernel(2), io.pe_io.rotated_kernel(0)) }

            is(1.U) { kernel_s2 := VecInit( io.pe_io.rotated_kernel(3), io.pe_io.rotated_kernel(4), io.pe_io.rotated_kernel(5),
                                            io.pe_io.rotated_kernel(6), io.pe_io.rotated_kernel(7), io.pe_io.rotated_kernel(8),
                                            io.pe_io.rotated_kernel(0), io.pe_io.rotated_kernel(1), io.pe_io.rotated_kernel(2)) }

            is(2.U) { kernel_s2 := VecInit( io.pe_io.rotated_kernel(5), io.pe_io.rotated_kernel(3), io.pe_io.rotated_kernel(4),
                                            io.pe_io.rotated_kernel(8), io.pe_io.rotated_kernel(6), io.pe_io.rotated_kernel(7),
                                            io.pe_io.rotated_kernel(2), io.pe_io.rotated_kernel(0), io.pe_io.rotated_kernel(1)) }

            is(3.U) { kernel_s2 := VecInit( io.pe_io.rotated_kernel(1), io.pe_io.rotated_kernel(2), io.pe_io.rotated_kernel(0),
                                            io.pe_io.rotated_kernel(4), io.pe_io.rotated_kernel(5), io.pe_io.rotated_kernel(3),
                                            io.pe_io.rotated_kernel(7), io.pe_io.rotated_kernel(8), io.pe_io.rotated_kernel(6)) }

            is(4.U) { kernel_s2 := VecInit( io.pe_io.rotated_kernel(0), io.pe_io.rotated_kernel(1), io.pe_io.rotated_kernel(2),
                                            io.pe_io.rotated_kernel(3), io.pe_io.rotated_kernel(4), io.pe_io.rotated_kernel(5),
                                            io.pe_io.rotated_kernel(6), io.pe_io.rotated_kernel(7), io.pe_io.rotated_kernel(8)) }

            is(5.U) { kernel_s2 := VecInit( io.pe_io.rotated_kernel(2), io.pe_io.rotated_kernel(0), io.pe_io.rotated_kernel(1),
                                            io.pe_io.rotated_kernel(5), io.pe_io.rotated_kernel(3), io.pe_io.rotated_kernel(4),
                                            io.pe_io.rotated_kernel(8), io.pe_io.rotated_kernel(6), io.pe_io.rotated_kernel(7)) }

            is(6.U) { kernel_s2 := VecInit( io.pe_io.rotated_kernel(7), io.pe_io.rotated_kernel(8), io.pe_io.rotated_kernel(6),
                                            io.pe_io.rotated_kernel(1), io.pe_io.rotated_kernel(2), io.pe_io.rotated_kernel(0),
                                            io.pe_io.rotated_kernel(4), io.pe_io.rotated_kernel(5), io.pe_io.rotated_kernel(3)) }

            is(7.U) { kernel_s2 := VecInit( io.pe_io.rotated_kernel(6), io.pe_io.rotated_kernel(7), io.pe_io.rotated_kernel(8),
                                            io.pe_io.rotated_kernel(0), io.pe_io.rotated_kernel(1), io.pe_io.rotated_kernel(2),
                                            io.pe_io.rotated_kernel(3), io.pe_io.rotated_kernel(4), io.pe_io.rotated_kernel(5)) }

            is(8.U) { kernel_s2 := VecInit( io.pe_io.rotated_kernel(8), io.pe_io.rotated_kernel(6), io.pe_io.rotated_kernel(7),
                                            io.pe_io.rotated_kernel(2), io.pe_io.rotated_kernel(0), io.pe_io.rotated_kernel(1),
                                            io.pe_io.rotated_kernel(5), io.pe_io.rotated_kernel(3), io.pe_io.rotated_kernel(4)) }
        }
    val s2_mempot_rd = Reg(Vec(9, UInt(mempot_width.W)))
    val s2_valid = Wire(Bool())

    when(s1_valid && !pipe_stall && io.pe_io.conv_en) {
        for (i <- 0 until 9) {
            val local_flag = flagReg(i)(2)
            val north_flag = flagReg(i)(1)
            val valid_flag = flagReg(i)(0)
            val s_i = ref_pixel_s2(i)(aeq_width - 3, aeq_width/2 - 1)
            val s_j = ref_pixel_s2(i)(aeq_width/2 - 2, 0)

            when(valid_flag === 1.U) {
                when(io.pe_io.kSize === 5.U){
                    when(local_flag === 1.U) { // Local memory
                        when(north_flag === 1.U) { // Local North Memory
                            io.pe_io.L2_N_portA_rdaddr(i).valid := validity_map5(block_counter_s2)(i)
                            io.pe_io.L2_N_portA_rdaddr(i).bits := s_i * tot_hor_blk + s_j
                            when(io.pe_io.L2_N_portA_rddata(i).valid) {
                                s2_mempot_rd(i) := io.pe_io.L2_N_portA_rddata(col_idx).bits
                            }.otherwise {
                                s2_mempot_rd(i) := 0.U
                            }
                        }.otherwise { // Local South Memory
                            io.pe_io.L2_S_portA_rdaddr(i).valid := validity_map5(block_counter_s2)(i)
                            io.pe_io.L2_S_portA_rdaddr(i).bits := s_i * tot_hor_blk + s_j
                            when(io.pe_io.L2_S_portA_rddata(i).valid) {
                                s2_mempot_rd(i) := io.pe_io.L2_S_portA_rddata(col_idx).bits
                            }.otherwise {
                                s2_mempot_rd(i) := 0.U
                            }
                        }
                    }.otherwise { // Main memory
                        io.pe_io.main_mempot_portA_rdaddr(i).valid := validity_map5(block_counter_s2)(i)
                        io.pe_io.main_mempot_portA_rdaddr(i).bits := s_i * tot_hor_blk + s_j
                        when(io.pe_io.main_mempot_portA_rddata(i).valid) {
                            s2_mempot_rd(i) := io.pe_io.main_mempot_portA_rddata(col_idx).bits
                        }.otherwise {
                            s2_mempot_rd(i) := 0.U
                        }
                    }
                }.elsewhen(io.pe_io.kSize === 7.U){
                    when(local_flag === 1.U) { // Local memory
                        when(north_flag === 1.U) { // Local North Memory
                            io.pe_io.L2_N_portA_rdaddr(i).valid := validity_map7(block_counter_s2)(i)
                            io.pe_io.L2_N_portA_rdaddr(i).bits := s_i * tot_hor_blk + s_j
                            when(io.pe_io.L2_N_portA_rddata(i).valid) {
                                s2_mempot_rd(i) := io.pe_io.L2_N_portA_rddata(col_idx).bits
                            }.otherwise {
                                s2_mempot_rd(i) := 0.U
                            }
                        }.otherwise { // Local South Memory
                            io.pe_io.L2_S_portA_rdaddr(i).valid := validity_map7(block_counter_s2)(i)
                            io.pe_io.L2_S_portA_rdaddr(i).bits := s_i * tot_hor_blk + s_j
                            when(io.pe_io.L2_S_portA_rddata(i).valid) {
                                s2_mempot_rd(i) := io.pe_io.L2_S_portA_rddata(col_idx).bits
                            }.otherwise {
                                s2_mempot_rd(i) := 0.U
                            }
                        }
                    }.otherwise { // Main memory
                        io.pe_io.main_mempot_portA_rdaddr(i).valid := validity_map7(block_counter_s2)(i)
                        io.pe_io.main_mempot_portA_rdaddr(i).bits := s_i * tot_hor_blk + s_j
                        when(io.pe_io.main_mempot_portA_rddata(i).valid) {
                            s2_mempot_rd(i) := io.pe_io.main_mempot_portA_rddata(col_idx).bits
                        }.otherwise {
                            s2_mempot_rd(i) := 0.U
                        }
                    }
                }.otherwise{
                    when(local_flag === 1.U) { // Local memory
                        when(north_flag === 1.U) { // Local North Memory
                            io.pe_io.L2_N_portA_rdaddr(i).valid := true.B
                            io.pe_io.L2_N_portA_rdaddr(i).bits := s_i * tot_hor_blk + s_j
                            when(io.pe_io.L2_N_portA_rddata(i).valid) {
                                s2_mempot_rd(i) := io.pe_io.L2_N_portA_rddata(col_idx).bits
                            }.otherwise {
                                s2_mempot_rd(i) := 0.U
                            }
                        }.otherwise { // Local South Memory
                            io.pe_io.L2_S_portA_rdaddr(i).valid := true.B
                            io.pe_io.L2_S_portA_rdaddr(i).bits := s_i * tot_hor_blk + s_j
                            when(io.pe_io.L2_S_portA_rddata(i).valid) {
                                s2_mempot_rd(i) := io.pe_io.L2_S_portA_rddata(col_idx).bits
                            }.otherwise {
                                s2_mempot_rd(i) := 0.U
                            }
                        }
                    }.otherwise { // Main memory
                        io.pe_io.main_mempot_portA_rdaddr(i).valid := true.B
                        io.pe_io.main_mempot_portA_rdaddr(i).bits := s_i * tot_hor_blk + s_j
                        when(io.pe_io.main_mempot_portA_rddata(i).valid) {
                            s2_mempot_rd(i) := io.pe_io.main_mempot_portA_rddata(col_idx).bits
                        }.otherwise {
                            s2_mempot_rd(i) := 0.U
                        }
                    }
                }
            }.otherwise { // Invalid address
                s2_mempot_rd(i) := 0.U
            }
        }
        s2_valid := true.B
    }.otherwise {
        for (i <- 0 until num_interlac) {
            s2_mempot_rd(i) := 0.U
        }
        s2_valid := false.B
    }

    // stage - 3: convolution
    val s3_conv = Reg(Vec(num_col, UInt(mempot_width.W)))
    val s3_valid = Wire(Bool())

    when(s2_valid && io.pe_io.conv_en) {
        for (i <- 0 until 9) {
            s3_conv(i) := s2_mempot_rd(i) + kernel_s2(i)
        }
        s3_valid := true.B
    }

    // Stage-4: Write Back to MemPot
    when(s3_valid && !pipe_stall && io.pe_io.conv_en) {
        for (i <- 0 until num_interlac) {
            val addr_flags = s1_addr_calc_stage4(i)(2 + local_mem_row_bits, 0)
            val local_flag = addr_flags(2)
            val north_flag = addr_flags(1)
            val valid_flag = addr_flags(0)
            val row_idx = addr_flags(local_mem_row_bits - 1, 0)
            val col_idx = s1_addr_calc_stage4(i)(blk_bit_width + log2Ceil(num_interlac) - 1, blk_bit_width)

            when(valid_flag === 1.U) {
                when(local_flag === 1.U) { // Local memory
                    when(north_flag === 1.U) { // Write to Local North Memory
                        io.pe_io.L2_N_portB_wraddr(col_idx).valid := true.B
                        io.pe_io.L2_N_portB_wraddr(col_idx).bits := row_idx
                        io.pe_io.L2_N_portB_wrdata(col_idx).valid := true.B
                        io.pe_io.L2_N_portB_wrdata(col_idx).bits := s3_conv(i)
                    }.otherwise { // Write to Local South Memory
                        io.pe_io.L2_S_portB_wraddr(col_idx).valid := true.B
                        io.pe_io.L2_S_portB_wraddr(col_idx).bits := row_idx
                        io.pe_io.L2_S_portB_wrdata(col_idx).valid := true.B
                        io.pe_io.L2_S_portB_wrdata(col_idx).bits := s3_conv(i)
                    }
                }.otherwise { // Write to Main Memory
                    io.pe_io.main_mempot_portB_wraddr(col_idx).valid := true.B
                    io.pe_io.main_mempot_portB_wraddr(col_idx).bits := row_idx
                    io.pe_io.main_mempot_portB_wrdata(col_idx).valid := true.B
                    io.pe_io.main_mempot_portB_wrdata(col_idx).bits := s3_conv(i)
                }
            }.otherwise { // Invalid address, no write
                io.pe_io.L2_N_portB_wraddr(col_idx).valid := false.B
                io.pe_io.L2_N_portB_wrdata(col_idx).valid := false.B
                io.pe_io.L2_S_portB_wraddr(col_idx).valid := false.B
                io.pe_io.L2_S_portB_wrdata(col_idx).valid := false.B
                io.pe_io.main_mempot_portB_wraddr(col_idx).valid := false.B
                io.pe_io.main_mempot_portB_wrdata(col_idx).valid := false.B
            }
        }
    }.otherwise {
        for (i <- 0 until num_interlac) {
            io.pe_io.L2_N_portB_wraddr(i).valid := false.B
            io.pe_io.L2_N_portB_wrdata(i).valid := false.B
            io.pe_io.L2_S_portB_wraddr(i).valid := false.B
            io.pe_io.L2_S_portB_wrdata(i).valid := false.B
            io.pe_io.main_mempot_portB_wraddr(i).valid := false.B
            io.pe_io.main_mempot_portB_wrdata(i).valid := false.B
        }
    }

    // --- pipeline data hazards mitigation ---
    val s1_s2_stall = WireDefault(false.B)

    val forward_enable = Wire(Vec(9, Bool()))
    val forward_data = Wire(Vec(9, UInt(mempot_width.W)))

    for (i <- 0 until 9) {
        forward_enable(i) := false.B
        forward_data(i) := 0.U
    }

    for (i <- 0 until 9) {
        when(s1_addr_calc_stage2(i) === s1_addr_calc_stage4(i) && s1_addr_calc_stage4(i)(0) === 1.U) {
            forward_enable(i) := true.B
            forward_data(i) := s3_conv(i)
        }

        when(s1_addr_calc_stage2(i) === s1_addr_calc_stage3(i) && s1_addr_calc_stage3(i)(0) === 1.U) {
            s1_s2_stall := true.B
        }
    }

    for (i <- 0 until 9) {
        when(forward_enable(i)) {
            s2_mempot_rd(i) := forward_data(i)
        }
    }

    when(s1_s2_stall) {
        s1_addr_calc := s1_addr_calc
        s1_addr_calc_stage2 := s1_addr_calc_stage2
    } .otherwise {
        s1_addr_calc_stage2 := s1_addr_calc
    }

    // --- thresholding pipeline stages ---
    val tot_blk = ((io.pe_io.T - 1)/3) * ((io.pe_io.N - 1)/3)
    
    val s1_main_mempot = Reg(Vec(9, UInt(mempot_width.W)))
    val s1_local_mempot = Reg(Vec(9, UInt(mempot_width.W)))
    val s1_valid_th = RegInit(false.B)

    val s2_add_result = Reg(Vec(9, UInt(mempot_width.W)))
    val s2_valid_th = RegInit(false.B)

    val s3_spike_event = Reg(UInt(9.W))
    val s3_valid_th = RegInit(false.B)

    val s4_valid_th = RegInit(false.B)
    val block_counter_th = RegInit(0.U(log2Ceil(aeq_depth).W))
    val aeq_wr_en = RegInit(false.B)

    // --- Stage 0: Memory Access ---
    when(io.pe_io.thresh_done === true.B) {

        val block_x = block_counter_th % tot_hor_blk.U
        val block_y = block_counter_th / tot_hor_blk.U

        val within_north_boundary = block_y < kernel_radius.U
        val within_south_boundary = block_y >= (tot_ver_blk - kernel_radius).U

        for (i <- 0 until 9) {
            when(within_north_boundary) {
                io.pe_io.L1_N_portA_rdaddr(i).valid := true.B
                io.pe_io.L1_S_portA_rdaddr(i).valid := false.B // Don't need South memory
                io.pe_io.main_mempot_portA_rdaddr(i).bits := block_counter_th * 9.U + i.U
                io.pe_io.L1_N_portA_rdaddr(i).bits := block_counter_th * 9.U + i.U
            }.elsewhen(within_south_boundary) {
                io.pe_io.L1_S_portA_rdaddr(i).valid := true.B
                io.pe_io.L1_N_portA_rdaddr(i).valid := false.B // Don't need North memory
                io.pe_io.main_mempot_portA_rdaddr(i).bits := block_counter_th * 9.U + i.U
                io.pe_io.L1_S_portA_rdaddr(i).bits := block_counter_th * 9.U + i.U
            }.otherwise {
                io.pe_io.L1_N_portA_rdaddr(i).valid := false.B
                io.pe_io.L1_S_portA_rdaddr(i).valid := false.B
                io.pe_io.main_mempot_portA_rdaddr(i).bits := block_counter_th * 9.U + i.U
            }

            when(io.pe_io.main_mempot_portA_rddata(i).fire) {
                s1_main_mempot(i) := io.pe_io.main_mempot_portA_rddata(i).bits
            }

            when(io.pe_io.L1_N_portA_rddata(i).fire) {
                s1_local_mempot(i) := io.pe_io.L1_N_portA_rddata(i).bits
            }

            when(io.pe_io.L1_S_portA_rddata(i).fire) {
                s1_local_mempot(i) := io.pe_io.L1_S_portA_rddata(i).bits
            }
        }

        s1_valid_th := true.B
    }.otherwise {
        s1_valid_th := false.B
    }

    // --- Stage 1: Addition & Biasing ---
    when(s1_valid_th) {
        for (i <- 0 until 9) {
            s2_add_result(i) := s1_main_mempot(i) + s1_local_mempot(i) + io.pe_io.bias(i)
        }
        s2_valid_th := true.B
    }

    // --- Stage 2: Threshold Comparison ---
    when(s2_valid_th) {
        for (i <- 0 until 9) {
            s3_spike_event := VecInit((0 until 9).map(i => s2_add_result(i) > io.pe_io.v_t)).asUInt
        }
        s3_valid_th := true.B
    }

    // --- Stage 3: Write to Active Event Queue (AEQ) ---
    when(s3_valid_th) {
        aeq_wr_en := true.B
        io.pe_io.aeq_portB_wraddr.valid := true.B
        io.pe_io.aeq_portB_wrdata.valid := true.B
        io.pe_io.aeq_portB_wraddr.bits := block_counter_th
        io.pe_io.aeq_portB_wrdata.bits := Cat(1.U(1.W), block_counter_th, s3_spike_event)

        when(io.pe_io.aeq_portB_wraddr.fire && io.pe_io.aeq_portB_wrdata.fire) {
            block_counter_th := block_counter_th + 1.U
        }

        when(block_counter_th === (mempot_depth - 1).U) {
            s4_valid_th := true.B
            aeq_wr_en := false.B
        }
    }

}

object pe_nxn extends App {
  val verilogString = chisel3.getVerilogString(new pe(kernel5 = true, kernel7 = true, max_local_rows = 3, num_col = 9, mempot_width = 16, mempot_depth = 256, aeq_width = 12, aeq_depth = 256, kernel_width = 8, num_interlac = 9, bias_width = 8))
  val verilogFile = new File("pe.sv")
  val writer = new PrintWriter(verilogFile)
  writer.write(verilogString)
  writer.close()
}

// object Main {
//   def main(args: Array[String]): Unit = {
//     val verilogString = circt.stage.ChiselStage.emitSystemVerilog(new pe_nxn(T = 16, N = 16, mempot_width = 16, mempot_depth = 256, aeq_width = 12, aeq_depth = 256, io.pe_io.kSize = 7, kernel_width = 8, num_interlac = 9, bias_width = 8))
//     println(verilogString)
//   }
// }