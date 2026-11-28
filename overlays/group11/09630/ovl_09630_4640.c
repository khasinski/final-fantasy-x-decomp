#include "common.h"
#include "vu0.h"

extern u8 D_01B0BF48[];
extern u8 *D_01B0C0B0;

extern s32 func_01B076C8(void *, void *, s32, s32, s32, s32, float);
extern void func_01B06598(s32, void *, void *);
extern void func_01B06018(s32, void *);
extern void func_01B05E98(s32, s32);
extern void func_01B0AD78(void *, s32);
extern void func_01B0BAA0(void *, s32);
extern void func_00118098(s32, s32);

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

void func_01B04640(void) {
    u8 *s3 = D_01B0C0B0;
    u8 *s2;
    u8 *v0;
    float ang1;
    float ang2;

    s2 = s3 + 0x4C0;
    func_01B076C8(D_01B0BF48, s2, 0, 0, 0, 0, 0.0007f);
    copy_vec(s3 + 0x590, s3 + 0x980);
    *(float *)(s2 + 0xC4) = *(float *)(s3 + 0x85C8);
    *(float *)(s2 + 0xD4) -= 15.0f;

    s2 = s3 + 0x5F0;
    func_01B076C8(D_01B0BF48, s2, 0, 0, 0, 0, 0.000525f);
    copy_vec(s3 + 0x6C0, s3 + 0x980);
    ang1 = *(float *)(s3 + 0x85C8) + 0.7853982f;
    if (ang1 > 3.1415927f) {
        ang1 -= 6.2831855f;
    } else if (ang1 < -3.1415927f) {
        ang1 += 6.2831855f;
    }
    *(float *)(s2 + 0xC4) = ang1;
    *(float *)(s2 + 0xC8) = 0.7853982f;
    *(float *)(s2 + 0xE0) = 15.0f;
    *(float *)(s2 + 0xD4) -= 15.0f;

    s2 += 0x130;
    func_01B076C8(D_01B0BF48, s2, 0, 0, 0, 0, 0.00035f);
    MMI_COPY_LQ_A3(s2 + 0xD0, s3 + 0x980);
    MMI_COPY_SQ_A3(s2 + 0xD0);
    ang2 = *(float *)(s3 + 0x85C8) + -0.7853982f;
    if (ang2 > 3.1415927f) {
        ang2 -= 6.2831855f;
    } else if (ang2 < -3.1415927f) {
        ang2 += 6.2831855f;
    }
    *(float *)(s2 + 0xC4) = ang2;
    *(float *)(s2 + 0xC8) = -0.7853982f;
    *(float *)(s2 + 0xD4) -= 15.0f;
    *(float *)(s2 + 0xE0) = -15.0f;

    if (*(s32 *)(s3 + 0x85E8) == 1) {
        func_01B06598(-1, s3 + 0x850, s3 + 0x910);
        MMI_COPY_LQ_A3(s3 + 0x920, s3 + 0x990);
        MMI_COPY_SQ_A3(s3 + 0x920);
    }

    func_01B06018(2, s3 + 0x8D0);
    MMI_COPY_LQ_A3(s3 + 0x950, s3 + 0x910);
    MMI_COPY_SQ_A3(s3 + 0x950);
    MMI_COPY_LQ_A3(s3 + 0x960, s3 + 0x920);
    MMI_COPY_SQ_A3(s3 + 0x960);
    func_01B06598(2, s3 + 0x8D0, s3 + 0x950);
    MMI_COPY_LQ_A3(s3 + 0x900, s3 + 0x960);
    MMI_COPY_SQ_A3(s3 + 0x900);
    func_01B05E98(2, 1);

    {
        register u8 *v0 __asm__("$2") = s3 + 0x81F0;
        v0[0x82] = 0x80;
        v0[0x81] = 0x80;
        v0[0x80] = 0x80;
        v0[0x83] = 0x80;
        v0[0x84] = 0x80;
        v0[0x85] = 0x80;
        v0[0x86] = 0x80;
        v0[0x87] = 0;
        *(s32 *)(v0 + 0x88) = 0;
        v0[0x98] = 0x48;
        v0[0x99] = 0;
        func_01B0AD78(v0, 0x18);
    }

    {
        register float f0 __asm__("$f0") = 0.05f;
        u8 *v0 = s3 + 0x8480;
        register u16 a1 __asm__("$5") = 4;
        register u8 v1 __asm__("$3") = 0x30;
        *(u16 *)(v0 + 0x124) = a1;
        v0[0xF0] = 0x80;
        v0[0xF1] = 0x80;
        v0[0xF2] = 0x80;
        v0[0xF3] = v1;
        *(float *)(v0 + 0xFC) = f0;
        *(s32 *)(v0 + 0x120) = 0;
        *(s32 *)(v0 + 0x110) = 0;
        *(s32 *)(v0 + 0xF8) = 0;
        *(s32 *)(v0 + 0x100) = 0;
        func_01B0BAA0(v0, 0x32);
    }

    func_00118098(0, 0);
    func_00118098(1, 0);
}
