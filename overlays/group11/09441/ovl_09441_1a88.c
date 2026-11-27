#include "common.h"

extern u8 *D_01B093A8;

int func_01B03170(int a0);
int func_00297C28(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
void func_00297CE8(int a0);

void func_01B01A88(void)
{
    u8 *s0 = D_01B093A8;

    *(int *)(s0 + 0x2494) = func_00297C28(func_01B03170(-1), 0, 0, 0, 0, 0, 0);
}

void func_01B01AD8(void)
{
    u8 *s0 = D_01B093A8;

    func_00297CE8(*(int *)(s0 + 0x2494));
    *(int *)(s0 + 0x2494) = -1;
}
