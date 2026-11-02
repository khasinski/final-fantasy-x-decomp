/* tu_068 0x1382e0-0x138588: low; unk_1382E0 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

void func_001382E0(void) {
}

void func_001382E8(void) {
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_1382E0", func_001382F0);

INCLUDE_ASM("build/ee_asm/game/atel/atel_1382E0", func_00138408);

int func_00138520(void) {
    int best = 0;
    int max = -1;
    int *p = (int *)(REC124828_BASE() + 0x2C);
    int i;

    for (i = 0; i < 8; i++, p++) {
        if (*p > max) {
            max = *p;
            best = i;
        }
    }
    return best;
}
