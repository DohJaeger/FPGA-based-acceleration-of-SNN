// Generated by CIRCT firtool-1.62.0
// Standard header to adapt well known macros for register randomization.
`ifndef RANDOMIZE
  `ifdef RANDOMIZE_MEM_INIT
    `define RANDOMIZE
  `endif // RANDOMIZE_MEM_INIT
`endif // not def RANDOMIZE

// RANDOM may be set to an expression that produces a 32-bit random unsigned value.
`ifndef RANDOM
  `define RANDOM $random
`endif // not def RANDOM

// Users can define INIT_RANDOM as general code that gets injected into the
// initializer block for modules with registers.
`ifndef INIT_RANDOM
  `define INIT_RANDOM
`endif // not def INIT_RANDOM

// If using random initialization, you can also define RANDOMIZE_DELAY to
// customize the delay used, otherwise 0.002 is used.
`ifndef RANDOMIZE_DELAY
  `define RANDOMIZE_DELAY 0.002
`endif // not def RANDOMIZE_DELAY

// Define INIT_RANDOM_PROLOG_ for use in our modules below.
`ifndef INIT_RANDOM_PROLOG_
  `ifdef RANDOMIZE
    `ifdef VERILATOR
      `define INIT_RANDOM_PROLOG_ `INIT_RANDOM
    `else  // VERILATOR
      `define INIT_RANDOM_PROLOG_ `INIT_RANDOM #`RANDOMIZE_DELAY begin end
    `endif // VERILATOR
  `else  // RANDOMIZE
    `define INIT_RANDOM_PROLOG_
  `endif // RANDOMIZE
`endif // not def INIT_RANDOM_PROLOG_

// Include register initializers in init blocks unless synthesis is set
`ifndef SYNTHESIS
  `ifndef ENABLE_INITIAL_REG_
    `define ENABLE_INITIAL_REG_
  `endif // not def ENABLE_INITIAL_REG_
`endif // not def SYNTHESIS

// Include rmemory initializers in init blocks unless synthesis is set
`ifndef SYNTHESIS
  `ifndef ENABLE_INITIAL_MEM_
    `define ENABLE_INITIAL_MEM_
  `endif // not def ENABLE_INITIAL_MEM_
`endif // not def SYNTHESIS

// VCS coverage exclude_file
module mem_128x10(	// src/main/scala/sync_mem.scala:26:23
  input  [6:0] R0_addr,
  input        R0_en,
               R0_clk,
  output [9:0] R0_data,
  input  [6:0] W0_addr,
  input        W0_en,
               W0_clk,
  input  [9:0] W0_data
);

  reg [9:0] Memory[0:127];	// src/main/scala/sync_mem.scala:26:23
  reg       _R0_en_d0;	// src/main/scala/sync_mem.scala:26:23
  reg [6:0] _R0_addr_d0;	// src/main/scala/sync_mem.scala:26:23
  always @(posedge R0_clk) begin	// src/main/scala/sync_mem.scala:26:23
    _R0_en_d0 <= R0_en;	// src/main/scala/sync_mem.scala:26:23
    _R0_addr_d0 <= R0_addr;	// src/main/scala/sync_mem.scala:26:23
  end // always @(posedge)
  always @(posedge W0_clk) begin	// src/main/scala/sync_mem.scala:26:23
    if (W0_en & 1'h1)	// src/main/scala/sync_mem.scala:26:23
      Memory[W0_addr] <= W0_data;	// src/main/scala/sync_mem.scala:26:23
  end // always @(posedge)
  `ifdef ENABLE_INITIAL_MEM_	// src/main/scala/sync_mem.scala:26:23
    `ifdef RANDOMIZE_REG_INIT	// src/main/scala/sync_mem.scala:26:23
      reg [31:0] _RANDOM;	// src/main/scala/sync_mem.scala:26:23
    `endif // RANDOMIZE_REG_INIT
    reg [31:0] _RANDOM_MEM;	// src/main/scala/sync_mem.scala:26:23
    initial begin	// src/main/scala/sync_mem.scala:26:23
      `INIT_RANDOM_PROLOG_	// src/main/scala/sync_mem.scala:26:23
      `ifdef RANDOMIZE_MEM_INIT	// src/main/scala/sync_mem.scala:26:23
        for (logic [7:0] i = 8'h0; i < 8'h80; i += 8'h1) begin
          _RANDOM_MEM = `RANDOM;	// src/main/scala/sync_mem.scala:26:23
          Memory[i[6:0]] = _RANDOM_MEM[9:0];	// src/main/scala/sync_mem.scala:26:23
        end	// src/main/scala/sync_mem.scala:26:23
      `endif // RANDOMIZE_MEM_INIT
      `ifdef RANDOMIZE_REG_INIT	// src/main/scala/sync_mem.scala:26:23
        _RANDOM = {`RANDOM};	// src/main/scala/sync_mem.scala:26:23
        _R0_en_d0 = _RANDOM[0];	// src/main/scala/sync_mem.scala:26:23
        _R0_addr_d0 = _RANDOM[7:1];	// src/main/scala/sync_mem.scala:26:23
      `endif // RANDOMIZE_REG_INIT
    end // initial
  `endif // ENABLE_INITIAL_MEM_
  assign R0_data = _R0_en_d0 ? Memory[_R0_addr_d0] : 10'bx;	// src/main/scala/sync_mem.scala:26:23
endmodule

module mem(	// src/main/scala/sync_mem.scala:17:8
  input        clock,	// src/main/scala/sync_mem.scala:17:8
               reset,	// src/main/scala/sync_mem.scala:17:8
  input  [6:0] io_rd_addr,	// src/main/scala/sync_mem.scala:18:13
  output [9:0] io_rd_data,	// src/main/scala/sync_mem.scala:18:13
  input  [6:0] io_wr_addr,	// src/main/scala/sync_mem.scala:18:13
  input  [9:0] io_wr_data,	// src/main/scala/sync_mem.scala:18:13
  input        io_wr_en,	// src/main/scala/sync_mem.scala:18:13
               io_rd_en	// src/main/scala/sync_mem.scala:18:13
);

  mem_128x10 mem_ext (	// src/main/scala/sync_mem.scala:26:23
    .R0_addr (io_rd_addr),
    .R0_en   (io_rd_en),
    .R0_clk  (clock),
    .R0_data (io_rd_data),
    .W0_addr (io_wr_addr),
    .W0_en   (io_wr_en),
    .W0_clk  (clock),
    .W0_data (io_wr_data)
  );
endmodule
