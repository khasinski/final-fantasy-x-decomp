/* Shared P6 -O0 helper (137 instances): VU0 4x4 matrix multiply with lock/unlock. */
#include "p6_overlay.h"

extern void func_00300280(void);
extern void func_003002C8(void);

void func_01B07F98(register void *out, register void *m0, register void *m1)
{
    func_00300280();
    __asm__ volatile(
        ".set noreorder\n\t"
        "lqc2 $vf31, 0(%2)\n\t"
        "lqc2 $vf27, 0(%1)\n\t"
        "lqc2 $vf28, 16(%1)\n\t"
        "lqc2 $vf29, 32(%1)\n\t"
        "lqc2 $vf30, 48(%1)\n\t"
        "vmulax.xyzw ACC, $vf27, $vf31x\n\t"
        "vmadday.xyzw ACC, $vf28, $vf31y\n\t"
        "vmaddaz.xyzw ACC, $vf29, $vf31z\n\t"
        "vmaddw.xyzw $vf26, $vf30, $vf31w\n\t"
        "lqc2 $vf31, 16(%2)\n\t"
        "sqc2 $vf26, 0(%0)\n\t"
        "vmulax.xyzw ACC, $vf27, $vf31x\n\t"
        "vmadday.xyzw ACC, $vf28, $vf31y\n\t"
        "vmaddaz.xyzw ACC, $vf29, $vf31z\n\t"
        "vmaddw.xyzw $vf26, $vf30, $vf31w\n\t"
        "lqc2 $vf31, 32(%2)\n\t"
        "sqc2 $vf26, 16(%0)\n\t"
        "vmulax.xyzw ACC, $vf27, $vf31x\n\t"
        "vmadday.xyzw ACC, $vf28, $vf31y\n\t"
        "vmaddaz.xyzw ACC, $vf29, $vf31z\n\t"
        "vmaddw.xyzw $vf26, $vf30, $vf31w\n\t"
        "lqc2 $vf31, 48(%2)\n\t"
        "sqc2 $vf26, 32(%0)\n\t"
        "vmulax.xyzw ACC, $vf27, $vf31x\n\t"
        "vmadday.xyzw ACC, $vf28, $vf31y\n\t"
        "vmaddaz.xyzw ACC, $vf29, $vf31z\n\t"
        "vmaddw.xyzw $vf26, $vf30, $vf31w\n\t"
        "sqc2 $vf26, 48(%0)\n\t"
        ".set reorder"
        : : "r"(out), "r"(m0), "r"(m1) : "memory");
    func_003002C8();
}
