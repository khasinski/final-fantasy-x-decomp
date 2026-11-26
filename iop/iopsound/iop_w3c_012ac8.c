#include "iopsound.h"

extern s32 D_06D25C;
extern s32 D_06D260;
extern s32 D_06D264;
extern s32 D_06D268;

s32 func_012AC8(s32 *arg) {
    D_06D260 = arg[0];
    D_06D264 = arg[1];
    D_06D268 = arg[2];
    imp_thsemap_7(D_06D25C);
    return 0;
}
