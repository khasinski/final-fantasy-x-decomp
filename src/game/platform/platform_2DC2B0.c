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

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC330);

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC410);
