/* tu_321 0x2a43d8-0x2a6fe8: low; ~opu (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: script/event flag helpers (see w10.h). */
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/t6.h"
#include "ffx/v6.h"

void op_unit_m_scale2(void *m, void *n);
void op_rt_m_6(void *m, void *n, void *a, void *b, int c);
void func_002B5750(void *a, void *b, void *c);
void func_002B5880(void *a, void *b, void *c);

/* DEBT(CAST): raw byte offsets, record types unknown */
s16 *opu_world(AnimCtx *o, s16 *p)
{
    u8 *m = (u8 *)o;
    register u8 *t __asm__("$16");
    float *f = (float *)o;
    int idx;

    t = o->p220;

    if (o->h21A & 0x400) {
        f[0] = p[1];
        f[1] = p[2];
        f[2] = p[3];
        f[0] *= 0.00390625f;
        f[1] *= 0.00390625f;
        f[2] *= 0.00390625f;
        p += 4;
        op_unit_m_scale2(o, o);
    } else {
        op_unit_m_scale(o, 1.0f);
        p += 1;
    }
    idx = (o->h21A & 0x7000) >> 12;
    t[0x19] = idx;
    op_rt_m_6(o, o, t + 0x30, t + 0x90, idx);
    if (!(o->h21A & 0x800)) {
        if (!(o->h21A & 0x200)) {
            func_002B56D8(t + 0xC0, m + 0x280, o);
        } else {
            func_002B5880(m + 0x30, m + 0x280, m + 0x30);
            op_m_copy(t + 0xC0, o);
        }
    } else {
        if (o->h21A & 0x200) {
            t += 0xC0;
            func_002B5750(t, m + 0x280, o);
            *(volatile u_long128 *)(t + 0x30) = *(u_long128 *)(m + 0x30);
        } else {
            op_m_copy(t + 0xC0, o);
        }
    }
    return p;
}

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

extern int D_003736A0[];

/* opu_motion_etc (ffx-rust): speed / end-motion commands of the unit's character */
u16 *func_002A5658(ScriptThread *th, u16 *pc)
{
    u8 *u = (u8 *)th->sub;
    Chr *c = owu_chr_hd[u[0x18]];

    switch ((s16)th->flags & 0xF000) {
    case 0:
        ((void (*)(Chr *, int))Ch_SetMotionSpeed)(c, pc[1]); /* DEBT(TYPE): callers pass the u16 unsigned */
        pc += 2;
        break;
    case 0x1000:
        func_002967E8(th, pc);
        pc += 1;
        MsEffectEndMotion(u[0x18], 0);
        break;
    case 0x2000:
        func_002967E8(th, pc);
        MsEffectEndMotion(u[0x18], D_003736A0[pc[1]]);
        pc += 2;
        break;
    }
    return pc;
}

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
