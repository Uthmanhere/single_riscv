// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vregfile__Syms_H_
#define _Vregfile__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vregfile.h"

// SYMS CLASS
class Vregfile__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vregfile*                      TOPp;
    
    // CREATORS
    Vregfile__Syms(Vregfile* topp, const char* namep);
    ~Vregfile__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif // guard
