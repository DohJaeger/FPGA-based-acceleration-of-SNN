import chisel3._
import chisel3.util._
import chisel3.util.Decoupled
import java.io.{File, PrintWriter, BufferedWriter, FileWriter}

import PE_IO_Defs._
import PE_IO_Defs.NetworkUtils


class cu(num_col: Int, mempot_width: Int, mempot_depth: Int, aeq_width: Int, aeq_depth: Int, kernel_width: Int, bias_width: Int, dim_width: Int) extends Module {
    val io = IO(new Bundle {
        val pe_io = new PE_IO(num_col, aeq_depth, aeq_width, mempot_depth, mempot_width, bias_width, kernel_width, dim_width)
    })
    
    NetworkUtils.initNetworkIO(io.pe_io, num_col)

    io.pe_io.conv_done := conv_done_reg
    io.pe_io.thresh_done := thresh_done_reg
    
    val conv_done_reg = RegInit(false.B)
    val thresh_done_reg = RegInit(false.B)

    val tot_hor_blk = (io.pe_io.N - 1.U)/3.U
    val se_blk = (io.pe_io.T - 1.U) / 3.U
    val se_col = (io.pe_io.T - 1.U) % 3.U

    val pipe_stall = false.B

    // --- Stage 0: Read AEQ ---
    val aeq_read_col_sel_counter = RegInit(0.U(log2Ceil(9).W))
    val aeq_read_addr = RegInit(0.U(log2Ceil(aeq_depth).W))

    val spike_event = RegInit(0.U(aeq_width.W))
    val spike_event_s1 = RegNext(spike_event)

    val spike_valid = RegInit(false.B)

    val eoq_bit = spike_event(aeq_width - 1)

    io.pe_io.aeq_in_rdaddr(aeq_read_col_sel_counter).valid := !pipe_stall && !((aeq_read_col_sel_counter === 8.U) && eoq_bit)
    io.pe_io.aeq_in_rdaddr(aeq_read_col_sel_counter).bits := aeq_read_addr
    io.pe_io.aeq_in_rddata(aeq_read_col_sel_counter).ready := !pipe_stall && !((aeq_read_col_sel_counter === 8.U) && eoq_bit)

    when(io.pe_io.aeq_in_rdaddr(aeq_read_col_sel_counter).valid && io.pe_io.aeq_in_rddata(aeq_read_col_sel_counter).ready) {
        spike_event := io.pe_io.aeq_in_rddata(aeq_read_col_sel_counter).bits
        spike_valid := true.B

        when(aeq_read_col_sel_counter === 8.U && eoq_bit) {
            aeq_read_col_sel_counter := 0.U
        }.otherwise {
            aeq_read_col_sel_counter := aeq_read_col_sel_counter + 1.U
        }

    }.otherwise {
        spike_valid := false.B
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

    val input_idx = Wire(UInt(4.W))
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

    val s1_valid = Wire(Bool())

    val main_valid = RegInit(VecInit(Seq.fill(9)(true.B)))
    val local_valid = RegInit(false.B)

    val new_i = Wire(UInt(i_in.getWidth.W))
    val new_j = Wire(UInt(j_in.getWidth.W))

    when(!pipe_stall) {
        for (col <- 0 until 9) {
            new_i := i_in
            new_j := j_in

            when(col.U === 0.U || col.U === 3.U || col.U === 6.U) {
                when(input_idx === 2.U || input_idx === 5.U || input_idx === 8.U) {
                    new_j := j_in + 1.U
                }
            }
            when(col.U === 2.U || col.U === 5.U || col.U === 8.U) {
                when(input_idx === 0.U || input_idx === 3.U || input_idx === 6.U) {
                    new_j := j_in - 1.U
                }
            }

            when(col.U === 0.U || col.U === 1.U || col.U === 2.U) {
                when(input_idx === 6.U || input_idx === 7.U || input_idx === 8.U) {
                    new_i := i_in + 1.U
                }
            }
            when(col.U === 6.U || col.U === 7.U || col.U === 8.U) {
                when(input_idx === 0.U || input_idx === 1.U || input_idx === 2.U) {
                    new_i := i_in - 1.U
                }
            }

            addr_calc_main(col) := Cat(new_i, new_j)
        }
        s1_valid := true.B
    }

    // Check if at the north or south edge
    when(isNorth) {
        local_valid := true.B
        main_valid := VecInit(Seq.fill(9)(true.B))
        main_valid(6) := false.B
        main_valid(7) := false.B
        main_valid(8) := false.B
        addr_calc_local := VecInit(Seq(addr_calc_main(0)(aeq_width/2 - 2, 0), addr_calc_main(1)(aeq_width/2 - 2, 0), addr_calc_main(2)(aeq_width/2 - 2, 0)))

    } .elsewhen(isSouth) {
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

    } .otherwise {
        local_valid := false.B
        main_valid := VecInit(Seq.fill(9)(true.B))
    }


    // stage - 2: mempot read
    val input_idx_s2 = RegNext(input_idx)
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
        
    val mempot_rd_main = Reg(Vec(9, UInt(mempot_width.W)))
    val mempot_rd_local = Reg(Vec(3, UInt(mempot_width.W)))
    val s2_valid = Wire(Bool())

    when(s1_valid && !pipe_stall && io.pe_io.conv_en) {
        for (i <- 0 until 9) {
            when(main_valid(i)) {
                io.pe_io.main_mempot_rdaddr(i).valid := true.B
                io.pe_io.main_mempot_rdaddr(i).bits := addr_calc_main(i)
                when(io.pe_io.main_mempot_rddata(i).valid) {
                    mempot_rd_main(i) := io.pe_io.main_mempot_rddata(i).bits
                }.otherwise {
                    mempot_rd_main(i) := 0.U
                }
            }.otherwise {
                mempot_rd_main(i) := 0.U
            }
        }

        when(isNorth_s2) {
            for (i <- 0 until 3) {
                io.pe_io.L2_N_rdaddr(i).valid := true.B
                io.pe_io.L2_N_rdaddr(i).bits := addr_calc_local(i)
                when(io.pe_io.L2_N_rddata(i).valid) {
                    mempot_rd_local(i) := io.pe_io.L2_N_rddata(i).bits
                }.otherwise {
                    mempot_rd_local(i) := 0.U
                }
            }
        }.otherwise {
            for (i <- 0 until 3) {
                mempot_rd_local(i) := 0.U
            }
        }

        when(isSouth_s2) {
            for (i <- 0 until 3) {
                io.pe_io.L2_S_rdaddr(i).valid := true.B
                io.pe_io.L2_S_rdaddr(i).bits := addr_calc_local(i)
                when(io.pe_io.L2_S_rddata(i).valid) {
                    mempot_rd_local(i) := io.pe_io.L2_S_rddata(i).bits
                }.otherwise {
                    mempot_rd_local(i) := 0.U
                }
            }
        }.otherwise {
            for (i <- 0 until 3) {
                mempot_rd_local(i) := 0.U
            }
        }

    }.otherwise {
        for (i <- 0 until 9) {
            mempot_rd_main(i) := 0.U
        }
        for (i <- 0 until 3) {
            mempot_rd_local(i) := 0.U
        }
        s2_valid := false.B
    }

    // stage - 3: convolution
    val s3_conv = Reg(Vec(num_col, UInt(mempot_width.W)))
    val s3_valid = Wire(Bool())

    when(s2_valid && io.pe_io.conv_en) {
        for (i <- 0 until 9) {
            s3_conv(i) := Mux(
                isNorth_s3 && (i.U >= 6.U && i.U <= 8.U),
                mempot_rd_local(i - 6) + kernel_s2(i),
                Mux(
                    isSouth_s3 && (i.U >= col_num_s3 && i.U <= col_num_s3 + 2.U),
                    mempot_rd_local(i.U - col_num_s3) + kernel_s2(i),
                    mempot_rd_main(i) + kernel_s2(i)
                )
            )
        }
        s3_valid := true.B
    }

    val mempot_wr_main = Reg(Vec(9, UInt(mempot_width.W)))
    val mempot_wr_local = Reg(Vec(3, UInt(mempot_width.W)))

    val mempot_wr_main_valid = RegInit(VecInit(Seq.fill(9)(false.B)))
    val mempot_wr_local_valid = RegInit(false.B)

    when(s2_valid && io.pe_io.conv_en) {
        mempot_wr_main_valid := VecInit(Seq.fill(9)(false.B))
        mempot_wr_local_valid := VecInit(Seq.fill(3)(false.B))

        for (i <- 0 until 9) {
            when(isNorth && (i.U >= 6.U && i.U <= 8.U)) {
                val local_idx = i.U - 6.U
                mempot_wr_local(local_idx) := s3_conv(i)
                mempot_wr_local_valid(local_idx) := true.B

            }.elsewhen(isSouth && (i.U >= col_num_s3 && i.U <= col_num_s3 + 2.U)) {
                val local_idx = i.U - col_num_s3
                mempot_wr_local(local_idx) := s3_conv(i)
                mempot_wr_local_valid(local_idx) := true.B

            }.otherwise {
                mempot_wr_main(i) := s3_conv(i)
                mempot_wr_main_valid(i) := true.B
            }
        }
    }

    // Stage-4: Write Back to MemPot
    when(s3_valid && io.pe_io.conv_en) {
        for (i <- 0 until 9) {
            when(mempot_wr_main_valid(i)) {
                io.pe_io.main_mempot_wraddr(i).valid := true.B
                io.pe_io.main_mempot_wraddr(i).bits := addr_calc_main_s4(i)
                io.pe_io.main_mempot_wrdata(i).valid := true.B
                io.pe_io.main_mempot_wrdata(i).bits := mempot_wr_main(i)

            }.otherwise {
                io.pe_io.main_mempot_wraddr(i).valid := false.B
                io.pe_io.main_mempot_wrdata(i).valid := false.B
            }
        }

        when(isNorth_s4) {
            for (i <- 0 until 3) {
                io.pe_io.L2_N_wraddr(i).valid := true.B
                io.pe_io.L2_N_wraddr(i).bits := addr_calc_local_s4(i)
                io.pe_io.L2_N_wrdata(i).valid := true.B
                io.pe_io.L2_N_wrdata(i).bits := mempot_wr_local(i)
            }
        }.elsewhen(isSouth_s4){
            for (i <- 0 until 3) {
                io.pe_io.L2_S_wraddr(i).valid := true.B
                io.pe_io.L2_S_wraddr(i).bits := addr_calc_local_s4(i)
                io.pe_io.L2_S_wrdata(i).valid := true.B
                io.pe_io.L2_S_wrdata(i).bits := mempot_wr_local(i)
            }
        }.otherwise {
            for (i <- 0 until 3) {
                io.pe_io.L2_N_wraddr(i).valid := false.B
                io.pe_io.L2_N_wrdata(i).valid := false.B
            }
        }
    }

    // --- pipeline data hazards mitigation ---

    val forward_enable = Wire(Vec(9, Bool()))
    val forward_data = Wire(Vec(9, UInt(mempot_width.W)))

    for (i <- 0 until 9) {
        forward_enable(i) := false.B
        forward_data(i) := 0.U
    }

    for (i <- 0 until 9) {
        when(addr_calc_main(i) === addr_calc_main_s4(i) && addr_calc_main_s4(i)(0) === 1.U) {
            forward_enable(i) := true.B
            forward_data(i) := s3_conv(i)
        }

        when(addr_calc_main(i) === addr_calc_main_s3(i) && addr_calc_main_s3(i)(0) === 1.U) {
            pipe_stall := true.B
        }
    }

    for (i <- 0 until 9) {
        when(forward_enable(i)) {
            mempot_rd_main(i) := forward_data(i)
        }
    }

    when(pipe_stall) {
        addr_calc_main := addr_calc_main
    }

}

class BoundaryCheck(dim_width: Int, aeq_width: Int) extends Module {
  val io = IO(new Bundle {
    val i = Input(UInt(((aeq_width - 2)/2).W))
    val se_blk = Input(UInt(dim_width.W))
    val se_col = Input(UInt(dim_width.W))
    val col = Input(UInt(4.W))
    val col_out = Output(UInt(4.W))
    val isNorth = Output(Bool())
    val isSouth = Output(Bool())
  })

  val p1 = (io.col(2) & io.col(1)) | io.col(3)
  val p0 = (~io.col(2) & io.col(1) & io.col(0)) | (io.col(2) & ~io.col(1))
  val new_col = Cat(0.U(2.W), p1, p0)
  io.col_out := new_col

  io.isNorth := (io.i === 0.U) && (new_col === 0.U)
  io.isSouth := (io.i === io.se_blk) && (new_col === io.se_col)
}