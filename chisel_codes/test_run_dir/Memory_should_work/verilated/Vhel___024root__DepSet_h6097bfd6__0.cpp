// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhel.h for the primary calling header

#include "verilated.h"

#include "Vhel__Syms.h"
#include "Vhel___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vhel___024root___dump_triggers__act(Vhel___024root* vlSelf);
#endif  // VL_DEBUG

void Vhel___024root___eval_triggers__act(Vhel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->clock) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clock)));
    vlSelf->__Vtrigrprev__TOP__clock = vlSelf->clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vhel___024root___dump_triggers__act(vlSelf);
    }
#endif
}
