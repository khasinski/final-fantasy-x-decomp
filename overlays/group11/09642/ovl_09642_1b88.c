#include "common.h"

static __inline__ void copy_vec4_a3(void *dst, void *src)
{
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    float x, y, z, w;
} VecF;

typedef struct {
    u8 pad00[0x850];
    u8 f850[0x80];
    u8 f8D0[0x40];
    VecF v910;
    VecF v920;
    u8 pad930[0x20];
    VecF v950;
    VecF v960;
    u8 pad970[0x250];
    u8 fBC0[0x188];
    float fD48;
} Work1B88;

extern Work1B88 *D_01B09148;

extern void func_01B038C8(int, void *, void *);
extern void func_01B05830(void *, void *, void *);
extern void func_01B08368(void *, int, int, float, float);

void func_01B01B88(void)
{
    VecF v0;
    VecF v1;
    Work1B88 *w = D_01B09148;
    float *py;
    float a;

    py = &w->v910.y;
    a = *py + 0.785398185f;
    if (a > 3.14159274f) {
        a -= 6.28318548f;
    } else if (a < -3.14159274f) {
        a += 6.28318548f;
    }
    *py = a;

    v0.x = 0.0f;
    v0.y = w->fD48;
    v0.z = 0.0f;
    v0.w = 0.0f;
    v1.x = 25.0f;
    v1.y = 0.0f;
    v1.z = 15.0f;
    v1.w = 1.0f;
    func_01B05830(&v0, &w->v920, &v1);
    func_01B038C8(0, w->f850, &w->v910);
    copy_vec4_a3(&w->v950, &w->v910);
    copy_vec4_a3(&w->v960, &w->v920);
    func_01B038C8(1, w->f8D0, &w->v950);
    func_01B08368(w->fBC0, 0x1E, 0x55, 0.5f, 1.0f);
}
