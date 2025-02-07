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

    val se_blk = (io.pe_io.T - 1.U) / 3   //south edge blk detect
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
    val i = (spike_event(aeq_width - 2, aeq_width/2)).asUInt
    val j = (spike_event(aeq_width/2 - 1, 1)).asUInt
    val Cs = aeq_col_select_counter
    
    val Cs_s1 = RegNext(Cs)
    
    // check if spike occurs on the boundary
    val isNorth = Wire(Bool())
    val isSouth = Wire(Bool())
    val (north, south) = Module(new BoundaryCheck(i, se_blk, se_col, se_col1, col, aeq_width, dim_width))
    isNorth := north
    isSouth := south

    when()
    val ref_pixel = Wire(Vec(9, UInt((4 + aeq_width - 2).W)))  // sub-block col + i_new + j_new
    val ref_pixel_s1 = RegNext((ref_pixel))

    val col_map_7 = VecInit(4.U, 5.U, 3.U, 7.U, 8.U, 6.U, 1.U, 2.U, 0.U)
    val col_map_5 = VecInit(8.U, 6.U, 7.U, 2.U, 0.U, 1.U, 5.U, 3.U, 4.U)

    val offset_7 = VecInit(Seq(
        VecInit((-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 0), (0, 1), (1, -1), (1, 0), (1, 1)),  // 0
        VecInit((-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 0), (0, 1), (1, -1), (1, 0), (1, 1)),  // 1
        VecInit((-1,  0), (-1, 1), (-1, 2), (0,  0), (0, 1), (0, 2), (1,  0), (1, 1), (1, 2)),  // 2
        VecInit((-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 0), (0, 1), (1, -1), (1, 0), (1, 1)),  // 3
        VecInit((-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 0), (0, 1), (1, -1), (1, 0), (1, 1)),  // 4
        VecInit((-1,  0), (-1, 1), (-1, 2), (0,  0), (0, 1), (0, 2), (1,  0), (1, 1), (1, 2)),  // 5
        VecInit(( 0, -1), ( 0, 0), ( 0, 1), (1, -1), (1, 0), (1, 1), (2, -1), (2, 0), (2, 1)),  // 6
        VecInit(( 0, -1), ( 0, 0), ( 0, 1), (1, -1), (1, 0), (1, 1), (2, -1), (2, 0), (2, 1)),  // 7
        VecInit(( 0,  0), ( 0, 1), ( 0, 2), (1,  0), (1, 1), (1, 2), (2,  0), (2, 1), (2, 2)),  // 8
    ))

    val offset_5 = VecInit(Seq(
        VecInit((-1, -1), (-1, 0), (0, -1), (0, 0)),  // 0
        VecInit((-1,  0), (-1, 1), (0,  0), (0, 1)),  // 1
        VecInit((-1,  0), (-1, 1), (0,  0), (0, 1)),  // 2
        VecInit(( 0, -1), ( 0, 0), (1, -1), (1, 0)),  // 3
        VecInit(( 0,  0), ( 0, 1), (1,  0), (1, 1)),  // 4
        VecInit(( 0,  0), ( 0, 1), (1,  0), (1, 1)),  // 5
        VecInit(( 1, -1), ( 0, 0), (1, -1), (1, 0)),  // 6
        VecInit(( 0,  0), ( 0, 1), (1,  0), (1, 1)),  // 7
        VecInit(( 0,  0), ( 0, 1), (1,  0), (1, 1))   // 8
    ))

    val ref_pixel_5x5 = Wire(Vec(4, UInt((3 + aeq_width/2).W)))
    when(kernel5.B) {
        for (idx <- 0 until 4) {
            val (off_i, off_j) = offset_5(Cs)(idx)
            ref_pixel_5x5(idx) := Cat(
                col_map_5(Cs),
                (i.asSInt + off_i.S).asUInt,
                (j.asSInt + off_j.S).asUInt
            )
        }
    }

    val ref_pixel_7x7 = Wire(Vec(9, UInt((3 + aeq_width/2).W)))
    when(kernel7.B) {
        for (idx <- 0 until 9) {
            val (off_i, off_j) = offset_7(Cs)(idx)
            ref_pixel_7x7(idx) := Cat(
                col_map_7(Cs),
                (i.asSInt + off_i.S).asUInt,
                (j.asSInt + off_j.S).asUInt
            )
        }
    }

    when(io.PE_IO.kSize === 5.U) {
        ref_pixel := ref_pixel_5x5 ++ VecInit(Seq.fill(5)(0.U((3 + aeq_width/2).W)))
    }.elsewhen(io.PE_IO.kSize === 7.U) {
        ref_pixel := ref_pixel_7x7
    }
    

    // --- stage - 1: calculate the neighbor address ---
    val s1_valid = Wire(Bool())
    val ref_pixel_s2 = Wire(Vec(9, UInt((3 + aeq_width / 2).W)))

    val block_counter = RegInit(0.U(log2Ceil(num_blocks_per_spike).W))

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

            ref_pixel_s2(col) := Cat(col.U(4.W), new_i, new_j)
        }
        s1_valid := true.B
    }


    // stage - 2: mempot read
    val s2_mempot_rd = Reg(Vec(9, UInt(mempot_width.W)))
    val s2_valid = Wire(Bool())

    when(s1_valid && !pipe_stall && io.pe_io.conv_en) {
        for (i <- 0 until num_interlac) {
            val addr_flags = s1_addr_calc_stage2(i)(2 + local_mem_row_bits, 0)
            val local_flag = addr_flags(2)
            val north_flag = addr_flags(1)
            val valid_flag = addr_flags(0)
            val row_idx = addr_flags(local_mem_row_bits - 1, 0)
            val col_idx = s1_addr_calc_stage2(i)(blk_bit_width + log2Ceil(num_interlac) - 1, blk_bit_width)

            when(valid_flag === 1.U) {
                when(local_flag === 1.U) { // Local memory
                    when(north_flag === 1.U) { // Local North Memory
                        io.pe_io.L2_N_portA_rdaddr(col_idx).valid := true.B
                        io.pe_io.L2_N_portA_rdaddr(col_idx).bits := row_idx
                        when(io.pe_io.L2_N_portA_rddata(col_idx).valid) {
                            s2_mempot_rd(i) := io.pe_io.L2_N_portA_rddata(col_idx).bits
                        }.otherwise {
                            s2_mempot_rd(i) := 0.U
                        }
                    }.otherwise { // Local South Memory
                        io.pe_io.L2_S_portA_rdaddr(col_idx).valid := true.B
                        io.pe_io.L2_S_portA_rdaddr(col_idx).bits := row_idx
                        when(io.pe_io.L2_S_portA_rddata(col_idx).valid) {
                            s2_mempot_rd(i) := io.pe_io.L2_S_portA_rddata(col_idx).bits
                        }.otherwise {
                            s2_mempot_rd(i) := 0.U
                        }
                    }
                }.otherwise { // Main memory
                    io.pe_io.main_mempot_portA_rdaddr(col_idx).valid := true.B
                    io.pe_io.main_mempot_portA_rdaddr(col_idx).bits := row_idx
                    when(io.pe_io.main_mempot_portA_rddata(col_idx).valid) {
                        s2_mempot_rd(i) := io.pe_io.main_mempot_portA_rddata(col_idx).bits
                    }.otherwise {
                        s2_mempot_rd(i) := 0.U
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
            s3_conv(i) := s2_mempot_rd(i) + io.pe_io.rotated_kernel(i)
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
    val tot_blk = tot_hor_blk * tot_ver_blk
    
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