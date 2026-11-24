#include "common.h"

extern void *D_01B007DC;
extern int D_01B00FD0;
extern void *D_01B00FD4;
extern u8 D_01B00FE0;
extern char D_01B04060[];

extern int func_01B03408(char *, ...);
extern void func_01B03998(void *, void *, int);
extern void func_01B03C80(void *, int, float, float);
extern void *func_002B49A0(void *, int, int);

int func_01B01BE8(void)
{
    func_01B03408(D_01B04060);
    D_01B00FD0 = (int)func_002B49A0(D_01B007DC, 4, 2);
    func_01B03998(&D_01B00FE0, D_01B00FD4, 500);
    func_01B03C80(&D_01B00FE0, 0, 0.0f, 0.0f);
    return 1;
}
