// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vhel__Syms.h"


VL_ATTR_COLD void Vhel___024root__trace_init_sub__TOP__0(Vhel___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,"clock", false,-1);
    tracep->declBit(c+2,"reset", false,-1);
    tracep->declBus(c+3,"io_rdAddr", false,-1, 9,0);
    tracep->declBus(c+4,"io_rdData", false,-1, 7,0);
    tracep->declBus(c+5,"io_wrAddr", false,-1, 9,0);
    tracep->declBus(c+6,"io_wrData", false,-1, 7,0);
    tracep->declBit(c+7,"io_wrEna", false,-1);
    tracep->declBit(c+8,"io_rdEna", false,-1);
    tracep->pushNamePrefix("hel ");
    tracep->declBit(c+1,"clock", false,-1);
    tracep->declBit(c+2,"reset", false,-1);
    tracep->declBus(c+3,"io_rdAddr", false,-1, 9,0);
    tracep->declBus(c+4,"io_rdData", false,-1, 7,0);
    tracep->declBus(c+5,"io_wrAddr", false,-1, 9,0);
    tracep->declBus(c+6,"io_wrData", false,-1, 7,0);
    tracep->declBit(c+7,"io_wrEna", false,-1);
    tracep->declBit(c+8,"io_rdEna", false,-1);
    tracep->declBit(c+9,"mem_io_rdData_MPORT_en", false,-1);
    tracep->declBus(c+10,"mem_io_rdData_MPORT_addr", false,-1, 9,0);
    tracep->declBus(c+4,"mem_io_rdData_MPORT_data", false,-1, 7,0);
    tracep->declBus(c+6,"mem_MPORT_data", false,-1, 7,0);
    tracep->declBus(c+5,"mem_MPORT_addr", false,-1, 9,0);
    tracep->declBit(c+11,"mem_MPORT_mask", false,-1);
    tracep->declBit(c+7,"mem_MPORT_en", false,-1);
    tracep->declBit(c+9,"mem_io_rdData_MPORT_en_pipe_0", false,-1);
    tracep->declBus(c+10,"mem_io_rdData_MPORT_addr_pipe_0", false,-1, 9,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vhel___024root__trace_init_top(Vhel___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root__trace_init_top\n"); );
    // Body
    Vhel___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vhel___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vhel___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vhel___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vhel___024root__trace_register(Vhel___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vhel___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vhel___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vhel___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vhel___024root__trace_full_sub_0(Vhel___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vhel___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root__trace_full_top_0\n"); );
    // Init
    Vhel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vhel___024root*>(voidSelf);
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vhel___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vhel___024root__trace_full_sub_0(Vhel___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->clock));
    bufp->fullBit(oldp+2,(vlSelf->reset));
    bufp->fullSData(oldp+3,(vlSelf->io_rdAddr),10);
    bufp->fullCData(oldp+4,(vlSelf->io_rdData),8);
    bufp->fullSData(oldp+5,(vlSelf->io_wrAddr),10);
    bufp->fullCData(oldp+6,(vlSelf->io_wrData),8);
    bufp->fullBit(oldp+7,(vlSelf->io_wrEna));
    bufp->fullBit(oldp+8,(vlSelf->io_rdEna));
    bufp->fullBit(oldp+9,(vlSelf->hel__DOT__mem_io_rdData_MPORT_en_pipe_0));
    bufp->fullSData(oldp+10,(vlSelf->hel__DOT__mem_io_rdData_MPORT_addr_pipe_0),10);
    bufp->fullBit(oldp+11,(1U));
}
