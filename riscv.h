#pragma once
#include "head.h"





reg_t r_mstatus();
void w_mstatus(reg_t x);

reg_t r_mie();
void w_mie(reg_t x);

//--------------
reg_t r_mhartid();
void w_mscratch(reg_t x);
void w_mtvec(reg_t x);