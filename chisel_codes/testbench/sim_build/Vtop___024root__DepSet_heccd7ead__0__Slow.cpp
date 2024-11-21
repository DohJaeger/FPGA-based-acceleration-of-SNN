// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clock = vlSelf->clock;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vtop___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("../pe.sv", 762, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vtop___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
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
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->io_wr_enable_aeq_0 = VL_RAND_RESET_I(1);
    vlSelf->io_wr_enable_aeq_1 = VL_RAND_RESET_I(1);
    vlSelf->io_wr_enable_aeq_2 = VL_RAND_RESET_I(1);
    vlSelf->io_wr_enable_aeq_3 = VL_RAND_RESET_I(1);
    vlSelf->io_wr_enable_aeq_4 = VL_RAND_RESET_I(1);
    vlSelf->io_wr_enable_aeq_5 = VL_RAND_RESET_I(1);
    vlSelf->io_wr_enable_aeq_6 = VL_RAND_RESET_I(1);
    vlSelf->io_wr_enable_aeq_7 = VL_RAND_RESET_I(1);
    vlSelf->io_wr_enable_aeq_8 = VL_RAND_RESET_I(1);
    vlSelf->io_rd_enable_aeq = VL_RAND_RESET_I(1);
    vlSelf->io_writeData_aeq_0 = VL_RAND_RESET_I(9);
    vlSelf->io_writeData_aeq_1 = VL_RAND_RESET_I(9);
    vlSelf->io_writeData_aeq_2 = VL_RAND_RESET_I(9);
    vlSelf->io_writeData_aeq_3 = VL_RAND_RESET_I(9);
    vlSelf->io_writeData_aeq_4 = VL_RAND_RESET_I(9);
    vlSelf->io_writeData_aeq_5 = VL_RAND_RESET_I(9);
    vlSelf->io_writeData_aeq_6 = VL_RAND_RESET_I(9);
    vlSelf->io_writeData_aeq_7 = VL_RAND_RESET_I(9);
    vlSelf->io_writeData_aeq_8 = VL_RAND_RESET_I(9);
    vlSelf->io_readData_aeq_0 = VL_RAND_RESET_I(9);
    vlSelf->io_readData_aeq_1 = VL_RAND_RESET_I(9);
    vlSelf->io_readData_aeq_2 = VL_RAND_RESET_I(9);
    vlSelf->io_readData_aeq_3 = VL_RAND_RESET_I(9);
    vlSelf->io_readData_aeq_4 = VL_RAND_RESET_I(9);
    vlSelf->io_readData_aeq_5 = VL_RAND_RESET_I(9);
    vlSelf->io_readData_aeq_6 = VL_RAND_RESET_I(9);
    vlSelf->io_readData_aeq_7 = VL_RAND_RESET_I(9);
    vlSelf->io_readData_aeq_8 = VL_RAND_RESET_I(9);
    vlSelf->io_wr_enable_mempot_0 = VL_RAND_RESET_I(1);
    vlSelf->io_wr_enable_mempot_1 = VL_RAND_RESET_I(1);
    vlSelf->io_wr_enable_mempot_2 = VL_RAND_RESET_I(1);
    vlSelf->io_wr_enable_mempot_3 = VL_RAND_RESET_I(1);
    vlSelf->io_wr_enable_mempot_4 = VL_RAND_RESET_I(1);
    vlSelf->io_wr_enable_mempot_5 = VL_RAND_RESET_I(1);
    vlSelf->io_wr_enable_mempot_6 = VL_RAND_RESET_I(1);
    vlSelf->io_wr_enable_mempot_7 = VL_RAND_RESET_I(1);
    vlSelf->io_wr_enable_mempot_8 = VL_RAND_RESET_I(1);
    vlSelf->io_rd_enable_mempot_0 = VL_RAND_RESET_I(1);
    vlSelf->io_rd_enable_mempot_1 = VL_RAND_RESET_I(1);
    vlSelf->io_rd_enable_mempot_2 = VL_RAND_RESET_I(1);
    vlSelf->io_rd_enable_mempot_3 = VL_RAND_RESET_I(1);
    vlSelf->io_rd_enable_mempot_4 = VL_RAND_RESET_I(1);
    vlSelf->io_rd_enable_mempot_5 = VL_RAND_RESET_I(1);
    vlSelf->io_rd_enable_mempot_6 = VL_RAND_RESET_I(1);
    vlSelf->io_rd_enable_mempot_7 = VL_RAND_RESET_I(1);
    vlSelf->io_rd_enable_mempot_8 = VL_RAND_RESET_I(1);
    vlSelf->io_addr_r_mempot_0 = VL_RAND_RESET_I(8);
    vlSelf->io_addr_r_mempot_1 = VL_RAND_RESET_I(8);
    vlSelf->io_addr_r_mempot_2 = VL_RAND_RESET_I(8);
    vlSelf->io_addr_r_mempot_3 = VL_RAND_RESET_I(8);
    vlSelf->io_addr_r_mempot_4 = VL_RAND_RESET_I(8);
    vlSelf->io_addr_r_mempot_5 = VL_RAND_RESET_I(8);
    vlSelf->io_addr_r_mempot_6 = VL_RAND_RESET_I(8);
    vlSelf->io_addr_r_mempot_7 = VL_RAND_RESET_I(8);
    vlSelf->io_addr_r_mempot_8 = VL_RAND_RESET_I(8);
    vlSelf->io_addr_w_mempot_0 = VL_RAND_RESET_I(8);
    vlSelf->io_addr_w_mempot_1 = VL_RAND_RESET_I(8);
    vlSelf->io_addr_w_mempot_2 = VL_RAND_RESET_I(8);
    vlSelf->io_addr_w_mempot_3 = VL_RAND_RESET_I(8);
    vlSelf->io_addr_w_mempot_4 = VL_RAND_RESET_I(8);
    vlSelf->io_addr_w_mempot_5 = VL_RAND_RESET_I(8);
    vlSelf->io_addr_w_mempot_6 = VL_RAND_RESET_I(8);
    vlSelf->io_addr_w_mempot_7 = VL_RAND_RESET_I(8);
    vlSelf->io_addr_w_mempot_8 = VL_RAND_RESET_I(8);
    vlSelf->io_din_mempot_0 = VL_RAND_RESET_I(9);
    vlSelf->io_din_mempot_1 = VL_RAND_RESET_I(9);
    vlSelf->io_din_mempot_2 = VL_RAND_RESET_I(9);
    vlSelf->io_din_mempot_3 = VL_RAND_RESET_I(9);
    vlSelf->io_din_mempot_4 = VL_RAND_RESET_I(9);
    vlSelf->io_din_mempot_5 = VL_RAND_RESET_I(9);
    vlSelf->io_din_mempot_6 = VL_RAND_RESET_I(9);
    vlSelf->io_din_mempot_7 = VL_RAND_RESET_I(9);
    vlSelf->io_din_mempot_8 = VL_RAND_RESET_I(9);
    vlSelf->io_dout_mempot_0 = VL_RAND_RESET_I(9);
    vlSelf->io_dout_mempot_1 = VL_RAND_RESET_I(9);
    vlSelf->io_dout_mempot_2 = VL_RAND_RESET_I(9);
    vlSelf->io_dout_mempot_3 = VL_RAND_RESET_I(9);
    vlSelf->io_dout_mempot_4 = VL_RAND_RESET_I(9);
    vlSelf->io_dout_mempot_5 = VL_RAND_RESET_I(9);
    vlSelf->io_dout_mempot_6 = VL_RAND_RESET_I(9);
    vlSelf->io_dout_mempot_7 = VL_RAND_RESET_I(9);
    vlSelf->io_dout_mempot_8 = VL_RAND_RESET_I(9);
    vlSelf->io_bias_0 = VL_RAND_RESET_I(8);
    vlSelf->io_bias_1 = VL_RAND_RESET_I(8);
    vlSelf->io_bias_2 = VL_RAND_RESET_I(8);
    vlSelf->io_bias_3 = VL_RAND_RESET_I(8);
    vlSelf->io_bias_4 = VL_RAND_RESET_I(8);
    vlSelf->io_bias_5 = VL_RAND_RESET_I(8);
    vlSelf->io_bias_6 = VL_RAND_RESET_I(8);
    vlSelf->io_bias_7 = VL_RAND_RESET_I(8);
    vlSelf->io_bias_8 = VL_RAND_RESET_I(8);
    vlSelf->io_V_t = VL_RAND_RESET_I(8);
    vlSelf->io_thresh_enab = VL_RAND_RESET_I(1);
    vlSelf->io_conv_enab = VL_RAND_RESET_I(1);
    vlSelf->io_kernel_0 = VL_RAND_RESET_I(8);
    vlSelf->io_kernel_1 = VL_RAND_RESET_I(8);
    vlSelf->io_kernel_2 = VL_RAND_RESET_I(8);
    vlSelf->io_kernel_3 = VL_RAND_RESET_I(8);
    vlSelf->io_kernel_4 = VL_RAND_RESET_I(8);
    vlSelf->io_kernel_5 = VL_RAND_RESET_I(8);
    vlSelf->io_kernel_6 = VL_RAND_RESET_I(8);
    vlSelf->io_kernel_7 = VL_RAND_RESET_I(8);
    vlSelf->io_kernel_8 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_wr_enable_aeq_0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_wr_enable_aeq_1 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_wr_enable_aeq_2 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_wr_enable_aeq_3 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_wr_enable_aeq_4 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_wr_enable_aeq_5 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_wr_enable_aeq_6 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_wr_enable_aeq_7 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_wr_enable_aeq_8 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_rd_enable_aeq = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_writeData_aeq_0 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_writeData_aeq_1 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_writeData_aeq_2 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_writeData_aeq_3 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_writeData_aeq_4 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_writeData_aeq_5 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_writeData_aeq_6 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_writeData_aeq_7 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_writeData_aeq_8 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_readData_aeq_0 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_readData_aeq_1 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_readData_aeq_2 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_readData_aeq_3 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_readData_aeq_4 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_readData_aeq_5 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_readData_aeq_6 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_readData_aeq_7 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_readData_aeq_8 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_wr_enable_mempot_0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_wr_enable_mempot_1 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_wr_enable_mempot_2 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_wr_enable_mempot_3 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_wr_enable_mempot_4 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_wr_enable_mempot_5 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_wr_enable_mempot_6 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_wr_enable_mempot_7 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_wr_enable_mempot_8 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_rd_enable_mempot_0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_rd_enable_mempot_1 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_rd_enable_mempot_2 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_rd_enable_mempot_3 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_rd_enable_mempot_4 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_rd_enable_mempot_5 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_rd_enable_mempot_6 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_rd_enable_mempot_7 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_rd_enable_mempot_8 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_addr_r_mempot_0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_addr_r_mempot_1 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_addr_r_mempot_2 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_addr_r_mempot_3 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_addr_r_mempot_4 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_addr_r_mempot_5 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_addr_r_mempot_6 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_addr_r_mempot_7 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_addr_r_mempot_8 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_addr_w_mempot_0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_addr_w_mempot_1 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_addr_w_mempot_2 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_addr_w_mempot_3 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_addr_w_mempot_4 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_addr_w_mempot_5 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_addr_w_mempot_6 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_addr_w_mempot_7 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_addr_w_mempot_8 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_din_mempot_0 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_din_mempot_1 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_din_mempot_2 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_din_mempot_3 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_din_mempot_4 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_din_mempot_5 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_din_mempot_6 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_din_mempot_7 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_din_mempot_8 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_dout_mempot_0 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_dout_mempot_1 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_dout_mempot_2 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_dout_mempot_3 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_dout_mempot_4 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_dout_mempot_5 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_dout_mempot_6 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_dout_mempot_7 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_dout_mempot_8 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__io_bias_0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_bias_1 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_bias_2 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_bias_3 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_bias_4 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_bias_5 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_bias_6 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_bias_7 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_bias_8 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_V_t = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_thresh_enab = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_conv_enab = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__io_kernel_0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_kernel_1 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_kernel_2 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_kernel_3 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_kernel_4 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_kernel_5 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_kernel_6 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_kernel_7 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__io_kernel_8 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT___mempotMem_io_dout_0 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT___mempotMem_io_dout_1 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT___mempotMem_io_dout_2 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT___mempotMem_io_dout_3 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT___mempotMem_io_dout_4 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT___mempotMem_io_dout_5 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT___mempotMem_io_dout_6 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT___mempotMem_io_dout_7 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT___mempotMem_io_dout_8 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__s2_memRead_0 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__s2_memRead_1 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__s2_memRead_2 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__s2_memRead_3 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__s2_memRead_4 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__s2_memRead_5 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__s2_memRead_6 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__s2_memRead_7 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__s2_memRead_8 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__s3_updates_0 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__s3_updates_1 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__s3_updates_2 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__s3_updates_3 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__s3_updates_4 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__s3_updates_5 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__s3_updates_6 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__s3_updates_7 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__s3_updates_8 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__validS1 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__validS2 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__validS3 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__validS4 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__unnamedblk1__DOT___GEN = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__unnamedblk1__DOT___GEN_0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__unnamedblk1__DOT___GEN_1 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_1 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_2 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_3 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_4 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_5 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_6 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_7 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_8 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk3__DOT___GEN_2 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->pe__DOT__unnamedblk4__DOT___RANDOM[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->pe__DOT__aeqMem__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_1 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_2 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_3 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_4 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_5 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_6 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_7 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_8 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__io_readEnable = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__io_writeData_0 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__aeqMem__DOT__io_writeData_1 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__aeqMem__DOT__io_writeData_2 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__aeqMem__DOT__io_writeData_3 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__aeqMem__DOT__io_writeData_4 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__aeqMem__DOT__io_writeData_5 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__aeqMem__DOT__io_writeData_6 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__aeqMem__DOT__io_writeData_7 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__aeqMem__DOT__io_writeData_8 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_0 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_1 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_2 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_3 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_4 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_5 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_6 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_7 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_8 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_0 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_1 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_2 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_3 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_4 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_5 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_6 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_7 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_8 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__writeCounters_0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__writeCounters_1 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__writeCounters_2 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__writeCounters_3 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__writeCounters_4 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__writeCounters_5 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__writeCounters_6 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__writeCounters_7 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__writeCounters_8 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__readCounter = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT___GEN = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_8 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_7 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_6 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_5 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_4 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_3 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_2 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_1 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_0 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_8 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_7 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_6 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_5 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_4 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_3 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_2 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_1 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_0 = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->pe__DOT__aeqMem__DOT__unnamedblk1__DOT___RANDOM[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_1 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_2 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_3 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_4 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_5 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_6 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_7 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_8 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_0 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_1 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_2 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_3 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_4 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_5 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_6 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_7 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_8 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_1 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_2 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_3 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_4 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_5 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_6 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_7 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_8 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_0 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_1 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_2 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_3 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_4 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_5 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_6 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_7 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_8 = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_1 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_2 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_3 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_4 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_5 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_6 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_7 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_8 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_1 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_2 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_3 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_4 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_5 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_6 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_7 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_8 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_data = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__W0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__W0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__W0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__W0_data = VL_RAND_RESET_I(11);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(11);
    }
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT___R0_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT___R0_addr_d0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT___RANDOM_MEM = VL_RAND_RESET_I(32);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_data = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__W0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__W0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__W0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__W0_data = VL_RAND_RESET_I(11);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(11);
    }
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT___R0_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT___R0_addr_d0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT___RANDOM_MEM = VL_RAND_RESET_I(32);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_data = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__W0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__W0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__W0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__W0_data = VL_RAND_RESET_I(11);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(11);
    }
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT___R0_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT___R0_addr_d0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT___RANDOM_MEM = VL_RAND_RESET_I(32);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_data = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__W0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__W0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__W0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__W0_data = VL_RAND_RESET_I(11);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(11);
    }
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT___R0_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT___R0_addr_d0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT___RANDOM_MEM = VL_RAND_RESET_I(32);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_data = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__W0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__W0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__W0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__W0_data = VL_RAND_RESET_I(11);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(11);
    }
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT___R0_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT___R0_addr_d0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT___RANDOM_MEM = VL_RAND_RESET_I(32);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_data = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__W0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__W0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__W0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__W0_data = VL_RAND_RESET_I(11);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(11);
    }
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT___R0_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT___R0_addr_d0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT___RANDOM_MEM = VL_RAND_RESET_I(32);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_data = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__W0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__W0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__W0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__W0_data = VL_RAND_RESET_I(11);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(11);
    }
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT___R0_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT___R0_addr_d0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT___RANDOM_MEM = VL_RAND_RESET_I(32);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_data = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__W0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__W0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__W0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__W0_data = VL_RAND_RESET_I(11);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(11);
    }
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT___R0_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT___R0_addr_d0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT___RANDOM_MEM = VL_RAND_RESET_I(32);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_data = VL_RAND_RESET_I(11);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__W0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__W0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__W0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__W0_data = VL_RAND_RESET_I(11);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(11);
    }
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT___R0_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT___R0_addr_d0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT___RANDOM_MEM = VL_RAND_RESET_I(32);
    vlSelf->pe__DOT__mempotMem__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_1 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_2 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_3 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_4 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_5 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_6 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_7 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_8 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_1 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_2 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_3 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_4 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_5 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_6 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_7 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_8 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_r_0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_r_1 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_r_2 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_r_3 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_r_4 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_r_5 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_r_6 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_r_7 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_r_8 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_w_0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_w_1 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_w_2 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_w_3 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_w_4 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_w_5 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_w_6 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_w_7 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_w_8 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__io_din_0 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__io_din_1 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__io_din_2 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__io_din_3 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__io_din_4 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__io_din_5 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__io_din_6 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__io_din_7 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__io_din_8 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_0 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_1 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_2 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_3 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_4 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_5 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_6 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_7 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_8 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT___GEN = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT___GEN_0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT___GEN_1 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT___GEN_2 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT___GEN_3 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT___GEN_4 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT___GEN_5 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT___GEN_6 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT___GEN_7 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_8 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_7 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_6 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_5 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_4 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_3 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_2 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_1 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_8 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_7 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_6 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_5 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_4 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_3 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_2 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_1 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_0 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_8 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_7 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_6 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_5 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_4 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_3 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_2 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_1 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_8 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_7 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_6 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_5 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_4 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_3 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_2 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_1 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_1 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_2 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_3 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_4 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_5 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_6 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_7 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_8 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_0 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_1 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_2 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_3 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_4 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_5 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_6 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_7 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_8 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_1 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_2 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_3 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_4 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_5 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_6 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_7 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_8 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_0 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_1 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_2 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_3 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_4 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_5 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_6 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_7 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_8 = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_1 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_2 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_3 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_4 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_5 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_6 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_7 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_8 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_1 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_2 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_3 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_4 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_5 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_6 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_7 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_8 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_data = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__W0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__W0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__W0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__W0_data = VL_RAND_RESET_I(9);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(9);
    }
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT___R0_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT___R0_addr_d0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT___RANDOM_MEM = VL_RAND_RESET_I(32);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_data = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__W0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__W0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__W0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__W0_data = VL_RAND_RESET_I(9);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(9);
    }
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT___R0_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT___R0_addr_d0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT___RANDOM_MEM = VL_RAND_RESET_I(32);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_data = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__W0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__W0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__W0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__W0_data = VL_RAND_RESET_I(9);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(9);
    }
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT___R0_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT___R0_addr_d0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT___RANDOM_MEM = VL_RAND_RESET_I(32);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_data = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__W0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__W0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__W0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__W0_data = VL_RAND_RESET_I(9);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(9);
    }
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT___R0_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT___R0_addr_d0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT___RANDOM_MEM = VL_RAND_RESET_I(32);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_data = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__W0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__W0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__W0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__W0_data = VL_RAND_RESET_I(9);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(9);
    }
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT___R0_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT___R0_addr_d0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT___RANDOM_MEM = VL_RAND_RESET_I(32);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_data = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__W0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__W0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__W0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__W0_data = VL_RAND_RESET_I(9);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(9);
    }
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT___R0_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT___R0_addr_d0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT___RANDOM_MEM = VL_RAND_RESET_I(32);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_data = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__W0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__W0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__W0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__W0_data = VL_RAND_RESET_I(9);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(9);
    }
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT___R0_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT___R0_addr_d0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT___RANDOM_MEM = VL_RAND_RESET_I(32);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_data = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__W0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__W0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__W0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__W0_data = VL_RAND_RESET_I(9);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(9);
    }
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT___R0_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT___R0_addr_d0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT___RANDOM_MEM = VL_RAND_RESET_I(32);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_data = VL_RAND_RESET_I(9);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__W0_addr = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__W0_en = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__W0_clk = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__W0_data = VL_RAND_RESET_I(9);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(9);
    }
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT___R0_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT___R0_addr_d0 = VL_RAND_RESET_I(8);
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT___RANDOM_MEM = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigrprev__TOP__clock = VL_RAND_RESET_I(1);
}
