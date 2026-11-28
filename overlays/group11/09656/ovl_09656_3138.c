#include "common.h"
#include "vu0.h"

extern u8 *D_01B0A988;
extern u8 D_01B0A860[];

extern u8 *func_01B09EB8(void);
extern void **func_01B06678(void *, s32);
extern void func_01B074B0(void *, void *);
extern void func_002DD128(float (*)[4]);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern void func_002DD318(float (*)[4], float (*)[4], float);
extern void func_002DCE08(float *, float (*)[4], float *);

void func_01B03138(void) {
    float mat[4][4];
    float v1[4];
    float v2[4];
    u8 *s4 = D_01B0A988 + 0x2B40;
    s32 i;

    v2[0] = 0.0f;
    v2[1] = 0.0f;
    v2[3] = 1.0f;
    for (i = 0; i < 3; i++) {
        u8 *p = func_01B09EB8();
        if (p == 0) {
            break;
        }
        func_01B074B0(p + 0x30, *func_01B06678(D_01B0A860, 5));
        func_002DD128(mat);
        func_002DD318(mat, mat, func_002B3DB0(3.1415927f));
        v2[2] = func_002B3DB0(100.0f);
        func_002DCE08(v1, mat, v2);

        VU0_LQC2(1, 0, s4);
        VU0_LQC2(2, 0, v1);
        VU0_OP("vadd.xyz $vf1, $vf1, $vf2");
        VU0_SQC2(1, 0, p);

        *(float *)(p + 0x04) += func_002B3DB0(30.0f) + 10.0f;
        *(float *)(p + 0x10) = func_002B3DB0(0.1f);
        *(float *)(p + 0x14) = -func_002B3DF8(0.1f);
        *(float *)(p + 0x18) = func_002B3DB0(0.1f);
        *(float *)(p + 0x1C) = func_002B3DB0(3.1415927f);
        *(s32 *)(p + 0x20) = 0;
        *(float *)(p + 0x24) = *(float *)(p + 0x14) * -0.01f;
        *(s32 *)(p + 0x28) = 0;
        *(float *)(p + 0x2C) = 1.0f;
        {
            float sc = (func_002B3DB0(0.2f) + 1.0f) * 0.1f;
            *(s32 *)(p + 0x50) = 0x10;
            *(s32 *)(p + 0x54) = -0x10;
            *(s32 *)(p + 0x40) = 0;
            *(s32 *)(p + 0x58) = 0x20;
            *(float *)(p + 0x3C) = sc;
            *(s32 *)(p + 0x5C) = 0;
            *(s32 *)(p + 0x4C) = 0x20;
            p[0x6B] = 0;
        }
    }
}
