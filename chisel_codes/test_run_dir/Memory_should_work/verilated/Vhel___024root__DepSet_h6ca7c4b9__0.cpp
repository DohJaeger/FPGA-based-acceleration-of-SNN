// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhel.h for the primary calling header

#include "verilated.h"

#include "Vhel___024root.h"

void Vhel___024root___eval_act(Vhel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vhel___024root___nba_sequent__TOP__0(Vhel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*9:0*/ __Vdlyvdim0__hel__DOT__mem__v0;
    __Vdlyvdim0__hel__DOT__mem__v0 = 0;
    CData/*7:0*/ __Vdlyvval__hel__DOT__mem__v0;
    __Vdlyvval__hel__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__hel__DOT__mem__v0;
    __Vdlyvset__hel__DOT__mem__v0 = 0;
    // Body
    __Vdlyvset__hel__DOT__mem__v0 = 0U;
    if (vlSelf->io_wrEna) {
        __Vdlyvval__hel__DOT__mem__v0 = vlSelf->io_wrData;
        __Vdlyvset__hel__DOT__mem__v0 = 1U;
        __Vdlyvdim0__hel__DOT__mem__v0 = vlSelf->io_wrAddr;
    }
    if (vlSelf->io_rdEna) {
        vlSelf->hel__DOT__mem_io_rdData_MPORT_en_pipe_0 = 1U;
        vlSelf->hel__DOT__mem_io_rdData_MPORT_addr_pipe_0 
            = vlSelf->io_rdAddr;
    } else {
        vlSelf->hel__DOT__mem_io_rdData_MPORT_en_pipe_0 = 0U;
    }
    if (__Vdlyvset__hel__DOT__mem__v0) {
        vlSelf->hel__DOT__mem[__Vdlyvdim0__hel__DOT__mem__v0] 
            = __Vdlyvval__hel__DOT__mem__v0;
    }
    vlSelf->io_rdData = vlSelf->hel__DOT__mem[vlSelf->hel__DOT__mem_io_rdData_MPORT_addr_pipe_0];
}

void Vhel___024root___eval_nba(Vhel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vhel___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vhel___024root___eval_triggers__act(Vhel___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vhel___024root___dump_triggers__act(Vhel___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vhel___024root___dump_triggers__nba(Vhel___024root* vlSelf);
#endif  // VL_DEBUG

void Vhel___024root___eval(Vhel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vhel___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vhel___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("hel.sv", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vhel___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vhel___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("hel.sv", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vhel___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vhel___024root___eval_debug_assertions(Vhel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->io_rdAddr & 0xfc00U))) {
        Verilated::overWidthError("io_rdAddr");}
    if (VL_UNLIKELY((vlSelf->io_wrAddr & 0xfc00U))) {
        Verilated::overWidthError("io_wrAddr");}
    if (VL_UNLIKELY((vlSelf->io_wrEna & 0xfeU))) {
        Verilated::overWidthError("io_wrEna");}
    if (VL_UNLIKELY((vlSelf->io_rdEna & 0xfeU))) {
        Verilated::overWidthError("io_rdEna");}
}
#endif  // VL_DEBUG
