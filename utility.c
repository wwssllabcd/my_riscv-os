

#include "utility.h"

void mem_set(void* addr, u8 pattern, u32 len) {
    for (u32 i = 0; i < len; i++) {
        RAM_U8(addr + i) = pattern;
    }
}
