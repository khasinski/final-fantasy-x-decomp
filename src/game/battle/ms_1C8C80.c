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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C8C80", func_001C8C80);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C8C80", MsGetEndBattleStatus);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C8C80", func_001CA480);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1C8C80/rodata", jtbl_0056E760);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C8C80", func_001CA9D8);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C8C80", func_001CAD60);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1C8C80/rodata", jtbl_0056E7A0);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C8C80", func_001CB560);

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
