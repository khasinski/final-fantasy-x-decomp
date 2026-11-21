/* Shared P6 -O0 helper (118 instances): VU0 3-component vector scale. */
#include "p6_overlay.h"

void func_01B09888(register void *dst, register void *src, register float s)
{
    __asm__ volatile(
        "lqc2 $vf31, 0(%1)\n\t"
        "lqc2 $vf29, 0(%0)\n\t"
        "mfc1 $2, %2\n\t"
        "qmtc2 $2, $vf30\n\t"
        "vmulx.xyz $vf29, $vf31, $vf30x\n\t"
        "sqc2 $vf29, 0(%0)"
        : : "r"(dst), "r"(src), "f"(s) : "$2", "memory");
}
