// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VTOP_H_
#define VERILATED_VTOP_H_  // guard

#include "verilated.h"
#include "svdpi.h"

class Vtop__Syms;
class Vtop___024root;

// This class is the main interface to the Verilated model
class Vtop VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vtop__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clock,0,0);
    VL_IN8(&reset,0,0);
    VL_IN8(&io_wr_enable_aeq_0,0,0);
    VL_IN8(&io_wr_enable_aeq_1,0,0);
    VL_IN8(&io_wr_enable_aeq_2,0,0);
    VL_IN8(&io_wr_enable_aeq_3,0,0);
    VL_IN8(&io_wr_enable_aeq_4,0,0);
    VL_IN8(&io_wr_enable_aeq_5,0,0);
    VL_IN8(&io_wr_enable_aeq_6,0,0);
    VL_IN8(&io_wr_enable_aeq_7,0,0);
    VL_IN8(&io_wr_enable_aeq_8,0,0);
    VL_IN8(&io_rd_enable_aeq,0,0);
    VL_IN8(&io_wr_enable_mempot_0,0,0);
    VL_IN8(&io_wr_enable_mempot_1,0,0);
    VL_IN8(&io_wr_enable_mempot_2,0,0);
    VL_IN8(&io_wr_enable_mempot_3,0,0);
    VL_IN8(&io_wr_enable_mempot_4,0,0);
    VL_IN8(&io_wr_enable_mempot_5,0,0);
    VL_IN8(&io_wr_enable_mempot_6,0,0);
    VL_IN8(&io_wr_enable_mempot_7,0,0);
    VL_IN8(&io_wr_enable_mempot_8,0,0);
    VL_IN8(&io_rd_enable_mempot_0,0,0);
    VL_IN8(&io_rd_enable_mempot_1,0,0);
    VL_IN8(&io_rd_enable_mempot_2,0,0);
    VL_IN8(&io_rd_enable_mempot_3,0,0);
    VL_IN8(&io_rd_enable_mempot_4,0,0);
    VL_IN8(&io_rd_enable_mempot_5,0,0);
    VL_IN8(&io_rd_enable_mempot_6,0,0);
    VL_IN8(&io_rd_enable_mempot_7,0,0);
    VL_IN8(&io_rd_enable_mempot_8,0,0);
    VL_IN8(&io_addr_r_mempot_0,7,0);
    VL_IN8(&io_addr_r_mempot_1,7,0);
    VL_IN8(&io_addr_r_mempot_2,7,0);
    VL_IN8(&io_addr_r_mempot_3,7,0);
    VL_IN8(&io_addr_r_mempot_4,7,0);
    VL_IN8(&io_addr_r_mempot_5,7,0);
    VL_IN8(&io_addr_r_mempot_6,7,0);
    VL_IN8(&io_addr_r_mempot_7,7,0);
    VL_IN8(&io_addr_r_mempot_8,7,0);
    VL_IN8(&io_addr_w_mempot_0,7,0);
    VL_IN8(&io_addr_w_mempot_1,7,0);
    VL_IN8(&io_addr_w_mempot_2,7,0);
    VL_IN8(&io_addr_w_mempot_3,7,0);
    VL_IN8(&io_addr_w_mempot_4,7,0);
    VL_IN8(&io_addr_w_mempot_5,7,0);
    VL_IN8(&io_addr_w_mempot_6,7,0);
    VL_IN8(&io_addr_w_mempot_7,7,0);
    VL_IN8(&io_addr_w_mempot_8,7,0);
    VL_IN8(&io_bias_0,7,0);
    VL_IN8(&io_bias_1,7,0);
    VL_IN8(&io_bias_2,7,0);
    VL_IN8(&io_bias_3,7,0);
    VL_IN8(&io_bias_4,7,0);
    VL_IN8(&io_bias_5,7,0);
    VL_IN8(&io_bias_6,7,0);
    VL_IN8(&io_bias_7,7,0);
    VL_IN8(&io_bias_8,7,0);
    VL_IN8(&io_V_t,7,0);
    VL_IN8(&io_thresh_enab,0,0);
    VL_IN8(&io_conv_enab,0,0);
    VL_IN8(&io_kernel_0,7,0);
    VL_IN8(&io_kernel_1,7,0);
    VL_IN8(&io_kernel_2,7,0);
    VL_IN8(&io_kernel_3,7,0);
    VL_IN8(&io_kernel_4,7,0);
    VL_IN8(&io_kernel_5,7,0);
    VL_IN8(&io_kernel_6,7,0);
    VL_IN8(&io_kernel_7,7,0);
    VL_IN8(&io_kernel_8,7,0);
    VL_IN16(&io_writeData_aeq_0,8,0);
    VL_IN16(&io_writeData_aeq_1,8,0);
    VL_IN16(&io_writeData_aeq_2,8,0);
    VL_IN16(&io_writeData_aeq_3,8,0);
    VL_IN16(&io_writeData_aeq_4,8,0);
    VL_IN16(&io_writeData_aeq_5,8,0);
    VL_IN16(&io_writeData_aeq_6,8,0);
    VL_IN16(&io_writeData_aeq_7,8,0);
    VL_IN16(&io_writeData_aeq_8,8,0);
    VL_OUT16(&io_readData_aeq_0,8,0);
    VL_OUT16(&io_readData_aeq_1,8,0);
    VL_OUT16(&io_readData_aeq_2,8,0);
    VL_OUT16(&io_readData_aeq_3,8,0);
    VL_OUT16(&io_readData_aeq_4,8,0);
    VL_OUT16(&io_readData_aeq_5,8,0);
    VL_OUT16(&io_readData_aeq_6,8,0);
    VL_OUT16(&io_readData_aeq_7,8,0);
    VL_OUT16(&io_readData_aeq_8,8,0);
    VL_IN16(&io_din_mempot_0,8,0);
    VL_IN16(&io_din_mempot_1,8,0);
    VL_IN16(&io_din_mempot_2,8,0);
    VL_IN16(&io_din_mempot_3,8,0);
    VL_IN16(&io_din_mempot_4,8,0);
    VL_IN16(&io_din_mempot_5,8,0);
    VL_IN16(&io_din_mempot_6,8,0);
    VL_IN16(&io_din_mempot_7,8,0);
    VL_IN16(&io_din_mempot_8,8,0);
    VL_OUT16(&io_dout_mempot_0,8,0);
    VL_OUT16(&io_dout_mempot_1,8,0);
    VL_OUT16(&io_dout_mempot_2,8,0);
    VL_OUT16(&io_dout_mempot_3,8,0);
    VL_OUT16(&io_dout_mempot_4,8,0);
    VL_OUT16(&io_dout_mempot_5,8,0);
    VL_OUT16(&io_dout_mempot_6,8,0);
    VL_OUT16(&io_dout_mempot_7,8,0);
    VL_OUT16(&io_dout_mempot_8,8,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vtop___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vtop(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vtop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vtop();
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
