FIRRTL version 1.2.0
circuit AEQ :
  module AEQ : @[src/test/scala/aeq.scala 15:8]
    input clock : Clock @[src/test/scala/aeq.scala 15:8]
    input reset : UInt<1> @[src/test/scala/aeq.scala 15:8]
    input io_writeEnable_0 : UInt<1> @[src/test/scala/aeq.scala 16:14]
    input io_writeEnable_1 : UInt<1> @[src/test/scala/aeq.scala 16:14]
    input io_writeEnable_2 : UInt<1> @[src/test/scala/aeq.scala 16:14]
    input io_writeEnable_3 : UInt<1> @[src/test/scala/aeq.scala 16:14]
    input io_writeEnable_4 : UInt<1> @[src/test/scala/aeq.scala 16:14]
    input io_writeEnable_5 : UInt<1> @[src/test/scala/aeq.scala 16:14]
    input io_writeEnable_6 : UInt<1> @[src/test/scala/aeq.scala 16:14]
    input io_writeEnable_7 : UInt<1> @[src/test/scala/aeq.scala 16:14]
    input io_writeEnable_8 : UInt<1> @[src/test/scala/aeq.scala 16:14]
    input io_readEnable : UInt<1> @[src/test/scala/aeq.scala 16:14]
    input io_writeData_0 : UInt<9> @[src/test/scala/aeq.scala 16:14]
    input io_writeData_1 : UInt<9> @[src/test/scala/aeq.scala 16:14]
    input io_writeData_2 : UInt<9> @[src/test/scala/aeq.scala 16:14]
    input io_writeData_3 : UInt<9> @[src/test/scala/aeq.scala 16:14]
    input io_writeData_4 : UInt<9> @[src/test/scala/aeq.scala 16:14]
    input io_writeData_5 : UInt<9> @[src/test/scala/aeq.scala 16:14]
    input io_writeData_6 : UInt<9> @[src/test/scala/aeq.scala 16:14]
    input io_writeData_7 : UInt<9> @[src/test/scala/aeq.scala 16:14]
    input io_writeData_8 : UInt<9> @[src/test/scala/aeq.scala 16:14]
    output io_readData_0 : UInt<11> @[src/test/scala/aeq.scala 16:14]
    output io_readData_1 : UInt<11> @[src/test/scala/aeq.scala 16:14]
    output io_readData_2 : UInt<11> @[src/test/scala/aeq.scala 16:14]
    output io_readData_3 : UInt<11> @[src/test/scala/aeq.scala 16:14]
    output io_readData_4 : UInt<11> @[src/test/scala/aeq.scala 16:14]
    output io_readData_5 : UInt<11> @[src/test/scala/aeq.scala 16:14]
    output io_readData_6 : UInt<11> @[src/test/scala/aeq.scala 16:14]
    output io_readData_7 : UInt<11> @[src/test/scala/aeq.scala 16:14]
    output io_readData_8 : UInt<11> @[src/test/scala/aeq.scala 16:14]

    mem brams_0 : @[src/test/scala/aeq.scala 23:30]
      data-type => UInt<11>
      depth => 256
      read-latency => 0
      write-latency => 1
      reader => data1
      writer => MPORT
      writer => MPORT_1
      read-under-write => undefined
    mem brams_1 : @[src/test/scala/aeq.scala 23:30]
      data-type => UInt<11>
      depth => 256
      read-latency => 0
      write-latency => 1
      reader => data1_1
      writer => MPORT_2
      writer => MPORT_3
      read-under-write => undefined
    mem brams_2 : @[src/test/scala/aeq.scala 23:30]
      data-type => UInt<11>
      depth => 256
      read-latency => 0
      write-latency => 1
      reader => data1_2
      writer => MPORT_4
      writer => MPORT_5
      read-under-write => undefined
    mem brams_3 : @[src/test/scala/aeq.scala 23:30]
      data-type => UInt<11>
      depth => 256
      read-latency => 0
      write-latency => 1
      reader => data1_3
      writer => MPORT_6
      writer => MPORT_7
      read-under-write => undefined
    mem brams_4 : @[src/test/scala/aeq.scala 23:30]
      data-type => UInt<11>
      depth => 256
      read-latency => 0
      write-latency => 1
      reader => data1_4
      writer => MPORT_8
      writer => MPORT_9
      read-under-write => undefined
    mem brams_5 : @[src/test/scala/aeq.scala 23:30]
      data-type => UInt<11>
      depth => 256
      read-latency => 0
      write-latency => 1
      reader => data1_5
      writer => MPORT_10
      writer => MPORT_11
      read-under-write => undefined
    mem brams_6 : @[src/test/scala/aeq.scala 23:30]
      data-type => UInt<11>
      depth => 256
      read-latency => 0
      write-latency => 1
      reader => data1_6
      writer => MPORT_12
      writer => MPORT_13
      read-under-write => undefined
    mem brams_7 : @[src/test/scala/aeq.scala 23:30]
      data-type => UInt<11>
      depth => 256
      read-latency => 0
      write-latency => 1
      reader => data1_7
      writer => MPORT_14
      writer => MPORT_15
      read-under-write => undefined
    mem brams_8 : @[src/test/scala/aeq.scala 23:30]
      data-type => UInt<11>
      depth => 256
      read-latency => 0
      write-latency => 1
      reader => data1_8
      writer => MPORT_16
      writer => MPORT_17
      read-under-write => undefined
    reg writeCounters_0 : UInt<8>, clock with :
      reset => (UInt<1>("h0"), writeCounters_0) @[src/test/scala/aeq.scala 24:30]
    reg writeCounters_1 : UInt<8>, clock with :
      reset => (UInt<1>("h0"), writeCounters_1) @[src/test/scala/aeq.scala 24:30]
    reg writeCounters_2 : UInt<8>, clock with :
      reset => (UInt<1>("h0"), writeCounters_2) @[src/test/scala/aeq.scala 24:30]
    reg writeCounters_3 : UInt<8>, clock with :
      reset => (UInt<1>("h0"), writeCounters_3) @[src/test/scala/aeq.scala 24:30]
    reg writeCounters_4 : UInt<8>, clock with :
      reset => (UInt<1>("h0"), writeCounters_4) @[src/test/scala/aeq.scala 24:30]
    reg writeCounters_5 : UInt<8>, clock with :
      reset => (UInt<1>("h0"), writeCounters_5) @[src/test/scala/aeq.scala 24:30]
    reg writeCounters_6 : UInt<8>, clock with :
      reset => (UInt<1>("h0"), writeCounters_6) @[src/test/scala/aeq.scala 24:30]
    reg writeCounters_7 : UInt<8>, clock with :
      reset => (UInt<1>("h0"), writeCounters_7) @[src/test/scala/aeq.scala 24:30]
    reg writeCounters_8 : UInt<8>, clock with :
      reset => (UInt<1>("h0"), writeCounters_8) @[src/test/scala/aeq.scala 24:30]
    reg readCounter : UInt<8>, clock with :
      reset => (UInt<1>("h0"), readCounter) @[src/test/scala/aeq.scala 25:28]
    reg columnSelectCounter : UInt<4>, clock with :
      reset => (UInt<1>("h0"), columnSelectCounter) @[src/test/scala/aeq.scala 26:36]
    node _T = eq(io_readEnable, UInt<1>("h0")) @[src/test/scala/aeq.scala 32:10]
    node _T_1 = and(_T, io_writeEnable_0) @[src/test/scala/aeq.scala 32:25]
    node data_hi = cat(UInt<1>("h0"), io_writeData_0) @[src/test/scala/aeq.scala 33:21]
    node data = cat(data_hi, UInt<1>("h1")) @[src/test/scala/aeq.scala 33:21]
    node _writeCounters_0_T = add(writeCounters_0, UInt<1>("h1")) @[src/test/scala/aeq.scala 35:44]
    node _writeCounters_0_T_1 = tail(_writeCounters_0_T, 1) @[src/test/scala/aeq.scala 35:44]
    node _T_2 = eq(writeCounters_0, UInt<8>("hff")) @[src/test/scala/aeq.scala 36:29]
    node lastData_hi = cat(UInt<1>("h1"), io_writeData_0) @[src/test/scala/aeq.scala 37:27]
    node lastData = cat(lastData_hi, UInt<1>("h1")) @[src/test/scala/aeq.scala 37:27]
    node _GEN_0 = validif(_T_2, writeCounters_0) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_1 = validif(_T_2, clock) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_2 = mux(_T_2, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/aeq.scala 36:40 38:23 23:30]
    node _GEN_3 = validif(_T_2, UInt<1>("h1")) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_4 = validif(_T_2, lastData) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_5 = validif(_T_1, writeCounters_0) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_6 = validif(_T_1, clock) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_7 = mux(_T_1, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/aeq.scala 32:47 34:21 23:30]
    node _GEN_8 = validif(_T_1, UInt<1>("h1")) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_9 = validif(_T_1, data) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_10 = mux(_T_1, _writeCounters_0_T_1, writeCounters_0) @[src/test/scala/aeq.scala 32:47 35:24 24:30]
    node _GEN_11 = validif(_T_1, _GEN_0) @[src/test/scala/aeq.scala 32:47]
    node _GEN_12 = validif(_T_1, _GEN_1) @[src/test/scala/aeq.scala 32:47]
    node _GEN_13 = mux(_T_1, _GEN_2, UInt<1>("h0")) @[src/test/scala/aeq.scala 23:30 32:47]
    node _GEN_14 = validif(_T_1, _GEN_3) @[src/test/scala/aeq.scala 32:47]
    node _GEN_15 = validif(_T_1, _GEN_4) @[src/test/scala/aeq.scala 32:47]
    node _T_3 = eq(io_readEnable, UInt<1>("h0")) @[src/test/scala/aeq.scala 32:10]
    node _T_4 = and(_T_3, io_writeEnable_1) @[src/test/scala/aeq.scala 32:25]
    node data_hi_1 = cat(UInt<1>("h0"), io_writeData_1) @[src/test/scala/aeq.scala 33:21]
    node data_1 = cat(data_hi_1, UInt<1>("h1")) @[src/test/scala/aeq.scala 33:21]
    node _writeCounters_1_T = add(writeCounters_1, UInt<1>("h1")) @[src/test/scala/aeq.scala 35:44]
    node _writeCounters_1_T_1 = tail(_writeCounters_1_T, 1) @[src/test/scala/aeq.scala 35:44]
    node _T_5 = eq(writeCounters_1, UInt<8>("hff")) @[src/test/scala/aeq.scala 36:29]
    node lastData_hi_1 = cat(UInt<1>("h1"), io_writeData_1) @[src/test/scala/aeq.scala 37:27]
    node lastData_1 = cat(lastData_hi_1, UInt<1>("h1")) @[src/test/scala/aeq.scala 37:27]
    node _GEN_16 = validif(_T_5, writeCounters_1) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_17 = validif(_T_5, clock) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_18 = mux(_T_5, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/aeq.scala 36:40 38:23 23:30]
    node _GEN_19 = validif(_T_5, UInt<1>("h1")) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_20 = validif(_T_5, lastData_1) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_21 = validif(_T_4, writeCounters_1) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_22 = validif(_T_4, clock) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_23 = mux(_T_4, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/aeq.scala 32:47 34:21 23:30]
    node _GEN_24 = validif(_T_4, UInt<1>("h1")) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_25 = validif(_T_4, data_1) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_26 = mux(_T_4, _writeCounters_1_T_1, writeCounters_1) @[src/test/scala/aeq.scala 32:47 35:24 24:30]
    node _GEN_27 = validif(_T_4, _GEN_16) @[src/test/scala/aeq.scala 32:47]
    node _GEN_28 = validif(_T_4, _GEN_17) @[src/test/scala/aeq.scala 32:47]
    node _GEN_29 = mux(_T_4, _GEN_18, UInt<1>("h0")) @[src/test/scala/aeq.scala 23:30 32:47]
    node _GEN_30 = validif(_T_4, _GEN_19) @[src/test/scala/aeq.scala 32:47]
    node _GEN_31 = validif(_T_4, _GEN_20) @[src/test/scala/aeq.scala 32:47]
    node _T_6 = eq(io_readEnable, UInt<1>("h0")) @[src/test/scala/aeq.scala 32:10]
    node _T_7 = and(_T_6, io_writeEnable_2) @[src/test/scala/aeq.scala 32:25]
    node data_hi_2 = cat(UInt<1>("h0"), io_writeData_2) @[src/test/scala/aeq.scala 33:21]
    node data_2 = cat(data_hi_2, UInt<1>("h1")) @[src/test/scala/aeq.scala 33:21]
    node _writeCounters_2_T = add(writeCounters_2, UInt<1>("h1")) @[src/test/scala/aeq.scala 35:44]
    node _writeCounters_2_T_1 = tail(_writeCounters_2_T, 1) @[src/test/scala/aeq.scala 35:44]
    node _T_8 = eq(writeCounters_2, UInt<8>("hff")) @[src/test/scala/aeq.scala 36:29]
    node lastData_hi_2 = cat(UInt<1>("h1"), io_writeData_2) @[src/test/scala/aeq.scala 37:27]
    node lastData_2 = cat(lastData_hi_2, UInt<1>("h1")) @[src/test/scala/aeq.scala 37:27]
    node _GEN_32 = validif(_T_8, writeCounters_2) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_33 = validif(_T_8, clock) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_34 = mux(_T_8, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/aeq.scala 36:40 38:23 23:30]
    node _GEN_35 = validif(_T_8, UInt<1>("h1")) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_36 = validif(_T_8, lastData_2) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_37 = validif(_T_7, writeCounters_2) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_38 = validif(_T_7, clock) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_39 = mux(_T_7, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/aeq.scala 32:47 34:21 23:30]
    node _GEN_40 = validif(_T_7, UInt<1>("h1")) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_41 = validif(_T_7, data_2) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_42 = mux(_T_7, _writeCounters_2_T_1, writeCounters_2) @[src/test/scala/aeq.scala 32:47 35:24 24:30]
    node _GEN_43 = validif(_T_7, _GEN_32) @[src/test/scala/aeq.scala 32:47]
    node _GEN_44 = validif(_T_7, _GEN_33) @[src/test/scala/aeq.scala 32:47]
    node _GEN_45 = mux(_T_7, _GEN_34, UInt<1>("h0")) @[src/test/scala/aeq.scala 23:30 32:47]
    node _GEN_46 = validif(_T_7, _GEN_35) @[src/test/scala/aeq.scala 32:47]
    node _GEN_47 = validif(_T_7, _GEN_36) @[src/test/scala/aeq.scala 32:47]
    node _T_9 = eq(io_readEnable, UInt<1>("h0")) @[src/test/scala/aeq.scala 32:10]
    node _T_10 = and(_T_9, io_writeEnable_3) @[src/test/scala/aeq.scala 32:25]
    node data_hi_3 = cat(UInt<1>("h0"), io_writeData_3) @[src/test/scala/aeq.scala 33:21]
    node data_3 = cat(data_hi_3, UInt<1>("h1")) @[src/test/scala/aeq.scala 33:21]
    node _writeCounters_3_T = add(writeCounters_3, UInt<1>("h1")) @[src/test/scala/aeq.scala 35:44]
    node _writeCounters_3_T_1 = tail(_writeCounters_3_T, 1) @[src/test/scala/aeq.scala 35:44]
    node _T_11 = eq(writeCounters_3, UInt<8>("hff")) @[src/test/scala/aeq.scala 36:29]
    node lastData_hi_3 = cat(UInt<1>("h1"), io_writeData_3) @[src/test/scala/aeq.scala 37:27]
    node lastData_3 = cat(lastData_hi_3, UInt<1>("h1")) @[src/test/scala/aeq.scala 37:27]
    node _GEN_48 = validif(_T_11, writeCounters_3) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_49 = validif(_T_11, clock) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_50 = mux(_T_11, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/aeq.scala 36:40 38:23 23:30]
    node _GEN_51 = validif(_T_11, UInt<1>("h1")) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_52 = validif(_T_11, lastData_3) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_53 = validif(_T_10, writeCounters_3) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_54 = validif(_T_10, clock) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_55 = mux(_T_10, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/aeq.scala 32:47 34:21 23:30]
    node _GEN_56 = validif(_T_10, UInt<1>("h1")) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_57 = validif(_T_10, data_3) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_58 = mux(_T_10, _writeCounters_3_T_1, writeCounters_3) @[src/test/scala/aeq.scala 32:47 35:24 24:30]
    node _GEN_59 = validif(_T_10, _GEN_48) @[src/test/scala/aeq.scala 32:47]
    node _GEN_60 = validif(_T_10, _GEN_49) @[src/test/scala/aeq.scala 32:47]
    node _GEN_61 = mux(_T_10, _GEN_50, UInt<1>("h0")) @[src/test/scala/aeq.scala 23:30 32:47]
    node _GEN_62 = validif(_T_10, _GEN_51) @[src/test/scala/aeq.scala 32:47]
    node _GEN_63 = validif(_T_10, _GEN_52) @[src/test/scala/aeq.scala 32:47]
    node _T_12 = eq(io_readEnable, UInt<1>("h0")) @[src/test/scala/aeq.scala 32:10]
    node _T_13 = and(_T_12, io_writeEnable_4) @[src/test/scala/aeq.scala 32:25]
    node data_hi_4 = cat(UInt<1>("h0"), io_writeData_4) @[src/test/scala/aeq.scala 33:21]
    node data_4 = cat(data_hi_4, UInt<1>("h1")) @[src/test/scala/aeq.scala 33:21]
    node _writeCounters_4_T = add(writeCounters_4, UInt<1>("h1")) @[src/test/scala/aeq.scala 35:44]
    node _writeCounters_4_T_1 = tail(_writeCounters_4_T, 1) @[src/test/scala/aeq.scala 35:44]
    node _T_14 = eq(writeCounters_4, UInt<8>("hff")) @[src/test/scala/aeq.scala 36:29]
    node lastData_hi_4 = cat(UInt<1>("h1"), io_writeData_4) @[src/test/scala/aeq.scala 37:27]
    node lastData_4 = cat(lastData_hi_4, UInt<1>("h1")) @[src/test/scala/aeq.scala 37:27]
    node _GEN_64 = validif(_T_14, writeCounters_4) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_65 = validif(_T_14, clock) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_66 = mux(_T_14, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/aeq.scala 36:40 38:23 23:30]
    node _GEN_67 = validif(_T_14, UInt<1>("h1")) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_68 = validif(_T_14, lastData_4) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_69 = validif(_T_13, writeCounters_4) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_70 = validif(_T_13, clock) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_71 = mux(_T_13, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/aeq.scala 32:47 34:21 23:30]
    node _GEN_72 = validif(_T_13, UInt<1>("h1")) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_73 = validif(_T_13, data_4) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_74 = mux(_T_13, _writeCounters_4_T_1, writeCounters_4) @[src/test/scala/aeq.scala 32:47 35:24 24:30]
    node _GEN_75 = validif(_T_13, _GEN_64) @[src/test/scala/aeq.scala 32:47]
    node _GEN_76 = validif(_T_13, _GEN_65) @[src/test/scala/aeq.scala 32:47]
    node _GEN_77 = mux(_T_13, _GEN_66, UInt<1>("h0")) @[src/test/scala/aeq.scala 23:30 32:47]
    node _GEN_78 = validif(_T_13, _GEN_67) @[src/test/scala/aeq.scala 32:47]
    node _GEN_79 = validif(_T_13, _GEN_68) @[src/test/scala/aeq.scala 32:47]
    node _T_15 = eq(io_readEnable, UInt<1>("h0")) @[src/test/scala/aeq.scala 32:10]
    node _T_16 = and(_T_15, io_writeEnable_5) @[src/test/scala/aeq.scala 32:25]
    node data_hi_5 = cat(UInt<1>("h0"), io_writeData_5) @[src/test/scala/aeq.scala 33:21]
    node data_5 = cat(data_hi_5, UInt<1>("h1")) @[src/test/scala/aeq.scala 33:21]
    node _writeCounters_5_T = add(writeCounters_5, UInt<1>("h1")) @[src/test/scala/aeq.scala 35:44]
    node _writeCounters_5_T_1 = tail(_writeCounters_5_T, 1) @[src/test/scala/aeq.scala 35:44]
    node _T_17 = eq(writeCounters_5, UInt<8>("hff")) @[src/test/scala/aeq.scala 36:29]
    node lastData_hi_5 = cat(UInt<1>("h1"), io_writeData_5) @[src/test/scala/aeq.scala 37:27]
    node lastData_5 = cat(lastData_hi_5, UInt<1>("h1")) @[src/test/scala/aeq.scala 37:27]
    node _GEN_80 = validif(_T_17, writeCounters_5) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_81 = validif(_T_17, clock) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_82 = mux(_T_17, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/aeq.scala 36:40 38:23 23:30]
    node _GEN_83 = validif(_T_17, UInt<1>("h1")) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_84 = validif(_T_17, lastData_5) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_85 = validif(_T_16, writeCounters_5) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_86 = validif(_T_16, clock) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_87 = mux(_T_16, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/aeq.scala 32:47 34:21 23:30]
    node _GEN_88 = validif(_T_16, UInt<1>("h1")) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_89 = validif(_T_16, data_5) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_90 = mux(_T_16, _writeCounters_5_T_1, writeCounters_5) @[src/test/scala/aeq.scala 32:47 35:24 24:30]
    node _GEN_91 = validif(_T_16, _GEN_80) @[src/test/scala/aeq.scala 32:47]
    node _GEN_92 = validif(_T_16, _GEN_81) @[src/test/scala/aeq.scala 32:47]
    node _GEN_93 = mux(_T_16, _GEN_82, UInt<1>("h0")) @[src/test/scala/aeq.scala 23:30 32:47]
    node _GEN_94 = validif(_T_16, _GEN_83) @[src/test/scala/aeq.scala 32:47]
    node _GEN_95 = validif(_T_16, _GEN_84) @[src/test/scala/aeq.scala 32:47]
    node _T_18 = eq(io_readEnable, UInt<1>("h0")) @[src/test/scala/aeq.scala 32:10]
    node _T_19 = and(_T_18, io_writeEnable_6) @[src/test/scala/aeq.scala 32:25]
    node data_hi_6 = cat(UInt<1>("h0"), io_writeData_6) @[src/test/scala/aeq.scala 33:21]
    node data_6 = cat(data_hi_6, UInt<1>("h1")) @[src/test/scala/aeq.scala 33:21]
    node _writeCounters_6_T = add(writeCounters_6, UInt<1>("h1")) @[src/test/scala/aeq.scala 35:44]
    node _writeCounters_6_T_1 = tail(_writeCounters_6_T, 1) @[src/test/scala/aeq.scala 35:44]
    node _T_20 = eq(writeCounters_6, UInt<8>("hff")) @[src/test/scala/aeq.scala 36:29]
    node lastData_hi_6 = cat(UInt<1>("h1"), io_writeData_6) @[src/test/scala/aeq.scala 37:27]
    node lastData_6 = cat(lastData_hi_6, UInt<1>("h1")) @[src/test/scala/aeq.scala 37:27]
    node _GEN_96 = validif(_T_20, writeCounters_6) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_97 = validif(_T_20, clock) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_98 = mux(_T_20, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/aeq.scala 36:40 38:23 23:30]
    node _GEN_99 = validif(_T_20, UInt<1>("h1")) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_100 = validif(_T_20, lastData_6) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_101 = validif(_T_19, writeCounters_6) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_102 = validif(_T_19, clock) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_103 = mux(_T_19, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/aeq.scala 32:47 34:21 23:30]
    node _GEN_104 = validif(_T_19, UInt<1>("h1")) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_105 = validif(_T_19, data_6) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_106 = mux(_T_19, _writeCounters_6_T_1, writeCounters_6) @[src/test/scala/aeq.scala 32:47 35:24 24:30]
    node _GEN_107 = validif(_T_19, _GEN_96) @[src/test/scala/aeq.scala 32:47]
    node _GEN_108 = validif(_T_19, _GEN_97) @[src/test/scala/aeq.scala 32:47]
    node _GEN_109 = mux(_T_19, _GEN_98, UInt<1>("h0")) @[src/test/scala/aeq.scala 23:30 32:47]
    node _GEN_110 = validif(_T_19, _GEN_99) @[src/test/scala/aeq.scala 32:47]
    node _GEN_111 = validif(_T_19, _GEN_100) @[src/test/scala/aeq.scala 32:47]
    node _T_21 = eq(io_readEnable, UInt<1>("h0")) @[src/test/scala/aeq.scala 32:10]
    node _T_22 = and(_T_21, io_writeEnable_7) @[src/test/scala/aeq.scala 32:25]
    node data_hi_7 = cat(UInt<1>("h0"), io_writeData_7) @[src/test/scala/aeq.scala 33:21]
    node data_7 = cat(data_hi_7, UInt<1>("h1")) @[src/test/scala/aeq.scala 33:21]
    node _writeCounters_7_T = add(writeCounters_7, UInt<1>("h1")) @[src/test/scala/aeq.scala 35:44]
    node _writeCounters_7_T_1 = tail(_writeCounters_7_T, 1) @[src/test/scala/aeq.scala 35:44]
    node _T_23 = eq(writeCounters_7, UInt<8>("hff")) @[src/test/scala/aeq.scala 36:29]
    node lastData_hi_7 = cat(UInt<1>("h1"), io_writeData_7) @[src/test/scala/aeq.scala 37:27]
    node lastData_7 = cat(lastData_hi_7, UInt<1>("h1")) @[src/test/scala/aeq.scala 37:27]
    node _GEN_112 = validif(_T_23, writeCounters_7) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_113 = validif(_T_23, clock) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_114 = mux(_T_23, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/aeq.scala 36:40 38:23 23:30]
    node _GEN_115 = validif(_T_23, UInt<1>("h1")) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_116 = validif(_T_23, lastData_7) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_117 = validif(_T_22, writeCounters_7) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_118 = validif(_T_22, clock) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_119 = mux(_T_22, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/aeq.scala 32:47 34:21 23:30]
    node _GEN_120 = validif(_T_22, UInt<1>("h1")) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_121 = validif(_T_22, data_7) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_122 = mux(_T_22, _writeCounters_7_T_1, writeCounters_7) @[src/test/scala/aeq.scala 32:47 35:24 24:30]
    node _GEN_123 = validif(_T_22, _GEN_112) @[src/test/scala/aeq.scala 32:47]
    node _GEN_124 = validif(_T_22, _GEN_113) @[src/test/scala/aeq.scala 32:47]
    node _GEN_125 = mux(_T_22, _GEN_114, UInt<1>("h0")) @[src/test/scala/aeq.scala 23:30 32:47]
    node _GEN_126 = validif(_T_22, _GEN_115) @[src/test/scala/aeq.scala 32:47]
    node _GEN_127 = validif(_T_22, _GEN_116) @[src/test/scala/aeq.scala 32:47]
    node _T_24 = eq(io_readEnable, UInt<1>("h0")) @[src/test/scala/aeq.scala 32:10]
    node _T_25 = and(_T_24, io_writeEnable_8) @[src/test/scala/aeq.scala 32:25]
    node data_hi_8 = cat(UInt<1>("h0"), io_writeData_8) @[src/test/scala/aeq.scala 33:21]
    node data_8 = cat(data_hi_8, UInt<1>("h1")) @[src/test/scala/aeq.scala 33:21]
    node _writeCounters_8_T = add(writeCounters_8, UInt<1>("h1")) @[src/test/scala/aeq.scala 35:44]
    node _writeCounters_8_T_1 = tail(_writeCounters_8_T, 1) @[src/test/scala/aeq.scala 35:44]
    node _T_26 = eq(writeCounters_8, UInt<8>("hff")) @[src/test/scala/aeq.scala 36:29]
    node lastData_hi_8 = cat(UInt<1>("h1"), io_writeData_8) @[src/test/scala/aeq.scala 37:27]
    node lastData_8 = cat(lastData_hi_8, UInt<1>("h1")) @[src/test/scala/aeq.scala 37:27]
    node _GEN_128 = validif(_T_26, writeCounters_8) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_129 = validif(_T_26, clock) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_130 = mux(_T_26, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/aeq.scala 36:40 38:23 23:30]
    node _GEN_131 = validif(_T_26, UInt<1>("h1")) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_132 = validif(_T_26, lastData_8) @[src/test/scala/aeq.scala 36:40 38:23]
    node _GEN_133 = validif(_T_25, writeCounters_8) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_134 = validif(_T_25, clock) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_135 = mux(_T_25, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/aeq.scala 32:47 34:21 23:30]
    node _GEN_136 = validif(_T_25, UInt<1>("h1")) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_137 = validif(_T_25, data_8) @[src/test/scala/aeq.scala 32:47 34:21]
    node _GEN_138 = mux(_T_25, _writeCounters_8_T_1, writeCounters_8) @[src/test/scala/aeq.scala 32:47 35:24 24:30]
    node _GEN_139 = validif(_T_25, _GEN_128) @[src/test/scala/aeq.scala 32:47]
    node _GEN_140 = validif(_T_25, _GEN_129) @[src/test/scala/aeq.scala 32:47]
    node _GEN_141 = mux(_T_25, _GEN_130, UInt<1>("h0")) @[src/test/scala/aeq.scala 23:30 32:47]
    node _GEN_142 = validif(_T_25, _GEN_131) @[src/test/scala/aeq.scala 32:47]
    node _GEN_143 = validif(_T_25, _GEN_132) @[src/test/scala/aeq.scala 32:47]
    node _readCounter_T = add(readCounter, UInt<1>("h1")) @[src/test/scala/aeq.scala 47:32]
    node _readCounter_T_1 = tail(_readCounter_T, 1) @[src/test/scala/aeq.scala 47:32]
    node _T_27 = eq(readCounter, UInt<8>("hff")) @[src/test/scala/aeq.scala 48:22]
    node _columnSelectCounter_T = add(columnSelectCounter, UInt<1>("h1")) @[src/test/scala/aeq.scala 49:50]
    node _columnSelectCounter_T_1 = tail(_columnSelectCounter_T, 1) @[src/test/scala/aeq.scala 49:50]
    node _T_28 = eq(columnSelectCounter, UInt<4>("h8")) @[src/test/scala/aeq.scala 50:32]
    node _GEN_144 = mux(_T_28, UInt<1>("h0"), _columnSelectCounter_T_1) @[src/test/scala/aeq.scala 49:27 50:41 51:29]
    node _GEN_145 = mux(_T_27, _GEN_144, columnSelectCounter) @[src/test/scala/aeq.scala 48:33 26:36]
    node _GEN_146 = validif(io_readEnable, readCounter) @[src/test/scala/aeq.scala 42:23 44:32]
    node _GEN_147 = validif(io_readEnable, clock) @[src/test/scala/aeq.scala 42:23 44:32]
    node _GEN_148 = mux(io_readEnable, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/aeq.scala 42:23 23:30 44:32]
    node _GEN_149 = validif(io_readEnable, brams_0.data1.data) @[src/test/scala/aeq.scala 42:23 45:22]
    node _GEN_150 = validif(io_readEnable, brams_1.data1_1.data) @[src/test/scala/aeq.scala 42:23 45:22]
    node _GEN_151 = validif(io_readEnable, brams_2.data1_2.data) @[src/test/scala/aeq.scala 42:23 45:22]
    node _GEN_152 = validif(io_readEnable, brams_3.data1_3.data) @[src/test/scala/aeq.scala 42:23 45:22]
    node _GEN_153 = validif(io_readEnable, brams_4.data1_4.data) @[src/test/scala/aeq.scala 42:23 45:22]
    node _GEN_154 = validif(io_readEnable, brams_5.data1_5.data) @[src/test/scala/aeq.scala 42:23 45:22]
    node _GEN_155 = validif(io_readEnable, brams_6.data1_6.data) @[src/test/scala/aeq.scala 42:23 45:22]
    node _GEN_156 = validif(io_readEnable, brams_7.data1_7.data) @[src/test/scala/aeq.scala 42:23 45:22]
    node _GEN_157 = validif(io_readEnable, brams_8.data1_8.data) @[src/test/scala/aeq.scala 42:23 45:22]
    node _GEN_158 = mux(io_readEnable, _readCounter_T_1, readCounter) @[src/test/scala/aeq.scala 42:23 47:17 25:28]
    node _GEN_159 = mux(io_readEnable, _GEN_145, columnSelectCounter) @[src/test/scala/aeq.scala 42:23 26:36]
    node _writeCounters_WIRE_0 = UInt<8>("h0") @[src/test/scala/aeq.scala 24:{38,38}]
    node _writeCounters_WIRE_1 = UInt<8>("h0") @[src/test/scala/aeq.scala 24:{38,38}]
    node _writeCounters_WIRE_2 = UInt<8>("h0") @[src/test/scala/aeq.scala 24:{38,38}]
    node _writeCounters_WIRE_3 = UInt<8>("h0") @[src/test/scala/aeq.scala 24:{38,38}]
    node _writeCounters_WIRE_4 = UInt<8>("h0") @[src/test/scala/aeq.scala 24:{38,38}]
    node _writeCounters_WIRE_5 = UInt<8>("h0") @[src/test/scala/aeq.scala 24:{38,38}]
    node _writeCounters_WIRE_6 = UInt<8>("h0") @[src/test/scala/aeq.scala 24:{38,38}]
    node _writeCounters_WIRE_7 = UInt<8>("h0") @[src/test/scala/aeq.scala 24:{38,38}]
    node _writeCounters_WIRE_8 = UInt<8>("h0") @[src/test/scala/aeq.scala 24:{38,38}]
    io_readData_0 <= _GEN_149
    io_readData_1 <= _GEN_150
    io_readData_2 <= _GEN_151
    io_readData_3 <= _GEN_152
    io_readData_4 <= _GEN_153
    io_readData_5 <= _GEN_154
    io_readData_6 <= _GEN_155
    io_readData_7 <= _GEN_156
    io_readData_8 <= _GEN_157
    brams_0.data1.addr <= _GEN_146
    brams_0.data1.en <= _GEN_148
    brams_0.data1.clk <= _GEN_147
    brams_0.MPORT.addr <= _GEN_5
    brams_0.MPORT.en <= _GEN_7
    brams_0.MPORT.clk <= _GEN_6
    brams_0.MPORT.data <= _GEN_9
    brams_0.MPORT.mask <= _GEN_8
    brams_0.MPORT_1.addr <= _GEN_11
    brams_0.MPORT_1.en <= _GEN_13
    brams_0.MPORT_1.clk <= _GEN_12
    brams_0.MPORT_1.data <= _GEN_15
    brams_0.MPORT_1.mask <= _GEN_14
    brams_1.data1_1.addr <= _GEN_146
    brams_1.data1_1.en <= _GEN_148
    brams_1.data1_1.clk <= _GEN_147
    brams_1.MPORT_2.addr <= _GEN_21
    brams_1.MPORT_2.en <= _GEN_23
    brams_1.MPORT_2.clk <= _GEN_22
    brams_1.MPORT_2.data <= _GEN_25
    brams_1.MPORT_2.mask <= _GEN_24
    brams_1.MPORT_3.addr <= _GEN_27
    brams_1.MPORT_3.en <= _GEN_29
    brams_1.MPORT_3.clk <= _GEN_28
    brams_1.MPORT_3.data <= _GEN_31
    brams_1.MPORT_3.mask <= _GEN_30
    brams_2.data1_2.addr <= _GEN_146
    brams_2.data1_2.en <= _GEN_148
    brams_2.data1_2.clk <= _GEN_147
    brams_2.MPORT_4.addr <= _GEN_37
    brams_2.MPORT_4.en <= _GEN_39
    brams_2.MPORT_4.clk <= _GEN_38
    brams_2.MPORT_4.data <= _GEN_41
    brams_2.MPORT_4.mask <= _GEN_40
    brams_2.MPORT_5.addr <= _GEN_43
    brams_2.MPORT_5.en <= _GEN_45
    brams_2.MPORT_5.clk <= _GEN_44
    brams_2.MPORT_5.data <= _GEN_47
    brams_2.MPORT_5.mask <= _GEN_46
    brams_3.data1_3.addr <= _GEN_146
    brams_3.data1_3.en <= _GEN_148
    brams_3.data1_3.clk <= _GEN_147
    brams_3.MPORT_6.addr <= _GEN_53
    brams_3.MPORT_6.en <= _GEN_55
    brams_3.MPORT_6.clk <= _GEN_54
    brams_3.MPORT_6.data <= _GEN_57
    brams_3.MPORT_6.mask <= _GEN_56
    brams_3.MPORT_7.addr <= _GEN_59
    brams_3.MPORT_7.en <= _GEN_61
    brams_3.MPORT_7.clk <= _GEN_60
    brams_3.MPORT_7.data <= _GEN_63
    brams_3.MPORT_7.mask <= _GEN_62
    brams_4.data1_4.addr <= _GEN_146
    brams_4.data1_4.en <= _GEN_148
    brams_4.data1_4.clk <= _GEN_147
    brams_4.MPORT_8.addr <= _GEN_69
    brams_4.MPORT_8.en <= _GEN_71
    brams_4.MPORT_8.clk <= _GEN_70
    brams_4.MPORT_8.data <= _GEN_73
    brams_4.MPORT_8.mask <= _GEN_72
    brams_4.MPORT_9.addr <= _GEN_75
    brams_4.MPORT_9.en <= _GEN_77
    brams_4.MPORT_9.clk <= _GEN_76
    brams_4.MPORT_9.data <= _GEN_79
    brams_4.MPORT_9.mask <= _GEN_78
    brams_5.data1_5.addr <= _GEN_146
    brams_5.data1_5.en <= _GEN_148
    brams_5.data1_5.clk <= _GEN_147
    brams_5.MPORT_10.addr <= _GEN_85
    brams_5.MPORT_10.en <= _GEN_87
    brams_5.MPORT_10.clk <= _GEN_86
    brams_5.MPORT_10.data <= _GEN_89
    brams_5.MPORT_10.mask <= _GEN_88
    brams_5.MPORT_11.addr <= _GEN_91
    brams_5.MPORT_11.en <= _GEN_93
    brams_5.MPORT_11.clk <= _GEN_92
    brams_5.MPORT_11.data <= _GEN_95
    brams_5.MPORT_11.mask <= _GEN_94
    brams_6.data1_6.addr <= _GEN_146
    brams_6.data1_6.en <= _GEN_148
    brams_6.data1_6.clk <= _GEN_147
    brams_6.MPORT_12.addr <= _GEN_101
    brams_6.MPORT_12.en <= _GEN_103
    brams_6.MPORT_12.clk <= _GEN_102
    brams_6.MPORT_12.data <= _GEN_105
    brams_6.MPORT_12.mask <= _GEN_104
    brams_6.MPORT_13.addr <= _GEN_107
    brams_6.MPORT_13.en <= _GEN_109
    brams_6.MPORT_13.clk <= _GEN_108
    brams_6.MPORT_13.data <= _GEN_111
    brams_6.MPORT_13.mask <= _GEN_110
    brams_7.data1_7.addr <= _GEN_146
    brams_7.data1_7.en <= _GEN_148
    brams_7.data1_7.clk <= _GEN_147
    brams_7.MPORT_14.addr <= _GEN_117
    brams_7.MPORT_14.en <= _GEN_119
    brams_7.MPORT_14.clk <= _GEN_118
    brams_7.MPORT_14.data <= _GEN_121
    brams_7.MPORT_14.mask <= _GEN_120
    brams_7.MPORT_15.addr <= _GEN_123
    brams_7.MPORT_15.en <= _GEN_125
    brams_7.MPORT_15.clk <= _GEN_124
    brams_7.MPORT_15.data <= _GEN_127
    brams_7.MPORT_15.mask <= _GEN_126
    brams_8.data1_8.addr <= _GEN_146
    brams_8.data1_8.en <= _GEN_148
    brams_8.data1_8.clk <= _GEN_147
    brams_8.MPORT_16.addr <= _GEN_133
    brams_8.MPORT_16.en <= _GEN_135
    brams_8.MPORT_16.clk <= _GEN_134
    brams_8.MPORT_16.data <= _GEN_137
    brams_8.MPORT_16.mask <= _GEN_136
    brams_8.MPORT_17.addr <= _GEN_139
    brams_8.MPORT_17.en <= _GEN_141
    brams_8.MPORT_17.clk <= _GEN_140
    brams_8.MPORT_17.data <= _GEN_143
    brams_8.MPORT_17.mask <= _GEN_142
    writeCounters_0 <= mux(reset, _writeCounters_WIRE_0, _GEN_10) @[src/test/scala/aeq.scala 24:{30,30}]
    writeCounters_1 <= mux(reset, _writeCounters_WIRE_1, _GEN_26) @[src/test/scala/aeq.scala 24:{30,30}]
    writeCounters_2 <= mux(reset, _writeCounters_WIRE_2, _GEN_42) @[src/test/scala/aeq.scala 24:{30,30}]
    writeCounters_3 <= mux(reset, _writeCounters_WIRE_3, _GEN_58) @[src/test/scala/aeq.scala 24:{30,30}]
    writeCounters_4 <= mux(reset, _writeCounters_WIRE_4, _GEN_74) @[src/test/scala/aeq.scala 24:{30,30}]
    writeCounters_5 <= mux(reset, _writeCounters_WIRE_5, _GEN_90) @[src/test/scala/aeq.scala 24:{30,30}]
    writeCounters_6 <= mux(reset, _writeCounters_WIRE_6, _GEN_106) @[src/test/scala/aeq.scala 24:{30,30}]
    writeCounters_7 <= mux(reset, _writeCounters_WIRE_7, _GEN_122) @[src/test/scala/aeq.scala 24:{30,30}]
    writeCounters_8 <= mux(reset, _writeCounters_WIRE_8, _GEN_138) @[src/test/scala/aeq.scala 24:{30,30}]
    readCounter <= mux(reset, UInt<8>("h0"), _GEN_158) @[src/test/scala/aeq.scala 25:{28,28}]
    columnSelectCounter <= mux(reset, UInt<4>("h0"), _GEN_159) @[src/test/scala/aeq.scala 26:{36,36}]
