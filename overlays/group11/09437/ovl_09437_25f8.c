#include "common.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0x1BA0];
    Vec4 v1BA0;
    u8 pad1BB0[0x60];
    Vec4 v1C10;
    u8 pad1C20[0x2FC];
    int w1F1C;
} Work25F8;

extern Work25F8 *D_01B0A5F0;
extern void func_0029A848(Vec4 *);

void func_01B025F8(void)
{
    Work25F8 *w = D_01B0A5F0;
    copy_vec(&w->v1BA0, &w->v1C10);
    w->v1BA0.y -= 40.0f;
    func_0029A848(&w->v1BA0);
}

int func_01B02628(void)
{
    return D_01B0A5F0->w1F1C == -1;
}
