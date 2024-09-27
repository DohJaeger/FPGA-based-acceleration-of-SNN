//> using scala "2.13.12"
//> using dep  "org.chipsalliance::chisel::6.0.0"
//> using plugin "org.chipsalliance:::chisel-plugin::6.0.0"
//> using options "-unchecked", "-deprecation", "-language:reflectiveCalls", "-feature", "-Xcheckinit", "-Xfatal-warnings", "-Ywarn-dead-code", "-Ywarn-unused", "-Ymacro-annotations"

import chisel3._
import chisel3.util._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.freespec.AnyFreeSpec

import java.io.File
import java.io.PrintWriter


//MultiMemory
// class MultiMemory(depth: Int, width: Int, numMemories: Int) extends Module {
//   val io = IO(new Bundle {
//     val rdAddr = Input(UInt(log2Ceil(depth).W))
//     val rdData = Output(Vec(numMemories, UInt(width.W)))
//     val wrAddr = Input(UInt(log2Ceil(depth).W))
//     val wrData = Input(Vec(numMemories, UInt(width.W)))
//     val wrEna = Input(Vec(numMemories, Bool()))
//     val rdEna = Input(Vec(numMemories, Bool()))
//   })

//   // Create an array of 9 memories
//   val mems = Seq.fill(numMemories)(SyncReadMem(depth, UInt(width.W)))

//   // Default assignment for read data
//   io.rdData := DontCare

//   // Handle read and write operations for each memory
//   for (i <- 0 until numMemories) {
//     when(io.rdEna(i)) {
//       io.rdData(i) := mems(i).read(io.rdAddr)
//     }
//     when(io.wrEna(i)) {
//       mems(i).write(io.wrAddr, io.wrData(i))
//     }
//   }
// }

//AEQ
class AEQ(depth: Int, width: Int) extends Module {
  val io = IO(new Bundle {
    val writeEnable = Input(Vec(9, Bool()))
    val readEnable = Input(Bool())
    val writeData = Input(Vec(9, UInt(9.W)))
    val readData = Output(Vec(9, UInt(9.W)))
  })

  val multiMem = Module(new MultiMemory(depth, width, 9))

  val writeCounters = RegInit(VecInit(Seq.fill(9)(0.U(8.W))))
  val readCounter = RegInit(0.U(8.W))
  val columnSelectCounter = RegInit(0.U(4.W))

  //reset condn
  io.readData := DontCare
  
  // Initialize all IO fields of multiMem
  multiMem.io.rdAddr := 0.U
  multiMem.io.wrAddr := 0.U
  multiMem.io.wrData := VecInit(Seq.fill(9)(0.U(width.W)))
  multiMem.io.wrEna := VecInit(Seq.fill(9)(false.B))
  multiMem.io.rdEna := VecInit(Seq.fill(9)(false.B))

  // Read logic
  when(io.readEnable) {
    multiMem.io.rdEna := VecInit(Seq.fill(9)(true.B))
    for (i <- 0 until 9) {
      io.readData(i) := multiMem.io.rdData(i)(9, 1) // Extract the 9-bit data
    }
    readCounter := readCounter + 1.U
    when(readCounter === (depth - 1).U) {
      columnSelectCounter := columnSelectCounter + 1.U
      when(columnSelectCounter === 8.U) {
        columnSelectCounter := 0.U
      }
    }
  }

  // Write logic
  for (i <- 0 until 9) {
    when(io.writeEnable(i)) {
      val data = Cat(0.U(1.W), io.writeData(i), 1.U(1.W)) // Concatenate valid bit, data, EOQ bit
      multiMem.io.wrAddr := writeCounters(i)
      multiMem.io.wrData(i) := data
      multiMem.io.wrEna(i) := true.B
      writeCounters(i) := writeCounters(i) + 1.U
      when(writeCounters(i) === (depth - 1).U) {
        val lastData = Cat(1.U(1.W), io.writeData(i), 1.U(1.W)) // Set EOQ bit for the last entry
        multiMem.io.wrAddr := writeCounters(i)
        multiMem.io.wrData(i) := lastData
        multiMem.io.wrEna(i) := true.B
      }
    }
  }
}

object Main extends App {
  val verilogString = chisel3.getVerilogString(new AEQ(256, 11))
  val verilogFile = new File("AEQ.sv")
  val writer = new PrintWriter(verilogFile)
  writer.write(verilogString)
  writer.close()
}