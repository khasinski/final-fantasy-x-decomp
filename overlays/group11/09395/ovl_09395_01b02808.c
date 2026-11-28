#include "common.h"

extern float D_01B00F70[4];
extern float D_01B00F80[4];
extern float D_01B00F90[4];
extern float D_01B00FA0[16];
extern float D_01B01010[4];
extern float D_01B00950;
extern void *D_01B00788;
extern u8 D_01B01308[];
extern int D_01B01004;

extern void func_01B04890(void *, void *, int);
extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DD080(void *, void *, void *);
extern void func_01B05450(void *, float);
extern void func_00110830(void *, void *);
extern void func_01B057D8(void *);
extern void func_01B05458(void *, float);

int func_01B02808(void)
{
    float mat0[4][4];
    float mat1[4][4];
    float f;

    func_01B04890(D_01B00F70, D_01B00F80, 0);
    func_01B04890(D_01B01010, 0, 0);
    f = D_01B00950;
    D_01B00F90[0] = f;
    D_01B00F90[1] = f;
    D_01B00F90[2] = f;
    D_01B00F90[3] = 1.0f;
    func_002DD128(D_01B00FA0);
    func_002DD128(mat1);
    func_002DD128(mat0);
    func_002DD318(mat1, mat1, D_01B00F80[1]);
    func_002DCE38(D_01B00FA0, mat1, D_01B00FA0);
    func_002DD080(D_01B00FA0, D_01B00FA0, D_01B00F70);
    func_01B05450(D_01B00FA0, 15.0f);
    mat0[0][0] = D_01B00F90[0] * 0.0010000001f;
    mat0[1][1] = D_01B00F90[1] * 0.0010000001f;
    mat0[2][2] = D_01B00F90[2] * 0.0010000001f;
    func_002DCE38(D_01B00FA0, D_01B00FA0, mat0);
    func_00110830(D_01B00788, D_01B00FA0);
    func_01B057D8(D_01B01308);
    func_01B05458(D_01B01010, 5.0f);
    return D_01B01004 == 0;
}
