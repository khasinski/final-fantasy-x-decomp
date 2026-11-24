#include "common.h"

typedef struct {
    s32 w00;
} RingObj;

extern s32 D_01B006A8;
extern void *D_01B006B0;
extern void *D_01B006B4;
extern void *D_01B006B8;
extern s32 D_01B006C0;
extern u8 D_01B006D0;
extern void *D_01B00DA4;
extern float D_01B00DC0[10][4];
extern s32 D_01B00E60;
extern RingObj D_01B00E68;
extern RingObj D_01B00F78;
extern RingObj D_01B01088;
extern RingObj D_01B01198;
extern RingObj D_01B012A8;
extern u8 D_01B03908[];
extern u8 D_01B03918[];
extern u8 D_01B03928[];
extern u8 D_01B03938[];
extern u8 D_01B03948[];
extern u8 D_01B03958[];

extern void *D_006A3924;
extern u8 D_006A3970;
extern u8 D_006A3A70;
extern void *D_006A3BCC;

extern void func_001AACA0(void *);
extern void func_001A9EE0(void *);
extern s32 func_0014AA50(s32);
extern void func_00107428(void *, s32, s32, float *);
extern void MsEffectTerminate(s32);
extern int func_01B02BC0(void *, ...);
extern int func_01B02C18(void *, ...);
extern void func_01B02C58(s32, s32);
extern void func_01B03590(void *);
extern void func_01B036E8(void *);

int func_01B02820(void)
{
    s32 i;

    if (D_01B006A8 == 0) {
        return 0;
    }

    D_006A3924 = &D_01B006D0;
    func_001AACA0(&D_006A3A70);
    func_001A9EE0(&D_006A3970);
    D_006A3BCC = D_01B006B0;
    D_01B006B8 = D_01B006B4;

    if (func_0014AA50(0) != 0) {
        func_01B02C58(0x20, 0x1A);
        func_01B02C18(D_01B03908, D_01B00E68.w00);
        func_01B03590(&D_01B00E68);
    }

    if (func_0014AA50(1) != 0) {
        func_01B02C58(0x20, 0x1B);
        func_01B02C18(D_01B03918, D_01B00F78.w00);
        if (D_01B00F78.w00 == 0) {
            for (i = 0; i < 10; i++) {
                func_00107428(D_01B00DA4, 0, 0, D_01B00DC0[i]);
            }
        }
        if (D_01B00F78.w00 < 0xAA) {
            s32 j;
            for (j = 8; j >= 0; j--) {
                D_01B00DC0[j + 1][0] = D_01B00DC0[j][0];
                D_01B00DC0[j + 1][1] = D_01B00DC0[j][1];
                D_01B00DC0[j + 1][2] = D_01B00DC0[j][2];
            }
            func_00107428(D_01B00DA4, 0, 0, D_01B00DC0[0]);
            func_01B03590(&D_01B00F78);
        }
    }

    if (func_0014AA50(2) != 0) {
        func_01B02C58(0x20, 0x1C);
        func_01B02C18(D_01B03928, D_01B01088.w00);
        func_01B03590(&D_01B01088);
    }

    if (func_0014AA50(3) != 0) {
        func_01B02C58(0x20, 0x1D);
        func_01B02C18(D_01B03938, D_01B01198.w00);
        func_01B03590(&D_01B01198);
    }

    if (func_0014AA50(4) != 0) {
        func_01B02C58(0x20, 0x1E);
        func_01B02C18(D_01B03948, D_01B012A8.w00);
        func_01B03590(&D_01B012A8);
    }

    if (func_0014AA50(5) != 0) {
        func_01B036E8(&D_01B00E68);
        func_01B036E8(&D_01B00F78);
        func_01B036E8(&D_01B01088);
        func_01B036E8(&D_01B01198);
        func_01B036E8(&D_01B012A8);
        func_01B02BC0(D_01B03958, D_01B00E60);
        MsEffectTerminate(D_01B006C0);
        return 1;
    } else {
        D_01B00E60++;
    }

    return 1;
}
