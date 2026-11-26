#include "iopsound.h"

extern s32 D_018F80;
extern volatile s32 D_018F84;
extern s32 D_018F90;
extern s32 D_018F94;
extern s32 D_019300[2];
extern s32 D_01934C;
extern s32 D_019350;
extern u8 D_017700[];
extern u8 D_06D3F0[];

extern void func_00FDF4(s32, void *, s32);
extern s32 func_00FD60(s32, s32, void *, s32, s32);
extern void func_00E8C4(void);
extern void func_00EFBC(s32, s32);
extern void func_00F084(s32);
extern void func_00E858(void);

s32 func_00E9A0(s32 keep) {
    if (D_018F90 != 0) {
        imp_libsd_5(0x0f81, 0);
        imp_libsd_5(0x1081, 0);
        func_00FDF4(0, NULL, 0);
        func_00FDF4(1, NULL, 0);
        D_019300[0] = func_00FD60(0, 2, NULL, 0, 0);
        D_019300[1] = func_00FD60(1, 2, NULL, 0, 0);
        D_019300[0] -= (s32)D_06D3F0 + D_01934C;
        D_019300[1] -= (s32)D_06D3F0;
        D_019300[0] &= ~0x3ff;
        D_019300[1] &= ~0x3ff;
        if (D_019300[0] >= D_01934C * 3) {
            D_019300[0] = 0;
        }
        if (D_019300[1] >= D_01934C) {
            D_019300[1] = 0;
        }
        D_019300[0] += (s32)D_06D3F0 + D_01934C;
        D_019300[1] += (s32)D_06D3F0;
        if (D_018F94 & 2) {
            D_018F84 = 2;
            func_00FDF4(0, (void *)func_00E8C4, 0);
            func_00FD60(0, 16, D_017700, 2048, 0);
            D_018F80 = ((s8 *)D_019300)[3];
        } else {
            D_018F80 = D_019300[1] >> 24;
        }
        func_00EFBC(4, 0);
        D_019350 &= ~12;
    }
    D_018F90 = 0;
    func_00F084(23);
    if (keep == 0) {
        D_018F80 = 0;
    }
    func_00E858();
    return D_019350;
}
