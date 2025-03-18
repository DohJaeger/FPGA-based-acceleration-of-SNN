module axi_lite_tdp_bram #(
    parameter ADDR_WIDTH = 10  // 2^10 = 1024 words (4KB BRAM)
)(
    // AXI Lite signals
    input           s00_axi_aclk,
    input           s00_axi_aresetn,

    input  [31:0]   s00_axi_awaddr,
    input           s00_axi_awvalid,
    output          s00_axi_awready,

    input  [31:0]   s00_axi_wdata,
    input  [3:0]    s00_axi_wstrb,
    input           s00_axi_wvalid,
    output          s00_axi_wready,

    output [1:0]    s00_axi_bresp,
    output          s00_axi_bvalid,
    input           s00_axi_bready,

    input  [31:0]   s00_axi_araddr,
    input           s00_axi_arvalid,
    output          s00_axi_arready,

    output [31:0]   s00_axi_rdata,
    output [1:0]    s00_axi_rresp,
    output          s00_axi_rvalid,
    input           s00_axi_rready,

    // Control signal to switch to PL
    input           ps_done,

    // PL Interface (Port A)
    input           clka_pl,
    input           ena_pl,
    input  [3:0]    wea_pl,
    input  [ADDR_WIDTH-1:0] addra_pl,
    input  [31:0]   dia_pl,
    output [31:0]   doa_pl,

    // Optional: Port B (can be PL-only or unused)
    input           clkb_pl,
    input           enb_pl,
    input  [3:0]    web_pl,
    input  [ADDR_WIDTH-1:0] addrb_pl,
    input  [31:0]   dib_pl,
    output [31:0]   dob_pl
);

// ------------------------
// AXI Lite Interface FSM
// ------------------------
reg [1:0] axi_awready_reg, axi_wready_reg, axi_bvalid_reg, axi_arready_reg, axi_rvalid_reg;
reg [31:0] axi_rdata_reg;
reg [ADDR_WIDTH-1:0] axi_awaddr_reg, axi_araddr_reg;

assign s00_axi_awready = ~ps_done && axi_awready_reg[0];
assign s00_axi_wready  = ~ps_done && axi_wready_reg[0];
assign s00_axi_bresp   = 2'b00;  // OKAY
assign s00_axi_bvalid  = ~ps_done && axi_bvalid_reg[0];

assign s00_axi_arready = ~ps_done && axi_arready_reg[0];
assign s00_axi_rdata   = axi_rdata_reg;
assign s00_axi_rresp   = 2'b00;  // OKAY
assign s00_axi_rvalid  = ~ps_done && axi_rvalid_reg[0];

// Write address
always @(posedge s00_axi_aclk) begin
    if (!s00_axi_aresetn) begin
        axi_awready_reg <= 2'b00;
        axi_awaddr_reg  <= 0;
    end else if (~ps_done) begin
        if (!axi_awready_reg[0] && s00_axi_awvalid) begin
            axi_awready_reg[0] <= 1;
            axi_awaddr_reg <= s00_axi_awaddr[ADDR_WIDTH+1:2]; // word aligned
        end else if (s00_axi_awvalid && s00_axi_awready) begin
            axi_awready_reg[0] <= 0;
        end
    end
end

// Write data
always @(posedge s00_axi_aclk) begin
    if (!s00_axi_aresetn) begin
        axi_wready_reg <= 2'b00;
    end else if (~ps_done) begin
        if (!axi_wready_reg[0] && s00_axi_wvalid) begin
            axi_wready_reg[0] <= 1;
        end else if (s00_axi_wvalid && s00_axi_wready) begin
            axi_wready_reg[0] <= 0;
        end
    end
end

// Write response
always @(posedge s00_axi_aclk) begin
    if (!s00_axi_aresetn) begin
        axi_bvalid_reg <= 2'b00;
    end else if (~ps_done) begin
        if (axi_awready_reg[0] && axi_wready_reg[0]) begin
            axi_bvalid_reg[0] <= 1;
        end else if (s00_axi_bready && axi_bvalid_reg[0]) begin
            axi_bvalid_reg[0] <= 0;
        end
    end
end

// Read address
always @(posedge s00_axi_aclk) begin
    if (!s00_axi_aresetn) begin
        axi_arready_reg <= 2'b00;
        axi_araddr_reg  <= 0;
    end else if (~ps_done) begin
        if (!axi_arready_reg[0] && s00_axi_arvalid) begin
            axi_arready_reg[0] <= 1;
            axi_araddr_reg <= s00_axi_araddr[ADDR_WIDTH+1:2]; // word aligned
        end else if (s00_axi_arvalid && s00_axi_arready) begin
            axi_arready_reg[0] <= 0;
        end
    end
end

// Read data
always @(posedge s00_axi_aclk) begin
    if (!s00_axi_aresetn) begin
        axi_rvalid_reg <= 2'b00;
    end else if (~ps_done) begin
        if (axi_arready_reg[0]) begin
            axi_rvalid_reg[0] <= 1;
        end else if (s00_axi_rready && axi_rvalid_reg[0]) begin
            axi_rvalid_reg[0] <= 0;
        end
    end
end

// ------------------------
// BRAM - True Dual Port
// ------------------------
reg [31:0] bram [0:(1<<ADDR_WIDTH)-1];
reg [31:0] do_a_reg, do_b_reg;

assign doa_pl = do_a_reg;
assign dob_pl = do_b_reg;

// Port A Logic (AXI or PL controlled)
wire [ADDR_WIDTH-1:0] addra_mux = ps_done ? addra_pl : axi_awaddr_reg;
wire [3:0] wea_mux = ps_done ? wea_pl : (axi_awready_reg[0] && axi_wready_reg[0]) ? s00_axi_wstrb : 4'b0000;
wire ena_mux = ps_done ? ena_pl : (axi_awready_reg[0] && axi_wready_reg[0]);

always @(posedge (ps_done ? clka_pl : s00_axi_aclk)) begin
    if (ena_mux) begin
        if (wea_mux != 4'b0000) begin
            if (wea_mux[0]) bram[addra_mux][7:0]   <= ps_done ? dia_pl[7:0]   : s00_axi_wdata[7:0];
            if (wea_mux[1]) bram[addra_mux][15:8]  <= ps_done ? dia_pl[15:8]  : s00_axi_wdata[15:8];
            if (wea_mux[2]) bram[addra_mux][23:16] <= ps_done ? dia_pl[23:16] : s00_axi_wdata[23:16];
            if (wea_mux[3]) bram[addra_mux][31:24] <= ps_done ? dia_pl[31:24] : s00_axi_wdata[31:24];
        end
        do_a_reg <= bram[addra_mux];
    end
end

// Port B Logic (PL only)
always @(posedge clkb_pl) begin
    if (enb_pl) begin
        if (web_pl != 4'b0000) begin
            if (web_pl[0]) bram[addrb_pl][7:0]   <= dib_pl[7:0];
            if (web_pl[1]) bram[addrb_pl][15:8]  <= dib_pl[15:8];
            if (web_pl[2]) bram[addrb_pl][23:16] <= dib_pl[23:16];
            if (web_pl[3]) bram[addrb_pl][31:24] <= dib_pl[31:24];
        end
        do_b_reg <= bram[addrb_pl];
    end
end

// AXI Read Data from Port A
always @(posedge s00_axi_aclk) begin
    if (~ps_done && axi_arready_reg[0]) begin
        axi_rdata_reg <= bram[axi_araddr_reg];
    end
end

endmodule