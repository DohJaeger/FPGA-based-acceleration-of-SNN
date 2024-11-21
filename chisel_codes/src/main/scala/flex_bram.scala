import chisel3._
import chisel3.util._
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.freespec.AnyFreeSpec

import java.io.File
import java.io.PrintWriter
// Top-level BRAM wrapper module in Chisel
class BRAMFlex(
  val bitsAU: Int = 10,              // Address width per BRAM unit
  val bitsDU: Int = 18,              // Data width per BRAM unit
  val depth: Int = 4096,             // Total depth (number of addresses)
  val bitsD: Int = 18,               // Total data width per address
  val portaEnableWrite: Boolean = true,
  val portbEnableWrite: Boolean = true,
  val portaReadFirst: Boolean = true,
  val portbReadFirst: Boolean = true,
  val initValueCount: Int = 4,
  val initValueArray: Seq[Int] = Seq.fill(4)(0),
  val initValueDefault: Int = 0
) extends Module {
  // Helper functions
  def log2(x: Int): Int = (math.log(x) / math.log(2)).toInt
  def ceilDiv(x: Int, y: Int): Int = (x + y - 1) / y

  // Local parameter calculations based on SystemVerilog code logic
  val depthU = 1 << bitsAU                   // Depth of each RAM unit
  val depthHTR = if ((depth % depthU) == 0) depthU else (depth % depthU)
  val depthH = if (depthHTR > 2) depthHTR else 2
  val blockCnt = ceilDiv(depth, depthU)
  val bitsA = log2(depth)
  val bitsAH = if (bitsA > bitsAU) (bitsA - bitsAU) else 1
  val bitsAT = log2(depthH)
  val bitsDH = if ((bitsD % bitsDU) <= (bitsDU / 2)) (bitsD % bitsDU) else 0
  val bitsDL = bitsD - bitsDH

  // I/O definitions
  val io = IO(new Bundle {
    val clka = Input(Bool())
    val clkb = Input(Bool())
    val addra = Input(UInt(bitsA.W))
    val addrb = Input(UInt(bitsA.W))
    val wena = Input(Bool())
    val wenb = Input(Bool())
    val wdataa = Input(UInt(bitsD.W))
    val wdatab = Input(UInt(bitsD.W))
    val rdataa = Output(UInt(bitsD.W))
    val rdatab = Output(UInt(bitsD.W))
  })

  // Address split (high and low parts)
  val addraH = io.addra(bitsA - 1, bitsAU)
  val addrbH = io.addrb(bitsA - 1, bitsAU)
  val addraU = io.addra(bitsAU - 1, 0)
  val addrbU = io.addrb(bitsAU - 1, 0)

  // Registers for read output
  val addraHR = RegNext(addraH)
  val addrbHR = RegNext(addrbH)
  val rdataaR = Wire(Vec(blockCnt, UInt(bitsD.W)))
  val rdatabR = Wire(Vec(blockCnt, UInt(bitsD.W)))

  // Default output assignment
  io.rdataa := rdataaR(addraHR)
  io.rdatab := rdatabR(addrbHR)

  // Helper function for memory initialization
  def initMemory(size: Int, initArray: Seq[Int], default: Int, width: Int): SyncReadMem[UInt] = {
    val mem = SyncReadMem(size, UInt(width.W))
    for (i <- 0 until size) {
      val initValue = if (i < initArray.length) initArray(i) else default
      mem.write(i.U, initValue.U)
    }
    mem
  }

// BRAM block generation for both high and low parts
for (ii <- 0 until blockCnt) {
  val wenaBlock = io.wena && (addraH === ii.U(bitsAH.W))
  val wenbBlock = io.wenb && (addrbH === ii.U(bitsAH.W))

  val depthB = if (ii < (blockCnt - 1)) depthU else depthH

  // RAMH (high bits storage) if needed
  if (bitsDH > 0) {
    val ramh = initMemory(depthB, initValueArray.map(_ >> bitsDL), initValueDefault >> bitsDL, bitsDH)
    when(io.clka.asBool && wenaBlock) {
      ramh.write(addraU, (io.wdataa >> bitsDL).asUInt)
    }
    when(io.clkb.asBool && wenbBlock) {
      ramh.write(addrbU, (io.wdatab >> bitsDL).asUInt)
    }
    val highBitsA = ramh.read(addraU)
    val highBitsB = ramh.read(addrbU)
    rdataaR(ii) := Cat(highBitsA, io.wdataa(bitsDL - 1, 0))
    rdatabR(ii) := Cat(highBitsB, io.wdatab(bitsDL - 1, 0))
  }

  // RAML (low bits storage) if needed
  if (bitsDL > 0) {
    val raml = initMemory(depthB, initValueArray, initValueDefault, bitsDL)
    when(io.clka.asBool && wenaBlock) {
      raml.write(addraU, io.wdataa(bitsDL - 1, 0))
    }
    when(io.clkb.asBool && wenbBlock) {
      raml.write(addrbU, io.wdatab(bitsDL - 1, 0))
    }
    val lowBitsA = raml.read(addraU)
    val lowBitsB = raml.read(addrbU)

    // Use a temporary variable to handle the conditional concatenation
    val finalRdataa = if (bitsDH > 0) Cat(io.wdataa(bitsD - 1, bitsDL), lowBitsA) else lowBitsA
    val finalRdatab = if (bitsDH > 0) Cat(io.wdatab(bitsD - 1, bitsDL), lowBitsB) else lowBitsB

    rdataaR(ii) := finalRdataa
    rdatabR(ii) := finalRdatab
  }
}



  // Optional read-first/write-first behavior
  if (portaEnableWrite && !portaReadFirst) {
    val wenaR = RegNext(io.wena)
    val wdataaR = RegNext(io.wdataa)
    io.rdataa := Mux(wenaR, wdataaR, io.rdataa)
  }
  if (portbEnableWrite && !portbReadFirst) {
    val wenbR = RegNext(io.wenb)
    val wdatabR = RegNext(io.wdatab)
    io.rdatab := Mux(wenbR, wdatabR, io.rdatab)
  }
}

object BRAMFlex extends App {
  val verilogString = chisel3.getVerilogString(new BRAMFlex())
  val verilogFile = new File("BRAMFlex.sv")
  val writer = new PrintWriter(verilogFile)
  writer.write(verilogString)
  writer.close()
}