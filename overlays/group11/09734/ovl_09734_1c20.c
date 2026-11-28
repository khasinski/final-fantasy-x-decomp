#include "common.h"

extern void *D_01B006A8;
extern u8 D_01B00758[];
extern float D_01B00798;
extern float D_01B009D0[4];
extern float D_01B009E0[4];
extern u8 D_01B009F0[];
extern void *D_01B00A3C;
extern u8 D_01B00A40[];
extern u8 D_01B00A70[];
extern s32 D_01B00AA4;
extern u8 D_01B00BB8[];

extern void func_00105050(s32, s32);
extern void *func_00102B98(s32);
extern void func_00110550(void *, s32);
extern void func_00110558(void *, s32);
extern void func_00110810(void *, s32);
extern void func_01B03808(void *, void *, void *);
extern void func_00108910(void *, s32, void *);
extern void func_01B011D8(void *);
extern void func_00110830(void *, void *);
extern void func_01B03858(void *);
extern void func_01B035D0(void *, float);

s32 func_01B01C20(void) {
    D_01B00AA4 = 0;
    if (D_01B006A8 == 0) {
        func_00105050(0x3015, 1);
        D_01B006A8 = func_00102B98(0x3015);
        func_00110550(D_01B006A8, 1);
        func_00110558(D_01B006A8, 1);
        func_00110810(D_01B006A8, 0);
    }
    D_01B009E0[0] = D_01B00798;
    D_01B009E0[1] = D_01B00798;
    D_01B009E0[2] = D_01B00798;
    D_01B009E0[3] = 1.0f;
    D_01B009D0[0] = 0.0f;
    D_01B009D0[1] = 0.0f;
    D_01B009D0[2] = 0.0f;
    D_01B009D0[3] = 0.0f;
    func_01B03808(D_01B00BB8, D_01B00758, D_01B006A8);
    func_00108910(D_01B00A3C, 0x10, D_01B00A70);
    return 1;
}

s32 func_01B01D00(void) {
    u8 unused[0xA0];

    D_01B009E0[0] = D_01B00798;
    D_01B009E0[1] = D_01B00798;
    D_01B009E0[2] = D_01B00798;
    D_01B009E0[3] = 1.0f;
    func_01B011D8(D_01B009F0);
    func_00110830(D_01B006A8, D_01B009F0);
    func_01B03858(D_01B00BB8);
    func_01B035D0(D_01B00A40, 5.0f);
    func_01B035D0(D_01B00A70, 5.0f);
    return D_01B00AA4 == 0;
}
