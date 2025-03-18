`timescale 1 ns / 1 ps

module AXI_LITE_BRAM #
(
    // Parameters of Axi Slave Bus Interface S00_AXI
    parameter integer C_S00_AXI_DATA_WIDTH = 32,
    parameter integer C_S00_AXI_ADDR_WIDTH = 4,
    parameter integer BRAM_DATA_WIDTH = 16,
    parameter integer BRAM_ADDR_WIDTH = 10
)
(
    // AXI Signals (PS Control)
    input wire  s00_axi_aclk,
    input wire  s00_axi_aresetn,
    input wire [C_S00_AXI_ADDR_WIDTH-1 : 0] s00_axi_awaddr,
    input wire [2 : 0] s00_axi_awprot,
    input wire  s00_axi_awvalid,
    output wire  s00_axi_awready,
    input wire [C_S00_AXI_DATA_WIDTH-1 : 0] s00_axi_wdata,
    input wire [(C_S00_AXI_DATA_WIDTH/8)-1 : 0] s00_axi_wstrb,
    input wire  s00_axi_wvalid,
    output wire  s00_axi_wready,
    output wire [1 : 0] s00_axi_bresp,
    output wire  s00_axi_bvalid,
    input wire  s00_axi_bready,
    input wire [C_S00_AXI_ADDR_WIDTH-1 : 0] s00_axi_araddr,
    input wire [2 : 0] s00_axi_arprot,
    input wire  s00_axi_arvalid,
    output wire  s00_axi_arready,
    output wire [C_S00_AXI_DATA_WIDTH-1 : 0] s00_axi_rdata,
    output wire [1 : 0] s00_axi_rresp,
    output wire  s00_axi_rvalid,
    input wire  s00_axi_rready,

    // PL Control Signals for BRAM
    input wire clka_pl, clkb_pl,    // PL clocks for BRAM
    input wire ena_pl, enb_pl,      // PL enables
    input wire wea_pl, web_pl,      // PL write enables
    input wire [BRAM_ADDR_WIDTH-1:0] addra_pl, addrb_pl, // PL addresses
    input wire [BRAM_DATA_WIDTH-1:0] dia_pl, dib_pl,     // PL data inputs
    output wire [BRAM_DATA_WIDTH-1:0] doa_pl, dob_pl,    // PL data outputs

    // PS-to-PL control signal
    input wire ps_done  // High when PS is finished writing
);

// Internal BRAM signals (muxed between AXI and PL)
wire bram_clka, bram_clkb;
wire bram_ena, bram_enb;
wire bram_wea, bram_web;
wire [BRAM_ADDR_WIDTH-1:0] bram_addra, bram_addrb;
wire [BRAM_DATA_WIDTH-1:0] bram_dia, bram_dib;
wire [BRAM_DATA_WIDTH-1:0] bram_doa, bram_dob;

// AXI Interface Instantiation
AXI_LITE_BRAM_slave_lite_v1_0_S00_AXI # ( 
    .C_S_AXI_DATA_WIDTH(C_S00_AXI_DATA_WIDTH),
    .C_S_AXI_ADDR_WIDTH(C_S00_AXI_ADDR_WIDTH)
) AXI_LITE_BRAM_slave_lite_v1_0_S00_AXI_inst (
    .S_AXI_ACLK(s00_axi_aclk),
    .S_AXI_ARESETN(s00_axi_aresetn),
    .S_AXI_AWADDR(s00_axi_awaddr),
    .S_AXI_AWPROT(s00_axi_awprot),
    .S_AXI_AWVALID(s00_axi_awvalid),
    .S_AXI_AWREADY(s00_axi_awready),
    .S_AXI_WDATA(s00_axi_wdata),
    .S_AXI_WSTRB(s00_axi_wstrb),
    .S_AXI_WVALID(s00_axi_wvalid),
    .S_AXI_WREADY(s00_axi_wready),
    .S_AXI_BRESP(s00_axi_bresp),
    .S_AXI_BVALID(s00_axi_bvalid),
    .S_AXI_BREADY(s00_axi_bready),
    .S_AXI_ARADDR(s00_axi_araddr),
    .S_AXI_ARPROT(s00_axi_arprot),
    .S_AXI_ARVALID(s00_axi_arvalid),
    .S_AXI_ARREADY(s00_axi_arready),
    .S_AXI_RDATA(s00_axi_rdata),
    .S_AXI_RRESP(s00_axi_rresp),
    .S_AXI_RVALID(s00_axi_rvalid),
    .S_AXI_RREADY(s00_axi_rready)
);

// BRAM Control Multiplexer (Switching between AXI and PL control)
assign bram_clka  = (ps_done) ? clka_pl  : s00_axi_aclk;
assign bram_clkb  = (ps_done) ? clkb_pl  : s00_axi_aclk;
assign bram_ena   = (ps_done) ? ena_pl   : 1'b1;  // Always enable during AXI access
assign bram_enb   = (ps_done) ? enb_pl   : 1'b1;
assign bram_wea   = (ps_done) ? wea_pl   : s00_axi_wvalid;
assign bram_web   = (ps_done) ? web_pl   : 1'b0;  // Only AXI writes to port A
assign bram_addra = (ps_done) ? addra_pl : s00_axi_awaddr[BRAM_ADDR_WIDTH-1:0];
assign bram_addrb = (ps_done) ? addrb_pl : s00_axi_araddr[BRAM_ADDR_WIDTH-1:0];
assign bram_dia   = (ps_done) ? dia_pl   : s00_axi_wdata[BRAM_DATA_WIDTH-1:0];
assign bram_dib   = (ps_done) ? dib_pl   : {BRAM_DATA_WIDTH{1'b0}}; // Only AXI uses Port A

// Instantiate True Dual-Port BRAM
TrueDualPortBRAM #(
    .DATA_WIDTH(BRAM_DATA_WIDTH),
    .ADDR_WIDTH(BRAM_ADDR_WIDTH)
) bram_inst (
    .clka(bram_clka), .clkb(bram_clkb),
    .ena(bram_ena), .enb(bram_enb),
    .wea(bram_wea), .web(bram_web),
    .addra(bram_addra), .addrb(bram_addrb),
    .dia(bram_dia), .dib(bram_dib),
    .doa(bram_doa), .dob(bram_dob)
);

// Output BRAM data to PL when PS is done
assign doa_pl = bram_doa;
assign dob_pl = bram_dob;

endmodule