/* Shared P6 -O0 helper: VU0 3-component vector length. */
#include "p6_overlay.h"

float func_01B05540(register void *v)
{
    float res;

    __asm__ volatile(
        "lqc2 $vf31, 0(%1)\n\t"
        "vmul.xyz $vf31, $vf31, $vf31\n\t"
        "vaddy.x $vf31, $vf31, $vf31y\n\t"
        "vaddz.x $vf31, $vf31, $vf31z\n\t"
        ".word 0x4A1F03BD\n\t"
        "vwaitq\n\t"
        "vaddq.x $vf31, $vf0, Q\n\t"
        "qmfc2 $2, $vf31\n\t"
        "mtc1 $2, %0"
        : "=f"(res)
        : "r"(v)
        : "$2");
    return res;
}
