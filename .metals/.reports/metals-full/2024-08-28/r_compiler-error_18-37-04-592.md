file://<WORKSPACE>/src/main/scala/cc.scala
### file%3A%2F%2F%2Fhome%2Frahul%2FDocuments%2FBTP%2FSNN_Chisel%2Fchisel_snn_rahul%2Fsrc%2Fmain%2Fscala%2Fcc.scala:443: error: `identifier` expected but `}` found
}
^

occurred in the presentation compiler.

presentation compiler configuration:
Scala version: 2.12.19
Classpath:
<HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala-library/2.12.19/scala-library-2.12.19.jar [exists ]
Options:



action parameters:
uri: file://<WORKSPACE>/src/main/scala/cc.scala
text:
```scala
//> using scala "2.13.12"
//> using dep  "org.chipsalliance::chisel::6.0.0"
//> using plugin "org.chipsalliance:::chisel-plugin::6.0.0"
//> using options "-unchecked", "-deprecation", "-language:reflectiveCalls", "-feature", "-Xcheckinit", "-Xfatal-warnings", "-Ywarn-dead-code", "-Ywarn-unused", "-Ymacro-annotations"


import chisel3._
import chisel3.util._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.freespec.AnyFreeSpec
import chisel3.stage.ChiselStage

import java.io.File
import java.io.PrintWriter


class snn_conv_commeneted extends Module {
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
    val conv_enab = Input(Bool())
    val kernel = Input(Vec(9, UInt(8.W)))
    val max_pool_enab = Input(UInt(2.W))
  })
  val rotated_kernel = Wire(Vec(9, UInt(8.W)))
  for (l <- 0 until 9) {
    rotated_kernel(l) := io.kernel(8 - l)
  }

  val brams = Seq.fill(9)(SyncReadMem(256, UInt(9.W))) // MemPot
  val brams1 = Seq.fill(9)(SyncReadMem(256, UInt(10.W))) // 8 bit data + 1 valid bit + 1 end of queue bit <- AEQ
  

  val writeCounters = RegInit(VecInit(Seq.fill(9)(0.U(8.W))))
  val thresh_done = Wire(Bool())
  val conv_done = WireDefault(Bool(), false.B)
  val write_done_max_pool = WireDefault(Bool(), false.B)
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
    io.thresh_enab && !io.conv_enab,
    256
  ) // Creates a counter from 0 to 255
  when(wrap) {
    thresh_done := true.B
  }
    .otherwise {
      thresh_done := false.B
    }
  when(!wrap) {
    when(io.thresh_enab && !io.conv_enab) {
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

        /*when (io.wr_enable_aeq(i)){
        for (k <- 0 until count-1){
          val data = Cat(0.U(1.W), t(k), 1.U(1.W)) //EOQ bit + data + valid bit
          brams1(i).write(writeCounters(i), data)
          writeCounters(i) := writeCounters(i) + 1.U
        }
        when (writeCounters(i) === (count - 1).asUInt(8.W)){
          val lastData = Cat(1.U(1.W), t(count -1), 1.U(1.W)) // EOQ bit set
          brams1(i).write(writeCounters(i), lastData)
        }
      }*/

      }
    }
      .elsewhen(io.max_pool_enab === 3.U) {
        val sequ = Seq(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 48,
          49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 96, 97,
          98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
          144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157,
          158, 159, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203,
          204, 205, 206, 207)
        for (i <- sequ) {
          for (j <- i to i + 2 * 16 by 16) {
            when(io.rd_enable) {
              /*val mem_max0 = brams(0).read(j.asUInt(8.W))
              val mem_max1 = brams(1).read(j.asUInt(8.W))
              val mem_max2 = brams(2).read(j.asUInt(8.W))
              val mem_max3 = brams(3).read(j.asUInt(8.W))
              val mem_max4 = brams(4).read(j.asUInt(8.W))
              val mem_max5 = brams(5).read(j.asUInt(8.W))
              val mem_max6 = brams(6).read(j.asUInt(8.W))
              val mem_max7 = brams(7).read(j.asUInt(8.W))
              val mem_max8 = brams(8).read(j.asUInt(8.W))*/
              //val decision = brams.map(b => b.read(j.asUInt(8.W)))(8) // Extract highest bit from each Bram
              val highestBits: Vec[Bool] = brams.map(b => b.read(j.asUInt(8.W)))(8).asTypeOf(Vec(brams.length, Bool()))
              val decision = highestBits.exists(_ === 1.U)

              when(decision)
               {
                val col = (j / 16 + 3 * (j % 16)) % 9
                val aeq_dat = (i / 48) * 5 + ((i + i / 48) / 3) % 16
                when(io.wr_enable_aeq(col)) {
                  val valid_dat = Cat(0.U(1.W), aeq_dat.asUInt(8.W), 1.U(1.W))
                  brams1(col).write(writeCounters(col), valid_dat)
                  writeCounters(col) := writeCounters(col) + 1.U
                }
              }
            }
          }
        }
        for (t <- 240 to 255) {
          when(io.rd_enable) {
            /*val mem0 = brams(0).read(t.asUInt(8.W))
            val mem1 = brams(1).read(t.asUInt(8.W))
            val mem2 = brams(2).read(t.asUInt(8.W))
            val mem3 = brams(3).read(t.asUInt(8.W))
            val mem4 = brams(4).read(t.asUInt(8.W))
            val mem5 = brams(5).read(t.asUInt(8.W))
            val mem6 = brams(6).read(t.asUInt(8.W))
            val mem7 = brams(7).read(t.asUInt(8.W))
            val mem8 = brams(8).read(t.asUInt(8.W))*/
            val highestBits1: Vec[Bool] = brams.map(b => b.read(t.asUInt(8.W)))(8).asTypeOf(Vec(brams.length, Bool()))
            val decision1 = highestBits1.exists(_ === 1.U)
            when(
              decision1
            ) {
              val colu = t % 9
              val aeq_datu = t / 9
              when(io.wr_enable_aeq(colu)) {
                val valid_datu = Cat(0.U(1.W), aeq_datu.asUInt(8.W), 1.U(1.W))
                brams1(colu).write(writeCounters(colu), valid_datu)
                writeCounters(colu) := writeCounters(colu) + 1.U

              }
            }
          }
          when(t.asUInt(8.W) === 255.U) {
            write_done_max_pool := true.B
          }
        }

        when(write_done_max_pool) {
          for (g <- 0 until 9) {
            val count = RegInit(0.U(5.W))
            when(io.rd_enable) {
              val aeq_datum = brams1(g).read(count)

              when(aeq_datum(0)) {
                count := count + 1.U
              }
                .elsewhen(!aeq_datum(0)) {
                  when(count > 0.U) {
                    when(io.rd_enable) {
                      val prev_dat = brams1(g).read(count - 1.U)

                      val mod_dat = Cat(1.U(1.W), prev_dat, 1.U(1.W))

                      when(io.wr_enable_aeq(g)) {
                        brams1(g).write(count - 1.U, mod_dat)
                      }
                    }
                  }
                }
            }

          }
        }
      }
      .otherwise{
        val seq2 = Seq(0, 32, 64, 96, 128, 160, 192, 224, 2, 34, 66, 98, 130, 162, 194, 226, 4, 36, 68, 100, 132, 164, 196, 228, 6, 38, 70, 102, 134, 166, 198, 230, 8, 40, 72, 104, 136, 168, 200, 232, 10, 42, 74, 106, 138, 170, 202, 234, 12, 44, 76, 108, 140, 172, 204, 236, 14, 46, 78, 110, 142, 174, 206, 238)
        for (k <- seq2){
          when (io.rd_enable){
            val highestBits_k: Vec[Bool] = brams.map(b => b.read(k.asUInt(8.W)))(8).asTypeOf(Vec(brams.length, Bool()))
            val highestBits_k1: Vec[Bool] = brams.map(b => b.read((k+1).asUInt(8.W)))(8).asTypeOf(Vec(brams.length, Bool()))
            val highestBits_k16: Vec[Bool] = brams.map(b => b.read((k+16).asUInt(8.W)))(8).asTypeOf(Vec(brams.length, Bool()))
            val highestBits_k17: Vec[Bool] = brams.map(b => b.read((k+17).asUInt(8.W)))(8).asTypeOf(Vec(brams.length, Bool()))
          
          
          val aeq_datum = ((k / 16) * 16 -  ((k / 16) % 2) * 16) / 4 + ( k - (k / 16) * 16) / 2
          when (highestBits_k(0) || highestBits_k(1) || highestBits_k(3) || highestBits_k(4)){
            val col0 = 0
            when(io.wr_enable_aeq(col0)) {
              val valid_dat0 = Cat(0.U(1.W), aeq_datum.asUInt(8.W), 1.U(1.W))
              brams1(col0).write(writeCounters(col0), valid_dat0)
              writeCounters(col0) := writeCounters(col0) + 1.U
            }
            
          }
          when (highestBits_k(2) || highestBits_k(5) || highestBits_k16(0) || highestBits_k16(3)){
            val col1 = 1
            when(io.wr_enable_aeq(col1)) {
              val valid_dat1 = Cat(0.U(1.W), aeq_datum.asUInt(8.W), 1.U(1.W))
              brams1(col1).write(writeCounters(col1), valid_dat1)
              writeCounters(col1) := writeCounters(col1) + 1.U
            }           
          }
          when (highestBits_k16(1) || highestBits_k16(2) || highestBits_k16(4) || highestBits_k16(5)){
            val col2 = 2
            when(io.wr_enable_aeq(col2)) {
              val valid_dat2 = Cat(0.U(1.W), aeq_datum.asUInt(8.W), 1.U(1.W))
              brams1(col2).write(writeCounters(col2), valid_dat2)
              writeCounters(col2) := writeCounters(col2) + 1.U
            }            
          }
          when (highestBits_k(6) || highestBits_k(7) || highestBits_k1(0) || highestBits_k1(1)){
            val col3 = 3
            when(io.wr_enable_aeq(col3)) {
              val valid_dat3 = Cat(0.U(1.W), aeq_datum.asUInt(8.W), 1.U(1.W))
              brams1(col3).write(writeCounters(col3), valid_dat3)
              writeCounters(col3) := writeCounters(col3) + 1.U
            }
          }
          when (highestBits_k(8) || highestBits_k16(6) || highestBits_k1(2) || highestBits_k1(0)){
            val col4 = 4
            when(io.wr_enable_aeq(col4)) {
              val valid_dat4 = Cat(0.U(1.W), aeq_datum.asUInt(8.W), 1.U(1.W))
              brams1(col4).write(writeCounters(col4), valid_dat4)
              writeCounters(col4) := writeCounters(col4) + 1.U
            }
          }
          when (highestBits_k16(7) || highestBits_k16(8) || highestBits_k17(1) || highestBits_k17(2)){
            val col5 = 5
            when(io.wr_enable_aeq(col5)) {
              val valid_dat5 = Cat(0.U(1.W), aeq_datum.asUInt(8.W), 1.U(1.W))
              brams1(col5).write(writeCounters(col5), valid_dat5)
              writeCounters(col5) := writeCounters(col5) + 1.U
            }
          }
          when (highestBits_k1(3) || highestBits_k1(4) || highestBits_k1(6) || highestBits_k1(7)){
            val col6 = 6
            when(io.wr_enable_aeq(col6)) {
              val valid_dat6 = Cat(0.U(1.W), aeq_datum.asUInt(8.W), 1.U(1.W))
              brams1(col6).write(writeCounters(col6), valid_dat6)
              writeCounters(col6) := writeCounters(col6) + 1.U
            }
          }
          when (highestBits_k1(5) || highestBits_k1(8) || highestBits_k17(3) || highestBits_k17(6)){
            val col7 = 7
            when(io.wr_enable_aeq(col7)) {
              val valid_dat7 = Cat(0.U(1.W), aeq_datum.asUInt(8.W), 1.U(1.W))
              brams1(col7).write(writeCounters(col7), valid_dat7)
              writeCounters(col7) := writeCounters(col7) + 1.U
            }
          }
          when (highestBits_k17(4) || highestBits_k17(5) || highestBits_k17(7) || highestBits_k17(8)){
            val col8 = 8
            when(io.wr_enable_aeq(col8)) {
              val valid_dat8 = Cat(0.U(1.W), aeq_datum.asUInt(8.W), 1.U(1.W))
              brams1(col8).write(writeCounters(col8), valid_dat8)
              writeCounters(col8) := writeCounters(col8) + 1.U
            }
          }
        }
        when (k.asUInt(8.W) === (seq2.last).U){
          write_done_max_pool := true.B

          }

        }
        when(write_done_max_pool) {
          for (g <- 0 until 9) {
            val count = RegInit(0.U(6.W))
            when(io.rd_enable) {
              val aeq_datum = brams1(g).read(count)

              when(aeq_datum(0)) {
                count := count + 1.U
              }
                .elsewhen(!aeq_datum(0)) {
                  when(count > 0.U) {
                    when(io.rd_enable) {
                      val prev_dat = brams1(g).read(count - 1.U)

                      val mod_dat = Cat(1.U(1.W), prev_dat, 1.U(1.W))

                      when(io.wr_enable_aeq(g)) {
                        brams1(g).write(count - 1.U, mod_dat)
                      }
                    }
                  }
                }
            }

          }
        }
      }
        

      

  }

 /* val readCounter = RegInit(0.U(8.W))
  val columnSelectCounter = RegInit(0.U(4.W))
  when(!conv_done) {
    when(io.conv_enab && !io.thresh_enab) {
      when(io.rd_enable) {
        //val x = columnSelectCounter.litValue()
        
        val AEQ_dat = brams1(columnSelectCounter).read(readCounter)  // Please help resolve this problem , conversion to and fro between Scala Int and Chisel UInt in convolution unit else I will have to rethink the entire convolution unit again. Also , this algorithm below is very clever way of doing the convolution efficiently.
        when(AEQ_dat(0)) {
          val main_dat = AEQ_dat(8, 1)
          val m = 3.U * (main_dat / 16.U) + (columnSelectCounter % 3.U)
          val n = 3.U * (main_dat % 16.U) + (columnSelectCounter / 3.U)
          for (k <- 0 to 2) {
            for (l <- 0 to 2) {
              val mk = m - 1.U + k.asUInt(8.W)
              val nl = n - 1.U + l.asUInt(8.W)
              val b = 16.U * (mk / 3.U) + (nl / 3.U)
              val c = (mk % 3.U) + 3.U * (nl % 3.U)
              val z = c.litValue()
              val o = z.toInt
              val mempot_dat = brams(o).read(b)
              val main_mempot_dat = mempot_dat(7, 0)
              val kernel_added =
                main_mempot_dat + rotated_kernel(4 + (l - 1) + 3 * (k - 1))
              when(io.wr_enable(c)) {
                brams(o).write(b, kernel_added)
              }

            }
          }
        }
        readCounter := readCounter + 1.U
        when(AEQ_dat(9) || !AEQ_dat(0)) {
          columnSelectCounter := columnSelectCounter + 1.U
          readCounter := 0.U
        }
      }
      when(columnSelectCounter === 8.U) {
        val last_column_dat = brams1(8).read(readCounter)
        when(last_column_dat(9) || !last_column_dat(0)) {
          conv_done := true.B

        }
      }

    }
  }*/


}

// object Main extends App {
//    println(
//       ChiselStage.emitSystemVerilog(
//          gen = new snn_conv_commented,
//         firtoolOpts =  Array("-disable-all-randomization","-strip-debug-info")

// )
// )
// }

object snn_conv_commented extends App {
    (new ChiselStage).emitFirrtl(new snn_conv_commented)
}


object snn_conv_commented extends App{
    (new ChiselStage).
}
// object Main extends App {
//   val verilogString = chisel3.getVerilogString(new snn_conv_commeneted)
//   val verilogFile = new File("snn_conv_commented.sv")
//   val writer = new PrintWriter(verilogFile)
//   writer.write(verilogString)
//   writer.close()
// }
```



#### Error stacktrace:

```
scala.meta.internal.parsers.Reporter.syntaxError(Reporter.scala:16)
	scala.meta.internal.parsers.Reporter.syntaxError$(Reporter.scala:16)
	scala.meta.internal.parsers.Reporter$$anon$1.syntaxError(Reporter.scala:22)
	scala.meta.internal.parsers.Reporter.syntaxError(Reporter.scala:17)
	scala.meta.internal.parsers.Reporter.syntaxError$(Reporter.scala:17)
	scala.meta.internal.parsers.Reporter$$anon$1.syntaxError(Reporter.scala:22)
	scala.meta.internal.parsers.ScalametaParser.syntaxErrorExpected(ScalametaParser.scala:394)
	scala.meta.internal.parsers.ScalametaParser.syntaxErrorExpected(ScalametaParser.scala:392)
	scala.meta.internal.parsers.ScalametaParser.name(ScalametaParser.scala:1138)
	scala.meta.internal.parsers.ScalametaParser.termName(ScalametaParser.scala:1141)
	scala.meta.internal.parsers.ScalametaParser.$anonfun$selector$1(ScalametaParser.scala:1197)
	scala.meta.internal.parsers.ScalametaParser.autoEndPos(ScalametaParser.scala:372)
	scala.meta.internal.parsers.ScalametaParser.selector(ScalametaParser.scala:1197)
	scala.meta.internal.parsers.ScalametaParser.simpleExprRest(ScalametaParser.scala:2149)
	scala.meta.internal.parsers.ScalametaParser.simpleExpr0(ScalametaParser.scala:2094)
	scala.meta.internal.parsers.ScalametaParser.simpleExpr(ScalametaParser.scala:2061)
	scala.meta.internal.parsers.ScalametaParser.prefixExpr(ScalametaParser.scala:2058)
	scala.meta.internal.parsers.ScalametaParser.postfixExpr(ScalametaParser.scala:1924)
	scala.meta.internal.parsers.ScalametaParser.$anonfun$expr$2(ScalametaParser.scala:1552)
	scala.meta.internal.parsers.ScalametaParser.atPosOpt(ScalametaParser.scala:327)
	scala.meta.internal.parsers.ScalametaParser.autoPosOpt(ScalametaParser.scala:370)
	scala.meta.internal.parsers.ScalametaParser.expr(ScalametaParser.scala:1480)
	scala.meta.internal.parsers.ScalametaParser$$anonfun$templateStat$1.applyOrElse(ScalametaParser.scala:4154)
	scala.meta.internal.parsers.ScalametaParser$$anonfun$templateStat$1.applyOrElse(ScalametaParser.scala:4147)
	scala.PartialFunction.$anonfun$runWith$1$adapted(PartialFunction.scala:145)
	scala.meta.internal.parsers.ScalametaParser.statSeqBuf(ScalametaParser.scala:4107)
	scala.meta.internal.parsers.ScalametaParser.getStats$2(ScalametaParser.scala:4137)
	scala.meta.internal.parsers.ScalametaParser.$anonfun$scala$meta$internal$parsers$ScalametaParser$$templateStatSeq$3(ScalametaParser.scala:4138)
	scala.meta.internal.parsers.ScalametaParser.$anonfun$scala$meta$internal$parsers$ScalametaParser$$templateStatSeq$3$adapted(ScalametaParser.scala:4136)
	scala.meta.internal.parsers.ScalametaParser.scala$meta$internal$parsers$ScalametaParser$$listBy(ScalametaParser.scala:562)
	scala.meta.internal.parsers.ScalametaParser.scala$meta$internal$parsers$ScalametaParser$$templateStatSeq(ScalametaParser.scala:4136)
	scala.meta.internal.parsers.ScalametaParser.scala$meta$internal$parsers$ScalametaParser$$templateStatSeq(ScalametaParser.scala:4128)
	scala.meta.internal.parsers.ScalametaParser.$anonfun$templateBody$1(ScalametaParser.scala:4006)
	scala.meta.internal.parsers.ScalametaParser.inBracesOr(ScalametaParser.scala:260)
	scala.meta.internal.parsers.ScalametaParser.inBraces(ScalametaParser.scala:256)
	scala.meta.internal.parsers.ScalametaParser.templateBody(ScalametaParser.scala:4006)
	scala.meta.internal.parsers.ScalametaParser.templateBodyOpt(ScalametaParser.scala:4009)
	scala.meta.internal.parsers.ScalametaParser.templateAfterExtends(ScalametaParser.scala:3960)
	scala.meta.internal.parsers.ScalametaParser.$anonfun$template$1(ScalametaParser.scala:3976)
	scala.meta.internal.parsers.ScalametaParser.atPos(ScalametaParser.scala:325)
	scala.meta.internal.parsers.ScalametaParser.autoPos(ScalametaParser.scala:369)
	scala.meta.internal.parsers.ScalametaParser.template(ScalametaParser.scala:3965)
	scala.meta.internal.parsers.ScalametaParser.$anonfun$templateOpt$1(ScalametaParser.scala:4000)
	scala.meta.internal.parsers.ScalametaParser.atPos(ScalametaParser.scala:325)
	scala.meta.internal.parsers.ScalametaParser.autoPos(ScalametaParser.scala:369)
	scala.meta.internal.parsers.ScalametaParser.templateOpt(ScalametaParser.scala:3993)
	scala.meta.internal.parsers.ScalametaParser.$anonfun$objectDef$1(ScalametaParser.scala:3722)
	scala.meta.internal.parsers.ScalametaParser.autoEndPos(ScalametaParser.scala:372)
	scala.meta.internal.parsers.ScalametaParser.autoEndPos(ScalametaParser.scala:377)
	scala.meta.internal.parsers.ScalametaParser.objectDef(ScalametaParser.scala:3714)
	scala.meta.internal.parsers.ScalametaParser.tmplDef(ScalametaParser.scala:3601)
	scala.meta.internal.parsers.ScalametaParser.topLevelTmplDef(ScalametaParser.scala:3589)
	scala.meta.internal.parsers.ScalametaParser$$anonfun$2.applyOrElse(ScalametaParser.scala:4121)
	scala.meta.internal.parsers.ScalametaParser$$anonfun$2.applyOrElse(ScalametaParser.scala:4115)
	scala.PartialFunction.$anonfun$runWith$1$adapted(PartialFunction.scala:145)
	scala.meta.internal.parsers.ScalametaParser.statSeqBuf(ScalametaParser.scala:4107)
	scala.meta.internal.parsers.ScalametaParser.$anonfun$statSeq$1(ScalametaParser.scala:4096)
	scala.meta.internal.parsers.ScalametaParser.$anonfun$statSeq$1$adapted(ScalametaParser.scala:4096)
	scala.meta.internal.parsers.ScalametaParser.scala$meta$internal$parsers$ScalametaParser$$listBy(ScalametaParser.scala:562)
	scala.meta.internal.parsers.ScalametaParser.statSeq(ScalametaParser.scala:4096)
	scala.meta.internal.parsers.ScalametaParser.bracelessPackageStats$1(ScalametaParser.scala:4285)
	scala.meta.internal.parsers.ScalametaParser.$anonfun$source$1(ScalametaParser.scala:4288)
	scala.meta.internal.parsers.ScalametaParser.atPos(ScalametaParser.scala:325)
	scala.meta.internal.parsers.ScalametaParser.autoPos(ScalametaParser.scala:369)
	scala.meta.internal.parsers.ScalametaParser.source(ScalametaParser.scala:4264)
	scala.meta.internal.parsers.ScalametaParser.entrypointSource(ScalametaParser.scala:4291)
	scala.meta.internal.parsers.ScalametaParser.parseSourceImpl(ScalametaParser.scala:119)
	scala.meta.internal.parsers.ScalametaParser.$anonfun$parseSource$1(ScalametaParser.scala:116)
	scala.meta.internal.parsers.ScalametaParser.parseRuleAfterBOF(ScalametaParser.scala:58)
	scala.meta.internal.parsers.ScalametaParser.parseRule(ScalametaParser.scala:53)
	scala.meta.internal.parsers.ScalametaParser.parseSource(ScalametaParser.scala:116)
	scala.meta.parsers.Parse$.$anonfun$parseSource$1(Parse.scala:30)
	scala.meta.parsers.Parse$$anon$1.apply(Parse.scala:37)
	scala.meta.parsers.Api$XtensionParseDialectInput.parse(Api.scala:22)
	scala.meta.internal.semanticdb.scalac.ParseOps$XtensionCompilationUnitSource.toSource(ParseOps.scala:15)
	scala.meta.internal.semanticdb.scalac.TextDocumentOps$XtensionCompilationUnitDocument.toTextDocument(TextDocumentOps.scala:161)
	scala.meta.internal.pc.SemanticdbTextDocumentProvider.textDocument(SemanticdbTextDocumentProvider.scala:54)
	scala.meta.internal.pc.ScalaPresentationCompiler.$anonfun$semanticdbTextDocument$1(ScalaPresentationCompiler.scala:469)
```
#### Short summary: 

file%3A%2F%2F%2Fhome%2Frahul%2FDocuments%2FBTP%2FSNN_Chisel%2Fchisel_snn_rahul%2Fsrc%2Fmain%2Fscala%2Fcc.scala:443: error: `identifier` expected but `}` found
}
^