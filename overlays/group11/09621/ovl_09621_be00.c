#include "vu0.h"

typedef struct {
    u8 *obj;
    void *src;
} ArgBE00;

void func_01B0BE00(ArgBE00 *arg)
{
    u8 *v0 = arg->obj + 0x20;
    void *v1 = arg->src;
    VU0_LQC2(31, 0x0, v1);
    VU0_SQC2(31, 0x10, v0);
    VU0_SQC2(31, 0x0, v0);
    __asm__ volatile("nop");
}
