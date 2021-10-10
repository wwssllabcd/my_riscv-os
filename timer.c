#include "timer.h"

#include "riscv.h"



void timer_disable() {
    RAM_U32(CLINT_MSIP) = 0;
}

void timer_enable() {
    RAM_U32(CLINT_MSIP) = 1;
}

void set_mtimecmp(u64 val) {
    printk("set_mtimecmp\n");
    RAM_U64(CLINT_MTIMECMP) = val;
}

void set_mtime(u64 val) {
    printk("set_mtime\n");
    RAM_U64(CLINT_MTIME) = val;
}

void timer_interrupt_enable() {
    // enable machine-mode timer interrupts
    w_mie(r_mie() | MIE_MTIE);
}

void timer_init() {
    printk("timer_init\n");

    // ask the CLINT for a timer interrupt.
    u32 interval = 10000000;  // cycles; about 1 second in qemu.
    set_mtimecmp(interval);
    set_mtime(0);
    timer_interrupt_enable();
}
