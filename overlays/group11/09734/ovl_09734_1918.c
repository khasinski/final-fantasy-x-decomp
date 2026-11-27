#include "common.h"

extern float D_01B00A80;
extern s32 D_01B00AA8;

extern void func_00173A70(int);
extern void func_00173720(float *);
extern void func_00173740(int *);

int func_01B01918(void)
{
    func_00173A70(4);
    D_01B00A80 = 1.0f;
    return 1;
}

int func_01B01948(void)
{
    float v[4];
    int c[4];
    float a;

    if (D_01B00AA8 >= 176) {
        D_01B00A80 += 0.035000002f;
        D_01B00A80 = (D_01B00A80 < 0.30000001192092896f) ? 0.30000001192092896f : ((D_01B00A80 > 1.0f) ? 1.0f : D_01B00A80);
        if (D_01B00A80 == 1.0f) {
            return 0;
        }
    } else {
        D_01B00A80 -= 0.046666666865348816f;
        D_01B00A80 = (D_01B00A80 < 0.30000001192092896f) ? 0.30000001192092896f : ((D_01B00A80 > 1.0f) ? 1.0f : D_01B00A80);
    }
    a = D_01B00A80;
    v[0] = a;
    v[1] = a;
    v[2] = a;
    v[3] = a;
    c[0] = 0x80;
    c[1] = 0x80;
    c[2] = 0x80;
    c[3] = 0x80;
    func_00173720(v);
    func_00173740(c);
    return 1;
}
