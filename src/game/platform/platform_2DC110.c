/* tu_349 0x2dc110-0x2dc580: medium; unk_2DC110 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC110);

u32 func_002DC158(u32 *p, u32 v)
{
    u32 old = *p;

    *p = v;
    return (old >> 8) & 1;
}

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC170);

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC188);

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC1A0);
INCLUDE_RODATA("build/ee_asm/game/platform/platform_2DC110/rodata", jtbl_005769D0);

int func_002DC200(void)
{
    int r = 0;
    int n = func_002DC2D0();

    if (n < 4) {
        if (n > 0) {
            r = 1;
            func_002DC310(func_002DC320());
        }
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC250);

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC280);

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC2B0);

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC2C0);

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC2D0);

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC310);

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC320);

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC330);

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC410);
