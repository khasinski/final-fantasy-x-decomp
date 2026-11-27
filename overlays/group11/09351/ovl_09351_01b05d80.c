#include "common.h"

extern u8 *D_01B0E828;
extern void func_01B0CA38(void *, int, int, float, float);

void func_01B05D80(void)
{
    func_01B0CA38(D_01B0E828 + 0x25E0, 0x1E, 0, 0.5f, 1.0f);
}
