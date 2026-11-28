#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

extern u8 *D_01B0B1F8;
extern u8 D_01B10960[];

extern void func_01B046E0(float *);
extern u8 *func_01B0A788(void);
extern void *func_002B49A0(void *, s32, s32);
extern void func_01B07D80(void *, void *);
extern void func_002DD128(float (*)[4]);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern void func_002DD318(float (*)[4], float (*)[4], float);
extern void func_002DCE08(float *, float (*)[4], float *);

void func_01B037E0(void) {
    float mat[4][4];
    float v0[4];
    float v1[4];
    float v2[4];
    u8 *s4 = D_01B0B1F8;
    s32 i;

    v2[0] = 0.0f;
    v2[1] = 0.0f;
    v2[3] = 1.0f;
    func_01B046E0(v0);
    v0[1] = 0.0f;

    for (i = 0; i < 3; i++) {
        u8 *p = func_01B0A788();
        if (p == 0) {
            break;
        }
        {
            void *tex = func_002B49A0(D_01B10960, 9, 1);
            func_01B07D80(p + 0x30, tex);
        }
        func_002DD128(mat);
        func_002DD318(mat, mat, func_002B3DB0(3.1415927f));
        v2[2] = func_002B3DB0(100.0f) + func_002B3DB0(50.0f);
        func_002DCE08(v1, mat, v2);
        copy_vec(p, v0);
        *(float *)(p + 0x00) += func_002B3DB0(50.0f);
        *(float *)(p + 0x04) = *(float *)(s4 + 0x14B4) - func_002B3DF8(10.0f) + 30.0f - 50.0f;
        *(float *)(p + 0x08) += func_002B3DB0(50.0f);
        *(float *)(p + 0x10) = v1[0] * 0.005f + func_002B3DB0(0.1f);
        *(float *)(p + 0x14) = func_002B3DF8(1.0f);
        *(float *)(p + 0x18) = v1[2] * 0.005f + func_002B3DB0(0.1f);
        *(float *)(p + 0x1C) = func_002B3DB0(3.1415927f);
        *(s32 *)(p + 0x20) = 0;
        *(float *)(p + 0x24) = 0.01f;
        *(s32 *)(p + 0x28) = 0;
        *(float *)(p + 0x2C) = 1.0f;
        *(float *)(p + 0x3C) = (func_002B3DB0(0.2f) + 1.0f) * 0.1f;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x40) = 0;
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x50) = 0;
        *(s32 *)(p + 0x58) = 98;
        *(s32 *)(p + 0x4C) = 98;

        p = func_01B0A788();
        if (p == 0) {
            break;
        }
        {
            void *tex = func_002B49A0(D_01B10960, 9, 0);
            func_01B07D80(p + 0x30, tex);
        }
        func_002DD128(mat);
        func_002DD318(mat, mat, func_002B3DB0(3.1415927f));
        v2[2] = func_002B3DB0(100.0f) + func_002B3DB0(50.0f);
        func_002DCE08(v1, mat, v2);
        copy_vec(p, v0);
        *(float *)(p + 0x00) += func_002B3DB0(50.0f);
        *(float *)(p + 0x04) = *(float *)(s4 + 0x14B4) - func_002B3DF8(10.0f) + 30.0f - 50.0f;
        *(float *)(p + 0x08) += func_002B3DB0(50.0f);
        *(float *)(p + 0x10) = v1[0] * 0.01f + func_002B3DB0(0.3f);
        *(float *)(p + 0x14) = func_002B3DB0(0.15f);
        *(float *)(p + 0x18) = v1[2] * 0.01f + func_002B3DB0(0.3f);
        *(float *)(p + 0x1C) = func_002B3DB0(3.1415927f);
        *(s32 *)(p + 0x20) = 0;
        *(float *)(p + 0x24) = 0.035f;
        *(s32 *)(p + 0x28) = 0;
        *(float *)(p + 0x2C) = 1.0f;
        *(float *)(p + 0x3C) = (func_002B3DB0(0.4f) + 1.0f) * 0.02f;
        *(s32 *)(p + 0x50) = 0;
        *(s32 *)(p + 0x60) = 0;
        {
            register s32 c40 __asm__("$2") = 40;
            register s32 c80 __asm__("$3") = 80;
            *(s32 *)(p + 0x4C) = c80;
            p[0x68] = c40;
            p[0x69] = c40;
            p[0x6A] = c40;
        }
        *(float *)(p + 0x48) = func_002B3DB0(0.62831855f);
    }
}
