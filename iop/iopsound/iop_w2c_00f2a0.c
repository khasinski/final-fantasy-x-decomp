#include "iopsound.h"

extern volatile s32 D_05A11C;
extern volatile s32 D_0193AC;

extern s32 func_00F188(void);

void func_00F2A0(void) {
    D_05A11C = 0;
    do {
        D_0193AC = imp_timrman_4(1, 32, 1);
    } while (D_0193AC <= 0);
    while (imp_timrman_20(D_0193AC, 0x25800, func_00F188, 0) != 0) {
    }
    while (imp_timrman_22(D_0193AC, 1, 0, 1) != 0) {
    }
    while (imp_timrman_23(D_0193AC) != 0) {
    }
}
