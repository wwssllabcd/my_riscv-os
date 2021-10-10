#include "trap.h"
#include "riscv.h"
#include "uart.h"

extern void trap_vector();

reg_t trap_handler(reg_t epc, reg_t cause) {
    reg_t return_pc = epc;

    return return_pc;
}

void trap_init() {
    printk("trap_init\n");

    // set the machine-mode trap handler.
    w_mtvec((reg_t)trap_vector);
}
