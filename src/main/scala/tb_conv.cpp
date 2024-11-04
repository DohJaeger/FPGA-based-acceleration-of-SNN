// Include Verilator's generated header for the conv module
#include "Vconv.h"            // Verilated model
#include "verilated.h"        // Verilator library
#include <iostream>

// Helper function to simulate clock
void toggleClock(Vconv* top, vluint64_t& main_time) {
    top->clock = !top->clock;
    top->eval();
    main_time++;
}

// Main Testbench
int main(int argc, char **argv, char **env) {
    // Initialize Verilator
    Verilated::commandArgs(argc, argv);

    // Create an instance of the Verilog module
    Vconv* top = new Vconv;

    // Initialize simulation inputs
    top->reset = 1;
    top->io_wr_enable_aeq_0 = 0;
    top->io_wr_enable_aeq_1 = 0;
    top->io_conv_enab = 0;

    vluint64_t main_time = 0;

    // Simulate reset
    toggleClock(top, main_time); // Clock cycle 1
    toggleClock(top, main_time); // Clock cycle 2
    top->reset = 0;              // De-assert reset

    // Provide some input data (input feature map AEQ)
    top->io_wr_enable_aeq_0 = 1;
    top->io_writeData_aeq_0 = 9; // Example input data
    top->io_writeData_aeq_1 = 12;
    top->io_writeData_aeq_2 = 14;
    top->io_writeData_aeq_3 = 17;
    top->io_writeData_aeq_4 = 19;
    top->io_writeData_aeq_5 = 21;
    top->io_writeData_aeq_6 = 24;
    top->io_writeData_aeq_7 = 27;
    top->io_writeData_aeq_8 = 30;

    // Provide kernel values for the convolution
    top->io_kernel_0 = 1;
    top->io_kernel_1 = 2;
    top->io_kernel_2 = 3;
    top->io_kernel_3 = 4;
    top->io_kernel_4 = 5;
    top->io_kernel_5 = 6;
    top->io_kernel_6 = 7;
    top->io_kernel_7 = 8;
    top->io_kernel_8 = 9;

    // Enable convolution
    top->io_conv_enab = 1;

    // Simulate a few cycles to let the convolution complete
    for (int i = 0; i < 20; i++) {
        toggleClock(top, main_time);
    }

    // Print the output of the convolution
    std::cout << "Convolution Output Data:" << std::endl;
    std::cout << "Read Data AEQ 0: " << top->io_readData_aeq_0 << std::endl;
    std::cout << "Read Data AEQ 1: " << top->io_readData_aeq_1 << std::endl;
    std::cout << "Read Data AEQ 2: " << top->io_readData_aeq_2 << std::endl;
    std::cout << "Read Data AEQ 3: " << top->io_readData_aeq_3 << std::endl;
    std::cout << "Read Data AEQ 4: " << top->io_readData_aeq_4 << std::endl;
    std::cout << "Read Data AEQ 5: " << top->io_readData_aeq_5 << std::endl;
    std::cout << "Read Data AEQ 6: " << top->io_readData_aeq_6 << std::endl;
    std::cout << "Read Data AEQ 7: " << top->io_readData_aeq_7 << std::endl;
    std::cout << "Read Data AEQ 8: " << top->io_readData_aeq_8 << std::endl;

    // Final cleanup
    top->final();
    delete top;
    return 0;
}
