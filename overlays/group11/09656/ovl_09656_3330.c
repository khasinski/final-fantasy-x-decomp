#include "common.h"

extern u8 *D_01B0A988;
extern float D_01B00984[3];
extern float D_01B009A0[3];

void *func_01B07E50(int a0);
void func_002DCF48(void *a0, void *a1);
void func_002DCE08(void *a0, void *a1, void *a2);

void func_01B03330(void *a0)
{
    float m[4][4];
    u8 *s1 = D_01B0A988;

    func_002DCF48(m, func_01B07E50(0));
    func_002DCE08(a0, m, s1 + 0x2B30);
}

void func_01B03388(void)
{
    float v[4];

    func_01B03330(v);
    D_01B00984[0] = v[0];
    D_01B00984[1] = -50.0f;
    D_01B00984[2] = v[2];
}

void func_01B033C8(void)
{
    float v[4];

    func_01B03330(v);
    D_01B009A0[0] = v[0];
    D_01B009A0[1] = -10.0f;
    D_01B009A0[2] = v[2];
}
