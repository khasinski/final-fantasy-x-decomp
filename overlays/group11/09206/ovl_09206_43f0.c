#include "common.h"

extern u8 *D_01B0C888;

extern void func_01B04078(void);
extern void func_01B06650(s32, s32);
extern void *func_01B07B20(void (*)(void));
extern void func_01B07CE8(void *);

void func_01B043F0(void)
{
    u8 *s0 = D_01B0C888;
    void *t;

    *(s32 *)(s0 + 0x8614) = 0;
    *(s32 *)(s0 + 0x8618) = 0;
    *(s32 *)(s0 + 0x861C) = 0;
    *(s32 *)(s0 + 0x8620) = 0xA0;
    func_01B06650(-1, 1);
    func_01B06650(1, 1);
    *(float *)(s0 + 0xA20) = -0.9424779f;
    *(float *)(s0 + 0xA24) = 0.0f;
    *(float *)(s0 + 0xA28) = 1.5707964f;
    t = func_01B07B20(func_01B04078);
    func_01B07CE8(t);
    *(void **)(s0 + 0x8604) = t;
}
