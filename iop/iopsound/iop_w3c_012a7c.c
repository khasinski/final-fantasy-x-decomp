#include "iopsound.h"

extern s32 D_06D24C;
extern s32 D_06D250;
extern s32 D_06D254;
extern s32 D_06D258;

s32 func_012A7C(s32 *arg) {
    D_06D250 = arg[0];
    D_06D254 = arg[1];
    D_06D258 = arg[2];
    imp_thsemap_7(D_06D24C);
    return 0;
}
