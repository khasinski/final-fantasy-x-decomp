/* tu_292 0x26bde0-0x26cce0: low; ~ppp (config/tu_map.tsv) */
#include "common.h"
#include "ffx/w9.h"
#include "ffx/r6.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/t6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"

#include "vu0.h"

extern s32 eff_sin_t;

/* DEBT(CAST) */
void func_0026BDE0(void *arg0, u32 arg1) {
    float temp_f2;
    float temp_f3;

    temp_f3 = *(float *)(((arg1 >> 2) & 0x3FFC) + (u8 *)&eff_sin_t);
    temp_f2 = *(float *)((((u32)(arg1 + 0x4000) >> 2) & 0x3FFC) + (u8 *)&eff_sin_t);
    MMI_SQ_ZERO(0, arg0);
    MMI_SQ_ZERO(0x10, arg0);
    MMI_SQ_ZERO(0x20, arg0);
    MMI_SQ_ZERO(0x30, arg0);
    (*(float *)((u8 *)(arg0) + (0))) = 1.0f;
    (*(float *)((u8 *)(arg0) + (0x14))) = temp_f2;
    (*(float *)((u8 *)(arg0) + (0x18))) = temp_f3;
    (*(float *)((u8 *)(arg0) + (0x28))) = temp_f2;
    (*(float *)((u8 *)(arg0) + (0x3C))) = 1.0f;
    (*(float *)((u8 *)(arg0) + (0x24))) = (float)-temp_f3;
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_0026BE48(void *arg0, u32 arg1) {
    register float temp_f3 __asm__("$f3");
    register float temp_f0 __asm__("$f0");

    temp_f0 = *(float *)(((arg1 >> 2) & 0x3FFC) + (u8 *)&eff_sin_t);
    temp_f3 = *(float *)((((u32)(arg1 + 0x4000) >> 2) & 0x3FFC) + (u8 *)&eff_sin_t);
    MMI_SQ_ZERO(0, arg0);
    MMI_SQ_ZERO(0x10, arg0);
    MMI_SQ_ZERO(0x20, arg0);
    MMI_SQ_ZERO(0x30, arg0);
    (*(float *)((u8 *)(arg0) + (0))) = temp_f3;
    (*(float *)((u8 *)(arg0) + (8))) = (float)-temp_f0;
    (*(float *)((u8 *)(arg0) + (0x14))) = 1.0f;
    (*(float *)((u8 *)(arg0) + (0x20))) = temp_f0;
    (*(float *)((u8 *)(arg0) + (0x28))) = temp_f3;
    (*(float *)((u8 *)(arg0) + (0x3C))) = 1.0f;
}

/* DEBT(CAST) */
void func_0026BEB0(void *arg0, u32 arg1) {
    float temp_f2;
    float temp_f3;

    temp_f3 = *(float *)(((arg1 >> 2) & 0x3FFC) + (u8 *)&eff_sin_t);
    temp_f2 = *(float *)((((u32)(arg1 + 0x4000) >> 2) & 0x3FFC) + (u8 *)&eff_sin_t);
    MMI_SQ_ZERO(0, arg0);
    MMI_SQ_ZERO(0x10, arg0);
    MMI_SQ_ZERO(0x20, arg0);
    MMI_SQ_ZERO(0x30, arg0);
    (*(float *)((u8 *)(arg0) + (0))) = temp_f2;
    (*(float *)((u8 *)(arg0) + (4))) = temp_f3;
    (*(float *)((u8 *)(arg0) + (0x28))) = 1.0f;
    (*(float *)((u8 *)(arg0) + (0x14))) = temp_f2;
    (*(float *)((u8 *)(arg0) + (0x3C))) = 1.0f;
    (*(float *)((u8 *)(arg0) + (0x10))) = (float)-temp_f3;
}

/* DEBT(FAKE) */
void pppGetRotMatrixXYZ(void *arg0, s32 *arg1) {
    u_long128 sp0[4];
    u_long128 sp40[4];
    u_long128 sp80[4];
    u_long128 spC0[4];
    register void *s0 __asm__("$16");
    register s32 *s1 __asm__("$17");
    register void *s2 __asm__("$18");

    s1 = arg1;
    func_0026BEB0(sp0, s1[2]);
    s0 = sp40;
    func_0026BE48(s0, s1[1]);
    s2 = sp80;
    VU0_LQC2(28, 0x0, sp0);
    VU0_LQC2(29, 0x10, sp0);
    VU0_LQC2(30, 0x20, sp0);
    VU0_LQC2(31, 0x30, sp0);
    VU0_LQC2(24, 0x0, s0);
    VU0_LQC2(25, 0x10, s0);
    VU0_LQC2(26, 0x20, s0);
    VU0_LQC2(27, 0x30, s0);
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf24x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf24y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf24z");
    VU0_OP("vmaddw.xyzw $vf24, $vf31, $vf24w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf25x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf25y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf25z");
    VU0_OP("vmaddw.xyzw $vf25, $vf31, $vf25w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf26x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf26y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf26z");
    VU0_OP("vmaddw.xyzw $vf26, $vf31, $vf26w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf27x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf27y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf27z");
    VU0_OP("vmaddw.xyzw $vf27, $vf31, $vf27w");
    VU0_SQC2(24, 0x0, s2);
    VU0_SQC2(25, 0x10, s2);
    VU0_SQC2(26, 0x20, s2);
    VU0_SQC2(27, 0x30, s2);
    s0 = spC0;
    func_0026BDE0(s0, s1[0]);
    VU0_LQC2(28, 0x0, s2);
    VU0_LQC2(29, 0x10, s2);
    VU0_LQC2(30, 0x20, s2);
    VU0_LQC2(31, 0x30, s2);
    VU0_LQC2(24, 0x0, s0);
    VU0_LQC2(25, 0x10, s0);
    VU0_LQC2(26, 0x20, s0);
    VU0_LQC2(27, 0x30, s0);
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf24x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf24y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf24z");
    VU0_OP("vmaddw.xyzw $vf24, $vf31, $vf24w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf25x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf25y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf25z");
    VU0_OP("vmaddw.xyzw $vf25, $vf31, $vf25w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf26x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf26y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf26z");
    VU0_OP("vmaddw.xyzw $vf26, $vf31, $vf26w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf27x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf27y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf27z");
    VU0_OP("vmaddw.xyzw $vf27, $vf31, $vf27w");
    VU0_SQC2(24, 0x0, arg0);
    VU0_SQC2(25, 0x10, arg0);
    VU0_SQC2(26, 0x20, arg0);
    VU0_SQC2(27, 0x30, arg0);
}

/* DEBT(FAKE) */
void func_0026C068(void *arg0, s32 *arg1) {
    u_long128 sp0[4];
    u_long128 sp40[4];
    u_long128 sp80[4];
    u_long128 spC0[4];
    register void *s0 __asm__("$16");
    register s32 *s1 __asm__("$17");
    register void *s2 __asm__("$18");

    s1 = arg1;
    func_0026BE48(sp0, s1[1]);
    s0 = sp40;
    func_0026BEB0(s0, s1[2]);
    s2 = sp80;
    VU0_LQC2(28, 0x0, sp0);
    VU0_LQC2(29, 0x10, sp0);
    VU0_LQC2(30, 0x20, sp0);
    VU0_LQC2(31, 0x30, sp0);
    VU0_LQC2(24, 0x0, s0);
    VU0_LQC2(25, 0x10, s0);
    VU0_LQC2(26, 0x20, s0);
    VU0_LQC2(27, 0x30, s0);
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf24x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf24y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf24z");
    VU0_OP("vmaddw.xyzw $vf24, $vf31, $vf24w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf25x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf25y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf25z");
    VU0_OP("vmaddw.xyzw $vf25, $vf31, $vf25w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf26x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf26y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf26z");
    VU0_OP("vmaddw.xyzw $vf26, $vf31, $vf26w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf27x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf27y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf27z");
    VU0_OP("vmaddw.xyzw $vf27, $vf31, $vf27w");
    VU0_SQC2(24, 0x0, s2);
    VU0_SQC2(25, 0x10, s2);
    VU0_SQC2(26, 0x20, s2);
    VU0_SQC2(27, 0x30, s2);
    s0 = spC0;
    func_0026BDE0(s0, s1[0]);
    VU0_LQC2(28, 0x0, s2);
    VU0_LQC2(29, 0x10, s2);
    VU0_LQC2(30, 0x20, s2);
    VU0_LQC2(31, 0x30, s2);
    VU0_LQC2(24, 0x0, s0);
    VU0_LQC2(25, 0x10, s0);
    VU0_LQC2(26, 0x20, s0);
    VU0_LQC2(27, 0x30, s0);
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf24x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf24y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf24z");
    VU0_OP("vmaddw.xyzw $vf24, $vf31, $vf24w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf25x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf25y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf25z");
    VU0_OP("vmaddw.xyzw $vf25, $vf31, $vf25w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf26x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf26y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf26z");
    VU0_OP("vmaddw.xyzw $vf26, $vf31, $vf26w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf27x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf27y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf27z");
    VU0_OP("vmaddw.xyzw $vf27, $vf31, $vf27w");
    VU0_SQC2(24, 0x0, arg0);
    VU0_SQC2(25, 0x10, arg0);
    VU0_SQC2(26, 0x20, arg0);
    VU0_SQC2(27, 0x30, arg0);
}

/* DEBT(FAKE) */
void func_0026C1B8(void *arg0, s32 *arg1) {
    u_long128 sp0[4];
    u_long128 sp40[4];
    u_long128 sp80[4];
    u_long128 spC0[4];
    register void *s0 __asm__("$16");
    register s32 *s1 __asm__("$17");
    register void *s2 __asm__("$18");

    s1 = arg1;
    func_0026BDE0(sp0, s1[0]);
    s0 = sp40;
    func_0026BEB0(s0, s1[2]);
    s2 = sp80;
    VU0_LQC2(28, 0x0, sp0);
    VU0_LQC2(29, 0x10, sp0);
    VU0_LQC2(30, 0x20, sp0);
    VU0_LQC2(31, 0x30, sp0);
    VU0_LQC2(24, 0x0, s0);
    VU0_LQC2(25, 0x10, s0);
    VU0_LQC2(26, 0x20, s0);
    VU0_LQC2(27, 0x30, s0);
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf24x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf24y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf24z");
    VU0_OP("vmaddw.xyzw $vf24, $vf31, $vf24w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf25x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf25y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf25z");
    VU0_OP("vmaddw.xyzw $vf25, $vf31, $vf25w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf26x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf26y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf26z");
    VU0_OP("vmaddw.xyzw $vf26, $vf31, $vf26w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf27x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf27y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf27z");
    VU0_OP("vmaddw.xyzw $vf27, $vf31, $vf27w");
    VU0_SQC2(24, 0x0, s2);
    VU0_SQC2(25, 0x10, s2);
    VU0_SQC2(26, 0x20, s2);
    VU0_SQC2(27, 0x30, s2);
    s0 = spC0;
    func_0026BE48(s0, s1[1]);
    VU0_LQC2(28, 0x0, s2);
    VU0_LQC2(29, 0x10, s2);
    VU0_LQC2(30, 0x20, s2);
    VU0_LQC2(31, 0x30, s2);
    VU0_LQC2(24, 0x0, s0);
    VU0_LQC2(25, 0x10, s0);
    VU0_LQC2(26, 0x20, s0);
    VU0_LQC2(27, 0x30, s0);
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf24x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf24y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf24z");
    VU0_OP("vmaddw.xyzw $vf24, $vf31, $vf24w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf25x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf25y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf25z");
    VU0_OP("vmaddw.xyzw $vf25, $vf31, $vf25w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf26x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf26y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf26z");
    VU0_OP("vmaddw.xyzw $vf26, $vf31, $vf26w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf27x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf27y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf27z");
    VU0_OP("vmaddw.xyzw $vf27, $vf31, $vf27w");
    VU0_SQC2(24, 0x0, arg0);
    VU0_SQC2(25, 0x10, arg0);
    VU0_SQC2(26, 0x20, arg0);
    VU0_SQC2(27, 0x30, arg0);
}

/* DEBT(FAKE) */
void func_0026C308(void *arg0, s32 *arg1) {
    u_long128 sp0[4];
    u_long128 sp40[4];
    u_long128 sp80[4];
    u_long128 spC0[4];
    register void *s0 __asm__("$16");
    register s32 *s1 __asm__("$17");
    register void *s2 __asm__("$18");

    s1 = arg1;
    func_0026BEB0(sp0, s1[2]);
    s0 = sp40;
    func_0026BDE0(s0, s1[0]);
    s2 = sp80;
    VU0_LQC2(28, 0x0, sp0);
    VU0_LQC2(29, 0x10, sp0);
    VU0_LQC2(30, 0x20, sp0);
    VU0_LQC2(31, 0x30, sp0);
    VU0_LQC2(24, 0x0, s0);
    VU0_LQC2(25, 0x10, s0);
    VU0_LQC2(26, 0x20, s0);
    VU0_LQC2(27, 0x30, s0);
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf24x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf24y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf24z");
    VU0_OP("vmaddw.xyzw $vf24, $vf31, $vf24w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf25x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf25y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf25z");
    VU0_OP("vmaddw.xyzw $vf25, $vf31, $vf25w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf26x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf26y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf26z");
    VU0_OP("vmaddw.xyzw $vf26, $vf31, $vf26w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf27x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf27y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf27z");
    VU0_OP("vmaddw.xyzw $vf27, $vf31, $vf27w");
    VU0_SQC2(24, 0x0, s2);
    VU0_SQC2(25, 0x10, s2);
    VU0_SQC2(26, 0x20, s2);
    VU0_SQC2(27, 0x30, s2);
    s0 = spC0;
    func_0026BE48(s0, s1[1]);
    VU0_LQC2(28, 0x0, s2);
    VU0_LQC2(29, 0x10, s2);
    VU0_LQC2(30, 0x20, s2);
    VU0_LQC2(31, 0x30, s2);
    VU0_LQC2(24, 0x0, s0);
    VU0_LQC2(25, 0x10, s0);
    VU0_LQC2(26, 0x20, s0);
    VU0_LQC2(27, 0x30, s0);
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf24x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf24y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf24z");
    VU0_OP("vmaddw.xyzw $vf24, $vf31, $vf24w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf25x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf25y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf25z");
    VU0_OP("vmaddw.xyzw $vf25, $vf31, $vf25w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf26x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf26y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf26z");
    VU0_OP("vmaddw.xyzw $vf26, $vf31, $vf26w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf27x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf27y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf27z");
    VU0_OP("vmaddw.xyzw $vf27, $vf31, $vf27w");
    VU0_SQC2(24, 0x0, arg0);
    VU0_SQC2(25, 0x10, arg0);
    VU0_SQC2(26, 0x20, arg0);
    VU0_SQC2(27, 0x30, arg0);
}

/* DEBT(FAKE) */
void func_0026C458(void *arg0, s32 *arg1) {
    u_long128 sp0[4];
    u_long128 sp40[4];
    u_long128 sp80[4];
    u_long128 spC0[4];
    register void *s0 __asm__("$16");
    register s32 *s1 __asm__("$17");
    register void *s2 __asm__("$18");

    s1 = arg1;
    func_0026BE48(sp0, s1[1]);
    s0 = sp40;
    func_0026BDE0(s0, s1[0]);
    s2 = sp80;
    VU0_LQC2(28, 0x0, sp0);
    VU0_LQC2(29, 0x10, sp0);
    VU0_LQC2(30, 0x20, sp0);
    VU0_LQC2(31, 0x30, sp0);
    VU0_LQC2(24, 0x0, s0);
    VU0_LQC2(25, 0x10, s0);
    VU0_LQC2(26, 0x20, s0);
    VU0_LQC2(27, 0x30, s0);
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf24x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf24y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf24z");
    VU0_OP("vmaddw.xyzw $vf24, $vf31, $vf24w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf25x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf25y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf25z");
    VU0_OP("vmaddw.xyzw $vf25, $vf31, $vf25w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf26x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf26y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf26z");
    VU0_OP("vmaddw.xyzw $vf26, $vf31, $vf26w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf27x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf27y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf27z");
    VU0_OP("vmaddw.xyzw $vf27, $vf31, $vf27w");
    VU0_SQC2(24, 0x0, s2);
    VU0_SQC2(25, 0x10, s2);
    VU0_SQC2(26, 0x20, s2);
    VU0_SQC2(27, 0x30, s2);
    s0 = spC0;
    func_0026BEB0(s0, s1[2]);
    VU0_LQC2(28, 0x0, s2);
    VU0_LQC2(29, 0x10, s2);
    VU0_LQC2(30, 0x20, s2);
    VU0_LQC2(31, 0x30, s2);
    VU0_LQC2(24, 0x0, s0);
    VU0_LQC2(25, 0x10, s0);
    VU0_LQC2(26, 0x20, s0);
    VU0_LQC2(27, 0x30, s0);
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf24x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf24y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf24z");
    VU0_OP("vmaddw.xyzw $vf24, $vf31, $vf24w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf25x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf25y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf25z");
    VU0_OP("vmaddw.xyzw $vf25, $vf31, $vf25w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf26x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf26y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf26z");
    VU0_OP("vmaddw.xyzw $vf26, $vf31, $vf26w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf27x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf27y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf27z");
    VU0_OP("vmaddw.xyzw $vf27, $vf31, $vf27w");
    VU0_SQC2(24, 0x0, arg0);
    VU0_SQC2(25, 0x10, arg0);
    VU0_SQC2(26, 0x20, arg0);
    VU0_SQC2(27, 0x30, arg0);
}

/* DEBT(FAKE) */
void func_0026C5A8(void *arg0, s32 *arg1) {
    u_long128 sp0[4];
    u_long128 sp40[4];
    u_long128 sp80[4];
    u_long128 spC0[4];
    register void *s0 __asm__("$16");
    register s32 *s1 __asm__("$17");
    register void *s2 __asm__("$18");

    s1 = arg1;
    func_0026BDE0(sp0, s1[0]);
    s0 = sp40;
    func_0026BE48(s0, s1[1]);
    s2 = sp80;
    VU0_LQC2(28, 0x0, sp0);
    VU0_LQC2(29, 0x10, sp0);
    VU0_LQC2(30, 0x20, sp0);
    VU0_LQC2(31, 0x30, sp0);
    VU0_LQC2(24, 0x0, s0);
    VU0_LQC2(25, 0x10, s0);
    VU0_LQC2(26, 0x20, s0);
    VU0_LQC2(27, 0x30, s0);
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf24x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf24y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf24z");
    VU0_OP("vmaddw.xyzw $vf24, $vf31, $vf24w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf25x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf25y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf25z");
    VU0_OP("vmaddw.xyzw $vf25, $vf31, $vf25w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf26x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf26y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf26z");
    VU0_OP("vmaddw.xyzw $vf26, $vf31, $vf26w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf27x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf27y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf27z");
    VU0_OP("vmaddw.xyzw $vf27, $vf31, $vf27w");
    VU0_SQC2(24, 0x0, s2);
    VU0_SQC2(25, 0x10, s2);
    VU0_SQC2(26, 0x20, s2);
    VU0_SQC2(27, 0x30, s2);
    s0 = spC0;
    func_0026BEB0(s0, s1[2]);
    VU0_LQC2(28, 0x0, s2);
    VU0_LQC2(29, 0x10, s2);
    VU0_LQC2(30, 0x20, s2);
    VU0_LQC2(31, 0x30, s2);
    VU0_LQC2(24, 0x0, s0);
    VU0_LQC2(25, 0x10, s0);
    VU0_LQC2(26, 0x20, s0);
    VU0_LQC2(27, 0x30, s0);
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf24x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf24y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf24z");
    VU0_OP("vmaddw.xyzw $vf24, $vf31, $vf24w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf25x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf25y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf25z");
    VU0_OP("vmaddw.xyzw $vf25, $vf31, $vf25w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf26x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf26y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf26z");
    VU0_OP("vmaddw.xyzw $vf26, $vf31, $vf26w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf27x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf27y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf27z");
    VU0_OP("vmaddw.xyzw $vf27, $vf31, $vf27w");
    VU0_SQC2(24, 0x0, arg0);
    VU0_SQC2(25, 0x10, arg0);
    VU0_SQC2(26, 0x20, arg0);
    VU0_SQC2(27, 0x30, arg0);
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_0026C6F8(void *arg0, void *arg1, void *arg2) {
    register s32 s0 __asm__("$16");
    register s32 s1 __asm__("$17");
    register void *s3 __asm__("$19");
    register s32 *v0 __asm__("$2");
    register s32 a1 __asm__("$5");

    s3 = (u8 *)arg0 + 0x10;
    v0 = *(s32 **)((u8 *)arg2 + 0xC);
    s1 = v0[2] + 0xA0;
    s0 = v0[0] + 0xA0;
    a1 = v0[1];
    __asm__("" : "+r"(a1));
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    s1 = (s32)((u8 *)arg0 + s1);
    a1 += 0xA0;
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    s0 = (s32)((u8 *)arg0 + s0);
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    pppGetRotMatrixXYZ(s3, (s32 *)((u8 *)arg0 + a1));
    VU0_LQC2(9, 0x0, s1);
    VU0_LQC2(10, 0x0, s3);
    VU0_LQC2(11, 0x10, s3);
    VU0_LQC2(12, 0x20, s3);
    VU0_OP("vmulx.xyz $vf10, $vf10, $vf9x");
    VU0_OP("vmuly.xyz $vf11, $vf11, $vf9y");
    VU0_OP("vmulz.xyz $vf12, $vf12, $vf9z");
    VU0_SQC2(10, 0x0, s3);
    VU0_SQC2(11, 0x10, s3);
    VU0_SQC2(12, 0x20, s3);
    *(s64 *)((u8 *)arg0 + 0x40) = *(s64 *)((u8 *)s0 + 0);
    *(float *)((u8 *)arg0 + 0x48) = *(float *)((u8 *)s0 + 8);
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_0026C7A0(void *arg0, void *arg1, void *arg2) {
    register s32 s0 __asm__("$16");
    register s32 s1 __asm__("$17");
    register void *s3 __asm__("$19");
    register s32 *v0 __asm__("$2");
    register s32 a1 __asm__("$5");

    s3 = (u8 *)arg0 + 0x10;
    v0 = *(s32 **)((u8 *)arg2 + 0xC);
    s1 = v0[2] + 0xA0;
    s0 = v0[0] + 0xA0;
    a1 = v0[1];
    __asm__("" : "+r"(a1));
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    s1 = (s32)((u8 *)arg0 + s1);
    a1 += 0xA0;
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    s0 = (s32)((u8 *)arg0 + s0);
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    func_0026C068(s3, (s32 *)((u8 *)arg0 + a1));
    VU0_LQC2(9, 0x0, s1);
    VU0_LQC2(10, 0x0, s3);
    VU0_LQC2(11, 0x10, s3);
    VU0_LQC2(12, 0x20, s3);
    VU0_OP("vmulx.xyz $vf10, $vf10, $vf9x");
    VU0_OP("vmuly.xyz $vf11, $vf11, $vf9y");
    VU0_OP("vmulz.xyz $vf12, $vf12, $vf9z");
    VU0_SQC2(10, 0x0, s3);
    VU0_SQC2(11, 0x10, s3);
    VU0_SQC2(12, 0x20, s3);
    *(s64 *)((u8 *)arg0 + 0x40) = *(s64 *)((u8 *)s0 + 0);
    *(float *)((u8 *)arg0 + 0x48) = *(float *)((u8 *)s0 + 8);
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_0026C848(void *arg0, void *arg1, void *arg2) {
    register s32 s0 __asm__("$16");
    register s32 s1 __asm__("$17");
    register void *s3 __asm__("$19");
    register s32 *v0 __asm__("$2");
    register s32 a1 __asm__("$5");

    s3 = (u8 *)arg0 + 0x10;
    v0 = *(s32 **)((u8 *)arg2 + 0xC);
    s1 = v0[2] + 0xA0;
    s0 = v0[0] + 0xA0;
    a1 = v0[1];
    __asm__("" : "+r"(a1));
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    s1 = (s32)((u8 *)arg0 + s1);
    a1 += 0xA0;
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    s0 = (s32)((u8 *)arg0 + s0);
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    func_0026C308(s3, (s32 *)((u8 *)arg0 + a1));
    VU0_LQC2(9, 0x0, s1);
    VU0_LQC2(10, 0x0, s3);
    VU0_LQC2(11, 0x10, s3);
    VU0_LQC2(12, 0x20, s3);
    VU0_OP("vmulx.xyz $vf10, $vf10, $vf9x");
    VU0_OP("vmuly.xyz $vf11, $vf11, $vf9y");
    VU0_OP("vmulz.xyz $vf12, $vf12, $vf9z");
    VU0_SQC2(10, 0x0, s3);
    VU0_SQC2(11, 0x10, s3);
    VU0_SQC2(12, 0x20, s3);
    *(s64 *)((u8 *)arg0 + 0x40) = *(s64 *)((u8 *)s0 + 0);
    *(float *)((u8 *)arg0 + 0x48) = *(float *)((u8 *)s0 + 8);
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_0026C8F0(void *arg0, void *arg1, void *arg2) {
    register s32 s0 __asm__("$16");
    register s32 s1 __asm__("$17");
    register void *s3 __asm__("$19");
    register s32 *v0 __asm__("$2");
    register s32 a1 __asm__("$5");

    s3 = (u8 *)arg0 + 0x10;
    v0 = *(s32 **)((u8 *)arg2 + 0xC);
    s1 = v0[2] + 0xA0;
    s0 = v0[0] + 0xA0;
    a1 = v0[1];
    __asm__("" : "+r"(a1));
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    s1 = (s32)((u8 *)arg0 + s1);
    a1 += 0xA0;
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    s0 = (s32)((u8 *)arg0 + s0);
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    func_0026C1B8(s3, (s32 *)((u8 *)arg0 + a1));
    VU0_LQC2(9, 0x0, s1);
    VU0_LQC2(10, 0x0, s3);
    VU0_LQC2(11, 0x10, s3);
    VU0_LQC2(12, 0x20, s3);
    VU0_OP("vmulx.xyz $vf10, $vf10, $vf9x");
    VU0_OP("vmuly.xyz $vf11, $vf11, $vf9y");
    VU0_OP("vmulz.xyz $vf12, $vf12, $vf9z");
    VU0_SQC2(10, 0x0, s3);
    VU0_SQC2(11, 0x10, s3);
    VU0_SQC2(12, 0x20, s3);
    *(s64 *)((u8 *)arg0 + 0x40) = *(s64 *)((u8 *)s0 + 0);
    *(float *)((u8 *)arg0 + 0x48) = *(float *)((u8 *)s0 + 8);
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_0026C998(void *arg0, void *arg1, void *arg2) {
    register s32 s0 __asm__("$16");
    register s32 s1 __asm__("$17");
    register void *s3 __asm__("$19");
    register s32 *v0 __asm__("$2");
    register s32 a1 __asm__("$5");

    s3 = (u8 *)arg0 + 0x10;
    v0 = *(s32 **)((u8 *)arg2 + 0xC);
    s1 = v0[2] + 0xA0;
    s0 = v0[0] + 0xA0;
    a1 = v0[1];
    __asm__("" : "+r"(a1));
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    s1 = (s32)((u8 *)arg0 + s1);
    a1 += 0xA0;
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    s0 = (s32)((u8 *)arg0 + s0);
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    func_0026C458(s3, (s32 *)((u8 *)arg0 + a1));
    VU0_LQC2(9, 0x0, s1);
    VU0_LQC2(10, 0x0, s3);
    VU0_LQC2(11, 0x10, s3);
    VU0_LQC2(12, 0x20, s3);
    VU0_OP("vmulx.xyz $vf10, $vf10, $vf9x");
    VU0_OP("vmuly.xyz $vf11, $vf11, $vf9y");
    VU0_OP("vmulz.xyz $vf12, $vf12, $vf9z");
    VU0_SQC2(10, 0x0, s3);
    VU0_SQC2(11, 0x10, s3);
    VU0_SQC2(12, 0x20, s3);
    *(s64 *)((u8 *)arg0 + 0x40) = *(s64 *)((u8 *)s0 + 0);
    *(float *)((u8 *)arg0 + 0x48) = *(float *)((u8 *)s0 + 8);
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_0026CA40(void *arg0, void *arg1, void *arg2) {
    register s32 s0 __asm__("$16");
    register s32 s1 __asm__("$17");
    register void *s3 __asm__("$19");
    register s32 *v0 __asm__("$2");
    register s32 a1 __asm__("$5");

    s3 = (u8 *)arg0 + 0x10;
    v0 = *(s32 **)((u8 *)arg2 + 0xC);
    s1 = v0[2] + 0xA0;
    s0 = v0[0] + 0xA0;
    a1 = v0[1];
    __asm__("" : "+r"(a1));
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    s1 = (s32)((u8 *)arg0 + s1);
    a1 += 0xA0;
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    s0 = (s32)((u8 *)arg0 + s0);
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    func_0026C5A8(s3, (s32 *)((u8 *)arg0 + a1));
    VU0_LQC2(9, 0x0, s1);
    VU0_LQC2(10, 0x0, s3);
    VU0_LQC2(11, 0x10, s3);
    VU0_LQC2(12, 0x20, s3);
    VU0_OP("vmulx.xyz $vf10, $vf10, $vf9x");
    VU0_OP("vmuly.xyz $vf11, $vf11, $vf9y");
    VU0_OP("vmulz.xyz $vf12, $vf12, $vf9z");
    VU0_SQC2(10, 0x0, s3);
    VU0_SQC2(11, 0x10, s3);
    VU0_SQC2(12, 0x20, s3);
    *(s64 *)((u8 *)arg0 + 0x40) = *(s64 *)((u8 *)s0 + 0);
    *(float *)((u8 *)arg0 + 0x48) = *(float *)((u8 *)s0 + 8);
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_0026CAE8(void *arg0, void *arg1, void *arg2) {
    u_long128 sp0[4];
    register s32 s0 __asm__("$16");
    register s32 s1 __asm__("$17");
    register void *s2 __asm__("$18");
    register s32 *v0 __asm__("$2");
    register void *v1 __asm__("$3");
    register void *a0 __asm__("$4");
    register s32 a1 __asm__("$5");

    v0 = *(s32 **)((u8 *)arg2 + 0xC);
    s1 = v0[2] + 0xA0;
    s0 = v0[0] + 0xA0;
    a1 = v0[1];
    __asm__("" : "+r"(a1));
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    s1 = (s32)((u8 *)arg0 + s1);
    a1 += 0xA0;
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    s0 = (s32)((u8 *)arg0 + s0);
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    pppGetRotMatrixXYZ(sp0, (s32 *)((u8 *)arg0 + a1));
    VU0_LQC2(9, 0x0, s1);
    VU0_LQC2(10, 0x0, sp0);
    VU0_LQC2(11, 0x10, sp0);
    VU0_LQC2(12, 0x20, sp0);
    VU0_OP("vmulx.xyz $vf10, $vf10, $vf9x");
    VU0_OP("vmuly.xyz $vf11, $vf11, $vf9y");
    VU0_OP("vmulz.xyz $vf12, $vf12, $vf9z");
    VU0_SQC2(10, 0x0, sp0);
    VU0_SQC2(11, 0x10, sp0);
    VU0_SQC2(12, 0x20, sp0);
    *(s64 *)((u8 *)arg0 + 0x40) = *(s64 *)((u8 *)s0 + 0);
    v1 = D_006A39B0;
    a0 = &sp0[3];
    *(float *)((u8 *)sp0 + 0x38) = *(float *)((u8 *)s0 + 8);
    *(s64 *)((u8 *)sp0 + 0) = *(s64 *)((u8 *)s0 + 0);
    VU0_LQC2(27, 0x0, a0);
    VU0_LQC2(28, 0x0, v1);
    VU0_LQC2(29, 0x10, v1);
    VU0_LQC2(30, 0x20, v1);
    VU0_LQC2(31, 0x30, v1);
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf27x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf27y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf27z");
    VU0_OP("vmaddw.xyzw $vf26, $vf31, $vf0w");
    VU0_SQC2(26, 0x0, a0);
    s2 = (u8 *)arg0 + 0x50;
    v0 = (s32 *)D_006A3A70;
    VU0_LQC2(28, 0x0, v0);
    VU0_LQC2(29, 0x10, v0);
    VU0_LQC2(30, 0x20, v0);
    VU0_LQC2(31, 0x30, v0);
    VU0_LQC2(24, 0x0, sp0);
    VU0_LQC2(25, 0x10, sp0);
    VU0_LQC2(26, 0x20, sp0);
    VU0_LQC2(27, 0x30, sp0);
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf24x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf24y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf24z");
    VU0_OP("vmaddw.xyzw $vf24, $vf31, $vf24w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf25x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf25y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf25z");
    VU0_OP("vmaddw.xyzw $vf25, $vf31, $vf25w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf26x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf26y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf26z");
    VU0_OP("vmaddw.xyzw $vf26, $vf31, $vf26w");
    VU0_OP("vmulax.xyzw ACC, $vf28, $vf27x");
    VU0_OP("vmadday.xyzw ACC, $vf29, $vf27y");
    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf27z");
    VU0_OP("vmaddw.xyzw $vf27, $vf31, $vf27w");
    VU0_SQC2(24, 0x0, s2);
    VU0_SQC2(25, 0x10, s2);
    VU0_SQC2(26, 0x20, s2);
    VU0_SQC2(27, 0x30, s2);
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_0026CC38(void *arg0, void *arg1, void *arg2) {
    register s32 s0 __asm__("$16");
    register s32 s1 __asm__("$17");
    register void *s3 __asm__("$19");
    register s32 *v0 __asm__("$2");
    register s32 a1 __asm__("$5");

    s3 = (u8 *)arg0 + 0x10;
    v0 = *(s32 **)((u8 *)arg2 + 0xC);
    s1 = v0[2] + 0xA0;
    s0 = v0[0] + 0xA0;
    a1 = v0[1];
    __asm__("" : "+r"(a1));
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    s1 = (s32)((u8 *)arg0 + s1);
    a1 += 0xA0;
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    s0 = (s32)((u8 *)arg0 + s0);
    __asm__("" : "+r"(s1), "+r"(s0), "+r"(a1));
    pppGetRotMatrixXYZ(s3, (s32 *)((u8 *)arg0 + a1));
    VU0_LQC2(9, 0x0, s1);
    VU0_LQC2(10, 0x0, s3);
    VU0_LQC2(11, 0x10, s3);
    VU0_LQC2(12, 0x20, s3);
    VU0_OP("vmulx.xyz $vf10, $vf10, $vf9x");
    VU0_OP("vmuly.xyz $vf11, $vf11, $vf9y");
    VU0_OP("vmulz.xyz $vf12, $vf12, $vf9z");
    VU0_SQC2(10, 0x0, s3);
    VU0_SQC2(11, 0x10, s3);
    VU0_SQC2(12, 0x20, s3);
    *(s64 *)((u8 *)arg0 + 0x40) = *(s64 *)((u8 *)s0 + 0);
    *(float *)((u8 *)arg0 + 0x48) = *(float *)((u8 *)s0 + 8);
}
