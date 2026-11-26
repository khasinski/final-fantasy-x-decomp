#include "iopsound.h"

extern volatile s32 D_018704;

s32 func_010770(s32 *arg) {
    s32 val;

    D_018704 = (*arg != 0) << 7;
    val = imp_libsd_12(10) & 0xFF7F;
    val |= D_018704;
    imp_libsd_11(10, (u16)val);
    return D_018704;
}
