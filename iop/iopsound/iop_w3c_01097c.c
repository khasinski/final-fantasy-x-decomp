#include "iopsound.h"

extern volatile s32 D_018708;
extern s32 D_01931C[];

s32 func_01097C(s32 *arg) {
    if (*arg != 0) {
        D_018708 &= ~0x100;
        imp_libsd_11(2, 1);
        imp_libsd_11(3, 1);
        *D_01931C |= 4;
    } else {
        D_018708 |= 0x100;
        imp_libsd_11(2, 0);
        imp_libsd_11(3, 0);
        imp_libsd_5(0x0B80, 0);
        imp_libsd_5(0x0C80, 0);
        imp_libsd_5(0x0B81, 0);
        imp_libsd_5(0x0C81, 0);
    }
    return *arg;
}
