import chisel3._
import chisel3.util._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.freespec.AnyFreeSpec
import org.scalatest.matchers.should.Matchers

import java.io.File
import java.io.PrintWriter

class pe(tileDepth: Int, tileWidth: Int, mempotSize: Int, memPixelWidth: Int) extends Module {
  val io = IO(new Bundle {
    
    //input aeq
    val rd_enable_input_aeq = Input(Bool())
    val writeData_output_aeq = Input(Vec(9, UInt(9.W)))    //aeq data width 9 bits

    //output aeq
    val wr_enable_output_aeq = Input(Vec(9, Bool()))Width
    val readData_input_aeq = Output(Vec(9, UInt(9.W)))

    //membrane potential memory
    val wr_enable_mempot = Input(Vec(9, Bool()))
    val rd_enable_mempot = Input(Vec(9, Bool()))
    val addr_r_mempot = Input(Vec(9, UInt(8.W)))    //membrane pixel width 8 bits
    val addr_w_mempot = Input(Vec(9, UInt(8.W)))
    val din_mempot = Input(Vec(9, UInt(9.W)))
    val dout_mempot = Output(Vec(9, UInt(9.W)))

    val bias = Input(Vec(9, UInt(8.W)))
    val V_t = Input(UInt(8.W))
    val thresh_enab = Input(Bool())
    val conv_enab = Input(Bool())
    val kernel = Input(Vec(9, UInt(8.W)))
  })

  val aeqMem = Module(new AEQ(tileDepth, tileWidth))
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

  //pipeline reg
  val s1_addrCalc = Reg(Vec(9, UInt(8.W)))
  val s2_memRead = Reg(Vec(9, UInt(9.W)))
  val s3_updates = Reg(Vec(9, UInt(9.W)))

  val validS1 = RegInit(false.B)
  val validS2 = RegInit(false.B)
  val validS3 = RegInit(false.B)
  val validS4 = RegInit(false.B)

  val stallPipeline = Wire(Bool())
  stallPipeline := false.B


  // s2-s3 hazard detection (s2 reading the same addr as s3 updating)
  for (i <- 0 until 9) {
    when(validS2 && validS3 && (s1_addrCalc(i) === s1_addrCalc(i))) {
      stallPipeline := true.B
    }
  }

  // s1 --> addr calculation of neighbour
  when(io.rd_enable_aeq && !stallPipeline) {
  for (i <- 0 until 9) {
      val in_addr = io.addr_r_mempot(i)

      val col_offset = Mux((i%3).U === 2.U || (i%3).U === 5.U || (i%3).U === 8.U, 1.U, 
                      Mux((i%3).U === 0.U || (i%3).U === 3.U || (i%3).U === 6.U, (-1).S.asUInt, 0.U))
      
      val row_offset = Mux((i/3).U === 2.U, 1.U, 
                      Mux((i/3).U === 0.U, (-1).S.asUInt, 0.U))
      
      s1_addrCalc(i) := in_addr + col_offset + row_offset
      }
      validS1 := true.B
  }

  // s2 --> mempot read
  when(validS1 && !stallPipeline) {
      for (i <- 0 until 9) {
      s2_memRead(i) := mempotMem.io.dout(i) // Read MemPot memory
      }
      validS2 := true.B
  }

  // s3 --> mempot update calc
  when(validS2 && !stallPipeline) {
      for (i <- 0 until 9) {
      val update = s2_memRead(i) + io.kernel(i) // Add kernel weight to MemPot value
      s3_updates(i) := Mux(update > 255.U, 255.U, update)
      }
      validS3 := true.B
  }

  // S4--> write back mempot
  when(validS3) {
    for (i <- 0 until 9) {
      mempotMem.io.wr_enable(i) := true.B
      mempotMem.io.din(i) := s3_updates(i) // Write updated value back to memory
    }
    validS4 := true.B
  }

  // frwarding logic for S2-S4 hazard
  when(validS2 && validS4) {
    for (i <- 0 until 9) {
      s2_memRead(i) := Mux(s1_addrCalc(i) === s1_addrCalc(i), s3_updates(i), mempotMem.io.dout(i))
    }
  }

  //valid signals for pipeline flow control
  when(validS4 && !stallPipeline) {
    validS1 := false.B
    validS2 := false.B
    validS3 := false.B
    validS4 := false.B
  }
}

class peTest extends AnyFlatSpec with ChiselScalatestTester with Matchers {
  "pe" should "perform memory read, update, and write-back operations correctly" in {
    // Test parameters
    val tileDepth = 256
    val tileWidth = 11
    val mempotSize = 48
    val memPixelWidth = 9

    test(new pe(tileDepth, tileWidth, mempotSize, memPixelWidth)) { dut =>
      // Initialize input signals
      dut.io.rd_enable_aeq.poke(false.B)
      dut.io.wr_enable_aeq.foreach(_.poke(false.B))
      dut.io.writeData_aeq.foreach(_.poke(0.U))
      dut.io.wr_enable_mempot.foreach(_.poke(false.B))
      dut.io.rd_enable_mempot.foreach(_.poke(false.B))
      dut.io.addr_r_mempot.foreach(_.poke(0.U))
      dut.io.addr_w_mempot.foreach(_.poke(0.U))
      dut.io.din_mempot.foreach(_.poke(0.U))
      dut.io.bias.foreach(_.poke(0.U))
      dut.io.V_t.poke(0.U)
      dut.io.thresh_enab.poke(false.B)
      dut.io.conv_enab.poke(false.B)
      dut.io.kernel.foreach(_.poke(1.U))

      // Write initial values to the AEQ memory and MemPot memory
      dut.io.wr_enable_aeq.foreach(_.poke(true.B))
      for (i <- 0 until 9) {
        dut.io.writeData_aeq(i).poke((i + 1).U)
      }
      dut.io.rd_enable_aeq.poke(true.B)
      dut.clock.step(1)

      // Check AEQ read data
      for (i <- 0 until 9) {
        dut.io.readData_aeq(i).expect((i + 1).U)
      }

      // Enable reading from MemPot memory and set addresses
      dut.io.rd_enable_mempot.foreach(_.poke(true.B))
      for (i <- 0 until 9) {
        dut.io.addr_r_mempot(i).poke(i.U)
      }

      // Set write enable for MemPot memory and write data
      dut.io.wr_enable_mempot.foreach(_.poke(true.B))
      for (i <- 0 until 9) {
        dut.io.din_mempot(i).poke((10 + i).U)
      }
      dut.clock.step(1)

      // Read data back from MemPot and verify it matches the written data
      for (i <- 0 until 9) {
        dut.io.dout_mempot(i).expect((10 + i).U)
      }

      // Enable convolution operation and set kernel weights
      dut.io.conv_enab.poke(true.B)
      for (i <- 0 until 9) {
        dut.io.kernel(i).poke((i + 1).U) // Kernel weights
      }

      // Trigger a convolution operation
      dut.io.rd_enable_aeq.poke(true.B)
      dut.clock.step(1)

      // Check pipeline stages for expected values in s2, s3, s4 (for basic validation)
      dut.io.dout_mempot.zipWithIndex.foreach { case (out, i) =>
        // Output values should reflect the kernel update logic
        val expectedUpdate = (10 + i) + (i + 1)
        val clampedUpdate = math.min(expectedUpdate, 255) // Saturate at 255 if overflow
        out.expect(clampedUpdate.U)
      }
    }
  }
}