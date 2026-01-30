`timescale 1ns / 1ps

module alu_tb();
    // Registre pre vstupy (v testbenchi sú reg, lebo im priraďujeme hodnoty)
    reg [7:0] a;
    reg [7:0] b;
    reg [3:0] op;
    
    // Drôty pre výstupy (wire, lebo ich len sledujeme)
    wire [7:0] out;
    wire z_flag;
    wire c_flag;
    wire n_flag;

    // Inštancia tvojej ALU
    alu uut (
        .a(a), 
        .b(b), 
        .op(op), 
        .out(out), 
        .z_flag(z_flag), 
        .c_flag(c_flag), 
        .n_flag(n_flag)
    );

    initial begin
        // Tieto dva riadky vytvoria súbor pre GTKWave
        $dumpfile("alu_test.vcd");
        $dumpvars(0, alu_tb);

        // --- TEST 1: ADD (10 + 5) ---
        a = 8'd10; b = 8'd5; op = 4'b0000;
        #10; // Čakaj 10ns

        // --- TEST 2: SUB (10 - 5) ---
        a = 8'd10; b = 8'd5; op = 4'b0001;
        #10;

        // --- TEST 3: ROL (Rotácia bitu 7 na pozíciu 0) ---
        a = 8'b10000001; op = 4'b1010;
        #10;

        // --- TEST 4: TVOJ ŠPECIÁLNY CMP (A < B) ---
        // Malo by zasvietiť n_flag podľa tvojej logiky
        a = 8'd20; b = 8'd50; op = 4'b1011;
        #10;

        // --- TEST 5: TVOJ ŠPECIÁLNY CMP (A > B) ---
        // Malo by zasvietiť c_flag
        a = 8'd100; b = 8'd30; op = 4'b1011;
        #10;

        // --- TEST 6: CLR (Clear) ---
        op = 4'b1101;
        #10;

        $display("Simulacia ukoncena. Otvor alu_test.vcd v GTKWave.");
        $finish;
    end
endmodule