// import chisel3._
// import chisel3.util._
// import chisel3.util.Decoupled
// import java.io.File
// import java.io.PrintWriter
// import java.io.{BufferedWriter, FileWriter}

// class DualPortAdder(DATA_WIDTH: Int, ADDR_WIDTH: Int) extends Module {
//   val io = IO(new Bundle {
//     val start = Input(Bool())
//     val stop = Input(Bool())
//   })

//   val bram = Module(new TrueDualPortBRAM(DATA_WIDTH, ADDR_WIDTH))

//   val addrA = RegInit(0.U(ADDR_WIDTH.W))
//   val addrB = RegInit(1.U(ADDR_WIDTH.W))
//   val sumA = RegInit(0.U(DATA_WIDTH.W))
//   val sumB = RegInit(0.U(DATA_WIDTH.W))
//   val state = RegInit(0.U(2.W))

//   bram.io.clka := clock
//   bram.io.clkb := clock
//   bram.io.ena  := true.B
//   bram.io.enb  := true.B
//   bram.io.wea  := false.B
//   bram.io.web  := false.B
//   bram.io.addra := addrA
//   bram.io.addrb := addrB
//   bram.io.dia := 0.U
//   bram.io.dib := 0.U

//   io.done := false.B

//   switch(state) {
//     is(0.U) {
//       when(io.start) {
//         bram.io.wea := true.B
//         bram.io.web := true.B
//         bram.io.dia := 10.U
//         bram.io.dib := 20.U
//         state := 1.U
//       }
//     }
//     is(1.U) {
//       bram.io.wea := false.B
//       bram.io.web := false.B
//       state := 2.U
//     }
//     is(2.U) {
//       sumA := bram.io.doa + 5.U
//       sumB := bram.io.dob + 10.U
//       state := 3.U
//     }
//     is(3.U) {
//       bram.io.wea := true.B
//       bram.io.web := true.B
//       bram.io.addra := addrA + 2.U
//       bram.io.addrb := addrB + 2.U
//       bram.io.dia := sumA
//       bram.io.dib := sumB
//       state := 4.U
//     }
//     is(4.U) {
//       io.done := true.B
//     }
//   }
// }

// object DualPortAdder extends App {
//   val verilogString = chisel3.getVerilogString(new DualPortAdder(32, 10))
//   val verilogFile = new File("DualPortAdder.sv")
//   val writer = new PrintWriter(verilogFile)
//   writer.write(verilogString)
//   writer.close()
// }