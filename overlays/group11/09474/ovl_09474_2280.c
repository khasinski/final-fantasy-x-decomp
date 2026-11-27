#include "common.h"

extern u8 *D_01B0A480;

void func_00118098(int a0, int a1);
void func_01B09A40(void *a0, int a1, int a2, float f0, float f1);

void func_01B02280(void)
{
    u8 *s0 = D_01B0A480;

    func_00118098(0, 0x10000);
    func_00118098(1, 0x20000);
    func_01B09A40(s0 + 0xE40, 0x1E, 0, 1.0f, 0.5f);
}
