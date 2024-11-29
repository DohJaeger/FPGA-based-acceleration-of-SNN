// import chisel3._
// import chisel3.util._
// import chiseltest._
// import org.scalatest.flatspec.AnyFlatSpec
// import org.scalatest.freespec.AnyFreeSpec

// import java.io.File
// import java.io.PrintWriter


// class hel (depth: Int, width: Int) extends Module{
//     val io = IO(new Bundle{
//     val rdAddr = Input (UInt(log2Ceil(depth).W))
//     val rdData = Output(UInt(width.W))
//     val wrAddr = Input (UInt(log2Ceil(depth).W))
//     val wrData = Input (UInt(width.W))
//     val wrEna = Input (Bool())
//     val rdEna = Input(Bool())
// })

//     val mem = SyncReadMem(depth, UInt(width.W)) //Synchronous Read Write Memory
//     io.rdData :=  DontCare
//     when (io.rdEna) {
//         io.rdData := mem.read(io.rdAddr)
//     }

//     when(io.wrEna) {
//         mem.write(io.wrAddr, io.wrData)
//     }
// }

// class helTest extends AnyFlatSpec with ChiselScalatestTester {
// "Memory" should "work" in {
//     test(new hel(1024,8)).withAnnotations (Seq (VerilatorBackendAnnotation, WriteVcdAnnotation)) { dut =>
//         // Write to the memory
//         for (addr <- 0 until 11) {
//             dut.io.wrEna.poke(true.B)
//             dut.io.wrAddr.poke (addr.U)
//             dut.io.wrData.poke((addr + 7) .U)
//             dut.clock.step()
//         }
//     // Read from the memory and check the read data
//         for (addr <- 0 until 11) {
//             dut.io.rdEna.poke(true.B)
//             dut.io.rdAddr.poke(addr.U)
//             dut.clock.step()
//             dut.io.rdData.expect((addr + 7).U)
//         }
//     }
// }
// }