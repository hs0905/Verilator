#include<verilated.h>
#include"Vcnt.h"
#include"verilated_vcd_c.h"

int main(int argc, char** argv, char** env){
    if(0 && argc && argv && env){} // Prevent unused variable warnings
    Vcnt* top = new Vcnt;

    // wave dump setting code
    Verilated::traceEverOn(true);
    VerilatedVcdC* wave_fp = new VerilatedVcdC;
    int time = 0;
    top->trace(wave_fp, 999);
    printf("waveform file name is top.vcd\n");

    wave_fp->open("top.vcd");

 //test code
 //init code
 // reset operation
    top->clk = 0;
    top->rstn = 1;
    top->eval();
    wave_fp->dump(time++);

    top->rstn = 0;
    top->eval();
    wave_fp->dump(time++);

    top->rstn = 1;
    top->eval();
    wave_fp->dump(time++);
 // real operation
    while(time<150){
        top->clk = top->clk ? 0 : 1;
        top->eval();
        wave_fp->dump(time++);
    }
 // final model cleanup
    top->final();
    wave_fp->close();

    delete top;
    delete wave_fp;

    //final
    exit(0);
}
