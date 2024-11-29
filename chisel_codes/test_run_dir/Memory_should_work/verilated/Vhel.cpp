// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vhel.h"
#include "Vhel__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vhel::Vhel(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vhel__Syms(contextp(), _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , io_rdData{vlSymsp->TOP.io_rdData}
    , io_wrData{vlSymsp->TOP.io_wrData}
    , io_wrEna{vlSymsp->TOP.io_wrEna}
    , io_rdEna{vlSymsp->TOP.io_rdEna}
    , io_rdAddr{vlSymsp->TOP.io_rdAddr}
    , io_wrAddr{vlSymsp->TOP.io_wrAddr}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vhel::Vhel(const char* _vcname__)
    : Vhel(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vhel::~Vhel() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vhel___024root___eval_debug_assertions(Vhel___024root* vlSelf);
#endif  // VL_DEBUG
void Vhel___024root___eval_static(Vhel___024root* vlSelf);
void Vhel___024root___eval_initial(Vhel___024root* vlSelf);
void Vhel___024root___eval_settle(Vhel___024root* vlSelf);
void Vhel___024root___eval(Vhel___024root* vlSelf);

void Vhel::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vhel::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vhel___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vhel___024root___eval_static(&(vlSymsp->TOP));
        Vhel___024root___eval_initial(&(vlSymsp->TOP));
        Vhel___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vhel___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vhel::eventsPending() { return false; }

uint64_t Vhel::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vhel::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vhel___024root___eval_final(Vhel___024root* vlSelf);

VL_ATTR_COLD void Vhel::final() {
    Vhel___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vhel::hierName() const { return vlSymsp->name(); }
const char* Vhel::modelName() const { return "Vhel"; }
unsigned Vhel::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vhel::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vhel___024root__trace_init_top(Vhel___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vhel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vhel___024root*>(voidSelf);
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vhel___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vhel___024root__trace_register(Vhel___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vhel::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vhel::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vhel___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
