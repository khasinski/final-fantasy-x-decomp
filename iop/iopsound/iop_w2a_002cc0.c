#include "iopsound.h"

s32 func_002CC0(s32 *cur, s32 target, s32 *cnt) {
    s32 c = *cur >> 12;
    s32 ret = 0;

    if (target != c) {
        ret = target - c;
        ret <<= 12;
        ret |= 0x800;
        ret /= *cnt;
    } else {
        *cnt = 0;
    }
    return ret;
}
