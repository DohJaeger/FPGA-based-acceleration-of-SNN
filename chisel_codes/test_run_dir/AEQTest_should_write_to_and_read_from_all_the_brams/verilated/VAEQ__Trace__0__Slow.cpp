// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VAEQ__Syms.h"


VL_ATTR_COLD void VAEQ___024root__trace_init_sub__TOP__0(VAEQ___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+29,"clock", false,-1);
    tracep->declBit(c+30,"reset", false,-1);
    tracep->declBit(c+31,"io_writeEnable_0", false,-1);
    tracep->declBit(c+32,"io_writeEnable_1", false,-1);
    tracep->declBit(c+33,"io_writeEnable_2", false,-1);
    tracep->declBit(c+34,"io_writeEnable_3", false,-1);
    tracep->declBit(c+35,"io_writeEnable_4", false,-1);
    tracep->declBit(c+36,"io_writeEnable_5", false,-1);
    tracep->declBit(c+37,"io_writeEnable_6", false,-1);
    tracep->declBit(c+38,"io_writeEnable_7", false,-1);
    tracep->declBit(c+39,"io_writeEnable_8", false,-1);
    tracep->declBit(c+40,"io_readEnable", false,-1);
    tracep->declBus(c+41,"io_writeData_0", false,-1, 8,0);
    tracep->declBus(c+42,"io_writeData_1", false,-1, 8,0);
    tracep->declBus(c+43,"io_writeData_2", false,-1, 8,0);
    tracep->declBus(c+44,"io_writeData_3", false,-1, 8,0);
    tracep->declBus(c+45,"io_writeData_4", false,-1, 8,0);
    tracep->declBus(c+46,"io_writeData_5", false,-1, 8,0);
    tracep->declBus(c+47,"io_writeData_6", false,-1, 8,0);
    tracep->declBus(c+48,"io_writeData_7", false,-1, 8,0);
    tracep->declBus(c+49,"io_writeData_8", false,-1, 8,0);
    tracep->declBus(c+50,"io_readData_0", false,-1, 10,0);
    tracep->declBus(c+51,"io_readData_1", false,-1, 10,0);
    tracep->declBus(c+52,"io_readData_2", false,-1, 10,0);
    tracep->declBus(c+53,"io_readData_3", false,-1, 10,0);
    tracep->declBus(c+54,"io_readData_4", false,-1, 10,0);
    tracep->declBus(c+55,"io_readData_5", false,-1, 10,0);
    tracep->declBus(c+56,"io_readData_6", false,-1, 10,0);
    tracep->declBus(c+57,"io_readData_7", false,-1, 10,0);
    tracep->declBus(c+58,"io_readData_8", false,-1, 10,0);
    tracep->pushNamePrefix("AEQ ");
    tracep->declBit(c+29,"clock", false,-1);
    tracep->declBit(c+30,"reset", false,-1);
    tracep->declBit(c+31,"io_writeEnable_0", false,-1);
    tracep->declBit(c+32,"io_writeEnable_1", false,-1);
    tracep->declBit(c+33,"io_writeEnable_2", false,-1);
    tracep->declBit(c+34,"io_writeEnable_3", false,-1);
    tracep->declBit(c+35,"io_writeEnable_4", false,-1);
    tracep->declBit(c+36,"io_writeEnable_5", false,-1);
    tracep->declBit(c+37,"io_writeEnable_6", false,-1);
    tracep->declBit(c+38,"io_writeEnable_7", false,-1);
    tracep->declBit(c+39,"io_writeEnable_8", false,-1);
    tracep->declBit(c+40,"io_readEnable", false,-1);
    tracep->declBus(c+41,"io_writeData_0", false,-1, 8,0);
    tracep->declBus(c+42,"io_writeData_1", false,-1, 8,0);
    tracep->declBus(c+43,"io_writeData_2", false,-1, 8,0);
    tracep->declBus(c+44,"io_writeData_3", false,-1, 8,0);
    tracep->declBus(c+45,"io_writeData_4", false,-1, 8,0);
    tracep->declBus(c+46,"io_writeData_5", false,-1, 8,0);
    tracep->declBus(c+47,"io_writeData_6", false,-1, 8,0);
    tracep->declBus(c+48,"io_writeData_7", false,-1, 8,0);
    tracep->declBus(c+49,"io_writeData_8", false,-1, 8,0);
    tracep->declBus(c+50,"io_readData_0", false,-1, 10,0);
    tracep->declBus(c+51,"io_readData_1", false,-1, 10,0);
    tracep->declBus(c+52,"io_readData_2", false,-1, 10,0);
    tracep->declBus(c+53,"io_readData_3", false,-1, 10,0);
    tracep->declBus(c+54,"io_readData_4", false,-1, 10,0);
    tracep->declBus(c+55,"io_readData_5", false,-1, 10,0);
    tracep->declBus(c+56,"io_readData_6", false,-1, 10,0);
    tracep->declBus(c+57,"io_readData_7", false,-1, 10,0);
    tracep->declBus(c+58,"io_readData_8", false,-1, 10,0);
    tracep->declBit(c+40,"brams_0_data1_en", false,-1);
    tracep->declBus(c+19,"brams_0_data1_addr", false,-1, 7,0);
    tracep->declBus(c+50,"brams_0_data1_data", false,-1, 10,0);
    tracep->declBus(c+59,"brams_0_MPORT_data", false,-1, 10,0);
    tracep->declBus(c+20,"brams_0_MPORT_addr", false,-1, 7,0);
    tracep->declBit(c+95,"brams_0_MPORT_mask", false,-1);
    tracep->declBit(c+1,"brams_0_MPORT_en", false,-1);
    tracep->declBus(c+60,"brams_0_MPORT_1_data", false,-1, 10,0);
    tracep->declBus(c+20,"brams_0_MPORT_1_addr", false,-1, 7,0);
    tracep->declBit(c+95,"brams_0_MPORT_1_mask", false,-1);
    tracep->declBit(c+10,"brams_0_MPORT_1_en", false,-1);
    tracep->declBit(c+40,"brams_1_data1_1_en", false,-1);
    tracep->declBus(c+19,"brams_1_data1_1_addr", false,-1, 7,0);
    tracep->declBus(c+51,"brams_1_data1_1_data", false,-1, 10,0);
    tracep->declBus(c+61,"brams_1_MPORT_2_data", false,-1, 10,0);
    tracep->declBus(c+21,"brams_1_MPORT_2_addr", false,-1, 7,0);
    tracep->declBit(c+95,"brams_1_MPORT_2_mask", false,-1);
    tracep->declBit(c+2,"brams_1_MPORT_2_en", false,-1);
    tracep->declBus(c+62,"brams_1_MPORT_3_data", false,-1, 10,0);
    tracep->declBus(c+21,"brams_1_MPORT_3_addr", false,-1, 7,0);
    tracep->declBit(c+95,"brams_1_MPORT_3_mask", false,-1);
    tracep->declBit(c+11,"brams_1_MPORT_3_en", false,-1);
    tracep->declBit(c+40,"brams_2_data1_2_en", false,-1);
    tracep->declBus(c+19,"brams_2_data1_2_addr", false,-1, 7,0);
    tracep->declBus(c+52,"brams_2_data1_2_data", false,-1, 10,0);
    tracep->declBus(c+63,"brams_2_MPORT_4_data", false,-1, 10,0);
    tracep->declBus(c+22,"brams_2_MPORT_4_addr", false,-1, 7,0);
    tracep->declBit(c+95,"brams_2_MPORT_4_mask", false,-1);
    tracep->declBit(c+3,"brams_2_MPORT_4_en", false,-1);
    tracep->declBus(c+64,"brams_2_MPORT_5_data", false,-1, 10,0);
    tracep->declBus(c+22,"brams_2_MPORT_5_addr", false,-1, 7,0);
    tracep->declBit(c+95,"brams_2_MPORT_5_mask", false,-1);
    tracep->declBit(c+12,"brams_2_MPORT_5_en", false,-1);
    tracep->declBit(c+40,"brams_3_data1_3_en", false,-1);
    tracep->declBus(c+19,"brams_3_data1_3_addr", false,-1, 7,0);
    tracep->declBus(c+53,"brams_3_data1_3_data", false,-1, 10,0);
    tracep->declBus(c+65,"brams_3_MPORT_6_data", false,-1, 10,0);
    tracep->declBus(c+23,"brams_3_MPORT_6_addr", false,-1, 7,0);
    tracep->declBit(c+95,"brams_3_MPORT_6_mask", false,-1);
    tracep->declBit(c+4,"brams_3_MPORT_6_en", false,-1);
    tracep->declBus(c+66,"brams_3_MPORT_7_data", false,-1, 10,0);
    tracep->declBus(c+23,"brams_3_MPORT_7_addr", false,-1, 7,0);
    tracep->declBit(c+95,"brams_3_MPORT_7_mask", false,-1);
    tracep->declBit(c+13,"brams_3_MPORT_7_en", false,-1);
    tracep->declBit(c+40,"brams_4_data1_4_en", false,-1);
    tracep->declBus(c+19,"brams_4_data1_4_addr", false,-1, 7,0);
    tracep->declBus(c+54,"brams_4_data1_4_data", false,-1, 10,0);
    tracep->declBus(c+67,"brams_4_MPORT_8_data", false,-1, 10,0);
    tracep->declBus(c+24,"brams_4_MPORT_8_addr", false,-1, 7,0);
    tracep->declBit(c+95,"brams_4_MPORT_8_mask", false,-1);
    tracep->declBit(c+5,"brams_4_MPORT_8_en", false,-1);
    tracep->declBus(c+68,"brams_4_MPORT_9_data", false,-1, 10,0);
    tracep->declBus(c+24,"brams_4_MPORT_9_addr", false,-1, 7,0);
    tracep->declBit(c+95,"brams_4_MPORT_9_mask", false,-1);
    tracep->declBit(c+14,"brams_4_MPORT_9_en", false,-1);
    tracep->declBit(c+40,"brams_5_data1_5_en", false,-1);
    tracep->declBus(c+19,"brams_5_data1_5_addr", false,-1, 7,0);
    tracep->declBus(c+55,"brams_5_data1_5_data", false,-1, 10,0);
    tracep->declBus(c+69,"brams_5_MPORT_10_data", false,-1, 10,0);
    tracep->declBus(c+25,"brams_5_MPORT_10_addr", false,-1, 7,0);
    tracep->declBit(c+95,"brams_5_MPORT_10_mask", false,-1);
    tracep->declBit(c+6,"brams_5_MPORT_10_en", false,-1);
    tracep->declBus(c+70,"brams_5_MPORT_11_data", false,-1, 10,0);
    tracep->declBus(c+25,"brams_5_MPORT_11_addr", false,-1, 7,0);
    tracep->declBit(c+95,"brams_5_MPORT_11_mask", false,-1);
    tracep->declBit(c+15,"brams_5_MPORT_11_en", false,-1);
    tracep->declBit(c+40,"brams_6_data1_6_en", false,-1);
    tracep->declBus(c+19,"brams_6_data1_6_addr", false,-1, 7,0);
    tracep->declBus(c+56,"brams_6_data1_6_data", false,-1, 10,0);
    tracep->declBus(c+71,"brams_6_MPORT_12_data", false,-1, 10,0);
    tracep->declBus(c+26,"brams_6_MPORT_12_addr", false,-1, 7,0);
    tracep->declBit(c+95,"brams_6_MPORT_12_mask", false,-1);
    tracep->declBit(c+7,"brams_6_MPORT_12_en", false,-1);
    tracep->declBus(c+72,"brams_6_MPORT_13_data", false,-1, 10,0);
    tracep->declBus(c+26,"brams_6_MPORT_13_addr", false,-1, 7,0);
    tracep->declBit(c+95,"brams_6_MPORT_13_mask", false,-1);
    tracep->declBit(c+16,"brams_6_MPORT_13_en", false,-1);
    tracep->declBit(c+40,"brams_7_data1_7_en", false,-1);
    tracep->declBus(c+19,"brams_7_data1_7_addr", false,-1, 7,0);
    tracep->declBus(c+57,"brams_7_data1_7_data", false,-1, 10,0);
    tracep->declBus(c+73,"brams_7_MPORT_14_data", false,-1, 10,0);
    tracep->declBus(c+27,"brams_7_MPORT_14_addr", false,-1, 7,0);
    tracep->declBit(c+95,"brams_7_MPORT_14_mask", false,-1);
    tracep->declBit(c+8,"brams_7_MPORT_14_en", false,-1);
    tracep->declBus(c+74,"brams_7_MPORT_15_data", false,-1, 10,0);
    tracep->declBus(c+27,"brams_7_MPORT_15_addr", false,-1, 7,0);
    tracep->declBit(c+95,"brams_7_MPORT_15_mask", false,-1);
    tracep->declBit(c+17,"brams_7_MPORT_15_en", false,-1);
    tracep->declBit(c+40,"brams_8_data1_8_en", false,-1);
    tracep->declBus(c+19,"brams_8_data1_8_addr", false,-1, 7,0);
    tracep->declBus(c+58,"brams_8_data1_8_data", false,-1, 10,0);
    tracep->declBus(c+75,"brams_8_MPORT_16_data", false,-1, 10,0);
    tracep->declBus(c+28,"brams_8_MPORT_16_addr", false,-1, 7,0);
    tracep->declBit(c+95,"brams_8_MPORT_16_mask", false,-1);
    tracep->declBit(c+9,"brams_8_MPORT_16_en", false,-1);
    tracep->declBus(c+76,"brams_8_MPORT_17_data", false,-1, 10,0);
    tracep->declBus(c+28,"brams_8_MPORT_17_addr", false,-1, 7,0);
    tracep->declBit(c+95,"brams_8_MPORT_17_mask", false,-1);
    tracep->declBit(c+18,"brams_8_MPORT_17_en", false,-1);
    tracep->declBus(c+20,"writeCounters_0", false,-1, 7,0);
    tracep->declBus(c+21,"writeCounters_1", false,-1, 7,0);
    tracep->declBus(c+22,"writeCounters_2", false,-1, 7,0);
    tracep->declBus(c+23,"writeCounters_3", false,-1, 7,0);
    tracep->declBus(c+24,"writeCounters_4", false,-1, 7,0);
    tracep->declBus(c+25,"writeCounters_5", false,-1, 7,0);
    tracep->declBus(c+26,"writeCounters_6", false,-1, 7,0);
    tracep->declBus(c+27,"writeCounters_7", false,-1, 7,0);
    tracep->declBus(c+28,"writeCounters_8", false,-1, 7,0);
    tracep->declBus(c+19,"readCounter", false,-1, 7,0);
    tracep->declBus(c+77,"data_hi", false,-1, 9,0);
    tracep->declBus(c+78,"lastData_hi", false,-1, 9,0);
    tracep->declBus(c+79,"data_hi_1", false,-1, 9,0);
    tracep->declBus(c+80,"lastData_hi_1", false,-1, 9,0);
    tracep->declBus(c+81,"data_hi_2", false,-1, 9,0);
    tracep->declBus(c+82,"lastData_hi_2", false,-1, 9,0);
    tracep->declBus(c+83,"data_hi_3", false,-1, 9,0);
    tracep->declBus(c+84,"lastData_hi_3", false,-1, 9,0);
    tracep->declBus(c+85,"data_hi_4", false,-1, 9,0);
    tracep->declBus(c+86,"lastData_hi_4", false,-1, 9,0);
    tracep->declBus(c+87,"data_hi_5", false,-1, 9,0);
    tracep->declBus(c+88,"lastData_hi_5", false,-1, 9,0);
    tracep->declBus(c+89,"data_hi_6", false,-1, 9,0);
    tracep->declBus(c+90,"lastData_hi_6", false,-1, 9,0);
    tracep->declBus(c+91,"data_hi_7", false,-1, 9,0);
    tracep->declBus(c+92,"lastData_hi_7", false,-1, 9,0);
    tracep->declBus(c+93,"data_hi_8", false,-1, 9,0);
    tracep->declBus(c+94,"lastData_hi_8", false,-1, 9,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void VAEQ___024root__trace_init_top(VAEQ___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root__trace_init_top\n"); );
    // Body
    VAEQ___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VAEQ___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VAEQ___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VAEQ___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VAEQ___024root__trace_register(VAEQ___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VAEQ___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VAEQ___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VAEQ___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VAEQ___024root__trace_full_sub_0(VAEQ___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VAEQ___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root__trace_full_top_0\n"); );
    // Init
    VAEQ___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VAEQ___024root*>(voidSelf);
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VAEQ___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VAEQ___024root__trace_full_sub_0(VAEQ___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VAEQ__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAEQ___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->AEQ__DOT__brams_0_MPORT_en));
    bufp->fullBit(oldp+2,(vlSelf->AEQ__DOT__brams_1_MPORT_2_en));
    bufp->fullBit(oldp+3,(vlSelf->AEQ__DOT__brams_2_MPORT_4_en));
    bufp->fullBit(oldp+4,(vlSelf->AEQ__DOT__brams_3_MPORT_6_en));
    bufp->fullBit(oldp+5,(vlSelf->AEQ__DOT__brams_4_MPORT_8_en));
    bufp->fullBit(oldp+6,(vlSelf->AEQ__DOT__brams_5_MPORT_10_en));
    bufp->fullBit(oldp+7,(vlSelf->AEQ__DOT__brams_6_MPORT_12_en));
    bufp->fullBit(oldp+8,(vlSelf->AEQ__DOT__brams_7_MPORT_14_en));
    bufp->fullBit(oldp+9,(vlSelf->AEQ__DOT__brams_8_MPORT_16_en));
    bufp->fullBit(oldp+10,(((IData)(vlSelf->AEQ__DOT__brams_0_MPORT_en) 
                            & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_0)))));
    bufp->fullBit(oldp+11,(((IData)(vlSelf->AEQ__DOT__brams_1_MPORT_2_en) 
                            & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_1)))));
    bufp->fullBit(oldp+12,(((IData)(vlSelf->AEQ__DOT__brams_2_MPORT_4_en) 
                            & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_2)))));
    bufp->fullBit(oldp+13,(((IData)(vlSelf->AEQ__DOT__brams_3_MPORT_6_en) 
                            & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_3)))));
    bufp->fullBit(oldp+14,(((IData)(vlSelf->AEQ__DOT__brams_4_MPORT_8_en) 
                            & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_4)))));
    bufp->fullBit(oldp+15,(((IData)(vlSelf->AEQ__DOT__brams_5_MPORT_10_en) 
                            & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_5)))));
    bufp->fullBit(oldp+16,(((IData)(vlSelf->AEQ__DOT__brams_6_MPORT_12_en) 
                            & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_6)))));
    bufp->fullBit(oldp+17,(((IData)(vlSelf->AEQ__DOT__brams_7_MPORT_14_en) 
                            & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_7)))));
    bufp->fullBit(oldp+18,(((IData)(vlSelf->AEQ__DOT__brams_8_MPORT_16_en) 
                            & (0xffU == (IData)(vlSelf->AEQ__DOT__writeCounters_8)))));
    bufp->fullCData(oldp+19,(vlSelf->AEQ__DOT__readCounter),8);
    bufp->fullCData(oldp+20,(vlSelf->AEQ__DOT__writeCounters_0),8);
    bufp->fullCData(oldp+21,(vlSelf->AEQ__DOT__writeCounters_1),8);
    bufp->fullCData(oldp+22,(vlSelf->AEQ__DOT__writeCounters_2),8);
    bufp->fullCData(oldp+23,(vlSelf->AEQ__DOT__writeCounters_3),8);
    bufp->fullCData(oldp+24,(vlSelf->AEQ__DOT__writeCounters_4),8);
    bufp->fullCData(oldp+25,(vlSelf->AEQ__DOT__writeCounters_5),8);
    bufp->fullCData(oldp+26,(vlSelf->AEQ__DOT__writeCounters_6),8);
    bufp->fullCData(oldp+27,(vlSelf->AEQ__DOT__writeCounters_7),8);
    bufp->fullCData(oldp+28,(vlSelf->AEQ__DOT__writeCounters_8),8);
    bufp->fullBit(oldp+29,(vlSelf->clock));
    bufp->fullBit(oldp+30,(vlSelf->reset));
    bufp->fullBit(oldp+31,(vlSelf->io_writeEnable_0));
    bufp->fullBit(oldp+32,(vlSelf->io_writeEnable_1));
    bufp->fullBit(oldp+33,(vlSelf->io_writeEnable_2));
    bufp->fullBit(oldp+34,(vlSelf->io_writeEnable_3));
    bufp->fullBit(oldp+35,(vlSelf->io_writeEnable_4));
    bufp->fullBit(oldp+36,(vlSelf->io_writeEnable_5));
    bufp->fullBit(oldp+37,(vlSelf->io_writeEnable_6));
    bufp->fullBit(oldp+38,(vlSelf->io_writeEnable_7));
    bufp->fullBit(oldp+39,(vlSelf->io_writeEnable_8));
    bufp->fullBit(oldp+40,(vlSelf->io_readEnable));
    bufp->fullSData(oldp+41,(vlSelf->io_writeData_0),9);
    bufp->fullSData(oldp+42,(vlSelf->io_writeData_1),9);
    bufp->fullSData(oldp+43,(vlSelf->io_writeData_2),9);
    bufp->fullSData(oldp+44,(vlSelf->io_writeData_3),9);
    bufp->fullSData(oldp+45,(vlSelf->io_writeData_4),9);
    bufp->fullSData(oldp+46,(vlSelf->io_writeData_5),9);
    bufp->fullSData(oldp+47,(vlSelf->io_writeData_6),9);
    bufp->fullSData(oldp+48,(vlSelf->io_writeData_7),9);
    bufp->fullSData(oldp+49,(vlSelf->io_writeData_8),9);
    bufp->fullSData(oldp+50,(vlSelf->io_readData_0),11);
    bufp->fullSData(oldp+51,(vlSelf->io_readData_1),11);
    bufp->fullSData(oldp+52,(vlSelf->io_readData_2),11);
    bufp->fullSData(oldp+53,(vlSelf->io_readData_3),11);
    bufp->fullSData(oldp+54,(vlSelf->io_readData_4),11);
    bufp->fullSData(oldp+55,(vlSelf->io_readData_5),11);
    bufp->fullSData(oldp+56,(vlSelf->io_readData_6),11);
    bufp->fullSData(oldp+57,(vlSelf->io_readData_7),11);
    bufp->fullSData(oldp+58,(vlSelf->io_readData_8),11);
    bufp->fullSData(oldp+59,((1U | ((IData)(vlSelf->io_writeData_0) 
                                    << 1U))),11);
    bufp->fullSData(oldp+60,((0x401U | ((IData)(vlSelf->io_writeData_0) 
                                        << 1U))),11);
    bufp->fullSData(oldp+61,((1U | ((IData)(vlSelf->io_writeData_1) 
                                    << 1U))),11);
    bufp->fullSData(oldp+62,((0x401U | ((IData)(vlSelf->io_writeData_1) 
                                        << 1U))),11);
    bufp->fullSData(oldp+63,((1U | ((IData)(vlSelf->io_writeData_2) 
                                    << 1U))),11);
    bufp->fullSData(oldp+64,((0x401U | ((IData)(vlSelf->io_writeData_2) 
                                        << 1U))),11);
    bufp->fullSData(oldp+65,((1U | ((IData)(vlSelf->io_writeData_3) 
                                    << 1U))),11);
    bufp->fullSData(oldp+66,((0x401U | ((IData)(vlSelf->io_writeData_3) 
                                        << 1U))),11);
    bufp->fullSData(oldp+67,((1U | ((IData)(vlSelf->io_writeData_4) 
                                    << 1U))),11);
    bufp->fullSData(oldp+68,((0x401U | ((IData)(vlSelf->io_writeData_4) 
                                        << 1U))),11);
    bufp->fullSData(oldp+69,((1U | ((IData)(vlSelf->io_writeData_5) 
                                    << 1U))),11);
    bufp->fullSData(oldp+70,((0x401U | ((IData)(vlSelf->io_writeData_5) 
                                        << 1U))),11);
    bufp->fullSData(oldp+71,((1U | ((IData)(vlSelf->io_writeData_6) 
                                    << 1U))),11);
    bufp->fullSData(oldp+72,((0x401U | ((IData)(vlSelf->io_writeData_6) 
                                        << 1U))),11);
    bufp->fullSData(oldp+73,((1U | ((IData)(vlSelf->io_writeData_7) 
                                    << 1U))),11);
    bufp->fullSData(oldp+74,((0x401U | ((IData)(vlSelf->io_writeData_7) 
                                        << 1U))),11);
    bufp->fullSData(oldp+75,((1U | ((IData)(vlSelf->io_writeData_8) 
                                    << 1U))),11);
    bufp->fullSData(oldp+76,((0x401U | ((IData)(vlSelf->io_writeData_8) 
                                        << 1U))),11);
    bufp->fullSData(oldp+77,(vlSelf->io_writeData_0),10);
    bufp->fullSData(oldp+78,((0x200U | (IData)(vlSelf->io_writeData_0))),10);
    bufp->fullSData(oldp+79,(vlSelf->io_writeData_1),10);
    bufp->fullSData(oldp+80,((0x200U | (IData)(vlSelf->io_writeData_1))),10);
    bufp->fullSData(oldp+81,(vlSelf->io_writeData_2),10);
    bufp->fullSData(oldp+82,((0x200U | (IData)(vlSelf->io_writeData_2))),10);
    bufp->fullSData(oldp+83,(vlSelf->io_writeData_3),10);
    bufp->fullSData(oldp+84,((0x200U | (IData)(vlSelf->io_writeData_3))),10);
    bufp->fullSData(oldp+85,(vlSelf->io_writeData_4),10);
    bufp->fullSData(oldp+86,((0x200U | (IData)(vlSelf->io_writeData_4))),10);
    bufp->fullSData(oldp+87,(vlSelf->io_writeData_5),10);
    bufp->fullSData(oldp+88,((0x200U | (IData)(vlSelf->io_writeData_5))),10);
    bufp->fullSData(oldp+89,(vlSelf->io_writeData_6),10);
    bufp->fullSData(oldp+90,((0x200U | (IData)(vlSelf->io_writeData_6))),10);
    bufp->fullSData(oldp+91,(vlSelf->io_writeData_7),10);
    bufp->fullSData(oldp+92,((0x200U | (IData)(vlSelf->io_writeData_7))),10);
    bufp->fullSData(oldp+93,(vlSelf->io_writeData_8),10);
    bufp->fullSData(oldp+94,((0x200U | (IData)(vlSelf->io_writeData_8))),10);
    bufp->fullBit(oldp+95,(1U));
}
