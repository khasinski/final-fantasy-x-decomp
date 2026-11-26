#include "common.h"

typedef float sceVu0FMATRIX[4][4];
typedef float sceVu0FVECTOR[4];

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct {
    sceVu0FMATRIX m;
    float f40[4];
    Vec4 pos;
} Ovl65C0;

extern Ovl65C0 D_01B065C0;
extern float D_01B06710;
extern float D_01B06714;
extern float D_01B06718;
extern int D_01B0671C;
extern u8 D_01B0BD20[];

extern void *func_002B49A0(void *, int, int);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DD128(void *);
extern void func_002DD270(void *, void *, float);
extern void func_002DD318(void *, void *, float);
extern void func_01B00C48(void *, void *, void *, int, int);
extern void func_01B02308(void);
extern void func_01B03E40(void *, void *);

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

void ovl_09311_20a0(void)
{
    sceVu0FMATRIX m0;
    sceVu0FMATRIX m1;
    sceVu0FMATRIX m2;
    sceVu0FMATRIX m3;
    register void *p_m2 __asm__("$20");
    void *res;

    if (D_01B06710 <= 0.0f) {
        return;
    }
    D_01B0671C += 1;
    if (D_01B0671C > 128) {
        D_01B0671C = 128;
    }
    {
        Ovl65C0 *s0 = &D_01B065C0;
        func_002DD128(m0);
        m0[2][2] = D_01B06710;
        m0[1][1] = D_01B06710;
        m0[0][0] = D_01B06710;
        {
            u_long128 *dst = (u_long128 *)m0[3];
            u_long128 *src = (u_long128 *)&s0->pos;
            register u_long128 _t __asm__("$7");
            __asm__("" : "+r"(dst), "+r"(src) : : "memory");
            _t = *src;
            *dst = _t;
            __asm__("" : : : "memory");
        }
    }
    p_m2 = m2;
    m0[3][1] += D_01B06710 * (40.0f / 0.085f);
    func_01B03E40(m1, p_m2);
    wrap_angle(&D_01B06714, 3.1415927f / 50.0f);
    wrap_angle(&D_01B06718, 3.1415927f / 40.0f);
    func_002DD128(m3);
    func_002DCE38(m3, p_m2, m3);
    func_002DD270(m3, m3, D_01B06714);
    func_002DD318(m3, m3, D_01B06718);
    m3[3][0] = 0.0f;
    m3[3][1] = 0.0f;
    m3[3][2] = 0.0f;
    res = func_002B49A0(D_01B0BD20, 4, 0);
    func_01B00C48(res, m0, m3, D_01B0671C, 1);
    func_01B00C48(res, m0, m3, D_01B0671C / 2, 0);
    func_01B02308();
}
