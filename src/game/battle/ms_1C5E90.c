/* tu_194 0x1c5e90-0x1c8c80: medium; ~Ms (config/tu_map.tsv) */
#define MsCalcMotionSpeed _hdr_MsCalcMotionSpeed
#define Ch_SetMotionSpeed _hdr_Ch_SetMotionSpeed
#define MsThreatProcess _hdr_MsThreatProcess
#define msResetHeadTarget _hdr_msResetHeadTarget
#define MsMessageCueRegist _hdr_MsMessageCueRegist
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/v3.h"
#include "ffx/s3.h"
#include "ffx/u2.h"
#undef MsMessageCueRegist
#undef MsCalcMotionSpeed
#undef Ch_SetMotionSpeed
#undef MsThreatProcess
#undef msResetHeadTarget

int MsMessageCueRegist(int, int, int, int, int);

int msResetHeadTarget(BtlChr *c);

int MsThreatProcess(int id, BtlChr *c);
int func_001C7D60(int id);
void Ch_SetMotionSpeed(Chr *chr, int v);
int func_00117D58(Chr *chr, int v);

extern s8 D_003193F0;
extern s8 D_00319403;
int func_001C6050(int a, int b, int id, int *out, int z);
int func_001C6878(int a, int b, int id);
int MsDamageCheckDeath(int a, int b, int c, int d);
int MsBlowProcess(int a, BtlChr *c);

int func_001C5E90(int a, int v, int z) {
    int sp0 = -1;
    u8 id = a;
    int r = 0;

    if (MsBtlChrNumCheck(id)) {
        int i = 0;
        BtlChr *c = MsGetChr(id);
        GsEnt48 *cmd = MsGetChrCommand(id);
        u8 sub = cmd->f2;
        int mask = MsGetChrBit(id, v, 1, 1);

        for (; i < 31; i++) {
            if ((mask >> i) & 1) {
                r += func_001C6050(id, sub, i, &sp0, z) & 1;
            } else {
                r += func_001C6878(id, sub, i) & 1;
            }
        }
        if (r == 0 && c->padAA9[0] != 0 && c->fAA4 != 0xFF && cmd->f2 + 1 >= cmd->f3) {
            if (sp0 >= 0) {
                MsRegSEplay(sp0, 0x3A);
            }
            if (c->pad38A[0] != 0) {
                c->f290 = 0;
                c->fC1E |= 4;
                c->f2D6 |= 0x100;
                MsBlowProcess(id, c);
                MsDamageCheckDeath(id, id, 1, 0);
                c->pad38A[0] = 0;
            }
            c->padAA9[0] = 0;
            D_003193F0 = 6;
            MsDeleteInputCue(id, c->fAA4, 1, 0);
        }
    }
    return r;
}

typedef struct {
    s8 s00;
    s8 s01;
    u8 b02;
    u8 b03;
    u8 b04;
    u8 b05;
    u8 b06;
    u8 b07[13];
    u16 h14;
    u16 h16;
    u16 h18;
    u16 pad1A;
    s32 w1C;
    s32 w20[3];
} DmgSub1C6050;

typedef struct {
    u8 b00;
    u8 b01;
    u8 b02;
    u8 b03;
    u8 b04;
    u8 b05;
    u8 b06;
    u8 b07;
    s16 h08;
    u16 h0A;
    u8 b0C;
    u8 pad0D[3];
    s32 w10;
    u8 pad14[3];
    u8 b17;
    DmgSub1C6050 sub[16];
} DmgRec1C6050;

typedef struct {
    u8 pad00[0x27C];
    u8 b27C;
    u8 b27D;
    u8 pad27E[0x48];
    u16 h2C6;
    u8 b2C8[13];
    u8 pad2D5;
    u16 h2D6;
    u8 pad2D8[0xA4];
    u16 h37C;
    u8 pad37E[0x14];
    u8 b392;
    u8 pad393[0x9];
    u8 b39C;
    u8 b39D;
    u8 pad39E[0x96];
    DmgRec1C6050 rec[2];
    u8 pad9E4[0xAA];
    u8 bA8E;
    u8 padA8F[0x1E];
    u8 bAAD;
    u8 padAAE[0x170];
    u8 bC1E;
    u8 padC1F;
    s32 wC20;
    u8 padC24[0x24];
    void *pC48;
} Chr1C6050;

extern int MsMenuCloseTitleWindow(int);
extern int func_001CF6A8(int, int);
extern int MsPayGIL(int);
extern int func_001CF6D0(int, int);
extern int MsLimitTypeDamageCheck(int, void *, int, void *, int, int, int);
extern void MsSubMP(int, BtlChr *, int, int, int, int);
extern void MsSubCTB(int, BtlChr *, int, int, int, int);
extern int MsLimitTypeStatusCheck(int, void *, int, void *, int, int);
extern int func_001C7718(int, BtlChr *);
extern int MsStoneProcess(int, BtlChr *);
extern int func_001C88D8(int, BtlChr *, int, int, int, int, int);
extern int func_001C87D8(int, BtlChr *, int);
extern int MsSetChrWeak(int, int);
extern int func_001C3758(int, void *, int, void *);
extern int func_001CF278(int, int, int);
extern void MsDamageSetMotion(int, int, int);

int func_001C6050(int a0, int a1, int id, int *out, int flags)
{
    int i;
    int ret;
    int diff_chr;
    int old_sleep;
    int old_zombie;
    int old_2CA;
    int old_2C9;
    int old_threat;
    int hp_dmg;
    DmgSub1C6050 *last_sub;
    Chr1C6050 *src_chr;
    Chr1C6050 *chr;

    src_chr = (Chr1C6050 *)MsGetChr(a0);
    ret = 0;
    chr = (Chr1C6050 *)MsGetChr(id);
    last_sub = 0;
    diff_chr = (a0 != id);

    for (i = 0; i < 2; i++) {
        DmgRec1C6050 *rec = &chr->rec[i];
        if (rec->b02 != a0 || rec->b03 != a1) {
            continue;
        }
        chr->bC1E = flags & 0x7F;
        chr->bAAD = a0;
        if (!(flags & 8)) {
            if (rec->b07 != 0) {
                MsMenuCloseTitleWindow(0);
                rec->b07 = 0;
                MsMessageCueRegist(4, rec->h0A, rec->h08, 0x1B, 0x23);
                if (rec->h08 > 0) {
                    func_001CF6A8(id, rec->b01);
                    MsRegSEplay2(id, 0x41);
                }
                rec->b05 |= 1;
            }
            if (rec->b0C != 0) {
                MsMenuCloseTitleWindow(0);
                rec->b0C = 0;
                MsMessageCueRegist(8, rec->w10, 0, 0x1B, 0x23);
                if (rec->w10 > 0) {
                    MsPayGIL(-rec->w10);
                    func_001CF6D0(id, rec->b01);
                    MsRegSEplay2(id, 0x41);
                }
                rec->b05 |= 1;
            }
        }
        if (rec->b04 != 0) {
            if (rec->b04 & 1) {
                u8 v = src_chr->b27C;
                src_chr->b27C = 0;
                chr->b27C = MsCheckRange(chr->b27C + v, 0, chr->b27D);
            }
            if (rec->b04 & 2) {
                u16 *p = (u16 *)((Chr1C6050 *)MsGetChr(rec->b17))->pC48;
                if (id == 3 && p != 0) {
                    if (p[3] != 0) {
                        int cmd = p[3];
                        if (MsGetSaveCommand(3, cmd) == 0) {
                            MsSetSaveCommand(3, cmd, 1);
                            MsMessageCueRegist(6, 3, cmd, 0x1E, 0x32);
                            chr->b27C = chr->b27D;
                        }
                    }
                }
            }
            rec->b04 = 0;
        }
        if (rec->b00 < rec->b01) {
            DmgSub1C6050 *sub = &rec->sub[rec->b00];
            hp_dmg = 0;
            if (!(flags & 8)) {
                s8 st = sub->s01;
                u8 b2 = sub->b02;
                int j;
                int old_dead, old_stone, old_blow;
                u8 old_2D2;
                switch (st) {
                case 1:
                    MsNumberRegist(id, 3, 0, 0, 1, b2, 0x81);
                    break;
                case 2:
                    MsNumberRegist(id, 4, 0, 0, 2, b2, 0x81);
                    break;
                }
                MsLimitTypeDamageCheck(a0, src_chr, id, chr, sub->w20[0], sub->w1C, rec->b06);
                for (j = 0; j < 3; j++) {
                    s32 val = sub->w20[j];
                    if ((sub->h18 >> j) & 1) {
                        switch (j) {
                        case 0:
                            hp_dmg += val;
                            ((void (*)(int, BtlChr *, int, int, int, int, int))func_001C7DC0)(id, (BtlChr *)chr, val, sub->w20[1], st, b2, 0x81);
                            chr->wC20 -= val;
                            break;
                        case 1:
                            ((void (*)(int, BtlChr *, int, int, int, int, int))MsSubMP)(id, (BtlChr *)chr, val, sub->w20[0], st, b2, 0x81);
                            break;
                        case 2:
                            MsSubCTB(id, (BtlChr *)chr, val, st, b2, 0x81);
                            break;
                        }
                    }
                }
                MsLimitTypeStatusCheck(a0, src_chr, id, chr, sub->b04, sub->b03);
                old_2CA = chr->b2C8[2];
                old_2C9 = chr->b2C8[1];
                old_dead = chr->h2C6 & 1;
                old_2D2 = chr->b2C8[10];
                old_blow = (chr->h2D6 >> 8) & 1;
                old_stone = (chr->h2C6 >> 2) & 1;
                old_sleep = (chr->h2C6 >> 3) & 1;
                old_zombie = (chr->h2C6 >> 1) & 1;
                old_threat = (chr->h2C6 >> 11) & 1;
                chr->h2C6 = sub->h14;
                for (j = 0; j < 13; j++) {
                    chr->b2C8[j] = sub->b07[j];
                }
                chr->h2D6 = sub->h16;
                MsLimitStatusProcess(id, (BtlChr *)chr, sub->b06);
                if (chr->b2C8[10] != 0 && old_2D2 == 0) {
                    chr->b392 = 0;
                }
                chr->bA8E = (chr->h2C6 >> 2) & 1;
                if ((chr->h2C6 & 1) != old_dead) {
                    ((int (*)(int, BtlChr *, int))func_001C7718)(id, (BtlChr *)chr, a0);
                }
                if (((chr->h2C6 >> 2) & 1) != old_stone) {
                    MsStoneProcess(id, (BtlChr *)chr);
                }
                if (((chr->h2D6 >> 8) & 1) != old_blow) {
                    MsBlowProcess(id, (BtlChr *)chr);
                }
                if (((chr->h2C6 >> 11) & 1) != old_threat) {
                    MsThreatProcess(id, (BtlChr *)chr);
                }
                rec->b05 |= 1;
                if ((chr->h37C >> 11) & 1) {
                    func_001C88D8(id, (BtlChr *)chr, a0, old_sleep, old_zombie, old_2CA, old_2C9);
                }
                if (hp_dmg > 0 && ((chr->h37C >> 10) & 1)) {
                    func_001C87D8(id, (BtlChr *)chr, a0);
                }
                MsSetChrWeak(id, -1);
                ret |= 2;
                rec->b00++;
            }
            if (chr->b39C != 0) {
                func_001C3758(a0, src_chr, id, chr);
            }
            if (!(flags & 2)) {
                if (sub->s00 != 1 || !(rec->b05 & 4)) {
                    last_sub = sub;
                    rec->b05 |= 4;
                }
            }
            if (!(flags & 0x10)) {
                MsStatusEffectCheck(id);
                if (func_001CF278(a0, id, sub->h18) != 0) {
                    *out = id;
                }
            }
            if (rec->b00 < rec->b01) {
                ret |= 1;
                continue;
            }
        }
        if ((rec->b05 & 1) && !(rec->b05 & 2)) {
            chr->b39D = 0;
            rec->b05 |= 2;
            MsActionRequest(id, a0, 3, 0, 1, 0);
        }
        if (flags & 0x400) {
            rec->b02 = 0xFF;
        } else {
            MsPopBtlPos(chr);
        }
    }

    if (!(ret & 1)) {
        if (MsDamageCheckDeath(a0, id, 0, diff_chr) != 0) {
            last_sub = 0;
        }
    }
    if (last_sub != 0) {
        int kind = last_sub->s00;
        if (flags & 0x20) {
            switch (kind) {
            case 5:
            case 8:
                kind = (brnd(9) & 3) + 0xD;
                break;
            case 6:
                kind = (brnd(9) & 1) + 0xF;
                break;
            }
        }
        MsDamageSetMotion(id, kind, diff_chr);
    }
    return ret;
}

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

void func_001C69B8(int id, BtlChr *c);

void MsDamageSetMotion(int a, int kind, int arg)
{
    int mot = -1;
    BtlChr *c = MsGetChr((u8)a);
    int id = c->fE2;
    int loop;
    int reset_pos;

    c = MsGetChr(id);
    MsEffectResetMotionDisable(c);
    msResetHeadTarget(c);
    c->f1CE = c->f1CF;
    c->f1CF = 0;
    c->f10E = 0;
    if (c->fF6 != 0) {
        return;
    }
    if (c->fA8E == 0) {
        loop = 1;
        reset_pos = 1;
        switch (kind) {
        case 1:
            if (!(c->flags & 0x4000)) {
                c->fF3 = 1;
                c->fAAF = c->fAAD;
                func_001C69B8(id, c);
                mot = 0xC;
            }
            break;
        case 2:
        case 7:
            if (c->fFE != 0) {
                reset_pos = 0;
            }
            c->fF3 = 1;
            mot = 0x10;
            break;
        case 3:
            c->fF3 = 1;
            mot = 0xE;
            break;
        case 4:
            c->fF3 = 1;
            mot = 0xF;
            break;
        case 12:
            reset_pos = 0;
            c->fF3 = 1;
            mot = 0x1B;
            break;
        case 5:
        case 8:
            c->fF3 = 1;
            mot = 9;
            break;
        case 6:
            c->fF3 = 1;
            mot = 0x30;
            break;
        case 13:
            c->fF3 = 1;
            mot = 9;
            c->f10E = 1;
            break;
        case 14:
            c->fF3 = 1;
            mot = 9;
            c->f10E = -1;
            break;
        case 15:
            c->fF3 = 1;
            mot = 0x30;
            c->f10E = 1;
            break;
        case 16:
            c->fF3 = 1;
            mot = 0x30;
            c->f10E = -1;
            break;
        case 11:
            mot = 0;
            loop = 0;
            break;
        default:
            if (c->fDA != 0) {
                mot = 0;
                loop = 0;
            }
            break;
        }

        if (c->f39A != 0 && (mot == 9 || mot == 0x30)) {
            mot = 0x43;
        }
        if (mot >= 0) {
            if (reset_pos != 0) {
                MsResetChrPos(id, c);
            }
            MsSetMotion(id, mot, loop, 0, arg, 0, 0);
        }
        c->fDA = 0;
    } else {
        c->fDC = 0;
        c->fDA = 1;
        MsResetChrPos(id, c);
        if (c->fAAD == id) {
            if (id == 5) {
                MsSetMotion(0x1D, 0, 1, 0, arg, 0, 0);
            }
            MsAttachWeapon(id, 0);
        }
        MsSetMotion(id, 0x38, 1, 0, arg, 0, 0);
        c->f1C8 = 0;
    }
}

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

int MsCheckInputCueExe(int id, BtlChr *c);
void MsSetDeathProcess(int id, BtlChr *c);
void MsDeathTerminate(int a, BtlChr *c);
void MsProvOff(int a);
void MsThreatOff(int id, BtlChr *c);
int func_001C8C40(int a, BtlChr *c, int d, u32 flags);
int MsAutoPhenixProcess(int id, int b, int c);
int MsSetDeath(int id, int arg1);

int MsDamageCheckDeath(int a, int b, int c, int d) {
    int ret = 0;
    BtlChr *ca = MsGetChr(a);
    BtlChr *cb = MsGetChr(b);
    int mode = ((cb->f2D6 >> 8) & 1) ? 2 : (cb->f290 <= 0);

    if (cb->f10 != 0 && mode != 0 && cb->fA8C == 0) {
        cb->f3C0 = cb->f3C1 ? cb->f3C1 : (mode == 2);
        cb->pad3C2[0] = mode;
        cb->padAAE[0] = a;
        ca->f39D = 0;
        if (cb->fA8D != 0 && cb->fA8E != 0) {
            cb->fA8F = 1;
        }
        if (MsGetRamChrMonster(b) != 0 && c == 0) {
            u16 cap;
            MsSetMonsterCheck(cb->fE, (u16 *)MsGetSaveMonsterDefeat());
            cap = *(u16 *)&cb->pad395[1];
            if (cb->fA90 != 0) {
                cb->fA90 = MsMonsterCapture(b, cap);
            }
            cb->fA91 = cb->fA90;
            D_003172F0.pad211B[0]++;
            MsSaveAddInfoData(a, 1);
            if (*(s32 *)cb->padC20 <= 0 && (s8)D_003172F0.pad3D[7] == 0) {
                cb->fC1F = 1;
                MsNumberRegist(b, 5, -1, -1, 0, 0, 0x81);
            }
        } else {
            cb->fA90 = 0;
        }
        MsSaveAddInfoData(b, 2);
        {
            u16 d6 = cb->f2D6;
            cb->fA8C = 1;
            MsProvOff(b);
            MsThreatOff(b, cb);
            MsClearStatus(b, 0);
            if (MsGetRamChrSummon(b) != 0) {
                cb->f27C = 0;
            }
            cb->f2C6 |= 1;
            if (cb->pad390[0] != 0) {
                GsEnt48 *cmd = MsGetChrCommand2(b);
                if (cmd != 0) {
                    cmd->f3 = cmd->f2 + 1;
                }
            }
            MsCleanInputCue(b, 1);
            MsCleanCommandCue(b, 1);
            if (cb->fB5 != 0) {
                cb->fA88 = 0;
            }
            MsActionRequest(b, a, 4, 0, 1, 0);
            if (c == 0) {
                MsGetItem(a, cb, *(s32 *)cb->padC48, cb->fC1F, d6);
            }
            if (mode == 1) {
                if (func_001C8C40(b, cb, a, d6) != 0) {
                    MsAutoPhenixProcess(b, (int)cb, a);
                }
            }
            MsLimitTypeDeathCheck(a, ca, b, cb);
            ret = MsSetDeath(b, d);
            MsSetChrWeak(b, -1);
        }
    }
    return ret;
}

int MsSetDeath(int id, int arg1) {
    int ret = 0;
    BtlChr *c = MsGetChr(id);

    if (c->fA8C == 1) {
        if (MsCheckInputCueExe(id, c)) {
            c->fF6 = 1;
            D_00319403 = id;
            MsEffectResetMotionDisable(c);
            MsResetChrPos(id, c);
            MsSetDeathProcess(id, c);
            if (c->f109 != 1) {
                if (c->f109 == 6) {
                    goto L_type6;
                }
                if (c->fA8D == 0) {
                    goto L_no_A8D;
                }
                if (c->fA8E == 0) {
                    goto L_no_A8E;
                }
                MsStoneRegist(id);
                MsSetMotion(id, 0x3A, 1, 0, arg1, 0, 0);
            } else if (c->fA8D != 0) {
                MsSetMotion(id, 0x39, 1, 0, arg1, 0, 0);
            } else {
                if (0) {
                L_type6:
                    MsDeathEffectStart(id, c->fB5);
                }
                MsDeathTerminate(id, c);
            }
            if (0) {
            L_no_A8E:
                MsSetMotion(id, 0x39, 1, 0, arg1, 0, 0);
            }
            if (0) {
            L_no_A8D:
                if (c->fA90 != 0) {
                    MsDeathEffectStart(id, 2);
                    MsSetMotion(id, 0x40, 1, 0, arg1, 0, 0);
                } else {
                    MsDeathEffectStart(id, c->fB5);
                    MsSetMotion(id, 8, 1, 0, arg1, 0, 0);
                }
            }
            ret = 1;
        }
    }
    return ret;
}

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

int MsLimitStatusProcess(int a, BtlChr *c, int b) {
    int old_hp = c->f300 & 1;
    int old_mp = (c->f300 >> 1) & 1;
    int force;
    int chg;

    if (b < 0) {
        force = 1;
        __asm__("" : "+r"(c));
        b = c->f300;
    } else {
        c->f300 = b;
        force = 0;
    }
    chg = 0;
    if ((b & 1) && (old_hp == 0 || force != 0)) {
        c->f254 = MsCheckRange(*(s32 *)c->pad25C * 2, 0, ((c->f37E >> 9) & 1) ? 0x1869F : 0x270F);
        chg = 1;
    } else if ((old_hp != 0 || force != 0) && !(b & 1)) {
        c->f254 = *(s32 *)c->pad25C;
        chg = 1;
    }
    if (chg != 0) {
        c->f290 = MsCheckRange(c->f290, 0, c->f254);
    }
    chg = 0;
    if (((b >> 1) & 1) && (old_mp == 0 || force != 0)) {
        chg = 1;
        c->f258 = MsCheckRange(*(s32 *)(c->pad25C + 4) * 2, 0, ((c->f37E >> 10) & 1) ? 0x270F : 0x3E7);
    } else if ((old_mp != 0 || force != 0) && !((b >> 1) & 1)) {
        c->f258 = *(s32 *)(c->pad25C + 4);
        chg = 1;
    }
    if (chg != 0) {
        c->f294 = MsCheckRange(c->f294, 0, c->f258);
    }
    return 0;
}

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

void MsCalcDamageCTB(GsEnt48 *e, int *ctb, int arg2, u8 *p3, u8 *p4) {
    int i = 0;
    int j;
    int id = e->id;
    BtlChr *ca = MsGetChr(id);

    for (; i < e->f3; i++) {
        OfsTbl *cmd = MsGetCommand(id, 0, -1, &e->f8[i], 0);
        if (cmd != 0) {
            int flg;
            int v40;
            int v44;
            int targets;

            if ((cmd->flags >> 18) & 1) {
                v40 = ca->f281;
                flg = 1;
                v44 = ca->pad287[0];
            } else {
                flg = 0;
                v40 = cmd->b28;
                v44 = cmd->b2A;
            }
            targets = e->f8[i].targets;
            for (j = 0; j < 31; j++) {
                if (((targets >> j) & 1) && ctb[j] >= 0) {
                    int v_s7 = 0;
                    int v_fp;
                    int mul;
                    int old_ctb;
                    BtlChr *cb = MsGetChr(j);

                    *(s32 *)&cb->pad3A2[2] = cb->f290;
                    *(s32 *)&cb->pad3A2[6] = cb->f294;
                    *(s32 *)&cb->pad3A2[10] = cb->f31C;
                    if (cmd->pad2E[0x45 - 0x2E] != 0 || (ca->pad29E[0x2B5 - 0x29E] != 0 && flg != 0)) {
                        int c2 = ca->pad29E[0x2C2 - 0x29E];
                        v_s7 = cmd->pad2E[0x52 - 0x2E];
                        if (v_s7 < c2) {
                            v_s7 = flg ? c2 : v_s7;
                        }
                    }
                    v_fp = 0;
                    if (cmd->pad2E[0x46 - 0x2E] != 0 || (ca->pad29E[0x2B6 - 0x29E] != 0 && flg != 0)) {
                        int c3 = ca->pad29E[0x2C3 - 0x29E];
                        v_fp = cmd->pad2E[0x53 - 0x2E];
                        if (v_fp < c3) {
                            v_fp = flg ? c3 : v_fp;
                        }
                    }
                    mul = ((cmd->flags >> 14) & 1) ? 2 : ((cmd->flags >> 13) & 1);
                    if (mul != 0) {
                        int rom = MsGetRomCTBcount(cb->f26C) * 3;
                        ctb[j] += (rom * mul) / 2;
                    }
                    if (cmd->pad2E[0x39 - 0x2E] != 0 || (ca->pad29E[0x2A9 - 0x29E] != 0 && flg != 0)) {
                        ctb[j] = ca->f31C + MsGetNextCTB(ca, arg2, ca->f2D3, ca->f2D4);
                        p3[j] = 0;
                        p4[j] = 0;
                    }
                    old_ctb = ctb[j];
                    if (cmd->pad23 & 4) {
                        ctb[j] += MsCalcDamageCommand(ca, cb, (int)cmd, v40, v44, cb->f2C6, 4, 0, 0, 0, 0);
                        if (ctb[j] < 0) {
                            ctb[j] = 0;
                        }
                    }
                    if (v_s7 != 0) {
                        if ((*(u16 *)cmd->pad20 >> 5) & 1) {
                            if (p3[j] < 0xFF) {
                                p3[j] = MsCheckRange(p3[j] - v_s7, 0, 0xFF);
                            } else {
                                ctb[j] = old_ctb;
                            }
                        } else if (p3[j] == 0) {
                            p3[j] = v_s7;
                            p4[j] = 0;
                        } else {
                            ctb[j] = old_ctb;
                        }
                    }
                    if (v_fp != 0) {
                        if ((*(u16 *)cmd->pad20 >> 5) & 1) {
                            if (p4[j] < 0xFF) {
                                p4[j] = MsCheckRange(p4[j] - v_fp, 0, 0xFF);
                            } else {
                                ctb[j] = old_ctb;
                            }
                        } else if (p4[j] == 0) {
                            p4[j] = v_fp;
                            p3[j] = 0;
                        } else {
                            ctb[j] = old_ctb;
                        }
                    }
                }
            }
        }
    }
}

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

int func_001C88D8(int id, BtlChr *c, int arg2, int arg3, int arg4, int arg5, int arg6) {
    int sub = 0;
    int item = 0;
    int cnt;

    if (func_001D8C78(id, 0x10) != 0) {
        int f0 = 0;
        int f1 = 0;
        int f2 = 0;
        int f3 = 0;
        cnt = 0;

        if (((c->f2C6 >> 3) & 1) && arg3 == 0 && !((c->f2EA >> 3) & 1)) {
            cnt = 1;
            f0 = 1;
        }
        if (((c->f2C6 >> 1) & 1) && arg4 == 0 && !((c->f2EA >> 1) & 1)) {
            cnt++;
            f1 = 1;
        }
        if (c->f2CA != 0 && arg5 == 0 && !((c->f2EC >> 2) & 1)) {
            cnt++;
            f2 = 1;
        }
        if (c->f2C9 != 0 && arg6 == 0 && !((c->f2EC >> 1) & 1)) {
            cnt++;
            f3 = 1;
        }
        if (cnt > 0 && MsAutoCommandStatusCheck(c, 1, 1, 1) != 0) {
            if (cnt >= 2 && func_001BFE30(0x200F) > 0) {
                sub = 5;
                item = 0x200F;
            } else if (f0 != 0 && func_001BFE30(0x200A) > 0) {
                sub = 1;
                item = 0x200A;
            } else if (f1 != 0 && func_001BFE30(0x200E) > 0) {
                sub = 2;
                item = 0x200E;
            } else if (f2 != 0 && func_001BFE30(0x200C) > 0) {
                sub = 3;
                item = 0x200C;
            } else if (f3 != 0 && func_001BFE30(0x200D) > 0) {
                sub = 4;
                item = 0x200D;
            } else if (func_001BFE30(0x200F) > 0) {
                sub = 5;
                item = 0x200F;
            }
        }
        if (item > 0) {
            func_001C86A8(id, id, arg2, item, sub | 0x10);
        }
    }
    return item;
}

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
