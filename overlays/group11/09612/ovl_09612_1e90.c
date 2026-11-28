#include "common.h"
#include "vu0.h"

#define copy_vec_m(dst, src) do { \
    MMI_COPY_LQ_A3(dst, src); \
    MMI_COPY_SQ_A3(dst); \
} while (0)

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

extern u8 *D_01B0A568;
extern s32 D_01B0A55C;

extern void func_01B03390(s32, float *, s32);
extern float func_01B03268(s32);
extern void func_01B04600(s32, void *);
extern void func_01B04B80(s32, void *, void *);
extern void func_01B040F8(s32, s32);
extern void func_01B04058(s32, s32);
extern void func_01B06AE8(void *, void *, void *);

void func_01B01E90(void) {
    float v0[4];
    float v1[4];
    float v2[4];
    register u8 *s __asm__("$17") = D_01B0A568;
    register float *v1_p __asm__("$18");

    func_01B03390(-1, v0, 0);
    copy_vec(s + 0x1510, v0);
    v1[0] = 0.0f;
    v1[1] = func_01B03268(-1);
    {
        u8 *p14f0 = s + 0x14F0;
        v1[2] = 0.0f;
        v1_p = v1;
        copy_vec_m(p14f0, v1_p);
    }
    copy_vec(s + 0x1500, v0);
    func_01B04600(-1, s + 0x14B0);
    func_01B04B80(-1, s + 0x14B0, v1_p);
    copy_vec(s + 0x14E0, s + 0x1500);
    func_01B040F8(-1, 1);
    func_01B04058(-1, 0);

    *(float *)(s + 0x1800) = v1[1];
    copy_vec(s + 0x1520, v0);
    v2[0] = 0.0f;
    v2[1] = 0.0f;
    v2[2] = -5.0f;
    func_01B06AE8(v1_p, s + 0x1520, v2);
    *(s32 *)(s + 0x180C) = 0;
    D_01B0A55C = 1;
}
