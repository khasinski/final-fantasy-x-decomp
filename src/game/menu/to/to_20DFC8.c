/* tu_234 0x20dfc8-0x20e248: low; ~TOSeqGetRect (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/t4.h"
#include "ffx/u3.h"

INCLUDE_ASM("build/ee_asm/game/menu/to/to_20DFC8", TOSeqGetRect);

void TOSeqGetColorRGBA(int a, const char *name, u8 *c0, u8 *c1, u8 *c2, u8 *c3)
{
    int idx = TkMenuGetParamHandle(a, name);
    u32 v;

    if (idx == 0) {
        *c0 = 0;
        *c1 = 0;
        *c2 = 0;
        *c3 = 0;
        return;
    }
    v = TkMenuGetParamOffset(a, idx, 0);
    *c0 = v;
    *c1 = v >> 8;
    *c2 = v >> 16;
    *c3 = v >> 24;
}

void TOSeqGetColor(int a, const char *name, int *out)
{
    int v = TkMenuGetParamHandle(a, name);

    if (v == 0) {
        *out = 0;
    } else {
        *out = TkMenuGetParamOffset(a, v, 0);
    }
}

void TOSeqGetPoint(int a, const char *name, s16 *out0, s16 *out1)
{
    int v = TkMenuGetParamHandle(a, name);

    if (v == 0) {
        *out0 = 0;
        *out1 = 0;
    } else {
        *out0 = TkMenuGetParamOffset(a, v, 0);
        *out1 = TkMenuGetParamOffset(a, v, 1);
    }
}

void TOSeqGetNum(int a, const char *name, s16 *out)
{
    int v = TkMenuGetParamHandle(a, name);

    if (v == 0) {
        *out = 0;
    } else {
        *out = TkMenuGetParamOffset(a, v, 0);
    }
}
