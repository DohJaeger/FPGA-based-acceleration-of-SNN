import chisel3._
import chisel3.util._
import java.io.File
import java.io.PrintWriter

class Top(T: Int, N: Int, mempot_width: Int, aeq_width: Int) extends Module {
    val io = IO(new Bundle {
        // Forward the tile IO for external communication
        // val tileIO = new tile(T, N, mempotWidth).io.cloneType
        val t_conv_en = Input(Bool())
        val t_thresh_en = Input(Bool())
        val t_kernel = Input(Vec(9, UInt(8.W)))
        val t_bias = Input(Vec(9, UInt(8.W)))
        val t_conv_done = Output(Bool())
        val t_thresh_done = Output(Bool())
    })

    val tile1 = Module(new tile(T, N, mempot_width))
    val tile2  = Module(new tile(T, N, mempot_width))

    // val L1_N_1 = Array.fill(3){Module(new mem(N/3, mempot_width))}
    val L1_S = Array.fill(3){Module(new mem(32, mempot_width))}
    val L2_N = Array.fill(3){Module(new mem(32, mempot_width))}
    // val L2_S_2 = Array.fill(3){Module(new mem(N/3, mempot_width))}
    val main_mem_1 = Array.fill(9){Module(new mem(32, mempot_width))}  // 9 blks for now
    val main_mem_2 = Array.fill(9){Module(new mem(32, mempot_width))}  // 9 blks for now
    val in_aeq_1 = (Module(new mem(256, aeq_width)))
    val out_aeq_1 = (Module(new mem(256, aeq_width)))
    val in_aeq_2 = (Module(new mem(256, aeq_width)))
    val out_aeq_2 = (Module(new mem(256, aeq_width)))

    //init
    tile1.io.stall := false.B
    tile2.io.stall := false.B

    tile1.io.conv_en := false.B
    tile1.io.bias := io.t_bias
    tile1.io.v_t := 1.U
    tile1.io.kernel := io.t_kernel
    tile1.io.rd_data_aeq_i := 0.U
    tile1.io.rd_data_main_mempot := VecInit(Seq.fill(9)(0.U(9.W)))
    tile1.io.rd_data_L2_N := VecInit(Seq.fill(3)(0.U(9.W)))
    tile1.io.rd_data_L2_S := VecInit(Seq.fill(3)(0.U(9.W)))

    tile2.io.conv_en := false.B
    tile2.io.bias := io.t_bias
    tile2.io.v_t := 1.U
    tile2.io.kernel := io.t_kernel
    tile2.io.rd_data_aeq_i := 0.U
    tile2.io.rd_data_main_mempot := VecInit(Seq.fill(9)(0.U(9.W)))
    tile2.io.rd_data_L2_N := VecInit(Seq.fill(3)(0.U(9.W)))
    tile2.io.rd_data_L2_S := VecInit(Seq.fill(3)(0.U(9.W)))

    // in_aeq_1
    in_aeq_1.io.rd_en := tile1.io.rd_en_aeq_i
    in_aeq_1.io.rd_addr := tile1.io.rd_addr_aeq_i
    tile1.io.rd_data_aeq_i := in_aeq_1.io.rd_data

    in_aeq_1.io.wr_data := DontCare
    in_aeq_1.io.wr_addr := DontCare
    in_aeq_1.io.wr_en := DontCare

    
    //out_aeq_1
    out_aeq_1.io.wr_en := tile1.io.wr_en_aeq_o
    out_aeq_1.io.wr_addr := tile1.io.wr_addr_aeq_o
    out_aeq_1.io.wr_data := tile1.io.wr_data_aeq_o

    out_aeq_1.io.rd_data := DontCare
    out_aeq_1.io.rd_addr := DontCare
    out_aeq_1.io.rd_en := DontCare

    // in_aeq_2
    in_aeq_2.io.rd_en := tile2.io.rd_en_aeq_i
    in_aeq_2.io.rd_addr := tile2.io.rd_addr_aeq_i
    tile2.io.rd_data_aeq_i := in_aeq_2.io.rd_data

    in_aeq_2.io.wr_data := DontCare
    in_aeq_2.io.wr_addr := DontCare
    in_aeq_2.io.wr_en := DontCare

    //out_aeq_2
    out_aeq_2.io.wr_en := tile2.io.wr_en_aeq_o
    out_aeq_2.io.wr_addr := tile2.io.wr_addr_aeq_o
    out_aeq_2.io.wr_data := tile2.io.wr_data_aeq_o

    out_aeq_2.io.rd_data := DontCare
    out_aeq_2.io.rd_addr := DontCare
    out_aeq_2.io.rd_en := DontCare

    for(i <- 0 until 9){
        main_mem_1(i).io.wr_en := tile1.io.wr_en_main_mempot(i)
        main_mem_1(i).io.wr_addr := tile1.io.wr_addr_main_mempot(i)
        main_mem_1(i).io.wr_data := tile1.io.wr_data_main_mempot(i)
        main_mem_1(i).io.rd_en := tile1.io.rd_en_main_mempot(i)
        main_mem_1(i).io.rd_addr := tile1.io.rd_addr_main_mempot(i)
        tile1.io.rd_data_main_mempot(i) := main_mem_1(i).io.rd_data

        main_mem_2(i).io.wr_en := tile2.io.wr_en_main_mempot(i)
        main_mem_2(i).io.wr_addr := tile2.io.wr_addr_main_mempot(i)
        main_mem_2(i).io.wr_data := tile2.io.wr_data_main_mempot(i)
        main_mem_2(i).io.rd_en := tile2.io.rd_en_main_mempot(i)
        main_mem_2(i).io.rd_addr := tile2.io.rd_addr_main_mempot(i)
        tile2.io.rd_data_main_mempot(i) := main_mem_2(i).io.rd_data
    }


    for(i <- 0 until 3){
        L2_N(i).io.wr_en := tile1.io.wr_en_L2_S(i)
        L2_N(i).io.wr_addr := tile1.io.wr_addr_L2_S(i)
        L2_N(i).io.wr_data := tile1.io.wr_data_L2_S(i)
        L1_S(i).io.rd_en := tile1.io.rd_en_L1_S
        L1_S(i).io.rd_addr := tile1.io.rd_addr_L1_S(i)
        tile1.io.rd_data_L1_S(i) := L1_S(i).io.rd_data

        L1_S(i).io.wr_en := tile2.io.wr_en_L2_N(i)
        L1_S(i).io.wr_addr := tile2.io.wr_addr_L2_N(i)
        L1_S(i).io.wr_data := tile2.io.wr_data_L2_N(i)
        L2_N(i).io.rd_en := tile2.io.rd_en_L1_N
        L2_N(i).io.rd_addr := tile2.io.rd_addr_L1_N(i)
        tile2.io.rd_data_L1_N(i) := L2_N(i).io.rd_data

        tile1.io.rd_data_L1_N(i) := DontCare
        tile2.io.rd_data_L1_S(i) := DontCare
        tile1.io.rd_data_L2_N(i) := DontCare
        tile2.io.rd_data_L2_S(i) := DontCare

    }

    when(io.t_conv_en && !io.t_thresh_en){
        tile1.io.conv_en := true.B
        tile2.io.conv_en := true.B
    }.otherwise{
        tile1.io.conv_en := false.B
        tile2.io.conv_en := false.B
    }

    when(io.t_thresh_en && !io.t_conv_en){
        tile1.io.thresh_en := true.B
        tile2.io.thresh_en := true.B
    }.otherwise{
        tile1.io.thresh_en := false.B
        tile2.io.thresh_en := false.B
    }

    io.t_thresh_done := tile1.io.thresh_done && tile2.io.thresh_done
    io.t_conv_done := tile1.io.conv_done && tile2.io.conv_done

}


object top extends App {
  val verilogString = chisel3.getVerilogString(new Top(6, 27, 9, 11))
  val verilogFile = new File("top.sv")
  val writer = new PrintWriter(verilogFile)
  writer.write(verilogString)
  writer.close()
}