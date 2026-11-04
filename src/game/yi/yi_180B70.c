/* tu_132 0x180b70-0x184ea0: medium; ~yi (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
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

void func_00181B48(float *p, int n)
{
    if (n > 0) do {
        VU0_LQC2(5, 0x0, p);
        VU0_LQC2(6, 0x10, p);
        VU0_LQC2(7, 0x20, p);
        VU0_OP("vaddx.w $vf5, $vf0, $vf0x");
        VU0_OP("vaddx.w $vf6, $vf0, $vf0x");
        VU0_OP("vaddx.w $vf7, $vf0, $vf0x");
        VU0_OP("vmulax.xyzw ACC, $vf1, $vf5x");
        VU0_OP("vmadday.xyzw ACC, $vf2, $vf5y");
        VU0_OP("vmaddaz.xyzw ACC, $vf3, $vf5z");
        VU0_OP("vmaddw.xyzw $vf5, $vf4, $vf5w");
        VU0_OP("vmulax.xyzw ACC, $vf1, $vf6x");
        VU0_OP("vmadday.xyzw ACC, $vf2, $vf6y");
        VU0_OP("vmaddaz.xyzw ACC, $vf3, $vf6z");
        VU0_OP("vmaddw.xyzw $vf6, $vf4, $vf6w");
        VU0_OP("vmulax.xyzw ACC, $vf1, $vf7x");
        VU0_OP("vmadday.xyzw ACC, $vf2, $vf7y");
        VU0_OP("vmaddaz.xyzw ACC, $vf3, $vf7z");
        VU0_OP("vmaddw.xyzw $vf7, $vf4, $vf7w");
        VU0_SQC2(5, 0x0, p);
        VU0_SQC2(6, 0x10, p);
        VU0_SQC2(7, 0x20, p);
        p += 12;
        n--;
        VU0_OP("nop");
        VU0_OP("nop");
        VU0_OP("nop");
    } while (n != 0);
}

void func_00181BC8(float *m, float *v, int cnt)
{
    int n;

    VU0_LQC2(26, 0x0, m);
    VU0_LQC2(27, 0x10, m);
    VU0_LQC2(28, 0x20, m);
    VU0_LQC2(29, 0x30, m);
    n = cnt * 3;
    if (n > 0) do {
        VU0_LQC2(30, 0x0, v);
        VU0_OP("vaddx.w $vf30, $vf0, $vf0x");
        VU0_OP("vmulax.xyzw ACC, $vf26, $vf30x");
        VU0_OP("vmadday.xyzw ACC, $vf27, $vf30y");
        VU0_OP("vmaddaz.xyzw ACC, $vf28, $vf30z");
        VU0_OP("vmaddw.xyzw $vf30, $vf29, $vf30w");
        VU0_SQC2(30, 0x0, v);
        v += 4;
        n--;
        VU0_OP("nop");
        VU0_OP("nop");
        VU0_OP("nop");
    } while (n != 0);
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_180B70", func_00181C28);

INCLUDE_ASM("build/ee_asm/game/yi/yi_180B70", func_001836E0);

INCLUDE_ASM("build/ee_asm/game/yi/yi_180B70", func_00184AA8);
