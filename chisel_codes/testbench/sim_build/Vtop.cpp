// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtop.h"
#include "Vtop__Syms.h"
#include "verilated_dpi.h"

//============================================================
// Constructors

Vtop::Vtop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtop__Syms(contextp(), _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , io_wr_enable_aeq_0{vlSymsp->TOP.io_wr_enable_aeq_0}
    , io_wr_enable_aeq_1{vlSymsp->TOP.io_wr_enable_aeq_1}
    , io_wr_enable_aeq_2{vlSymsp->TOP.io_wr_enable_aeq_2}
    , io_wr_enable_aeq_3{vlSymsp->TOP.io_wr_enable_aeq_3}
    , io_wr_enable_aeq_4{vlSymsp->TOP.io_wr_enable_aeq_4}
    , io_wr_enable_aeq_5{vlSymsp->TOP.io_wr_enable_aeq_5}
    , io_wr_enable_aeq_6{vlSymsp->TOP.io_wr_enable_aeq_6}
    , io_wr_enable_aeq_7{vlSymsp->TOP.io_wr_enable_aeq_7}
    , io_wr_enable_aeq_8{vlSymsp->TOP.io_wr_enable_aeq_8}
    , io_rd_enable_aeq{vlSymsp->TOP.io_rd_enable_aeq}
    , io_wr_enable_mempot_0{vlSymsp->TOP.io_wr_enable_mempot_0}
    , io_wr_enable_mempot_1{vlSymsp->TOP.io_wr_enable_mempot_1}
    , io_wr_enable_mempot_2{vlSymsp->TOP.io_wr_enable_mempot_2}
    , io_wr_enable_mempot_3{vlSymsp->TOP.io_wr_enable_mempot_3}
    , io_wr_enable_mempot_4{vlSymsp->TOP.io_wr_enable_mempot_4}
    , io_wr_enable_mempot_5{vlSymsp->TOP.io_wr_enable_mempot_5}
    , io_wr_enable_mempot_6{vlSymsp->TOP.io_wr_enable_mempot_6}
    , io_wr_enable_mempot_7{vlSymsp->TOP.io_wr_enable_mempot_7}
    , io_wr_enable_mempot_8{vlSymsp->TOP.io_wr_enable_mempot_8}
    , io_rd_enable_mempot_0{vlSymsp->TOP.io_rd_enable_mempot_0}
    , io_rd_enable_mempot_1{vlSymsp->TOP.io_rd_enable_mempot_1}
    , io_rd_enable_mempot_2{vlSymsp->TOP.io_rd_enable_mempot_2}
    , io_rd_enable_mempot_3{vlSymsp->TOP.io_rd_enable_mempot_3}
    , io_rd_enable_mempot_4{vlSymsp->TOP.io_rd_enable_mempot_4}
    , io_rd_enable_mempot_5{vlSymsp->TOP.io_rd_enable_mempot_5}
    , io_rd_enable_mempot_6{vlSymsp->TOP.io_rd_enable_mempot_6}
    , io_rd_enable_mempot_7{vlSymsp->TOP.io_rd_enable_mempot_7}
    , io_rd_enable_mempot_8{vlSymsp->TOP.io_rd_enable_mempot_8}
    , io_addr_r_mempot_0{vlSymsp->TOP.io_addr_r_mempot_0}
    , io_addr_r_mempot_1{vlSymsp->TOP.io_addr_r_mempot_1}
    , io_addr_r_mempot_2{vlSymsp->TOP.io_addr_r_mempot_2}
    , io_addr_r_mempot_3{vlSymsp->TOP.io_addr_r_mempot_3}
    , io_addr_r_mempot_4{vlSymsp->TOP.io_addr_r_mempot_4}
    , io_addr_r_mempot_5{vlSymsp->TOP.io_addr_r_mempot_5}
    , io_addr_r_mempot_6{vlSymsp->TOP.io_addr_r_mempot_6}
    , io_addr_r_mempot_7{vlSymsp->TOP.io_addr_r_mempot_7}
    , io_addr_r_mempot_8{vlSymsp->TOP.io_addr_r_mempot_8}
    , io_addr_w_mempot_0{vlSymsp->TOP.io_addr_w_mempot_0}
    , io_addr_w_mempot_1{vlSymsp->TOP.io_addr_w_mempot_1}
    , io_addr_w_mempot_2{vlSymsp->TOP.io_addr_w_mempot_2}
    , io_addr_w_mempot_3{vlSymsp->TOP.io_addr_w_mempot_3}
    , io_addr_w_mempot_4{vlSymsp->TOP.io_addr_w_mempot_4}
    , io_addr_w_mempot_5{vlSymsp->TOP.io_addr_w_mempot_5}
    , io_addr_w_mempot_6{vlSymsp->TOP.io_addr_w_mempot_6}
    , io_addr_w_mempot_7{vlSymsp->TOP.io_addr_w_mempot_7}
    , io_addr_w_mempot_8{vlSymsp->TOP.io_addr_w_mempot_8}
    , io_bias_0{vlSymsp->TOP.io_bias_0}
    , io_bias_1{vlSymsp->TOP.io_bias_1}
    , io_bias_2{vlSymsp->TOP.io_bias_2}
    , io_bias_3{vlSymsp->TOP.io_bias_3}
    , io_bias_4{vlSymsp->TOP.io_bias_4}
    , io_bias_5{vlSymsp->TOP.io_bias_5}
    , io_bias_6{vlSymsp->TOP.io_bias_6}
    , io_bias_7{vlSymsp->TOP.io_bias_7}
    , io_bias_8{vlSymsp->TOP.io_bias_8}
    , io_V_t{vlSymsp->TOP.io_V_t}
    , io_thresh_enab{vlSymsp->TOP.io_thresh_enab}
    , io_conv_enab{vlSymsp->TOP.io_conv_enab}
    , io_kernel_0{vlSymsp->TOP.io_kernel_0}
    , io_kernel_1{vlSymsp->TOP.io_kernel_1}
    , io_kernel_2{vlSymsp->TOP.io_kernel_2}
    , io_kernel_3{vlSymsp->TOP.io_kernel_3}
    , io_kernel_4{vlSymsp->TOP.io_kernel_4}
    , io_kernel_5{vlSymsp->TOP.io_kernel_5}
    , io_kernel_6{vlSymsp->TOP.io_kernel_6}
    , io_kernel_7{vlSymsp->TOP.io_kernel_7}
    , io_kernel_8{vlSymsp->TOP.io_kernel_8}
    , io_writeData_aeq_0{vlSymsp->TOP.io_writeData_aeq_0}
    , io_writeData_aeq_1{vlSymsp->TOP.io_writeData_aeq_1}
    , io_writeData_aeq_2{vlSymsp->TOP.io_writeData_aeq_2}
    , io_writeData_aeq_3{vlSymsp->TOP.io_writeData_aeq_3}
    , io_writeData_aeq_4{vlSymsp->TOP.io_writeData_aeq_4}
    , io_writeData_aeq_5{vlSymsp->TOP.io_writeData_aeq_5}
    , io_writeData_aeq_6{vlSymsp->TOP.io_writeData_aeq_6}
    , io_writeData_aeq_7{vlSymsp->TOP.io_writeData_aeq_7}
    , io_writeData_aeq_8{vlSymsp->TOP.io_writeData_aeq_8}
    , io_readData_aeq_0{vlSymsp->TOP.io_readData_aeq_0}
    , io_readData_aeq_1{vlSymsp->TOP.io_readData_aeq_1}
    , io_readData_aeq_2{vlSymsp->TOP.io_readData_aeq_2}
    , io_readData_aeq_3{vlSymsp->TOP.io_readData_aeq_3}
    , io_readData_aeq_4{vlSymsp->TOP.io_readData_aeq_4}
    , io_readData_aeq_5{vlSymsp->TOP.io_readData_aeq_5}
    , io_readData_aeq_6{vlSymsp->TOP.io_readData_aeq_6}
    , io_readData_aeq_7{vlSymsp->TOP.io_readData_aeq_7}
    , io_readData_aeq_8{vlSymsp->TOP.io_readData_aeq_8}
    , io_din_mempot_0{vlSymsp->TOP.io_din_mempot_0}
    , io_din_mempot_1{vlSymsp->TOP.io_din_mempot_1}
    , io_din_mempot_2{vlSymsp->TOP.io_din_mempot_2}
    , io_din_mempot_3{vlSymsp->TOP.io_din_mempot_3}
    , io_din_mempot_4{vlSymsp->TOP.io_din_mempot_4}
    , io_din_mempot_5{vlSymsp->TOP.io_din_mempot_5}
    , io_din_mempot_6{vlSymsp->TOP.io_din_mempot_6}
    , io_din_mempot_7{vlSymsp->TOP.io_din_mempot_7}
    , io_din_mempot_8{vlSymsp->TOP.io_din_mempot_8}
    , io_dout_mempot_0{vlSymsp->TOP.io_dout_mempot_0}
    , io_dout_mempot_1{vlSymsp->TOP.io_dout_mempot_1}
    , io_dout_mempot_2{vlSymsp->TOP.io_dout_mempot_2}
    , io_dout_mempot_3{vlSymsp->TOP.io_dout_mempot_3}
    , io_dout_mempot_4{vlSymsp->TOP.io_dout_mempot_4}
    , io_dout_mempot_5{vlSymsp->TOP.io_dout_mempot_5}
    , io_dout_mempot_6{vlSymsp->TOP.io_dout_mempot_6}
    , io_dout_mempot_7{vlSymsp->TOP.io_dout_mempot_7}
    , io_dout_mempot_8{vlSymsp->TOP.io_dout_mempot_8}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtop::Vtop(const char* _vcname__)
    : Vtop(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtop::~Vtop() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop___024root___eval_static(Vtop___024root* vlSelf);
void Vtop___024root___eval_initial(Vtop___024root* vlSelf);
void Vtop___024root___eval_settle(Vtop___024root* vlSelf);
void Vtop___024root___eval(Vtop___024root* vlSelf);

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtop___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtop___024root___eval_static(&(vlSymsp->TOP));
        Vtop___024root___eval_initial(&(vlSymsp->TOP));
        Vtop___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtop___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtop::eventsPending() { return false; }

uint64_t Vtop::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtop::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtop___024root___eval_final(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop::final() {
    Vtop___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtop::hierName() const { return vlSymsp->name(); }
const char* Vtop::modelName() const { return "Vtop"; }
unsigned Vtop::threads() const { return 1; }
