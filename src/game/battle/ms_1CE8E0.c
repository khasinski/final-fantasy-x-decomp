/* tu_197 0x1ce8e0-0x1d00d8: low; ~Ms (config/tu_map.tsv) */
#define MsSetWeaponEffectAttribute _hdr_MsSetWeaponEffectAttribute
#define MsCheckWrongStatus _hdr_MsCheckWrongStatus
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"
#include "ffx/g2.h"
#include "ffx/s3.h"
#undef MsSetWeaponEffectAttribute
#undef MsCheckWrongStatus

s32 func_001CE8E0(void) {
    return D_00319308;
}

int MsEffectGetLastMagicNum2(PackedCmd cmd) {
    int r = -1;
    if (cmd.lo == 2) {
        r = D_00319308;
    }
    return r;
}

s8 MsEffectGetTargetFlag(u8 id) {
    return MsGetChr(id)->fA9A;
}

u8 MsGetSummonerNum(u8 id) {
    return MsGetChr(id)->f391;
}

s8 func_001CE960(void) {
    return D_00319426;
}

void func_001CE970(void) {
    int i;
    for (i = 7; i >= 0; i--) {
        D_003172F0.f195C[i] = 0;
    }
}

void MsEffectCameraEnd(int flag) {
    int i;
    for (i = 0; i < 8; i++) {
        if (D_003172F0.f195C[i] != 0) {
            MsCameraFree(D_003172F0.f195C[i]);
            D_003172F0.f195C[i] = 0;
        }
    }
    if (flag == 0) {
        if (D_003172F0.f10 != 0) {
            if (D_003172F0.f1753 != 0) {
                D_003172F0.f1753 = 0;
                MsAtelRequestCamera(0, 0, 0x1C, 0xFFFF, 1, 1, 0, 0);
            }
        }
    }
}

int MsEffectCameraGet(int a, u32 idx, int c) {
    int r = 0;
    if (idx < 8) {
        GameState *g = &D_003172F0;
        r = g->f195C[idx];
        if (r == 0) {
            r = MsCameraGet(a, idx, c);
            g->f195C[idx] = r;
        }
    }
    return r;
}

void MsEffectSepClearAll(void) {
    op_oef2_sep_free_all(0xFFFF);
}

void func_001CEAD8(int a) {
    if (a != 0x29F) {
        func_00297EA0();
    } else {
        func_002F8660(0);
        ((int (*)(int))func_002F8660)(2); /* DEBT(CAST): func_002F8660 returns int, declared void in funcs.h */
        (*(void (**)(int))0x1B00020)(D_00662620); /* DEBT(CAST): indirect call through fixed vector */
    }
}

int func_001CEB28(int mask) {
    int n = 0;
    int bits = 0;
    int i;
    for (i = 0; i < 31; i++) {
        if ((mask >> i) & 1) {
            n++;
            if (MsGetChr(i)->fA9A != 0) {
                bits |= 1 << i;
            }
        }
    }
    return (n <= 1) ? mask : bits;
}

int func_001CEBC8(Ent4 *p, int n) {
    while (p->b0 != 0 || p->b1 != 0 || p->b2 != 0) {
        if (p->b0 != 0xFF) {
            p->b2 = n;
            n++;
            if (n >= 0x19) {
                MsBattleError(D_0056E950);
            }
        }
        p++;
    }
    return n;
}

void func_001CEC58(void) {
    int r = func_001CEBC8(D_0031FA18, 0);
    r = func_001CEBC8(D_0031FA50, r);
    func_001CEBC8(D_0031FA88, r);
}

void MsEtEffectReadInit(void) {
    D_00662624 = 0;
}

void func_001CECA8(void) {
    s32 buf;
    GetCD()->f10(0xD);
    buf = GetCD()->f14(6);
    func_0011C348(0x40);
    buf = (s32)user_malloc(buf, 5, D_0056E958, -1); /* DEBT(TYPE): handle/pointer kept as int */
    GetCD()->f0(6, buf, 0, 0);
    GetCD()->f8(0);
    ((void (*)(s32))func_002D0938)(buf); /* DEBT(TYPE): called with the buffer although defined without parameters */
    func_0011D590(buf, 5);
}

void MsEtEffectRead(void)
{
    GetCD()->f10(0xD);
    if (GetCD()->f14(7) > 0x50FF0)
    {
        MsBattleError(D_0056E960);
    }
    func_0011C348(0x40);
    D_00662624 = user_malloc(0x50FF0, 5, D_0056E970, -1);
    GetCD()->f0(7, D_00662624, 0, 0);
    GetCD()->f8(0);
    op_et_battle_init(D_00662624);
}

void MsEtEffectSet(void) {
    op_et_battle_effect_init();
    D_0031737C = D_00662624;
}

void MsEtEffectStop(void) {
    if (D_00662624 != 0) {
        op_et_battle_effect_free();
    }
}

void MsEtEffectFree(void) {
    if (D_00662624 != 0) {
        op_et_battle_effect_free();
        func_0011D590(D_00662624, 5);
        D_00662624 = 0;
        D_0031737C = 0;
    }
}

void MsStatusEffect(int id, BtlChr *c, Ent4 *e, int on, s32 *w) {
    if (e->b0 != 0xFF) {
        u8 k = e->b2;
        u8 flags = e->v;
        u32 eff = w[k];
        if (on != 0) {
            if (eff == 0) {
                u8 b;
                eff = MsGetEffID(*(u16 *)c->padAE0, 3, id);
                (*(u16 *)c->padAE0)++;
                if (D_003172F0.f20FE != 0) {
                    b = e->b1;
                } else {
                    b = e->b0;
                }
                if ((flags & 0x10) == 0) {
                    op_et_eff(D_003172F0.f8C, 0, b, eff);
                    w[k] = eff;
                }
            }
        } else {
            if (eff != 0) {
                op_et_eff_off_signal(eff);
                w[k] = 0;
            }
        }
    }
}

int MsStatusEffectReflect(int id) {
    int r = 0;
    BtlChr *c = MsGetChr(id);
    if (c->fB64 == 0) {
        r = MsGetEffID(c->fAE6, 9, id);
        c->fAE6++;
        op_et_eff(D_0031737C, 0, 0xF, r);
        c->fB64 = r;
    }
    return r;
}

u32 MsEtEffectEncount(int a, u32 v) {
    GameState *g = &D_003172F0;
    u32 r = 0;
    if (g->f1754 == 0) {
        MsRegSEplay2(0xFF, v);
        r = MsGetEffID(g->f1758, 10, 0);
        g->f1758++;
        op_et_encount_effect_on(a, r);
        g->f1754 = r;
    }
    return r;
}

u32 func_001CF0C0(int id) {
    BtlChr *c = MsGetChr(id);
    u32 r = MsGetEffID(c->fADE, 0xC, id);
    c->fADE++;
    op_et_eff(D_0031737C, 0, 0x36, r);
    return r;
}

void MsStatusEffectCheck(int id) {
    BtlChr *c = MsGetChr(id);
    u8 *b;
    Chr *chr;
    int i;
    int v;

    if (c->fA8D == 0) {
        for (i = 0; i < 12; i++) {
            MsStatusEffect(id, c, &D_0031FA18[i], (c->f2C6 >> i) & 1, c->fAF0);
        }
        b = &c->f2C8; /* DEBT(CAST): f2C8..f2D4 are one 13-byte array */
        for (i = 0; i < 13; i++) {
            MsStatusEffect(id, c, &D_0031FA50[i], b[i], c->fAF0);
        }
        for (i = 0; i < 16; i++) {
            MsStatusEffect(id, c, &D_0031FA88[i], (c->f2D6 >> i) & 1, c->fAF0);
        }
    }
    v = MsGetColorStatus(id);
    c->f3B8 = v;
    chr = c->chr;
    if (v != c->f3BC && chr != 0) {
        op_et_astatus_effect_change(chr, v);
    }
    c->f3BC = v;
}

s32 func_001CF278(int unused0, s32 arg1, s32 arg2)
{
    s32 state0;

    state0 = 0;
    if (arg2 != 0)
    {
        if (arg2 & 0x20)
        {
            state0 = 1;
            func_001CF600(arg1, 0, 0xD);
        }
        if (arg2 & 0x40)
        {
            state0 += 1;
            func_001CF600(arg1, 0, 0xE);
        }
        if (arg2 & 8)
        {
            state0 += 1;
            func_001CF600(arg1, 0, 0x15);
        }
        if (arg2 & 0x10)
        {
            state0 += 1;
            func_001CF600(arg1, 0, 0x4B);
        }
        if (arg2 & 0x200)
        {
            state0 += 1;
            func_001CF600(arg1, 0, 2);
        }
        if (arg2 & 0x400)
        {
            state0 += 1;
            func_001CF600(arg1, 0, 3);
        }
        if (arg2 & 0x800)
        {
            state0 += 1;
            func_001CF600(arg1, 0, 4);
        }
        if (arg2 & 0x1000)
        {
            state0 += 1;
            func_001CF600(arg1, 0, 5);
        }
        if (arg2 & 0x2000)
        {
            state0 += 1;
            func_001CF600(arg1, 0, 6);
        }
        if (arg2 & 0x4000)
        {
            state0 += 1;
            func_001CF600(arg1, 0, 7);
        }
        if (arg2 & 0x8000)
        {
            state0 += 1;
            func_001CF600(arg1, 0, 0x49);
        }
    }
    return state0;
}

int MsStatusEffectClear(int id) {
    BtlChr *c = MsGetChr(id);
    int n = 0;
    int i;
    s32 *p = c->fAF0;
    for (i = 23; i >= 0; i--, p++) {
        if (*p != 0) {
            n++;
            op_et_eff_off_signal(*p);
            *p = 0;
        }
    }
    return n;
}

int func_001CF458(int a, int b, int c) {
    if (func_001CF6F8(a, b, 8, c, 1) != 0) {
        MsGetChr(a)->fAD3++;
        return 1;
    }
    return 0;
}

int func_001CF4B0(int id, int a, int b) {
    int r = 0;
    BtlChr *c = MsGetChr(id);
    u32 v = MsGetEffID(c->fADE, 7, id);
    c->fADE = c->fADE + 1;
    if (op_et_eff(D_0031737C, a, b, v) > 0) {
        c->fAD2++;
        r = 1;
    }
    return r;
}

int func_001CF558(int id, int a, int b) {
    int r = 0;
    BtlChr *c = MsGetChr(id);
    u32 v = MsGetEffID(c->fADE, 8, id);
    c->fADE = c->fADE + 1;
    if (op_et_eff(D_0031737C, a, b, v) > 0) {
        c->fAD3++;
        r = 1;
    }
    return r;
}

int func_001CF600(int id, int a, int b) {
    int r = 0;
    BtlChr *c = MsGetChr(id);
    u32 v = MsGetEffID(c->fAEA, 14, id);
    c->fAEA = c->fAEA + 1;
    if (op_et_eff(D_003172F0.f8C, a, b, v) > 0) {
        D_003172F0.f2028++;
        r = 1;
    }
    return r;
}

int func_001CF6A8(int a, int b) {
    return func_001CF600(a, 0, b == 0 ? 9 : 10);
}

int func_001CF6D0(int a, int b) {
    return func_001CF600(a, 0, b == 0 ? 0x4C : 0x4D);
}

s32 func_001CF6F8(s32 a, s32 b, s32 c, s32 d, s32 e) {
    BtlChr *temp_16;
    s32 var_4_2;
    u16 var_4;
    u32 temp_17;
    s32 r;

    if (a != 0xFF) {
        temp_16 = MsGetChr(a);
        if (c == 1) {
            var_4 = temp_16->fAE2;
            temp_16->fAE2 = var_4 + 1;
        } else {
            var_4 = temp_16->fADE;
            temp_16->fADE = var_4 + 1;
        }
        temp_17 = MsGetEffID((s32) var_4, c, a);
        var_4_2 = 0;
        if ((e == 0) || (D_00317337 == 0)) {
            var_4_2 = temp_16->f4C;
        }
        r = op_et_eff(var_4_2, b, d, (s32) temp_17);
        if (r > 0) {
            return (s32) temp_17;
        }
    }
    return 0;
}

int func_001CF7D8(int id, int on) {
    BtlChr *c = MsGetChr(id);
    Chr *chr = c->chr;

    if (c->f4C != 0) {
        if (chr == 0) {
            return 0;
        }
        if (on) {
            func_002994B8(chr);
        } else {
            func_002994D8(chr);
        }
        return 1;
    }
    return 0;
}

int func_001CF840(int a) {
    int sum = 0;
    int i;
    for (i = 0; i < 31; i++) {
        sum += func_001CF7D8(i, a);
    }
    return sum;
}

void func_001CF8A0(void) {
    op_et_bindeff2();
}

u8 MsCheckStat(int i) {
    return D_0031FA18[i].v;
}

u8 func_001CF8C0(int i) {
    return D_0031FA50[i].v;
}

u8 MsCheckStat2(int i) {
    return D_0031FA88[i].v;
}

typedef struct {
    u8 pad0[0x20];
    u16 h20;
    u8 pad22;
    u8 b23;
    u8 pad24[0x2E - 0x24];
    u8 b2E[12];
    u8 b3A[13];
    u8 b47[13];
    u16 h54;
} Q4ActStatus;

int MsCheckWrongStatus(Q4ActStatus *p) {
    Ent4 *e = D_0031FA18;
    int i;
    u8 *b1;
    int v1, v2;

    if (((p->h20 >> 4) & 1) == 0) {
        if ((p->b23 & 7) != 0) {
            return -1;
        }
        b1 = p->b2E;
        for (i = 0; i < 12; i++, e++) {
            v1 = b1[i];
            if (v1 > 0 && (e->v & 0x80)) {
                return -1;
            }
        }
        e = D_0031FA50;
        b1 = p->b3A;
        for (i = 0; i < 13; i++, e++) {
            v1 = b1[i];
            v2 = p->b47[i];
            if (v1 > 0 && v2 > 0 && (e->v & 0x80)) {
                return -1;
            }
        }
        e = D_0031FA88;
        for (i = 0; i < 16; i++, e++) {
            if (((p->h54 >> i) & 1) > 0 && (e->v & 0x80)) {
                return -1;
            }
        }
    }
    return 0;
}

void MsMagicEffectSet(int a, BtlChr *c) {
    int x, y;
    if (MsGetRamChrMonster(a)) {
        x = 0x37;
        y = 0x38;
    } else {
        x = 0x1E;
        y = 0x1F;
    }
    c->fAD0 = x;
    c->fAD1 = y;
}

/* DEBT(FAKE) */
s32 func_001CFA38(s32 id, s32 v) {
    BtlChr *temp_2;
    BtlChr *var_20;
    s32 var_2;
    u32 temp_19;
    register u32 var_17 __asm__("$17");
    u8 var_18;

    if (id != 0xFF) {
        temp_2 = MsGetChr(id);
        var_2 = -1;
        if (temp_2->fB60 == 0) {
            var_2 = -1;
            if (temp_2->fACF != 0) {
                if (v == 0) {
                    if ((D_003172F0.f20FE != 0) || (temp_2->f1C5 != 0)) {
                        var_18 = 0x35;
                        if (temp_2->f280 == 0) {
                            var_18 = temp_2->fAD1;
                        }
                    } else {
                        var_18 = 0x34;
                        if (temp_2->f280 == 0) {
                            var_18 = temp_2->fAD0;
                        }
                    }
                } else {
                    if ((D_003172F0.f20FE != 0) || (temp_2->f1C5 != 0)) {
                        var_18 = 0x21;
                    } else {
                        var_18 = 0x20;
                    }
                }
                if (var_18 != 0) {
                    var_17 = 0;
                    var_20 = 0;
                    switch (var_18) {
                    case 0x34:
                    case 0x35:
                        var_17 = 0x3E;
                        break;
                    case 0x20:
                    case 0x21:
                        var_17 = 0x1A;
                        var_20 = MsGetChr((s32) (&D_003172F0)->f2118);
                        break;
                    case 0x1E:
                    case 0x1F:
                    case 0x37:
                    case 0x38:
                        var_17 = 0x19;
                        break;
                    }
                    MsRegSEplay(id, var_17);
                    temp_19 = MsGetEffID((s32) temp_2->fAE4, 5, id);
                    temp_2->fC36 = (u16) var_17;
                    temp_2->fAE4 += 1;
                    if (var_20 != 0) {
                        var_20->fC36 = (u16) var_17;
                    }
                    op_et_eff(D_003172F0.f8C, 0, (s32) var_18, (s32) temp_19);
                    temp_2->fB60 = (s32) temp_19;
                }
                return -1;
            }
        }
        /* Duplicate return node #24. Try simplifying control flow for better match */
        return var_2;
    }
    var_2 = 0;
    return var_2;
}

int func_001CFBC8(int id) {
    BtlChr *c;
    if (id == 0xFF) {
        return 0;
    }
    c = MsGetChr(id);
    if (c->fAAA == 8) {
        func_001CFBC8(0x10);
        func_001CFBC8(0x11);
    }
    if (c->fB60 != 0) {
        op_et_prayeff_send_read_through(c->fB60);
        c->fB60 = 0;
        return -1;
    }
    return 0;
}

int MsSetWeaponEffectAttribute(int id, BtlChr *c) {
    int count = 0;
    int i;

    if (c->fA8D == 0) {
        int attr = c->f299;
        for (i = 0; i < 4; i++) {
            int on = 0;
            int eff_type = 0;
            switch (i) {
            case 0:
                on = attr & 1;
                eff_type = 0x3C;
                break;
            case 1:
                on = (attr >> 1) & 1;
                eff_type = 0x3D;
                break;
            case 2:
                on = (attr >> 2) & 1;
                eff_type = 0x3E;
                break;
            case 3:
                on = (attr >> 3) & 1;
                eff_type = 0x3F;
                break;
            }
            if (on != 0 && c->fB50[i] == 0) {
                u32 eff = MsGetEffID(*(u16 *)c->padAE8, 13, id);
                (*(u16 *)c->padAE8)++;
                if (op_et_eff(D_003172F0.f8C, 0, eff_type, eff) > 0) {
                    c->fB50[i] = eff;
                    count++;
                }
            }
        }
    }
    return count;
}

int func_001CFDB0(int unused, BtlChr *c) {
    int n = 0;
    int i;
    s32 *p = c->fB50;
    for (i = 3; i >= 0; i--, p++) {
        if (*p != 0) {
            n++;
            op_et_eff_off_signal(*p);
            *p = 0;
        }
    }
    return n;
}

int MsGetColorStatus(int id) {
    BtlChr *c = MsGetChr((u8)id);
    int f = (c->f2C6 >> 1) & 1;
    if (c->fA8E != 0) {
        f |= 2;
    }
    if ((c->f2C6 >> 9) & 1) {
        f |= 4;
    }
    if (c->f2D3 != 0) {
        f |= 8;
    }
    if (c->f2D4 != 0) {
        f |= 0x10;
    }
    if ((c->f2D6 >> 10) & 1) {
        f |= 0x20;
    }
    return f;
}

void func_001CFE80(int id, int b) {
    void *p = MsGetChrHandle(id);
    if (p != 0) {
        func_00299360(p, b);
    }
}

int func_001CFEC0(int id) {
    if (MsBtlChrNumCheck(id) != 0) {
        int a = -1;
        int b;
        BtlChr *c = MsGetChr(id);
        b = -1;
        if ((c->f2D6 >> 6) & 1) {
            a = 0x77;
            b = 0x48;
        }
        if ((c->f2D6 >> 13) & 1) {
            a = 0x77;
            b = 0x4A;
        }
        if (a >= 0) {
            MsRegSEplay(id, a);
        }
        if (b >= 0) {
            func_001CF558(id, 0, b);
        }
    }
    return 0;
}

int MsDeathEffectStart(int id, int kind) {
    if (id != 0xFF) {
        int eff = 0;
        int type = 4;
        BtlChr *c = MsGetChr(id);
        int se;

        if (c->f3C1 == 3) {
            kind = 1;
        }
        se = 0;
        switch (kind) {
        case 0:
        case 1:
        case 6:
            break;
        case 2:
            eff = 0x29;
            se = 0x4C;
            break;
        case 3:
            eff = 0x2A;
            se = 0x1C;
            break;
        case 4:
            eff = 0x2B;
            se = 0x1B;
            break;
        case 5:
            eff = 0x2C;
            se = 0x49;
            break;
        case 8:
            eff = 0x2C;
            break;
        case 7:
            c->fAD7 = 0;
            eff = 0x39;
            se = 0x58;
            type = 15;
            break;
        }
        if (se != 0) {
            MsRegSEplay(id, se);
        }
        if (eff != 0) {
            u32 eff_id = MsGetEffID(c->fADE, type, id);
            c->fB7 = 1;
            c->fADE++;
            op_et_eff(D_003172F0.f8C, 0, eff, eff_id);
            return 1;
        }
    }
    return 0;
}

void func_001D0098(int a) {
    MsRegSEfade(0, 0x1C, a);
    MsRegSEfade(0, 0x1B, a);
}
