#include "common.h"

extern int D_01B00350;
extern float D_01B0034C;
extern u8 D_01B0A630[];
extern void func_01B0DDE0(void *, int, int, int, u32, float, float, float, float);

int func_01B0AD88(void)
{
    if (D_01B00350 == 0) {
        D_01B0034C += 0.033333337f;
        if (D_01B0034C > 1.0f) {
            D_01B0034C = 1.0f;
        }
    } else {
        D_01B0034C -= 0.033333337f;
        if (D_01B0034C < 0.0f) {
            D_01B0034C = 0.0f;
        }
    }
    func_01B0DDE0(D_01B0A630, 0, 0, 0, (u32)(D_01B0034C * 64.0f), -1.0f, -1.0f, 1.0f, 1.0f);
    if (D_01B0034C == 0.0f) {
        return 0;
    }
    return 1;
}
