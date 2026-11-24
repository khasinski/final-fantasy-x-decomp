#include "common.h"

typedef struct Ovl09212SubAF {
    u8 pad00[0x64];
    float f64;
    u8 pad68[0x5C];
    float fC4;
    u8 padC8[0xC];
    float fD4;
    u8 padD8[0x58];
} Ovl09212SubAF;

typedef struct Ovl09212Work {
    u8 pad00[0x720];
    Ovl09212SubAF s720;
    Ovl09212SubAF s850;
    u8 pad980[0x40];
    u8 f9C0[0x40];
    float fA00[4];
    u8 padA10[0x30];
    float fA40[4];
    u8 padA50[0x50];
    float fAA0[4];
    float fAB0[4];
    u8 padAC0[0x270C];
    s32 w31CC;
} Ovl09212Work;

extern Ovl09212Work *D_01B0A8E8;

void func_01B05388(s32, void *, void *);
void func_002DD128(void *);
float func_002B3DB0(float);
void func_002DD318(void *, void *, float);
float func_002B3DF8(float);
void func_002DCE08(void *, void *, void *);
float func_01B06FA0(float, float, float, float);
s32 func_002EFD78(void);
void func_00118098(s32, s32);

void func_01B032D0(void)
{
    Ovl09212Work *w = D_01B0A8E8;
    float mtx[4][4];
    float vec[4];
    float t;
    float val;
    s32 cnt;

    {
        float *p = &w->fAA0[1];
        float a = *p + 0.031415928f;
        if (a > 3.1415927f) {
            a -= 6.2831855f;
        } else if (a < -3.1415927f) {
            a += 6.2831855f;
        }
        *p = a;
    }

    func_01B05388(-1, w->f9C0, w->fAA0);

    {
        Ovl09212SubAF *sub = &w->s720;
        sub->fD4 += 8.333333f;
        cnt = --w->w31CC;
        sub = &w->s850;
        sub->fD4 += 8.333333f;
    }
    w->fAB0[1] += 8.333333f;

    if (cnt == 0) {
        func_002DD128(mtx);
        func_002DD318(mtx, mtx, func_002B3DB0(3.1415927f));
        vec[0] = 0.0f;
        vec[1] = 0.0f;
        vec[2] = func_002B3DF8(10.0f) + 30.0f;
        vec[3] = 1.0f;
        func_002DCE08(vec, mtx, vec);
        w->w31CC = 40;
        w->fA40[0] = w->fAB0[0] + vec[0];
        w->fA40[1] = w->fAB0[1] + 50.0f;
        w->fA40[2] = w->fAB0[2] + vec[2];
        w->fA40[3] = 20.0f;
    }

    t = (float)w->w31CC / 40.0f;
    w->fA40[1] = (w->fAB0[1] - 100.0f) * (1.0f - t) + (w->fAB0[1] + 100.0f) * t;
    val = func_01B06FA0(0.0f, 1.0f, 0.0f, t);
    w->fA00[2] = val;
    w->fA00[1] = val;
    w->fA00[0] = val;

    func_00118098(0, func_002EFD78() % 0x8000);
    func_00118098(1, func_002EFD78() % 0x8000);
}
