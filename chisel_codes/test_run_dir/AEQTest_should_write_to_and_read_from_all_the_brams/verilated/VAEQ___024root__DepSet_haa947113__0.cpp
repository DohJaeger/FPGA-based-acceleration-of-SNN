// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAEQ.h for the primary calling header

#include "verilated.h"

#include "VAEQ___024root.h"

VL_INLINE_OPT void VAEQ___024root___ico_sequent__TOP__0(VAEQ___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->AEQ__DOT__brams_0_MPORT_en = ((~ (IData)(vlSelf->io_readEnable)) 
                                          & (IData)(vlSelf->io_writeEnable_0));
    vlSelf->AEQ__DOT__brams_1_MPORT_2_en = ((~ (IData)(vlSelf->io_readEnable)) 
                                            & (IData)(vlSelf->io_writeEnable_1));
    vlSelf->AEQ__DOT__brams_2_MPORT_4_en = ((~ (IData)(vlSelf->io_readEnable)) 
                                            & (IData)(vlSelf->io_writeEnable_2));
    vlSelf->AEQ__DOT__brams_3_MPORT_6_en = ((~ (IData)(vlSelf->io_readEnable)) 
                                            & (IData)(vlSelf->io_writeEnable_3));
    vlSelf->AEQ__DOT__brams_4_MPORT_8_en = ((~ (IData)(vlSelf->io_readEnable)) 
                                            & (IData)(vlSelf->io_writeEnable_4));
    vlSelf->AEQ__DOT__brams_5_MPORT_10_en = ((~ (IData)(vlSelf->io_readEnable)) 
                                             & (IData)(vlSelf->io_writeEnable_5));
    vlSelf->AEQ__DOT__brams_6_MPORT_12_en = ((~ (IData)(vlSelf->io_readEnable)) 
                                             & (IData)(vlSelf->io_writeEnable_6));
    vlSelf->AEQ__DOT__brams_7_MPORT_14_en = ((~ (IData)(vlSelf->io_readEnable)) 
                                             & (IData)(vlSelf->io_writeEnable_7));
    vlSelf->AEQ__DOT__brams_8_MPORT_16_en = ((~ (IData)(vlSelf->io_readEnable)) 
                                             & (IData)(vlSelf->io_writeEnable_8));
}

void VAEQ___024root___eval_ico(VAEQ___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        VAEQ___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void VAEQ___024root___eval_act(VAEQ___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root___eval_act\n"); );
}

VL_INLINE_OPT void VAEQ___024root___nba_sequent__TOP__0(VAEQ___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vdlyvdim0__AEQ__DOT__brams_8__v0;
    __Vdlyvdim0__AEQ__DOT__brams_8__v0 = 0;
    SData/*10:0*/ __Vdlyvval__AEQ__DOT__brams_8__v0;
    __Vdlyvval__AEQ__DOT__brams_8__v0 = 0;
    CData/*0:0*/ __Vdlyvset__AEQ__DOT__brams_8__v0;
    __Vdlyvset__AEQ__DOT__brams_8__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__AEQ__DOT__brams_8__v1;
    __Vdlyvdim0__AEQ__DOT__brams_8__v1 = 0;
    SData/*10:0*/ __Vdlyvval__AEQ__DOT__brams_8__v1;
    __Vdlyvval__AEQ__DOT__brams_8__v1 = 0;
    CData/*0:0*/ __Vdlyvset__AEQ__DOT__brams_8__v1;
    __Vdlyvset__AEQ__DOT__brams_8__v1 = 0;
    CData/*7:0*/ __Vdlyvdim0__AEQ__DOT__brams_7__v0;
    __Vdlyvdim0__AEQ__DOT__brams_7__v0 = 0;
    SData/*10:0*/ __Vdlyvval__AEQ__DOT__brams_7__v0;
    __Vdlyvval__AEQ__DOT__brams_7__v0 = 0;
    CData/*0:0*/ __Vdlyvset__AEQ__DOT__brams_7__v0;
    __Vdlyvset__AEQ__DOT__brams_7__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__AEQ__DOT__brams_7__v1;
    __Vdlyvdim0__AEQ__DOT__brams_7__v1 = 0;
    SData/*10:0*/ __Vdlyvval__AEQ__DOT__brams_7__v1;
    __Vdlyvval__AEQ__DOT__brams_7__v1 = 0;
    CData/*0:0*/ __Vdlyvset__AEQ__DOT__brams_7__v1;
    __Vdlyvset__AEQ__DOT__brams_7__v1 = 0;
    CData/*7:0*/ __Vdlyvdim0__AEQ__DOT__brams_6__v0;
    __Vdlyvdim0__AEQ__DOT__brams_6__v0 = 0;
    SData/*10:0*/ __Vdlyvval__AEQ__DOT__brams_6__v0;
    __Vdlyvval__AEQ__DOT__brams_6__v0 = 0;
    CData/*0:0*/ __Vdlyvset__AEQ__DOT__brams_6__v0;
    __Vdlyvset__AEQ__DOT__brams_6__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__AEQ__DOT__brams_6__v1;
    __Vdlyvdim0__AEQ__DOT__brams_6__v1 = 0;
    SData/*10:0*/ __Vdlyvval__AEQ__DOT__brams_6__v1;
    __Vdlyvval__AEQ__DOT__brams_6__v1 = 0;
    CData/*0:0*/ __Vdlyvset__AEQ__DOT__brams_6__v1;
    __Vdlyvset__AEQ__DOT__brams_6__v1 = 0;
    CData/*7:0*/ __Vdlyvdim0__AEQ__DOT__brams_5__v0;
    __Vdlyvdim0__AEQ__DOT__brams_5__v0 = 0;
    SData/*10:0*/ __Vdlyvval__AEQ__DOT__brams_5__v0;
    __Vdlyvval__AEQ__DOT__brams_5__v0 = 0;
    CData/*0:0*/ __Vdlyvset__AEQ__DOT__brams_5__v0;
    __Vdlyvset__AEQ__DOT__brams_5__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__AEQ__DOT__brams_5__v1;
    __Vdlyvdim0__AEQ__DOT__brams_5__v1 = 0;
    SData/*10:0*/ __Vdlyvval__AEQ__DOT__brams_5__v1;
    __Vdlyvval__AEQ__DOT__brams_5__v1 = 0;
    CData/*0:0*/ __Vdlyvset__AEQ__DOT__brams_5__v1;
    __Vdlyvset__AEQ__DOT__brams_5__v1 = 0;
    CData/*7:0*/ __Vdlyvdim0__AEQ__DOT__brams_4__v0;
    __Vdlyvdim0__AEQ__DOT__brams_4__v0 = 0;
    SData/*10:0*/ __Vdlyvval__AEQ__DOT__brams_4__v0;
    __Vdlyvval__AEQ__DOT__brams_4__v0 = 0;
    CData/*0:0*/ __Vdlyvset__AEQ__DOT__brams_4__v0;
    __Vdlyvset__AEQ__DOT__brams_4__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__AEQ__DOT__brams_4__v1;
    __Vdlyvdim0__AEQ__DOT__brams_4__v1 = 0;
    SData/*10:0*/ __Vdlyvval__AEQ__DOT__brams_4__v1;
    __Vdlyvval__AEQ__DOT__brams_4__v1 = 0;
    CData/*0:0*/ __Vdlyvset__AEQ__DOT__brams_4__v1;
    __Vdlyvset__AEQ__DOT__brams_4__v1 = 0;
    CData/*7:0*/ __Vdlyvdim0__AEQ__DOT__brams_1__v0;
    __Vdlyvdim0__AEQ__DOT__brams_1__v0 = 0;
    SData/*10:0*/ __Vdlyvval__AEQ__DOT__brams_1__v0;
    __Vdlyvval__AEQ__DOT__brams_1__v0 = 0;
    CData/*0:0*/ __Vdlyvset__AEQ__DOT__brams_1__v0;
    __Vdlyvset__AEQ__DOT__brams_1__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__AEQ__DOT__brams_1__v1;
    __Vdlyvdim0__AEQ__DOT__brams_1__v1 = 0;
    SData/*10:0*/ __Vdlyvval__AEQ__DOT__brams_1__v1;
    __Vdlyvval__AEQ__DOT__brams_1__v1 = 0;
    CData/*0:0*/ __Vdlyvset__AEQ__DOT__brams_1__v1;
    __Vdlyvset__AEQ__DOT__brams_1__v1 = 0;
    CData/*7:0*/ __Vdlyvdim0__AEQ__DOT__brams_0__v0;
    __Vdlyvdim0__AEQ__DOT__brams_0__v0 = 0;
    SData/*10:0*/ __Vdlyvval__AEQ__DOT__brams_0__v0;
    __Vdlyvval__AEQ__DOT__brams_0__v0 = 0;
    CData/*0:0*/ __Vdlyvset__AEQ__DOT__brams_0__v0;
    __Vdlyvset__AEQ__DOT__brams_0__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__AEQ__DOT__brams_0__v1;
    __Vdlyvdim0__AEQ__DOT__brams_0__v1 = 0;
    SData/*10:0*/ __Vdlyvval__AEQ__DOT__brams_0__v1;
    __Vdlyvval__AEQ__DOT__brams_0__v1 = 0;
    CData/*0:0*/ __Vdlyvset__AEQ__DOT__brams_0__v1;
    __Vdlyvset__AEQ__DOT__brams_0__v1 = 0;
    CData/*7:0*/ __Vdlyvdim0__AEQ__DOT__brams_2__v0;
    __Vdlyvdim0__AEQ__DOT__brams_2__v0 = 0;
    SData/*10:0*/ __Vdlyvval__AEQ__DOT__brams_2__v0;
    __Vdlyvval__AEQ__DOT__brams_2__v0 = 0;
    CData/*0:0*/ __Vdlyvset__AEQ__DOT__brams_2__v0;
    __Vdlyvset__AEQ__DOT__brams_2__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__AEQ__DOT__brams_2__v1;
    __Vdlyvdim0__AEQ__DOT__brams_2__v1 = 0;
    SData/*10:0*/ __Vdlyvval__AEQ__DOT__brams_2__v1;
    __Vdlyvval__AEQ__DOT__brams_2__v1 = 0;
    CData/*0:0*/ __Vdlyvset__AEQ__DOT__brams_2__v1;
    __Vdlyvset__AEQ__DOT__brams_2__v1 = 0;
    CData/*7:0*/ __Vdlyvdim0__AEQ__DOT__brams_3__v0;
    __Vdlyvdim0__AEQ__DOT__brams_3__v0 = 0;
    SData/*10:0*/ __Vdlyvval__AEQ__DOT__brams_3__v0;
    __Vdlyvval__AEQ__DOT__brams_3__v0 = 0;
    CData/*0:0*/ __Vdlyvset__AEQ__DOT__brams_3__v0;
    __Vdlyvset__AEQ__DOT__brams_3__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__AEQ__DOT__brams_3__v1;
    __Vdlyvdim0__AEQ__DOT__brams_3__v1 = 0;
    SData/*10:0*/ __Vdlyvval__AEQ__DOT__brams_3__v1;
    __Vdlyvval__AEQ__DOT__brams_3__v1 = 0;
    CData/*0:0*/ __Vdlyvset__AEQ__DOT__brams_3__v1;
    __Vdlyvset__AEQ__DOT__brams_3__v1 = 0;
    // Body
    __Vdlyvset__AEQ__DOT__brams_3__v0 = 0U;
    __Vdlyvset__AEQ__DOT__brams_3__v1 = 0U;
    __Vdlyvset__AEQ__DOT__brams_2__v0 = 0U;
    __Vdlyvset__AEQ__DOT__brams_2__v1 = 0U;
    __Vdlyvset__AEQ__DOT__brams_0__v0 = 0U;
    __Vdlyvset__AEQ__DOT__brams_0__v1 = 0U;
    __Vdlyvset__AEQ__DOT__brams_1__v0 = 0U;
    __Vdlyvset__AEQ__DOT__brams_1__v1 = 0U;
    __Vdlyvset__AEQ__DOT__brams_4__v0 = 0U;
    __Vdlyvset__AEQ__DOT__brams_4__v1 = 0U;
    __Vdlyvset__AEQ__DOT__brams_5__v0 = 0U;
    __Vdlyvset__AEQ__DOT__brams_5__v1 = 0U;
    __Vdlyvset__AEQ__DOT__brams_6__v0 = 0U;
    __Vdlyvset__AEQ__DOT__brams_6__v1 = 0U;
    __Vdlyvset__AEQ__DOT__brams_7__v0 = 0U;
    __Vdlyvset__AEQ__DOT__brams_7__v1 = 0U;
    __Vdlyvset__AEQ__DOT__brams_8__v0 = 0U;
    __Vdlyvset__AEQ__DOT__brams_8__v1 = 0U;
    if (vlSelf->AEQ__DOT__brams_3_MPORT_6_en) {
        __Vdlyvval__AEQ__DOT__brams_3__v0 = (1U | ((IData)(vlSelf->io_writeData_3) 
                                                   << 1U));
        __Vdlyvset__AEQ__DOT__brams_3__v0 = 1U;
        __Vdlyvdim0__AEQ__DOT__brams_3__v0 = vlSelf->AEQ__DOT__writeCounters_3;
    }
    if (((IData)(vlSelf->AEQ__DOT__brams_3_MPORT_6_en) 
         & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_3)))) {
        __Vdlyvval__AEQ__DOT__brams_3__v1 = (0x401U 
                                             | ((IData)(vlSelf->io_writeData_3) 
                                                << 1U));
        __Vdlyvset__AEQ__DOT__brams_3__v1 = 1U;
        __Vdlyvdim0__AEQ__DOT__brams_3__v1 = vlSelf->AEQ__DOT__writeCounters_3;
    }
    if (vlSelf->AEQ__DOT__brams_2_MPORT_4_en) {
        __Vdlyvval__AEQ__DOT__brams_2__v0 = (1U | ((IData)(vlSelf->io_writeData_2) 
                                                   << 1U));
        __Vdlyvset__AEQ__DOT__brams_2__v0 = 1U;
        __Vdlyvdim0__AEQ__DOT__brams_2__v0 = vlSelf->AEQ__DOT__writeCounters_2;
    }
    if (((IData)(vlSelf->AEQ__DOT__brams_2_MPORT_4_en) 
         & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_2)))) {
        __Vdlyvval__AEQ__DOT__brams_2__v1 = (0x401U 
                                             | ((IData)(vlSelf->io_writeData_2) 
                                                << 1U));
        __Vdlyvset__AEQ__DOT__brams_2__v1 = 1U;
        __Vdlyvdim0__AEQ__DOT__brams_2__v1 = vlSelf->AEQ__DOT__writeCounters_2;
    }
    if (vlSelf->AEQ__DOT__brams_0_MPORT_en) {
        __Vdlyvval__AEQ__DOT__brams_0__v0 = (1U | ((IData)(vlSelf->io_writeData_0) 
                                                   << 1U));
        __Vdlyvset__AEQ__DOT__brams_0__v0 = 1U;
        __Vdlyvdim0__AEQ__DOT__brams_0__v0 = vlSelf->AEQ__DOT__writeCounters_0;
    }
    if (((IData)(vlSelf->AEQ__DOT__brams_0_MPORT_en) 
         & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_0)))) {
        __Vdlyvval__AEQ__DOT__brams_0__v1 = (0x401U 
                                             | ((IData)(vlSelf->io_writeData_0) 
                                                << 1U));
        __Vdlyvset__AEQ__DOT__brams_0__v1 = 1U;
        __Vdlyvdim0__AEQ__DOT__brams_0__v1 = vlSelf->AEQ__DOT__writeCounters_0;
    }
    if (vlSelf->AEQ__DOT__brams_1_MPORT_2_en) {
        __Vdlyvval__AEQ__DOT__brams_1__v0 = (1U | ((IData)(vlSelf->io_writeData_1) 
                                                   << 1U));
        __Vdlyvset__AEQ__DOT__brams_1__v0 = 1U;
        __Vdlyvdim0__AEQ__DOT__brams_1__v0 = vlSelf->AEQ__DOT__writeCounters_1;
    }
    if (((IData)(vlSelf->AEQ__DOT__brams_1_MPORT_2_en) 
         & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_1)))) {
        __Vdlyvval__AEQ__DOT__brams_1__v1 = (0x401U 
                                             | ((IData)(vlSelf->io_writeData_1) 
                                                << 1U));
        __Vdlyvset__AEQ__DOT__brams_1__v1 = 1U;
        __Vdlyvdim0__AEQ__DOT__brams_1__v1 = vlSelf->AEQ__DOT__writeCounters_1;
    }
    if (vlSelf->AEQ__DOT__brams_4_MPORT_8_en) {
        __Vdlyvval__AEQ__DOT__brams_4__v0 = (1U | ((IData)(vlSelf->io_writeData_4) 
                                                   << 1U));
        __Vdlyvset__AEQ__DOT__brams_4__v0 = 1U;
        __Vdlyvdim0__AEQ__DOT__brams_4__v0 = vlSelf->AEQ__DOT__writeCounters_4;
    }
    if (((IData)(vlSelf->AEQ__DOT__brams_4_MPORT_8_en) 
         & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_4)))) {
        __Vdlyvval__AEQ__DOT__brams_4__v1 = (0x401U 
                                             | ((IData)(vlSelf->io_writeData_4) 
                                                << 1U));
        __Vdlyvset__AEQ__DOT__brams_4__v1 = 1U;
        __Vdlyvdim0__AEQ__DOT__brams_4__v1 = vlSelf->AEQ__DOT__writeCounters_4;
    }
    if (vlSelf->AEQ__DOT__brams_5_MPORT_10_en) {
        __Vdlyvval__AEQ__DOT__brams_5__v0 = (1U | ((IData)(vlSelf->io_writeData_5) 
                                                   << 1U));
        __Vdlyvset__AEQ__DOT__brams_5__v0 = 1U;
        __Vdlyvdim0__AEQ__DOT__brams_5__v0 = vlSelf->AEQ__DOT__writeCounters_5;
    }
    if (((IData)(vlSelf->AEQ__DOT__brams_5_MPORT_10_en) 
         & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_5)))) {
        __Vdlyvval__AEQ__DOT__brams_5__v1 = (0x401U 
                                             | ((IData)(vlSelf->io_writeData_5) 
                                                << 1U));
        __Vdlyvset__AEQ__DOT__brams_5__v1 = 1U;
        __Vdlyvdim0__AEQ__DOT__brams_5__v1 = vlSelf->AEQ__DOT__writeCounters_5;
    }
    if (vlSelf->AEQ__DOT__brams_6_MPORT_12_en) {
        __Vdlyvval__AEQ__DOT__brams_6__v0 = (1U | ((IData)(vlSelf->io_writeData_6) 
                                                   << 1U));
        __Vdlyvset__AEQ__DOT__brams_6__v0 = 1U;
        __Vdlyvdim0__AEQ__DOT__brams_6__v0 = vlSelf->AEQ__DOT__writeCounters_6;
    }
    if (((IData)(vlSelf->AEQ__DOT__brams_6_MPORT_12_en) 
         & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_6)))) {
        __Vdlyvval__AEQ__DOT__brams_6__v1 = (0x401U 
                                             | ((IData)(vlSelf->io_writeData_6) 
                                                << 1U));
        __Vdlyvset__AEQ__DOT__brams_6__v1 = 1U;
        __Vdlyvdim0__AEQ__DOT__brams_6__v1 = vlSelf->AEQ__DOT__writeCounters_6;
    }
    if (vlSelf->AEQ__DOT__brams_7_MPORT_14_en) {
        __Vdlyvval__AEQ__DOT__brams_7__v0 = (1U | ((IData)(vlSelf->io_writeData_7) 
                                                   << 1U));
        __Vdlyvset__AEQ__DOT__brams_7__v0 = 1U;
        __Vdlyvdim0__AEQ__DOT__brams_7__v0 = vlSelf->AEQ__DOT__writeCounters_7;
    }
    if (((IData)(vlSelf->AEQ__DOT__brams_7_MPORT_14_en) 
         & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_7)))) {
        __Vdlyvval__AEQ__DOT__brams_7__v1 = (0x401U 
                                             | ((IData)(vlSelf->io_writeData_7) 
                                                << 1U));
        __Vdlyvset__AEQ__DOT__brams_7__v1 = 1U;
        __Vdlyvdim0__AEQ__DOT__brams_7__v1 = vlSelf->AEQ__DOT__writeCounters_7;
    }
    if (vlSelf->AEQ__DOT__brams_8_MPORT_16_en) {
        __Vdlyvval__AEQ__DOT__brams_8__v0 = (1U | ((IData)(vlSelf->io_writeData_8) 
                                                   << 1U));
        __Vdlyvset__AEQ__DOT__brams_8__v0 = 1U;
        __Vdlyvdim0__AEQ__DOT__brams_8__v0 = vlSelf->AEQ__DOT__writeCounters_8;
    }
    if (((IData)(vlSelf->AEQ__DOT__brams_8_MPORT_16_en) 
         & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_8)))) {
        __Vdlyvval__AEQ__DOT__brams_8__v1 = (0x401U 
                                             | ((IData)(vlSelf->io_writeData_8) 
                                                << 1U));
        __Vdlyvset__AEQ__DOT__brams_8__v1 = 1U;
        __Vdlyvdim0__AEQ__DOT__brams_8__v1 = vlSelf->AEQ__DOT__writeCounters_8;
    }
    if (vlSelf->reset) {
        vlSelf->AEQ__DOT__readCounter = 0U;
        vlSelf->AEQ__DOT__writeCounters_3 = 0U;
        vlSelf->AEQ__DOT__writeCounters_2 = 0U;
        vlSelf->AEQ__DOT__writeCounters_0 = 0U;
        vlSelf->AEQ__DOT__writeCounters_1 = 0U;
        vlSelf->AEQ__DOT__writeCounters_4 = 0U;
        vlSelf->AEQ__DOT__writeCounters_5 = 0U;
        vlSelf->AEQ__DOT__writeCounters_6 = 0U;
        vlSelf->AEQ__DOT__writeCounters_7 = 0U;
        vlSelf->AEQ__DOT__writeCounters_8 = 0U;
    } else {
        if (vlSelf->io_readEnable) {
            vlSelf->AEQ__DOT__readCounter = vlSelf->AEQ__DOT___readCounter_T_1;
        }
        if (((~ (IData)(vlSelf->io_readEnable)) & (IData)(vlSelf->io_writeEnable_3))) {
            vlSelf->AEQ__DOT__writeCounters_3 = vlSelf->AEQ__DOT___writeCounters_3_T_1;
        }
        if (((~ (IData)(vlSelf->io_readEnable)) & (IData)(vlSelf->io_writeEnable_2))) {
            vlSelf->AEQ__DOT__writeCounters_2 = vlSelf->AEQ__DOT___writeCounters_2_T_1;
        }
        if (((~ (IData)(vlSelf->io_readEnable)) & (IData)(vlSelf->io_writeEnable_0))) {
            vlSelf->AEQ__DOT__writeCounters_0 = vlSelf->AEQ__DOT___writeCounters_0_T_1;
        }
        if (((~ (IData)(vlSelf->io_readEnable)) & (IData)(vlSelf->io_writeEnable_1))) {
            vlSelf->AEQ__DOT__writeCounters_1 = vlSelf->AEQ__DOT___writeCounters_1_T_1;
        }
        if (((~ (IData)(vlSelf->io_readEnable)) & (IData)(vlSelf->io_writeEnable_4))) {
            vlSelf->AEQ__DOT__writeCounters_4 = vlSelf->AEQ__DOT___writeCounters_4_T_1;
        }
        if (((~ (IData)(vlSelf->io_readEnable)) & (IData)(vlSelf->io_writeEnable_5))) {
            vlSelf->AEQ__DOT__writeCounters_5 = vlSelf->AEQ__DOT___writeCounters_5_T_1;
        }
        if (((~ (IData)(vlSelf->io_readEnable)) & (IData)(vlSelf->io_writeEnable_6))) {
            vlSelf->AEQ__DOT__writeCounters_6 = vlSelf->AEQ__DOT___writeCounters_6_T_1;
        }
        if (((~ (IData)(vlSelf->io_readEnable)) & (IData)(vlSelf->io_writeEnable_7))) {
            vlSelf->AEQ__DOT__writeCounters_7 = vlSelf->AEQ__DOT___writeCounters_7_T_1;
        }
        if (((~ (IData)(vlSelf->io_readEnable)) & (IData)(vlSelf->io_writeEnable_8))) {
            vlSelf->AEQ__DOT__writeCounters_8 = vlSelf->AEQ__DOT___writeCounters_8_T_1;
        }
    }
    if (__Vdlyvset__AEQ__DOT__brams_3__v0) {
        vlSelf->AEQ__DOT__brams_3[__Vdlyvdim0__AEQ__DOT__brams_3__v0] 
            = __Vdlyvval__AEQ__DOT__brams_3__v0;
    }
    if (__Vdlyvset__AEQ__DOT__brams_3__v1) {
        vlSelf->AEQ__DOT__brams_3[__Vdlyvdim0__AEQ__DOT__brams_3__v1] 
            = __Vdlyvval__AEQ__DOT__brams_3__v1;
    }
    if (__Vdlyvset__AEQ__DOT__brams_2__v0) {
        vlSelf->AEQ__DOT__brams_2[__Vdlyvdim0__AEQ__DOT__brams_2__v0] 
            = __Vdlyvval__AEQ__DOT__brams_2__v0;
    }
    if (__Vdlyvset__AEQ__DOT__brams_2__v1) {
        vlSelf->AEQ__DOT__brams_2[__Vdlyvdim0__AEQ__DOT__brams_2__v1] 
            = __Vdlyvval__AEQ__DOT__brams_2__v1;
    }
    if (__Vdlyvset__AEQ__DOT__brams_0__v0) {
        vlSelf->AEQ__DOT__brams_0[__Vdlyvdim0__AEQ__DOT__brams_0__v0] 
            = __Vdlyvval__AEQ__DOT__brams_0__v0;
    }
    if (__Vdlyvset__AEQ__DOT__brams_0__v1) {
        vlSelf->AEQ__DOT__brams_0[__Vdlyvdim0__AEQ__DOT__brams_0__v1] 
            = __Vdlyvval__AEQ__DOT__brams_0__v1;
    }
    if (__Vdlyvset__AEQ__DOT__brams_1__v0) {
        vlSelf->AEQ__DOT__brams_1[__Vdlyvdim0__AEQ__DOT__brams_1__v0] 
            = __Vdlyvval__AEQ__DOT__brams_1__v0;
    }
    if (__Vdlyvset__AEQ__DOT__brams_1__v1) {
        vlSelf->AEQ__DOT__brams_1[__Vdlyvdim0__AEQ__DOT__brams_1__v1] 
            = __Vdlyvval__AEQ__DOT__brams_1__v1;
    }
    if (__Vdlyvset__AEQ__DOT__brams_4__v0) {
        vlSelf->AEQ__DOT__brams_4[__Vdlyvdim0__AEQ__DOT__brams_4__v0] 
            = __Vdlyvval__AEQ__DOT__brams_4__v0;
    }
    if (__Vdlyvset__AEQ__DOT__brams_4__v1) {
        vlSelf->AEQ__DOT__brams_4[__Vdlyvdim0__AEQ__DOT__brams_4__v1] 
            = __Vdlyvval__AEQ__DOT__brams_4__v1;
    }
    if (__Vdlyvset__AEQ__DOT__brams_5__v0) {
        vlSelf->AEQ__DOT__brams_5[__Vdlyvdim0__AEQ__DOT__brams_5__v0] 
            = __Vdlyvval__AEQ__DOT__brams_5__v0;
    }
    if (__Vdlyvset__AEQ__DOT__brams_5__v1) {
        vlSelf->AEQ__DOT__brams_5[__Vdlyvdim0__AEQ__DOT__brams_5__v1] 
            = __Vdlyvval__AEQ__DOT__brams_5__v1;
    }
    if (__Vdlyvset__AEQ__DOT__brams_6__v0) {
        vlSelf->AEQ__DOT__brams_6[__Vdlyvdim0__AEQ__DOT__brams_6__v0] 
            = __Vdlyvval__AEQ__DOT__brams_6__v0;
    }
    if (__Vdlyvset__AEQ__DOT__brams_6__v1) {
        vlSelf->AEQ__DOT__brams_6[__Vdlyvdim0__AEQ__DOT__brams_6__v1] 
            = __Vdlyvval__AEQ__DOT__brams_6__v1;
    }
    if (__Vdlyvset__AEQ__DOT__brams_7__v0) {
        vlSelf->AEQ__DOT__brams_7[__Vdlyvdim0__AEQ__DOT__brams_7__v0] 
            = __Vdlyvval__AEQ__DOT__brams_7__v0;
    }
    if (__Vdlyvset__AEQ__DOT__brams_7__v1) {
        vlSelf->AEQ__DOT__brams_7[__Vdlyvdim0__AEQ__DOT__brams_7__v1] 
            = __Vdlyvval__AEQ__DOT__brams_7__v1;
    }
    if (__Vdlyvset__AEQ__DOT__brams_8__v0) {
        vlSelf->AEQ__DOT__brams_8[__Vdlyvdim0__AEQ__DOT__brams_8__v0] 
            = __Vdlyvval__AEQ__DOT__brams_8__v0;
    }
    if (__Vdlyvset__AEQ__DOT__brams_8__v1) {
        vlSelf->AEQ__DOT__brams_8[__Vdlyvdim0__AEQ__DOT__brams_8__v1] 
            = __Vdlyvval__AEQ__DOT__brams_8__v1;
    }
    vlSelf->AEQ__DOT___readCounter_T_1 = (0xffU & ((IData)(1U) 
                                                   + (IData)(vlSelf->AEQ__DOT__readCounter)));
    vlSelf->io_readData_0 = vlSelf->AEQ__DOT__brams_0
        [vlSelf->AEQ__DOT__readCounter];
    vlSelf->io_readData_1 = vlSelf->AEQ__DOT__brams_1
        [vlSelf->AEQ__DOT__readCounter];
    vlSelf->io_readData_2 = vlSelf->AEQ__DOT__brams_2
        [vlSelf->AEQ__DOT__readCounter];
    vlSelf->io_readData_3 = vlSelf->AEQ__DOT__brams_3
        [vlSelf->AEQ__DOT__readCounter];
    vlSelf->io_readData_4 = vlSelf->AEQ__DOT__brams_4
        [vlSelf->AEQ__DOT__readCounter];
    vlSelf->io_readData_5 = vlSelf->AEQ__DOT__brams_5
        [vlSelf->AEQ__DOT__readCounter];
    vlSelf->io_readData_6 = vlSelf->AEQ__DOT__brams_6
        [vlSelf->AEQ__DOT__readCounter];
    vlSelf->io_readData_7 = vlSelf->AEQ__DOT__brams_7
        [vlSelf->AEQ__DOT__readCounter];
    vlSelf->io_readData_8 = vlSelf->AEQ__DOT__brams_8
        [vlSelf->AEQ__DOT__readCounter];
    vlSelf->AEQ__DOT___writeCounters_3_T_1 = (0xffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->AEQ__DOT__writeCounters_3)));
    vlSelf->AEQ__DOT___writeCounters_2_T_1 = (0xffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->AEQ__DOT__writeCounters_2)));
    vlSelf->AEQ__DOT___writeCounters_0_T_1 = (0xffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->AEQ__DOT__writeCounters_0)));
    vlSelf->AEQ__DOT___writeCounters_1_T_1 = (0xffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->AEQ__DOT__writeCounters_1)));
    vlSelf->AEQ__DOT___writeCounters_4_T_1 = (0xffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->AEQ__DOT__writeCounters_4)));
    vlSelf->AEQ__DOT___writeCounters_5_T_1 = (0xffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->AEQ__DOT__writeCounters_5)));
    vlSelf->AEQ__DOT___writeCounters_6_T_1 = (0xffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->AEQ__DOT__writeCounters_6)));
    vlSelf->AEQ__DOT___writeCounters_7_T_1 = (0xffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->AEQ__DOT__writeCounters_7)));
    vlSelf->AEQ__DOT___writeCounters_8_T_1 = (0xffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->AEQ__DOT__writeCounters_8)));
}

void VAEQ___024root___eval_nba(VAEQ___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VAEQ___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
}

void VAEQ___024root___eval_triggers__ico(VAEQ___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VAEQ___024root___dump_triggers__ico(VAEQ___024root* vlSelf);
#endif  // VL_DEBUG
void VAEQ___024root___eval_triggers__act(VAEQ___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VAEQ___024root___dump_triggers__act(VAEQ___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VAEQ___024root___dump_triggers__nba(VAEQ___024root* vlSelf);
#endif  // VL_DEBUG

void VAEQ___024root___eval(VAEQ___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        VAEQ___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                VAEQ___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("AEQ.sv", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            VAEQ___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            VAEQ___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VAEQ___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("AEQ.sv", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                VAEQ___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VAEQ___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("AEQ.sv", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VAEQ___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VAEQ___024root___eval_debug_assertions(VAEQ___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->io_writeEnable_0 & 0xfeU))) {
        Verilated::overWidthError("io_writeEnable_0");}
    if (VL_UNLIKELY((vlSelf->io_writeEnable_1 & 0xfeU))) {
        Verilated::overWidthError("io_writeEnable_1");}
    if (VL_UNLIKELY((vlSelf->io_writeEnable_2 & 0xfeU))) {
        Verilated::overWidthError("io_writeEnable_2");}
    if (VL_UNLIKELY((vlSelf->io_writeEnable_3 & 0xfeU))) {
        Verilated::overWidthError("io_writeEnable_3");}
    if (VL_UNLIKELY((vlSelf->io_writeEnable_4 & 0xfeU))) {
        Verilated::overWidthError("io_writeEnable_4");}
    if (VL_UNLIKELY((vlSelf->io_writeEnable_5 & 0xfeU))) {
        Verilated::overWidthError("io_writeEnable_5");}
    if (VL_UNLIKELY((vlSelf->io_writeEnable_6 & 0xfeU))) {
        Verilated::overWidthError("io_writeEnable_6");}
    if (VL_UNLIKELY((vlSelf->io_writeEnable_7 & 0xfeU))) {
        Verilated::overWidthError("io_writeEnable_7");}
    if (VL_UNLIKELY((vlSelf->io_writeEnable_8 & 0xfeU))) {
        Verilated::overWidthError("io_writeEnable_8");}
    if (VL_UNLIKELY((vlSelf->io_readEnable & 0xfeU))) {
        Verilated::overWidthError("io_readEnable");}
    if (VL_UNLIKELY((vlSelf->io_writeData_0 & 0xfe00U))) {
        Verilated::overWidthError("io_writeData_0");}
    if (VL_UNLIKELY((vlSelf->io_writeData_1 & 0xfe00U))) {
        Verilated::overWidthError("io_writeData_1");}
    if (VL_UNLIKELY((vlSelf->io_writeData_2 & 0xfe00U))) {
        Verilated::overWidthError("io_writeData_2");}
    if (VL_UNLIKELY((vlSelf->io_writeData_3 & 0xfe00U))) {
        Verilated::overWidthError("io_writeData_3");}
    if (VL_UNLIKELY((vlSelf->io_writeData_4 & 0xfe00U))) {
        Verilated::overWidthError("io_writeData_4");}
    if (VL_UNLIKELY((vlSelf->io_writeData_5 & 0xfe00U))) {
        Verilated::overWidthError("io_writeData_5");}
    if (VL_UNLIKELY((vlSelf->io_writeData_6 & 0xfe00U))) {
        Verilated::overWidthError("io_writeData_6");}
    if (VL_UNLIKELY((vlSelf->io_writeData_7 & 0xfe00U))) {
        Verilated::overWidthError("io_writeData_7");}
    if (VL_UNLIKELY((vlSelf->io_writeData_8 & 0xfe00U))) {
        Verilated::overWidthError("io_writeData_8");}
}
#endif  // VL_DEBUG
