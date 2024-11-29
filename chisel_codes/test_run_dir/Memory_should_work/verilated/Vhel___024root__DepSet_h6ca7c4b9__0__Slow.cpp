// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhel.h for the primary calling header

#include "verilated.h"

#include "Vhel___024root.h"

VL_ATTR_COLD void Vhel___024root___eval_static(Vhel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vhel___024root___eval_initial(Vhel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clock = vlSelf->clock;
}

VL_ATTR_COLD void Vhel___024root___eval_final(Vhel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vhel___024root___eval_triggers__stl(Vhel___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vhel___024root___dump_triggers__stl(Vhel___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vhel___024root___eval_stl(Vhel___024root* vlSelf);

VL_ATTR_COLD void Vhel___024root___eval_settle(Vhel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vhel___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vhel___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("hel.sv", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vhel___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vhel___024root___dump_triggers__stl(Vhel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vhel___024root___stl_sequent__TOP__0(Vhel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->io_rdData = vlSelf->hel__DOT__mem[vlSelf->hel__DOT__mem_io_rdData_MPORT_addr_pipe_0];
}

VL_ATTR_COLD void Vhel___024root___eval_stl(Vhel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vhel___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vhel___024root___dump_triggers__act(Vhel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vhel___024root___dump_triggers__nba(Vhel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vhel___024root___ctor_var_reset(Vhel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->io_rdAddr = VL_RAND_RESET_I(10);
    vlSelf->io_rdData = VL_RAND_RESET_I(8);
    vlSelf->io_wrAddr = VL_RAND_RESET_I(10);
    vlSelf->io_wrData = VL_RAND_RESET_I(8);
    vlSelf->io_wrEna = VL_RAND_RESET_I(1);
    vlSelf->io_rdEna = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->hel__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->hel__DOT__mem_io_rdData_MPORT_en_pipe_0 = VL_RAND_RESET_I(1);
    vlSelf->hel__DOT__mem_io_rdData_MPORT_addr_pipe_0 = VL_RAND_RESET_I(10);
    vlSelf->__Vtrigrprev__TOP__clock = VL_RAND_RESET_I(1);
}

VL_ATTR_COLD void Vhel___024root___configure_coverage(Vhel___024root* vlSelf, bool first) {
    if (false && vlSelf) {}  // Prevent unused
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root___configure_coverage\n"); );
    // Body
    if (false && first) {}  // Prevent unused
}
