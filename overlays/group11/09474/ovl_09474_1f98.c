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

extern u8 *D_01B0A480;
extern s32 D_01B0A414;
extern s32 D_01B0A434;
extern s32 D_01B0A454;
extern s32 D_01B0A474;

extern void func_01B037B0(s32, float *, s32);
extern float func_01B03688(s32);
extern void func_01B04A20(s32, void *);
extern void func_01B04FA0(s32, void *, void *);
extern void func_01B04518(s32, s32);
extern void func_01B04478(s32, s32);
extern void func_0029A878(void);

void func_01B01F98(void) {
    float v0[4];
    float v1[4];
    register u8 *s __asm__("$17") = D_01B0A480;
    register float *v1_p __asm__("$18");

    func_01B037B0(0, v0, 0);
    copy_vec(s + 0xCD0, v0);
    v1[0] = 0.0f;
    v1[1] = func_01B03688(0);
    {
        register u8 *pc50 __asm__("$2") = s + 0xC50;
        v1[2] = 0.0f;
        v1[3] = 0.0f;
        v1_p = v1;
        copy_vec_m(pc50, v1_p);
    }
    copy_vec(s + 0xC60, v0);
    func_01B04A20(0, s + 0xAD0);
    func_01B04FA0(0, s + 0xAD0, v1_p);
    copy_vec(s + 0xB00, s + 0xC60);

    copy_vec(s + 0xC70, v1_p);
    copy_vec(s + 0xC80, v0);
    func_01B04A20(-1, s + 0xB10);
    func_01B04FA0(-1, s + 0xB10, v1_p);
    copy_vec(s + 0xB40, s + 0xC80);

    func_01B04518(-1, 1);
    func_01B04478(-1, 0);
    func_0029A878();

    *(s32 *)(s + 0xEDC) = 0;
    *(float *)(s + 0xEC8) = v1[1];
    *(float *)(s + 0xEC4) = 0.0f;
    *(float *)(s + 0xEC0) = 0.0f;
    {
        register s32 one __asm__("$2") = 1;
        D_01B0A414 = one;
        D_01B0A434 = one;
        D_01B0A454 = one;
        D_01B0A474 = one;
    }
}
