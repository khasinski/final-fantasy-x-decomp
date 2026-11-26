#include "iopsound.h"

extern void func_00E260(s32);
extern void func_00E2A8(s32, s32);
extern void func_00E308(s32);
extern void func_00E344(s32, s32);

s32 func_0125C0(s32 *arg) {
    func_00E260(arg[0]);
    return 0;
}

s32 func_0125E4(s32 *arg) {
    if (arg[0] != 0) {
        func_00E2A8(arg[0], arg[1]);
    } else {
        func_00E260(arg[1]);
    }
    return 0;
}

s32 func_01262C(s32 *arg) {
    func_00E308(arg[0]);
    return 0;
}

s32 func_012650(s32 *arg) {
    if (arg[0] != 0) {
        func_00E344(arg[0], arg[1]);
    } else {
        func_00E308(arg[1]);
    }
    return 0;
}
