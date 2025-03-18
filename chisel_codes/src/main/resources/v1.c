// #include "xparameters.h"
// #include "xil_printf.h"

// // Define the base address of your AXI-Lite BRAM
// #define BRAM_BASE_ADDR 0x43C00000
// #define BRAM_SIZE 16  // Number of 32-bit words for testing

// int main() {
//     xil_printf("Starting BRAM AXI-Lite Access Test...\r\n");

//     volatile uint32_t* bram_ptr = (uint32_t*)BRAM_BASE_ADDR;

//     // Write data to BRAM
//     xil_printf("Writing data to BRAM...\r\n");
//     for (int i = 0; i < BRAM_SIZE; i++) {
//         bram_ptr[i] = 0x1000 + i;  // Example data
//     }

//     // Read back and verify
//     xil_printf("Reading data from BRAM...\r\n");
//     for (int i = 0; i < BRAM_SIZE; i++) {
//         uint32_t read_val = bram_ptr[i];
//         xil_printf("BRAM[%d] = 0x%08X\r\n", i, read_val);
//     }

//     xil_printf("BRAM AXI-Lite Access Test Complete.\r\n");
//     return 0;
// }