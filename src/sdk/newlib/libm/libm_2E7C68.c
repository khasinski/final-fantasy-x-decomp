/* tu_357 0x2e7c68-0x2e7e60: high; unk_2E7C68 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"

int func_002E7C68(double x)
{
    int hx;

    GET_HIGH_WORD(hx, x);
    return (u32)((hx & 0x7fffffff) - 0x7ff00000) >> 31;
}

INCLUDE_ASM("build/ee_asm/sdk/newlib/libm/libm_2E7C68", func_002E7C88);
