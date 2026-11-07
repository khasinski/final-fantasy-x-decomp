/* tu_068 0x1382e0-0x138588: low; unk_1382E0 (config/tu_map.tsv) */
#define func_001382F0 _hdr_func_001382F0
#define func_00138408 _hdr_func_00138408
#include "common.h"
#include "ffx/q1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#undef func_001382F0
#undef func_00138408

void func_001382E0(void) {
}

void func_001382E8(void) {
}

s32 _m2c_func_001382F0_Sg_LightGetColor(s32, float *) __asm__("Sg_LightGetColor");
s32 _m2c_func_001382F0_Sg_LightGetDir(s32, float *) __asm__("Sg_LightGetDir");
s32 _m2c_func_001382F0_func_001382E0(s8 *, float *) __asm__("func_001382E0");
s32 _m2c_func_001382F0_func_001382E8(s8 *, float *) __asm__("func_001382E8");
void func_001382F0(void) {
    _m2c_func_001382F0_Sg_LightGetColor(0, D_0058E5C0);
    _m2c_func_001382F0_func_001382E0(D_0056A650, D_0058E5C0);
    _m2c_func_001382F0_Sg_LightGetColor(1, D_0058E5D0);
    _m2c_func_001382F0_func_001382E0(D_0056A658, D_0058E5D0);
    _m2c_func_001382F0_Sg_LightGetColor(2, D_0058E5E0);
    _m2c_func_001382F0_func_001382E0(D_0056A660, D_0058E5E0);
    _m2c_func_001382F0_Sg_LightGetColor(3, D_0058E5F0);
    _m2c_func_001382F0_func_001382E0(D_0056A668, D_0058E5F0);
    _m2c_func_001382F0_Sg_LightGetDir(0, D_0058E600);
    _m2c_func_001382F0_func_001382E8(D_0056A670, D_0058E600);
    _m2c_func_001382F0_Sg_LightGetDir(1, D_0058E610);
    _m2c_func_001382F0_func_001382E8(D_0056A678, D_0058E610);
    _m2c_func_001382F0_Sg_LightGetDir(2, D_0058E620);
    _m2c_func_001382F0_func_001382E8(D_0056A680, D_0058E620);
}

s32 _m2c_func_00138408_Sg_LightSetColor(s32, float *) __asm__("Sg_LightSetColor");
s32 _m2c_func_00138408_Sg_LightSetDir(s32, float *) __asm__("Sg_LightSetDir");
s32 _m2c_func_00138408_func_001382E0(s8 *, float *) __asm__("func_001382E0");
s32 _m2c_func_00138408_func_001382E8(s8 *, float *) __asm__("func_001382E8");
void func_00138408(void) {
    _m2c_func_00138408_Sg_LightSetColor(0, D_0058E5C0);
    _m2c_func_00138408_func_001382E0(D_0056A650, D_0058E5C0);
    _m2c_func_00138408_Sg_LightSetColor(1, D_0058E5D0);
    _m2c_func_00138408_func_001382E0(D_0056A658, D_0058E5D0);
    _m2c_func_00138408_Sg_LightSetColor(2, D_0058E5E0);
    _m2c_func_00138408_func_001382E0(D_0056A660, D_0058E5E0);
    _m2c_func_00138408_Sg_LightSetColor(3, D_0058E5F0);
    _m2c_func_00138408_func_001382E0(D_0056A668, D_0058E5F0);
    _m2c_func_00138408_Sg_LightSetDir(0, D_0058E600);
    _m2c_func_00138408_func_001382E8(D_0056A670, D_0058E600);
    _m2c_func_00138408_Sg_LightSetDir(1, D_0058E610);
    _m2c_func_00138408_func_001382E8(D_0056A678, D_0058E610);
    _m2c_func_00138408_Sg_LightSetDir(2, D_0058E620);
    _m2c_func_00138408_func_001382E8(D_0056A680, D_0058E620);
}

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
