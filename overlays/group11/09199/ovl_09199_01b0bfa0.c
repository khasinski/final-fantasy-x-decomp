#include "common.h"

extern u8 g_fn_cb[];
extern u8 g_sym_0cc0[];
extern void g_fn_reg1(void *);
extern void g_fn_reg2(void *);

void func_01B0BFA0(u8 *a0)
{
    void *m[4];

    m[0] = a0;
    m[2] = a0;
    m[1] = g_fn_cb;
    g_fn_reg1(m);
    m[1] = a0;
    m[0] = g_sym_0cc0;
    g_fn_reg2(m);
    *(int *)(a0 + 0x34) = 0;
    *(int *)(a0 + 0x18) = 0x64;
}
