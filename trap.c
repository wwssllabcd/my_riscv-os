#include "trap.h"
#include "riscv.h"
#include "uart.h"
#include "timer.h"

extern void trap_vector();

void trap_handler() {

    
    w_mie(~((~r_mie()) | (1 << 7)));

    RAM_U64(CLINT_MTIMECMP) =  RAM_U64(CLINT_MTIME) + 0x800000;


    u64 mtime = RAM_U64(CLINT_MTIME);
    u64 tcmp = RAM_U64(CLINT_MTIMECMP);

    printk("trap_handler, mtime=%lX, tcmp=%lX\n", mtime, tcmp);


    u32 a = RAM_U32(0x2004000);
    u32 b = RAM_U32(0x2004004);

    u32 c = RAM_U32(0x200Bff8);
    u32 d = RAM_U32(0x200Bffc);



    printk("trap_handler, a=%X, b=%X, c=%X, d=%X\n", a,b, c,d);

 

    w_mie(r_mie() | MIE_MTIE);
}

void trap_init() {
    printk("trap_init\n");

    // set the machine-mode trap handler.
    w_mtvec((reg_t)trap_vector);
}
