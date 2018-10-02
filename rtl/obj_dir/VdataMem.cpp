// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VdataMem.h for the primary calling header

#include "VdataMem.h"          // For This
#include "VdataMem__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VdataMem) {
    VdataMem__Syms* __restrict vlSymsp = __VlSymsp = new VdataMem__Syms(this, name());
    VdataMem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VdataMem::__Vconfigure(VdataMem__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VdataMem::~VdataMem() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VdataMem::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VdataMem::eval\n"); );
    VdataMem__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VdataMem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void VdataMem::_eval_initial_loop(VdataMem__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void VdataMem::_sequent__TOP__1(VdataMem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VdataMem::_sequent__TOP__1\n"); );
    VdataMem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvdim0__dataMem__DOT__dataMem_regs__v0,0,0);
    VL_SIG8(__Vdlyvset__dataMem__DOT__dataMem_regs__v0,0,0);
    VL_SIG(__Vdlyvval__dataMem__DOT__dataMem_regs__v0,31,0);
    // Body
    __Vdlyvset__dataMem__DOT__dataMem_regs__v0 = 0U;
    // ALWAYS at dataMem.sv:14
    if (vlTOPp->write_ctrl) {
	__Vdlyvval__dataMem__DOT__dataMem_regs__v0 
	    = vlTOPp->write_data;
	__Vdlyvset__dataMem__DOT__dataMem_regs__v0 = 1U;
	__Vdlyvdim0__dataMem__DOT__dataMem_regs__v0 
	    = (1U & ((IData)(1U) + vlTOPp->data_addr));
    }
    // ALWAYSPOST at dataMem.sv:16
    if (__Vdlyvset__dataMem__DOT__dataMem_regs__v0) {
	vlTOPp->dataMem__DOT__dataMem_regs[__Vdlyvdim0__dataMem__DOT__dataMem_regs__v0] 
	    = __Vdlyvval__dataMem__DOT__dataMem_regs__v0;
    }
}

VL_INLINE_OPT void VdataMem::_settle__TOP__2(VdataMem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VdataMem::_settle__TOP__2\n"); );
    VdataMem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->dataOut = vlTOPp->dataMem__DOT__dataMem_regs
	[(1U & ((IData)(1U) + vlTOPp->data_addr))];
}

void VdataMem::_eval(VdataMem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VdataMem::_eval\n"); );
    VdataMem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_settle__TOP__2(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void VdataMem::_eval_initial(VdataMem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VdataMem::_eval_initial\n"); );
    VdataMem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VdataMem::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VdataMem::final\n"); );
    // Variables
    VdataMem__Syms* __restrict vlSymsp = this->__VlSymsp;
    VdataMem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VdataMem::_eval_settle(VdataMem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VdataMem::_eval_settle\n"); );
    VdataMem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData VdataMem::_change_request(VdataMem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VdataMem::_change_request\n"); );
    VdataMem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VdataMem::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VdataMem::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
	Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((write_ctrl & 0xfeU))) {
	Verilated::overWidthError("write_ctrl");}
}
#endif // VL_DEBUG

void VdataMem::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VdataMem::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    write_ctrl = VL_RAND_RESET_I(1);
    write_data = VL_RAND_RESET_I(32);
    data_addr = VL_RAND_RESET_I(32);
    dataOut = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    dataMem__DOT__dataMem_regs[__Vi0] = VL_RAND_RESET_I(32);
    }}
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
}
