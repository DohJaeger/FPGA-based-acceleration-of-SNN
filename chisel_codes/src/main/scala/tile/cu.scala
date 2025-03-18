import chisel3._
import chisel3.util._
import chisel3.util.Decoupled
import java.io.{File, PrintWriter, BufferedWriter, FileWriter}

import IO_DEFS._
import IO_DEFS.{NetworkUtils, KernelUtils}


class cu(num_col: Int, mempot_width: Int, mempot_depth: Int, aeq_width: Int, aeq_depth: Int, kernel_width: Int, bias_width: Int, dim_width: Int) extends Module {
    val io = IO(new Bundle {
        val pe_io = new CU_IO(num_col, aeq_depth, aeq_width, mempot_depth, mempot_width, bias_width, kernel_width, dim_width)
    })
    
    NetworkUtils.initCUIO(io.pe_io, num_col)
    
    val conv_done = RegInit(false.B)    // s0
    val conv_done_s2 = RegNext(conv_done)
    val conv_done_s3 = RegNext(conv_done_s2)
    val conv_done_s4 = RegNext(conv_done_s3)

    io.pe_io.conv_done := conv_done_s4

    val tot_hor_blk = (io.pe_io.N - 1.U)/3.U
    val se_blk = (io.pe_io.T - 1.U) / 3.U
    val se_col = (io.pe_io.T - 1.U) % 3.U

    val pipe_stall = WireInit(false.B)

    // --- Stage 0: Read AEQ ---
    val aeq_read_col_sel_counter = RegInit(0.U(log2Ceil(9).W))
    val aeq_read_addr = RegInit(0.U(log2Ceil(aeq_depth).W))

    val spike_event = WireInit(0.U(aeq_width.W))
    val spike_event_s1 = RegNext(spike_event)

    val spike_valid = WireInit(false.B)
    val spike_valid_s1 = RegNext(spike_valid)

    val eoq_bit = WireInit(false.B)
    
    io.pe_io.ai_rdaddr(aeq_read_col_sel_counter) := aeq_read_addr
    
    spike_event := io.pe_io.ai_rddata(aeq_read_col_sel_counter)
    spike_valid := spike_event(0)
    eoq_bit := spike_event(aeq_width - 1)
    
    when(aeq_read_col_sel_counter === 8.U && eoq_bit) {
        aeq_read_col_sel_counter := 0.U
        conv_done := true.B
    }.otherwise {
        when(eoq_bit){
            aeq_read_addr := 0.U
            aeq_read_col_sel_counter := aeq_read_col_sel_counter + 1.U
        }.elsewhen(!pipe_stall && io.pe_io.conv_en && !conv_done){
            aeq_read_addr := aeq_read_addr + 1.U
        }
    }

    // --- stage - 1: calculate the neighbor address ---
    val i_in = Wire(UInt((aeq_width/2 - 1).W))
    val j_in = Wire(UInt((aeq_width/2 - 1).W))

    val addr_calc_main = Reg(Vec(9, UInt((aeq_width - 2).W))) // s2
    val addr_calc_local = Reg(Vec(3, UInt((aeq_width - 2).W)))

    val addr_calc_main_s3 = RegNext(addr_calc_main)
    val addr_calc_local_s3 = RegNext(addr_calc_local)

    val addr_calc_main_s4 = RegNext(addr_calc_main_s3)
    val addr_calc_local_s4 = RegNext(addr_calc_local_s3)

    i_in := (spike_event_s1(aeq_width - 2, aeq_width / 2)).asUInt
    j_in := (spike_event_s1(aeq_width / 2 - 1, 1)).asUInt

    val input_idx = WireInit(0.U(4.W))
    input_idx := aeq_read_col_sel_counter

    val boundaryCheck = Module(new BoundaryCheck(aeq_width, dim_width))
    boundaryCheck.io.i := i_in
    boundaryCheck.io.se_blk := se_blk
    boundaryCheck.io.se_col := se_col
    boundaryCheck.io.col := input_idx

    val isNorth = boundaryCheck.io.isNorth
    val isSouth = boundaryCheck.io.isSouth
    val col_num = boundaryCheck.io.col_out

    val isNorth_s2 = RegNext(isNorth)
    val isSouth_s2 = RegNext(isSouth)
    val isNorth_s3 = RegNext(isNorth_s2)
    val isSouth_s3 = RegNext(isSouth_s2)
    val isNorth_s4 = RegNext(isNorth_s3)
    val isSouth_s4 = RegNext(isSouth_s3)
    val col_num_s3 = RegNext(RegNext(col_num))
    val col_num_s4 = RegNext(col_num_s3)

    val s1_valid = WireInit(false.B)

    val main_valid = RegInit(VecInit(Seq.fill(9)(true.B)))
    val local_valid = RegInit(false.B)

    val new_i = WireInit(0.U(i_in.getWidth.W))
    val new_j = WireInit(0.U(j_in.getWidth.W))

    // AddrCalc module instantiated
    val addrCalc = Module(new AddrCalc(aeq_width))
    addrCalc.io.input_idx := input_idx
    addrCalc.io.i := i_in
    addrCalc.io.j := j_in
    for (col <- 0 until 9) {
		addr_calc_main(col) := Cat(addrCalc.io.new_i(col), addrCalc.io.new_j(col))
	}


    // Check if at the north or south edge
    when(spike_valid_s1 && !pipe_stall && io.pe_io.conv_en && !conv_done){
        when(isNorth) {
            local_valid := true.B
            main_valid := VecInit(Seq.fill(9)(true.B))
            main_valid(6) := false.B
            main_valid(7) := false.B
            main_valid(8) := false.B
            addr_calc_local := VecInit(Seq(addr_calc_main(0)(aeq_width/2 - 2, 0), addr_calc_main(1)(aeq_width/2 - 2, 0), addr_calc_main(2)(aeq_width/2 - 2, 0)))

        }.elsewhen(isSouth) {
            local_valid := true.B
            main_valid := VecInit(Seq.fill(9)(true.B))

            switch(col_num) {
                is(0.U) {
                    main_valid(3) := false.B
                    main_valid(4) := false.B
                    main_valid(5) := false.B
                    addr_calc_local := VecInit(Seq(addr_calc_main(3)(aeq_width/2 - 2, 0), addr_calc_main(4)(aeq_width/2 - 2, 0), addr_calc_main(5)(aeq_width/2 - 2, 0)))
                }
                is(1.U) {
                    main_valid(6) := false.B
                    main_valid(7) := false.B
                    main_valid(8) := false.B
                    addr_calc_local := VecInit(Seq(addr_calc_main(6)(aeq_width/2 - 2, 0), addr_calc_main(7)(aeq_width/2 - 2, 0), addr_calc_main(8)(aeq_width/2 - 2, 0)))
                }
                is(2.U) {
                    main_valid(0) := false.B
                    main_valid(1) := false.B
                    main_valid(2) := false.B
                    addr_calc_local := VecInit(Seq(addr_calc_main(0)(aeq_width/2 - 2, 0), addr_calc_main(1)(aeq_width/2 - 2, 0), addr_calc_main(2)(aeq_width/2 - 2, 0)))
                }
            }

        }.otherwise {
            local_valid := false.B
            main_valid := VecInit(Seq.fill(9)(true.B))
        }
    }


    // stage - 2: mempot read
    val input_idx_s2 = RegNext(input_idx)
    val kernel_s2 = Reg(Vec(9, UInt(kernel_width.W)))

    kernel_s2 := KernelUtils.selectKernel(input_idx_s2, io.pe_io.rotated_kernel)
        
    val mempot_rd_main = Wire(Vec(9, UInt(mempot_width.W)))
    val mempot_rd_local = Wire(Vec(3, UInt(mempot_width.W)))

    mempot_rd_main.foreach(_ := DontCare)
    mempot_rd_local.foreach(_ := DontCare)

    val s2_valid = RegInit(false.B)

    when(!pipe_stall && io.pe_io.conv_en && !conv_done_s2) {
        for (i <- 0 until 9) {
            when(main_valid(i)) {
                io.pe_io.mm_we(i) := false.B
                io.pe_io.mm_rdaddr(i) := addr_calc_main(i)
                mempot_rd_main(i) := io.pe_io.mm_rddata(i)
            }
        }

        when(isNorth_s2) {
            for (i <- 0 until 3) {
                io.pe_io.ln2_we(i) := false.B
                io.pe_io.ln2_rdaddr(i) := addr_calc_local(i)
                mempot_rd_local(i) := io.pe_io.ln2_rddata(i)
            }
        }

        when(isSouth_s2) {
            for (i <- 0 until 3) {
                io.pe_io.ls2_we(i) := false.B
                io.pe_io.ls2_rdaddr(i) := addr_calc_local(i)
                mempot_rd_local(i) := io.pe_io.ls2_rddata(i)
            }
        }
    
    }

    // stage - 3: convolution
    val s3_conv = Reg(Vec(num_col, UInt(mempot_width.W)))
    val s3_valid = Reg(Bool())

    when(io.pe_io.conv_en & !conv_done_s3) {
        when(isNorth_s3) {
            for (i <- 6 until 9) {
                s3_conv(i) := mempot_rd_local(i - 6) + kernel_s2(i)
            }

            for (i <- 0 until 6){
                s3_conv(i) := mempot_rd_main(i) + kernel_s2(i)
            }
        }.elsewhen(isSouth_s3) {
            when(col_num_s3 === 0.U){
                for (i <- 0 until 3){
                    s3_conv(i) := mempot_rd_main(i) + kernel_s2(i)
                }

                for (i <- 3 until 6){
                    s3_conv(i) := mempot_rd_local(i - 3) + kernel_s2(i)
                }
    
                for (i <- 6 until 9){
                    s3_conv(i) := mempot_rd_main(i) + kernel_s2(i)
                }
            }.elsewhen(col_num_s3 === 1.U){
                for (i <- 0 until 6){
                    s3_conv(i) := mempot_rd_main(i) + kernel_s2(i)
                }

                for (i <- 6 until 9){
                    s3_conv(i) := mempot_rd_local(i - 6) + kernel_s2(i)
                }
            }.otherwise{
                for (i <- 0 until 3){
                    s3_conv(i) := mempot_rd_local(i) + kernel_s2(i)
                }

                for (i <- 3 until 9){
                    s3_conv(i) := mempot_rd_main(i) + kernel_s2(i)
                }
            }

        }.otherwise {
            for (i <- 0 until 9) {
                s3_conv(i) := mempot_rd_main(i) + kernel_s2(i)
            }
        }
    }

    val mempot_wr_main = Reg(Vec(9, UInt(mempot_width.W)))
    val mempot_wr_local = Reg(Vec(3, UInt(mempot_width.W)))

    val mempot_wr_main_valid = RegInit(VecInit(Seq.fill(9)(false.B)))
    val mempot_wr_local_valid = RegInit(false.B)

    when(!conv_done && io.pe_io.conv_en) {
        for (i <- 0 until 9) {
            when(isNorth && (i.U >= 6.U && i.U <= 8.U)) {
                val local_idx = (i.U - 6.U)(1, 0)
                mempot_wr_local(local_idx) := s3_conv(i)
                mempot_wr_local_valid := true.B

            }.elsewhen(isSouth && (i.U >= col_num_s3 && i.U <= col_num_s3 + 2.U)) {
                val local_idx = (i.U - col_num_s3)(1, 0)
                mempot_wr_local(local_idx) := s3_conv(i)
                mempot_wr_local_valid := true.B

            }.otherwise {
                mempot_wr_main(i) := s3_conv(i)
                mempot_wr_main_valid(i) := true.B
            }
        }
    }

    // Stage-4: Write Back to MemPot
    when(io.pe_io.conv_en && !conv_done_s4) {
        for (i <- 0 until 9) {
            io.pe_io.mm_we(i) := mempot_wr_main_valid(i)
            io.pe_io.mm_wraddr(i) := addr_calc_main_s4(i)
            io.pe_io.mm_wrdata(i) := mempot_wr_main(i)
        }

        when(isNorth_s4) {
            for (i <- 0 until 3) {
                io.pe_io.ln2_wraddr(i) := addr_calc_local_s4(i)
                io.pe_io.ln2_we(i) := true.B
                io.pe_io.ln2_wrdata(i) := mempot_wr_local(i)
            }
        }.elsewhen(isSouth_s4){
            for (i <- 0 until 3) {
                io.pe_io.ls2_wraddr(i) := addr_calc_local_s4(i)
                io.pe_io.ls2_we(i) := true.B
                io.pe_io.ls2_wrdata(i) := mempot_wr_local(i)
            }
        }
    }

    // --- pipeline data hazards mitigation ---

    val forward_enable = Wire(Vec(9, Bool()))
    val forward_data = Wire(Vec(9, UInt(mempot_width.W)))
    forward_enable.foreach(_ := DontCare)
    forward_data.foreach(_ := DontCare)

    when(io.pe_io.conv_en) {
        // Case 1: No boundary spike -> Only compare main memory
        when(!isNorth_s2 & !isSouth_s2) {
            for (i <- 0 until 9) {
                when(addr_calc_main(i) === addr_calc_main_s4(i)) {
                    mempot_rd_main(i) := s3_conv(i) // Forward result from S4
                }
            }
        }

        // Case 2: North boundary -> Compare local memory
        when(isNorth_s2 === isNorth_s4) {
            for (i <- 0 until 3) {
                when(addr_calc_local(i) === addr_calc_local_s4(i)) {
                    mempot_rd_local(i) := s3_conv(i + 6) // Forward from corresponding S4 index
                }
            }
        }

        // Case 3: South boundary -> Compare local memory with `se_col` handling
        when(isSouth_s2 === isSouth_s4) {
            for (i <- 0 until 3) {
                when(addr_calc_local(i) === addr_calc_local_s4(i)) {
                    val sel_vec = VecInit(Seq(s3_conv(i + 3), s3_conv(i + 6), s3_conv(i)))
                    mempot_rd_local(i) := sel_vec(se_col)
                }
            }
        }

        // Case 4: Overlap in Main Memory (For Boundary Conditions)
        for (i <- 0 until 9) {
            when(addr_calc_main(i) === addr_calc_main_s4(i)) {
                mempot_rd_main(i) := s3_conv(i) // Forward result from S4
            }
        }
    }

    when(io.pe_io.conv_en) {
        // Check for S2-S3 hazard in Main Memory
        for (i <- 0 until 9) {
            when(addr_calc_main(i) === addr_calc_main_s3(i)) {
                pipe_stall := true.B  // Stall pipeline if addresses match
            }
        }

        // Check for S2-S3 hazard in Local Memory
        for (i <- 0 until 3) {
            when(addr_calc_local(i) === addr_calc_local_s3(i)) {
                pipe_stall := true.B  // Stall pipeline if addresses match
            }
        }
    }   

}


object cu extends App {
  val verilogString = chisel3.getVerilogString(new cu(num_col = 9, mempot_width = 8, mempot_depth = 1024, aeq_width = 10, aeq_depth = 1024, kernel_width = 8, bias_width = 8, dim_width = 8))
  val verilogFile = new File("cu.sv")
  val writer = new PrintWriter(verilogFile)
  writer.write(verilogString)
  writer.close()
}