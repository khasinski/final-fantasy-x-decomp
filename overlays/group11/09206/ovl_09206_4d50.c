#include "common.h"

extern u8 D_01B0C700[];
extern u8 *D_01B0C888;

extern void func_00118098(s32, s32);
extern void func_01B082F0(void *, void *);

void func_01B04D50(void)
{
    u8 *s2 = D_01B0C888;
    u8 *s0 = s2 + 0x4C0;
    s32 i;

    *(float *)(s2 + 0x9C4) -= 30.0f;
    for (i = 0; i < 3; i++) {
        func_01B082F0(D_01B0C700, s0);
        s0 += 0x130;
    }
    *(s32 *)(s2 + 0x8624) = 0x14;
    func_00118098(0, 0x10000);
    func_00118098(1, 0x8000);
}
