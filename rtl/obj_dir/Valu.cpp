// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu.h for the primary calling header

#include "Valu.h"              // For This
#include "Valu__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Valu) {
    Valu__Syms* __restrict vlSymsp = __VlSymsp = new Valu__Syms(this, name());
    Valu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Valu::__Vconfigure(Valu__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Valu::~Valu() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Valu::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Valu::eval\n"); );
    Valu__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Valu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Valu::_eval_initial_loop(Valu__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Valu::_combo__TOP__1(Valu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu::_combo__TOP__1\n"); );
    Valu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at alu.sv:27
    if ((4U & (IData)(vlTOPp->funct3))) {
	if ((2U & (IData)(vlTOPp->funct3))) {
	    vlTOPp->aluOut = ((1U & (IData)(vlTOPp->funct3))
			       ? (vlTOPp->r1 & vlTOPp->r2)
			       : (vlTOPp->r1 | vlTOPp->r2));
	} else {
	    if ((1U & (IData)(vlTOPp->funct3))) {
		if (vlTOPp->funct7) {
		    if (vlTOPp->funct7) {
			vlTOPp->aluOut = ((0x1fU >= vlTOPp->r2)
					   ? (vlTOPp->r1 
					      >> vlTOPp->r2)
					   : 0U);
		    }
		} else {
		    vlTOPp->aluOut = ((0x1fU >= vlTOPp->r2)
				       ? (vlTOPp->r1 
					  >> vlTOPp->r2)
				       : 0U);
		}
	    } else {
		vlTOPp->aluOut = (vlTOPp->r1 ^ vlTOPp->r2);
	    }
	}
    } else {
	if ((2U & (IData)(vlTOPp->funct3))) {
	    vlTOPp->aluOut = ((1U & (IData)(vlTOPp->funct3))
			       ? ((vlTOPp->r1 < vlTOPp->r2)
				   ? 0xffU : 0U) : 
			      ((vlTOPp->r1 < vlTOPp->r2)
			        ? 0xffU : 0U));
	} else {
	    if ((1U & (IData)(vlTOPp->funct3))) {
		vlTOPp->aluOut = ((0x1fU >= vlTOPp->r2)
				   ? (vlTOPp->r1 << vlTOPp->r2)
				   : 0U);
	    } else {
		if (vlTOPp->funct7) {
		    if (vlTOPp->funct7) {
			vlTOPp->overflow = (1U & (IData)(
							 (VL_ULL(1) 
							  & (((QData)((IData)(vlTOPp->r1)) 
							      - (QData)((IData)(vlTOPp->r2))) 
							     >> 0x20U))));
			vlTOPp->aluOut = (vlTOPp->r1 
					  - vlTOPp->r2);
		    }
		} else {
		    vlTOPp->overflow = (1U & (IData)(
						     (VL_ULL(1) 
						      & (((QData)((IData)(vlTOPp->r1)) 
							  + (QData)((IData)(vlTOPp->r2))) 
							 >> 0x20U))));
		    vlTOPp->aluOut = (vlTOPp->r1 + vlTOPp->r2);
		}
	    }
	}
    }
    vlTOPp->zero = (0U == vlTOPp->aluOut);
}

void Valu::_eval(Valu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu::_eval\n"); );
    Valu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Valu::_eval_initial(Valu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu::_eval_initial\n"); );
    Valu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Valu::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu::final\n"); );
    // Variables
    Valu__Syms* __restrict vlSymsp = this->__VlSymsp;
    Valu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Valu::_eval_settle(Valu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu::_eval_settle\n"); );
    Valu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Valu::_change_request(Valu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu::_change_request\n"); );
    Valu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Valu::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((funct3 & 0xf8U))) {
	Verilated::overWidthError("funct3");}
    if (VL_UNLIKELY((funct7 & 0xfeU))) {
	Verilated::overWidthError("funct7");}
}
#endif // VL_DEBUG

void Valu::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu::_ctor_var_reset\n"); );
    // Body
    r1 = VL_RAND_RESET_I(32);
    r2 = VL_RAND_RESET_I(32);
    funct3 = VL_RAND_RESET_I(3);
    funct7 = VL_RAND_RESET_I(1);
    zero = VL_RAND_RESET_I(1);
    overflow = VL_RAND_RESET_I(1);
    aluOut = VL_RAND_RESET_I(32);
}
