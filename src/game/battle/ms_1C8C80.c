/* tu_195 0x1c8c80-0x1ccc10: low; ~Ms (config/tu_map.tsv) */
#define MsStructClear _hdr_MsStructClear
#define func_001CB7A0 _hdr_func_001CB7A0
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/v3.h"
#include "ffx/u2.h"
#include "ffx/g2.h"
#undef func_001CB7A0
#undef MsStructClear

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C8C80", func_001C8C80);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C8C80", func_001C90C0);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C8C80", MsInsertBtlCommand);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C8C80", func_001CA248);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C8C80", MsBattleProcess);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C8C80", MsSetBerserkCommand);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C8C80", MsSetProvokingCommand);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C8C80", MsGetCursorTarget);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C8C80", func_001CC648);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C8C80", func_001CC7E8);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C8C80", MsGetCommandTarget2);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C8C80", MsBattleError);
