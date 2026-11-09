/* tu_317 0x29a8a8-0x29dc40: low; ~opu (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#define MsCameraSetScrDpt _hdr_MsCameraSetScrDpt
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w9.h"
#include "ffx/q6.h"
#include "ffx/v6.h"
#include "ffx/g4.h"
#include "ffx/s6.h"
#include "ffx/t6.h"
#include "ffx/q7.h"
#undef MsCameraSetScrDpt
void MsCameraSetScrDpt(int h, float a);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29A8A8", opu_test_data_read);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29A8A8", opu_debug_check);

int func_0029B560(void) {
    int ofs = MsBattleGetStatus() ? 0 : 0x20;
    Chr **p = owu_chr_hd + ofs;
    int n = 0;
    int i;

    for (i = 0; i < 0xD0; i++) {
        if (p[i] != 0) {
            n++;
        }
    }
    return n;
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29A8A8", opd_target_handle_by_index);

u16 func_0029B680(void) {
    Chr *key = opd_target_handle_by_index();
    int i;

    if (key == 0) {
        return 0;
    }
    i = opus_get_chr_status_index(key, 0, 0);
    if (i < 0) {
        return 0;
    }
    return owu_chr_status[i].hE;
}

void func_0029B6D8(void) {
}

extern int D_007649A8;
s32 MsCameraGet(s32 a, s32 b, s32 c);
void MsCameraFree(int h);

typedef struct {
    u8 pad00[0x18];
    int cam;
} OpCamState;

void opd_camera_change(int a) {
    s8 *hw = (s8 *)&D_2008250;

    if (a != 0) {
        ((OpCamState *)&D_00764990)->cam = MsCameraGet(3, 0, 7);
        MsCameraSetRoll(((OpCamState *)&D_00764990)->cam, 0.0f);
        MsCameraSetScrDpt(((OpCamState *)&D_00764990)->cam, 1024.0f);
        MsBattleSpecialCameraPause(1);
        func_001CB798(0);
        if (hw[6] != 0) {
            Sg_EnableDrawMenu(0);
        } else {
            Sg_EnableDrawMenu(1);
        }
        if (hw[5] != 0) {
            Sg_EnableDrawGui(0);
        } else {
            Sg_EnableDrawGui(1);
        }
    } else {
        MsCameraFree(D_007649A8);
        func_001CB798(1);
        Sg_EnableDrawMenu(1);
        Sg_EnableDrawGui(1);
        MsBattleSpecialCameraPause(0);
    }
}

void func_0029B7D8(void) {
    D_0054D5E8[0]->vt50->f50(0);
}

void func_0029B808(void) {
    opus_ffxfocus_free();
}

void func_0029B810(void) {
}

void func_0029B818(void) {
}

int op_et_battle_genko_counter_get(void) {
    return D_0054D5E8[0]->b3A;
}

int func_0029B830(int a) {
    int r;
    if (D_00703FF0.b[1] != 0) {
        r = -1;
    } else if (op_oef2_sound_cue_check(a) != 0) {
        r = -1;
    } else {
        r = func_002D0570(a) != 0 ? -1 : 0;
    }
    return r;
}

void op_et_prayeff_send_read_through(Chr *key) {
    func_00120108(D_005753B0);
    func_00298230(key, 0x1000);
}

void op_et_encount_effect_on(int a, int b)
{
    HwRegs2008250 *hw = &D_2008250;

    if (D_007649A0 == 0) {
        if (D_00703E28 != 0) {
            ((void (*)(int, int, int, int))opu_et_unit)(D_00703E28, 0, a + 8, b); /* DEBT(CAST): void cast prevents sibling call */
        }
    } else if (hw->h40 & 0x20) {
        ((void (*)(int, int, int, int))opu_et_unit)(hw->w98, 0, hw->wBC, b); /* DEBT(CAST): void cast prevents sibling call */
    } else {
        if (D_00703E28 != 0) {
            ((void (*)(int, int, int, int))opu_et_unit)(D_00703E28, 0, a + 8, b); /* DEBT(CAST): void cast prevents sibling call */
        }
    }
}

u16 *opu_unit_max(ScriptThread *th, u16 *pc) {
    s16 max = pc[1];
    s16 n = max - *(u16 *)((u8 *)th + 0x334);
    u8 *p = *(u8 **)((u8 *)th + 0x320) + (*(u16 *)((u8 *)th + 0x334) << 8);

    for (; n > 0; n--, p += 0x100) {
        *(u_long128 *)p = 0;
    }
    pc += 2;
    *(s16 *)((u8 *)th + 0x334) = max;
    return pc;
}

/* operand 1 is a signed byte offset from the opcode word. DEBT(CAST): byte arithmetic on a u16 stream */
#define SCRIPT_JUMP(pc) ((u16 *)((char *)(pc) + (s16)(pc)[1]))

u16 *func_0029B9B0(ScriptThread *th, u16 *pc) {
    return SCRIPT_JUMP(pc);
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29A8A8", opu_jump_etc);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29A8A8", opu_jump_etc2);

u16 *func_0029C338(ScriptThread *th, u16 *pc) {
    th->sub->stk[th->sp] = pc + 2;
    return SCRIPT_JUMP(pc);
}

u16 *func_0029C360(ScriptThread *th) {
    return th->sub->stk[th->sp];
}

u16 *func_0029C378(ScriptThread *th, u16 *pc) {
    th->sub->h1A = pc[1];
    return pc + 2;
}

u16 *opu_et_no(ScriptThread *th, u16 *pc) {
    ScriptSub *sub = th->sub;
    SlotEntry *e = &owu_eff_status[sub->h14];

    sub->h1A = pc[1] + (e->sub->h1A & 0x7FF0);
    return pc + 2;
}

u16 *func_0029C3C8(ScriptThread *th, u16 *pc) {
    return pc + 1;
}

int MsGetDamageInfo(int a, int b, void *x, void *y, void *z);
float opus_cscale_get(int id, int flag);

u16 *func_0029C3D0(ScriptThread *th, u16 *pc) {
    u16 flags = th->flags;
    ScriptSub *sub = th->sub;
    int arg = pc[1];
    u32 idx = flags >> 12;
    SlotEntry *e;
    int r;
    s16 max;
    float f;

    switch (flags & 0xE00) {
    case 0x000:
        sub->loopcnt[idx] = arg;
        pc += 2;
        break;
    case 0x200:
        func_002967E8(th, pc);
        e = &owu_eff_status[sub->h14];
        r = MsGetDamageInfo(e->key, sub->b18, 0, 0, 0);
        sub->loopcnt[idx] = r;
        if (r != 0) {
            pc += 2;
        } else {
            pc = SCRIPT_JUMP(pc);
        }
        break;
    case 0x400:
        r = func_002B3D68((s16)pc[2]);
        pc += 3;
        sub->loopcnt[idx] = arg + r;
        break;
    case 0x600:
        f = *(float *)((char *)sub + arg);
        pc += 2;
        sub->loopcnt[idx] = f;
        break;
    case 0x800:
        max = pc[2];
        f = opus_cscale_get(sub->b18, th->b21E);
        pc += 3;
        arg = f * arg;
        if (arg > max) {
            arg = max;
        }
        if (arg <= 0) {
            arg = 1;
        }
        sub->loopcnt[idx] = arg;
        break;
    }
    return pc;
}

u16 *func_0029C550(ScriptThread *th, u16 *pc) {
    u8 *cnt = th->sub->loopcnt;

    cnt += th->flags >> 12;
    if (--*cnt != 0) {
            return SCRIPT_JUMP(pc);
    }
    return pc + 2;
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29A8A8", opu_en_lock);
INCLUDE_RODATA("build/ee_asm/game/op/opu/opu_29A8A8/rodata", jtbl_00575470);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29A8A8", opu_en_on);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29A8A8", func_0029CBD0);
INCLUDE_RODATA("build/ee_asm/game/op/opu/opu_29A8A8/rodata", jtbl_005754A0);

/* DEBT(CAST): operand 1 is a byte offset into the entity block starting at ScriptSub.a8 */
u16 *func_0029CF78(ScriptThread *th, u16 *pc) {
    ScriptSub *sub = th->sub;
    s16 idx = pc[1];
    s16 val = pc[2];

    switch (((s16)th->flags & 0xF000) >> 12) {
    case 0:
        *(u8 *)((char *)sub + idx + 0xA8) = val;
        pc += 3;
        break;
    case 1:
        *(u16 *)((char *)&sub->a8 + idx) = val;
        pc += 3;
        break;
    case 2:
        *(u16 *)((char *)&sub->a8 + idx) = val;
        *(u16 *)((char *)&sub->a8 + idx + 2) = pc[3];
        pc += 4;
        break;
    }
    return pc;
}

typedef struct {
    u8 pad00[0x60];
    void (*f60)(void *);
} OpuMemVt;

typedef struct {
    u8 pad00[0x0C];
    int w0C;
    u8 pad10[0x18];
    int w28;
    int w2C;
    u8 pad30[0x20];
    OpuMemVt *vt50;
    int w54;
    int w58;
    u8 pad5C[0x44];
    int wA0;
    int wA4;
    int wA8;
    int wAC;
    int wB0;
} OpuMemObj300;

int op_heap_init(int base, int size);
void op_free(int heap, void *ptr);

u16 *opu_mem(ScriptThread *th, u16 *pc) {
    OpuMemObj300 *o = (OpuMemObj300 *)th->obj300;
    ScriptSub *sub = th->sub;
    int s1, s2, s3;
    int p1, p2;

    switch ((s16)th->flags & 0xF000) {
    case 0x0000:
        if (sub->pBC != 0) {
            op_free(*(int *)((u8 *)th + 0x3A8), sub->pBC);
            sub->pBC = 0;
        }
        pc += 1;
        break;
    case 0x1000:
        s1 = pc[1] << 8;
        s2 = pc[2] << 8;
        s3 = pc[3] << 8;
        o->wA8 = op_heap_init(o->w0C, s1);
        pc += 4;
        o->wAC = s1;
        o->wA4 = s2;
        o->wB0 = s3;
        p1 = o->w0C + s1;
        o->wA0 = p1;
        p2 = p1 + s2;
        o->w54 = p2;
        o->w58 = p2;
        o->w28 = D_00303550;
        o->w2C = D_00303550;
        o->vt50->f60(o);
        break;
    }
    return pc;
}

u16 *opu_mfifo(ScriptThread *th, u16 *pc)
{
    T6_Th300Subs *o = (T6_Th300Subs *)th->obj300; /* DEBT(CAST) */
    ScriptSub *sub = th->sub;
    ScriptSub *tgt = opus_no_get(th->obj300, sub, (s16)pc[1]);
    int self;
    u32 idx;

    switch (tgt->bBB) {
    case 10:
        if (sub == tgt) {
            self = 1;
            idx = 0;
        } else {
            self = 0;
            idx = (u32)((u8 *)sub - o->subs) >> 8;
        }
        if (th->h212 == 0) {
            op_mfifo_set(tgt->pBC, (int)&sub->f90, self, (u16)idx); /* DEBT(TYPE): q7.h prototype takes int */
        }
        break;
    case 17:
        if (th->h212 == 0) {
            op_mfifo_set(sub->pBC, (int)&sub->f90, 0, 0); /* DEBT(TYPE) */
        }
        break;
    }
    return pc + 2;
}

u16 *opu_damage(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub;
    SlotEntry *e;
    int mode;

    func_002967E8(th, pc);
    sub = th->sub;
    e = &owu_eff_status[sub->h14];
    if (th->flags & 0x800) {
        mode = 2;
        func_00120108(D_005754D8, e->key, sub->b18);
    } else {
        mode = 0;
        func_00120108(D_00575510, e->key, sub->b18);
    }
    switch ((s16)th->flags & 0xF000) {
    case 0x0000:
        func_001C5E90(e->key, e->list[0], mode);
        pc++;
        break;
    case 0x1000:
        func_001C5E90(e->key, sub->b18, mode);
        pc++;
        break;
    case 0x2000:
        MsMergeDamage(e->key, sub->b18);
        pc++;
        break;
    }
    return pc;
}

u16 *opu_damage_motion(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub;
    SlotEntry *e;
    int mode;
    int id;

    func_002967E8(th, pc);
    sub = th->sub;
    e = &owu_eff_status[sub->h14];
    switch ((s16)th->flags & 0xF000) {
    case 0x0000:
        mode = 5;
        break;
    case 0x1000:
        mode = 6;
        break;
    }
    if (!(th->flags & 0x800)) {
        id = e->list[0];
    } else {
        id = sub->b18;
    }
    MsDamageSetMotion(id, mode, 1);
    return pc + 1;
}

u16 *func_0029D3A8(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;

    switch ((s16)pc[1]) {
    case 1:
        if (th->h212 != 0) {
            pc = SCRIPT_JUMP_AT(pc, 2);
        } else {
            pc += 3;
        }
        break;
    case 2:
        pc += 2;
        D_0054B7C0.x = sub->f90;
        D_0054B7C0.y = sub->f94;
        D_0054B7C0.z = sub->f98;
        break;
    case 3:
        func_0029D9C0(th, sub, SCRIPT_JUMP_AT(pc, 2));
        pc += 3;
        break;
    case 4:
        th->h3B8 = pc[2];
        pc += 3;
        break;
    }
    return pc;
}

u16 *func_0029D478(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    s16 n = pc[1];

    sub->a8.p = pc + 2;
    sub->bBB = 8;
    opus_draw_on((IdList *)th->obj300, th->h214); /* DEBT(CAST): obj300 is described as bytes */
    return pc + 3 + n;
}

u16 *func_0029D4D8(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    ScriptSub *other;

    switch ((s16)th->flags & 0xF000) {
    case 0x0000:
        other = opus_no_get(th->obj300, sub, (s16)pc[1]);
        pc += 2;
        sub->v40[2] = op_deg_get(sub->v40, sub->v40[0], sub->v40[2], other->v40[0], other->v40[2]);
        break;
    case 0x1000:
        sub->bBA = 0;
        func_002B5978(sub->v40, &sub->f90, 16.0f);
        pc += 2;
        break;
    }
    sub->bB2 &= ~4;
    return pc;
}

u16 *func_0029D580(ScriptThread *th, u16 *pc) {
    ScriptSub *sub;

    func_002967E8(th, pc);
    sub = th->sub;
    if (((s16)th->flags & 0xF000) == 0) {
        if (func_001B84B8(sub->b18) == 0) {
            th->f210 = 1;
        } else {
            pc += 1;
        }
    }
    return pc;
}

u16 *func_0029D5E0(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;

    switch ((s16)th->flags & 0xF000) {
    case 0x0000:
        func_002967E8(th, pc);
        MsEffectWaitFlag(1);
        sub->bB2 |= 1;
        break;
    case 0x1000:
        func_002967E8(th, pc);
        MsEffectWaitFlag(0);
        sub->bB2 &= ~1;
        break;
    case 0x2000:
        sub->bB2 |= 2;
        break;
    case 0x3000:
        sub->bB2 &= ~2;
        break;
    case 0x4000:
        sub->bB2 |= 4;
        break;
    case 0x5000:
        sub->bB2 &= ~4;
        break;
    }
    return pc + 1;
}

u16 *opu_ffx(ScriptThread *th, u16 *pc)
{
    SlotEntry *e = &owu_eff_status[th->sub->h14];

    switch ((s16)(pc[1] - 1)) {
    case 0:
        D_00703FF0.b[1] = 1;
        pc += 2;
        break;
    case 1:
        pc += 2;
        D_00703FF0.b[1] = 0;
        break;
    case 2:
        if (D_00703FF0.b[1] != 0) {
            th->f210 = 1;
        } else {
            pc += 2;
        }
        break;
    case 3:
        pc += 2;
        MsEffectReady(e->key, 1);
        return pc;
    case 4:
        if (MsEffectMotionLevel(e->key) > 0) {
            pc += 2;
        } else {
            th->f210 = 1;
        }
        break;
    case 5:
        pc += 2;
        MsEffectReady(e->key, 0);
        return pc;
    case 6:
        pc += 2;
        func_0011A9E0(1);
        func_0011AA08(1);
        Sg_EnableDrawMenu(1);
        Sg_EnableDrawGui(1);
        return pc;
    case 7:
        pc += 2;
        func_0011A9E0(0);
        func_0011AA08(0);
        Sg_EnableDrawMenu(0);
        Sg_EnableDrawGui(0);
        break;
    }
    return pc;
}

/* DEBT(CAST): bytecode stream read as raw bytes */
u8 *func_0029D838(AnimCtx *o, u8 *p)
{
    int a = *(u16 *)(p + 2);

    switch ((s16)o->h21A & 0xF000) {
    case 0:
        AtelSetEffectFlag(a);
        p += 4;
        break;
    case 0x1000:
        if (func_0014AA50(a) != 0) {
            p += 4;
        } else {
            o->b210 = 1;
        }
        break;
    }
    return p;
}

void func_001149A8(Chr *chr, float a, float b, float c);

u16 *func_0029D8B8(ScriptThread *th, u16 *pc) {
    ScriptSub *sub = th->sub;
    s16 op = pc[1];
    Chr *chr = owu_chr_hd[sub->b18];
    float f0, f1;
    int a;

    switch (op) {
    case 0:
        a = (int)*(float *)((u8 *)sub + 0x34);
        pc += 2;
        f1 = (a + 0x400) & 0xFFF;
        f0 = *(float *)((u8 *)sub + 0x38);
        f1 = f1 * 0.000244140625f * 360.0f - 90.0f;
        f0 += func_002B3DB0(10.0f);
        func_001149A8(chr, *(float *)((u8 *)sub + 0x30) * 0.00390625f, f1, f0);
        break;
    case 1:
        func_00114968(chr, 0);
        pc += 2;
        break;
    }
    return pc;
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29A8A8", func_0029D9C0);

void func_001AF2E8(float *out);
int op_point_get_line_circle(float *out1, float *out2, float cx, float cz, float r, float x0, float z0, float x1, float z1);
void func_002B3120(u32 color, int a, int b);

void opus_camera_limit(void *obj300, int v) {
    float v0[4];
    float v1[4];
    float v2[4];
    float v3[4];
    float v4[4];
    float dpt;

    if ((s16)D_00703FF0.hC != 0) {
        func_001AF2E8(v2);
        MsCameraGetPosNow(1, v0);
        MsCameraGetPosNow(0, v1);
        dpt = MsCameraGetScrDpt();
        if (op_point_get_line_circle(v3, v4, v2[0], v2[2], 120.0f, v0[0], v0[2], v1[0], v1[1]) != 0) {
            int cam = *(int *)((u8 *)obj300 + 0x5C);
            float d;

            v3[1] = v0[1];
            d = op_length_get(v0, v3) * (float)((s16)D_00703FF0.hC - 0x1000) * 0.00390625f;
            MsCameraSetRect(cam, 1, v3);
            MsCameraSetScrDpt(cam, dpt - d);
            if (D_007649A0 != 0 && *((s8 *)&D_2008250 + 0xB) != 0) {
                func_002B3120(0x80800000, 0x48, 0);
            }
        }
    }
}
