#include "common.h"

extern void *D_01B006C4;
extern int D_01B00CB0;
extern void *D_01B00CB8;
extern u8 D_01B00CC0;
extern char D_01B037C8[];

extern int func_01B02BC0(char *, ...);
extern void func_01B03150(void *, void *, int);
extern void func_01B03438(void *, int, float, float);
extern void *func_002B49A0(void *, int, int);

int func_01B01640(void)
{
    func_01B02BC0(D_01B037C8);
    D_01B00CB0 = (int)func_002B49A0(D_01B006C4, 4, 0);
    func_01B03150(&D_01B00CC0, D_01B00CB8, 100);
    func_01B03438(&D_01B00CC0, 0, 0.0f, 0.0f);
    return 1;
}
