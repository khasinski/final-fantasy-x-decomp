/* tu_349 0x2dc110-0x2dc580: medium; unk_2DC110 (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"

void func_002DC250(int enabled) {
    u32 status;
    VU0_CFC2_NI(status, 28);
    if (enabled == 1) status |= 0x4;
    else status &= 0xFFFFFFFB;
    VU0_CTC2_NI(28, status);
}

void func_002DC280(int enabled) {
    u32 status;
    VU0_CFC2_NI(status, 28);
    if (enabled == 1) status |= 0x8;
    else status &= 0xFFFFFFF7;
    VU0_CTC2_NI(28, status);
}
