/* Shared 09522-family task init (92 B, 8 containers). */
#include "common.h"

extern u8 fn_ovl_23f0[];
extern u8 g_ovl_b20[];
extern void fn_ovl_bde0(void *);
extern void fn_ovl_c1e8(void *);

void ovl_09522_27c0(u8 *a0)
{
    u32 buf[3];

    buf[0] = (u32)a0;
    buf[1] = (u32)fn_ovl_23f0;
    buf[2] = (u32)a0;
    fn_ovl_bde0(buf);
    buf[0] = (u32)g_ovl_b20;
    buf[1] = (u32)a0;
    fn_ovl_c1e8(buf);
    *(volatile u32 *)(a0 + 0x18) = 0;
    *(volatile u32 *)(a0 + 0x1C) = 0;
}
