#include "common.h"

extern u32 D_01B00850[];
extern u8 D_01B00C58[];
extern u8 D_01B01300[];
extern u8 D_01B0F750[];
extern void *D_01B0F77C;

extern void func_01B0D508(void *);
extern void func_01B0D400(void *);
extern void func_01B0D3B0(void *);
extern void func_01B04FF8(void *);
extern s32 func_001ACEA0(void);
extern void func_001C69C8(void *, u32, s32);
extern void func_01B0A210(void *);
extern void func_01B0A118(void *);
extern void func_01B0A690(void *);
extern void func_01B0A5E8(void *);
extern void func_01B0B348(void *);
extern void func_01B0B2A0(void *);
extern void func_01B0E408(void *);

typedef struct {
    void *f0;
    u8 *f4;
} Arg29E8;

typedef struct {
    void *f0;
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    s32 f18;
} Param4FF8;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    void *f10;
    void *f14;
} Param6;

void func_01B029E8(Arg29E8 *arg) {
    union {
        Param6 p6;
        Param4FF8 p7;
    } u;
    void *sp20;
    void *sp24;
    void *sp28;
    void *sp2C;
    void *sp30;
    void *sp34;
    void *sp38;
    void *sp3C;
    void *sp40;
    void *sp44;
    void *sp48;
    void *sp4C;
    void *sp50;
    void *sp54;
    void *sp58;
    u8 *s = arg->f4;
    s32 st;

loop:
    st = *(s32 *)(s + 0x4AC);
    if (st == 0) {
        goto case_0;
    }
    if (st == 10000) {
        goto case_10000;
    }
    goto done;
case_0:
    *(float *)(s + 0x44) += *(float *)(s + 0x494);
    *(float *)(s + 0x494) += 0.2f;
    if (*(float *)(s + 0x44) >= 0.0f) {
        s32 i;
        s32 rnd;
        float f;
        *(s32 *)(s + 0xD8) = 0;
        *(float *)(s + 0x44) = 0.1f;

        sp20 = s + 0x380;
        func_01B0D508(&sp20);
        sp24 = s + 0x380;
        func_01B0D400(&sp24);

        u.p6.f0 = s + 0x380;
        u.p6.f4 = D_01B00C58;
        u.p6.f8 = s + 0xE0;
        u.p6.fC = D_01B0F77C;
        u.p6.f10 = D_01B0F750;
        u.p6.f14 = (void *)3;
        func_01B0D3B0(&u.p6);

        f = *(float *)(s + 0x488);
        u.p7.f0 = D_01B01300;
        u.p7.f4 = 1.0f;
        u.p7.f8 = f * 4.0f + 2.0f;
        u.p7.fC = 0.2f;
        u.p7.f10 = f * 8.0f + 4.0f;
        u.p7.f14 = 30.0f;
        u.p7.f18 = 0;
        func_01B04FF8(&u.p7);

        rnd = func_001ACEA0();
        for (i = 0; i < *(s32 *)(s + 0x4A8); i++) {
            if ((rnd >> i) & 1) {
                u8 *tgt = ((u8 **)*(u32 *)(s + 0x480))[i];
                s32 r2 = func_001ACEA0();
                func_001C69C8(*(void **)(tgt + 0x54), D_01B00850[r2 & 1], 1);
            }
        }
        *(s32 *)(s + 0x4AC) = 10000;
        goto loop;
    }
    goto done;
case_10000:
    if (*(u32 *)(s + 0x468) & 4) {
        sp28 = s + 0x20;
        func_01B0A210(&sp28);
        sp2C = s + 0x20;
        func_01B0A118(&sp2C);

        sp30 = s + 0x50;
        func_01B0A210(&sp30);
        sp34 = s + 0x50;
        func_01B0A118(&sp34);

        sp38 = s + 0xB0;
        func_01B0A690(&sp38);
        sp3C = s + 0xB0;
        func_01B0A5E8(&sp3C);

        sp40 = s + 0x80;
        func_01B0A210(&sp40);
        sp44 = s + 0x80;
        func_01B0A118(&sp44);

        sp48 = s + 0xE0;
        func_01B0B348(&sp48);
        sp4C = s + 0xE0;
        func_01B0B2A0(&sp4C);

        sp50 = s + 0x230;
        func_01B0B348(&sp50);
        sp54 = s + 0x230;
        func_01B0B2A0(&sp54);

        *(s32 *)(s + 0x4AC) = 20000;
        sp58 = arg->f0;
        func_01B0E408(&sp58);
    }
done:
    *(s32 *)(s + 0x4A0) += 1;
}
