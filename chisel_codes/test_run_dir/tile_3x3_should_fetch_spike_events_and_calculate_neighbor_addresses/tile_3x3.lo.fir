FIRRTL version 1.2.0
circuit tile_3x3 :
  module tile_3x3 : @[src/main/scala/tile_3x3.scala 16:7]
    input clock : Clock @[src/main/scala/tile_3x3.scala 16:7]
    input reset : UInt<1> @[src/main/scala/tile_3x3.scala 16:7]
    output io_rd_en_aeq_i_0 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_aeq_i_1 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_aeq_i_2 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_aeq_i_3 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_aeq_i_4 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_aeq_i_5 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_aeq_i_6 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_aeq_i_7 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_aeq_i_8 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_aeq_i_0 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_aeq_i_1 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_aeq_i_2 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_aeq_i_3 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_aeq_i_4 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_aeq_i_5 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_aeq_i_6 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_aeq_i_7 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_aeq_i_8 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_aeq_i_0 : UInt<12> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_aeq_i_1 : UInt<12> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_aeq_i_2 : UInt<12> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_aeq_i_3 : UInt<12> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_aeq_i_4 : UInt<12> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_aeq_i_5 : UInt<12> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_aeq_i_6 : UInt<12> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_aeq_i_7 : UInt<12> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_aeq_i_8 : UInt<12> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_aeq_i_valid_0 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_aeq_i_valid_1 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_aeq_i_valid_2 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_aeq_i_valid_3 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_aeq_i_valid_4 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_aeq_i_valid_5 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_aeq_i_valid_6 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_aeq_i_valid_7 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_aeq_i_valid_8 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_aeq_o_0 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_aeq_o_1 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_aeq_o_2 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_aeq_o_3 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_aeq_o_4 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_aeq_o_5 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_aeq_o_6 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_aeq_o_7 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_aeq_o_8 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_aeq_o_0 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_aeq_o_1 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_aeq_o_2 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_aeq_o_3 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_aeq_o_4 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_aeq_o_5 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_aeq_o_6 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_aeq_o_7 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_aeq_o_8 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_aeq_o_0 : UInt<12> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_aeq_o_1 : UInt<12> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_aeq_o_2 : UInt<12> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_aeq_o_3 : UInt<12> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_aeq_o_4 : UInt<12> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_aeq_o_5 : UInt<12> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_aeq_o_6 : UInt<12> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_aeq_o_7 : UInt<12> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_aeq_o_8 : UInt<12> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_main_mempot_0 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_main_mempot_1 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_main_mempot_2 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_main_mempot_3 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_main_mempot_4 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_main_mempot_5 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_main_mempot_6 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_main_mempot_7 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_main_mempot_8 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_main_mempot_0 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_main_mempot_1 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_main_mempot_2 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_main_mempot_3 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_main_mempot_4 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_main_mempot_5 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_main_mempot_6 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_main_mempot_7 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_main_mempot_8 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_main_mempot_0 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_main_mempot_1 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_main_mempot_2 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_main_mempot_3 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_main_mempot_4 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_main_mempot_5 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_main_mempot_6 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_main_mempot_7 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_main_mempot_8 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_main_mempot_0 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_main_mempot_1 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_main_mempot_2 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_main_mempot_3 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_main_mempot_4 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_main_mempot_5 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_main_mempot_6 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_main_mempot_7 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_main_mempot_8 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_main_mempot_0 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_main_mempot_1 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_main_mempot_2 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_main_mempot_3 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_main_mempot_4 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_main_mempot_5 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_main_mempot_6 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_main_mempot_7 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_main_mempot_8 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_main_mempot_0 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_main_mempot_1 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_main_mempot_2 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_main_mempot_3 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_main_mempot_4 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_main_mempot_5 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_main_mempot_6 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_main_mempot_7 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_main_mempot_8 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_main_mempot_valid_0 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_main_mempot_valid_1 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_main_mempot_valid_2 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_main_mempot_valid_3 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_main_mempot_valid_4 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_main_mempot_valid_5 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_main_mempot_valid_6 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_main_mempot_valid_7 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_main_mempot_valid_8 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_L2_N_0 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_L2_N_1 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_L2_N_2 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_L2_N_0 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_L2_N_1 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_L2_N_2 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_L2_N_0 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_L2_N_1 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_L2_N_2 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_L2_N_0 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_L2_N_1 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_L2_N_2 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_L2_N_0 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_L2_N_1 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_L2_N_2 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L2_N_0 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L2_N_1 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L2_N_2 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L2_N_valid_0 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L2_N_valid_1 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L2_N_valid_2 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_L2_S_0 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_L2_S_1 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_en_L2_S_2 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_L2_S_0 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_L2_S_1 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_addr_L2_S_2 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_L2_S_0 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_L2_S_1 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    output io_wr_data_L2_S_2 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_L2_S_0 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_L2_S_1 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_L2_S_2 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_L2_S_0 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_L2_S_1 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_L2_S_2 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L2_S_0 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L2_S_1 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L2_S_2 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L2_S_valid_0 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L2_S_valid_1 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L2_S_valid_2 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_L1_N_0 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_L1_N_1 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_L1_N_2 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_L1_N_0 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_L1_N_1 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_L1_N_2 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L1_N_0 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L1_N_1 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L1_N_2 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L1_N_valid_0 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L1_N_valid_1 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L1_N_valid_2 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_L1_S_0 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_L1_S_1 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_en_L1_S_2 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_L1_S_0 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_L1_S_1 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_rd_addr_L1_S_2 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L1_S_0 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L1_S_1 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L1_S_2 : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L1_S_valid_0 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L1_S_valid_1 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rd_data_L1_S_valid_2 : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_thresh_en : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_conv_en : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    input io_bias_0 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_bias_1 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_bias_2 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_bias_3 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_bias_4 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_bias_5 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_bias_6 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_bias_7 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_bias_8 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_v_t : UInt<16> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rotated_kernel_0 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rotated_kernel_1 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rotated_kernel_2 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rotated_kernel_3 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rotated_kernel_4 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rotated_kernel_5 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rotated_kernel_6 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rotated_kernel_7 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    input io_rotated_kernel_8 : UInt<8> @[src/main/scala/tile_3x3.scala 17:16]
    output io_conv_done : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]
    output io_thresh_done : UInt<1> @[src/main/scala/tile_3x3.scala 17:16]

    reg s1_addr_calc_0 : UInt<14>, clock with :
      reset => (UInt<1>("h0"), s1_addr_calc_0) @[src/main/scala/tile_3x3.scala 122:27]
    reg s1_addr_calc_1 : UInt<14>, clock with :
      reset => (UInt<1>("h0"), s1_addr_calc_1) @[src/main/scala/tile_3x3.scala 122:27]
    reg s1_addr_calc_2 : UInt<14>, clock with :
      reset => (UInt<1>("h0"), s1_addr_calc_2) @[src/main/scala/tile_3x3.scala 122:27]
    reg s1_addr_calc_3 : UInt<14>, clock with :
      reset => (UInt<1>("h0"), s1_addr_calc_3) @[src/main/scala/tile_3x3.scala 122:27]
    reg s1_addr_calc_4 : UInt<14>, clock with :
      reset => (UInt<1>("h0"), s1_addr_calc_4) @[src/main/scala/tile_3x3.scala 122:27]
    reg s1_addr_calc_5 : UInt<14>, clock with :
      reset => (UInt<1>("h0"), s1_addr_calc_5) @[src/main/scala/tile_3x3.scala 122:27]
    reg s1_addr_calc_6 : UInt<14>, clock with :
      reset => (UInt<1>("h0"), s1_addr_calc_6) @[src/main/scala/tile_3x3.scala 122:27]
    reg s1_addr_calc_7 : UInt<14>, clock with :
      reset => (UInt<1>("h0"), s1_addr_calc_7) @[src/main/scala/tile_3x3.scala 122:27]
    reg s1_addr_calc_8 : UInt<14>, clock with :
      reset => (UInt<1>("h0"), s1_addr_calc_8) @[src/main/scala/tile_3x3.scala 122:27]
    reg s2_mempot_rd_0 : UInt<9>, clock with :
      reset => (UInt<1>("h0"), s2_mempot_rd_0) @[src/main/scala/tile_3x3.scala 123:27]
    reg s2_mempot_rd_1 : UInt<9>, clock with :
      reset => (UInt<1>("h0"), s2_mempot_rd_1) @[src/main/scala/tile_3x3.scala 123:27]
    reg s2_mempot_rd_2 : UInt<9>, clock with :
      reset => (UInt<1>("h0"), s2_mempot_rd_2) @[src/main/scala/tile_3x3.scala 123:27]
    reg s2_mempot_rd_3 : UInt<9>, clock with :
      reset => (UInt<1>("h0"), s2_mempot_rd_3) @[src/main/scala/tile_3x3.scala 123:27]
    reg s2_mempot_rd_4 : UInt<9>, clock with :
      reset => (UInt<1>("h0"), s2_mempot_rd_4) @[src/main/scala/tile_3x3.scala 123:27]
    reg s2_mempot_rd_5 : UInt<9>, clock with :
      reset => (UInt<1>("h0"), s2_mempot_rd_5) @[src/main/scala/tile_3x3.scala 123:27]
    reg s2_mempot_rd_6 : UInt<9>, clock with :
      reset => (UInt<1>("h0"), s2_mempot_rd_6) @[src/main/scala/tile_3x3.scala 123:27]
    reg s2_mempot_rd_7 : UInt<9>, clock with :
      reset => (UInt<1>("h0"), s2_mempot_rd_7) @[src/main/scala/tile_3x3.scala 123:27]
    reg s2_mempot_rd_8 : UInt<9>, clock with :
      reset => (UInt<1>("h0"), s2_mempot_rd_8) @[src/main/scala/tile_3x3.scala 123:27]
    reg s3_conv_0 : UInt<9>, clock with :
      reset => (UInt<1>("h0"), s3_conv_0) @[src/main/scala/tile_3x3.scala 124:22]
    reg s3_conv_1 : UInt<9>, clock with :
      reset => (UInt<1>("h0"), s3_conv_1) @[src/main/scala/tile_3x3.scala 124:22]
    reg s3_conv_2 : UInt<9>, clock with :
      reset => (UInt<1>("h0"), s3_conv_2) @[src/main/scala/tile_3x3.scala 124:22]
    reg s3_conv_3 : UInt<9>, clock with :
      reset => (UInt<1>("h0"), s3_conv_3) @[src/main/scala/tile_3x3.scala 124:22]
    reg s3_conv_4 : UInt<9>, clock with :
      reset => (UInt<1>("h0"), s3_conv_4) @[src/main/scala/tile_3x3.scala 124:22]
    reg s3_conv_5 : UInt<9>, clock with :
      reset => (UInt<1>("h0"), s3_conv_5) @[src/main/scala/tile_3x3.scala 124:22]
    reg s3_conv_6 : UInt<9>, clock with :
      reset => (UInt<1>("h0"), s3_conv_6) @[src/main/scala/tile_3x3.scala 124:22]
    reg s3_conv_7 : UInt<9>, clock with :
      reset => (UInt<1>("h0"), s3_conv_7) @[src/main/scala/tile_3x3.scala 124:22]
    reg s3_conv_8 : UInt<9>, clock with :
      reset => (UInt<1>("h0"), s3_conv_8) @[src/main/scala/tile_3x3.scala 124:22]
    reg s1_valid : UInt<1>, clock with :
      reset => (UInt<1>("h0"), s1_valid) @[src/main/scala/tile_3x3.scala 126:27]
    reg s2_valid : UInt<1>, clock with :
      reset => (UInt<1>("h0"), s2_valid) @[src/main/scala/tile_3x3.scala 127:27]
    reg s3_valid : UInt<1>, clock with :
      reset => (UInt<1>("h0"), s3_valid) @[src/main/scala/tile_3x3.scala 128:27]
    reg s4_valid : UInt<1>, clock with :
      reset => (UInt<1>("h0"), s4_valid) @[src/main/scala/tile_3x3.scala 129:27]
    reg conv_done_reg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), conv_done_reg) @[src/main/scala/tile_3x3.scala 133:32]
    reg thresh_done_reg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), thresh_done_reg) @[src/main/scala/tile_3x3.scala 134:34]
    reg aeq_read_counter : UInt<8>, clock with :
      reset => (UInt<1>("h0"), aeq_read_counter) @[src/main/scala/tile_3x3.scala 143:35]
    reg aeq_read_col_sel_counter : UInt<4>, clock with :
      reset => (UInt<1>("h0"), aeq_read_col_sel_counter) @[src/main/scala/tile_3x3.scala 144:43]
    node _T = eq(UInt<1>("h0"), UInt<1>("h0")) @[src/main/scala/tile_3x3.scala 146:10]
    node _T_1 = and(_T, io_conv_en) @[src/main/scala/tile_3x3.scala 146:22]
    node _T_2 = eq(conv_done_reg, UInt<1>("h0")) @[src/main/scala/tile_3x3.scala 146:39]
    node _T_3 = and(_T_1, _T_2) @[src/main/scala/tile_3x3.scala 146:36]
    node _T_4 = add(UInt<4>("h9"), UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 148:65]
    node _T_5 = tail(_T_4, 1) @[src/main/scala/tile_3x3.scala 148:65]
    node _T_6 = eq(aeq_read_col_sel_counter, _T_5) @[src/main/scala/tile_3x3.scala 148:41]
    node _T_7 = eq(_T_6, UInt<1>("h0")) @[src/main/scala/tile_3x3.scala 148:14]
    node _io_rd_en_aeq_i_aeq_read_col_sel_counter = UInt<1>("h1") @[src/main/scala/tile_3x3.scala 149:{54,54}]
    node _GEN_0 = validif(eq(UInt<1>("h0"), aeq_read_col_sel_counter), _io_rd_en_aeq_i_aeq_read_col_sel_counter) @[src/main/scala/tile_3x3.scala 149:{54,54}]
    node _GEN_1 = validif(eq(UInt<1>("h1"), aeq_read_col_sel_counter), _io_rd_en_aeq_i_aeq_read_col_sel_counter) @[src/main/scala/tile_3x3.scala 149:{54,54}]
    node _GEN_2 = validif(eq(UInt<2>("h2"), aeq_read_col_sel_counter), _io_rd_en_aeq_i_aeq_read_col_sel_counter) @[src/main/scala/tile_3x3.scala 149:{54,54}]
    node _GEN_3 = validif(eq(UInt<2>("h3"), aeq_read_col_sel_counter), _io_rd_en_aeq_i_aeq_read_col_sel_counter) @[src/main/scala/tile_3x3.scala 149:{54,54}]
    node _GEN_4 = validif(eq(UInt<3>("h4"), aeq_read_col_sel_counter), _io_rd_en_aeq_i_aeq_read_col_sel_counter) @[src/main/scala/tile_3x3.scala 149:{54,54}]
    node _GEN_5 = validif(eq(UInt<3>("h5"), aeq_read_col_sel_counter), _io_rd_en_aeq_i_aeq_read_col_sel_counter) @[src/main/scala/tile_3x3.scala 149:{54,54}]
    node _GEN_6 = validif(eq(UInt<3>("h6"), aeq_read_col_sel_counter), _io_rd_en_aeq_i_aeq_read_col_sel_counter) @[src/main/scala/tile_3x3.scala 149:{54,54}]
    node _GEN_7 = validif(eq(UInt<3>("h7"), aeq_read_col_sel_counter), _io_rd_en_aeq_i_aeq_read_col_sel_counter) @[src/main/scala/tile_3x3.scala 149:{54,54}]
    node _GEN_8 = validif(eq(UInt<4>("h8"), aeq_read_col_sel_counter), _io_rd_en_aeq_i_aeq_read_col_sel_counter) @[src/main/scala/tile_3x3.scala 149:{54,54}]
    node _io_rd_addr_aeq_i_aeq_read_col_sel_counter = aeq_read_counter @[src/main/scala/tile_3x3.scala 150:{56,56}]
    node _GEN_9 = validif(eq(UInt<1>("h0"), aeq_read_col_sel_counter), _io_rd_addr_aeq_i_aeq_read_col_sel_counter) @[src/main/scala/tile_3x3.scala 150:{56,56}]
    node _GEN_10 = validif(eq(UInt<1>("h1"), aeq_read_col_sel_counter), _io_rd_addr_aeq_i_aeq_read_col_sel_counter) @[src/main/scala/tile_3x3.scala 150:{56,56}]
    node _GEN_11 = validif(eq(UInt<2>("h2"), aeq_read_col_sel_counter), _io_rd_addr_aeq_i_aeq_read_col_sel_counter) @[src/main/scala/tile_3x3.scala 150:{56,56}]
    node _GEN_12 = validif(eq(UInt<2>("h3"), aeq_read_col_sel_counter), _io_rd_addr_aeq_i_aeq_read_col_sel_counter) @[src/main/scala/tile_3x3.scala 150:{56,56}]
    node _GEN_13 = validif(eq(UInt<3>("h4"), aeq_read_col_sel_counter), _io_rd_addr_aeq_i_aeq_read_col_sel_counter) @[src/main/scala/tile_3x3.scala 150:{56,56}]
    node _GEN_14 = validif(eq(UInt<3>("h5"), aeq_read_col_sel_counter), _io_rd_addr_aeq_i_aeq_read_col_sel_counter) @[src/main/scala/tile_3x3.scala 150:{56,56}]
    node _GEN_15 = validif(eq(UInt<3>("h6"), aeq_read_col_sel_counter), _io_rd_addr_aeq_i_aeq_read_col_sel_counter) @[src/main/scala/tile_3x3.scala 150:{56,56}]
    node _GEN_16 = validif(eq(UInt<3>("h7"), aeq_read_col_sel_counter), _io_rd_addr_aeq_i_aeq_read_col_sel_counter) @[src/main/scala/tile_3x3.scala 150:{56,56}]
    node _GEN_17 = validif(eq(UInt<4>("h8"), aeq_read_col_sel_counter), _io_rd_addr_aeq_i_aeq_read_col_sel_counter) @[src/main/scala/tile_3x3.scala 150:{56,56}]
    node _GEN_18 = validif(eq(UInt<1>("h0"), aeq_read_col_sel_counter), io_rd_data_aeq_i_0) @[src/main/scala/tile_3x3.scala 153:{37,37}]
    node _GEN_19 = mux(eq(UInt<1>("h1"), aeq_read_col_sel_counter), io_rd_data_aeq_i_1, _GEN_18) @[src/main/scala/tile_3x3.scala 153:{37,37}]
    node _GEN_20 = mux(eq(UInt<2>("h2"), aeq_read_col_sel_counter), io_rd_data_aeq_i_2, _GEN_19) @[src/main/scala/tile_3x3.scala 153:{37,37}]
    node _GEN_21 = mux(eq(UInt<2>("h3"), aeq_read_col_sel_counter), io_rd_data_aeq_i_3, _GEN_20) @[src/main/scala/tile_3x3.scala 153:{37,37}]
    node _GEN_22 = mux(eq(UInt<3>("h4"), aeq_read_col_sel_counter), io_rd_data_aeq_i_4, _GEN_21) @[src/main/scala/tile_3x3.scala 153:{37,37}]
    node _GEN_23 = mux(eq(UInt<3>("h5"), aeq_read_col_sel_counter), io_rd_data_aeq_i_5, _GEN_22) @[src/main/scala/tile_3x3.scala 153:{37,37}]
    node _GEN_24 = mux(eq(UInt<3>("h6"), aeq_read_col_sel_counter), io_rd_data_aeq_i_6, _GEN_23) @[src/main/scala/tile_3x3.scala 153:{37,37}]
    node _GEN_25 = mux(eq(UInt<3>("h7"), aeq_read_col_sel_counter), io_rd_data_aeq_i_7, _GEN_24) @[src/main/scala/tile_3x3.scala 153:{37,37}]
    node _GEN_26 = mux(eq(UInt<4>("h8"), aeq_read_col_sel_counter), io_rd_data_aeq_i_8, _GEN_25) @[src/main/scala/tile_3x3.scala 153:{37,37}]
    node _io_rd_data_aeq_i_aeq_read_col_sel_counter = _GEN_26 @[src/main/scala/tile_3x3.scala 153:37]
    node blk_in = bits(_io_rd_data_aeq_i_aeq_read_col_sel_counter, 10, 1) @[src/main/scala/tile_3x3.scala 153:37]
    node _m_T = div(blk_in, UInt<3>("h6")) @[src/main/scala/tile_3x3.scala 155:39]
    node _m_T_1 = mul(UInt<2>("h3"), _m_T) @[src/main/scala/tile_3x3.scala 155:29]
    node _m_T_2 = rem(aeq_read_col_sel_counter, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 155:89]
    node _m_T_3 = add(_m_T_1, _m_T_2) @[src/main/scala/tile_3x3.scala 155:61]
    node m = tail(_m_T_3, 1) @[src/main/scala/tile_3x3.scala 155:61]
    node _n_T = rem(blk_in, UInt<3>("h6")) @[src/main/scala/tile_3x3.scala 156:39]
    node _n_T_1 = mul(UInt<2>("h3"), _n_T) @[src/main/scala/tile_3x3.scala 156:29]
    node _n_T_2 = div(aeq_read_col_sel_counter, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 156:89]
    node _n_T_3 = add(_n_T_1, _n_T_2) @[src/main/scala/tile_3x3.scala 156:61]
    node n = tail(_n_T_3, 1) @[src/main/scala/tile_3x3.scala 156:61]
    node _mk_T = sub(m, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 161:32]
    node _mk_T_1 = tail(_mk_T, 1) @[src/main/scala/tile_3x3.scala 161:32]
    node _mk_T_2 = add(_mk_T_1, UInt<1>("h0")) @[src/main/scala/tile_3x3.scala 161:37]
    node mk = tail(_mk_T_2, 1) @[src/main/scala/tile_3x3.scala 161:37]
    node _nl_T = sub(n, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 162:32]
    node _nl_T_1 = tail(_nl_T, 1) @[src/main/scala/tile_3x3.scala 162:32]
    node _nl_T_2 = add(_nl_T_1, UInt<1>("h0")) @[src/main/scala/tile_3x3.scala 162:38]
    node nl = tail(_nl_T_2, 1) @[src/main/scala/tile_3x3.scala 162:38]
    node _blk_out_T = div(mk, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 163:61]
    node _blk_out_T_1 = mul(UInt<3>("h6"), _blk_out_T) @[src/main/scala/tile_3x3.scala 163:55]
    node _blk_out_T_2 = div(nl, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 163:77]
    node _blk_out_T_3 = add(_blk_out_T_1, _blk_out_T_2) @[src/main/scala/tile_3x3.scala 163:72]
    node _blk_out_T_4 = tail(_blk_out_T_3, 1) @[src/main/scala/tile_3x3.scala 163:72]
    node blk_out = bits(_blk_out_T_4, 9, 0) @[src/main/scala/tile_3x3.scala 163:87]
    node _col_out_T = rem(mk, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:40]
    node _col_out_T_1 = mul(_col_out_T, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:51]
    node _col_out_T_2 = rem(nl, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:66]
    node _col_out_T_3 = add(_col_out_T_1, _col_out_T_2) @[src/main/scala/tile_3x3.scala 165:61]
    node _col_out_T_4 = tail(_col_out_T_3, 1) @[src/main/scala/tile_3x3.scala 165:61]
    node col_out = bits(_col_out_T_4, 3, 0) @[src/main/scala/tile_3x3.scala 165:76]
    node _s1_addr_calc_0_T = cat(blk_out, col_out) @[src/main/scala/tile_3x3.scala 166:55]
    node _mk_T_3 = sub(m, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 161:32]
    node _mk_T_4 = tail(_mk_T_3, 1) @[src/main/scala/tile_3x3.scala 161:32]
    node _mk_T_5 = add(_mk_T_4, UInt<1>("h0")) @[src/main/scala/tile_3x3.scala 161:37]
    node mk_1 = tail(_mk_T_5, 1) @[src/main/scala/tile_3x3.scala 161:37]
    node _nl_T_3 = sub(n, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 162:32]
    node _nl_T_4 = tail(_nl_T_3, 1) @[src/main/scala/tile_3x3.scala 162:32]
    node _nl_T_5 = add(_nl_T_4, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 162:38]
    node nl_1 = tail(_nl_T_5, 1) @[src/main/scala/tile_3x3.scala 162:38]
    node _blk_out_T_5 = div(mk_1, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 163:61]
    node _blk_out_T_6 = mul(UInt<3>("h6"), _blk_out_T_5) @[src/main/scala/tile_3x3.scala 163:55]
    node _blk_out_T_7 = div(nl_1, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 163:77]
    node _blk_out_T_8 = add(_blk_out_T_6, _blk_out_T_7) @[src/main/scala/tile_3x3.scala 163:72]
    node _blk_out_T_9 = tail(_blk_out_T_8, 1) @[src/main/scala/tile_3x3.scala 163:72]
    node blk_out_1 = bits(_blk_out_T_9, 9, 0) @[src/main/scala/tile_3x3.scala 163:87]
    node _col_out_T_5 = rem(mk_1, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:40]
    node _col_out_T_6 = mul(_col_out_T_5, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:51]
    node _col_out_T_7 = rem(nl_1, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:66]
    node _col_out_T_8 = add(_col_out_T_6, _col_out_T_7) @[src/main/scala/tile_3x3.scala 165:61]
    node _col_out_T_9 = tail(_col_out_T_8, 1) @[src/main/scala/tile_3x3.scala 165:61]
    node col_out_1 = bits(_col_out_T_9, 3, 0) @[src/main/scala/tile_3x3.scala 165:76]
    node _s1_addr_calc_1_T = cat(blk_out_1, col_out_1) @[src/main/scala/tile_3x3.scala 166:55]
    node _mk_T_6 = sub(m, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 161:32]
    node _mk_T_7 = tail(_mk_T_6, 1) @[src/main/scala/tile_3x3.scala 161:32]
    node _mk_T_8 = add(_mk_T_7, UInt<1>("h0")) @[src/main/scala/tile_3x3.scala 161:37]
    node mk_2 = tail(_mk_T_8, 1) @[src/main/scala/tile_3x3.scala 161:37]
    node _nl_T_6 = sub(n, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 162:32]
    node _nl_T_7 = tail(_nl_T_6, 1) @[src/main/scala/tile_3x3.scala 162:32]
    node _nl_T_8 = add(_nl_T_7, UInt<2>("h2")) @[src/main/scala/tile_3x3.scala 162:38]
    node nl_2 = tail(_nl_T_8, 1) @[src/main/scala/tile_3x3.scala 162:38]
    node _blk_out_T_10 = div(mk_2, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 163:61]
    node _blk_out_T_11 = mul(UInt<3>("h6"), _blk_out_T_10) @[src/main/scala/tile_3x3.scala 163:55]
    node _blk_out_T_12 = div(nl_2, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 163:77]
    node _blk_out_T_13 = add(_blk_out_T_11, _blk_out_T_12) @[src/main/scala/tile_3x3.scala 163:72]
    node _blk_out_T_14 = tail(_blk_out_T_13, 1) @[src/main/scala/tile_3x3.scala 163:72]
    node blk_out_2 = bits(_blk_out_T_14, 9, 0) @[src/main/scala/tile_3x3.scala 163:87]
    node _col_out_T_10 = rem(mk_2, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:40]
    node _col_out_T_11 = mul(_col_out_T_10, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:51]
    node _col_out_T_12 = rem(nl_2, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:66]
    node _col_out_T_13 = add(_col_out_T_11, _col_out_T_12) @[src/main/scala/tile_3x3.scala 165:61]
    node _col_out_T_14 = tail(_col_out_T_13, 1) @[src/main/scala/tile_3x3.scala 165:61]
    node col_out_2 = bits(_col_out_T_14, 3, 0) @[src/main/scala/tile_3x3.scala 165:76]
    node _s1_addr_calc_2_T = cat(blk_out_2, col_out_2) @[src/main/scala/tile_3x3.scala 166:55]
    node _mk_T_9 = sub(m, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 161:32]
    node _mk_T_10 = tail(_mk_T_9, 1) @[src/main/scala/tile_3x3.scala 161:32]
    node _mk_T_11 = add(_mk_T_10, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 161:37]
    node mk_3 = tail(_mk_T_11, 1) @[src/main/scala/tile_3x3.scala 161:37]
    node _nl_T_9 = sub(n, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 162:32]
    node _nl_T_10 = tail(_nl_T_9, 1) @[src/main/scala/tile_3x3.scala 162:32]
    node _nl_T_11 = add(_nl_T_10, UInt<1>("h0")) @[src/main/scala/tile_3x3.scala 162:38]
    node nl_3 = tail(_nl_T_11, 1) @[src/main/scala/tile_3x3.scala 162:38]
    node _blk_out_T_15 = div(mk_3, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 163:61]
    node _blk_out_T_16 = mul(UInt<3>("h6"), _blk_out_T_15) @[src/main/scala/tile_3x3.scala 163:55]
    node _blk_out_T_17 = div(nl_3, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 163:77]
    node _blk_out_T_18 = add(_blk_out_T_16, _blk_out_T_17) @[src/main/scala/tile_3x3.scala 163:72]
    node _blk_out_T_19 = tail(_blk_out_T_18, 1) @[src/main/scala/tile_3x3.scala 163:72]
    node blk_out_3 = bits(_blk_out_T_19, 9, 0) @[src/main/scala/tile_3x3.scala 163:87]
    node _col_out_T_15 = rem(mk_3, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:40]
    node _col_out_T_16 = mul(_col_out_T_15, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:51]
    node _col_out_T_17 = rem(nl_3, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:66]
    node _col_out_T_18 = add(_col_out_T_16, _col_out_T_17) @[src/main/scala/tile_3x3.scala 165:61]
    node _col_out_T_19 = tail(_col_out_T_18, 1) @[src/main/scala/tile_3x3.scala 165:61]
    node col_out_3 = bits(_col_out_T_19, 3, 0) @[src/main/scala/tile_3x3.scala 165:76]
    node _s1_addr_calc_3_T = cat(blk_out_3, col_out_3) @[src/main/scala/tile_3x3.scala 166:55]
    node _mk_T_12 = sub(m, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 161:32]
    node _mk_T_13 = tail(_mk_T_12, 1) @[src/main/scala/tile_3x3.scala 161:32]
    node _mk_T_14 = add(_mk_T_13, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 161:37]
    node mk_4 = tail(_mk_T_14, 1) @[src/main/scala/tile_3x3.scala 161:37]
    node _nl_T_12 = sub(n, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 162:32]
    node _nl_T_13 = tail(_nl_T_12, 1) @[src/main/scala/tile_3x3.scala 162:32]
    node _nl_T_14 = add(_nl_T_13, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 162:38]
    node nl_4 = tail(_nl_T_14, 1) @[src/main/scala/tile_3x3.scala 162:38]
    node _blk_out_T_20 = div(mk_4, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 163:61]
    node _blk_out_T_21 = mul(UInt<3>("h6"), _blk_out_T_20) @[src/main/scala/tile_3x3.scala 163:55]
    node _blk_out_T_22 = div(nl_4, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 163:77]
    node _blk_out_T_23 = add(_blk_out_T_21, _blk_out_T_22) @[src/main/scala/tile_3x3.scala 163:72]
    node _blk_out_T_24 = tail(_blk_out_T_23, 1) @[src/main/scala/tile_3x3.scala 163:72]
    node blk_out_4 = bits(_blk_out_T_24, 9, 0) @[src/main/scala/tile_3x3.scala 163:87]
    node _col_out_T_20 = rem(mk_4, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:40]
    node _col_out_T_21 = mul(_col_out_T_20, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:51]
    node _col_out_T_22 = rem(nl_4, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:66]
    node _col_out_T_23 = add(_col_out_T_21, _col_out_T_22) @[src/main/scala/tile_3x3.scala 165:61]
    node _col_out_T_24 = tail(_col_out_T_23, 1) @[src/main/scala/tile_3x3.scala 165:61]
    node col_out_4 = bits(_col_out_T_24, 3, 0) @[src/main/scala/tile_3x3.scala 165:76]
    node _s1_addr_calc_4_T = cat(blk_out_4, col_out_4) @[src/main/scala/tile_3x3.scala 166:55]
    node _mk_T_15 = sub(m, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 161:32]
    node _mk_T_16 = tail(_mk_T_15, 1) @[src/main/scala/tile_3x3.scala 161:32]
    node _mk_T_17 = add(_mk_T_16, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 161:37]
    node mk_5 = tail(_mk_T_17, 1) @[src/main/scala/tile_3x3.scala 161:37]
    node _nl_T_15 = sub(n, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 162:32]
    node _nl_T_16 = tail(_nl_T_15, 1) @[src/main/scala/tile_3x3.scala 162:32]
    node _nl_T_17 = add(_nl_T_16, UInt<2>("h2")) @[src/main/scala/tile_3x3.scala 162:38]
    node nl_5 = tail(_nl_T_17, 1) @[src/main/scala/tile_3x3.scala 162:38]
    node _blk_out_T_25 = div(mk_5, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 163:61]
    node _blk_out_T_26 = mul(UInt<3>("h6"), _blk_out_T_25) @[src/main/scala/tile_3x3.scala 163:55]
    node _blk_out_T_27 = div(nl_5, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 163:77]
    node _blk_out_T_28 = add(_blk_out_T_26, _blk_out_T_27) @[src/main/scala/tile_3x3.scala 163:72]
    node _blk_out_T_29 = tail(_blk_out_T_28, 1) @[src/main/scala/tile_3x3.scala 163:72]
    node blk_out_5 = bits(_blk_out_T_29, 9, 0) @[src/main/scala/tile_3x3.scala 163:87]
    node _col_out_T_25 = rem(mk_5, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:40]
    node _col_out_T_26 = mul(_col_out_T_25, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:51]
    node _col_out_T_27 = rem(nl_5, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:66]
    node _col_out_T_28 = add(_col_out_T_26, _col_out_T_27) @[src/main/scala/tile_3x3.scala 165:61]
    node _col_out_T_29 = tail(_col_out_T_28, 1) @[src/main/scala/tile_3x3.scala 165:61]
    node col_out_5 = bits(_col_out_T_29, 3, 0) @[src/main/scala/tile_3x3.scala 165:76]
    node _s1_addr_calc_5_T = cat(blk_out_5, col_out_5) @[src/main/scala/tile_3x3.scala 166:55]
    node _mk_T_18 = sub(m, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 161:32]
    node _mk_T_19 = tail(_mk_T_18, 1) @[src/main/scala/tile_3x3.scala 161:32]
    node _mk_T_20 = add(_mk_T_19, UInt<2>("h2")) @[src/main/scala/tile_3x3.scala 161:37]
    node mk_6 = tail(_mk_T_20, 1) @[src/main/scala/tile_3x3.scala 161:37]
    node _nl_T_18 = sub(n, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 162:32]
    node _nl_T_19 = tail(_nl_T_18, 1) @[src/main/scala/tile_3x3.scala 162:32]
    node _nl_T_20 = add(_nl_T_19, UInt<1>("h0")) @[src/main/scala/tile_3x3.scala 162:38]
    node nl_6 = tail(_nl_T_20, 1) @[src/main/scala/tile_3x3.scala 162:38]
    node _blk_out_T_30 = div(mk_6, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 163:61]
    node _blk_out_T_31 = mul(UInt<3>("h6"), _blk_out_T_30) @[src/main/scala/tile_3x3.scala 163:55]
    node _blk_out_T_32 = div(nl_6, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 163:77]
    node _blk_out_T_33 = add(_blk_out_T_31, _blk_out_T_32) @[src/main/scala/tile_3x3.scala 163:72]
    node _blk_out_T_34 = tail(_blk_out_T_33, 1) @[src/main/scala/tile_3x3.scala 163:72]
    node blk_out_6 = bits(_blk_out_T_34, 9, 0) @[src/main/scala/tile_3x3.scala 163:87]
    node _col_out_T_30 = rem(mk_6, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:40]
    node _col_out_T_31 = mul(_col_out_T_30, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:51]
    node _col_out_T_32 = rem(nl_6, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:66]
    node _col_out_T_33 = add(_col_out_T_31, _col_out_T_32) @[src/main/scala/tile_3x3.scala 165:61]
    node _col_out_T_34 = tail(_col_out_T_33, 1) @[src/main/scala/tile_3x3.scala 165:61]
    node col_out_6 = bits(_col_out_T_34, 3, 0) @[src/main/scala/tile_3x3.scala 165:76]
    node _s1_addr_calc_6_T = cat(blk_out_6, col_out_6) @[src/main/scala/tile_3x3.scala 166:55]
    node _mk_T_21 = sub(m, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 161:32]
    node _mk_T_22 = tail(_mk_T_21, 1) @[src/main/scala/tile_3x3.scala 161:32]
    node _mk_T_23 = add(_mk_T_22, UInt<2>("h2")) @[src/main/scala/tile_3x3.scala 161:37]
    node mk_7 = tail(_mk_T_23, 1) @[src/main/scala/tile_3x3.scala 161:37]
    node _nl_T_21 = sub(n, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 162:32]
    node _nl_T_22 = tail(_nl_T_21, 1) @[src/main/scala/tile_3x3.scala 162:32]
    node _nl_T_23 = add(_nl_T_22, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 162:38]
    node nl_7 = tail(_nl_T_23, 1) @[src/main/scala/tile_3x3.scala 162:38]
    node _blk_out_T_35 = div(mk_7, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 163:61]
    node _blk_out_T_36 = mul(UInt<3>("h6"), _blk_out_T_35) @[src/main/scala/tile_3x3.scala 163:55]
    node _blk_out_T_37 = div(nl_7, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 163:77]
    node _blk_out_T_38 = add(_blk_out_T_36, _blk_out_T_37) @[src/main/scala/tile_3x3.scala 163:72]
    node _blk_out_T_39 = tail(_blk_out_T_38, 1) @[src/main/scala/tile_3x3.scala 163:72]
    node blk_out_7 = bits(_blk_out_T_39, 9, 0) @[src/main/scala/tile_3x3.scala 163:87]
    node _col_out_T_35 = rem(mk_7, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:40]
    node _col_out_T_36 = mul(_col_out_T_35, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:51]
    node _col_out_T_37 = rem(nl_7, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:66]
    node _col_out_T_38 = add(_col_out_T_36, _col_out_T_37) @[src/main/scala/tile_3x3.scala 165:61]
    node _col_out_T_39 = tail(_col_out_T_38, 1) @[src/main/scala/tile_3x3.scala 165:61]
    node col_out_7 = bits(_col_out_T_39, 3, 0) @[src/main/scala/tile_3x3.scala 165:76]
    node _s1_addr_calc_7_T = cat(blk_out_7, col_out_7) @[src/main/scala/tile_3x3.scala 166:55]
    node _mk_T_24 = sub(m, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 161:32]
    node _mk_T_25 = tail(_mk_T_24, 1) @[src/main/scala/tile_3x3.scala 161:32]
    node _mk_T_26 = add(_mk_T_25, UInt<2>("h2")) @[src/main/scala/tile_3x3.scala 161:37]
    node mk_8 = tail(_mk_T_26, 1) @[src/main/scala/tile_3x3.scala 161:37]
    node _nl_T_24 = sub(n, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 162:32]
    node _nl_T_25 = tail(_nl_T_24, 1) @[src/main/scala/tile_3x3.scala 162:32]
    node _nl_T_26 = add(_nl_T_25, UInt<2>("h2")) @[src/main/scala/tile_3x3.scala 162:38]
    node nl_8 = tail(_nl_T_26, 1) @[src/main/scala/tile_3x3.scala 162:38]
    node _blk_out_T_40 = div(mk_8, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 163:61]
    node _blk_out_T_41 = mul(UInt<3>("h6"), _blk_out_T_40) @[src/main/scala/tile_3x3.scala 163:55]
    node _blk_out_T_42 = div(nl_8, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 163:77]
    node _blk_out_T_43 = add(_blk_out_T_41, _blk_out_T_42) @[src/main/scala/tile_3x3.scala 163:72]
    node _blk_out_T_44 = tail(_blk_out_T_43, 1) @[src/main/scala/tile_3x3.scala 163:72]
    node blk_out_8 = bits(_blk_out_T_44, 9, 0) @[src/main/scala/tile_3x3.scala 163:87]
    node _col_out_T_40 = rem(mk_8, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:40]
    node _col_out_T_41 = mul(_col_out_T_40, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:51]
    node _col_out_T_42 = rem(nl_8, UInt<2>("h3")) @[src/main/scala/tile_3x3.scala 165:66]
    node _col_out_T_43 = add(_col_out_T_41, _col_out_T_42) @[src/main/scala/tile_3x3.scala 165:61]
    node _col_out_T_44 = tail(_col_out_T_43, 1) @[src/main/scala/tile_3x3.scala 165:61]
    node col_out_8 = bits(_col_out_T_44, 3, 0) @[src/main/scala/tile_3x3.scala 165:76]
    node _s1_addr_calc_8_T = cat(blk_out_8, col_out_8) @[src/main/scala/tile_3x3.scala 166:55]
    node _aeq_read_counter_T = add(aeq_read_counter, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 172:50]
    node _aeq_read_counter_T_1 = tail(_aeq_read_counter_T, 1) @[src/main/scala/tile_3x3.scala 172:50]
    node _io_rd_data_aeq_i_aeq_read_col_sel_counter_0 = _GEN_26 @[src/main/scala/tile_3x3.scala 173:29]
    node _T_8 = bits(_io_rd_data_aeq_i_aeq_read_col_sel_counter_0, 11, 11) @[src/main/scala/tile_3x3.scala 173:29]
    node _io_rd_data_aeq_i_aeq_read_col_sel_counter_1 = _GEN_26 @[src/main/scala/tile_3x3.scala 173:61]
    node _T_9 = bits(_io_rd_data_aeq_i_aeq_read_col_sel_counter_1, 0, 0) @[src/main/scala/tile_3x3.scala 173:61]
    node _T_10 = eq(_T_9, UInt<1>("h0")) @[src/main/scala/tile_3x3.scala 173:49]
    node _T_11 = or(_T_8, _T_10) @[src/main/scala/tile_3x3.scala 173:46]
    node _aeq_read_col_sel_counter_T = add(aeq_read_col_sel_counter, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 175:70]
    node _aeq_read_col_sel_counter_T_1 = tail(_aeq_read_col_sel_counter_T, 1) @[src/main/scala/tile_3x3.scala 175:70]
    node _GEN_27 = mux(_T_11, UInt<1>("h0"), _aeq_read_counter_T_1) @[src/main/scala/tile_3x3.scala 172:30 173:66 174:34]
    node _GEN_28 = mux(_T_11, _aeq_read_col_sel_counter_T_1, aeq_read_col_sel_counter) @[src/main/scala/tile_3x3.scala 173:66 175:42 144:43]
    node _T_12 = add(UInt<4>("h9"), UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 178:67]
    node _T_13 = tail(_T_12, 1) @[src/main/scala/tile_3x3.scala 178:67]
    node _T_14 = eq(aeq_read_col_sel_counter, _T_13) @[src/main/scala/tile_3x3.scala 178:43]
    node _GEN_29 = mux(_T_14, UInt<1>("h0"), UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 170:22 178:73 179:26]
    node _GEN_30 = validif(_T_7, _GEN_0) @[src/main/scala/tile_3x3.scala 148:72]
    node _GEN_31 = validif(_T_7, _GEN_1) @[src/main/scala/tile_3x3.scala 148:72]
    node _GEN_32 = validif(_T_7, _GEN_2) @[src/main/scala/tile_3x3.scala 148:72]
    node _GEN_33 = validif(_T_7, _GEN_3) @[src/main/scala/tile_3x3.scala 148:72]
    node _GEN_34 = validif(_T_7, _GEN_4) @[src/main/scala/tile_3x3.scala 148:72]
    node _GEN_35 = validif(_T_7, _GEN_5) @[src/main/scala/tile_3x3.scala 148:72]
    node _GEN_36 = validif(_T_7, _GEN_6) @[src/main/scala/tile_3x3.scala 148:72]
    node _GEN_37 = validif(_T_7, _GEN_7) @[src/main/scala/tile_3x3.scala 148:72]
    node _GEN_38 = validif(_T_7, _GEN_8) @[src/main/scala/tile_3x3.scala 148:72]
    node _GEN_39 = validif(_T_7, _GEN_9) @[src/main/scala/tile_3x3.scala 148:72]
    node _GEN_40 = validif(_T_7, _GEN_10) @[src/main/scala/tile_3x3.scala 148:72]
    node _GEN_41 = validif(_T_7, _GEN_11) @[src/main/scala/tile_3x3.scala 148:72]
    node _GEN_42 = validif(_T_7, _GEN_12) @[src/main/scala/tile_3x3.scala 148:72]
    node _GEN_43 = validif(_T_7, _GEN_13) @[src/main/scala/tile_3x3.scala 148:72]
    node _GEN_44 = validif(_T_7, _GEN_14) @[src/main/scala/tile_3x3.scala 148:72]
    node _GEN_45 = validif(_T_7, _GEN_15) @[src/main/scala/tile_3x3.scala 148:72]
    node _GEN_46 = validif(_T_7, _GEN_16) @[src/main/scala/tile_3x3.scala 148:72]
    node _GEN_47 = validif(_T_7, _GEN_17) @[src/main/scala/tile_3x3.scala 148:72]
    node _GEN_48 = mux(_T_7, _s1_addr_calc_0_T, s1_addr_calc_0) @[src/main/scala/tile_3x3.scala 122:27 148:72 166:49]
    node _GEN_49 = mux(_T_7, _s1_addr_calc_1_T, s1_addr_calc_1) @[src/main/scala/tile_3x3.scala 122:27 148:72 166:49]
    node _GEN_50 = mux(_T_7, _s1_addr_calc_2_T, s1_addr_calc_2) @[src/main/scala/tile_3x3.scala 122:27 148:72 166:49]
    node _GEN_51 = mux(_T_7, _s1_addr_calc_3_T, s1_addr_calc_3) @[src/main/scala/tile_3x3.scala 122:27 148:72 166:49]
    node _GEN_52 = mux(_T_7, _s1_addr_calc_4_T, s1_addr_calc_4) @[src/main/scala/tile_3x3.scala 122:27 148:72 166:49]
    node _GEN_53 = mux(_T_7, _s1_addr_calc_5_T, s1_addr_calc_5) @[src/main/scala/tile_3x3.scala 122:27 148:72 166:49]
    node _GEN_54 = mux(_T_7, _s1_addr_calc_6_T, s1_addr_calc_6) @[src/main/scala/tile_3x3.scala 122:27 148:72 166:49]
    node _GEN_55 = mux(_T_7, _s1_addr_calc_7_T, s1_addr_calc_7) @[src/main/scala/tile_3x3.scala 122:27 148:72 166:49]
    node _GEN_56 = mux(_T_7, _s1_addr_calc_8_T, s1_addr_calc_8) @[src/main/scala/tile_3x3.scala 122:27 148:72 166:49]
    node _GEN_57 = mux(_T_7, _GEN_29, s1_valid) @[src/main/scala/tile_3x3.scala 126:27 148:72]
    node _GEN_58 = mux(_T_7, _GEN_27, aeq_read_counter) @[src/main/scala/tile_3x3.scala 143:35 148:72]
    node _GEN_59 = mux(_T_7, _GEN_28, aeq_read_col_sel_counter) @[src/main/scala/tile_3x3.scala 144:43 148:72]
    node _GEN_60 = validif(_T_3, _GEN_30) @[src/main/scala/tile_3x3.scala 146:55]
    node _GEN_61 = validif(_T_3, _GEN_31) @[src/main/scala/tile_3x3.scala 146:55]
    node _GEN_62 = validif(_T_3, _GEN_32) @[src/main/scala/tile_3x3.scala 146:55]
    node _GEN_63 = validif(_T_3, _GEN_33) @[src/main/scala/tile_3x3.scala 146:55]
    node _GEN_64 = validif(_T_3, _GEN_34) @[src/main/scala/tile_3x3.scala 146:55]
    node _GEN_65 = validif(_T_3, _GEN_35) @[src/main/scala/tile_3x3.scala 146:55]
    node _GEN_66 = validif(_T_3, _GEN_36) @[src/main/scala/tile_3x3.scala 146:55]
    node _GEN_67 = validif(_T_3, _GEN_37) @[src/main/scala/tile_3x3.scala 146:55]
    node _GEN_68 = validif(_T_3, _GEN_38) @[src/main/scala/tile_3x3.scala 146:55]
    node _GEN_69 = validif(_T_3, _GEN_39) @[src/main/scala/tile_3x3.scala 146:55]
    node _GEN_70 = validif(_T_3, _GEN_40) @[src/main/scala/tile_3x3.scala 146:55]
    node _GEN_71 = validif(_T_3, _GEN_41) @[src/main/scala/tile_3x3.scala 146:55]
    node _GEN_72 = validif(_T_3, _GEN_42) @[src/main/scala/tile_3x3.scala 146:55]
    node _GEN_73 = validif(_T_3, _GEN_43) @[src/main/scala/tile_3x3.scala 146:55]
    node _GEN_74 = validif(_T_3, _GEN_44) @[src/main/scala/tile_3x3.scala 146:55]
    node _GEN_75 = validif(_T_3, _GEN_45) @[src/main/scala/tile_3x3.scala 146:55]
    node _GEN_76 = validif(_T_3, _GEN_46) @[src/main/scala/tile_3x3.scala 146:55]
    node _GEN_77 = validif(_T_3, _GEN_47) @[src/main/scala/tile_3x3.scala 146:55]
    node _GEN_78 = mux(_T_3, _GEN_48, s1_addr_calc_0) @[src/main/scala/tile_3x3.scala 122:27 146:55]
    node _GEN_79 = mux(_T_3, _GEN_49, s1_addr_calc_1) @[src/main/scala/tile_3x3.scala 122:27 146:55]
    node _GEN_80 = mux(_T_3, _GEN_50, s1_addr_calc_2) @[src/main/scala/tile_3x3.scala 122:27 146:55]
    node _GEN_81 = mux(_T_3, _GEN_51, s1_addr_calc_3) @[src/main/scala/tile_3x3.scala 122:27 146:55]
    node _GEN_82 = mux(_T_3, _GEN_52, s1_addr_calc_4) @[src/main/scala/tile_3x3.scala 122:27 146:55]
    node _GEN_83 = mux(_T_3, _GEN_53, s1_addr_calc_5) @[src/main/scala/tile_3x3.scala 122:27 146:55]
    node _GEN_84 = mux(_T_3, _GEN_54, s1_addr_calc_6) @[src/main/scala/tile_3x3.scala 122:27 146:55]
    node _GEN_85 = mux(_T_3, _GEN_55, s1_addr_calc_7) @[src/main/scala/tile_3x3.scala 122:27 146:55]
    node _GEN_86 = mux(_T_3, _GEN_56, s1_addr_calc_8) @[src/main/scala/tile_3x3.scala 122:27 146:55]
    node _GEN_87 = mux(_T_3, _GEN_57, s1_valid) @[src/main/scala/tile_3x3.scala 126:27 146:55]
    node _GEN_88 = mux(_T_3, _GEN_58, aeq_read_counter) @[src/main/scala/tile_3x3.scala 143:35 146:55]
    node _GEN_89 = mux(_T_3, _GEN_59, aeq_read_col_sel_counter) @[src/main/scala/tile_3x3.scala 144:43 146:55]
    node _T_15 = eq(UInt<1>("h0"), UInt<1>("h0")) @[src/main/scala/tile_3x3.scala 186:22]
    node _T_16 = and(s1_valid, _T_15) @[src/main/scala/tile_3x3.scala 186:19]
    node _T_17 = and(_T_16, io_conv_en) @[src/main/scala/tile_3x3.scala 186:34]
    node _T_18 = bits(s1_addr_calc_6, 8, 4) @[src/main/scala/tile_3x3.scala 188:32]
    node _T_19 = geq(_T_18, UInt<4>("h9")) @[src/main/scala/tile_3x3.scala 188:38]
    node _T_20 = bits(s1_addr_calc_6, 3, 0) @[src/main/scala/tile_3x3.scala 188:72]
    node _T_21 = geq(_T_20, UInt<4>("h6")) @[src/main/scala/tile_3x3.scala 188:78]
    node _T_22 = and(_T_19, _T_21) @[src/main/scala/tile_3x3.scala 188:51]
    node _T_23 = bits(s1_addr_calc_0, 8, 4) @[src/main/scala/tile_3x3.scala 207:40]
    node _T_24 = lt(_T_23, UInt<4>("h9")) @[src/main/scala/tile_3x3.scala 207:46]
    node _T_25 = bits(s1_addr_calc_0, 3, 0) @[src/main/scala/tile_3x3.scala 207:78]
    node _T_26 = lt(_T_25, UInt<4>("h3")) @[src/main/scala/tile_3x3.scala 207:85]
    node _T_27 = and(_T_24, _T_26) @[src/main/scala/tile_3x3.scala 207:58]
    node _GEN_90 = validif(_T_27, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 207:98 209:30]
    node _GEN_91 = validif(_T_27, s1_addr_calc_0) @[src/main/scala/tile_3x3.scala 207:98 210:32]
    node _GEN_92 = mux(_T_27, io_rd_data_L2_N_0, io_rd_data_main_mempot_0) @[src/main/scala/tile_3x3.scala 207:98 211:29 231:33]
    node _GEN_93 = validif(_T_27, s1_addr_calc_1) @[src/main/scala/tile_3x3.scala 207:98 214:32]
    node _GEN_94 = mux(_T_27, io_rd_data_L2_N_1, io_rd_data_main_mempot_1) @[src/main/scala/tile_3x3.scala 207:98 215:29 231:33]
    node _GEN_95 = validif(_T_27, s1_addr_calc_2) @[src/main/scala/tile_3x3.scala 207:98 218:32]
    node _GEN_96 = mux(_T_27, io_rd_data_L2_N_2, io_rd_data_main_mempot_2) @[src/main/scala/tile_3x3.scala 207:98 219:29 231:33]
    node _GEN_97 = mux(_T_27, UInt<1>("h1"), UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 207:98 222:41 229:41]
    node _GEN_98 = mux(_T_27, s1_addr_calc_3, s1_addr_calc_3) @[src/main/scala/tile_3x3.scala 207:98 223:43 230:43]
    node _GEN_99 = mux(_T_27, io_rd_data_main_mempot_3, io_rd_data_main_mempot_3) @[src/main/scala/tile_3x3.scala 207:98 224:33 231:33]
    node _GEN_100 = mux(_T_27, s1_addr_calc_4, s1_addr_calc_4) @[src/main/scala/tile_3x3.scala 207:98 223:43 230:43]
    node _GEN_101 = mux(_T_27, io_rd_data_main_mempot_4, io_rd_data_main_mempot_4) @[src/main/scala/tile_3x3.scala 207:98 224:33 231:33]
    node _GEN_102 = mux(_T_27, s1_addr_calc_5, s1_addr_calc_5) @[src/main/scala/tile_3x3.scala 207:98 223:43 230:43]
    node _GEN_103 = mux(_T_27, io_rd_data_main_mempot_5, io_rd_data_main_mempot_5) @[src/main/scala/tile_3x3.scala 207:98 224:33 231:33]
    node _GEN_104 = mux(_T_27, s1_addr_calc_6, s1_addr_calc_6) @[src/main/scala/tile_3x3.scala 207:98 223:43 230:43]
    node _GEN_105 = mux(_T_27, io_rd_data_main_mempot_6, io_rd_data_main_mempot_6) @[src/main/scala/tile_3x3.scala 207:98 224:33 231:33]
    node _GEN_106 = mux(_T_27, s1_addr_calc_7, s1_addr_calc_7) @[src/main/scala/tile_3x3.scala 207:98 223:43 230:43]
    node _GEN_107 = mux(_T_27, io_rd_data_main_mempot_7, io_rd_data_main_mempot_7) @[src/main/scala/tile_3x3.scala 207:98 224:33 231:33]
    node _GEN_108 = mux(_T_27, s1_addr_calc_8, s1_addr_calc_8) @[src/main/scala/tile_3x3.scala 207:98 223:43 230:43]
    node _GEN_109 = mux(_T_27, io_rd_data_main_mempot_8, io_rd_data_main_mempot_8) @[src/main/scala/tile_3x3.scala 207:98 224:33 231:33]
    node _GEN_110 = validif(eq(_T_27, UInt<1>("h0")), UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 207:98 229:41]
    node _GEN_111 = validif(eq(_T_27, UInt<1>("h0")), s1_addr_calc_0) @[src/main/scala/tile_3x3.scala 207:98 230:43]
    node _GEN_112 = validif(eq(_T_27, UInt<1>("h0")), s1_addr_calc_1) @[src/main/scala/tile_3x3.scala 207:98 230:43]
    node _GEN_113 = validif(eq(_T_27, UInt<1>("h0")), s1_addr_calc_2) @[src/main/scala/tile_3x3.scala 207:98 230:43]
    node _GEN_114 = mux(_T_22, UInt<1>("h1"), _GEN_110) @[src/main/scala/tile_3x3.scala 188:92 191:41]
    node _GEN_115 = mux(_T_22, s1_addr_calc_0, _GEN_111) @[src/main/scala/tile_3x3.scala 188:92 192:43]
    node _GEN_116 = mux(_T_22, io_rd_data_main_mempot_0, _GEN_92) @[src/main/scala/tile_3x3.scala 188:92 193:33]
    node _GEN_117 = mux(_T_22, s1_addr_calc_1, _GEN_112) @[src/main/scala/tile_3x3.scala 188:92 192:43]
    node _GEN_118 = mux(_T_22, io_rd_data_main_mempot_1, _GEN_94) @[src/main/scala/tile_3x3.scala 188:92 193:33]
    node _GEN_119 = mux(_T_22, s1_addr_calc_2, _GEN_113) @[src/main/scala/tile_3x3.scala 188:92 192:43]
    node _GEN_120 = mux(_T_22, io_rd_data_main_mempot_2, _GEN_96) @[src/main/scala/tile_3x3.scala 188:92 193:33]
    node _GEN_121 = mux(_T_22, UInt<1>("h1"), _GEN_97) @[src/main/scala/tile_3x3.scala 188:92 191:41]
    node _GEN_122 = mux(_T_22, s1_addr_calc_3, _GEN_98) @[src/main/scala/tile_3x3.scala 188:92 192:43]
    node _GEN_123 = mux(_T_22, io_rd_data_main_mempot_3, _GEN_99) @[src/main/scala/tile_3x3.scala 188:92 193:33]
    node _GEN_124 = mux(_T_22, s1_addr_calc_4, _GEN_100) @[src/main/scala/tile_3x3.scala 188:92 192:43]
    node _GEN_125 = mux(_T_22, io_rd_data_main_mempot_4, _GEN_101) @[src/main/scala/tile_3x3.scala 188:92 193:33]
    node _GEN_126 = mux(_T_22, s1_addr_calc_5, _GEN_102) @[src/main/scala/tile_3x3.scala 188:92 192:43]
    node _GEN_127 = mux(_T_22, io_rd_data_main_mempot_5, _GEN_103) @[src/main/scala/tile_3x3.scala 188:92 193:33]
    node _GEN_128 = validif(_T_22, UInt<1>("h1")) @[src/main/scala/tile_3x3.scala 188:92 195:30]
    node _GEN_129 = validif(_T_22, s1_addr_calc_6) @[src/main/scala/tile_3x3.scala 188:92 196:32]
    node _GEN_130 = mux(_T_22, io_rd_data_L2_S_0, _GEN_105) @[src/main/scala/tile_3x3.scala 188:92 197:29]
    node _GEN_131 = validif(_T_22, s1_addr_calc_7) @[src/main/scala/tile_3x3.scala 188:92 200:32]
    node _GEN_132 = mux(_T_22, io_rd_data_L2_S_1, _GEN_107) @[src/main/scala/tile_3x3.scala 188:92 201:29]
    node _GEN_133 = validif(_T_22, s1_addr_calc_8) @[src/main/scala/tile_3x3.scala 188:92 204:32]
    node _GEN_134 = mux(_T_22, io_rd_data_L2_S_2, _GEN_109) @[src/main/scala/tile_3x3.scala 188:92 205:29]
    node _GEN_135 = validif(eq(_T_22, UInt<1>("h0")), _GEN_90) @[src/main/scala/tile_3x3.scala 188:92]
    node _GEN_136 = validif(eq(_T_22, UInt<1>("h0")), _GEN_91) @[src/main/scala/tile_3x3.scala 188:92]
    node _GEN_137 = validif(eq(_T_22, UInt<1>("h0")), _GEN_93) @[src/main/scala/tile_3x3.scala 188:92]
    node _GEN_138 = validif(eq(_T_22, UInt<1>("h0")), _GEN_95) @[src/main/scala/tile_3x3.scala 188:92]
    node _GEN_139 = validif(eq(_T_22, UInt<1>("h0")), _GEN_97) @[src/main/scala/tile_3x3.scala 188:92]
    node _GEN_140 = validif(eq(_T_22, UInt<1>("h0")), _GEN_104) @[src/main/scala/tile_3x3.scala 188:92]
    node _GEN_141 = validif(eq(_T_22, UInt<1>("h0")), _GEN_106) @[src/main/scala/tile_3x3.scala 188:92]
    node _GEN_142 = validif(eq(_T_22, UInt<1>("h0")), _GEN_108) @[src/main/scala/tile_3x3.scala 188:92]
    node _GEN_143 = mux(_T_17, UInt<1>("h1"), s2_valid) @[src/main/scala/tile_3x3.scala 186:48 234:18 127:27]
    node _GEN_144 = validif(_T_17, _GEN_114) @[src/main/scala/tile_3x3.scala 186:48]
    node _GEN_145 = validif(_T_17, _GEN_115) @[src/main/scala/tile_3x3.scala 186:48]
    node _GEN_146 = mux(_T_17, _GEN_116, s2_mempot_rd_0) @[src/main/scala/tile_3x3.scala 123:27 186:48]
    node _GEN_147 = validif(_T_17, _GEN_117) @[src/main/scala/tile_3x3.scala 186:48]
    node _GEN_148 = mux(_T_17, _GEN_118, s2_mempot_rd_1) @[src/main/scala/tile_3x3.scala 123:27 186:48]
    node _GEN_149 = validif(_T_17, _GEN_119) @[src/main/scala/tile_3x3.scala 186:48]
    node _GEN_150 = mux(_T_17, _GEN_120, s2_mempot_rd_2) @[src/main/scala/tile_3x3.scala 123:27 186:48]
    node _GEN_151 = validif(_T_17, _GEN_121) @[src/main/scala/tile_3x3.scala 186:48]
    node _GEN_152 = validif(_T_17, _GEN_122) @[src/main/scala/tile_3x3.scala 186:48]
    node _GEN_153 = mux(_T_17, _GEN_123, s2_mempot_rd_3) @[src/main/scala/tile_3x3.scala 123:27 186:48]
    node _GEN_154 = validif(_T_17, _GEN_124) @[src/main/scala/tile_3x3.scala 186:48]
    node _GEN_155 = mux(_T_17, _GEN_125, s2_mempot_rd_4) @[src/main/scala/tile_3x3.scala 123:27 186:48]
    node _GEN_156 = validif(_T_17, _GEN_126) @[src/main/scala/tile_3x3.scala 186:48]
    node _GEN_157 = mux(_T_17, _GEN_127, s2_mempot_rd_5) @[src/main/scala/tile_3x3.scala 123:27 186:48]
    node _GEN_158 = validif(_T_17, _GEN_128) @[src/main/scala/tile_3x3.scala 186:48]
    node _GEN_159 = validif(_T_17, _GEN_129) @[src/main/scala/tile_3x3.scala 186:48]
    node _GEN_160 = mux(_T_17, _GEN_130, s2_mempot_rd_6) @[src/main/scala/tile_3x3.scala 123:27 186:48]
    node _GEN_161 = validif(_T_17, _GEN_131) @[src/main/scala/tile_3x3.scala 186:48]
    node _GEN_162 = mux(_T_17, _GEN_132, s2_mempot_rd_7) @[src/main/scala/tile_3x3.scala 123:27 186:48]
    node _GEN_163 = validif(_T_17, _GEN_133) @[src/main/scala/tile_3x3.scala 186:48]
    node _GEN_164 = mux(_T_17, _GEN_134, s2_mempot_rd_8) @[src/main/scala/tile_3x3.scala 123:27 186:48]
    node _GEN_165 = validif(_T_17, _GEN_135) @[src/main/scala/tile_3x3.scala 186:48]
    node _GEN_166 = validif(_T_17, _GEN_136) @[src/main/scala/tile_3x3.scala 186:48]
    node _GEN_167 = validif(_T_17, _GEN_137) @[src/main/scala/tile_3x3.scala 186:48]
    node _GEN_168 = validif(_T_17, _GEN_138) @[src/main/scala/tile_3x3.scala 186:48]
    node _GEN_169 = validif(_T_17, _GEN_139) @[src/main/scala/tile_3x3.scala 186:48]
    node _GEN_170 = validif(_T_17, _GEN_140) @[src/main/scala/tile_3x3.scala 186:48]
    node _GEN_171 = validif(_T_17, _GEN_141) @[src/main/scala/tile_3x3.scala 186:48]
    node _GEN_172 = validif(_T_17, _GEN_142) @[src/main/scala/tile_3x3.scala 186:48]
    io_rd_en_aeq_i_0 <= _GEN_60
    io_rd_en_aeq_i_1 <= _GEN_61
    io_rd_en_aeq_i_2 <= _GEN_62
    io_rd_en_aeq_i_3 <= _GEN_63
    io_rd_en_aeq_i_4 <= _GEN_64
    io_rd_en_aeq_i_5 <= _GEN_65
    io_rd_en_aeq_i_6 <= _GEN_66
    io_rd_en_aeq_i_7 <= _GEN_67
    io_rd_en_aeq_i_8 <= _GEN_68
    io_rd_addr_aeq_i_0 <= _GEN_69
    io_rd_addr_aeq_i_1 <= _GEN_70
    io_rd_addr_aeq_i_2 <= _GEN_71
    io_rd_addr_aeq_i_3 <= _GEN_72
    io_rd_addr_aeq_i_4 <= _GEN_73
    io_rd_addr_aeq_i_5 <= _GEN_74
    io_rd_addr_aeq_i_6 <= _GEN_75
    io_rd_addr_aeq_i_7 <= _GEN_76
    io_rd_addr_aeq_i_8 <= _GEN_77
    io_wr_en_aeq_o_0 is invalid
    io_wr_en_aeq_o_1 is invalid
    io_wr_en_aeq_o_2 is invalid
    io_wr_en_aeq_o_3 is invalid
    io_wr_en_aeq_o_4 is invalid
    io_wr_en_aeq_o_5 is invalid
    io_wr_en_aeq_o_6 is invalid
    io_wr_en_aeq_o_7 is invalid
    io_wr_en_aeq_o_8 is invalid
    io_wr_addr_aeq_o_0 is invalid
    io_wr_addr_aeq_o_1 is invalid
    io_wr_addr_aeq_o_2 is invalid
    io_wr_addr_aeq_o_3 is invalid
    io_wr_addr_aeq_o_4 is invalid
    io_wr_addr_aeq_o_5 is invalid
    io_wr_addr_aeq_o_6 is invalid
    io_wr_addr_aeq_o_7 is invalid
    io_wr_addr_aeq_o_8 is invalid
    io_wr_data_aeq_o_0 is invalid
    io_wr_data_aeq_o_1 is invalid
    io_wr_data_aeq_o_2 is invalid
    io_wr_data_aeq_o_3 is invalid
    io_wr_data_aeq_o_4 is invalid
    io_wr_data_aeq_o_5 is invalid
    io_wr_data_aeq_o_6 is invalid
    io_wr_data_aeq_o_7 is invalid
    io_wr_data_aeq_o_8 is invalid
    io_wr_en_main_mempot_0 is invalid
    io_wr_en_main_mempot_1 is invalid
    io_wr_en_main_mempot_2 is invalid
    io_wr_en_main_mempot_3 is invalid
    io_wr_en_main_mempot_4 is invalid
    io_wr_en_main_mempot_5 is invalid
    io_wr_en_main_mempot_6 is invalid
    io_wr_en_main_mempot_7 is invalid
    io_wr_en_main_mempot_8 is invalid
    io_wr_addr_main_mempot_0 is invalid
    io_wr_addr_main_mempot_1 is invalid
    io_wr_addr_main_mempot_2 is invalid
    io_wr_addr_main_mempot_3 is invalid
    io_wr_addr_main_mempot_4 is invalid
    io_wr_addr_main_mempot_5 is invalid
    io_wr_addr_main_mempot_6 is invalid
    io_wr_addr_main_mempot_7 is invalid
    io_wr_addr_main_mempot_8 is invalid
    io_wr_data_main_mempot_0 is invalid
    io_wr_data_main_mempot_1 is invalid
    io_wr_data_main_mempot_2 is invalid
    io_wr_data_main_mempot_3 is invalid
    io_wr_data_main_mempot_4 is invalid
    io_wr_data_main_mempot_5 is invalid
    io_wr_data_main_mempot_6 is invalid
    io_wr_data_main_mempot_7 is invalid
    io_wr_data_main_mempot_8 is invalid
    io_rd_en_main_mempot_0 <= _GEN_144
    io_rd_en_main_mempot_1 <= _GEN_144
    io_rd_en_main_mempot_2 <= _GEN_144
    io_rd_en_main_mempot_3 <= _GEN_151
    io_rd_en_main_mempot_4 <= _GEN_151
    io_rd_en_main_mempot_5 <= _GEN_151
    io_rd_en_main_mempot_6 <= _GEN_169
    io_rd_en_main_mempot_7 <= _GEN_169
    io_rd_en_main_mempot_8 <= _GEN_169
    io_rd_addr_main_mempot_0 <= bits(_GEN_145, 7, 0)
    io_rd_addr_main_mempot_1 <= bits(_GEN_147, 7, 0)
    io_rd_addr_main_mempot_2 <= bits(_GEN_149, 7, 0)
    io_rd_addr_main_mempot_3 <= bits(_GEN_152, 7, 0)
    io_rd_addr_main_mempot_4 <= bits(_GEN_154, 7, 0)
    io_rd_addr_main_mempot_5 <= bits(_GEN_156, 7, 0)
    io_rd_addr_main_mempot_6 <= bits(_GEN_170, 7, 0)
    io_rd_addr_main_mempot_7 <= bits(_GEN_171, 7, 0)
    io_rd_addr_main_mempot_8 <= bits(_GEN_172, 7, 0)
    io_wr_en_L2_N_0 is invalid
    io_wr_en_L2_N_1 is invalid
    io_wr_en_L2_N_2 is invalid
    io_wr_addr_L2_N_0 is invalid
    io_wr_addr_L2_N_1 is invalid
    io_wr_addr_L2_N_2 is invalid
    io_wr_data_L2_N_0 is invalid
    io_wr_data_L2_N_1 is invalid
    io_wr_data_L2_N_2 is invalid
    io_rd_en_L2_N_0 <= _GEN_165
    io_rd_en_L2_N_1 <= _GEN_165
    io_rd_en_L2_N_2 <= _GEN_165
    io_rd_addr_L2_N_0 <= bits(_GEN_166, 7, 0)
    io_rd_addr_L2_N_1 <= bits(_GEN_167, 7, 0)
    io_rd_addr_L2_N_2 <= bits(_GEN_168, 7, 0)
    io_wr_en_L2_S_0 is invalid
    io_wr_en_L2_S_1 is invalid
    io_wr_en_L2_S_2 is invalid
    io_wr_addr_L2_S_0 is invalid
    io_wr_addr_L2_S_1 is invalid
    io_wr_addr_L2_S_2 is invalid
    io_wr_data_L2_S_0 is invalid
    io_wr_data_L2_S_1 is invalid
    io_wr_data_L2_S_2 is invalid
    io_rd_en_L2_S_0 <= _GEN_158
    io_rd_en_L2_S_1 <= _GEN_158
    io_rd_en_L2_S_2 <= _GEN_158
    io_rd_addr_L2_S_0 <= bits(_GEN_159, 7, 0)
    io_rd_addr_L2_S_1 <= bits(_GEN_161, 7, 0)
    io_rd_addr_L2_S_2 <= bits(_GEN_163, 7, 0)
    io_rd_en_L1_N_0 is invalid
    io_rd_en_L1_N_1 is invalid
    io_rd_en_L1_N_2 is invalid
    io_rd_addr_L1_N_0 is invalid
    io_rd_addr_L1_N_1 is invalid
    io_rd_addr_L1_N_2 is invalid
    io_rd_en_L1_S_0 is invalid
    io_rd_en_L1_S_1 is invalid
    io_rd_en_L1_S_2 is invalid
    io_rd_addr_L1_S_0 is invalid
    io_rd_addr_L1_S_1 is invalid
    io_rd_addr_L1_S_2 is invalid
    io_conv_done <= conv_done_reg @[src/main/scala/tile_3x3.scala 136:18]
    io_thresh_done <= thresh_done_reg @[src/main/scala/tile_3x3.scala 137:20]
    s1_addr_calc_0 <= _GEN_78
    s1_addr_calc_1 <= _GEN_79
    s1_addr_calc_2 <= _GEN_80
    s1_addr_calc_3 <= _GEN_81
    s1_addr_calc_4 <= _GEN_82
    s1_addr_calc_5 <= _GEN_83
    s1_addr_calc_6 <= _GEN_84
    s1_addr_calc_7 <= _GEN_85
    s1_addr_calc_8 <= _GEN_86
    s2_mempot_rd_0 <= bits(_GEN_146, 8, 0)
    s2_mempot_rd_1 <= bits(_GEN_148, 8, 0)
    s2_mempot_rd_2 <= bits(_GEN_150, 8, 0)
    s2_mempot_rd_3 <= bits(_GEN_153, 8, 0)
    s2_mempot_rd_4 <= bits(_GEN_155, 8, 0)
    s2_mempot_rd_5 <= bits(_GEN_157, 8, 0)
    s2_mempot_rd_6 <= bits(_GEN_160, 8, 0)
    s2_mempot_rd_7 <= bits(_GEN_162, 8, 0)
    s2_mempot_rd_8 <= bits(_GEN_164, 8, 0)
    s3_conv_0 <= s3_conv_0 @[src/main/scala/tile_3x3.scala 124:22]
    s3_conv_1 <= s3_conv_1 @[src/main/scala/tile_3x3.scala 124:22]
    s3_conv_2 <= s3_conv_2 @[src/main/scala/tile_3x3.scala 124:22]
    s3_conv_3 <= s3_conv_3 @[src/main/scala/tile_3x3.scala 124:22]
    s3_conv_4 <= s3_conv_4 @[src/main/scala/tile_3x3.scala 124:22]
    s3_conv_5 <= s3_conv_5 @[src/main/scala/tile_3x3.scala 124:22]
    s3_conv_6 <= s3_conv_6 @[src/main/scala/tile_3x3.scala 124:22]
    s3_conv_7 <= s3_conv_7 @[src/main/scala/tile_3x3.scala 124:22]
    s3_conv_8 <= s3_conv_8 @[src/main/scala/tile_3x3.scala 124:22]
    s1_valid <= mux(reset, UInt<1>("h0"), _GEN_87) @[src/main/scala/tile_3x3.scala 126:{27,27}]
    s2_valid <= mux(reset, UInt<1>("h0"), _GEN_143) @[src/main/scala/tile_3x3.scala 127:{27,27}]
    s3_valid <= mux(reset, UInt<1>("h0"), s3_valid) @[src/main/scala/tile_3x3.scala 128:{27,27,27}]
    s4_valid <= mux(reset, UInt<1>("h0"), s4_valid) @[src/main/scala/tile_3x3.scala 129:{27,27,27}]
    conv_done_reg <= mux(reset, UInt<1>("h0"), conv_done_reg) @[src/main/scala/tile_3x3.scala 133:{32,32,32}]
    thresh_done_reg <= mux(reset, UInt<1>("h0"), thresh_done_reg) @[src/main/scala/tile_3x3.scala 134:{34,34,34}]
    aeq_read_counter <= mux(reset, UInt<8>("h0"), _GEN_88) @[src/main/scala/tile_3x3.scala 143:{35,35}]
    aeq_read_col_sel_counter <= mux(reset, UInt<4>("h0"), _GEN_89) @[src/main/scala/tile_3x3.scala 144:{43,43}]
