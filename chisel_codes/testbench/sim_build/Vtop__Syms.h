// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP__SYMS_H_
#define VERILATED_VTOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtop.h"

// INCLUDE MODULE CLASSES
#include "Vtop___024root.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class Vtop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtop___024root                 TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_TOP;
    VerilatedScope __Vscope_pe;
    VerilatedScope __Vscope_pe__aeqMem;
    VerilatedScope __Vscope_pe__aeqMem__multiMem;
    VerilatedScope __Vscope_pe__aeqMem__multiMem__mems_0_ext;
    VerilatedScope __Vscope_pe__aeqMem__multiMem__mems_1_ext;
    VerilatedScope __Vscope_pe__aeqMem__multiMem__mems_2_ext;
    VerilatedScope __Vscope_pe__aeqMem__multiMem__mems_3_ext;
    VerilatedScope __Vscope_pe__aeqMem__multiMem__mems_4_ext;
    VerilatedScope __Vscope_pe__aeqMem__multiMem__mems_5_ext;
    VerilatedScope __Vscope_pe__aeqMem__multiMem__mems_6_ext;
    VerilatedScope __Vscope_pe__aeqMem__multiMem__mems_7_ext;
    VerilatedScope __Vscope_pe__aeqMem__multiMem__mems_8_ext;
    VerilatedScope __Vscope_pe__aeqMem__unnamedblk1;
    VerilatedScope __Vscope_pe__mempotMem;
    VerilatedScope __Vscope_pe__mempotMem__multiMem;
    VerilatedScope __Vscope_pe__mempotMem__multiMem__mems_0_ext;
    VerilatedScope __Vscope_pe__mempotMem__multiMem__mems_1_ext;
    VerilatedScope __Vscope_pe__mempotMem__multiMem__mems_2_ext;
    VerilatedScope __Vscope_pe__mempotMem__multiMem__mems_3_ext;
    VerilatedScope __Vscope_pe__mempotMem__multiMem__mems_4_ext;
    VerilatedScope __Vscope_pe__mempotMem__multiMem__mems_5_ext;
    VerilatedScope __Vscope_pe__mempotMem__multiMem__mems_6_ext;
    VerilatedScope __Vscope_pe__mempotMem__multiMem__mems_7_ext;
    VerilatedScope __Vscope_pe__mempotMem__multiMem__mems_8_ext;
    VerilatedScope __Vscope_pe__unnamedblk1;
    VerilatedScope __Vscope_pe__unnamedblk1__unnamedblk2;
    VerilatedScope __Vscope_pe__unnamedblk1__unnamedblk3;
    VerilatedScope __Vscope_pe__unnamedblk4;

    // SCOPE HIERARCHY
    VerilatedHierarchy __Vhier;

    // CONSTRUCTORS
    Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp);
    ~Vtop__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
