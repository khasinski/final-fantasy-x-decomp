#include "common.h"

extern u8 *D_01B102F0;

extern void func_00118098(int, int);
extern void func_01B0F458(void *, int, int, float, float);

void func_01B068A8(void)
{
    u8 *s0 = D_01B102F0;

    func_00118098(0, 0x8000);
    func_00118098(1, 0x10000);
    func_01B0F458(s0 + 0x17B0, 0x1E, 0, 1.0f, 0.7f);
}
