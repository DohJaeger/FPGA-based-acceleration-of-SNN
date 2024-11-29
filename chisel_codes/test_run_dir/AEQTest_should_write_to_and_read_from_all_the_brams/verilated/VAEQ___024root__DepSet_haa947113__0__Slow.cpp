// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAEQ.h for the primary calling header

#include "verilated.h"

#include "VAEQ___024root.h"

VL_ATTR_COLD void VAEQ___024root___eval_static(VAEQ___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root___eval_static\n"); );
}

VL_ATTR_COLD void VAEQ___024root___eval_initial(VAEQ___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clock = vlSelf->clock;
}

VL_ATTR_COLD void VAEQ___024root___eval_final(VAEQ___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root___eval_final\n"); );
}

VL_ATTR_COLD void VAEQ___024root___eval_triggers__stl(VAEQ___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VAEQ___024root___dump_triggers__stl(VAEQ___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void VAEQ___024root___eval_stl(VAEQ___024root* vlSelf);

VL_ATTR_COLD void VAEQ___024root___eval_settle(VAEQ___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        VAEQ___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                VAEQ___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("AEQ.sv", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            VAEQ___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VAEQ___024root___dump_triggers__stl(VAEQ___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VAEQ___024root___stl_sequent__TOP__0(VAEQ___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->AEQ__DOT___writeCounters_0_T_1 = (0xffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->AEQ__DOT__writeCounters_0)));
    vlSelf->AEQ__DOT___writeCounters_1_T_1 = (0xffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->AEQ__DOT__writeCounters_1)));
    vlSelf->AEQ__DOT___writeCounters_2_T_1 = (0xffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->AEQ__DOT__writeCounters_2)));
    vlSelf->AEQ__DOT___writeCounters_3_T_1 = (0xffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->AEQ__DOT__writeCounters_3)));
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
    vlSelf->AEQ__DOT___readCounter_T_1 = (0xffU & ((IData)(1U) 
                                                   + (IData)(vlSelf->AEQ__DOT__readCounter)));
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
}

VL_ATTR_COLD void VAEQ___024root___eval_stl(VAEQ___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        VAEQ___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VAEQ___024root___dump_triggers__ico(VAEQ___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VAEQ___024root___dump_triggers__act(VAEQ___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root___dump_triggers__act\n"); );
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
VL_ATTR_COLD void VAEQ___024root___dump_triggers__nba(VAEQ___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VAEQ___024root___ctor_var_reset(VAEQ___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->io_writeEnable_0 = VL_RAND_RESET_I(1);
    vlSelf->io_writeEnable_1 = VL_RAND_RESET_I(1);
    vlSelf->io_writeEnable_2 = VL_RAND_RESET_I(1);
    vlSelf->io_writeEnable_3 = VL_RAND_RESET_I(1);
    vlSelf->io_writeEnable_4 = VL_RAND_RESET_I(1);
    vlSelf->io_writeEnable_5 = VL_RAND_RESET_I(1);
    vlSelf->io_writeEnable_6 = VL_RAND_RESET_I(1);
    vlSelf->io_writeEnable_7 = VL_RAND_RESET_I(1);
    vlSelf->io_writeEnable_8 = VL_RAND_RESET_I(1);
    vlSelf->io_readEnable = VL_RAND_RESET_I(1);
    vlSelf->io_writeData_0 = VL_RAND_RESET_I(9);
    vlSelf->io_writeData_1 = VL_RAND_RESET_I(9);
    vlSelf->io_writeData_2 = VL_RAND_RESET_I(9);
    vlSelf->io_writeData_3 = VL_RAND_RESET_I(9);
    vlSelf->io_writeData_4 = VL_RAND_RESET_I(9);
    vlSelf->io_writeData_5 = VL_RAND_RESET_I(9);
    vlSelf->io_writeData_6 = VL_RAND_RESET_I(9);
    vlSelf->io_writeData_7 = VL_RAND_RESET_I(9);
    vlSelf->io_writeData_8 = VL_RAND_RESET_I(9);
    vlSelf->io_readData_0 = VL_RAND_RESET_I(11);
    vlSelf->io_readData_1 = VL_RAND_RESET_I(11);
    vlSelf->io_readData_2 = VL_RAND_RESET_I(11);
    vlSelf->io_readData_3 = VL_RAND_RESET_I(11);
    vlSelf->io_readData_4 = VL_RAND_RESET_I(11);
    vlSelf->io_readData_5 = VL_RAND_RESET_I(11);
    vlSelf->io_readData_6 = VL_RAND_RESET_I(11);
    vlSelf->io_readData_7 = VL_RAND_RESET_I(11);
    vlSelf->io_readData_8 = VL_RAND_RESET_I(11);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->AEQ__DOT__brams_0[__Vi0] = VL_RAND_RESET_I(11);
    }
    vlSelf->AEQ__DOT__brams_0_MPORT_en = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->AEQ__DOT__brams_1[__Vi0] = VL_RAND_RESET_I(11);
    }
    vlSelf->AEQ__DOT__brams_1_MPORT_2_en = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->AEQ__DOT__brams_2[__Vi0] = VL_RAND_RESET_I(11);
    }
    vlSelf->AEQ__DOT__brams_2_MPORT_4_en = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->AEQ__DOT__brams_3[__Vi0] = VL_RAND_RESET_I(11);
    }
    vlSelf->AEQ__DOT__brams_3_MPORT_6_en = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->AEQ__DOT__brams_4[__Vi0] = VL_RAND_RESET_I(11);
    }
    vlSelf->AEQ__DOT__brams_4_MPORT_8_en = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->AEQ__DOT__brams_5[__Vi0] = VL_RAND_RESET_I(11);
    }
    vlSelf->AEQ__DOT__brams_5_MPORT_10_en = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->AEQ__DOT__brams_6[__Vi0] = VL_RAND_RESET_I(11);
    }
    vlSelf->AEQ__DOT__brams_6_MPORT_12_en = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->AEQ__DOT__brams_7[__Vi0] = VL_RAND_RESET_I(11);
    }
    vlSelf->AEQ__DOT__brams_7_MPORT_14_en = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->AEQ__DOT__brams_8[__Vi0] = VL_RAND_RESET_I(11);
    }
    vlSelf->AEQ__DOT__brams_8_MPORT_16_en = VL_RAND_RESET_I(1);
    vlSelf->AEQ__DOT__writeCounters_0 = VL_RAND_RESET_I(8);
    vlSelf->AEQ__DOT__writeCounters_1 = VL_RAND_RESET_I(8);
    vlSelf->AEQ__DOT__writeCounters_2 = VL_RAND_RESET_I(8);
    vlSelf->AEQ__DOT__writeCounters_3 = VL_RAND_RESET_I(8);
    vlSelf->AEQ__DOT__writeCounters_4 = VL_RAND_RESET_I(8);
    vlSelf->AEQ__DOT__writeCounters_5 = VL_RAND_RESET_I(8);
    vlSelf->AEQ__DOT__writeCounters_6 = VL_RAND_RESET_I(8);
    vlSelf->AEQ__DOT__writeCounters_7 = VL_RAND_RESET_I(8);
    vlSelf->AEQ__DOT__writeCounters_8 = VL_RAND_RESET_I(8);
    vlSelf->AEQ__DOT__readCounter = VL_RAND_RESET_I(8);
    vlSelf->AEQ__DOT___writeCounters_0_T_1 = VL_RAND_RESET_I(8);
    vlSelf->AEQ__DOT___writeCounters_1_T_1 = VL_RAND_RESET_I(8);
    vlSelf->AEQ__DOT___writeCounters_2_T_1 = VL_RAND_RESET_I(8);
    vlSelf->AEQ__DOT___writeCounters_3_T_1 = VL_RAND_RESET_I(8);
    vlSelf->AEQ__DOT___writeCounters_4_T_1 = VL_RAND_RESET_I(8);
    vlSelf->AEQ__DOT___writeCounters_5_T_1 = VL_RAND_RESET_I(8);
    vlSelf->AEQ__DOT___writeCounters_6_T_1 = VL_RAND_RESET_I(8);
    vlSelf->AEQ__DOT___writeCounters_7_T_1 = VL_RAND_RESET_I(8);
    vlSelf->AEQ__DOT___writeCounters_8_T_1 = VL_RAND_RESET_I(8);
    vlSelf->AEQ__DOT___readCounter_T_1 = VL_RAND_RESET_I(8);
    vlSelf->__Vtrigrprev__TOP__clock = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}

VL_ATTR_COLD void VAEQ___024root___configure_coverage(VAEQ___024root* vlSelf, bool first) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root___configure_coverage\n"); );
    // Body
    if (false && first) {}  // Prevent unused
}
