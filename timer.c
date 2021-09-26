#include "timer.h"

#include "riscv.h"

// Table 6.1: SiFive CLINT Memory Map
#define CLINT_MSIP (CLINT_BASE)
#define CLINT_MTIMECMP (CLINT_BASE + 0x4000)
#define CLINT_MTIME (CLINT_BASE + 0xBFF8)

// Machine-mode Interrupt Enable
#define MIE_MEIE (1 << 11)  // external
#define MIE_MTIE (1 << 7)   // timer
#define MIE_MSIE (1 << 3)   // software

void timer_disable() {
    RAM_U32(CLINT_MSIP) = 0;
}

void timer_enable() {
    RAM_U32(CLINT_MSIP) = 1;
}

void set_mtimecmp(u64 val) {
    RAM_U64(CLINT_MTIMECMP) = val;
}

void set_mtime(u64 val) {
    RAM_U64(CLINT_MTIME) = val;
}

void timer_interrupt_enable() {
    // enable machine-mode timer interrupts.
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
