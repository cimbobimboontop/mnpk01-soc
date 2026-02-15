`define OP_NOP   8'h0
`define OP_MVI   8'h01
`define OP_MOV   8'h02
`define OP_MVIB  8'h03
`define OP_LOAD  8'h04
`define OP_STORE 8'h05
module controlunit{
    input [7:0] rom_data,
    input clk,
    input [3:0] extra_bytes,
    output write_reg_en,
    output [3:0] reg_addr,
    output write_temp_from_reg,
    output reg pc_inc,
    output high_b
};
reg [3:0] bytes_to_fetch;
    typedef enum reg [2:0]{
        S_FETCH = 2'b00,
        S_DECODE = 2'b01,
        S_COLLECT = 2'b10,
    } state_t;
    state_t state;
    reg [7:0] ir;
    always @(posedge clk)begin
        pc_inc = 0;
        
        case(state)
            S_FETCH: begin 
                ir <= rom_data; 
                state <= S_DECODE;
                bytes_to_fetch <= 0;
            end
            S_DECODE: begin 
                if(ir == `OP_MVI) begin
                    state <= S_COLLECT;
                    bytes_to_fetch <= 2;
                end
            end
            S_COLLECT: begin
                if(ir == 'OP_MVI && bytes_to_fetch == 2 ) begin
                    state <= S_COLLECT;
                    bytes_to_fetch <= bytes_to_fetch -1;
                    pc_inc = 1;
                    reg_addr < = rom_data[3:0];
                end
                else if(ir == `OP_MVI && bytes_to_fetch == 1) begin
                    state <= S_FETCH;
                    pc_inc <= 1;
                    write_reg_en <= 1;
                end
            end
            endcase
        
    end
    
endmodule