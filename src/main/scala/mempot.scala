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


 class mempot extends Module{
    val io = IO(new Bundle{
    val wr_enable = Input(Vec(9,Bool()))
    val rd_enable = Input(Vec(9,Bool()))
    val addr_r = Input(Vec(9,UInt(8.W)))
    val addr_w = Input(Vec(9,UInt(8.W)))
    val din = Input(Vec(9,UInt(9.W)))
    val dout = Output(Vec(9,UInt(9.W)))

    })

    val brams = Seq.fill(9)(SyncReadMem(256, UInt(9.W))) // MemPot EXTRA BIT TO store spike indicator

    for (i <- 0 until 9){
      io.dout(i) := DontCare
      when (io.rd_enable(i)){
        io.dout(i) := brams(i).read(io.addr_r(i))
      }

      when (!io.rd_enable(i) && io.wr_enable(i)){
        brams(i).write(io.addr_w(i),io.din(i))
      }
    }
  }
  
object mempot extends App {
  val verilogString = chisel3.getVerilogString(new mempot())
  val verilogFile = new File("mempot.v")
  val writer = new PrintWriter(verilogFile)
  writer.write(verilogString)
  writer.close()
}