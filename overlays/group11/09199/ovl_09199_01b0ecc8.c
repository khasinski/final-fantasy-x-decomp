#include "common.h"

typedef struct {
    u8 *obj;
    s32 val;
} ArgECC8;

void func_01B0ECC8(ArgECC8 *a)
{
    s32 v = a->val;
    u8 *o = a->obj;
    float f = (float)(v << 15) / 3.1415927f;
    *(u32 *)(o + 0x78) = 0;
    *(float *)(o + 0x7C) = (float)v;
    __asm__("" : : "m"(*(float *)(o + 0x7C)));
    *(float *)(o + 0x8C) = (float)v;
    *(s16 *)(o + 0x94) = (s16)f;
}
