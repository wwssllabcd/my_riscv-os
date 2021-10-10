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

void os_start(void) {
    printk("os_start start\n");
    while (1) {
        ;
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
