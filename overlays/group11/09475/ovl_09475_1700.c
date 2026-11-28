#include "common.h"

extern u8 *D_01B0A068;
extern s32 D_01B0A05C;
extern s32 D_01B0A03C;

extern void func_01B039A8(s32, void *, s32);
extern float func_01B03880(s32);

void func_01B01700(void) {
    u8 *s = D_01B0A068;
    float y;

    func_01B039A8(-1, s + 0x820, 0);
    y = func_01B03880(-1);
    *(s32 *)(s + 0xD74) = 0;
    *(float *)(s + 0xD64) = y;
    *(float *)(s + 0xCC4) = 0.0f;
    *(float *)(s + 0xCC0) = 0.0f;
    D_01B0A03C = 1;
    D_01B0A05C = 1;
}
