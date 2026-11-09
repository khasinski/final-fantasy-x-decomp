/* tu_198 0x1d00d8-0x1d2170: low; ~Ms (config/tu_map.tsv) */
#define D_0031FA50 _hdr_D_0031FA50
#include "common.h"
#include "ffx/s3.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"
#undef D_0031FA50

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D00D8", MsExchangeChr);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D00D8", MsGetMagicEffNum);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1D00D8/rodata", jtbl_0056EAA0);
