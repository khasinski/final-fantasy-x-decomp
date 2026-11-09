/* tu_021 0x113ff8-0x115e70: low; ~Ch (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#include "ffx/g0.h"

typedef struct G0Slot16 {
    s8 b0;
    s8 b1;
    s16 h2;
    s32 w4;
    void *p8;
    s32 wC;
} G0Slot16; /* DEBT(NAME) */

typedef struct ClothSpring {
    s16 h0;
    s16 h2;
    float f4;
    float f8;
} ClothSpring;

typedef struct ClothVec4 {
    float x;
    float y;
    float z;
    float w;
} ClothVec4;

float sqrtf(float x);

static __inline__ void vu0_add(void *dst, void *a, void *b)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0(%1)\n"
        "lqc2       $vf5, 0x0(%2)\n"
        "vadd.xyz   $vf6, $vf4, $vf5\n"
        "sqc2       $vf6, 0x0(%0)\n"
        : : "r"(dst), "r"(a), "r"(b));
}

static __inline__ void vu0_sub(void *dst, void *a, void *b)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0(%1)\n"
        "lqc2       $vf5, 0x0(%2)\n"
        "vsub.xyz   $vf6, $vf4, $vf5\n"
        "sqc2       $vf6, 0x0(%0)\n"
        : : "r"(dst), "r"(a), "r"(b));
}

static __inline__ float vu0_dot(void *a, void *b)
{
    float ret;
    __asm__ volatile(
        "lqc2       $vf4, 0x0(%1)\n"
        "lqc2       $vf5, 0x0(%2)\n"
        "vmul.xyz   $vf5, $vf4, $vf5\n"
        "vaddy.x    $vf5, $vf5, $vf5y\n"
        "vaddz.x    $vf5, $vf5, $vf5z\n"
        "qmfc2.ni   $2, $vf5\n"
        "mtc1       $2, %0\n"
        : "=f"(ret) : "r"(a), "r"(b) : "$2");
    return ret;
}

static __inline__ void vu0_scale(void *dst, void *src, float s)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0(%1)\n"
        "mfc1       $8, %2\n"
        "qmtc2.ni   $8, $vf5\n"
        "vmulx.xyz  $vf6, $vf4, $vf5x\n"
        "sqc2       $vf6, 0x0(%0)\n"
        : : "r"(dst), "r"(src), "f"(s) : "$8");
}

void func_00113FF8(ClothSpring *c, int n, ClothVec4 *verts)
{
    ClothVec4 *sp = (ClothVec4 *)0x70000000;

    for (; n--; c++) {
        ClothVec4 *v0 = &verts[c->h0];
        ClothVec4 *v1 = &verts[c->h2];
        float d2;

        vu0_sub(sp, v1, v0);
        d2 = vu0_dot(sp, sp);
        if (d2 > c->f8) {
            float d = sqrtf(d2);
            vu0_scale(sp, sp, c->f4 / d);
            vu0_add(v1, v0, sp);
        }
    }
}

void func_00114120(ClothSpring *c, int n, ClothVec4 *verts)
{
    ClothVec4 *sp = (ClothVec4 *)0x70000000;

    for (; n--; c++) {
        ClothVec4 *v0 = &verts[c->h0];
        ClothVec4 *v1 = &verts[c->h2];
        float d2;

        vu0_sub(sp, v1, v0);
        d2 = vu0_dot(sp, sp);
        if (d2 > c->f8) {
            float d = sqrtf(d2);
            vu0_scale(sp, sp, ((d - c->f4) / d) * 0.5f);
            vu0_add(v0, v0, sp);
            vu0_sub(v1, v1, sp);
        }
    }
}

void func_00114270(ClothSpring *c, int n, ClothVec4 *verts)
{
    ClothVec4 *sp = (ClothVec4 *)0x70000000;

    for (; n--; c++) {
        ClothVec4 *v0 = &verts[c->h0];
        ClothVec4 *v1 = &verts[c->h2];
        float d2;

        vu0_sub(sp, v1, v0);
        d2 = vu0_dot(sp, sp);
        if (d2 < c->f8) {
            float d = sqrtf(d2);
            vu0_scale(sp, sp, c->f4 / d);
            vu0_add(v1, v0, sp);
        }
    }
}

void func_00114398(ClothSpring *c, int n, ClothVec4 *verts)
{
    ClothVec4 *sp = (ClothVec4 *)0x70000000;

    for (; n--; c++) {
        ClothVec4 *v0 = &verts[c->h0];
        ClothVec4 *v1 = &verts[c->h2];
        float d2;

        vu0_sub(sp, v1, v0);
        d2 = vu0_dot(sp, sp);
        if (d2 < c->f8) {
            float d = sqrtf(d2);
            vu0_scale(sp, sp, ((d - c->f4) / d) * 0.5f);
            vu0_add(v0, v0, sp);
            vu0_sub(v1, v1, sp);
        }
    }
}

void func_001144E8(ClothSpring *c, int n, ClothVec4 *verts)
{
    ClothVec4 *sp = (ClothVec4 *)0x70000000;

    for (; n--; c++) {
        ClothVec4 *v0 = &verts[c->h0];
        ClothVec4 *v1 = &verts[c->h2];
        float d2;
        float d;

        vu0_sub(sp, v1, v0);
        d2 = vu0_dot(sp, sp);
        d = sqrtf(d2);
        vu0_scale(sp, sp, c->f4 / d);
        vu0_add(v1, v0, sp);
    }
}

void func_00114600(ClothSpring *c, int n, ClothVec4 *verts)
{
    ClothVec4 *sp = (ClothVec4 *)0x70000000;

    for (; n--; c++) {
        ClothVec4 *v0 = &verts[c->h0];
        ClothVec4 *v1 = &verts[c->h2];
        float d2;
        float d;

        vu0_sub(sp, v1, v0);
        d2 = vu0_dot(sp, sp);
        d = sqrtf(d2);
        vu0_scale(sp, sp, ((d - c->f4) / d) * 0.5f);
        vu0_add(v0, v0, sp);
        vu0_sub(v1, v1, sp);
    }
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_113FF8", Ch_ClothReset2);

s32 Ch_ClothReset(void *a) /* DEBT(TYPE): declared in funcs.h as returning s32, no value is produced */
{
    Ch_ReserveCalcNorm2(a);
    Ch_ClothReset2(a);
}

/* DEBT(TYPE): global type guessed from the access width only */
void func_001148E0(float v)
{
    D_0057F640 = v;
}

void func_001148F0(float x, float y, float z)
{
    D_0057F638 = y;
    D_0057F63C = z;
    D_0057F634 = x;
}

void func_00114910(float *x, float *y, float *z)
{
    if (y != 0) {
        *y = D_0057F638;
    }
    if (z != 0) {
        *z = D_0057F63C;
    }
    if (x != 0) {
        *x = D_0057F634;
    }
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_00114948(void) {
    register u8 *saved_reg_gp __asm__("$28");
    float f = (*(float *)((u8 *)(saved_reg_gp) + (-0x7D84)));
    D_0057F638 = 0.0f;
    D_0057F63C = 0.0f;
    D_0057F634 = f;
}

void func_00114968(Chr *chr, s32 v)
{
    FLAGS_SET(chr, 33, v);
}

s32 func_00114998(Chr *chr)
{
    return (s32)((u64)chr->flags >> 33) & 1;
}

void func_001149A8(Chr *chr, float x, float y, float z)
{
    chr->f810 = y;
    chr->f814 = z;
    chr->f818 = x;
    func_00114968(chr, 1);
}

void func_001149C0(Chr *chr, float *x, float *y, float *z)
{
    if (y != 0) {
        *y = chr->f810;
    }
    if (z != 0) {
        *z = chr->f814;
    }
    if (x != 0) {
        *x = chr->f818;
    }
}

void func_001149F8(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "lqc2       $vf5, 0x10($5)\n"
        "lqc2       $vf6, 0x20($5)\n"
        "lqc2       $vf7, 0x0($6)\n"
        "vmulax.xyzw ACC, $vf4, $vf7x\n"
        "vmadday.xyzw ACC, $vf5, $vf7y\n"
        "vmaddz.xyzw $vf8, $vf6, $vf7z\n"
        "sqc2      $vf8, 0x0($4)\n"
        :  : "r"(a0), "r"(a1), "r"(a2));
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_113FF8", func_00114A20);
INCLUDE_RODATA("build/ee_asm/game/chr/ch_113FF8/rodata", jtbl_005697E0);

void Ch_ClothSetAtariJimenCheck(Chr *chr)
{
    chr->u828.flags2 &= ~(1UL << 35);
    if (chr->h00 == 2 || chr->h00 == 0x66) {
        switch (chr->w738) {
        case 0x2113D:
        case 0x2113E:
        case 0x2113F:
        case 0x6610CC:
            chr->u828.flags2 |= (1UL << 35);
            break;
        }
    }
}

void func_00114B30(s8 v)
{
    D_0057F644 = v;
}

s8 func_00114B40(void)
{
    return D_0057F644;
}

/* DEBT(TYPE): global type guessed from the access width only */
void func_00114B50(float v)
{
    D_0057F648 = v;
}

/* DEBT(TYPE): global type guessed from the access width only */
void func_00114B60(float v)
{
    D_0057F64C = v;
}

void Ch_ClothEnableGrav(Chr *chr, int v)
{
    u64 *w = &chr->u828.flags2;

    *w = (*w & ~(1L << 32)) | ((u64)(v & 1) << 32);
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_113FF8", func_00114BA0);
INCLUDE_RODATA("build/ee_asm/game/chr/ch_113FF8/rodata", jtbl_005699D0);

void func_00115DF0(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "lqc2       $vf5, 0x0($6)\n"
        "vadd.xyz   $vf6, $vf4, $vf5\n"
        "sqc2      $vf6, 0x0($4)\n"
        :  : "r"(a0), "r"(a1), "r"(a2));
}

void func_00115E08(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "lqc2       $vf5, 0x0($6)\n"
        "vsub.xyz   $vf6, $vf4, $vf5\n"
        "sqc2      $vf6, 0x0($4)\n"
        :  : "r"(a0), "r"(a1), "r"(a2));
}

void func_00115E20(u32 a0, u32 a1, float f0)
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

void func_00115E48(u32 a0, u32 a1, float f12)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "mfc1       $8, $f12\n"
        "qmtc2.ni   $8, $vf5\n"
        "vmulx.xyz  $vf6, $vf4, $vf5x\n"
        "sqc2      $vf6, 0x0($4)\n"
        :  : "r"(a0), "r"(a1) : "$8");
}

void func_00115E60(u_long128 *dst, u_long128 *src)
{
    register u_long128 t __asm__("$6") = *src; /* DEBT(FAKE): original quadword temp lives in a2 */
    *dst = t;
}
