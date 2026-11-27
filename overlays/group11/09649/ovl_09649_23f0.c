#include "common.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    Vec4 vD0;
} Sub720;

typedef struct {
    u8 pad00[0x720];
    Sub720 s720;
    u8 pad800[0xCB0];
    Vec4 v14B0;
    u8 pad14C0[0x1CB8];
    float f3178;
} Work23F0;

extern u8 D_01B0B130[];
extern Work23F0 *D_01B0B1F8;
extern void func_01B069B8(void *, void *, int, int, int, int, float);

void func_01B023F0(void)
{
    Work23F0 *w = D_01B0B1F8;
    Sub720 *s = &w->s720;

    func_01B069B8(D_01B0B130, s, 6, 0, 0, 0, 0.180000007f);
    copy_vec(&s->vD0, &w->v14B0);
    s->fC4 = w->f3178;
}
