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

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", opp_md_point4);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", func_002B0178);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", func_002B0228);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", func_002B0400);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", opp_gline);

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

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", opp_mdc_parallel4);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", opp_mdc_point4);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", rcefChrDraw);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", opps_mdc_init_notc);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", func_002B0BF0);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", func_002B0DC8);

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
