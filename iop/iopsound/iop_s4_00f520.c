#include "iopsound.h"

extern void func_00F0D4(s32);

s32 func_00F520(void) {
    s32 timeout = 1000;
    s32 err;
    s32 st;

    do {
        err = imp_cdvdman_8();
        if (err != -1) {
            break;
        }
        imp_thbase_33(1000);
    } while (--timeout != 0);

    if (timeout != 0) {
        if (err == 1) {
            timeout = 1000;
            do {
                st = imp_cdvdman_28();
                if (st != -1) {
                    break;
                }
                imp_thbase_33(1000);
            } while (--timeout != 0);

            if (timeout != 0) {
                err = (st == 1) ? 49 : 0;
            } else {
                goto fail;
            }
        }
    } else {
    fail:
        err = 19;
        func_00F0D4(29);
    }
    return err;
}
