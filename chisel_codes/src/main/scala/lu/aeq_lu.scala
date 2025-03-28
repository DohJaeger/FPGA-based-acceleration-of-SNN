import chisel3._
import chisel3.util._

class AeqReadStageLU_IO(aeq_depth: Int, aeq_width: Int) extends Bundle {
    val lin_en = Input(Bool())
    val lin_done = Output(Bool())

    val ai_rdaddr = Output(Vec(9, UInt(log2Ceil(aeq_depth).W)))
    val ai_rddata = Input(Vec(9, UInt(aeq_width.W)))

    val aeq_col_cnt = Output(UInt(4.W))
    val spike_event = Output(UInt(aeq_width.W))
    val spike_valid = Output(Bool())
}

class AeqReadStageLU(aeq_depth: Int, aeq_width: Int) extends Module {
    val io = IO(new AeqReadStageLU_IO(aeq_depth, aeq_width))

    val aeq_read_col_sel_counter = RegInit(0.U(4.W))
    val aeq_read_addr = RegInit(0.U(log2Ceil(aeq_depth).W))

    val spike_event_reg = RegInit(0.U(aeq_width.W))
    val spike_valid_reg = RegInit(false.B)
    val lin_done_reg = RegInit(false.B)

    val read_en = WireDefault(false.B)

    io.aeq_col_cnt := aeq_read_col_sel_counter
    io.lin_done := lin_done_reg
    io.spike_event := spike_event_reg
    io.spike_valid := spike_valid_reg

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

    when(io.lin_en && read_en) {
        spike_event_reg := selected_data
        spike_valid_reg := spike_valid

        when(eoq_bit) {
            aeq_read_addr := 0.U
            when(aeq_read_col_sel_counter === 8.U) {
                lin_done_reg := true.B
                aeq_read_col_sel_counter := 0.U
            }.otherwise {
                aeq_read_col_sel_counter := aeq_read_col_sel_counter + 1.U
            }
        }.elsewhen(spike_valid) {
            aeq_read_addr := aeq_read_addr + 1.U
        }
    }.otherwise {
        aeq_read_col_sel_counter := 0.U
        aeq_read_addr := 0.U
    }
}