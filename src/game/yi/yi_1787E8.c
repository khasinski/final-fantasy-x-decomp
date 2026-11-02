/* tu_126 0x1787e8-0x17a1b8: low; ~yi (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/r1.h"
#include "ffx/r2.h"
#include "ffx/s2.h"
#include "ffx/v2.h"

void func_001787E8(int a, int b) {
    D_0030E9E0 = a;
    D_0030E9E4 = b;
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_1787E8", func_00178800);

INCLUDE_ASM("build/ee_asm/game/yi/yi_1787E8", func_00178C08);

INCLUDE_ASM("build/ee_asm/game/yi/yi_1787E8", yiAssert);

INCLUDE_ASM("build/ee_asm/game/yi/yi_1787E8", func_00179A10);

INCLUDE_ASM("build/ee_asm/game/yi/yi_1787E8", func_0017A110);
