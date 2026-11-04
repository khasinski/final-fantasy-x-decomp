/* tu_323 0x2ac750-0x2af1d0: low; ~opp (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/v6.h"
#include "ffx/w10.h"
#include "ffx/r6.h"
#include "ffx/g4.h"

INCLUDE_ASM("build/ee_asm/game/op/opp_2AC750", func_002AC750);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AC750", opp_anm);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AC750", func_002ACD20);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AC750", opp_anm_yodare);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AC750", func_002AD890);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AC750", opp_dtt);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AC750", opp_anmm);
INCLUDE_RODATA("build/ee_asm/game/op/opp_2AC750/rodata", jtbl_00575A70);

s32 func_002AE200(u8 *a) {
    a[0x210] = 0xFF; /* DEBT(CAST): record type unknown, raw byte offset */
    return 0;
}

/* DEBT(CAST): bytecode stream read as raw bytes */
u8 *func_002AE210(AnimCtx *o, int b, u8 *p)
{
    o->b210 = o->h21A >> 8;
    return p + 2;
}

char *func_002AE228(s32 a, s32 b, s16 *p) {
    return (char *)p + p[1]; /* DEBT(CAST): s16 table whose second entry is a byte offset */
}

INCLUDE_ASM("build/ee_asm/game/op/opp_2AC750", func_002AE238);

/* DEBT(CAST): bytecode stream and table offsets read as raw bytes */
u8 *opp_anmm_anm(AnimCtx *o, G4AnimRes *r, u8 *p, G4AnimWork *w)
{
    u8 *sub = r->p20 + (w->h4C << 8);
    u8 *blk = r->p60[sub[0x1E]];

    w->w4 = ((int *)(*(int *)(blk + 0x10) + (int)blk))[*(s16 *)(p + 2)];
    w->w8 = 0xFF010000;
    *(u8 *)&w->w8 = sub[0xB3];
    w->wC = 0x100;
    w->w1C = 0x80808080;
    w->w2C = 0;
    w->w3C = 0;
    return p + 4;
}

u8 *opp_anmm_f(AnimCtx *o, int b, u8 *p, AnimWork *w)
{
    if ((s16)o->h21A & 0xF000) {
    } else {
        w->b08 |= 0x80;
    }
    return p + 2;
}

INCLUDE_ASM("build/ee_asm/game/op/opp_2AC750", opp_anmm_v);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AC750", func_002AE3E0);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AC750", opp_anmm_vr);

/* DEBT(CAST): bytecode stream read as raw bytes */
u8 *opp_anmm_scale(AnimCtx *o, int b, u8 *p, u8 *w)
{
    u16 v = *(u16 *)(p + 2);

    *(u16 *)(w + D_00373720[(o->h21A & 0x7000) >> 12]) = v;
    return p + 4;
}

INCLUDE_ASM("build/ee_asm/game/op/opp_2AC750", func_002AE620);

/* DEBT(CAST): bytecode stream read as raw bytes */
u8 *opp_anmm_rgba(AnimCtx *o, int b, u8 *p, AnimWork *w)
{
    if (o->h21A & 0x1000) {
        w->h2C = *(u16 *)(p + 2);
        w->h2E = *(u16 *)(p + 4);
    } else {
        w->h1C = *(u16 *)(p + 2);
        w->h1E = *(u16 *)(p + 4);
    }
    return p + 6;
}

/* DEBT(CAST): bytecode stream read as raw bytes */
u8 *opp_anmm_fin(AnimCtx *o, int b, u8 *p, AnimWork *w)
{
    w->b4E = (s16)o->h21A >> 12;
    if (w->b4E == 2) {
        w->f40 = w->f10;
        w->f44 = w->f14;
        w->f48 = w->f18;
    }
    return p + 2;
}

/* DEBT(CAST): bytecode stream read as raw bytes */
u8 *func_002AE728(AnimCtx *o, int b, u8 *p, AnimWork *w)
{
    u8 *q = (u8 *)&w->h1C;
    u16 mask = 0x1000;
    int i;

    p += 2;
    for (i = 0; i < 4; i++) {
        if ((s16)o->h21A & mask) {
            q[i] = *p;
            p += 2;
        }
        mask <<= 1;
    }
    return p;
}

u8 *func_002AE770(s32 a, s32 b, u8 *p, u8 *q) {
    q[0x4F] = p[2]; /* DEBT(CAST): record types unknown, raw byte offset */
    return p + 4;
}

/* DEBT(CAST): bytecode stream read as raw bytes */
u8 *opp_anmm_jloop(AnimCtx *o, int b, u8 *p, AnimWork *w)
{
    if (--w->b4F != 0) {
        return p + *(s16 *)(p + 2);
    }
    return p + 4;
}

INCLUDE_ASM("build/ee_asm/game/op/opp_2AC750", func_002AE7B0);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AC750", func_002AE840);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AC750", opp_anmm_rgba3);

/* DEBT(CAST): bytecode stream read as raw bytes */
u8 *func_002AE930(AnimCtx *o, AnimRes *r, u8 *p, AnimWork *w)
{
    *(float *)((u8 *)w + p[2]) = *(float *)(r->p20 + (w->h4C << 8) + p[3]);
    return p + 4;
}

INCLUDE_ASM("build/ee_asm/game/op/opp_2AC750", func_002AE960);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AC750", func_002AE9E0);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AC750", opp_anmm_fin_en_bone5);

/* DEBT(CAST): bytecode stream read as raw bytes */
u8 *opp_anmm_fin_en_bone3x(AnimCtx *o, int b, u8 *p, AnimWork *w)
{
    w->f40 = *(s16 *)(p + 2);
    w->b4E = 5;
    return p + 4;
}

INCLUDE_ASM("build/ee_asm/game/op/opp_2AC750", opp_anmm_scale_cscale);

u8 *func_002AECB8(AnimCtx *o, R6Obj *r, u8 *p, AnimWork *w)
{
    int i = opus_get_weapon_index_by_chrid(((ScriptSub *)((u8 *)r->p20 + (w->h4C << 8)))->b18); /* DEBT(CAST): 0x100-byte sub records */
    int v;

    if (!(o->h21A & 0x1000)) {
        v = D_00703E20.b6C[i] + 1;
        if (v >= 0x7F) {
            v = 0x7F;
        }
    } else {
        v = D_00703E20.b6C[i] - 1;
        if (v <= 0) {
            v = 0;
        }
    }
    D_00703E20.b6C[i] = v;
    return p + 2;
}

INCLUDE_ASM("build/ee_asm/game/op/opp_2AC750", opp_anmm_gw_wscale);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AC750", func_002AEDC0);

INCLUDE_ASM("build/ee_asm/game/op/opp_2AC750", func_002AEFB8);
