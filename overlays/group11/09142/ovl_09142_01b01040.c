#include "common.h"

extern float D_01B00820;
extern float D_01B00824;
extern int D_01B00AB8;
extern int D_01B00B34;
extern float D_01B00C00[4];
extern float D_01B00C10[4];
extern float D_01B00C20[4];
extern float D_01B00C30[4];
extern float D_01B00C40;

extern void func_00107378(int, void *);
extern void func_00108910(int, int, void *);
extern void func_001109B0(int);
extern int func_001B6790(int, void *);
extern void func_002DCE08(void *, void *, void *);
extern float func_002DCEA0(void *, void *);
extern void func_002DCEC8(void *, void *);
extern void func_002DD020(void *, void *, void *);
extern void func_002DD038(void *, void *, void *);
extern void func_002DD0B0(void *, void *);
extern void func_002DD998(void *, void *, float);
extern double atan(double);
extern double sqrt(double);
extern double dpadd(double, double);

extern float func_01B00F38(int);
extern void func_01B00FE8(void *, void *);
extern void func_01B04148(void *, float);
extern void func_01B04150(void *, float);

extern int abs(int);

void func_01B01040(u8 *a0)
{
    float v[4];
    float mat[4][4];
    float u0[4];
    float u1[4];
    float d;
    float f;

    func_01B00FE8(mat, a0);

    v[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = -D_01B00820;
    v[3] = 1.0f;
    func_002DCE08(D_01B00C00, mat, v);
    func_01B04150(D_01B00C00, 5.0f);

    v[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = D_01B00820;
    v[3] = 1.0f;
    func_002DCE08(D_01B00C10, mat, v);
    func_01B04150(D_01B00C10, 5.0f);

    v[0] = -D_01B00820;
    v[1] = 0.0f;
    v[2] = 0.0f;
    v[3] = 1.0f;
    func_002DCE08(D_01B00C20, mat, v);
    func_01B04150(D_01B00C20, 5.0f);

    v[0] = D_01B00820;
    v[1] = 0.0f;
    v[2] = 0.0f;
    v[3] = 1.0f;
    func_002DCE08(D_01B00C30, mat, v);
    func_01B04150(D_01B00C30, 5.0f);

    func_002DCEC8(u0, a0 + 0x20);
    func_002DCEC8(u1, mat[2]);
    d = func_002DCEA0(u0, u1);
    f = (float)atan((double)d / sqrt((double)(1.0f - d * d)));
    f = (float)dpadd(1.57079632679489665, (double)f);
    D_01B00C40 = (float)((double)(f * 180.0f) / 3.1415926535897933);
    func_01B04148(mat, 20.0f);
}

void func_01B01280(float *a0, int a1)
{
    float mat[4][4];
    float v40[4];
    float v50[4];
    float v60[4];
    float v70[4];
    float r;
    int dy;

    func_00107378(a1, mat);
    func_002DD0B0(v40, mat[3]);
    func_002DD0B0(v50, mat[2]);
    func_002DCEC8(v50, v50);
    func_002DD998(v50, v50, -1.0f);
    r = func_01B00F38(D_01B00B34);
    func_001109B0(a1);
    func_00108910(a1, 16, v60);
    func_002DD998(v70, v50, (float)((double)(r + 6.0f) - 6.0));
    func_002DD020(a0, v60, v70);

    dy = abs((int)(v60[1] - v40[1]));
    if ((float)dy < 19.200001f) {
        a0[1] = v40[1] - 19.200001f;
    } else {
        a0[1] -= 8.0f;
    }
}

void func_01B013F8(float *a0, int a1)
{
    float mat[4][4];
    float v40[4];
    float v50[4];
    float v60[4];
    float v70[4];
    float v80[4];
    float v90[4];
    float r;
    int dy;

    func_00107378(a1, mat);
    func_002DD0B0(v40, mat[3]);
    func_001B6790(D_01B00B34, v80);
    func_001B6790(D_01B00AB8, v90);
    func_002DD038(v50, v90, v80);
    func_002DCEC8(v50, v50);
    r = func_01B00F38(D_01B00B34) + D_01B00824;
    func_001109B0(a1);
    func_00108910(a1, 16, v60);
    func_002DD998(v70, v50, (float)((double)(r + 6.0f) - 6.0));
    func_002DD020(a0, v60, v70);

    dy = abs((int)(v60[1] - v40[1]));
    if ((float)dy < 19.200001f) {
        a0[1] = v40[1] - 19.200001f;
    } else {
        a0[1] -= 8.0f;
    }
}
