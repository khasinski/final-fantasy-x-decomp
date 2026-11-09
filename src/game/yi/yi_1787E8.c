/* tu_126 0x1787e8-0x17a1b8: low; ~yi (config/tu_map.tsv) */
#define func_002ED038 _hdr_func_002ED038
#include "common.h"
#include "ffx/q3.h"
#include "ffx/r1.h"
#include "ffx/r2.h"
#include "ffx/s2.h"
#include "ffx/v2.h"
#undef func_002ED038

void func_001787E8(int a, int b) {
    D_0030E9E0 = a;
    D_0030E9E4 = b;
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_1787E8", func_00178800);

INCLUDE_ASM("build/ee_asm/game/yi/yi_1787E8", func_00178C08);

INCLUDE_ASM("build/ee_asm/game/yi/yi_1787E8", yiAssert);

INCLUDE_ASM("build/ee_asm/game/yi/yi_1787E8", func_00179A10);

extern char D_0056C3E8[];
extern char D_0056C3F0[];
extern s64 func_002ED038(float);

void func_0017A110(float (*m)[4])
{
    int i;
    int j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            func_002EF240(D_0056C3E8, func_002ED038(m[i][j]));
        }
        func_002EF240(D_0056C3F0);
    }
    func_002EF240(D_0056C3F0);
}
