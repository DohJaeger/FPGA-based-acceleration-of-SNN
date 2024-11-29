                                                                                                          
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

 class mem (depth : Int , width : Int) extends Module {
 val io = IO(new Bundle {
 val rd_addr = Input(UInt(log2Ceil(depth).W))
 val rd_data = Output(UInt(width.W))
 val wr_addr = Input(UInt(log2Ceil(depth).W))
 val wr_data = Input(UInt(width.W))
 val wr_en = Input(Bool())
 val rd_en = Input(Bool())
 })
 val mem = SyncReadMem(depth, UInt(width.W)) //Synchronous Read Write mem
 io.rd_data := DontCare
 when (io.rd_en){

   io.rd_data := mem.read(io.rd_addr)
 }

 when(io.wr_en) {
   mem.write(io.wr_addr, io.wr_data)
 }
}

// class mem(depth: Int, width: Int) extends Module {
//   val io = IO(new Bundle {
//     val rd_addr = Input(UInt(log2Ceil(depth).W))
//     val rd_data = Output(UInt(width.W))
//     val rd_valid = Output(Bool())
//     val wr_addr = Input(UInt(log2Ceil(depth).W))
//     val wr_data = Input(UInt(width.W))
//     val wr_en = Input(Bool())
//     val rd_en = Input(Bool())
//   })

//   val mem = SyncReadMem(depth, UInt(width.W))
  
//   val rd_data_reg = RegInit(0.U(width.W))
//   val rd_valid_reg = RegInit(false.B)
  
//   io.rd_data := rd_data_reg
//   io.rd_valid := rd_valid_reg

//   // Synchronous Read
//   when(io.rd_en) {
//     rd_data_reg := mem.read(io.rd_addr)
//     rd_valid_reg := true.B
//   } .otherwise {
//     rd_valid_reg := false.B
//     rd_valid_reg := false.B
//   }

//   // Synchronous Write
//   when(io.wr_en) {
//     mem.write(io.wr_addr, io.wr_data)
//   }
// }

object sync_mem extends App {
  val verilogString = chisel3.getVerilogString(new mem(128,10))
  val verilogFile = new File("sync_mem.sv")
  val writer = new PrintWriter(verilogFile)
  writer.write(verilogString)
  writer.close()
}