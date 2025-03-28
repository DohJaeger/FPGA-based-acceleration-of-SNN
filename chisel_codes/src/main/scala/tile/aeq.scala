import chisel3._
import chisel3.util._
import chisel3.util.Decoupled
import java.io.{File, PrintWriter, BufferedWriter, FileWriter}

import IO_DEFS._
import IO_DEFS.{NetworkUtils, KernelUtils}

class AeqReadStageIO(aeq_depth: Int, aeq_width: Int) extends Bundle {
    val conv_en = Input(Bool())
    val pipe_stall = Input(Bool())
    val conv_done = Output(Bool())

    val ai_rdaddr = Output(Vec(9, UInt(log2Ceil(aeq_depth).W)))
    val ai_rddata = Input(Vec(9, UInt(aeq_width.W)))

    val aeq_col_cnt = Output(UInt(4.W))
    val spike_event = Output(UInt(aeq_width.W))
    val spike_valid = Output(Bool())
    // val eoq_bit = Output(Bool())
}

class AeqReadStage(aeq_depth: Int, aeq_width: Int) extends Module {
    val io = IO(new AeqReadStageIO(aeq_depth, aeq_width))

    val aeq_read_col_sel_counter = RegInit(0.U(4.W))
    val aeq_read_addr = RegInit(0.U(log2Ceil(aeq_depth).W))

    val spike_event_reg = RegInit(0.U(aeq_width.W))
    val spike_valid_reg = RegInit(false.B)
    val eoq_bit_reg = RegInit(false.B)
    val conv_done_reg = RegInit(false.B)

    val read_en = WireDefault(false.B)

    io.aeq_col_cnt := aeq_read_col_sel_counter
    io.conv_done := conv_done_reg

    io.spike_event := spike_event_reg
    io.spike_valid := spike_valid_reg
    // io.eoq_bit := eoq_bit_reg

    for (i <- 0 until 9) {
        io.ai_rdaddr(i) := 0.U
    }

    when(aeq_read_col_sel_counter < 9.U) {
        io.ai_rdaddr(aeq_read_col_sel_counter) := aeq_read_addr
        read_en := true.B
    }

    val selected_data = Wire(UInt(aeq_width.W))
    selected_data := 0.U
    for (i <- 0 until 9) {
        when(aeq_read_col_sel_counter === i.U) {
            selected_data := io.ai_rddata(i)
        }
    }

    val spike_valid = selected_data(0)
    val eoq_bit = selected_data(aeq_width - 1)

    when(io.conv_en && read_en) {
        spike_event_reg := selected_data
        spike_valid_reg := spike_valid
        eoq_bit_reg := eoq_bit

        when(eoq_bit) {
            aeq_read_addr := 0.U
            when(aeq_read_col_sel_counter === 8.U) {
                conv_done_reg := true.B
                aeq_read_col_sel_counter := 0.U
            }.otherwise {
                when(!io.pipe_stall){
                    aeq_read_col_sel_counter := aeq_read_col_sel_counter + 1.U
                }.otherwise{
                    aeq_read_col_sel_counter := aeq_read_col_sel_counter
                }
            }
        }.elsewhen(spike_valid) {
            when(!io.pipe_stall){
                aeq_read_addr := aeq_read_addr + 1.U
            }.otherwise{
                aeq_read_addr := aeq_read_addr
            }
        }
    }.otherwise {
        aeq_read_col_sel_counter := 0.U
        aeq_read_addr := 0.U
    }
}


class TopLevelModule(aeq_depth: Int, aeq_width: Int) extends Module {
    val io = IO(new Bundle {
        val conv_en = Input(Bool())
        val pipe_stall = Input(Bool())
        val conv_done = Output(Bool())
        val spike_event = Output(UInt(aeq_width.W))
        val spike_valid = Output(Bool())
        // val eoq_bit = Output(Bool())
    })

    // Instantiate AEQ Read Stage
    val aeqReadStage = Module(new AeqReadStage(aeq_depth, aeq_width))

    aeqReadStage.io.conv_en := io.conv_en
    io.conv_done := aeqReadStage.io.conv_done

    io.spike_event := aeqReadStage.io.spike_event
    io.spike_valid := aeqReadStage.io.spike_valid
    // io.eoq_bit := aeqReadStage.io.eoq_bit

    val ai  = Array.fill(9)(null: tdpb_init)
    for (i <- 0 until 9) {
		ai(i) = Module(new tdpb_init(10, 10, s"ai_$i.mem"))

        ai(i).io := DontCare
	}


    val ai_rdaddr = aeqReadStage.io.ai_rdaddr
    val ai_rddata_vec = Wire(Vec(9, UInt(aeq_width.W)))

    val aeq_col_cnt = aeqReadStage.io.aeq_col_cnt


    for (i <- 0 until 9) {
        ai(i).io.clka := clock
        ai(i).io.ena := true.B
        ai(i).io.wea := false.B
        ai(i).io.addra := ai_rdaddr(i)
        ai(i).io.dia := 0.U
        ai_rddata_vec(i) := ai(i).io.doa
    }

    aeqReadStage.io.ai_rddata := ai_rddata_vec
    aeqReadStage.io.pipe_stall := io.pipe_stall
}


object aeq extends App {
  val verilogString = chisel3.getVerilogString(new TopLevelModule(aeq_width = 10, aeq_depth = 1024))
  val verilogFile = new File("aeq.sv")
  val writer = new PrintWriter(verilogFile)
  writer.write(verilogString)
  writer.close()
}