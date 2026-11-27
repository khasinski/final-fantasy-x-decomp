#include "common.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0x1B50];
    u8 f1B50[0x40];
    Vec4 v1B90;
    Vec4 v1BA0;
    u8 pad1BB0[0x80];
    Vec4 v1C30;
    Vec4 v1C40;
    u8 pad1C50[0x2D0];
    int w1F20;
} Ovl09494Work;

extern Ovl09494Work *D_01B0A310;

extern void func_01B04FD8(int, void *, void *);
extern void func_01B06F40(void *, void *, void *);

void func_01B02320(void)
{
    Vec4 off;
    Ovl09494Work *w = D_01B0A310;

    copy_vec(&w->v1C30, &w->v1BA0);
    copy_vec(&w->v1C40, &w->v1BA0);
    w->v1B90.x = -1.4137167f;
    off.x = 0.0f;
    off.y = -50.0f;
    off.z = 0.0f;
    off.w = 1.0f;
    func_01B06F40(&w->v1B90, &w->v1C40, &off);
    func_01B04FD8(-1, w->f1B50, &w->v1B90);
    w->w1F20 = 30;
}
