#pragma once

// https://rcore-os.github.io/rCore-Tutorial-deploy/docs/lab-2/guide/part-2.html
// virt_memmap[] = {
//     [VIRT_DEBUG] =       {        0x0,         0x100 },
//     [VIRT_MROM] =        {     0x1000,        0xf000 },
//     [VIRT_TEST] =        {   0x100000,        0x1000 },
//     [VIRT_RTC] =         {   0x101000,        0x1000 },
//     [VIRT_CLINT] =       {  0x2000000,       0x10000 },
//     [VIRT_PCIE_PIO] =    {  0x3000000,       0x10000 },
//     [VIRT_PLIC] =        {  0xc000000, VIRT_PLIC_SIZE(VIRT_CPUS_MAX * 2) },
//     [VIRT_UART0] =       { 0x10000000,         0x100 },
//     [VIRT_VIRTIO] =      { 0x10001000,        0x1000 },
//     [VIRT_FLASH] =       { 0x20000000,     0x4000000 },
//     [VIRT_PCIE_ECAM] =   { 0x30000000,    0x10000000 },
//     [VIRT_PCIE_MMIO] =   { 0x40000000,    0x40000000 },
//     [VIRT_BUTTER_ROBOT]= { 0x50000000,         0x100 },
//     [VIRT_DRAM] =        { 0x80000000,           0x0 },
// };


#define VIRT_CLINT                   (0x2000000)

//PLIC (Platform Level Interrupt Controller)

//---------------

#define CLINT_BASE                   (VIRT_CLINT)      //CORE LOCAL INTERRUPT
#define UART_BASE                    (0x10000000)