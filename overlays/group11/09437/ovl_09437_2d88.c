#include "common.h"

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

extern u8 *D_01B0A310;

void func_01B02B80(u8 *a0)
{
    copy_vec(a0 + 0xD0, D_01B0A310 + 0x1C00);
}
