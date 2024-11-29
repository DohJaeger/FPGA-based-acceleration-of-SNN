// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VAEQ__Syms.h"


void VAEQ___024root__trace_chg_sub_0(VAEQ___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VAEQ___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root__trace_chg_top_0\n"); );
    // Init
    VAEQ___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VAEQ___024root*>(voidSelf);
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VAEQ___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void VAEQ___024root__trace_chg_sub_0(VAEQ___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->AEQ__DOT__brams_0_MPORT_en));
        bufp->chgBit(oldp+1,(vlSelf->AEQ__DOT__brams_1_MPORT_2_en));
        bufp->chgBit(oldp+2,(vlSelf->AEQ__DOT__brams_2_MPORT_4_en));
        bufp->chgBit(oldp+3,(vlSelf->AEQ__DOT__brams_3_MPORT_6_en));
        bufp->chgBit(oldp+4,(vlSelf->AEQ__DOT__brams_4_MPORT_8_en));
        bufp->chgBit(oldp+5,(vlSelf->AEQ__DOT__brams_5_MPORT_10_en));
        bufp->chgBit(oldp+6,(vlSelf->AEQ__DOT__brams_6_MPORT_12_en));
        bufp->chgBit(oldp+7,(vlSelf->AEQ__DOT__brams_7_MPORT_14_en));
        bufp->chgBit(oldp+8,(vlSelf->AEQ__DOT__brams_8_MPORT_16_en));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+9,(((IData)(vlSelf->AEQ__DOT__brams_0_MPORT_en) 
                              & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_0)))));
        bufp->chgBit(oldp+10,(((IData)(vlSelf->AEQ__DOT__brams_1_MPORT_2_en) 
                               & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_1)))));
        bufp->chgBit(oldp+11,(((IData)(vlSelf->AEQ__DOT__brams_2_MPORT_4_en) 
                               & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_2)))));
        bufp->chgBit(oldp+12,(((IData)(vlSelf->AEQ__DOT__brams_3_MPORT_6_en) 
                               & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_3)))));
        bufp->chgBit(oldp+13,(((IData)(vlSelf->AEQ__DOT__brams_4_MPORT_8_en) 
                               & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_4)))));
        bufp->chgBit(oldp+14,(((IData)(vlSelf->AEQ__DOT__brams_5_MPORT_10_en) 
                               & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_5)))));
        bufp->chgBit(oldp+15,(((IData)(vlSelf->AEQ__DOT__brams_6_MPORT_12_en) 
                               & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_6)))));
        bufp->chgBit(oldp+16,(((IData)(vlSelf->AEQ__DOT__brams_7_MPORT_14_en) 
                               & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_7)))));
        bufp->chgBit(oldp+17,(((IData)(vlSelf->AEQ__DOT__brams_8_MPORT_16_en) 
                               & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_8)))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgCData(oldp+18,(vlSelf->AEQ__DOT__readCounter),8);
        bufp->chgCData(oldp+19,(vlSelf->AEQ__DOT__writeCounters_0),8);
        bufp->chgCData(oldp+20,(vlSelf->AEQ__DOT__writeCounters_1),8);
        bufp->chgCData(oldp+21,(vlSelf->AEQ__DOT__writeCounters_2),8);
        bufp->chgCData(oldp+22,(vlSelf->AEQ__DOT__writeCounters_3),8);
        bufp->chgCData(oldp+23,(vlSelf->AEQ__DOT__writeCounters_4),8);
        bufp->chgCData(oldp+24,(vlSelf->AEQ__DOT__writeCounters_5),8);
        bufp->chgCData(oldp+25,(vlSelf->AEQ__DOT__writeCounters_6),8);
        bufp->chgCData(oldp+26,(vlSelf->AEQ__DOT__writeCounters_7),8);
        bufp->chgCData(oldp+27,(vlSelf->AEQ__DOT__writeCounters_8),8);
    }
    bufp->chgBit(oldp+28,(vlSelf->clock));
    bufp->chgBit(oldp+29,(vlSelf->reset));
    bufp->chgBit(oldp+30,(vlSelf->io_writeEnable_0));
    bufp->chgBit(oldp+31,(vlSelf->io_writeEnable_1));
    bufp->chgBit(oldp+32,(vlSelf->io_writeEnable_2));
    bufp->chgBit(oldp+33,(vlSelf->io_writeEnable_3));
    bufp->chgBit(oldp+34,(vlSelf->io_writeEnable_4));
    bufp->chgBit(oldp+35,(vlSelf->io_writeEnable_5));
    bufp->chgBit(oldp+36,(vlSelf->io_writeEnable_6));
    bufp->chgBit(oldp+37,(vlSelf->io_writeEnable_7));
    bufp->chgBit(oldp+38,(vlSelf->io_writeEnable_8));
    bufp->chgBit(oldp+39,(vlSelf->io_readEnable));
    bufp->chgSData(oldp+40,(vlSelf->io_writeData_0),9);
    bufp->chgSData(oldp+41,(vlSelf->io_writeData_1),9);
    bufp->chgSData(oldp+42,(vlSelf->io_writeData_2),9);
    bufp->chgSData(oldp+43,(vlSelf->io_writeData_3),9);
    bufp->chgSData(oldp+44,(vlSelf->io_writeData_4),9);
    bufp->chgSData(oldp+45,(vlSelf->io_writeData_5),9);
    bufp->chgSData(oldp+46,(vlSelf->io_writeData_6),9);
    bufp->chgSData(oldp+47,(vlSelf->io_writeData_7),9);
    bufp->chgSData(oldp+48,(vlSelf->io_writeData_8),9);
    bufp->chgSData(oldp+49,(vlSelf->io_readData_0),11);
    bufp->chgSData(oldp+50,(vlSelf->io_readData_1),11);
    bufp->chgSData(oldp+51,(vlSelf->io_readData_2),11);
    bufp->chgSData(oldp+52,(vlSelf->io_readData_3),11);
    bufp->chgSData(oldp+53,(vlSelf->io_readData_4),11);
    bufp->chgSData(oldp+54,(vlSelf->io_readData_5),11);
    bufp->chgSData(oldp+55,(vlSelf->io_readData_6),11);
    bufp->chgSData(oldp+56,(vlSelf->io_readData_7),11);
    bufp->chgSData(oldp+57,(vlSelf->io_readData_8),11);
    bufp->chgSData(oldp+58,((1U | ((IData)(vlSelf->io_writeData_0) 
                                   << 1U))),11);
    bufp->chgSData(oldp+59,((0x401U | ((IData)(vlSelf->io_writeData_0) 
                                       << 1U))),11);
    bufp->chgSData(oldp+60,((1U | ((IData)(vlSelf->io_writeData_1) 
                                   << 1U))),11);
    bufp->chgSData(oldp+61,((0x401U | ((IData)(vlSelf->io_writeData_1) 
                                       << 1U))),11);
    bufp->chgSData(oldp+62,((1U | ((IData)(vlSelf->io_writeData_2) 
                                   << 1U))),11);
    bufp->chgSData(oldp+63,((0x401U | ((IData)(vlSelf->io_writeData_2) 
                                       << 1U))),11);
    bufp->chgSData(oldp+64,((1U | ((IData)(vlSelf->io_writeData_3) 
                                   << 1U))),11);
    bufp->chgSData(oldp+65,((0x401U | ((IData)(vlSelf->io_writeData_3) 
                                       << 1U))),11);
    bufp->chgSData(oldp+66,((1U | ((IData)(vlSelf->io_writeData_4) 
                                   << 1U))),11);
    bufp->chgSData(oldp+67,((0x401U | ((IData)(vlSelf->io_writeData_4) 
                                       << 1U))),11);
    bufp->chgSData(oldp+68,((1U | ((IData)(vlSelf->io_writeData_5) 
                                   << 1U))),11);
    bufp->chgSData(oldp+69,((0x401U | ((IData)(vlSelf->io_writeData_5) 
                                       << 1U))),11);
    bufp->chgSData(oldp+70,((1U | ((IData)(vlSelf->io_writeData_6) 
                                   << 1U))),11);
    bufp->chgSData(oldp+71,((0x401U | ((IData)(vlSelf->io_writeData_6) 
                                       << 1U))),11);
    bufp->chgSData(oldp+72,((1U | ((IData)(vlSelf->io_writeData_7) 
                                   << 1U))),11);
    bufp->chgSData(oldp+73,((0x401U | ((IData)(vlSelf->io_writeData_7) 
                                       << 1U))),11);
    bufp->chgSData(oldp+74,((1U | ((IData)(vlSelf->io_writeData_8) 
                                   << 1U))),11);
    bufp->chgSData(oldp+75,((0x401U | ((IData)(vlSelf->io_writeData_8) 
                                       << 1U))),11);
    bufp->chgSData(oldp+76,(vlSelf->io_writeData_0),10);
    bufp->chgSData(oldp+77,((0x200U | (IData)(vlSelf->io_writeData_0))),10);
    bufp->chgSData(oldp+78,(vlSelf->io_writeData_1),10);
    bufp->chgSData(oldp+79,((0x200U | (IData)(vlSelf->io_writeData_1))),10);
    bufp->chgSData(oldp+80,(vlSelf->io_writeData_2),10);
    bufp->chgSData(oldp+81,((0x200U | (IData)(vlSelf->io_writeData_2))),10);
    bufp->chgSData(oldp+82,(vlSelf->io_writeData_3),10);
    bufp->chgSData(oldp+83,((0x200U | (IData)(vlSelf->io_writeData_3))),10);
    bufp->chgSData(oldp+84,(vlSelf->io_writeData_4),10);
    bufp->chgSData(oldp+85,((0x200U | (IData)(vlSelf->io_writeData_4))),10);
    bufp->chgSData(oldp+86,(vlSelf->io_writeData_5),10);
    bufp->chgSData(oldp+87,((0x200U | (IData)(vlSelf->io_writeData_5))),10);
    bufp->chgSData(oldp+88,(vlSelf->io_writeData_6),10);
    bufp->chgSData(oldp+89,((0x200U | (IData)(vlSelf->io_writeData_6))),10);
    bufp->chgSData(oldp+90,(vlSelf->io_writeData_7),10);
    bufp->chgSData(oldp+91,((0x200U | (IData)(vlSelf->io_writeData_7))),10);
    bufp->chgSData(oldp+92,(vlSelf->io_writeData_8),10);
    bufp->chgSData(oldp+93,((0x200U | (IData)(vlSelf->io_writeData_8))),10);
}

void VAEQ___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root__trace_cleanup\n"); );
    // Init
    VAEQ___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VAEQ___024root*>(voidSelf);
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
