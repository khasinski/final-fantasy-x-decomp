/* tu_197 0x1ce8e0-0x1d00d8: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"
#include "ffx/g2.h"
#define func_001CF458 s3_func_001CF458 /* DEBT(TYPE): this header's guess conflicts with the TU */
#include "ffx/s3.h"
#undef func_001CF458

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1CE8E0", MsStatusEffect);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1CE8E0", func_001CF6F8);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1CE8E0", MsCheckWrongStatus);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1CE8E0", func_001CFA38);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1CE8E0/rodata", jtbl_0056E980);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1CE8E0", MsSetWeaponEffectAttribute);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1CE8E0", MsDeathEffectStart);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1CE8E0/rodata", jtbl_0056E9F0);

void func_001D0098(int a) {
    MsRegSEfade(0, 0x1C, a);
    MsRegSEfade(0, 0x1B, a);
}
