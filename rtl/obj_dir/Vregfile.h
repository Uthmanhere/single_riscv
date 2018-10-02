// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vregfile_H_
#define _Vregfile_H_

#include "verilated.h"

class Vregfile__Syms;

//----------

VL_MODULE(Vregfile) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(write_ctrl,0,0);
    VL_IN8(write_addr,4,0);
    VL_IN8(rs1_addr,4,0);
    VL_IN8(rs2_addr,4,0);
    VL_IN(write_data,31,0);
    VL_OUT(rs1,31,0);
    VL_OUT(rs2,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG(regfile__DOT__regfile_regs[32],31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vregfile__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vregfile);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vregfile(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vregfile();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vregfile__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vregfile__Syms* symsp, bool first);
  private:
    static QData _change_request(Vregfile__Syms* __restrict vlSymsp);
    void _ctor_var_reset();
  public:
    static void _eval(Vregfile__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vregfile__Syms* __restrict vlSymsp);
    static void _eval_settle(Vregfile__Syms* __restrict vlSymsp);
    static void _sequent__TOP__1(Vregfile__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vregfile__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
