/* Shared P6 -O0 helper: VU0 vec3 add (64B, -O0). */
#include "p6_overlay.h"

void func_01B08068(register float *v0, register float *v1, register float *v2)
{
    __asm__ volatile (
        "lqc2    $vf1, 0x0(%1)\n\t"
        "lqc2    $vf2, 0x0(%2)\n\t"
        "lqc2    $vf3, 0x0(%0)\n\t"
        "vadd.xyz $vf3, $vf1, $vf2\n\t"
        "sqc2    $vf3, 0x0(%0)\n\t"
        :
        : "r"(v0), "r"(v1), "r"(v2)
        : "memory"
    );
}
