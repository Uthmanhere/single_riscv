// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Valu.h for the primary calling header

#ifndef _Valu___024unit_H_
#define _Valu___024unit_H_

#include "verilated.h"

class Valu__Syms;

//----------

VL_MODULE(Valu___024unit) {
  public:
    
    // PORTS
    
    // LOCAL SIGNALS
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    Valu__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Valu___024unit);  ///< Copying not allowed
  public:
    Valu___024unit(const char* name="TOP");
    ~Valu___024unit();
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(Valu__Syms* symsp, bool first);
  private:
    void _ctor_var_reset();
} VL_ATTR_ALIGNED(128);

#endif // guard
