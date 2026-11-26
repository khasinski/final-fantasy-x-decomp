#include "iopsound.h"

extern s32 D_122400[];
extern s32 D_122408;
extern s32 D_019368;

s32 func_0129B4(s32 *arg) {
    if (arg[0] == 0) {
        D_122400[0] = D_122400[1] = 0;
    }
    D_122408 = arg[1];
    imp_thsemap_6(D_019368);
    return 0;
}
