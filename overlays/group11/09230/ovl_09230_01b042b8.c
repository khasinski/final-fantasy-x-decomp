#include "common.h"

extern void func_00110C30(void *, void *, float);

void func_01B042B8(u8 **a0)
{
    u8 *v0 = *a0;
    func_00110C30(*(void **)(v0 + 0x1EC), *(void **)(v0 + 0x1F8), 1.0f);
    __asm__ volatile("");
}
