#include "iopsound.h"

extern s32 func_00C7A4(s32);

extern s32 D_01937C;
extern s32 D_019398;

s32 func_011128(s32 *arg) {
    imp_thsemap_7(D_019398);
    return *arg;
}

s32 func_01115C(s32 *arg) {
    return func_00C7A4(*arg);
}

s32 func_011180(s32 *arg) {
    imp_thsemap_7(D_01937C);
    return *arg;
}
