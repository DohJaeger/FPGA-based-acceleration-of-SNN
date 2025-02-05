FIRRTL version 1.2.0
circuit my_top :
  module calculate : @[src/test/scala/my_mod_test.scala 32:7]
    input clock : Clock @[src/test/scala/my_mod_test.scala 32:7]
    input reset : UInt<1> @[src/test/scala/my_mod_test.scala 32:7]
    input io_start : UInt<1> @[src/test/scala/my_mod_test.scala 33:16]
    input io_i_data : UInt<8> @[src/test/scala/my_mod_test.scala 33:16]
    input io_i_data_valid : UInt<1> @[src/test/scala/my_mod_test.scala 33:16]
    output io_rd_addr : UInt<6> @[src/test/scala/my_mod_test.scala 33:16]
    output io_rd_en : UInt<1> @[src/test/scala/my_mod_test.scala 33:16]
    output io_wr_en : UInt<1> @[src/test/scala/my_mod_test.scala 33:16]
    output io_wr_addr : UInt<6> @[src/test/scala/my_mod_test.scala 33:16]
    output io_o_data : UInt<8> @[src/test/scala/my_mod_test.scala 33:16]
    output io_done : UInt<1> @[src/test/scala/my_mod_test.scala 33:16]

    reg counter : UInt<8>, clock with :
      reset => (UInt<1>("h0"), counter) @[src/test/scala/my_mod_test.scala 52:26]
    reg temp : UInt<8>, clock with :
      reset => (UInt<1>("h0"), temp) @[src/test/scala/my_mod_test.scala 53:23]
    node _T = eq(counter, UInt<4>("hb")) @[src/test/scala/my_mod_test.scala 55:32]
    node _T_1 = eq(_T, UInt<1>("h0")) @[src/test/scala/my_mod_test.scala 55:22]
    node _T_2 = and(io_start, _T_1) @[src/test/scala/my_mod_test.scala 55:19]
    node _GEN_0 = mux(io_i_data_valid, io_i_data, temp) @[src/test/scala/my_mod_test.scala 59:30 60:18 53:23]
    node _temp_T = add(temp, UInt<3>("h4")) @[src/test/scala/my_mod_test.scala 63:22]
    node _temp_T_1 = tail(_temp_T, 1) @[src/test/scala/my_mod_test.scala 63:22]
    node _counter_T = add(counter, UInt<1>("h1")) @[src/test/scala/my_mod_test.scala 69:28]
    node _counter_T_1 = tail(_counter_T, 1) @[src/test/scala/my_mod_test.scala 69:28]
    node _GEN_1 = validif(_T_2, counter) @[src/test/scala/my_mod_test.scala 55:42 56:20]
    node _GEN_2 = mux(_T_2, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/my_mod_test.scala 55:42 57:18 72:18]
    node _GEN_3 = mux(_T_2, _temp_T_1, temp) @[src/test/scala/my_mod_test.scala 55:42 63:14 53:23]
    node _GEN_4 = validif(_T_2, temp) @[src/test/scala/my_mod_test.scala 55:42 67:19]
    node _GEN_5 = mux(_T_2, _counter_T_1, counter) @[src/test/scala/my_mod_test.scala 55:42 69:17 52:26]
    node _T_3 = eq(counter, UInt<4>("hb")) @[src/test/scala/my_mod_test.scala 76:18]
    node _GEN_6 = mux(_T_3, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/my_mod_test.scala 50:13 76:28 77:17]
    io_rd_addr <= bits(_GEN_1, 5, 0)
    io_rd_en <= _GEN_2
    io_wr_en <= _GEN_2
    io_wr_addr <= bits(_GEN_1, 5, 0)
    io_o_data <= _GEN_4
    io_done <= _GEN_6
    counter <= mux(reset, UInt<8>("h0"), _GEN_5) @[src/test/scala/my_mod_test.scala 52:{26,26}]
    temp <= mux(reset, UInt<8>("h0"), _GEN_3) @[src/test/scala/my_mod_test.scala 53:{23,23}]

  module my_bram : @[src/test/scala/my_mod_test.scala 6:7]
    input clock : Clock @[src/test/scala/my_mod_test.scala 6:7]
    input reset : UInt<1> @[src/test/scala/my_mod_test.scala 6:7]
    input io_rd_addr : UInt<6> @[src/test/scala/my_mod_test.scala 7:16]
    output io_rd_data : UInt<8> @[src/test/scala/my_mod_test.scala 7:16]
    output io_rd_data_valid : UInt<1> @[src/test/scala/my_mod_test.scala 7:16]
    input io_wr_addr : UInt<6> @[src/test/scala/my_mod_test.scala 7:16]
    input io_wr_data : UInt<8> @[src/test/scala/my_mod_test.scala 7:16]
    input io_wr_en : UInt<1> @[src/test/scala/my_mod_test.scala 7:16]
    input io_rd_en : UInt<1> @[src/test/scala/my_mod_test.scala 7:16]

    mem mem : @[src/test/scala/my_mod_test.scala 16:26]
      data-type => UInt<8>
      depth => 50
      read-latency => 1
      write-latency => 1
      reader => io_rd_data_MPORT
      writer => MPORT
      read-under-write => undefined
    node _GEN_0 = validif(UInt<1>("h1"), io_rd_addr) @[src/test/scala/my_mod_test.scala 20:{31,31}]
    node _GEN_1 = mux(UInt<1>("h1"), UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/my_mod_test.scala 16:26 20:{31,31}]
    node _io_rd_data_WIRE = _GEN_0 @[src/test/scala/my_mod_test.scala 20:31]
    node _GEN_2 = validif(UInt<1>("h1"), _io_rd_data_WIRE) @[src/test/scala/my_mod_test.scala 20:{31,31}]
    node _GEN_3 = validif(UInt<1>("h1"), clock) @[src/test/scala/my_mod_test.scala 20:{31,31}]
    node _GEN_4 = mux(io_rd_en, _GEN_1, UInt<1>("h0")) @[src/test/scala/my_mod_test.scala 19:20 16:26]
    node _GEN_5 = validif(io_rd_en, _GEN_2) @[src/test/scala/my_mod_test.scala 19:20]
    node _GEN_6 = validif(io_rd_en, _GEN_3) @[src/test/scala/my_mod_test.scala 19:20]
    node _GEN_7 = validif(io_rd_en, mem.io_rd_data_MPORT.data) @[src/test/scala/my_mod_test.scala 19:20 20:20]
    node _GEN_8 = mux(io_rd_en, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/my_mod_test.scala 19:20 21:26 24:26]
    node _GEN_9 = validif(io_wr_en, io_wr_addr) @[src/test/scala/my_mod_test.scala 27:20 28:18]
    node _GEN_10 = validif(io_wr_en, clock) @[src/test/scala/my_mod_test.scala 27:20 28:18]
    node _GEN_11 = mux(io_wr_en, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/my_mod_test.scala 27:20 28:18 16:26]
    node _GEN_12 = validif(io_wr_en, UInt<1>("h1")) @[src/test/scala/my_mod_test.scala 27:20 28:18]
    node _GEN_13 = validif(io_wr_en, io_wr_data) @[src/test/scala/my_mod_test.scala 27:20 28:18]
    io_rd_data <= _GEN_7
    io_rd_data_valid <= _GEN_8
    mem.io_rd_data_MPORT.addr <= _GEN_5
    mem.io_rd_data_MPORT.en <= _GEN_4
    mem.io_rd_data_MPORT.clk <= _GEN_6
    mem.MPORT.addr <= _GEN_9
    mem.MPORT.en <= _GEN_11
    mem.MPORT.clk <= _GEN_10
    mem.MPORT.data <= _GEN_13
    mem.MPORT.mask <= _GEN_12

  module my_top : @[src/test/scala/my_mod_test.scala 81:7]
    input clock : Clock @[src/test/scala/my_mod_test.scala 81:7]
    input reset : UInt<1> @[src/test/scala/my_mod_test.scala 81:7]
    input io_start : UInt<1> @[src/test/scala/my_mod_test.scala 82:16]
    output io_done : UInt<1> @[src/test/scala/my_mod_test.scala 82:16]

    inst my_calc of calculate @[src/test/scala/my_mod_test.scala 87:25]
    inst my_mem of my_bram @[src/test/scala/my_mod_test.scala 88:24]
    io_done <= my_calc.io_done @[src/test/scala/my_mod_test.scala 94:13]
    my_calc.clock <= clock
    my_calc.reset <= reset
    my_calc.io_start <= io_start @[src/test/scala/my_mod_test.scala 91:22]
    my_calc.io_i_data <= my_mem.io_rd_data @[src/test/scala/my_mod_test.scala 92:23]
    my_calc.io_i_data_valid <= my_mem.io_rd_data_valid @[src/test/scala/my_mod_test.scala 93:29]
    my_mem.clock <= clock
    my_mem.reset <= reset
    my_mem.io_rd_addr <= my_calc.io_rd_addr @[src/test/scala/my_mod_test.scala 96:23]
    my_mem.io_wr_addr <= my_calc.io_wr_addr @[src/test/scala/my_mod_test.scala 98:23]
    my_mem.io_wr_data <= my_calc.io_o_data @[src/test/scala/my_mod_test.scala 100:23]
    my_mem.io_wr_en <= my_calc.io_wr_en @[src/test/scala/my_mod_test.scala 99:21]
    my_mem.io_rd_en <= my_calc.io_rd_en @[src/test/scala/my_mod_test.scala 97:21]
