/* tu_325 0x2b0fc0-0x2b1720: medium; ~opf (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/r6.h"
#include "ffx/v6.h"

void func_002B0FC0(u32 a0, u32 a1)
{
    __asm__ volatile(
        "lw         $6, 0x220($4)\n"
        "addiu      $6, $6, 0x30\n"
        "lui        $3, (0x3D800000 >> 16)\n"
        "qmtc2.ni   $3, $vf26\n"
        "lqc2       $vf21, 0x10($6)\n"
        "vmulx.xyzw $vf21, $vf21, $vf26x\n"
        "sqc2       $vf21, 0x60($6)\n"
        "daddu     $2, $5, $0\n"
        :  : "r"(a0), "r"(a1) : "$2", "$3", "$6");
}

#include "vu0.h"

extern float eff_sin_t[];
void op_unit_m(void *m);
void func_002B5348(void *dst, void *m, void *rot, void *pos);
void func_002B5880(void *dst, void *m, void *src);
void func_002B5978(float *dst, float *src, float s);

INCLUDE_ASM("build/ee_asm/game/op/opf_2B0FC0", func_002B0FE8);

INCLUDE_ASM("build/ee_asm/game/op/opf_2B0FC0", func_002B10B0);

INCLUDE_ASM("build/ee_asm/game/op/opf_2B0FC0", func_002B1170);

int func_002B12D8(void *a0, int a1)
{
    s8 *s = *(s8 **)((u8 *)a0 + 0x220);
    float f0 = *(float *)(s + s[0xA0]);
    register float f6 __asm__("$f6") = *(float *)(s + s[0xA1]);
    register float f5 __asm__("$f5") = (s[0xA2] != 0) ? *(float *)(s + s[0xA2]) : 0.0f;
    int ang = (int)f0 & 0xFFF;
    register float x __asm__("$f3") = *(float *)(s + 0x40);
    register float sc __asm__("$f2") = 0.0625f;
    register float z __asm__("$f4") = *(float *)(s + 0x48);
    register float y __asm__("$f1") = *(float *)(s + 0x44);
    register float s0 __asm__("$f0") = eff_sin_t[ang];

    *(float *)(s + 0x90) = (s0 * f6 + x) * sc;
    *(float *)(s + 0x98) = (eff_sin_t[(ang + 0x400) & 0xFFF] * f6 + z) * sc;
    *(float *)(s + 0x94) = (y + f5) * sc;
    return a1;
}

int func_002B1390(void *a0, int a1)
{
    s8 *s = *(s8 **)((u8 *)a0 + 0x220);
    float f0 = *(float *)(s + s[0xA0]);
    register float f6 __asm__("$f6") = *(float *)(s + s[0xA1]);
    register float f5 __asm__("$f5") = (s[0xA2] != 0) ? *(float *)(s + s[0xA2]) : 0.0f;
    int ang = (int)f0 & 0xFFF;
    register float y __asm__("$f3") = *(float *)(s + 0x44);
    register float sc __asm__("$f2") = 0.0625f;
    register float x __asm__("$f4") = *(float *)(s + 0x40);
    register float z __asm__("$f1") = *(float *)(s + 0x48);
    register float s0 __asm__("$f0") = eff_sin_t[ang];

    *(float *)(s + 0x94) = (s0 * f6 + y) * sc;
    *(float *)(s + 0x90) = (eff_sin_t[(ang + 0x400) & 0xFFF] * f6 + x) * sc;
    *(float *)(s + 0x98) = (z + f5) * sc;
    return a1;
}

int opf_sph(void *a0, int a1)
{
    u8 *s2 = *(u8 **)((u8 *)a0 + 0x220);
    u8 *s3 = (u8 *)a0 + 0x40;
    u8 *s1 = (u8 *)opus_no_get((u8 *)a0 + 0x300, s2, *(s16 *)(s2 + 0xA0));
    u_long128 q;
    u64 lo;
    u32 z;

    op_unit_m(a0);
    func_002B5348(a0, a0, s2 + 0x30, s1 + 0x90);
    func_002B5978((float *)s3, (float *)(s2 + 0x40), 0.0625f);
    func_002B5880(s3, a0, s3);
    q = *(u_long128 *)s3;
    __asm__ volatile("sd %1, 0x90(%0)" : : "r"(s2), "r"(q) : "memory");
    __asm__ volatile("pextuw %0, $0, %1" : "=&r"(z) : "r"(q));
    *(u32 *)(s2 + 0x98) = z;
    return a1;
}

INCLUDE_ASM("build/ee_asm/game/op/opf_2B0FC0", func_002B1500);

int func_002B15B0(void *a0, int a1)
{
    u8 *s0 = *(u8 **)((u8 *)a0 + 0x220);
    u8 *t1 = (u8 *)opus_no_get((u8 *)a0 + 0x300, s0, *(s16 *)(s0 + 0xA0));
    register float x __asm__("$f1") = *(float *)(s0 + 0xA4);
    register u8 *dst __asm__("$6");
    register u8 *p1 __asm__("$5");
    register u8 *pf __asm__("$4");
    register u64 q __asm__("$2");

    __asm__ volatile("" : "+f"(x));
    dst = s0 + 0x90;
    __asm__ volatile("" : "+r"(dst));
    p1 = t1 + 0x90;
    pf = s0 + 0x40;
    __asm__ volatile("" : "+r"(p1), "+r"(pf));
    *(float *)a0 = x;
    *(float *)((u8 *)a0 + 4) = *(float *)(s0 + 0x44);
    *(float *)((u8 *)a0 + 8) = *(float *)(s0 + 0x48);
    __asm__ volatile("" ::: "memory");
    q = 0x3B800000;
    VU0_LQC2(20, 0, pf);
    VU0_LQC2(22, 0, a0);
    VU0_LQC2(23, 0, p1);
    VU0_QMTC2_NI(31, q);
    VU0_OP("vsub.xyz $vf30, $vf23, $vf22");
    VU0_OP("vmulx.xyz $vf30, $vf30, $vf20x");
    VU0_OP("vmulx.xyz $vf30, $vf30, $vf31x");
    VU0_OP("vadd.xyz $vf30, $vf30, $vf22");
    VU0_QMFC2_NI(q, 30);
    __asm__ volatile("sd %1, 0(%0)" : : "r"(dst), "r"(q) : "memory");
    __asm__ volatile("pextuw %0, $0, %1" : "=r"(q) : "r"(q));
    __asm__ volatile("sw %1, 8(%0)" : : "r"(dst), "r"(q) : "memory");
    return a1;
}

extern char D_00575AC0[];
void func_00120108(char *fmt, ...);
void func_002EA328(int status) __attribute__((noreturn));
void op_spline_xyz(void *dst, float t, int a, int b, s16 n);
void func_002B5978(float *dst, float *src, float s);

typedef struct SplRec {
    s16 h0;
    u8 pad2[5];
    s8 b7;
    int w8;
    int wC;
} SplRec;

void opf_spl_gw(void *a0)
{
    s8 *sub = *(s8 **)((u8 *)a0 + 0x220);
    u8 *base = (u8 *)opus_no_get((u8 *)a0 + 0x300, sub, *(s16 *)(sub + 0xA0));
    SplRec *sp = *(SplRec **)(base + 0xBC);

    if (sp == 0) {
        func_00120108(D_00575AC0);
        func_002EA328(1);
    }
    op_spline_xyz(a0, *(float *)(sub + sub[0xA2]) * (1.0f / 256.0f), sp->w8, sp->wC, sp->h0);
    if (sp->b7 != 0) {
        func_002B5978((float *)(sub + 0x90), (float *)a0, 16.0f);
    } else {
        func_002B5978((float *)(sub + 0x90), (float *)a0, 1.0f);
    }
}
