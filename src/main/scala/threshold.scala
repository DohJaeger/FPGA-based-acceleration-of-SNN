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

import chisel3._
import chisel3.util._

class threshold_pipelined(val blockDim: Int, val memPotSize: Int, val maxMemPotValue: Int, val minMemPotValue: Int) extends Module {
  val io = IO(new Bundle {
    val enable          = Input(Bool())               
    val threshold       = Input(UInt(8.W))           
    val bias            = Input(SInt(8.W))          
    val maxPoolingEnable = Input(Bool())              
    val memPotReadData  = Vec(9, Input(SInt(16.W)))  
    val memPotAddr      = Vec(9, Output(UInt(16.W))) 
    val aeqWriteEnable  = Output(Bool())        
    val aeqWriteAddr    = Output(UInt(16.W))   
    val memPotWriteData = Vec(9, Output(SInt(16.W)))  
    val memPotWriteAddr = Vec(9, Output(UInt(16.W)))  
    val validS5         = Output(Bool())          
  })

  // pipeline stages
  val s1_addrCalc      = Reg(Vec(9, UInt(16.W)))     
  val s2_memPot        = Reg(Vec(9, SInt(16.W)))     
  val s3_updatedMemPot = Reg(Vec(9, SInt(16.W)))   
  val s4_spike         = Reg(Vec(9, Bool()))   
  val s5_writeBack     = Reg(Vec(9, SInt(16.W)))      
  val validS1, validS2, validS3, validS4, validS5 = RegInit(false.B)

  // counter to iterate 3x3 win across whole ip feature map
  val iMem = RegInit(0.U(8.W))
  val jMem = RegInit(0.U(8.W))

  // s1 --> addr calc
  when(io.enable && !validS1) {
    for (i <- 0 until 9) {
      val row_offset = (i / 3).U + iMem * 3.U
      val col_offset = (i % 3).U + jMem * 3.U
      s1_addrCalc(i) := (row_offset * blockDim.U + col_offset)
    }
    validS1 := true.B
  }

  // s2 --> mempot read
  when(validS1 && !validS2) {
    for (i <- 0 until 9) {
      s2_memPot(i) := io.memPotReadData(i)
    }
    validS2 := true.B
  }

  // s3 --> bias addition
  when(validS2 && !validS3) {
    for (i <- 0 until 9) {
      s3_updatedMemPot(i) := s2_memPot(i) + io.bias
    }
    validS3 := true.B
  }

  // s4 --> threshold
  when(validS3 && !validS4) {
    for (i <- 0 until 9) {
      // s4_spike(i) := (s3_updatedMemPot(i) > io.threshold)
    }
    validS4 := true.B
  }

  // s5 --> mem wb
  when(validS4 && !validS5) {
    for (i <- 0 until 9) {
      val updatedMemPot = s3_updatedMemPot(i)
      val saturatedMemPot = Mux(updatedMemPot > maxMemPotValue.S, maxMemPotValue.S,
                            Mux(updatedMemPot < minMemPotValue.S, minMemPotValue.S, updatedMemPot))
      s5_writeBack(i) := saturatedMemPot
      
      // aeq update for spikes
      when(s4_spike(i)) {
        io.aeqWriteEnable := true.B
        io.aeqWriteAddr := s1_addrCalc(i) //spike addr to aeq
      }
    }
    validS5 := true.B
  }

  // updated potentials to mempot
  when(validS5) {
    for (i <- 0 until 9) {
      io.memPotWriteData(i) := s5_writeBack(i)
      io.memPotWriteAddr(i) := s1_addrCalc(i)
    }
    validS5 := false.B
  }

  // move to next 3x3 block
  when(validS5) {
    when(jMem === (blockDim - 1).U) {
      jMem := 0.U
      iMem := iMem + 1.U
    } .otherwise {
      jMem := jMem + 1.U
    }
  }
}


object threshold_pipelined extends App {
  val verilogString = chisel3.getVerilogString(new conv(256, 11, 48, 9))
  val verilogFile = new File("threshold_pipelined.sv")
  val writer = new PrintWriter(verilogFile)
  writer.write(verilogString)
  writer.close()
}