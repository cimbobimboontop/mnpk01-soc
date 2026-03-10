// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu.h for the primary calling header

#include "Valu__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Valu___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Valu___024root___eval_triggers__ico(Valu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_triggers__ico\n"); );
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    vlSelfRef.__VicoFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Valu___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
}

bool Valu___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Valu___024root___ico_sequent__TOP__0(Valu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___ico_sequent__TOP__0\n"); );
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*8:0*/ alu__DOT__tmp_result;
    alu__DOT__tmp_result = 0;
    // Body
    alu__DOT__tmp_result = 0U;
    vlSelfRef.out = 0U;
    vlSelfRef.c_flag = 0U;
    if ((8U & (IData)(vlSelfRef.op))) {
        if ((4U & (IData)(vlSelfRef.op))) {
            vlSelfRef.out = ((2U & (IData)(vlSelfRef.op))
                              ? 0U : ((1U & (IData)(vlSelfRef.op))
                                       ? 0U : (IData)(vlSelfRef.a)));
        } else if ((2U & (IData)(vlSelfRef.op))) {
            if ((1U & (IData)(vlSelfRef.op))) {
                vlSelfRef.out = vlSelfRef.a;
                vlSelfRef.c_flag = ((IData)(vlSelfRef.a) 
                                    > (IData)(vlSelfRef.b));
            } else {
                vlSelfRef.out = ((0x000000feU & ((IData)(vlSelfRef.a) 
                                                 << 1U)) 
                                 | (1U & ((IData)(vlSelfRef.a) 
                                          >> 7U)));
                vlSelfRef.c_flag = (1U & ((IData)(vlSelfRef.a) 
                                          >> 7U));
            }
        } else if ((1U & (IData)(vlSelfRef.op))) {
            vlSelfRef.c_flag = (1U & (IData)(vlSelfRef.a));
            vlSelfRef.out = (0x000000ffU & VL_SHIFTR_III(8,8,32, (IData)(vlSelfRef.a), 1U));
        } else {
            vlSelfRef.c_flag = (1U & ((IData)(vlSelfRef.a) 
                                      >> 7U));
            vlSelfRef.out = (0x000000ffU & VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.a), 1U));
        }
    } else if ((4U & (IData)(vlSelfRef.op))) {
        vlSelfRef.out = (0x000000ffU & ((2U & (IData)(vlSelfRef.op))
                                         ? ((1U & (IData)(vlSelfRef.op))
                                             ? (~ (IData)(vlSelfRef.a))
                                             : ((IData)(vlSelfRef.a) 
                                                ^ (IData)(vlSelfRef.b)))
                                         : ((1U & (IData)(vlSelfRef.op))
                                             ? ((IData)(vlSelfRef.a) 
                                                | (IData)(vlSelfRef.b))
                                             : ((IData)(vlSelfRef.a) 
                                                & (IData)(vlSelfRef.b)))));
    } else if ((2U & (IData)(vlSelfRef.op))) {
        if ((1U & (IData)(vlSelfRef.op))) {
            vlSelfRef.out = (0x000000ffU & ((IData)(vlSelfRef.a) 
                                            - (IData)(1U)));
            vlSelfRef.c_flag = (1U > (IData)(vlSelfRef.a));
        } else {
            alu__DOT__tmp_result = (0x000001ffU & ((IData)(1U) 
                                                   + (IData)(vlSelfRef.a)));
            vlSelfRef.out = (0x000000ffU & (IData)(alu__DOT__tmp_result));
            vlSelfRef.c_flag = (1U & ((IData)(alu__DOT__tmp_result) 
                                      >> 8U));
        }
    } else if ((1U & (IData)(vlSelfRef.op))) {
        vlSelfRef.out = (0x000000ffU & ((IData)(vlSelfRef.a) 
                                        - (IData)(vlSelfRef.b)));
        vlSelfRef.c_flag = ((IData)(vlSelfRef.a) < (IData)(vlSelfRef.b));
    } else {
        alu__DOT__tmp_result = (0x000001ffU & ((IData)(vlSelfRef.a) 
                                               + (IData)(vlSelfRef.b)));
        vlSelfRef.out = (0x000000ffU & (IData)(alu__DOT__tmp_result));
        vlSelfRef.c_flag = (1U & ((IData)(alu__DOT__tmp_result) 
                                  >> 8U));
    }
    vlSelfRef.z_flag = (0U == (IData)(vlSelfRef.out));
    vlSelfRef.n_flag = (1U & ((IData)(vlSelfRef.out) 
                              >> 7U));
    if ((0x0bU == (IData)(vlSelfRef.op))) {
        vlSelfRef.z_flag = ((IData)(vlSelfRef.a) == (IData)(vlSelfRef.b));
        vlSelfRef.n_flag = ((IData)(vlSelfRef.a) < (IData)(vlSelfRef.b));
    }
}

void Valu___024root___eval_ico(Valu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_ico\n"); );
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Valu___024root___ico_sequent__TOP__0(vlSelf);
    }
}

bool Valu___024root___eval_phase__ico(Valu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_phase__ico\n"); );
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Valu___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = Valu___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Valu___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Valu___024root___eval(Valu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval\n"); );
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Valu___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("alu.v", 1, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Valu___024root___eval_phase__ico(vlSelf));
}

#ifdef VL_DEBUG
void Valu___024root___eval_debug_assertions(Valu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_debug_assertions\n"); );
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.op & 0xf0U)))) {
        Verilated::overWidthError("op");
    }
}
#endif  // VL_DEBUG
