/* tu_211 0x1e2360-0x1e4c30: medium; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/g3.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"
#include "ffx/w5.h"

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E2360", MsLimitTypeProcess);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E2360", func_001E2560);

int func_001E2658(int i, int k, int force) {
    GameState *g = &D_003172F0;
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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E2360", MsLimitUp);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E2360", MsLimitTypeDamageCheck);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E2360", MsLimitTypeStatusCheck);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E2360", MsLimitTypeTurnCheck);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E2360", MsLimitCommandProcess);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E2360", func_001E35D8);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E2360", func_001E3698);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1E2360/rodata", jtbl_0056F8E0);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E2360", MsSetRikkuLimit);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E2360", MsSetReelResult);

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
        e = (u8 *)func_001E4A30(i); /* DEBT(CAST): the records are read as bytes */
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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E2360", func_001E47B8);

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

s32 *func_001E4A30(u32 i) {
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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E2360", msResetHeadTarget);
