/* tu_321 0x2a43d8-0x2a6fe8: low; ~opu (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: script/event flag helpers (see w10.h). */
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/t6.h"
#include "ffx/v6.h"

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A43D8", opu_world);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A43D8", func_002A4540);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A43D8", func_002A4680);

/* DEBT(NAME): module and names guessed: object field helpers (see w10.h). */
INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A43D8", opus_local_get);

void func_002A4A38(void *a)
{
    func_002DD610(a, 512.0f, 0.8f, 0.87285f, 2048.0f, 2048.0f, 1.0f, 16777215.0f, 1.0f, 65536.0f);
}

u16 *func_002A4AA0(ScriptThread *thread, u16 *op)
{
    int *entry;
    ScriptSub *state;

    state = thread->sub;
    entry = op_oef2_a_get(thread->res[state->b1E], 4, op[1]);
    state->bBB = 2;
    state->pE0 = entry;
    state->hC0 = 0x80;
    state->hC2 = 0x48;

    state->a8.ub[0] = ((s16)thread->flags & 0xE000) >> 13;
    state->a8.ub[1] = ((u32)thread->flags & 0xE00) >> 9;

    /* DEBT(CAST): the embedded object at 0x300 begins with an IdList. */
    opus_draw_on((IdList *)thread->obj300, thread->h214);
    return op + 2;
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A43D8", func_002A4B40);

void opus_md_tex0_reset_multi(int a, int lo, int hi, u64 arg)
{
    int i;
    int *v;

    for (i = lo; i <= hi; i++) {
        v = op_oef2_a_get(a, 4, i);
        if (v != 0) {
            op_md_tex0_reset(v, arg);
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A43D8", ope_draw);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A43D8", opu_part_init);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A43D8", opu_part_run);

int opu_part_kill(V6Obj *o, int b)
{
    o->ops->fn54(o->h220);
    return b + 2;
}

u32 func_002A5488(char *a) {
    return *(u32 *)(a + 0x14) > 0xFFFFF; /* DEBT(CAST): record type unknown, word at +0x14 */
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A43D8", opu_motion);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A43D8", func_002A5658);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A43D8", func_002A5750);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A43D8", opu_v_en_bone);
INCLUDE_RODATA("build/ee_asm/game/op/opu/opu_2A43D8/rodata", jtbl_00575670);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A43D8", opu_mdc);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A43D8", func_002A6758);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A43D8", func_002A6878);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A43D8", opu_mdc_break);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A43D8", opus_get_bone_matrix);

int opus_get_bone_vertex(Vec4 *v, Chr *chr, int bone)
{
    Vec4 unused; /* DEBT(PADDING): the original frame has 16 more bytes */

    if (bone & 0x8000) {
        return Ch_OptposGet((int)chr, bone & 0x7FFF, (int)v); /* DEBT(TYPE): q7.h prototype takes ints */
    }
    return func_00107428(chr, bone, 0, v);
}

void opus_chara_root_m_get(void *dst, Chr *chr)
{
    s32 v = func_00110840(chr);

    if (v != 0) {
        op_m_copy(dst, (void *)v); /* DEBT(TYPE): func_00110840 really returns a pointer */
    } else {
        Ch_GetRootGlobalMatrix(chr, dst);
    }
}

void opus_chara_matrix_jack(Chr *chr, int v) {
    if (chr != 0) {
        Ch_SetOrgMatrix(chr, v);
        Ch_EnClip(chr, 0);
    }
}

void func_002A6E70(Chr *chr)
{
    if (chr != 0) {
        Ch_SetOrgMatrix(chr, 0);
        Ch_EnClip(chr, 1);
    }
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A43D8", opus_rt_m_chara);
