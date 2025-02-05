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

class PE_IO(num_col: Int, aeq_depth: Int, aeq_width: Int, mempot_depth: Int, mempot_width: Int, bias_width: Int, kernel_width: Int) extends Bundle {

    // Main Memory BRAM Port A -> Read from BRAM
    val main_mempot_portA_rdaddr = Vec(num_col, Decoupled(UInt(log2Ceil(mempot_depth).W)))
    val main_mempot_portA_rddata = Vec(num_col, Flipped(Decoupled(UInt(mempot_width.W))))

    // Main Memory BRAM Port B -> Write to BRAM
    val main_mempot_portB_wraddr = Vec(num_col, Decoupled(UInt(log2Ceil(mempot_depth).W)))
    val main_mempot_portB_wrdata = Vec(num_col, Decoupled(UInt(mempot_width.W)))

    // Local Memory L2_N BRAM Port A -> Read from BRAM (parallel)
    val L2_N_portA_rdaddr = Vec(num_col, Decoupled(UInt(log2Ceil(mempot_depth).W)))
    val L2_N_portA_rddata = Vec(num_col, Flipped(Decoupled(UInt(mempot_width.W))))

    // Local Memory L2_N BRAM Port B -> Write to BRAM (parallel)
    val L2_N_portB_wraddr = Vec(num_col, Decoupled(UInt(log2Ceil(mempot_depth).W)))
    val L2_N_portB_wrdata = Vec(num_col, Decoupled(UInt(mempot_width.W)))

    // Local Memory L2_S BRAM Port A -> Read from BRAM (parallel)
    val L2_S_portA_rdaddr = Vec(num_col, Decoupled(UInt(log2Ceil(mempot_depth).W)))
    val L2_S_portA_rddata = Vec(num_col, Flipped(Decoupled(UInt(mempot_width.W))))

    // Local Memory L2_S BRAM Port B -> Write to BRAM (parallel)
    val L2_S_portB_wraddr = Vec(num_col, Decoupled(UInt(log2Ceil(mempot_depth).W)))
    val L2_S_portB_wrdata = Vec(num_col, Decoupled(UInt(mempot_width.W)))

    // Local Memory L1_N BRAM Port A -> Read from BRAM (parallel)
    val L1_N_portA_rdaddr = Vec(num_col, Decoupled(UInt(log2Ceil(mempot_depth).W)))
    val L1_N_portA_rddata = Vec(num_col, Flipped(Decoupled(UInt(mempot_width.W))))

    // Local Memory L1_S BRAM Port A -> Read from BRAM (parallel)
    val L1_S_portA_rdaddr = Vec(num_col, Decoupled(UInt(log2Ceil(mempot_depth).W)))
    val L1_S_portA_rddata = Vec(num_col, Flipped(Decoupled(UInt(mempot_width.W))))

    // AEQ Port A -> Read from AEQ
    val aeq_portA_rdaddr = Decoupled(UInt(log2Ceil(aeq_depth).W))
    val aeq_portA_rddata = Flipped(Decoupled(UInt(aeq_width.W)))

    // AEQ Port B -> Write to AEQ
    val aeq_portB_wraddr = Decoupled(UInt(log2Ceil(aeq_depth).W))
    val aeq_portB_wrdata = Decoupled(UInt(aeq_width.W))

    // Network Parameters
    val thresh_en = Input(Bool())
    val conv_en = Input(Bool())
    val linear_en = Input(Bool())
    val bias = Input(Vec(num_col, UInt(bias_width.W)))
    val v_t = Input(UInt(mempot_width.W))
    val rotated_kernel = Input(Vec(num_col, UInt(kernel_width.W)))
    val kSize = Input(UInt(kernel_width.W))

    // Output Flags
    val conv_done = Output(Bool())
    val thresh_done = Output(Bool())
    val linear_done = Output(Bool())
}

object NetworkUtils {
    def initNetworkIO(io: PE_IO, num_col: Int): Unit = {
        // Main Memory
        for (i <- 0 until num_col) {
            io.main_mempot_portA_rdaddr(i).valid := false.B
            io.main_mempot_portA_rdaddr(i).bits := 0.U
            io.main_mempot_portA_rddata(i).ready := false.B

            io.main_mempot_portB_wraddr(i).valid := false.B
            io.main_mempot_portB_wraddr(i).bits := 0.U
            io.main_mempot_portB_wrdata(i).valid := false.B
            io.main_mempot_portB_wrdata(i).bits := 0.U
        }

        // Local Memory L2_N (parallel)
        for (i <- 0 until num_col) {
            io.L2_N_portA_rdaddr(i).valid := false.B
            io.L2_N_portA_rdaddr(i).bits := 0.U
            io.L2_N_portA_rddata(i).ready := false.B

            io.L2_N_portB_wraddr(i).valid := false.B
            io.L2_N_portB_wraddr(i).bits := 0.U
            io.L2_N_portB_wrdata(i).valid := false.B
            io.L2_N_portB_wrdata(i).bits := 0.U
        }

        // Local Memory L2_S (parallel)
        for (i <- 0 until num_col) {
            io.L2_S_portA_rdaddr(i).valid := false.B
            io.L2_S_portA_rdaddr(i).bits := 0.U
            io.L2_S_portA_rddata(i).ready := false.B

            io.L2_S_portB_wraddr(i).valid := false.B
            io.L2_S_portB_wraddr(i).bits := 0.U
            io.L2_S_portB_wrdata(i).valid := false.B
            io.L2_S_portB_wrdata(i).bits := 0.U
        }

        // Local Memory L1_N (parallel)
        for (i <- 0 until num_col) {
            io.L1_N_portA_rdaddr(i).valid := false.B
            io.L1_N_portA_rdaddr(i).bits := 0.U
            io.L1_N_portA_rddata(i).ready := false.B
        }

        // Local Memory L1_S (parallel)
        for (i <- 0 until num_col) {
            io.L1_S_portA_rdaddr(i).valid := false.B
            io.L1_S_portA_rdaddr(i).bits := 0.U
            io.L1_S_portA_rddata(i).ready := false.B
        }

        // AEQ Port A
        io.aeq_portA_rdaddr.valid := false.B
        io.aeq_portA_rdaddr.bits := 0.U
        io.aeq_portA_rddata.ready := false.B

        // AEQ Port B
        io.aeq_portB_wraddr.valid := false.B
        io.aeq_portB_wraddr.bits := 0.U
        io.aeq_portB_wrdata.valid := false.B
        io.aeq_portB_wrdata.bits := 0.U

        // Output Flags
        io.conv_done := false.B
        io.thresh_done := false.B
        io.linear_done := false.B
    }
}

}