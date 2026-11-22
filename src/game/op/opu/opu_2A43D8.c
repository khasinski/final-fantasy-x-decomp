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

void func_002B6278(void *dst, void *a, void *b);
void func_002DD438(void *dst, void *a, void *b, void *c);
extern float D_0054B7A0[];

u16 *func_002A4540(ScriptThread *s2, u16 *s4)
{
    register u8 *s0 __asm__("$16") = (u8 *)s2 + 0x300;
    ScriptSub *s3 = s2->sub;
    register ScriptSub *s1 __asm__("$17") = opus_no_get(s0, s3, (s16)s4[1]);
    ScriptSub *a0 = opus_no_get(s0, s3, (s16)s4[2]);

    __asm__ volatile(
        "lui $2, 0x3F80\n\t"
        "lqc2 $vf31, 0x90(%0)\n\t"
        "lqc2 $vf30, 0x90(%1)\n\t"
        "vsub.xyzw $vf31, $vf30, $vf31\n\t"
        "sqc2 $vf31, 0x0(%2)\n\t"
        "sw $2, 0xC(%2)"
        : : "r"(s1), "r"(a0), "r"(s2) : "$2", "memory");
    if (s2->flags & 0x400) {
        __asm__ volatile("sq $0, 0x10(%0)" : : "r"(s2) : "memory");
        s0 = (u8 *)s2 + 0x40;
        func_002B6278(s0, (u8 *)s2 + 0x10, s2);
    } else {
        s0 = (u8 *)s2 + 0x40;
        func_002B6278(s0, (u8 *)s3 + 0x90, s2);
        __asm__ volatile(
            "lui $2, 0x3F80\n\t"
            "lqc2 $vf31, 0x90(%0)\n\t"
            "sqc2 $vf31, 0x30(%1)\n\t"
            "sw $2, 0x3C(%1)"
            : : "r"(s3), "r"(s0) : "$2", "memory");
    }
    if ((s16)s2->flags & 0x8000) {
        func_002B56D8((u8 *)s3 + 0xC0, (u8 *)s2 + 0x280, s0);
    } else if (s2->flags & 0x200) {
        func_002DD438((u8 *)s3 + 0xC0, (u8 *)s3 + 0x90, s2, D_0054B7A0);
    } else {
        op_m_copy((u8 *)s3 + 0xC0, s0);
    }
    return s4 + 3;
}

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

void func_002B6E20(void *md, u16 a, u16 b);
void op_md_tex0_reset(void *md, u64 tex0);
void op_md_vn_index(void *md, void *a1, void *a2);
void func_002B7590(void *md, void *m1, void *m2, void *m3, void *w);
void opus_md_tex0_reset_multi(int a, int lo, int hi, u64 arg);
extern int D_00373684;
extern float D_004F4010[];
extern float D_004F3FD0[];

u16 *func_002A4B40(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    int res = th->res[sub->b1E];
    void *md = op_oef2_a_get(res, 4, pc[1]);
    u64 tex0;

    switch ((s16)th->flags & 0xF000) {
    case 0x0000: {
        void *buf = (void *)op_malloc(*(void **)((u8 *)th + 0x3A8), op_md_size_get(md));
        op_md_copy(md, buf);
        op_oef2_a_set(res, 4, (s16)pc[2], (int)buf);
        pc += 3;
        break;
    }
    case 0x1000:
        op_free(*(void **)((u8 *)th + 0x3A8), md);
        pc += 2;
        break;
    case 0x2000: {
        u64 *t = (u64 *)op_oef2_a_get(res, 2, (s16)pc[2]);
        pc += 3;
        op_md_tex0_change(md, *t);
        break;
    }
    case 0x3000:
        func_002B6E20(md, pc[2], pc[3]);
        pc += 4;
        break;
    case 0x4000: {
        s16 *p = (s16 *)((u8 *)pc + (s16)pc[2]);
        register u64 t __asm__("$16");
        __asm__ volatile(
            "lh $2, 0(%1)\n\t"
            "lh $3, 4(%1)\n\t"
            "pextlh %0, $3, $2\n\t"
            "lh $2, 2(%1)\n\t"
            "lh $3, 6(%1)\n\t"
            "pextlh $2, $3, $2\n\t"
            "pextlh %0, $2, %0"
            : "=&r"(t) : "r"(p) : "$2", "$3");
        op_md_tex0_reset(md, t);
        pc += 3;
        break;
    }
    case 0x5000: {
        void *m = op_oef2_a_get(res, 4, (s16)pc[1]);
        void *m40, *mC0, *loc;
        if (D_00373684 == 0) {
            register int t __asm__("$3");
            op_md_vn_index(m, (void *)0x6800000, (void *)0x6C00000);
            t = D_00373684 + 1;
            D_00373684 = t;
        }
        m40 = (u8 *)th + 0x40;
        mC0 = (u8 *)th + 0xC0;
        pc += 2;
        op_unit_m_scale(th, *(float *)((u8 *)sub + 0x3C) * 0.000000476837158203125f);
        loc = opus_local_get(th, sub);
        func_002B56D8(m40, D_004F4010, D_004F3FD0);
        func_002B56D8(mC0, loc, th);
        func_002B56D8(mC0, D_004F4010, mC0);
        func_002B7590(m, mC0, th, m40, *(void **)((u8 *)th + 0x328));
        break;
    }
    case 0x6000: {
        s16 *p = (s16 *)((u8 *)pc + (s16)pc[3]);
        register u64 t __asm__("$16");
        __asm__ volatile(
            "lh $2, 0(%1)\n\t"
            "lh $3, 4(%1)\n\t"
            "pextlh %0, $3, $2\n\t"
            "lh $2, 2(%1)\n\t"
            "lh $3, 6(%1)\n\t"
            "pextlh $2, $3, $2\n\t"
            "pextlh %0, $2, %0"
            : "=&r"(t) : "r"(p) : "$2", "$3");
        opus_md_tex0_reset_multi(res, (s16)pc[1], (s16)pc[2], t);
        pc += 4;
        break;
    }
    }
    return pc;
}

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

u16 *ope_draw(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;

    switch ((s16)th->flags & 0xF000) {
    case 0x0000: {
        register u8 b __asm__("$3") = pc[1];
        sub->bBB = b;
        *(u16 *)((u8 *)sub + 0xA8) = pc[2];
        *(u16 *)((u8 *)sub + 0xAA) = pc[3];
        pc += 4;
        opus_draw_on((IdList *)th->obj300, th->h214);
        break;
    }
    case 0x1000:
        sub->hC0 = pc[1] | sub->hC0;
        pc += 2;
        break;
    case 0x2000:
        sub->bBB = pc[1];
        *(u16 **)((u8 *)sub + 0xA8) = pc + 3;
        opus_draw_on((IdList *)th->obj300, th->h214);
        pc = (u16 *)((u8 *)pc + (u16)((s16)pc[2] * 2) + 6);
        break;
    case 0x3000:
        sub->hC0 &= ~pc[1];
        pc += 2;
        break;
    case 0x4000:
        sub->bBB = 0;
        opus_draw_off((IdList *)th->obj300, th->h214);
        pc += 1;
        break;
    }
    return pc;
}

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

void func_002B52C0(void *a, void *b, void *c);
void func_002B5348(void *a, void *b, void *c, void *d);
void func_002A6E70(Chr *chr);
void opus_get_bone_matrix(void *dst, Chr *chr, int bone);
void opus_chara_matrix_jack(Chr *chr, int v);
void opus_rt_m_chara(void *dst, int id, float scale, void *a2, void *a3, int live);

u16 *func_002A5750(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    Chr *chr = owu_chr_hd[sub->b18];
    void *loc;

    func_00110AF0(chr);
    if (th->flags & 0x800) {
        loc = opus_local_get(th, sub);
    }
    switch (th->flags & 0xF000) {
    case 0x0000:
    case 0x4000:
do_chara:
        opus_rt_m_chara(th, sub->b18, *(float *)((u8 *)sub + 0x3C), 0, 0, th->b21E);
        if (th->flags & 0x4000) {
            func_002B52C0(th, th, (u8 *)sub + 0x30);
        } else {
            func_002B5348(th, th, (u8 *)sub + 0x30, (u8 *)sub + 0x90);
        }
        if (th->flags & 0x800) {
            func_002B56D8((u8 *)sub + 0xC0, loc, th);
        } else {
            op_m_copy((u8 *)sub + 0xC0, th);
        }
        opus_chara_matrix_jack(chr, (int)((u8 *)sub + 0xC0));
        pc += 1;
        break;
    case 0x1000:
        func_002A6E70(chr);
        pc += 1;
        break;
    case 0x2000:
    case 0x5000:
        loc = opus_local_get(th, sub);
        if (((s16)th->flags & 0xF000) == 0x2000) {
            th->flags = 0x800;
        } else {
            th->flags = 0x4800;
        }
        goto do_chara;
    case 0x6000: {
        void *m100 = (u8 *)th + 0x100;
        opus_rt_m_chara(m100, sub->b18, *(float *)((u8 *)sub + 0x3C), 0, 0, th->b21E);
        func_002B5348(th, m100, (u8 *)sub + 0x30, (u8 *)sub + 0x90);
        if (th->flags & 0x800) {
            func_002B56D8(th, loc, th);
        }
        opus_get_bone_matrix((u8 *)th + 0x80, chr, 0x8001);
        if (((int (*)(int))func_002966E8)(sub->b18) == 0) {
            func_002B5880((u8 *)th + 0x50, m100, (u8 *)th + 0xB0);
            func_002B5880((u8 *)th + 0x40, th, (u8 *)th + 0xB0);
            *(float *)((u8 *)th + 0x34) -= (*(float *)((u8 *)th + 0x44) - *(float *)((u8 *)th + 0x34)) * 0.5f;
            *(float *)((u8 *)th + 0x30) -= (*(float *)((u8 *)th + 0x40) - *(float *)((u8 *)th + 0x30)) * 0.5f;
            *(float *)((u8 *)th + 0x38) -= (*(float *)((u8 *)th + 0x48) - *(float *)((u8 *)th + 0x38)) * 0.5f;
            *(float *)((u8 *)th + 0x34) += *(float *)((u8 *)th + 0x54) * 0.5f;
        }
        op_m_copy((u8 *)sub + 0xC0, th);
        pc += 1;
        opus_chara_matrix_jack(chr, (int)((u8 *)sub + 0xC0));
        break;
    }
    case 0x7000: {
        float xz = *(float *)((u8 *)sub + 0x3C) * 0.00390625f * 0.001f;
        *(float *)((u8 *)th + 0x48) = xz;
        *(float *)((u8 *)th + 0x40) = xz;
        *(float *)((u8 *)th + 0x44) = *(float *)((u8 *)sub + 0x4C) * 0.00390625f * 0.001f;
        op_unit_m_scale2(th, (u8 *)th + 0x40);
        func_002B5348(th, th, (u8 *)sub + 0x30, (u8 *)sub + 0x90);
do_jack:
        if (th->flags & 0x800) {
            func_002B56D8((u8 *)sub + 0xC0, loc, th);
        } else {
            op_m_copy((u8 *)sub + 0xC0, th);
        }
        opus_chara_matrix_jack(chr, (int)((u8 *)sub + 0xC0));
        pc += 1;
        break;
    }
    }
    return pc;
}

float func_00110AF0(Chr *chr);
int func_002B3D68(int n);
int opus_get_bone_vertex(Vec4 *v, Chr *chr, int bone);
extern float eff_sin_t[];
extern u8 D_00373688[];

u16 *opu_v_en_bone(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    int flag1 = th->flags & 1;
    u16 bone = pc[1];
    Chr *chr = owu_chr_hd[sub->b18];
    float scale = func_00110AF0(chr);
    float f;
    float *p30;
    int max_bone;
    int tmp0;

    switch (((s16)th->flags & 0xF000) >> 12) {
    case 0:
        if (flag1) {
            opus_get_bone_vertex((Vec4 *)th, chr, bone);
            func_002B5978((u8 *)sub + 0x40, th, 16.0f);
        } else {
            Ch_ElemGetBaseMatrix(chr, bone, th);
            func_002B5978((u8 *)sub + 0x40, (u8 *)th + 0x30, 0.016f);
        }
        pc += 2;
        break;
    case 1:
        p30 = (float *)((u8 *)sub + 0x30);
    case1_body:
        if (flag1) {
            void *m40 = (u8 *)th + 0x40;
            void *m80 = (u8 *)th + 0x80;
            opus_chara_root_m_get(th, chr);
            opus_get_bone_matrix(m40, chr, bone);
            func_002B56D8(th, th, m40);
            func_002B5978(m80, p30, 10.0f / scale);
            func_002B5880(m40, th, m80);
            func_002B5978((u8 *)sub + 0x40, m40, 16.0f);
        } else {
            void *m40 = (u8 *)th + 0x40;
            void *m80 = (u8 *)th + 0x80;
            opus_get_bone_matrix(m40, chr, bone);
            func_002B5978(m80, p30, 10.0f / scale);
            func_002B5880(m40, th, m80);
            func_002B5978((u8 *)sub + 0x40, m40, 0.016f);
        }
        pc += 2;
        break;
    case 2:
        if (flag1) {
            Ch_OptposGet(chr, bone, th);
            func_002B5978((u8 *)sub + 0x40, th, 16.0f);
        }
        pc += 2;
        break;
    case 3: {
        int n = func_0010B948(chr);
        max_bone = n - 1;
        if (max_bone >= 4) {
            bone = func_002B3D68(n - 5) + 4;
        } else {
            bone = max_bone;
        }
        if ((int)bone > max_bone) {
            bone = max_bone;
        }
        if (flag1) {
            opus_chara_root_m_get(th, chr);
            opus_get_bone_matrix((u8 *)th + 0x40, chr, bone);
            func_002B5880(th, th, (u8 *)th + 0x70);
            func_002B5978((u8 *)sub + 0x40, th, 16.0f);
        }
        pc += 1;
        break;
    }
    case 4: {
        register float *v __asm__("$2") = (float *)((u8 *)sub + 0x30);
        __asm__("" : "+r"(v));
        p30 = v;
        f = p30[bone];
        bone = (u16)(int)f;
        goto case1_body;
    }
    case 5:
        f = (s16)pc[2];
        *(float *)((u8 *)th + 0xC0) = f;
        f = (s16)pc[3];
        *(float *)((u8 *)th + 0xC4) = f;
        f = (s16)pc[4];
        *(float *)((u8 *)th + 0xC8) = f;
        func_002B5978((u8 *)th + 0xC0, (u8 *)th + 0xC0, 10.0f / scale);
        if (flag1) {
            opus_chara_root_m_get(th, chr);
            opus_get_bone_matrix((u8 *)th + 0x40, chr, bone);
            func_002B56D8(th, th, (u8 *)th + 0x40);
            func_002B5880((u8 *)th + 0x40, th, (u8 *)th + 0xC0);
            func_002B5978((u8 *)sub + 0x40, (u8 *)th + 0x40, 16.0f);
        } else {
            opus_get_bone_matrix((u8 *)th + 0x40, chr, bone);
            func_002B5880((u8 *)th + 0x40, th, (u8 *)th + 0xC0);
            func_002B5978((u8 *)sub + 0x40, (u8 *)th + 0x40, 0.016f);
        }
        pc += 5;
        break;
    case 6: {
        register int a3 __asm__("$7") = func_0010B948(chr) - 1;
        __asm__("" : "+r"(a3));
        max_bone = a3;
        tmp0 = (s16)pc[2];
        if (tmp0 < a3) {
            a3 = tmp0;
        }
        tmp0 = (s16)pc[1];
        bone = func_002B3D68(a3 - tmp0) + tmp0;
        if ((int)bone > max_bone) {
            bone = max_bone;
        }
        if (flag1) {
            func_00107428(chr, bone, 0, th);
            func_002B5978((u8 *)sub + 0x40, th, 16.0f);
        }
        pc += 3;
        break;
    }
    case 7: {
        s16 *tbl = (s16 *)((u8 *)pc + (s16)pc[1]);
        s16 idx;
        tmp0 = tbl[0];
        idx = func_002B3D68(tmp0);
        if (idx >= tmp0) {
            idx = tmp0 - 1;
        }
        bone = (u16)tbl[idx + 1];
        if (flag1) {
            func_00107428(chr, bone, 0, th);
            func_002B5978((u8 *)sub + 0x40, th, 16.0f);
        }
        pc += 2;
        break;
    }
    case 8: {
        register int ang __asm__("$7");
        u8 *pC0;
        register u8 b __asm__("$3") = sub->bB2;

        ang = *(u32 *)((u8 *)sub + 0x48);
        __asm__ volatile(
            "qmtc2.ni %0, $vf31\n\t"
            "vftoi0.xyzw $vf31, $vf31\n\t"
            "qmfc2.ni %0, $vf31"
            : "+r"(ang));
        ang &= 0xFFF;
        {
            register float *sin_tbl __asm__("$4");
            __asm__ volatile(
                "lui %0, %%hi(eff_sin_t)\n\t"
                "ori %1, %1, 4\n\t"
                "addiu %0, %0, %%lo(eff_sin_t)"
                : "=&r"(sin_tbl), "+r"(b));
            sub->bB2 = b;
            f = sin_tbl[ang];
            *(float *)((u8 *)th + 0x0) = (f * *(float *)((u8 *)sub + 0x40) * 0.0625f) / 0.001f;
            {
                register int tmp_ang __asm__("$3") = ang + 0x400;
                ang = tmp_ang & 0xFFF;
            }
            {
                register int sh __asm__("$2") = ang << 2;
                f = *(float *)((u32)sh + (u32)sin_tbl);
            }
        }
        *(float *)((u8 *)th + 0x8) = (f * *(float *)((u8 *)sub + 0x40) * 0.0625f) / 0.001f;
        *(float *)((u8 *)th + 0x4) = (*(float *)((u8 *)sub + 0x44) * 0.0625f) / 0.001f;
        pC0 = (u8 *)th + 0xC0;
        {
            register int oidx __asm__("$2") = ((s16)pc[2] << 18) >> 16;
            register u8 *p0 __asm__("$3");
            register int i1 __asm__("$6");
            register int i2 __asm__("$2");
            register u8 *p1 __asm__("$6");
            register u8 *p2 __asm__("$2");
            register u32 b0 __asm__("$7");
            register float *fp __asm__("$3");
            register float *fp2 __asm__("$2");

            __asm__("" : "+r"(oidx));
            p0 = D_00373688 + oidx;
            i1 = oidx + 1;
            b0 = *p0;
            p1 = i1 + D_00373688;
            i2 = oidx + 2;
            __asm__("" : "+r"(i2) : "r"(p1));
            b0 <<= 2;
            p2 = i2 + D_00373688;
            __asm__("" : "+r"(p2) : "r"(b0));
            __asm__("" : "+r"(b0) : "r"(p2));
            fp = (float *)(pC0 + b0);
            __asm__("" : "+r"(fp));
            *fp = *(float *)((u8 *)th + 0x0);
            b0 = *p1 << 2;
            fp = (float *)(pC0 + b0);
            __asm__("" : "+r"(fp));
            *fp = *(float *)((u8 *)th + 0x4);
            {
                register u32 b2 __asm__("$6") = *p2;
                b0 = b2 << 2;
            }
            fp2 = (float *)(pC0 + b0);
            __asm__("" : "+r"(fp2));
            *fp2 = *(float *)((u8 *)th + 0x8);
        }
        opus_chara_root_m_get(th, chr);
        opus_get_bone_matrix((u8 *)th + 0x40, chr, (s16)pc[1]);
        func_002B56D8(th, th, (u8 *)th + 0x40);
        func_002B5978(pC0, pC0, 10.0f / scale);
        func_002B5880((u8 *)sub + 0x90, th, pC0);
        return pc + 3;
    }
    case 9:
        func_002967E8(th, pc);
        chr = (Chr *)MsGetWeaponHandle(sub->b18, 0);
        if (chr != 0) {
            f = *(float *)((u8 *)sub + (s16)pc[1]);
            f *= 0.00390625f;
            opus_chara_root_m_get(th, chr);
            opus_get_bone_matrix((u8 *)th + 0x40, chr, (s16)pc[2]);
            opus_get_bone_matrix((u8 *)th + 0x80, chr, (s16)pc[3]);
            func_002B56D8((u8 *)th + 0xC0, th, (u8 *)th + 0x70);
            func_002B56D8((u8 *)th + 0xD0, th, (u8 *)th + 0xB0);
            __asm__ volatile(
                "lqc2 $vf24, 0xC0(%0)\n\t"
                "lqc2 $vf25, 0xD0(%0)\n\t"
                "mfc1 $2, %2\n\t"
                "qmtc2.ni $2, $vf26\n\t"
                "lui $3, 0x4180\n\t"
                "qmtc2.ni $3, $vf27\n\t"
                "vsub.xyz $vf31, $vf25, $vf24\n\t"
                "vmulx.xyz $vf31, $vf31, $vf26x\n\t"
                "vadd.xyz $vf31, $vf31, $vf24\n\t"
                "vmulx.xyz $vf31, $vf31, $vf27x\n\t"
                "sqc2 $vf31, 0x40(%1)"
                :
                : "r"(th), "r"(sub), "f"(f)
                : "$2", "$3", "memory");
        }
        pc += 4;
        break;
    case 10:
        f = *(float *)((u8 *)sub + (s16)pc[1]);
        opus_get_bone_vertex((Vec4 *)th, chr, (u16)(int)f);
        pc += 2;
        func_002B5978((u8 *)sub + 0x40, th, 16.0f);
        break;
    default:
        func_002967E8(th, pc);
        func_001B6790(sub->b18, th);
        func_002B5978((u8 *)sub + 0x40, th, 16.0f);
        *(float *)((u8 *)sub + 0x44) -= 256.0f;
        break;
    }
    func_002B5978((u8 *)sub + 0x90, (u8 *)sub + 0x40, 0.0625f);
    return pc;
}

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

u16 *func_002A6878(ScriptThread *s2, u16 *s3)
{
    ScriptSub *s4 = s2->sub;
    Chr *s5 = owu_chr_hd[s4->b18];
    int s0;
    void *m40, *m80, *mC0;

    switch ((s16)s2->flags & 0xF000) {
    case 0x0000:
        func_002967E8(s2, s3);
        s0 = (s16)s3[1];
        break;
    case 0x1000:
        func_002967E8(s2, s3);
        s0 = (int)*(float *)((u8 *)s4 + ((u8 *)s3)[2]);
        break;
    default:
        return s3;
    }
    opus_chara_root_m_get(s2, s5);
    m40 = (u8 *)s2 + 0x40;
    opus_get_bone_matrix(m40, s5, s0);
    m80 = (u8 *)s2 + 0x80;
    func_002B56D8(s2, s2, m40);
    mC0 = (u8 *)s2 + 0xC0;
    op_unit_m_scale(m80, 999.99993896484375f);
    func_002B5978((float *)mC0, (float *)((u8 *)s4 + 0x90), 999.99993896484375f);
    func_002B5348(m80, m80, (u8 *)s4 + 0x30, mC0);
    func_002B56D8(s2, s2, m80);
    __asm__ volatile(
        "move $2, %0\n\t"
        "addiu $3, $0, 3\n"
        "1:\n\t"
        "lqc2 $vf31, 0($2)\n\t"
        "vmul.xyz $vf30, $vf31, $vf31\n\t"
        "vaddy.x $vf30, $vf30, $vf30y\n\t"
        "vaddz.x $vf30, $vf30, $vf30z\n\t"
        "vsqrt Q, $vf30x\n\t"
        "vwaitq\n\t"
        "vaddq.x $vf30, $vf0, Q\n\t"
        "vdiv Q, $vf0w, $vf30x\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf29, $vf31, Q\n\t"
        "sqc2 $vf29, 0($2)\n\t"
        ".set noreorder\n\t"
        "addi $3, $3, -1\n\t"
        "bnez $3, 1b\n\t"
        "addiu $2, $2, 16\n\t"
        "nop\n\t"
        ".set reorder"
        : : "r"(s2) : "$2", "$3", "memory");
    s3 += 2;
    func_002B56D8((u8 *)s4 + 0xC0, (u8 *)s2 + 0x280, s2);
    return s3;
}

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
