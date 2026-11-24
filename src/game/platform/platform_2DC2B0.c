/* tu_349 0x2dc110-0x2dc580: medium; unk_2DC110 (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"

u32 func_002DC2B0(void)
{
    u32 v;

    VU0_CFC2_NI(v, 28);
    return (v >> 2) & 1;
}

u32 func_002DC2C0(void)
{
    u32 v;

    VU0_CFC2_NI(v, 28);
    return (v >> 3) & 1;
}

int func_002DC2D0(void)
{
    u32 v;

    VU0_CFC2_NI(v, 29);
    if (v & 2) {
        return 1;
    }
    if (v & 4) {
        return 2;
    }
    if (v & 8) {
        return 3;
    }
    return (v & 1) ? 4 : 0;
}

void func_002DC310(int addr)
{
    VU0_CTC2_NI(27, addr & 0xFFFF);
    VU0_OP("vcallmsr $vi27");
}

int func_002DC320(void)
{
    int v;

    VU0_CFC2_NI(v, 26);
    return v & 0xFFFF;
}

#define VU0_CFC2_NI_NV(v, vi) __asm__("cfc2.ni %0, $vi" #vi : "=r"(v))

int func_002DC330(u8 *buf)
{
    int v;

    if (func_002DC170(buf) != 0) {
        return 0;
    }
    VU0_CFC2_NI_NV(v, 16); *(u32 *)(buf + 0x200) = v;
    VU0_CFC2_NI_NV(v, 17); *(u32 *)(buf + 0x204) = v;
    VU0_CFC2_NI_NV(v, 18); *(u32 *)(buf + 0x208) = v;
    VU0_CFC2_NI_NV(v, 20); *(u32 *)(buf + 0x20C) = v;
    VU0_CFC2_NI_NV(v, 21); *(u32 *)(buf + 0x210) = v;
    VU0_CFC2_NI_NV(v, 22); *(u32 *)(buf + 0x214) = v;
    VU0_CFC2_NI_NV(v, 0); *(u16 *)(buf + 0x218) = v;
    VU0_CFC2_NI_NV(v, 1); *(u16 *)(buf + 0x21A) = v;
    VU0_CFC2_NI_NV(v, 2); *(u16 *)(buf + 0x21C) = v;
    VU0_CFC2_NI_NV(v, 3); *(u16 *)(buf + 0x21E) = v;
    VU0_CFC2_NI_NV(v, 4); *(u16 *)(buf + 0x220) = v;
    VU0_CFC2_NI_NV(v, 5); *(u16 *)(buf + 0x222) = v;
    VU0_CFC2_NI_NV(v, 6); *(u16 *)(buf + 0x224) = v;
    VU0_CFC2_NI_NV(v, 7); *(u16 *)(buf + 0x226) = v;
    VU0_CFC2_NI_NV(v, 8); *(u16 *)(buf + 0x228) = v;
    VU0_CFC2_NI_NV(v, 9); *(u16 *)(buf + 0x22A) = v;
    VU0_CFC2_NI_NV(v, 10); *(u16 *)(buf + 0x22C) = v;
    VU0_CFC2_NI_NV(v, 11); *(u16 *)(buf + 0x22E) = v;
    VU0_CFC2_NI_NV(v, 12); *(u16 *)(buf + 0x230) = v;
    VU0_CFC2_NI_NV(v, 13); *(u16 *)(buf + 0x232) = v;
    VU0_CFC2_NI_NV(v, 14); *(u16 *)(buf + 0x234) = v;
    VU0_CFC2_NI_NV(v, 15); *(u16 *)(buf + 0x236) = v;
    return 1;
}

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC410);
