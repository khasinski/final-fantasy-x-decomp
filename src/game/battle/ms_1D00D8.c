/* tu_198 0x1d00d8-0x1d2170: low; ~Ms (config/tu_map.tsv) */
#define D_0031FA50 _hdr_D_0031FA50
#define MsExchangeChr _hdr_MsExchangeChr
#include "common.h"
#include "ffx/s3.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"
#undef D_0031FA50
#undef MsExchangeChr

typedef struct {
    u16 h0;
    u8 b2;
    u8 pad3;
    u16 h4;
    u8 b6;
    u8 pad7;
    u16 h8;
    u8 bA;
    u8 padB;
    u16 hC;
    u8 bE;
    u8 padF;
} CmdUseEnt16;

extern CmdUseEnt16 D_0031FA50[];
void MsInsertChrCommand(int a, int b, int c);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D00D8", MsParseCommand);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1D00D8/rodata", jtbl_0056EA20);

int func_001D0D48(u16 *p) {
    int r = 0;
    int i;
    u16 *q;
    if (p != 0) {
        for (i = 0; i < 2; i++) {
            q = p + i;
            if (*q == 0x3029) {
                r = 1;
                break;
            }
        }
    }
    return r;
}

void func_001D0D98(int a, BtlChr *c) {
    if (c->f10B != 0) {
        c->f10A = c->f10B;
    } else {
        c->f10A = func_001D1DF8(a, c, c->fA80);
    }
}

int MsCheckMegas(int x) {
    if (x == 16 || x == 17) {
        x = 15;
    }
    return x;
}

typedef struct {
    u8 pad00[4];
    s32 f04;
    s32 f08;
    u8 pad0C[4];
    s8 f10;
    u8 pad11[9];
    s8 f1A;
    u8 pad1B[3];
    s8 f1E;
    u8 pad1F[0x1E];
    s8 f3D;
    u8 pad3E[0x7A];
    u8 fB8;
    u8 padB9[0x23];
    s8 fDC;
    u8 padDD[0x19];
    s8 fF6;
    u8 padF7[6];
    s8 fFD;
    u8 padFE[0xBE];
    u8 f1BC;
    u8 f1BD;
    u8 f1BE;
    u8 f1BF;
    u8 f1C0;
    u8 f1C1;
    u8 f1C2;
    u8 pad1C3[6];
    u8 f1C9;
    u8 f1CA;
    u8 f1CB;
    u8 pad1CC[5];
    s8 f1D1;
    u8 pad1D2[2];
    float f1D4[2];
    u8 pad1DC[0x140];
    s8 f31C;
    u8 pad31D[0xB9];
    s8 f3D6;
    u8 pad3D7[0x6B1];
    s8 fA88;
    u8 padA89[2];
    s8 fA8B;
    u8 padA8C[1];
    s8 fA8D;
    u8 padA8E[0x2A];
    s8 fAB8;
} ExChr; /* DEBT(NAME): BtlChr offset view for MsExchangeChr */

typedef struct {
    u8 pad00[0x1FC5];
    u8 f1FC5[7];
    u8 pad1FCC[7];
    u8 f1FD3[17];
    u8 pad1FE4[0x134];
    s8 f2118;
    s8 f2119;
} ExGS; /* DEBT(NAME): GameState offset view for MsExchangeChr */

extern void MsProvOff(int);
extern void MsThreatOff(int, void *);
extern int MsCleanInputCue(int, int);
extern void func_001B7498(int, int);
extern void MsEffectWeaponFree(int);
extern void MsStatusEffectCheck(int);
extern void MsBtlReadCueRegist(int, int, int, int, int);
extern void func_001B1490(int, int);
extern void MsInsertInputCue(int, int, int, int, int, int);

#define EX_GS ((ExGS *)&D_003172F0) /* DEBT(CAST): GameState offset view */

int MsExchangeChr(int a, int b, int mode, int arg3)
{
    ExChr *ca = (ExChr *)MsGetChr(a); /* DEBT(CAST): offset view */
    ExChr *cb = (ExChr *)MsGetChr(b); /* DEBT(CAST): offset view */
    int i;

    if (a != 0xFF && ca->f10 != 0) {
        ca->f1C0 = ca->f1C9;
        ca->f1C1 = ca->f1CA;
        ca->f1C2 = ca->f1CB;
        if (ca->fA8D == 0) {
            ca->fA88 = 0;
            ca->fAB8 = 1;
            ca->fDC = 0;
            MsProvOff(a);
            MsThreatOff(a, ca);
            MsCleanInputCue(a, 1);
            if (mode > 0) {
                ca->fA8B = 1;
                ca->f1A = 1;
                func_001B7498(a, -1);
                EX_GS->f2118 = b;
                EX_GS->f2119 = a;
                ca->f1BC = cb->f1BC;
                ca->f1BD = 12;
                ca->f1BE = b;
                MsSetDirThetaMode(ca);
                if (b != 0xFF) {
                    ca->f1D4[1] = cb->f1D4[cb->f1D1];
                }
                MsSetMotion(a, 3, 1, 1, 1, 0, 0);
            } else {
                ca->fF6 = 0;
                ca->f1BD += 3;
                MsSetMotion(a, 0x12, 1, 1, 1, 0, 0);
            }
            MsPushBtlPos(ca);
        }
        MsEffectWeaponFree(a);
        MsSEPchrClear(ca, 1);
        for (i = 0; i < 7; i++) {
            if (EX_GS->f1FC5[i] == a) {
                EX_GS->f1FC5[i] = b;
                break;
            }
        }
        for (i = 0; i < 17; i++) {
            if (EX_GS->f1FD3[i] == b) {
                EX_GS->f1FD3[i] = a;
                break;
            }
        }
    } else {
        ca = 0;
    }

    if (b != 0xFF && cb->f10 != 0) {
        s32 f04 = cb->f04;
        s32 f08 = cb->f08;
        int cue_type;
        if (cb->fA8D != 0) {
            cue_type = 10;
            MsPushBtlPos(cb);
        } else {
            if (mode <= 0 && ca != 0) {
                cb->f1BC = ca->f1C0;
                cb->f1BD = ca->f1C1;
                cb->f1BE = ca->f1C2;
                cb->f1BF = ca->f1BF;
                cb->f1D4[0] = ca->f1D4[0];
                cb->f1D4[1] = ca->f1D4[1];
                cb->fB8 = ca->fB8;
                cb->f31C = 0;
            }
            MsPushBtlPos(cb);
            cb->fAB8 = 0;
            cb->fA88 = 1;
            if (mode > 0) {
                MsSummonLimitSave(cb);
                cue_type = 8;
                cb->f1E = 0;
                cb->fFD = 4;
            } else {
                ((u8 *)&btlgetdata)[b] = 1; /* DEBT(CAST): byte array at btlgetdata */
                if (mode < 0) {
                    cb->fA8B = 0;
                    cb->f1A = 0;
                    cue_type = 0;
                    msSetChrBodyHit(cb, 3, 1);
                    MsSetDirThetaMode(cb);
                    MsStatusEffectCheck(b);
                } else {
                    cb->f3D = 1;
                    cue_type = 6;
                }
            }
        }
        MsBtlReadCueRegist(3, b, b, 0, 0);
        MsBtlReadCueRegist(0, b, b, f04, 0);
        MsBtlReadCueRegist(2, b, b, f08, cue_type);
        func_001B1490(b, 3);
        if (a != 0xFF && mode >= 0) {
            cb->f3D6 = 1;
            MsInsertInputCue(b, 0, 1, 0, a, arg3);
        }
    }
    return b;
}

void MsExchangeSummon(int a, int b) {
    int j;
    int i;

    D_00319407 = 1;
    for (i = 0; i < 18; i++) {
        BtlChr *c = MsGetChr(i);
        c->padA89[0] = c->fA88;
    }
    for (i = 0; i < 17; i++) {
        D_003172F0.pad1FCC[i + 24] = D_003172F0.pad1FCC[i + 7];
    }
    for (i = 0; i < 7; i++) {
        u8 id = D_003172F0.f1FC5[i];
        D_003172F0.f1FC5[i + 7] = id;
        if (id != a && id != 0xFF) {
            MsExchangeChr(id, 0xFF, 0, 0);
        }
    }
    MsGetChr(b)->f391 = a;
    if ((u32)(b - 15) < 3) {
        MsExchangeChr(a, b, 1, 0);
        i = 0;
        for (j = 15; j < 18; j++, i++) {
            D_003192B5[i] = j;
            if (j != b) {
                MsGetChr(j)->f391 = a;
                MsExchangeChr(0xFF, j, 1, 0);
            }
        }
    } else {
        MsExchangeChr(a, b, 1, 0);
    }
    MsChangeMonsterDir();
    MsInsertChrCommand(b, a, 0);
}

void MsEscapeAll(void) {
    int i;
    for (i = 0; i < 7; i++) {
        u8 id = D_003192B5[i];
        if (id != 0xFF) {
            BtlChr *c = MsGetChr(id);
            c->fDC = 0;
            if (c->fA88 != 0 && c->fA8C == 0 && c->fA8E == 0) {
                MsLimitTypeEscapeCheck(id, c);
                c->f1BC.b += 3;
                MsSetMotion(id, 0x12, 1, 1, 1, 0, 0);
                MsPushBtlPos(c);
            }
        }
    }
}

s32 func_001D1458(int id, int a, int h) {
    GsEnt48 e;
    MsGetChr(id)->fAB2 = 0;
    MsStructClear(&e, 0x48);
    e.f3 = 1;
    e.f8[0].h0 = h;
    e.f8[0].targets = D_003172F0.f2000;
    e.f2 = 0;
    e.f8[0].h2 = 0;
    MsInsertInputCue(id, 0, 0, 0, a, 1);
    MsInsertCommandCue(id, &e, 8, 0, 0, 0, a);
    return D_003172F0.f2000;
}

int func_001D1510(int id, int cmd, int mode, int *out_a, int *out_b) {
    CmdUseEnt16 *p = &D_0031FA50[id];
    int val_a;
    int val_b;
    int ret = 0;
    val_a = 0;
    val_b = 0;

    switch (mode) {
    case 0:
        if (((D_0031D1DC >> 11) & 1) || MsGetSaveCommandUse(id, cmd) == 0) {
            ret = p->h0;
            val_b = p->b2;
        } else {
            ret = p->h4;
            val_b = p->b6;
        }
        val_a = 1;
        break;
    case 1:
        ret = p->h8;
        val_b = p->bA;
        val_a = 3;
        break;
    case 2:
        ret = p->hC;
        val_b = p->bE;
        val_a = 2;
        break;
    }
    if (out_a != 0) {
        *out_a = val_a;
    }
    if (out_b != 0) {
        *out_b = val_b;
    }
    return ret;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D00D8", MsInsertChrCommand);

/* DEBT(ORDER): independent reset fields are ordered to retain the original schedule. */
void MsReturnSummon(s32 reset)
{
    BtlChr *chr;
    s32 index;
    u8 id;

    if (D_003172F0.f2118 != 0)
    {
            for (index = 0; index < 7; index++)
        {
            id = D_003172F0.f1FC5[index];
            if (id != 0xFF)
            {
                chr = MsGetChr((s32) id);
                MsSummonLimitLoad(chr);
                if ((reset != 0) && (chr->f290 <= 0))
                {
                    MsRelife((s32) id, chr, 0);
                }
                MsFreePlayer(id);
            }
                }
        MsReturnParty();
        MsExchangePlayer(D_003172F0.f2118);
        MsChangeMonsterDir();
        D_003172F0.f2125 = 1;
        D_003172F0.f2118 = 0;
        D_003172F0.f2119 = -1;
    }
}

void MsReturnParty(void) {
    int i;
    if (D_003172F0.f2117 != 0) {
        D_003172F0.f2117 = 0;
        for (i = 0; i < 7; i++) {
            u8 id = D_003172F0.f1FC5[i + 7];
            D_003172F0.f1FC5[i] = id;
            if (id != 0xFF) {
                MsGetChr(id);
            }
        }
        for (i = 0; i < 17; i++) {
            D_003172F0.pad1FCC[i + 7] = D_003172F0.pad1FCC[i + 24];
        }
    }
}

void MsExchangeParty(void) {
    int i;

    for (i = 0; i < 7; i++) {
        u8 t = D_003172F0.pad1FA6[i + 0x26];
        D_003172F0.pad1FA6[i + 0x26] = D_003172F0.pad1FA6[i + 0x1F];
        D_003172F0.pad1FA6[i + 0x1F] = t;
    }
    for (i = 0; i < 17; i++) {
        u8 t = D_003172F0.pad1FCC[i + 24];
        D_003172F0.pad1FCC[i + 24] = D_003172F0.pad1FCC[i + 7];
        D_003172F0.pad1FCC[i + 7] = t;
    }
    for (i = 0; i < 18; i++) {
        BtlChr *c = MsGetChr(i);
        s8 t = ((s8 *)c)[0xA89];
        ((s8 *)c)[0xA89] = c->fA88;
        c->fA88 = t;
    }
}

void func_001D1A30(void) {
    int i;
    for (i = 0; i < 7; i++) {
        int id = D_003192BC[i];
        if (id != 0xFF) {
            BtlChr *c = MsGetChr(id);
            if (c->fA8D == 0) {
                c->fA88 = 1;
            }
        }
    }
}

void MsFreePlayer(int id) {
    BtlChr *c = MsGetChr(id);
    c->fA88 = 0;
    MsCleanInputCue(id, 0);
    if (D_003172F0.f2114 == id) {
        D_003172F0.f2114 = -1;
    }
    if (c->chr != 0) {
        MsBtlChrFree(id, 7);
    }
}

void MsExchangePlayer(void) {
    int i;
    for (i = 0; i < 7; i++) {
        u8 id = D_003172F0.f1FC5[i];
        if (id != 0xFF) {
            BtlChr *c = MsGetChr(id);
            int k = id == D_003172F0.f2119 ? -1 : 0;
            c->f1BC.a = c->f1C0.a;
            c->f1BC.b = c->f1C0.b;
            c->f1BC.c = c->f1C0.c;
            MsExchangeChr(0xFF, id, k, 0);
        }
    }
}

int func_001D1BF0(int a, Sub1C *p) {
    int r = 1;
    if (a == 1 || a == 5) {
        u32 f = p->f1C;
        if ((f >> 20) & 1) {
            r = 0;
        } else if ((f >> 21) & 1) {
            r = 2;
        }
    }
    return r;
}

void MsSortCommand(u16 *p) {
    u16 *s = (u16 *)btl_ply_win; /* DEBT(TYPE): btl_ply_win is declared s32 */
    func_001D1CE0(p, s + 0x2838, 0x14);
    func_001D1CE0(p + 0x14, s + 0x284C, 8);
    func_001D1CE0(p + 0x1C, s + 0x2854, 8);
    func_001D1CE0(p + 0x24, s + 0x285C, 0x18);
    func_001D1CE0(p + 0x3C, s + 0x2874, 0x18);
    func_001D1CE0(p + 0x54, s + 0x288C, 0x20);
    func_001D1CE0(p + 0x74, s + 0x28AC, 0x20);
    func_001D1CE0(p + 0x94, s + 0x28CC, 0x18);
}

void func_001D1CE0(u16 *src, u16 *dst, int n) {
    int i;
    int k;
    int v;
    u16 t;

    for (i = 0; i < n; i++) {
        k = src[i];
        t = k; /* DEBT(FAKE): u16 copy only steers register allocation of the sort loop */
        v = 0x100;
        if (t != 0xFF && (k >> 12) == 3) {
            v = MsGetRomPlyCommand(k, 0)->b5C;
        }
        dst[i] = v;
    }
    do {
        v = 0;
        for (i = 0; i < n - 1; i++) {
            if (dst[i + 1] < dst[i]) {
                t = dst[i + 1];
                dst[i + 1] = dst[i];
                dst[i] = t;
                t = src[i + 1];
                src[i + 1] = src[i];
                src[i] = t;
                v = 1;
            }
        }
    } while (v);
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D00D8", func_001D1DF8);

void MsComBufInit(void) {
    D_00662628 = 0;
}

int func_001D1FA8(int x, int y, int z) {
    int r = 0;
    int n = D_00662628;
    if (n < 8) {
        Q4Ev *e = &D_00662630[n];
        r = 1;
        D_00662628 = n + 1;
        e->key = x;
        e->v[0] = y;
        e->v[1] = z;
    }
    return r;
}

typedef struct {
    u8 pad0[0x10];
    u16 h10[2];
    u8 pad14[0x19 - 0x14];
    u8 b19;
    u8 pad1A[0x58 - 0x1A];
    u8 b58;
} MagicEffData;

int MsGetMagicEffNum(int id, int cmd, MagicEffData *p) {
    int idx;
    int res;

    if ((u32)(p->b19 - 8) < 10) {
        if (((D_0031D1DC >> 11) & 1) || MsGetSaveCommandUse(id, cmd) == 0) {
            idx = 0;
        } else {
            idx = 1;
        }
    } else {
        idx = D_003193EE;
    }
    res = p->h10[idx];
    if (p->b58 == 0x24 || p->b58 == 0x34 || p->b58 == 0x44 || p->b58 == 0x54) {
        int sp0[2];
        switch (FFXGetLang()) {
        case 2:
            sp0[0] = 0x2B3;
            sp0[1] = 0x2B4;
            break;
        case 0:
        case 3:
            sp0[0] = 0x2B9;
            sp0[1] = 0x2BA;
            break;
        case 4:
            sp0[0] = 0x2B7;
            sp0[1] = 0x2B8;
            break;
        case 5:
            sp0[0] = 0x2B5;
            sp0[1] = 0x2B6;
            break;
        default:
            sp0[0] = p->h10[0];
            sp0[1] = p->h10[1];
            break;
        }
        res = sp0[idx];
    } else {
        int i;
        Q4Ev *e = D_00662630;
        for (i = 0; i < D_00662628; i++, e++) {
            if (cmd == e->key) {
                res = e->v[idx];
            }
        }
    }
    return res;
}
