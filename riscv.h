#pragma once
#include "head.h"



// Machine-mode Interrupt Enable
#define MIE_MEIE (1 << 11) // external
#define MIE_MTIE (1 << 7)  // timer
#define MIE_MSIE (1 << 3)  // software

#define GET_PC(VAR)  asm volatile("auipc %0, 0" : "=r"(VAR))


reg_t r_mstatus();
void w_mstatus(reg_t x);


reg_t r_mie();
void w_mie(reg_t x);

//--------------
reg_t r_mhartid();
void w_mscratch(reg_t x);
void w_mtvec(reg_t x);