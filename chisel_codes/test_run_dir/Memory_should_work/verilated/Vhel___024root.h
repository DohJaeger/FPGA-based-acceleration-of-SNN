// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vhel.h for the primary calling header

#ifndef VERILATED_VHEL___024ROOT_H_
#define VERILATED_VHEL___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_cov.h"

class Vhel__Syms;

class Vhel___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(io_rdData,7,0);
    VL_IN8(io_wrData,7,0);
    VL_IN8(io_wrEna,0,0);
    VL_IN8(io_rdEna,0,0);
    CData/*0:0*/ hel__DOT__mem_io_rdData_MPORT_en_pipe_0;
    CData/*0:0*/ __Vtrigrprev__TOP__clock;
    CData/*0:0*/ __VactContinue;
    VL_IN16(io_rdAddr,9,0);
    VL_IN16(io_wrAddr,9,0);
    SData/*9:0*/ hel__DOT__mem_io_rdData_MPORT_addr_pipe_0;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 1024> hel__DOT__mem;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vhel__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vhel___024root(Vhel__Syms* symsp, const char* v__name);
    ~Vhel___024root();
    VL_UNCOPYABLE(Vhel___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
    void __vlCoverInsert(std::atomic<uint32_t>* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
