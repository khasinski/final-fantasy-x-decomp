#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

extern u8 *D_01B09358;

extern float func_01B060C0(float, float, float, float, float, float);
extern float func_01B06550(float, float);
extern void func_01B04418(s32, void *, void *);
extern void func_01B01998(void);

void func_01B01A50(u8 *a0) {
    u8 *s = D_01B09358;
    s32 rem;
    float t;
    float *p0;
    float *p1;
    float *dst;
    float ang;
    s32 i;

    if (*(s32 *)(s + 0x54B4) > 0) {
        *(s32 *)(s + 0x54B4) -= 1;
    }

    t = (float)*(s32 *)(s + 0x54B4) / (float)*(s32 *)(s + 0x54B8);
    p1 = (float *)(s + 0xFA0);
    dst = (float *)(s + 0xF60);
    p0 = (float *)(s + 0xF90);
    for (i = 0; i < 3; i++) {
        float diff = p1[i] - p0[i];
        dst[i] = p0[i] + func_01B060C0(diff, diff * 1.01f, diff * 1.5f, diff, 0.0f, t);
    }

    ang = func_01B06550(*(float *)(s + 0xF54), *(float *)(s + 0xFB4)) * (1.0f - t) + *(float *)(s + 0xF54) * t;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    *(float *)(s + 0xF54) = ang;

    func_01B04418(-1, s + 0xD10, s + 0xF50);

    if (*(s32 *)(s + 0x54B4) == 10) {
        func_01B01998();
    }
    if (*(s32 *)(s + 0x54B4) <= 0) {
        copy_vec(dst, p1);
        a0[0x56] = 1;
    }
}
