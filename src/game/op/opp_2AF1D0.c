/* tu_324 0x2af1d0-0x2b0fc0: low; ~opp (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: animation data readers (see w10.h). */
#define func_002B06B0 _hdr_func_002B06B0
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/r6.h"
#include "ffx/v6.h"
#include "ffx/g4.h"
#undef func_002B06B0

void func_002AF1D0(AnimCtx *o, int b)
{
    AnimTgt *t = o->p220;
    s16 k = *t->pA8;

    switch (k) {
    case 1:
        opp_dbg_draw_spl(o, b);
        break;
    case 2:
        func_002AF368(o, b);
        break;
    case 3:
        func_002AF648(o, b);
        break;
    case 4:
        func_002AF828(o, b);
        break;
    case 5:
        opp_dbg_draw_line_circle(o, b);
        break;
    }
}

extern HwRegs2008250 D_2008250;
extern char D_00575AA8[];
void func_002B41B0(char *);
AnimTgt *opus_no_get(int, AnimTgt *, s16);
void op_spline_draw_path3(int, int, s16, AnimCtx *, int);

void opp_dbg_draw_spl(AnimCtx *o, int b)
{
    AnimTgt *t = o->p220;
    s16 idx = t->pA8[1];
    AnimTgt *tgt;
    s8 *spl;
    void *loc;

    if (idx == 0) {
        tgt = t;
    } else {
        tgt = opus_no_get(b, t, idx);
    }
    spl = *(s8 **)((u8 *)tgt + 0xBC);
    if (spl == 0) {
        if (D_2008250.b2 != 0) {
            func_002B41B0(D_00575AA8);
        }
        return;
    }
    loc = (void *)opus_local_get((void *)o, (void *)t);
    if (spl[7] != 0) {
        op_unit_m_scale(o, 0.0625f);
        func_002DCE38(o, loc, o);
        func_002DCE38(o, (u8 *)o + 0x2C0, o);
    } else {
        func_002DCE38(o, (u8 *)o + 0x2C0, loc);
    }
    op_spline_draw_path3(*(int *)(spl + 8), *(int *)(spl + 0xC), *(s16 *)spl, o, *(int *)(b + 0x28));
}

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", func_002AF368);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", func_002AF4B8);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", func_002AF648);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", func_002AF828);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", opp_dbg_draw_line_circle);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", func_002AFDC0);

#include "vu0.h"

void func_002B5348(void *, void *, void *, void *);
void func_002B58B0(void *, void *, void *);
void func_002B2AD8(void *, s32, s32, s32);
s32 op1_md_draw(s32, void *);
void *func_002B0178(void *, void *, void *, void *, s32);
void func_002B0400(void *, void *, void *, void *, void *);
void _opp_func_002B56D8(void *, void *, void *) __asm__("func_002B56D8");
void *_opp_opus_local_get(void *, void *) __asm__("opus_local_get");

typedef struct OppCtx0 {
    union {
        u_long128 q;
        s32 w[4];
    } u0;
    u8 pad10[0x20E];
    s8 b21E;
    u8 pad21F;
    void *p220;
} OppCtx0; /* DEBT(NAME) */

void opp_md_point4(void *arg0, void *arg1)
{
    OppCtx0 *o = (OppCtx0 *)arg0;
    void *p80 = (u8 *)arg0 + 0x80;
    void *pC0 = (u8 *)arg0 + 0xC0;
    void *t = o->p220;
    s16 *pA8 = *(s16 **)((u8 *)t + 0xA8);
    s16 *pA8_1 = pA8 + 1;
    register float sc __asm__("$f0") = *(float *)((u8 *)t + 0x3C);
    void *p100;
    s32 ret;

    __asm__ volatile("" : "+f"(sc));
    o->u0.q = *(u_long128 *)((u8 *)t + 0x30);
    __asm__ volatile("" ::: "memory");
    o->u0.w[0] = 0;
    p100 = (u8 *)arg0 + 0x100;
    op_unit_m_scale(p80, sc * (1.0f / 2097152.0f));
    func_002B5348(p80, p80, (u8 *)t + 0x30, (u8 *)t + 0x90);
    _opp_func_002B56D8(pC0, _opp_opus_local_get(arg0, t), p80);
    _opp_func_002B56D8(pC0, (u8 *)arg0 + 0x2C0, pC0);
    ret = (s32)func_002B0178(p100, arg0, arg1, t, pA8[1]);
    *(u32 *)((u8 *)arg0 + 0x100) |= 0x40;
    func_002B0400(p100, arg0, arg1, t, pA8_1);
    *(s32 *)((u8 *)arg1 + 0x54) = op1_md_draw(ret, p100);
}

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", func_002B0178);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", func_002B0228);

void func_002B0400(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4)
{
    register void *s7 __asm__("$23") = arg2;
    register void *s6 __asm__("$22") = arg0;
    register void *s5 __asm__("$21") = arg3;
    register u8 *s0 __asm__("$16") = *(u8 **)((u8 *)s6 + 0x24);
    register u8 *s1 __asm__("$17") = *(u8 **)((u8 *)s6 + 0x28);
    register u32 s2 __asm__("$18");
    register u32 fp __asm__("$30");
    register s16 *p __asm__("$20") = (s16 *)arg4 + 1;
    register s32 i __asm__("$19");

    MMI_SQ_ZERO(0x0, s0);
    MMI_SQ_ZERO(0x10, s0);
    MMI_SQ_ZERO(0x20, s0);
    MMI_SQ_ZERO(0x30, s0);
    MMI_SQ_ZERO(0x0, s1);
    MMI_SQ_ZERO(0x10, s1);
    MMI_SQ_ZERO(0x20, s1);
    MMI_SQ_ZERO(0x30, s1);
    s2 = 0x70003F00;
    fp = 0;
    __asm__ volatile("" : "+r"(s2), "+r"(fp));
    i = 3;
    do {
        if (*p != 0) {
            register u8 *t __asm__("$4") = (u8 *)opus_no_get((int)s7, (AnimTgt *)s5, *p);
            register u32 v0 __asm__("$2");
            register u_long128 q __asm__("$2");

            VU0_LQC2(30, 0x90, t);
            VU0_SQC2(30, 0x0, s1);
            v0 = *(u32 *)(t + 0x4C);
            VU0_QMTC2_NI(28, v0);
            v0 = 0x3D800000;
            VU0_QMTC2_NI(26, v0);
            VU0_OP("vmulx.x $vf28, $vf28, $vf26x");
            VU0_QMFC2_NI(v0, 28);
            *(u32 *)(s1 + 0xC) = v0;
            v0 = *(u32 *)(t + 0xC8);
            MMI_OP2Z("pextlb", q, v0);
            MMI_OP2Z("pextlh", q, q);
            VU0_QMTC2_NI(31, q);
            VU0_OP("vitof0.xyzw $vf31, $vf31");
            v0 = 0x3C800000;
            VU0_QMTC2_NI(30, v0);
            VU0_OP("vmulx.xyzw $vf31, $vf31, $vf30x");
            VU0_SQC2(31, 0x0, s0);
        }
        s0 += 0x10;
        s1 += 0x10;
        p++;
    } while (--i >= 0);
    __asm__ volatile("" : : "r"(s2), "r"(fp));
    {
        register s32 c80 __asm__("$6") = 0x80;
        register s32 cm1 __asm__("$5") = -1;
        {
            register s32 t __asm__("$7") = (s32)(*(float *)((u8 *)s5 + 0x30));
            register s32 v __asm__("$2") = (u32)t >> 31;
            register s32 r __asm__("$7");
            v = (t + v) >> 1;
            if (v >= 0x80) {
                r = c80;
            } else {
                r = v;
            }
            if (r <= cm1) {
                r = 0;
            }
            __asm__("" : "+r"(r) : "r"(v));
            ((u8 *)s6)[0x4C] = r;
        }
        {
            register s32 t __asm__("$7") = (s32)(*(float *)((u8 *)s5 + 0x4C));
            register s32 v __asm__("$2") = (u32)t >> 31;
            register s32 r __asm__("$7");
            v = (t + v) >> 1;
            if (v >= 0x80) {
                r = c80;
            } else {
                r = v;
            }
            if (r <= cm1) {
                r = 0;
            }
            ((u8 *)s6)[0x4D] = r;
        }
    }
}

typedef union U64Alias {
    u64 q;
    u8 b[8];
} U64Alias; /* DEBT(NAME) */

void opp_gline(void *arg0, void *arg1)
{
    u8 *s1 = *(u8 **)((u8 *)arg0 + 0x220);
    u8 *s4 = (u8 *)opus_no_get((int)arg1, (AnimTgt *)s1, *(s16 *)(s1 + 0xA8));
    u8 *s0 = *(u8 **)((u8 *)arg1 + 0x54);
    void *loc = _opp_opus_local_get(arg0, s1);
    u_long128 c;

    _opp_func_002B56D8(arg0, (u8 *)arg0 + 0x2C0, loc);
    *(u64 *)(s0 + 0x10) = 0x5024C00000008001ULL;
    *(u64 *)(s0 + 0x18) = 0x4141EULL;
    s0[0x20] = s1[0xC2];
    {
        u8 c3 = s1[0xC3];
        ((U64Alias *)(s0 + 0x28))->q = 0x42ULL;
        s0[0x34] = c3;
    }
    {
        u32 w = *(u32 *)(s1 + 0xC8);
        MMI_OP2Z("pextlb", c, w);
        MMI_OP2Z("pextlh", c, c);
    }
    *(u_long128 *)(s0 + 0x30) = c;
    func_002B58B0(s0 + 0x40, arg0, s1 + 0x90);
    {
        u32 w = *(u32 *)(s4 + 0xC8);
        MMI_OP2Z("pextlb", c, w);
        MMI_OP2Z("pextlh", c, c);
    }
    *(u_long128 *)(s0 + 0x50) = c;
    func_002B58B0(s0 + 0x60, arg0, s4 + 0x90);
    s0 += 0x70;
    func_002B2AD8(*(void **)((u8 *)arg1 + 0x54), (s32)(s0 - *(u8 **)((u8 *)arg1 + 0x54)) / 16, 0, 0);
    *(u8 **)((u8 *)arg1 + 0x54) = s0;
}

void _m2c_func_002B06B0_func_002B56D8(void *, void *, void *) __asm__("func_002B56D8");
s32 _m2c_func_002B06B0_op1_mdc_draw(s32, void *, void *, void *, void *) __asm__("op1_mdc_draw");
void *_m2c_func_002B06B0_opus_local_get(void *, void *) __asm__("opus_local_get");
void _m2c_func_002B06B0_opus_rt_m_chara(void *, u8, void *, void *, s8, float) __asm__("opus_rt_m_chara");
s32 _m2c_func_002B06B0_rcefChrDraw(void *, void *, void *, void *, s16) __asm__("rcefChrDraw");
/* DEBT(CAST) */
void func_002B06B0(void *arg0) {
    s32 temp_2;
    void *temp_17;
    void *temp_18;
    void *temp_19;
    void *temp_20;
    void *temp_21;
    void *temp_22;

    temp_21 = arg0 + 0x80;
    temp_17 = (*(void **)((u8 *)(arg0) + (0x220)));
    temp_20 = arg0 + 0xC0;
    temp_22 = arg0 + 0x2C0;
    temp_18 = arg0 + 0x100;
    _m2c_func_002B06B0_opus_rt_m_chara(temp_21, (*(u8 *)((u8 *)(temp_17) + (0x18))), temp_17 + 0x30, temp_17 + 0x90, (*(s8 *)((u8 *)(arg0) + (0x21E))), (*(float *)((u8 *)(temp_17) + (0x3C))));
    temp_19 = arg0 + 0x300;
    _m2c_func_002B06B0_func_002B56D8(temp_20, _m2c_func_002B06B0_opus_local_get(arg0, temp_17), temp_21);
    _m2c_func_002B06B0_func_002B56D8(temp_20, temp_22, temp_20);
    _m2c_func_002B06B0_rcefChrDraw(temp_18, arg0, temp_19, temp_17, -1);
    temp_2 = _m2c_func_002B06B0_rcefChrDraw(temp_18, arg0, temp_19, temp_17, (*(s16 *)((u8 *)(temp_17) + (0xA8))));
    (*(u8 *)((u8 *)(temp_18) + (0x4C))) = 0x80;
    (*(s8 *)((u8 *)(temp_18) + (0x4D))) = 0;
    (*(s32 *)((u8 *)(temp_19) + (0x54))) = _m2c_func_002B06B0_op1_mdc_draw(temp_2, temp_18, temp_21, arg0 + 0x280, temp_22);
}

void _opp_func_002B0BF0(void *, void *, void *, void *, void *) __asm__("func_002B0BF0");
void _opp_func_002B0DC8(void *, void *, void *, void *, void *) __asm__("func_002B0DC8");

typedef struct OppCtx {
    union {
        u_long128 q;
        s32 w[4];
    } u0;
    u8 pad10[0x20E];
    s8 b21E;
    u8 pad21F;
    void *p220;
} OppCtx; /* DEBT(NAME) */

/* DEBT(CAST): OppCtx overlays AnimCtx for non-aliasing b21E and 128-bit copy */
/* DEBT(ORDER): barriers keep lw/lq/sq/sw before opus_rt_m_chara */
/* DEBT(REG): pin s2/s3/s4/s6 to match callee-saved register allocation */
void opp_mdc_parallel4(void *arg0, void *arg1)
{
    OppCtx *o = (OppCtx *)arg0;
    register void *p80 __asm__("$20") = (u8 *)arg0 + 0x80;
    register void *pC0 __asm__("$18") = (u8 *)arg0 + 0xC0;
    register void *p100 __asm__("$19") = (u8 *)arg0 + 0x100;
    void *t = o->p220;
    register s16 *pA8 __asm__("$22") = *(s16 **)((u8 *)t + 0xA8);
    s32 ret;

    __asm__ volatile("" : "+r"(pA8), "+r"(pC0), "+r"(p100));
    o->u0.q = *(u_long128 *)((u8 *)t + 0x30);
    __asm__ volatile("" ::: "memory");
    o->u0.w[0] = 0;
    _m2c_func_002B06B0_opus_rt_m_chara(p80, *(u8 *)((u8 *)t + 0x18), arg0, (u8 *)t + 0x90, o->b21E, *(float *)((u8 *)t + 0x3C));
    _m2c_func_002B06B0_func_002B56D8(pC0, _m2c_func_002B06B0_opus_local_get(arg0, t), p80);
    _m2c_func_002B06B0_func_002B56D8(pC0, (u8 *)arg0 + 0x2C0, pC0);
    ret = _m2c_func_002B06B0_rcefChrDraw(p100, arg0, arg1, t, *pA8);
    _opp_func_002B0BF0(p100, arg0, arg1, t, pA8);
    *(s32 *)((u8 *)arg1 + 0x54) = _m2c_func_002B06B0_op1_mdc_draw(ret, p100, p80, (u8 *)arg0 + 0x280, (u8 *)arg0 + 0x2C0);
}

/* DEBT(CAST): OppCtx overlays AnimCtx for non-aliasing b21E and 128-bit copy */
/* DEBT(ORDER): barriers keep lw/lq/sq/sw before opus_rt_m_chara */
/* DEBT(REG): pin s2/s3/s4/s6 to match callee-saved register allocation */
void opp_mdc_point4(void *arg0, void *arg1)
{
    OppCtx *o = (OppCtx *)arg0;
    register void *p80 __asm__("$20") = (u8 *)arg0 + 0x80;
    register void *pC0 __asm__("$18") = (u8 *)arg0 + 0xC0;
    register void *p100 __asm__("$19") = (u8 *)arg0 + 0x100;
    void *t = o->p220;
    register s16 *pA8 __asm__("$22") = *(s16 **)((u8 *)t + 0xA8);
    s32 ret;

    __asm__ volatile("" : "+r"(pA8), "+r"(pC0), "+r"(p100));
    o->u0.q = *(u_long128 *)((u8 *)t + 0x30);
    __asm__ volatile("" ::: "memory");
    o->u0.w[0] = 0;
    _m2c_func_002B06B0_opus_rt_m_chara(p80, *(u8 *)((u8 *)t + 0x18), arg0, (u8 *)t + 0x90, o->b21E, *(float *)((u8 *)t + 0x3C));
    _m2c_func_002B06B0_func_002B56D8(pC0, _m2c_func_002B06B0_opus_local_get(arg0, t), p80);
    _m2c_func_002B06B0_func_002B56D8(pC0, (u8 *)arg0 + 0x2C0, pC0);
    ret = _m2c_func_002B06B0_rcefChrDraw(p100, arg0, arg1, t, *pA8);
    *(u32 *)((u8 *)arg0 + 0x100) |= 0x40;
    _opp_func_002B0DC8(p100, arg0, arg1, t, pA8);
    *(s32 *)((u8 *)arg1 + 0x54) = _m2c_func_002B06B0_op1_mdc_draw(ret, p100, p80, (u8 *)arg0 + 0x280, (u8 *)arg0 + 0x2C0);
}

void *op_oef2_a_get(int, int, int);

typedef struct MdcReq {
    u32 w0;
    u32 w4;
    u16 h8;
    u16 hA;
    u32 wC;
    u64 q10;
    union {
        u32 w;
        u8 b[4];
    } u18;
    union {
        u32 w;
        u8 b[4];
    } u1C;
    u32 p20;
    u32 p24;
    u32 p28;
    u32 p2C;
    u32 w30;
    u32 w34;
    u64 q38;
    u32 w40;
    u32 w44;
    u32 w48;
    u8 b4C;
    u8 b4D;
    u8 pad4E[2];
} MdcReq; /* DEBT(NAME) */

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", rcefChrDraw);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", opps_mdc_init_notc);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", func_002B0BF0);

void func_002B0DC8(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4)
{
    register void *s7 __asm__("$23") = arg2;
    register void *s6 __asm__("$22") = arg0;
    register void *s5 __asm__("$21") = arg3;
    register u8 *s0 __asm__("$16") = *(u8 **)((u8 *)s6 + 0x24);
    register u8 *s1 __asm__("$17") = *(u8 **)((u8 *)s6 + 0x28);
    register u32 s2 __asm__("$18");
    register u32 fp __asm__("$30");
    register s16 *p __asm__("$20") = (s16 *)arg4 + 1;
    register s32 i __asm__("$19");

    MMI_SQ_ZERO(0x0, s0);
    MMI_SQ_ZERO(0x10, s0);
    MMI_SQ_ZERO(0x20, s0);
    MMI_SQ_ZERO(0x30, s0);
    MMI_SQ_ZERO(0x0, s1);
    MMI_SQ_ZERO(0x10, s1);
    MMI_SQ_ZERO(0x20, s1);
    MMI_SQ_ZERO(0x30, s1);
    s2 = 0x70003F00;
    fp = 0;
    __asm__ volatile("" : "+r"(s2), "+r"(fp));
    i = 3;
    do {
        if (*p != 0) {
            u8 *t = (u8 *)opus_no_get((int)s7, (AnimTgt *)s5, *p);
            register u32 v0 __asm__("$2");
            register u32 v1 __asm__("$3");
            register u_long128 q __asm__("$2");

            VU0_LQC2(30, 0x90, t);
            VU0_SQC2(30, 0x0, s1);
            v0 = *(u32 *)(t + 0x4C);
            VU0_QMTC2_NI(28, v0);
            v0 = 0x3D800000;
            VU0_QMTC2_NI(26, v0);
            VU0_OP("vmulx.x $vf28, $vf28, $vf26x");
            VU0_QMFC2_NI(v0, 28);
            *(u32 *)(s1 + 0xC) = v0;
            v0 = *(u32 *)(t + 0xC8);
            MMI_OP2Z("pextlb", q, v0);
            MMI_OP2Z("pextlh", q, q);
            VU0_QMTC2_NI(31, q);
            v1 = *(u32 *)(t + 0x3C);
            VU0_QMTC2_NI(29, v1);
            VU0_OP("vitof0.xyzw $vf31, $vf31");
            v0 = 0x3B800000;
            VU0_QMTC2_NI(30, v0);
            v1 = 0x38000000;
            VU0_QMTC2_NI(28, v1);
            VU0_OP("vmulx.w $vf31, $vf31, $vf30x");
            VU0_OP("vmulx.xyz $vf31, $vf31, $vf29x");
            VU0_OP("vmulx.xyz $vf31, $vf31, $vf28x");
            VU0_SQC2(31, 0x0, s0);
        }
        s0 += 0x10;
        s1 += 0x10;
        p++;
    } while (--i >= 0);
    __asm__ volatile("" : : "r"(s2), "r"(fp));
    {
        register s32 c80 __asm__("$6") = 0x80;
        register s32 cm1 __asm__("$5") = -1;
        {
            register s32 t __asm__("$7") = (s32)(*(float *)((u8 *)s5 + 0x30));
            register s32 v __asm__("$2") = (u32)t >> 31;
            register s32 r __asm__("$7");
            v = (t + v) >> 1;
            if (v >= 0x80) {
                r = c80;
            } else {
                r = v;
            }
            if (r <= cm1) {
                r = 0;
            }
            __asm__("" : "+r"(r) : "r"(v));
            ((u8 *)s6)[0x4C] = r;
        }
        {
            register s32 t __asm__("$7") = (s32)(*(float *)((u8 *)s5 + 0x4C));
            register s32 v __asm__("$2") = (u32)t >> 31;
            register s32 r __asm__("$7");
            v = (t + v) >> 1;
            if (v >= 0x80) {
                r = c80;
            } else {
                r = v;
            }
            if (r <= cm1) {
                r = 0;
            }
            ((u8 *)s6)[0x4D] = r;
        }
    }
}

#include "vu0.h"

int func_002A88F8(int, int, int, int, int, s16);

void opp_weapon_shadow(AnimCtx *o, void *b)
{
    u8 *t = (u8 *)o->p220;
    int b54 = *(int *)((u8 *)b + 0x54);
    int v = *(int *)(t + 0x44);

    VU0_QMTC2_NI(31, v);
    VU0_OP("vftoi0.xyzw $vf31, $vf31");
    VU0_QMFC2_NI(v, 31);
    *(int *)((u8 *)b + 0x54) = func_002A88F8(*(int *)(t + 0xBC), v, b54, *(int *)(t + 0xC8), *(int *)(t + 0xA8), *(s16 *)(t + 0xC2));
}

void opp_et_ovl(void) {
}
