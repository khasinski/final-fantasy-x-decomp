#include "common.h"

extern u8 g_sym_0a80[];
void g_fn_cb1(void *);
void g_fn_cb2(void *m);
void g_fn_cb3(void *m);

void func_01B1A2D0(u8 *a0, int a1)
{
    void *m[4];

    m[0] = a0;
    m[1] = g_fn_cb1;
    m[2] = a0;
    g_fn_cb2(m);
    m[0] = g_sym_0a80;
    m[1] = a0;
    g_fn_cb3(m);
    *(int *)(a0 + 0x3C) = a1;
    *(int *)(a0 + 0x30) = 0;
    *(int *)(a0 + 0x18) = 0;
}
