#include "common.h"

typedef struct SB880Sub144 {
    u8 pad00[0x20];
    float v20[4];
} SB880Sub144;

typedef struct SB880Sub148 {
    u8 pad00[0x20];
    s32 s20;
    s32 s24;
    s32 s28;
} SB880Sub148;

typedef struct SB880Src {
    u8 pad00[0xD0];
    float vD0[4];
    u8 padE0[0x64];
    SB880Sub144 *p144;
    SB880Sub148 *p148;
} SB880Src;

typedef struct SB880Obj {
    u8 pad00[0x18];
    s32 s18;
    u8 pad1C[0x8];
    void *p24;
    SB880Src *p28;
    u8 pad2C[0x44];
    u8 s70[0x20];
    float v90[4];
    u8 sA0[0x20];
    float vC0[4];
    u8 sD0[0x20];
    s32 sF0;
    s32 sF4;
    s32 sF8;
    u8 padFC[4];
    u8 s100[0x150];
    u8 s250[0x10];
} SB880Obj;

extern void func_01B1B290(void);
extern void func_01B2CC48(void *a0);
extern void func_01B2D050(void *a0);
extern void func_01B261F0(void *a0);
extern void func_002DD0B0(float *dst, float *src);
extern void func_01B27870(void *a0);
extern void func_01B28CC0(void *a0);
extern void func_01B2BC98(void *a0);
extern void *func_002B49A0(void *a0, s32 a1, s32 a2);

extern u8 D_01B00AF0[];
extern u8 D_01B00B08[];
extern u8 D_01B008E0[];
extern u8 D_01B00B28[];
extern void *D_01B2E0D4;
extern u8 D_01B2E0A8[];
extern void *D_01B00640;

void func_01B1B880(SB880Obj *a0, SB880Src *a1)
{
    void *m[10];
    SB880Sub148 *p148;

    m[0] = a0;
    m[1] = func_01B1B290;
    m[2] = a0;
    func_01B2CC48(m);

    m[0] = D_01B00AF0;
    m[1] = a0;
    func_01B2D050(m);

    m[0] = a0->s70;
    m[1] = D_01B00B08;
    func_01B261F0(m);
    func_002DD0B0(a0->v90, a1->vD0);

    m[0] = a0->sA0;
    m[1] = D_01B00B08;
    func_01B261F0(m);
    func_002DD0B0(a0->vC0, a1->p144->v20);
    a0->vC0[3] *= 350.0f;

    m[0] = a0->sD0;
    m[1] = D_01B00B08;
    func_01B27870(m);

    p148 = a1->p148;
    a0->sF0 = p148->s20 + 0x8000;
    a0->sF4 = p148->s24;
    a0->sF8 = p148->s28;

    {
        register void **v1 __asm__("$3") = m + 4;
        m[4] = a0->s100;
        v1[1] = D_01B00B08;
        v1[2] = D_01B008E0;
        m[7] = a0->s70;
        m[8] = a0->sD0;
        m[9] = a0->sA0;
        func_01B28CC0(v1);
    }

    m[0] = a0->s250;
    m[1] = D_01B00B28;
    m[2] = a0->s100;
    m[3] = D_01B2E0D4;
    m[4] = D_01B2E0A8;
    m[5] = (void *)7;
    func_01B2BC98(m);

    a0->p28 = a1;
    a0->p24 = func_002B49A0(D_01B00640, 9, 0);
    a0->s18 = 0;
}
