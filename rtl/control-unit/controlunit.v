module controlunit(
    input clk,
    input rst,
    input [7:0] rom_data,
    output reg pc_inc
);

    typedef enum reg {
        S_FETCH  = 1'b0,
        S_DECODE = 1'b1
    } state_t;

    state_t state;
    reg [7:0] ir;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= S_FETCH;
            pc_inc <= 0;
            ir <= 8'h00;
        end else begin
            pc_inc <= 0; 

            case (state)
                S_FETCH: begin
                    ir <= rom_data;
                    pc_inc <= 1;
                    state <= S_DECODE;
                end

                S_DECODE: begin
                    case (ir)
                        8'h01:   state <= S_FETCH;
                        default: state <= S_FETCH;
                    endcase
                end
            endcase
        end
    end

endmodule