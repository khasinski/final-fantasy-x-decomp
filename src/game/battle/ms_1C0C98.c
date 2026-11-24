/* tu_193 0x1c0c98-0x1c5e90: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"

struct Obj436Slot *func_001C0C98(Obj436 *o) {
    struct Obj436Slot *p = 0;
    int i;

    for (i = 0; i < 2; i++) {
        if (o->slot[i].v == 0xFF) {
            p = &o->slot[i];
            MsStructClear(p, sizeof(struct Obj436Slot));
            break;
        }
    }
    return p;
}

typedef struct {
    u8 pad0[6];
    u8 b6;
    u8 b7[13];
    u16 h14;
    u16 h16;
} Unk1C0D00;

typedef struct {
    u8 pad0[0x2C6];
    u16 h2C6;
    u8 b2C8[13];
    u8 pad2D5;
    u16 h2D6;
    u8 pad2D8[0x300 - 0x2D8];
    u8 b300;
} Unk1C0D00Chr;

void func_001C0D00(Unk1C0D00 *dst, Unk1C0D00 *src, Unk1C0D00Chr *c) {
    int i;
    if (src != 0) {
        dst->h14 = src->h14;
        for (i = 0; i < 13; i++) {
            dst->b7[i] = src->b7[i];
        }
        dst->h16 = src->h16;
        dst->b6 = src->b6;
    } else {
        dst->h14 = c->h2C6;
        for (i = 0; i < 13; i++) {
            dst->b7[i] = c->b2C8[i];
        }
        dst->h16 = c->h2D6;
        dst->b6 = c->b300;
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", MsCalcCommand);

int func_001C1908(int a0, BtlChr *a1, int a2, BtlChr *a3, OfsTbl *a4, int a5, Obj436Ent *a6, void *a7, int *a8, int *a9, u8 *a10);
int func_001C7D60(int id);

int MsCalcDamage(int a0, BtlChr *a1, int a2, BtlChr *a3, OfsTbl *a4, int a5, u8 *a6, void *a7, int *a8, int *a9, int count)
{
    u8 flag;
    int total = 0;
    u8 *prev;
    int i;

    *(s32 *)((u8 *)a3 + 0x3A4) = *(s32 *)((u8 *)a3 + 0x290);
    *(s32 *)((u8 *)a3 + 0x3A8) = *(s32 *)((u8 *)a3 + 0x294);
    *(s32 *)((u8 *)a3 + 0x3AC) = *((u8 *)a3 + 0x31C);
    *(s32 *)((u8 *)a3 + 0x9F4) = 0;
    *(s32 *)((u8 *)a3 + 0x9F8) = 0;
    *(s32 *)((u8 *)a3 + 0x9FC) = 0;
    if (a6[0] != 0) {
        prev = a6 + (a6[0] * 0x2C - 0x14);
    } else {
        prev = 0;
    }
    for (i = a6[0]; i < a6[0] + count; i++) {
        u8 *old = prev;

        prev = a6 + (i * 0x2C + 0x18);
        func_001C0D00((Unk1C0D00 *)prev, (Unk1C0D00 *)old, (Unk1C0D00Chr *)a3);
        total += func_001C1908(a0, a1, a2, a3, a4, a5, (Obj436Ent *)prev, a7, a8, a9, &flag);
    }
    if (func_001C7D60(a2) != 0 && *(s32 *)((u8 *)a3 + 0x290) - total <= 0) {
        *((u8 *)a3 + 0xAAC) = 1;
    } else {
        *((u8 *)a3 + 0xAAC) = 0;
    }
    if (a0 == 0 && a2 < 8) {
        if (total < 0) {
            MsAddLoveParam(a2, 1);
        } else if (total > 0) {
            MsAddLoveParam(a2, -1);
        }
    }
    a6[1] = a6[0] + count;
    a6[0x16] = flag;
    return total;
}

int func_001C1368(int id1, int id2) {
    int start;
    int i;
    int end;
    int best_val;
    int best_id;

    if (MsGetRamChrMonster(id2) != 0) {
        start = 20;
        end = 28;
    } else {
        start = 0;
        end = 18;
    }
    best_val = -1;
    best_id = -1;
    for (i = start; i < end; i++) {
        BtlChr *c = MsGetChr(i);
        if (i != id1) {
            if (i != id2 && c->fA88 != 0 && (((c->f2D6 >> 12) & 1) || ((c->f2D6 >> 13) & 1)) && c->fA8C == 0 && MsAutoCommandStatusCheck(c, 1, 1, 1) != 0) {
                int val = c->f290;
                val <<= (c->f2D6 >> 13) & 1;
                if (id2 == 0) {
                    val += MsAddLoveParam(i, 0) / 2;
                }
                if (i == 0) {
                    val += MsAddLoveParam(id2, 0) / 2;
                }
                if (best_val < val) {
                    best_val = val;
                    best_id = i;
                }
            }
        }
    }
    return (best_id < 0) ? id2 : best_id;
}

typedef struct OfsTbl_64 {
    u8 pad0[0x1A];
    u16 h1A;
    u64 flags64 __attribute__((packed));
    u16 h20;
    u8 pad22[0x2B - 0x22];
    u8 b2B;
} OfsTbl_64;

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", func_001C14F0);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", func_001C1908);

int func_001C2500(int unused, BtlChr *c, Q4Act *act, int *q, int force) {
    int r = 0;
    if ((act->h20 >> 4) & 1) {
        if (q[0] < 0 || q[1] < 0 || q[2] < 0) r = 1;
    } else {
        if (q[0] > 0 || q[1] > 0 || q[2] > 0) r = 1;
    }
    if (force) r = 1;
    if (r) c->f3D5 = 1;
    return r;
}

int MsCalcMagic(GsEnt48 *e, int idx) {
    int sp0;
    if (e != 0) {
        int id = e->id;
        BtlChr *c = MsGetChr(id);
        OfsTbl *t;
        int mp;
        int lim;

        if (c->f39E != 0) {
            sp0 = 0x3028;
            t = MsGetCommand(id, 0, -1, 0, &sp0);
            mp = MsCheckUseCommand(id, t, 0);
            if (e->f2 != 0) {
                mp = 0;
            }
        } else {
            t = MsGetCommand(id, 0, 0x305F, &e->f8[idx], &sp0);
            mp = MsCheckUseCommand(id, t, 0);
        }
        lim = 0;
        if (D_0031732C == 0) {
            if (t != 0) {
                lim = t->b26;
            }
        }
        if (t != 0 && t->b26 != 0) {
            c->f280 = 1;
        } else {
            c->f280 = 0;
        }
        if (c->f294 >= mp && mp >= 0 && c->f27C >= lim && lim >= 0) {
            c->f38C = mp;
            c->f38D = lim;
            return -1;
        }
    }
    return 0;
}

void MsUseChrMpLimit(int id) {
    BtlChr *c = MsGetChr(id);
    c->f294 = MsCheckRange(c->f294 - c->f38C, 0, 9999);
    c->f27C = MsCheckRange(c->f27C - c->f38D, 0, c->f27D);
    if (c->f38D != 0) {
        MsSummonLimitLoad(c);
        func_001E2560(id);
    }
    c->f38C = 0;
    c->f38D = 0;
}

int func_001C2758(BtlChr *c, u32 *flags, int dmg) {
    u16 f = c->f2D6;
    if ((f >> 6) & 1) {
        c->f39A = 1;
        dmg /= 4;
        *flags |= 0x8000;
    }
    if ((f >> 7) & 1) {
        dmg = dmg * 3 / 2;
    }
    return dmg;
}

int func_001C27C0(BtlChr *c, int v) {
    if (((c->f2C6 >> 9) & 1) && c->fC1C == c->f386) {
        v = v * 3 / 2;
    }
    return v;
}

int func_001C2800(BtlChr *c, OfsTbl *t, int kind, int *dmg) {
    int r = 0;
    if (kind == 0x311F) {
        if (c->f28A != 0) {
            c->f28A = 0;
            if (dmg != 0) {
                *dmg = *dmg * 3 / 2;
            }
        }
    } else if (((c->f37C >> 6) & 1) && (u32)(t->b17 - 1) < 2) {
        if (dmg != 0) {
            *dmg = *dmg * 3 / 2;
        }
        r = -1;
    }
    return r;
}

int func_001C2898(BtlChr *c, Q4Act *act, int b, int kind, int dmg) {
    if (((c->f37C >> 9) & 1) && (b >> 12) == 2 && ((act->h20 >> 4) & 1)) {
        if (kind == 6 || kind == 8) {
            dmg <<= 1;
        }
    }
    return dmg;
}

int MsCheckUseCommand(int id, OfsTbl *t, int add) {
    BtlChr *c;
    int v;

    if (t != 0) {
        c = MsGetChr(id);
        if (t->b26 != 0 && (c->f27C < c->f27D || ((c->f2D6 >> 10) & 1)) && D_0031732C == 0) {
            return -1;
        }
        if (((t->flags >> 17) & 1) && c->f2C9 != 0) {
            return -1;
        }
        v = MsGetCommandMP(id, t);
        if (MsGetRamChrMonster(id) == 1 || D_00317321 != 0) {
            v = 0;
            add = 0;
        }
        return (c->f294 < v + add) ? -1 : v;
    }
    return -1;
}

int MsGetCommandMP(int id, OfsTbl *t) {
    int mp = 0;
    if (t != 0) {
        BtlChr *c = MsGetChr(id);
        int mul;
        int div;
        int add;

        if (c->pad38E[0] == 0) {
            mp = t->b25;
        }
        mul = 1;
        div = 1;
        add = 0;
        if ((c->f37C >> 14) & 1) {
            div = 2;
            add = 1;
        }
        if ((c->f37C >> 15) & 1) {
            if (mp != 0) {
                mp = 1;
                div = 1;
                add = 0;
            }
        }
        if (func_001C2800(c, t, 0, 0) != 0) {
            mul = 2;
            add = 0;
        }
        mp = (mp * mul + add) / div;
        if ((c->f300 >> 2) & 1) {
            mp = 0;
        }
    }
    return mp;
}

void *MsGetCommand(int id, int a, int stop_cmd, void *cmd_list, int *io_cmd) {
    int count = (cmd_list != 0) ? 2 : 1;
    int found_cmd = 0;
    int i = 0;
    OfsTbl *res = 0;

    for (; i < count; i++) {
        int cmd;
        OfsTbl *t;
        int sub;

        if (cmd_list != 0) {
            cmd = ((u16 *)cmd_list)[i];
        } else {
            cmd = 0xFF;
            if (io_cmd != 0) {
                cmd = *io_cmd;
            }
        }
        sub = cmd & 0xFFF;
        t = 0;
        switch (cmd >> 12) {
        case 3:
            t = MsGetRomPlyCommand(sub, 0);
            break;
        case 4:
            t = MsGetRomMonCommand1(sub, 0);
            break;
        case 6:
            t = MsGetRomMonCommand2(sub, 0);
            break;
        case 2:
            t = MsGetRomItem(sub, 0);
            break;
        }
        if (t != 0) {
            int kind = t->b16 & 0xF8;
            if (res == 0 || (kind != 8 && kind != 0x10)) {
                res = t;
                found_cmd = cmd;
            }
        }
        if (cmd == 0x311E || cmd == 0x3024 || cmd == 0x302A || cmd == stop_cmd) {
            break;
        }
    }
    if (io_cmd != 0) {
        if (res != 0) {
            *io_cmd = found_cmd;
        } else {
            *io_cmd = 0;
        }
    }
    return res;
}

/* DEBT(CAST) */
s32 func_001C2C98(s32 id, s32 a, s32 b) {
    BtlChr *temp_4;
    OfsTbl *temp_2;
    s32 var_17;
    s32 var_5;
    s32 var_6;

    temp_2 = MsGetComData(a, 0);
    var_17 = 0;
    if (temp_2 != 0) {
        temp_4 = MsGetChr(id);
        if (!(!(((u32) temp_2->flags >> 0x12) & 1))) {
            var_6 = temp_4->f281;
            var_5 = temp_2->b2D | temp_4->f299;
        } else {
            var_6 = temp_2->b28;
            var_5 = temp_2->b2D;
        }
        switch (b) {
        case 0:
            var_17 = var_6;
            break;
        case 1:
            var_17 = (*(u16 *)((u8 *)(temp_2) + (0x20))) & 3;
            break;
        case 10:
            var_17 = ((u16) temp_2->h1A >> 2) & 3;
            break;
        case 2:
            var_17 = temp_2->pad23 & 1;
            break;
        case 3:
            var_17 = temp_2->pad23 & 2;
            break;
        case 4:
            var_17 = temp_2->pad23 & 4;
            break;
        case 5:
            var_17 = ((s32) var_5 >> 4) & 1;
            break;
        case 6:
            var_17 = ((s32) var_5 >> 3) & 1;
            break;
        case 7:
            var_17 = ((s32) var_5 >> 2) & 1;
            break;
        case 8:
            var_17 = ((s32) var_5 >> 1) & 1;
            break;
        case 9:
            var_17 = var_5 & 1;
            break;
        }
    }
    return (s32) var_17;
}

int MsGetRndChr(int id, int kind) {
    int off = 0;
    int v;
    switch (kind) {
    case 1: off = 0x10; break;
    case 2: off = 0x20; break;
    }
    if (MsGetRamChrMonster(id) == 0) {
        if (MsGetRamChrSummon(id) != 0) {
            v = 0x1B;
        } else {
            v = id + 0x14;
        }
    } else {
        v = id + 8;
    }
    return v + off;
}

int MsSetChrImageDamageAttack(BtlChr *c) {
    int a = MsCalcDamageCommand(c, c, 0, 0xE, 0x10, 0, 1, 0, 0, 0, 0);
    int b = MsCalcDamageCommand(c, c, 0, 0x14, 0x10, 0, 1, 0, 0, 0, 0);
    if (b < a) b = a;
    return c->f3B4 = b;
}

int MsCalcDamageCommand(BtlChr *src, BtlChr *dst, int c, int d, int e, int f, int g, int h, int i, int j, int k)
{
    u8 *cmd = (u8 *)c;
    u16 flags = f;
    int *out_def = (int *)i;
    int *out_mdef = (int *)j;
    int cur_val = 0;
    int max_val = 0;
    int ret = k;
    int rnd_id;
    int def;
    int mdef;
    int rnd;
    int s;

    rnd_id = MsGetRndChr(src->f0C, 0);
    def = dst->pad269[0];
    mdef = dst->pad26B[0];
    switch (g) {
    case 1:
        cur_val = *(s32 *)((u8 *)dst + 0x3A4);
        max_val = dst->f254;
        break;
    case 2:
        cur_val = *(s32 *)((u8 *)dst + 0x3A8);
        max_val = dst->f258;
        break;
    case 4:
        cur_val = *(s32 *)((u8 *)dst + 0x3AC);
        max_val = dst->f31D;
        break;
    }
    if (cmd != 0 && (cmd[0x23] & 1)) {
        if ((flags >> 6) & 1) {
            def = 0;
        }
        if ((flags >> 7) & 1) {
            mdef = 0;
        }
    }
    if (h != 0) {
        rnd = (brnd(rnd_id) & 0x1F) + 0xF0;
    } else {
        rnd = 0x100;
    }
    switch (d) {
    case 1: {
        int base;
        int d_num;
        int v;

        s = src->f268 + src->pad31E[0];
        base = (s * s * s) / 32 + 30;
        d_num = 730 - (def * 51 - (def * def) / 11) / 10;
        v = base * d_num / 730;
        v = v * (15 - dst->pad31E[0]) / 15;
        ret = (v * e / 16) * rnd / 256;
        break;
    }
    case 2:
        s = src->f268 + src->pad31E[0];
        ret = ((((s * s * s) / 32 + 30) * e) / 16) * rnd / 256;
        break;
    case 3: {
        int base;
        int d_num;
        int v;

        s = src->f26A + src->pad31E[2];
        base = ((s * s) / 6 + e) * e / 4;
        d_num = 730 - (mdef * 51 - (mdef * mdef) / 11) / 10;
        v = base * d_num / 730;
        v = v * (15 - dst->pad31E[2]) / 15;
        ret = v * rnd / 256;
        break;
    }
    case 4:
        s = src->f26A + src->pad31E[2];
        ret = ((((s * s) / 6 + e) * e) / 4) * rnd / 256;
        break;
    case 5:
        ret = cur_val * e / 16;
        break;
    case 6:
        ret = e * 50;
        break;
    case 7:
        ret = ((src->f26A + src->pad31E[2] + e) / 2) * e * rnd / 256;
        break;
    case 8:
        ret = max_val * e / 16;
        break;
    case 9: {
        int tmp = rnd * 50;

        ret = e * tmp / 256;
        break;
    }
    case 10:
        ret = (u32)(dst->f258 * e) / 16;
        break;
    case 11:
        ret = dst->f31D * e / 16;
        break;
    case 12:
        ret = *(s32 *)((u8 *)dst + 0x3A8) * e / 16;
        break;
    case 13:
        ret = *(s32 *)((u8 *)dst + 0x3AC) * e / 16;
        break;
    case 14:
        s = src->f268;
        return (((s * s * s) / 32 + 30) * e) / 16;
    case 20:
        s = src->f26A;
        return (((s * s * s) / 32 + 30) * e) / 16;
    case 15:
        s = src->f26A + src->pad31E[2];
        ret = ((((s * s * s) / 32 + 30) * e) / 16) * rnd / 256;
        break;
    case 16:
        ret = (u32)(src->f254 * e) / 10U;
        break;
    case 17: {
        u32 pct;
        u32 v;

        s = src->f268 + src->pad31E[0];
        pct = (u32)(src->f290 * 100) / (u32)src->f254 + 10;
        v = (u32)(((s * s * s) / 32 + 30) * pct) / 110U;
        ret = (u32)((u32)(v * e) >> 4) * rnd >> 8;
        break;
    }
    case 18: {
        u32 pct;
        u32 v;

        s = src->f268 + src->pad31E[0];
        pct = (u32)(src->f294 * 100) / (u32)src->f258 + 10;
        v = (u32)(((s * s * s) / 32 + 30) * pct) / 110U;
        ret = (u32)((u32)(v * e) >> 4) * rnd >> 8;
        break;
    }
    case 19: {
        u32 pct;
        u32 v;

        s = src->f268 + src->pad31E[0];
        pct = 130 - (u32)(src->f290 * 100) / (u32)src->f254;
        v = (u32)(((s * s * s) / 32 + 30) * pct) / 60U;
        ret = (u32)((u32)(v * e) >> 4) * rnd >> 8;
        break;
    }
    case 21:
        ret = D_003188B0 / 10;
        break;
    case 22:
        if (dst->f0C < 18) {
            ret = ((struct { u8 pad[0x5620]; struct { s32 v; u8 pad[0x90]; } ent[18]; } *)&D_003194D0)->ent[dst->f0C].v * e;
        }
        break;
    case 23:
        ret = e * 9999;
        break;
    }
    if (cmd != 0 && ((*(u16 *)(cmd + 0x20) >> 4) & 1)) {
        if (!((flags >> 1) & 1)) {
            ret = -ret;
        }
    }
    if (out_def != 0) {
        *out_def = def;
    }
    if (out_mdef != 0) {
        *out_mdef = mdef;
    }
    return ret;
}

int func_001C3578(int a, int mask, Q4Flags *f) {
    int r = 0;
    int e = 0;
    int g = 0;
    int h = 0;
    int d = 0;
    int have = 0;
    int need = 0;

    if (mask & 1) {
        need++;
        if (f->b0E != 0) {
            e = f->b0E;
            have++;
        }
    }
    if ((mask >> 2) & 1) {
        need++;
        if (f->b0F != 0) {
            g = f->b0F;
            have++;
        }
    }
    if ((mask >> 1) & 1) {
        need++;
        if (f->b10 != 0) {
            h = f->b10;
            have++;
        }
    }
    if ((mask >> 3) & 1) {
        need++;
        if (f->b0D != 0) {
            d = f->b0D;
            have++;
        }
    }
    if (have > 0 && have >= need) {
        if (e != 0 && e < 0xFE) {
            e--;
            f->b0E = e;
        }
        if (g != 0 && g < 0xFE) {
            g--;
            f->b0F = g;
        }
        if (h != 0 && h < 0xFE) {
            h--;
            f->b10 = h;
        }
        if (d != 0 && d < 0xFE) {
            d--;
            f->b0D = d;
        }
        r = -1;
    }
    return r;
}

int func_001C3688(int flag, int a, BtlChr *c, int b, BtlChr *c2, Q4Act *act) {
    int r = 0;
    int mode = act->h20 & 3;
    if (((act->h1A >> 2) & 3) == 0) {
        if (c->fAB1 != 0) goto end; /* DEBT(GOTO): an early return r gets folded to return 0 */
        if (a != b && *(s8 *)&D_00319432 != 0 /* DEBT(TYPE): read as signed here */) {
            if (mode == 1) {
                if ((c2->f37C >> 4) & 1) {
                    r = 2;
                } else if ((c2->f37C >> 3) & 1) {
                    r = 1;
                }
            } else if (mode == 2) {
                if ((c2->f37C >> 5) & 1) r = 1;
            }
            if (flag != 0 && r != 0 && MsCheckWrongStatus(act) != 0) {
                c2->f39C = 1;
            }
        }
    }
end:
    return r;
}

int func_001C3758(int id, BtlChr *c, int x, BtlChr *c2) {
    int r = 0;
    if (MsAutoCommandStatusCheck(c2, 1, 1, 1) != 0) {
        GsEnt48 e;
        r = 1;
        if (c->f106 == 1) {
            c->f39D = 1;
        } else {
            c->f39D = 0;
        }
        MsStructClear(&e, 0x48);
        e.id = x;
        e.f3 = 1;
        e.f8[0].h0 = c2->f386;
        e.f8[0].h2 = 0xFF;
        e.f8[0].targets = 1 << id;
        MsInsertBtlCommand(&e, 0, 1, id);
    }
    c2->f39C = 0;
    return r;
}

void func_001C3828(int unused, BtlChr *c, Q4Act *act, int unused2, int *cnt, Q4Act *b) {
    if ((act->h20 & 3) == 1) {
        if (((b->h14 >> 8) & 1) && !((c->f2EA >> 8) & 1)) {
            b->h14 &= ~0x100;
            cnt[1]++;
        }
        if ((u32)(b->b07 - 1) < 0xFE) {
            c->f1CF = 1;
            b->b07 = 0;
            cnt[2]++;
        }
    }
}

int func_001C38A8(Q4Act *act, u32 *flags, int *mode, Q4Flags *f, int dmg) {
    int m = act->h20 & 3;
    if (m == 2 && f->b0A != 0) {
        *mode = m;
        dmg /= 2;
        *flags |= 0x20;
    }
    return dmg;
}

int func_001C38E8(Q4Act *act, u32 *flags, int *mode, Q4Flags *f, int dmg) {
    if ((act->h20 & 3) == 1 && f->b0B != 0) {
        *mode = 2;
        dmg /= 2;
        *flags |= 0x40;
    }
    return dmg;
}

int func_001C3930(BtlChr *c, BtlChr *c2, Q4Act *act, u32 *flags, int dmg) {
    int r;
    int v;

    if ((act->h20 >> 2) & 1) {
        r = brnd(MsGetRndChr(c->f0C, 0)) % 101;
        v = c->f26D + c->f322 - c2->f26D + c2->f323;
        if ((act->h20 >> 3) & 1) {
            v += c->f298;
        } else {
            v += act->b27;
        }
        if (r < v || ((c->f300 >> 4) & 1) || D_0031732D != 0) {
            dmg *= 2;
            *flags |= 0x100;
        }
    }
    return dmg;
}

int func_001C3A38(BtlChr *c, int kind, u32 *flags, u32 mask, int *cnt, int ret) {
    if (kind == 8 || kind == 5) {
        if ((c->flags278 >> 1) & 1) {
            *flags &= ~mask;
            ret = 0;
            (*cnt)++;
        }
    }
    return ret;
}

int func_001C3A88(BtlChr *c, Q4Act *a, Q4Act *b, int dmg) {
    int s = ((c->f2C6 >> 1) & 1) + ((b->h14 >> 1) & 1);
    if ((a->w1C >> 8) & 1) {
        if (s == 1) {
            dmg = -dmg;
        }
    }
    return dmg;
}

int func_001C3AD0(BtlChr *c, int unused_a1, int mask, int dmg) {
    u8 f29A;
    u8 f29D;
    u8 f29C;
    u8 f29B;
    int found;
    int i;

    if (mask == 0) {
        return dmg;
    }
    found = 0;
    f29D = c->f29D;
    f29C = c->f29C;
    f29B = c->f29B;
    f29A = c->f29A;
    for (i = 0; i < 8; i++) {
        if (((mask >> i) & 1) && ((f29D >> i) & 1)) {
            found = 1;
            dmg = dmg * 3 / 2;
        }
    }
    if (found) {
        return dmg;
    }
    for (i = 0; i < 8; i++) {
        if (((mask >> i) & 1) && !((f29B >> i) & 1) && !((f29C >> i) & 1) && !((f29A >> i) & 1)) {
            found = 1;
        }
    }
    if (found) {
        return dmg;
    }
    for (i = 0; i < 8; i++) {
        if (((mask >> i) & 1) && ((f29C >> i) & 1) && !((f29B >> i) & 1) && !((f29A >> i) & 1)) {
            found = 1;
        }
    }
    if (found) {
        return dmg / 2;
    }
    for (i = 0; i < 8; i++) {
        if (((mask >> i) & 1) && ((f29B >> i) & 1) && !((f29A >> i) & 1)) {
            dmg = 0;
            found = 1;
        }
    }
    if (found) {
        return dmg;
    }
    for (i = 0; i < 8; i++) {
        if (((mask >> i) & 1) && ((f29A >> i) & 1)) {
            found = 1;
        }
    }
    if (found) {
        return -dmg;
    }
    return dmg;
}

int func_001C3C90(BtlChr *c, BtlChr *c2, Q4ActB *a2, Q4Act *a3, int *out, int dmg) {
    if ((a2->h1E & 1) == 0 && (c2->flags278 & 1) != 0) {
        if (((c->f37C >> 13) & 1) == 0 && ((a3->h14 >> 6) & 1) == 0) {
            dmg /= 3;
            *out = 1;
        }
    }
    return dmg;
}

int func_001C3D00(BtlChr *c, Q4Act *a, u32 *flags, Q4Act *b, int dmg) {
    if ((a->h20 & 3) == 1 && (((b->h16 >> 11) & 1) || ((b->h16 >> 13) & 1))) {
        c->f39A = 1;
        dmg /= 2;
        if ((b->h16 >> 11) & 1) {
            *flags |= 8;
        } else {
            *flags |= 0x10;
        }
    }
    return dmg;
}

int func_001C3D78(Q4Act *a, Q4Act *b, int dmg) {
    if ((a->h20 & 3) != 1 && ((b->h16 >> 7) & 1) != 0) {
        dmg /= 5;
    }
    return dmg;
}

int func_001C3DC0(BtlChr *c, Q4Act *act, int dmg) {
    int m = act->h20 & 3;
    if (m == 1) {
        if ((c->f2C6 >> 4) & 1) {
            dmg /= 2;
        }
    }
    if (m == 2) {
        if ((c->f2C6 >> 5) & 1) {
            dmg /= 2;
        }
    }
    return dmg;
}

int func_001C3E20(BtlChr *c, Q4Act *act, u32 *flags, u32 mask, int *cnt, int ret) {
    int r = 0;
    int m = act->h20 & 3;
    if (m == 1 && ((c->flags278 >> 5) & 1)) r = 1;
    if (m == 2 && ((c->flags278 >> 6) & 1)) r = 1;
    if ((c->flags278 >> 7) & 1) r = 1;
    if (r) {
        *flags &= ~mask;
        ret = 0;
        (*cnt)++;
    }
    return ret;
}

int func_001C3EA0(BtlChr *c, int v) {
    if (c->f9E6 != 0) {
        float d = c->f9F0 + c->f9F0;
        v = v * (d + c->f9EC) / d;
    }
    return v;
}

void func_001C3EE8(int unused, Q4Act *a, int b, int *p, int *cnt, int *arr) {
    int i;
    if (((a->h14 >> 2) & 1) != 0 && ((b >> 2) & 1) != 0 && ((a->h16 >> 8) & 1) == 0) {
        *p = 0;
        for (i = 2; i >= 0; i--) {
            arr[i] = 0;
        }
        cnt[6]++;
    }
}

int func_001C3F58(int a, int b, Q4Act *act, int dmg) {
    Ent4 *p1 = &((Ent4 *)D_0031F988)[a];
    Ent4 *p2 = &((Ent4 *)D_0031F988)[b];
    int m = act->h20 & 3;

    if (m == 1) {
        if (p1->b0 != 0) {
            dmg += dmg * p1->b0 / 100;
        }
        if (p2->b2 != 0) {
            dmg -= dmg * p2->b2 / 100;
        }
    } else if (m == 2) {
        if (p1->b1 != 0) {
            dmg += dmg * p1->b1 / 100;
        }
        if (p2->v != 0) {
            dmg -= dmg * p2->v / 100;
        }
    }
    return dmg;
}

extern s8 D_0031FA08[];

int func_001C4008(BtlChr *src, BtlChr *dst, OfsTbl *act, Q4Act *b, int mode) {
    u32 flags = act->flags;
    int type;
    int acc;
    int hit;
    int r;

    if (((flags >> 23) & 1) && !(dst->f2C6 & 1) && !((dst->f2C6 >> 1) & 1)) {
        return 2;
    }
    type = (flags >> 3) & 7;
    acc = 0;
    switch (type) {
    case 0:
        return 0;
    case 1:
    case 2:
        acc = ((u8 *)act)[0x29];
        break;
    case 3:
    case 4:
        acc = src->pad26E[1];
        break;
    case 5:
        acc = (src->pad26E[1] * 5) >> 1;
        break;
    case 6:
        acc = (src->pad26E[1] * 3) >> 1;
        break;
    case 7:
        acc = src->pad26E[1] >> 1;
        break;
    }
    {
        int sleep = b->b07;
        if (sleep > 0) {
            return 0;
        }
    }
    if ((b->h14 >> 2) & 1) {
        return 0;
    }
    if (D_003172F0.f4F != 0) {
        return 1;
    }
    r = brnd(MsGetRndChr(src->f0C, 1)) % 101;
    hit = 0;
    switch (type) {
    case 1:
    case 3:
    case 5:
    case 6:
    case 7: {
        int idx;
        int e;
        idx = (acc * 2) / 5;
        e = dst->pad26E[0] - 10;
        idx -= e;
        if (idx < 0) {
            idx = 0;
        }
        if (idx > 8) {
            idx = 8;
        }
        hit = D_0031FA08[idx];
        if (((act->flags >> 6) & 1) && src->f2CA != 0) {
            hit /= 10;
        }
        {
            int a = src->pad31E[1] * 10 + hit;
            int b = src->f322 + src->f26D;
            hit = a + b - dst->f26D + dst->f323 - dst->pad31E[3] * 10;
        }
        break;
    }
    case 2:
    case 4:
        hit = acc - dst->pad26E[0];
        if (((act->flags >> 6) & 1) && src->f2CA != 0) {
            hit /= 10;
        }
        {
            int a = src->pad31E[1] * 10 + hit;
            int b = src->f322 + src->f26D;
            hit = a + b - dst->f26D + dst->f323 - dst->pad31E[3] * 10;
        }
        break;
    }
    if ((r < hit && mode != 2) || (s8)D_003172F0.pad34[6] != 0) {
        return 0;
    }
    return 1;
}

u32 func_001C4290(BtlChr *c, Q4Act *act, u32 flags, Triple *t) {
    int k;
    if ((act->w1C >> 14) & 1) {
        k = 2;
    } else {
        k = (act->w1C >> 13) & 1;
    }
    if (k != 0) {
        int v;
        flags |= 4;
        v = MsGetRomCTBcount(c->f26C) * 3;
        t->w8 += v * k / 2;
    }
    return flags;
}

int func_001C4320(int a, Q4Act *act, u32 *flags, u32 mask, int t0, Triple *cnt, Triple *t2) {
    if ((t0 & 4) && ((act->h14 >> 11) & 1)) {
        t2->w8 = 0;
        *flags &= ~mask;
        cnt->w4 += 1;
    }
    return t0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", func_001C4368);

int func_001C4EF0(int x) {
    if (((x >> 1) & 1) || ((x >> 2) & 1) || ((x >> 3) & 1) || ((x >> 4) & 1) || ((x >> 5) & 1)) {
        return -1;
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", func_001C4F40);

/* DEBT(CAST) */
s32 func_001C5340(s32 arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    s32 temp_19;
    s32 temp_3;
    s32 var_22;

    var_22 = 0;
    if ((*(s32 *)((u8 *)(arg2) + (0x1C))) < 0) {
        temp_19 = ((u32) ((u32) ((D_003172F0.f15C0 + (*(s32 *)((u8 *)(arg1) + (0x3C4)))) << 8) / (u32) (*(u32 *)((u8 *)(arg1) + (0x254)))) / 20U) - 0x40;
        temp_3 = brnd(MsGetRndChr(arg0, 2)) & 0xFF;
        if ((((u16) (*(u16 *)((u8 *)(arg1) + (0x278))) >> 0xA) & 1) || ((*(u8 *)((u8 *)(arg4) + (7))) != 0)) {
            (*(s32 *)((u8 *)(arg3) + (0x14))) = (s32) ((*(s32 *)((u8 *)(arg3) + (0x14))) + 1);
        } else if (((temp_3 < temp_19) && (D_003172F0.f15C0 > 0)) || ((s8) D_003172F0.pad34[6] != 0)) {
            (*(s32 *)((u8 *)(arg1) + (0x3C8))) = temp_19;
            (*(s8 *)((u8 *)(arg1) + (0x3C1))) = 2;
            var_22 = 1;
            (*(u16 *)((u8 *)(arg4) + (0x16))) = (u16) ((*(u16 *)((u8 *)(arg4) + (0x16))) | 0x100);
            (*(s32 *)((u8 *)(arg3) + (0x10))) = (s32) ((*(s32 *)((u8 *)(arg3) + (0x10))) + 1);
        } else {
            (*(s32 *)((u8 *)(arg3) + (0x18))) = (s32) ((*(s32 *)((u8 *)(arg3) + (0x18))) + 1);
        }
        (*(s32 *)((u8 *)(arg1) + (0x3C4))) = MsCheckRange((*(s32 *)((u8 *)(arg1) + (0x3C4))) + D_003172F0.f15C0, 0, 0x3B9AC9FF);
    }
    return var_22;
}

int func_001C54A0(BtlChr *c, Triple *t, Q4Cnt *n, int unused, int t0, int t1) {
    if (t0 & 4) {
        if (((c->flags278 >> 8) & 1) && t1 == 0) {
            n->w14++;
            t->w8 = 0;
        } else if (t->w8 != 0) {
            n->w10++;
        }
    }
    return t0;
}

u32 func_001C54F8(int unused, Q4Act *a, int b, u32 flags, int *out) {
    if ((b & 1) == 0 && (a->h14 & 1) != 0) {
        out[0] = 0;
        out[1] = 0;
        out[2] = 0;
        flags &= ~7;
    }
    return flags;
}

void func_001C5538(int unused, BtlChr *chr, const u8 *effect) {
    int i = 0;
    /* DEBT(TYPE): six adjacent stat levels span pad31E, f322 and f323. */
    u8 *stat = (u8 *)chr + offsetof(BtlChr, pad31E);
    /* DEBT(TYPE): action fields at 0x56 (stat mask) and 0x59 (increment). */
    int mask = *(const u16 *)(effect + 0x56);

    do {
        int amount = effect[0x59];
        if ((mask & (1 << i++)) != 0U) {
            if (!amount) {
                amount = 1;
            }
            *stat = MsCheckRange(*stat + amount, 0, 5);
        }
        stat++;
    } while (i < 6);
}

typedef struct Unk1C55D0_A2 {
    u8 pad0[0xA];
    u8 bA;
    u8 padB[0x24 - 0xB];
    u16 h24[2];
    u8 b28[2];
} Unk1C55D0_A2;

typedef struct Unk1C55D0_A3 {
    u8 pad0[7];
    u8 b7;
    s16 h8;
    u16 hA;
} Unk1C55D0_A3;

extern s8 D_0031732A;
extern s8 D_00317331;

int func_001C55D0(BtlChr *a0, BtlChr *a1, Unk1C55D0_A2 *a2, Unk1C55D0_A3 *a3, int a4) {
    if (a2 != 0) {
        u8 bA = a2->bA;
        int r;
        int lim;

        if (bA == 0 || a2->b28[0] == 0 || (a2->h24[0] >> 12) != 2 || (u8)D_00319405 == (a2->h24[0] >> 12)) {
            bA = 0;
            a3->h8 = 0;
        } else {
            a3->h8 = -1;
        }
        a3->hA = 0;
        a3->b7 = 1;
        r = brnd(10) % 255;
        lim = 0x20;
        if ((a0->f37E >> 8) & 1) {
            lim = 0x100;
        } else if ((a0->f37E >> 7) & 1) {
            lim = 0x80;
        }
        if ((r < bA || D_0031732A != 0) && a4 == 0) {
            int v = a2->bA;
            int r2;
            int idx;

            v >>= 1;
            a2->bA = v;
            if (v == 0) {
                a2->bA = 1;
            }
            r2 = brnd(11) & 0xFF;
            idx = 0;
            if (r2 < lim || D_00317331 != 0) {
                if (a2->b28[1] != 0) {
                    idx = (a2->h24[1] >> 12) == 2;
                }
            }
            a3->h8 = a2->b28[idx];
            a3->hA = a2->h24[idx];
            if (a1 != 0) {
                if (a1->padAAB[0] < 0xFF) {
                    a1->padAAB[0]++;
                }
            }
            MsSaveItemUse(a3->hA, a3->h8);
        }
    }
    return 0;
}

int func_001C5B10(int a0, int a1, int a2, int a3, int a4, int a5, int *a6, int *a7, int *a8, OfsTbl *a9, int a10, int a11, int a12, int a13, int *a14);
int func_001C5E60(int a, int *p);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", func_001C5798);

void MsCalcDrainResult(int a0, BtlChr *a1, OfsTbl *a2, u8 *a3, int *a4, int a5) {
    if (a3[1] < 0x10) {
        int sp40[8];
        int sp60[2];
        int i;
        int orig_kind = a2->pad23;
        int b2C8 = a1->f2C8;
        int *p40 = sp40;
        int *p60 = sp60;
        int kind;
        int res;
        u8 idx;
        u8 *ent;

        for (i = 7; i >= 0; i--) {
            p40[i] = 0;
        }
        for (i = 1; i >= 0; i--) {
            p60[i] = 0;
        }
        kind = orig_kind;
        if (a5 != 0) {
            sp60[1]++;
            kind = 0;
        }
        res = func_001C5B10(a0, a0, 0, 0, 0, 0, a4, p40, p40, a2, 0, b2C8, kind, kind, p60);
        idx = a3[1];
        a3[4] |= 4;
        a3[1] = idx + 1;
        ent = a3 + (idx * 0x2C + 0x18);
        *(u16 *)(ent + 0x18) = kind;
        ent[2] = kind;
        ent[0] = res;
        ent[1] = func_001C5E60(kind, p60);
        for (i = 0; i < 3; i++) {
            ((int *)(ent + 0x20))[i] = a4[i];
        }
        func_001C0D00((Unk1C0D00 *)ent, 0, (Unk1C0D00Chr *)a1);
    }
}

int func_001C5A80(int a, int b) {
    int n = 0;
    if (MsBtlChrNumCheck(a) != 0) {
        int m = MsGetChrBit(a, b, 1, 1);
        int i;
        for (i = 0; i < 0x1F; i++) {
            if ((m >> i) & 1) {
                n++;
                MsGetChr(i)->fE5 = 0;
            }
        }
    }
    return n;
}

int func_001C5B10(int a0, int a1, int a2, int a3, int a4, int a5, int *a6, int *a7, int *a8, OfsTbl *a9, int a10, int a11, int a12, int a13, int *a14)
{
    int i;
    int max_val;
    int max_idx;
    int min_idx;
    int min_val;
    int low2;
    int ret;
    s8 f107;
    BtlChr *chr;

    if (a7[4] == 0) {
        if (a7[6] != 0) {
            a14[1]++;
        } else if (a7[5] != 0) {
            a14[0]++;
        }
    }
    low2 = a12 & 3;
    max_idx = -1;
    min_idx = -1;
    max_val = 0;
    min_val = 0;
    for (i = 0; i < 2; i++) {
        int val = a6[i];
        if (max_idx < 0 || max_val < val) {
            max_idx = i;
            max_val = val;
        }
        if (min_idx < 0 || val < min_val) {
            min_val = val;
            min_idx = i;
        }
    }
    ret = 0;
    chr = MsGetChr(a1);
    f107 = *((s8 *)chr + 0x107);
    if (max_val > 0) {
        int denom;
        int flag;
        int unused;

        switch (max_idx) {
        case 1:
            denom = MsGetRamChrMPmax(a1);
            break;
        case 2:
            denom = func_001BB2B0(a1);
            break;
        default:
            denom = MsGetRamChrHPmax(a1);
            break;
        }
        flag = 0;
        if (denom == 0) {
            denom = 1;
        }
        ret = 5;
        unused = max_val / denom;
        if (a3 != 0 || (a5 >= 100 && a2 == 2) || (a4 >= 100 && a2 == 1)) {
            if (a2 == 2 && (f107 & 2) && !((a10 >> 7) & 1)) {
                flag = 1;
                ret = 3;
            }
            if (a2 == 1 && (f107 & 1) && !((a10 >> 6) & 1)) {
                flag = 1;
                ret = 4;
            }
        }
        if (a12 & 0x100) {
            ret = flag ? 5 : 6;
        }
    } else if (a2 == 1 && low2 != 0) {
        ret = (f107 & 1) ? 4 : 5;
    } else if (a7[1] != 0) {
        ret = 8;
    } else if (a7[2] != 0) {
        ret = 11;
    } else if (a8[2] != 0) {
        ret = 12;
    } else if (a8[3] != 0) {
        ret = 2;
    } else if (min_val < 0) {
        if (a0 != a1) {
            ret = a11 ? 0 : 2;
        }
    } else if (a2 == 2 && low2 != 0 && (f107 & 2)) {
        ret = 3;
    } else if (low2 != 0) {
        ret = 0;
    } else if (a6[2] != 0) {
        ret = 0;
    } else if (a8[1] != 0) {
        if (a0 != a1) {
            ret = a11 ? 0 : 7;
        }
    } else if (a7[0] != 0) {
        ret = 9;
    } else {
        ret = a8[0] ? 10 : 0;
    }
    return ret;
}

int func_001C5E60(int a, int *p) {
    int r = 0;
    if (a == 0) {
        r = p[1] != 0;
    }
    if (p[1] == 0) {
        if (p[0] != 0) {
            r = 2;
        }
    }
    return r;
}
