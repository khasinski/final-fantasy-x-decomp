#include "common.h"

extern void *D_01B012C4;
extern void *D_01B012C8;
extern void func_002B4980(void *);
extern void func_002D02E8(void *, int, int, int);
extern void func_002944B0(void *, int, int, int);
extern void *func_002B49A0(void *, int, int);

void ovl_09227_0648(void *a0)
{
    void **p1 = &D_01B012C4;
    void **p2 = &D_01B012C8;

    func_002B4980(a0);
    func_002D02E8(a0, 0, 1000, 256);
    func_002944B0(a0, 0, 1000, 256);
    *p1 = func_002B49A0(a0, 6, 0);
    *p2 = func_002B49A0(a0, 6, 1);
}
