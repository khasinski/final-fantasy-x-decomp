#include "common.h"

extern float D_01B00A90;
extern s32 D_01B00AB8;

extern void func_00173720(float *);
extern void func_00173740(int *);

int func_01B019B0(void)
{
    float v[4];
    int c[4];
    float a;

    if (D_01B00AB8 >= 176) {
        D_01B00A90 += 0.035000002f;
        D_01B00A90 = (D_01B00A90 < 0.30000001192092896f) ? 0.30000001192092896f : ((D_01B00A90 > 1.0f) ? 1.0f : D_01B00A90);
        if (D_01B00A90 == 1.0f) {
            return 0;
        }
    } else {
        D_01B00A90 -= 0.046666666865348816f;
        D_01B00A90 = (D_01B00A90 < 0.30000001192092896f) ? 0.30000001192092896f : ((D_01B00A90 > 1.0f) ? 1.0f : D_01B00A90);
    }
    a = D_01B00A90;
    c[0] = 0x80;
    c[1] = 0x80;
    c[2] = 0x80;
    c[3] = 0x80;
    v[0] = a;
    v[1] = a;
    v[2] = a;
    v[3] = a;
    func_00173720(v);
    func_00173740(c);
    return 1;
}
