package IO_DEFS
{

import chisel3._
import chisel3.util._
import chisel3.util.Decoupled

import java.io.{File, PrintWriter, BufferedWriter, FileWriter}
/*
-- AEQ bits -> EOQ_bit(1) + blk_bits + Valid_bit(1)
-- local mem
    ln1 --> north boundary pixels in this tile
    ln2 --> north boundary pixels in the other tile
    ls1 --> south boundary pixels in this tile
    ls2 --> south boundary pixels in the other tile
*/

    class CU_IO(num_col: Int, aeq_depth: Int, aeq_width: Int, mempot_depth: Int, mempot_width: Int, bias_width: Int, kernel_width: Int, dim_width: Int) extends Bundle {

        val mm_rdaddr = Output(Vec(9, UInt(log2Ceil(mempot_depth).W)))
        val mm_rddata = Input(Vec(9, UInt(mempot_width.W)))

        val mm_wraddr = Output(Vec(9, UInt(log2Ceil(mempot_depth).W)))
        val mm_wrdata = Output(Vec(9, UInt(mempot_width.W)))
        val mm_we = Output(Vec(9, Bool()))

        val ln2_rdaddr = Output(Vec(3, UInt(log2Ceil(mempot_depth).W)))
        val ln2_rddata = Input(Vec(3, UInt(mempot_width.W)))

        val ln2_wraddr = Output(Vec(3, UInt(log2Ceil(mempot_depth).W)))
        val ln2_wrdata = Output(Vec(3, UInt(mempot_width.W)))
        val ln2_we = Output(Vec(3, Bool()))

        val ls2_rdaddr = Output(Vec(3, UInt(log2Ceil(mempot_depth).W)))
        val ls2_rddata = Input(Vec(3, UInt(mempot_width.W)))

        val ls2_wraddr = Output(Vec(3, UInt(log2Ceil(mempot_depth).W)))
        val ls2_wrdata = Output(Vec(3, UInt(mempot_width.W)))
        val ls2_we = Output(Vec(3, Bool()))

        val ai_rdaddr = Output(Vec(9, UInt(log2Ceil(aeq_depth).W)))
        val ai_rddata = Input(Vec(9, UInt(aeq_width.W)))

        // Network Parameters
        val conv_en = Input(Bool())
        val rotated_kernel = Input(Vec(num_col, UInt(kernel_width.W)))
        val kSize = Input(UInt(kernel_width.W))
        val T = Input(UInt(dim_width.W))
        val N = Input(UInt(dim_width.W))

        // Output Flags
        val conv_done = Output(Bool())
    }

    class TU_IO(num_col: Int, aeq_depth: Int, aeq_width: Int, mempot_depth: Int, mempot_width: Int, bias_width: Int, kernel_width: Int, dim_width: Int) extends Bundle {

        val mm_rdaddr = Output(Vec(9, UInt(log2Ceil(mempot_depth).W)))
        val mm_rddata = Input(Vec(9, UInt(mempot_width.W)))

        val ln1_rdaddr = Output(Vec(3, UInt(log2Ceil(mempot_depth).W)))
        val ln1_rddata = Input(Vec(3, UInt(mempot_width.W)))

        val ls1_rdaddr = Output(Vec(3, UInt(log2Ceil(mempot_depth).W)))
        val ls1_rddata = Input(Vec(3, UInt(mempot_width.W)))

        val ao_wraddr = Output(Vec(9, UInt(log2Ceil(aeq_depth).W)))
        val ao_wrdata = Output(Vec(9, UInt(aeq_width.W)))
        val ao_we = Output(Vec(9, Bool()))

        // Network Parameters
        val thresh_en = Input(Bool())
        val bias = Input(UInt(mempot_width.W))
        val v_t = Input(UInt(mempot_width.W))
        val T = Input(UInt(dim_width.W))
        val N = Input(UInt(dim_width.W))
        val maxpool_en = Input(Bool())

        val thresh_done = Output(Bool())
    }

    object NetworkUtils {
        def initCUIO(io: CU_IO, num_col: Int): Unit = {
            io.mm_rdaddr := DontCare
            io.mm_wraddr := DontCare
            io.mm_wrdata := DontCare
            io.mm_we := DontCare

            io.ln2_rdaddr := DontCare
            io.ln2_wraddr := DontCare
            io.ln2_wrdata := DontCare
            io.ln2_we := DontCare

            io.ls2_rdaddr := DontCare
            io.ls2_wraddr := DontCare
            io.ls2_wrdata := DontCare
            io.ls2_we := DontCare

            io.ai_rdaddr := DontCare

            io.conv_done := DontCare
        }

        def initTUIO(io: TU_IO, num_col: Int): Unit = {
            io.mm_rdaddr := DontCare

            io.ln1_rdaddr := DontCare
            io.ls1_rdaddr := DontCare

            io.ao_wraddr := DontCare
            io.ao_wrdata := DontCare
            io.ao_we := DontCare

            io.thresh_done := DontCare
        }
    }

    object KernelUtils {
        def selectKernel(input_idx: UInt, rotated_kernel: Vec[UInt]): Vec[UInt] = {
            val kernel = VecInit(Seq.fill(9)(0.U(rotated_kernel(0).getWidth.W)))

            switch(input_idx) {
                is(0.U) { kernel := VecInit(rotated_kernel(4), rotated_kernel(5), rotated_kernel(3),
                                            rotated_kernel(7), rotated_kernel(8), rotated_kernel(6),
                                            rotated_kernel(1), rotated_kernel(2), rotated_kernel(0)) }

                is(1.U) { kernel := VecInit(rotated_kernel(3), rotated_kernel(4), rotated_kernel(5),
                                            rotated_kernel(6), rotated_kernel(7), rotated_kernel(8),
                                            rotated_kernel(0), rotated_kernel(1), rotated_kernel(2)) }

                is(2.U) { kernel := VecInit(rotated_kernel(5), rotated_kernel(3), rotated_kernel(4),
                                            rotated_kernel(8), rotated_kernel(6), rotated_kernel(7),
                                            rotated_kernel(2), rotated_kernel(0), rotated_kernel(1)) }

                is(3.U) { kernel := VecInit(rotated_kernel(1), rotated_kernel(2), rotated_kernel(0),
                                            rotated_kernel(4), rotated_kernel(5), rotated_kernel(3),
                                            rotated_kernel(7), rotated_kernel(8), rotated_kernel(6)) }

                is(4.U) { kernel := VecInit(rotated_kernel(0), rotated_kernel(1), rotated_kernel(2),
                                            rotated_kernel(3), rotated_kernel(4), rotated_kernel(5),
                                            rotated_kernel(6), rotated_kernel(7), rotated_kernel(8)) }

                is(5.U) { kernel := VecInit(rotated_kernel(2), rotated_kernel(0), rotated_kernel(1),
                                            rotated_kernel(5), rotated_kernel(3), rotated_kernel(4),
                                            rotated_kernel(8), rotated_kernel(6), rotated_kernel(7)) }

                is(6.U) { kernel := VecInit(rotated_kernel(7), rotated_kernel(8), rotated_kernel(6),
                                            rotated_kernel(1), rotated_kernel(2), rotated_kernel(0),
                                            rotated_kernel(4), rotated_kernel(5), rotated_kernel(3)) }

                is(7.U) { kernel := VecInit(rotated_kernel(6), rotated_kernel(7), rotated_kernel(8),
                                            rotated_kernel(0), rotated_kernel(1), rotated_kernel(2),
                                            rotated_kernel(3), rotated_kernel(4), rotated_kernel(5)) }

                is(8.U) { kernel := VecInit(rotated_kernel(8), rotated_kernel(6), rotated_kernel(7),
                                            rotated_kernel(2), rotated_kernel(0), rotated_kernel(1),
                                            rotated_kernel(5), rotated_kernel(3), rotated_kernel(4)) }
                }
                
            kernel
        }
    }
}