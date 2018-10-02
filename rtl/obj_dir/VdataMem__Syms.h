// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _VdataMem__Syms_H_
#define _VdataMem__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "VdataMem.h"

// SYMS CLASS
class VdataMem__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VdataMem*                      TOPp;
    
    // CREATORS
    VdataMem__Syms(VdataMem* topp, const char* namep);
    ~VdataMem__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif // guard
