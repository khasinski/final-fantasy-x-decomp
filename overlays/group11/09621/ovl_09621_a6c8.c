#include "vu0.h"

typedef struct {
    u8 *obj;
    s32 flag;
    float f8;
    float fC;
} ArgA6C8;

void func_01B0A6C8(ArgA6C8 *arg)
{
    u8 *a2 = arg->obj;
    *(float *)(a2 + 0x50) = arg->f8;
    *(float *)(a2 + 0x58) = arg->fC;
    if (arg->flag != 0) {
        *(u32 *)(a2 + 0x6C) |= 2;
    } else {
        float *p40 = (float *)(a2 + 0x40);
        float *p30 = (float *)(a2 + 0x30);
        float *p20 = (float *)(a2 + 0x20);
        float d;
        float z;
        *(u32 *)(a2 + 0x6C) &= ~2U;
        VU0_LQC2_INPUTS(31, p30, p20, p40);
        VU0_LQC2(30, 0x0, p20);
        VU0_OP("vsub.xyzw $vf31, $vf31, $vf30");
        VU0_SQC2(31, 0x0, p40);
        d = *(float *)(a2 + 0x64) - *(float *)(a2 + 0x60);
        {
            register float z __asm__("$f2") = 0.0f;
            __asm__("" : "+f"(z));
            *(float *)(a2 + 0x5C) = z;
            *(float *)(a2 + 0x54) = z;
        }
        *(float *)(a2 + 0x68) = d;
    }
    *(u32 *)(a2 + 0x6C) |= 1;
}
