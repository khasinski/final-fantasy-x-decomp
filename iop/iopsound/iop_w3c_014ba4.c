#include "iopsound.h"

extern s32 D_019348;
extern s32 D_018700;
extern s8 *D_018758;
extern s32 D_019384;
extern u8 *D_018754;
extern s32 D_019354;
extern volatile s32 D_018710;
extern volatile s32 D_018718;
extern s32 D_06D2E0[];

extern s32 func_00F714(void *, s32, s32, s32);
extern void func_00F038(s32);

void func_014BA4(void) {
    s32 ret;

    while (1) {
        imp_thsemap_8(D_019348);
        do {
            if (D_018700 == 0 && *D_018758 == 0) {
                ret = func_00F714(D_06D2E0, D_019384, 0, 0x8000);
            } else {
                ret = func_00F714(D_06D2E0, D_019384, *(s32 *)(D_018754 + 220), 0x8000);
                if (ret == 0) {
                    break;
                }
                if (D_018700 != 0) {
                    imp_sysclib_23(D_06D2E0, D_018758);
                } else {
                    *D_018758 = 0;
                    D_06D2E0[1] = 0;
                    D_06D2E0[0] = D_019354;
                }
            }
        } while (ret != 0);
        D_018710 = 0;
        D_018718++;
        func_00F038(20);
    }
}
