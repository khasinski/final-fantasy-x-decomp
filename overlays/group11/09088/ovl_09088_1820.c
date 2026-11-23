#include "common.h"

extern void func_002DD128(float (*m)[4]);
extern void *func_01B00BE0(int);

typedef struct {
    int f0;
    void *f4;
    int f8;
    int fC;
    s16 f10;
    s16 f12;
} Obj1860;

void func_01B01820(float (*m)[4])
{
    func_002DD128(m);
    m[2][2] = 0.01f;
    m[1][1] = 0.01f;
    m[0][0] = 0.01f;
}

void func_01B01860(int a0, Obj1860 *s, int a2)
{
    s->f0 = a2;
    s->f4 = func_01B00BE0(a0);
    s->f8 = -1;
    s->f10 = 1;
    s->fC = 0;
    s->f12 = 0;
}
