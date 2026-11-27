#include "common.h"

extern u8 *D_01B0A988;

void func_01B04E98(void *a0, void *a1);
void func_002DCE38(void *a0, void *a1, void *a2);
void func_002B7B20(void *a0, void *a1);

void func_01B01BA0(void *a0, void *a1)
{
    float m0[4][4];
    float m1[4][4];
    float m2[4][4];
    u8 *v0;

    func_01B04E98(m1, m2);
    func_002DCE38(m0, m2, a1);
    func_002DCE38(m0, m1, m0);
    v0 = D_01B0A988 + 0x3B80;
    *(void **)(v0 + 0x20) = m0;
    func_002B7B20(a0, v0);
}
