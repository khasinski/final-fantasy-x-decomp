/* tu_212 0x1e4c30-0x1e4cd0: medium; unk_1E4C30 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/g3.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"

void func_001E4C30(u32 i, float v) {
    if (i < 16) {
        D_00663200[i] = v;
    }
}

float func_001E4C58(u32 i) {
    float r = 0.0f;
    if (i < 16) {
        r = D_00663200[i];
    }
    return r;
}

void func_001E4C80(u32 i, int v) {
    if (i < 16) {
        D_00663240[i] = v;
    }
}

int func_001E4CA8(u32 i) {
    int r = 0;
    if (i < 16) {
        r = D_00663240[i];
    }
    return r;
}
