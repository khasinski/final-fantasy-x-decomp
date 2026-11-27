#include "common.h"

extern int D_01B00B84;
extern int MsGetChrHandle(int);
extern void func_0010C790(int, int);

int func_01B0ED78(void)
{
    func_0010C790(MsGetChrHandle(D_01B00B84), 0);
    return 0;
}
