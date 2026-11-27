#include "common.h"

extern u8 *D_01B004F4;
extern u8 D_01B004F8[];
extern void *D_006A3924;
extern void func_00267658(void *, int, void *, int);

void func_01B0B0D8(u8 *a0)
{
    void **p = *(void ***)(D_01B004F4 + 0x10);
    D_006A3924 = D_01B004F8;
    func_00267658(a0, 0x1000, p[0], 1);
    *(int *)(a0 + 0x40) = 0;
    {
        register float f0 __asm__("$f0") = 0.13197001f;
        register float f1 __asm__("$f1") = 1.0f;
        *(int *)(a0 + 0x5C) = 1;
        *(float *)(a0 + 0x6C) = f1;
        *(float *)(a0 + 0x68) = f0;
        *(int *)(a0 + 0x44) = 0;
        *(int *)(a0 + 0x48) = 0;
        __asm__ volatile("");
        *(float *)(a0 + 0x4C) = f1;
        *(int *)(a0 + 0x50) = 0;
        *(int *)(a0 + 0x54) = 0;
        *(int *)(a0 + 0x58) = 0;
        *(float *)(a0 + 0x60) = f0;
        __asm__ volatile("");
        *(float *)(a0 + 0x64) = f0;
    }
}
