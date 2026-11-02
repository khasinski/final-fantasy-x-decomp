/* tu_067 0x138220-0x1382e0: medium; ~Tk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

int func_00138220(void) {
    return func_001AFA00();
}

int func_00138240(void) {
    return func_001BD360();
}

void func_00138260(void) {
    int i;

    for (i = 1; i >= 0; i--) {
        D_0058D448[i] = 2.0f;
    }
}

float TkGetMessageSpeed(int i) {
    i = i != 0;
    return D_0058D448[i];
}

void func_001382C0(int i, float v) {
    i = i != 0;
    D_0058D448[i] = v;
}
