#include "common.h"

extern u8 *D_01B0B1F8;
extern s32 D_01B0B200;

extern s32 func_002B7B20(void *, void *);
extern void func_002DCE38(void *, void *, void *);
extern void func_01B05768(void *, void *);

void func_01B01AE0(void *a0, void *a1)
{
    float m0[4][4];
    float m1[4][4];
    float m2[4][4];
    u8 *v0;

    func_01B05768(m1, m2);
    func_002DCE38(m0, m2, a1);
    func_002DCE38(m0, m1, m0);
    v0 = D_01B0B1F8 + 0x3100;
    *(s32 *)(v0 + 0x34) = D_01B0B200;
    *(void **)(v0 + 0x20) = m0;
    *(s32 *)(v0 + 0x44) = 0;
    D_01B0B200 = func_002B7B20(a0, v0);
}
