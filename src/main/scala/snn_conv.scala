// //> using scala "2.13.12"
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

// class snn_conv extends Module {
//   val io = IO(new Bundle {
//     val wr_enable = Input(Vec(9, Bool()))
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
//     val conv_enab = Input(Bool())
//     val kernel = Input(Vec(9, UInt(8.W)))
//     val max_pool_enab = Input(Bool())
//   })

//   val aeq_in = Module(new AEQ(256, 11))
//   val mempot = Module(new mempot(48, 9))

//   val rotated_kernel = Wire(Vec(9, UInt(8.W)))
//   for (l <- 0 until 9) {
//     rotated_kernel(l) := io.kernel(8 - l)
//   }

//   // val brams = Seq.fill(9)(SyncReadMem(256, UInt(9.W))) // MemPot
//   // val brams1 = Seq.fill(9)(SyncReadMem(256, UInt(10.W))) // 8 bit data + 1 valid bit + 1 EOQ <- AEQ
//   val writeCounters = RegInit(VecInit(Seq.fill(9)(0.U(8.W))))
//   val thresh_done = Wire(Bool())
//   val conv_done = WireDefault(Bool(), false.B)
//   val write_done_max_pool = WireDefault(Bool(), false.B)
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
//     io.thresh_enab && !io.conv_enab,
//     256
//   ) // Creates a counter from 0 to 255
//   when(wrap) {
//     thresh_done := true.B
//   }
//     .otherwise {
//       thresh_done := false.B
//     }
//   when(!wrap) {
//     when(io.thresh_enab && !io.conv_enab) {
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
//     when(!io.max_pool_enab) {
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

//         /*when (io.wr_enable_aeq(i)){
//         for (k <- 0 until count-1){
//           val data = Cat(0.U(1.W), t(k), 1.U(1.W)) //EOQ bit + data + valid bit
//           brams1(i).write(writeCounters(i), data)
//           writeCounters(i) := writeCounters(i) + 1.U
//         }
//         when (writeCounters(i) === (count - 1).asUInt(8.W)){
//           val lastData = Cat(1.U(1.W), t(count -1), 1.U(1.W)) // EOQ bit set
//           brams1(i).write(writeCounters(i), lastData)
//         }
//       }*/

//       }
//     }
//       .elsewhen(io.max_pool_enab) {
//         val sequ = Seq(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 48,
//           49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 96, 97,
//           98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
//           144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157,
//           158, 159, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203,
//           204, 205, 206, 207)
//         for (i <- sequ) {
//           for (j <- i to i + 2 * 16 by 16) {
//             when(io.rd_enable) {
//               val highestBits: Vec[Bool] = brams.map(b => b.read(j.asUInt(8.W)))(8).asTypeOf(Vec(brams.length, Bool()))
//               val decision = highestBits.exists(_ === 1.U)

//               when(decision)
//                {
//                 val col = (j / 16 + 3 * (j % 16)) % 9
//                 val aeq_dat = (i / 48) * 5 + ((i + i / 48) / 3) % 16
//                 when(io.wr_enable_aeq(col)) {
//                   val valid_dat = Cat(0.U(1.W), aeq_dat.asUInt(8.W), 1.U(1.W))
//                   brams1(col).write(writeCounters(col), valid_dat)
//                   writeCounters(col) := writeCounters(col) + 1.U
//                 }
//               }
//             }
//           }
//         }
//         for (t <- 240 to 255) {
//           when(io.rd_enable) {
//             val highestBits1: Vec[Bool] = brams.map(b => b.read(t.asUInt(8.W)))(8).asTypeOf(Vec(brams.length, Bool()))
//             val decision1 = highestBits1.exists(_ === 1.U)
//             when(
//               decision1
//             ) {
//               val colu = t % 9
//               val aeq_datu = t / 9
//               when(io.wr_enable_aeq(colu)) {
//                 val valid_datu = Cat(0.U(1.W), aeq_datu.asUInt(8.W), 1.U(1.W))
//                 brams1(colu).write(writeCounters(colu), valid_datu)
//                 writeCounters(colu) := writeCounters(colu) + 1.U

//               }
//             }
//           }
//           when(t.asUInt(8.W) === 255.U) {
//             write_done_max_pool := true.B
//           }
//         }

//         when(write_done_max_pool) {
//           for (g <- 0 until 9) {
//             val count = RegInit(0.U(5.W))
//             when(io.rd_enable) {
//               val aeq_datum = brams1(g).read(count)

//               when(aeq_datum(0)) {
//                 count := count + 1.U
//               }
//                 .elsewhen(!aeq_datum(0)) {
//                   when(count > 0.U) {
//                     when(io.rd_enable) {
//                       val prev_dat = brams1(g).read(count - 1.U)

//                       val mod_dat = Cat(1.U(1.W), prev_dat, 1.U(1.W))

//                       when(io.wr_enable_aeq(g)) {
//                         brams1(g).write(count - 1.U, mod_dat)
//                       }
//                     }
//                   }
//                 }
//             }

//           }
//         }
//       }

//   }

//  /* val readCounter = RegInit(0.U(8.W))
//   val columnSelectCounter = RegInit(0.U(4.W))
//   when(!conv_done) {
//     when(io.conv_enab && !io.thresh_enab) {
//       when(io.rd_enable) {
//         //val x = columnSelectCounter.litValue()
        
//         val AEQ_dat = brams1(columnSelectCounter).read(readCounter)  // Please help resolve this problem , conversion to and fro between Scala Int and Chisel UInt in convolution unit else I will have to rethink the entire convolution unit again. Also , this algorithm below is very clever way of doing the convolution efficiently.
//         when(AEQ_dat(0)) {
//           val main_dat = AEQ_dat(8, 1)
//           val m = 3.U * (main_dat / 16.U) + (columnSelectCounter % 3.U)
//           val n = 3.U * (main_dat % 16.U) + (columnSelectCounter / 3.U)
//           for (k <- 0 to 2) {
//             for (l <- 0 to 2) {
//               val mk = m - 1.U + k.asUInt(8.W)
//               val nl = n - 1.U + l.asUInt(8.W)
//               val b = 16.U * (mk / 3.U) + (nl / 3.U)
//               val c = (mk % 3.U) + 3.U * (nl % 3.U)
//               val z = c.litValue()
//               val o = z.toInt
//               val mempot_dat = brams(o).read(b)
//               val main_mempot_dat = mempot_dat(7, 0)
//               val kernel_added =
//                 main_mempot_dat + rotated_kernel(4 + (l - 1) + 3 * (k - 1))
//               when(io.wr_enable(c)) {
//                 brams(o).write(b, kernel_added)
//               }

//             }
//           }
//         }
//         readCounter := readCounter + 1.U
//         when(AEQ_dat(9) || !AEQ_dat(0)) {
//           columnSelectCounter := columnSelectCounter + 1.U
//           readCounter := 0.U
//         }
//       }
//       when(columnSelectCounter === 8.U) {
//         val last_column_dat = brams1(8).read(readCounter)
//         when(last_column_dat(9) || !last_column_dat(0)) {
//           conv_done := true.B

//         }
//       }

//     }
//   }*/


// }

// /*object Main extends App {
//    println(
//       ChiselStage.emitSystemVerilog(
//          gen = new snn_conv_commented,
//         firtoolOpts =  Array("-disable-all-randomization","-strip-debug-info")

// )
// )
// }*/
// // object conv extends App {
// //   val verilogString = chisel3.getVerilogString(new snn_conv)
// //   val verilogFile = new File("snn_conv.sv")
// //   val writer = new PrintWriter(verilogFile)
// //   writer.write(verilogString)
// //   writer.close()
// // }