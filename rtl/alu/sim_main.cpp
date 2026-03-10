#include <iostream>
#include <iomanip>
#include "Valu.h"
#include "verilated.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Valu* top = new Valu;

    int total_tests = 0;
    int errors = 0;


    for (int op = 0; op < 14; op++) {
        for (int a = 0; a < 256; a++) {
            for (int b = 0; b < 256; b++) {
                
                top->a = a;
                top->b = b;
                top->op = op;
                top->eval();

                int exp_out = 0;
                int exp_c = 0;
                int exp_z = 0;
                int exp_n = 0;

                
                switch (op) {
                    case 0:  exp_out = (a + b) & 0xFF; exp_c = ((a + b) > 255); break;
                    case 1:  exp_out = (a - b) & 0xFF; exp_c = (a < b); break;
                    case 2:  exp_out = (a + 1) & 0xFF; exp_c = ((a + 1) > 255); break;
                    case 3:  exp_out = (a - 1) & 0xFF; exp_c = (a < 1); break;
                    case 4:  exp_out = (a & b); break;
                    case 5:  exp_out = (a | b); break;
                    case 6:  exp_out = (a ^ b); break;
                    case 7:  exp_out = (~a) & 0xFF; break;
                    case 8:  exp_out = (a << 1) & 0xFF; exp_c = (a >> 7) & 1; break;
                    case 9:  exp_out = (a >> 1) & 0xFF; exp_c = a & 1; break;
                    case 10: exp_out = ((a << 1) | (a >> 7)) & 0xFF; exp_c = (a >> 7) & 1; break;
                    case 11: // CMP - Tvoja špeciálna logika
                        exp_out = a; 
                        exp_z = (a == b); 
                        exp_c = (a > b); 
                        exp_n = (a < b); 
                        break;
                    case 12: exp_out = a; break; // PASS_A
                    case 13: exp_out = 0; break; // CLR
                    default: exp_out = 0; break;
                }

                
                if (op != 11) {
                    exp_z = (exp_out == 0);
                    exp_n = (exp_out >> 7) & 1;
                }

                // Kontrola všetkého: OUT, Z, C, N
                bool bug = (top->out != (exp_out & 0xFF)) || 
                           (top->z_flag != exp_z) || 
                           (top->c_flag != exp_c) || 
                           (top->n_flag != exp_n);

                if (bug) {
                    errors++;
                    if (errors <= 20) {
                        std::cout << " CHYBA: OP:" << op << " A:" << a << " B:" << b 
                                  << " | RTL[OUT:" << (int)top->out << " Z:" << (int)top->z_flag << " C:" << (int)top->c_flag << " N:" << (int)top->n_flag << "]"
                                  << " | EXP[OUT:" << exp_out << " Z:" << exp_z << " C:" << exp_c << " N:" << exp_n << "]" << std::endl;
                    }
                }
                total_tests++;
            }
        }
    }

    std::cout << "\n--- REPORT ---" << std::endl;
    std::cout << "Testov celkovo: " << total_tests << std::endl;
    if (errors == 0) {
        std::cout << " STATUS: 100% SUCCESS!" << std::endl;
    } else {
        std::cout << " STATUS: Nájdených " << errors << " chýb. Skontroluj logiku vyššie." << std::endl;
    }

    delete top;
    return 0;
}