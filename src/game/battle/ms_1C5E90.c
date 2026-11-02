/* tu_194 0x1c5e90-0x1c8c80: medium; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/v3.h"
#include "ffx/s3.h"
#include "ffx/u2.h"

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C5E90", func_001C5E90);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C5E90", func_001C6050);

int func_001C6878(int a, int b, int id) {
    int r = 0;
    BtlChr *c = MsGetChr(id);
    u8 *p = (u8 *)c + 0x434; /* DEBT(CAST): two 0x2D8-byte records */
    int i;
    for (i = 1; i >= 0; i--, p += 0x2D8) {
        if (p[2] == a && p[3] == b) {
            r |= p[0] < p[1];
        }
    }
    return r;
}

int MsResetChrPos(int id, BtlChr *c) {
    int r = 0;
    Chr *chr = c->chr;
    if (chr != 0) {
        int ok = 0;
        float pos[4];
        if (c->fFF == 0xFF && c->fE6 == 0 && !(c->flags & 0x8000)) {
            s8 s = c->f1CD;
            c->f1CD = 1;
            ok = MsCheckBtlPos(id, c, c->f34);
            c->f1CD = s;
        }
        if (ok) {
            r = 1;
            Ch_OptposGet(chr, 6, pos);
            MsSetChrPos(id, pos);
        }
    }
    return r;
}

void func_001C69B8(int id, BtlChr *c) {
    c->fE5 = 1;
    func_001B6790(id, c->f80);
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C5E90", MsDamageSetMotion);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1C5E90/rodata", jtbl_0056E680);

void MsSetDamageMotion(int a, int kind, int arg) {
    u8 id = a;
    int sub;
    int mask;
    int i;
    int k;
    BtlChr *c;
    struct Obj436Slot *s;

    if (MsBtlChrNumCheck(id)) {
        MsGetChr(id);
        i = 0;
        sub = MsGetChrCommand(id)->f2;
        mask = MsGetChrBit(id, kind, 1, 1);
        for (; i < 31; i++) {
            if (!((mask >> i) & 1)) {
                continue;
            }
            if (i == id) {
                continue;
            }
            c = MsGetChr(i);
            if (c->fA8C != 0) {
                continue;
            }
            s = ((Obj436 *)c)->slot; /* DEBT(CAST): the slot area of the BtlChr record */
            for (k = 0; k < 2; k++, s++) {
                if (s->v == id && s->sub == sub) {
                    MsDamageSetMotion(i, arg, 1);
                }
            }
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C5E90", MsDamageCheckDeath);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C5E90", MsSetDeath);

int MsCheckInputCueExe(int id, BtlChr *c) {
    int r = 1;

    if (c->fC1E & 2) {
        r = 0;
    }
    if (c->fC1E & 4) {
        r = 0;
    }
    if (c->fB9 != 0 && c->f1C8 != 0) {
        r = 0;
    }
    if (func_001D9780(id) || func_001D8CD0(id)) {
        r = 0;
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C5E90", MsSetDeathProcess);

void MsDeathTerminate(int a, BtlChr *c) {
    if (c->fB7 == 0) {
        c->fF6 = 0;
    }
    c->fB4 = 1;
    MsStatusEffectCheck(a);
    MsResetBindEffect(a);
}

void MsSetEternalRelife(BtlChr *c) {
    if (c->f3B != 0) {
        c->f2D6 |= 0x200;
    }
}

void MsRelife(int id, BtlChr *c, int full) {
    if (c->f290 <= 0) {
        c->f290 = 1;
    }
    MsSetEternalRelife(c);
    c->fA8C = 0;
    c->fB5 = c->fB6;
    c->fA8D = 0;
    c->fA8E = 0;
    c->fA8F = 0;
    c->fA90 = 0;
    c->fA91 = 0;
    c->fAD7 = 0;
    c->f3C0 = 0;
    c->f3C1 = 0;
    c->f2C6 &= ~1;
    D_003172F0.f203C &= ~(1 << id);
    func_001B7518(&c->chr, c->f19C);
    MsSetEscapeFlag(id, c, 0);
    c->f109 = 0;
    c->fDC = 1;
    c->fB4 = 0;
    c->fAAC = 0;
    c->fC1F = 0;
    c->f31C = c->f31D;
    msSetChrBodyHit(c, 3, 1);
    if (full) {
        c->fFE = 1;
        MsSetChrWeak(id, -1);
        MsResetAutoStatus(c);
        MsSetAutoStatus(c);
    }
}

void MsSetEscapeFlag(int a, BtlChr *chr, int on) {
    if (on == 0) {
        chr->fA8D = 0;
        chr->fA88 = 1;
        func_001B57F0(a, 1);
    } else {
        chr->fA8D = 1;
        chr->fA88 = 0;
    }
}

void MsSetEscapeFlagAll(int a) {
    int i;
    for (i = 0; i < 0x12; i++) {
        MsSetEscapeFlag(i, MsGetChr(i), a);
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C5E90", MsLimitStatusProcess);

int MsBlowProcess(int a, BtlChr *c) {
    int r;
    if ((c->f2D6 >> 8) & 1) {
        r = 1;
        MsSetEscapeFlag(a, c, 1);
    } else {
        r = 0;
        MsRelife(a, c, 1);
    }
    return r;
}

int func_001C7718(int a, BtlChr *c) {
    int r;
    if ((c->f2C6 & 1) != 0) {
        c->f290 = 0;
        r = 1;
    } else {
        MsRelife(a, c, 1);
        r = 0;
        MsSetVoiceCheck(a, 10, 1, 0, 0);
    }
    return r;
}

int MsStoneProcess(int id, BtlChr *chr)
{
    int result = 0;
    if (chr->chr != 0) {
        if ((chr->f2C6 >> 2) & 1) {
            MsRegSEplay(id, 0x59);
            result = 1;
            func_001B7518(&chr->chr, -1.0f);
            MsProvOff(id);
            if (chr->f290 <= 0) chr->f2D6 |= 0x100;
        } else {
            MsSetEternalRelife(chr);
            func_001B7518(&chr->chr, chr->f19C);
            MsResetAutoStatus(chr);
            MsSetAutoStatus(chr);
        }
    }
    return result;
}

void MsProvOff(int a) {
    int i;
    BtlChr *c;
    for (i = 0; i < 31; i++) {
        c = MsGetChr(i);
        if ((c->f2C6 >> 10) & 1) {
            if (c->f284 == a) {
                c->f2C6 &= ~0x400;
            }
        }
    }
}

void MsThreatOff(int id, BtlChr *c) {
    int t;
    BtlChr *d;

    if ((c->f2C6 >> 11) & 1) {
        t = c->f286;
        if (t != 0xFF) {
            d = MsGetChr(t);
        } else {
            t = id;
            d = c;
        }
        d->f2C6 &= ~0x800;
        MsThreatProcess(t, d);
    }
}

void func_001C7928(int id, BtlChr *c) {
    if (c->fA8C == 0 && ((c->f2C6 >> 2) & 1) == 0 && ((c->f2D6 >> 8) & 1) == 0 && func_001DAF88(c, 0) != 0) {
        c->fDC = 1;
        MsSetMotion(id, 0, 1, 0, 1, 0, 0);
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C5E90", MsThreatProcess);

void MsSetPartyRelifeTime(void) {
    int i;
    for (i = 0; i < 7; i++) {
        int id = D_003192B5[i];
        if (id != 0xFF) {
            BtlChr *c = MsGetChr(id);
            c->f290 = 0;
            c->f398 = c->f399 + 1;
        }
    }
}

void MsOrderInit(void) {
    D_006625E8 = 0;
}

void MsOrderRegist(int v) {
    if (D_006625E8 < 31) {
        D_006625F0[D_006625E8++] = v;
    }
}

int func_001C7BE0(int id) {
    if (MsGetRamChrMonster(id) == 0) {
        return ((0xFF - MsGetChr(id)->f26C) << 8) + id;
    }
    return id + 0x10000;
}

u8 *MsOrderCalc(int *out) {
    int i;
    int j;
    int best;
    int m;
    int v;
    u8 t;

    if (out != 0) {
        *out = D_006625E8;
    }
    for (i = 0; i < D_006625E8 - 1; i++) {
        best = i;
        m = func_001C7BE0(D_006625F0[i]);
        for (j = i + 1; j < D_006625E8; j++) {
            v = func_001C7BE0(D_006625F0[j]);
            if (v < m) {
                m = v;
                best = j;
            }
        }
        if (best != i) {
            t = D_006625F0[i];
            D_006625F0[i] = D_006625F0[best];
            D_006625F0[best] = t;
        }
    }
    return D_006625F0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C5E90", func_001C7D60);

void func_001C7DC0(int a, BtlChr *c, int n, int x, int y, int flags) {
    if ((flags & 1) != 0) {
        MsNumberRegist(a, 0, n, x, y, flags);
    }
    if (func_001C7D60(a) != 0) {
        c->f290 -= n;
        c->f290 = MsCheckRange(c->f290, 0, c->f254);
    }
}

void MsSubMP(int a, BtlChr *c, int n, int x, int y, int flags) {
    if ((flags & 2) != 0) {
        MsNumberRegist(a, 1, n, x, y, flags);
    }
    if (func_001C7D60(a) != 0) {
        c->f294 -= n;
        c->f294 = MsCheckRange(c->f294, 0, c->f258);
    }
}

void MsSubCTB(int a, BtlChr *c, int n, int x, int y, int z) {
    if ((y & 4) != 0) {
        MsNumberRegist(a, 2, n, n, x, y, z);
    }
    c->f31C = MsCheckRange(c->f31C + n, 0, 0xFF);
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C5E90", MsCalcCostCTB);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C5E90", MsCalcDamageCTB);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C5E90", MsCalcMotionSpeed);

int MsCalcEscape(int id) {
    s8 k = D_003172F0.f212F;
    int v = (u8)brnd(MsGetRndChr(id, 0));
    if (k != 1 && D_003172F0.f4F == 0 && (v < 0xBF || k == 2)) return 1;
    return 0;
}

int MsAutoCommandStatusCheck(BtlChr *c, int a, int b, int d) {
    int r = 0;
    if (c->fA8E == 0 && ((c->f2C6 >> 8) & 1) == 0 && ((c->f2C6 >> 9) & 1) == 0 && c->f2C8 == 0 && ((c->f2D6 >> 8) & 1) == 0) {
        if (a == 0 || c->fA88 != 0) {
            if (b == 0 || ((c->f2C6 >> 10) & 1) == 0) {
                if (d == 0 || ((c->f2C6 >> 11) & 1) == 0) {
                    r = 1;
                }
            }
        }
    }
    return r;
}

void func_001C86A8(int id, int bit, int c, int h, int a) {
    GsEnt48 e;
    struct GsEnt48Sub *p;
    MsStructClear(&e, 0x48);
    p = e.f8;
    e.id = id;
    e.f3 = 1;
    p->h0 = 0x3001;
    p->h2 = h;
    p->targets = 1 << bit;
    MsInsertBtlCommand(&e, a, 1, c);
}

void func_001C8740(int id, int bit, int c, int h, int a) {
    GsEnt48 e;
    struct GsEnt48Sub *p;
    MsStructClear(&e, 0x48);
    p = e.f8;
    e.id = id;
    e.f3 = 1;
    p->h0 = h;
    p->h2 = 0xFF;
    p->targets = 1 << bit;
    MsInsertBtlCommand(&e, a, 1, c);
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C5E90", func_001C87D8);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C5E90", func_001C88D8);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C5E90", MsAutoPhenixProcess);

int func_001C8C40(int a, BtlChr *c, int d, u32 flags) {
    int r = -1;
    if ((flags >> 9) & 1) {
        func_001C8740(a, a, d, 0x311F, 0x40);
        r = 0;
    } else {
        c->f28A = 0;
    }
    return r;
}
