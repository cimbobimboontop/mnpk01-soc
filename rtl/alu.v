module alu (
    input [7:0] a,
    input [7:0] b,
    input [3:0] op,
    output reg [7:0] out,
    output reg z_flag,
    output reg c_flag,
    output reg n_flag;
);
    reg [8:0] tmp_result;

    always @(*) begin
        tmp_result = 9'b0;
        c_flag = 1'b0;
        z_flag = 1'b0

        case (op)
        //ARITMETICS
        4'b0000: begin  //ADD
             tmp_result = a+b;
             out = tmp_result[7:0];
             c_flag =tmp_result[8];
             case(out)
             0: begin
                z_flag=1;
             end
             endcase
        end

        4'b0001: begin  //SUB
            out = a-b;
            c_flag = (a<b);
            case(out)
            0: begin
                z_flag = 1;
            end
            endcase
        end
        4'b0010: begin  //INC A
            tmp_result = a+1;
            out = tmp_result[7:0];
            c_flag = tmp_result[8];
        end
        4'b0011: begin //DEC A
            out = a-1;
            c_flag = (a<1);
            case(out)
            0: begin
                z_flag = 1;
            end
            endcase
        end
        //LOGIC
        4'b0100: begin //AND A B
            out= a&b;
        end
        4'b0101: begin //OR A B
            out= a|b;
        end
        4'b0110: begin //XOR AB
            out = a^b;
        end
        4'b0111: begin //NOT A
            out = ~a;
        end
        



        endcase
    end


    
endmodule