#include "iopsound.h"

extern s32 D_018FC8;
extern u32 D_018704;
extern s32 D_018718;
extern s32 D_06D3F0[2][0x1900];
extern u8 D_017700[];

extern void func_0093C8(void *, s32, s32);
extern void func_00FDF4(s32, void *, s32);
extern void func_00FD60(s32, s32, void *, s32, s32);

s32 func_0127E4(void) {
    D_018FC8--;
    if (D_018FC8 == 0) {
        func_00FDF4(0, NULL, 0);
        func_00FD60(0, 2, NULL, 0, 0);
        imp_libsd_11(10, (D_018704 | 0x0801) & 0xFFFF);
        D_018718++;
    }
    return D_018FC8;
}

s32 func_012874(void) {
    D_018FC8--;
    if (D_018FC8 == 0) {
        func_00FDF4(0, NULL, 0);
        func_00FD60(0, 2, NULL, 0, 0);
        imp_libsd_11(10, (D_018704 | 0x0800) & 0xFFFF);
        D_018718++;
    }
    return D_018FC8;
}

s32 func_012904(s32 *arg) {
    if (arg[0] != 0) {
        D_018FC8 = 54;
        func_0093C8(D_06D3F0, 4096, 1);
        func_00FDF4(0, func_012874, 0);
        func_00FD60(0, 16, D_06D3F0, 4096, 0);
    } else {
        D_018FC8 = 48;
        func_00FDF4(0, func_0127E4, 0);
        func_00FD60(0, 16, D_017700, 4096, 0);
    }
    return 0;
}
