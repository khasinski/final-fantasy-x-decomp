#include "common.h"

void func_01B06150(u8 *a0)
{
    register u32 v0 __asm__("$2") = 0x80800040;
    register int a1 __asm__("$5") = 0x80;
    __asm__("" : "+r"(v0), "+r"(a1));
    {
        register int v1 __asm__("$3") = 0x96;
        __asm__("" : "+r"(v1));
        *(int *)(a0 + 0x120) = a1;
        __asm__ volatile("");
        *(int *)(a0 + 0x130) = v1;
        *(u32 *)(a0 + 0x124) = v0;
        *(int *)(a0 + 0x128) = 0;
        __asm__ volatile("");
        *(int *)(a0 + 0x12C) = 0;
    }
}
