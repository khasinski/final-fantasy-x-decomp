#include "common.h"

typedef struct {
    u8 pad00[0x10];
    s32 fn10;
} SubTask;

typedef struct {
    u8 pad00[0x8];
    SubTask *sub08;
    u8 pad0C[0x8];
    s32 state14;
} Task0F38;

typedef struct {
    s32 w00;
    s32 w04;
    s32 w08;
    s32 w0C;
} Buf7DF8;

typedef struct {
    u8 pad00[0xD0];
    float vecD0[4];
} Obj7ED0;

typedef struct {
    u8 pad00[0x50];
    float f50;
    float f54;
    float f58;
    u8 pad5C[0x8];
    float f64;
    u8 pad68[0x44];
    s32 wAC;
} CamObj;

extern u8 D_01B07DD8[];
extern u8 D_01B07D18[];
extern u8 D_01B07D78[];
extern u8 D_01B07E88[];
extern void *D_01B08134;
extern u8 D_01B00CC0[];
extern Buf7DF8 D_01B07DF8;
extern float D_01B07E84;
extern Obj7ED0 D_01B07ED0;
extern u8 D_01B006B0[];
extern u8 D_01B006F0[];

extern s32 func_01B03110(void *);
extern s32 func_01B064C8(void *);
extern s32 func_01B04070(void *, void *);
extern void func_01B06708(void);
extern void func_01B02338(s32, s32);
extern void func_01B02850(s32, s32, float);
extern void func_01B021E8(s32);
extern void func_01B07A98(void *, s32);
extern void func_00117E58(s32);
extern void func_01B01670(s32, void *, s32);
extern void func_01B017A0(s32, void *);
extern void func_01B03F90(void *, void *, s32, s32, s32, void *, float);
extern CamObj *func_01B068F8(s32);
extern void func_01B06A10(void *, s32, void *, s32, s32);
extern void func_01B069A8(void *, s32, void *, void *, s32);

void ovl_09347_0f38(Task0F38 *s3)
{
    s32 a = func_01B03110(D_01B07DD8);
    s32 b = func_01B064C8(D_01B07D18);
    s32 c = func_01B064C8(D_01B07D78);
    s32 d = func_01B04070(D_01B07E88, D_01B08134);

    if (d == 1 && a == 1 && b == 1 && c == 1) {
        func_01B06708();
        func_01B02338(-1, 0);
        s3->state14 = 3;
        s3->sub08->fn10 = (s32)D_01B00CC0;
    }
}

void ovl_09347_1008(void)
{
    func_01B02850(-1, 16, 0.0f);
    func_01B021E8(-1);
}

void ovl_09347_1030(void)
{
    D_01B07DF8.w00 = 0;
    D_01B07DF8.w04 = 0;
    D_01B07DF8.w08 = 80;
    D_01B07DF8.w0C = 0;
    func_01B07A98(&D_01B07DF8, 80);
}

void ovl_09347_1058(void)
{
    func_00117E58(40);
}

void ovl_09347_1060(void)
{
    float v[4];

    func_01B01670(-1, v, 0);
    v[1] -= 0.09f;
    func_01B017A0(-1, v);
}

void ovl_09347_10a8(void)
{
    float v[4];

    func_01B01670(-1, v, 0);
    D_01B07E84 += 0.005f;
    v[1] += D_01B07E84;
    func_01B017A0(-1, v);
}

void ovl_09347_1100(void)
{
    Obj7ED0 *s0 = &D_01B07ED0;

    func_01B03F90(D_01B07E88, s0, 0, 0, 8, ovl_09347_1008, 0.4f);
    func_01B01670(-1, s0->vecD0, 1);
    s0->vecD0[1] += 5.0f;
}

void ovl_09347_1178(void)
{
    CamObj *cam = func_01B068F8(0);
    func_01B06A10(cam, 0, D_01B006B0, 5, 24);
}

void ovl_09347_11b0(void)
{
    CamObj *cam = func_01B068F8(0);
    func_01B06A10(cam, 0, D_01B006F0, 4, 30);
}

void ovl_09347_11e8(void)
{
    CamObj *cam = func_01B068F8(0);

    cam->f64 += 4.0f;
    cam->f50 = -0.0727f;
    cam->f54 = 14.0f;
    cam->f58 = -97.9727f;
    cam->wAC = 0;
}

void ovl_09347_1248(void)
{
    float a[4];
    float b[4];
    CamObj *cam = func_01B068F8(0);

    a[0] = 0.0f;
    a[1] = -0.36f;
    a[2] = 0.0f;
    b[0] = 0.0f;
    b[1] = 0.003f;
    b[2] = 0.0f;
    func_01B069A8(cam, 1, a, b, 120);
}
