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
} Sub130;

typedef struct {
    u8 pad00[0x130];
    Sub130 s130;
    u8 pad210[0x750];
    Vec4 v960;
    u8 pad970[0x7A20];
    int w8390[4];
    u8 pad83A0[0x90];
    u8 f8430[0x1D8];
    float f8608;
} Work3D48;

extern u8 D_01B0C700[];
extern Work3D48 *D_01B0C888;
extern void func_00118098(int, int);
extern void func_01B07E80(void *, void *, int, int, int, int, float);
extern void func_01B0B6A0(void *, int);
extern void func_01B0BA88(void *, int, int, float, float);

void func_01B03D48(void)
{
    Work3D48 *w = D_01B0C888;
    int *p;

    func_01B0BA88(w->f8430, 0x1E, 0, 1.0f, 0.5f);
    p = w->w8390;
    p[1] = 0x64;
    p[0] = 0;
    p[2] = 0;
    p[3] = 0;
    func_01B0B6A0(p, 0x96);
    func_00118098(0, 0x10000);
    func_00118098(1, 0x8000);
}

void func_01B03DD0(void)
{
    Work3D48 *w = D_01B0C888;
    Sub130 *s = &w->s130;

    func_01B07E80(D_01B0C700, s, 1, 0, 0, 0, 0.150000006f);
    copy_vec(&s->vD0, &w->v960);
    s->fC4 = w->f8608;
    s->vD0.y -= 0.5f;
}
