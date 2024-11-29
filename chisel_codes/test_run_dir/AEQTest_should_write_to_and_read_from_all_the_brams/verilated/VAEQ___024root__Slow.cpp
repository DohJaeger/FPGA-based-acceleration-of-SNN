// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAEQ.h for the primary calling header

#include "verilated.h"

#include "VAEQ__Syms.h"
#include "VAEQ___024root.h"

void VAEQ___024root___ctor_var_reset(VAEQ___024root* vlSelf);

VAEQ___024root::VAEQ___024root(VAEQ__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VAEQ___024root___ctor_var_reset(this);
}

void VAEQ___024root___configure_coverage(VAEQ___024root* vlSelf, bool first);

void VAEQ___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
    VAEQ___024root___configure_coverage(this, first);
}

VAEQ___024root::~VAEQ___024root() {
}

// Coverage
void VAEQ___024root::__vlCoverInsert(std::atomic<uint32_t>* countp, bool enable, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp, const char* linescovp) {
    assert(sizeof(uint32_t) == sizeof(std::atomic<uint32_t>));
    uint32_t* count32p = reinterpret_cast<uint32_t*>(countp);
    static uint32_t fake_zero_count = 0;
    if (!enable) count32p = &fake_zero_count;
    *count32p = 0;
    VL_COVER_INSERT(vlSymsp->_vm_contextp__->coveragep(), count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",std::string{name()} + hierp,  "page",pagep,  "comment",commentp,  (linescovp[0] ? "linescov" : ""), linescovp);
}
