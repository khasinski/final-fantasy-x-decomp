#include "common.h"

extern int func_001A81E8(s32, float);

typedef struct {
    u8 *obj;
    float f4;
    float f8;
    u32 uC;
} ArgC1C0;

void func_01B0C1C0(ArgC1C0 *arg) {
    u8 *v1 = arg->obj;
    float f;
    float f4;

    if (arg->uC < 2) {
        *(float *)(v1 + 0xEC) = 1.0f;
        f = *(float *)(v1 + 0x68);
        *(float *)(v1 + 0xFC) = arg->f8;
        f4 = arg->f4;
        *(float *)(v1 + 0xCC) = f4;
        *(float *)(v1 + 0xDC) = f - f4;
        *(u16 *)(v1 + 0x9C) = (u16)arg->uC;
        {
            int r = func_001A81E8(*(s32 *)(v1 + 0x134), f);
            __asm__("" : : "r"(r));
        }
    }
}
