/* tu_132 0x180b70-0x184ea0: medium; ~yi (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/v2.h"

void func_00180B70(R2Big4000 *o) {
    int i;
    int *p = &o->q[0].a;
    for (i = 0; i < 0x400; i++) {
        p[0] = p[1] = p[2] = p[3] = 0;
        p += 4;
    }
    o->w4000 = 0;
    o->w4008 = 0;
    o->a4050[0] = o->a4050[1] = o->a4050[2] = o->a4050[3] = 0;
    o->a4060[0] = o->a4060[1] = o->a4060[2] = o->a4060[3] = 0;
    o->w407C = 0;
    o->w4080 = 0;
    o->w4074 = 0;
    o->w4078 = 0;
    o->w4084 = 0;
    o->w4088 = 0;
    o->b408C = 0;
    o->b408D = 0;
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_180B70", func_00180BE8);

INCLUDE_ASM("build/ee_asm/game/yi/yi_180B70", func_00180C58);

INCLUDE_ASM("build/ee_asm/game/yi/yi_180B70", yiExecVIFpacket);
INCLUDE_RODATA("build/ee_asm/game/yi/yi_180B70/rodata", jtbl_0056CDE0);

INCLUDE_ASM("build/ee_asm/game/yi/yi_180B70", func_001812C0);

INCLUDE_ASM("build/ee_asm/game/yi/yi_180B70", func_001812C8);

INCLUDE_ASM("build/ee_asm/game/yi/yi_180B70", func_00181378);

INCLUDE_ASM("build/ee_asm/game/yi/yi_180B70", func_00181428);

INCLUDE_ASM("build/ee_asm/game/yi/yi_180B70", yiPacketConvToOMD);

INCLUDE_ASM("build/ee_asm/game/yi/yi_180B70", func_00181B48);

INCLUDE_ASM("build/ee_asm/game/yi/yi_180B70", func_00181BC8);

INCLUDE_ASM("build/ee_asm/game/yi/yi_180B70", func_00181C28);

INCLUDE_ASM("build/ee_asm/game/yi/yi_180B70", func_001836E0);

INCLUDE_ASM("build/ee_asm/game/yi/yi_180B70", func_00184AA8);
