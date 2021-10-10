#include "head.h"
#include "timer.h"
#include "trap.h"


#define MSTATUS_MIE (1 << 3)  // machine-mode interrupt enable.

vu32 m_temp_storage[128];

void mscratch_init() {
    printk("mscratch_init\n");

    mem_set((void*)m_temp_storage, 0xFF, sizeof(m_temp_storage));
    w_mscratch((reg_t)m_temp_storage);
}

// void delay(vu32 count)
// {
// 	while (count--);
// }

// void user_task0(void)
// {
// 	printk("Task0: Created!\n");
// 	while (1)
// 	{
// 		printk("Task0: Running...\n");
// 		lib_delay(0x10000);
// 	}
// }

// void user_task1(void)
// {
// 	printk("Task1: Created!\n");
// 	while (1)
// 	{
// 		printk("Task1: Running...\n");
// 		lib_delay(0x10000);
// 	}
// }

void global_interrupt_enable() {


	printk("global_interrupt_enable\n");

    // enable machine-mode interrupts.
    w_mstatus(r_mstatus() | MSTATUS_MIE);
}

reg_t r_sp(void) {
    reg_t x;
    asm volatile("mv %0, sp" : "=r"(x));
    return x;
}

void os_start(void) {
    printk("os_start \n");
    u32 cnt =0;

   
    

    while (1) {
        u64 a = RAM_U64(CLINT_MTIME);

        reg_t b = r_sp();
        

        printk("cnt=%X, timer=%X, sp=%X \n", cnt, a, b);

        cnt++;
    }
}

void os_main(void) {
    printk("os_main start\n");
    printk("A=%X, B=%X, C=%X \n", 0x87654321, 0x12345678, 12345678);

    mscratch_init();

    trap_init();

    timer_init();

    global_interrupt_enable();

    os_start();
}
