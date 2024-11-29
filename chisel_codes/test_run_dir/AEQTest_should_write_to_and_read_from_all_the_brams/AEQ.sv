module AEQ( // @[src/test/scala/aeq.scala 15:8]
  input         clock, // @[src/test/scala/aeq.scala 15:8]
  input         reset, // @[src/test/scala/aeq.scala 15:8]
  input         io_writeEnable_0, // @[src/test/scala/aeq.scala 16:14]
  input         io_writeEnable_1, // @[src/test/scala/aeq.scala 16:14]
  input         io_writeEnable_2, // @[src/test/scala/aeq.scala 16:14]
  input         io_writeEnable_3, // @[src/test/scala/aeq.scala 16:14]
  input         io_writeEnable_4, // @[src/test/scala/aeq.scala 16:14]
  input         io_writeEnable_5, // @[src/test/scala/aeq.scala 16:14]
  input         io_writeEnable_6, // @[src/test/scala/aeq.scala 16:14]
  input         io_writeEnable_7, // @[src/test/scala/aeq.scala 16:14]
  input         io_writeEnable_8, // @[src/test/scala/aeq.scala 16:14]
  input         io_readEnable, // @[src/test/scala/aeq.scala 16:14]
  input  [8:0]  io_writeData_0, // @[src/test/scala/aeq.scala 16:14]
  input  [8:0]  io_writeData_1, // @[src/test/scala/aeq.scala 16:14]
  input  [8:0]  io_writeData_2, // @[src/test/scala/aeq.scala 16:14]
  input  [8:0]  io_writeData_3, // @[src/test/scala/aeq.scala 16:14]
  input  [8:0]  io_writeData_4, // @[src/test/scala/aeq.scala 16:14]
  input  [8:0]  io_writeData_5, // @[src/test/scala/aeq.scala 16:14]
  input  [8:0]  io_writeData_6, // @[src/test/scala/aeq.scala 16:14]
  input  [8:0]  io_writeData_7, // @[src/test/scala/aeq.scala 16:14]
  input  [8:0]  io_writeData_8, // @[src/test/scala/aeq.scala 16:14]
  output [10:0] io_readData_0, // @[src/test/scala/aeq.scala 16:14]
  output [10:0] io_readData_1, // @[src/test/scala/aeq.scala 16:14]
  output [10:0] io_readData_2, // @[src/test/scala/aeq.scala 16:14]
  output [10:0] io_readData_3, // @[src/test/scala/aeq.scala 16:14]
  output [10:0] io_readData_4, // @[src/test/scala/aeq.scala 16:14]
  output [10:0] io_readData_5, // @[src/test/scala/aeq.scala 16:14]
  output [10:0] io_readData_6, // @[src/test/scala/aeq.scala 16:14]
  output [10:0] io_readData_7, // @[src/test/scala/aeq.scala 16:14]
  output [10:0] io_readData_8 // @[src/test/scala/aeq.scala 16:14]
);
`ifdef RANDOMIZE_MEM_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
  reg [31:0] _RAND_15;
  reg [31:0] _RAND_16;
  reg [31:0] _RAND_17;
  reg [31:0] _RAND_18;
`endif // RANDOMIZE_REG_INIT
  reg [10:0] brams_0 [0:255]; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_0_data1_en; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_0_data1_addr; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_0_data1_data; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_0_MPORT_data; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_0_MPORT_addr; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_0_MPORT_mask; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_0_MPORT_en; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_0_MPORT_1_data; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_0_MPORT_1_addr; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_0_MPORT_1_mask; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_0_MPORT_1_en; // @[src/test/scala/aeq.scala 23:30]
  reg [10:0] brams_1 [0:255]; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_1_data1_1_en; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_1_data1_1_addr; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_1_data1_1_data; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_1_MPORT_2_data; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_1_MPORT_2_addr; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_1_MPORT_2_mask; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_1_MPORT_2_en; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_1_MPORT_3_data; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_1_MPORT_3_addr; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_1_MPORT_3_mask; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_1_MPORT_3_en; // @[src/test/scala/aeq.scala 23:30]
  reg [10:0] brams_2 [0:255]; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_2_data1_2_en; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_2_data1_2_addr; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_2_data1_2_data; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_2_MPORT_4_data; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_2_MPORT_4_addr; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_2_MPORT_4_mask; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_2_MPORT_4_en; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_2_MPORT_5_data; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_2_MPORT_5_addr; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_2_MPORT_5_mask; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_2_MPORT_5_en; // @[src/test/scala/aeq.scala 23:30]
  reg [10:0] brams_3 [0:255]; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_3_data1_3_en; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_3_data1_3_addr; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_3_data1_3_data; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_3_MPORT_6_data; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_3_MPORT_6_addr; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_3_MPORT_6_mask; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_3_MPORT_6_en; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_3_MPORT_7_data; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_3_MPORT_7_addr; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_3_MPORT_7_mask; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_3_MPORT_7_en; // @[src/test/scala/aeq.scala 23:30]
  reg [10:0] brams_4 [0:255]; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_4_data1_4_en; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_4_data1_4_addr; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_4_data1_4_data; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_4_MPORT_8_data; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_4_MPORT_8_addr; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_4_MPORT_8_mask; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_4_MPORT_8_en; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_4_MPORT_9_data; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_4_MPORT_9_addr; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_4_MPORT_9_mask; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_4_MPORT_9_en; // @[src/test/scala/aeq.scala 23:30]
  reg [10:0] brams_5 [0:255]; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_5_data1_5_en; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_5_data1_5_addr; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_5_data1_5_data; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_5_MPORT_10_data; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_5_MPORT_10_addr; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_5_MPORT_10_mask; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_5_MPORT_10_en; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_5_MPORT_11_data; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_5_MPORT_11_addr; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_5_MPORT_11_mask; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_5_MPORT_11_en; // @[src/test/scala/aeq.scala 23:30]
  reg [10:0] brams_6 [0:255]; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_6_data1_6_en; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_6_data1_6_addr; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_6_data1_6_data; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_6_MPORT_12_data; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_6_MPORT_12_addr; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_6_MPORT_12_mask; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_6_MPORT_12_en; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_6_MPORT_13_data; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_6_MPORT_13_addr; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_6_MPORT_13_mask; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_6_MPORT_13_en; // @[src/test/scala/aeq.scala 23:30]
  reg [10:0] brams_7 [0:255]; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_7_data1_7_en; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_7_data1_7_addr; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_7_data1_7_data; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_7_MPORT_14_data; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_7_MPORT_14_addr; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_7_MPORT_14_mask; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_7_MPORT_14_en; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_7_MPORT_15_data; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_7_MPORT_15_addr; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_7_MPORT_15_mask; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_7_MPORT_15_en; // @[src/test/scala/aeq.scala 23:30]
  reg [10:0] brams_8 [0:255]; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_8_data1_8_en; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_8_data1_8_addr; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_8_data1_8_data; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_8_MPORT_16_data; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_8_MPORT_16_addr; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_8_MPORT_16_mask; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_8_MPORT_16_en; // @[src/test/scala/aeq.scala 23:30]
  wire [10:0] brams_8_MPORT_17_data; // @[src/test/scala/aeq.scala 23:30]
  wire [7:0] brams_8_MPORT_17_addr; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_8_MPORT_17_mask; // @[src/test/scala/aeq.scala 23:30]
  wire  brams_8_MPORT_17_en; // @[src/test/scala/aeq.scala 23:30]
  reg [7:0] writeCounters_0; // @[src/test/scala/aeq.scala 24:30]
  reg [7:0] writeCounters_1; // @[src/test/scala/aeq.scala 24:30]
  reg [7:0] writeCounters_2; // @[src/test/scala/aeq.scala 24:30]
  reg [7:0] writeCounters_3; // @[src/test/scala/aeq.scala 24:30]
  reg [7:0] writeCounters_4; // @[src/test/scala/aeq.scala 24:30]
  reg [7:0] writeCounters_5; // @[src/test/scala/aeq.scala 24:30]
  reg [7:0] writeCounters_6; // @[src/test/scala/aeq.scala 24:30]
  reg [7:0] writeCounters_7; // @[src/test/scala/aeq.scala 24:30]
  reg [7:0] writeCounters_8; // @[src/test/scala/aeq.scala 24:30]
  reg [7:0] readCounter; // @[src/test/scala/aeq.scala 25:28]
  wire  _T = ~io_readEnable; // @[src/test/scala/aeq.scala 32:10]
  wire  _T_1 = ~io_readEnable & io_writeEnable_0; // @[src/test/scala/aeq.scala 32:25]
  wire [9:0] data_hi = {1'h0,io_writeData_0}; // @[src/test/scala/aeq.scala 33:21]
  wire [7:0] _writeCounters_0_T_1 = writeCounters_0 + 8'h1; // @[src/test/scala/aeq.scala 35:44]
  wire  _T_2 = writeCounters_0 == 8'hff; // @[src/test/scala/aeq.scala 36:29]
  wire [9:0] lastData_hi = {1'h1,io_writeData_0}; // @[src/test/scala/aeq.scala 37:27]
  wire  _T_4 = ~io_readEnable & io_writeEnable_1; // @[src/test/scala/aeq.scala 32:25]
  wire [9:0] data_hi_1 = {1'h0,io_writeData_1}; // @[src/test/scala/aeq.scala 33:21]
  wire [7:0] _writeCounters_1_T_1 = writeCounters_1 + 8'h1; // @[src/test/scala/aeq.scala 35:44]
  wire  _T_5 = writeCounters_1 == 8'hff; // @[src/test/scala/aeq.scala 36:29]
  wire [9:0] lastData_hi_1 = {1'h1,io_writeData_1}; // @[src/test/scala/aeq.scala 37:27]
  wire  _T_7 = ~io_readEnable & io_writeEnable_2; // @[src/test/scala/aeq.scala 32:25]
  wire [9:0] data_hi_2 = {1'h0,io_writeData_2}; // @[src/test/scala/aeq.scala 33:21]
  wire [7:0] _writeCounters_2_T_1 = writeCounters_2 + 8'h1; // @[src/test/scala/aeq.scala 35:44]
  wire  _T_8 = writeCounters_2 == 8'hff; // @[src/test/scala/aeq.scala 36:29]
  wire [9:0] lastData_hi_2 = {1'h1,io_writeData_2}; // @[src/test/scala/aeq.scala 37:27]
  wire  _T_10 = ~io_readEnable & io_writeEnable_3; // @[src/test/scala/aeq.scala 32:25]
  wire [9:0] data_hi_3 = {1'h0,io_writeData_3}; // @[src/test/scala/aeq.scala 33:21]
  wire [7:0] _writeCounters_3_T_1 = writeCounters_3 + 8'h1; // @[src/test/scala/aeq.scala 35:44]
  wire  _T_11 = writeCounters_3 == 8'hff; // @[src/test/scala/aeq.scala 36:29]
  wire [9:0] lastData_hi_3 = {1'h1,io_writeData_3}; // @[src/test/scala/aeq.scala 37:27]
  wire  _T_13 = ~io_readEnable & io_writeEnable_4; // @[src/test/scala/aeq.scala 32:25]
  wire [9:0] data_hi_4 = {1'h0,io_writeData_4}; // @[src/test/scala/aeq.scala 33:21]
  wire [7:0] _writeCounters_4_T_1 = writeCounters_4 + 8'h1; // @[src/test/scala/aeq.scala 35:44]
  wire  _T_14 = writeCounters_4 == 8'hff; // @[src/test/scala/aeq.scala 36:29]
  wire [9:0] lastData_hi_4 = {1'h1,io_writeData_4}; // @[src/test/scala/aeq.scala 37:27]
  wire  _T_16 = ~io_readEnable & io_writeEnable_5; // @[src/test/scala/aeq.scala 32:25]
  wire [9:0] data_hi_5 = {1'h0,io_writeData_5}; // @[src/test/scala/aeq.scala 33:21]
  wire [7:0] _writeCounters_5_T_1 = writeCounters_5 + 8'h1; // @[src/test/scala/aeq.scala 35:44]
  wire  _T_17 = writeCounters_5 == 8'hff; // @[src/test/scala/aeq.scala 36:29]
  wire [9:0] lastData_hi_5 = {1'h1,io_writeData_5}; // @[src/test/scala/aeq.scala 37:27]
  wire  _T_19 = ~io_readEnable & io_writeEnable_6; // @[src/test/scala/aeq.scala 32:25]
  wire [9:0] data_hi_6 = {1'h0,io_writeData_6}; // @[src/test/scala/aeq.scala 33:21]
  wire [7:0] _writeCounters_6_T_1 = writeCounters_6 + 8'h1; // @[src/test/scala/aeq.scala 35:44]
  wire  _T_20 = writeCounters_6 == 8'hff; // @[src/test/scala/aeq.scala 36:29]
  wire [9:0] lastData_hi_6 = {1'h1,io_writeData_6}; // @[src/test/scala/aeq.scala 37:27]
  wire  _T_22 = ~io_readEnable & io_writeEnable_7; // @[src/test/scala/aeq.scala 32:25]
  wire [9:0] data_hi_7 = {1'h0,io_writeData_7}; // @[src/test/scala/aeq.scala 33:21]
  wire [7:0] _writeCounters_7_T_1 = writeCounters_7 + 8'h1; // @[src/test/scala/aeq.scala 35:44]
  wire  _T_23 = writeCounters_7 == 8'hff; // @[src/test/scala/aeq.scala 36:29]
  wire [9:0] lastData_hi_7 = {1'h1,io_writeData_7}; // @[src/test/scala/aeq.scala 37:27]
  wire  _T_25 = ~io_readEnable & io_writeEnable_8; // @[src/test/scala/aeq.scala 32:25]
  wire [9:0] data_hi_8 = {1'h0,io_writeData_8}; // @[src/test/scala/aeq.scala 33:21]
  wire [7:0] _writeCounters_8_T_1 = writeCounters_8 + 8'h1; // @[src/test/scala/aeq.scala 35:44]
  wire  _T_26 = writeCounters_8 == 8'hff; // @[src/test/scala/aeq.scala 36:29]
  wire [9:0] lastData_hi_8 = {1'h1,io_writeData_8}; // @[src/test/scala/aeq.scala 37:27]
  wire [7:0] _readCounter_T_1 = readCounter + 8'h1; // @[src/test/scala/aeq.scala 47:32]
  assign brams_0_data1_en = io_readEnable;
  assign brams_0_data1_addr = readCounter;
  assign brams_0_data1_data = brams_0[brams_0_data1_addr]; // @[src/test/scala/aeq.scala 23:30]
  assign brams_0_MPORT_data = {data_hi,1'h1};
  assign brams_0_MPORT_addr = writeCounters_0;
  assign brams_0_MPORT_mask = 1'h1;
  assign brams_0_MPORT_en = _T & io_writeEnable_0;
  assign brams_0_MPORT_1_data = {lastData_hi,1'h1};
  assign brams_0_MPORT_1_addr = writeCounters_0;
  assign brams_0_MPORT_1_mask = 1'h1;
  assign brams_0_MPORT_1_en = _T_1 & _T_2;
  assign brams_1_data1_1_en = io_readEnable;
  assign brams_1_data1_1_addr = readCounter;
  assign brams_1_data1_1_data = brams_1[brams_1_data1_1_addr]; // @[src/test/scala/aeq.scala 23:30]
  assign brams_1_MPORT_2_data = {data_hi_1,1'h1};
  assign brams_1_MPORT_2_addr = writeCounters_1;
  assign brams_1_MPORT_2_mask = 1'h1;
  assign brams_1_MPORT_2_en = _T & io_writeEnable_1;
  assign brams_1_MPORT_3_data = {lastData_hi_1,1'h1};
  assign brams_1_MPORT_3_addr = writeCounters_1;
  assign brams_1_MPORT_3_mask = 1'h1;
  assign brams_1_MPORT_3_en = _T_4 & _T_5;
  assign brams_2_data1_2_en = io_readEnable;
  assign brams_2_data1_2_addr = readCounter;
  assign brams_2_data1_2_data = brams_2[brams_2_data1_2_addr]; // @[src/test/scala/aeq.scala 23:30]
  assign brams_2_MPORT_4_data = {data_hi_2,1'h1};
  assign brams_2_MPORT_4_addr = writeCounters_2;
  assign brams_2_MPORT_4_mask = 1'h1;
  assign brams_2_MPORT_4_en = _T & io_writeEnable_2;
  assign brams_2_MPORT_5_data = {lastData_hi_2,1'h1};
  assign brams_2_MPORT_5_addr = writeCounters_2;
  assign brams_2_MPORT_5_mask = 1'h1;
  assign brams_2_MPORT_5_en = _T_7 & _T_8;
  assign brams_3_data1_3_en = io_readEnable;
  assign brams_3_data1_3_addr = readCounter;
  assign brams_3_data1_3_data = brams_3[brams_3_data1_3_addr]; // @[src/test/scala/aeq.scala 23:30]
  assign brams_3_MPORT_6_data = {data_hi_3,1'h1};
  assign brams_3_MPORT_6_addr = writeCounters_3;
  assign brams_3_MPORT_6_mask = 1'h1;
  assign brams_3_MPORT_6_en = _T & io_writeEnable_3;
  assign brams_3_MPORT_7_data = {lastData_hi_3,1'h1};
  assign brams_3_MPORT_7_addr = writeCounters_3;
  assign brams_3_MPORT_7_mask = 1'h1;
  assign brams_3_MPORT_7_en = _T_10 & _T_11;
  assign brams_4_data1_4_en = io_readEnable;
  assign brams_4_data1_4_addr = readCounter;
  assign brams_4_data1_4_data = brams_4[brams_4_data1_4_addr]; // @[src/test/scala/aeq.scala 23:30]
  assign brams_4_MPORT_8_data = {data_hi_4,1'h1};
  assign brams_4_MPORT_8_addr = writeCounters_4;
  assign brams_4_MPORT_8_mask = 1'h1;
  assign brams_4_MPORT_8_en = _T & io_writeEnable_4;
  assign brams_4_MPORT_9_data = {lastData_hi_4,1'h1};
  assign brams_4_MPORT_9_addr = writeCounters_4;
  assign brams_4_MPORT_9_mask = 1'h1;
  assign brams_4_MPORT_9_en = _T_13 & _T_14;
  assign brams_5_data1_5_en = io_readEnable;
  assign brams_5_data1_5_addr = readCounter;
  assign brams_5_data1_5_data = brams_5[brams_5_data1_5_addr]; // @[src/test/scala/aeq.scala 23:30]
  assign brams_5_MPORT_10_data = {data_hi_5,1'h1};
  assign brams_5_MPORT_10_addr = writeCounters_5;
  assign brams_5_MPORT_10_mask = 1'h1;
  assign brams_5_MPORT_10_en = _T & io_writeEnable_5;
  assign brams_5_MPORT_11_data = {lastData_hi_5,1'h1};
  assign brams_5_MPORT_11_addr = writeCounters_5;
  assign brams_5_MPORT_11_mask = 1'h1;
  assign brams_5_MPORT_11_en = _T_16 & _T_17;
  assign brams_6_data1_6_en = io_readEnable;
  assign brams_6_data1_6_addr = readCounter;
  assign brams_6_data1_6_data = brams_6[brams_6_data1_6_addr]; // @[src/test/scala/aeq.scala 23:30]
  assign brams_6_MPORT_12_data = {data_hi_6,1'h1};
  assign brams_6_MPORT_12_addr = writeCounters_6;
  assign brams_6_MPORT_12_mask = 1'h1;
  assign brams_6_MPORT_12_en = _T & io_writeEnable_6;
  assign brams_6_MPORT_13_data = {lastData_hi_6,1'h1};
  assign brams_6_MPORT_13_addr = writeCounters_6;
  assign brams_6_MPORT_13_mask = 1'h1;
  assign brams_6_MPORT_13_en = _T_19 & _T_20;
  assign brams_7_data1_7_en = io_readEnable;
  assign brams_7_data1_7_addr = readCounter;
  assign brams_7_data1_7_data = brams_7[brams_7_data1_7_addr]; // @[src/test/scala/aeq.scala 23:30]
  assign brams_7_MPORT_14_data = {data_hi_7,1'h1};
  assign brams_7_MPORT_14_addr = writeCounters_7;
  assign brams_7_MPORT_14_mask = 1'h1;
  assign brams_7_MPORT_14_en = _T & io_writeEnable_7;
  assign brams_7_MPORT_15_data = {lastData_hi_7,1'h1};
  assign brams_7_MPORT_15_addr = writeCounters_7;
  assign brams_7_MPORT_15_mask = 1'h1;
  assign brams_7_MPORT_15_en = _T_22 & _T_23;
  assign brams_8_data1_8_en = io_readEnable;
  assign brams_8_data1_8_addr = readCounter;
  assign brams_8_data1_8_data = brams_8[brams_8_data1_8_addr]; // @[src/test/scala/aeq.scala 23:30]
  assign brams_8_MPORT_16_data = {data_hi_8,1'h1};
  assign brams_8_MPORT_16_addr = writeCounters_8;
  assign brams_8_MPORT_16_mask = 1'h1;
  assign brams_8_MPORT_16_en = _T & io_writeEnable_8;
  assign brams_8_MPORT_17_data = {lastData_hi_8,1'h1};
  assign brams_8_MPORT_17_addr = writeCounters_8;
  assign brams_8_MPORT_17_mask = 1'h1;
  assign brams_8_MPORT_17_en = _T_25 & _T_26;
  assign io_readData_0 = brams_0_data1_data; // @[src/test/scala/aeq.scala 42:23 45:22]
  assign io_readData_1 = brams_1_data1_1_data; // @[src/test/scala/aeq.scala 42:23 45:22]
  assign io_readData_2 = brams_2_data1_2_data; // @[src/test/scala/aeq.scala 42:23 45:22]
  assign io_readData_3 = brams_3_data1_3_data; // @[src/test/scala/aeq.scala 42:23 45:22]
  assign io_readData_4 = brams_4_data1_4_data; // @[src/test/scala/aeq.scala 42:23 45:22]
  assign io_readData_5 = brams_5_data1_5_data; // @[src/test/scala/aeq.scala 42:23 45:22]
  assign io_readData_6 = brams_6_data1_6_data; // @[src/test/scala/aeq.scala 42:23 45:22]
  assign io_readData_7 = brams_7_data1_7_data; // @[src/test/scala/aeq.scala 42:23 45:22]
  assign io_readData_8 = brams_8_data1_8_data; // @[src/test/scala/aeq.scala 42:23 45:22]
  always @(posedge clock) begin
    if (brams_0_MPORT_en & brams_0_MPORT_mask) begin
      brams_0[brams_0_MPORT_addr] <= brams_0_MPORT_data; // @[src/test/scala/aeq.scala 23:30]
    end
    if (brams_0_MPORT_1_en & brams_0_MPORT_1_mask) begin
      brams_0[brams_0_MPORT_1_addr] <= brams_0_MPORT_1_data; // @[src/test/scala/aeq.scala 23:30]
    end
    if (brams_1_MPORT_2_en & brams_1_MPORT_2_mask) begin
      brams_1[brams_1_MPORT_2_addr] <= brams_1_MPORT_2_data; // @[src/test/scala/aeq.scala 23:30]
    end
    if (brams_1_MPORT_3_en & brams_1_MPORT_3_mask) begin
      brams_1[brams_1_MPORT_3_addr] <= brams_1_MPORT_3_data; // @[src/test/scala/aeq.scala 23:30]
    end
    if (brams_2_MPORT_4_en & brams_2_MPORT_4_mask) begin
      brams_2[brams_2_MPORT_4_addr] <= brams_2_MPORT_4_data; // @[src/test/scala/aeq.scala 23:30]
    end
    if (brams_2_MPORT_5_en & brams_2_MPORT_5_mask) begin
      brams_2[brams_2_MPORT_5_addr] <= brams_2_MPORT_5_data; // @[src/test/scala/aeq.scala 23:30]
    end
    if (brams_3_MPORT_6_en & brams_3_MPORT_6_mask) begin
      brams_3[brams_3_MPORT_6_addr] <= brams_3_MPORT_6_data; // @[src/test/scala/aeq.scala 23:30]
    end
    if (brams_3_MPORT_7_en & brams_3_MPORT_7_mask) begin
      brams_3[brams_3_MPORT_7_addr] <= brams_3_MPORT_7_data; // @[src/test/scala/aeq.scala 23:30]
    end
    if (brams_4_MPORT_8_en & brams_4_MPORT_8_mask) begin
      brams_4[brams_4_MPORT_8_addr] <= brams_4_MPORT_8_data; // @[src/test/scala/aeq.scala 23:30]
    end
    if (brams_4_MPORT_9_en & brams_4_MPORT_9_mask) begin
      brams_4[brams_4_MPORT_9_addr] <= brams_4_MPORT_9_data; // @[src/test/scala/aeq.scala 23:30]
    end
    if (brams_5_MPORT_10_en & brams_5_MPORT_10_mask) begin
      brams_5[brams_5_MPORT_10_addr] <= brams_5_MPORT_10_data; // @[src/test/scala/aeq.scala 23:30]
    end
    if (brams_5_MPORT_11_en & brams_5_MPORT_11_mask) begin
      brams_5[brams_5_MPORT_11_addr] <= brams_5_MPORT_11_data; // @[src/test/scala/aeq.scala 23:30]
    end
    if (brams_6_MPORT_12_en & brams_6_MPORT_12_mask) begin
      brams_6[brams_6_MPORT_12_addr] <= brams_6_MPORT_12_data; // @[src/test/scala/aeq.scala 23:30]
    end
    if (brams_6_MPORT_13_en & brams_6_MPORT_13_mask) begin
      brams_6[brams_6_MPORT_13_addr] <= brams_6_MPORT_13_data; // @[src/test/scala/aeq.scala 23:30]
    end
    if (brams_7_MPORT_14_en & brams_7_MPORT_14_mask) begin
      brams_7[brams_7_MPORT_14_addr] <= brams_7_MPORT_14_data; // @[src/test/scala/aeq.scala 23:30]
    end
    if (brams_7_MPORT_15_en & brams_7_MPORT_15_mask) begin
      brams_7[brams_7_MPORT_15_addr] <= brams_7_MPORT_15_data; // @[src/test/scala/aeq.scala 23:30]
    end
    if (brams_8_MPORT_16_en & brams_8_MPORT_16_mask) begin
      brams_8[brams_8_MPORT_16_addr] <= brams_8_MPORT_16_data; // @[src/test/scala/aeq.scala 23:30]
    end
    if (brams_8_MPORT_17_en & brams_8_MPORT_17_mask) begin
      brams_8[brams_8_MPORT_17_addr] <= brams_8_MPORT_17_data; // @[src/test/scala/aeq.scala 23:30]
    end
    if (reset) begin // @[src/test/scala/aeq.scala 24:30]
      writeCounters_0 <= 8'h0; // @[src/test/scala/aeq.scala 24:30]
    end else if (~io_readEnable & io_writeEnable_0) begin // @[src/test/scala/aeq.scala 32:47]
      writeCounters_0 <= _writeCounters_0_T_1; // @[src/test/scala/aeq.scala 35:24]
    end
    if (reset) begin // @[src/test/scala/aeq.scala 24:30]
      writeCounters_1 <= 8'h0; // @[src/test/scala/aeq.scala 24:30]
    end else if (~io_readEnable & io_writeEnable_1) begin // @[src/test/scala/aeq.scala 32:47]
      writeCounters_1 <= _writeCounters_1_T_1; // @[src/test/scala/aeq.scala 35:24]
    end
    if (reset) begin // @[src/test/scala/aeq.scala 24:30]
      writeCounters_2 <= 8'h0; // @[src/test/scala/aeq.scala 24:30]
    end else if (~io_readEnable & io_writeEnable_2) begin // @[src/test/scala/aeq.scala 32:47]
      writeCounters_2 <= _writeCounters_2_T_1; // @[src/test/scala/aeq.scala 35:24]
    end
    if (reset) begin // @[src/test/scala/aeq.scala 24:30]
      writeCounters_3 <= 8'h0; // @[src/test/scala/aeq.scala 24:30]
    end else if (~io_readEnable & io_writeEnable_3) begin // @[src/test/scala/aeq.scala 32:47]
      writeCounters_3 <= _writeCounters_3_T_1; // @[src/test/scala/aeq.scala 35:24]
    end
    if (reset) begin // @[src/test/scala/aeq.scala 24:30]
      writeCounters_4 <= 8'h0; // @[src/test/scala/aeq.scala 24:30]
    end else if (~io_readEnable & io_writeEnable_4) begin // @[src/test/scala/aeq.scala 32:47]
      writeCounters_4 <= _writeCounters_4_T_1; // @[src/test/scala/aeq.scala 35:24]
    end
    if (reset) begin // @[src/test/scala/aeq.scala 24:30]
      writeCounters_5 <= 8'h0; // @[src/test/scala/aeq.scala 24:30]
    end else if (~io_readEnable & io_writeEnable_5) begin // @[src/test/scala/aeq.scala 32:47]
      writeCounters_5 <= _writeCounters_5_T_1; // @[src/test/scala/aeq.scala 35:24]
    end
    if (reset) begin // @[src/test/scala/aeq.scala 24:30]
      writeCounters_6 <= 8'h0; // @[src/test/scala/aeq.scala 24:30]
    end else if (~io_readEnable & io_writeEnable_6) begin // @[src/test/scala/aeq.scala 32:47]
      writeCounters_6 <= _writeCounters_6_T_1; // @[src/test/scala/aeq.scala 35:24]
    end
    if (reset) begin // @[src/test/scala/aeq.scala 24:30]
      writeCounters_7 <= 8'h0; // @[src/test/scala/aeq.scala 24:30]
    end else if (~io_readEnable & io_writeEnable_7) begin // @[src/test/scala/aeq.scala 32:47]
      writeCounters_7 <= _writeCounters_7_T_1; // @[src/test/scala/aeq.scala 35:24]
    end
    if (reset) begin // @[src/test/scala/aeq.scala 24:30]
      writeCounters_8 <= 8'h0; // @[src/test/scala/aeq.scala 24:30]
    end else if (~io_readEnable & io_writeEnable_8) begin // @[src/test/scala/aeq.scala 32:47]
      writeCounters_8 <= _writeCounters_8_T_1; // @[src/test/scala/aeq.scala 35:24]
    end
    if (reset) begin // @[src/test/scala/aeq.scala 25:28]
      readCounter <= 8'h0; // @[src/test/scala/aeq.scala 25:28]
    end else if (io_readEnable) begin // @[src/test/scala/aeq.scala 42:23]
      readCounter <= _readCounter_T_1; // @[src/test/scala/aeq.scala 47:17]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_MEM_INIT
  _RAND_0 = {1{`RANDOM}};
  for (initvar = 0; initvar < 256; initvar = initvar+1)
    brams_0[initvar] = _RAND_0[10:0];
  _RAND_1 = {1{`RANDOM}};
  for (initvar = 0; initvar < 256; initvar = initvar+1)
    brams_1[initvar] = _RAND_1[10:0];
  _RAND_2 = {1{`RANDOM}};
  for (initvar = 0; initvar < 256; initvar = initvar+1)
    brams_2[initvar] = _RAND_2[10:0];
  _RAND_3 = {1{`RANDOM}};
  for (initvar = 0; initvar < 256; initvar = initvar+1)
    brams_3[initvar] = _RAND_3[10:0];
  _RAND_4 = {1{`RANDOM}};
  for (initvar = 0; initvar < 256; initvar = initvar+1)
    brams_4[initvar] = _RAND_4[10:0];
  _RAND_5 = {1{`RANDOM}};
  for (initvar = 0; initvar < 256; initvar = initvar+1)
    brams_5[initvar] = _RAND_5[10:0];
  _RAND_6 = {1{`RANDOM}};
  for (initvar = 0; initvar < 256; initvar = initvar+1)
    brams_6[initvar] = _RAND_6[10:0];
  _RAND_7 = {1{`RANDOM}};
  for (initvar = 0; initvar < 256; initvar = initvar+1)
    brams_7[initvar] = _RAND_7[10:0];
  _RAND_8 = {1{`RANDOM}};
  for (initvar = 0; initvar < 256; initvar = initvar+1)
    brams_8[initvar] = _RAND_8[10:0];
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  _RAND_9 = {1{`RANDOM}};
  writeCounters_0 = _RAND_9[7:0];
  _RAND_10 = {1{`RANDOM}};
  writeCounters_1 = _RAND_10[7:0];
  _RAND_11 = {1{`RANDOM}};
  writeCounters_2 = _RAND_11[7:0];
  _RAND_12 = {1{`RANDOM}};
  writeCounters_3 = _RAND_12[7:0];
  _RAND_13 = {1{`RANDOM}};
  writeCounters_4 = _RAND_13[7:0];
  _RAND_14 = {1{`RANDOM}};
  writeCounters_5 = _RAND_14[7:0];
  _RAND_15 = {1{`RANDOM}};
  writeCounters_6 = _RAND_15[7:0];
  _RAND_16 = {1{`RANDOM}};
  writeCounters_7 = _RAND_16[7:0];
  _RAND_17 = {1{`RANDOM}};
  writeCounters_8 = _RAND_17[7:0];
  _RAND_18 = {1{`RANDOM}};
  readCounter = _RAND_18[7:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
