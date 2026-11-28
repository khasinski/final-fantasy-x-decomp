#include "common.h"

extern void *D_01B00B84;
extern void *func_001B4E58(void *);
extern void func_0010C790(void *, int);
extern void func_002B2C50(int);

int func_01B0F630(void)
{
    func_0010C790(func_001B4E58(D_01B00B84), 0);
    func_002B2C50(0);
    return 0;
}
