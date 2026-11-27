#include "common.h"

extern u8 D_01B004F8[];
extern void *D_006A3924;
extern void func_00267530(void);

int func_01B0B6F8(void)
{
    D_006A3924 = D_01B004F8;
    func_00267530();
    return 1;
}
