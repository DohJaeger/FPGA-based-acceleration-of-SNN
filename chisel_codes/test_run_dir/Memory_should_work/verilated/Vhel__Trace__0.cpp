// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vhel__Syms.h"


void Vhel___024root__trace_chg_sub_0(Vhel___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vhel___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root__trace_chg_top_0\n"); );
    // Init
    Vhel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vhel___024root*>(voidSelf);
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vhel___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vhel___024root__trace_chg_sub_0(Vhel___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->clock));
    bufp->chgBit(oldp+1,(vlSelf->reset));
    bufp->chgSData(oldp+2,(vlSelf->io_rdAddr),10);
    bufp->chgCData(oldp+3,(vlSelf->io_rdData),8);
    bufp->chgSData(oldp+4,(vlSelf->io_wrAddr),10);
    bufp->chgCData(oldp+5,(vlSelf->io_wrData),8);
    bufp->chgBit(oldp+6,(vlSelf->io_wrEna));
    bufp->chgBit(oldp+7,(vlSelf->io_rdEna));
    bufp->chgBit(oldp+8,(vlSelf->hel__DOT__mem_io_rdData_MPORT_en_pipe_0));
    bufp->chgSData(oldp+9,(vlSelf->hel__DOT__mem_io_rdData_MPORT_addr_pipe_0),10);
}

void Vhel___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhel___024root__trace_cleanup\n"); );
    // Init
    Vhel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vhel___024root*>(voidSelf);
    Vhel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
