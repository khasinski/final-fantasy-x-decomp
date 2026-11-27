#include "common.h"

extern s32 D_01B00F6C;
extern float D_01B00FE0;
extern s32 D_01B011EC;
extern s32 D_01B011F8;

extern void func_00173720(float *);
extern void func_00173740(int *);

int func_01B02F08(void)
{
    float v[4];
    int c[4];
    float a;

    if (D_01B011EC > 0 || (D_01B00F6C != 0 && D_01B011F8 >= 221)) {
        D_01B00FE0 += 0.01f;
        D_01B00FE0 = (D_01B00FE0 < 0.80000004f) ? 0.80000004f : ((D_01B00FE0 > 1.0f) ? 1.0f : D_01B00FE0);
        if (D_01B00FE0 == 1.0f) {
            return 0;
        }
    } else {
        D_01B00FE0 -= 0.013333333f;
        D_01B00FE0 = (D_01B00FE0 < 0.80000004f) ? 0.80000004f : ((D_01B00FE0 > 1.0f) ? 1.0f : D_01B00FE0);
    }
    a = D_01B00FE0;
    c[1] = 0x80;
    c[2] = 0x80;
    c[3] = 0x80;
    v[0] = a;
    v[1] = a;
    v[2] = a;
    v[3] = a;
    c[0] = (int)((1.0f - a) * 128.0f + 128.0f);
    func_00173720(v);
    func_00173740(c);
    return 1;
}
