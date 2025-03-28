import chisel3._
import chisel3.util._
import java.io.File
import java.io.PrintWriter

class tdp_bram(DATA_WIDTH: Int, ADDR_WIDTH: Int, initFileName: String = "") extends Module {
  val io = IO(new Bundle {
    val clka   = Input(Clock())
    val clkb   = Input(Clock())
    val ena    = Input(Bool())
    val enb    = Input(Bool())
    val wea    = Input(Bool())
    val web    = Input(Bool())
    val addra  = Input(UInt(ADDR_WIDTH.W))
    val addrb  = Input(UInt(ADDR_WIDTH.W))
    val dia    = Input(UInt(DATA_WIDTH.W))
    val dib    = Input(UInt(DATA_WIDTH.W))
    val doa    = Output(UInt(DATA_WIDTH.W))
    val dob    = Output(UInt(DATA_WIDTH.W))
  })

  val bram = Module(new tdpb(DATA_WIDTH, ADDR_WIDTH))

  bram.io.clka  := io.clka
  bram.io.clkb  := io.clkb
  bram.io.ena   := io.ena
  bram.io.enb   := io.enb
  bram.io.wea   := io.wea
  bram.io.web   := io.web
  bram.io.addra := io.addra
  bram.io.addrb := io.addrb
  bram.io.dia   := io.dia
  bram.io.dib   := io.dib
  
  io.doa := bram.io.doa
  io.dob := bram.io.dob
}


class tdpb(
	val DATA_WIDTH: Int, 
	val ADDR_WIDTH: Int
) extends BlackBox(Map(
	"DATA_WIDTH" -> DATA_WIDTH,
	"ADDR_WIDTH" -> ADDR_WIDTH
)) with HasBlackBoxResource {
	
	val io = IO(new Bundle {
		val clka   = Input(Clock())
		val clkb   = Input(Clock())
		val ena    = Input(Bool())
		val enb    = Input(Bool())
		val wea    = Input(Bool())
		val web    = Input(Bool())
		val addra  = Input(UInt(ADDR_WIDTH.W))
		val addrb  = Input(UInt(ADDR_WIDTH.W))
		val dia    = Input(UInt(DATA_WIDTH.W))
		val dib    = Input(UInt(DATA_WIDTH.W))
		val doa    = Output(UInt(DATA_WIDTH.W))
		val dob    = Output(UInt(DATA_WIDTH.W))
	})

	addResource("/tdpb.v")
}

class tdpb_init(
	val DATA_WIDTH: Int, 
	val ADDR_WIDTH: Int, 
	val INIT_FILE: String = ""
) extends BlackBox(Map(
	"DATA_WIDTH" -> DATA_WIDTH,
	"ADDR_WIDTH" -> ADDR_WIDTH,
	"INIT_FILE"  -> INIT_FILE
)) with HasBlackBoxResource {
	
	val io = IO(new Bundle {
		val clka   = Input(Clock())
		val clkb   = Input(Clock())
		val ena    = Input(Bool())
		val enb    = Input(Bool())
		val wea    = Input(Bool())
		val web    = Input(Bool())
		val addra  = Input(UInt(ADDR_WIDTH.W))
		val addrb  = Input(UInt(ADDR_WIDTH.W))
		val dia    = Input(UInt(DATA_WIDTH.W))
		val dib    = Input(UInt(DATA_WIDTH.W))
		val doa    = Output(UInt(DATA_WIDTH.W))
		val dob    = Output(UInt(DATA_WIDTH.W))
	})

	addResource("/tdpb_init.v")
}

// object tdp_bram extends App {
//   val verilogString = chisel3.getVerilogString(new tdp_bram(32, 10, "hello"))
//   val verilogFile = new File("tdpBRAM.sv")
//   val writer = new PrintWriter(verilogFile)
//   writer.write(verilogString)
//   writer.close()
// }