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

void opus_get_bone_matrix(void *dst, Chr *chr, int bone);
void opus_chara_root_m_get(void *dst, Chr *chr);
void opus_chara_matrix_jack(Chr *chr, int v);
void func_002B52C0(void *a, void *b, void *c);
void func_002B5318(void *a, void *b, void *c);

u16 *func_002A4680(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    Chr *chr = owu_chr_hd[sub->b18];
    u16 save_b8;
    void *p;

    switch ((s16)th->flags & 0xF000) {
    case 0:
        save_b8 = *(u16 *)((u8 *)sub + 0xB8);
        *(u16 *)((u8 *)sub + 0xB8) = pc[1];
        p = opus_local_get(th, sub);
        pc += 2;
        func_002DCF48(th, p);
        func_002B5880((u8 *)sub + 0x90, th, (u8 *)sub + 0x90);
        func_002B5978((float *)((u8 *)sub + 0x40), (float *)((u8 *)sub + 0x90), 16.0f);
        *(u16 *)((u8 *)sub + 0xB8) = save_b8;
        break;
    case 0x1000:
        opus_get_bone_matrix((u8 *)sub + 0xC0, chr, (s16)pc[1]);
        pc += 2;
        break;
    case 0x5000:
        opus_chara_root_m_get(th, chr);
        p = (u8 *)th + 0x40;
        opus_get_bone_matrix(p, chr, (s16)pc[1]);
        pc += 2;
        func_002B56D8((u8 *)sub + 0xC0, th, p);
        break;
    case 0x2000:
        func_002B5880((u8 *)sub + 0xF0, (u8 *)sub + 0xC0, (u8 *)sub + 0x90);
        pc += 1;
        break;
    case 0x3000:
        pc += 1;
        func_002B56D8((u8 *)sub + 0xC0, (u8 *)sub + 0xC0, (u8 *)th + 0x280);
        break;
    case 0x4000:
        pc += 1;
        func_002B5318((u8 *)sub + 0xC0, (u8 *)sub + 0xC0, (u8 *)sub + 0x90);
        break;
    case 0x6000:
        opus_chara_matrix_jack(chr, (int)((u8 *)sub + 0xC0));
        pc += 1;
        break;
    case 0x7000:
        op_unit_m(th);
        pc += 1;
        func_002B52C0(th, th, (u8 *)sub + 0x30);
        func_002B56D8((u8 *)sub + 0xC0, (u8 *)sub + 0xC0, th);
        break;
    case 0x8000:
        opus_chara_root_m_get(th, chr);
        pc += 1;
        func_002B56D8((u8 *)sub + 0xC0, th, (u8 *)sub + 0xC0);
        break;
    }
    return pc;
}

/* DEBT(NAME): module and names guessed: object field helpers (see w10.h). */
void *opus_local_get(ScriptThread *a0, ScriptSub *a1)
{
    u8 *th = (u8 *)a0;
    u8 *sub = (u8 *)a1;
    s16 id = *(s16 *)(sub + 0xB8);
    u8 *obj300 = th + 0x300;
    s16 *p;
    int idx;

    if (id == 0) {
        return th + 0x280;
    }
    if (id >= 0) {
search:
        p = *(s16 **)(obj300 + 0x14);
        for (idx = *p; idx >= 0; idx = *++p) {
            sub = *(u8 **)(obj300 + 0x20) + (idx << 8);
            if (*(u16 *)(sub + 0x1A) == id) {
                return sub + 0xC0;
            }
        }
        p = *(s16 **)(obj300 + 0x10);
        for (idx = *p; idx >= 0; idx = *++p) {
            sub = *(u8 **)(obj300 + 0x20) + (idx << 8);
            if (*(u16 *)(sub + 0x1A) == id) {
                return sub + 0xC0;
            }
        }
        p = *(s16 **)(obj300 + 0x18);
        for (idx = *p; idx >= 0; idx = *++p) {
            sub = *(u8 **)(obj300 + 0x20) + (idx << 8);
            if (*(u16 *)(sub + 0x1A) == id) {
                return sub + 0xC0;
            }
        }
        return *(u8 **)(obj300 + 0x20) + 0xC0;
    }
    if (id == -0x100) {
        return sub + 0xC0;
    }
    if (id == -1) {
        sub = *(u8 **)(obj300 + 0x20) + (*(u16 *)(sub + 0x1C) << 8);
        return sub + 0xC0;
    }
    if ((id & 0xFF00) == 0xFE00) {
        SlotEntry *e = &owu_eff_status[*(u16 *)(sub + 0x14)];
        sub = (u8 *)e->sub;
        id = (*(u16 *)(sub + 0x1A) & 0x7FF0) | (id & 0xF);
        goto search;
    }
    for (; id < 0; id++) {
        sub = *(u8 **)(obj300 + 0x20) + (*(u16 *)(sub + 0x1C) << 8);
    }
    return sub + 0xC0;
}

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

u16 *opu_part_init(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    int res = th->res[sub->b1E];
    int (**ops)(void *);
    float h, w;
    int v;

    switch ((s16)th->flags & 0xF000) {
    case 0:
        v = (s16)pc[2];
        *(int **)((u8 *)sub + 0xD0) = op_oef2_a_get(res, 8, (s16)pc[1]);
        *((u8 *)sub + 0xD4) = v;
        *(float *)((u8 *)sub + 0xDC) = (s16)pc[3] * 0.00390625f;
        pc += 4;
        ops = (int (**)(void *))(*(u8 **)((u8 *)th + 0x350) + 0x40);
        ops[0](sub);
        ops[1](sub);
        sub->bBB = 3;
        break;
    case 0x1000:
        func_002967E8(th, pc);
        h = MsGetChrHeight(sub->b18);
        w = MsGetChrWidth(sub->b18);
        if (h < w) {
            h = w;
        }
        h /= 18.0f;
        pc += 1;
        *(float *)((u8 *)sub + 0xDC) *= h;
        break;
    case 0x2000:
        v = func_002B7388(op_oef2_a_get(res, 8, (s16)pc[1]), (s16)pc[2]);
        op_oef2_a_set(res, 4, (s16)pc[3], v);
        pc += 4;
        break;
    }
    return pc;
}

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

u16 *func_002A6758(ScriptThread *th, u16 *pc)
{
    u_long128 buf[64];
    ScriptSub *sub = th->sub;

    switch ((s16)th->flags & 0xF000) {
    case 0:
        ((void (*)(Chr *, s16))Ch_DrawSetSituation)(owu_chr_hd[sub->b18], (s16)pc[1]);
        pc += 2;
        break;
    case 0x1000:
        func_00295CF8((u_long128 *)th, buf);
        func_00103788((s16)pc[1]);
        pc += 2;
        func_00295D28((u_long128 *)th, buf);
        break;
    case 0x2000:
        Ch_EnClip(owu_chr_hd[sub->b18], 1);
        pc += 1;
        break;
    case 0x3000:
        Ch_EnClip(owu_chr_hd[sub->b18], 0);
        pc += 1;
        break;
    }
    return pc;
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A43D8", func_002A6878);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A43D8", opu_mdc_break);

#include "vu0.h"

void opus_get_bone_matrix(void *dst, Chr *chr, int bone)
{
    Vec4 sp;
    u8 *d = dst;

    if (bone & 0x8000) {
        Ch_ElemGetBaseMatrix(chr, Ch_OptposGetElement((int)chr, bone & 0xFF, (int)&sp), d);
        func_002B5880(d + 0x30, d, &sp);
    } else {
        Ch_ElemGetBaseMatrix(chr, bone, dst);
        MMI_SQ_ZERO(0x40, d);
    }
}

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

void func_002B52C0(void *a, void *b, void *c);
void func_002B5318(void *a, void *b, void *c);
void func_002B5348(void *a, void *b, void *c, void *d);

void opus_rt_m_chara(void *dst, int id, float scale, void *a2, void *a3, int live)
{
    Vec4 v;
    Chr *chr = owu_chr_hd[id];

    if (live != 0 && id < 0x20) {
        MsGetChrScale(id, &v);
    } else {
        v.x = Ch_GetScaleX(chr);
        v.y = Ch_GetScaleY(chr);
        v.z = Ch_GetScaleZ(chr);
    }
    func_002B5978((float *)&v, (float *)&v, func_00110AF0(chr) * scale * 0.001f * 0.00390625f);
    op_unit_m_scale2(dst, &v);
    if (a2 != 0) {
        if (a3 != 0) {
            func_002B5348(dst, dst, a2, a3);
            return;
        }
        func_002B52C0(dst, dst, a2);
    }
    if (a3 != 0) {
        func_002B5318(dst, dst, a3);
    }
}
