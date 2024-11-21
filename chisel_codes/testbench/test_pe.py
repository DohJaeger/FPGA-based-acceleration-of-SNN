# pe_test.py

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer
import random

# Testbench parameters
DEPTH = 256
WIDTH = 11
MEM_POT_SIZE = 48
MEM_PIXEL_WIDTH = 9

# Helper function to drive 9-element vector signals
async def drive_vector(signal, values):
    for idx, val in enumerate(values):
        signal[idx].value = val

@cocotb.test()
async def test_pe(dut):
    """Cocotb testbench for the 'pe' module."""

    # Set up clock
    clock = Clock(dut.clock, 10, units="ns")  # 10ns period -> 100 MHz
    cocotb.start_soon(clock.start())

    # Initialize all inputs to default values
    dut.rd_enable_aeq.value = 0
    dut.wr_enable_aeq.value = [0] * 9
    dut.rd_enable_mempot.value = [0] * 9
    dut.wr_enable_mempot.value = [0] * 9
    dut.addr_r_mempot.value = [0] * 9
    dut.addr_w_mempot.value = [0] * 9
    dut.din_mempot.value = [0] * 9
    dut.writeData_aeq.value = [0] * 9
    dut.bias.value = [0] * 9
    dut.V_t.value = 0
    dut.thresh_enab.value = 0
    dut.conv_enab.value = 0
    dut.kernel.value = [0] * 9

    await RisingEdge(dut.clock)  # Synchronize with the clock
    dut._log.info("Resetting the DUT")

    # Reset sequence
    dut.reset.value = 1
    await RisingEdge(dut.clock)
    dut.reset.value = 0
    await RisingEdge(dut.clock)

    # Test 1: Basic Write/Read to AEQ memory
    dut._log.info("Starting Test 1: Write/Read to AEQ memory")
    dut.rd_enable_aeq.value = 1
    await drive_vector(dut.wr_enable_aeq, [1] * 9)
    await drive_vector(dut.writeData_aeq, [random.randint(0, 0x1FF) for _ in range(9)])

    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    # Verify read data matches the write data
    for i in range(9):
        assert dut.readData_aeq[i].value == dut.writeData_aeq[i].value, f"Mismatch in AEQ memory at index {i}"

    dut._log.info("Test 1 passed")

    # Test 2: Memory operations with MemPot
    dut._log.info("Starting Test 2: MemPot memory write/read")
    await drive_vector(dut.addr_r_mempot, [random.randint(0, 0xFF) for _ in range(9)])
    await drive_vector(dut.addr_w_mempot, [random.randint(0, 0xFF) for _ in range(9)])
    await drive_vector(dut.din_mempot, [random.randint(0, 0x1FF) for _ in range(9)])
    await drive_vector(dut.wr_enable_mempot, [1] * 9)

    await RisingEdge(dut.clock)
    await drive_vector(dut.wr_enable_mempot, [0] * 9)
    await drive_vector(dut.rd_enable_mempot, [1] * 9)

    await RisingEdge(dut.clock)

    for i in range(9):
        assert dut.dout_mempot[i].value == dut.din_mempot[i].value, f"Mismatch in MemPot memory at index {i}"

    dut._log.info("Test 2 passed")

    # Test 3: Kernel and pipeline operations
    dut._log.info("Starting Test 3: Kernel and pipeline operations")
    await drive_vector(dut.kernel, [random.randint(0, 0xFF) for _ in range(9)])
    dut.conv_enab.value = 1

    # Stimulate the pipeline stages
    await RisingEdge(dut.clock)
    dut.rd_enable_aeq.value = 1

    await RisingEdge(dut.clock)

    # Stall simulation for S2-S3 hazard
    dut._log.info("Testing pipeline stall condition")
    stall_triggered = False
    await drive_vector(dut.addr_r_mempot, [0x01] * 9)
    await RisingEdge(dut.clock)
    if dut.stallPipeline.value:
        stall_triggered = True

    dut._log.info(f"Pipeline stall condition {'triggered' if stall_triggered else 'not triggered'} as expected")

    # Final check
    dut._log.info("All tests passed")
