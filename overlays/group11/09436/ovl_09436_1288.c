#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

extern u8 *D_01B09358;

extern void func_01B02C28(s32, float *, s32);
extern float func_01B02F98(s32);
extern void func_01B06380(float *, float *, float *);
extern float func_01B06420(void *, float *);

void func_01B01288(void) {
    float v0[4];
    float v1[4];
    float v2[4];
    u8 *s = D_01B09358;
    float d;
    s32 n;

    func_01B02C28(*(s32 *)(s + 0x54A4), v0, 0);
    v2[0] = 0.0f;
    v2[1] = *(float *)(s + 0x54A0);
    v2[2] = 0.0f;
    v2[3] = 0.0f;
    v1[0] = 0.0f;
    v1[1] = 0.0f;
    v1[2] = func_01B02F98(*(s32 *)(s + 0x54A4)) + 20.0f;
    v1[3] = 1.0f;
    func_01B06380(v2, v0, v1);

    v0[1] = *(float *)(s + 0xF74);
    d = func_01B06420(s + 0xF70, v0);
    copy_vec(s + 0xF80, v0);

    n = (s32)(d / 3.0f);
    *(s32 *)(s + 0x54A8) = n;
    if (n < 9) {
        *(s32 *)(s + 0x54A8) = 9;
    }
    *(s32 *)(s + 0x54AC) = *(s32 *)(s + 0x54A8);
}
