#include "common.h"

extern int D_01B00658;
extern float D_01B0074C;
extern float D_01B00750;
extern int D_01B00768;
extern float D_01B00A00[4];

extern void func_01B04BB8(void *);
extern void func_00107378(int, void *);
extern int func_00107BE8(int, int);
extern float func_001109E0(int);
extern void func_002DD020(void *, void *, void *);
extern void func_002DD0B0(void *, void *);
extern void func_002DD0C0(void *, void *);
extern void func_002DD998(void *, void *, float);

void func_01B036A0(void)
{
    func_00107BE8(D_01B00658, 0);
    D_01B00768 = 0;
}

void func_01B036D0(float (*dst)[4], int a1)
{
    float mat[4][4];
    float v[4];
    float d;

    func_00107378(a1, mat);
    func_01B04BB8(mat);
    d = func_001109E0(a1);
    func_002DD998(v, mat[2], -(d + D_01B0074C));
    func_002DD020(mat[3], mat[3], v);
    mat[3][1] += D_01B00750;
    func_002DD0C0(dst, mat);
    func_002DD0B0(D_01B00A00, dst[3]);
}
