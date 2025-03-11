package PE_IO_Defs
{

import chisel3._
import chisel3.util._
import chisel3.util.Decoupled

/*
-- AEQ bits -> EOQ_bit(1) + blk_bits + Valid_bit(1)
-- local mem
    L1_N --> north boundary pixels in this tile
    L2_N --> north boundary pixels in the other tile
    L1_S --> south boundary pixels in the other tile
    L2_S --> south boundary pixels in the other tile
*/

class PE_IO(num_col: Int, aeq_depth: Int, aeq_width: Int, mempot_depth: Int, mempot_width: Int, bias_width: Int, kernel_width: Int, dim_width: Int) extends Bundle {

    val main_mempot_rdaddr = Vec(num_col, Decoupled(UInt(log2Ceil(mempot_depth).W)))
    val main_mempot_rddata = Vec(num_col, Flipped(Decoupled(UInt(mempot_width.W))))

    val main_mempot_wraddr = Vec(num_col, Decoupled(UInt(log2Ceil(mempot_depth).W)))
    val main_mempot_wrdata = Vec(num_col, Decoupled(UInt(mempot_width.W)))

    val L2_N_rdaddr = Vec(num_col, Decoupled(UInt(log2Ceil(mempot_depth).W)))
    val L2_N_rddata = Vec(num_col, Flipped(Decoupled(UInt(mempot_width.W))))

    val L2_N_wraddr = Vec(num_col, Decoupled(UInt(log2Ceil(mempot_depth).W)))
    val L2_N_wrdata = Vec(num_col, Decoupled(UInt(mempot_width.W)))

    val L2_S_rdaddr = Vec(num_col, Decoupled(UInt(log2Ceil(mempot_depth).W)))
    val L2_S_rddata = Vec(num_col, Flipped(Decoupled(UInt(mempot_width.W))))

    val L2_S_wraddr = Vec(num_col, Decoupled(UInt(log2Ceil(mempot_depth).W)))
    val L2_S_wrdata = Vec(num_col, Decoupled(UInt(mempot_width.W)))

    val L1_N_rdaddr = Vec(num_col, Decoupled(UInt(log2Ceil(mempot_depth).W)))
    val L1_N_rddata = Vec(num_col, Flipped(Decoupled(UInt(mempot_width.W))))

    val L1_S_rdaddr = Vec(num_col, Decoupled(UInt(log2Ceil(mempot_depth).W)))
    val L1_S_rddata = Vec(num_col, Flipped(Decoupled(UInt(mempot_width.W))))

    // // AEQ Port A -> Read from AEQ
    // val aeq_portA_rdaddr = Decoupled(UInt(log2Ceil(aeq_depth).W))
    // val aeq_portA_rddata = Flipped(Decoupled(UInt(aeq_width.W)))

    // // AEQ Port B -> Write to AEQ
    // val aeq_portB_wraddr = Decoupled(UInt(log2Ceil(aeq_depth).W))
    // val aeq_portB_wrdata = Decoupled(UInt(aeq_width.W))

    val aeq_in_rdaddr = Vec(num_col, Decoupled(UInt(log2Ceil(mempot_depth).W)))
    val aeq_in_rddata = Vec(num_col, Flipped(Decoupled(UInt(mempot_width.W))))

    val aeq_out_wraddr = Vec(num_col, Decoupled(UInt(log2Ceil(mempot_depth).W)))
    val aeq_out_wrdata = Vec(num_col, Decoupled(UInt(mempot_width.W)))

    // Network Parameters
    val thresh_en = Input(Bool())
    val conv_en = Input(Bool())
    val linear_en = Input(Bool())
    val bias = Input(UInt(mempot_width.W))
    val v_t = Input(UInt(mempot_width.W))
    val rotated_kernel = Input(Vec(num_col, UInt(kernel_width.W)))
    val kSize = Input(UInt(kernel_width.W))
    val T = Input(UInt(dim_width.W))
    val N = Input(UInt(dim_width.W))

    // Output Flags
    val conv_done = Output(Bool())
    val thresh_done = Output(Bool())
    val linear_done = Output(Bool())
}

object NetworkUtils {
    def initNetworkIO(io: PE_IO, num_col: Int): Unit = {
        for (i <- 0 until num_col) {
            io.main_mempot_rdaddr(i).valid := false.B
            io.main_mempot_rdaddr(i).bits := 0.U
            io.main_mempot_rddata(i).ready := false.B

            io.main_mempot_wraddr(i).valid := false.B
            io.main_mempot_wraddr(i).bits := 0.U
            io.main_mempot_wrdata(i).valid := false.B
            io.main_mempot_wrdata(i).bits := 0.U
        }

        for (i <- 0 until num_col) {
            io.L2_N_rdaddr(i).valid := false.B
            io.L2_N_rdaddr(i).bits := 0.U
            io.L2_N_rddata(i).ready := false.B

            io.L2_N_wraddr(i).valid := false.B
            io.L2_N_wraddr(i).bits := 0.U
            io.L2_N_wrdata(i).valid := false.B
            io.L2_N_wrdata(i).bits := 0.U
        }

        for (i <- 0 until num_col) {
            io.L2_S_rdaddr(i).valid := false.B
            io.L2_S_rdaddr(i).bits := 0.U
            io.L2_S_rddata(i).ready := false.B

            io.L2_S_wraddr(i).valid := false.B
            io.L2_S_wraddr(i).bits := 0.U
            io.L2_S_wrdata(i).valid := false.B
            io.L2_S_wrdata(i).bits := 0.U
        }

        for (i <- 0 until num_col) {
            io.L1_N_rdaddr(i).valid := false.B
            io.L1_N_rdaddr(i).bits := 0.U
            io.L1_N_rddata(i).ready := false.B
        }

        for (i <- 0 until num_col) {
            io.L1_S_rdaddr(i).valid := false.B
            io.L1_S_rdaddr(i).bits := 0.U
            io.L1_S_rddata(i).ready := false.B
        }

        for (i <- 0 until num_col) {
            io.aeq_in_rdaddr(i).valid := false.B
            io.aeq_in_rdaddr(i).bits := 0.U
            io.aeq_in_rddata(i).ready := false.B

            io.aeq_out_wraddr(i).valid := false.B
            io.aeq_out_wraddr(i).bits := 0.U
            io.aeq_out_wrdata(i).valid := false.B
            io.aeq_out_wrdata(i).bits := 0.U
        }

        io.conv_done := false.B
        io.thresh_done := false.B
        io.linear_done := false.B
    }
}

}