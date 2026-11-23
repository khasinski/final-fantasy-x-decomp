#include "common.h"

typedef unsigned int qword __attribute__((mode(TI)));

#define VEC_COPY(dst, src) { \
    register qword a3 __asm__("$7") = *(qword *)(src); \
    *(qword *)(dst) = a3; \
    __asm__ volatile(""); \
}

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct {
    Vec4 pos;
    Vec4 vel;
    Vec4 acc;
    u8 sub30[0x0C];
    float f3C;
    u8 pad40[0x0C];
    s32 w4C;
    s32 w50;
    u8 pad54[0x10];
    u8 b64;
    u8 b65;
    u8 b66;
    u8 pad67;
    u8 b68;
    u8 b69;
    u8 b6A;
    u8 b6B;
} Part09398;

extern u8 D_01B06490[];

extern float func_002B3DB0(float);
extern void func_01B015A8(int, Vec4 *, int);
extern void **func_01B04458(void *, int);
extern void func_01B05290(void *, void *);
extern Part09398 *func_01B05CC0(void);

void ovl_09398_0f08(void)
{
    Vec4 v0;
    Part09398 *p;

    func_01B015A8(-1, &v0, 0);
    p = func_01B05CC0();
    if (p != 0) {
        func_01B05290(p->sub30, *func_01B04458(D_01B06490, 0));
        VEC_COPY(&p->pos, &v0);
        {
            float r = func_002B3DB0(2.0f);
            register float fx __asm__("$f1") = p->pos.x;
            fx += r;
            p->pos.x = fx;
        }
        p->pos.y -= 2.0f;
        p->pos.z += func_002B3DB0(2.0f);
        p->vel.x = func_002B3DB0(0.2f);
        p->vel.y = func_002B3DB0(0.1f) + (-0.3f);
        p->vel.z = func_002B3DB0(0.2f);
        p->vel.w = func_002B3DB0(3.1415927f);
        p->acc.x = p->vel.x * 0.02f;
        p->acc.y = p->vel.y * 0.02f;
        p->acc.z = p->vel.z * 0.02f;
        p->acc.w = 1.0f;
        p->f3C = (func_002B3DB0(0.5f) + 1.0f) * 0.5f;
        p->w4C = 32;
        p->w50 = 32;
        p->b64 = 250;
        p->b65 = 250;
        p->b66 = 250;
        p->b68 = 250;
        p->b69 = 250;
        p->b6A = 250;
        p->b6B = 0;
        p = func_01B05CC0();
        if (p != 0) {
            func_01B05290(p->sub30, *func_01B04458(D_01B06490, 1));
            VEC_COPY(&p->pos, &v0);
            p->pos.x += func_002B3DB0(2.0f);
            p->pos.y -= 2.0f;
            p->pos.z += func_002B3DB0(2.0f);
            p->vel.x = func_002B3DB0(0.5f);
            p->vel.y = func_002B3DB0(0.5f) + (-2.0f);
            p->vel.z = func_002B3DB0(0.5f);
            p->vel.w = func_002B3DB0(3.1415927f);
            p->acc.x = p->vel.x * (-0.01f);
            p->acc.y = p->vel.y * (-(func_002B3DB0(0.02f) + 0.1f));
            p->acc.z = p->vel.z * (-0.01f);
            p->acc.w = 1.0f;
            p->f3C = (func_002B3DB0(0.5f) + 1.0f) * 0.03f;
            p->w4C = 24;
            p->w50 = 0;
        }
    }
}
