import chisel3._
import chisel3.util._
import chisel3.util.Decoupled
import java.io.{File, PrintWriter, BufferedWriter, FileWriter}

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

class AddrCalc(aeq_width: Int) extends Module {
	val io = IO(new Bundle {
		val input_idx = Input(UInt(4.W))    // input col
		val i = Input(UInt((aeq_width/2 - 1).W))    // input block row
		val j = Input(UInt((aeq_width/2 - 1).W))    // input block col
		val new_i = Output(Vec(9, UInt((aeq_width/2 - 1).W)))   // neighbouring pixels' block's row
		val new_j = Output(Vec(9, UInt((aeq_width/2 - 1).W)))   // neighbouring pixels' block's col
	})

    io.new_i.foreach(_ := DontCare)
    io.new_j.foreach(_ := DontCare)

	when(io.input_idx === 2.U || io.input_idx === 5.U || io.input_idx === 8.U) {
		io.new_j(0) := io.j + 1.U
        io.new_j(3) := io.j + 1.U
        io.new_j(6) := io.j + 1.U
	}.otherwise{
        io.new_j(0) := io.j
        io.new_j(3) := io.j
        io.new_j(6) := io.j
    }

	when(io.input_idx === 6.U || io.input_idx === 7.U || io.input_idx === 8.U) {
		io.new_i(0) := io.i + 1.U
        io.new_i(1) := io.i + 1.U
        io.new_i(2) := io.i + 1.U
	}.otherwise{
        io.new_i(0) := io.i
        io.new_i(1) := io.i
        io.new_i(2) := io.i
    }

	when(io.input_idx === 0.U || io.input_idx === 3.U || io.input_idx === 6.U) {
		io.new_j(2) := io.j - 1.U
        io.new_j(5) := io.j - 1.U
        io.new_j(8) := io.j - 1.U
	}.otherwise{
        io.new_j(2) := io.j
        io.new_j(5) := io.j
        io.new_j(8) := io.j
    }

	when(io.input_idx === 0.U || io.input_idx === 1.U || io.input_idx === 2.U) {
		io.new_i(6) := io.i - 1.U
        io.new_i(7) := io.i - 1.U
        io.new_i(8) := io.i - 1.U
	}.otherwise{
        io.new_i(6) := io.i
        io.new_i(7) := io.i
        io.new_i(8) := io.i
    }

    io.new_j(1) := io.j

	io.new_i(3) := io.i

	io.new_i(4) := io.i
	io.new_j(4) := io.j

	io.new_i(5) := io.i
    io.new_j(7) := io.j
}