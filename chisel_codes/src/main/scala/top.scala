import chisel3._
import chisel3.util._
import chisel3.util.Decoupled
import java.io.{File, PrintWriter, BufferedWriter, FileWriter}


class top(num_col: Int, mempot_width: Int, mempot_depth: Int, aeq_width: Int, aeq_depth: Int, kernel_width: Int, bias_width: Int, dim_width: Int, blk_dim_width: Int) extends Module {
    val io = IO(new Bundle {

        val bias = Input(UInt(mempot_width.W))
        val kSize = Input(UInt(kernel_width.W))
        val v_t = Input(UInt(mempot_width.W))
        val conv_en = Input(Bool())
        val thresh_en = Input(Bool())
        val maxpool_en = Input(Bool())
        val rotated_kernel = Input(Vec(num_col, UInt(kernel_width.W)))

        val ao_dout = Output(Vec(9, UInt(log2Ceil(aeq_width).W)))
        // val ln2_dout = Output(Vec(3, UInt(log2Ceil(aeq_width).W)))

        val T = Input(UInt(dim_width.W))
        val N = Input(UInt(dim_width.W))
        val conv_done = Output(Bool())
        val thresh_done = Output(Bool())
    })

    val tile_inst = Module(new tile(num_col, mempot_width, mempot_depth, aeq_width, aeq_depth, kernel_width, bias_width, dim_width, blk_dim_width))

    io.ao_dout := tile_inst.io.ao_dout

    val ln2 = Array.fill(3)(null: tdpb)
	val ls2 = Array.fill(3)(null: tdpb)

    for (i <- 0 until 3) {
		ln2(i) = Module(new tdpb(9, 10))
		ls2(i) = Module(new tdpb(9, 10))

        // ln2(i).io := DontCare
        // ls2(i).io := DontCare
	}

    // === Local North Mem ===
    for (i <- 0 until 3) {
        ln2(i).io.clka := clock
        ln2(i).io.clkb := clock
        ln2(i).io.ena := true.B
        ln2(i).io.enb := true.B
        ln2(i).io.wea := true.B
        ln2(i).io.web := tile_inst.io.ln2_we(i)
        ln2(i).io.addra := DontCare
        ln2(i).io.addrb := Mux(tile_inst.io.ln2_we(i), tile_inst.io.ln2_wraddr(i), tile_inst.io.ln2_rdaddr(i))
        ln2(i).io.dia := 0.U
        ln2(i).io.dib := tile_inst.io.ln2_wrdata(i)
        tile_inst.io.ln2_rddata(i) := ln2(i).io.dob
        // io.ln2_dout(i) := ln2(i).io.dob //check
    }

    // === Local South Mem ===
    for (i <- 0 until 3) {
        ls2(i).io.clka := clock
        ls2(i).io.clkb := clock
        ls2(i).io.ena := true.B
        ls2(i).io.enb := true.B
        ls2(i).io.wea := true.B
        ls2(i).io.web := tile_inst.io.ls2_we(i)
        ls2(i).io.addra := DontCare
        ls2(i).io.addrb := Mux(tile_inst.io.ls2_we(i), tile_inst.io.ls2_wraddr(i), tile_inst.io.ls2_rdaddr(i))
        ls2(i).io.dia := 0.U
        ls2(i).io.dib := tile_inst.io.ls2_wrdata(i)
        tile_inst.io.ls2_rddata(i) := ls2(i).io.dob
    }

    tile_inst.io.conv_en := io.conv_en
    tile_inst.io.thresh_en := io.thresh_en
    tile_inst.io.maxpool_en := io.maxpool_en
    tile_inst.io.bias := io.bias
    tile_inst.io.v_t := io.v_t
    tile_inst.io.rotated_kernel := io.rotated_kernel
    tile_inst.io.kSize := io.kSize
    tile_inst.io.T := io.T
    tile_inst.io.N := io.N

    io.conv_done := tile_inst.io.conv_done
    io.thresh_done := tile_inst.io.thresh_done

}

object top extends App {
  val verilogString = chisel3.getVerilogString(new top(num_col = 9, mempot_width = 8, mempot_depth = 1024, aeq_width = 10, aeq_depth = 1024, kernel_width = 8, bias_width = 8, dim_width = 8, blk_dim_width = 8))
  val verilogFile = new File("top.sv")
  val writer = new PrintWriter(verilogFile)
  writer.write(verilogString)
  writer.close()
}