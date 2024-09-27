                                                                                                          
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

 class Memory (depth : Int , width : Int) extends Module {
 val io = IO(new Bundle {
 val rdAddr = Input(UInt(log2Ceil(depth).W))
 val rdData = Output(UInt(width.W))
 val wrAddr = Input(UInt(log2Ceil(depth).W))
 val wrData = Input(UInt(width.W))
 val wrEna = Input(Bool())
 val rdEna = Input(Bool())
 })
 val mem = SyncReadMem(depth, UInt(width.W)) //Synchronous Read Write Memory
 io.rdData := DontCare
 when (io.rdEna){

   io.rdData := mem.read(io.rdAddr)
 }

 when(io.wrEna) {
   mem.write(io.wrAddr, io.wrData)
 }
}
object Memory extends App {
  val verilogString = chisel3.getVerilogString(new Memory(1024,28))
  val verilogFile = new File("sync_mem.sv")
  val writer = new PrintWriter(verilogFile)
  writer.write(verilogString)
  writer.close()
}