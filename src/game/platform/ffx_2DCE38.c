/* tu_351 0x2dce38-0x2ddb48: low; ~FFXVu0InnerProduct (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/v7.h"

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DCE38);

void func_002DCE80(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "lqc2       $vf5, 0x0($6)\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vsub.w     $vf6, $vf6, $vf6\n"
        "sqc2      $vf6, 0x0($4)\n"
        :  : "r"(a0), "r"(a1), "r"(a2));
}

void func_002DCEA0(u32 a0, u32 a1, float f0)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($4)\n"
        "lqc2       $vf5, 0x0($5)\n"
        "vmul.xyz   $vf5, $vf4, $vf5\n"
        "vaddy.x    $vf5, $vf5, $vf5y\n"
        "vaddz.x    $vf5, $vf5, $vf5z\n"
        "qmfc2.ni   $2, $vf5\n"
        "mtc1       $2, $f0\n"
        "nop\n"
        :  : "r"(a0), "r"(a1) : "$2");
}

void func_002DCEC8(s32 a, s32 b)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "vmul.xyz   $vf5, $vf4, $vf4\n"
        "vaddy.x    $vf5, $vf5, $vf5y\n"
        "vaddz.x    $vf5, $vf5, $vf5z\n"
        ".word      0x4A0503BD                    # vsqrt      Q, $vf5x # 00000000 <InstrIdType: R5900_COP2_SPECIAL2>\n"
        "vwaitq\n"
        "vaddq.x    $vf5, $vf0, Q\n"
        "vdiv       Q, $vf0w, $vf5x\n"
        "vsub.xyzw  $vf6, $vf0, $vf0\n"
        "vwaitq\n"
        "vmulq.xyz  $vf6, $vf4, Q\n"
        "sqc2      $vf6, 0x0($4)\n"
        :  : "r"(a), "r"(b));
}

void func_002DCF00(u32 a0, u32 a1)
{
    __asm__ volatile(
        "lq         $8, 0x0($5)\n"
        "lq         $9, 0x10($5)\n"
        "lq         $10, 0x20($5)\n"
        "lq         $11, 0x30($5)\n"
        "pextlw     $12, $9, $8\n"
        "pextuw     $13, $9, $8\n"
        "pextlw     $14, $11, $10\n"
        "pextuw     $15, $11, $10\n"
        "pcpyld     $8, $14, $12\n"
        "pcpyud     $9, $12, $14\n"
        "pcpyld     $10, $15, $13\n"
        "pcpyud     $11, $13, $15\n"
        "sq         $8, 0x0($4)\n"
        "sq         $9, 0x10($4)\n"
        "sq         $10, 0x20($4)\n"
        "sq        $11, 0x30($4)\n"
        :  : "r"(a0), "r"(a1) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15");
}

void func_002DCF48(u32 a0, u32 a1)
{
    __asm__ volatile(
        "lq         $8, 0x0($5)\n"
        "lq         $9, 0x10($5)\n"
        "lq         $10, 0x20($5)\n"
        "lqc2       $vf4, 0x30($5)\n"
        "vmove.xyzw $vf5, $vf4\n"
        "vsub.xyz   $vf4, $vf4, $vf4\n"
        "vmove.xyzw $vf9, $vf4\n"
        "qmfc2.ni   $11, $vf4\n"
        "pextlw     $12, $9, $8\n"
        "pextuw     $13, $9, $8\n"
        "pextlw     $14, $11, $10\n"
        "pextuw     $15, $11, $10\n"
        "pcpyld     $8, $14, $12\n"
        "pcpyud     $9, $12, $14\n"
        "pcpyld     $10, $15, $13\n"
        "qmtc2.ni   $8, $vf6\n"
        "qmtc2.ni   $9, $vf7\n"
        "qmtc2.ni   $10, $vf8\n"
        "vmulax.xyz ACC, $vf6, $vf5x\n"
        "vmadday.xyz ACC, $vf7, $vf5y\n"
        "vmaddz.xyz $vf4, $vf8, $vf5z\n"
        "vsub.xyz   $vf4, $vf9, $vf4\n"
        "sq         $8, 0x0($4)\n"
        "sq         $9, 0x10($4)\n"
        "sq         $10, 0x20($4)\n"
        "sqc2      $vf4, 0x30($4)\n"
        :  : "r"(a0), "r"(a1) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15");
}

void func_002DCFB8(u32 a0, u32 a1, float f12)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "mfc1       $8, $f12\n"
        "qmtc2.ni   $8, $vf5\n"
        "vdiv       Q, $vf0w, $vf5x\n"
        "vwaitq\n"
        "vmulq.xyzw $vf4, $vf4, Q\n"
        "sqc2      $vf4, 0x0($4)\n"
        :  : "r"(a0), "r"(a1) : "$8");
}

void func_002DCFD8(u32 a0, u32 a1, float f12)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "mfc1       $8, $f12\n"
        "qmtc2.ni   $8, $vf5\n"
        "vdiv       Q, $vf0w, $vf5x\n"
        "vwaitq\n"
        "vmulq.xyz  $vf4, $vf4, Q\n"
        "sqc2      $vf4, 0x0($4)\n"
        :  : "r"(a0), "r"(a1) : "$8");
}

void func_002DCFF8(u32 a0, u32 a1, u32 a2, float f12)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "lqc2       $vf5, 0x0($6)\n"
        "mfc1       $8, $f12\n"
        "qmtc2.ni   $8, $vf6\n"
        "vaddw.x    $vf7, $vf0, $vf0w\n"
        "vsub.x     $vf8, $vf7, $vf6\n"
        "vmulax.xyzw ACC, $vf4, $vf6x\n"
        "vmaddx.xyzw $vf9, $vf5, $vf8x\n"
        "sqc2      $vf9, 0x0($4)\n"
        :  : "r"(a0), "r"(a1), "r"(a2) : "$8");
}

void func_002DD020(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "lqc2       $vf5, 0x0($6)\n"
        "vadd.xyzw  $vf6, $vf4, $vf5\n"
        "sqc2      $vf6, 0x0($4)\n"
        :  : "r"(a0), "r"(a1), "r"(a2));
}

void func_002DD038(Vec4 * out, Vec4 * a, Vec4 * b)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "lqc2       $vf5, 0x0($6)\n"
        "vsub.xyzw  $vf6, $vf4, $vf5\n"
        "sqc2      $vf6, 0x0($4)\n"
        :  : "r"(out), "r"(a), "r"(b));
}

void func_002DD050(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "lqc2       $vf5, 0x0($6)\n"
        "vmul.xyzw  $vf6, $vf4, $vf5\n"
        "sqc2      $vf6, 0x0($4)\n"
        :  : "r"(a0), "r"(a1), "r"(a2));
}

void func_002DD068(u32 a0, u32 a1, float f12)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "mfc1       $8, $f12\n"
        "qmtc2.ni   $8, $vf5\n"
        "vmulx.xyzw $vf6, $vf4, $vf5x\n"
        "sqc2      $vf6, 0x0($4)\n"
        :  : "r"(a0), "r"(a1) : "$8");
}

void func_002DD080(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($6)\n"
        "lqc2       $vf5, 0x30($5)\n"
        "lq         $7, 0x0($5)\n"
        "lq         $8, 0x10($5)\n"
        "lq         $9, 0x20($5)\n"
        "vadd.xyz   $vf5, $vf5, $vf4\n"
        "sq         $7, 0x0($4)\n"
        "sq         $8, 0x10($4)\n"
        "sq         $9, 0x20($4)\n"
        "sqc2      $vf5, 0x30($4)\n"
        :  : "r"(a0), "r"(a1), "r"(a2) : "$7", "$8", "$9");
}

void func_002DD0B0(void *pa, void *pb)
{
    u_long128 *a = pa, *b = pb;
    register u_long128 t __asm__("$6") = *b;
    *a = t;
}

void func_002DD0C0(void *pa, void *pb)
{
    u_long128 *a = pa, *b = pb;
    register u_long128 t0 __asm__("$6");
    register u_long128 t1 __asm__("$7");
    register u_long128 t2 __asm__("$8");
    register u_long128 t3 __asm__("$9");
    t0 = b[0];
    __asm__ volatile("");
    t1 = b[1];
    __asm__ volatile("");
    t2 = b[2];
    __asm__ volatile("");
    t3 = b[3];
    __asm__ volatile("");
    a[0] = t0;
    __asm__ volatile("");
    a[1] = t1;
    __asm__ volatile("");
    a[2] = t2;
    __asm__ volatile("");
    a[3] = t3;
}

void func_002DD0E8(u32 a0, u32 a1)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "vftoi4.xyzw $vf5, $vf4\n"
        "sqc2      $vf5, 0x0($4)\n"
        :  : "r"(a0), "r"(a1));
}

void func_002DD0F8(u32 a0, u32 a1)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "vftoi0.xyzw $vf5, $vf4\n"
        "sqc2      $vf5, 0x0($4)\n"
        :  : "r"(a0), "r"(a1));
}

void func_002DD108(u32 a0, u32 a1)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "vitof4.xyzw $vf5, $vf4\n"
        "sqc2      $vf5, 0x0($4)\n"
        :  : "r"(a0), "r"(a1));
}

void func_002DD118(u32 a0, u32 a1)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "vitof0.xyzw $vf5, $vf4\n"
        "sqc2      $vf5, 0x0($4)\n"
        :  : "r"(a0), "r"(a1));
}

void func_002DD128(struct W3Whole * w)
{
    __asm__ volatile(
        "vsub.xyzw  $vf4, $vf0, $vf0\n"
        "vadd.w     $vf4, $vf4, $vf0\n"
        "vmr32.xyzw $vf5, $vf4\n"
        "vmr32.xyzw $vf6, $vf5\n"
        "vmr32.xyzw $vf7, $vf6\n"
        "sqc2       $vf4, 0x30($4)\n"
        "sqc2       $vf5, 0x20($4)\n"
        "sqc2       $vf6, 0x10($4)\n"
        "sqc2      $vf7, 0x0($4)\n"
        :  : "r"(w));
}

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD150);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD1C8);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD270);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD318);

void func_002DD3C0(void *m, int unused, float *v)
{
    func_002DD1C8(m, v[2]);
    func_002DD318(m, m, v[1]);
    func_002DD270(m, m, v[0]);
}

void func_002DD410(u32 a0, u32 a1, float f12, float f13)
{
    __asm__ volatile(
        "mfc1       $8, $f12\n"
        "mfc1       $9, $f13\n"
        "lqc2       $vf6, 0x0($5)\n"
        "qmtc2.ni   $8, $vf4\n"
        "qmtc2.ni   $9, $vf5\n"
        "vmaxx.xyzw $vf6, $vf6, $vf4x\n"
        "vminix.xyzw $vf6, $vf6, $vf5x\n"
        "sqc2      $vf6, 0x0($4)\n"
        :  : "r"(a0), "r"(a1) : "$8", "$9");
}

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD438);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD4E8);

void func_002DD5A8(Vec4 *m, void *r0, void *r1, void *r2, void *r3)
{
    func_002DD0B0(&m[0], r0);
    func_002DD0B0(&m[1], r1);
    func_002DD0B0(&m[2], r2);
    func_002DD0B0(&m[3], r3);
}

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD610);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD718);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD8A8);

void func_002DD900(void *a, void *b, void *c, int flag)
{
    VU0_LQC2(4, 0x0, b);
    VU0_LQC2(5, 0x10, b);
    VU0_LQC2(6, 0x20, b);
    VU0_LQC2(7, 0x30, b);
    VU0_LQC2(8, 0x0, c);
    VU0_OP("vmulax.xyzw ACC, $vf4, $vf8x");
    VU0_OP("vmadday.xyzw ACC, $vf5, $vf8y");
    VU0_OP("vmaddaz.xyzw ACC, $vf6, $vf8z");
    VU0_OP("vmaddw.xyzw $vf9, $vf7, $vf8w");
    VU0_OP("vdiv Q, $vf0w, $vf9w");
    VU0_OP("vwaitq");
    VU0_OP("vmulq.xyz $vf9, $vf9, Q");
    VU0_OP("vftoi4.xyzw $vf10, $vf9");
    if (flag) {
        VU0_OP("vftoi0.zw $vf10, $vf9");
    }
    VU0_SQC2(10, 0x0, a);
}

void func_002DD948(void *dst, float *src)
{
    float *d = dst;

    d[0] = src[0];
    d[1] = src[1];
    d[2] = src[2];
}

void func_002DD968(u32 a0, u32 a1, u32 a2, float f12)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "lqc2       $vf5, 0x0($6)\n"
        "mfc1       $8, $f12\n"
        "qmtc2.ni   $8, $vf6\n"
        "vmove.w    $vf9, $vf4\n"
        "vaddw.x    $vf7, $vf0, $vf0w\n"
        "vsub.x     $vf8, $vf7, $vf6\n"
        "vmulax.xyz ACC, $vf4, $vf6x\n"
        "vmaddx.xyz $vf9, $vf5, $vf8x\n"
        "sqc2      $vf9, 0x0($4)\n"
        :  : "r"(a0), "r"(a1), "r"(a2) : "$8");
}

void func_002DD998(u32 a0, u32 a1, float f12)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "mfc1       $8, $f12\n"
        "qmtc2.ni   $8, $vf5\n"
        "vmulx.xyz  $vf4, $vf4, $vf5x\n"
        "sqc2      $vf4, 0x0($4)\n"
        :  : "r"(a0), "r"(a1) : "$8");
}

int func_002DD9B0(void *a)
{
    int r;
    register u64 k __asm__("$2");
    VU0_OP("vsub.xyzw $vf4, $vf0, $vf0");
    k = 0x4580000045800000UL;
    __asm__ volatile("" : : "r"(k));
    VU0_LQC2(7, 0x0, a);
    VU0_QMTC2_NI(6, k);
    VU0_CTC2_NI_ZERO(16);
    VU0_OP("vsub.xyw $vf5, $vf7, $vf4");
    VU0_OP("vsub.xy $vf5, $vf6, $vf7");
    VU0_OP("vnop");
    VU0_OP("vnop");
    VU0_OP("vnop");
    VU0_OP("vnop");
    VU0_OP("vnop");
    VU0_CFC2_NI(r, 16);
    return r & 0xC0;
}

int func_002DD9F8(void *a, void *b, void *c)
{
    int r;
    register u64 k __asm__("$2");
    VU0_OP("vsub.xyzw $vf4, $vf0, $vf0");
    k = 0x4580000045800000UL;
    __asm__ volatile("" : : "r"(k));
    VU0_LQC2(6, 0x0, a);
    VU0_LQC2(8, 0x0, b);
    VU0_LQC2(9, 0x0, c);
    VU0_QMTC2_NI(7, k);
    VU0_CTC2_NI_ZERO(16);
    VU0_OP("vsub.xyw $vf5, $vf6, $vf4");
    VU0_OP("vsub.xy $vf5, $vf7, $vf6");
    VU0_OP("vsub.xyw $vf5, $vf8, $vf4");
    VU0_OP("vsub.xy $vf5, $vf7, $vf8");
    VU0_OP("vsub.xyw $vf5, $vf9, $vf4");
    VU0_OP("vsub.xy $vf5, $vf7, $vf9");
    VU0_OP("vnop");
    VU0_OP("vnop");
    VU0_OP("vnop");
    VU0_OP("vnop");
    VU0_OP("vnop");
    VU0_CFC2_NI(r, 16);
    return r & 0xC0;
}

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DDA58);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DDAE8);
