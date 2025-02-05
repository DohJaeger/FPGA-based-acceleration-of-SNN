FIRRTL version 1.2.0
circuit my_top :
  module calculate : @[src/test/scala/my_mod_test.scala 33:7]
    input clock : Clock @[src/test/scala/my_mod_test.scala 33:7]
    input reset : UInt<1> @[src/test/scala/my_mod_test.scala 33:7]
    input io_start : UInt<1> @[src/test/scala/my_mod_test.scala 34:16]
    input io_i_data : UInt<8> @[src/test/scala/my_mod_test.scala 34:16]
    input io_i_data_valid : UInt<1> @[src/test/scala/my_mod_test.scala 34:16]
    output io_rd_addr : UInt<6> @[src/test/scala/my_mod_test.scala 34:16]
    output io_rd_en : UInt<1> @[src/test/scala/my_mod_test.scala 34:16]
    output io_wr_en : UInt<1> @[src/test/scala/my_mod_test.scala 34:16]
    output io_wr_addr : UInt<6> @[src/test/scala/my_mod_test.scala 34:16]
    output io_o_data : UInt<8> @[src/test/scala/my_mod_test.scala 34:16]
    output io_done : UInt<1> @[src/test/scala/my_mod_test.scala 34:16]

    reg counter : UInt<8>, clock with :
      reset => (UInt<1>("h0"), counter) @[src/test/scala/my_mod_test.scala 53:26]
    reg temp : UInt<8>, clock with :
      reset => (UInt<1>("h0"), temp) @[src/test/scala/my_mod_test.scala 54:23]
    node _T = eq(counter, UInt<4>("hb")) @[src/test/scala/my_mod_test.scala 56:32]
    node _T_1 = eq(_T, UInt<1>("h0")) @[src/test/scala/my_mod_test.scala 56:22]
    node _T_2 = and(io_start, _T_1) @[src/test/scala/my_mod_test.scala 56:19]
    node _GEN_0 = mux(io_i_data_valid, io_i_data, temp) @[src/test/scala/my_mod_test.scala 60:30 61:18 54:23]
    node _temp_T = add(temp, UInt<3>("h4")) @[src/test/scala/my_mod_test.scala 64:22]
    node _temp_T_1 = tail(_temp_T, 1) @[src/test/scala/my_mod_test.scala 64:22]
    node _counter_T = add(counter, UInt<1>("h1")) @[src/test/scala/my_mod_test.scala 70:28]
    node _counter_T_1 = tail(_counter_T, 1) @[src/test/scala/my_mod_test.scala 70:28]
    node _GEN_1 = validif(_T_2, counter) @[src/test/scala/my_mod_test.scala 56:42 57:20]
    node _GEN_2 = mux(_T_2, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/my_mod_test.scala 56:42 58:18 73:18]
    node _GEN_3 = mux(_T_2, _temp_T_1, temp) @[src/test/scala/my_mod_test.scala 56:42 64:14 54:23]
    node _GEN_4 = validif(_T_2, temp) @[src/test/scala/my_mod_test.scala 56:42 68:19]
    node _GEN_5 = mux(_T_2, _counter_T_1, counter) @[src/test/scala/my_mod_test.scala 56:42 70:17 53:26]
    node _T_3 = eq(counter, UInt<4>("hb")) @[src/test/scala/my_mod_test.scala 77:18]
    node _GEN_6 = mux(_T_3, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/my_mod_test.scala 51:13 77:28 78:17]
    io_rd_addr <= bits(_GEN_1, 5, 0)
    io_rd_en <= _GEN_2
    io_wr_en <= _GEN_2
    io_wr_addr <= bits(_GEN_1, 5, 0)
    io_o_data <= _GEN_4
    io_done <= _GEN_6
    counter <= mux(reset, UInt<8>("h0"), _GEN_5) @[src/test/scala/my_mod_test.scala 53:{26,26}]
    temp <= mux(reset, UInt<8>("h0"), _GEN_3) @[src/test/scala/my_mod_test.scala 54:{23,23}]

  module my_bram : @[src/test/scala/my_mod_test.scala 7:7]
    input clock : Clock @[src/test/scala/my_mod_test.scala 7:7]
    input reset : UInt<1> @[src/test/scala/my_mod_test.scala 7:7]
    input io_rd_addr : UInt<6> @[src/test/scala/my_mod_test.scala 8:16]
    output io_rd_data : UInt<8> @[src/test/scala/my_mod_test.scala 8:16]
    output io_rd_data_valid : UInt<1> @[src/test/scala/my_mod_test.scala 8:16]
    input io_wr_addr : UInt<6> @[src/test/scala/my_mod_test.scala 8:16]
    input io_wr_data : UInt<8> @[src/test/scala/my_mod_test.scala 8:16]
    input io_wr_en : UInt<1> @[src/test/scala/my_mod_test.scala 8:16]
    input io_rd_en : UInt<1> @[src/test/scala/my_mod_test.scala 8:16]

    mem mem : @[src/test/scala/my_mod_test.scala 17:26]
      data-type => UInt<8>
      depth => 50
      read-latency => 1
      write-latency => 1
      reader => io_rd_data_MPORT
      writer => MPORT
      read-under-write => undefined
    node _GEN_0 = validif(UInt<1>("h1"), io_rd_addr) @[src/test/scala/my_mod_test.scala 21:{31,31}]
    node _GEN_1 = mux(UInt<1>("h1"), UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/my_mod_test.scala 17:26 21:{31,31}]
    node _io_rd_data_WIRE = _GEN_0 @[src/test/scala/my_mod_test.scala 21:31]
    node _GEN_2 = validif(UInt<1>("h1"), _io_rd_data_WIRE) @[src/test/scala/my_mod_test.scala 21:{31,31}]
    node _GEN_3 = validif(UInt<1>("h1"), clock) @[src/test/scala/my_mod_test.scala 21:{31,31}]
    node _GEN_4 = mux(io_rd_en, _GEN_1, UInt<1>("h0")) @[src/test/scala/my_mod_test.scala 20:20 17:26]
    node _GEN_5 = validif(io_rd_en, _GEN_2) @[src/test/scala/my_mod_test.scala 20:20]
    node _GEN_6 = validif(io_rd_en, _GEN_3) @[src/test/scala/my_mod_test.scala 20:20]
    node _GEN_7 = validif(io_rd_en, mem.io_rd_data_MPORT.data) @[src/test/scala/my_mod_test.scala 20:20 21:20]
    node _GEN_8 = mux(io_rd_en, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/my_mod_test.scala 20:20 22:26 25:26]
    node _GEN_9 = validif(io_wr_en, io_wr_addr) @[src/test/scala/my_mod_test.scala 28:20 29:18]
    node _GEN_10 = validif(io_wr_en, clock) @[src/test/scala/my_mod_test.scala 28:20 29:18]
    node _GEN_11 = mux(io_wr_en, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/my_mod_test.scala 28:20 29:18 17:26]
    node _GEN_12 = validif(io_wr_en, UInt<1>("h1")) @[src/test/scala/my_mod_test.scala 28:20 29:18]
    node _GEN_13 = validif(io_wr_en, io_wr_data) @[src/test/scala/my_mod_test.scala 28:20 29:18]
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

  module my_top : @[src/test/scala/my_mod_test.scala 82:7]
    input clock : Clock @[src/test/scala/my_mod_test.scala 82:7]
    input reset : UInt<1> @[src/test/scala/my_mod_test.scala 82:7]
    input io_start : UInt<1> @[src/test/scala/my_mod_test.scala 83:16]
    output io_done : UInt<1> @[src/test/scala/my_mod_test.scala 83:16]
    output exposed_rd_addr : UInt<6> @[src/main/scala/chiseltest/experimental/Observe.scala 71:16]
    output exposed_wr_addr : UInt<6> @[src/main/scala/chiseltest/experimental/Observe.scala 71:16]
    output exposed_o_data : UInt<8> @[src/main/scala/chiseltest/experimental/Observe.scala 71:16]
    output exposed_i_data : UInt<8> @[src/main/scala/chiseltest/experimental/Observe.scala 71:16]
    output exposed_done : UInt<1> @[src/main/scala/chiseltest/experimental/Observe.scala 71:16]

    inst my_calc of calculate @[src/test/scala/my_mod_test.scala 88:25]
    inst my_mem of my_bram @[src/test/scala/my_mod_test.scala 89:24]
    node exposed_rd_addr_ob_bore = my_calc.io_rd_addr @[src/main/scala/chiseltest/experimental/Observe.scala 72:{27,27}]
    node exposed_wr_addr_ob_bore = my_calc.io_wr_addr @[src/main/scala/chiseltest/experimental/Observe.scala 72:{27,27}]
    node exposed_o_data_ob_bore = my_calc.io_o_data @[src/main/scala/chiseltest/experimental/Observe.scala 72:{27,27}]
    node exposed_i_data_ob_bore = my_calc.io_i_data @[src/main/scala/chiseltest/experimental/Observe.scala 72:{27,27}]
    node exposed_done_ob_bore = my_calc.io_done @[src/main/scala/chiseltest/experimental/Observe.scala 72:{27,27}]
    io_done <= my_calc.io_done @[src/test/scala/my_mod_test.scala 95:13]
    exposed_rd_addr <= exposed_rd_addr_ob_bore @[src/main/scala/chiseltest/experimental/Observe.scala 72:8]
    exposed_wr_addr <= exposed_wr_addr_ob_bore @[src/main/scala/chiseltest/experimental/Observe.scala 72:8]
    exposed_o_data <= exposed_o_data_ob_bore @[src/main/scala/chiseltest/experimental/Observe.scala 72:8]
    exposed_i_data <= exposed_i_data_ob_bore @[src/main/scala/chiseltest/experimental/Observe.scala 72:8]
    exposed_done <= exposed_done_ob_bore @[src/main/scala/chiseltest/experimental/Observe.scala 72:8]
    my_calc.clock <= clock
    my_calc.reset <= reset
    my_calc.io_start <= io_start @[src/test/scala/my_mod_test.scala 92:22]
    my_calc.io_i_data <= my_mem.io_rd_data @[src/test/scala/my_mod_test.scala 93:23]
    my_calc.io_i_data_valid <= my_mem.io_rd_data_valid @[src/test/scala/my_mod_test.scala 94:29]
    my_mem.clock <= clock
    my_mem.reset <= reset
    my_mem.io_rd_addr <= my_calc.io_rd_addr @[src/test/scala/my_mod_test.scala 97:23]
    my_mem.io_wr_addr <= my_calc.io_wr_addr @[src/test/scala/my_mod_test.scala 99:23]
    my_mem.io_wr_data <= my_calc.io_o_data @[src/test/scala/my_mod_test.scala 101:23]
    my_mem.io_wr_en <= my_calc.io_wr_en @[src/test/scala/my_mod_test.scala 100:21]
    my_mem.io_rd_en <= my_calc.io_rd_en @[src/test/scala/my_mod_test.scala 98:21]
