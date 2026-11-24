#include "common.h"

extern void func_01B03670(int);
extern int func_01B036A0(int);

void func_01B00F00(void)
{
    func_01B03670(0x3013);
}

int func_01B00F08(void)
{
    return func_01B036A0(0x3013) == 1;
}
