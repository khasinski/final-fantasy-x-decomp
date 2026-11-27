#include "common.h"

extern s32 D_01B00AB4;
extern float D_01B00B80;
extern s32 D_01B00C48;
extern s32 D_01B00D58;

extern void func_00173720(float *);
extern void func_00173740(int *);

int func_01B018D0(void)
{
    float v[4];
    int c[4];
    float a;
    int cond = 0;

    if (D_01B00AB4 != 0) {
        if (D_01B00C48 >= 176) {
            cond = 1;
        }
    } else {
        if (D_01B00D58 >= 81) {
            cond = 1;
        }
    }
    if (cond != 0) {
        D_01B00B80 += 0.035000002f;
        D_01B00B80 = (D_01B00B80 < 0.30000001192092896f) ? 0.30000001192092896f : ((D_01B00B80 > 1.0f) ? 1.0f : D_01B00B80);
        if (D_01B00B80 == 1.0f) {
            return 0;
        }
    } else {
        D_01B00B80 -= 0.046666666865348816f;
        D_01B00B80 = (D_01B00B80 < 0.30000001192092896f) ? 0.30000001192092896f : ((D_01B00B80 > 1.0f) ? 1.0f : D_01B00B80);
    }
    a = D_01B00B80;
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
