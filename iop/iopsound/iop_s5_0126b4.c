#include "iopsound.h"

typedef struct {
    s32 a;
    s32 b;
} S_019300;

extern S_019300 D_019300;
extern s32 D_122400[];

extern void func_00E9A0(s32);
extern s32 func_00EE2C(void);
extern void func_00EECC(s32);
extern void func_00EF44(s32, s32);

s32 func_0126B4(s32 *arg) {
    func_00E9A0(arg[0]);
    if (arg[0] == 0) {
        D_122400[0] = 0;
        D_019300.a = D_019300.b = 0;
    }
    return 0;
}

s32 func_01270C(void) {
    return func_00EE2C();
}

s32 func_01272C(s32 *arg) {
    func_00EECC(arg[0]);
    return arg[0];
}

s32 func_01275C(s32 *arg) {
    if (arg[0] != 0) {
        func_00EF44(arg[0], arg[1]);
    } else {
        func_00EECC(arg[1]);
    }
    return arg[0];
}
