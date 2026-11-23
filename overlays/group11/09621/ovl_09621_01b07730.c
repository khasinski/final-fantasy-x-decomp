#include "common.h"

typedef struct S7730Obj {
    u8 pad00[0x1C];
    s32 s1C;
    s32 s20;
    float f24;
    u8 pad28[4];
    void *p2C;
    void *p30;
    u8 pad34[0xC];
    u8 s40[0x30];
    float v70[4];
    u8 pad80[0x40];
    float vC0[4];
    s32 sD0;
    s32 sD4;
    s32 sD8;
    u8 padDC[4];
    s32 sE0;
    s32 sE4;
    s32 sE8;
} S7730Obj;

extern void func_01B074D0(void);
extern void func_01B16A98(void *a0);
extern void func_01B16EA0(void *a0);
extern void func_01B0DBC0(void *a0);
extern void func_002DD038(float *dst, float *a, void *b);
extern void func_002DCEC8(float *dst, float *src);
extern void func_002DD068(float *dst, float *src, float scale);
extern s32 func_001ACEA0(void);

extern u8 D_01B00B80[];
extern void *D_01B00718[];

void func_01B07730(S7730Obj *a0, void *a1, s32 a2, void *a3, void *a4)
{
    float v[4];
    void *m[4];
    void **s1 = m;

    s1[1] = func_01B074D0;
    m[0] = a0;
    m[2] = a0;
    func_01B16A98(s1);

    m[0] = D_01B00B80;
    m[1] = a0;
    func_01B16EA0(s1);

    m[0] = a1;
    m[1] = D_01B00718[a2];
    m[2] = a0->s40;
    func_01B0DBC0(s1);

    func_002DD038(v, a0->v70, a3);
    func_002DCEC8(v, v);
    func_002DD068(a0->vC0, v, 5.0f);

    a0->vC0[3] = 0.0f;
    a0->vC0[1] += -2.0f;
    a0->sD0 = 0;
    a0->sD4 = 0;
    a0->sD8 = 0;
    a0->sE0 = (func_001ACEA0() & 0x7FF) - 1024;
    a0->sE4 = (func_001ACEA0() & 0x7FF) - 1024;
    a0->sE8 = (func_001ACEA0() & 0x7FF) - 1024;
    a0->p30 = a4;
    a0->s1C = a2;
    a0->p2C = a1;
    a0->f24 = 1.0f;
    a0->s20 = 0;
}
