/* tu_350 0x2dc580-0x2dce38: medium; ~FFXVu0ApplyMatrix (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"

void func_002DC700(int enabled) {
    u32 status;
    VU0_CFC2_NI(status, 28);
    if (enabled == 1) status |= 0x400;
    else status &= 0xFFFFFBFF;
    VU0_CTC2_NI(28, status);
}

void func_002DC730(int enabled) {
    u32 status;
    VU0_CFC2_NI(status, 28);
    if (enabled == 1) status |= 0x800;
    else status &= 0xFFFFF7FF;
    VU0_CTC2_NI(28, status);
}

u32 func_002DC760(void)
{
    u32 v;

    VU0_CFC2_NI(v, 28);
    return (v >> 10) & 1;
}

u32 func_002DC770(void)
{
    u32 v;

    VU0_CFC2_NI(v, 28);
    return (v >> 11) & 1;
}

int func_002DC780(void) {
    u32 status;
    VU0_CFC2_NI(status, 29);
    if (status & 0x200) status = 1;
    else if (status & 0x400) status = 2;
    else if (status & 0x800) status = 3;
    else if (status & 0x100) status = 4;
    else status = 0;
    return status;
}

void func_002DC7C8(int value)
{
    value &= 0xFFFF;
    VU0_CTC2_NI(31, value);
}
