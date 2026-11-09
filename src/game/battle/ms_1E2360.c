/* tu_211 0x1e2360-0x1e4c30: medium; ~Ms (config/tu_map.tsv) */
#define msResetHeadTarget _hdr_msResetHeadTarget
#define func_001E2560 _hdr_func_001E2560
#define MsMessageCueRegist _hdr_MsMessageCueRegist
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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E2360", MsLimitTypeProcess);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E2360", MsLimitUp);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E2360", MsLimitTypeDamageCheck);

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
