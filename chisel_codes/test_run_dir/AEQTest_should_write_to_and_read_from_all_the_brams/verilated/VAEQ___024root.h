// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VAEQ.h for the primary calling header

#ifndef VERILATED_VAEQ___024ROOT_H_
#define VERILATED_VAEQ___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_cov.h"

class VAEQ__Syms;

class VAEQ___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(reset,0,0);
        VL_IN8(io_writeEnable_0,0,0);
        VL_IN8(io_writeEnable_1,0,0);
        VL_IN8(io_writeEnable_2,0,0);
        VL_IN8(io_writeEnable_3,0,0);
        VL_IN8(io_writeEnable_4,0,0);
        VL_IN8(io_writeEnable_5,0,0);
        VL_IN8(io_writeEnable_6,0,0);
        VL_IN8(io_writeEnable_7,0,0);
        VL_IN8(io_writeEnable_8,0,0);
        VL_IN8(io_readEnable,0,0);
        CData/*0:0*/ AEQ__DOT__brams_0_MPORT_en;
        CData/*0:0*/ AEQ__DOT__brams_1_MPORT_2_en;
        CData/*0:0*/ AEQ__DOT__brams_2_MPORT_4_en;
        CData/*0:0*/ AEQ__DOT__brams_3_MPORT_6_en;
        CData/*0:0*/ AEQ__DOT__brams_4_MPORT_8_en;
        CData/*0:0*/ AEQ__DOT__brams_5_MPORT_10_en;
        CData/*0:0*/ AEQ__DOT__brams_6_MPORT_12_en;
        CData/*0:0*/ AEQ__DOT__brams_7_MPORT_14_en;
        CData/*0:0*/ AEQ__DOT__brams_8_MPORT_16_en;
        CData/*7:0*/ AEQ__DOT__writeCounters_0;
        CData/*7:0*/ AEQ__DOT__writeCounters_1;
        CData/*7:0*/ AEQ__DOT__writeCounters_2;
        CData/*7:0*/ AEQ__DOT__writeCounters_3;
        CData/*7:0*/ AEQ__DOT__writeCounters_4;
        CData/*7:0*/ AEQ__DOT__writeCounters_5;
        CData/*7:0*/ AEQ__DOT__writeCounters_6;
        CData/*7:0*/ AEQ__DOT__writeCounters_7;
        CData/*7:0*/ AEQ__DOT__writeCounters_8;
        CData/*7:0*/ AEQ__DOT__readCounter;
        CData/*7:0*/ AEQ__DOT___writeCounters_0_T_1;
        CData/*7:0*/ AEQ__DOT___writeCounters_1_T_1;
        CData/*7:0*/ AEQ__DOT___writeCounters_2_T_1;
        CData/*7:0*/ AEQ__DOT___writeCounters_3_T_1;
        CData/*7:0*/ AEQ__DOT___writeCounters_4_T_1;
        CData/*7:0*/ AEQ__DOT___writeCounters_5_T_1;
        CData/*7:0*/ AEQ__DOT___writeCounters_6_T_1;
        CData/*7:0*/ AEQ__DOT___writeCounters_7_T_1;
        CData/*7:0*/ AEQ__DOT___writeCounters_8_T_1;
        CData/*7:0*/ AEQ__DOT___readCounter_T_1;
        CData/*0:0*/ __Vtrigrprev__TOP__clock;
        CData/*0:0*/ __VactContinue;
        VL_IN16(io_writeData_0,8,0);
        VL_IN16(io_writeData_1,8,0);
        VL_IN16(io_writeData_2,8,0);
        VL_IN16(io_writeData_3,8,0);
        VL_IN16(io_writeData_4,8,0);
        VL_IN16(io_writeData_5,8,0);
        VL_IN16(io_writeData_6,8,0);
        VL_IN16(io_writeData_7,8,0);
        VL_IN16(io_writeData_8,8,0);
        VL_OUT16(io_readData_0,10,0);
        VL_OUT16(io_readData_1,10,0);
        VL_OUT16(io_readData_2,10,0);
        VL_OUT16(io_readData_3,10,0);
        VL_OUT16(io_readData_4,10,0);
        VL_OUT16(io_readData_5,10,0);
        VL_OUT16(io_readData_6,10,0);
        VL_OUT16(io_readData_7,10,0);
        VL_OUT16(io_readData_8,10,0);
        IData/*31:0*/ __VstlIterCount;
        IData/*31:0*/ __VicoIterCount;
        IData/*31:0*/ __VactIterCount;
    };
    struct {
        VlUnpacked<SData/*10:0*/, 256> AEQ__DOT__brams_0;
        VlUnpacked<SData/*10:0*/, 256> AEQ__DOT__brams_1;
        VlUnpacked<SData/*10:0*/, 256> AEQ__DOT__brams_2;
        VlUnpacked<SData/*10:0*/, 256> AEQ__DOT__brams_3;
        VlUnpacked<SData/*10:0*/, 256> AEQ__DOT__brams_4;
        VlUnpacked<SData/*10:0*/, 256> AEQ__DOT__brams_5;
        VlUnpacked<SData/*10:0*/, 256> AEQ__DOT__brams_6;
        VlUnpacked<SData/*10:0*/, 256> AEQ__DOT__brams_7;
        VlUnpacked<SData/*10:0*/, 256> AEQ__DOT__brams_8;
        VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VAEQ__Syms* const vlSymsp;

    // CONSTRUCTORS
    VAEQ___024root(VAEQ__Syms* symsp, const char* v__name);
    ~VAEQ___024root();
    VL_UNCOPYABLE(VAEQ___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
    void __vlCoverInsert(std::atomic<uint32_t>* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
