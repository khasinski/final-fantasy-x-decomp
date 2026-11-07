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

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", opp_dbg_draw_spl);

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

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", opp_weapon_shadow);

void opp_et_ovl(void) {
}
