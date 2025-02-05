module TrueDualPortBRAM #(
    parameter DATA_WIDTH = 16,
    parameter ADDR_WIDTH = 10
)(
    input                        clka, clkb,
    input                        ena, enb,
    input                        wea, web,
    input      [ADDR_WIDTH-1:0]   addra, addrb,
    input      [DATA_WIDTH-1:0]   dia, dib,
    output reg [DATA_WIDTH-1:0]   doa, dob
);

    reg [DATA_WIDTH-1:0] ram [(2**ADDR_WIDTH)-1:0];

    always @(posedge clka) begin
        if (ena) begin
            if (wea)
                ram[addra] <= dia;
            doa <= ram[addra];
        end
    end

    always @(posedge clkb) begin
        if (enb) begin
            if (web)
                ram[addrb] <= dib;
            dob <= ram[addrb];
        end
    end

endmodule