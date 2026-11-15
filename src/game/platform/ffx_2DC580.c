/* tu_350 0x2dc580-0x2dce38: medium; ~FFXVu0ApplyMatrix (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DC580", func_002DC580);

void func_002DC5B0(u16 addr, V7VuQword *p)
{
    V7VuQword val;
    register int vi1 __asm__("$6");
    register u_long128 vf1 __asm__("$5");
    u64 hi = p->d[1];
    u64 lo = p->d[0];
    val.d[1] = hi;
    VU0_CFC2_NI(vi1, 1);
    val.d[0] = lo;
    VU0_QMFC2_NI(vf1, 1);
    VU0_QMTC2_NI(1, *(u_long128 *)&val);
    VU0_CTC2_NI(1, addr);
    VU0_OP("vsqi.xyzw $vf1, ($vi1++)");
    VU0_CTC2_NI(1, vi1);
    VU0_QMTC2_NI(1, vf1);
}

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DC580", func_002DC5F0);
