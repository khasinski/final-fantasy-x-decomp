/* tu_005 0x106380-0x106440: medium; unk_106380 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

void func_00106380(Blk64 *src)
{
    *(Blk64 *)&D_0057E8B0 = *src; /* DEBT(CAST) */
}

void func_001063D0(Blk64 *src)
{
    *(Blk64 *)&D_0057E8F0 = *src; /* DEBT(CAST) */
}

s32 *func_00106420(void)
{
    return &D_0057E8F0;
}

s32 *func_00106430(void)
{
    return &D_0057E8B0;
}
