#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

#define copy_vec_r(dst, src) do { \
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory"); \
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory"); \
} while (0)

extern u8 *D_01B093A8;

extern void func_01B06A80(float *, void *, float *);
extern void func_01B03458(s32, float *);

void func_01B01D20(void) {
    float v0[4];
    float v1[4];
    float v2[4];
    register u8 *s __asm__("$16") = D_01B093A8;
    register u8 *p1900 __asm__("$20") = s + 0x1900;

    copy_vec(s + 0xD0, p1900);
    v1[0] = 0.0f;
    v1[1] = *(float *)(s + 0x2488);
    v1[2] = 0.0f;
    v1[3] = 0.0f;
    v2[0] = 0.0f;
    v2[1] = 0.0f;
    v2[2] = 130.0f;
    v2[3] = 1.0f;
    func_01B06A80(v1, s + 0xD0, v2);

    *(s32 *)(s + 0x104) = 0;
    copy_vec(s + 0x1910, s + 0xD0);
    {
        register s32 c120 __asm__("$3") = 120;
        *(s32 *)(s + 0x2490) = c120;
    }
    copy_vec_r(v0, p1900);
    v2[2] = 105.0f;
    v2[3] = 1.0f;
    {
        register float *a1 __asm__("$5") = v0;
        v2[0] = 0.0f;
        v2[1] = 0.0f;
        func_01B06A80(v1, a1, v2);
    }
    func_01B03458(-1, v0);
}
