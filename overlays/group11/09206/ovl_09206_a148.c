#include "common.h"
#include "vu0.h"

#define COPY_VEC(dst, src) do { \
    __asm__ volatile("lq $7, 0(%1)" : : "r"(dst), "r"(src) : "$7", "memory"); \
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory"); \
} while (0)

typedef struct Vec4Slot {
    float v00[4];       /* 0x00 */
    float v10[4];       /* 0x10 */
    u8 pad20[0xC];
    float f2C;          /* 0x2C */
    float f30;          /* 0x30 */
    s32 w34;            /* 0x34 */
    u32 pad38;
    s32 w3C;            /* 0x3C */
} Vec4Slot;

void func_002DD968(float *dst, float *v1, float *v0, float t);

void func_01B0A148(Vec4Slot *s, float *dst)
{
    s->f2C += s->f30;
    if (s->f2C < 1.0f) {
        func_002DD968(dst, s->v10, s->v00, s->f2C);
    } else {
        COPY_VEC(dst, s->v10);
        s->w3C = 0;
    }
}

void func_01B0A198(Vec4Slot *s, float *dst)
{
    __asm__ volatile("lqc2 $vf1, 0(%0)" : : "r"(s->v00), "r"(s->v10) : "memory");
    VU0_LQC2(2, 0, s->v10);
    VU0_OP("vadd.xyz $vf1, $vf1, $vf2");
    VU0_SQC2(1, 0, s->v00);

    VU0_LQC2(1, 0, dst);
    VU0_LQC2(2, 0, s->v00);
    VU0_OP("vadd.xyz $vf1, $vf1, $vf2");
    VU0_SQC2(1, 0, dst);

    if (--s->w34 <= 0) {
        s->w3C = 0;
    }
}
