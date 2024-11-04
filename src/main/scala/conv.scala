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

class conv(depth: Int, width: Int, mempotSize: Int, memPixelWidth: Int) extends Module {
  val io = IO(new Bundle {
    // AEQ control
    val wr_enable_aeq = Input(Vec(9, Bool()))
    val rd_enable_aeq = Input(Bool())
    val writeData_aeq = Input(Vec(9, UInt(9.W)))
    val readData_aeq = Output(Vec(9, UInt(9.W)))

    // mempot control
    val wr_enable_mempot = Input(Vec(9, Bool()))
    val rd_enable_mempot = Input(Vec(9, Bool()))
    val addr_r_mempot = Input(Vec(9, UInt(8.W))) 
    val addr_w_mempot = Input(Vec(9, UInt(8.W))) 
    val din_mempot = Input(Vec(9, UInt(9.W)))
    val dout_mempot = Output(Vec(9, UInt(9.W)))

    // ronv and thresholding params
    val bias = Input(Vec(9, UInt(8.W)))
    val V_t = Input(UInt(8.W))
    val thresh_enab = Input(Bool())
    val conv_enab = Input(Bool())
    val kernel = Input(Vec(9, UInt(8.W)))
  })

  val aeqMem = Module(new AEQ(depth, width))
  val mempotMem = Module(new mempot(mempotSize, memPixelWidth))

  aeqMem.io.writeEnable := io.wr_enable_aeq
  aeqMem.io.readEnable := io.rd_enable_aeq
  aeqMem.io.writeData := io.writeData_aeq
  io.readData_aeq := aeqMem.io.readData

  mempotMem.io.wr_enable := io.wr_enable_mempot
  mempotMem.io.rd_enable := io.rd_enable_mempot
  mempotMem.io.addr_r := io.addr_r_mempot
  mempotMem.io.addr_w := io.addr_w_mempot
  mempotMem.io.din := io.din_mempot
  io.dout_mempot := mempotMem.io.dout

  val rotated_kernel = Wire(Vec(9, UInt(8.W)))
  for (l <- 0 until 9) {
    rotated_kernel(l) := io.kernel(8 - l)
  }

  // thresholding
  val dout = Wire(Vec(9, UInt(8.W)))
  dout := DontCare
  val thresh_done = RegInit(false.B)
  val (counter, wrap) = Counter(io.thresh_enab && !io.conv_enab, 256)
  
  when(wrap) {
    thresh_done := true.B
  }.otherwise {
    thresh_done := false.B
    for (i <- 0 until 9) {
      when(io.rd_enable_mempot(i)) {
        val temp = mempotMem.io.dout(i)
        dout(i) := temp + io.bias(i)
      }
      when(dout(i) > io.V_t) {
        mempotMem.io.wr_enable(i) := true.B
        mempotMem.io.din(i) := 256.U(9.W) // Spike --> 9th bit
      }.otherwise {
        mempotMem.io.wr_enable(i) := true.B
        mempotMem.io.din(i) := dout(i)
      }
    }
  }

  // conv Operation
  val conv_done = RegInit(false.B)

  when(!conv_done && io.conv_enab && !io.thresh_enab) {
    when(io.rd_enable_aeq) {
      val AEQ_dat = aeqMem.io.readData(0) // Read AEQ

      when(AEQ_dat(0)) { // Valid bit
        val main_dat = AEQ_dat(8, 1)
        val m = (3.U * (main_dat / 16.U)) + (0.U % 3.U) 
        val n = (3.U * (main_dat % 16.U)) + (0.U / 3.U) 

        for (k <- 0 until 3) {
          for (l <- 0 until 3) {
            val mk = m - 1.U + k.asUInt(8.W)
            val nl = n - 1.U + l.asUInt(8.W)
            val b = (16.U * (mk / 3.U)) + (nl / 3.U) // MemPot address
            val c = (mk % 3.U) + 3.U * (nl % 3.U) // MemPot BRAM column

            val mempot_dat = mempotMem.io.dout(c)
            val kernel_added = mempot_dat + rotated_kernel(4 + (l - 1) + 3 * (k - 1))

            when(io.wr_enable_mempot(c)) {
              mempotMem.io.wr_enable(c) := true.B
              mempotMem.io.din(c) := kernel_added
            }
          }
        }
      }

      conv_done := true.B
    }
  }
}

object conv extends App {object conv extends App {
  val verilogString = chisel3.getVerilogString(new conv(256, 11, 48, 9))
  val verilogFile = new File("conv.sv")
  val writer = new PrintWriter(verilogFile)
  writer.write(verilogString)
  writer.close()
}
}
