/* tu_349 0x2dc110-0x2dc580: medium; unk_2DC110 (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"

typedef struct Vu0RegisterState {
    u_long128 vf[32];
    u32 status;
    u32 mac;
    u32 clip;
    u32 r;
    u32 i;
    u32 q;
    u16 vi[16];
} Vu0RegisterState;

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC110);

u32 func_002DC158(u32 *p, u32 v)
{
    u32 old = *p;

    *p = v;
    return (old >> 8) & 1;
}

int func_002DC170(void)
{
    u32 v;

    VU0_CFC2_NI(v, 29);
    return (v & 0xF) == 1;
}
