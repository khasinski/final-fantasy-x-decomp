/* tu_178 0x1ac0b8-0x1acfd8: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q4.h"
#include "ffx/s2.h"
#include "ffx/u2.h"
#include "ffx/v2.h"

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC0B8);

int func_001AC128(u32 i) {
    int r = 0;
    int j;
    Rec142F0 *p;
    if (i < 3) {
        p = &ms_screen[i];
        for (j = 0; j < 2; j++) {
            if (p->e16C[j].b != 0) {
                r = -1;
                break;
            }
        }
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC188);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC200);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC230);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC258);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC290);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC2D0);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC310);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC348);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC388);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC3D0);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC3E8);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC400);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC458);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC528);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC5E0);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC698);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC750);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", MsVectorRect2Polar);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001ACAE8);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001ACB10);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001ACB28);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001ACB48);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001ACCB0);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001ACD48);

int func_001ACDB8(void) {
    u8 b[8];
    func_002E2128(b);
    return (b[0] ^ b[1] ^ b[2] ^ b[3] ^ b[4] ^ b[5] ^ b[6] ^ b[7]) + 1;
}

void func_001ACE18(s32 arg0)
{
    s32 *output;
    s32 seed;
    s32 remaining;

    remaining = 0x43;
    seed = func_001ACDB8();
    seed *= arg0 + 1;
    /* DEBT(ORDER): independent seed updates retain original scheduling. */
    D_00317130 = (seed * 0x420C56D7) + 0x2E0A;
    D_00317134 = (seed * 0x599E67E6) + 0x301D;
    func_001ACEA0();
    output = D_0065FE30;
    do
    {
        remaining -= 1;
        *output = func_001ACEA0();
        output += 1;
    } while (remaining >= 0);
}

/* random number generator: LCG with multiplier 0x5D588B65 on the seed D_00317130 */
int func_001ACEA0(void) {
    s32 seed = D_00317130 * 0x5D588B65 + 0x3C35;
    D_00317130 = (seed >> 16) + (seed << 16);
    return D_00317130 & 0x7FFFFFFF;
}

float func_001ACED8(void) {
    union { u32 u; float f; } v;

    v.u = (func_001ACEA0() & 0x7FFFFF) | 0x3F800000;
    return v.f;
}

int func_001ACF10(void) {
    int v;

    /* DEBT(TYPE): func_002D4138 returns s64; this caller was compiled against an int prototype */
    v = D_00317134 * 0x6C078965 + ((int (*)(void))func_002D4138)() + 0x4F07;
    D_00317134 = (v >> 16) + (v << 16);
    return D_00317134 & 0x7FFFFFFF;
}

int brnd(int i) {
    int v;
    D_0065FE30[i] = D_0065FE30[i] * D_00317138[i];
    D_0065FE30[i] ^= D_00317248[i];
    v = D_0065FE30[i];
    D_0065FE30[i] = (v >> 16) + (v << 16);
    return D_0065FE30[i] & 0x7FFFFFFF;
}

u8 *func_001ACFC8(void) {
    return D_0056DFB0;
}
