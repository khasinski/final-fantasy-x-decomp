#include "common.h"

extern void *D_01B00658;
extern int D_01B00BA4;
extern void func_0010C790(void *, int);
extern void func_01B01898(void);

int func_01B01C00(void)
{
    func_0010C790(D_01B00658, 0);
    func_01B01898();
    D_01B00BA4 = 1;
    return 1;
}
