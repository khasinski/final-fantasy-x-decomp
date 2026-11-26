#include "iopsound.h"

extern s32 D_06D240;
extern s32 D_06D244;
extern s32 D_06D248;

s32 func_012580(s32 *arg) {
    D_06D244 = arg[0];
    D_06D248 = arg[1];
    imp_thsemap_7(D_06D240);
    return 0;
}
