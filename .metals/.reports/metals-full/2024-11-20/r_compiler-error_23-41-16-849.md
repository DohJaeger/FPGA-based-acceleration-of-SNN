file://<WORKSPACE>/chisel_codes/src/main/scala/tile.scala
### java.lang.IndexOutOfBoundsException: -1

occurred in the presentation compiler.

presentation compiler configuration:


action parameters:
offset: 5991
uri: file://<WORKSPACE>/chisel_codes/src/main/scala/tile.scala
text:
```scala
import chisel3._
import chisel3.util._
import java.io.File
import java.io.PrintWriter

// tile depth: T
// tile width: N
class tile(T: Int, N: Int, mempot_width: Int) extends Module {
    val io = IO(new Bundle {
        
        // input aeq read
        val rd_en_aeq_i = Output(Bool())
        val rd_addr_aeq_i = Output(UInt(9.W))   //assumed input aeq depth = 256(8 bits)
        val rd_data_aeq_i = Input(UInt(9.W))     //aeq width = 9 bits
        
        // output aeq write (after thresholding)
        val wr_en_aeq_o = Output(Bool())
        val wr_addr_aeq_o = Output(UInt(9.W))   //assumed output aeq depth = 256(8bit)
        val wr_data_aeq_o = Output(UInt(9.W))

        // main mempot rd/wr
        val wr_en_main_mempot = Output(Vec(9, Bool()))
        val wr_addr_main_mempot = Output(Vec(9, UInt(8.W)))
        val wr_data_main_mempot = Output(Vec(9, UInt(9.W)))

        val rd_en_main_mempot = Output(Vec(9, Bool()))
        val rd_addr_main_mempot = Output(Vec(9, UInt(8.W)))
        val rd_data_main_mempot = Input(Vec(9, UInt(9.W)))      //membrane pixel width 9 bits

        // boundary/local mempots
        // L1_N --> north boundary pixels in this tile
        // L2_N --> north boundary pixels in the other tile
        // L1_S --> south boundary pixels in this tile
        // L2_S --> south boundary pixels in the pther tile
        val wr_en_L2_N = Output(Vec(3, Bool()))     //3 parallel interlacing for now(as kernel: 3x3)
        val wr_addr_L2_N = Output(Vec(3, UInt(8.W)))
        val wr_data_L2_N = Output(Vec(3, UInt(9.W)))

        val wr_en_L2_S = Output(Vec(3, Bool()))     //3 parallel interlacing for now(as kernel: 3x3)
        val wr_addr_L2_S = Output(Vec(3, UInt(8.W)))
        val wr_data_L2_S = Output(Vec(3, UInt(9.W)))

        val rd_en_L1_N = Output(Vec(3, Bool()))
        val rd_addr_L1_N = Output(Vec(3, UInt(8.W)))
        val rd_data_L1_N = Input(Vec(3, UInt(9.W)))     //membrane pixel width 9 bits

        val rd_en_L1_S = Output(Vec(3, Bool()))
        val rd_addr_L1_S = Output(Vec(3, UInt(8.W)))
        val rd_data_L1_S = Input(Vec(3, UInt(9.W)))     //membrane pixel width 9 bits

        // network params
        val thresh_en = Input(Bool())
        val conv_en = Input(Bool())
        val bias = Input(Vec(9, UInt(8.W)))
        val V_t = Input(UInt(8.W))
        val kernel = Input(Vec(9, UInt(8.W)))
    })

    // IO init
    io.rd_en_aeq_i := false.B
    io.rd_addr_aeq_i := 0.U

    io.wr_en_aeq_o := false.B
    io.wr_addr_aeq_o := 0.U
    io.wr_data_aeq_o := 0.U

    io.wr_en_main_mempot := VecInit(Seq.fill(9)(false.B))
    io.wr_addr_main_mempot := VecInit(Seq.fill(9)(0.U(8.W)))
    io.wr_data_main_mempot := VecInit(Seq.fill(9)(0.U(9.W)))

    io.rd_en_main_mempot := VecInit(Seq.fill(9)(false.B))
    io.rd_addr_main_mempot := VecInit(Seq.fill(9)(0.U(8.W)))

    io.wr_en_L2_N := VecInit(Seq.fill(3)(false.B))
    io.wr_addr_L2_N := VecInit(Seq.fill(3)(0.U(8.W)))
    io.wr_data_L2_N := VecInit(Seq.fill(3)(0.U(9.W)))

    io.wr_en_L2_S := VecInit(Seq.fill(3)(false.B))
    io.wr_addr_L2_S := VecInit(Seq.fill(3)(0.U(8.W)))
    io.wr_data_L2_S := VecInit(Seq.fill(3)(0.U(9.W)))

    io.rd_en_L1_N := VecInit(Seq.fill(3)(false.B))
    io.rd_addr_L1_N := VecInit(Seq.fill(3)(0.U(8.W)))

    io.rd_en_L1_S := VecInit(Seq.fill(3)(false.B))
    io.rd_addr_L1_S := VecInit(Seq.fill(3)(0.U(8.W)))

    // // memory init
    // val input_aeq_depth = tile_width * tile_depth
    // val output_aeq_depth = tile_width * tile_depth
    // val mem_interlac_size = 9     // # of parallel BRAMs
    // val mempot_depth = (tile_depth * tile_width) / 9    // assuming perfect 3x3 blocks in the tile for now

    // val input_aeq = Module(new Memory(input_aeq_depth, 9))
    // val output_aeq = Module(new Memory(output_aeq_depth, 9))
    // val mempot = Seq.fill(mem_interlac_size)(Module(new Memory(mempot_depth, mempot_width)))

    // // Default signal connections for all memories
    // input_aeq.io.rdAddr := 0.U
    // input_aeq.io.rdData := DontCare
    // input_aeq.io.wrAddr := 0.U
    // input_aeq.io.wrData := 0.U
    // input_aeq.io.wrEna := false.B
    // input_aeq.io.rdEna := false.B

    // output_aeq.io.rdAddr := 0.U
    // output_aeq.io.rdData := DontCare
    // output_aeq.io.wrAddr := 0.U
    // output_aeq.io.wrData := 0.U
    // output_aeq.io.wrEna := false.B
    // output_aeq.io.rdEna := false.B

    // for (i <- 0 until mem_interlac_size) {
    //     mempot(i).io.rdAddr := 0.U
    //     mempot(i).io.rdData := DontCare
    //     mempot(i).io.wrAddr := 0.U
    //     mempot(i).io.wrData := 0.U
    //     mempot(i).io.wrEna := false.B
    //     mempot(i).io.rdEna := false.B
    // }   //memory init done

    val rotated_kernel = Wire(Vec(9, UInt(8.W)))
    for (l <- 0 until 9) {
        rotated_kernel(l) := io.kernel(8 - l)
    }

    val writeCounters = RegInit(VecInit(Seq.fill(9)(0.U(8.W))))
    val thresh_done = WireDefault(Bool(), false.B)
    val conv_done = WireDefault(Bool(), false.B)

    // pipeline regs and signals
    val s1_addr_calc = Reg(Vec(9, UInt(8.W)))
    val s2_mempot_rd = Reg(Vec(9, UInt(9.W)))
    val s3_conv = Reg(Vec(9, UInt(9.W)))

    val s1_valid = RegInit(false.B)
    val s2_valid = RegInit(false.B)
    val s3_valid = RegInit(false.B)
    val s4_valid = RegInit(false.B)
    val pipe_stall = Wire(Bool())
    pipe_stall := false.B

    // convolution pipeline stages
    // stage - 1: fetch spike event and calculate the neighbour address
    // stage - 2: access mempot
    // stage - 3: do the convolution
    // stage - 4: main/local mempot update

    //stage: 1
    val tot_hor_blk = N/3 + N%3
    val tot_ver_blk = T/3 + T%3

    val read_counter = RegInit(0.U(8.W))
    when(!pipe_stall && io.conv_en) {
        io.rd_en_aeq_i := true.B
        io.rd_addr_aeq_i := read_counter
        val spike_event = rd_data_aeq_i

        when(spike_event(0)){   // spike_event = EOQ(1) + Blk(4) + col(4) + valid(1)
            val blk_in = spike_event(@@)
        }
    }

}

object tile extends App {
  val verilogString = chisel3.getVerilogString(new tile(6, 27, 8))
  val verilogFile = new File("tile.sv")
  val writer = new PrintWriter(verilogFile)
  writer.write(verilogString)
  writer.close()
}

```



#### Error stacktrace:

```
scala.collection.LinearSeqOps.apply(LinearSeq.scala:129)
	scala.collection.LinearSeqOps.apply$(LinearSeq.scala:128)
	scala.collection.immutable.List.apply(List.scala:79)
	dotty.tools.dotc.util.Signatures$.applyCallInfo(Signatures.scala:244)
	dotty.tools.dotc.util.Signatures$.computeSignatureHelp(Signatures.scala:101)
	dotty.tools.dotc.util.Signatures$.signatureHelp(Signatures.scala:88)
	dotty.tools.pc.SignatureHelpProvider$.signatureHelp(SignatureHelpProvider.scala:47)
	dotty.tools.pc.ScalaPresentationCompiler.signatureHelp$$anonfun$1(ScalaPresentationCompiler.scala:422)
```
#### Short summary: 

java.lang.IndexOutOfBoundsException: -1