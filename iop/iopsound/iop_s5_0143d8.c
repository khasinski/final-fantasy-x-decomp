#include "iopsound.h"

extern s32 D_019318;
extern s32 D_018700;
extern s8 D_122570;
extern s8 D_122470;
extern s32 D_06D2E0[];

extern s32 func_00F714(void *, s32, s32, s32);

void func_0143D8(void) {
    while (1) {
        s32 ret;
        imp_thsemap_8(D_019318);
        do {
            if (D_018700 == 0 && D_122570 == 0 && D_122470 == 0) {
                ret = func_00F714(D_06D2E0, D_06D2E0[64], D_06D2E0[66], D_06D2E0[67]);
            } else {
                ret = func_00F714(D_06D2E0, D_06D2E0[64], D_06D2E0[66], D_06D2E0[67]);
                if (ret != 0) {
                    D_06D2E0[1] = 0;
                    D_06D2E0[0] = D_06D2E0[65];
                }
            }
        } while (ret != 0);
    }
}
