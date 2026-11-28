#include "common.h"

extern u8 *D_01B0C0B0;
extern u8 D_01B11810[];
extern void *op_oef2_a_get(void *, int, int);
extern void func_01B010D0(void *, void *);

void func_01B01060(void)
{
    u8 *s0 = D_01B0C0B0 + 0x9D0;
    int i;

    for (i = 0; i < 20; i++) {
        func_01B010D0(op_oef2_a_get(D_01B11810, 4, i), s0);
        s0 += 0x600;
    }
}
