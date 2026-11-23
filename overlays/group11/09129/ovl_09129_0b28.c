/* Shared 09129/09663 draw callback (116 B). */
#include "common.h"

extern void *D_006A3924;
extern u8 g_ovl_res[];

extern unsigned long *op_oef2_a_get(void *, int, int);
extern void fn_ovl_4478(void *, void *, unsigned long, int, int);

void ovl_09129_0b28(u8 *a0)
{
    u8 *s1 = *(u8 **)((u8 *)D_006A3924 + 0x20);
    u8 *s0 = a0 + 0x130;
    u8 *s2 = a0 + 0x50;
    unsigned long *v0 = op_oef2_a_get(g_ovl_res, 2, 3);

    fn_ovl_4478(*(void **)(s1 + 0xFC), s2, *v0, (*(s16 *)(s0 + 6)) >> 7, 1);
}
