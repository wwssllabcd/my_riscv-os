#include "riscv.h"

//--------------------
reg_t r_mstatus(){
  reg_t x;
  asm volatile("csrr %0, mstatus" : "=r" (x) );
  return x;
}

void w_mstatus(reg_t x){
  asm volatile("csrw mstatus, %0" : : "r" (x));
}

//--------------------
reg_t r_mie()
{
  reg_t x;
  asm volatile("csrr %0, mie" : "=r" (x) );
  return x;
}

void w_mie(reg_t x)
{
  asm volatile("csrw mie, %0" : : "r" (x));
}

//--------------------

reg_t r_mhartid(){
  reg_t x;
  asm volatile("csrr %0, mhartid" : "=r" (x) );
  return x;
}

// Machine Scratch register, for early trap handler
void w_mscratch(reg_t x)
{
  asm volatile("csrw mscratch, %0" : : "r" (x));
}

// Machine-mode interrupt vector
void w_mtvec(reg_t x)
{
  asm volatile("csrw mtvec, %0" : : "r" (x));
}