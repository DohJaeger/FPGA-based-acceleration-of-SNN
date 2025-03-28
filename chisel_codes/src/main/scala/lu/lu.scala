import chisel3._
import chisel3.util._
import chisel3.util.Decoupled
import java.io.{File, PrintWriter, BufferedWriter, FileWriter}

import IO_DEFS._
import IO_DEFS.NetworkUtils

class lu(num_col: Int, aeq_depth: Int, aeq_width: Int, wm_depth: Int, bias_width: Int, wm_width: Int, mempot_width: Int, tot_blk_width: Int) extends Module {
    val io = IO(new Bundle {
        val lu_io = new LU_IO(num_col, aeq_depth, aeq_width, wm_depth, bias_width, wm_width, tot_blk_width)
    })
    
    NetworkUtils.initLUIO(io.lu_io, num_col)

    // stage-1: read aeq
    val aeqReadStage = Module(new AeqReadStageLU(aeq_depth, aeq_width))
    aeqReadStage.io.lin_en := io.lu_io.lin_en
    io.lu_io.lin_done := aeqReadStage.io.lin_done

    io.lu_io.ai_rdaddr := aeqReadStage.io.ai_rdaddr
    aeqReadStage.io.ai_rddata := io.lu_io.ai_rddata

    val aeq_col_cnt = aeqReadStage.io.aeq_col_cnt

    val col_s2 = RegNext(aeq_col_cnt)

    val i_in = Wire(UInt((aeq_width/2 - 1).W))
    val j_in = Wire(UInt((aeq_width/2 - 1).W))

    val spike_valid_s1 = RegInit(false.B)
    val spike_valid_s2 = RegInit(false.B)

    when(aeqReadStage.io.spike_valid) {
        i_in := aeqReadStage.io.spike_event(aeq_width - 2, aeq_width / 2).asUInt
        j_in := aeqReadStage.io.spike_event(aeq_width / 2 - 1, 1).asUInt
        spike_valid_s1 := true.B
    }.otherwise {
        spike_valid_s1 := false.B
    }

    // stage-2: read weight mem
    val wm_addr = Wire(Vec(10, UInt(log2Ceil(wm_depth).W)))
    val wm_data = Wire(Vec(10, UInt(mempot_width.W)))

    when(spike_valid_s1) {
        for (i <- 0 until 10) {
            wm_addr(i) :=  (col_s2 * io.lu_io.tot_blk) + (i_in * io.lu_io.tot_hor_blk) + j_in
        }
    }
    io.lu_io.wm_rdaddr := wm_addr
    wm_data := io.lu_io.wm_rddata

    spike_valid_s2 := spike_valid_s1

    // stage-3: accumulate
    val neuronMem = Mem(10, UInt(mempot_width.W))

    when(spike_valid_s2) {
        val old_neurons = neuronMem(i_in)
        val new_neurons = Wire(Vec(10, UInt(mempot_width.W)))

        for (i <- 0 until 10) {
            new_neurons(i) := old_neurons(i) + wm_data(i)
        }

        neuronMem(i_in) := new_neurons
    }

}