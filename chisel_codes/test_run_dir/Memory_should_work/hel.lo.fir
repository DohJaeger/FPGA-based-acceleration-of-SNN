FIRRTL version 1.2.0
circuit hel :
  module hel : @[src/test/scala/hel.scala 11:7]
    input clock : Clock @[src/test/scala/hel.scala 11:7]
    input reset : UInt<1> @[src/test/scala/hel.scala 11:7]
    input io_rdAddr : UInt<10> @[src/test/scala/hel.scala 12:16]
    output io_rdData : UInt<8> @[src/test/scala/hel.scala 12:16]
    input io_wrAddr : UInt<10> @[src/test/scala/hel.scala 12:16]
    input io_wrData : UInt<8> @[src/test/scala/hel.scala 12:16]
    input io_wrEna : UInt<1> @[src/test/scala/hel.scala 12:16]
    input io_rdEna : UInt<1> @[src/test/scala/hel.scala 12:16]

    mem mem : @[src/test/scala/hel.scala 21:26]
      data-type => UInt<8>
      depth => 1024
      read-latency => 1
      write-latency => 1
      reader => io_rdData_MPORT
      writer => MPORT
      read-under-write => undefined
    node _GEN_0 = validif(UInt<1>("h1"), io_rdAddr) @[src/test/scala/hel.scala 24:{30,30}]
    node _GEN_1 = mux(UInt<1>("h1"), UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/hel.scala 21:26 24:{30,30}]
    node _io_rdData_WIRE = _GEN_0 @[src/test/scala/hel.scala 24:30]
    node _GEN_2 = validif(UInt<1>("h1"), _io_rdData_WIRE) @[src/test/scala/hel.scala 24:{30,30}]
    node _GEN_3 = validif(UInt<1>("h1"), clock) @[src/test/scala/hel.scala 24:{30,30}]
    node _GEN_4 = mux(io_rdEna, _GEN_1, UInt<1>("h0")) @[src/test/scala/hel.scala 23:21 21:26]
    node _GEN_5 = validif(io_rdEna, _GEN_2) @[src/test/scala/hel.scala 23:21]
    node _GEN_6 = validif(io_rdEna, _GEN_3) @[src/test/scala/hel.scala 23:21]
    node _GEN_7 = validif(io_rdEna, mem.io_rdData_MPORT.data) @[src/test/scala/hel.scala 23:21 24:19]
    node _GEN_8 = validif(io_wrEna, io_wrAddr) @[src/test/scala/hel.scala 27:20 28:18]
    node _GEN_9 = validif(io_wrEna, clock) @[src/test/scala/hel.scala 27:20 28:18]
    node _GEN_10 = mux(io_wrEna, UInt<1>("h1"), UInt<1>("h0")) @[src/test/scala/hel.scala 27:20 28:18 21:26]
    node _GEN_11 = validif(io_wrEna, UInt<1>("h1")) @[src/test/scala/hel.scala 27:20 28:18]
    node _GEN_12 = validif(io_wrEna, io_wrData) @[src/test/scala/hel.scala 27:20 28:18]
    io_rdData <= _GEN_7
    mem.io_rdData_MPORT.addr <= _GEN_5
    mem.io_rdData_MPORT.en <= _GEN_4
    mem.io_rdData_MPORT.clk <= _GEN_6
    mem.MPORT.addr <= _GEN_8
    mem.MPORT.en <= _GEN_10
    mem.MPORT.clk <= _GEN_9
    mem.MPORT.data <= _GEN_12
    mem.MPORT.mask <= _GEN_11
