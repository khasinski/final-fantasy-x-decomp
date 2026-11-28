#include "common.h"
#include "vu0.h"

extern u8 *D_01B093A8;
extern s32 D_01B007C0[];

extern s32 func_0011ABB8(void);
extern float func_002B3DF8(float);
extern float func_002B3DB0(float);
extern void func_002DD128(float (*)[4]);
extern void func_002DD318(float (*)[4], float (*)[4], float);
extern void func_002DCE08(float *, float (*)[4], float *);
extern void func_01B04B18(s32, void *, void *);
extern void func_002DD998(void *, void *, float);

static inline void add_angle(float *dst, float delta) {
    float a = *dst + delta;
    if (a > 3.1415927f) {
        a -= 6.2831855f;
    } else if (a < -3.1415927f) {
        a += 6.2831855f;
    }
    *dst = a;
}

void func_01B01F40(void) {
    float mat[4][4];
    float v0[4];
    float v1[4];
    u8 *base;
    u8 *p;
    s32 i;

    if (func_0011ABB8() != 0) {
        return;
    }

    base = D_01B093A8;
    p = base + 0x1F00;
    v0[0] = 0.0f;
    v0[1] = 0.0f;
    v0[3] = 0.0f;

    i = 0;
    if (D_01B007C0[1] > 0) {
        u8 *p1900 = base + 0x1900;
        do {
            float r;

        if (*(s32 *)(p + 0xA8) > 0) {
            *(s32 *)(p + 0xA8) -= 1;
            goto next;
        }
        if (*(s32 *)(p + 0xA4) > 0) {
            float ratio = (float)(*(s32 *)(p + 0xA4)) / 500.0f;
            r = *(float *)(p + 0xA0) * (1.0f - ratio) + *(float *)(p + 0x9C) * ratio;
            *(s32 *)(p + 0xA4) -= 1;

            *(float *)(p + 0x44) += *(float *)(p + 0x54);
            *(float *)(p + 0x74) += *(float *)(p + 0x44);
            *(float *)(p + 0x94) += *(float *)(p + 0x98);
            if (*(float *)(p + 0x94) < -0.12566371f) {
                *(float *)(p + 0x94) = -0.12566371f;
            }
            add_angle((float *)(p + 0x90), *(float *)(p + 0x94));
        } else {
            r = *(float *)(p + 0xA0);
        }

        add_angle((float *)(p + 0x60), func_002B3DF8(0.015707964f) + 0.015707964f);
        add_angle((float *)(p + 0x64), -(func_002B3DB0(0.015707964f) + 0.09424778f));

        v0[2] = -r;
        func_002DD128(mat);
        func_002DD318(mat, mat, *(float *)(p + 0x90));
        func_002DCE08(v1, mat, v0);
        func_01B04B18(i, p, p + 0x60);
        func_002DD998(p, p, *(float *)(p + 0x80));
        func_002DD998(p + 0x10, p + 0x10, *(float *)(p + 0x84));
        func_002DD998(p + 0x20, p + 0x20, *(float *)(p + 0x88));

        {
            u8 *dst = p + 0x30;
            VU0_LQC2(1, 0, p1900);
            VU0_LQC2(2, 0, v1);
            VU0_OP("vadd.xyz $vf1, $vf1, $vf2");
            VU0_SQC2(1, 0, dst);
        }
        *(float *)(p + 0x34) = *(float *)(p + 0x74);
        next:
            p += 0xB0;
            i++;
        } while (i < D_01B007C0[1]);
    }
}
