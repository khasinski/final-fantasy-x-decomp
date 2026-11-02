/* tu_019 0x1132b8-0x113938: low; ~Ch (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#include "ffx/g0.h"

INCLUDE_ASM("build/ee_asm/game/chr/ch_1132B8", Ch_RomDataReadInit);

INCLUDE_ASM("build/ee_asm/game/chr/ch_1132B8", func_001133A8);

void Ch_RomReadChrCB(U0Args *p)
{
    Cache_Entry_NotYet(p->w14, p->wC, 0);
}

s32 func_00113480(void)
{
    return D_0078E4A0();
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_1132B8", Ch_DataRead);

s32 Ch_DataReadSync(s32 h)
{
    s32 value0;

    value0 = Cache_CheckYet(1, h);
    if (value0 == 2)
    {
        yiAssert(0, D_00569770, D_00569788, ch_create_name(h));
    }
    return value0;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_1132B8", Ch_MgrpRead);

void func_00113810(V0Pair *p)
{
    func_00104F28(p->b, p->a);
}

s32 func_00113820(s32 a)
{
    return D_0078E518(0xC, a);
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_1132B8", Ch_RomReadEventMGRP);
