/* tu_330 0x2b4ff8-0x2b6b50: low; ~op (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: resource loader wrappers (see w10.h). */
#include "common.h"
#include "vu0.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w10.h"

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B4FF8);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B50E0);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_rot_m_z);

void func_002B52C0(void *a, void *b, void *c)
{
    __asm__ volatile(
        ".set noreorder\n"
        "qmtc2.ni   $31, $vf7\n"
        "qmtc2.ni   $4, $vf4\n"
        "qmtc2.ni   $5, $vf5\n"
        "qmtc2.ni   $6, $vf6\n"
        "qmfc2.ni   $6, $vf6\n"
        "qmfc2.ni   $5, $vf5\n"
        "qmfc2.ni   $4, $vf4\n"
        "jal        op_rot_m_z\n"
        " lwc1      $f12, 0x8($6)\n"
        "qmfc2.ni   $6, $vf6\n"
        "qmfc2.ni   $5, $vf4\n"
        "qmfc2.ni   $4, $vf4\n"
        "jal        func_002B50E0\n"
        " lwc1      $f12, 0x4($6)\n"
        "qmfc2.ni   $6, $vf6\n"
        "qmfc2.ni   $5, $vf4\n"
        "qmfc2.ni   $4, $vf4\n"
        "jal        func_002B4FF8\n"
        " lwc1      $f12, 0x0($6)\n"
        "qmfc2.ni   $31, $vf7\n"
        ".set reorder\n"
        : : "r"(a), "r"(b), "r"(c));
}

void func_002B5318(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        "lqc2       $vf31, 0x0($6)\n"
        "lqc2       $vf30, 0x30($5)\n"
        "lq         $7, 0x0($5)\n"
        "lq         $8, 0x10($5)\n"
        "lq         $9, 0x20($5)\n"
        "vadd.xyz   $vf30, $vf30, $vf31\n"
        "sq         $7, 0x0($4)\n"
        "sq         $8, 0x10($4)\n"
        "sq         $9, 0x20($4)\n"
        "sqc2      $vf30, 0x30($4)\n"
        :  : "r"(a0), "r"(a1), "r"(a2) : "$7", "$8", "$9");
}

void func_002B5348(void *a, void *b, void *c, void *d)
{
    __asm__ volatile(
        ".set noreorder\n"
        "qmtc2.ni   $31, $vf3\n"
        "qmtc2.ni   $4, $vf4\n"
        "qmtc2.ni   $5, $vf5\n"
        "qmtc2.ni   $6, $vf6\n"
        "lqc2       $vf7, 0x0($7)\n"
        "qmfc2.ni   $6, $vf6\n"
        "qmfc2.ni   $5, $vf5\n"
        "qmfc2.ni   $4, $vf4\n"
        "jal        op_rot_m_z\n"
        " lwc1      $f12, 0x8($6)\n"
        "qmfc2.ni   $6, $vf6\n"
        "qmfc2.ni   $5, $vf4\n"
        "qmfc2.ni   $4, $vf4\n"
        "jal        func_002B50E0\n"
        " lwc1      $f12, 0x4($6)\n"
        "qmfc2.ni   $6, $vf6\n"
        "qmfc2.ni   $5, $vf4\n"
        "qmfc2.ni   $4, $vf4\n"
        "jal        func_002B4FF8\n"
        " lwc1      $f12, 0x0($6)\n"
        "qmfc2.ni   $4, $vf4\n"
        "lqc2       $vf30, 0x30($4)\n"
        "lq         $5, 0x0($4)\n"
        "lq         $6, 0x10($4)\n"
        "lq         $7, 0x20($4)\n"
        "vadd.xyz   $vf30, $vf30, $vf7\n"
        "sq         $5, 0x0($4)\n"
        "sq         $6, 0x10($4)\n"
        "sq         $7, 0x20($4)\n"
        "sqc2       $vf30, 0x30($4)\n"
        "qmfc2.ni   $31, $vf3\n"
        ".set reorder\n"
        : : "r"(a), "r"(b), "r"(c), "r"(d));
}

void func_002B53D0(void *a, void *b, void *c, void *d)
{
    __asm__ volatile(
        ".set noreorder\n"
        "qmtc2.ni   $31, $vf3\n"
        "qmtc2.ni   $4, $vf4\n"
        "qmtc2.ni   $5, $vf5\n"
        "qmtc2.ni   $6, $vf6\n"
        "lqc2       $vf7, 0x0($7)\n"
        "qmfc2.ni   $6, $vf6\n"
        "qmfc2.ni   $5, $vf5\n"
        "qmfc2.ni   $4, $vf4\n"
        "jal        op_rot_m_z\n"
        " lwc1      $f12, 0x8($6)\n"
        "qmfc2.ni   $6, $vf6\n"
        "qmfc2.ni   $5, $vf4\n"
        "qmfc2.ni   $4, $vf4\n"
        "jal        func_002B4FF8\n"
        " lwc1      $f12, 0x0($6)\n"
        "qmfc2.ni   $6, $vf6\n"
        "qmfc2.ni   $5, $vf4\n"
        "qmfc2.ni   $4, $vf4\n"
        "jal        func_002B50E0\n"
        " lwc1      $f12, 0x4($6)\n"
        "qmfc2.ni   $4, $vf4\n"
        "lqc2       $vf30, 0x30($4)\n"
        "lq         $5, 0x0($4)\n"
        "lq         $6, 0x10($4)\n"
        "lq         $7, 0x20($4)\n"
        "vadd.xyz   $vf30, $vf30, $vf7\n"
        "sq         $5, 0x0($4)\n"
        "sq         $6, 0x10($4)\n"
        "sq         $7, 0x20($4)\n"
        "sqc2       $vf30, 0x30($4)\n"
        "qmfc2.ni   $31, $vf3\n"
        ".set reorder\n"
        : : "r"(a), "r"(b), "r"(c), "r"(d));
}

void func_002B5458(void *a, void *b, void *c, void *d)
{
    __asm__ volatile(
        ".set noreorder\n"
        "qmtc2.ni   $31, $vf3\n"
        "qmtc2.ni   $4, $vf4\n"
        "qmtc2.ni   $5, $vf5\n"
        "qmtc2.ni   $6, $vf6\n"
        "lqc2       $vf7, 0x0($7)\n"
        "qmfc2.ni   $6, $vf6\n"
        "qmfc2.ni   $5, $vf5\n"
        "qmfc2.ni   $4, $vf4\n"
        "jal        func_002B50E0\n"
        " lwc1      $f12, 0x4($6)\n"
        "qmfc2.ni   $6, $vf6\n"
        "qmfc2.ni   $5, $vf4\n"
        "qmfc2.ni   $4, $vf4\n"
        "jal        op_rot_m_z\n"
        " lwc1      $f12, 0x8($6)\n"
        "qmfc2.ni   $6, $vf6\n"
        "qmfc2.ni   $5, $vf4\n"
        "qmfc2.ni   $4, $vf4\n"
        "jal        func_002B4FF8\n"
        " lwc1      $f12, 0x0($6)\n"
        "qmfc2.ni   $4, $vf4\n"
        "lqc2       $vf30, 0x30($4)\n"
        "lq         $5, 0x0($4)\n"
        "lq         $6, 0x10($4)\n"
        "lq         $7, 0x20($4)\n"
        "vadd.xyz   $vf30, $vf30, $vf7\n"
        "sq         $5, 0x0($4)\n"
        "sq         $6, 0x10($4)\n"
        "sq         $7, 0x20($4)\n"
        "sqc2       $vf30, 0x30($4)\n"
        "qmfc2.ni   $31, $vf3\n"
        ".set reorder\n"
        : : "r"(a), "r"(b), "r"(c), "r"(d));
}

void op_rt_m_yxz(void *a, void *b, void *c, void *d)
{
    __asm__ volatile(
        ".set noreorder\n"
        "qmtc2.ni   $31, $vf3\n"
        "qmtc2.ni   $4, $vf4\n"
        "qmtc2.ni   $5, $vf5\n"
        "qmtc2.ni   $6, $vf6\n"
        "lqc2       $vf7, 0x0($7)\n"
        "qmfc2.ni   $6, $vf6\n"
        "qmfc2.ni   $5, $vf5\n"
        "qmfc2.ni   $4, $vf4\n"
        "jal        func_002B50E0\n"
        " lwc1      $f12, 0x4($6)\n"
        "qmfc2.ni   $6, $vf6\n"
        "qmfc2.ni   $5, $vf4\n"
        "qmfc2.ni   $4, $vf4\n"
        "jal        func_002B4FF8\n"
        " lwc1      $f12, 0x0($6)\n"
        "qmfc2.ni   $6, $vf6\n"
        "qmfc2.ni   $5, $vf4\n"
        "qmfc2.ni   $4, $vf4\n"
        "jal        op_rot_m_z\n"
        " lwc1      $f12, 0x8($6)\n"
        "qmfc2.ni   $4, $vf4\n"
        "lqc2       $vf30, 0x30($4)\n"
        "lq         $5, 0x0($4)\n"
        "lq         $6, 0x10($4)\n"
        "lq         $7, 0x20($4)\n"
        "vadd.xyz   $vf30, $vf30, $vf7\n"
        "sq         $5, 0x0($4)\n"
        "sq         $6, 0x10($4)\n"
        "sq         $7, 0x20($4)\n"
        "sqc2       $vf30, 0x30($4)\n"
        "qmfc2.ni   $31, $vf3\n"
        ".set reorder\n"
        : : "r"(a), "r"(b), "r"(c), "r"(d));
}

void func_002B5568(void *a, void *b, void *c, void *d)
{
    __asm__ volatile(
        ".set noreorder\n"
        "qmtc2.ni   $31, $vf3\n"
        "qmtc2.ni   $4, $vf4\n"
        "qmtc2.ni   $5, $vf5\n"
        "qmtc2.ni   $6, $vf6\n"
        "lqc2       $vf7, 0x0($7)\n"
        "qmfc2.ni   $6, $vf6\n"
        "qmfc2.ni   $5, $vf5\n"
        "qmfc2.ni   $4, $vf4\n"
        "jal        func_002B4FF8\n"
        " lwc1      $f12, 0x0($6)\n"
        "qmfc2.ni   $6, $vf6\n"
        "qmfc2.ni   $5, $vf4\n"
        "qmfc2.ni   $4, $vf4\n"
        "jal        op_rot_m_z\n"
        " lwc1      $f12, 0x8($6)\n"
        "qmfc2.ni   $6, $vf6\n"
        "qmfc2.ni   $5, $vf4\n"
        "qmfc2.ni   $4, $vf4\n"
        "jal        func_002B50E0\n"
        " lwc1      $f12, 0x4($6)\n"
        "qmfc2.ni   $4, $vf4\n"
        "lqc2       $vf30, 0x30($4)\n"
        "lq         $5, 0x0($4)\n"
        "lq         $6, 0x10($4)\n"
        "lq         $7, 0x20($4)\n"
        "vadd.xyz   $vf30, $vf30, $vf7\n"
        "sq         $5, 0x0($4)\n"
        "sq         $6, 0x10($4)\n"
        "sq         $7, 0x20($4)\n"
        "sqc2       $vf30, 0x30($4)\n"
        "qmfc2.ni   $31, $vf3\n"
        ".set reorder\n"
        : : "r"(a), "r"(b), "r"(c), "r"(d));
}

void func_002B55F0(void *a, void *b, void *c, void *d)
{
    __asm__ volatile(
        ".set noreorder\n"
        "qmtc2.ni   $31, $vf3\n"
        "qmtc2.ni   $4, $vf4\n"
        "qmtc2.ni   $5, $vf5\n"
        "qmtc2.ni   $6, $vf6\n"
        "lqc2       $vf7, 0x0($7)\n"
        "qmfc2.ni   $6, $vf6\n"
        "qmfc2.ni   $5, $vf5\n"
        "qmfc2.ni   $4, $vf4\n"
        "jal        func_002B4FF8\n"
        " lwc1      $f12, 0x0($6)\n"
        "qmfc2.ni   $6, $vf6\n"
        "qmfc2.ni   $5, $vf4\n"
        "qmfc2.ni   $4, $vf4\n"
        "jal        func_002B50E0\n"
        " lwc1      $f12, 0x4($6)\n"
        "qmfc2.ni   $6, $vf6\n"
        "qmfc2.ni   $5, $vf4\n"
        "qmfc2.ni   $4, $vf4\n"
        "jal        op_rot_m_z\n"
        " lwc1      $f12, 0x8($6)\n"
        "qmfc2.ni   $4, $vf4\n"
        "lqc2       $vf30, 0x30($4)\n"
        "lq         $5, 0x0($4)\n"
        "lq         $6, 0x10($4)\n"
        "lq         $7, 0x20($4)\n"
        "vadd.xyz   $vf30, $vf30, $vf7\n"
        "sq         $5, 0x0($4)\n"
        "sq         $6, 0x10($4)\n"
        "sq         $7, 0x20($4)\n"
        "sqc2       $vf30, 0x30($4)\n"
        "qmfc2.ni   $31, $vf3\n"
        ".set reorder\n"
        : : "r"(a), "r"(b), "r"(c), "r"(d));
}

void op_rt_m_6(void *a, void *b, void *c, void *d, int sel)
{
    switch (sel) {
    case 0:
        func_002B5348(a, b, c, d);
        break;
    case 1:
        func_002B53D0(a, b, c, d);
        break;
    case 2:
        func_002B5458(a, b, c, d);
        break;
    case 3:
        op_rt_m_yxz(a, b, c, d);
        break;
    case 4:
        func_002B5568(a, b, c, d);
        break;
    case 5:
        func_002B55F0(a, b, c, d);
        break;
    }
}

void func_002B56D8(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        "lqc2       $vf28, 0x0($5)\n"
        "lqc2       $vf29, 0x10($5)\n"
        "lqc2       $vf30, 0x20($5)\n"
        "lqc2       $vf31, 0x30($5)\n"
        "lqc2       $vf24, 0x0($6)\n"
        "lqc2       $vf25, 0x10($6)\n"
        "lqc2       $vf26, 0x20($6)\n"
        "lqc2       $vf27, 0x30($6)\n"
        "vmulax.xyzw ACC, $vf28, $vf24x\n"
        "vmadday.xyzw ACC, $vf29, $vf24y\n"
        "vmaddaz.xyzw ACC, $vf30, $vf24z\n"
        "vmaddw.xyzw $vf24, $vf31, $vf24w\n"
        "vmulax.xyzw ACC, $vf28, $vf25x\n"
        "vmadday.xyzw ACC, $vf29, $vf25y\n"
        "vmaddaz.xyzw ACC, $vf30, $vf25z\n"
        "vmaddw.xyzw $vf25, $vf31, $vf25w\n"
        "vmulax.xyzw ACC, $vf28, $vf26x\n"
        "vmadday.xyzw ACC, $vf29, $vf26y\n"
        "vmaddaz.xyzw ACC, $vf30, $vf26z\n"
        "vmaddw.xyzw $vf26, $vf31, $vf26w\n"
        "vmulax.xyzw ACC, $vf28, $vf27x\n"
        "vmadday.xyzw ACC, $vf29, $vf27y\n"
        "vmaddaz.xyzw ACC, $vf30, $vf27z\n"
        "vmaddw.xyzw $vf27, $vf31, $vf27w\n"
        "sqc2       $vf24, 0x0($4)\n"
        "sqc2       $vf25, 0x10($4)\n"
        "sqc2       $vf26, 0x20($4)\n"
        "sqc2      $vf27, 0x30($4)\n"
        :  : "r"(a0), "r"(a1), "r"(a2));
}

void func_002B5750(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        "lqc2       $vf28, 0x0($5)\n"
        "lqc2       $vf29, 0x10($5)\n"
        "lqc2       $vf30, 0x20($5)\n"
        "lqc2       $vf24, 0x0($6)\n"
        "lqc2       $vf25, 0x10($6)\n"
        "lqc2       $vf26, 0x20($6)\n"
        "lqc2       $vf27, 0x30($6)\n"
        "vmulax.xyzw ACC, $vf28, $vf24x\n"
        "vmadday.xyzw ACC, $vf29, $vf24y\n"
        "vmaddz.xyzw $vf24, $vf30, $vf24z\n"
        "vmulax.xyzw ACC, $vf28, $vf25x\n"
        "vmadday.xyzw ACC, $vf29, $vf25y\n"
        "vmaddz.xyzw $vf25, $vf30, $vf25z\n"
        "vmulax.xyzw ACC, $vf28, $vf26x\n"
        "vmadday.xyzw ACC, $vf29, $vf26y\n"
        "vmaddz.xyzw $vf26, $vf30, $vf26z\n"
        "sqc2       $vf24, 0x0($4)\n"
        "sqc2       $vf25, 0x10($4)\n"
        "sqc2       $vf26, 0x20($4)\n"
        "sqc2      $vf27, 0x30($4)\n"
        :  : "r"(a0), "r"(a1), "r"(a2));
}

void op_unit_m(float *m)
{
    int one = 0x3F800000;

    MMI_SQ_ZERO(0x0, m);
    MMI_SQ_ZERO(0x10, m);
    MMI_SQ_ZERO(0x20, m);
    MMI_SQ_ZERO(0x30, m);
    ((int *)m)[5] = one;
    ((int *)m)[10] = one;
    ((int *)m)[15] = one;
    ((int *)m)[0] = one;
}

/* DEBT(FAKE) */
void op_unit_m_scale(float *m, float a)
{
    register int one __asm__("$2") = 0x3F800000;
    __asm__ volatile("" : "+r"(one));
    MMI_SQ_ZERO(0x0, m);
    MMI_SQ_ZERO(0x10, m);
    MMI_SQ_ZERO(0x20, m);
    MMI_SQ_ZERO(0x30, m);
    m[5] = a;
    m[10] = a;
    m[0] = a;
    __asm__ volatile("" : : : "memory");
    ((int *)m)[15] = one;
}

/* DEBT(FAKE) */
void op_unit_m_scale2(int *m, int *s)
{
    register int one __asm__("$2") = 0x3F800000;
    register int s0 __asm__("$8");
    register int s1 __asm__("$9");
    register int s2 __asm__("$10");
    __asm__ volatile("" : "+r"(one));
    s1 = s[1];
    s2 = s[2];
    s0 = s[0];
    __asm__ volatile("" : "+r"(s0), "+r"(s1), "+r"(s2));
    MMI_SQ_ZERO(0x0, m);
    MMI_SQ_ZERO(0x10, m);
    MMI_SQ_ZERO(0x20, m);
    MMI_SQ_ZERO(0x30, m);
    m[5] = s1;
    m[10] = s2;
    m[15] = one;
    m[0] = s0;
}

void op_m_copy(void *dst_, void *src_)
{
    volatile u_long128 *dst = dst_, *src = src_;
    u_long128 a = src[0], b = src[1], c = src[2], d = src[3];
    dst[0] = a;
    dst[1] = b;
    dst[2] = c;
    dst[3] = d;
}

void func_002B5858(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        "lqc2       $vf27, 0x0($6)\n"
        "lqc2       $vf28, 0x0($5)\n"
        "lqc2       $vf29, 0x10($5)\n"
        "lqc2       $vf30, 0x20($5)\n"
        "vmulax.xyzw ACC, $vf28, $vf27x\n"
        "vmadday.xyzw ACC, $vf29, $vf27y\n"
        "vmaddz.xyzw $vf26, $vf30, $vf27z\n"
        "sqc2      $vf26, 0x0($4)\n"
        :  : "r"(a0), "r"(a1), "r"(a2));
}

void func_002B5880(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        "lqc2       $vf27, 0x0($6)\n"
        "lqc2       $vf28, 0x0($5)\n"
        "lqc2       $vf29, 0x10($5)\n"
        "lqc2       $vf30, 0x20($5)\n"
        "lqc2       $vf31, 0x30($5)\n"
        "vmulax.xyzw ACC, $vf28, $vf27x\n"
        "vmadday.xyzw ACC, $vf29, $vf27y\n"
        "vmaddaz.xyzw ACC, $vf30, $vf27z\n"
        "vmaddw.xyzw $vf26, $vf31, $vf0w\n"
        "sqc2      $vf26, 0x0($4)\n"
        :  : "r"(a0), "r"(a1), "r"(a2));
}

void func_002B58B0(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        "lqc2       $vf27, 0x0($6)\n"
        "lqc2       $vf28, 0x0($5)\n"
        "lqc2       $vf29, 0x10($5)\n"
        "lqc2       $vf30, 0x20($5)\n"
        "lqc2       $vf31, 0x30($5)\n"
        "vmulax.xyzw ACC, $vf28, $vf27x\n"
        "vmadday.xyzw ACC, $vf29, $vf27y\n"
        "vmaddaz.xyzw ACC, $vf30, $vf27z\n"
        "vmaddw.xyzw $vf26, $vf31, $vf0w\n"
        "vdiv       Q, $vf0w, $vf26w\n"
        "vwaitq\n"
        "vmulq.xyz  $vf26, $vf26, Q\n"
        "vftoi4.xyzw $vf27, $vf26\n"
        "sqc2      $vf27, 0x0($4)\n"
        :  : "r"(a0), "r"(a1), "r"(a2));
}

void func_002B58F0(u32 a0, u32 a1)
{
    __asm__ volatile(
        "lqc2       $vf31, 0x0($5)\n"
        "vmul.xyz   $vf28, $vf31, $vf31\n"
        "vaddy.x    $vf28, $vf28, $vf28y\n"
        "vaddz.x    $vf28, $vf28, $vf28z\n"
        ".word      0x4A1C03BD                    # vsqrt      Q, $vf28x # 00000000 <InstrIdType: R5900_COP2_SPECIAL2>\n"
        "vwaitq\n"
        "vaddq.x    $vf28, $vf0, Q\n"
        "vdiv       Q, $vf0w, $vf28x\n"
        "vwaitq\n"
        "vmulq.xyz  $vf31, $vf31, Q\n"
        "sqc2       $vf31, 0x0($4)\n"
        "lqc2       $vf31, 0x10($5)\n"
        "vmul.xyz   $vf28, $vf31, $vf31\n"
        "vaddy.x    $vf28, $vf28, $vf28y\n"
        "vaddz.x    $vf28, $vf28, $vf28z\n"
        ".word      0x4A1C03BD                    # vsqrt      Q, $vf28x # 00000000 <InstrIdType: R5900_COP2_SPECIAL2>\n"
        "vwaitq\n"
        "vaddq.x    $vf28, $vf0, Q\n"
        "vdiv       Q, $vf0w, $vf28x\n"
        "vwaitq\n"
        "vmulq.xyz  $vf31, $vf31, Q\n"
        "sqc2       $vf31, 0x10($4)\n"
        "lqc2       $vf31, 0x20($5)\n"
        "vmul.xyz   $vf28, $vf31, $vf31\n"
        "vaddy.x    $vf28, $vf28, $vf28y\n"
        "vaddz.x    $vf28, $vf28, $vf28z\n"
        ".word      0x4A1C03BD                    # vsqrt      Q, $vf28x # 00000000 <InstrIdType: R5900_COP2_SPECIAL2>\n"
        "vwaitq\n"
        "vaddq.x    $vf28, $vf0, Q\n"
        "vdiv       Q, $vf0w, $vf28x\n"
        "vwaitq\n"
        "vmulq.xyz  $vf31, $vf31, Q\n"
        "sqc2      $vf31, 0x20($4)\n"
        :  : "r"(a0), "r"(a1));
}

void func_002B5978(u32 a0, u32 a1, float f12)
{
    __asm__ volatile(
        "lqc2       $vf30, 0x0($5)\n"
        "mfc1       $3, $f12\n"
        "qmtc2.ni   $3, $vf31\n"
        "vmulx.xyz  $vf30, $vf30, $vf31x\n"
        "qmfc2.ni   $2, $vf30\n"
        "sd         $2, 0x0($4)\n"
        "pexew      $2, $2\n"
        "sw        $2, 0x8($4)\n"
        :  : "r"(a0), "r"(a1) : "$2", "$3");
}

void func_002B59A0(u32 a0, u32 a1, float f12)
{
    __asm__ volatile(
        "lqc2       $vf30, 0x0($5)\n"
        "mfc1       $3, $f12\n"
        "qmtc2.ni   $3, $vf31\n"
        "vmulx.xyzw $vf30, $vf30, $vf31x\n"
        "sqc2      $vf30, 0x0($4)\n"
        :  : "r"(a0), "r"(a1) : "$3");
}

void func_002B59B8(float *m, float *x, float *y, int n)
{
    int stride = (n + 3) & 0xFC;
    int sz = stride * 8;
    float *h = func_002B3888(sz);
    float *d = h + stride;
    int i;

    m[0] = 0.0f;
    m[n - 1] = 0.0f;
    for (i = 0; i < n - 1; i++) {
        h[i] = x[i + 1] - x[i];
        if (h[i] != 0.0f) {
            d[i + 1] = (y[i + 1] - y[i]) / h[i];
        } else {
            d[i + 1] = 0.0f;
        }
    }
    m[1] = d[2] - d[1] - h[0] * m[0];
    d[1] = 2.0f * (x[2] - x[0]);
    for (i = 1; i < n - 2; i++) {
        float t = h[i] / d[i];
        m[i + 1] = d[i + 2] - d[i + 1] - m[i] * t;
        d[i + 1] = 2.0f * (x[i + 2] - x[i]) - h[i] * t;
    }
    m[n - 2] -= h[n - 2] * m[n - 1];
    for (i = n - 2; i > 0; i--) {
        if (h[i] == 0.0f) {
            m[i] = 0.0f;
        } else {
            m[i] = (m[i] - h[i] * m[i + 1]) / d[i];
        }
    }
    func_002B39C0(sz);
}

double func_002E9290(double);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_spline_xyz_table);

float func_002B5EC0(float *y, float *x, float *m, int n, float t)
{
    int lo;
    int hi;
    float x0;
    float dx;

    if (n == 1) {
        return y[0];
    }
    if (n == 2) {
        dx = y[1] - y[0];
        return y[0] + dx * t;
    }
    lo = 0;
    hi = n - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (x[mid] < t) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    if (lo > 0) {
        lo--;
    }
    x0 = x[lo];
    dx = x[lo + 1] - x0;
    t -= x0;
    if (dx != 0.0f) {
        return (((m[lo + 1] - m[lo]) * t / dx + m[lo] * 3.0f) * t + ((y[lo + 1] - y[lo]) / dx - (m[lo] * 2.0f + m[lo + 1]) * dx)) * t + y[lo];
    }
    return y[lo];
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_spline_xyz);

double func_002E9290(double);
double func_002E8C28(double, double);

float op_deg_get(float *dist, float x0, float y0, float x1, float y1)
{
    float dx = x0 - x1;
    float dy = y0 - y1;
    float a;

    if (dist != 0) {
        float d2 = dx * dx + dy * dy;
        func_002ED038(d2);
        *dist = func_002EC440(func_002E9290(func_002ED038(d2)));
    }
    a = func_002EC440(func_002E8C28(func_002ED038(dy), func_002ED038(dx)));
    a = -(a * 2048.0f / 3.141592f) + -1024.0f;
    __asm__(
        ".set noreorder\n"
        "cvt.w.s $f1, %0\n"
        "mfc1    $2, $f1\n"
        "andi    $2, $2, 0xFFF\n"
        "mtc1    $2, %0\n"
        "cvt.s.w %0, %0\n"
        ".set reorder"
        : "+f"(a) : : "$2", "$f1");
    return a;
}

extern float D_004F4120[4];
extern float D_004F4130[4];
void func_002DCE80(void *a, void *b, void *c);

int func_002B6278(float *a, void *b, float *c)
{
    float m[4][4];
    float v[4];
    register int flag __asm__("$7");

    __asm__ volatile(
        ".set noreorder\n"
        "lw    $2, 0x0(%1)\n"
        "lw    $3, 0x8(%1)\n"
        "or    $2, $2, $3\n"
        "beqz  $2, 1f\n"
        " move %0, $0\n"
        "nop\n"
        "addiu %0, %0, 1\n"
        "1:\n"
        "nop\n"
        ".set reorder\n"
        : "=r"(flag) : "r"(c) : "$2", "$3");
    if (flag != 0) {
        func_002DCE80(v, D_004F4120, c);
    } else {
        func_002DCE80(v, D_004F4130, c);
    }
    func_002DD128(m);
    func_002DCEC8(m[0], v);
    func_002DCEC8(m[2], c);
    func_002DCE80(m[1], m[2], m[0]);
    func_002DD080((Blk64 *)a, (Blk64 *)m, b);
}

int func_002B6358(float *a, void *b, void *c)
{
    int tmp[4];

    __asm__ volatile(
        "lui       $2, (0x3F800000 >> 16)\n"
        "lqc2      $vf31, 0x0(%1)\n"
        "lqc2      $vf30, 0x0(%2)\n"
        "vsub.xyzw $vf31, $vf30, $vf31\n"
        "sqc2      $vf31, 0x0(%0)\n"
        "sw        $2, 0xC(%0)\n"
        : : "r"(tmp), "r"(b), "r"(c) : "$2", "memory");
    return func_002B6278(a, b, (float *)tmp);
}

/* DEBT(FAKE) */
int op_deg_in_check(float v, float lo, float hi) {
    register int temp_3 __asm__("$3");
    register int temp_5 __asm__("$5");
    register int temp_4 __asm__("$4");
    int var_2;

    temp_3 = (int)lo;
    temp_5 = (int)hi;
    temp_4 = (int)v;
    temp_3 &= 0xFFF;
    temp_5 &= 0xFFF;
    temp_4 &= 0xFFF;
    if (temp_5 < temp_3) {
        if ((temp_4 >= temp_3) || (temp_5 >= temp_4)) {
            __asm__ volatile("" : "+r"(temp_3));
            return 1;
        }
        __asm__ volatile("" : "+r"(temp_4), "+r"(temp_5));
        return 0;
    }
    var_2 = 0;
    if (temp_4 >= temp_3) {
        var_2 = temp_5 >= temp_4;
        __asm__ volatile("" : "+r"(temp_4), "+r"(temp_5));
    }
    return var_2;
}

void op_length_get(u32 a0, u32 a1, float f0)
{
    __asm__ volatile(
        "lq         $2, 0x0($4)\n"
        "lq         $3, 0x0($5)\n"
        "qmtc2.ni   $2, $vf30\n"
        "qmtc2.ni   $3, $vf31\n"
        "vsub.xyz   $vf31, $vf31, $vf30\n"
        "vmul.xyz   $vf31, $vf31, $vf31\n"
        "vaddy.x    $vf31, $vf31, $vf31y\n"
        "vaddz.x    $vf31, $vf31, $vf31z\n"
        ".word      0x4A1F03BD                    # vsqrt      Q, $vf31x # 00000000 <InstrIdType: R5900_COP2_SPECIAL2>\n"
        "vwaitq\n"
        "vaddq.x    $vf31, $vf0, Q\n"
        "qmfc2.ni   $2, $vf31\n"
        "mtc1       $2, $f0\n"
        "nop\n"
        :  : "r"(a0), "r"(a1) : "$2", "$3");
}

void func_002B50E0(void *dst, void *src, float angle);

void func_002B6440(void *a, void *b, float angle)
{
    int m[16];

    __asm__ volatile(
        "lui $2, (0x3F800000 >> 16)\n"
        "sq  $0, 0x0(%0)\n"
        "sq  $0, 0x10(%0)\n"
        "sq  $0, 0x20(%0)\n"
        "sq  $0, 0x30(%0)\n"
        "sw  $2, 0x0(%0)\n"
        "sw  $2, 0x14(%0)\n"
        "sw  $2, 0x28(%0)\n"
        "sw  $2, 0x3C(%0)\n"
        : : "r"(m) : "$2", "memory");
    func_002B50E0(m, m, angle);
    func_002B5880((u32)a, (u32)m, (u32)b);
}

void func_002B64B0(void *a, void *b, void *c, float angle)
{
    int tmp[4];
    int save[8];

    __asm__ volatile(
        "sqc2    $vf30, 0x0(%1)\n"
        "sqc2    $vf31, 0x10(%1)\n"
        "lqc2    $vf30, 0x0(%2)\n"
        "lqc2    $vf31, 0x0(%3)\n"
        "vsub.xz $vf31, $vf30, $vf31\n"
        "sqc2    $vf31, 0x0(%0)\n"
        : : "r"(tmp), "r"(save), "r"(b), "r"(c) : "memory");
    func_002B6440(tmp, tmp, angle);
    __asm__ volatile(
        "lqc2    $vf30, 0x0(%2)\n"
        "lqc2    $vf31, 0x0(%0)\n"
        "vadd.xz $vf30, $vf30, $vf31\n"
        "sqc2    $vf30, 0x0(%3)\n"
        "lqc2    $vf31, 0x10(%1)\n"
        "lqc2    $vf30, 0x0(%1)\n"
        : : "r"(tmp), "r"(save), "r"(b), "r"(a), "r"(c) : "memory");
}

int func_002B69A8(float *rx, float *ry, float cx, float cy, float r, float x0, float y0, float x1, float y1);
float _op_deg_get(float x0, float y0, float x1, float y1, float *dist) __asm__("op_deg_get");

int op_point_get_line_circle(float *out0, float *out1, float cx, float cy, float r, float x0, float y0, float x1, float y1)
{
    float pad[4];
    float p0[4];
    float p1[4];
    float rx[8];
    float ry[4];
    float d0, d1, d2;
    int n;
    float a0, a1, a2;

    (void)pad;
    n = func_002B69A8(rx, ry, cx, cy, r, x0, y0, x1, y1);
    MMI_SQ_ZERO(0x0, p0);
    MMI_SQ_ZERO(0x0, p1);
    p0[0] = rx[0];
    p0[2] = ry[0];
    p1[0] = rx[1];
    p1[2] = ry[1];
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        __asm__ volatile(
            "lq $2, 0x0(%1)\n\t"
            "sq $2, 0x0(%0)"
            : : "r"(out0), "r"(p0) : "$2", "memory");
        return 1;
    }
    a0 = _op_deg_get(x0, y0, x1, y1, &d0);
    a1 = _op_deg_get(x0, y0, p0[0], p0[2], &d1);
    a2 = _op_deg_get(x0, y0, p1[0], p1[2], &d2);
    if (d2 < d1) {
        u_long128 tq = *(u_long128 *)p0;
        float ta = a1;
        float td = d1;

        a1 = a2;
        d1 = d2;
        a2 = ta;
        d2 = td;
        *(u_long128 *)p0 = *(u_long128 *)p1;
        *(u_long128 *)p1 = tq;
    }
    if (d0 < d1) {
        return 0;
    }
    if (d0 < d2) {
        register float f12 __asm__("$f12") = a1;
        register float c128 __asm__("$f13");
        register float hi __asm__("$f14");
        __asm__(
            ".set noreorder\n\t"
            ".set noat\n\t"
            "lui   $1, 0x4300\n\t"
            "mtc1  $1, %0\n\t"
            "add.s %1, %2, %0\n\t"
            ".set at\n\t"
            ".set reorder"
            : "=&f"(c128), "=f"(hi) : "f"(a0), "f"(f12));
        if (op_deg_in_check(f12, a0 - c128, hi) != 0) {
            out0[0] = p0[0];
            out0[2] = p0[2];
            return 1;
        }
        return 0;
    }
    {
        register float f12 __asm__("$f12") = a1;
        register float c128 __asm__("$f0");
        float lo, hi;
        __asm__(
            ".set noreorder\n\t"
            ".set noat\n\t"
            "lui   $1, 0x4300\n\t"
            "mtc1  $1, %0\n\t"
            "add.s %1, %2, %0\n\t"
            ".set at\n\t"
            ".set reorder"
            : "=&f"(c128), "=f"(hi) : "f"(a0), "f"(f12));
        lo = a0 - c128;
        if (op_deg_in_check(f12, lo, hi) != 0) {
            if (op_deg_in_check(a2, lo, hi) != 0) {
                out0[0] = p0[0];
                out0[2] = p0[2];
                out1[0] = p1[0];
                out1[2] = p1[2];
                return 2;
            }
            out0[0] = p0[0];
            out0[2] = p0[2];
            return 1;
        }
        if (op_deg_in_check(a2, lo, hi) != 0) {
            out0[0] = p1[0];
            out0[2] = p1[2];
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B6768);

double func_002E7B28(double);
double func_002E8278(double);

void func_002B68D0(float *px, float *py, float x0, float y0, float angle, float x1, float y1)
{
    float a = -angle;
    float c = func_002EC440(func_002E7B28(func_002ED038(a)));
    float dx = x1 - x0;
    float dy = y1 - y0;
    float s = func_002EC440(func_002E8278(func_002ED038(a)));

    *px = dx * c + dy * s + x0;
    *py = -dx * s + dy * c + y0;
}

float func_002B6768(float x0, float y0, float x1, float y1);
void _func_002B68D0(float x0, float y0, float angle, float x1, float y1, float *px, float *py) __asm__("func_002B68D0");

int func_002B69A8(float *rx, float *ry, float cx, float cy, float r, float x0, float y0, float x1, float y1)
{
    float lx, ly;
    float angle;
    double dly;
    float dx;

    angle = func_002B6768(x0, y0, x1, y1);
    _func_002B68D0(0.0f, 0.0f, -angle, cx - x0, cy - y0, &lx, &ly);
    dly = func_002ED038(ly);
    if (func_002EC198(dly, 0.0) < 0) {
        dly = func_002EBC08(0.0, dly);
    }
    if (func_002EC198(dly, func_002ED038(r)) > 0) {
        return 0;
    }
    func_002ED038(r * r - ly * ly);
    dx = func_002EC440(func_002E9290(func_002ED038(r * r - ly * ly)));
    _func_002B68D0(cx, cy, angle, cx + dx, cy - ly, rx, ry);
    if (dx == 0.0f) {
        return 1;
    }
    _func_002B68D0(cx, cy, angle, cx - dx, cy - ly, rx + 1, ry + 1);
    return 2;
}
