// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VAEQ.h"
#include "VAEQ__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VAEQ::VAEQ(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VAEQ__Syms(contextp(), _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , io_writeEnable_0{vlSymsp->TOP.io_writeEnable_0}
    , io_writeEnable_1{vlSymsp->TOP.io_writeEnable_1}
    , io_writeEnable_2{vlSymsp->TOP.io_writeEnable_2}
    , io_writeEnable_3{vlSymsp->TOP.io_writeEnable_3}
    , io_writeEnable_4{vlSymsp->TOP.io_writeEnable_4}
    , io_writeEnable_5{vlSymsp->TOP.io_writeEnable_5}
    , io_writeEnable_6{vlSymsp->TOP.io_writeEnable_6}
    , io_writeEnable_7{vlSymsp->TOP.io_writeEnable_7}
    , io_writeEnable_8{vlSymsp->TOP.io_writeEnable_8}
    , io_readEnable{vlSymsp->TOP.io_readEnable}
    , io_writeData_0{vlSymsp->TOP.io_writeData_0}
    , io_writeData_1{vlSymsp->TOP.io_writeData_1}
    , io_writeData_2{vlSymsp->TOP.io_writeData_2}
    , io_writeData_3{vlSymsp->TOP.io_writeData_3}
    , io_writeData_4{vlSymsp->TOP.io_writeData_4}
    , io_writeData_5{vlSymsp->TOP.io_writeData_5}
    , io_writeData_6{vlSymsp->TOP.io_writeData_6}
    , io_writeData_7{vlSymsp->TOP.io_writeData_7}
    , io_writeData_8{vlSymsp->TOP.io_writeData_8}
    , io_readData_0{vlSymsp->TOP.io_readData_0}
    , io_readData_1{vlSymsp->TOP.io_readData_1}
    , io_readData_2{vlSymsp->TOP.io_readData_2}
    , io_readData_3{vlSymsp->TOP.io_readData_3}
    , io_readData_4{vlSymsp->TOP.io_readData_4}
    , io_readData_5{vlSymsp->TOP.io_readData_5}
    , io_readData_6{vlSymsp->TOP.io_readData_6}
    , io_readData_7{vlSymsp->TOP.io_readData_7}
    , io_readData_8{vlSymsp->TOP.io_readData_8}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VAEQ::VAEQ(const char* _vcname__)
    : VAEQ(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VAEQ::~VAEQ() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VAEQ___024root___eval_debug_assertions(VAEQ___024root* vlSelf);
#endif  // VL_DEBUG
void VAEQ___024root___eval_static(VAEQ___024root* vlSelf);
void VAEQ___024root___eval_initial(VAEQ___024root* vlSelf);
void VAEQ___024root___eval_settle(VAEQ___024root* vlSelf);
void VAEQ___024root___eval(VAEQ___024root* vlSelf);

void VAEQ::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VAEQ::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VAEQ___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VAEQ___024root___eval_static(&(vlSymsp->TOP));
        VAEQ___024root___eval_initial(&(vlSymsp->TOP));
        VAEQ___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VAEQ___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VAEQ::eventsPending() { return false; }

uint64_t VAEQ::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VAEQ::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VAEQ___024root___eval_final(VAEQ___024root* vlSelf);

VL_ATTR_COLD void VAEQ::final() {
    VAEQ___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VAEQ::hierName() const { return vlSymsp->name(); }
const char* VAEQ::modelName() const { return "VAEQ"; }
unsigned VAEQ::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> VAEQ::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VAEQ___024root__trace_init_top(VAEQ___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VAEQ___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VAEQ___024root*>(voidSelf);
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    VAEQ___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void VAEQ___024root__trace_register(VAEQ___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VAEQ::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VAEQ::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VAEQ___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
