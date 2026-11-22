/* tu_195 0x1c8c80-0x1ccc10: low; ~Ms (config/tu_map.tsv) */
#define MsStructClear _hdr_MsStructClear
#define func_001CB7A0 _hdr_func_001CB7A0
#define MsInsertBtlCommand _hdr_MsInsertBtlCommand
#define MsInsertInputCue _hdr_MsInsertInputCue
#define MsInsertCommandCue _hdr_MsInsertCommandCue
#define MsGetChrCursorFlag _hdr_MsGetChrCursorFlag
#define MsGetChrDist _hdr_MsGetChrDist
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/v3.h"
#include "ffx/u2.h"
#include "ffx/g2.h"
#undef MsInsertCommandCue
#undef MsInsertInputCue
#undef MsInsertBtlCommand
#undef func_001CB7A0
#undef MsStructClear
#undef MsGetChrCursorFlag
#undef MsGetChrDist

int MsInsertInputCue(int id, int a, int b, int c, int d, int e);
int MsInsertCommandCue(int id, GsEnt48 *e, int n, int a, int b, int c, int d);
s8 MsGetChrCursorFlag(int id);
s8 MsGetChrDist(int id);

extern const s8 _d_00576479 __asm__("D_00576479");
extern void MsBtlReadManage(void);
extern int func_0020D540(void);
extern int MsSEP3Dprocess(void);
extern void MsMenuCloseTitleWindow(int);
extern void MsResetNormalCalc(void);
extern void MsSEPtransProcess(void);
extern void func_001E5FF8(void);
extern int MsCheckChrHitMotionAll(void);
extern void TOControlBtlWindow(void);
extern void MsLimitTypeProcess(void);
extern void MsMessageCueProcess(void);
extern void MsNumberCalcProcess(void);
extern void func_001D25E0(void);
extern void MsMotionPosCheckAll(void);
extern void MsEffectStart(void);
extern int TkCheckSoftWareReset(void);
extern void opd_exit_from_ovl(void);
extern void MsNowMusicStop(void);
extern void MsCameraInit(void);
extern void MsBattleAllFree(void);
extern void MsEtEffectFree(void);
extern void MsBattleMemInit(void);
extern void MsEnvInit(void);
extern void MsBattleInit(void);
extern void func_001AD9C0(void);
extern void MsBattleExe(int, int, int, int);
extern void func_001540C0(int);
extern void func_002D8778(int);
extern void func_0020AE58(void);
extern void MsBtlGetTerm(void);
extern void MsSetSaveData(void);
extern void MsBattleFree(void);
extern void func_00148390(int, int, int, int);
extern int func_204B198(void);
extern void MsBattleLabelExe(int, int, int);
extern void MsEventEffectProcess(void);

typedef struct {
    u8 pad0[0x10];
    s8 f10;
    s8 f11;
    s8 f12;
    s8 f13;
    s8 f14;
    s8 f15;
    u8 pad16[0x2C - 0x16];
    s8 f2C;
    u8 pad2D[0x4A - 0x2D];
    s8 f4A;
    u8 pad4B[0x104 - 0x4B];
    u8 f104;
    u8 pad105[0x120 - 0x105];
    s16 *p120;
    u8 pad124[0x12C - 0x124];
    u8 *p12C;
    u8 pad130[0x1984 - 0x130];
    s16 f1984;
    s16 f1986;
    s8 f1988;
    s8 f1989;
    u8 pad198A[0x2010 - 0x198A];
    s32 f2010;
    s32 f2014;
    u8 pad2018[0x2030 - 0x2018];
    s32 f2030;
    s32 f2034;
    s32 f2038;
    u8 pad203C[0x2100 - 0x203C];
    s8 f2100;
    s8 f2101;
    u8 pad2102[0x2116 - 0x2102];
    s8 f2116;
    u8 pad2117[0x211A - 0x2117];
    s8 f211A;
    u8 pad211B;
    u8 f211C;
    u8 f211D;
    u8 pad211E[0x2125 - 0x211E];
    u8 f2125;
    s8 f2126;
    u8 pad2127;
    s8 f2128;
    u8 pad2129[0x2131 - 0x2129];
    s8 f2131;
} GsMain;
extern GsMain _gs_main __asm__("D_003172F0");

void func_001C8C80(void)
{
    int pad;
    int dbg;

    MsBtlReadManage();
    dbg = _d_00576479;
    if (dbg == 1) {
        func_001CB8A8(_gs_main.f2C);
    }
    if (MsBattleGetStatus() != 0) {
        if (func_0020D540() != 0) {
            MsBattleProcess();
        }
        pad = TkGetControlerHist(0, 0, 0);
        _gs_main.f2034 = pad;
        _gs_main.f2131 = MsSEP3Dprocess();
        _gs_main.f2030++;
        _gs_main.f2116 = 0;
        _gs_main.f2010 = 0;
        _gs_main.f2014 = 0;
        if (_gs_main.f2100 != 0) {
            _gs_main.f2100--;
        }
        if (_gs_main.f2101 > 0) {
            _gs_main.f2101--;
            if (_gs_main.f2101 <= 0) {
                MsMenuCloseTitleWindow(0);
            }
        }
        if (_gs_main.f2125 != 0) {
            _gs_main.f2126 = MsCheckPlyBtlPosAll();
            if (_gs_main.f2126 == 0) {
                _gs_main.f2125 = 0;
                MsResetNormalCalc();
            }
        }
        MsSEPtransProcess();
        if (func_001C90C0() != 0 && _gs_main.f10 == 1) {
            func_001CA248();
        }
        func_001CA480();
        func_001CA998();
        func_001E5FF8();
        _gs_main.f211A = MsCheckChrHitMotionAll();
        if (_gs_main.f211C != 0) {
            _gs_main.f211C--;
        }
        if (_gs_main.f211D != 0) {
            _gs_main.f211D--;
        }
        if (func_001C90C0() != 0) {
            if (_gs_main.f211C == 0) {
                func_001C9920();
            }
            if (_gs_main.f10 == 1) {
                func_001CA9D8();
            }
        }
        TOControlBtlWindow();
        func_001CAD60();
        MsLimitTypeProcess();
        MsMessageCueProcess();
        MsNumberCalcProcess();
        func_001D25E0();
        MsMotionPosCheckAll();
        MsEffectStart();
        if (TkCheckSoftWareReset() != 0 && func_001C9138() != 0) {
            _gs_main.f13 = 6;
        }
        if (_d_00576479 == 1) {
            if ((pad & 0x800) && func_001C9138() != 0) {
                volatile GsMain *gm = &_gs_main;
                register int v5 __asm__("$2") = 5;
                gm->f13 = v5;
                gm->f10 = 1;
            }
            if (_gs_main.f10 == 1 && (pad & 0x4F) == 0x4F) {
                opd_exit_from_ovl();
                MsNowMusicStop();
                MsCameraInit();
                if (pad & 0x20) {
                    MsBattleAllFree();
                    MsEtEffectFree();
                    MsBattleMemInit();
                    MsEnvInit();
                    MsBattleInit();
                    func_001AD9C0();
                }
                MsBattleExe(0, _gs_main.f1986, _gs_main.f1988, _gs_main.f1989);
                return;
            }
        }
        if (_gs_main.f10 == 0x21 || _gs_main.f13 == 5 || _gs_main.f13 == 6) {
            func_001540C0(2);
            func_002D8778(0);
            Sg_SetKeepFps(_gs_main.f2128);
            func_0020AE58();
            func_0013A278();
            MsBtlGetTerm();
            if (_gs_main.f4A == 0) {
                MsSetSaveData();
            }
            MsBattleFree();
            func_00148390(_gs_main.f104, ((*_gs_main.p120) << 16) | *_gs_main.p12C, _gs_main.f1984, _gs_main.f13);
            _gs_main.f104 = 0;
        }
        _gs_main.f2038 = _gs_main.f2034;
    } else {
        if (dbg == 1 && FFXIsDebug() != 0 && (TkGetControlerHist(0, 0, 0) & 0x4F) == 0x4F) {
            func_0020AE58();
            MsBattleLabelExe(func_204B198(), 0, 0);
        }
        if (_gs_main.f12 != 0) {
            MsBattleExe(0, _gs_main.f1986, _gs_main.f1988, _gs_main.f1989);
        }
    }
    MsEventEffectProcess();
}

/* DEBT(CAST) */
s32 func_001C90C0(void) {
    if ((D_003172F0.f2100 != 0) || (D_003172F0.f211A != 0) || (D_003172F0.f2114 >= 0) || (D_003172F0.f2074 != 0) || (D_003172F0.f14 != 0)) {
        return 0;
    }
    if (D_003172F0.f175B != 0) {
        return 0;
    }
    return ((*(s64 *)((u8 *)(&D_003172F0) + (0x2138))) & 0x0000FF00FF000000LL) ? 0 : -1;
}

int func_001C9138(void) {
    int r = 0;
    if (MsBtlReadCueLevel() == 0 && MsSEPtransAmount() == 0 && msVoiceCheckStanby(1) == 0 && D_003172F0.f10 == 1 && MsEffectCheck() == 0 && D_003172F0.f1754 == 0 && D_003172F0.f2106 == 0) {
        if (MsStoneEffectCheck() == 0) {
            r = -1;
        }
    }
    return r;
}

int MsCheckPlyBtlPosAll(void) {
    int r = 1;
    int i;
    if (MsBtlReadCueLevel() == 0) {
        r = 0;
        for (i = 0; i < 18; i++) {
            if (MsGetChr(i)->f1C8 == 0) {
                continue;
            }
            D_003172F0.f2004 |= 1 << i;
            r = 1;
            break;
        }
    }
    return r;
}

int func_001C9278(void) {
    int r = 0;
    int i = 0;
    while (i < 0x1F) {
        if (MsGetChr(i)->f1C8 != 0) {
            D_003172F0.f2138 = i;
            r = 1;
            D_003172F0.f2139 = 0xFE;
            break;
        }
        i++;
    }
    return r;
}

int MsCheckChrMotionAll(int mode) {
    int r = 0;
    int i;
    for (i = 0; i < 18; i++) {
        BtlChr *c = MsGetChr(i);
        if (c->fF2 == 0 && (c->fF6 == 0 || mode != 2)) {
            continue;
        }
        if (mode != 0) {
            D_003172F0.f2004 |= 1 << i;
        }
        r = 1;
        break;
    }
    return r;
}

void MsSetBtlTarget(int a, int b) {
    GameState *g = &D_003172F0;
    g->f1FF8 = b;
    if (g->f1FFC != b) {
        if (g->f1511 == 0 || g->f210E != 0) {
            MsSetTargetDir(a, b);
            MsSetHeadTarget(a, b);
            MsAtelRequestCamera(0, a, 0x19, 0xFFFF, 1, 1, 0, 0);
            g->f1FFC = g->f1FF8;
        }
    }
}

void MsResetBtlTarget(int a) {
    if (D_003172F0.f1511 == 0) {
        MsSetHeadTarget(a, 0);
        MsAtelRequestCamera(0, a, 0x84, 0xFFFF, 0, 1, 0, 0);
    }
    *(u32 *)&D_003172F0.f1FFC = 0xFFFFFFFF;
}

void func_001C94C0(GsEnt48 *e) {
    D_003172F0.f2116 = 1;
    D_003172F0.ent1520 = *e;
}

int MsSetBtlCommand(u8 *p, int a, int b) { /* DEBT(CAST): p is a 0x48-byte action record, byte 0 = character id */
    int r = -1;
    D_003172F0.f2127 = 0;
    if (p != 0) {
        int id = p[0];
        BtlChr *c = MsGetChr(id);
        D_003172F0.f15C0 = a;
        if (MsBtlChrNumCheck(id) != 0 && (u32)b < 2) {
            if (MsRegistCommandCue(id, p, 0, 0, b) != 0) {
                return 0;
            }
            MsDeleteInputCue(id, c->fAA4, 0, 0);
        }
    }
    return r;
}

int MsInsertBtlCommand(GsEnt48 *e, int a, int b, int c) {
    if (e != 0) {
        int id = e->id;
        BtlChr *chr = MsGetChr(id);
        if (MsBtlChrNumCheck(id) != 0 && (u32)b < 2) {
            if (MsInsertInputCue(id, a, 0, b, c, 1) != 0) {
                if (MsInsertCommandCue(id, e, 0, a, b, 0, c) != 0) {
                    return 0;
                }
                MsDeleteInputCue(id, chr->fAA4, 0, 0);
            }
        }
    }
    return -1;
}

BtlChr *_ms_MsGetMon(int id) __asm__("MsGetMon"); /* DEBT(TYPE): u2.h declares u8 parameter; orig passes int without 0xff mask */

/* DEBT(CAST): 0xA8C/0xA8E paired status bytes tested via 32-bit mask 0x00FF00FF */
int MsGetEndBattleStatus(int unused) {
    int status = 0;
    int alive = 0;
    int active = 0;
    int i;

    for (i = 0; i < 7; i++) {
        u8 id = D_003192B5[i];
        if (id != 0xFF) {
            BtlChr *c = MsGetChr(id);
            if ((s8)c->padA92[0] != 0 && (s8)c->padA92[1] != 0 && c->f290 > 0 && (*(u32 *)&c->fA8C & 0x00FF00FF) == 0) {
                alive++;
                if (c->fA88 != 0) {
                    active++;
                }
            }
        }
    }
    if (alive == 0) {
        status = 1;
    } else if (active == 0) {
        status = 3;
    } else {
        int allDead = 1;
        for (i = 0; i < 8; i++) {
            BtlChr *m = _ms_MsGetMon(i);
            if (m->fA88 != 0 && (s8)m->padA92[0] != 0 && (*(u32 *)&m->fA8C & 0x00FF00FF) == 0) {
                allDead = 0;
            }
        }
        if (allDead != 0) {
            status = (D_003172F0.pad211B[0] != 0) ? 2 : 4;
        }
    }
    if ((u8)D_003172F0.f2121 != 0) {
        status = (u8)D_003172F0.f2121;
    }
    return status;
}

void func_001C98B8(void) {
    int i;
    for (i = 0; i < 31; i++) {
        msSetEndDir(MsGetChr(i));
    }
}

void msSetEndDir(BtlChr *c) {
    c->f15C = c->f1D4[(s8)c->f1D1] + 3.1415927f;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C8C80", func_001C9920);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1C8C80/rodata", jtbl_0056E6C0);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1C8C80/rodata", jtbl_0056E740);

u8 *MsOrderCalc(int *n);
int MsRegistInputCue(int id, int a, int b, int c);
void MsLimitTypeTurnCheck(int id, BtlChr *c);

int func_001CA248(void) {
    int count;
    u8 *order;
    int i;

    if ((s8)D_003172F0.pad11[0] != 0 || D_003172F0.f1510 != 0) {
        return 0;
    }
    MsOrderInit();
    for (i = 0; i < 31; i++) {
        register BtlChr *c __asm__("$4") = MsGetChr(i);
        __asm__ volatile("" : "+r"(c));
        if (c->fAA6 == 0 && c->fA88 != 0 && c->fA8C == 0 && !((c->f2C6 >> 2) & 1) && c->f31C == 0 && (s8)c->padA96[0] != 0) {
            MsOrderRegist(i);
        }
    }
    order = MsOrderCalc(&count);
    if (count > 0) {
        if (MsRegistInputCue(*order, 0, 1, 0) != 0) {
            BtlChr *c = MsGetChr(*order);
            MsLimitTypeTurnCheck(*order, c);
        }
    } else {
        D_003172F0.pad1512[0]++;
        if ((s8)D_003172F0.pad1512[0] >= (s8)D_003172F0.pad1512[1]) {
            D_003172F0.pad1512[0] = 0;
            for (i = 0; i < 31; i++) {
                BtlChr *c = MsGetChr(i);
                if (c->fAA6 == 0 && c->fA88 != 0 && c->fA8C == 0 && !((c->f2C6 >> 2) & 1)) {
                    register int next_ctb __asm__("$3");
                    if (c->f392 < 0xFF) {
                        c->f392++;
                    }
                    next_ctb = c->f31C;
                    __asm__ volatile("" : "+r"(next_ctb));
                    next_ctb = next_ctb - 1;
                    if (next_ctb <= 0) {
                        next_ctb = 0;
                        c->fAA8 = 3;
                        if ((s8)c->padA96[0] == 0) {
                            next_ctb = c->f31D;
                        }
                    } else if ((s8)D_003172F0.pad2A[1] != 0) {
                        next_ctb = 1;
                    }
                    c->f31C = next_ctb;
                }
            }
        }
    }
    return -1;
}

int func_001CA438(BtlChr *c) {
    int r = 0;
    int v;
    if (D_003172F0.f2103 == 0 && c->fAD3 == 0 && D_003172F0.f2028 == 0) {
        v = 1;
        r = 1;
    } else {
        v = 5;
    }
    c->fAB0 = v;
    return r;
}

extern int func_001C5E90(int, int, int);
extern void MsPoisonProcess(int, BtlChr *);
extern void MsEffectFree(int);
extern void MsEffectCameraCall(int, int);
extern void MsEffectCameraEnd(int);
extern void MsScreenFocusResetAll(void);
extern void MsSetChrPosAfterSummon(int, int, int);
extern void MsReturnSummon(int);
extern void MsSetEscapeFlag(int, BtlChr *, int);
extern void MsSetEscapeFlagAll(int);
extern void MsBtlChrFree(int, int);
extern void MsMusicVolume(int, int);
extern void func_001CFBC8(int);
extern void MsCommandReturnChrStatusAll(int);
extern void MsBattleSpecialCameraFree(void);
extern void MsResetAfterImage(BtlChr *);
extern void func_001B7498(int, int);

typedef struct {
    u8 pad0[0x57];
    s8 f57;
    u8 pad58[0x1510 - 0x58];
    s8 f1510;
    s8 f1511;
    u8 pad1512[0x1753 - 0x1512];
    u8 f1753;
    u8 pad1754[0x197C - 0x1754];
    s32 f197C;
    s32 f1980;
    u8 pad1984[0x2004 - 0x1984];
    s32 f2004;
    u8 pad2008[0x200C - 0x2008];
    s32 f200C;
    u8 pad2010[0x2030 - 0x2010];
    s32 f2030;
    u8 pad2034[0x2101 - 0x2034];
    s8 f2101;
    s8 f2102;
    s8 f2103;
    u8 pad2104[0x210E - 0x2104];
    s8 f210E;
    u8 pad210F[0x2114 - 0x210F];
    s8 f2114;
    u8 pad2115[0x2118 - 0x2115];
    s8 f2118;
    s8 f2119;
    u8 pad211A[0x2125 - 0x211A];
    s8 f2125;
    u8 pad2126[0x212A - 0x2126];
    s8 f212A;
    u8 pad212B[0x2134 - 0x212B];
    s8 f2134;
    s8 f2135;
    u8 pad2136[0x213A - 0x2136];
    s8 f213A;
    u8 pad213B[0x213F - 0x213B];
    s8 f213F;
    s8 f2140;
    u8 pad2141[0x2143 - 0x2141];
    s8 f2143;
    s8 f2144;
    s8 f2145;
    s8 f2146;
} GsActEnd;
extern GsActEnd _gs_ae __asm__("D_003172F0");

void func_001CA480(void)
{
    int i;

    if (MsBtlReadCueLevel() != 0 || MsSEPtransAmount() != 0) {
        return;
    }
    for (i = 0; i < 31; i++) {
        BtlChr *c = MsGetChr(i);
        int done;
        int ret_sum;
        u8 *cmd;

        if (c->fAB0 == 0 || c->fAB0 == 4) {
            continue;
        }
        if (c->fAB0 == 5) {
            func_001CA438(c);
        } else if (((s8 *)c)[0xAB2] == 0) {
            if (c->fABB == 0 || c->fABB == 6) {
                if (_gs_ae.f2101 > 0 && _gs_ae.f2102 - 0x14 < _gs_ae.f2101) {
                    continue;
                }
                if (_gs_ae.f2144 != 0) {
                    if (func_001CB808() != 0) {
                        continue;
                    }
                    _gs_ae.f2144 = 0;
                }
                if (i == _gs_ae.f2114 && ((*(s32 *)((u8 *)c + 0xA80) >> i) & 1) && _gs_ae.f2103 != 0) {
                    continue;
                }
                while (func_001C5E90(i, -5, 0x400) != 0) {
                }
                cmd = (u8 *)MsGetChrCommand2(i);
                if (cmd[2] + 1 >= cmd[3]) {
                    MsPoisonProcess(i, c);
                }
                func_001CA438(c);
            }
        }
        if (c->fAB0 != 1) {
            continue;
        }
        done = 1;
        ret_sum = 0;
        MsEffectFree(i);
        MsMenuCloseTitleWindow(0);
        MsStructClear((s8 *)c + 0x3EC, 0x48);
        cmd = (u8 *)MsGetChrCommand2(i);
        if (cmd != 0) {
            cmd[2]++;
            if (cmd[2] < cmd[3]) {
                done = 0;
                c->fAB0 = 4;
                cmd[4] = 0;
            }
        }
        MsEffectCameraCall(-1, 0);
        MsEffectCameraEnd(1);
        if (_gs_ae.f57 == 0) {
            MsScreenFocusResetAll();
        }
        switch ((s8)(((u8 *)c)[0xAAA] - 1)) {
        case 0:
            _gs_ae.f2140 = 0;
            MsSetChrPosAfterSummon(_gs_ae.f2119, _gs_ae.f2118, 1);
            MsSetVoiceCheck(_gs_ae.f2118, 0xC, 1, 0, 0);
            break;
        case 1:
            ret_sum = 1;
            MsReturnSummon(0);
            break;
        case 2:
            MsReturnSummon(1);
            break;
        case 3:
            MsSetEscapeFlag(i, c, 1);
            break;
        case 4:
            MsSetEscapeFlagAll(1);
            break;
        case 5:
            MsBtlChrFree(i, 0xC);
            break;
        case 6:
            _gs_ae.f2125 = 1;
            break;
        }
        if (_gs_ae.f2134 != 0) {
            _gs_ae.f2134 = 0;
            MsMusicVolume(0x7F, 0x1E);
        }
        _gs_ae.f200C = 0xFF;
        _gs_ae.f2004 = 0;
        _gs_ae.f213F = 0;
        _gs_ae.f212A = 0;
        _gs_ae.f210E = 0;
        _gs_ae.f2135 = 0;
        _gs_ae.f213A = 1;
        _gs_ae.f197C = 0;
        _gs_ae.f1980 = 0;
        func_001CFBC8(i);
        MsCommandReturnChrStatusAll(-1);
        MsBattleSpecialCameraFree();
        MsResetAfterImage(c);
        ((s8 *)c)[0xACF] = 1;
        *(s16 *)((u8 *)c + 0xADA) = -1;
        ((s8 *)c)[0xAAA] = 0;
        ((s8 *)c)[0xC1E] = 0;
        ((s8 *)c)[0xAA9] = 0;
        if (*(s32 *)((u8 *)c + 0x16C) & 0x10000) {
            func_001B7498(i, 1);
        }
        if (done != 0) {
            c->fAB0 = 0;
            ((s8 *)c)[0x390] = 0;
            _gs_ae.f2145 = 0;
            ((s8 *)c)[0x110] = 0;
            MsDeleteCommandCue(i, ((u8 *)c)[0xAA5], 0);
            MsSetChrWeak(i, -1);
        }
        if (func_001CA948(i, c) != 0) {
            MsSetMotion(i, 0, 0, 0, 1, 0, 0);
        }
        Sg_Blur(0);
        {
            register int f1753 __asm__("$3") = _gs_ae.f1753;
            if (f1753 != 0 && (MsGetEndBattleStatus(0) == 0 || _gs_ae.f1510 != 0 || ret_sum != 0 || _gs_ae.f2143 != 0)) {
                _gs_ae.f2030 = 0;
                _gs_ae.f1753 = 0;
                if (_gs_ae.f1511 == 0 || _gs_ae.f2143 != 0) {
                    MsAtelRequestCamera(0, i, 0x1C, 0xFFFF, 1, 1, 0, 0);
                } else {
                    _gs_ae.f2146 = 1;
                }
            }
        }
        _gs_ae.f2143 = 0;
    }
}

int func_001CA948(int id, BtlChr *c) {
    if (c->fDC != 0 && c->fAA7 == 0 && c->f1C8 == 0 && c->fF2 == 0 && c->fDD != 0 && D_00319404 != id) {
        return 1;
    }
    return 0;
}

void func_001CA998(void) {
    int i;
    for (i = 0; i < 31; i++) {
        MsSetDeath(i, 1);
    }
}

extern char D_0056E780[];
extern int func_001DB3B8(BtlChr *);
extern void MsCheckStatusBeforeAction(int, BtlChr *);
extern int MsGetRamChrSummon(int);
extern void TOSetBtlActiveChr(int);

typedef struct {
    u8 pad0[0x14];
    s8 f14;
    u8 pad15[0x2A - 0x15];
    s8 f2A;
    u8 pad2B[0x1511 - 0x2B];
    s8 f1511;
    u8 pad1512[0x15C0 - 0x1512];
    s32 f15C0;
    u8 pad15C4[0x1FFC - 0x15C4];
    s32 f1FFC;
    u8 pad2000[0x2020 - 0x2000];
    s32 f2020;
    u8 pad2024[0x2078 - 0x2024];
    s16 f2078;
    u8 pad207A[0x2103 - 0x207A];
    s8 f2103;
    u8 pad2104[0x210F - 0x2104];
    s8 f210F;
    u8 pad2110[0x2135 - 0x2110];
    s8 f2135;
} GsInpCue;
extern GsInpCue _gs_ic __asm__("D_003172F0");

void func_001CA9D8(void)
{
    GsEnt48 ent;

    if (_gs_ic.f2135 != 0) {
        return;
    }
    while (1) {
        u8 *cue = (u8 *)MsGetInputCue();
        int id;
        BtlChr *c;
        int st;
        int need_menu;

        if (cue == 0 || cue[3] != 0) {
            break;
        }
        id = cue[0];
        if (MsBtlChrNumCheck(id) != 0) {
            c = MsGetChr(id);
            st = func_001DB3B8(c);
            if (st == 2) {
                if (_gs_ic.f1511 != 0) {
                    break;
                }
            } else if (st == 1) {
                if (_gs_ic.f2103 != 0) {
                    break;
                }
            }
            MsCheckStatusBeforeAction(id, c);
            cue = (u8 *)MsGetInputCue();
            if (cue == 0 || cue[3] != 0) {
                break;
            }
            if (c->fA8C == 0 && MsGetEndBattleStatus(0) == 0) {
                _gs_ic.f15C0 = 0;
                _gs_ic.f2020 = 0;
                _gs_ic.f1FFC = 0;
                _gs_ic.f210F = id;
                _gs_ic.f2078 = 0;
                if (_gs_ic.f1511 == 0) {
                    MsAtelRequestCamera(0, id, 0x3E, 0xFFFF, 0, 1, 0, 0);
                }
                if (((s8 *)c)[0xAB7] == 0) {
                    ((s8 *)c)[0xAB7] = 1;
                    MsActionRequest(id, 0xFF, 1, 0, 2, 0);
                    if (MsGetRamChrSummon(id) != 0) {
                        MsActionRequest(id, 0xFF, 0xC, 1, 2, 0);
                    }
                }
                if (_gs_ic.f14 != 0) {
                    break;
                }
                cue[3] = 1;
                c->fAA4 = 0;
                ((s8 *)c)[0xAB7] = 0;
                need_menu = 1;
                if (MsSetDeathSentence(id, c, &ent, cue[1]) != 0) {
                    need_menu = 0;
                } else if (((u8 *)c)[0x2C8] != 0) {
                    ent.id = id;
                    ent.f3 = 0;
                    MsSetBtlCommand((u8 *)&ent, 0, cue[1]);
                    need_menu = 0;
                } else if ((c->f2C6 >> 10) & 1) {
                    if (MsSetProvokingCommand(id, c, &ent, cue[1]) != 0) {
                        need_menu = 0;
                    }
                } else if ((c->f2C6 >> 9) & 1) {
                    MsSetBerserkCommand(id, c, &ent, cue[1], 0);
                    need_menu = 0;
                } else if ((c->f2C6 >> 8) & 1) {
                    MsSetBerserkCommand(id, c, &ent, cue[1], 1);
                    need_menu = 0;
                }
                if (need_menu != 0) {
                    if (func_001CACF8(id, c) == 0 || _gs_ic.f2A != 0) {
                        TOSetBtlActiveChr(id);
                    } else {
                        ent.id = id;
                        ent.f3 = 0;
                        MsSetBtlCommand((u8 *)&ent, 0, cue[1]);
                    }
                }
                c->f3D6 = 0;
            } else {
                MsDeleteInputCue(id, 0, 0, 0);
            }
        } else {
            MsDeleteInputCue(id, 0, 0, 0);
            MsBattleError(D_0056E780);
        }
    }
}

int func_001CACF8(int kind, BtlChr *c) {
    s8 r = c->fAB3;
    int v;
    if (kind == 0xE) {
        v = MsGetYoujinbouCom() / 4;
        if ((u8)brnd(0x11) < v) {
            r = 1;
        }
    }
    return r;
}

extern char D_0056E790[];
extern int MsSystemMessageCheck(void);
extern int MsDefenseProcess(void);
extern int func_001DBB50(BtlChr *);
extern int MsSetRikkuLimit(int, BtlChr *, GsEnt48 *);
extern int MsCheckRikkuLimit(int, BtlChr *, GsEnt48 *);
extern void func_001D9E70(int);
extern void func_001B8728(void);
extern int MsCheckSummon(int, BtlChr *, int, GsEnt48 *);
extern int MsCalcMagic(GsEnt48 *, int);
extern void MsActionTarget(int, int, GsEnt48 *, int, int, int);
extern void MsCalcCommand(GsEnt48 *, int);
extern void MsDefenseStartProcess(void);
extern void MsMessageCueRegist(int, int, int, int, int);
extern int func_001D9DF0(int);
extern void func_001D9D68(int, int);
extern void func_001DBB30(BtlChr *);
extern void MsParseCommand(GsEnt48 *);
extern int func_001CB4E0(int);
extern int func_001CB560(int, GsEnt48 *, int, int *);
extern int MsSetChrMimic(int, BtlChr *, GsEnt48 *);
extern int func_001CB888(int, Q4Obj176 *);
extern int SndGetStreamState(void);
extern int MsAutoCommandStatusCheck(BtlChr *, int, int, int);
extern void msResetHeadTarget(BtlChr *);
extern int MsUseItem(int, GsEnt48 *, int);

typedef struct {
    u8 pad0[0x15C0];
    s32 f15C0;
    u8 pad15C4[0x1753 - 0x15C4];
    s8 f1753;
    u8 pad1754[0x1FF8 - 0x1754];
    s32 f1FF8;
    u8 pad1FFC[0x2074 - 0x1FFC];
    u8 f2074;
    u8 pad2075[0x2104 - 0x2075];
    s8 f2104;
    u8 pad2105[0x210F - 0x2105];
    s8 f210F;
    s8 f2110;
    s8 f2111;
    s8 f2112;
    u8 pad2113[0x2125 - 0x2113];
    u8 f2125;
    u8 pad2126[0x212B - 0x2126];
    s8 f212B;
    u8 pad212C[0x2138 - 0x212C];
    s64 f2138;
    u8 pad2140[0x2146 - 0x2140];
    u8 f2146;
} GsCmdProc;
typedef struct {
    u8 pad0[0x1753];
    s8 f1753;
    u8 pad1754[0x210F - 0x1754];
    s8 f210F;
    s8 f2110;
    s8 f2111;
    s8 f2112;
    u8 pad2113[0x213A - 0x2113];
    s8 f213A;
    u8 pad213B[0x213F - 0x213B];
    s8 f213F;
    u8 pad2140[0x2146 - 0x2140];
    u8 f2146;
} GsCmdProc2;
extern GsCmdProc _gs_cp __asm__("D_003172F0");
extern GsCmdProc2 _gs_cp2 __asm__("D_003172F0");

int func_001CAD60(void)
{
    int far_cnt;
    int ret = 0;
    int ok;

    if (_gs_cp.f2125 != 0 || _gs_cp.f2104 != 0 || (_gs_cp.f2138 & 0x0000FF00FF000000LL) || _gs_cp.f2074 != 0 || SndGetStreamState() != 0 || MsSystemMessageCheck() != 0) {
        return 0;
    }
    while (1) {
        GsEnt48 *e = (GsEnt48 *)func_001D92A0();
        int id;
        BtlChr *c;
        int kind;

        if (e == 0 || ((u8 *)e)[4] == 1) {
            break;
        }
        id = e->id;
        c = MsGetChr(id);
        if (((s8 *)c)[0xF3] != 0 || ((s8 *)c)[0x1CE] != 0) {
            break;
        }
        kind = ((u8 *)e)[1];
        if (MsBtlChrNumCheck(id) != 0 && (u32)kind < 2) {
            ok = 1;
            switch (((u8 *)e)[4]) {
            case 2:
                if (func_001CB4E0(_gs_cp.f1FF8) == 0) {
                    ((u8 *)e)[4] = 1;
                    c->fAB0 = 3;
                }
                break;
            case 3:
                if (MsDefenseProcess() != 0) {
                    _gs_cp.f212B = 2;
                    ((u8 *)e)[4] = 1;
                    *(s32 *)((u8 *)c + 0xA80) = e->f8[((u8 *)e)[2]].targets;
                    c->fAB0 = 3;
                }
                break;
                case 6:
                    if (func_001DBB50(c) != 0) {
                        ((u8 *)e)[4] = 1;
                        c->fAB0 = 3;
                        ((s8 *)c)[0x3A0] = 0;
                    }
                    break;
                case 4:
                    if (c->f1C8 != 0 || c->fF6 != 0) {
                        break;
                    }
                    *(s32 *)((u8 *)c + 0xA80) = 0;
                    ((s8 *)c)[0xF5] = 1;
                    MsSetMotion(id, 0x1D, 1, 0, 1, 0, 0);
                    MsAtelRequestCamera(0, id, 0x46, 0xFFFF, 0, 1, 0, 0);
                    ((u8 *)e)[4] = 5;
                    /* fallthrough */
                case 5:
                    if (MsSetRikkuLimit(id, c, e) != 0) {
                        break;
                    }
                    /* fallthrough */
                default:
                    if (MsCheckRikkuLimit(id, c, e) != 0) {
                        break;
                    }
                    if (id == 5 && ((int (*)(int, BtlChr *, GsEnt48 *))func_001CB888)(5, c, e) != 0) {
                        break;
                    }
                    if (_gs_cp2.f2146 != 0) {
                        MsAtelRequestCamera(0, id, 0x1C, 0xFFFF, 1, 1, 0, 0);
                        _gs_cp2.f2146 = 0;
                    }
                    ret = 1;
                    {
                        int sub = 0;
                        int targets = 0;
                        int mimic_fail = MsSetChrMimic(id, c, e);

                        ((u8 *)e)[4] = ret;
                        ((u8 *)e)[5] = 0;
                        ((u8 *)c)[0xAA5] = 0;
                        c->fAB0 = 2;
                        ((s8 *)c)[0xAA9] = ret;
                        ((s8 *)c)[0xAB1] = kind;
                        {
                            volatile GsCmdProc2 *gp = &_gs_cp2;
                            gp->f213A = 0;
                            gp->f213F = ret;
                            gp->f1753 = ret;
                            gp->f210F = id;
                            gp->f2110 = id;
                            gp->f2112 = id;
                        }
                        far_cnt = 0;
                        msResetHeadTarget(c);
                        func_001D9E70(id);
                        func_001B8728();
                        if (((u8 *)c)[0x2C8] == 0) {
                            if (MsCheckSummon(id, c, kind, e) != 0) {
                                if (e->f3 == 0) {
                                    ((s8 *)c)[0xAB4] = ret;
                                    if (kind == 0) {
                                        MsActionRequest(id, 0xFF, 0, 1, 0, (void *)e);
                                    } else {
                                        MsActionRequest(id, 0xFF, 3, 1, kind, (void *)e);
                                    }
                                } else if (((u8 *)e)[2] == 0) {
                                    ((s8 *)c)[0xAB4] = 0;
                                }
                            }
                            sub = ((u8 *)e)[2];
                            targets = e->f8[sub].targets;
                            _gs_cp.f1FF8 = targets;
                        }
                        if (((u8 *)e)[7] == 0x30 && MsAutoCommandStatusCheck(c, 1, 1, 1) == 0) {
                            targets = 0;
                            e->f8[sub].targets = 0;
                        }
                        ok = 0;
                        ((u8 *)c)[0xAAA] = ((u8 *)e)[6];
                        if (mimic_fail == 0 && e->f3 != 0 && MsCalcMagic(e, sub) != 0) {
                            *(s32 *)((u8 *)c + 0xA80) = targets;
                            MsActionTarget(targets, id, e, sub, 2, 1);
                            if (func_001CB560(id, e, sub, &far_cnt) != 0) {
                                *(s32 *)((u8 *)c + 0xA84) = *(s32 *)((u8 *)c + 0xA80);
                                MsCalcCommand(e, sub);
                                {
                                    register int tgt __asm__("$3") = *(s32 *)((u8 *)c + 0xA80);
                                    if (tgt == 0 || e->f8[sub].targets != 0) {
                                        c->fAB0 = 3;
                                        MsPayGIL(_gs_cp.f15C0);
                                        if (func_001CB4E0(targets) != 0) {
                                            c->fAB0 = 4;
                                            ((u8 *)e)[4] = 2;
                                        }
                                        if (_gs_cp.f212B != 0) {
                                            MsDefenseStartProcess();
                                            c->fAB0 = 4;
                                            ((u8 *)e)[4] = 3;
                                        }
                                        ok = 1;
                                    }
                                }
                            }
                        }
                        if (ok == 0) {
                            if (mimic_fail != 0) {
                                MsMessageCueRegist(1, id, 0x3016, 0x1B, 0x23);
                            } else {
                                int retry = 0;

                                MsUseItem(id, e, 1);
                                if (far_cnt != 0 && ((s8 *)c)[0xAB4] == 0) {
                                    retry = 1;
                                    MsMessageCueRegist(1, id, 0x300E, 0x1B, 0x23);
                                } else if (((u8 *)c)[0x3D7] != 0) {
                                    retry = 0;
                                    MsMessageCueRegist(1, id, 0x3017, 0x1B, 0x23);
                                    MsSetMotion(id, 0x22, 1, 1, 1, 0, 0);
                                }
                                if (retry != 0 && func_001D9DF0(id) != 0) {
                                    _gs_cp2.f213F = 0;
                                    c->fAB0 = 0;
                                    c->f3D6 = 1;
                                    func_001D9D68(id, 0);
                                    MsDeleteCommandCue(id, ((u8 *)c)[0xAA5], 0);
                                }
                            }
                            ((s8 *)c)[0x38C] = 0;
                            ((s8 *)c)[0x38D] = 0;
                            ((s8 *)c)[0xAB2] = 0;
                        }
                        if (((u8 *)c)[0x3A0] != 0) {
                            func_001DBB30(c);
                            c->fAB0 = 4;
                            ((u8 *)e)[4] = 6;
                        }
                    }
                    break;
                }
                if (((u8 *)e)[4] == 1 && ok != 0) {
                    *(GsEnt48 *)((u8 *)c + 0x3EC) = *e;
                    MsParseCommand(e);
                }
                break;
            } else {
                MsDeleteInputCue(id, c->fAA4, 0, 0);
                MsDeleteCommandCue(id, 0, 0);
                MsBattleError(D_0056E790);
            }
    }
    return ret;
}

int func_001CB4E0(int mask) {
    int i;
    int n = 0;
    for (i = 0; i < 0x1F; i++) {
        if ((mask >> i) & 1) {
            BtlChr *c = MsGetChr(i);
            if (c->fCB != 0) {
                if (c->fCA != 0) {
                    n++;
                }
            }
        }
    }
    return n;
}

extern int MsAutoCommandStatusCheck(BtlChr *, int, int, int);
extern void msResetHeadTarget(BtlChr *);

int func_001CB560(int id, GsEnt48 *e, int idx, int *out_far)
{
    int ret = -1;
    int mask = 0;
    int far_cnt = 0;
    int targets;
    int allow_dead;
    int bit27;
    OfsTbl *cmd;

    targets = e->f8[idx].targets;
    cmd = (OfsTbl *)MsGetCommand(id, 0, -1, (void *)&e->f8[idx], 0);

    if (cmd != 0) {
        int far;
        int i;

        bit27 = (*(u32 *)((u8 *)cmd + 0x1C) >> 27) & 1;
        allow_dead = (cmd->h1A >> 6) & 1;
        far = MsGetCommandFar(id, (Obj1A *)cmd);

        for (i = 0; i < 31; i++) {
            BtlChr *c = MsGetChr(i);

            if ((targets >> i) & 1) {
                int skip = 0;

                if (far < ((s8 *)c)[0x1BF] && id != i) {
                    skip = 1;
                    far_cnt++;
                } else if (!allow_dead && c->fA8C != 0) {
                    skip = 2;
                }
                if (skip == 0) {
                    ((s8 *)c)[0xAAD] = id;
                    mask |= 1 << i;
                    MsSetMotion(((s8 *)c)[0xE2], 0x1C, 0, 0, 1, 0, 0);
                    if (id != i && c->fA8C == 0 && MsAutoCommandStatusCheck(c, 1, 1, 1) != 0) {
                        if (bit27 != 0) {
                            msResetHeadTarget(c);
                        } else {
                            MsSetHeadTarget(i, 1 << id);
                        }
                    }
                }
            }
        }
        if (((u8 *)cmd)[0x2B] != 0 || ((*(u32 *)((u8 *)cmd + 0x1C) >> 9) & 1) || ((*(u16 *)((u8 *)cmd + 0x20) >> 8) & 1)) {
            if (mask == 0) {
                ret = 0;
            }
        }
    }
    if (out_far != 0) {
        *out_far = far_cnt;
    }
    e->f8[idx].targets = mask;
    D_003172F0.f1FF8 = mask;
    return ret;
}

void func_001CB798(void) {
}

void *_m2c_func_001CB7A0_MsGetChr() __asm__("MsGetChr");
s32 _m2c_func_001CB7A0_func_002EC198(s32, s32) __asm__("func_002EC198");
s32 _m2c_func_001CB7A0_func_002ED038(float) __asm__("func_002ED038");
extern s8 _m2c_func_001CB7A0_D_0031942F __asm__("D_0031942F");
/* DEBT(CAST) */ /* DEBT(GOTO) */
s8 func_001CB7A0(s32 arg0) {
    s8 var_16;
    s8 var_2;
    void *temp_2;

    var_16 = _m2c_func_001CB7A0_D_0031942F;
    if (arg0 != 0xFF) {
        temp_2 = _m2c_func_001CB7A0_MsGetChr(arg0);
        if (((*(s8 *)((u8 *)(temp_2) + (0x15))) == 0) || (var_2 = var_16, (_m2c_func_001CB7A0_func_002EC198(_m2c_func_001CB7A0_func_002ED038((*(float *)((u8 *)(temp_2) + (0x40)))), 0) == 0))) {
            var_16 = 0;
            goto block_4;
        }
    } else {
block_4:
        var_2 = var_16;
    }
    return var_2;
}

int func_001CB808(void) {
    int r = 0;
    int i = 0;
    while (i < 3) {
        u8 id = D_003192B5[i];
        i++;
        if (id == 0xFF) continue;
        if (MsGetChr(id)->fF6 != 0) {
            r = -1;
            break;
        }
    }
    return r;
}

int func_001CB888(int a, Q4Obj176 *p) {
    return p->f176 != 0;
}

void MsDebugCameraSleepInit(void) {
    D_00662610 = -1;
}

void func_001CB8A8(int v) {
    int i;
    int j;
    if (D_00662610 != v) {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 4; j++) {
                D_00314840[i].slot[j].b5 = v & 1;
            }
        }
        D_00662610 = v;
    }
}

extern char D_0056E7B8[];
extern char D_0056E7D8[];
extern char D_0056E7F0[];
extern char D_0056E800[];
extern char D_0056E818[];
extern char D_0056E830[];
extern char D_0056E848[];
extern char D_0056E858[];
extern char D_0056E870[];
extern char D_0056E890[];
int MsGetYoujinbouCom(void);
int MsGetSummonEnergy(int id);
int MsCheckStartEffect(int a, int b);
int func_002D6730(void);
int SndGetStreamState(void);
int func_002D87A0(void);
int func_002D87D8(void);

typedef struct {
    u8 pad0[0x10];
    s8 f10;
    u8 pad11[3];
    s8 f14;
    s8 f15;
    u8 pad16[0x197C - 0x16];
    s32 f197C;
    s32 f1980;
    u8 pad1984[6];
    char f198A[0x200C - 0x198A];
    s32 f200C;
    u8 pad2010[0x201C - 0x2010];
    s32 f201C;
    u8 pad2020[0x202C - 0x2020];
    s32 f202C;
    u8 pad2030[0x2106 - 0x2030];
    s8 f2106;
    u8 pad2107[0x2110 - 0x2107];
    u8 f2110;
    u8 pad2111[0x2117 - 0x2111];
    s8 f2117;
    u8 pad2118[0x2131 - 0x2118];
    s8 f2131;
    u8 pad2132[0x2138 - 0x2132];
    s8 f2138;
    u8 f2139;
} GsBtlProc;
extern GsBtlProc _gs_bp __asm__("D_003172F0"); /* DEBT(TYPE): local view of D_003172F0 */

extern void _void_TODapsString(char *) __asm__("TODapsString"); /* DEBT(TYPE): funcs.h declares int */

void MsBattleProcess(void)
{
    char buf[0x40];
    int line = 0;

    func_002F0008(buf, D_0056E7B8, _gs_bp.f10, MsBtlReadCueLevel(), GetCD()->f8(1), MsSEPtransCheckWave(), TkSndReportStatus(), MsGetEndBattleStatus(0));
    TODapsSetPos(0xBC, line * 13 + 8);
    _void_TODapsString(buf);
    TODapsSetPos(0x188, line++ * 13 + 8);
    _void_TODapsString(_gs_bp.f198A);
    func_002F0008(buf, D_0056E7D8, func_002D87A0(), func_002D87D8(), _gs_bp.f2131);
    TODapsSetPos(0xEC, line++ * 13 + 8);
    _void_TODapsString(buf);
    func_002F0008(buf, D_0056E7F0, _gs_bp.f197C, _gs_bp.f1980);
    TODapsSetPos(0x140, line++ * 13 + 8);
    _void_TODapsString(buf);
    if (_gs_bp.f2117 != 0) {
        func_002F0008(buf, D_0056E800, MsGetYoujinbouCom(), MsGetSummonEnergy(0xF), MsGetSummonEnergy(0x10), MsGetSummonEnergy(0x11));
        TODapsSetPos(0x110, line++ * 13 + 8);
        _void_TODapsString(buf);
    }
    if (_gs_bp.f200C != 0xFF) {
        u8 c = _gs_bp.f2110;
        func_002F0008(buf, D_0056E818, c, _gs_bp.f200C, MsGetMotionNum(c));
        TODapsSetPos(0xC8, line * 13 + 8);
        _void_TODapsString(buf);
    }
    func_002F0008(buf, D_0056E830, _gs_bp.f14, _gs_bp.f15, _gs_bp.f2138, _gs_bp.f2139);
    TODapsSetPos(0x164, line++ * 13 + 8);
    _void_TODapsString(buf);
    if (_gs_bp.f201C >= 0) {
        BtlChr *c = MsGetChr(_gs_bp.f2110);
        int y;

        func_002F0008(buf, D_0056E848, c->fABB, _gs_bp.f201C);
        y = line++ * 13 + 8;
        TODapsSetPos(0x104, y);
        _void_TODapsString(buf);
        func_002F0008(buf, D_0056E858, MsCheckChrMotionAll(0), c->f1C8, c->fF6, c->fF2, ((u8 *)c)[0xD2]);
        TODapsSetPos(0x158, y);
        _void_TODapsString(buf);
        func_002F0008(buf, D_0056E870, c->fABD, MsCheckStartEffect(((u8 *)c)[0xC], *(s32 *)((u8 *)c + 0xA80)), _gs_bp.f2106, func_002D6730(), SndGetStreamState());
        TODapsSetPos(0x110, line++ * 13 + 8);
        _void_TODapsString(buf);
    }
    if (_gs_bp.f202C >= 0) {
        _gs_bp.f202C++;
        func_002F0008(buf, D_0056E890, _gs_bp.f202C);
        TODapsSetPos(0x1C4, line * 13 + 8);
        _void_TODapsString(buf);
    }
}

int MsSetBerserkCommand(int id, BtlChr *c, GsEnt48 *e, int arg, int mode) {
    int r = 0;
    int k;
    int cmd;
    int t;
    if (e != 0) {
        k = c->f386;
        t = MsGetCommandTarget(id, k, mode, 1);
        if (k != 0 && t > 0) {
            cmd = k;
            r = -1;
        } else {
            r = -2;
            cmd = 0xFF;
            t = 0;
        }
        e->id = id;
        e->f3 = 1;
        e->f8[0].h0 = cmd;
        e->f8[0].h2 = 0xFF;
        e->f8[0].targets = t;
        MsSetBtlCommand((u8 *)e, 0, arg);
    }
    return r;
}

int MsSetProvokingCommand(int id, BtlChr *c, GsEnt48 *e, int arg) {
    int r = 0;

    if (e != 0) {
        int prov_id = c->f284;
        register int k __asm__("$20") = c->f386;
        register int cmd __asm__("$7");
        BtlChr *prov = MsGetChr(prov_id);
        if (prov->fA88 == 0 || (*(int *)&prov->fA8C & 0x00FF00FF) != 0) {
            c->f2C6 &= 0xFBFF;
            return 0;
        }
        if (c->f28B != 0) {
            return 0;
        }
        {
            register int kind __asm__("$17") = -15;
            register OfsTbl *t __asm__("$16");
            int mask;
            if (MsGetRamChrMonster(prov_id) == 0) {
                kind = -14;
            }
            t = MsGetComData(k, 0);
            mask = MsGetCursorTarget(id, kind, t, k, 1);
            if ((mask >> prov_id) & 1) {
                switch ((t->h1A >> 2) & 3) {
                case 0:
                case 3:
                    mask = 1 << prov_id;
                    break;
                case 1:
                    {
                        int i;
                        int grp = MsGetChrGroup(prov_id);
                        for (i = 0; i < 31; i++) {
                            if ((mask >> i) & 1) {
                                if (MsGetChrGroup(i) != grp) {
                                    mask &= ~(1 << i);
                                }
                            }
                        }
                    }
                    break;
                case 2:
                    break;
                default:
                    mask = 0;
                    break;
                }
            } else {
                mask = 0;
            }
            if (k != 0 && mask > 0) {
                cmd = k;
                __asm__ volatile("" : "+r"(cmd));
                r = -1;
            } else {
                r = -2;
                cmd = 0xFF;
                mask = 0;
            }
            e->id = id;
            e->f8[0].targets = mask;
            e->f3 = 1;
            e->f8[0].h0 = cmd;
            e->f8[0].h2 = 0xFF;
            MsSetBtlCommand((u8 *)e, 0, arg);
        }
    }
    return r;
}

int MsGetCommandTarget(int id, int k, int mode, int arg) {
    OfsTbl *t = MsGetComData(k, 0);
    int r;
    int out;

    if (mode < 0) {
        mode = ((t->h1A >> 1) & 1) ^ 1;
    }
    if (MsGetRamChrMonster(id) == 0) {
        r = (u8)mode ? -14 : -15;
    } else {
        r = (u8)mode ? -15 : -14;
    }
    r = MsGetCursorTarget(id, r, t, k, arg);
    switch ((t->h1A >> 2) & 3) {
    case 0:
        if (r != 0) {
            MsActTargetSearch(id, r, 0x5C, 0, 4, 0, 1, &out);
            r = 1 << out;
        }
        break;
    case 1:
        r = func_001CC7E8(r);
        break;
    case 2:
        break;
    case 3:
        r = 1 << id;
        break;
    }
    return r;
}

int MsGetCursorTarget(int id, int kind, OfsTbl *t, int k, int arg) {
    int mask;
    int i;
    int fail;
    int far;

    mask = MsGetChrBit(id, kind, 0, 1);
    for (i = 0; i < 31; i++) {
        if ((mask >> i) & 1) {
            fail = 0;
            if (MsGetChrCursorFlag(i) == 0) {
                fail = 1;
            }
            switch (MsGetChrEventFlag(i, k)) {
            case 1:
                if (!((t->h1A >> 11) & 1)) {
                    fail = 1;
                }
                break;
            case 0:
                if (!((t->h1A >> 10) & 1)) {
                    fail = 1;
                }
                break;
            case 2:
                fail = 1;
                break;
            }
            far = MsGetCommandFar(id, (Obj1A *)t);
            if (far < MsGetChrDist(i)) {
                if (id != i) {
                    fail = 1;
                }
            }
            if (MsGetChrStatDeath(i) != 0) {
                if (!((t->h1A >> 6) & 1)) {
                    fail = 1;
                }
            }
            if (fail != 0) {
                mask &= ~(1 << i);
            }
        }
    }
    return mask;
}

int MsSetDeathSentence(int id, BtlChr *c, GsEnt48 *e, int arg) {
    int r = 0;
    if ((c->f2D6 >> 14) & 1) {
        if (c->f3D6 == 0 && e != 0) {
            if (c->f288 == 0 || --c->f288 == 0) {
                r = 1;
                e->f8[0].h0 = 0x3120;
                e->f8[0].h2 = 0xFF;
                e->f8[0].targets = 1 << id;
                e->id = id;
                e->f3 = 1;
                MsSetBtlCommand((u8 *)e, 0, arg); /* DEBT(CAST): see MsSetBtlCommand */
            }
        }
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C8C80", MsSetChrMimic);

int func_001CC648(int mask, OfsTbl *command)
{
    int result;
    int valid = 0;
    int selected = 0;
    int i = 0;
    int allow_dead = (command->h1A >> 6) & 1;

    result = 1;
    for (; i < 31; i++) {
        if ((mask >> i) & 1) {
            BtlChr *c;

            selected++;
            c = MsGetChr(i);
            if (c->fA88 && c->fA99) {
                if (!MsGetChrStatDeath(i) || allow_dead) {
                    valid++;
                }
            }
        }
    }
    if (selected > 0 && valid >= selected) {
        result = 0;
    }
    return result;
}

int func_001CC728(int a, int mask) {
    int r = 1;
    int i;
    for (i = 0; i < 31; i++) {
        if ((mask >> i) & 1) {
            if (MsGetRamChrMonster(a) != MsGetRamChrMonster(i)) {
                r = 0;
            }
            break;
        }
    }
    return r;
}

void func_001CC798(void) {
    MsStructClear(D_00318858, 0x48);
}

int MsGetCommandFar(int a, Obj1A *p) {
    int m = (p->f1A >> 7) & 3;
    if ((p->f1A >> 9) & 1) {
        if (a == 4 || a == 8 || a == 13) {
            m = 3;
        }
    }
    return m;
}

s32 func_001CC7E8(s32 r) {
    u8 sp[8];
    u8 *p;
    s32 i;
    s32 cnt;
    s32 rnd;
    s32 acc;
    s32 ret;

    p = &sp[7];
    for (i = 7; i >= 0; i--) {
        *p = 0;
        p--;
    }
    for (i = 0; i < 31; i++) {
        if ((r >> i) & 1) {
            sp[MsGetChrGroup(i)]++;
        }
    }
    cnt = 0;
    for (i = 0; i < 8; i++) {
        if (sp[i] != 0) {
            cnt++;
        }
    }
    ret = 0;
    if (cnt != 0) {
        rnd = brnd(5) % cnt;
        acc = 0;
        cnt = rnd;
        for (i = 0; i < 8; i++) {
            if (sp[i] != 0) {
                acc++;
                if (acc > rnd) {
                    cnt = i;
                    break;
                }
            }
        }
        for (i = 0; i < 31; i++) {
            if (((r >> i) & 1) && (MsGetChrGroup(i) == cnt)) {
                ret |= 1 << i;
            }
        }
    }
    return ret;
}

/* DEBT(FAKE) */ /* DEBT(GOTO) */
s32 MsGetCommandTarget2(s32 id, s32 a, s32 b, s32 c) {
    OfsTbl *temp_18;
    s32 var_16;
    register s32 var_2 __asm__("$2");
    register s32 var_5 __asm__("$5");
    s32 var_5_2;
    s32 var_5_3;
    s32 temp_ret;
    s32 cond;

    var_16 = b;
    temp_18 = MsGetComData(a, 0);
    if (var_16 >= 0) {
        var_5_2 = var_16 & 0xFF;
        if (var_16 & 0x200) {

        } else {
            goto block_4;
        }
    } else {
        var_16 = (((u16) temp_18->h1A >> 1) & 1) ^ 1;
block_4:
        temp_ret = MsGetRamChrMonster(id);
        cond = var_16 & 0xFF;
        if (temp_ret == 0) {
            var_5_3 = -0xF;
            var_2 = -0xE;
        } else {
            var_5_3 = -0xE;
            var_2 = -0xF;
        }
        var_5_2 = cond ? var_2 : var_5_3;
    }
    var_5 = MsGetCursorTarget(id, var_5_2, temp_18, a, c);
    if ((var_16 >= 0) && (var_16 & 0x100)) {
        var_5 &= ~(1 << id);
    }
    return var_5;
}

int func_001CCA60(int a, int b, int mask, int k) {
    OfsTbl *t = MsGetComData(k, 0);
    int r;
    int v;
    int i;

    switch ((t->h1A >> 2) & 3) {
    case 0:
        break;
    case 2:
        mask = b;
        break;
    case 1:
        r = mask;
        v = -1;
        for (i = 0; i < 31; i++) {
            if ((mask >> i) & 1) {
                v = MsGetChrGroup(i);
                break;
            }
        }
        for (i = 0; i < 31; i++) {
            if ((b >> i) & 1) {
                if (v == MsGetChrGroup(i)) {
                    r |= 1 << i;
                }
            }
        }
        mask = r;
        break;
    case 3:
        mask = 1 << a;
        break;
    }
    return mask;
}

void MsStructClear(s8 *arg0, s32 arg1) {
    s32 var_5;
    s8 *var_4;

    var_4 = arg0;
    var_5 = arg1;
    if (var_5 > 0) {
        do {
            *var_4 = 0;
            var_5 -= 1;
            var_4 += 1;
        } while (var_5 != 0);
    }
}

void MsStructFill(u16 *p, int n, int v) {
    int i;
    for (i = 0; i < n / 2; i++) {
        *p++ = v;
    }
}

void MsBattleError(char *name) {
    while (1) {
    }
}
