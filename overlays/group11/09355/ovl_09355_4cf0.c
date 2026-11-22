#include "common.h"
#include "vu0.h"

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct Obj4cf0 Obj4cf0;

struct Obj4cf0 {
    u8 pad00[0x20];
    Vec4 v20;
    Vec4 v30;
    Vec4 pts[5];
    void (*cb90)(Obj4cf0 *);
    void (*cb94)(Obj4cf0 *);
    float f98;
    float f9C;
    void *pA0;
    s32 wA4;
    s32 wA8;
    u8 padAC[0x04];
    u16 hB0;
};

typedef struct {
    u8 pad00[0x14];
    Obj4cf0 *p14;
    u8 b18;
} OvlTask;

extern void func_001B6790(void *, Vec4 *);
extern void func_001B6BB0(void *, Vec4 *);
extern void func_002DD020(Vec4 *, Vec4 *, Vec4 *);
extern void func_002DD038(Vec4 *, Vec4 *, Vec4 *);
extern void func_002DD068(Vec4 *, Vec4 *, float);

extern void *func_01B00DF8(int);
extern int func_01B02AE8(Obj4cf0 *);
extern OvlTask *func_01B03608(void *);
extern void func_01B03688(OvlTask *);
extern void func_01B037D0(OvlTask *);
extern float func_01B044E0(float, float, float, float, float, float);

void ovl_09355_4e78(OvlTask *a0);

static inline void copy_vec(Vec4 *dst, Vec4 *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

void ovl_09355_4cf0(Obj4cf0 *a0, int a1, Vec4 *a2, int a3, float f12, float f13, float f14)
{
    Vec4 v00;
    Vec4 v10;
    void *p;
    int i;
    OvlTask *t;

    p = func_01B00DF8(a1);
    func_001B6790(p, &v00);
    {
        register Vec4 *d0 __asm__("$3") = &a0->v20;
        __asm__("" : "+r"(d0));
        copy_vec(d0, &v00);
    }
    copy_vec(&a0->v30, a2);
    func_002DD038(&v10, a2, &v00);

    {
        float z = 0.0f;
        *(volatile float *)&a0->pts[0].x = z;
        *(volatile float *)&a0->pts[0].z = z;
        *(volatile float *)&a0->pts[0].y = z;
    }
    copy_vec(&a0->pts[4], &v10);
    func_002DD068(&a0->pts[1], &v10, f12);
    func_002DD068(&a0->pts[2], &v10, f13);
    func_002DD068(&a0->pts[3], &v10, f14);

    for (i = 4; i >= 0; i--) {
        a0->pts[i].w = 1.0f;
    }

    a0->pA0 = p;
    a0->wA4 = a3;
    *(s32 *)&a0->f98 = 0;
    a0->f9C = 1.0f / (float)a3;
    a0->cb90 = 0;
    a0->cb94 = 0;
    a0->wA8 = 0;
    a0->hB0 = 0;

    t = func_01B03608((void *)ovl_09355_4e78);
    t->p14 = a0;
    t->b18 = 1;
    __asm__ volatile("" : : : "memory");
    func_01B037D0(t);
}

void ovl_09355_4e78(OvlTask *a0)
{
    Vec4 pos;
    Obj4cf0 *s0 = a0->p14;
    int r;

    if (s0->wA8 > 0) {
        if (s0->hB0 & 1) {
            func_01B02AE8(s0);
        }
        s0->wA8--;
        return;
    }

    if (s0->wA4 > 0 && --s0->wA4 > 0) {
        float t = s0->f98 + s0->f9C;
        s0->f98 = t;
        pos.x = func_01B044E0(s0->pts[0].x, s0->pts[1].x, s0->pts[2].x, s0->pts[3].x, s0->pts[4].x, t);
        pos.y = func_01B044E0(s0->pts[0].y, s0->pts[1].y, s0->pts[2].y, s0->pts[3].y, s0->pts[4].y, t);
        pos.z = func_01B044E0(s0->pts[0].z, s0->pts[1].z, s0->pts[2].z, s0->pts[3].z, s0->pts[4].z, t);
        func_002DD020(&pos, &s0->v20, &pos);
    } else {
        __asm__ volatile("lq $7, 0(%0)" : : "r"(&s0->v30) : "$7", "memory");
        __asm__ volatile("sq $7, 0(%0)" : : "r"(&pos) : "memory");
    }

    func_001B6BB0(s0->pA0, &pos);

    if (s0->wA4 >= 0) {
        if (s0->cb90 != 0) {
            s0->cb90(s0);
        }
        if (s0->wA4 == 0) {
            if (s0->cb94 != 0) {
                s0->cb94(s0);
            }
            s0->wA4--;
        }
    }

    r = func_01B02AE8(s0);
    if (s0->wA4 <= 0 && r == 1) {
        s0->hB0 |= 0x8000;
        func_01B03688(a0);
    }
}
