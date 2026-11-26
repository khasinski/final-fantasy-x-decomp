#include "common.h"

extern void func_00103208(void *);
extern void *func_01B037F0(int);
extern void func_01B04FF0(int);

void func_01B01768(void)
{
    func_00103208(func_01B037F0(1));
    func_00103208(func_01B037F0(2));
    func_00103208(func_01B037F0(3));
    func_00103208(func_01B037F0(4));
    func_01B04FF0(0x3019);
    func_01B04FF0(0x301F);
}
