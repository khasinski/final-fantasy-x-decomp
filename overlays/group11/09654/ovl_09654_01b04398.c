#include "common.h"

void func_01B04398(u8 *a0)
{
    register u32 c0 __asm__("$2") = 0x80800040;
    register u32 c80 __asm__("$5") = 0x80;
    register u32 c1e __asm__("$3") = 0x1E;
    *(u32 *)(a0 + 0x120) = c80;
    *(u32 *)(a0 + 0x130) = c1e;
    *(u32 *)(a0 + 0x124) = c0;
    *(u32 *)(a0 + 0x12C) = 0;
    *(u32 *)(a0 + 0x128) = 0;
}
