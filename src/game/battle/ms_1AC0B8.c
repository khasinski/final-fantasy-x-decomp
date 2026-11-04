/* tu_178 0x1ac0b8-0x1acfd8: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q4.h"
#include "ffx/s2.h"
#include "ffx/u2.h"
#include "ffx/v2.h"
#include "vu0.h"

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC0B8);

int func_001AC128(u32 i) {
    int r = 0;
    int j;
    Rec142F0 *p;
    if (i < 3) {
        p = &ms_screen[i];
        for (j = 0; j < 2; j++) {
            if (p->e16C[j].b != 0) {
                r = -1;
                break;
            }
        }
    }
    return r;
}

void func_001AC188(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "lqc2       $vf5, 0x10($5)\n"
        "lqc2       $vf6, 0x20($5)\n"
        "lqc2       $vf7, 0x30($5)\n"
        "lqc2       $vf8, 0x0($6)\n"
        "lqc2       $vf9, 0x10($6)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "lqc2       $vf10, 0x20($6)\n"
        "vmulax.xyzw ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw $vf13, $vf7, $vf9w\n"
        "sqc2       $vf12, 0x0($4)\n"
        "lqc2       $vf11, 0x30($6)\n"
        "vmulax.xyzw ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw $vf14, $vf7, $vf10w\n"
        "sqc2       $vf13, 0x10($4)\n"
        "vmulax.xyzw ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw $vf15, $vf7, $vf11w\n"
        "sqc2       $vf14, 0x20($4)\n"
        "sqc2      $vf15, 0x30($4)\n"
        :  : "r"(a0), "r"(a1), "r"(a2));
}

void func_001AC200(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "lqc2       $vf5, 0x10($5)\n"
        "lqc2       $vf6, 0x20($5)\n"
        "lqc2       $vf7, 0x30($5)\n"
        "lqc2       $vf8, 0x0($6)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, 0x0($4)\n"
        :  : "r"(a0), "r"(a1), "r"(a2));
}

void func_001AC230(u8 * a, u8 * b)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "vmul.xyz   $vf5, $vf4, $vf4\n"
        "vaddy.x    $vf5, $vf5, $vf5y\n"
        "vaddz.x    $vf5, $vf5, $vf5z\n"
        "vrsqrt     Q, $vf0w, $vf5x\n"
        "vwaitq\n"
        "vmulq.xyz  $vf4, $vf4, Q\n"
        "sqc2      $vf4, 0x0($4)\n"
        :  : "r"(a), "r"(b));
}

void func_001AC258(float t, float * dst, float * src, int n)
{
    __asm__ volatile(
        "mfc1       $2, $f12\n"
        "lqc2       $vf4, 0x0($5)\n"
        "lqc2       $vf6, 0x0($6)\n"
        "vsub.xyz   $vf4, $vf4, $vf6\n"
        "qmtc2.ni   $2, $vf6\n"
        "vmul.xyz   $vf5, $vf4, $vf4\n"
        "vaddy.x    $vf5, $vf5, $vf5y\n"
        "vaddz.x    $vf5, $vf5, $vf5z\n"
        "vrsqrt     Q, $vf0w, $vf5x\n"
        "vwaitq\n"
        "vmulq.xyz  $vf4, $vf4, Q\n"
        "vmulx.xyz  $vf4, $vf4, $vf6x\n"
        "sqc2      $vf4, 0x0($4)\n"
        :  : "r"(dst), "r"(src), "r"(n) : "$2");
}

void func_001AC290(u32 a0, u32 a1, u32 a2, float f12, float f13)
{
    __asm__ volatile(
        "mfc1       $2, $f12\n"
        "mfc1       $3, $f13\n"
        "lqc2       $vf4, 0x0($5)\n"
        "lqc2       $vf5, 0x0($6)\n"
        "qmtc2.ni   $2, $vf6\n"
        "qmtc2.ni   $3, $vf7\n"
        "vaddx.x    $vf8, $vf6, $vf7x\n"
        "vdiv       Q, $vf0w, $vf8x\n"
        "vmulx.xyz  $vf4, $vf4, $vf7x\n"
        "vmulx.xyz  $vf5, $vf5, $vf6x\n"
        "vadd.xyz   $vf4, $vf4, $vf5\n"
        "vwaitq\n"
        "vmulq.xyz  $vf4, $vf4, Q\n"
        "sqc2      $vf4, 0x0($4)\n"
        :  : "r"(a0), "r"(a1), "r"(a2) : "$2", "$3");
}

float func_001AC2D0(float *v)
{
    float r;
    volatile float t; /* DEBT(FAKE): original reads the stack copy twice */

    VU0_LQC2(4, 0, v);
    VU0_OP("vmul.xyz $vf5, $vf4, $vf4");
    VU0_OP("vaddy.x $vf5, $vf5, $vf5y");
    VU0_OP("vaddz.x $vf5, $vf5, $vf5z");
    VU0_OP(".word 0x4A0503BD"); /* vsqrt Q, $vf5x */
    VU0_OP("vwaitq");
    VU0_OP("vaddq.xyzw $vf5, $vf0, Q");
    VU0_QMFC2_NI(r, 5);
    t = r;
    t;
    return t;
}

float func_001AC310(float *v)
{
    float r;
    volatile float t; /* DEBT(FAKE): original reads the stack copy twice */

    VU0_LQC2(4, 0, v);
    VU0_OP("vmul.xz $vf5, $vf4, $vf4");
    VU0_OP("vaddz.x $vf5, $vf5, $vf5z");
    VU0_OP(".word 0x4A0503BD"); /* vsqrt Q, $vf5x */
    VU0_OP("vwaitq");
    VU0_OP("vaddq.xyzw $vf5, $vf0, Q");
    VU0_QMFC2_NI(r, 5);
    t = r;
    t;
    return t;
}

float func_001AC348(float *a, float *b)
{
    float r;
    volatile float t; /* DEBT(FAKE): original reads the stack copy twice */

    VU0_LQC2(4, 0, a);
    VU0_LQC2(6, 0, b);
    VU0_OP("vsub.xz $vf4, $vf4, $vf6");
    VU0_OP("vmul.xz $vf5, $vf4, $vf4");
    VU0_OP("vaddz.x $vf5, $vf5, $vf5z");
    VU0_OP(".word 0x4A0503BD"); /* vsqrt Q, $vf5x */
    VU0_OP("vwaitq");
    VU0_OP("vaddq.xyzw $vf5, $vf0, Q");
    VU0_QMFC2_NI(r, 5);
    t = r;
    t;
    return t;
}

float func_001AC388(float *a, float *b)
{
    float r;
    volatile float t; /* DEBT(FAKE): original reads the stack copy twice */

    VU0_LQC2(4, 0, a);
    VU0_LQC2(6, 0, b);
    VU0_OP("vsub.xyz $vf4, $vf4, $vf6");
    VU0_OP("vmul.xyz $vf5, $vf4, $vf4");
    VU0_OP("vaddy.x $vf5, $vf5, $vf5y");
    VU0_OP("vaddz.x $vf5, $vf5, $vf5z");
    VU0_OP(".word 0x4A0503BD"); /* vsqrt Q, $vf5x */
    VU0_OP("vwaitq");
    VU0_OP("vaddq.xyzw $vf5, $vf0, Q");
    VU0_QMFC2_NI(r, 5);
    t = r;
    t;
    return t;
}

void func_001AC3D0(float * dst, float * a, float * b)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "lqc2       $vf5, 0x0($6)\n"
        "vadd.xyz   $vf6, $vf4, $vf5\n"
        "sqc2      $vf6, 0x0($4)\n"
        :  : "r"(dst), "r"(a), "r"(b));
}

void func_001AC3E8(float * dst, float * a, float * b)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "lqc2       $vf5, 0x0($6)\n"
        "vsub.xyz   $vf6, $vf4, $vf5\n"
        "sqc2      $vf6, 0x0($4)\n"
        :  : "r"(dst), "r"(a), "r"(b));
}

void func_001AC400(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "lqc2       $vf5, 0x10($5)\n"
        "lqc2       $vf6, 0x20($5)\n"
        "lqc2       $vf7, 0x30($5)\n"
        "lqc2       $vf12, 0x0($6)\n"
        "vsub.xyzw  $vf8, $vf8, $vf8\n"
        "vaddw.x    $vf8, $vf0, $vf0w\n"
        "vsub.xyzw  $vf9, $vf9, $vf9\n"
        "vaddw.y    $vf9, $vf0, $vf0w\n"
        "vsub.xyzw  $vf10, $vf10, $vf10\n"
        "vaddw.z    $vf10, $vf0, $vf0w\n"
        "vadd.xyzw  $vf11, $vf0, $vf12\n"
        "vmulax.xyzw ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw $vf11, $vf7, $vf11w\n"
        "sqc2       $vf8, 0x0($4)\n"
        "sqc2       $vf9, 0x10($4)\n"
        "sqc2       $vf10, 0x20($4)\n"
        "sqc2      $vf11, 0x30($4)\n"
        :  : "r"(a0), "r"(a1), "r"(a2));
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC458);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC528);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC5E0);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC698);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001AC750);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", MsVectorRect2Polar);

void func_001ACAE8(float *a, float *b, float *c)
{
    VU0_LQC2(1, 0, a);
    VU0_OP("vmove.xyzw $vf0, $vf2");
    VU0_LQC2(3, 0, c);
    if (b != 0) {
        VU0_LQC2(2, 0, b);
        VU0_OP("vsub.xyzw $vf1, $vf1, $vf2");
    }
    VU0_OP("vmul.xyzw $vf1, $vf1, $vf3");
    VU0_OP("vadd.xyzw $vf1, $vf1, $vf2");
    VU0_SQC2(1, 0, a);
}

void func_001ACB10(float * v, float f)
{
    __asm__ volatile(
        "mfc1       $2, $f12\n"
        "lqc2       $vf1, 0x0($4)\n"
        "qmtc2.ni   $2, $vf2\n"
        "vmulx.xyzw $vf1, $vf1, $vf2x\n"
        "sqc2      $vf1, 0x0($4)\n"
        :  : "r"(v) : "$2");
}

void func_001ACB28(u32 a0, float f12)
{
    __asm__ volatile(
        "mfc1       $2, $f12\n"
        "lqc2       $vf1, 0x0($4)\n"
        "qmtc2.ni   $2, $vf2\n"
        "vdiv       Q, $vf0w, $vf2x\n"
        "vwaitq\n"
        "vmulq.xyzw $vf1, $vf1, Q\n"
        "sqc2      $vf1, 0x0($4)\n"
        :  : "r"(a0) : "$2");
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001ACB48);

void func_001ACCB0(u32 a0, u32 a1)
{
    __asm__ volatile(
        "addiu      $8, $5, 0x70\n"
        "addiu      $7, $5, 0x10\n"
        "addiu      $6, $5, 0x20\n"
        "addiu      $3, $5, 0x30\n"
        "addiu      $2, $5, 0x50\n"
        "addiu      $5, $5, 0x40\n"
        "lqc2       $vf4, 0x0($7)\n"
        "lqc2       $vf5, 0x0($6)\n"
        "lqc2       $vf6, 0x0($3)\n"
        "lqc2       $vf7, 0x0($2)\n"
        "lqc2       $vf8, 0x0($5)\n"
        "lqc2       $vf9, 0x0($8)\n"
        "vadd.xy    $vf5, $vf5, $vf6\n"
        "vadd.xy    $vf5, $vf5, $vf9\n"
        "vsub.xy    $vf5, $vf5, $vf7\n"
        "vmulw.xy   $vf4, $vf4, $vf4w\n"
        "vmulz.x    $vf4, $vf4, $vf8z\n"
        "vmulw.y    $vf4, $vf4, $vf8w\n"
        "vdiv       Q, $vf4x, $vf7z\n"
        "vwaitq\n"
        "vaddq.x    $vf4, $vf0, Q\n"
        "vdiv       Q, $vf4y, $vf7w\n"
        "vwaitq\n"
        "vaddq.y    $vf4, $vf0, Q\n"
        "vmove.xyz  $vf1, $vf0\n"
        "vsub.w     $vf1, $vf1, $vf1\n"
        "vmove.yzw  $vf2, $vf1\n"
        "vmove.x    $vf2, $vf4\n"
        "sqc2       $vf2, 0x0($4)\n"
        "vmove.xzw  $vf3, $vf1\n"
        "vmove.y    $vf3, $vf4\n"
        "sqc2       $vf3, 0x10($4)\n"
        "vmove.w    $vf5, $vf0\n"
        "sqc2       $vf5, 0x20($4)\n"
        "vmove.xyw  $vf4, $vf1\n"
        "sqc2      $vf4, 0x30($4)\n"
        : "+r"(a1) : "r"(a0) : "$2", "$3", "$6", "$7", "$8");
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AC0B8", func_001ACD48);

int func_001ACDB8(void) {
    u8 b[8];
    func_002E2128(b);
    return (b[0] ^ b[1] ^ b[2] ^ b[3] ^ b[4] ^ b[5] ^ b[6] ^ b[7]) + 1;
}

void func_001ACE18(s32 arg0)
{
    s32 *output;
    s32 seed;
    s32 remaining;

    remaining = 0x43;
    seed = func_001ACDB8();
    seed *= arg0 + 1;
    /* DEBT(ORDER): independent seed updates retain original scheduling. */
    D_00317130 = (seed * 0x420C56D7) + 0x2E0A;
    D_00317134 = (seed * 0x599E67E6) + 0x301D;
    func_001ACEA0();
    output = D_0065FE30;
    do
    {
        remaining -= 1;
        *output = func_001ACEA0();
        output += 1;
    } while (remaining >= 0);
}

/* random number generator: LCG with multiplier 0x5D588B65 on the seed D_00317130 */
int func_001ACEA0(void) {
    s32 seed = D_00317130 * 0x5D588B65 + 0x3C35;
    D_00317130 = (seed >> 16) + (seed << 16);
    return D_00317130 & 0x7FFFFFFF;
}

float func_001ACED8(void) {
    union { u32 u; float f; } v;

    v.u = (func_001ACEA0() & 0x7FFFFF) | 0x3F800000;
    return v.f;
}

int func_001ACF10(void) {
    int v;

    /* DEBT(TYPE): func_002D4138 returns s64; this caller was compiled against an int prototype */
    v = D_00317134 * 0x6C078965 + ((int (*)(void))func_002D4138)() + 0x4F07;
    D_00317134 = (v >> 16) + (v << 16);
    return D_00317134 & 0x7FFFFFFF;
}

int brnd(int i) {
    int v;
    D_0065FE30[i] = D_0065FE30[i] * D_00317138[i];
    D_0065FE30[i] ^= D_00317248[i];
    v = D_0065FE30[i];
    D_0065FE30[i] = (v >> 16) + (v << 16);
    return D_0065FE30[i] & 0x7FFFFFFF;
}

u8 *func_001ACFC8(void) {
    return D_0056DFB0;
}
