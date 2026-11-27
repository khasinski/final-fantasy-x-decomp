#include "common.h"

extern u8 g_sym_a478[];
extern u8 g_sym_0ce8[];

extern void g_fn_19ff0(void *);
extern void g_fn_1a3f8(void *);
extern void g_fn_10990(void *);

void func_01B0A6C0(u8 *a0, int a1)
{
    void *msg[4];

    msg[0] = a0;
    msg[1] = g_sym_a478;
    msg[2] = a0;
    g_fn_19ff0(msg);

    msg[0] = g_sym_0ce8;
    msg[1] = a0;
    g_fn_1a3f8(msg);

    *(int *)(a0 + 0x1C) = a1;
    msg[0] = (void *)a1;
    msg[1] = (void *)188;
    g_fn_10990(msg);

    *(int *)(a0 + 0x2C) = 0;
    *(int *)(a0 + 0x18) = 0;
}
