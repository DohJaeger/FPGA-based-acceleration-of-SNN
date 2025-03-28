import chisel3._
import chisel3.util._
import chisel3.util.Decoupled
import java.io.{File, PrintWriter, BufferedWriter, FileWriter}


class tile(num_col: Int, mempot_width: Int, mempot_depth: Int, aeq_width: Int, aeq_depth: Int, kernel_width: Int, bias_width: Int, dim_width: Int, blk_dim_width: Int) extends Module {
    val io = IO(new Bundle {
        val conv_en = Input(Bool())
        val thresh_en = Input(Bool())
        val maxpool_en = Input(Bool())

        // Network Params
        val bias = Input(UInt(mempot_width.W))
        val v_t = Input(UInt(mempot_width.W))
        val rotated_kernel = Input(Vec(num_col, UInt(kernel_width.W)))
        val kSize = Input(UInt(kernel_width.W))
        val T = Input(UInt(dim_width.W))
        val N = Input(UInt(dim_width.W))

        val conv_done = Output(Bool())
        val thresh_done = Output(Bool())

        val ao_dout = Output(Vec(9, UInt(log2Ceil(aeq_width).W)))

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
    })

    // Instantiate CU
    val cu = Module(new cu(num_col, mempot_width, mempot_depth, aeq_width, aeq_depth, kernel_width, bias_width, dim_width))

    val tu = Module(new tu3(num_col, mempot_width, mempot_depth, aeq_width, aeq_depth, kernel_width, bias_width, dim_width, blk_dim_width))

	val ai  = Array.fill(9)(null: tdpb_init)
	val ao  = Array.fill(9)(null: tdpb_init)
	val mm  = Array.fill(9)(null: tdpb_init)
	val ln1 = Array.fill(3)(null: tdpb)
	val ls1 = Array.fill(3)(null: tdpb)

	// Instantiate BRAMs in a for loop
	for (i <- 0 until 9) {
		ai(i) = Module(new tdpb_init(10, 10, s"ai_$i.mem"))
		ao(i) = Module(new tdpb_init(10, 10, s"ao_$i.mem"))
		// mm(i) = Module(new tdpb(9, 10))

        mm(i) = Module(new tdpb_init(8, 10, s"mm_$i.mem"))

        ai(i).io := DontCare
        ao(i).io := DontCare
        mm(i).io := DontCare
	}

	for (i <- 0 until 3) {
		ln1(i) = Module(new tdpb(9, 10))
		ls1(i) = Module(new tdpb(9, 10))

        ln1(i).io := DontCare
        ls1(i).io := DontCare
	}

    // --- Connect Network Parameters ---
    cu.io.pe_io.conv_en := io.conv_en
    cu.io.pe_io.rotated_kernel := io.rotated_kernel
    cu.io.pe_io.kSize := io.kSize
    cu.io.pe_io.T := io.T
    cu.io.pe_io.N := io.N

    tu.io.tu_io.thresh_en := io.thresh_en
    tu.io.tu_io.maxpool_en := io.maxpool_en
    tu.io.tu_io.bias := io.bias
    tu.io.tu_io.v_t := io.v_t
    tu.io.tu_io.T := io.T
    tu.io.tu_io.N := io.N

    // === Main Mem Connections ===
    for (i <- 0 until 9) {
        // Shared for CU and TU (read/write) read port -> a, portb write
        mm(i).io.clka := clock
        mm(i).io.clkb := clock
        mm(i).io.ena := true.B
        mm(i).io.enb := true.B

        mm(i).io.wea := false.B
        // mm(i).io.addra := Mux(io.conv_en, cu.io.pe_io.mm_rdaddr(i), Mux(io.thresh_en, tu.io.tu_io.mm_rdaddr(i), 0.U))
        mm(i).io.addra := tu.io.tu_io.mm_rdaddr(i)
        mm(i).io.dia := 0.U
        
        mm(i).io.web := cu.io.pe_io.mm_we(i)
        mm(i).io.dib := cu.io.pe_io.mm_wrdata(i)
        mm(i).io.addrb := cu.io.pe_io.mm_wraddr(i)

        cu.io.pe_io.mm_rddata(i) := Mux(io.conv_en, mm(i).io.doa, 0.U)
        tu.io.tu_io.mm_rddata(i) := Mux(io.thresh_en, mm(i).io.doa, 0.U)
    }

    // === Local North Mem ===
    for (i <- 0 until 3) {
        ln1(i).io.clka := clock
        ln1(i).io.clkb := clock
        ln1(i).io.ena := true.B
        ln1(i).io.enb := true.B

        ln1(i).io.wea := false.B // CU only reads
        ln1(i).io.addra := tu.io.tu_io.ln1_rdaddr(i)
        ln1(i).io.dia := 0.U
        
        ln1(i).io.web := false.B // TU only reads
        ln1(i).io.addrb := DontCare
        ln1(i).io.dib := 0.U
        tu.io.tu_io.ln1_rddata(i) := ln1(i).io.doa

        // CU gets from external north mem (ln2 from lower tile)
        io.ln2_rdaddr(i) := cu.io.pe_io.ln2_rdaddr(i)
        cu.io.pe_io.ln2_rddata(i) := io.ln2_rddata(i)

        io.ln2_we := cu.io.pe_io.ln2_we
        io.ln2_wraddr := cu.io.pe_io.ln2_wraddr
        io.ln2_wrdata := cu.io.pe_io.ln2_wrdata
    }

    // === Local South Mem ===
    for (i <- 0 until 3) {
        ls1(i).io.clka := clock
        ls1(i).io.clkb := clock
        ls1(i).io.ena := true.B
        ls1(i).io.enb := true.B
        ls1(i).io.wea := false.B
        ls1(i).io.web := false.B
        ls1(i).io.addra := tu.io.tu_io.ls1_rdaddr(i)
        ls1(i).io.addrb := DontCare
        ls1(i).io.dia := 0.U
        ls1(i).io.dib := 0.U
        tu.io.tu_io.ls1_rddata(i) := ls1(i).io.doa

        // CU gets from external south mem (ls2 from upper tile)
        io.ls2_rdaddr(i) := cu.io.pe_io.ls2_rdaddr(i)
        cu.io.pe_io.ls2_rddata(i) := io.ls2_rddata(i)

        io.ls2_we := cu.io.pe_io.ls2_we
        io.ls2_wraddr := cu.io.pe_io.ls2_wraddr
        io.ls2_wrdata := cu.io.pe_io.ls2_wrdata
    }

    // === AEQ Connections ===
    for (i <- 0 until 9) {
        ai(i).io.clka := clock
        ai(i).io.ena := true.B
        ai(i).io.wea := false.B
        ai(i).io.addra := cu.io.pe_io.ai_rdaddr(i)
        ai(i).io.dia := 0.U // Not writing, dia can be 0
        cu.io.pe_io.ai_rddata(i) := ai(i).io.doa
    }

    for (i <- 0 until 9) {
        ao(i).io.clka := clock
        ao(i).io.ena := true.B
        ao(i).io.wea := tu.io.tu_io.ao_we(i)
        ao(i).io.addra := tu.io.tu_io.ao_wraddr(i)
        ao(i).io.dia := tu.io.tu_io.ao_wrdata(i)
        // Not reading from ao, so outputs can be ignored or defaulted
        io.ao_dout(i) := ao(i).io.doa
    }

    // Output flags
    io.conv_done := cu.io.pe_io.conv_done
    io.thresh_done := tu.io.tu_io.thresh_done
}

object tile extends App {
  val verilogString = chisel3.getVerilogString(new tile(num_col = 9, mempot_width = 8, mempot_depth = 1024, aeq_width = 10, aeq_depth = 1024, kernel_width = 8, bias_width = 8, dim_width = 8, blk_dim_width = 8))
  val verilogFile = new File("tile.sv")
  val writer = new PrintWriter(verilogFile)
  writer.write(verilogString)
  writer.close()
}