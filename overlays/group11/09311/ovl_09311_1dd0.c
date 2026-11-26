#include "common.h"

typedef float sceVu0FMATRIX[4][4];
typedef float sceVu0FVECTOR[4];

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct {
    Vec4 m[4];
    float f40;
    float f44;
    float f48;
    float f4C;
    Vec4 pos;
    float f60;
    float f64;
    float f68;
    int w6C;
} Ovl65C0;

extern Ovl65C0 D_01B065C0;
extern float D_01B06710;
extern int D_01B06720;

extern void func_002B2F18(int);
extern void func_002DD1C8(void *, void *, float);
extern void func_002DD270(void *, void *, float);
extern void func_002DD318(void *, void *, float);
extern void func_002DD998(void *, void *, float);
extern void func_01B032E8(int);
extern void func_01B03438(int, void *);
extern void func_01B039E0(int, void *);
extern void func_01B03E90(int, void *);

static __inline__ void wrap_angle(float *p, float d)
{
    float v = *p + d;
    if (v > 3.1415927f) {
        v -= 6.2831855f;
    } else if (v < -3.1415927f) {
        v += 6.2831855f;
    }
    *p = v;
}

void ovl_09311_1dd0(void)
{
    sceVu0FMATRIX m;
    Ovl65C0 *s1 = &D_01B065C0;

    if (s1->w6C > 0) {
        s1->w6C -= 1;
        if (s1->w6C == 0) {
            func_01B032E8(-1);
        }
        return;
    }
    if (s1->f64 == 0.0f) {
        return;
    }
    wrap_angle(&s1->f40, s1->f60);
    wrap_angle(&s1->f44, s1->f60);
    wrap_angle(&s1->f48, s1->f60);
    s1->f64 += s1->f68;
    if (s1->f64 < 0.0f) {
        s1->f64 = 0.0f;
        s1->f68 = 0.0f;
    }
    D_01B06710 -= 0.085f / 90.0f;
    if (s1->f64 == 0.0f) {
        func_01B039E0(-1, 0);
        func_01B03438(-1, 0);
        D_01B06710 = 0.0f;
        func_002B2F18(D_01B06720);
        D_01B06720 = -1;
    }
    s1->pos.y += 0.4f;
    func_01B03E90(-1, m);
    func_002DD1C8(s1->m, m, s1->f48);
    func_002DD270(s1->m, s1->m, s1->f40);
    func_002DD318(s1->m, s1->m, s1->f44);
    func_002DD998(&s1->m[0], &s1->m[0], s1->f64);
    func_002DD998(&s1->m[1], &s1->m[1], s1->f64);
    func_002DD998(&s1->m[2], &s1->m[2], s1->f64);
    {
        register u_long128 *dst __asm__("$2") = (u_long128 *)&s1->m[3];
        register u_long128 *src __asm__("$3") = (u_long128 *)&s1->pos;
        register u_long128 _t __asm__("$7");
        __asm__("" : "+r"(dst), "+r"(src));
        _t = *src;
        *dst = _t;
    }
}
