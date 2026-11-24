#include "common.h"

extern u16 D_01B12E90[];
extern u16 D_01B12E98[];
extern u16 D_01B12EA0[];

u16 func_01B0AB30(s32 i) {
    return D_01B12E90[i];
}

u16 func_01B0AB48(s32 i) {
    return D_01B12E98[i];
}

u16 func_01B0AB60(s32 i) {
    return D_01B12EA0[i];
}
