#include "common.h"
#include "vu0.h"

extern void func_00300280(void);
extern void func_003002C8(void);

void func_01B118E0(void *dst, void *m1, void *m2) {
    register void *r_dst __asm__("$18") = dst;
    register void *r_m1 __asm__("$17") = m1;
    register void *r_m2 __asm__("$16") = m2;

    func_00300280();
    VU0_LQC2(31, 0, r_m2);
    VU0_LQC2(27, 0, r_m1);
    VU0_LQC2(28, 16, r_m1);
    VU0_LQC2(29, 32, r_m1);
    VU0_LQC2(30, 48, r_m1);
    VU0_OP("vmulax.xyzw ACC, $vf27, $vf31x");
    VU0_OP("vmadday.xyzw ACC, $vf28, $vf31y");
    VU0_OP("vmaddaz.xyzw ACC, $vf29, $vf31z");
    VU0_OP("vmaddw.xyzw $vf26, $vf30, $vf31w");
    VU0_LQC2(31, 16, r_m2);
    VU0_SQC2(26, 0, r_dst);
    VU0_OP("vmulax.xyzw ACC, $vf27, $vf31x");
    VU0_OP("vmadday.xyzw ACC, $vf28, $vf31y");
    VU0_OP("vmaddaz.xyzw ACC, $vf29, $vf31z");
    VU0_OP("vmaddw.xyzw $vf26, $vf30, $vf31w");
    VU0_LQC2(31, 32, r_m2);
    VU0_SQC2(26, 16, r_dst);
    VU0_OP("vmulax.xyzw ACC, $vf27, $vf31x");
    VU0_OP("vmadday.xyzw ACC, $vf28, $vf31y");
    VU0_OP("vmaddaz.xyzw ACC, $vf29, $vf31z");
    VU0_OP("vmaddw.xyzw $vf26, $vf30, $vf31w");
    VU0_LQC2(31, 48, r_m2);
    VU0_SQC2(26, 32, r_dst);
    VU0_OP("vmulax.xyzw ACC, $vf27, $vf31x");
    VU0_OP("vmadday.xyzw ACC, $vf28, $vf31y");
    VU0_OP("vmaddaz.xyzw ACC, $vf29, $vf31z");
    VU0_OP("vmaddw.xyzw $vf26, $vf30, $vf31w");
    VU0_SQC2(26, 48, r_dst);
    func_003002C8();
}
