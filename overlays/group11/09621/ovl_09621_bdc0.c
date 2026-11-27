#include "vu0.h"

typedef struct {
    u8 *obj;
    void *src;
} ArgBDC0;

void func_01B0BDC0(ArgBDC0 *arg)
{
    u8 *v0 = arg->obj + 0x20;
    void *v1 = arg->src;
    VU0_LQC2(31, 0x0, v1);
    VU0_SQC2(31, 0x20, v0);
    VU0_SQC2(31, 0x30, v0);
    __asm__ volatile("nop");
}
