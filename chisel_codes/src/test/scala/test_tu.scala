import chisel3._
import chisel3.util._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class TU3Test extends AnyFlatSpec with ChiselScalatestTester {
  "tu3 module" should "perform thresholding correctly" in {
    test(new tu3(num_col = 9, mempot_width = 8, mempot_depth = 16, aeq_width = 8, aeq_depth = 16, kernel_width = 8, bias_width = 8, dim_width = 8, blk_dim_width = 8)) { dut =>
      
      // Initialize inputs
      dut.io.tu_io.thresh_en.poke(true.B)
      dut.io.maxpool_en.poke(false.B)
      dut.io.tu_io.v_t.poke(10.U)  // Set threshold
      
      // Simulate main memory read data
      for (i <- 0 until 9) {
        dut.io.tu_io.main_mempot_rddata(i).valid.poke(true.B)
        dut.io.tu_io.main_mempot_rddata(i).bits.poke((i * 2).U) // Assign increasing values
      }
      
      // Simulate local memory read data
      for (i <- 0 until 3) {
        dut.io.tu_io.L1_N_rddata(i).valid.poke(true.B)
        dut.io.tu_io.L1_N_rddata(i).bits.poke(5.U)
      }
      
      dut.clock.step(5) // Allow processing time
      
      // Check if thresholding logic works
      for (i <- 0 until 9) {
        val expectedSpike = if (i * 2 + 5 >= 10) true else false
        dut.io.tu_io.aeq_out_wraddr(i).valid.expect(expectedSpike.B)
        dut.io.tu_io.aeq_out_wrdata(i).valid.expect(expectedSpike.B)
      }
    }
  }
}