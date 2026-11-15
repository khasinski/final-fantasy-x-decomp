/* tu_041 0x123844-0x124058: high; ~sg (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"

INCLUDE_ASM("build/ee_asm/game/main/sg_123844", func_00123844);

INCLUDE_ASM("build/ee_asm/game/main/sg_123844", func_00123878);

INCLUDE_ASM("build/ee_asm/game/main/sg_123844", sg_getvtex);

INCLUDE_ASM("build/ee_asm/game/main/sg_123844", sg_getnorm);

INCLUDE_ASM("build/ee_asm/game/main/sg_123844", func_001238B0);

INCLUDE_ASM("build/ee_asm/game/main/sg_123844", func_001238C8);

INCLUDE_ASM("build/ee_asm/game/main/sg_123844", func_001239CC);

INCLUDE_ASM("build/ee_asm/game/main/sg_123844", func_00123BAC);

INCLUDE_ASM("build/ee_asm/game/main/sg_123844", func_00123C00);

INCLUDE_ASM("build/ee_asm/game/main/sg_123844", func_00123C40);

int func_00123C60(void)
{
    int status;

    VU0_CFC2_NI(status, 28);
    return status;
}

void func_00123C6C(void)
{
    BREAK();
}

INCLUDE_ASM("build/ee_asm/game/main/sg_123844", func_00123C78);

void func_00123CD0(void)
{
}

INCLUDE_ASM("build/ee_asm/game/main/sg_123844", func_00123CD8);

INCLUDE_ASM("build/ee_asm/game/main/sg_123844", func_00123EC4);
