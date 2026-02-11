module resourcehandler(
    input [7:0] d_in,
    input reg_passthrough,
    input clk,
    input rst,
    output reg [7:0] reg_in
);

always @(posedge clk or posedge rst) begin
    if (rst) begin
        reg_in <= 8'h00;
    end else if (reg_passthrough) begin
        reg_in <= d_in;
    end
end

endmodule