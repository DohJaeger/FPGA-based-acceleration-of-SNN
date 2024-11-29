//> using scala "2.13.12"
//> using dep  "org.chipsalliance::chisel::6.0.0"
//> using plugin "org.chipsalliance:::chisel-plugin::6.0.0"
//> using options "-unchecked", "-deprecation", "-language:reflectiveCalls", "-feature", "-Xcheckinit", "-Xfatal-warnings", "-Ywarn-dead-code", "-Ywarn-unused", "-Ymacro-annotations"

import chisel3._
import chisel3.util._
import chiseltest._
import chiseltest.experimental.expose
import org.scalatest.freespec.AnyFreeSpec

import java.io.File
import java.io.PrintWriter

 class AEQ extends Module {
  val io = IO(new Bundle {
    val writeEnable = Input(Vec(9, Bool()))
    val readEnable = Input(Bool())
    val writeData = Input(Vec(9, UInt(9.W)))
    val readData = Output(Vec(9, UInt(11.W)))
  })

  val brams = Seq.fill(9)(Mem(256, UInt(11.W))) // Each entry is 11 bits: 9 bits for data, 1 bit for valid, 1 bit for end-of-queue // EOQ bit + 9 bit data + valid bit
  val writeCounters = RegInit(VecInit(Seq.fill(9)(0.U(8.W))))
  val readCounter = RegInit(0.U(8.W))
  val columnSelectCounter = RegInit(0.U(4.W))
  
  for (i <- 0 until 9){
    io.readData(i) := DontCare
  }
  for(i <- 0 until 9) {
    when(!io.readEnable && io.writeEnable(i)) {
      val data = Cat("b0".U, io.writeData(i), "b1".U) // Concatenate the valid bit, the data, and the end-of-queue bit
      brams(i).write(writeCounters(i), data)
      writeCounters(i) := writeCounters(i) + 1.U
      when(writeCounters(i) === 255.U) {
        val lastData = Cat(1.U(1.W), io.writeData(i), 1.U(1.W)) // Set the end-of-queue bit for the last entry
        brams(i).write(writeCounters(i), lastData)
      }
    }
  }
  when(io.readEnable) {
    for(i <- 0 until 9) {
      val data1 = brams(i).read(readCounter)
      io.readData(i) :=  data1 // Extract the 9-bit data
    }
    readCounter := readCounter + 1.U
    when(readCounter === 255.U) {
      columnSelectCounter := columnSelectCounter + 1.U
      when(columnSelectCounter === 8.U) {
        columnSelectCounter := 0.U
      }
    }
  }


}

class AEQTest extends AnyFreeSpec with ChiselScalatestTester {
  
    "AEQTest should write to and read from all the brams" in {
      test(new AEQ).withAnnotations(Seq(VerilatorBackendAnnotation, WriteVcdAnnotation)) { dut =>
        // Write to all the brams at every address location
        for (i <- 0 until 9) {
          for (addr <- 0 until 256) {
            dut.io.writeEnable(i).poke(true.B)
            dut.io.writeData(i).poke(i.U)
            dut.clock.step()
          }
          dut.io.writeEnable(i).poke(false.B)
        }

        // Read from all the locations of all the brams
        dut.io.readEnable.poke(true.B)
        var readCount = 0
        for (h <- 0 until 256) {
          for (i <- 0 until 9) {
            val expected = if (readCount == 255) (2*i+1025).asUInt(11.W) else (2*i+1).asUInt(11.W)
            dut.io.readData(i).expect(expected)
            
          }
          dut.clock.step()
          readCount += 1
        }
        dut.io.readEnable.poke(false.B)
      }
    
  }
}


/*object Main extends App {
   println(
      ChiselStage.emitSystemVerilog(
         gen = new AEQ,
        firtoolOpts =  Array("-disable-all-randomization","-strip-debug-info")

)
)
}*/