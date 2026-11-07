/* tu_234 0x20dfc8-0x20e248: low; ~TOSeqGetRect (config/tu_map.tsv) */
#define TOSeqGetRect _hdr_TOSeqGetRect
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/t4.h"
#include "ffx/u3.h"
#undef TOSeqGetRect

s32 _m2c_TOSeqGetRect_TkMenuGetParamHandle() __asm__("TkMenuGetParamHandle");
s16 _m2c_TOSeqGetRect_TkMenuGetParamOffset(s32, s32, s32) __asm__("TkMenuGetParamOffset");
void TOSeqGetRect(s32 arg0, s32 arg1, s16 *arg2, s16 *arg3, s16 *arg4, s16 *arg5) {
    s32 temp_2;

    temp_2 = _m2c_TOSeqGetRect_TkMenuGetParamHandle(arg0);
    if (temp_2 == 0) {
        *arg2 = 0;
        *arg3 = 0;
        *arg4 = 0;
        *arg5 = 0;
        return;
    }
    *arg2 = _m2c_TOSeqGetRect_TkMenuGetParamOffset(arg0, temp_2, 0);
    *arg3 = _m2c_TOSeqGetRect_TkMenuGetParamOffset(arg0, temp_2, 1);
    *arg4 = _m2c_TOSeqGetRect_TkMenuGetParamOffset(arg0, temp_2, 2);
    *arg5 = _m2c_TOSeqGetRect_TkMenuGetParamOffset(arg0, temp_2, 3);
}

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
