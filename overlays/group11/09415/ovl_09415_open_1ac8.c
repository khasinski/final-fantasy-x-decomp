#include "common.h"

typedef int qword __attribute__((mode(TI)));

typedef struct {
    unsigned long long lo;
    unsigned long long hi;
} Vec4Q;

extern Vec4Q D_01B029F0;

extern void func_002DCE80(void *, void *, void *);
extern void func_002DCEC8(void *, void *);
extern void func_002DD038(void *, void *, void *);

void func_01B01AC8(float m[4][4], void *eye, void *at)
{
    float dir[4];
    float x[4];
    float y[4];
    float z[4];
    Vec4Q up = D_01B029F0;

    func_002DD038(dir, at, eye);
    func_002DCEC8(z, dir);
    func_002DCE80(x, &up, z);
    func_002DCE80(y, z, x);
    func_002DCEC8(x, x);
    func_002DCEC8(y, y);
    *(qword *)m[3] = 0;
    m[0][0] = x[0];
    m[0][1] = x[1];
    m[0][2] = x[2];
    m[0][3] = 0.0f;
    m[1][0] = y[0];
    m[1][1] = y[1];
    m[1][2] = y[2];
    m[1][3] = 0.0f;
    m[2][0] = z[0];
    m[2][1] = z[1];
    m[2][2] = z[2];
    m[2][3] = 0.0f;
    m[3][3] = 1.0f;
}
