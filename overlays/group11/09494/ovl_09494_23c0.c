#include "common.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

static inline void lerp_vec(Vec4 *dst, Vec4 *a, Vec4 *b, float t) {
    Vec4 tmp;
    float *pt = &tmp.x;
    float *pb = &b->x;
    float *pa = &a->x;
    float s = 1.0f - t;
    s32 i;
    for (i = 2; i >= 0; i--) {
        *pt++ = *pa++ * s + *pb++ * t;
    }
    tmp.w = 1.0f;
    copy_vec(dst, &tmp);
}

typedef struct {
    u8 pad00[0x1B50];
    u8 f1B50[0x40]; /* 0x1B50 */
    Vec4 v1B90;     /* 0x1B90 */
    Vec4 v1BA0;     /* 0x1BA0 */
    u8 pad1BB0[0x60];
    Vec4 v1C10;     /* 0x1C10 */
    Vec4 v1C20;     /* 0x1C20 */
    Vec4 v1C30;     /* 0x1C30 */
    Vec4 v1C40;     /* 0x1C40 */
    u8 pad1C50[0x2D0];
    int w1F20;      /* 0x1F20 */
} Ovl09494Work;

extern Ovl09494Work *D_01B0A310;
extern void func_01B04FD8(int, void *, void *);

void func_01B023C0(void)
{
    Ovl09494Work *w = D_01B0A310;
    float t;

    if (w->w1F20 > 0) {
        w->w1F20--;
        t = (float)w->w1F20 / 30.0f;
    } else {
        t = 1.0f;
    }
    lerp_vec(&w->v1BA0, &w->v1C40, &w->v1C30, t);
}

void func_01B02470(void)
{
    Ovl09494Work *w = D_01B0A310;

    w->v1B90.x = 0.0f;
    func_01B04FD8(-1, w->f1B50, &w->v1B90);
    copy_vec(&w->v1BA0, &w->v1C10);
}
