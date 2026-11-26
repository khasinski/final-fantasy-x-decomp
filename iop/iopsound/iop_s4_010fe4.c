#include "iopsound.h"

extern void func_00B4A8(s32);
extern void func_00B7C8(void *);

extern u8 *D_018FA8;
extern char D_122470[];
extern char D_122570[];

s32 func_010FE4(s32 *arg) {
    imp_sysclib_23(D_122570, arg);
    return *arg;
}

s32 func_011018(s32 *arg) {
    imp_sysclib_23(D_122470, arg);
    return *arg;
}

s32 func_01104C(s32 *arg) {
    func_00B4A8(*arg);
    return 0;
}

s32 func_011070(u8 *arg) {
    u8 *base = D_018FA8;
    u8 *p = arg + 28;

    if (p >= base + 8448) {
        p = base;
    }
    func_00B7C8(p);
    return 0;
}
