#include "common.h"

void func_01B078C8(void *a0, void *a1);
void func_002DCF48(void *a0, void *a1);

void func_01B04ED8(u8 *a0)
{
    float m0[4][4];
    float m1[4][4];

    func_01B078C8(m0, m1);
    func_002DCF48(a0 + 0x80, m1);
}
