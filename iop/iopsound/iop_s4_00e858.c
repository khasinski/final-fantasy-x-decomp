#include "iopsound.h"

extern void func_00EFBC(s32, s32);
extern s32 func_00FD60(s32, s32, void *, s32, s32);
extern void func_00FDF4(s32, void *, s32);

extern volatile s32 D_018F80;
extern volatile s32 D_018F84;
extern u32 D_018F94;
extern s32 D_06D2A0;

void func_00E858(void) {
    s32 st;

    st = imp_libsd_20(((D_018F94 >> 1) ^ 1) & 1, 0);
    func_00EFBC(4, D_018F80);
    func_00EFBC(8, D_06D2A0 >> 12);
    func_00EFBC(9, st);
}

s32 func_00E8C4(void) {
    D_018F84--;
    if (D_018F84 == 0) {
        func_00FD60(0, 2, NULL, 0, 0);
        func_00FDF4(0, NULL, 0);
    }
    return D_018F84;
}

s32 func_00E930(void) {
    s32 st;

    st = imp_libsd_20(((D_018F94 >> 1) ^ 1) & 1, 0);
    D_018F80 &= ~1;
    D_018F80 |= st >> 24;
    func_00E858();
    return D_018F80;
}
