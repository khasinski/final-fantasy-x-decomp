#include "common.h"

extern u8 *D_01B0A988;

void func_00118098(int a0, int a1);
void func_01B09BE8(void *a0, int a1, int a2, float f0, float f1);

void func_01B01D90(void)
{
    func_00118098(0, 0x10000);
    func_00118098(1, 0x20000);
    func_01B09BE8(D_01B0A988 + 0x3870, 0x14, 0, 1.0f, 0.5f);
}
