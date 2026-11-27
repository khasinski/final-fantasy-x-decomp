#include "common.h"

extern u8 g_sym_a900[];
extern u8 g_sym_0ce8[];

extern void g_fn_1a2e8(void *);
extern void g_fn_1a6f0(void *);

void func_01B0ACA8(u8 *a0, u8 *a1)
{
    void *msg[4];

    msg[0] = a0;
    msg[1] = g_sym_a900;
    msg[2] = a0;
    g_fn_1a2e8(msg);

    msg[0] = g_sym_0ce8;
    msg[1] = a0;
    g_fn_1a6f0(msg);

    a1[0x1724] |= 2;
    *(void **)(a0 + 0x1C) = a1;
    *(int *)(a0 + 0x2C) = 0;
    *(int *)(a0 + 0x18) = 0;
}
