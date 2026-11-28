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
extern void func_01B03270(void *);
extern s32 func_001AF358(void);
extern float func_01B03078(s32);
extern void func_01B06278(void *, float *, void *);

void func_01B01450(void) {
    float v0[4];
    float v1[4];
    float v2[4];
    u8 *s = D_01B09358;
    float d;
    s32 n;

    if (*(s32 *)(s + 0x54C4) == -1) {
        v1[1] = -80.0f;
    } else {
        v1[1] = -30.0f;
    }

    func_01B02C28(*(s32 *)(s + 0x54A4), v0, 0);
    v2[0] = 0.0f;
    v2[1] = *(float *)(s + 0x54A0);
    v2[2] = 0.0f;
    v2[3] = 0.0f;
    v1[0] = 0.0f;
    v1[2] = func_01B02F98(*(s32 *)(s + 0x54A4)) + 50.0f;
    v1[3] = 1.0f;
    v0[1] = *(float *)(s + 0xF74);
    func_01B06380(v2, v0, v1);

    copy_vec(s + 0xFA0, v0);
    *(float *)(s + 0xFB4) = *(float *)(s + 0x54A0);
    d = func_01B06420(s + 0xF90, v0);
    n = (s32)(d * 0.5f);
    if (n < 35) {
        n = 35;
    }
    *(s32 *)(s + 0x54B4) = n;
    *(s32 *)(s + 0x54B8) = n;
    func_01B03270(s + 0xFC0);
    if (func_001AF358() == 0x018B0046) {
        *(float *)(s + 0xFC4) = *(float *)(s + 0xF74);
    } else {
        *(float *)(s + 0xFC4) = func_01B03078(0);
    }
    func_01B06278(s + 0xFB0, v0, s + 0xFC0);
}
