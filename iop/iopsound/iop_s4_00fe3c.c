#include "iopsound.h"

extern volatile s32 D_06D230[2];

s32 func_00FE3C(s32 ch, s32 flag) {
    s32 oldstat;
    s32 intr_res;
    s32 i;

    ch &= 1;
    if (flag == 1) {
        intr_res = imp_intrman_17(&oldstat);
        if (intr_res == 0) {
            imp_intrman_18(oldstat);
        }
        while (D_06D230[ch] != 0) {
            if (intr_res == 0) {
                imp_thbase_33(100);
            } else {
                for (i = 0xffff; i != -1; i--) {
                }
            }
        }
    }
    return D_06D230[ch];
}
