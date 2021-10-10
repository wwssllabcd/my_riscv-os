#include "trap.h"
#include "riscv.h"
#include "uart.h"

extern void trap_vector();

void trap_handler() {

    u32 a = 
    printk("trap_handler\n");
}

void trap_init() {
    printk("trap_init\n");

    // set the machine-mode trap handler.
    w_mtvec((reg_t)trap_vector);
}
