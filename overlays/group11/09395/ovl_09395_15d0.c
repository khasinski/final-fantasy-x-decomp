#include "common.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(8))) Vec15D0;

extern Vec15D0 D_01B05980;
extern float D_01B0095C;
extern float D_01B00960;

extern void func_002DD038(void *, void *, void *);
extern void func_002DD998(void *, void *, float);
extern void func_002DD020(void *, void *, void *);
extern void func_002DCE80(void *, void *, void *);
extern void func_002DCEC8(void *, void *);
extern s32 func_002EFD78(void);

void func_01B015D0(float *s5, float *a1, float *s0, s32 s3) {
    float diff[4];
    float tmp[4];
    Vec15D0 up;
    float side[4];
    float t;
    float step;
    s32 i;

    up = D_01B05980;
    t = 0.0f;
    func_002DD038(diff, a1, s5);
    step = 1.0f / (float)(s3 - 1);
    for (i = 0; i < s3; i++, s0 += 4) {
        func_002DD998(tmp, diff, t);
        t += step;
        func_002DD020(s0, s5, tmp);
        if (i != 0 && i != s3 - 1) {
            func_002DCE80(side, &up, diff);
            func_002DCEC8(side, side);
            func_002DD998(tmp, side, D_01B0095C * (((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f));
            func_002DD020(s0, s0, tmp);
            s0[1] += D_01B00960 * (((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f);
        }
    }
}
