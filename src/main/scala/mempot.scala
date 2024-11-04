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
//     val rdEna = Input(Bool())
//   })

//   // Create an array of 9 memories
//   val mems = Seq.fill(numMemories)(SyncReadMem(depth, UInt(width.W)))

//   // Default assignment for read data
//   io.rdData := DontCare

//   // Handle read and write operations for each memory
//   for (i <- 0 until numMemories) {
//     when(io.rdEna) {
//       io.rdData(i) := mems(i).read(io.rdAddr)
//     }
//     when(io.wrEna(i)) {
//       mems(i).write(io.wrAddr, io.wrData(i))
//     }
//   }
// }

class mempot (mempotSize: Int, memPixelWidth: Int) extends Module{ //mempixelWidht --> size of pizel //mempotSize --> size of output feature map
  val io = IO(new Bundle{
  val wr_enable = Input(Vec(9,Bool()))
  val rd_enable = Input(Vec(9,Bool()))
  val addr_r = Input(Vec(9,UInt(8.W)))
  val addr_w = Input(Vec(9,UInt(8.W)))
  val din = Input(Vec(9,UInt(9.W)))
  val dout = Output(Vec(9,UInt(9.W))) //widht of mem is 9 here

  })

  val mempotColDepth = (mempotSize*mempotSize)/9 + (mempotSize*mempotSize)%9
  val multiMem = Module(new MultiMemory(mempotColDepth, memPixelWidth, 9)) //last bit as a spike indicator //9 --> # parallel columns

  // Initialize all IO of multiMem
  multiMem.io.rdAddr := VecInit(Seq.fill(9)(0.U(8.W)))
  multiMem.io.wrAddr := VecInit(Seq.fill(9)(0.U(8.W)))
  multiMem.io.wrData := VecInit(Seq.fill(9)(0.U(memPixelWidth.W)))
  multiMem.io.wrEna := VecInit(Seq.fill(9)(false.B))
  multiMem.io.rdEna := VecInit(Seq.fill(9)(false.B))
  
  for (i <- 0 until 9){
    io.dout(i) := DontCare
    when (io.rd_enable(i)){
      multiMem.io.rdEna(i) := io.rd_enable(i)
      multiMem.io.rdAddr(i) := io.addr_r(i)
      io.dout(i) := multiMem.io.rdData(i)
    }

    when (!io.rd_enable(i) && io.wr_enable(i)){
      multiMem.io.wrEna(i) := io.wr_enable(i)
      multiMem.io.wrAddr(i) := io.addr_w(i)
      multiMem.io.wrData(i) := io.din(i)
    }
  }
}
  
object mempot extends App {
  val verilogString = chisel3.getVerilogString(new mempot(48, 9))
  val verilogFile = new File("mempot.sv")
  val writer = new PrintWriter(verilogFile)
  writer.write(verilogString)
  writer.close()
}