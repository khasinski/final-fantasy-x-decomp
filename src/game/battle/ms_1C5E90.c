/* tu_194 0x1c5e90-0x1c8c80: medium; ~Ms (config/tu_map.tsv) */
#define MsCalcMotionSpeed _hdr_MsCalcMotionSpeed
#define Ch_SetMotionSpeed _hdr_Ch_SetMotionSpeed
#define MsThreatProcess _hdr_MsThreatProcess
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/v3.h"
#include "ffx/s3.h"
#include "ffx/u2.h"
#undef MsCalcMotionSpeed
#undef Ch_SetMotionSpeed
#undef MsThreatProcess

int MsThreatProcess(int id, BtlChr *c);
int func_001C7D60(int id);
void Ch_SetMotionSpeed(Chr *chr, int v);
int func_00117D58(Chr *chr, int v);

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

void MsSetDeathProcess(int id, BtlChr *c) {
    float pos[4];

    c->fA8C = 2;
    func_001B6790(id, pos);
    *(float *)((u8 *)c + 0xC30) = pos[1];
    MsAtelRequestCamera(0, id, 0x3F, 0xFFFF, 0, 1, 0, 0);
    c->f1CE = 0;
    c->f1CF = 0;
    msSetChrBodyHit(c, 3, 0);
    c->fDC = 0;
}

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

int MsThreatProcess(int id, BtlChr *c) {
    float pos1[4];
    float pos2[4];
    int ret;
    int t;
    BtlChr *d;

    if ((c->f2C6 >> 11) & 1) {
        t = c->pad285[0];
        ret = 1;
        d = MsGetChr(t);
        MsGetChrBtlPos(id, pos1);
        MsVectorRect2Polar(pos2, pos1, (int)&c->f1D4[2], 0, 0);
        MsSetDirThetaMode(c);
        if (t != 0xFF) {
            MsGetChrBtlPos(t, pos2);
            MsVectorRect2Polar(pos1, pos2, (int)&d->f1D4[2], 0, 0);
            d->f286 = id;
            d->f2C6 |= 0x800;
            MsSetDirThetaMode(d);
        }
    } else {
        t = c->pad285[0];
        ret = 0;
        if (t == 0xFF) {
            t = c->f286;
        }
        d = MsGetChr(t);
        c->pad285[0] = 0xFF;
        c->f286 = 0xFF;
        MsSetDirThetaMode(c);
        func_001C7928(id, c);
        if (t != 0xFF) {
            d->pad285[0] = 0xFF;
            d->f286 = 0xFF;
            d->f2C6 &= ~0x800;
            MsSetDirThetaMode(d);
            func_001C7928(t, d);
        }
    }
    return ret;
}

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

int func_001C7D60(int id) {
    int r;
    if ((MsGetRamChrMonster(id) == 1 && D_00317318 != 0) || (MsGetRamChrMonster(id) == 0 && D_00317319 != 0)) {
        r = 0;
    } else {
        r = 1;
    }
    return r;
}

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

int MsCalcCostCTB(GsEnt48 *e) {
    struct GsEnt48Sub sp0;
    OfsTbl *t = 0;

    if (e != 0) {
        struct GsEnt48Sub *p = e->f8;
        int id = e->id;
        BtlChr *c;
        u16 *cmd_p;
        int done;
        int i;

        sp0.h2 = 0xFF;
        sp0.targets = p->targets;
        c = MsGetChr(id);
        cmd_p = &p->h0;
        done = 0;
        for (i = 0; i < 2; i++, cmd_p++) {
            u16 cmd = *cmd_p;
            if (cmd != 0xFF) {
                OfsTbl *res;
                if (c->f39E != 0) {
                    cmd = 0x3028;
                }
                sp0.h0 = cmd;
                res = MsGetCommand(id, 0, -1, &sp0, 0);
                switch (cmd) {
                case 0x3029:
                    done = 1;
                    break;
                case 0x305F:
                    done = 1;
                    break;
                case 0x311E:
                    done = 1;
                    break;
                }
                if (res != 0) {
                    t = res;
                }
                if (done != 0) {
                    break;
                }
            }
        }
    }
    if (t != 0 && t->b24 != 0) {
        return t->b24;
    }
    return 3;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C5E90", MsCalcDamageCTB);

int MsCalcMotionSpeed(BtlChr *c) {
    int mul = 8;
    Chr *chr = c->chr;
    int spd;

    if (c->f12 != 0) {
        mul = MsGetChr(c->f14)->padC6[0];
    } else if (c->fA8E != 0) {
        mul = 0;
    } else if (((c->f2C6 >> 11) & 1) && c->f286 == 0xFF) {
        if (c->fF2 == 0) {
            if (c->f1C8 == 0) {
                mul = 0;
            }
        }
    } else if (c->f2D3 != 0) {
        mul = 16;
    } else if (c->f2D4 != 0) {
        if ((u32)(c->fB0 - 0x10) <= 0x1A) {
            mul = 4;
        }
    }
    c->padC6[0] = mul;
    if (c->fC4 == 1) {
        spd = *(u16 *)&c->fC2;
    } else {
        spd = (c->fBC * mul) / 8;
    }
    if (chr != 0 && spd != c->fC0 && c->f38 != 0) {
        if (c->fC0 == 0 && spd != 0) {
            func_00117D58(chr, 1);
        }
        if (c->fC0 != 0 && spd == 0) {
            func_00117D58(chr, 0);
        }
        Ch_SetMotionSpeed(chr, spd);
        c->fC0 = spd;
    }
    return spd;
}

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

int func_001C87D8(int id, BtlChr *c, int arg2) {
    int sub = 0;
    int item = 0;

    if ((u32)c->f290 <= (u32)c->f254 / 2 && func_001D8C78(id, 0x20) != 0 && MsAutoCommandStatusCheck(c, 1, 1, 1) != 0) {
        if (func_001BFE30(0x2000) > 0) {
            sub = 1;
            item = 0x2000;
        } else if (func_001BFE30(0x2001) > 0) {
            sub = 2;
            item = 0x2001;
        } else if (func_001BFE30(0x2002) > 0) {
            sub = 3;
            item = 0x2002;
        }
        if (item > 0) {
            func_001C86A8(id, id, arg2, item, sub | 0x20);
        }
    }
    return item;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C5E90", func_001C88D8);

int MsAutoPhenixProcess(int id, int b, int c) {
    int r = 0;
    int i;
    int end;
    int ok;
    if (MsGetRamChrMonster(id) == 0) {
        ok = func_001BFE30(0x2006);
        i = 0;
        end = 0x14;
    } else {
        i = 0x14;
        end = 0x1C;
        ok = 1;
    }
    if (ok > 0) {
        for (; i < end; i++) {
            BtlChr *chr = MsGetChr(i);
            if (chr->fA8C == 0 && ((chr->f37C >> 12) & 1) &&
                MsAutoCommandStatusCheck(chr, 1, 1, 1) != 0) {
                r = 0x2006;
                func_001C86A8(i, id, c, 0x2006, 0x30);
                break;
            }
        }
    }
    return r;
}

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
