#include "common.h"

extern u8 *D_01B0BC98;

void *func_01B09058(int a0);
void func_002DCF48(void *a0, void *a1);
void func_002DCE08(void *a0, void *a1, void *a2);

void func_01B044F8(void *a0)
{
    float m[4][4];
    u8 *s1 = D_01B0BC98;

    func_002DCF48(m, func_01B09058(0));
    func_002DCE08(a0, m, s1 + 0x2B30);
}
