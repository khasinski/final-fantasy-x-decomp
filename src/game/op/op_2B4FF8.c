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

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B52C0);

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

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B5348);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B53D0);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B5458);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_rt_m_yxz);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B5568);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B55F0);

void op_rt_m_6(int a, int b, int c, int d, int sel)
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

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_unit_m_scale);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_unit_m_scale2);

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

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B59B8);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_spline_xyz_table);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B5EC0);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_spline_xyz);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_deg_get);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B6278);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B6358);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_deg_in_check);

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

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B6440);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B64B0);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_point_get_line_circle);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B6768);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B68D0);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B69A8);
