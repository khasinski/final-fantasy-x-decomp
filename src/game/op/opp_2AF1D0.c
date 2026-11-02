/* tu_324 0x2af1d0-0x2b0fc0: low; ~opp (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: animation data readers (see w10.h). */
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/r6.h"
#include "ffx/v6.h"
#include "ffx/g4.h"

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

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", func_002B06B0);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", opp_mdc_parallel4);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", opp_mdc_point4);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", rcefChrDraw);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", opps_mdc_init_notc);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", func_002B0BF0);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", func_002B0DC8);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AF1D0", opp_weapon_shadow);

void opp_et_ovl(void) {
}
