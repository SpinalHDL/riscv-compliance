// RISC-V Compliance Test Header File
// Copyright (c) 2017, Codasip Ltd. All Rights Reserved.
// See LICENSE for license details.
//
// Description: Common header file for RV32I tests

#ifndef _COMPLIANCE_TEST_H
#define _COMPLIANCE_TEST_H

#include "riscv_test.h"

//-----------------------------------------------------------------------
// RV Compliance Macros
//-----------------------------------------------------------------------

#define RV_COMPLIANCE_HALT                                                    \
        la a0, codasip_signature_start;                                        \
        la a1, codasip_signature_end; \
        li a2, 0xF00FFF2C; \
complience_halt_loop: \
        beq a0, a1, complience_halt_break; \
        lw a3, 12(a0); \
        sw a3, 0(a2); \
        lw a3, 8(a0); \
        sw a3, 0(a2); \
        lw a3, 4(a0); \
        sw a3, 0(a2); \
        lw a3, 0(a0); \
        sw a3, 0(a2); \
        addi a0, a0, 16; \
        j complience_halt_loop; \
complience_halt_break:; \
        li a0, 0xF00FFF20;                                                         \
        sw x0, 0 (a0);                                                         \



#define RV_COMPLIANCE_RV32M                                                   \

//Nops are for RVC JAL test which require offset
#ifdef RVC
#define RV_COMPLIANCE_CODE_BEGIN                                              \
        .section .text.init;                                                  \
        .align  4;                                                            \
        .globl _start;                                                        \
        _start:                                                               \
        nop;nop;nop;nop;nop;nop;nop;nop; \
        nop;nop;nop;nop;nop;nop;nop;nop; \
        nop;nop;nop;nop;nop;nop;nop;nop; \
        nop;nop;nop;nop;nop;nop;nop;nop; \
        nop;nop;nop;nop;nop;nop;nop;nop; \
        nop;nop;nop;nop;nop;nop;nop;nop; \
        nop;nop;nop;nop;nop;nop;nop;nop; \
        nop;nop;nop;nop;nop;nop;nop;nop; \
        nop;nop;nop;nop;nop;nop;nop;nop; \
        nop;nop;nop;nop;nop;nop;nop;nop; \
        nop;nop;nop;nop;nop;nop;nop;nop; \
        nop;nop;nop;nop;nop;nop;nop;nop; \
        nop;nop;nop;nop;nop;nop;nop;nop; \
        nop;nop;nop;nop;nop;nop;nop;nop; \
        nop;nop;nop;nop;nop;nop;nop; 
#else
#define RV_COMPLIANCE_CODE_BEGIN                                              \
        .section .text.init;                                                  \
        .align  4;                                                            \
        .globl _start;                                                        \
        _start:                                                               
#endif


#define RV_COMPLIANCE_CODE_END                                                \


#define RV_COMPLIANCE_DATA_BEGIN                                              \
        .align 4;                                                             \
        .global codasip_signature_start;                                      \
        codasip_signature_start:                                              \

#define RV_COMPLIANCE_DATA_END                                                \
        .align 4;                                                             \
        .global codasip_signature_end;                                        \
        codasip_signature_end:                                                 \

#endif
