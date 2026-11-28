#include "common.h"

extern u8 *D_01B0BC98;

void func_01B040D8(void)
{
    *(u16 *)(D_01B0BC98 + 0x714) |= 1;
}

void func_01B040F0(void)
{
    *(u16 *)(D_01B0BC98 + 0x714) &= ~1;
}
