/* tu_318 0x29dc40-0x2a0618: low; ~opu; split at 0x2a0618: flag split: 0x2A0618-0x2A0718 needs -Btools/cc/ee-as-delay/ -Wa,-mips4 (config/cflags.txt), func_0029FD20 does not (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#define opu_v_get _hdr_opu_v_get
#define opus_v_en_all _hdr_opus_v_en_all
#define opus_v_chara_all _hdr_opus_v_chara_all
#include "common.h"
#include "vu0.h"
#include "ffx/q7.h"
#include "ffx/r6.h"
#include "ffx/s6.h"
#include "ffx/t6.h"
#undef opu_v_get
#undef opus_v_en_all
#undef opus_v_chara_all

u16 *func_0029DC40(ScriptThread *th, u16 *pc)
{
    R6Th300 *t = R6_TH300(th);
    ScriptSub *sub = th->sub;
    u32 mask = pc[1];
    int n;

    if ((s16)th->flags & 0x8000) {
        mask <<= 16;
    }
    switch ((th->flags & 0x7000) >> 12) {
    case 0:
        t->flags4 |= mask;
        pc += 2;
        break;
    case 1:
        t->flags4 &= ~mask;
        pc += 2;
        break;
    case 2:
        if (t->flags4 & mask) {
            pc = SCRIPT_JUMP_AT(pc, 2);
        } else {
            pc += 3;
        }
        break;
    case 3:
        if (!(t->flags4 & mask)) {
            pc = SCRIPT_JUMP_AT(pc, 2);
        } else {
            pc += 3;
        }
        break;
    case 4:
        if (t->flags4 & mask) {
            th->f210 = 1;
        } else {
            pc += 2;
        }
        break;
    case 5:
        if (t->flags4 & mask) {
            pc += 2;
        } else {
            th->f210 = 1;
        }
        break;
    case 6:
        n = opus_en_index(sub) + 1;
        if (owu_eff_status[sub->h14].b8 == n) {
            t->flags4 |= mask;
        }
        pc += 2;
        break;
    }
    return pc;
}

u16 *func_0029DD98(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    s16 mask = pc[1];
    int n;

    switch ((th->flags & 0x7000) >> 12) {
    case 0:
        sub->hB0 |= mask;
        pc += 2;
        break;
    case 1:
        sub->hB0 &= ~mask;
        pc += 2;
        break;
    case 2:
        if (sub->hB0 & mask) {
            pc = SCRIPT_JUMP_AT(pc, 2);
        } else {
            pc += 3;
        }
        break;
    case 3:
        if (!(sub->hB0 & mask)) {
            pc = SCRIPT_JUMP_AT(pc, 2);
        } else {
            pc += 3;
        }
        break;
    case 4:
        if (sub->hB0 & mask) {
            th->f210 = 1;
        } else {
            pc += 2;
        }
        break;
    case 5:
        if (sub->hB0 & mask) {
            pc += 2;
        } else {
            th->f210 = 1;
        }
        break;
    case 6:
        n = opus_en_index(sub) + 1;
        if (owu_eff_status[sub->h14].b8 == n) {
            sub->hB0 |= mask;
        }
        pc += 2;
        break;
    }
    return pc;
}

u16 *func_0029DED8(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = opus_no_get(th->obj300, th->sub, (s16)pc[1]);
    s16 mask = pc[2];
    int n;

    switch ((th->flags & 0x7000) >> 12) {
    case 0:
        sub->hB0 |= mask;
        pc += 3;
        break;
    case 1:
        sub->hB0 &= ~mask;
        pc += 3;
        break;
    case 2:
        if (sub->hB0 & mask) {
            pc = SCRIPT_JUMP_AT(pc, 3);
        } else {
            pc += 4;
        }
        break;
    case 3:
        if (!(sub->hB0 & mask)) {
            pc = SCRIPT_JUMP_AT(pc, 3);
        } else {
            pc += 4;
        }
        break;
    case 4:
        if (sub->hB0 & mask) {
            th->f210 = 1;
        } else {
            pc += 3;
        }
        break;
    case 5:
        if (sub->hB0 & mask) {
            pc += 3;
        } else {
            th->f210 = 1;
        }
        break;
    case 6:
        n = opus_en_index(sub) + 1;
        if (owu_eff_status[sub->h14].b8 == n) {
            sub->hB0 |= mask;
        }
        pc += 3;
        break;
    }
    return pc;
}

u16 *func_0029E030(ScriptThread *th, u16 *pc)
{
    SlotEntry *e = &owu_eff_status[th->sub->h14];
    u32 mask = pc[1] | (pc[2] << 16);

    switch ((th->flags & 0x7000) >> 12) {
    case 0:
        e->wC |= mask;
        pc += 3;
        break;
    case 1:
        e->wC &= ~mask;
        pc += 3;
        break;
    case 2:
        if (e->wC & mask) {
            pc = SCRIPT_JUMP_AT(pc, 3);
        } else {
            pc += 4;
        }
        break;
    case 3:
        if (!(e->wC & mask)) {
            pc = SCRIPT_JUMP_AT(pc, 3);
        } else {
            pc += 4;
        }
        break;
    case 4:
        if (e->wC & mask) {
            th->f210 = 1;
        } else {
            pc += 3;
        }
        break;
    case 5:
        if (!(e->wC & mask)) {
            th->f210 = 1;
        } else {
            pc += 3;
        }
        break;
    }
    return pc;
}

u16 *opu_level(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    int level;
    int sig;
    u16 val;

    if (!((s16)th->flags & 0x8000)) {
        level = (u8)func_00110B78(owu_chr_hd[sub->b18]);
    } else {
        func_002967E8(th, pc);
        sig = MsGetChrMotionSignal(sub->b18);
    }
    val = pc[1];
    switch ((s16)th->flags & 0xF000) {
    case 0x0000:
        if ((u16)level == val) {
            pc = SCRIPT_JUMP_AT(pc, 2);
        } else {
            pc += 3;
        }
        break;
    case 0x1000:
        if ((u16)level == val) {
            pc += 3;
        } else {
            pc = SCRIPT_JUMP_AT(pc, 2);
        }
        break;
    case 0x2000:
        if (level & val) {
            pc = SCRIPT_JUMP_AT(pc, 2);
        } else {
            pc += 3;
        }
        break;
    case 0x3000:
        if (level & val) {
            pc += 3;
        } else {
            pc = SCRIPT_JUMP_AT(pc, 2);
        }
        break;
    case 0x4000:
        if ((u16)level == val) {
            th->f210 = 1;
        } else {
            pc += 2;
        }
        break;
    case 0x5000:
        if ((u16)level != val) {
            th->f210 = 1;
        } else {
            pc += 2;
        }
        break;
    case 0x6000:
        Ch_EffectSetEffectLevel(owu_chr_hd[sub->b18], val);
        pc += 2;
        break;
    case 0x8000:
        if (sig & val) {
            pc = SCRIPT_JUMP_AT(pc, 2);
        } else {
            pc += 3;
        }
        break;
    case 0x9000:
        if (sig & val) {
            pc += 3;
        } else {
            pc = SCRIPT_JUMP_AT(pc, 2);
        }
        break;
    case 0xA000:
        if (sig & val) {
            th->f210 = 1;
        } else {
            pc += 2;
        }
        break;
    case 0xB000:
        if (sig & val) {
            pc += 2;
        } else {
            th->f210 = 1;
        }
        break;
    }
    return pc;
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40", func_0029E360);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40", opu_v_256);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40", func_0029E598);

void opu_vran_256(void) {
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40", func_0029E6F0);

typedef struct OpuSubClear {
    u8 pad00[0x30];
    s64 q30;
    s32 w38;
    s32 w3C;
    s64 q40;
    s32 w48;
    s32 w4C;
    s64 q50;
    s32 w58;
    s32 w5C;
    s64 q60;
    s32 w68;
    s32 w6C;
    s64 q70;
    s32 w78;
    s32 w7C;
    s64 q80;
    s32 w88;
    s32 w8C;
    u8 pad90[0x2A];
    u8 bBA;
} OpuSubClear;

extern void (*_opu_jtbl_00373518[])(ScriptThread *, u16 *) __asm__("jtbl_00373518");

u16 *func_0029E8F0(ScriptThread *th, u16 *pc)
{
    OpuSubClear *sub = (OpuSubClear *)th->sub;

    switch ((s16)th->flags & 0xF000) {
    case 0x0000:
        MMI_SQ_ZERO(0x30, sub);
        MMI_SQ_ZERO(0x40, sub);
        _opu_jtbl_00373518[sub->bBA](th, pc);
        break;
    case 0x1000:
        sub->q40 = 0;
        sub->w48 = 0;
        _opu_jtbl_00373518[sub->bBA](th, pc);
        break;
    case 0x2000:
        sub->q30 = 0;
        sub->w38 = 0;
        _opu_jtbl_00373518[sub->bBA](th, pc);
        break;
    case 0x4000:
        MMI_SQ_ZERO(0x50, sub);
        MMI_SQ_ZERO(0x60, sub);
        MMI_SQ_ZERO(0x70, sub);
        MMI_SQ_ZERO(0x80, sub);
        break;
    case 0x5000:
        sub->q60 = 0;
        sub->w68 = 0;
        sub->q80 = 0;
        sub->w88 = 0;
        break;
    case 0x6000:
        sub->q50 = 0;
        sub->w58 = 0;
        sub->q70 = 0;
        sub->w78 = 0;
        break;
    }
    return pc + 1;
}

u16 *opu_v_get(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    ScriptSub *tgt = opus_no_get(th->obj300, sub, (s16)pc[2]);
    s16 op = pc[1];
    int ofs = ((op & 7) << 4) + 0x30;
    int *src = (int *)((char *)tgt + ofs);
    int *dst = (int *)((char *)sub + ofs);
    s16 fx;
    s16 fy;
    s16 fz;

    fx = op & 0x1000;
    if (fx) {
        dst[0] = src[0];
    }
    fy = op & 0x2000;
    if (fy) {
        dst[1] = src[1];
    }
    fz = op & 0x4000;
    if (fz) {
        dst[2] = src[2];
    }
    if (op & 0x8000) {
        dst[3] = src[3];
    }
    if (op & 0x10) {
        if (fx) {
            sub->f90 = tgt->f90;
        }
        if (fy) {
            sub->f94 = tgt->f94;
        }
        if (fz) {
            sub->f98 = tgt->f98;
        }
    }
    return pc + 3;
}

int _opu_func_002A06A0(int id, float *out) __asm__("func_002A06A0");
float _opu_func_002965F8(int id, int v) __asm__("func_002965F8");
int _opu_MsGetChrFly(int id) __asm__("MsGetChrFly");
int _opu_func_001ADA00(void) __asm__("func_001ADA00");
void _opu_opus_get_bone_vertex(float *out, Chr *chr, int id) __asm__("opus_get_bone_vertex");
void _opu_MsGetChrBtlPos(int id, float *out) __asm__("MsGetChrBtlPos");
int _opu_func_002966E8(int id) __asm__("func_002966E8");

u16 *opu_v_en(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    float h;
    int bone;

    switch ((s16)th->flags & 0xF000) {
    case 0x0000:
        _opu_func_002A06A0(sub->b18, th->v00);
        func_002B5978(sub->v40, th->v00, 16.0f);
        break;
    case 0x1000:
        h = _opu_func_002965F8(sub->b18, th->b21E) * 0.5f;
        _opu_func_002A06A0(sub->b18, th->v00);
        if (th->b21E != 0 && _opu_MsGetChrFly(sub->b18) == 0 && _opu_func_001ADA00() == 0) {
            th->v00[1] -= h;
        }
        _opu_opus_get_bone_vertex(th->v10, owu_chr_hd[sub->b18], 0x8003);
        th->v00[0] = th->v10[0];
        th->v00[2] = th->v10[2];
        func_002B5978(sub->v40, th->v00, 16.0f);
        break;
    case 0x2000:
        func_002967E8(th, pc);
        opus_v_en_all(&owu_eff_status[sub->h14], th->v00, 0);
        func_002B5978(sub->v40, th->v00, 16.0f);
        break;
    case 0x3000:
        func_002967E8(th, pc);
        _opu_MsGetChrBtlPos(sub->b18, th->v00);
        func_002B5978(sub->v40, th->v00, 16.0f);
        break;
    case 0x4000:
        _opu_func_002A06A0(sub->b18, th->v00);
        h = _opu_func_002965F8(sub->b18, th->b21E) * 0.5f;
        if (_opu_func_002966E8(sub->b18) != 0) {
            th->v00[1] += h;
        }
        func_002B5978(sub->v40, th->v00, 16.0f);
        break;
    case 0x5000:
        func_002967E8(th, pc);
        opus_v_en_all(&owu_eff_status[sub->h14], th->v00, 1);
        func_002B5978(sub->v40, th->v00, 16.0f);
        break;
    case 0x6000:
    case 0x7000:
        bone = (th->flags & 0x1000) ? 0x11 : 0x10;
        _opu_opus_get_bone_vertex(th->v00, owu_chr_hd[sub->b18], bone | 0x8000);
        func_002B5978(sub->v40, th->v00, 16.0f);
        break;
    case 0x8000:
        func_002967E8(th, pc);
        opus_v_chara_all(th->v00);
        func_002B5978(sub->v40, th->v00, 16.0f);
        break;
    }
    func_002B5978(&sub->f90, sub->v40, 0.0625f);
    return pc + 1;
}

void _opu_opus_set_chr_pos(int id, float *pos) __asm__("opus_set_chr_pos");
float _opu_func_002A0660(float a) __asm__("func_002A0660");
s64 _opu_func_002ED038(float a) __asm__("func_002ED038");
void _opu_opus_set_chr_dirf(int id, s64 dir) __asm__("opus_set_chr_dirf");
void _opu_MsSetChrMoveFlag(int id, int v) __asm__("MsSetChrMoveFlag");
void _opu_MsSetMove(int a, int b, int c, int d, float f0, float f1, int e, float f2, int g, float f3, float f4) __asm__("MsSetMove");
void _opu_func_001B6C30(int id, float *pos) __asm__("func_001B6C30");
void _opu_func_001D3480(int id) __asm__("func_001D3480");
void _opu_MsSetChrDirTarget(int a, int b, int c, int d, int e, int f) __asm__("MsSetChrDirTarget");
float _opu_MsGetChrBtlDir(int id) __asm__("MsGetChrBtlDir");

u16 *opu_v_en_move(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    SlotEntry *e = &owu_eff_status[sub->h14];
    float f;
    float dir;
    float d;
    int id;
    int t;

    switch ((s16)th->flags & 0xF000) {
    case 0x0000:
        _opu_opus_set_chr_pos(sub->b18, &sub->f90);
        pc += 1;
        break;
    case 0x2000:
        dir = _opu_func_002A0660(sub->v30[1]);
        _opu_opus_set_chr_dirf(sub->b18, _opu_func_002ED038(dir));
        pc += 1;
        break;
    case 0x3000:
        func_002967E8(th, pc);
        if (th->flags & 0x800) {
            id = e->b18;
        } else {
            id = sub->b18;
        }
        _opu_MsSetChrMoveFlag(id, 1);
        pc += 1;
        break;
    case 0x4000:
        func_002967E8(th, pc);
        if (th->flags & 0x800) {
            id = e->b18;
        } else {
            id = sub->b18;
        }
        _opu_MsSetChrMoveFlag(id, 0);
        pc += 1;
        break;
    case 0x5000:
        func_002967E8(th, pc);
        pc += 1;
        _opu_MsGetChrBtlPos(sub->b18, th->v00);
        _opu_opus_set_chr_pos(sub->b18, th->v00);
        dir = _opu_MsGetChrBtlDir(sub->b18);
        _opu_opus_set_chr_dirf(sub->b18, _opu_func_002ED038(dir));
        break;
    case 0x6000:
        func_002967E8(th, pc);
        d = (float)(s16)pc[2] * 0.0625f;
        if (th->flags & 0x800) {
            f = *(float *)((char *)sub + (s16)pc[1]);
            t = (int)f;
        } else {
            t = (s16)pc[1];
        }
        _opu_MsSetMove(e->b18, 2, e->list[0], t, 0.0f, d, 0, 1.0f, 0, 0.0f, 0.0f);
        pc += 3;
        break;
    case 0x7000:
        func_002967E8(th, pc);
        d = (float)(s16)pc[2] * 0.0625f;
        if (th->flags & 0x800) {
            f = *(float *)((char *)sub + (s16)pc[1]);
            t = (int)f;
        } else {
            t = (s16)pc[1];
        }
        _opu_MsSetMove(e->b18, 1, e->b18, t, 0.0f, d, 0, 1.0f, 0, 0.0f, 0.0f);
        pc += 3;
        break;
    case 0x8000:
        func_002967E8(th, pc);
        if (th->flags & 0x800) {
            f = *(float *)((char *)sub + (s16)pc[1]);
            t = (int)f;
        } else {
            t = (s16)pc[1];
        }
        _opu_MsSetChrDirTarget(e->b18, 2, 0, e->list[0], 0, t);
        pc += 2;
        break;
    case 0x9000:
        func_002967E8(th, pc);
        if (th->flags & 0x800) {
            t = (int)f;
        } else {
            t = (s16)pc[1];
        }
        _opu_MsSetChrDirTarget(e->b18, 1, 0, e->list[0], 0, t);
        pc += 2;
        break;
    case 0xA000:
        func_002967E8(th, pc);
        pc += 1;
        _opu_func_001B6C30(sub->b18, &sub->f90);
        break;
    case 0xB000:
        func_002967E8(th, pc);
        pc += 1;
        _opu_func_001D3480(e->key);
        break;
    }
    return pc;
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40", func_0029F208);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40", func_0029F2B8);

void _opu_func_002A06D0(int id, float *out) __asm__("func_002A06D0");
float _opu_func_002A0618(float a) __asm__("func_002A0618");
void _opu_MsSetChrDirTarget(int a, int b, int c, int d, int e, int f) __asm__("MsSetChrDirTarget");
float _opu_MsGetChrBtlDir(int id) __asm__("MsGetChrBtlDir");

u16 *opu_r_en(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    float dir;
    u8 ofs1;
    u8 ofs2;

    _opu_func_002A06D0(sub->b18, th->v00);
    dir = _opu_func_002A0618(th->v00[0]);
    switch ((s16)th->flags & 0xF000) {
    case 0x0000:
        sub->v30[1] = dir;
        sub->v30[0] = 0.0f;
        sub->v30[2] = 0.0f;
        pc += 1;
        break;
    case 0x1000:
        sub->v40[2] = dir;
        pc += 1;
        break;
    case 0x2000:
        sub->v30[1] = dir;
        pc += 1;
        break;
    case 0x3000:
        func_002967E8(th, pc);
        pc += 1;
        _opu_MsSetChrDirTarget(owu_eff_status[sub->h14].b18, 2, 0, sub->b18, 0, 0);
        break;
    case 0x4000:
        func_002967E8(th, pc);
        opus_v_en_all(&owu_eff_status[sub->h14], th->v00, 0);
        dir = op_deg_get(th->v10, sub->f90, sub->f98, th->v00[0], th->v00[2]);
        ofs1 = ((u8 *)pc)[2];
        ofs2 = ((u8 *)pc)[3];
        *(float *)((char *)sub + ofs1) = dir;
        if (th->flags & 0x800) {
            *(float *)((char *)sub + ofs2) = th->v10[0];
        }
        pc += 2;
        break;
    case 0x5000:
        *(float *)((char *)sub + pc[1]) = dir;
        pc += 2;
        break;
    case 0x6000:
        func_002967E8(th, pc);
        dir = _opu_func_002A0618(_opu_MsGetChrBtlDir(sub->b18));
        *(float *)((char *)sub + pc[1]) = dir;
        pc += 2;
        break;
    }
    return pc;
}

float _opu_op_deg_get(ScriptThread *th, float x1, float z1, float x2, float z2) __asm__("op_deg_get");
int _opu_op_deg_in_check(float a, float min, float max) __asm__("op_deg_in_check");

u16 *func_0029F5F8(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    ScriptSub *tgt = opus_no_get(th->obj300, sub, (s16)pc[1]);
    float deg = _opu_op_deg_get(th, sub->f90, sub->f98, tgt->f90, tgt->f98);
    u8 ofs1 = ((u8 *)pc)[4];
    u8 ofs2 = ((u8 *)pc)[5];

    switch ((s16)th->flags & 0xF000) {
    case 0x0000:
        if (th->flags & 0x800) {
            deg += 2048.0f;
        }
        *(float *)((char *)sub + ofs1) = deg;
        pc += 3;
        break;
    case 0x1000:
        if (th->flags & 0x800) {
            deg += 2048.0f;
        }
        *(float *)((char *)sub + ofs1) = deg;
        *(float *)((char *)sub + ofs2) = *(float *)th * 16.0f;
        pc += 3;
        break;
    }
    return pc;
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40", opu_v_etc);

u16 *func_0029FAC0(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    u8 ofs;
    s16 d_i;
    float f;
    float d;

    switch ((s16)th->flags & 0xF000) {
    case 0x0000:
        ofs = ((u8 *)pc)[3];
        d_i = pc[2];
        f = *(float *)((char *)sub + ofs);
        d = d_i;
        if (_opu_op_deg_in_check(*(float *)((char *)sub + ((u8 *)pc)[2]), f - d, f + d) != 0) {
            pc = SCRIPT_JUMP_AT(pc, 3);
        } else {
            pc += 4;
        }
        break;
    case 0x1000:
        ofs = ((u8 *)pc)[3];
        d_i = pc[2];
        f = *(float *)((char *)sub + ofs);
        d = d_i;
        if (_opu_op_deg_in_check(*(float *)((char *)sub + ((u8 *)pc)[2]), f - d, f + d) != 0) {
            pc = SCRIPT_JUMP_AT(pc, 3);
        } else {
            pc += 4;
        }
        break;
    }
    return pc;
}

float _opu_opus_cscale_get(int id, int v) __asm__("opus_cscale_get");
void _opu_MsGetChrScale(int id, float *out) __asm__("MsGetChrScale");

u16 *opu_v_scale(ScriptThread *th, u16 *pc)
{
    s16 mask = pc[1];
    ScriptSub *sub = th->sub;
    float s;
    float *v;
    int i;

    switch ((s16)th->flags & 0xE000) {
    case 0x0000:
        s = _opu_opus_cscale_get(sub->b18, th->b21E);
        break;
    case 0x2000:
        if (th->b21E != 0) {
            _opu_MsGetChrScale(sub->b18, th->v00);
            s = th->v00[1];
            if (s < 0.0f) {
                s = -s;
            }
        } else {
            s = 1.0f;
        }
        break;
    case 0x4000:
        s = opus_cwidth_scale_get(sub->b18, th->b21E);
        break;
    }
    switch ((s16)(th->flags & 0x1000)) {
    case 0x0000:
        v = sub->v30;
        for (i = 0; i < 8; i++, v++) {
            if (mask & 1) {
                *v *= s;
            }
            mask >>= 1;
        }
        break;
    case 0x1000:
        v = sub->v40;
        s *= 16.0f;
        mask >>= 4;
        for (i = 0; i < 3; i++, v++) {
            if (mask & 1) {
                *v *= s;
            }
            mask >>= 1;
        }
        break;
    }
    return pc + 2;
}

u16 *func_0029FD20(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub;
    float h;

    func_002967E8(th, pc);
    sub = th->sub;
    h = MsGetChrGround(sub->b18);
    switch ((s16)th->flags & 0xF000) {
    case 0x0000:
        if (sub->f94 <= h) {
            pc = (u16 *)((char *)pc + (s16)pc[1]);
        } else {
            pc += 2;
        }
        break;
    case 0x1000:
        if (h <= sub->f94) {
            pc = (u16 *)((char *)pc + (s16)pc[1]);
        } else {
            pc += 2;
        }
        break;
    }
    return pc;
}

u16 *opu_s_div(ScriptThread *th, u16 *pc)
{
    T6_SubVel *sub = (T6_SubVel *)th->sub; /* DEBT(CAST): see T6_SubVel */
    float n = pc[1];

    switch (th->flags & 0xE00) {
    case 0x000:
        if (th->flags & 0x1000) {
            sub->da[0] = -(sub->a[0] / n);
        }
        if (th->flags & 0x2000) {
            sub->da[1] = -(sub->a[1] / n);
        }
        if (th->flags & 0x4000) {
            sub->da[2] = -(sub->a[2] / n);
        }
        if (th->flags & 0x8000) {
            sub->da[3] = -(sub->a[3] / n);
        }
        break;
    case 0x200:
        if (th->flags & 0x1000) {
            sub->db[0] = -(sub->b[0] / n);
        }
        if (th->flags & 0x2000) {
            sub->db[1] = -(sub->b[1] / n);
        }
        if (th->flags & 0x4000) {
            sub->db[2] = -(sub->b[2] / n);
        }
        if (th->flags & 0x8000) {
            sub->db[3] = -(sub->b[3] / n);
        }
        break;
    }
    return pc + 2;
}

u16 *func_0029FF10(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    u16 flags = th->flags;
    u16 op = pc[1];
    float *v = (float *)((char *)sub + D_003735B0[op & 0xF]); /* DEBT(CAST): offset table */
    u16 pos = op & 0x8000;
    u16 fx;
    u16 fy;
    u16 fz;

    fx = flags & 0x1000;
    if (fx) {
        v[0] = 0.0f - v[0];
    }
    fy = flags & 0x2000;
    if (fy) {
        v[1] = 0.0f - v[1];
    }
    fz = flags & 0x4000;
    if (fz) {
        v[2] = 0.0f - v[2];
    }
    if (flags & 0x8000) {
        v[3] = 0.0f - v[3];
    }
    if (pos) {
        v = &sub->f90;
        if (fx) {
            v[0] = 0.0f - v[0];
        }
        if (fy) {
            v[1] = 0.0f - v[1];
        }
        if (fz) {
            v[2] = 0.0f - v[2];
        }
    }
    return pc + 2;
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40", func_002A0010);

u16 *opu_length(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    ScriptSub *tgt;
    u16 ofs;

    if (((s16)th->flags & 0xF000) == 0) {
        ofs = pc[2];
        tgt = opus_no_get(th->obj300, sub, (s16)pc[1]);
        pc += 3;
        *(float *)((char *)sub + ofs) = op_length_get(&sub->f90, &tgt->f90) * 16.0f; /* DEBT(CAST): operand is a byte offset into ScriptSub */
    }
    return pc;
}

void _opu_op_unit_m(void *m) __asm__("op_unit_m");
void _opu_func_002B5318(void *a, void *b, void *c) __asm__("func_002B5318");
void *_opu_opus_local_get(ScriptThread *th, ScriptSub *sub) __asm__("opus_local_get");
void _opu_func_002B58B0(void *a, void *b, void *c) __asm__("func_002B58B0");

u16 *opu_v_2d(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    ScriptSub *tgt;

    if (((s16)th->flags & 0xF000) == 0) {
        tgt = opus_no_get(th->obj300, sub, (s16)pc[1]);
        _opu_op_unit_m(th->m80);
        _opu_func_002B5318(th->m80, th->m80, &tgt->f90);
        func_002B56D8(th->m80, _opu_opus_local_get(th, tgt), th->m80);
        func_002B56D8(th->mC0, th->m2C0, th->m80);
        MMI_SQ_ZERO(0x0, th);
        pc += 2;
        _opu_func_002B58B0(th->v00, th->mC0, th->v00);
        sub->f90 = (float)((((int *)th)[0] - 0x8000) >> 4) * sub->v40[0] * 0.00390625f;
        sub->f94 = (float)((((int *)th)[1] - 0x8000) >> 4) * sub->v40[0] * 0.00390625f;
    }
    return pc;
}

int _opu_MsEffectGetTargetFlag(int id) __asm__("MsEffectGetTargetFlag");
int _opu_func_002A06A0(int id, float *out) __asm__("func_002A06A0");
s8 *_opu_MsGetBattleList(int a, int *cnt) __asm__("MsGetBattleList");

void opus_v_en_all(SlotEntry *e, float *out, int check_flag)
{
    int i;
    int n = 0;
    float x;
    float y;
    float z;

    x = y = z = 0.0f;
    for (i = 0; i < e->b8; i++) {
        if (check_flag == 0 || _opu_MsEffectGetTargetFlag(e->list[i]) != 0) {
            _opu_func_002A06A0(e->list[i], out);
            n++;
            x += out[0];
            y += out[1];
            z += out[2];
        }
    }
    out[0] = x / (float)n;
    out[1] = y / (float)n;
    out[2] = z / (float)n;
}

void opus_v_chara_all(float *out)
{
    int cnt;
    int i;
    int n = 0;
    float x;
    float y;
    float z;
    s8 *list;

    x = y = z = 0.0f;
    list = _opu_MsGetBattleList(0x10, &cnt);
    for (i = 0; i < cnt; i++) {
        _opu_func_002A06A0(*list++, out);
        n++;
        x += out[0];
        y += out[1];
        z += out[2];
    }
    out[0] = x / (float)n;
    out[1] = y / (float)n;
    out[2] = z / (float)n;
}
