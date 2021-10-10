#pragma once

// Table 6.1: SiFive CLINT Memory Map
#define CLINT_MSIP (CLINT_BASE)
#define CLINT_MTIMECMP (CLINT_BASE + 0x4000)
#define CLINT_MTIME (CLINT_BASE + 0xBFF8)


void timer_init();