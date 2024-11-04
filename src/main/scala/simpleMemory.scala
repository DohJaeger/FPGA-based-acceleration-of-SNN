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

// Memory Block
class SimpleMemory(depth: Int, width: Int) extends Module {
  val io = IO(new Bundle {
    val wrAddr = Input(UInt(log2Ceil(depth).W)) // Write address
    val wrData = Input(UInt(width.W))           // Write data
    val wrEna = Input(Bool())                   // Write enable
    val rdAddr = Input(UInt(log2Ceil(depth).W)) // Read address
    val rdData = Output(UInt(width.W))          // Read data
    val rdEna = Input(Bool())                   // Read enable
  })

  // Define memory
  val mem = SyncReadMem(depth, UInt(width.W))

  // Default read data
  io.rdData := DontCare

  // Write operation
  when(io.wrEna) {
    mem.write(io.wrAddr, io.wrData)
  }

  // Read operation
  when(io.rdEna) {
    io.rdData := mem.read(io.rdAddr)
  }
}

// Test Block that increments the data by +2
class MemoryTestBlock(depth: Int, width: Int) extends Module {
  val io = IO(new Bundle {
    val start = Input(Bool())                   // Start signal to initiate the operation
    val addr = Input(UInt(log2Ceil(depth).W))   // Address to read/write from/to
    val done = Output(Bool())                   // Done signal to indicate completion
  })

  val memory = Module(new SimpleMemory(depth, width))

  // FSM states
  val idle :: read :: write :: doneState :: Nil = Enum(4)
  val state = RegInit(idle)

  val readData = Reg(UInt(width.W))
  val incrementedData = readData + 2.U  // Increment data by 2

  // Default signal values
  memory.io.rdAddr := io.addr
  memory.io.wrAddr := io.addr
  memory.io.wrData := 0.U
  memory.io.wrEna := false.B
  memory.io.rdEna := false.B
  io.done := false.B

  // State machine to perform read, increment, and write-back
  switch(state) {
    is(idle) {
      when(io.start) {
        state := read
      }
    }

    is(read) {
      memory.io.rdEna := true.B
      state := write
    }

    is(write) {
      readData := memory.io.rdData
      memory.io.wrEna := true.B
      memory.io.wrData := incrementedData
      state := doneState
    }

    is(doneState) {
      io.done := true.B
      state := idle
    }
  }
}


// object testMem extends App {
//   val verilogString = chisel3.getVerilogString(new MemoryTestBlock(256, 8))
//   val verilogFile = new File("testMem.sv")
//   val writer = new PrintWriter(verilogFile)
//   writer.write(verilogString)
//   writer.close()
// }

object testMem extends App {
  val verilogString = chisel3.getVerilogString(new SimpleMemory(256, 8))
  val verilogFile = new File("testMem.sv")
  val writer = new PrintWriter(verilogFile)
  writer.write(verilogString)
  writer.close()
}
