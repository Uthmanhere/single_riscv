// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vregfile.h for the primary calling header

#include "Vregfile.h"          // For This
#include "Vregfile__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vregfile) {
    Vregfile__Syms* __restrict vlSymsp = __VlSymsp = new Vregfile__Syms(this, name());
    Vregfile* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vregfile::__Vconfigure(Vregfile__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vregfile::~Vregfile() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vregfile::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vregfile::eval\n"); );
    Vregfile__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vregfile* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void Vregfile::_eval_initial_loop(Vregfile__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vregfile::_sequent__TOP__1(Vregfile__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile::_sequent__TOP__1\n"); );
    Vregfile* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvdim0__regfile__DOT__regfile_regs__v0,4,0);
    VL_SIG8(__Vdlyvset__regfile__DOT__regfile_regs__v0,0,0);
    VL_SIG(__Vdlyvval__regfile__DOT__regfile_regs__v0,31,0);
    // Body
    __Vdlyvset__regfile__DOT__regfile_regs__v0 = 0U;
    // ALWAYS at regfile.sv:18
    if (vlTOPp->write_ctrl) {
	__Vdlyvval__regfile__DOT__regfile_regs__v0 
	    = vlTOPp->write_data;
	__Vdlyvset__regfile__DOT__regfile_regs__v0 = 1U;
	__Vdlyvdim0__regfile__DOT__regfile_regs__v0 
	    = vlTOPp->write_addr;
    }
    // ALWAYSPOST at regfile.sv:20
    if (__Vdlyvset__regfile__DOT__regfile_regs__v0) {
	vlTOPp->regfile__DOT__regfile_regs[__Vdlyvdim0__regfile__DOT__regfile_regs__v0] 
	    = __Vdlyvval__regfile__DOT__regfile_regs__v0;
    }
}

VL_INLINE_OPT void Vregfile::_settle__TOP__2(Vregfile__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile::_settle__TOP__2\n"); );
    Vregfile* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->rs1 = vlTOPp->regfile__DOT__regfile_regs
	[vlTOPp->rs1_addr];
    vlTOPp->rs2 = vlTOPp->regfile__DOT__regfile_regs
	[vlTOPp->rs2_addr];
}

void Vregfile::_eval(Vregfile__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile::_eval\n"); );
    Vregfile* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_settle__TOP__2(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vregfile::_eval_initial(Vregfile__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile::_eval_initial\n"); );
    Vregfile* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vregfile::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile::final\n"); );
    // Variables
    Vregfile__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vregfile* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vregfile::_eval_settle(Vregfile__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile::_eval_settle\n"); );
    Vregfile* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Vregfile::_change_request(Vregfile__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile::_change_request\n"); );
    Vregfile* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vregfile::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
	Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((write_ctrl & 0xfeU))) {
	Verilated::overWidthError("write_ctrl");}
    if (VL_UNLIKELY((write_addr & 0xe0U))) {
	Verilated::overWidthError("write_addr");}
    if (VL_UNLIKELY((rs1_addr & 0xe0U))) {
	Verilated::overWidthError("rs1_addr");}
    if (VL_UNLIKELY((rs2_addr & 0xe0U))) {
	Verilated::overWidthError("rs2_addr");}
}
#endif // VL_DEBUG

void Vregfile::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    write_ctrl = VL_RAND_RESET_I(1);
    write_data = VL_RAND_RESET_I(32);
    write_addr = VL_RAND_RESET_I(5);
    rs1_addr = VL_RAND_RESET_I(5);
    rs2_addr = VL_RAND_RESET_I(5);
    rs1 = VL_RAND_RESET_I(32);
    rs2 = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    regfile__DOT__regfile_regs[__Vi0] = VL_RAND_RESET_I(32);
    }}
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
}
