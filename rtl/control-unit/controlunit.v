module controlunit(
    input clk,
    input rst,
    input [7:0] rom_data,
    output reg pc_inc
);

    typedef enum reg [3:0] {
        S_FETCH  = 4'b0000,
        S_DECODE = 4'b0001,
        S_COLLECT_REG = 4'b0010,
        S_COLLECT_REG2 = 4'b0011,
        S_COLLECT_DATA = 4'b0100,
        S_COLLECT_DATA2 = 4'b0101
    } state_t;

    state_t state;
    reg [7:0] ir;
    reg [7:0] op;

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
                    op <= rom_data;
                    pc_inc <= 1;
                    state <= S_DECODE;

                end

                S_DECODE: begin
                    case (ir)
                        8'h00:   state <= S_FETCH;
                        8'h01:   state <= S_COLLECT_REG;
                        8'h02:   state <= S_COLLECT_REG;
                        8'h03:   state <= S_COLLECT_REG;
                        8'h04:   state <= S_COLLECT_REG;
                        8'h05:   state <= S_COLLECT_DATA;
                        default: state <= S_FETCH;
                    endcase
                end
                S_COLLECT_REG: begin
                    pc_inc <=1;
                    case(op)
                        8'h01:   state <= S_COLLECT_DATA;
                        8'h02:   state <= S_COLLECT_REG2;
                        8'h03:   state <= S_COLLECT_DATA;
                        8'h04:   state <= S_COLLECT_DATA;
                        
                        default: state <= S_FETCH;
                    endcase

                end
                S_COLLECT_REG2: begin 
                    state <= S_FETCH;
                    pc_inc <= 1;
                end
                S_COLLECT_DATA: begin
                    pc_inc <= 1;
                    case(op)
                        8'h01:   state<= S_FETCH;
                        8'h03:   state<= S_COLLECT_DATA2;
                        8'h04:   state<= S_COLLECT_DATA2;
                        8'h05:   state<= S_COLLECT_DATA2;
                        
                        
                    
                    endcase

                end
                S_COLLECT_DATA2: begin 
                    pc_inc <= 1;
                    case(op)
                        8'h05: state<= S_COLLECT_REG;
                        default: state <= S_FETCH; 
                endcase
                    
                end

            endcase
        end
    end

endmodule