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
class MultiMemory(depth: Int, width: Int, numMemories: Int) extends Module {
  val io = IO(new Bundle {
    val rdAddr = Input(Vec(numMemories, UInt(log2Ceil(depth).W)))
    val rdData = Output(Vec(numMemories, UInt(width.W)))
    val wrAddr = Input(Vec(numMemories, UInt(log2Ceil(depth).W)))
    val wrData = Input(Vec(numMemories, UInt(width.W)))
    val wrEna = Input(Vec(numMemories, Bool()))
    val rdEna = Input(Vec(numMemories, Bool()))
  })

  // Create an array of 9 memories
  val mems = Seq.fill(numMemories)(SyncReadMem(depth, UInt(width.W)))

  // Default assignment for read data
  io.rdData := DontCare

  // Handle read and write operations for each memory
  for (i <- 0 until numMemories) {
    when(io.rdEna(i)) {
      io.rdData(i) := mems(i).read(io.rdAddr(i))
    }
    when(io.wrEna(i)) {
      mems(i).write(io.wrAddr(i), io.wrData(i))
    }
  }
}

// object MultiMemory extends App {
//   val verilogString = chisel3.getVerilogString(new MultiMemory(256, 11, 9))
//   val verilogFile = new File("multi_sync_mem.sv")
//   val writer = new PrintWriter(verilogFile)
//   writer.write(verilogString)
//   writer.close()
// }