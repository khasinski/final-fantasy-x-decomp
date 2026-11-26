/* tu_211 0x1e2360-0x1e4c30: medium; ~Ms (config/tu_map.tsv) */
#define msResetHeadTarget _hdr_msResetHeadTarget
#define func_001E2560 _hdr_func_001E2560
#define MsMessageCueRegist _hdr_MsMessageCueRegist
#define MsLimitUp _hdr_MsLimitUp
#define D_003172F0 _hdr_D_003172F0
#include "common.h"
#include "ffx/g3.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"
#include "ffx/w5.h"
#undef msResetHeadTarget
#undef func_001E2560
#undef MsMessageCueRegist
#undef MsLimitUp
#undef D_003172F0

int MsMessageCueRegist(int a, int b, int c, int d, int e);
int MsSetSaveCommand(int a, int b, int c);

typedef struct {
    u8 pad0[0x14];
    s8 f14;
    u8 pad15[0x1752 - 0x15];
    u8 f1752;
    u8 pad1753[0x175B - 0x1753];
    u8 f175B;
    u8 pad175C[0x207A - 0x175C];
    u16 h207A;
    u8 pad207C[0x2115 - 0x207C];
    u8 f2115;
    u8 pad2116[0x2133 - 0x2116];
    s8 f2133;
    u8 pad2134[0x213E - 0x2134];
    u8 f213E;
} GameStateLocal;

extern GameStateLocal D_003172F0;

int func_001E2360(void) {
    int i;
    int n = 0;
    for (i = 0; i < 0x1F; i++) {
        if (MsGetChr(i)->fAB0 != 0) {
            n++;
        }
    }
    return n;
}

void MsLimitTypeProcess(void) {
    register GameStateLocal *g __asm__("s0") = &D_003172F0;
    int flag;
    int i;
    int j;
    u8 id;
    PartySlot *p;
    s32 m;
    u16 *h;
    u16 cmd;

    if (g->f14 == 0 && g->f1752 == 1 && g->f175B != 0 && func_001E2360() == 0) {
        flag = 0;
        for (i = 0; i < 7; i++) {
            id = D_003192B5[i];
            if (id != 0xFF) {
                p = &D_0031EA9C[id];
                MsGetChr(id);
                m = p->v88;
                h = p->h60;
                for (j = 0; j < 20; j++, h++) {
                    if (!((m >> j) & 1) && *h == 0) {
                        flag = 1;
                        if (MsMessageCueRegist(7, id, j, 0x1E, 0x32) != 0) {
                            m |= 1 << j;
                        }
                    }
                }
                p->v88 = m;
            }
        }
        cmd = D_003172F0.h207A;
        if (cmd != 0) {
            flag = 1;
            if (MsMessageCueRegist(6, 0, cmd, 0x1E, 0x32) != 0) {
                MsSetSaveCommand(0, cmd, 1);
                D_003172F0.h207A = 0;
            }
        }
        if (flag == 0) {
            D_003172F0.f175B = 0;
        }
    }
}

typedef struct {
    u8 pad0[0x3DAC];
    s32 f3DAC;
} SaveDataE2560;

extern u16 D_00320068[];
extern s32 D_00320070[];

int func_001E2560(int id) {
    int r = 0;
    int i;

    if (id == 0 && D_003172F0.f2115 != 2) {
        MsGetChr(0);
        ((SaveDataE2560 *)&D_003194D0)->f3DAC++;
        for (i = 0; i < 4; i++) {
            u16 cmd = D_00320068[i];
            if (MsGetSaveCommand(id, cmd) == 0 && ((SaveDataE2560 *)&D_003194D0)->f3DAC >= D_00320070[i]) {
                r = 1;
                D_003172F0.h207A = cmd;
                D_003172F0.f175B = 1;
            }
        }
    }
    return r;
}

int func_001E2658(int i, int k, int force) {
    GameStateLocal *g = &D_003172F0;
    int r = 0;
    BtlChr *c;
    s32 bits;
    PartySlot *p;
    s32 m;

    if (g->f2115 == 0 && i >= 0 && i < 7 && (u32)k < 17) {
        c = MsGetChr(i);
        if ((c->fA8C == 0 && c->fA8E == 0) || force) {
            bits = c->f3B0;
            if (!((bits >> k) & 1)) {
                p = &D_0031EA9C[i];
                if (p->h60[k] != 0xFFFF) {
                    c->f3B0 = bits | (1 << k);
                    m = p->v88;
                    if (p->h60[k] == 0 || --p->h60[k] == 0) {
                        if (!((m >> k) & 1)) {
                            g->f175B = 1;
                            r = 1;
                        }
                    }
                }
            }
        }
    }
    return r;
}

extern s8 D_00317336;

int MsLimitUp(int a, BtlChr *c, int b) {
    u8 old;
    int val;

    if (D_00317336 == 0 && !((c->f2D6 >> 10) & 1) && c->fA8C == 0 && c->fA8E == 0) {
        if ((c->f37E >> 1) & 1) {
            b *= 3;
        } else if (c->f37E & 1) {
            b *= 2;
        } else if ((c->f37E >> 2) & 1) {
            b <<= MsCalcWeakLevel(c->f290, c->f254) > 0;
        }
        if ((c->f300 >> 5) & 1) {
            b = (b * 3) / 2;
        }
        b <<= (c->f300 >> 6) & 1;
        if ((c->f2D6 >> 6) & 1) {
            b = 0;
        }
        b <<= (c->f2D6 >> 7) & 1;
        if ((c->f37E >> 3) & 1) {
            register double v __asm__("v0");
            register double k __asm__("a1");
            MsApUp(a, c, (int)((MsGetNextAP(a) * b / c->f27D) * *(float *)&c->pad3C2[0xA]), 0);
            b = 0;
            v = *(float *)&c->pad3C2[0xA];
            __asm__(".set noat\n\tlui $1, %%hi(D_0056F8D8)\n\tld %0, %%lo(D_0056F8D8)($1)\n\t.set at" : "=r"(k), "+r"(v));
            *(float *)&c->pad3C2[0xA] = v * k;
        }
        old = c->f27C;
        val = MsCheckRange(old + b, 0, c->f27D);
        c->f27C = val;
        if (old < val && val == c->f27D) {
            MsSaveAddInfoData(a, 3);
        }
    }
    return b;
}

int MsLimitTypeDamageCheck(int src_id, BtlChr *src, int dst_id, BtlChr *dst, int dmg, int dmg2, int flag) {
    int count = 0;
    int src_mon = MsGetRamChrMonster(src_id);
    int dst_mon = MsGetRamChrMonster(dst_id);
    int i;

    if (dst->f27B == 0x13 && dmg >= 0 && src_mon == 1 && dst_mon == 0) {
        MsLimitUp(dst_id, dst, (u32)(dmg2 * 18) / dst->f254 + 1);
    }
    if (dmg > 0) {
        if (src_mon == 1 && dst_mon == 0) {
            count++;
            func_001E2658(dst_id, 2, 0);
            if (dst->f27B == 2) {
                MsLimitUp(dst_id, dst, (u32)(dmg * 30) / dst->f254 + 1);
            }
            for (i = 0; i < 7; i++) {
                BtlChr *c = MsGetChr(i);
                if (c->fA88 != 0 && i != dst_id) {
                    count++;
                    func_001E2658(i, 1, 0);
                    if (c->f27B == 1) {
                        MsLimitUp(i, c, (u32)(dmg * 20) / dst->f254 + 1);
                    }
                }
            }
        } else if (src_mon == 0 && dst_mon == 1) {
            count++;
            if (flag != 0) {
                func_001E2658(src_id, 0, 0);
                if (src->f27B == 0) {
                    int v = (dmg * 10) / src->f3B4 + 1;
                    if (v > 16) {
                        v = 16;
                    }
                    MsLimitUp(src_id, src, v);
                }
                if (src->f27B == 0x13) {
                    MsLimitUp(src_id, src, ((dmg * 16) / src->f3B4) / 10 + 1);
                }
            }
        }
    } else if (dmg < 0) {
        if (src_mon == 0 && dst_mon == 0 && src_id != dst_id) {
            count++;
            func_001E2658(src_id, 3, 0);
            if (src->f27B == 3) {
                dmg = -dmg;
                if (dmg > dst->f254 - dst->f290) {
                    dmg = dst->f254 - dst->f290;
                }
                MsLimitUp(src_id, src, (u32)(dmg * 16) / dst->f254 + 1);
            }
        }
    }
    return count;
}

int MsLimitTypeStatusCheck(int source_id, BtlChr *source, int target_id, BtlChr *target, int a, int b) {
    int count = 0;
    int source_kind = MsGetRamChrMonster(source_id);
    int target_kind = MsGetRamChrMonster(target_id);

    if (source_kind == 1 && target_kind == 0) {
        if (a > 0) {
            count++;
            func_001E2658(target_id, 5, 1);
            if (target->f27B == 5) {
                MsLimitUp(target_id, target, 0x10);
            }
        }
        if (b & 1) {
            count++;
            func_001E2658(target_id, 6, 1);
            if (target->f27B == 6) {
                MsLimitUp(target_id, target, 0x10);
            }
        }
        if (b & 2) {
            count++;
            func_001E2658(target_id, 10, 1);
            if (target->f27B == 10) {
                MsLimitUp(target_id, target, 10);
            }
        }
    } else if (source_kind == 0 && target_kind == 1) {
        if (a > 0) {
            count++;
            func_001E2658(source_id, 4, 0);
            if (source->f27B == 4) {
                MsLimitUp(source_id, source, 0x10);
            }
        }
    }
    return count;
}

/* DEBT(CAST): the final threshold comparison uses unsigned 32-bit values. */
s32 MsLimitTypeDeathCheck(s32 source_id, BtlChr *source, s32 target_id, BtlChr *target)
{
    BtlChr *chr;
    s32 source_kind;
    s32 target_kind;
    s32 value;
    s32 id;
    s32 count;

    count = 0;
    source_kind = MsGetRamChrMonster(source_id);
    target_kind = MsGetRamChrMonster(target_id);
    if ((source_kind == 1) && (target_kind == 0))
    {
        id = 0;
        do
        {
            chr = MsGetChr(id);
            if ((chr->fA88 != 0) && (id != target_id))
            {
                count += 1;
                func_001E2658(id, 7, 0);
                if (chr->f27B == 7)
                {
                    MsLimitUp(id, chr, 0x1E);
                }
            }
            id += 1;
        } while (id < 7);
    }
    else if ((source_kind == 0) && (target_kind == 1))
    {
        func_001E2658(source_id, 8, 0);
        if (source->f27B == 8)
        {
            MsLimitUp(source_id, source, 0x14);
        }
        value = target->f254;
        if (((source->f3B4 * 0x14) < value) || (value >= 0x2710))
        {
            func_001E2658(source_id, 9, 0);
        }
        if (source->f27B == 9)
        {
            if ((u32) (source->f3B4 * 3) < (u32) target->f254)
            {
                MsLimitUp(source_id, source, 0x14);
            }
        }
    }
    return count;
}

int MsLimitTypeTurnCheck(int id, BtlChr *c) {
    int count = 0;
    int n;
    int i;
    BtlChr *t;

    if (id >= 0 && id < 7) {
        count = 1;
        func_001E2658(id, 0xD, 0);
        if (c->f27B == 0xD) {
            MsLimitUp(id, c, 3);
        }
        if (MsCalcWeakLevel(c->f290, c->f254) > 0) {
            count = 2;
            func_001E2658(id, 0xF, 0);
            if (c->f27B == 0xF) {
                MsLimitUp(id, c, 5);
            }
        }
        n = 0;
        for (i = 0; i < 18; i++) {
            if (i != id) {
                t = MsGetChr(i);
                if (t->fA88 != 0 && *(s8 *)&t->padA96[0] != 0 && t->fA8C == 0 && t->fA8E == 0) {
                    n++;
                }
            }
        }
        if (n == 0) {
            count++;
            func_001E2658(id, 0x10, 0);
            if (c->f27B == 0x10) {
                MsLimitUp(id, c, 0x10);
            }
        }
        if (((c->f2C6 >> 1) & 1) || ((c->f2C6 >> 3) & 1) || ((c->f2C6 >> 8) & 1) ||
            c->f2C8 != 0 || c->f2C9 != 0 || c->f2CA != 0 || c->f2D4 != 0 || ((c->f2D6 >> 14) & 1)) {
            count++;
            func_001E2658(id, 0xE, 0);
            if (c->f27B == 0xE) {
                MsLimitUp(id, c, 0x10);
            }
        }
    }
    return count;
}

int MsLimitTypeEscapeCheck(int a, BtlChr *c)
{
    func_001E2658(a, 0xC, 0);
    if (c->f27B == 0xC) {
        MsLimitUp(a, c, 0xA);
    }
    return 0;
}

s32 MsLimitTypeWinCheck(void)
{
    BtlChr *chr;
    s32 i;
    s32 count;

    count = 0;
    i = 0;
    do
    {
        chr = MsGetChr(i);
        if (chr->fA88 != 0)
        {
            count += 1;
            func_001E2658(i, 0xB, 0);
            if (chr->f27B == 0xB)
            {
                MsLimitUp(i, chr, 0x14);
            }
        }
        i += 1;
    } while (i < 7);
    return count;
}

typedef struct {
    u8 pad0[0x26];
    u8 f26;
} UnkCmd26;

typedef struct {
    u8 pad0[8];
    struct {
        u16 h[2];
        u8 pad4[12];
    } f8[4];
} GsEnt48Arr;

int MsLimitCommandProcess(int id, BtlChr *chr, GsEnt48 *ent, int idx) {
    s8 flag = 0;
    int i;
    for (i = 0; i < 2; i++) {
        int cmd = ((GsEnt48Arr *)ent)->f8[idx].h[i];
        UnkCmd26 *t = (UnkCmd26 *)MsGetCommand(id, 0, -1, 0, &cmd);
        if (t != 0) {
            u8 v = t->f26;
            if (v != 0) {
                chr->f38D = v;
                if (cmd == 0x3118) {
                    flag = 1;
                }
            }
        }
    }
    if (chr->f38F != 0) {
        chr->f38F = 0;
        chr->f38D = chr->f27D;
    }
    D_003172F0.f2133 = flag;
    return 0;
}

void MsSummonLimitSave(BtlChr *c)
{
    if (D_00319423 != 0) {
        c->f27E = c->f27C;
        c->f27C = c->f27D;
        c->f27F = 1;
    }
}

void MsSummonLimitLoad(BtlChr *c)
{
    if (c->f27F != 0) {
        c->f27C = c->f27E;
        c->f27F = 0;
    }
}

int MsEffectLimitStart(int a, int b) { /* b: unused; callers pass 0 */
    u8 id = a;
    BtlChr *c = MsGetChr(id);
    OfsTbl *t;
    int k;

    c->f9E4 = 1;
    c->f9E5 = 0;
    k = c->fC1C;
    t = MsGetCommand(id, 0, -1, 0, &k);
    switch (id) {
    case 0:
        TOBtlInitTidusLimitWindow();
        TOBtlOpenTidusLimitWindow(t->b58);
        break;
    case 2:
        TOBtlInitAuronLimitWindow();
        func_0021AEB0(t->b58);
        break;
    case 5:
        TOBtlInitLuluLimitWindow();
        func_0021BAB8(k);
        break;
    }
    MsAtelRequestMagicCamera(0, id, 0, 0x87, 0xFFFF, 0, 1, 0, 0);
    return 0;
}

int MsEffectLimitSync(u8 id)
{
    int r = -1;

    if (MsGetChr(id)->f9E4 == 0) {
        r = 0;
    }
    return r;
}

int func_001E3518(int arg, BtlChr *c) {
    u8 id = arg;
    int r = 0xB;
    int sel = 0;
    int k = c->fC1C;
    OfsTbl *t = MsGetCommand(id, 0, -1, 0, &k);
    switch (t->b58) {
    case 0x20:
    case 0x30:
    case 0x40:
        sel = t->b58;
        r = 0xC;
        break;
    case 0x25:
        r = 0xC;
        sel = 0x25;
        break;
    }
    if (sel != 0) {
        D_00319427 = 0;
        MsEffectLimitStart(id, 0);
    }
    return r;
}

s32 _m2c_func_001E35D8_func_001E3698(s32, BtlChr *, s32, s32) __asm__("func_001E3698");
/* DEBT(CAST) */
s32 func_001E35D8(s32 a, s32 b, float x, float y) {
    BtlChr *temp_2;
    s32 temp_16;
    s32 var_18;

    temp_16 = a & 0xFF;
    temp_2 = MsGetChr(temp_16);
    var_18 = 0;
    if (temp_2->f9E4 != 0) {
        temp_2->f9F0 = y;
        temp_2->f9E4 = 0;
        (*(s32 *)((u8 *)(temp_2) + (0x9E8))) = b;
        var_18 = 1;
        temp_2->f9EC = x;
        _m2c_func_001E35D8_func_001E3698(temp_16, temp_2, b, (s32) x);
        MsAtelRequestMagicCamera(0, temp_16, 0, 0x88, 0xFFFF, 0, 1, 0, 0);
    }
    return var_18;
}

typedef struct {
    u8 pad00[0x20];
    s32 val[3];
} DmgSub1E3698;

typedef struct {
    u8 b00;
    u8 b01;
    u8 b02;
    u8 b03;
    u8 b04;
    u8 pad05[0x10];
    u8 b15;
    u8 b16;
    u8 pad17[0x1];
    DmgSub1E3698 sub[16];
    u8 pad2D8_fix[0x2D8 - 0x18 - 16 * 0x2C];
} DmgRec1E3698;

typedef struct {
    u8 pad00[0x1C];
    u32 w1C;
    u8 pad20[0xB];
    u8 b2B;
    u8 pad2C[0x2C];
    u8 b58;
} Cmd1E3698;

typedef struct {
    u8 pad00[0x9E6];
    u8 b9E6;
    u8 pad9E7[0x99];
    u32 wA80;
    u8 padA84[0x198];
    u16 hC1C;
} Chr1E3698;

typedef struct {
    u8 pad00[0x2];
    u8 f2;
    u8 f3;
    u8 pad04[0xC];
    struct {
        u32 w00;
        u8 pad04[0xC];
    } ent[4];
} Cc1E3698;

extern int MsCalcDamage(int, void *, int, void *, void *, int, void *, int, int *, int *, int);
extern u8 *MsGetTargetRandomList(int, int *, int);
extern int MsCalcDrainResult(int, void *, void *, void *, int *, int);

int func_001E3698(int id, BtlChr *chr, int flag)
{
    s8 hits[31];
    s32 drain[4];
    DmgRec1E3698 *recs[31];
    s32 cmd_id;
    s32 sub_cmd_id;
    s32 out0;
    s32 out1;
    s32 rand_cnt;
    int cnt;
    int sub;
    int kind;
    Cc1E3698 *cc;
    DmgRec1E3698 *drain_rec;
    Cmd1E3698 *cmd;
    Cmd1E3698 *sub_cmd;
    DmgRec1E3698 *r;
    int i, j;
    int diff;
    u32 mask;

    cc = (Cc1E3698 *)MsGetChrCommand(id);
    cnt = 0;
    sub = cc->f2;
    cmd_id = ((Chr1E3698 *)chr)->hC1C;
    drain_rec = 0;
    cmd = (Cmd1E3698 *)MsGetCommand(id, 0, -1, 0, &cmd_id);
    kind = cmd->b58;

    for (i = 0; i < 31; i++) {
        BtlChr *c = MsGetChr(i);
        hits[i] = 0;
        recs[i] = 0;
        for (j = 0; j < 2; j++) {
            r = (DmgRec1E3698 *)((u8 *)c + 0x434 + j * 0x2D8);
            if (r->b02 == id && r->b03 == sub) {
                recs[i] = r;
                cnt++;
                if (!(r->b04 & 4)) {
                    hits[i] = r->b01 - r->b00;
                } else {
                    drain_rec = r;
                    r->b01 = 0;
                }
                break;
            }
        }
    }

    if (id == 0 || id == 2) {
        ((Chr1E3698 *)chr)->b9E6 = 1;
    }

    diff = 0;
    sub_cmd = 0;
    switch (kind) {
    case 0x30:
        if (flag == 0) {
            sub_cmd_id = 0x30EC;
            sub_cmd = (Cmd1E3698 *)MsGetCommand(id, 0, -1, 0, &sub_cmd_id);
            diff = cmd->b2B - sub_cmd->b2B;
        }
        break;
    case 0x52:
        if (flag == 0) {
            sub_cmd_id = 0x310D;
            sub_cmd = (Cmd1E3698 *)MsGetCommand(id, 0, -1, 0, &sub_cmd_id);
            diff = cmd->b2B - sub_cmd->b2B;
        }
        break;
    case 0x25:
        sub_cmd = cmd;
        if (flag <= 0) {
            flag = 1;
        }
        diff = sub_cmd->b2B - flag;
        if (diff < 0) {
            diff = 0;
        }
        break;
    }

    if (diff != 0) {
        if (sub_cmd != 0 && !((sub_cmd->w1C >> 15) & 1)) {
            for (j = 0; j < 31; j++) {
                if (hits[j] > 0) {
                    hits[j] -= diff;
                    if (hits[j] <= 0) {
                        hits[j] = 0;
                        recs[j]->b01 = recs[j]->b00;
                    }
                }
            }
        } else {
            for (i = 0; i < diff; i++) {
                u8 max_h = 0;
                for (j = 0; j < 31; j++) {
                    if (hits[j] > max_h) {
                        max_h = hits[j];
                    }
                }
                if (max_h != 0) {
                    int n = 0;
                    int pick;
                    int t;
                    t = max_h;
                    __asm__("" : "+r"(t) : "r"(n));
                    for (j = 0; j < 31; j++) {
                        if (hits[j] == t) {
                            n++;
                        }
                    }
                    pick = brnd(0x10) % n;
                    n = 0;
                    for (j = 0; j < 31; j++) {
                        if (hits[j] == max_h) {
                            n++;
                            if (n > pick) {
                                hits[j]--;
                                if (hits[j] <= 0) {
                                    hits[j] = 0;
                                    recs[j]->b01 = recs[j]->b00;
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    mask = 0;
    cmd = 0;
    for (i = 0; i < 31; i++) {
        r = recs[i];
        if (r != 0 && hits[i] > 0) {
            BtlChr *tc;
            int mode;
            mask |= 1 << i;
            tc = MsGetChr(i);
            sub_cmd_id = 0;
            mode = 0;
            switch (kind) {
            case 0x20:
                if (flag != 0) {
                    mode = 1;
                    sub_cmd_id = 0x3060;
                } else {
                    sub_cmd_id = 0x30EB;
                }
                break;
            case 0x30:
                if (flag != 0) {
                    mode = 1;
                    sub_cmd_id = 0x3061;
                } else {
                    sub_cmd_id = 0x30EC;
                }
                break;
            case 0x40:
                if (flag != 0) {
                    mode = 1;
                    sub_cmd_id = 0x3062;
                } else {
                    sub_cmd_id = 0x30ED;
                }
                break;
            case 0x50:
                if (flag != 0) {
                    mode = 1;
                    sub_cmd_id = 0x3112;
                } else {
                    hits[i] = 0;
                    r->b01 = r->b00;
                }
                break;
            case 0x22:
                if (flag != 0) {
                    if (r->b16 != 0) {
                        mode = 1;
                        sub_cmd_id = 0x3064;
                    } else {
                        mode = 2;
                        sub_cmd_id = 0x310E;
                    }
                } else {
                    sub_cmd_id = 0x310A;
                }
                break;
            case 0x32:
                if (flag != 0) {
                    if (r->b16 != 0) {
                        mode = 1;
                        sub_cmd_id = 0x3065;
                    } else {
                        mode = 2;
                        sub_cmd_id = 0x310F;
                    }
                } else {
                    sub_cmd_id = 0x310B;
                }
                break;
            case 0x42:
                if (flag != 0) {
                    if (r->b16 != 0) {
                        mode = 1;
                        sub_cmd_id = 0x3066;
                    } else {
                        mode = 2;
                        sub_cmd_id = 0x3110;
                    }
                } else {
                    sub_cmd_id = 0x310C;
                }
                break;
            case 0x52:
                if (flag != 0) {
                    if (r->b16 != 0) {
                        mode = 1;
                        sub_cmd_id = 0x3067;
                    } else {
                        mode = 2;
                        sub_cmd_id = 0x3111;
                    }
                } else {
                    sub_cmd_id = 0x310D;
                }
                break;
            case 0x25:
                sub_cmd_id = cmd_id;
                break;
            }
            r->b15 = mode;
            if (sub_cmd_id != 0) {
                r->b00 = 0;
                cmd = (Cmd1E3698 *)MsGetCommand(id, 0, -1, 0, &sub_cmd_id);
                MsCalcDamage(id, chr, i, tc, cmd, sub_cmd_id, r, 0, &out0, &out1, hits[i]);
            }
        }
    }

    ((Chr1E3698 *)chr)->wA80 = mask;
    if (sub < cc->f3) {
        cc->ent[sub].w00 = mask;
    }
    ((Chr1E3698 *)chr)->b9E6 = 0;

    if (drain_rec != 0 && cmd != 0) {
        u8 *rlist;
        for (i = 0; i < 31; i++) {
            hits[i] = 0;
        }
        rlist = MsGetTargetRandomList(id, &rand_cnt, 1);
        D_003172F0.f213E = rand_cnt;
        for (i = 0; i < rand_cnt; i++) {
            u8 tid = rlist[i];
            r = recs[tid];
            for (j = 0; j < 3; j++) {
                drain[j] = -r->sub[hits[tid]].val[j];
            }
            MsCalcDrainResult(id, chr, cmd, drain_rec, drain, 0);
            hits[tid]++;
        }
    }

    return cnt;
}

void func_001E3DA8(BtlChr *c)
{
    MsGetChr(c->f0C)->fABD = 0;
}

int MsCheckRikkuLimit(int id, BtlChr *c, GsEnt48 *e) {
    int arg[8];
    int tmp;
    int r = 0;
    MsGetCommand(id, 0, -1, &e->f8[e->f2], &tmp);
    if (tmp == 0x311E) {
        r = 1;
        msSetEndDir(c);
        arg[3] = id;
        e->f4 = 4;
        c->fABD = 1;
        c->f280 = 1;
        GetCD()->f10(0xD);
        GetCD()->f14(0x20);
        GetCD()->f0(0x20, 0x1EF0000, func_001E3DA8, arg);
    }
    return r;
}

int MsSetRikkuLimit(int id, BtlChr *c, GsEnt48 *e)
{
    int items[2];
    int i;
    int j;
    int cmd;
    int tgt;
    int ret;

    if (c->fABD != 0) {
        ret = 1;
    } else if (c->pad3D7[0] != 0) {
        ret = (s8)c->fF5 != 0;
    } else {
        register struct GsEnt48Sub *sub __asm__("s0");
        int cnt;
        register u32 n __asm__("$11") = e->f3;
        register int ff __asm__("$2") = 0xFF;
        items[1] = ff;
        cnt = 0;
        __asm__("" : : "r"(cnt), "r"(n));
        items[0] = ff;
        for (i = 0; i != (int)n;) {
            u16 *p = &e->f8[i].h0;
            for (j = 0; j < 2; j++, p++) {
                u16 v = *p;
                if (v != 0xFF && v != 0x311E && v != 0x3001 && cnt < 2) {
                    items[cnt] = v;
                    cnt++;
                }
            }
            i++;
            if (i >= (int)n) {
                break;
            }
        }
        sub = &e->f8[0];
        if (cnt < 2) {
            MsSaveItemUse(items[0], -1);
            cmd = items[0];
        } else {
            MsSaveItemUse(items[0], -1);
            MsSaveItemUse(items[1], -1);
            items[0] &= 0xFFF;
            if (items[0] < 0) {
                items[0] = 0;
            }
            items[1] &= 0xFFF;
            if (items[1] < 0) {
                items[1] = 0;
            }
            {
                int x = items[0];
                int y = items[1];
                if (x > y) {
                    register int tmp __asm__("$2") = x;
                    items[0] = y;
                    items[1] = tmp;
                    y = *(volatile int *)&items[1];
                }
                cmd = *(u16 *)((u8 *)MsGetExcelData(y, (void *)0x1EF0000, 0) + (items[0] << 1));
            }
        }
        {
            register int one __asm__("$2") = 1;
            register int ff __asm__("$3") = 0xFF;
            register int a0 __asm__("$4");
            e->f8[0].h0 = cmd;
            e->f3 = one;
            a0 = id;
            __asm__("" : "+r"(a0));
            sub->h2 = ff;
            tgt = MsGetCommandTarget(a0, cmd, -1, 1);
        }
        sub->targets = tgt;
        MsSetTargetDir(id, tgt);
        if (tgt != 0 && cnt >= 2) {
            MsSetSaveCommand(id, cmd, 1);
        }
        ret = tgt == 0;
        c->pad3D7[0] = 1;
    }
    return ret;
}

void MsCheckLimitUp(int a, BtlChr *c)
{
    int k;

    if (c->f3D4 != 0) {
        k = c->f3D5 & 1;
        c->f27C = MsCheckRange(c->f27C + c->f3E8[k], 0, c->f27D);
        c->f3A1 = MsCheckRange(c->f3A1 + c->f3E6[k], 0, 0x64);
    }
}

void MsSetLimitParty(int id, BtlChr *c) {
    int i;
    c->f31C = 0;
    for (i = 0; i < 7; i++) {
        u8 k = D_003192B5[i]; /* DEBT(TYPE): D_003192B5 is declared [3] but holds 7 ids */
        if (k != 0xFF && k != id) {
            BtlChr *t = MsGetChr(k);
            t->fA80 = c->fA80;
            t->f111 = c->f111;
            t->f280 = c->f280;
            t->f38C = c->f38C;
            t->f38D = c->f38D;
            t->f31C = MsGetNextCTB(t, c->fAA8, t->f2D3, t->f2D4);
        }
    }
}

typedef struct {
    u8 pad0[0x9E6];
    u8 f9E6;
    u8 pad9E7[5];
    float f9EC;
    float f9F0;
    u8 pad9F4[0x4C];
    u8 fA40[0x40];
} ReelChr;

extern u16 D_00320080[];
int func_001E47B8(u8 *symbols, s32 *out_value);
void *func_001E4A30(u32 i);

void MsSetReelResult(u8 id, u8 *reels, float f0, float f1)
{
    u8 ids[0x20];
    u8 *ptrs[0x20];
    s32 cnt;
    s32 cmd_id;
    s32 out1;
    s32 out2;
    int n = 0;
    int i;
    int j;
    int res;
    int hit_idx;
    ReelChr *chr = (ReelChr *)MsGetChr(id);
    u8 cmd_idx;
    u8 *slot;
    u8 *cmd;
    u8 *rec;
    u8 *hit_list;

    if (id == 4) {
        chr->f9EC = f0;
        chr->f9E6 = 1;
        chr->f9F0 = f1;
    }
    cmd_idx = ((u8 *)MsGetChrCommand(id))[2];
    for (i = 0; i < 0x1F; i++) {
        u8 *c = (u8 *)MsGetChr(i);
        for (j = 0; j < 2; j++) {
            slot = c + 0x434 + j * 0x2D8;
            if (slot[2] == id && slot[3] == cmd_idx) {
                ids[n] = i;
                ptrs[n] = slot;
                n++;
                slot[0] = 0;
                slot[1] = 0;
                break;
            }
        }
    }
    hit_list = chr->fA40;
    hit_idx = 0;
    for (i = 0; i < 4; i++) {
        rec = (u8 *)func_001E4A30(i);
        res = func_001E47B8(reels + i * 3, &cnt);

        cmd_id = 0;
        if (res != 0 && n != 0) {
            cmd_id = D_00320080[res - 1];
            cmd = (u8 *)MsGetCommand(id, 0, -1, 0, &cmd_id);
            switch ((*(u16 *)(cmd + 0x1A) >> 2) & 3) {
            case 0:
                for (j = 0; j < cnt; j++) {
                    int k = brnd(0x13) % n;
                    u8 tid = ids[k];
                    BtlChr *tc;

                    slot = ptrs[k];
                    tc = MsGetChr(tid);
                    hit_list[hit_idx] = tid;
                    MsCalcDamage(id, (BtlChr *)chr, tid, tc, cmd, cmd_id, slot, 0, &out1, &out2, 1);
                    hit_idx++;
                    slot[0]++;
                }
                break;
            case 1:
            case 2:
                cnt = n;
                for (j = 0; j < cnt; j++) {
                    u8 tid = ids[j];
                    BtlChr *tc;

                    slot = ptrs[j];
                    tc = MsGetChr(tid);
                    hit_list[hit_idx] = tid;
                    MsCalcDamage(id, (BtlChr *)chr, tid, tc, cmd, cmd_id, slot, 0, &out1, &out2, 1);
                    hit_idx++;
                    slot[0]++;
                }
                break;
            }
        } else {
            res = 0;
            cnt = 0;
        }
        rec[0] = res;
        rec[1] = cnt;
        *(u16 *)(rec + 2) = cmd_id;
    }
    for (j = 0; j < n; j++) {
        slot = ptrs[j];
        slot[0] = 0;
    }
    chr->f9E6 = 0;
}

int func_001E4640(u8 id)
{
    return MsAtelRequestMagicCamera(0, id, 0, 0x88, 0xFFFF, 0, 1, 0, 0);
}

u8 *MsGetTargetListWakka(int a, int *out1, int n, int *out2) {
    u8 id = a;
    u8 *r = 0;
    BtlChr *c;
    u8 *src;
    u8 *e;
    int off;
    int i;

    if (MsBtlChrNumCheck(id)) {
        c = MsGetChr(id);
        off = i = 0;
        src = c->fA40;
        r = c->fA00;
        for (; i < n; i++) {
            off += ((u8 *)func_001E4A30(i))[1]; /* DEBT(CAST): the records are read as bytes */
        }
        e = func_001E4A30(i);
        if (out1 != 0) {
            *out1 = e[1];
        }
        if (out2 != 0) {
            *out2 = e[0];
        }
        for (i = 0; i < e[1]; i++) {
            r[i] = src[off + i];
        }
        for (; i < 31; i++) {
            r[i] = 0xFF;
        }
    }
    return r;
}

s32 func_001E47B8(u8 *symbols, s32 *out_value)
{
    s32 count2;
    s32 count8;
    s32 count5;
    s32 count1;
    s32 count7;
    s32 count0;
    s32 count6;
    s32 count3;
    s32 count9;
    s32 result;

    *out_value = 0;
    result = 0;
    if (func_001E49F8(symbols, 0xFF) == 0) {
        *out_value = 1;
        if (func_001E49F8(symbols, 0xA) >= 3) {
            return 0xF;
        }
        count0 = func_001E49F8(symbols, 0);
        count1 = func_001E49F8(symbols, 1);
        count2 = func_001E49F8(symbols, 2);
        count3 = func_001E49F8(symbols, 3);
        if (count0 >= 3) {
            return 2;
        }
        if (count1 >= 3) {
            return 4;
        }
        if (count2 >= 3) {
            return 6;
        }
        if (count3 >= 3) {
            return 8;
        }
        if (count0 >= 2) {
            return 1;
        }
        if (count1 >= 2) {
            return 3;
        }
        if (count2 >= 2) {
            return 5;
        }
        if (count3 >= 2) {
            return 7;
        }
        count7 = func_001E49F8(symbols, 7);
        count8 = func_001E49F8(symbols, 8);
        count9 = func_001E49F8(symbols, 9);
        if (count7 >= 3) {
            return 0xA;
        }
        if (count8 >= 3) {
            return 0xC;
        }
        if (count9 >= 3) {
            return 0xE;
        }
        if (count7 >= 2) {
            return 9;
        }
        if (count8 >= 2) {
            return 0xB;
        }
        if (count9 >= 2) {
            return 0xD;
        }
        count5 = func_001E49F8(symbols, 5);
        count6 = func_001E49F8(symbols, 6);
        if (count6 >= 3) {
            *out_value = 12;
            return 17;
        }
        if (count5 >= 3) {
            *out_value = 6;
            return 17;
        }
        if (count5 > 0 || count6 > 0) {
            *out_value = count5 + count6 * 2;
            return 17;
        }
        return 16;
    }
    return result;
}

int func_001E49F8(u8 *p, int v)
{
    int n = 0;
    int i;

    for (i = 0; i < 3; i++) {
        if (p[i] == v) {
            n++;
        }
    }
    return n;
}

void *func_001E4A30(u32 i) {
    if (i < 4) {
        return &D_003188A0[i];
    }
    return 0;
}

int func_001E4A58(u8 id)
{
    int r = 0;

    if (MsBtlChrNumCheck(id)) {
        switch (MsGetChr(id)->fC1C) {
        case 0x3074:
            r = 0;
            break;
        case 0x3075:
            r = 1;
            break;
        case 0x3076:
            r = 2;
            break;
        case 0x3077:
            r = 3;
            break;
        }
    }
    return r;
}

int MsSetHeadTarget(int id, int mask) {
    int r = 0;
    if (D_00317346 == 0) {
        BtlChr *c = MsGetChr(id);
        if (c->chr != 0 && c->fF7 != 0) {
            int t = id;
            int i;
            for (i = 0; i < 0x1F; i++) {
                if (((mask >> i) & 1) && id != i) {
                    t = i;
                    r++;
                }
            }
            if (r == 1) {
                c->fF8 = t;
                c->fF9 = 5;
            } else {
                c->fF8 = 0xFF;
                c->fF9 = 5;
            }
        }
    }
    return r;
}

void _m2c_msResetHeadTarget_Ch_NeckSetEnable(s32, s32) __asm__("Ch_NeckSetEnable");
void _m2c_msResetHeadTarget_func_0010A230(s32, float, float) __asm__("func_0010A230");
/* DEBT(CAST) */
s32 msResetHeadTarget(void *arg0) {
    s32 temp_16;
    s32 var_17;

    var_17 = 0;
    if ((*(u8 *)((u8 *)(arg0) + (0xF8))) != 0xFF) {
        var_17 = 1;
        (*(u8 *)((u8 *)(arg0) + (0xF8))) = 0xFFU;
        if ((*(s8 *)((u8 *)(arg0) + (0xA8E))) != 0) {
            temp_16 = (*(s32 *)((u8 *)(arg0) + (0)));
            (*(s8 *)((u8 *)(arg0) + (0xF9))) = 0;
            if (temp_16 != 0) {
                _m2c_msResetHeadTarget_func_0010A230(temp_16, 0, 0);
                _m2c_msResetHeadTarget_Ch_NeckSetEnable(temp_16, 0);
            }
        } else {
            (*(s8 *)((u8 *)(arg0) + (0xF9))) = 1;
        }
    }
    return var_17;
}
