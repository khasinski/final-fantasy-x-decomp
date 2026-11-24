#include "common.h"

extern void *D_01B006C4;
extern int D_01B00CB4;
extern void *D_01B00CBC;
extern u8 D_01B00D30;
extern char D_01B037D8[];

extern int func_01B02BC0(char *, ...);
extern void func_01B03150(void *, void *, int);
extern void func_01B03438(void *, int, float, float);
extern void *func_002B49A0(void *, int, int);

int func_01B01A88(void)
{
    func_01B02BC0(D_01B037D8);
    D_01B00CB4 = (int)func_002B49A0(D_01B006C4, 4, 1);
    func_01B03150(&D_01B00D30, D_01B00CBC, 100);
    func_01B03438(&D_01B00D30, 0, 0.0f, 0.0f);
    return 1;
}
