#include "common.h"

extern u8 *D_01B093A8;
extern s32 D_01B007C0[];

extern void func_01B04598(s32, void *);
extern void func_01B04448(s32, s32);
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

void func_01B02460(void) {
    float mat[4][4];
    float v0[4];
    float v1[4];
    u8 *p = D_01B093A8 + 0x1F00;
    s32 i;

    v0[0] = 0.0f;
    v0[1] = 0.0f;
    v0[3] = 0.0f;

    for (i = 0; i < D_01B007C0[1]; i++, p += 0xB0) {
        float ratio;
        float r;

        if (*(s32 *)(p + 0xA8) > 0) {
            *(s32 *)(p + 0xA8) -= 1;
            continue;
        }
        if (*(s32 *)(p + 0xA4) <= 0) {
            continue;
        }
        ratio = (float)(*(s32 *)(p + 0xA4)) / 500.0f;
        r = *(float *)(p + 0xA0) * (1.0f - ratio) + *(float *)(p + 0x9C) * ratio;
        *(s32 *)(p + 0xA4) -= 1;

        *(float *)(p + 0x44) += *(float *)(p + 0x54);
        *(float *)(p + 0x74) += *(float *)(p + 0x44);
        *(float *)(p + 0x94) += *(float *)(p + 0x98);
        if (*(float *)(p + 0x94) < -0.12566371f) {
            *(float *)(p + 0x94) = -0.12566371f;
        }

        add_angle((float *)(p + 0x90), *(float *)(p + 0x94));

        if (*(s32 *)(p + 0xA4) == 0) {
            func_01B04598(i, 0);
            func_01B04448(i, 1);
        }

        add_angle((float *)(p + 0x60), 0.31415927f);
        add_angle((float *)(p + 0x64), -0.31415927f);

        v0[2] = -r;
        func_002DD128(mat);
        func_002DD318(mat, mat, *(float *)(p + 0x90));
        func_002DCE08(v1, mat, v0);
        func_01B04B18(i, p, p + 0x60);
        func_002DD998(p, p, *(float *)(p + 0x80));
        func_002DD998(p + 0x10, p + 0x10, *(float *)(p + 0x84));
        func_002DD998(p + 0x20, p + 0x20, *(float *)(p + 0x88));
        *(float *)(p + 0x30) = *(float *)(p + 0x70);
        *(float *)(p + 0x34) = *(float *)(p + 0x74);
        *(float *)(p + 0x38) = *(float *)(p + 0x78);
    }
}
