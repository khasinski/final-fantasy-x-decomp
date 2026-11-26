#include "iopsound.h"

extern s32 D_0193A8;

extern s32 func_00C920(void);
extern s32 func_00B818(s32);

s32 func_012B14(void) {
    return func_00C920();
}

s32 func_012B34(s32 *arg) {
    arg[1] = D_0193A8;
    return 0x96000;
}

s32 func_012B4C(s32 *arg) {
    return func_00B818(arg[0]);
}
