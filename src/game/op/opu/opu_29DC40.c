/* tu_318 0x29dc40-0x2a0618: low; ~opu; split at 0x2a0618: flag split: 0x2A0618-0x2A0718 needs -Btools/cc/ee-as-delay/ -Wa,-mips4 (config/cflags.txt), func_0029FD20 does not (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#define opu_v_get _hdr_opu_v_get
#define opus_v_en_all _hdr_opus_v_en_all
#define opus_v_chara_all _hdr_opus_v_chara_all
#include "common.h"
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

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40", opu_level);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40", func_0029E360);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40", opu_v_256);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40", func_0029E598);

void opu_vran_256(void) {
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40", func_0029E6F0);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40", func_0029E8F0);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40", opu_v_get);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40", opu_v_en);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40", opu_v_en_move);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40", func_0029F208);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40", func_0029F2B8);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40", opu_r_en);

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

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40", opu_v_scale);

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

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40", opu_v_2d);

int _opu_MsEffectGetTargetFlag(int id) __asm__("MsEffectGetTargetFlag");
void _opu_func_002A06A0(int id, float *out) __asm__("func_002A06A0");
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
