#include "iopsound.h"

extern void func_00F0D4(s32);

extern s32 D_019380;

s32 func_00F5E4(void) {
    s32 timeout = 1000;

    do {
        if (imp_cdvdman_5() != 0) {
            break;
        }
        imp_thbase_33(1000);
    } while (--timeout != 0);

    if (timeout != 0) {
        timeout = 15000;
        do {
            if (imp_cdvdman_11(1) == 0) {
                break;
            }
            imp_thbase_33(1000);
        } while (--timeout != 0);
        if (timeout != 0) {
            return timeout;
        }
    }
    func_00F0D4(29);
    return timeout;
}

s32 func_00F66C(void) {
    s32 timeout;
    s32 ret = 0;

    if (imp_cdvdman_28() == 1) {
        imp_cdvdman_13(0);
        timeout = 1000;
        do {
            ret = imp_cdvdman_12();
            if (ret != 1) {
                break;
            }
            imp_thbase_33(1000);
        } while (--timeout != 0);

        if (ret == D_019380) {
            func_00F5E4();
        } else {
            ret |= 0x10;
        }
    } else {
        imp_cdvdman_13(0);
        func_00F5E4();
    }
    return ret;
}
