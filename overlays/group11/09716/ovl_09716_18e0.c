#include "common.h"

extern int D_01B07ED8;
extern void *func_01B020D8(int);
extern void func_00117A68(void *);
extern void func_002A3BD8(void *, int);

void func_01B018E0(void)
{
    void *s0 = func_01B020D8(-1);
    func_00117A68(s0);
    func_002A3BD8(s0, D_01B07ED8);
}
