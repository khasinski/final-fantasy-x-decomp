#include "common.h"

extern u8 g_sym_b778[];
extern u8 g_sym_0f40[];
extern void g_fn_d740(void *);
extern void g_fn_db48(void *);

void func_01B0D1F8(u8 *a0)
{
    void *m[4];

    m[0] = a0;
    m[2] = a0;
    m[1] = g_sym_b778;
    g_fn_d740(m);
    m[1] = a0;
    m[0] = g_sym_0f40;
    g_fn_db48(m);
    *(u32 *)(a0 + 0x34) = 0;
    *(u32 *)(a0 + 0x18) = 0x96;
}
