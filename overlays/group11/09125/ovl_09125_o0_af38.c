/* Shared P6 -O0 helper (117 instances): VU0 scalar sqrtf. */
#include "p6_overlay.h"

float func_01B0AF38(register float x)
{
    float buf[4];

    buf[1] = x;
    __asm__ volatile(
        "lqc2 $vf10, 0(%1)\n\t"
        ".word 0x4A8A03BD\n\t"
        "vwaitq\n\t"
        "cfc2 $2, $vi22\n\t"
        "mtc1 $2, %0"
        : "=f"(x)
        : "r"(buf)
        : "$2");
    return x;
}
