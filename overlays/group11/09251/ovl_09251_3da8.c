#include "vu0.h"

extern void func_00300280(void);
extern void func_003002C8(void);

void func_01B03DA8(void *dst, void *m1, void *m2)
{
    register void *b __asm__("$16") = m2;
    register void *a __asm__("$17") = m1;
    register void *d __asm__("$18") = dst;
    func_00300280();
    VU0_LQC2(31, 0x0, b);
    VU0_LQC2(27, 0x0, a);
    VU0_LQC2(28, 0x10, a);
    VU0_LQC2(29, 0x20, a);
    VU0_LQC2(30, 0x30, a);
    VU0_OP("vmulax.xyzw ACC, $vf27, $vf31x");
    VU0_OP("vmadday.xyzw ACC, $vf28, $vf31y");
    VU0_OP("vmaddaz.xyzw ACC, $vf29, $vf31z");
    VU0_OP("vmaddw.xyzw $vf26, $vf30, $vf31w");
    VU0_LQC2(31, 0x10, b);
    VU0_SQC2(26, 0x0, d);
    VU0_OP("vmulax.xyzw ACC, $vf27, $vf31x");
    VU0_OP("vmadday.xyzw ACC, $vf28, $vf31y");
    VU0_OP("vmaddaz.xyzw ACC, $vf29, $vf31z");
    VU0_OP("vmaddw.xyzw $vf26, $vf30, $vf31w");
    VU0_LQC2(31, 0x20, b);
    VU0_SQC2(26, 0x10, d);
    VU0_OP("vmulax.xyzw ACC, $vf27, $vf31x");
    VU0_OP("vmadday.xyzw ACC, $vf28, $vf31y");
    VU0_OP("vmaddaz.xyzw ACC, $vf29, $vf31z");
    VU0_OP("vmaddw.xyzw $vf26, $vf30, $vf31w");
    VU0_LQC2(31, 0x30, b);
    VU0_SQC2(26, 0x20, d);
    VU0_OP("vmulax.xyzw ACC, $vf27, $vf31x");
    VU0_OP("vmadday.xyzw ACC, $vf28, $vf31y");
    VU0_OP("vmaddaz.xyzw ACC, $vf29, $vf31z");
    VU0_OP("vmaddw.xyzw $vf26, $vf30, $vf31w");
    VU0_SQC2(26, 0x30, d);
    func_003002C8();
}
