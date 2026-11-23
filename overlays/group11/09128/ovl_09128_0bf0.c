/* Shared 09128-family draw callbacks (236 B: 0x0BF0 + 0x0C68). */
#include "common.h"

extern void *D_006A3924;
extern u8 g_ovl_res[];

extern unsigned long *op_oef2_a_get(void *, int, int);
extern void fn_ovl_45b8(void *, void *, unsigned long, int, int);

void ovl_09128_0bf0(u8 *a0)
{
    u8 *s1 = *(u8 **)((u8 *)D_006A3924 + 0x20);
    u8 *s0 = a0 + 0x130;
    u8 *s2 = a0 + 0x50;
    unsigned long *v0 = op_oef2_a_get(g_ovl_res, 2, 3);

    fn_ovl_45b8(*(void **)(s1 + 0x3C), s2, *v0, (*(s16 *)(s0 + 6)) >> 7, 1);
}

void ovl_09128_0c68(u8 *a0)
{
    u8 *s1 = *(u8 **)((u8 *)D_006A3924 + 0x20);
    u8 *s0 = a0 + 0x130;
    u8 *s2 = a0 + 0x50;
    unsigned long *v0 = op_oef2_a_get(g_ovl_res, 2, 3);

    fn_ovl_45b8(*(void **)(s1 + 0x11C), s2, *v0, (*(s16 *)(s0 + 6)) >> 7, 1);
}
