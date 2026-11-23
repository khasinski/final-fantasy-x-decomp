/* 09136 draw callbacks (236 B: 0x0D78 + 0x0DF0). */
#include "common.h"

extern void *D_006A3924;
extern u8 g_ovl_res[];

extern unsigned long *op_oef2_a_get(void *, int, int);
extern void fn_ovl_4740(void *, void *, unsigned long, int, int);

void ovl_09136_0d78(u8 *a0)
{
    u8 *s1 = *(u8 **)((u8 *)D_006A3924 + 0x20);
    u8 *s0 = a0 + 0x110;
    u8 *s2 = a0 + 0x50;
    unsigned long *v0 = op_oef2_a_get(g_ovl_res, 2, 0);

    fn_ovl_4740(*(void **)(s1 + 0x5C), s2, *v0, (*(s16 *)(s0 + 6)) >> 7, 1);
}

void ovl_09136_0df0(u8 *a0)
{
    u8 *s1 = *(u8 **)((u8 *)D_006A3924 + 0x20);
    u8 *s0 = a0 + 0x130;
    u8 *s2 = a0 + 0x50;
    unsigned long *v0 = op_oef2_a_get(g_ovl_res, 2, 0);

    fn_ovl_4740(*(void **)(s1 + 0x23C), s2, *v0, (*(s16 *)(s0 + 6)) >> 7, 1);
}
