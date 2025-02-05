import chisel3._
import chisel3.util._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class Tile3x3Tester extends AnyFlatSpec with ChiselScalatestTester {
  "tile_3x3" should "fetch spike events and calculate neighbor addresses" in {
    test(new tile_3x3(T = 16, N = 16, mempot_width = 16, mempot_depth = 256, aeq_width = 12, aeq_depth = 256, kSize = 3, kernel_width = 8, num_interlac = 9))
      .withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
        // Initialize inputs
        dut.io.conv_en.poke(true.B)
        dut.io.thresh_en.poke(false.B)

        // Set AEQ inputs
        for (i <- 0 until 9) {
          dut.io.rd_data_aeq_i(i).poke(0.U)
          dut.io.rd_data_aeq_i_valid(i).poke(false.B)
        }

        // Define a simple spike event for testing
        val spikeEvent = "b000000000000".U(12.W) // Example: EOQ = 0, Valid = 1, Block = 150
        val totHorBlk = 16 / 3 + (if (16 % 3 > 0) 1 else 0) // Total horizontal blocks (Scala division)
        val totVerBlk = 16 / 3 + (if (16 % 3 > 0) 1 else 0) // Total vertical blocks (Scala division)

        dut.io.rd_data_aeq_i(0).poke(spikeEvent)
        dut.io.rd_data_aeq_i_valid(0).poke(true.B)

        // Step through the pipeline
        dut.clock.step(1)

        // Check stage-1 address calculations
        dut.io.rd_en_aeq_i(0).expect(true.B)
        dut.io.rd_addr_aeq_i(0).expect(0.U)

        // Verify neighbor addresses
        for (k <- 0 until 3) {
          for (l <- 0 until 3) {
            // Extract block index (use Scala for the calculations)
            val blkIn = spikeEvent.litValue >> 1 & 0x3FF // Extract block from spike event (Scala math)
            val m = 3 * (blkIn / totHorBlk) + (1 % 3) // Row index (Scala math)
            val n = 3 * (blkIn % totHorBlk) + (1 / 3) // Column index (Scala math)

            val mk = m - 1 + k
            val nl = n - 1 + l
            val blkOut = totHorBlk * (mk / 3) + nl / 3
            val colOut = ((mk % 3) * 3 + nl % 3)

            val expectedAddr = (blkOut << log2Ceil(9)) | colOut // Combine blkOut and colOut into the expected address

            println(s"blkOut: $blkOut colOut: $colOut blkIn: $blkIn blkOut: $blkOut  colOut: $colOut m: $m n: $n mk: $mk nl: $nl")

            // Compare the expected address with DUT output
            // Replace this with the actual signal in your DUT that represents the calculated address
            // dut.s1_addr_calc(k * 3 + l).expect(expectedAddr.U)
          }
        }

        // Verify valid signal
        // Replace `dut.s1_valid` with the actual valid signal from your DUT
        // dut.s1_valid.expect(true.B)
      }
  }
}
