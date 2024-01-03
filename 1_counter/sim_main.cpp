#include<verilated.h>

#include"Vcnt.h"

int module_init(Vcnt* top){
    top->clk    = 0;
    top->rstn   = 1;
    top->eval();
    top->rstn   = 0;
    top->eval();
    top->rstn   = 1;
    top->eval();
    return 0;
}

int n_clk(Vcnt* top, int n){
    for(int i=0 ; i<n ; i++){
        top->clk = 0;
        top->eval();
        top->clk = 1;
        top->eval();
    }
    return 0;
}

int main(int argc, char** argv, char** env){
    if(0 && argc && argv && env){} // Prevent unused variable warnings

    Vcnt* top = new Vcnt;

    printf("cnt value = %d\n", top->out);
    module_init(top);
    printf("cnt value = %d\n", top->out);

    n_clk(top, 5);
    printf("cnt value = %d\n", top->out);

    n_clk(top, 15);
    printf("cnt value = %d\n", top->out);

    module_init(top);
    printf("cnt value = %d\n", top->out);

    top->final();
    delete top;

    exit(0);
}

