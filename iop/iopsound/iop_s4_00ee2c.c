#include "iopsound.h"

extern u32 D_018F94;

s32 func_00EE2C(void) {
    return imp_libsd_20(((D_018F94 >> 1) ^ 1) & 1, 0);
}
