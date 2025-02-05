// import chisel3._
// import chisel3.util._
// import java.io.File
// import java.io.PrintWriter

// class my_bram (depth : Int , width : Int) extends Module {
//     val io = IO(new Bundle {
//     val rd_addr = Input(UInt(log2Ceil(depth).W))
//     val rd_data = Output(UInt(width.W))
//     val rd_data_valid = Output(Bool())
//     val wr_addr = Input(UInt(log2Ceil(depth).W))
//     val wr_data = Input(UInt(width.W))
//     val wr_en = Input(Bool())
//     val rd_en = Input(Bool())
// })
//     val mem = SyncReadMem(depth, UInt(width.W))
//     io.rd_data := DontCare

//     when (io.rd_en){
//         io.rd_data := mem.read(io.rd_addr) 
//         io.rd_data_valid := true.B

//     } .otherwise{
//         io.rd_data_valid := false.B
//     }

//     when(io.wr_en) {
//         mem.write(io.wr_addr, io.wr_data)
//     }
// }

// class calculate (depth : Int, width : Int) extends Module {
//     val io = IO(new Bundle {
//         val start = Input(Bool())
//         val i_data = Input(UInt(width.W))
//         val i_data_valid = Input(Bool())
//         val rd_addr = Output(UInt(log2Ceil(depth).W))
//         val rd_en = Output(Bool())
//         val wr_en = Output(Bool())
//         val wr_addr = Output(UInt(log2Ceil(depth).W))
//         val o_data = Output(UInt(width.W))
//         val done = Output(Bool())
//     })

//     io.rd_addr := DontCare
//     io.rd_en := DontCare
//     io.wr_en := DontCare
//     io.wr_addr := DontCare
//     io.o_data := DontCare
//     io.done := DontCare

//     val counter = RegInit(0.U(width.W))
//     val temp = RegInit(0.U(width.W))

//     when(io.start && !(counter === 11.U)){
//         io.rd_addr := counter
//         io.rd_en := true.B

//         when(io.i_data_valid){
//             temp := io.i_data
//         }

//         temp := temp + 4.U

//         io.wr_en := true.B
//         io.wr_addr := counter
//         io.o_data := temp

//         counter := counter + 1.U

//     } .otherwise{
//         io.rd_en := false.B
//         io.wr_en := false.B
//     }

//     when(counter === 11.U) {
//         io.done := true.B
//     }
// }

// class my_top(depth: Int, width: Int) extends Module {
//   val io = IO(new Bundle {
//     val start = Input(Bool())
//     val done = Output(Bool())
//     val init = Input(Bool())

//     val wr_addr = Input(UInt(log2Ceil(depth).W))
//     val wr_data = Input(UInt(width.W))
//     val wr_en = Input(Bool())

//     val rd_addr = Input(UInt(log2Ceil(depth).W))
//     val rd_data = Output(UInt(width.W))
//     val rd_data_valid = Output(Bool())
//     val rd_en = Input(Bool())
//   })

//   // Submodules
//   val my_calc = Module(new calculate(depth, width))
//   val my_mem = Module(new my_bram(depth, width))

//   // Default assignments for IO and internal signals
//   io.done := false.B
//   io.rd_data := DontCare
//   io.rd_data_valid := false.B

//   my_calc.io.start := false.B
//   my_calc.io.i_data := DontCare
//   my_calc.io.i_data_valid := false.B

//   my_mem.io.rd_addr := DontCare
//   my_mem.io.rd_en := false.B
//   my_mem.io.wr_addr := DontCare
//   my_mem.io.wr_data := DontCare
//   my_mem.io.wr_en := false.B

//   // Initialization logic
//   when(io.init && !io.start) {
//     my_mem.io.wr_addr := io.wr_addr
//     my_mem.io.wr_en := io.wr_en
//     my_mem.io.wr_data := io.wr_data
//     my_mem.io.rd_addr := io.rd_addr
//     my_mem.io.rd_en := io.rd_en

//     io.rd_data := my_mem.io.rd_data
//     io.rd_data_valid := my_mem.io.rd_data_valid
//   }

//   // Operation logic
//   when(io.start && !io.init) {
//     my_calc.io.start := io.start
//     my_calc.io.i_data := my_mem.io.rd_data
//     my_calc.io.i_data_valid := my_mem.io.rd_data_valid
//     io.done := my_calc.io.done

//     my_mem.io.rd_addr := my_calc.io.rd_addr
//     my_mem.io.rd_en := my_calc.io.rd_en
//     my_mem.io.wr_addr := my_calc.io.wr_addr
//     my_mem.io.wr_en := my_calc.io.wr_en
//     my_mem.io.wr_data := my_calc.io.o_data
//   }

//   // Expose signals for testing
// //   val exposed_rd_addr = chiseltest.experimental.expose(my_calc.io.rd_addr)
// //   val exposed_wr_addr = chiseltest.experimental.expose(my_calc.io.wr_addr)
// //   val exposed_o_data = chiseltest.experimental.expose(my_calc.io.o_data)
// //   val exposed_i_data = chiseltest.experimental.expose(my_calc.io.i_data)
// //   val exposed_done = chiseltest.experimental.expose(my_calc.io.done)
// }

// object my_top extends App {
//   val verilogString = chisel3.getVerilogString(new my_top(50, 8))
//   val verilogFile = new File("my_module_test.sv")
//   val writer = new PrintWriter(verilogFile)
//   writer.write(verilogString)
//   writer.close()
// }