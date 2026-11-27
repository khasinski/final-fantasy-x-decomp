#include "common.h"

extern u8 *D_01B0A1E0;

float func_002B3DB0(float a0);
void func_01B05138(int a0, void *a1, void *a2);
void func_002DD128(void *a0);
void func_002DD318(void *a0, void *a1, float a2);
void func_002DCE38(void *a0, void *a1, void *a2);

void func_01B026A0(void)
{
    float m[4][4];
    u8 *s0 = D_01B0A1E0;
    u8 *s1 = s0 + 0x980;
    u8 *v0;
    float *p;
    float ang;
    int h;

    *(float *)(s0 + 0xA90) -= *(float *)(s0 + 0xA80);
    *(float *)(s0 + 0xA98) -= *(float *)(s0 + 0xA88);
    *(float *)(s0 + 0xA50) = *(float *)(s0 + 0xA90) + func_002B3DB0(0.1f);
    *(float *)(s0 + 0xA58) = *(float *)(s0 + 0xA98) + func_002B3DB0(0.1f);
    func_01B05138(-1, s1, s0 + 0xA40);
    p = (float *)(s0 + 0xA84);
    {
        float step = 0.062831856f;
        ang = *(float *)(s0 + 0xA84) + step;
    }
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    *p = ang;
    func_002DD128(m);
    func_002DD318(m, m, *(float *)(s0 + 0xA84));
    func_002DCE38(s1, s1, m);
    v0 = s0 + 0x5F0;
    *(float *)(v0 + 0xD0) -= *(float *)(s0 + 0xA94);
    *(float *)(v0 + 0xD8) -= *(float *)(s0 + 0xA9C);
    h = *(u16 *)(v0 + 0x74) - 0x11;
    *(u16 *)(v0 + 0x74) = h;
    *(u16 *)(v0 + 0x72) = h;
    *(u16 *)(v0 + 0x70) = h;
}
