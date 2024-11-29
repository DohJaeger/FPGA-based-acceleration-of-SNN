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

class mempot_with_thresh extends Module {
  val io = IO(new Bundle {
    val wr_enable = Input(Vec(9, Bool()))
    // val rd_enable = Input(Vec(9,Bool()))
    val wr_enable_aeq = Input(Vec(9, Bool()))
    val rd_enable = Input(Bool())
    val addr_r_mempot = Input(Vec(9, UInt(8.W)))
    val addr_w_mempot = Input(Vec(9, UInt(8.W)))
    val din_mempot = Input(Vec(9, UInt(9.W)))
    val dout_mempot = Output(Vec(9, UInt(9.W)))
    val addr_r_aeq = Input(Vec(9, UInt(8.W)))
    val addr_w_aeq = Input(Vec(9, UInt(8.W)))
    val din_aeq = Input(Vec(9, UInt(10.W)))
    val dout_aeq = Output(Vec(9, UInt(10.W)))
    val bias = Input(Vec(9, UInt(8.W)))
    val V_t = Input(UInt(8.W))
    val thresh_enab = Input(Bool())
    //val conv_enab = Input(Bool())
    //val kernel = Input(Vec(9, UInt(8.W)))
    val max_pool_enab = Input(UInt(2.W))
  })
  

  val brams = Seq.fill(9)(SyncReadMem(256, UInt(9.W))) // MemPot
  val brams1 = Seq.fill(9)(SyncReadMem(256, UInt(10.W))) // 8 bit data + 1 valid bit + 1 end of queue bit <- AEQ
 
  

  val writeCounters = RegInit(VecInit(Seq.fill(9)(0.U(8.W))))
  val thresh_done = Wire(Bool())
  //val conv_done = WireDefault(Bool(), false.B)
  //val write_done_max_pool = WireDefault(Bool(), false.B)
  for (i <- 0 until 9) {
    io.dout_mempot(i) := 0.U
    when(io.rd_enable) {
      io.dout_mempot(i) := brams(i).read(io.addr_r_mempot(i))
    }

    when(!io.rd_enable && io.wr_enable(i)) {
      brams(i).write(io.addr_w_mempot(i), io.din_mempot(i))
    }
  }
  for (i <- 0 until 9) {
    io.dout_aeq(i) := 0.U
    when(io.rd_enable) {
      io.dout_aeq(i) := brams1(i).read(io.addr_r_aeq(i))
    }

    when(!io.rd_enable && io.wr_enable(i)) {
      brams1(i).write(io.addr_w_aeq(i), io.din_aeq(i))
    }
  }

  val dout = Wire(Vec(9, UInt(8.W)))
  dout := VecInit(Seq.fill(9)(0.U(8.W))) // Initialize dout to zero
  val din = Wire(Vec(256, UInt(9.W)))
  din := VecInit(Seq.fill(256)(0.U(9.W)))

  val (counter, wrap) = Counter(
    io.thresh_enab ,
    256
  ) // Creates a counter from 0 to 255
  when(wrap) {
    thresh_done := true.B
  }
    .otherwise {
      thresh_done := false.B
    }
  when(!wrap) {
    when(io.thresh_enab) {
      for (i <- 0 until 9) {
        when(io.rd_enable) {
          val temp = brams(i).read(counter)
          dout(i) := temp + io.bias(i)
        }
          .elsewhen(!io.rd_enable && io.wr_enable(i)) {
            when(dout(i) > io.V_t) {
              brams(i).write(counter, 256.U(9.W)) // spike indicator high
            }
              .otherwise {
                val temp1 = Cat(0.U(1.W), dout(i))
                brams(i).write(counter, temp1)
              }
          }
      }
    }
  }

  when(thresh_done) {
    when(io.max_pool_enab === 0.U) {
      for (i <- 0 until 9) {
        when(io.rd_enable && io.wr_enable_aeq(i)) {
          for (j <- 0 until 256) {
            din(j) := brams(i).read(j.asUInt(8.W))
            val temp2 = din(j)
            when(temp2(8)) {

              val data = Cat(
                0.U(1.W),
                j.asUInt(8.W),
                1.U(1.W)
              ) // EOQ bit + data + valid bit
              brams1(i).write(writeCounters(i), data)
              writeCounters(i) := writeCounters(i) + 1.U
            }

          }

        }
        when(io.wr_enable_aeq(i)) {

          when(writeCounters(i) > 0.U) {
            val lastElement = brams1(i)(writeCounters(i) - 1.U)
            val mod_last = Cat(
              1.U(1.W),
              lastElement(8, 1),
              1.U(1.W)
            ) // EOQ bit set for last element
            brams1(i).write(writeCounters(i) - 1.U, mod_last)
          }

        }
      }
    }
  
 

  }
}

/*object Main extends App {
   println(
      ChiselStage.emitSystemVerilog(
         gen = new snn_conv_commented,
        firtoolOpts =  Array("-disable-all-randomization","-strip-debug-info")

)
)
}*/


class MempotWithThreshTest extends AnyFreeSpec with ChiselScalatestTester {
  "MempotWithThresh should work properly" in {
    test(new mempot_with_thresh).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      // Initialize inputs
      val falseVec = Seq.fill(9)(false.B)
      val zeroVec8 = Seq.fill(9)(0.U(8.W))
      val zeroVec9 = Seq.fill(9)(0.U(9.W))
      val zeroVec10 = Seq.fill(9)(0.U(10.W))
      val twoVec8 = Seq.fill(9)(2.U(8.W))

      for (i <- 0 until 9) {
        dut.io.wr_enable(i).poke(falseVec(i))
        dut.io.wr_enable_aeq(i).poke(falseVec(i))
        dut.io.addr_r_mempot(i).poke(zeroVec8(i))
        dut.io.addr_w_mempot(i).poke(zeroVec8(i))
        dut.io.din_mempot(i).poke(zeroVec9(i))
        dut.io.addr_r_aeq(i).poke(zeroVec8(i))
        dut.io.addr_w_aeq(i).poke(zeroVec8(i))
        dut.io.din_aeq(i).poke(zeroVec10(i))
        dut.io.bias(i).poke(twoVec8(i))
      }
      dut.io.rd_enable.poke(false.B)
      dut.io.V_t.poke(4.U(8.W))
      dut.io.thresh_enab.poke(false.B)
      dut.io.max_pool_enab.poke(0.U(2.W))


      // Fill few locations of the brams with different values
      for (i <- 0 until 9) {
        dut.io.wr_enable(i).poke(true.B)
        dut.io.addr_w_mempot(i).poke(0.U(8.W))
        dut.io.din_mempot(i).poke(i.U(9.W))
        dut.clock.step()
        dut.io.addr_w_mempot(i).poke(1.U(8.W))
        dut.io.din_mempot(i).poke((i+1).U(9.W))
        dut.clock.step()
        dut.io.addr_w_mempot(i).poke(2.U(8.W))
        dut.io.din_mempot(i).poke((i+2).U(9.W))
        dut.clock.step()
        dut.io.wr_enable(i).poke(false.B)
      }

      // Enable thresholding
      dut.io.thresh_enab.poke(true.B)
      dut.clock.step(256)

      // Check the output of brams1 for the locations where address of spikes occurred
      for (i <- 0 until 9) {
        dut.io.rd_enable.poke(true.B)
        dut.io.addr_r_aeq(i).poke(0.U(8.W))
        dut.clock.step()// //> using scala "2.13.12"
// //> using dep  "org.chipsalliance::chisel::6.0.0"
// //> using plugin "org.chipsalliance:::chisel-plugin::6.0.0"
// //> using options "-unchecked", "-deprecation", "-language:reflectiveCalls", "-feature", "-Xcheckinit", "-Xfatal-warnings", "-Ywarn-dead-code", "-Ywarn-unused", "-Ymacro-annotations"


// import chisel3._
// import chisel3.util._
// import chiseltest._
// import org.scalatest.flatspec.AnyFlatSpec
// import org.scalatest.freespec.AnyFreeSpec

// import java.io.File
// import java.io.PrintWriter

// class mempot_with_thresh extends Module {
//   val io = IO(new Bundle {
//     val wr_enable = Input(Vec(9, Bool()))
//     // val rd_enable = Input(Vec(9,Bool()))
//     val wr_enable_aeq = Input(Vec(9, Bool()))
//     val rd_enable = Input(Bool())
//     val addr_r_mempot = Input(Vec(9, UInt(8.W)))
//     val addr_w_mempot = Input(Vec(9, UInt(8.W)))
//     val din_mempot = Input(Vec(9, UInt(9.W)))
//     val dout_mempot = Output(Vec(9, UInt(9.W)))
//     val addr_r_aeq = Input(Vec(9, UInt(8.W)))
//     val addr_w_aeq = Input(Vec(9, UInt(8.W)))
//     val din_aeq = Input(Vec(9, UInt(10.W)))
//     val dout_aeq = Output(Vec(9, UInt(10.W)))
//     val bias = Input(Vec(9, UInt(8.W)))
//     val V_t = Input(UInt(8.W))
//     val thresh_enab = Input(Bool())
//     //val conv_enab = Input(Bool())
//     //val kernel = Input(Vec(9, UInt(8.W)))
//     val max_pool_enab = Input(UInt(2.W))
//   })
  

//   val brams = Seq.fill(9)(SyncReadMem(256, UInt(9.W))) // MemPot
//   val brams1 = Seq.fill(9)(SyncReadMem(256, UInt(10.W))) // 8 bit data + 1 valid bit + 1 end of queue bit <- AEQ
 
  

//   val writeCounters = RegInit(VecInit(Seq.fill(9)(0.U(8.W))))
//   val thresh_done = Wire(Bool())
//   //val conv_done = WireDefault(Bool(), false.B)
//   //val write_done_max_pool = WireDefault(Bool(), false.B)
//   for (i <- 0 until 9) {
//     io.dout_mempot(i) := 0.U
//     when(io.rd_enable) {
//       io.dout_mempot(i) := brams(i).read(io.addr_r_mempot(i))
//     }

//     when(!io.rd_enable && io.wr_enable(i)) {
//       brams(i).write(io.addr_w_mempot(i), io.din_mempot(i))
//     }
//   }
//   for (i <- 0 until 9) {
//     io.dout_aeq(i) := 0.U
//     when(io.rd_enable) {
//       io.dout_aeq(i) := brams1(i).read(io.addr_r_aeq(i))
//     }

//     when(!io.rd_enable && io.wr_enable(i)) {
//       brams1(i).write(io.addr_w_aeq(i), io.din_aeq(i))
//     }
//   }

//   val dout = Wire(Vec(9, UInt(8.W)))
//   dout := VecInit(Seq.fill(9)(0.U(8.W))) // Initialize dout to zero
//   val din = Wire(Vec(256, UInt(9.W)))
//   din := VecInit(Seq.fill(256)(0.U(9.W)))

//   val (counter, wrap) = Counter(
//     io.thresh_enab ,
//     256
//   ) // Creates a counter from 0 to 255
//   when(wrap) {
//     thresh_done := true.B
//   }
//     .otherwise {
//       thresh_done := false.B
//     }
//   when(!wrap) {
//     when(io.thresh_enab) {
//       for (i <- 0 until 9) {
//         when(io.rd_enable) {
//           val temp = brams(i).read(counter)
//           dout(i) := temp + io.bias(i)
//         }
//           .elsewhen(!io.rd_enable && io.wr_enable(i)) {
//             when(dout(i) > io.V_t) {
//               brams(i).write(counter, 256.U(9.W)) // spike indicator high
//             }
//               .otherwise {
//                 val temp1 = Cat(0.U(1.W), dout(i))
//                 brams(i).write(counter, temp1)
//               }
//           }
//       }
//     }
//   }

//   when(thresh_done) {
//     when(io.max_pool_enab === 0.U) {
//       for (i <- 0 until 9) {
//         when(io.rd_enable && io.wr_enable_aeq(i)) {
//           for (j <- 0 until 256) {
//             din(j) := brams(i).read(j.asUInt(8.W))
//             val temp2 = din(j)
//             when(temp2(8)) {

//               val data = Cat(
//                 0.U(1.W),
//                 j.asUInt(8.W),
//                 1.U(1.W)
//               ) // EOQ bit + data + valid bit
//               brams1(i).write(writeCounters(i), data)
//               writeCounters(i) := writeCounters(i) + 1.U
//             }

//           }

//         }
//         when(io.wr_enable_aeq(i)) {

//           when(writeCounters(i) > 0.U) {
//             val lastElement = brams1(i)(writeCounters(i) - 1.U)
//             val mod_last = Cat(
//               1.U(1.W),
//               lastElement(8, 1),
//               1.U(1.W)
//             ) // EOQ bit set for last element
//             brams1(i).write(writeCounters(i) - 1.U, mod_last)
//           }

//         }
//       }
//     }
  
 

//   }
// }

// /*object Main extends App {
//    println(
//       ChiselStage.emitSystemVerilog(
//          gen = new snn_conv_commented,
//         firtoolOpts =  Array("-disable-all-randomization","-strip-debug-info")

// )
// )
// }*/


// class MempotWithThreshTest extends AnyFreeSpec with ChiselScalatestTester {
//   "MempotWithThresh should work properly" in {
//     test(new mempot_with_thresh).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
//       // Initialize inputs
//       val falseVec = Seq.fill(9)(false.B)
//       val zeroVec8 = Seq.fill(9)(0.U(8.W))
//       val zeroVec9 = Seq.fill(9)(0.U(9.W))
//       val zeroVec10 = Seq.fill(9)(0.U(10.W))
//       val twoVec8 = Seq.fill(9)(2.U(8.W))

//       for (i <- 0 until 9) {
//         dut.io.wr_enable(i).poke(falseVec(i))
//         dut.io.wr_enable_aeq(i).poke(falseVec(i))
//         dut.io.addr_r_mempot(i).poke(zeroVec8(i))
//         dut.io.addr_w_mempot(i).poke(zeroVec8(i))
//         dut.io.din_mempot(i).poke(zeroVec9(i))
//         dut.io.addr_r_aeq(i).poke(zeroVec8(i))
//         dut.io.addr_w_aeq(i).poke(zeroVec8(i))
//         dut.io.din_aeq(i).poke(zeroVec10(i))
//         dut.io.bias(i).poke(twoVec8(i))
//       }
//       dut.io.rd_enable.poke(false.B)
//       dut.io.V_t.poke(4.U(8.W))
//       dut.io.thresh_enab.poke(false.B)// //> using scala "2.13.12"
// //> using dep  "org.chipsalliance::chisel::6.0.0"
// //> using plugin "org.chipsalliance:::chisel-plugin::6.0.0"
// //> using options "-unchecked", "-deprecation", "-language:reflectiveCalls", "-feature", "-Xcheckinit", "-Xfatal-warnings", "-Ywarn-dead-code", "-Ywarn-unused", "-Ymacro-annotations"


// import chisel3._
// import chisel3.util._
// import chiseltest._
// import org.scalatest.flatspec.AnyFlatSpec
// import org.scalatest.freespec.AnyFreeSpec

// import java.io.File
// import java.io.PrintWriter

// class mempot_with_thresh extends Module {
//   val io = IO(new Bundle {
//     val wr_enable = Input(Vec(9, Bool()))
//     // val rd_enable = Input(Vec(9,Bool()))
//     val wr_enable_aeq = Input(Vec(9, Bool()))
//     val rd_enable = Input(Bool())
//     val addr_r_mempot = Input(Vec(9, UInt(8.W)))
//     val addr_w_mempot = Input(Vec(9, UInt(8.W)))
//     val din_mempot = Input(Vec(9, UInt(9.W)))
//     val dout_mempot = Output(Vec(9, UInt(9.W)))
//     val addr_r_aeq = Input(Vec(9, UInt(8.W)))
//     val addr_w_aeq = Input(Vec(9, UInt(8.W)))
//     val din_aeq = Input(Vec(9, UInt(10.W)))
//     val dout_aeq = Output(Vec(9, UInt(10.W)))
//     val bias = Input(Vec(9, UInt(8.W)))
//     val V_t = Input(UInt(8.W))
//     val thresh_enab = Input(Bool())
//     //val conv_enab = Input(Bool())
//     //val kernel = Input(Vec(9, UInt(8.W)))
//     val max_pool_enab = Input(UInt(2.W))
//   })
  

//   val brams = Seq.fill(9)(SyncReadMem(256, UInt(9.W))) // MemPot
//   val brams1 = Seq.fill(9)(SyncReadMem(256, UInt(10.W))) // 8 bit data + 1 valid bit + 1 end of queue bit <- AEQ
 
  

//   val writeCounters = RegInit(VecInit(Seq.fill(9)(0.U(8.W))))
//   val thresh_done = Wire(Bool())
//   //val conv_done = WireDefault(Bool(), false.B)
//   //val write_done_max_pool = WireDefault(Bool(), false.B)
//   for (i <- 0 until 9) {
//     io.dout_mempot(i) := 0.U
//     when(io.rd_enable) {
//       io.dout_mempot(i) := brams(i).read(io.addr_r_mempot(i))
//     }

//     when(!io.rd_enable && io.wr_enable(i)) {
//       brams(i).write(io.addr_w_mempot(i), io.din_mempot(i))
//     }
//   }
//   for (i <- 0 until 9) {
//     io.dout_aeq(i) := 0.U
//     when(io.rd_enable) {
//       io.dout_aeq(i) := brams1(i).read(io.addr_r_aeq(i))
//     }

//     when(!io.rd_enable && io.wr_enable(i)) {
//       brams1(i).write(io.addr_w_aeq(i), io.din_aeq(i))
//     }
//   }

//   val dout = Wire(Vec(9, UInt(8.W)))
//   dout := VecInit(Seq.fill(9)(0.U(8.W))) // Initialize dout to zero
//   val din = Wire(Vec(256, UInt(9.W)))
//   din := VecInit(Seq.fill(256)(0.U(9.W)))

//   val (counter, wrap) = Counter(
//     io.thresh_enab ,
//     256
//   ) // Creates a counter from 0 to 255
//   when(wrap) {
//     thresh_done := true.B
//   }
//     .otherwise {
//       thresh_done := false.B
//     }
//   when(!wrap) {
//     when(io.thresh_enab) {
//       for (i <- 0 until 9) {
//         when(io.rd_enable) {
//           val temp = brams(i).read(counter)
//           dout(i) := temp + io.bias(i)
//         }
//           .elsewhen(!io.rd_enable && io.wr_enable(i)) {
//             when(dout(i) > io.V_t) {
//               brams(i).write(counter, 256.U(9.W)) // spike indicator high
//             }
//               .otherwise {
//                 val temp1 = Cat(0.U(1.W), dout(i))
//                 brams(i).write(counter, temp1)
//               }
//           }
//       }
//     }
//   }

//   when(thresh_done) {
//     when(io.max_pool_enab === 0.U) {
//       for (i <- 0 until 9) {
//         when(io.rd_enable && io.wr_enable_aeq(i)) {
//           for (j <- 0 until 256) {
//             din(j) := brams(i).read(j.asUInt(8.W))
//             val temp2 = din(j)
//             when(temp2(8)) {

//               val data = Cat(
//                 0.U(1.W),
//                 j.asUInt(8.W),
//                 1.U(1.W)
//               ) // EOQ bit + data + valid bit
//               brams1(i).write(writeCounters(i), data)
//               writeCounters(i) := writeCounters(i) + 1.U
//             }

//           }

//         }
//         when(io.wr_enable_aeq(i)) {

//           when(writeCounters(i) > 0.U) {
//             val lastElement = brams1(i)(writeCounters(i) - 1.U)
//             val mod_last = Cat(
//               1.U(1.W),
//               lastElement(8, 1),
//               1.U(1.W)
//             ) // EOQ bit set for last element
//             brams1(i).write(writeCounters(i) - 1.U, mod_last)
//           }

//         }
//       }
//     }
  
 

//   }
// }

// /*object Main extends App {
//    println(
//       ChiselStage.emitSystemVerilog(
//          gen = new snn_conv_commented,
//         firtoolOpts =  Array("-disable-all-randomization","-strip-debug-info")

// )
// )
// }*/


// class MempotWithThreshTest extends AnyFreeSpec with ChiselScalatestTester {
//   "MempotWithThresh should work properly" in {
//     test(new mempot_with_thresh).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
//       // Initialize inputs
//       val falseVec = Seq.fill(9)(false.B)
//       val zeroVec8 = Seq.fill(9)(0.U(8.W))
//       val zeroVec9 = Seq.fill(9)(0.U(9.W))
//       val zeroVec10 = Seq.fill(9)(0.U(10.W))
//       val twoVec8 = Seq.fill(9)(2.U(8.W))

//       for (i <- 0 until 9) {
//         dut.io.wr_enable(i).poke(falseVec(i))
//         dut.io.wr_enable_aeq(i).poke(falseVec(i))
//         dut.io.addr_r_mempot(i).poke(zeroVec8(i))
//         dut.io.addr_w_mempot(i).poke(zeroVec8(i))
//         dut.io.din_mempot(i).poke(zeroVec9(i))
//         dut.io.addr_r_aeq(i).poke(zeroVec8(i))
//         dut.io.addr_w_aeq(i).poke(zeroVec8(i))
//         dut.io.din_aeq(i).poke(zeroVec10(i))
//         dut.io.bias(i).poke(twoVec8(i))
//       }
//       dut.io.rd_enable.poke(false.B)
//       dut.io.V_t.poke(4.U(8.W))
//       dut.io.thresh_enab.poke(false.B)
//       dut.io.max_pool_enab.poke(0.U(2.W))


//       // Fill few locations of the brams with different values
//       for (i <- 0 until 9) {
//         dut.io.wr_enable(i).poke(true.B)
//         dut.io.addr_w_mempot(i).poke(0.U(8.W))
//         dut.io.din_mempot(i).poke(i.U(9.W))
//         dut.clock.step()
//         dut.io.addr_w_mempot(i).poke(1.U(8.W))
//         dut.io.din_mempot(i).poke((i+1).U(9.W))
//         dut.clock.step()
//         dut.io.addr_w_mempot(i).poke(2.U(8.W))
//         dut.io.din_mempot(i).poke((i+2).U(9.W))
//         dut.clock.step()
//         dut.io.wr_enable(i).poke(false.B)
//       }

//       // Enable thresholding
//       dut.io.thresh_enab.poke(true.B)
//       dut.clock.step(256)

//       // Check the output of brams1 for the locations where address of spikes occurred
//       for (i <- 0 until 9) {
//         dut.io.rd_enable.poke(true.B)
//         dut.io.addr_r_aeq(i).poke(0.U(8.W))
//         dut.clock.step()
//         println(s"Output at location 0 of bram1 $i: ${dut.io.dout_aeq(i).peek()}")
//         dut.io.addr_r_aeq(i).poke(1.U(8.W))
//         dut.clock.step()
//         println(s"Output at location 1 of bram1 $i: ${dut.io.dout_aeq(i).peek()}")
//         dut.io.addr_r_aeq(i).poke(2.U(8.W))
//         dut.clock.step()
//         println(s"Output at location 2 of bram1 $i: ${dut.io.dout_aeq(i).peek()}")
//         dut.io.rd_enable.poke(false.B)
//       }

//       // Check for those locations of brams where spikes have occurred
//       for (i <- 0 until 9) {
//         dut.io.rd_enable.poke(true.B)
//         for (j <- 0 until 256) {
//           dut.io.addr_r_mempot(i).poke(j.U(8.W))
//           dut.clock.step()
//           val value = dut.io.dout_mempot(i).peek()
//           if (value(8) == 1) {
//             println(s"Spike occurred at location $j of bram $i")
//           }
//         }
//         dut.io.rd_enable.poke(false.B)
//       }
//     }
//   }
// }

// object Main extends App {
//   val verilogString = chisel3.getVerilogString(new mempot_with_thresh)
//   val verilogFile = new File("mempot_with_thresh.v")
//   val writer = new PrintWriter(verilogFile)
//   writer.write(verilogString)
//   writer.close()
// }


//       dut.io.max_pool_enab.poke(0.U(2.W))


//       // Fill few locations of the brams with different values
//       for (i <- 0 until 9) {
//         dut.io.wr_enable(i).poke(true.B)
//         dut.io.addr_w_mempot(i).poke(0.U(8.W))
//         dut.io.din_mempot(i).poke(i.U(9.W))
//         dut.clock.step()
//         dut.io.addr_w_mempot(i).poke(1.U(8.W))
//         dut.io.din_mempot(i).poke((i+1).U(9.W))
//         dut.clock.step()
//         dut.io.addr_w_mempot(i).poke(2.U(8.W))
//         dut.io.din_mempot(i).poke((i+2).U(9.W))
//         dut.clock.step()
//         dut.io.wr_enable(i).poke(false.B)
//       }

//       // Enable thresholding
//       dut.io.thresh_enab.poke(true.B)
//       dut.clock.step(256)

//       // Check the output of brams1 for the locations where address of spikes occurred
//       for (i <- 0 until 9) {
//         dut.io.rd_enable.poke(true.B)
//         dut.io.addr_r_aeq(i).poke(0.U(8.W))
//         dut.clock.step()
//         println(s"Output at location 0 of bram1 $i: ${dut.io.dout_aeq(i).peek()}")
//         dut.io.addr_r_aeq(i).poke(1.U(8.W))
//         dut.clock.step()
//         println(s"Output at location 1 of bram1 $i: ${dut.io.dout_aeq(i).peek()}")
//         dut.io.addr_r_aeq(i).poke(2.U(8.W))
//         dut.clock.step()
//         println(s"Output at location 2 of bram1 $i: ${dut.io.dout_aeq(i).peek()}")
//         dut.io.rd_enable.poke(false.B)
//       }

//       // Check for those locations of brams where spikes have occurred
//       for (i <- 0 until 9) {
//         dut.io.rd_enable.poke(true.B)
//         for (j <- 0 until 256) {
//           dut.io.addr_r_mempot(i).poke(j.U(8.W))
//           dut.clock.step()
//           val value = dut.io.dout_mempot(i).peek()
//           if (value(8) == 1) {
//             println(s"Spike occurred at location $j of bram $i")
//           }
//         }
//         dut.io.rd_enable.poke(false.B)
//       }
//     }
//   }
// }

// object Main extends App {
//   val verilogString = chisel3.getVerilogString(new mempot_with_thresh)
//   val verilogFile = new File("mempot_with_thresh.v")
//   val writer = new PrintWriter(verilogFile)
//   writer.write(verilogString)
//   writer.close()
// }


        println(s"Output at location 0 of bram1 $i: ${dut.io.dout_aeq(i).peek()}")
        dut.io.addr_r_aeq(i).poke(1.U(8.W))
        dut.clock.step()
        println(s"Output at location 1 of bram1 $i: ${dut.io.dout_aeq(i).peek()}")
        dut.io.addr_r_aeq(i).poke(2.U(8.W))
        dut.clock.step()
        println(s"Output at location 2 of bram1 $i: ${dut.io.dout_aeq(i).peek()}")
        dut.io.rd_enable.poke(false.B)
      }

      // Check for those locations of brams where spikes have occurred
      for (i <- 0 until 9) {
        dut.io.rd_enable.poke(true.B)
        for (j <- 0 until 256) {
          dut.io.addr_r_mempot(i).poke(j.U(8.W))
          dut.clock.step()
          val value = dut.io.dout_mempot(i).peek()
          if (value(8) == 1) {
            println(s"Spike occurred at location $j of bram $i")
          }
        }
        dut.io.rd_enable.poke(false.B)
      }
    }
  }
}

object Main extends App {
  val verilogString = chisel3.getVerilogString(new mempot_with_thresh)
  val verilogFile = new File("mempot_with_thresh.v")
  val writer = new PrintWriter(verilogFile)
  writer.write(verilogString)
  writer.close()
}

