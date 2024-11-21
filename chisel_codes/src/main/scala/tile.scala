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
        val rd_data_aeq_i = Input(UInt(11.W))     //aeq width = 9 bits
        
        // output aeq write (after thresholding)
        val wr_en_aeq_o = Output(Bool())
        val wr_addr_aeq_o = Output(UInt(9.W))   //assumed output aeq depth = 256(8bit)
        val wr_data_aeq_o = Output(UInt(11.W))

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
        val rd_en_L2_N = Output(Vec(3, Bool()))     //3 parallel interlacing for now(as kernel: 3x3)
        val rd_addr_L2_N = Output(Vec(3, UInt(8.W)))
        val rd_data_L2_N = Input(Vec(3, UInt(9.W)))

        val wr_en_L2_S = Output(Vec(3, Bool()))     //3 parallel interlacing for now(as kernel: 3x3)
        val wr_addr_L2_S = Output(Vec(3, UInt(8.W)))
        val wr_data_L2_S = Output(Vec(3, UInt(9.W)))
        val rd_en_L2_S = Output(Vec(3, Bool()))     //3 parallel interlacing for now(as kernel: 3x3)
        val rd_addr_L2_S = Output(Vec(3, UInt(8.W)))
        val rd_data_L2_S = Input(Vec(3, UInt(9.W)))

        val rd_en_L1_N = Output(Bool())
        val rd_addr_L1_N = Output(Vec(3, UInt(8.W)))
        val rd_data_L1_N = Input(Vec(3, UInt(9.W)))     //membrane pixel width 9 bits

        val rd_en_L1_S = Output(Bool())
        val rd_addr_L1_S = Output(Vec(3, UInt(8.W)))
        val rd_data_L1_S = Input(Vec(3, UInt(9.W)))     //membrane pixel width 9 bits

        // network params
        val thresh_en = Input(Bool())
        val conv_en = Input(Bool())
        val bias = Input(Vec(9, UInt(8.W)))
        val v_t = Input(UInt(9.W))
        val kernel = Input(Vec(9, UInt(8.W)))

        //out
        val conv_done = Output(Bool())
        val thresh_done = Output(Bool())
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
    io.rd_en_L2_N := VecInit(Seq.fill(3)(false.B))
    io.rd_addr_L2_N := VecInit(Seq.fill(3)(0.U(8.W)))

    io.wr_en_L2_S := VecInit(Seq.fill(3)(false.B))
    io.wr_addr_L2_S := VecInit(Seq.fill(3)(0.U(8.W)))
    io.wr_data_L2_S := VecInit(Seq.fill(3)(0.U(9.W)))
    io.rd_en_L2_S := VecInit(Seq.fill(3)(false.B))
    io.rd_addr_L2_S := VecInit(Seq.fill(3)(0.U(8.W)))

    io.rd_en_L1_N := false.B
    io.rd_addr_L1_N := VecInit(Seq.fill(3)(0.U(8.W)))

    io.rd_en_L1_S := false.B
    io.rd_addr_L1_S := VecInit(Seq.fill(3)(0.U(8.W)))

    io.conv_done := false.B
    io.thresh_done := false.B

    val rotated_kernel = Wire(Vec(9, UInt(8.W)))
    for (l <- 0 until 9) {
        rotated_kernel(l) := io.kernel(8 - l)
    }

    val writeCounters = RegInit(VecInit(Seq.fill(9)(0.U(8.W))))

    // pipeline regs and signals
    val s1_addr_calc = Reg(Vec(9, UInt(9.W)))   //contains block(5) and column(4)
    val s2_mempot_rd = Reg(Vec(9, UInt(9.W)))
    val s3_conv = Reg(Vec(9, UInt(9.W)))

    val s1_valid = RegInit(false.B)
    val s2_valid = RegInit(false.B)
    val s3_valid = RegInit(false.B)
    val s4_valid = RegInit(false.B)
    val pipe_stall = Wire(Bool())
    pipe_stall := false.B

    val conv_done_reg = RegInit(false.B)
    val thresh_done_reg = RegInit(false.B)

    io.conv_done := conv_done_reg
    io.thresh_done := thresh_done_reg

    // ### convolution pipeline stages ###
    // stage - 1: fetch spike event and calculate the neighbour address
    val tot_hor_blk = (N / 3 + N % 3) //here 9; hard coded temporarily to remove int and UInt mismatch error ###solve it later
    val tot_ver_blk = (T / 3 + T % 3)

    val read_counter = RegInit(0.U(8.W))    // assume input aeq depth as 256
    when(!pipe_stall && io.conv_en && !conv_done_reg) {
        io.rd_en_aeq_i := true.B
        io.rd_addr_aeq_i := read_counter
        val spike_event = io.rd_data_aeq_i
        s1_valid := false.B

        when(spike_event(0) && !spike_event(10)){   // spike_event = EOQ(1) + Blk(5) + col(4) + valid(1)
            val blk_in = spike_event(9,5)
            val col_in = spike_event(4,1)
            // val m = 3.U * (blk_in / tot_hor_blk) + (col_in % 3.U)
            val m = 3.U * (blk_in / 9.U) + (col_in % 3.U)
            // val n = 3.U * (blk_in % tot_hor_blk) + (col_in / 3.U)
            val n = 3.U * (blk_in % 9.U) + (col_in / 3.U)

            val i = RegInit(0.U)
            for(k <- 0 until 3){
                for(l <- 0 until 3){
                    val mk = m - 1.U+ k.U
                    val nl = n - 1.U + l.U
                    // val blk_out = (tot_hor_blk * (mk / 3) + nl / 3).U(4.W)
                    val blk_out = (9.U * (mk / 3.U) + nl / 3.U)
                    val col_out = ((mk % 3.U)*3.U + nl % 3.U)
                    s1_addr_calc(i) := Cat(blk_out(3,0), col_out(3,0))
                    i := i + 1.U
                }
            }
            s1_valid := true.B
        }
        read_counter := read_counter + 1.U
        when(spike_event(10) || !spike_event(0)) {
            read_counter := 0.U
            conv_done_reg := true.B
        }
    }

    // stage - 2: access main/local mempot
    when(s1_valid && !pipe_stall && io.conv_en){
        s2_valid := false.B
        when(((s1_addr_calc(6))(8,4) >= 9.U(4.W)) && ((s1_addr_calc(6))(3,0) >= 6.U(4.W))) {

            for (i <- 0 until 6) {
                io.rd_en_main_mempot(i) := true.B
                io.rd_addr_main_mempot(i) := s1_addr_calc(i)
                s2_mempot_rd(i) := io.rd_data_main_mempot(i)
            }
            io.rd_en_L2_S(0) := true.B
            io.rd_addr_L2_S(0) := s1_addr_calc(6)
            s2_mempot_rd(6) := io.rd_data_L2_S(0)

            io.rd_en_L2_S(1) := true.B
            io.rd_addr_L2_S(1) := s1_addr_calc(7)
            s2_mempot_rd(7) := io.rd_data_L2_S(1)

            io.rd_en_L2_S(2) := true.B
            io.rd_addr_L2_S(2) := s1_addr_calc(8)
            s2_mempot_rd(8) := io.rd_data_L2_S(2)

        } .elsewhen (((s1_addr_calc(0))(8,4) < 9.U(4.W)) && ((s1_addr_calc(0)(3,0)) < 3.U(4.W))) {

            io.rd_en_L2_N(0) := true.B
            io.rd_addr_L2_N(0) := s1_addr_calc(0)
            s2_mempot_rd(0) := io.rd_data_L2_N(0)

            io.rd_en_L2_N(1) := true.B
            io.rd_addr_L2_N(1) := s1_addr_calc(1)
            s2_mempot_rd(1) := io.rd_data_L2_N(1)

            io.rd_en_L2_N(2) := true.B
            io.rd_addr_L2_N(2) := s1_addr_calc(2)
            s2_mempot_rd(2) := io.rd_data_L2_N(2)

            for (i <- 3 until 9) {
                io.rd_en_main_mempot(i) := true.B
                io.rd_addr_main_mempot(i) := s1_addr_calc(i)
                s2_mempot_rd(i) := io.rd_data_main_mempot(i)
            }

        } .otherwise {
            for (i <- 0 until 9) {
                io.rd_en_main_mempot(i) := true.B
                io.rd_addr_main_mempot(i) := s1_addr_calc(i)
                s2_mempot_rd(i) := io.rd_data_main_mempot(i)
            }
        }
        s2_valid := true.B
    }

    // stage - 3: convolution
    when(s2_valid && io.conv_en) {
        for (i <- 0 until 9) {
            s3_conv(i) := s2_mempot_rd(i) + rotated_kernel(i)
        }
        s3_valid := true.B
    }

    // stage - 4: mempot write-back
    // check s1_address calc, does it reamin same after 1 cycle
    when(s3_valid && io.conv_en) {
        s4_valid := false.B
        when(((s1_addr_calc(6))(8,4) >= 9.U(4.W)) && ((s1_addr_calc(6))(3,0) >= 6.U(4.W))) {

            for (i <- 0 until 6) {
                io.wr_en_main_mempot(i) := true.B
                io.wr_addr_main_mempot(i) := s1_addr_calc(i)
                io.wr_data_main_mempot(i) := s3_conv(i)
            }
            io.wr_en_L2_S(0) := true.B
            io.wr_addr_L2_S(0) := s1_addr_calc(6)
            io.wr_data_L2_S(0) := s3_conv(6)

            io.wr_en_L2_S(1) := true.B
            io.wr_addr_L2_S(1) := s1_addr_calc(7)
            io.wr_data_L2_S(1) := s3_conv(7)

            io.wr_en_L2_S(2) := true.B
            io.wr_addr_L2_S(2) := s1_addr_calc(7)
            io.wr_data_L2_S(2) := s3_conv(7)

        } .elsewhen (((s1_addr_calc(0))(8,4) < 9.U(4.W)) && ((s1_addr_calc(0)(3,0)) < 3.U(4.W))) {

            io.wr_en_L2_S(0) := true.B
            io.wr_addr_L2_S(0) := s1_addr_calc(0)
            io.wr_data_L2_S(0) := s3_conv(0)

            io.wr_en_L2_S(1) := true.B
            io.wr_addr_L2_S(1) := s1_addr_calc(1)
            io.wr_data_L2_S(1) := s3_conv(1)

            io.wr_en_L2_S(2) := true.B
            io.wr_addr_L2_S(2) := s1_addr_calc(2)
            io.wr_data_L2_S(2) := s3_conv(2)

            for (i <- 3 until 9) {
                io.wr_en_main_mempot(i) := true.B
                io.wr_addr_main_mempot(i) := s1_addr_calc(i)
                io.wr_data_main_mempot(i) := s3_conv(i)
            }

        } .otherwise {
            for (i <- 0 until 9) {
                io.wr_en_main_mempot(i) := true.B
                io.wr_addr_main_mempot(i) := s1_addr_calc(i)
                io.wr_data_main_mempot(i) := s3_conv(i)
            }
        }
        s4_valid := true.B
    }


    // ### thresholding pipeline stages ###
    val tot_blk = tot_hor_blk * tot_ver_blk
    val (read_mem_counter, wrap) = Counter(io.thresh_en && !io.conv_en, tot_blk)
    val thresh_blk_counter = Reg(UInt(5.W))

    when(wrap) {
        thresh_done_reg := true.B
    }.otherwise {
        thresh_done_reg := false.B
    }

    io.thresh_done := thresh_done_reg

    // pipeline regs and signals
    val s1_thresh_main_mem_rd = Reg(Vec(9, UInt(9.W)))   // main mempot data
    val s1_thresh_local_mem_rd = Reg(Vec(3, UInt(9.W)))  // 3 local mem pixels
    val s2_thresh_bias_added = Reg(Vec(9, UInt(9.W)))
    val s3_thresh_aeq_out_data = Reg(Vec(9, UInt(10.W)))
    // val s3_conv = Reg(Vec(9, UInt(9.W)))

    val s1_thresh_valid = RegInit(false.B)
    val s2_thresh_valid = RegInit(false.B)
    val s3_thresh_valid = RegInit(false.B)
    // val s4_valid = RegInit(false.B)

    // stage - 1: read mempot block-wise
    when(io.thresh_en && !wrap){
        when(thresh_blk_counter < 9.U){     // for now tot_hor_blk = 9
            io.rd_en_L1_N := true.B

            for(i <- 0 until 3){
                io.rd_addr_L1_N(i) := thresh_blk_counter
                s1_thresh_local_mem_rd(i) := io.rd_data_L1_N(i)
            }

            for(i <- 0 until 9){
                io.rd_en_main_mempot(i) := true.B
                io.rd_addr_main_mempot(i) := thresh_blk_counter
                s1_thresh_main_mem_rd(i) := io.rd_data_main_mempot(i)
            }

        } .elsewhen(thresh_blk_counter >= 9.U){
            io.rd_en_L1_S := true.B

            for(i <- 0 until 3){
                io.rd_addr_L1_S(i) := thresh_blk_counter
                s1_thresh_local_mem_rd(i) := io.rd_data_L1_S(i)
            }

            for(i <- 0 until 9){
                io.rd_en_main_mempot(i) := true.B
                io.rd_addr_main_mempot(i) := thresh_blk_counter
                s1_thresh_main_mem_rd(i) := io.rd_data_main_mempot(i)
            }

        }
        thresh_blk_counter := thresh_blk_counter + 1.U
        s1_thresh_valid := true.B
    }
        
    // stage - 2: add bias compare and 
    when(s1_thresh_valid){
        for(i <- 0 until 3){
            s2_thresh_bias_added(i) := s1_thresh_main_mem_rd(i) + s1_thresh_local_mem_rd(i) + io.bias(i)

        }

        for(i <- 3 until 9){
            s2_thresh_bias_added(i) := s1_thresh_main_mem_rd(i) + io.bias(i)
        }
        s2_thresh_valid := true.B
    }

    // stage - 3: compare to threshold
    val s3_thresh_blk_counter = Reg(UInt(5.W))
    when(s2_thresh_valid){
        when(s3_thresh_blk_counter === 19.U){     // total 19 blks: tot_hor_blk * tot_ver_blk
            for(i <- 0 until 9){
                when(s2_thresh_bias_added(i) >= io.v_t){
                    s3_thresh_aeq_out_data(i) := Cat(1.U(1.W), s3_thresh_blk_counter, i.U(4.W), 1.U(1.W))
                }
            }
        }. otherwise{
            for(i <- 0 until 9){
                when(s2_thresh_bias_added(i) >= io.v_t){
                    s3_thresh_aeq_out_data(i) := Cat(0.U(1.W), s3_thresh_blk_counter, i.U(4.W), 1.U(1.W))
                }
            }
        }
        s3_thresh_blk_counter := s3_thresh_blk_counter + 1.U
        s3_thresh_valid := true.B
    }

    // stage - 4: update output aeq
    val s4_thresh_aeq_counter = Reg(UInt(5.W))
    when(s3_thresh_valid){
        io.wr_en_aeq_o := true.B

        for(i <- 0 until 9){
            when(s3_thresh_aeq_out_data(i)(0)){
                io.wr_addr_aeq_o := s4_thresh_aeq_counter
                io.wr_data_aeq_o := s3_thresh_aeq_out_data(i)
                s4_thresh_aeq_counter := s4_thresh_aeq_counter + 1.U
            }
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
