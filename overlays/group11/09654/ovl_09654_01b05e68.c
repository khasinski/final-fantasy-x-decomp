#include "common.h"

extern u8 *g_state_db20;
extern u8 g_sym_d9d8[];

extern float g_fn_4a18(void);
extern void g_fn_8ec0(void *, void *, int, int, int, int, float);
extern void g_fn_4b40(void *);
extern void g_fn_cad0(void *, int);
extern void g_fn_cc88(void *, int, int, float, float);

void func_01B05E68(void)
{
    u8 *sub = g_state_db20 + 0x260;
    float s = g_fn_4a18() * 0.0005f;

    g_fn_8ec0(g_sym_d9d8, sub, 2, 0, 0, 0, s);
    {
        register u32 two __asm__("$2") = 2;
        register void *fn __asm__("$3") = g_fn_4b40;
        sub[0x126] = two;
        *(void **)(sub + 0x104) = fn;
    }
}

void func_01B05ED8(void)
{
    u8 *st = g_state_db20;
    u8 *sub = st + 0x15D0;

    sub[0x83] = 0x80;
    sub[0x82] = 0x80;
    sub[0x81] = 0x80;
    sub[0x80] = 0x80;
    sub[0x84] = 0x80;
    sub[0x85] = 0x80;
    sub[0x86] = 0x80;
    {
        register u32 c28 __asm__("$6") = 0x28;
        register u32 c48 __asm__("$7") = 0x48;
        *(u32 *)(sub + 0x88) = c28;
        sub[0x98] = c48;
    }
    sub[0x87] = 0;
    sub[0x99] = 0;
    g_fn_cad0(sub, 0x14);
    g_fn_cc88(st + 0x1830, 0x1E, 0x6E, 0.5f, 1.0f);
}

void func_01B05F60(void)
{
    u8 *st = g_state_db20;
    u8 *sub = st + 0x15D0;

    sub[0x86] = 0xFF;
    sub[0x85] = 0xFF;
    sub[0x84] = 0xFF;
    sub[0x87] = 0x80;
    sub[0x98] = 0x48;
    sub[0x83] = 0;
    sub[0x82] = 0;
    sub[0x81] = 0;
    sub[0x80] = 0;
    sub[0x99] = 0;
    *(u32 *)(sub + 0x88) = 0x14;
    g_fn_cad0(sub, 0x1E);
    *(u32 *)(sub + 0x94) = 1;

    sub = st + 0x1670;
    sub[0x82] = 0xFF;
    sub[0x81] = 0xFF;
    sub[0x80] = 0xFF;
    sub[0x83] = 0x80;
    sub[0x98] = 0x48;
    sub[0x87] = 0;
    sub[0x86] = 0;
    sub[0x85] = 0;
    sub[0x84] = 0;
    sub[0x99] = 0;
    *(u32 *)(sub + 0x88) = 0x33;
    g_fn_cad0(sub, 0x1E);

    g_fn_cc88(st + 0x1830, 0x1E, 0x28, 0.5f, 1.0f);
}
