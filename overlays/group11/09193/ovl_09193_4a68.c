/* Shared 09193-family VU0 XZ distance helper (60 B, ~159 containers). */

#include "vu0.h"

float ovl_09193_4a68(void *a, void *b)
{
    float tmp[4];
    /* DEBT(FAKE): pin raw int result to a3 to match original qmfc2/mtc1 reg. */
    register int bits __asm__("a3");
    union { int i; float f; } u;

    VU0_LQC2(1, 0, a);
    VU0_LQC2(2, 0, b);
    VU0_OP("vsub.xyzw $vf1, $vf1, $vf2");
    VU0_SQC2(1, 0, tmp);
    VU0_LQC2(1, 0, tmp);
    VU0_OP("vmul.xz $vf1, $vf1, $vf1");
    VU0_OP("vaddz.x $vf1, $vf1, $vf1");
    VU0_OP("vsqrt Q, $vf1x");
    VU0_OP("vwaitq");
    VU0_OP("vaddq.x $vf1, $vf0, Q");
    VU0_QMFC2(bits, 1);
    /* DEBT(CAST): union bit-cast int -> float for VU0 qmfc2 return value. */
    u.i = bits;
    return u.f;
}
