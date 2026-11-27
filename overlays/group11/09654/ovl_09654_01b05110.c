#include "common.h"

extern u8 *g_state_db20;
extern u8 g_sym_d9d8[];

extern float g_fn_4a18(void);
extern void g_fn_8ec0(void *, void *, int, int, int, int, float);
extern void g_fn_5028(void *);
extern void g_fn_cad0(void *, int);

void func_01B05110(void)
{
    u8 *st = g_state_db20;
    u8 *sub = st + 0x720;
    u8 *p;
    float s = g_fn_4a18() * 0.0018f;

    g_fn_8ec0(g_sym_d9d8, sub, 6, 0, 0, 0, s);
    {
        register u32 two __asm__("$2") = 2;
        register void *fn __asm__("$3") = g_fn_5028;
        sub[0x126] = two;
        *(void **)(sub + 0x104) = fn;
    }

    p = st + 0x1490;
    p[0x86] = 0xFF;
    p[0x85] = 0xFF;
    p[0x84] = 0xFF;
    p[0x87] = 0x80;
    p[0x98] = 0x48;
    p[0x83] = 0;
    p[0x82] = 0;
    p[0x81] = 0;
    p[0x80] = 0;
    p[0x99] = 0;
    *(u32 *)(p + 0x88) = 4;
    g_fn_cad0(p, 0x14);
    *(u32 *)(p + 0x94) = 1;

    p = st + 0x1530;
    p[0x82] = 0xFF;
    p[0x81] = 0xFF;
    p[0x80] = 0xFF;
    p[0x83] = 0x80;
    p[0x98] = 0x48;
    p[0x87] = 0;
    p[0x86] = 0;
    p[0x85] = 0;
    p[0x84] = 0;
    p[0x99] = 0;
    *(u32 *)(p + 0x88) = 0x19;
    g_fn_cad0(p, 0x14);
}
