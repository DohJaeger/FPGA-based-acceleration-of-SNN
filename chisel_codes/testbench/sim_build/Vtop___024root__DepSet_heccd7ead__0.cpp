// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Init
    SData/*8:0*/ pe__DOT____Vcellinp__mempotMem__io_din_8;
    pe__DOT____Vcellinp__mempotMem__io_din_8 = 0;
    SData/*8:0*/ pe__DOT____Vcellinp__mempotMem__io_din_7;
    pe__DOT____Vcellinp__mempotMem__io_din_7 = 0;
    SData/*8:0*/ pe__DOT____Vcellinp__mempotMem__io_din_6;
    pe__DOT____Vcellinp__mempotMem__io_din_6 = 0;
    SData/*8:0*/ pe__DOT____Vcellinp__mempotMem__io_din_5;
    pe__DOT____Vcellinp__mempotMem__io_din_5 = 0;
    SData/*8:0*/ pe__DOT____Vcellinp__mempotMem__io_din_4;
    pe__DOT____Vcellinp__mempotMem__io_din_4 = 0;
    SData/*8:0*/ pe__DOT____Vcellinp__mempotMem__io_din_3;
    pe__DOT____Vcellinp__mempotMem__io_din_3 = 0;
    SData/*8:0*/ pe__DOT____Vcellinp__mempotMem__io_din_2;
    pe__DOT____Vcellinp__mempotMem__io_din_2 = 0;
    SData/*8:0*/ pe__DOT____Vcellinp__mempotMem__io_din_1;
    pe__DOT____Vcellinp__mempotMem__io_din_1 = 0;
    SData/*8:0*/ pe__DOT____Vcellinp__mempotMem__io_din_0;
    pe__DOT____Vcellinp__mempotMem__io_din_0 = 0;
    CData/*0:0*/ pe__DOT____Vcellinp__mempotMem__io_wr_enable_8;
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_8 = 0;
    CData/*0:0*/ pe__DOT____Vcellinp__mempotMem__io_wr_enable_7;
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_7 = 0;
    CData/*0:0*/ pe__DOT____Vcellinp__mempotMem__io_wr_enable_6;
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_6 = 0;
    CData/*0:0*/ pe__DOT____Vcellinp__mempotMem__io_wr_enable_5;
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_5 = 0;
    CData/*0:0*/ pe__DOT____Vcellinp__mempotMem__io_wr_enable_4;
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_4 = 0;
    CData/*0:0*/ pe__DOT____Vcellinp__mempotMem__io_wr_enable_3;
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_3 = 0;
    CData/*0:0*/ pe__DOT____Vcellinp__mempotMem__io_wr_enable_2;
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_2 = 0;
    CData/*0:0*/ pe__DOT____Vcellinp__mempotMem__io_wr_enable_1;
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_1 = 0;
    CData/*0:0*/ pe__DOT____Vcellinp__mempotMem__io_wr_enable_0;
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_0 = 0;
    SData/*10:0*/ __VdfgTmp_hd9153207__0;
    __VdfgTmp_hd9153207__0 = 0;
    SData/*10:0*/ __VdfgTmp_hda0608a3__0;
    __VdfgTmp_hda0608a3__0 = 0;
    SData/*10:0*/ __VdfgTmp_hfb5fa790__0;
    __VdfgTmp_hfb5fa790__0 = 0;
    SData/*10:0*/ __VdfgTmp_h32e8def9__0;
    __VdfgTmp_h32e8def9__0 = 0;
    SData/*10:0*/ __VdfgTmp_hc179140a__0;
    __VdfgTmp_hc179140a__0 = 0;
    SData/*10:0*/ __VdfgTmp_h492f2847__0;
    __VdfgTmp_h492f2847__0 = 0;
    SData/*10:0*/ __VdfgTmp_hef936cc7__0;
    __VdfgTmp_hef936cc7__0 = 0;
    SData/*10:0*/ __VdfgTmp_h719cea72__0;
    __VdfgTmp_h719cea72__0 = 0;
    SData/*10:0*/ __VdfgTmp_h587e5e0b__0;
    __VdfgTmp_h587e5e0b__0 = 0;
    // Body
    vlSelf->pe__DOT__io_wr_enable_mempot_0 = vlSelf->io_wr_enable_mempot_0;
    vlSelf->pe__DOT__io_wr_enable_mempot_1 = vlSelf->io_wr_enable_mempot_1;
    vlSelf->pe__DOT__io_wr_enable_mempot_2 = vlSelf->io_wr_enable_mempot_2;
    vlSelf->pe__DOT__io_wr_enable_mempot_3 = vlSelf->io_wr_enable_mempot_3;
    vlSelf->pe__DOT__io_wr_enable_mempot_4 = vlSelf->io_wr_enable_mempot_4;
    vlSelf->pe__DOT__io_wr_enable_mempot_5 = vlSelf->io_wr_enable_mempot_5;
    vlSelf->pe__DOT__io_wr_enable_mempot_6 = vlSelf->io_wr_enable_mempot_6;
    vlSelf->pe__DOT__io_wr_enable_mempot_7 = vlSelf->io_wr_enable_mempot_7;
    vlSelf->pe__DOT__io_wr_enable_mempot_8 = vlSelf->io_wr_enable_mempot_8;
    vlSelf->pe__DOT__io_din_mempot_0 = vlSelf->io_din_mempot_0;
    vlSelf->pe__DOT__io_din_mempot_1 = vlSelf->io_din_mempot_1;
    vlSelf->pe__DOT__io_din_mempot_2 = vlSelf->io_din_mempot_2;
    vlSelf->pe__DOT__io_din_mempot_3 = vlSelf->io_din_mempot_3;
    vlSelf->pe__DOT__io_din_mempot_4 = vlSelf->io_din_mempot_4;
    vlSelf->pe__DOT__io_din_mempot_5 = vlSelf->io_din_mempot_5;
    vlSelf->pe__DOT__io_din_mempot_6 = vlSelf->io_din_mempot_6;
    vlSelf->pe__DOT__io_din_mempot_7 = vlSelf->io_din_mempot_7;
    vlSelf->pe__DOT__io_din_mempot_8 = vlSelf->io_din_mempot_8;
    vlSelf->pe__DOT__io_bias_0 = vlSelf->io_bias_0;
    vlSelf->pe__DOT__io_bias_1 = vlSelf->io_bias_1;
    vlSelf->pe__DOT__io_bias_2 = vlSelf->io_bias_2;
    vlSelf->pe__DOT__io_bias_3 = vlSelf->io_bias_3;
    vlSelf->pe__DOT__io_bias_4 = vlSelf->io_bias_4;
    vlSelf->pe__DOT__io_bias_5 = vlSelf->io_bias_5;
    vlSelf->pe__DOT__io_bias_6 = vlSelf->io_bias_6;
    vlSelf->pe__DOT__io_bias_7 = vlSelf->io_bias_7;
    vlSelf->pe__DOT__io_bias_8 = vlSelf->io_bias_8;
    vlSelf->pe__DOT__io_V_t = vlSelf->io_V_t;
    vlSelf->pe__DOT__io_thresh_enab = vlSelf->io_thresh_enab;
    vlSelf->pe__DOT__io_conv_enab = vlSelf->io_conv_enab;
    vlSelf->pe__DOT__io_kernel_0 = vlSelf->io_kernel_0;
    vlSelf->pe__DOT__io_kernel_1 = vlSelf->io_kernel_1;
    vlSelf->pe__DOT__io_kernel_2 = vlSelf->io_kernel_2;
    vlSelf->pe__DOT__io_kernel_3 = vlSelf->io_kernel_3;
    vlSelf->pe__DOT__io_kernel_4 = vlSelf->io_kernel_4;
    vlSelf->pe__DOT__io_kernel_5 = vlSelf->io_kernel_5;
    vlSelf->pe__DOT__io_kernel_6 = vlSelf->io_kernel_6;
    vlSelf->pe__DOT__io_kernel_7 = vlSelf->io_kernel_7;
    vlSelf->pe__DOT__io_kernel_8 = vlSelf->io_kernel_8;
    vlSelf->pe__DOT__reset = vlSelf->reset;
    vlSelf->pe__DOT__io_writeData_aeq_0 = vlSelf->io_writeData_aeq_0;
    vlSelf->pe__DOT__io_writeData_aeq_1 = vlSelf->io_writeData_aeq_1;
    vlSelf->pe__DOT__io_writeData_aeq_2 = vlSelf->io_writeData_aeq_2;
    vlSelf->pe__DOT__io_writeData_aeq_3 = vlSelf->io_writeData_aeq_3;
    vlSelf->pe__DOT__io_writeData_aeq_4 = vlSelf->io_writeData_aeq_4;
    vlSelf->pe__DOT__io_writeData_aeq_5 = vlSelf->io_writeData_aeq_5;
    vlSelf->pe__DOT__io_writeData_aeq_6 = vlSelf->io_writeData_aeq_6;
    vlSelf->pe__DOT__io_writeData_aeq_7 = vlSelf->io_writeData_aeq_7;
    vlSelf->pe__DOT__io_writeData_aeq_8 = vlSelf->io_writeData_aeq_8;
    vlSelf->pe__DOT__io_addr_r_mempot_0 = vlSelf->io_addr_r_mempot_0;
    vlSelf->pe__DOT__io_addr_r_mempot_1 = vlSelf->io_addr_r_mempot_1;
    vlSelf->pe__DOT__io_addr_r_mempot_2 = vlSelf->io_addr_r_mempot_2;
    vlSelf->pe__DOT__io_addr_r_mempot_3 = vlSelf->io_addr_r_mempot_3;
    vlSelf->pe__DOT__io_addr_r_mempot_4 = vlSelf->io_addr_r_mempot_4;
    vlSelf->pe__DOT__io_addr_r_mempot_5 = vlSelf->io_addr_r_mempot_5;
    vlSelf->pe__DOT__io_addr_r_mempot_6 = vlSelf->io_addr_r_mempot_6;
    vlSelf->pe__DOT__io_addr_r_mempot_7 = vlSelf->io_addr_r_mempot_7;
    vlSelf->pe__DOT__io_addr_r_mempot_8 = vlSelf->io_addr_r_mempot_8;
    vlSelf->pe__DOT__io_addr_w_mempot_0 = vlSelf->io_addr_w_mempot_0;
    vlSelf->pe__DOT__io_addr_w_mempot_1 = vlSelf->io_addr_w_mempot_1;
    vlSelf->pe__DOT__io_addr_w_mempot_2 = vlSelf->io_addr_w_mempot_2;
    vlSelf->pe__DOT__io_addr_w_mempot_3 = vlSelf->io_addr_w_mempot_3;
    vlSelf->pe__DOT__io_addr_w_mempot_4 = vlSelf->io_addr_w_mempot_4;
    vlSelf->pe__DOT__io_addr_w_mempot_5 = vlSelf->io_addr_w_mempot_5;
    vlSelf->pe__DOT__io_addr_w_mempot_6 = vlSelf->io_addr_w_mempot_6;
    vlSelf->pe__DOT__io_addr_w_mempot_7 = vlSelf->io_addr_w_mempot_7;
    vlSelf->pe__DOT__io_addr_w_mempot_8 = vlSelf->io_addr_w_mempot_8;
    if (vlSelf->io_wr_enable_aeq_0) {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_0 
            = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_0;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_0 
            = (1U | (((IData)((0xffU == (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_0))) 
                      << 0xaU) | ((IData)(vlSelf->io_writeData_aeq_0) 
                                  << 1U)));
    } else {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_0 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_0 = 0U;
    }
    if (vlSelf->io_wr_enable_aeq_1) {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_1 
            = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_1;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_1 
            = (1U | (((IData)((0xffU == (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_1))) 
                      << 0xaU) | ((IData)(vlSelf->io_writeData_aeq_1) 
                                  << 1U)));
    } else {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_1 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_1 = 0U;
    }
    if (vlSelf->io_wr_enable_aeq_2) {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_2 
            = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_2;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_2 
            = (1U | (((IData)((0xffU == (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_2))) 
                      << 0xaU) | ((IData)(vlSelf->io_writeData_aeq_2) 
                                  << 1U)));
    } else {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_2 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_2 = 0U;
    }
    if (vlSelf->io_wr_enable_aeq_3) {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_3 
            = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_3;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_3 
            = (1U | (((IData)((0xffU == (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_3))) 
                      << 0xaU) | ((IData)(vlSelf->io_writeData_aeq_3) 
                                  << 1U)));
    } else {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_3 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_3 = 0U;
    }
    if (vlSelf->io_wr_enable_aeq_4) {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_4 
            = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_4;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_4 
            = (1U | (((IData)((0xffU == (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_4))) 
                      << 0xaU) | ((IData)(vlSelf->io_writeData_aeq_4) 
                                  << 1U)));
    } else {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_4 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_4 = 0U;
    }
    if (vlSelf->io_wr_enable_aeq_5) {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_5 
            = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_5;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_5 
            = (1U | (((IData)((0xffU == (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_5))) 
                      << 0xaU) | ((IData)(vlSelf->io_writeData_aeq_5) 
                                  << 1U)));
    } else {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_5 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_5 = 0U;
    }
    if (vlSelf->io_wr_enable_aeq_6) {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_6 
            = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_6;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_6 
            = (1U | (((IData)((0xffU == (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_6))) 
                      << 0xaU) | ((IData)(vlSelf->io_writeData_aeq_6) 
                                  << 1U)));
    } else {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_6 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_6 = 0U;
    }
    if (vlSelf->io_wr_enable_aeq_7) {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_7 
            = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_7;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_7 
            = (1U | (((IData)((0xffU == (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_7))) 
                      << 0xaU) | ((IData)(vlSelf->io_writeData_aeq_7) 
                                  << 1U)));
    } else {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_7 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_7 = 0U;
    }
    if (vlSelf->io_wr_enable_aeq_8) {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_8 
            = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_8;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_8 
            = (1U | (((IData)((0xffU == (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_8))) 
                      << 0xaU) | ((IData)(vlSelf->io_writeData_aeq_8) 
                                  << 1U)));
    } else {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_8 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_8 = 0U;
    }
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_0 
        = ((IData)(vlSelf->io_rd_enable_mempot_0) ? (IData)(vlSelf->io_addr_r_mempot_0)
            : 0U);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_1 
        = ((IData)(vlSelf->io_rd_enable_mempot_1) ? (IData)(vlSelf->io_addr_r_mempot_1)
            : 0U);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_2 
        = ((IData)(vlSelf->io_rd_enable_mempot_2) ? (IData)(vlSelf->io_addr_r_mempot_2)
            : 0U);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_3 
        = ((IData)(vlSelf->io_rd_enable_mempot_3) ? (IData)(vlSelf->io_addr_r_mempot_3)
            : 0U);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_4 
        = ((IData)(vlSelf->io_rd_enable_mempot_4) ? (IData)(vlSelf->io_addr_r_mempot_4)
            : 0U);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_5 
        = ((IData)(vlSelf->io_rd_enable_mempot_5) ? (IData)(vlSelf->io_addr_r_mempot_5)
            : 0U);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_6 
        = ((IData)(vlSelf->io_rd_enable_mempot_6) ? (IData)(vlSelf->io_addr_r_mempot_6)
            : 0U);
    vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_7 
        = ((IData)(vlSelf->io_rd_enable_mempot_7) ? (IData)(vlSelf->io_addr_r_mempot_7)
            : 0U);
    if (vlSelf->io_rd_enable_mempot_8) {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_8 
            = vlSelf->io_addr_r_mempot_8;
        vlSelf->pe__DOT__io_wr_enable_aeq_0 = vlSelf->io_wr_enable_aeq_0;
        vlSelf->pe__DOT__io_wr_enable_aeq_1 = vlSelf->io_wr_enable_aeq_1;
        vlSelf->pe__DOT__io_wr_enable_aeq_2 = vlSelf->io_wr_enable_aeq_2;
        vlSelf->pe__DOT__io_wr_enable_aeq_3 = vlSelf->io_wr_enable_aeq_3;
        vlSelf->pe__DOT__io_wr_enable_aeq_4 = vlSelf->io_wr_enable_aeq_4;
        vlSelf->pe__DOT__io_wr_enable_aeq_5 = vlSelf->io_wr_enable_aeq_5;
        vlSelf->pe__DOT__io_wr_enable_aeq_6 = vlSelf->io_wr_enable_aeq_6;
        vlSelf->pe__DOT__io_wr_enable_aeq_7 = vlSelf->io_wr_enable_aeq_7;
        vlSelf->pe__DOT__io_wr_enable_aeq_8 = vlSelf->io_wr_enable_aeq_8;
        vlSelf->pe__DOT__io_rd_enable_mempot_0 = vlSelf->io_rd_enable_mempot_0;
        vlSelf->pe__DOT__io_rd_enable_mempot_1 = vlSelf->io_rd_enable_mempot_1;
        vlSelf->pe__DOT__io_rd_enable_mempot_2 = vlSelf->io_rd_enable_mempot_2;
        vlSelf->pe__DOT__io_rd_enable_mempot_3 = vlSelf->io_rd_enable_mempot_3;
        vlSelf->pe__DOT__io_rd_enable_mempot_4 = vlSelf->io_rd_enable_mempot_4;
        vlSelf->pe__DOT__io_rd_enable_mempot_5 = vlSelf->io_rd_enable_mempot_5;
        vlSelf->pe__DOT__io_rd_enable_mempot_6 = vlSelf->io_rd_enable_mempot_6;
        vlSelf->pe__DOT__io_rd_enable_mempot_7 = vlSelf->io_rd_enable_mempot_7;
        vlSelf->pe__DOT__io_rd_enable_mempot_8 = 1U;
    } else {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_8 = 0U;
        vlSelf->pe__DOT__io_wr_enable_aeq_0 = vlSelf->io_wr_enable_aeq_0;
        vlSelf->pe__DOT__io_wr_enable_aeq_1 = vlSelf->io_wr_enable_aeq_1;
        vlSelf->pe__DOT__io_wr_enable_aeq_2 = vlSelf->io_wr_enable_aeq_2;
        vlSelf->pe__DOT__io_wr_enable_aeq_3 = vlSelf->io_wr_enable_aeq_3;
        vlSelf->pe__DOT__io_wr_enable_aeq_4 = vlSelf->io_wr_enable_aeq_4;
        vlSelf->pe__DOT__io_wr_enable_aeq_5 = vlSelf->io_wr_enable_aeq_5;
        vlSelf->pe__DOT__io_wr_enable_aeq_6 = vlSelf->io_wr_enable_aeq_6;
        vlSelf->pe__DOT__io_wr_enable_aeq_7 = vlSelf->io_wr_enable_aeq_7;
        vlSelf->pe__DOT__io_wr_enable_aeq_8 = vlSelf->io_wr_enable_aeq_8;
        vlSelf->pe__DOT__io_rd_enable_mempot_0 = vlSelf->io_rd_enable_mempot_0;
        vlSelf->pe__DOT__io_rd_enable_mempot_1 = vlSelf->io_rd_enable_mempot_1;
        vlSelf->pe__DOT__io_rd_enable_mempot_2 = vlSelf->io_rd_enable_mempot_2;
        vlSelf->pe__DOT__io_rd_enable_mempot_3 = vlSelf->io_rd_enable_mempot_3;
        vlSelf->pe__DOT__io_rd_enable_mempot_4 = vlSelf->io_rd_enable_mempot_4;
        vlSelf->pe__DOT__io_rd_enable_mempot_5 = vlSelf->io_rd_enable_mempot_5;
        vlSelf->pe__DOT__io_rd_enable_mempot_6 = vlSelf->io_rd_enable_mempot_6;
        vlSelf->pe__DOT__io_rd_enable_mempot_7 = vlSelf->io_rd_enable_mempot_7;
        vlSelf->pe__DOT__io_rd_enable_mempot_8 = 0U;
    }
    if (vlSelf->pe__DOT__validS3) {
        pe__DOT____Vcellinp__mempotMem__io_din_0 = vlSelf->pe__DOT__s3_updates_0;
        pe__DOT____Vcellinp__mempotMem__io_din_1 = vlSelf->pe__DOT__s3_updates_1;
        pe__DOT____Vcellinp__mempotMem__io_din_2 = vlSelf->pe__DOT__s3_updates_2;
        pe__DOT____Vcellinp__mempotMem__io_din_3 = vlSelf->pe__DOT__s3_updates_3;
        pe__DOT____Vcellinp__mempotMem__io_din_4 = vlSelf->pe__DOT__s3_updates_4;
        pe__DOT____Vcellinp__mempotMem__io_din_5 = vlSelf->pe__DOT__s3_updates_5;
        pe__DOT____Vcellinp__mempotMem__io_din_6 = vlSelf->pe__DOT__s3_updates_6;
        pe__DOT____Vcellinp__mempotMem__io_din_7 = vlSelf->pe__DOT__s3_updates_7;
        pe__DOT____Vcellinp__mempotMem__io_din_8 = vlSelf->pe__DOT__s3_updates_8;
    } else {
        pe__DOT____Vcellinp__mempotMem__io_din_0 = vlSelf->io_din_mempot_0;
        pe__DOT____Vcellinp__mempotMem__io_din_1 = vlSelf->io_din_mempot_1;
        pe__DOT____Vcellinp__mempotMem__io_din_2 = vlSelf->io_din_mempot_2;
        pe__DOT____Vcellinp__mempotMem__io_din_3 = vlSelf->io_din_mempot_3;
        pe__DOT____Vcellinp__mempotMem__io_din_4 = vlSelf->io_din_mempot_4;
        pe__DOT____Vcellinp__mempotMem__io_din_5 = vlSelf->io_din_mempot_5;
        pe__DOT____Vcellinp__mempotMem__io_din_6 = vlSelf->io_din_mempot_6;
        pe__DOT____Vcellinp__mempotMem__io_din_7 = vlSelf->io_din_mempot_7;
        pe__DOT____Vcellinp__mempotMem__io_din_8 = vlSelf->io_din_mempot_8;
    }
    vlSelf->io_dout_mempot_0 = ((IData)(vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT___R0_en_d0)
                                 ? vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory
                                [vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT___R0_addr_d0]
                                 : 0U);
    vlSelf->io_dout_mempot_1 = ((IData)(vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT___R0_en_d0)
                                 ? vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory
                                [vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT___R0_addr_d0]
                                 : 0U);
    vlSelf->io_dout_mempot_2 = ((IData)(vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT___R0_en_d0)
                                 ? vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory
                                [vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT___R0_addr_d0]
                                 : 0U);
    vlSelf->io_dout_mempot_3 = ((IData)(vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT___R0_en_d0)
                                 ? vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory
                                [vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT___R0_addr_d0]
                                 : 0U);
    vlSelf->io_dout_mempot_4 = ((IData)(vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT___R0_en_d0)
                                 ? vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory
                                [vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT___R0_addr_d0]
                                 : 0U);
    vlSelf->io_dout_mempot_5 = ((IData)(vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT___R0_en_d0)
                                 ? vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory
                                [vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT___R0_addr_d0]
                                 : 0U);
    vlSelf->io_dout_mempot_6 = ((IData)(vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT___R0_en_d0)
                                 ? vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory
                                [vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT___R0_addr_d0]
                                 : 0U);
    vlSelf->io_dout_mempot_7 = ((IData)(vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT___R0_en_d0)
                                 ? vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory
                                [vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT___R0_addr_d0]
                                 : 0U);
    vlSelf->io_dout_mempot_8 = ((IData)(vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT___R0_en_d0)
                                 ? vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory
                                [vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT___R0_addr_d0]
                                 : 0U);
    __VdfgTmp_hd9153207__0 = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory
        [vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT___R0_addr_d0];
    __VdfgTmp_hda0608a3__0 = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory
        [vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT___R0_addr_d0];
    __VdfgTmp_hfb5fa790__0 = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory
        [vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT___R0_addr_d0];
    __VdfgTmp_h32e8def9__0 = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory
        [vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT___R0_addr_d0];
    __VdfgTmp_hc179140a__0 = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory
        [vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT___R0_addr_d0];
    __VdfgTmp_h492f2847__0 = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory
        [vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT___R0_addr_d0];
    __VdfgTmp_hef936cc7__0 = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory
        [vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT___R0_addr_d0];
    __VdfgTmp_h719cea72__0 = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory
        [vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT___R0_addr_d0];
    __VdfgTmp_h587e5e0b__0 = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory
        [vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT___R0_addr_d0];
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_0 
        = ((IData)(vlSelf->io_wr_enable_mempot_0) | (IData)(vlSelf->pe__DOT__validS3));
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_1 
        = ((IData)(vlSelf->io_wr_enable_mempot_1) | (IData)(vlSelf->pe__DOT__validS3));
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_2 
        = ((IData)(vlSelf->io_wr_enable_mempot_2) | (IData)(vlSelf->pe__DOT__validS3));
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_3 
        = ((IData)(vlSelf->io_wr_enable_mempot_3) | (IData)(vlSelf->pe__DOT__validS3));
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_4 
        = ((IData)(vlSelf->io_wr_enable_mempot_4) | (IData)(vlSelf->pe__DOT__validS3));
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_5 
        = ((IData)(vlSelf->io_wr_enable_mempot_5) | (IData)(vlSelf->pe__DOT__validS3));
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_6 
        = ((IData)(vlSelf->io_wr_enable_mempot_6) | (IData)(vlSelf->pe__DOT__validS3));
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_7 
        = ((IData)(vlSelf->io_wr_enable_mempot_7) | (IData)(vlSelf->pe__DOT__validS3));
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_8 
        = ((IData)(vlSelf->io_wr_enable_mempot_8) | (IData)(vlSelf->pe__DOT__validS3));
    if (vlSelf->io_rd_enable_aeq) {
        vlSelf->pe__DOT__aeqMem__DOT___GEN = vlSelf->pe__DOT__aeqMem__DOT__readCounter;
        vlSelf->pe__DOT__io_rd_enable_aeq = 1U;
    } else {
        vlSelf->pe__DOT__aeqMem__DOT___GEN = 0U;
        vlSelf->pe__DOT__io_rd_enable_aeq = 0U;
    }
    vlSelf->pe__DOT__clock = vlSelf->clock;
    vlSelf->pe__DOT__aeqMem__DOT__reset = vlSelf->pe__DOT__reset;
    vlSelf->pe__DOT__aeqMem__DOT__io_writeData_0 = vlSelf->pe__DOT__io_writeData_aeq_0;
    vlSelf->pe__DOT__aeqMem__DOT__io_writeData_1 = vlSelf->pe__DOT__io_writeData_aeq_1;
    vlSelf->pe__DOT__aeqMem__DOT__io_writeData_2 = vlSelf->pe__DOT__io_writeData_aeq_2;
    vlSelf->pe__DOT__aeqMem__DOT__io_writeData_3 = vlSelf->pe__DOT__io_writeData_aeq_3;
    vlSelf->pe__DOT__aeqMem__DOT__io_writeData_4 = vlSelf->pe__DOT__io_writeData_aeq_4;
    vlSelf->pe__DOT__aeqMem__DOT__io_writeData_5 = vlSelf->pe__DOT__io_writeData_aeq_5;
    vlSelf->pe__DOT__aeqMem__DOT__io_writeData_6 = vlSelf->pe__DOT__io_writeData_aeq_6;
    vlSelf->pe__DOT__aeqMem__DOT__io_writeData_7 = vlSelf->pe__DOT__io_writeData_aeq_7;
    vlSelf->pe__DOT__aeqMem__DOT__io_writeData_8 = vlSelf->pe__DOT__io_writeData_aeq_8;
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_r_0 = vlSelf->pe__DOT__io_addr_r_mempot_0;
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_r_1 = vlSelf->pe__DOT__io_addr_r_mempot_1;
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_r_2 = vlSelf->pe__DOT__io_addr_r_mempot_2;
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_r_3 = vlSelf->pe__DOT__io_addr_r_mempot_3;
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_r_4 = vlSelf->pe__DOT__io_addr_r_mempot_4;
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_r_5 = vlSelf->pe__DOT__io_addr_r_mempot_5;
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_r_6 = vlSelf->pe__DOT__io_addr_r_mempot_6;
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_r_7 = vlSelf->pe__DOT__io_addr_r_mempot_7;
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_r_8 = vlSelf->pe__DOT__io_addr_r_mempot_8;
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_w_0 = vlSelf->pe__DOT__io_addr_w_mempot_0;
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_w_1 = vlSelf->pe__DOT__io_addr_w_mempot_1;
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_w_2 = vlSelf->pe__DOT__io_addr_w_mempot_2;
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_w_3 = vlSelf->pe__DOT__io_addr_w_mempot_3;
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_w_4 = vlSelf->pe__DOT__io_addr_w_mempot_4;
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_w_5 = vlSelf->pe__DOT__io_addr_w_mempot_5;
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_w_6 = vlSelf->pe__DOT__io_addr_w_mempot_6;
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_w_7 = vlSelf->pe__DOT__io_addr_w_mempot_7;
    vlSelf->pe__DOT__mempotMem__DOT__io_addr_w_8 = vlSelf->pe__DOT__io_addr_w_mempot_8;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_0 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_0;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_1 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_1;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_2 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_2;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_3 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_3;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_4 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_4;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_5 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_5;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_6 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_6;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_7 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_7;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_8 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_8;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_0 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_0;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_1 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_1;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_2 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_2;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_3 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_3;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_4 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_4;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_5 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_5;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_6 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_6;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_7 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_7;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_8 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_8;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_0 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_0;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_1 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_1;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_2 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_2;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_3 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_3;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_4 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_4;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_5 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_5;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_6 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_6;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_7 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_7;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_8 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_8;
    vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_0 
        = vlSelf->pe__DOT__io_wr_enable_aeq_0;
    vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_1 
        = vlSelf->pe__DOT__io_wr_enable_aeq_1;
    vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_2 
        = vlSelf->pe__DOT__io_wr_enable_aeq_2;
    vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_3 
        = vlSelf->pe__DOT__io_wr_enable_aeq_3;
    vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_4 
        = vlSelf->pe__DOT__io_wr_enable_aeq_4;
    vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_5 
        = vlSelf->pe__DOT__io_wr_enable_aeq_5;
    vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_6 
        = vlSelf->pe__DOT__io_wr_enable_aeq_6;
    vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_7 
        = vlSelf->pe__DOT__io_wr_enable_aeq_7;
    vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_8 
        = vlSelf->pe__DOT__io_wr_enable_aeq_8;
    vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_0 
        = vlSelf->pe__DOT__io_rd_enable_mempot_0;
    vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_1 
        = vlSelf->pe__DOT__io_rd_enable_mempot_1;
    vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_2 
        = vlSelf->pe__DOT__io_rd_enable_mempot_2;
    vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_3 
        = vlSelf->pe__DOT__io_rd_enable_mempot_3;
    vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_4 
        = vlSelf->pe__DOT__io_rd_enable_mempot_4;
    vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_5 
        = vlSelf->pe__DOT__io_rd_enable_mempot_5;
    vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_6 
        = vlSelf->pe__DOT__io_rd_enable_mempot_6;
    vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_7 
        = vlSelf->pe__DOT__io_rd_enable_mempot_7;
    vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_8 
        = vlSelf->pe__DOT__io_rd_enable_mempot_8;
    vlSelf->pe__DOT__mempotMem__DOT__io_din_0 = pe__DOT____Vcellinp__mempotMem__io_din_0;
    vlSelf->pe__DOT__mempotMem__DOT__io_din_1 = pe__DOT____Vcellinp__mempotMem__io_din_1;
    vlSelf->pe__DOT__mempotMem__DOT__io_din_2 = pe__DOT____Vcellinp__mempotMem__io_din_2;
    vlSelf->pe__DOT__mempotMem__DOT__io_din_3 = pe__DOT____Vcellinp__mempotMem__io_din_3;
    vlSelf->pe__DOT__mempotMem__DOT__io_din_4 = pe__DOT____Vcellinp__mempotMem__io_din_4;
    vlSelf->pe__DOT__mempotMem__DOT__io_din_5 = pe__DOT____Vcellinp__mempotMem__io_din_5;
    vlSelf->pe__DOT__mempotMem__DOT__io_din_6 = pe__DOT____Vcellinp__mempotMem__io_din_6;
    vlSelf->pe__DOT__mempotMem__DOT__io_din_7 = pe__DOT____Vcellinp__mempotMem__io_din_7;
    vlSelf->pe__DOT__mempotMem__DOT__io_din_8 = pe__DOT____Vcellinp__mempotMem__io_din_8;
    vlSelf->pe__DOT__io_dout_mempot_0 = vlSelf->io_dout_mempot_0;
    vlSelf->pe__DOT___mempotMem_io_dout_0 = vlSelf->io_dout_mempot_0;
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_0 = vlSelf->io_dout_mempot_0;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_0 
        = vlSelf->io_dout_mempot_0;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_data 
        = vlSelf->io_dout_mempot_0;
    vlSelf->pe__DOT__io_dout_mempot_1 = vlSelf->io_dout_mempot_1;
    vlSelf->pe__DOT___mempotMem_io_dout_1 = vlSelf->io_dout_mempot_1;
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_1 = vlSelf->io_dout_mempot_1;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_1 
        = vlSelf->io_dout_mempot_1;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_data 
        = vlSelf->io_dout_mempot_1;
    vlSelf->pe__DOT__io_dout_mempot_2 = vlSelf->io_dout_mempot_2;
    vlSelf->pe__DOT___mempotMem_io_dout_2 = vlSelf->io_dout_mempot_2;
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_2 = vlSelf->io_dout_mempot_2;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_2 
        = vlSelf->io_dout_mempot_2;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_data 
        = vlSelf->io_dout_mempot_2;
    vlSelf->pe__DOT__io_dout_mempot_3 = vlSelf->io_dout_mempot_3;
    vlSelf->pe__DOT___mempotMem_io_dout_3 = vlSelf->io_dout_mempot_3;
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_3 = vlSelf->io_dout_mempot_3;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_3 
        = vlSelf->io_dout_mempot_3;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_data 
        = vlSelf->io_dout_mempot_3;
    vlSelf->pe__DOT__io_dout_mempot_4 = vlSelf->io_dout_mempot_4;
    vlSelf->pe__DOT___mempotMem_io_dout_4 = vlSelf->io_dout_mempot_4;
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_4 = vlSelf->io_dout_mempot_4;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_4 
        = vlSelf->io_dout_mempot_4;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_data 
        = vlSelf->io_dout_mempot_4;
    vlSelf->pe__DOT__io_dout_mempot_5 = vlSelf->io_dout_mempot_5;
    vlSelf->pe__DOT___mempotMem_io_dout_5 = vlSelf->io_dout_mempot_5;
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_5 = vlSelf->io_dout_mempot_5;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_5 
        = vlSelf->io_dout_mempot_5;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_data 
        = vlSelf->io_dout_mempot_5;
    vlSelf->pe__DOT__io_dout_mempot_6 = vlSelf->io_dout_mempot_6;
    vlSelf->pe__DOT___mempotMem_io_dout_6 = vlSelf->io_dout_mempot_6;
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_6 = vlSelf->io_dout_mempot_6;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_6 
        = vlSelf->io_dout_mempot_6;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_data 
        = vlSelf->io_dout_mempot_6;
    vlSelf->pe__DOT__io_dout_mempot_7 = vlSelf->io_dout_mempot_7;
    vlSelf->pe__DOT___mempotMem_io_dout_7 = vlSelf->io_dout_mempot_7;
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_7 = vlSelf->io_dout_mempot_7;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_7 
        = vlSelf->io_dout_mempot_7;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_data 
        = vlSelf->io_dout_mempot_7;
    vlSelf->pe__DOT__io_dout_mempot_8 = vlSelf->io_dout_mempot_8;
    vlSelf->pe__DOT___mempotMem_io_dout_8 = vlSelf->io_dout_mempot_8;
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_8 = vlSelf->io_dout_mempot_8;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_8 
        = vlSelf->io_dout_mempot_8;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_data 
        = vlSelf->io_dout_mempot_8;
    if (vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT___R0_en_d0) {
        vlSelf->io_readData_aeq_0 = (0x1ffU & ((IData)(__VdfgTmp_hd9153207__0) 
                                               >> 1U));
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_data 
            = __VdfgTmp_hd9153207__0;
    } else {
        vlSelf->io_readData_aeq_0 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_data = 0U;
    }
    if (vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT___R0_en_d0) {
        vlSelf->io_readData_aeq_1 = (0x1ffU & ((IData)(__VdfgTmp_hda0608a3__0) 
                                               >> 1U));
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_data 
            = __VdfgTmp_hda0608a3__0;
    } else {
        vlSelf->io_readData_aeq_1 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_data = 0U;
    }
    if (vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT___R0_en_d0) {
        vlSelf->io_readData_aeq_2 = (0x1ffU & ((IData)(__VdfgTmp_hfb5fa790__0) 
                                               >> 1U));
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_data 
            = __VdfgTmp_hfb5fa790__0;
    } else {
        vlSelf->io_readData_aeq_2 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_data = 0U;
    }
    if (vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT___R0_en_d0) {
        vlSelf->io_readData_aeq_3 = (0x1ffU & ((IData)(__VdfgTmp_h32e8def9__0) 
                                               >> 1U));
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_data 
            = __VdfgTmp_h32e8def9__0;
    } else {
        vlSelf->io_readData_aeq_3 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_data = 0U;
    }
    if (vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT___R0_en_d0) {
        vlSelf->io_readData_aeq_4 = (0x1ffU & ((IData)(__VdfgTmp_hc179140a__0) 
                                               >> 1U));
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_data 
            = __VdfgTmp_hc179140a__0;
    } else {
        vlSelf->io_readData_aeq_4 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_data = 0U;
    }
    if (vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT___R0_en_d0) {
        vlSelf->io_readData_aeq_5 = (0x1ffU & ((IData)(__VdfgTmp_h492f2847__0) 
                                               >> 1U));
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_data 
            = __VdfgTmp_h492f2847__0;
    } else {
        vlSelf->io_readData_aeq_5 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_data = 0U;
    }
    if (vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT___R0_en_d0) {
        vlSelf->io_readData_aeq_6 = (0x1ffU & ((IData)(__VdfgTmp_hef936cc7__0) 
                                               >> 1U));
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_data 
            = __VdfgTmp_hef936cc7__0;
    } else {
        vlSelf->io_readData_aeq_6 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_data = 0U;
    }
    if (vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT___R0_en_d0) {
        vlSelf->io_readData_aeq_7 = (0x1ffU & ((IData)(__VdfgTmp_h719cea72__0) 
                                               >> 1U));
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_data 
            = __VdfgTmp_h719cea72__0;
    } else {
        vlSelf->io_readData_aeq_7 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_data = 0U;
    }
    if (vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT___R0_en_d0) {
        vlSelf->io_readData_aeq_8 = (0x1ffU & ((IData)(__VdfgTmp_h587e5e0b__0) 
                                               >> 1U));
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_data 
            = __VdfgTmp_h587e5e0b__0;
    } else {
        vlSelf->io_readData_aeq_8 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_data = 0U;
    }
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_0 
        = pe__DOT____Vcellinp__mempotMem__io_wr_enable_0;
    vlSelf->pe__DOT__mempotMem__DOT___GEN = ((~ (IData)(vlSelf->io_rd_enable_mempot_0)) 
                                             & (IData)(pe__DOT____Vcellinp__mempotMem__io_wr_enable_0));
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_1 
        = pe__DOT____Vcellinp__mempotMem__io_wr_enable_1;
    vlSelf->pe__DOT__mempotMem__DOT___GEN_0 = ((~ (IData)(vlSelf->io_rd_enable_mempot_1)) 
                                               & (IData)(pe__DOT____Vcellinp__mempotMem__io_wr_enable_1));
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_2 
        = pe__DOT____Vcellinp__mempotMem__io_wr_enable_2;
    vlSelf->pe__DOT__mempotMem__DOT___GEN_1 = ((~ (IData)(vlSelf->io_rd_enable_mempot_2)) 
                                               & (IData)(pe__DOT____Vcellinp__mempotMem__io_wr_enable_2));
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_3 
        = pe__DOT____Vcellinp__mempotMem__io_wr_enable_3;
    vlSelf->pe__DOT__mempotMem__DOT___GEN_2 = ((~ (IData)(vlSelf->io_rd_enable_mempot_3)) 
                                               & (IData)(pe__DOT____Vcellinp__mempotMem__io_wr_enable_3));
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_4 
        = pe__DOT____Vcellinp__mempotMem__io_wr_enable_4;
    vlSelf->pe__DOT__mempotMem__DOT___GEN_3 = ((~ (IData)(vlSelf->io_rd_enable_mempot_4)) 
                                               & (IData)(pe__DOT____Vcellinp__mempotMem__io_wr_enable_4));
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_5 
        = pe__DOT____Vcellinp__mempotMem__io_wr_enable_5;
    vlSelf->pe__DOT__mempotMem__DOT___GEN_4 = ((~ (IData)(vlSelf->io_rd_enable_mempot_5)) 
                                               & (IData)(pe__DOT____Vcellinp__mempotMem__io_wr_enable_5));
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_6 
        = pe__DOT____Vcellinp__mempotMem__io_wr_enable_6;
    vlSelf->pe__DOT__mempotMem__DOT___GEN_5 = ((~ (IData)(vlSelf->io_rd_enable_mempot_6)) 
                                               & (IData)(pe__DOT____Vcellinp__mempotMem__io_wr_enable_6));
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_7 
        = pe__DOT____Vcellinp__mempotMem__io_wr_enable_7;
    vlSelf->pe__DOT__mempotMem__DOT___GEN_6 = ((~ (IData)(vlSelf->io_rd_enable_mempot_7)) 
                                               & (IData)(pe__DOT____Vcellinp__mempotMem__io_wr_enable_7));
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_8 
        = pe__DOT____Vcellinp__mempotMem__io_wr_enable_8;
    vlSelf->pe__DOT__mempotMem__DOT___GEN_7 = ((~ (IData)(vlSelf->io_rd_enable_mempot_8)) 
                                               & (IData)(pe__DOT____Vcellinp__mempotMem__io_wr_enable_8));
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_0 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_1 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_2 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_3 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_4 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_5 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_6 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_7 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_8 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__io_readEnable = vlSelf->pe__DOT__io_rd_enable_aeq;
    vlSelf->pe__DOT__aeqMem__DOT__clock = vlSelf->pe__DOT__clock;
    vlSelf->pe__DOT__mempotMem__DOT__clock = vlSelf->pe__DOT__clock;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_0;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_1;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_2;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_3;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_4;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_5;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_6;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_7;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_8;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_0;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_1;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_2;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_3;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_4;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_5;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_6;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_7;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdAddr_8;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__W0_data 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_0;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__W0_data 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_1;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__W0_data 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_2;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__W0_data 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_3;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__W0_data 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_4;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__W0_data 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_5;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__W0_data 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_6;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__W0_data 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_7;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__W0_data 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_8;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_0 
        = vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_0;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_1 
        = vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_1;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_2 
        = vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_2;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_3 
        = vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_3;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_4 
        = vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_4;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_5 
        = vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_5;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_6 
        = vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_6;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_7 
        = vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_7;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_8 
        = vlSelf->pe__DOT__aeqMem__DOT__io_writeEnable_8;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_0 
        = vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_0;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_1 
        = vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_1;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_2 
        = vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_2;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_3 
        = vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_3;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_4 
        = vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_4;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_5 
        = vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_5;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_6 
        = vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_6;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_7 
        = vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_7;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_8 
        = vlSelf->pe__DOT__mempotMem__DOT__io_rd_enable_8;
    vlSelf->pe__DOT__io_readData_aeq_0 = vlSelf->io_readData_aeq_0;
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_0 = vlSelf->io_readData_aeq_0;
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_0 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_data;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_0 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_data;
    vlSelf->pe__DOT__io_readData_aeq_1 = vlSelf->io_readData_aeq_1;
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_1 = vlSelf->io_readData_aeq_1;
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_1 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_data;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_1 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_data;
    vlSelf->pe__DOT__io_readData_aeq_2 = vlSelf->io_readData_aeq_2;
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_2 = vlSelf->io_readData_aeq_2;
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_2 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_data;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_2 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_data;
    vlSelf->pe__DOT__io_readData_aeq_3 = vlSelf->io_readData_aeq_3;
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_3 = vlSelf->io_readData_aeq_3;
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_3 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_data;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_3 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_data;
    vlSelf->pe__DOT__io_readData_aeq_4 = vlSelf->io_readData_aeq_4;
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_4 = vlSelf->io_readData_aeq_4;
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_4 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_data;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_4 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_data;
    vlSelf->pe__DOT__io_readData_aeq_5 = vlSelf->io_readData_aeq_5;
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_5 = vlSelf->io_readData_aeq_5;
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_5 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_data;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_5 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_data;
    vlSelf->pe__DOT__io_readData_aeq_6 = vlSelf->io_readData_aeq_6;
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_6 = vlSelf->io_readData_aeq_6;
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_6 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_data;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_6 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_data;
    vlSelf->pe__DOT__io_readData_aeq_7 = vlSelf->io_readData_aeq_7;
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_7 = vlSelf->io_readData_aeq_7;
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_7 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_data;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_7 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_data;
    vlSelf->pe__DOT__io_readData_aeq_8 = vlSelf->io_readData_aeq_8;
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_8 = vlSelf->io_readData_aeq_8;
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_8 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_data;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_8 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_data;
    if (vlSelf->pe__DOT__mempotMem__DOT___GEN) {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_0 
            = vlSelf->io_addr_w_mempot_0;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_0 
            = pe__DOT____Vcellinp__mempotMem__io_din_0;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_0 
            = pe__DOT____Vcellinp__mempotMem__io_wr_enable_0;
    } else {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_0 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_0 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_0 = 0U;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT___GEN_0) {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_1 
            = vlSelf->io_addr_w_mempot_1;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_1 
            = pe__DOT____Vcellinp__mempotMem__io_din_1;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_1 
            = pe__DOT____Vcellinp__mempotMem__io_wr_enable_1;
    } else {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_1 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_1 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_1 = 0U;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT___GEN_1) {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_2 
            = vlSelf->io_addr_w_mempot_2;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_2 
            = pe__DOT____Vcellinp__mempotMem__io_din_2;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_2 
            = pe__DOT____Vcellinp__mempotMem__io_wr_enable_2;
    } else {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_2 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_2 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_2 = 0U;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT___GEN_2) {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_3 
            = vlSelf->io_addr_w_mempot_3;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_3 
            = pe__DOT____Vcellinp__mempotMem__io_din_3;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_3 
            = pe__DOT____Vcellinp__mempotMem__io_wr_enable_3;
    } else {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_3 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_3 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_3 = 0U;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT___GEN_3) {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_4 
            = vlSelf->io_addr_w_mempot_4;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_4 
            = pe__DOT____Vcellinp__mempotMem__io_din_4;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_4 
            = pe__DOT____Vcellinp__mempotMem__io_wr_enable_4;
    } else {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_4 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_4 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_4 = 0U;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT___GEN_4) {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_5 
            = vlSelf->io_addr_w_mempot_5;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_5 
            = pe__DOT____Vcellinp__mempotMem__io_din_5;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_5 
            = pe__DOT____Vcellinp__mempotMem__io_wr_enable_5;
    } else {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_5 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_5 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_5 = 0U;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT___GEN_5) {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_6 
            = vlSelf->io_addr_w_mempot_6;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_6 
            = pe__DOT____Vcellinp__mempotMem__io_din_6;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_6 
            = pe__DOT____Vcellinp__mempotMem__io_wr_enable_6;
    } else {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_6 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_6 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_6 = 0U;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT___GEN_6) {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_7 
            = vlSelf->io_addr_w_mempot_7;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_7 
            = pe__DOT____Vcellinp__mempotMem__io_din_7;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_7 
            = pe__DOT____Vcellinp__mempotMem__io_wr_enable_7;
    } else {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_7 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_7 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_7 = 0U;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT___GEN_7) {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_8 
            = vlSelf->io_addr_w_mempot_8;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_8 
            = pe__DOT____Vcellinp__mempotMem__io_din_8;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_8 
            = pe__DOT____Vcellinp__mempotMem__io_wr_enable_8;
    } else {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_8 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_8 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_8 = 0U;
    }
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_0;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_1;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_2;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_3;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_4;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_5;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_6;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_7;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_8;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_0 
        = vlSelf->pe__DOT__aeqMem__DOT__io_readEnable;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_1 
        = vlSelf->pe__DOT__aeqMem__DOT__io_readEnable;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_2 
        = vlSelf->pe__DOT__aeqMem__DOT__io_readEnable;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_3 
        = vlSelf->pe__DOT__aeqMem__DOT__io_readEnable;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_4 
        = vlSelf->pe__DOT__aeqMem__DOT__io_readEnable;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_5 
        = vlSelf->pe__DOT__aeqMem__DOT__io_readEnable;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_6 
        = vlSelf->pe__DOT__aeqMem__DOT__io_readEnable;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_7 
        = vlSelf->pe__DOT__aeqMem__DOT__io_readEnable;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_8 
        = vlSelf->pe__DOT__aeqMem__DOT__io_readEnable;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__clock 
        = vlSelf->pe__DOT__aeqMem__DOT__clock;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__clock 
        = vlSelf->pe__DOT__mempotMem__DOT__clock;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__W0_en 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_0;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__W0_en 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_1;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__W0_en 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_2;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__W0_en 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_3;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__W0_en 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_4;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__W0_en 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_5;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__W0_en 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_6;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__W0_en 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_7;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__W0_en 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrEna_8;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_0;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_1;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_2;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_3;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_4;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_5;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_6;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_7;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdEna_8;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_0 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_0;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_0 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_0;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_0 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_0;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_1 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_1;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_1 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_1;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_1 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_1;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_2 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_2;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_2 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_2;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_2 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_2;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_3 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_3;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_3 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_3;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_3 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_3;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_4 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_4;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_4 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_4;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_4 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_4;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_5 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_5;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_5 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_5;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_5 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_5;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_6 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_6;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_6 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_6;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_6 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_6;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_7 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_7;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_7 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_7;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_7 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_7;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_8 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_8;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_8 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_8;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_8 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_8;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_en 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_0;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_en 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_1;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_en 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_2;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_en 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_3;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_en 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_4;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_en 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_5;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_en 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_6;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_en 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_7;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_en 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdEna_8;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_clk 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__W0_clk 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_clk 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__W0_clk 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_clk 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__W0_clk 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_clk 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__W0_clk 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_clk 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__W0_clk 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_clk 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__W0_clk 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_clk 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__W0_clk 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_clk 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__W0_clk 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_clk 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__W0_clk 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_clk 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__W0_clk 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_clk 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__W0_clk 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_clk 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__W0_clk 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_clk 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__W0_clk 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_clk 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__W0_clk 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_clk 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__W0_clk 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_clk 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__W0_clk 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_clk 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__W0_clk 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_clk 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__W0_clk 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__clock;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_0;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__W0_data 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_0;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__W0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_0;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_1;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__W0_data 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_1;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__W0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_1;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_2;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__W0_data 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_2;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__W0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_2;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_3;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__W0_data 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_3;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__W0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_3;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_4;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__W0_data 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_4;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__W0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_4;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_5;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__W0_data 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_5;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__W0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_5;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_6;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__W0_data 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_6;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__W0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_6;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_7;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__W0_data 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_7;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__W0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_7;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_8;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__W0_data 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_8;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__W0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_8;
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*8:0*/ pe__DOT____Vcellinp__mempotMem__io_din_8;
    pe__DOT____Vcellinp__mempotMem__io_din_8 = 0;
    SData/*8:0*/ pe__DOT____Vcellinp__mempotMem__io_din_7;
    pe__DOT____Vcellinp__mempotMem__io_din_7 = 0;
    SData/*8:0*/ pe__DOT____Vcellinp__mempotMem__io_din_6;
    pe__DOT____Vcellinp__mempotMem__io_din_6 = 0;
    SData/*8:0*/ pe__DOT____Vcellinp__mempotMem__io_din_5;
    pe__DOT____Vcellinp__mempotMem__io_din_5 = 0;
    SData/*8:0*/ pe__DOT____Vcellinp__mempotMem__io_din_4;
    pe__DOT____Vcellinp__mempotMem__io_din_4 = 0;
    SData/*8:0*/ pe__DOT____Vcellinp__mempotMem__io_din_3;
    pe__DOT____Vcellinp__mempotMem__io_din_3 = 0;
    SData/*8:0*/ pe__DOT____Vcellinp__mempotMem__io_din_2;
    pe__DOT____Vcellinp__mempotMem__io_din_2 = 0;
    SData/*8:0*/ pe__DOT____Vcellinp__mempotMem__io_din_1;
    pe__DOT____Vcellinp__mempotMem__io_din_1 = 0;
    SData/*8:0*/ pe__DOT____Vcellinp__mempotMem__io_din_0;
    pe__DOT____Vcellinp__mempotMem__io_din_0 = 0;
    CData/*0:0*/ pe__DOT____Vcellinp__mempotMem__io_wr_enable_8;
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_8 = 0;
    CData/*0:0*/ pe__DOT____Vcellinp__mempotMem__io_wr_enable_7;
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_7 = 0;
    CData/*0:0*/ pe__DOT____Vcellinp__mempotMem__io_wr_enable_6;
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_6 = 0;
    CData/*0:0*/ pe__DOT____Vcellinp__mempotMem__io_wr_enable_5;
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_5 = 0;
    CData/*0:0*/ pe__DOT____Vcellinp__mempotMem__io_wr_enable_4;
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_4 = 0;
    CData/*0:0*/ pe__DOT____Vcellinp__mempotMem__io_wr_enable_3;
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_3 = 0;
    CData/*0:0*/ pe__DOT____Vcellinp__mempotMem__io_wr_enable_2;
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_2 = 0;
    CData/*0:0*/ pe__DOT____Vcellinp__mempotMem__io_wr_enable_1;
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_1 = 0;
    CData/*0:0*/ pe__DOT____Vcellinp__mempotMem__io_wr_enable_0;
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_0 = 0;
    SData/*10:0*/ __VdfgTmp_hd9153207__0;
    __VdfgTmp_hd9153207__0 = 0;
    SData/*10:0*/ __VdfgTmp_hda0608a3__0;
    __VdfgTmp_hda0608a3__0 = 0;
    SData/*10:0*/ __VdfgTmp_hfb5fa790__0;
    __VdfgTmp_hfb5fa790__0 = 0;
    SData/*10:0*/ __VdfgTmp_h32e8def9__0;
    __VdfgTmp_h32e8def9__0 = 0;
    SData/*10:0*/ __VdfgTmp_hc179140a__0;
    __VdfgTmp_hc179140a__0 = 0;
    SData/*10:0*/ __VdfgTmp_h492f2847__0;
    __VdfgTmp_h492f2847__0 = 0;
    SData/*10:0*/ __VdfgTmp_hef936cc7__0;
    __VdfgTmp_hef936cc7__0 = 0;
    SData/*10:0*/ __VdfgTmp_h719cea72__0;
    __VdfgTmp_h719cea72__0 = 0;
    SData/*10:0*/ __VdfgTmp_h587e5e0b__0;
    __VdfgTmp_h587e5e0b__0 = 0;
    SData/*8:0*/ __Vdly__pe__DOT__s2_memRead_0;
    __Vdly__pe__DOT__s2_memRead_0 = 0;
    SData/*8:0*/ __Vdly__pe__DOT__s2_memRead_1;
    __Vdly__pe__DOT__s2_memRead_1 = 0;
    SData/*8:0*/ __Vdly__pe__DOT__s2_memRead_2;
    __Vdly__pe__DOT__s2_memRead_2 = 0;
    SData/*8:0*/ __Vdly__pe__DOT__s2_memRead_3;
    __Vdly__pe__DOT__s2_memRead_3 = 0;
    SData/*8:0*/ __Vdly__pe__DOT__s2_memRead_4;
    __Vdly__pe__DOT__s2_memRead_4 = 0;
    SData/*8:0*/ __Vdly__pe__DOT__s2_memRead_5;
    __Vdly__pe__DOT__s2_memRead_5 = 0;
    SData/*8:0*/ __Vdly__pe__DOT__s2_memRead_6;
    __Vdly__pe__DOT__s2_memRead_6 = 0;
    SData/*8:0*/ __Vdly__pe__DOT__s2_memRead_7;
    __Vdly__pe__DOT__s2_memRead_7 = 0;
    SData/*8:0*/ __Vdly__pe__DOT__s2_memRead_8;
    __Vdly__pe__DOT__s2_memRead_8 = 0;
    CData/*0:0*/ __Vdly__pe__DOT__validS1;
    __Vdly__pe__DOT__validS1 = 0;
    CData/*0:0*/ __Vdly__pe__DOT__validS2;
    __Vdly__pe__DOT__validS2 = 0;
    CData/*0:0*/ __Vdly__pe__DOT__validS3;
    __Vdly__pe__DOT__validS3 = 0;
    CData/*0:0*/ __Vdly__pe__DOT__validS4;
    __Vdly__pe__DOT__validS4 = 0;
    CData/*7:0*/ __Vdly__pe__DOT__aeqMem__DOT__readCounter;
    __Vdly__pe__DOT__aeqMem__DOT__readCounter = 0;
    CData/*7:0*/ __Vdly__pe__DOT__aeqMem__DOT__writeCounters_7;
    __Vdly__pe__DOT__aeqMem__DOT__writeCounters_7 = 0;
    CData/*7:0*/ __Vdly__pe__DOT__aeqMem__DOT__writeCounters_6;
    __Vdly__pe__DOT__aeqMem__DOT__writeCounters_6 = 0;
    CData/*7:0*/ __Vdly__pe__DOT__aeqMem__DOT__writeCounters_5;
    __Vdly__pe__DOT__aeqMem__DOT__writeCounters_5 = 0;
    CData/*7:0*/ __Vdly__pe__DOT__aeqMem__DOT__writeCounters_4;
    __Vdly__pe__DOT__aeqMem__DOT__writeCounters_4 = 0;
    CData/*7:0*/ __Vdly__pe__DOT__aeqMem__DOT__writeCounters_3;
    __Vdly__pe__DOT__aeqMem__DOT__writeCounters_3 = 0;
    CData/*7:0*/ __Vdly__pe__DOT__aeqMem__DOT__writeCounters_2;
    __Vdly__pe__DOT__aeqMem__DOT__writeCounters_2 = 0;
    CData/*7:0*/ __Vdly__pe__DOT__aeqMem__DOT__writeCounters_1;
    __Vdly__pe__DOT__aeqMem__DOT__writeCounters_1 = 0;
    CData/*7:0*/ __Vdly__pe__DOT__aeqMem__DOT__writeCounters_0;
    __Vdly__pe__DOT__aeqMem__DOT__writeCounters_0 = 0;
    CData/*7:0*/ __Vdly__pe__DOT__aeqMem__DOT__writeCounters_8;
    __Vdly__pe__DOT__aeqMem__DOT__writeCounters_8 = 0;
    CData/*7:0*/ __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0;
    __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0 = 0;
    SData/*10:0*/ __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0;
    __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0;
    __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0;
    __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0 = 0;
    SData/*10:0*/ __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0;
    __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0;
    __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0;
    __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0 = 0;
    SData/*10:0*/ __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0;
    __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0;
    __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0;
    __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0 = 0;
    SData/*10:0*/ __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0;
    __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0;
    __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0;
    __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0 = 0;
    SData/*10:0*/ __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0;
    __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0;
    __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0;
    __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0 = 0;
    SData/*10:0*/ __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0;
    __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0;
    __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0;
    __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0 = 0;
    SData/*10:0*/ __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0;
    __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0;
    __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0;
    __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0 = 0;
    SData/*10:0*/ __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0;
    __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0;
    __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0;
    __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0 = 0;
    SData/*10:0*/ __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0;
    __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0;
    __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0;
    __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0 = 0;
    SData/*8:0*/ __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0;
    __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0;
    __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0;
    __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0 = 0;
    SData/*8:0*/ __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0;
    __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0;
    __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0;
    __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0 = 0;
    SData/*8:0*/ __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0;
    __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0;
    __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0;
    __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0 = 0;
    SData/*8:0*/ __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0;
    __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0;
    __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0;
    __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0 = 0;
    SData/*8:0*/ __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0;
    __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0;
    __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0;
    __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0 = 0;
    SData/*8:0*/ __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0;
    __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0;
    __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0;
    __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0 = 0;
    SData/*8:0*/ __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0;
    __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0;
    __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0;
    __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0 = 0;
    SData/*8:0*/ __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0;
    __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0;
    __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0;
    __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0 = 0;
    SData/*8:0*/ __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0;
    __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0;
    __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0 = 0;
    // Body
    __Vdly__pe__DOT__aeqMem__DOT__writeCounters_8 = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_8;
    __Vdly__pe__DOT__aeqMem__DOT__writeCounters_0 = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_0;
    __Vdly__pe__DOT__aeqMem__DOT__writeCounters_1 = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_1;
    __Vdly__pe__DOT__aeqMem__DOT__writeCounters_2 = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_2;
    __Vdly__pe__DOT__aeqMem__DOT__writeCounters_3 = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_3;
    __Vdly__pe__DOT__aeqMem__DOT__writeCounters_4 = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_4;
    __Vdly__pe__DOT__aeqMem__DOT__writeCounters_5 = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_5;
    __Vdly__pe__DOT__aeqMem__DOT__writeCounters_6 = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_6;
    __Vdly__pe__DOT__aeqMem__DOT__writeCounters_7 = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_7;
    __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0 = 0U;
    __Vdly__pe__DOT__aeqMem__DOT__readCounter = vlSelf->pe__DOT__aeqMem__DOT__readCounter;
    __Vdly__pe__DOT__validS4 = vlSelf->pe__DOT__validS4;
    __Vdly__pe__DOT__validS2 = vlSelf->pe__DOT__validS2;
    __Vdly__pe__DOT__validS1 = vlSelf->pe__DOT__validS1;
    __Vdly__pe__DOT__s2_memRead_8 = vlSelf->pe__DOT__s2_memRead_8;
    __Vdly__pe__DOT__s2_memRead_7 = vlSelf->pe__DOT__s2_memRead_7;
    __Vdly__pe__DOT__s2_memRead_6 = vlSelf->pe__DOT__s2_memRead_6;
    __Vdly__pe__DOT__s2_memRead_5 = vlSelf->pe__DOT__s2_memRead_5;
    __Vdly__pe__DOT__s2_memRead_4 = vlSelf->pe__DOT__s2_memRead_4;
    __Vdly__pe__DOT__s2_memRead_3 = vlSelf->pe__DOT__s2_memRead_3;
    __Vdly__pe__DOT__s2_memRead_2 = vlSelf->pe__DOT__s2_memRead_2;
    __Vdly__pe__DOT__s2_memRead_1 = vlSelf->pe__DOT__s2_memRead_1;
    __Vdly__pe__DOT__s2_memRead_0 = vlSelf->pe__DOT__s2_memRead_0;
    __Vdly__pe__DOT__validS3 = vlSelf->pe__DOT__validS3;
    if (vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_8) {
        __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_8;
        __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0 = 1U;
        __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_8;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_7) {
        __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_7;
        __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0 = 1U;
        __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_7;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_6) {
        __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_6;
        __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0 = 1U;
        __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_6;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_5) {
        __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_5;
        __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0 = 1U;
        __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_5;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_4) {
        __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_4;
        __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0 = 1U;
        __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_4;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_3) {
        __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_3;
        __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0 = 1U;
        __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_3;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_2) {
        __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_2;
        __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0 = 1U;
        __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_2;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_1) {
        __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_1;
        __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0 = 1U;
        __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_1;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_0) {
        __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_0;
        __Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0 = 1U;
        __Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_0;
    }
    vlSelf->pe__DOT__unnamedblk1__DOT___GEN = ((IData)(vlSelf->pe__DOT__validS2) 
                                               & (IData)(vlSelf->pe__DOT__validS3));
    vlSelf->pe__DOT__unnamedblk1__DOT___GEN_0 = ((IData)(vlSelf->pe__DOT__validS1) 
                                                 & (~ (IData)(vlSelf->pe__DOT__unnamedblk1__DOT___GEN)));
    vlSelf->pe__DOT__unnamedblk1__DOT___GEN_1 = ((IData)(vlSelf->pe__DOT__validS2) 
                                                 & (~ (IData)(vlSelf->pe__DOT__unnamedblk1__DOT___GEN)));
    if (vlSelf->reset) {
        __Vdly__pe__DOT__aeqMem__DOT__writeCounters_8 = 0U;
        __Vdly__pe__DOT__aeqMem__DOT__writeCounters_0 = 0U;
        __Vdly__pe__DOT__aeqMem__DOT__writeCounters_1 = 0U;
        __Vdly__pe__DOT__aeqMem__DOT__writeCounters_2 = 0U;
        __Vdly__pe__DOT__aeqMem__DOT__writeCounters_3 = 0U;
        __Vdly__pe__DOT__aeqMem__DOT__writeCounters_4 = 0U;
        __Vdly__pe__DOT__aeqMem__DOT__writeCounters_5 = 0U;
        __Vdly__pe__DOT__aeqMem__DOT__writeCounters_6 = 0U;
        __Vdly__pe__DOT__aeqMem__DOT__writeCounters_7 = 0U;
        __Vdly__pe__DOT__aeqMem__DOT__readCounter = 0U;
        __Vdly__pe__DOT__validS1 = 0U;
        __Vdly__pe__DOT__validS2 = 0U;
        __Vdly__pe__DOT__validS3 = 0U;
        __Vdly__pe__DOT__validS4 = 0U;
    } else {
        if (vlSelf->io_wr_enable_aeq_8) {
            __Vdly__pe__DOT__aeqMem__DOT__writeCounters_8 
                = (0xffU & ((IData)(1U) + (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_8)));
        }
        if (vlSelf->io_wr_enable_aeq_0) {
            __Vdly__pe__DOT__aeqMem__DOT__writeCounters_0 
                = (0xffU & ((IData)(1U) + (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_0)));
        }
        if (vlSelf->io_wr_enable_aeq_1) {
            __Vdly__pe__DOT__aeqMem__DOT__writeCounters_1 
                = (0xffU & ((IData)(1U) + (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_1)));
        }
        if (vlSelf->io_wr_enable_aeq_2) {
            __Vdly__pe__DOT__aeqMem__DOT__writeCounters_2 
                = (0xffU & ((IData)(1U) + (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_2)));
        }
        if (vlSelf->io_wr_enable_aeq_3) {
            __Vdly__pe__DOT__aeqMem__DOT__writeCounters_3 
                = (0xffU & ((IData)(1U) + (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_3)));
        }
        if (vlSelf->io_wr_enable_aeq_4) {
            __Vdly__pe__DOT__aeqMem__DOT__writeCounters_4 
                = (0xffU & ((IData)(1U) + (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_4)));
        }
        if (vlSelf->io_wr_enable_aeq_5) {
            __Vdly__pe__DOT__aeqMem__DOT__writeCounters_5 
                = (0xffU & ((IData)(1U) + (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_5)));
        }
        if (vlSelf->io_wr_enable_aeq_6) {
            __Vdly__pe__DOT__aeqMem__DOT__writeCounters_6 
                = (0xffU & ((IData)(1U) + (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_6)));
        }
        if (vlSelf->io_wr_enable_aeq_7) {
            __Vdly__pe__DOT__aeqMem__DOT__writeCounters_7 
                = (0xffU & ((IData)(1U) + (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_7)));
        }
        if (vlSelf->io_rd_enable_aeq) {
            __Vdly__pe__DOT__aeqMem__DOT__readCounter 
                = (0xffU & ((IData)(1U) + (IData)(vlSelf->pe__DOT__aeqMem__DOT__readCounter)));
        }
        vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk3__DOT___GEN_2 
            = ((IData)(vlSelf->pe__DOT__validS4) & 
               (~ (IData)(vlSelf->pe__DOT__unnamedblk1__DOT___GEN)));
        __Vdly__pe__DOT__validS1 = ((~ (IData)(vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk3__DOT___GEN_2)) 
                                    & (((IData)(vlSelf->io_rd_enable_aeq) 
                                        & (~ (IData)(vlSelf->pe__DOT__unnamedblk1__DOT___GEN))) 
                                       | (IData)(vlSelf->pe__DOT__validS1)));
        __Vdly__pe__DOT__validS2 = ((~ (IData)(vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk3__DOT___GEN_2)) 
                                    & ((IData)(vlSelf->pe__DOT__unnamedblk1__DOT___GEN_0) 
                                       | (IData)(vlSelf->pe__DOT__validS2)));
        __Vdly__pe__DOT__validS3 = ((~ (IData)(vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk3__DOT___GEN_2)) 
                                    & ((IData)(vlSelf->pe__DOT__unnamedblk1__DOT___GEN_1) 
                                       | (IData)(vlSelf->pe__DOT__validS3)));
        __Vdly__pe__DOT__validS4 = ((~ (IData)(vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk3__DOT___GEN_2)) 
                                    & ((IData)(vlSelf->pe__DOT__validS3) 
                                       | (IData)(vlSelf->pe__DOT__validS4)));
    }
    if (((IData)(vlSelf->pe__DOT__validS2) & (IData)(vlSelf->pe__DOT__validS4))) {
        __Vdly__pe__DOT__s2_memRead_0 = vlSelf->pe__DOT__s3_updates_0;
        __Vdly__pe__DOT__s2_memRead_1 = vlSelf->pe__DOT__s3_updates_1;
        __Vdly__pe__DOT__s2_memRead_2 = vlSelf->pe__DOT__s3_updates_2;
        __Vdly__pe__DOT__s2_memRead_3 = vlSelf->pe__DOT__s3_updates_3;
        __Vdly__pe__DOT__s2_memRead_4 = vlSelf->pe__DOT__s3_updates_4;
        __Vdly__pe__DOT__s2_memRead_5 = vlSelf->pe__DOT__s3_updates_5;
        __Vdly__pe__DOT__s2_memRead_6 = vlSelf->pe__DOT__s3_updates_6;
        __Vdly__pe__DOT__s2_memRead_7 = vlSelf->pe__DOT__s3_updates_7;
        __Vdly__pe__DOT__s2_memRead_8 = vlSelf->pe__DOT__s3_updates_8;
    } else if (vlSelf->pe__DOT__unnamedblk1__DOT___GEN_0) {
        __Vdly__pe__DOT__s2_memRead_0 = vlSelf->io_dout_mempot_0;
        __Vdly__pe__DOT__s2_memRead_1 = vlSelf->io_dout_mempot_1;
        __Vdly__pe__DOT__s2_memRead_2 = vlSelf->io_dout_mempot_2;
        __Vdly__pe__DOT__s2_memRead_3 = vlSelf->io_dout_mempot_3;
        __Vdly__pe__DOT__s2_memRead_4 = vlSelf->io_dout_mempot_4;
        __Vdly__pe__DOT__s2_memRead_5 = vlSelf->io_dout_mempot_5;
        __Vdly__pe__DOT__s2_memRead_6 = vlSelf->io_dout_mempot_6;
        __Vdly__pe__DOT__s2_memRead_7 = vlSelf->io_dout_mempot_7;
        __Vdly__pe__DOT__s2_memRead_8 = vlSelf->io_dout_mempot_8;
    }
    if (vlSelf->pe__DOT__unnamedblk1__DOT___GEN_1) {
        vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T 
            = (0x1ffU & ((IData)(vlSelf->pe__DOT__s2_memRead_0) 
                         + (IData)(vlSelf->io_kernel_0)));
        vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_1 
            = (0x1ffU & ((IData)(vlSelf->pe__DOT__s2_memRead_1) 
                         + (IData)(vlSelf->io_kernel_1)));
        vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_2 
            = (0x1ffU & ((IData)(vlSelf->pe__DOT__s2_memRead_2) 
                         + (IData)(vlSelf->io_kernel_2)));
        vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_3 
            = (0x1ffU & ((IData)(vlSelf->pe__DOT__s2_memRead_3) 
                         + (IData)(vlSelf->io_kernel_3)));
        vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_4 
            = (0x1ffU & ((IData)(vlSelf->pe__DOT__s2_memRead_4) 
                         + (IData)(vlSelf->io_kernel_4)));
        vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_5 
            = (0x1ffU & ((IData)(vlSelf->pe__DOT__s2_memRead_5) 
                         + (IData)(vlSelf->io_kernel_5)));
        vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_6 
            = (0x1ffU & ((IData)(vlSelf->pe__DOT__s2_memRead_6) 
                         + (IData)(vlSelf->io_kernel_6)));
        vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_7 
            = (0x1ffU & ((IData)(vlSelf->pe__DOT__s2_memRead_7) 
                         + (IData)(vlSelf->io_kernel_7)));
        vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_8 
            = (0x1ffU & ((IData)(vlSelf->pe__DOT__s2_memRead_8) 
                         + (IData)(vlSelf->io_kernel_8)));
        vlSelf->pe__DOT__s3_updates_0 = ((0x100U & (IData)(vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T))
                                          ? 0xffU : (IData)(vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T));
        vlSelf->pe__DOT__s3_updates_1 = ((0x100U & (IData)(vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_1))
                                          ? 0xffU : (IData)(vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_1));
        vlSelf->pe__DOT__s3_updates_2 = ((0x100U & (IData)(vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_2))
                                          ? 0xffU : (IData)(vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_2));
        vlSelf->pe__DOT__s3_updates_3 = ((0x100U & (IData)(vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_3))
                                          ? 0xffU : (IData)(vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_3));
        vlSelf->pe__DOT__s3_updates_4 = ((0x100U & (IData)(vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_4))
                                          ? 0xffU : (IData)(vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_4));
        vlSelf->pe__DOT__s3_updates_5 = ((0x100U & (IData)(vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_5))
                                          ? 0xffU : (IData)(vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_5));
        vlSelf->pe__DOT__s3_updates_6 = ((0x100U & (IData)(vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_6))
                                          ? 0xffU : (IData)(vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_6));
        vlSelf->pe__DOT__s3_updates_7 = ((0x100U & (IData)(vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_7))
                                          ? 0xffU : (IData)(vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_7));
        vlSelf->pe__DOT__s3_updates_8 = ((0x100U & (IData)(vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_8))
                                          ? 0xffU : (IData)(vlSelf->pe__DOT__unnamedblk1__DOT__unnamedblk2__DOT___update_T_8));
    }
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT___R0_en_d0 
        = vlSelf->io_rd_enable_mempot_8;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT___R0_en_d0 
        = vlSelf->io_rd_enable_mempot_7;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT___R0_en_d0 
        = vlSelf->io_rd_enable_mempot_6;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT___R0_en_d0 
        = vlSelf->io_rd_enable_mempot_5;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT___R0_en_d0 
        = vlSelf->io_rd_enable_mempot_4;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT___R0_en_d0 
        = vlSelf->io_rd_enable_mempot_3;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT___R0_en_d0 
        = vlSelf->io_rd_enable_mempot_2;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT___R0_en_d0 
        = vlSelf->io_rd_enable_mempot_1;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT___R0_en_d0 
        = vlSelf->io_rd_enable_mempot_0;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT___R0_addr_d0 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_8;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT___R0_addr_d0 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_7;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT___R0_addr_d0 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_6;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT___R0_addr_d0 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_5;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT___R0_addr_d0 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_4;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT___R0_addr_d0 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_3;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT___R0_addr_d0 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_2;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT___R0_addr_d0 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_1;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT___R0_addr_d0 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_rdAddr_0;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT___R0_en_d0 
        = vlSelf->io_rd_enable_aeq;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT___R0_en_d0 
        = vlSelf->io_rd_enable_aeq;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT___R0_en_d0 
        = vlSelf->io_rd_enable_aeq;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT___R0_en_d0 
        = vlSelf->io_rd_enable_aeq;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT___R0_en_d0 
        = vlSelf->io_rd_enable_aeq;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT___R0_en_d0 
        = vlSelf->io_rd_enable_aeq;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT___R0_en_d0 
        = vlSelf->io_rd_enable_aeq;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT___R0_en_d0 
        = vlSelf->io_rd_enable_aeq;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT___R0_en_d0 
        = vlSelf->io_rd_enable_aeq;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT___R0_addr_d0 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT___R0_addr_d0 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT___R0_addr_d0 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT___R0_addr_d0 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT___R0_addr_d0 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT___R0_addr_d0 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT___R0_addr_d0 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT___R0_addr_d0 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT___R0_addr_d0 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__writeCounters_8 = __Vdly__pe__DOT__aeqMem__DOT__writeCounters_8;
    if (vlSelf->io_wr_enable_aeq_8) {
        __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_8;
        __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0 = 1U;
        __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_8;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_8 
            = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_8;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_8 
            = (1U | (((IData)((0xffU == (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_8))) 
                      << 0xaU) | ((IData)(vlSelf->io_writeData_aeq_8) 
                                  << 1U)));
    } else {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_8 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_8 = 0U;
    }
    vlSelf->pe__DOT__aeqMem__DOT__writeCounters_0 = __Vdly__pe__DOT__aeqMem__DOT__writeCounters_0;
    if (vlSelf->io_wr_enable_aeq_0) {
        __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_0;
        __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0 = 1U;
        __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_0;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_0 
            = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_0;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_0 
            = (1U | (((IData)((0xffU == (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_0))) 
                      << 0xaU) | ((IData)(vlSelf->io_writeData_aeq_0) 
                                  << 1U)));
    } else {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_0 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_0 = 0U;
    }
    vlSelf->pe__DOT__aeqMem__DOT__writeCounters_1 = __Vdly__pe__DOT__aeqMem__DOT__writeCounters_1;
    if (vlSelf->io_wr_enable_aeq_1) {
        __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_1;
        __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0 = 1U;
        __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_1;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_1 
            = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_1;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_1 
            = (1U | (((IData)((0xffU == (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_1))) 
                      << 0xaU) | ((IData)(vlSelf->io_writeData_aeq_1) 
                                  << 1U)));
    } else {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_1 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_1 = 0U;
    }
    vlSelf->pe__DOT__aeqMem__DOT__writeCounters_2 = __Vdly__pe__DOT__aeqMem__DOT__writeCounters_2;
    if (vlSelf->io_wr_enable_aeq_2) {
        __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_2;
        __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0 = 1U;
        __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_2;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_2 
            = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_2;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_2 
            = (1U | (((IData)((0xffU == (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_2))) 
                      << 0xaU) | ((IData)(vlSelf->io_writeData_aeq_2) 
                                  << 1U)));
    } else {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_2 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_2 = 0U;
    }
    vlSelf->pe__DOT__aeqMem__DOT__writeCounters_3 = __Vdly__pe__DOT__aeqMem__DOT__writeCounters_3;
    if (vlSelf->io_wr_enable_aeq_3) {
        __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_3;
        __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0 = 1U;
        __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_3;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_3 
            = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_3;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_3 
            = (1U | (((IData)((0xffU == (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_3))) 
                      << 0xaU) | ((IData)(vlSelf->io_writeData_aeq_3) 
                                  << 1U)));
    } else {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_3 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_3 = 0U;
    }
    vlSelf->pe__DOT__aeqMem__DOT__writeCounters_4 = __Vdly__pe__DOT__aeqMem__DOT__writeCounters_4;
    if (vlSelf->io_wr_enable_aeq_4) {
        __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_4;
        __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0 = 1U;
        __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_4;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_4 
            = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_4;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_4 
            = (1U | (((IData)((0xffU == (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_4))) 
                      << 0xaU) | ((IData)(vlSelf->io_writeData_aeq_4) 
                                  << 1U)));
    } else {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_4 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_4 = 0U;
    }
    vlSelf->pe__DOT__aeqMem__DOT__writeCounters_5 = __Vdly__pe__DOT__aeqMem__DOT__writeCounters_5;
    if (vlSelf->io_wr_enable_aeq_5) {
        __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_5;
        __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0 = 1U;
        __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_5;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_5 
            = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_5;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_5 
            = (1U | (((IData)((0xffU == (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_5))) 
                      << 0xaU) | ((IData)(vlSelf->io_writeData_aeq_5) 
                                  << 1U)));
    } else {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_5 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_5 = 0U;
    }
    vlSelf->pe__DOT__aeqMem__DOT__writeCounters_6 = __Vdly__pe__DOT__aeqMem__DOT__writeCounters_6;
    if (vlSelf->io_wr_enable_aeq_6) {
        __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_6;
        __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0 = 1U;
        __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_6;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_6 
            = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_6;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_6 
            = (1U | (((IData)((0xffU == (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_6))) 
                      << 0xaU) | ((IData)(vlSelf->io_writeData_aeq_6) 
                                  << 1U)));
    } else {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_6 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_6 = 0U;
    }
    vlSelf->pe__DOT__aeqMem__DOT__writeCounters_7 = __Vdly__pe__DOT__aeqMem__DOT__writeCounters_7;
    if (vlSelf->io_wr_enable_aeq_7) {
        __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_7;
        __Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0 = 1U;
        __Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0 
            = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_7;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_7 
            = vlSelf->pe__DOT__aeqMem__DOT__writeCounters_7;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_7 
            = (1U | (((IData)((0xffU == (IData)(vlSelf->pe__DOT__aeqMem__DOT__writeCounters_7))) 
                      << 0xaU) | ((IData)(vlSelf->io_writeData_aeq_7) 
                                  << 1U)));
    } else {
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_7 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_7 = 0U;
    }
    if (__Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0) {
        vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory[__Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0] 
            = __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0;
    }
    if (__Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0) {
        vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory[__Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0] 
            = __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0;
    }
    if (__Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0) {
        vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory[__Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0] 
            = __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0;
    }
    if (__Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0) {
        vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory[__Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0] 
            = __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0;
    }
    if (__Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0) {
        vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory[__Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0] 
            = __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0;
    }
    if (__Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0) {
        vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory[__Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0] 
            = __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0;
    }
    if (__Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0) {
        vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory[__Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0] 
            = __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0;
    }
    if (__Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0) {
        vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory[__Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0] 
            = __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0;
    }
    if (__Vdlyvset__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0) {
        vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory[__Vdlyvdim0__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0] 
            = __Vdlyvval__pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0;
    }
    if (__Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0) {
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory[__Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0] 
            = __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory__v0;
    }
    if (__Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0) {
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory[__Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0] 
            = __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory__v0;
    }
    if (__Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0) {
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory[__Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0] 
            = __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory__v0;
    }
    if (__Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0) {
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory[__Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0] 
            = __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory__v0;
    }
    if (__Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0) {
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory[__Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0] 
            = __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory__v0;
    }
    if (__Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0) {
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory[__Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0] 
            = __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory__v0;
    }
    if (__Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0) {
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory[__Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0] 
            = __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory__v0;
    }
    if (__Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0) {
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory[__Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0] 
            = __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory__v0;
    }
    if (__Vdlyvset__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0) {
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory[__Vdlyvdim0__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0] 
            = __Vdlyvval__pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory__v0;
    }
    vlSelf->pe__DOT__aeqMem__DOT__readCounter = __Vdly__pe__DOT__aeqMem__DOT__readCounter;
    vlSelf->pe__DOT__s2_memRead_0 = __Vdly__pe__DOT__s2_memRead_0;
    vlSelf->pe__DOT__s2_memRead_1 = __Vdly__pe__DOT__s2_memRead_1;
    vlSelf->pe__DOT__s2_memRead_2 = __Vdly__pe__DOT__s2_memRead_2;
    vlSelf->pe__DOT__s2_memRead_3 = __Vdly__pe__DOT__s2_memRead_3;
    vlSelf->pe__DOT__s2_memRead_4 = __Vdly__pe__DOT__s2_memRead_4;
    vlSelf->pe__DOT__s2_memRead_5 = __Vdly__pe__DOT__s2_memRead_5;
    vlSelf->pe__DOT__s2_memRead_6 = __Vdly__pe__DOT__s2_memRead_6;
    vlSelf->pe__DOT__s2_memRead_7 = __Vdly__pe__DOT__s2_memRead_7;
    vlSelf->pe__DOT__s2_memRead_8 = __Vdly__pe__DOT__s2_memRead_8;
    vlSelf->pe__DOT__validS1 = __Vdly__pe__DOT__validS1;
    vlSelf->pe__DOT__validS2 = __Vdly__pe__DOT__validS2;
    vlSelf->pe__DOT__validS4 = __Vdly__pe__DOT__validS4;
    vlSelf->pe__DOT__validS3 = __Vdly__pe__DOT__validS3;
    vlSelf->pe__DOT__aeqMem__DOT___GEN = ((IData)(vlSelf->io_rd_enable_aeq)
                                           ? (IData)(vlSelf->pe__DOT__aeqMem__DOT__readCounter)
                                           : 0U);
    if (vlSelf->pe__DOT__validS3) {
        pe__DOT____Vcellinp__mempotMem__io_din_0 = vlSelf->pe__DOT__s3_updates_0;
        pe__DOT____Vcellinp__mempotMem__io_din_1 = vlSelf->pe__DOT__s3_updates_1;
        pe__DOT____Vcellinp__mempotMem__io_din_2 = vlSelf->pe__DOT__s3_updates_2;
        pe__DOT____Vcellinp__mempotMem__io_din_3 = vlSelf->pe__DOT__s3_updates_3;
        pe__DOT____Vcellinp__mempotMem__io_din_4 = vlSelf->pe__DOT__s3_updates_4;
        pe__DOT____Vcellinp__mempotMem__io_din_5 = vlSelf->pe__DOT__s3_updates_5;
        pe__DOT____Vcellinp__mempotMem__io_din_6 = vlSelf->pe__DOT__s3_updates_6;
        pe__DOT____Vcellinp__mempotMem__io_din_7 = vlSelf->pe__DOT__s3_updates_7;
        pe__DOT____Vcellinp__mempotMem__io_din_8 = vlSelf->pe__DOT__s3_updates_8;
    } else {
        pe__DOT____Vcellinp__mempotMem__io_din_0 = vlSelf->io_din_mempot_0;
        pe__DOT____Vcellinp__mempotMem__io_din_1 = vlSelf->io_din_mempot_1;
        pe__DOT____Vcellinp__mempotMem__io_din_2 = vlSelf->io_din_mempot_2;
        pe__DOT____Vcellinp__mempotMem__io_din_3 = vlSelf->io_din_mempot_3;
        pe__DOT____Vcellinp__mempotMem__io_din_4 = vlSelf->io_din_mempot_4;
        pe__DOT____Vcellinp__mempotMem__io_din_5 = vlSelf->io_din_mempot_5;
        pe__DOT____Vcellinp__mempotMem__io_din_6 = vlSelf->io_din_mempot_6;
        pe__DOT____Vcellinp__mempotMem__io_din_7 = vlSelf->io_din_mempot_7;
        pe__DOT____Vcellinp__mempotMem__io_din_8 = vlSelf->io_din_mempot_8;
    }
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_0 
        = ((IData)(vlSelf->io_wr_enable_mempot_0) | (IData)(vlSelf->pe__DOT__validS3));
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_1 
        = ((IData)(vlSelf->io_wr_enable_mempot_1) | (IData)(vlSelf->pe__DOT__validS3));
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_2 
        = ((IData)(vlSelf->io_wr_enable_mempot_2) | (IData)(vlSelf->pe__DOT__validS3));
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_3 
        = ((IData)(vlSelf->io_wr_enable_mempot_3) | (IData)(vlSelf->pe__DOT__validS3));
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_4 
        = ((IData)(vlSelf->io_wr_enable_mempot_4) | (IData)(vlSelf->pe__DOT__validS3));
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_5 
        = ((IData)(vlSelf->io_wr_enable_mempot_5) | (IData)(vlSelf->pe__DOT__validS3));
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_6 
        = ((IData)(vlSelf->io_wr_enable_mempot_6) | (IData)(vlSelf->pe__DOT__validS3));
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_7 
        = ((IData)(vlSelf->io_wr_enable_mempot_7) | (IData)(vlSelf->pe__DOT__validS3));
    pe__DOT____Vcellinp__mempotMem__io_wr_enable_8 
        = ((IData)(vlSelf->io_wr_enable_mempot_8) | (IData)(vlSelf->pe__DOT__validS3));
    vlSelf->io_dout_mempot_8 = ((IData)(vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT___R0_en_d0)
                                 ? vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory
                                [vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT___R0_addr_d0]
                                 : 0U);
    vlSelf->io_dout_mempot_7 = ((IData)(vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT___R0_en_d0)
                                 ? vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory
                                [vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT___R0_addr_d0]
                                 : 0U);
    vlSelf->io_dout_mempot_6 = ((IData)(vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT___R0_en_d0)
                                 ? vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory
                                [vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT___R0_addr_d0]
                                 : 0U);
    vlSelf->io_dout_mempot_5 = ((IData)(vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT___R0_en_d0)
                                 ? vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory
                                [vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT___R0_addr_d0]
                                 : 0U);
    vlSelf->io_dout_mempot_4 = ((IData)(vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT___R0_en_d0)
                                 ? vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory
                                [vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT___R0_addr_d0]
                                 : 0U);
    vlSelf->io_dout_mempot_3 = ((IData)(vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT___R0_en_d0)
                                 ? vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory
                                [vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT___R0_addr_d0]
                                 : 0U);
    vlSelf->io_dout_mempot_2 = ((IData)(vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT___R0_en_d0)
                                 ? vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory
                                [vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT___R0_addr_d0]
                                 : 0U);
    vlSelf->io_dout_mempot_1 = ((IData)(vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT___R0_en_d0)
                                 ? vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory
                                [vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT___R0_addr_d0]
                                 : 0U);
    vlSelf->io_dout_mempot_0 = ((IData)(vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT___R0_en_d0)
                                 ? vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory
                                [vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT___R0_addr_d0]
                                 : 0U);
    __VdfgTmp_h587e5e0b__0 = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__Memory
        [vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT___R0_addr_d0];
    __VdfgTmp_h719cea72__0 = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__Memory
        [vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT___R0_addr_d0];
    __VdfgTmp_hef936cc7__0 = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__Memory
        [vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT___R0_addr_d0];
    __VdfgTmp_h492f2847__0 = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__Memory
        [vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT___R0_addr_d0];
    __VdfgTmp_hc179140a__0 = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__Memory
        [vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT___R0_addr_d0];
    __VdfgTmp_h32e8def9__0 = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__Memory
        [vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT___R0_addr_d0];
    __VdfgTmp_hfb5fa790__0 = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__Memory
        [vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT___R0_addr_d0];
    __VdfgTmp_hda0608a3__0 = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__Memory
        [vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT___R0_addr_d0];
    __VdfgTmp_hd9153207__0 = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__Memory
        [vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT___R0_addr_d0];
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_8 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_8;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_8 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_8;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_0 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_0;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_0 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_0;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_1 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_1;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_1 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_1;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_2 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_2;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_2 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_2;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_3 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_3;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_3 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_3;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_4 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_4;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_4 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_4;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_5 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_5;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_5 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_5;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_6 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_6;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_6 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_6;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_7 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrAddr_7;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_7 
        = vlSelf->pe__DOT__aeqMem__DOT____Vcellinp__multiMem__io_wrData_7;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_0 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_1 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_2 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_3 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_4 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_5 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_6 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_7 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_8 
        = vlSelf->pe__DOT__aeqMem__DOT___GEN;
    vlSelf->pe__DOT__mempotMem__DOT__io_din_0 = pe__DOT____Vcellinp__mempotMem__io_din_0;
    vlSelf->pe__DOT__mempotMem__DOT__io_din_1 = pe__DOT____Vcellinp__mempotMem__io_din_1;
    vlSelf->pe__DOT__mempotMem__DOT__io_din_2 = pe__DOT____Vcellinp__mempotMem__io_din_2;
    vlSelf->pe__DOT__mempotMem__DOT__io_din_3 = pe__DOT____Vcellinp__mempotMem__io_din_3;
    vlSelf->pe__DOT__mempotMem__DOT__io_din_4 = pe__DOT____Vcellinp__mempotMem__io_din_4;
    vlSelf->pe__DOT__mempotMem__DOT__io_din_5 = pe__DOT____Vcellinp__mempotMem__io_din_5;
    vlSelf->pe__DOT__mempotMem__DOT__io_din_6 = pe__DOT____Vcellinp__mempotMem__io_din_6;
    vlSelf->pe__DOT__mempotMem__DOT__io_din_7 = pe__DOT____Vcellinp__mempotMem__io_din_7;
    vlSelf->pe__DOT__mempotMem__DOT__io_din_8 = pe__DOT____Vcellinp__mempotMem__io_din_8;
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_0 
        = pe__DOT____Vcellinp__mempotMem__io_wr_enable_0;
    vlSelf->pe__DOT__mempotMem__DOT___GEN = ((~ (IData)(vlSelf->io_rd_enable_mempot_0)) 
                                             & (IData)(pe__DOT____Vcellinp__mempotMem__io_wr_enable_0));
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_1 
        = pe__DOT____Vcellinp__mempotMem__io_wr_enable_1;
    vlSelf->pe__DOT__mempotMem__DOT___GEN_0 = ((~ (IData)(vlSelf->io_rd_enable_mempot_1)) 
                                               & (IData)(pe__DOT____Vcellinp__mempotMem__io_wr_enable_1));
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_2 
        = pe__DOT____Vcellinp__mempotMem__io_wr_enable_2;
    vlSelf->pe__DOT__mempotMem__DOT___GEN_1 = ((~ (IData)(vlSelf->io_rd_enable_mempot_2)) 
                                               & (IData)(pe__DOT____Vcellinp__mempotMem__io_wr_enable_2));
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_3 
        = pe__DOT____Vcellinp__mempotMem__io_wr_enable_3;
    vlSelf->pe__DOT__mempotMem__DOT___GEN_2 = ((~ (IData)(vlSelf->io_rd_enable_mempot_3)) 
                                               & (IData)(pe__DOT____Vcellinp__mempotMem__io_wr_enable_3));
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_4 
        = pe__DOT____Vcellinp__mempotMem__io_wr_enable_4;
    vlSelf->pe__DOT__mempotMem__DOT___GEN_3 = ((~ (IData)(vlSelf->io_rd_enable_mempot_4)) 
                                               & (IData)(pe__DOT____Vcellinp__mempotMem__io_wr_enable_4));
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_5 
        = pe__DOT____Vcellinp__mempotMem__io_wr_enable_5;
    vlSelf->pe__DOT__mempotMem__DOT___GEN_4 = ((~ (IData)(vlSelf->io_rd_enable_mempot_5)) 
                                               & (IData)(pe__DOT____Vcellinp__mempotMem__io_wr_enable_5));
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_6 
        = pe__DOT____Vcellinp__mempotMem__io_wr_enable_6;
    vlSelf->pe__DOT__mempotMem__DOT___GEN_5 = ((~ (IData)(vlSelf->io_rd_enable_mempot_6)) 
                                               & (IData)(pe__DOT____Vcellinp__mempotMem__io_wr_enable_6));
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_7 
        = pe__DOT____Vcellinp__mempotMem__io_wr_enable_7;
    vlSelf->pe__DOT__mempotMem__DOT___GEN_6 = ((~ (IData)(vlSelf->io_rd_enable_mempot_7)) 
                                               & (IData)(pe__DOT____Vcellinp__mempotMem__io_wr_enable_7));
    vlSelf->pe__DOT__mempotMem__DOT__io_wr_enable_8 
        = pe__DOT____Vcellinp__mempotMem__io_wr_enable_8;
    vlSelf->pe__DOT__mempotMem__DOT___GEN_7 = ((~ (IData)(vlSelf->io_rd_enable_mempot_8)) 
                                               & (IData)(pe__DOT____Vcellinp__mempotMem__io_wr_enable_8));
    vlSelf->pe__DOT__io_dout_mempot_8 = vlSelf->io_dout_mempot_8;
    vlSelf->pe__DOT___mempotMem_io_dout_8 = vlSelf->io_dout_mempot_8;
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_8 = vlSelf->io_dout_mempot_8;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_8 
        = vlSelf->io_dout_mempot_8;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_data 
        = vlSelf->io_dout_mempot_8;
    vlSelf->pe__DOT__io_dout_mempot_7 = vlSelf->io_dout_mempot_7;
    vlSelf->pe__DOT___mempotMem_io_dout_7 = vlSelf->io_dout_mempot_7;
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_7 = vlSelf->io_dout_mempot_7;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_7 
        = vlSelf->io_dout_mempot_7;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_data 
        = vlSelf->io_dout_mempot_7;
    vlSelf->pe__DOT__io_dout_mempot_6 = vlSelf->io_dout_mempot_6;
    vlSelf->pe__DOT___mempotMem_io_dout_6 = vlSelf->io_dout_mempot_6;
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_6 = vlSelf->io_dout_mempot_6;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_6 
        = vlSelf->io_dout_mempot_6;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_data 
        = vlSelf->io_dout_mempot_6;
    vlSelf->pe__DOT__io_dout_mempot_5 = vlSelf->io_dout_mempot_5;
    vlSelf->pe__DOT___mempotMem_io_dout_5 = vlSelf->io_dout_mempot_5;
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_5 = vlSelf->io_dout_mempot_5;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_5 
        = vlSelf->io_dout_mempot_5;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_data 
        = vlSelf->io_dout_mempot_5;
    vlSelf->pe__DOT__io_dout_mempot_4 = vlSelf->io_dout_mempot_4;
    vlSelf->pe__DOT___mempotMem_io_dout_4 = vlSelf->io_dout_mempot_4;
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_4 = vlSelf->io_dout_mempot_4;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_4 
        = vlSelf->io_dout_mempot_4;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_data 
        = vlSelf->io_dout_mempot_4;
    vlSelf->pe__DOT__io_dout_mempot_3 = vlSelf->io_dout_mempot_3;
    vlSelf->pe__DOT___mempotMem_io_dout_3 = vlSelf->io_dout_mempot_3;
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_3 = vlSelf->io_dout_mempot_3;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_3 
        = vlSelf->io_dout_mempot_3;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_data 
        = vlSelf->io_dout_mempot_3;
    vlSelf->pe__DOT__io_dout_mempot_2 = vlSelf->io_dout_mempot_2;
    vlSelf->pe__DOT___mempotMem_io_dout_2 = vlSelf->io_dout_mempot_2;
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_2 = vlSelf->io_dout_mempot_2;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_2 
        = vlSelf->io_dout_mempot_2;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_data 
        = vlSelf->io_dout_mempot_2;
    vlSelf->pe__DOT__io_dout_mempot_1 = vlSelf->io_dout_mempot_1;
    vlSelf->pe__DOT___mempotMem_io_dout_1 = vlSelf->io_dout_mempot_1;
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_1 = vlSelf->io_dout_mempot_1;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_1 
        = vlSelf->io_dout_mempot_1;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_data 
        = vlSelf->io_dout_mempot_1;
    vlSelf->pe__DOT__io_dout_mempot_0 = vlSelf->io_dout_mempot_0;
    vlSelf->pe__DOT___mempotMem_io_dout_0 = vlSelf->io_dout_mempot_0;
    vlSelf->pe__DOT__mempotMem__DOT__io_dout_0 = vlSelf->io_dout_mempot_0;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_rdData_0 
        = vlSelf->io_dout_mempot_0;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_data 
        = vlSelf->io_dout_mempot_0;
    if (vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT___R0_en_d0) {
        vlSelf->io_readData_aeq_8 = (0x1ffU & ((IData)(__VdfgTmp_h587e5e0b__0) 
                                               >> 1U));
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_data 
            = __VdfgTmp_h587e5e0b__0;
    } else {
        vlSelf->io_readData_aeq_8 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_data = 0U;
    }
    if (vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT___R0_en_d0) {
        vlSelf->io_readData_aeq_7 = (0x1ffU & ((IData)(__VdfgTmp_h719cea72__0) 
                                               >> 1U));
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_data 
            = __VdfgTmp_h719cea72__0;
    } else {
        vlSelf->io_readData_aeq_7 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_data = 0U;
    }
    if (vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT___R0_en_d0) {
        vlSelf->io_readData_aeq_6 = (0x1ffU & ((IData)(__VdfgTmp_hef936cc7__0) 
                                               >> 1U));
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_data 
            = __VdfgTmp_hef936cc7__0;
    } else {
        vlSelf->io_readData_aeq_6 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_data = 0U;
    }
    if (vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT___R0_en_d0) {
        vlSelf->io_readData_aeq_5 = (0x1ffU & ((IData)(__VdfgTmp_h492f2847__0) 
                                               >> 1U));
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_data 
            = __VdfgTmp_h492f2847__0;
    } else {
        vlSelf->io_readData_aeq_5 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_data = 0U;
    }
    if (vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT___R0_en_d0) {
        vlSelf->io_readData_aeq_4 = (0x1ffU & ((IData)(__VdfgTmp_hc179140a__0) 
                                               >> 1U));
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_data 
            = __VdfgTmp_hc179140a__0;
    } else {
        vlSelf->io_readData_aeq_4 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_data = 0U;
    }
    if (vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT___R0_en_d0) {
        vlSelf->io_readData_aeq_3 = (0x1ffU & ((IData)(__VdfgTmp_h32e8def9__0) 
                                               >> 1U));
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_data 
            = __VdfgTmp_h32e8def9__0;
    } else {
        vlSelf->io_readData_aeq_3 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_data = 0U;
    }
    if (vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT___R0_en_d0) {
        vlSelf->io_readData_aeq_2 = (0x1ffU & ((IData)(__VdfgTmp_hfb5fa790__0) 
                                               >> 1U));
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_data 
            = __VdfgTmp_hfb5fa790__0;
    } else {
        vlSelf->io_readData_aeq_2 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_data = 0U;
    }
    if (vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT___R0_en_d0) {
        vlSelf->io_readData_aeq_1 = (0x1ffU & ((IData)(__VdfgTmp_hda0608a3__0) 
                                               >> 1U));
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_data 
            = __VdfgTmp_hda0608a3__0;
    } else {
        vlSelf->io_readData_aeq_1 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_data = 0U;
    }
    if (vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT___R0_en_d0) {
        vlSelf->io_readData_aeq_0 = (0x1ffU & ((IData)(__VdfgTmp_hd9153207__0) 
                                               >> 1U));
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_data 
            = __VdfgTmp_hd9153207__0;
    } else {
        vlSelf->io_readData_aeq_0 = 0U;
        vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_data = 0U;
    }
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_8;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__W0_data 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_8;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_0;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__W0_data 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_0;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_1;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__W0_data 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_1;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_2;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__W0_data 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_2;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_3;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__W0_data 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_3;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_4;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__W0_data 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_4;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_5;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__W0_data 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_5;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_6;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__W0_data 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_6;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrAddr_7;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__W0_data 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_wrData_7;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_0;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_1;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_2;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_3;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_4;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_5;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_6;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_7;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_addr 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdAddr_8;
    if (vlSelf->pe__DOT__mempotMem__DOT___GEN) {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_0 
            = vlSelf->io_addr_w_mempot_0;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_0 
            = pe__DOT____Vcellinp__mempotMem__io_din_0;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_0 
            = pe__DOT____Vcellinp__mempotMem__io_wr_enable_0;
    } else {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_0 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_0 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_0 = 0U;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT___GEN_0) {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_1 
            = vlSelf->io_addr_w_mempot_1;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_1 
            = pe__DOT____Vcellinp__mempotMem__io_din_1;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_1 
            = pe__DOT____Vcellinp__mempotMem__io_wr_enable_1;
    } else {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_1 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_1 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_1 = 0U;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT___GEN_1) {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_2 
            = vlSelf->io_addr_w_mempot_2;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_2 
            = pe__DOT____Vcellinp__mempotMem__io_din_2;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_2 
            = pe__DOT____Vcellinp__mempotMem__io_wr_enable_2;
    } else {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_2 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_2 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_2 = 0U;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT___GEN_2) {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_3 
            = vlSelf->io_addr_w_mempot_3;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_3 
            = pe__DOT____Vcellinp__mempotMem__io_din_3;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_3 
            = pe__DOT____Vcellinp__mempotMem__io_wr_enable_3;
    } else {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_3 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_3 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_3 = 0U;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT___GEN_3) {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_4 
            = vlSelf->io_addr_w_mempot_4;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_4 
            = pe__DOT____Vcellinp__mempotMem__io_din_4;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_4 
            = pe__DOT____Vcellinp__mempotMem__io_wr_enable_4;
    } else {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_4 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_4 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_4 = 0U;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT___GEN_4) {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_5 
            = vlSelf->io_addr_w_mempot_5;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_5 
            = pe__DOT____Vcellinp__mempotMem__io_din_5;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_5 
            = pe__DOT____Vcellinp__mempotMem__io_wr_enable_5;
    } else {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_5 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_5 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_5 = 0U;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT___GEN_5) {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_6 
            = vlSelf->io_addr_w_mempot_6;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_6 
            = pe__DOT____Vcellinp__mempotMem__io_din_6;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_6 
            = pe__DOT____Vcellinp__mempotMem__io_wr_enable_6;
    } else {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_6 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_6 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_6 = 0U;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT___GEN_6) {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_7 
            = vlSelf->io_addr_w_mempot_7;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_7 
            = pe__DOT____Vcellinp__mempotMem__io_din_7;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_7 
            = pe__DOT____Vcellinp__mempotMem__io_wr_enable_7;
    } else {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_7 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_7 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_7 = 0U;
    }
    if (vlSelf->pe__DOT__mempotMem__DOT___GEN_7) {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_8 
            = vlSelf->io_addr_w_mempot_8;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_8 
            = pe__DOT____Vcellinp__mempotMem__io_din_8;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_8 
            = pe__DOT____Vcellinp__mempotMem__io_wr_enable_8;
    } else {
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_8 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_8 = 0U;
        vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_8 = 0U;
    }
    vlSelf->pe__DOT__io_readData_aeq_8 = vlSelf->io_readData_aeq_8;
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_8 = vlSelf->io_readData_aeq_8;
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_8 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_data;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_8 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_8_ext__DOT__R0_data;
    vlSelf->pe__DOT__io_readData_aeq_7 = vlSelf->io_readData_aeq_7;
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_7 = vlSelf->io_readData_aeq_7;
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_7 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_data;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_7 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_7_ext__DOT__R0_data;
    vlSelf->pe__DOT__io_readData_aeq_6 = vlSelf->io_readData_aeq_6;
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_6 = vlSelf->io_readData_aeq_6;
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_6 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_data;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_6 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_6_ext__DOT__R0_data;
    vlSelf->pe__DOT__io_readData_aeq_5 = vlSelf->io_readData_aeq_5;
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_5 = vlSelf->io_readData_aeq_5;
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_5 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_data;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_5 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_5_ext__DOT__R0_data;
    vlSelf->pe__DOT__io_readData_aeq_4 = vlSelf->io_readData_aeq_4;
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_4 = vlSelf->io_readData_aeq_4;
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_4 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_data;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_4 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_4_ext__DOT__R0_data;
    vlSelf->pe__DOT__io_readData_aeq_3 = vlSelf->io_readData_aeq_3;
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_3 = vlSelf->io_readData_aeq_3;
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_3 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_data;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_3 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_3_ext__DOT__R0_data;
    vlSelf->pe__DOT__io_readData_aeq_2 = vlSelf->io_readData_aeq_2;
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_2 = vlSelf->io_readData_aeq_2;
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_2 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_data;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_2 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_2_ext__DOT__R0_data;
    vlSelf->pe__DOT__io_readData_aeq_1 = vlSelf->io_readData_aeq_1;
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_1 = vlSelf->io_readData_aeq_1;
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_1 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_data;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_1 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_1_ext__DOT__R0_data;
    vlSelf->pe__DOT__io_readData_aeq_0 = vlSelf->io_readData_aeq_0;
    vlSelf->pe__DOT__aeqMem__DOT__io_readData_0 = vlSelf->io_readData_aeq_0;
    vlSelf->pe__DOT__aeqMem__DOT___multiMem_io_rdData_0 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_data;
    vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__io_rdData_0 
        = vlSelf->pe__DOT__aeqMem__DOT__multiMem__DOT__mems_0_ext__DOT__R0_data;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_0 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_0;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_0 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_0;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_0 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_0;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_1 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_1;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_1 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_1;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_1 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_1;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_2 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_2;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_2 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_2;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_2 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_2;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_3 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_3;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_3 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_3;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_3 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_3;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_4 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_4;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_4 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_4;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_4 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_4;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_5 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_5;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_5 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_5;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_5 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_5;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_6 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_6;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_6 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_6;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_6 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_6;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_7 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_7;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_7 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_7;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_7 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_7;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_8 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrAddr_8;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_8 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrData_8;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_8 
        = vlSelf->pe__DOT__mempotMem__DOT____Vcellinp__multiMem__io_wrEna_8;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_0;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__W0_data 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_0;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_0_ext__DOT__W0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_0;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_1;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__W0_data 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_1;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_1_ext__DOT__W0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_1;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_2;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__W0_data 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_2;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_2_ext__DOT__W0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_2;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_3;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__W0_data 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_3;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_3_ext__DOT__W0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_3;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_4;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__W0_data 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_4;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_4_ext__DOT__W0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_4;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_5;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__W0_data 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_5;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_5_ext__DOT__W0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_5;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_6;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__W0_data 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_6;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_6_ext__DOT__W0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_6;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_7;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__W0_data 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_7;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_7_ext__DOT__W0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_7;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__W0_addr 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrAddr_8;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__W0_data 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrData_8;
    vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__mems_8_ext__DOT__W0_en 
        = vlSelf->pe__DOT__mempotMem__DOT__multiMem__DOT__io_wrEna_8;
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
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
        Vtop___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("../pe.sv", 762, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vtop___024root___eval_ico(vlSelf);
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
            Vtop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("../pe.sv", 762, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("../pe.sv", 762, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->io_wr_enable_aeq_0 & 0xfeU))) {
        Verilated::overWidthError("io_wr_enable_aeq_0");}
    if (VL_UNLIKELY((vlSelf->io_wr_enable_aeq_1 & 0xfeU))) {
        Verilated::overWidthError("io_wr_enable_aeq_1");}
    if (VL_UNLIKELY((vlSelf->io_wr_enable_aeq_2 & 0xfeU))) {
        Verilated::overWidthError("io_wr_enable_aeq_2");}
    if (VL_UNLIKELY((vlSelf->io_wr_enable_aeq_3 & 0xfeU))) {
        Verilated::overWidthError("io_wr_enable_aeq_3");}
    if (VL_UNLIKELY((vlSelf->io_wr_enable_aeq_4 & 0xfeU))) {
        Verilated::overWidthError("io_wr_enable_aeq_4");}
    if (VL_UNLIKELY((vlSelf->io_wr_enable_aeq_5 & 0xfeU))) {
        Verilated::overWidthError("io_wr_enable_aeq_5");}
    if (VL_UNLIKELY((vlSelf->io_wr_enable_aeq_6 & 0xfeU))) {
        Verilated::overWidthError("io_wr_enable_aeq_6");}
    if (VL_UNLIKELY((vlSelf->io_wr_enable_aeq_7 & 0xfeU))) {
        Verilated::overWidthError("io_wr_enable_aeq_7");}
    if (VL_UNLIKELY((vlSelf->io_wr_enable_aeq_8 & 0xfeU))) {
        Verilated::overWidthError("io_wr_enable_aeq_8");}
    if (VL_UNLIKELY((vlSelf->io_rd_enable_aeq & 0xfeU))) {
        Verilated::overWidthError("io_rd_enable_aeq");}
    if (VL_UNLIKELY((vlSelf->io_writeData_aeq_0 & 0xfe00U))) {
        Verilated::overWidthError("io_writeData_aeq_0");}
    if (VL_UNLIKELY((vlSelf->io_writeData_aeq_1 & 0xfe00U))) {
        Verilated::overWidthError("io_writeData_aeq_1");}
    if (VL_UNLIKELY((vlSelf->io_writeData_aeq_2 & 0xfe00U))) {
        Verilated::overWidthError("io_writeData_aeq_2");}
    if (VL_UNLIKELY((vlSelf->io_writeData_aeq_3 & 0xfe00U))) {
        Verilated::overWidthError("io_writeData_aeq_3");}
    if (VL_UNLIKELY((vlSelf->io_writeData_aeq_4 & 0xfe00U))) {
        Verilated::overWidthError("io_writeData_aeq_4");}
    if (VL_UNLIKELY((vlSelf->io_writeData_aeq_5 & 0xfe00U))) {
        Verilated::overWidthError("io_writeData_aeq_5");}
    if (VL_UNLIKELY((vlSelf->io_writeData_aeq_6 & 0xfe00U))) {
        Verilated::overWidthError("io_writeData_aeq_6");}
    if (VL_UNLIKELY((vlSelf->io_writeData_aeq_7 & 0xfe00U))) {
        Verilated::overWidthError("io_writeData_aeq_7");}
    if (VL_UNLIKELY((vlSelf->io_writeData_aeq_8 & 0xfe00U))) {
        Verilated::overWidthError("io_writeData_aeq_8");}
    if (VL_UNLIKELY((vlSelf->io_wr_enable_mempot_0 
                     & 0xfeU))) {
        Verilated::overWidthError("io_wr_enable_mempot_0");}
    if (VL_UNLIKELY((vlSelf->io_wr_enable_mempot_1 
                     & 0xfeU))) {
        Verilated::overWidthError("io_wr_enable_mempot_1");}
    if (VL_UNLIKELY((vlSelf->io_wr_enable_mempot_2 
                     & 0xfeU))) {
        Verilated::overWidthError("io_wr_enable_mempot_2");}
    if (VL_UNLIKELY((vlSelf->io_wr_enable_mempot_3 
                     & 0xfeU))) {
        Verilated::overWidthError("io_wr_enable_mempot_3");}
    if (VL_UNLIKELY((vlSelf->io_wr_enable_mempot_4 
                     & 0xfeU))) {
        Verilated::overWidthError("io_wr_enable_mempot_4");}
    if (VL_UNLIKELY((vlSelf->io_wr_enable_mempot_5 
                     & 0xfeU))) {
        Verilated::overWidthError("io_wr_enable_mempot_5");}
    if (VL_UNLIKELY((vlSelf->io_wr_enable_mempot_6 
                     & 0xfeU))) {
        Verilated::overWidthError("io_wr_enable_mempot_6");}
    if (VL_UNLIKELY((vlSelf->io_wr_enable_mempot_7 
                     & 0xfeU))) {
        Verilated::overWidthError("io_wr_enable_mempot_7");}
    if (VL_UNLIKELY((vlSelf->io_wr_enable_mempot_8 
                     & 0xfeU))) {
        Verilated::overWidthError("io_wr_enable_mempot_8");}
    if (VL_UNLIKELY((vlSelf->io_rd_enable_mempot_0 
                     & 0xfeU))) {
        Verilated::overWidthError("io_rd_enable_mempot_0");}
    if (VL_UNLIKELY((vlSelf->io_rd_enable_mempot_1 
                     & 0xfeU))) {
        Verilated::overWidthError("io_rd_enable_mempot_1");}
    if (VL_UNLIKELY((vlSelf->io_rd_enable_mempot_2 
                     & 0xfeU))) {
        Verilated::overWidthError("io_rd_enable_mempot_2");}
    if (VL_UNLIKELY((vlSelf->io_rd_enable_mempot_3 
                     & 0xfeU))) {
        Verilated::overWidthError("io_rd_enable_mempot_3");}
    if (VL_UNLIKELY((vlSelf->io_rd_enable_mempot_4 
                     & 0xfeU))) {
        Verilated::overWidthError("io_rd_enable_mempot_4");}
    if (VL_UNLIKELY((vlSelf->io_rd_enable_mempot_5 
                     & 0xfeU))) {
        Verilated::overWidthError("io_rd_enable_mempot_5");}
    if (VL_UNLIKELY((vlSelf->io_rd_enable_mempot_6 
                     & 0xfeU))) {
        Verilated::overWidthError("io_rd_enable_mempot_6");}
    if (VL_UNLIKELY((vlSelf->io_rd_enable_mempot_7 
                     & 0xfeU))) {
        Verilated::overWidthError("io_rd_enable_mempot_7");}
    if (VL_UNLIKELY((vlSelf->io_rd_enable_mempot_8 
                     & 0xfeU))) {
        Verilated::overWidthError("io_rd_enable_mempot_8");}
    if (VL_UNLIKELY((vlSelf->io_din_mempot_0 & 0xfe00U))) {
        Verilated::overWidthError("io_din_mempot_0");}
    if (VL_UNLIKELY((vlSelf->io_din_mempot_1 & 0xfe00U))) {
        Verilated::overWidthError("io_din_mempot_1");}
    if (VL_UNLIKELY((vlSelf->io_din_mempot_2 & 0xfe00U))) {
        Verilated::overWidthError("io_din_mempot_2");}
    if (VL_UNLIKELY((vlSelf->io_din_mempot_3 & 0xfe00U))) {
        Verilated::overWidthError("io_din_mempot_3");}
    if (VL_UNLIKELY((vlSelf->io_din_mempot_4 & 0xfe00U))) {
        Verilated::overWidthError("io_din_mempot_4");}
    if (VL_UNLIKELY((vlSelf->io_din_mempot_5 & 0xfe00U))) {
        Verilated::overWidthError("io_din_mempot_5");}
    if (VL_UNLIKELY((vlSelf->io_din_mempot_6 & 0xfe00U))) {
        Verilated::overWidthError("io_din_mempot_6");}
    if (VL_UNLIKELY((vlSelf->io_din_mempot_7 & 0xfe00U))) {
        Verilated::overWidthError("io_din_mempot_7");}
    if (VL_UNLIKELY((vlSelf->io_din_mempot_8 & 0xfe00U))) {
        Verilated::overWidthError("io_din_mempot_8");}
    if (VL_UNLIKELY((vlSelf->io_thresh_enab & 0xfeU))) {
        Verilated::overWidthError("io_thresh_enab");}
    if (VL_UNLIKELY((vlSelf->io_conv_enab & 0xfeU))) {
        Verilated::overWidthError("io_conv_enab");}
}
#endif  // VL_DEBUG
