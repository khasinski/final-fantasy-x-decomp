/* tu_006 0x106440-0x106dc8: medium; ~Sg (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

s32 *func_00106440(void)
{
    return &D_00303650;
}

s32 *func_00106450(void)
{
    return &D_0057E970;
}

s32 *func_00106460(void)
{
    return &D_00303650;
}

s32 *func_00106470(void)
{
    return &D_0057E970;
}

V128 *func_00106480(s32 unused, V128 *dst)
{
    if (dst != 0) {
        *dst = D_003035C0;
    }
    return &D_003035C0;
}

void Sg_InitLight(void)
{
    func_002DD5A8(&D_00303650, &D_003035F0, &D_00303600, &D_00303610, &D_00303620);
    func_002DD4E8(&D_0057E970, &D_003035C0, &D_003035D0, &D_003035E0);
}

INCLUDE_ASM("build/ee_asm/game/main/sg_106440", Sg_LightSetDir);

void Sg_LightGetDir(int i, V128 *v)
{
    switch (i) {
    case 0:
        *v = D_003035C0;
        break;
    case 1:
        *v = D_003035D0;
        break;
    case 2:
        *v = D_003035E0;
        break;
    }
}

INCLUDE_ASM("build/ee_asm/game/main/sg_106440", Sg_LightSetColor);

/* DEBT(CAST): the public vector pointer is copied as two 64-bit words. */
void Sg_LightGetColor(int i, float *v)
{
    V128 *out = (V128 *)v;
    switch (i) {
    case 0: *out = D_003035F0; break;
    case 1: *out = D_00303600; break;
    case 2: *out = D_00303610; break;
    case 3: *out = D_00303620; break;
    }
}

s32 func_00106780(s32 a, float x, float y, float z)
{
    float v[4];

    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = 0;
    return Sg_LightSetColor(a, v);
}

s32 func_001067B0(s32 a, float x, float y, float z)
{
    float v[4];

    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = 0;
    return Sg_LightSetDir(a, v);
}

s32 func_001067E0(s32 a, float x, float y, float z)
{
    float v[4];

    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = 0;
    return Sg_LightSetDir(a, v);
}

INCLUDE_ASM("build/ee_asm/game/main/sg_106440", func_00106810);

INCLUDE_ASM("build/ee_asm/game/main/sg_106440", func_00106A08);
