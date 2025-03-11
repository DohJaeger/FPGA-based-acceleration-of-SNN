module LU #(
    parameter   M_AXI_BURST_LENGTH      = 64,
    parameter   M_AXI_BURST_SIZE        = 8, //bytes
    parameter   M_AXI_ARADDR_WIDTH      = 32,
    localparam  M_AXI_ARLEN             = 8'd64,
    localparam  M_AXI_ARSIZE            = 3'b010,
    localparam  M_AXI_DATA_WIDTH        = 32,

    parameter   S_AXIS_DATA_WIDTH       = 32,
    parameter   M_AXIS_DATA_WIDTH       = 32

)(
    input wire                          axi_aclk,
    input wire                          axi_aresetn,

    //S_AXIS Input Interface
    input wire [S_AXIS_DATA_WIDTH-1:0]  s_axis_tdata,
    input wire                          s_axis_tvalid,
    output reg                          s_axis_tready,
    input wire                          s_axis_tlast,

    //M_AXIS Output Interface
    output reg [M_AXIS_DATA_WIDTH-1:0]  m_axis_tdata,
    output reg                          m_axis_tvalid,
    input wire                          m_axis_tready,
    output reg                          m_axis_tlast,
    output reg [7:0]                    m_axis_tid, 

    //M_AXI Interface to DDR 
    output reg [M_AXI_ARADDR_WIDTH-1:0] m_axi_araddr,
    output reg                          m_axi_arvalid,
    input wire                          m_axi_arready,
    output reg [7:0]                    m_axi_arlen,
    output reg [2:0]                    m_axi_arsize,
    output reg [1:0]                    m_axi_arburst,

    input wire [M_AXI_DATA_WIDTH-1:0]   m_axi_rdata,
    input wire                          m_axi_rvalid,
    output reg                          m_axi_rready,
    input wire                          m_axi_rlast,

    //CTRL Interface
    input wire                          ctrl_aresetn,
    input wire [31:0]                   ctrl_baseaddr,
    input wire [31:0]                   ctrl_addroffset                 
);


// ARSTATE MACHINE -> sends read requests to DDR
reg [1:0] axi_arstate;
localparam AXI_ARSTATE_START = 0;
localparam AXI_ARSTATE_IDLE  = 1;
localparam AXI_ARSTATE_SEND  = 2;
localparam AXI_ARSTATE_LAST  = 3;

always @(posedge axi_aclk) begin
    if(~axi_aresetn | ~ctrl_aresetn) begin
        axi_arstate <= AXI_ARSTATE_START;
        m_axi_araddr <= ctrl_baseaddr;
    end
    else begin
        case(axi_arstate)
            AXI_ARSTATE_START: begin
                if(s_axis_tvalid & m_axi_arready & s_axis_tlast)
                    axi_arstate <= AXI_ARSTATE_LAST;
                else if(s_axis_tvalid & m_axi_arready) begin
                    axi_arstate <= AXI_ARSTATE_SEND;
                    m_axi_araddr <= m_axi_araddr + ctrl_addroffset;
                end
            end
            AXI_ARSTATE_IDLE: begin
                if(s_axis_tvalid & m_axi_arready & s_axis_tlast)
                    axi_arstate <= AXI_ARSTATE_LAST;
                else if(s_axis_tvalid & m_axi_arready) begin
                    axi_arstate <= AXI_ARSTATE_SEND;
                    m_axi_araddr <= m_axi_araddr + ctrl_addroffset;
                end
            end
            AXI_ARSTATE_SEND: begin
                if(s_axis_tvalid & m_axi_arready & s_axis_tlast)
                    axi_arstate <= AXI_ARSTATE_LAST;
                else if(s_axis_tvalid & m_axi_arready) begin
                    axi_arstate <= AXI_ARSTATE_SEND;
                    m_axi_araddr <= m_axi_araddr + ctrl_addroffset;
                end
                else
                    axi_arstate <= AXI_ARSTATE_IDLE;
            end
        endcase
    end   
end

always @(*) begin
    case(axi_arstate)
        AXI_ARSTATE_START: begin
            m_axi_arvalid = s_axis_tvalid;
            m_axi_arlen = M_AXI_ARLEN;
            m_axi_arsize = M_AXI_ARSIZE;
            m_axi_arburst = 2'b01;

            s_axis_tready = m_axi_arready;
        end
        AXI_ARSTATE_IDLE: begin
            s_axis_tready = m_axi_arready;
            m_axi_arvalid = s_axis_tvalid;

        end
        AXI_ARSTATE_SEND: begin
            s_axis_tready = m_axi_arready;
            m_axi_arvalid = s_axis_tvalid;
        end
        AXI_ARSTATE_LAST: begin
            s_axis_tready = 0;
            m_axi_arvalid = 0;
        end
    endcase
end

//RSTATE MACHINE -> receives weight data from DDR
reg [2:0] axi_rstate;
localparam AXI_RSTATE_START = 0;
localparam AXI_RSTATE_IDLE  = 1;
localparam AXI_RSTATE_SEND  = 2;

always @(posedge axi_aclk) begin
    if(~axi_aresetn | ~ctrl_aresetn) begin
       axi_rstate <= AXI_RSTATE_START; 
       m_axis_tid <= 0;
    end
    else begin
        case(axi_rstate)
            AXI_RSTATE_START: begin
                if(m_axi_rvalid & m_axis_tready & m_axi_rlast) begin
                    axi_rstate <= AXI_RSTATE_SEND;
                    m_axis_tid <= m_axis_tid + 1;
                end
                else if(m_axi_rvalid & m_axis_tready) begin
                    axi_rstate <= AXI_RSTATE_SEND;
                end

            end
            AXI_RSTATE_IDLE: begin
                if(m_axi_rvalid & m_axis_tready & m_axi_rlast) begin
                    axi_rstate <= AXI_RSTATE_SEND;
                    m_axis_tid <= m_axis_tid + 1;
                end
                else if(m_axi_rvalid & m_axis_tready) 
                    axi_rstate <= AXI_RSTATE_SEND;
            end
            AXI_RSTATE_SEND: begin
                if(m_axi_rvalid & m_axis_tready & m_axi_rlast) begin
                    axi_rstate <= AXI_RSTATE_SEND;
                    m_axis_tid <= m_axis_tid + 1;
                end
                else if(m_axi_rvalid & m_axis_tready) 
                    axi_rstate <= AXI_RSTATE_SEND;
                else 
                    axi_rstate <= AXI_RSTATE_IDLE;
            end
        endcase
    end
end

always @(*) begin
    case(axi_rstate)
        AXI_RSTATE_START: begin
            m_axi_rready = 1;
            m_axis_tvalid = 0;
            m_axis_tdata = 0;
            m_axis_tdata = m_axi_rdata;
        end
        AXI_RSTATE_IDLE: begin
            m_axi_rready = m_axis_tready;
            m_axis_tvalid = m_axi_rvalid;
            m_axis_tdata = m_axi_rdata;
        end
        AXI_RSTATE_SEND: begin
            m_axi_rready = m_axis_tready;
            m_axis_tvalid = m_axi_rvalid;
            m_axis_tdata = m_axi_rdata;
        end
    endcase
end



endmodule