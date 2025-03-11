import chisel3._
import chisel3.util._
import chisel3.util.Decoupled
import java.io.{File, PrintWriter, BufferedWriter, FileWriter}

import PE_IO_Defs._
import PE_IO_Defs.NetworkUtils


class tu3(num_col: Int, mempot_width: Int, mempot_depth: Int, aeq_width: Int, aeq_depth: Int, kernel_width: Int, bias_width: Int, dim_width: Int, blk_dim_width: Int) extends Module {
    val io = IO(new Bundle {
        val tu_io = new PE_IO(num_col, aeq_depth, aeq_width, mempot_depth, mempot_width, bias_width, kernel_width, dim_width)
        val maxpool_en = Input(Bool())
    })
    
    NetworkUtils.initNetworkIO(io.tu_io, num_col)

    val i_max = (io.tu_io.N - 1.U)/3.U
    val j_max = (io.tu_io.T - 1.U)/3.U
    val se_col = (io.tu_io.T - 1.U) % 3.U

    // stage 1: mempot access
    val i_cnt = RegInit(0.U(log2Ceil((aeq_width / 2 - 1)).W))
    val j_cnt = RegInit(0.U(log2Ceil(aeq_width / 2 - 1).W))
    val addr_write = Reg(UInt((aeq_width - 2).W))
    val addr_write_s3 = RegNext(RegNext(addr_write))
    val i_cnt_s3 = RegNext(RegNext(i_cnt))
    val j_cnt_s3 = RegNext(RegNext(j_cnt))

    addr_write := Cat(i_cnt, j_cnt)

    val mempot_rd_main = Reg(Vec(9, UInt(mempot_width.W)))
    val mempot_rd_local = Reg(Vec(3, UInt(mempot_width.W)))

    val mempot_rd_local_valid = RegInit(false.B)

    val isNorth = Wire(Bool())
    val isSouth = Wire(Bool())

    isNorth := (i_cnt === 0.U)
    isSouth := (j_cnt === j_max)

    val isNorth_s2 = RegNext(isNorth)
    val isSouth_s2 = RegNext(isSouth)

    j_cnt := Mux((j_cnt <= j_max) && (i_cnt === i_max), j_cnt + 1.U, j_cnt)

    // mem access
    when(io.tu_io.thresh_en && j_cnt <= j_max) {
        for (i <- 0 until 9) {
            io.tu_io.main_mempot_rdaddr(i).valid := true.B
            io.tu_io.main_mempot_rdaddr(i).bits := i_cnt + j_cnt * j_max
            when(io.tu_io.main_mempot_rddata(i).valid) {
                mempot_rd_main(i) := io.tu_io.main_mempot_rddata(i).bits
            }.otherwise {
                mempot_rd_main(i) := 0.U
            }
        }

        when(isNorth) {
            mempot_rd_local_valid := true.B

            for (i <- 0 until 3) {
                io.tu_io.L1_N_rdaddr(i).valid := true.B
                io.tu_io.L1_N_rdaddr(i).bits := j_cnt

                when(io.tu_io.L1_N_rddata(i).valid) {
                    mempot_rd_local(i) := io.tu_io.L1_N_rddata(i).bits
                }.otherwise {
                    mempot_rd_local(i) := 0.U
                }
            }
        }.elsewhen(isSouth){
            mempot_rd_local_valid := true.B

            for (i <- 0 until 3) {
                io.tu_io.L1_S_rdaddr(i).valid := true.B
                io.tu_io.L1_S_rdaddr(i).bits := j_cnt

                when(io.tu_io.L1_S_rddata(i).valid) {
                    mempot_rd_local(i) := io.tu_io.L1_S_rddata(i).bits
                }.otherwise {
                    mempot_rd_local(i) := 0.U
                }
            }
        }.otherwise {
            for (i <- 0 until 3) {
                mempot_rd_local(i) := 0.U
            }
        }

        i_cnt := i_cnt + 1.U

    }.otherwise {
        for (i <- 0 until 9) {
            mempot_rd_main(i) := 0.U
        }
        for (i <- 0 until 3) {
            mempot_rd_local(i) := 0.U
        }
    }

    // maxpool addr calc
    val row_component_i = RegInit(0.U(3.W))
    val row_component_j = RegInit(0.U(3.W))
    val addr_component_i = RegInit(0.U(log2Ceil(blk_dim_width).W))
    val addr_component_j = RegInit(0.U(log2Ceil(blk_dim_width).W))
    val maxpool_row = RegInit(0.U(log2Ceil(blk_dim_width).W))

    val maxpool_row_s3 = RegNext(RegNext(maxpool_row))

    when(io.tu_io.thresh_en) {

        when(i_cnt === i_max) {
            row_component_i := 0.U
            addr_component_i := 0.U

        }.elsewhen(row_component_i === 2.U) {
            row_component_i := 0.U
            addr_component_i := addr_component_i + 1.U

        }.otherwise {
            row_component_i := row_component_i + 1.U
        }

        when(j_cnt === j_max) {
            row_component_j := 0.U
            addr_component_j := addr_component_j + 1.U
        }.elsewhen(row_component_j === 6.U) {
            row_component_j := 0.U
            addr_component_j := addr_component_j + 1.U
        }.otherwise {
            row_component_j := row_component_j + 3.U
        }

        maxpool_row := row_component_i + row_component_j
    }

    // stage 2: add (local + main + bias)
    val mempot_biased = Reg(Vec(9, UInt(mempot_width.W)))

    when(isNorth_s2){
        for (i <- 0 until 3){
            mempot_biased(i) := mempot_rd_main(i) + mempot_rd_local(i) + io.tu_io.bias
        }

        for (i <- 3 until 9){
            mempot_biased(i) := mempot_rd_main(i) + io.tu_io.bias
        }
    }.elsewhen(isSouth_s2){
        when(se_col === 0.U){
            for (i <- 0 until 3){
                mempot_biased(i) := mempot_rd_main(i) + mempot_rd_local(i) + io.tu_io.bias
            }

            for (i <- 3 until 9){
                mempot_biased(i) := mempot_rd_main(i) + io.tu_io.bias
            }
        }.elsewhen(se_col === 1.U){
            for (i <- 0 until 3){
                mempot_biased(i) := mempot_rd_main(i) + io.tu_io.bias
            }

            for (i <- 3 until 6){
                mempot_biased(i) := mempot_rd_main(i) + mempot_rd_local(i) + io.tu_io.bias
            }

            for (i <- 6 until 9){
                mempot_biased(i) := mempot_rd_main(i) + io.tu_io.bias
            }
        }.otherwise{
            for (i <- 0 until 3){
                mempot_biased(i) := mempot_rd_main(i) + io.tu_io.bias
            }

            for (i <- 3 until 6){
                mempot_biased(i) := mempot_rd_main(i) + io.tu_io.bias
            }

            for (i <- 6 until 9){
                mempot_biased(i) := mempot_rd_main(i) + mempot_rd_local(i) + io.tu_io.bias
            }

        }
    }

    // stage 3: comparator
    val spike_out = Reg(Vec(9, Bool()))

    for(i <- 0 until 9){
        spike_out(i) := Mux(mempot_biased(i) >= io.tu_io.v_t, true.B, false.B)
    }

    val spike_or = RegInit(false.B)
    spike_or := spike_out.reduce(_ | _)

    // stage 4: write aeq out
    when(spike_or) {
        when(io.maxpool_en) {
            // maxpool enabled
            io.tu_io.aeq_out_wraddr(maxpool_row_s3).valid := true.B
            io.tu_io.aeq_out_wraddr(maxpool_row_s3).bits := i_cnt_s3 + j_max * j_cnt_s3

            io.tu_io.aeq_out_wrdata(maxpool_row_s3).valid := true.B
            io.tu_io.aeq_out_wrdata(maxpool_row_s3).bits := Cat((i_cnt_s3 === i_max) && (j_cnt_s3 === j_max), addr_write_s3, 1.U)
        }.otherwise {
            // maxpool disabled
            for (i <- 0 until 9) {
                io.tu_io.aeq_out_wraddr(i).valid := spike_out(i)
                io.tu_io.aeq_out_wraddr(i).bits := addr_write_s3

                io.tu_io.aeq_out_wrdata(i).valid := spike_out(i)
                io.tu_io.aeq_out_wrdata(i).bits := Cat((i_cnt_s3 === i_max) && (j_cnt_s3 === j_max), addr_write_s3, 1.U)
            }
        }
    }.otherwise {
        for (i <- 0 until num_col) {
            io.tu_io.aeq_out_wraddr(i).valid := false.B
            io.tu_io.aeq_out_wrdata(i).valid := false.B
        }
    }

}