/* tu_179 0x1acfd8-0x1af9e8: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q4.h"
#include "ffx/s2.h"
#include "ffx/v2.h"
#include "ffx/u2.h"
#include "ffx/g2.h"

void MsBattleMemInit(void) {
    D_0065FF40 = 0;
    MsStructClear(&D_003172F0, 0x2148);
    MsEtEffectReadInit();
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1ACFD8", MsSetCountryName);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1ACFD8/rodata", jtbl_0056E000);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1ACFD8", MsDebugInfoRead);

void MsEnvInit(void)
{
    char buf[0x80];

    if (FFXIsDebug()) {
        ((int (*)(void *))MsSetCountryName)(D_00319438); /* DEBT(TYPE): funcs.h declares MsSetCountryName void; it returns int */
        if (D_00317316 == 1) {
            func_002F0008(buf, D_0056E048, D_00319438);
            S2_PcFileTblSet(buf, 0xD);
        } else if (D_00317316 == 2) {
            func_002F0008(buf, D_0056E078, D_00319438);
            S2_PcFileTblSet(buf, 0xD);
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1ACFD8", MsBattleInit);

void func_001AD9C0(void) {
    MsEtEffectRead();
}

void func_001AD9C8(int a) {
    if (a != 0) {
        D_003172F0.f104 = 0;
        D_003172F0.f105 = 0;
    }
    D_003172F0.w108 = 0;
    D_003172F0.w10C = 0;
    D_003172F0.f110 = 1.0f;
    D_003172F0.f114 = 1.0f;
}

s8 func_001ADA00(void) {
    return D_003193EE;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1ACFD8", func_001ADA10);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1ACFD8", MsFldGetScene);

void MsBattleInitAtEvent(int a) {
    D_003172F0.f118 = 0;
    D_003172F0.f11C = 3.0f;
    MsEventEffectInit();
    func_001AD9C8(1);
    func_001ADA10(a, 0);
}

void MsBattleDisposeAtEvent(void) {
}

void func_001ADC50(int a) {
    func_001AD9C8(0);
    func_001ADA10(a, 0);
}

/* DEBT(CAST): the allocator accepts resident-table pointers as integer handles. */
void MsBattleAllFree(void)
{
    MsBattleFree();
    func_001ADEA8(0);
    func_001DBCB8(0);
    func_001DBCB8(1);
    func_001DBCB8(3);
    func_001DBCB8(4);
    func_001DBCB8(5);
    func_001DBCB8(6);
    func_001DBCB8(8);
    func_001DBCB8(0xA);
    func_001DBCB8(0xB);
    func_001DBCB8(0xC);
    func_001DBCB8(7);
    func_001DBCB8(0xE);
    func_001DBCB8(9);
    func_001DBCB8(0xF);
    func_001DBCB8(0x10);
    func_001DD520();
    MsWeaponNameFree();
    MsMemCheckFree();
    func_0011D590((s32) D_003172F0.pF4, 5);
    func_0011D590((s32) D_003172F0.p5C, 5);
    func_0011D590((s32) D_003172F0.p60, 5);
    func_0011D590((s32) D_003172F0.p64, 5);
    func_0011D590((s32) D_003172F0.p74, 5);
    func_0011D590((s32) D_003172F0.p78, 5);
    func_0011D590((s32) D_003172F0.p68, 5);
    func_0011D590((s32) D_003172F0.p6C, 5);
    func_0011D590((s32) D_003172F0.p70, 5);
    func_0011D590((s32) D_003172F0.p80, 5);
    func_0011D590((s32) D_003172F0.p88, 5);
    func_0011D590((s32) D_003172F0.p84, 5);
    func_0011D590((s32) D_003172F0.p94, 5);
    func_0011D590((s32) D_003172F0.p90, 5);
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1ACFD8", MsBattleFree);

void func_001ADEA8(int i) {
    if (D_003172F0.h32[i].handle != 0) {
        func_0011D590(D_003172F0.h32[i].handle, 5);
        D_003172F0.h32[i].handle = 0;
    }
}

void func_001ADEF0(void) {
    if (D_003172F0.ent[0].handle != 0) {
        func_0011D590(D_003172F0.ent[0].handle, 5);
        D_003172F0.ent[0].handle = 0;
    }
}

void MsBattleDraw(void) {
    if (FFXIsDebug() != 0) {
        func_2038588();
    }
}

void MsBattleCursorCalc(void) {
    if (MsBattleGetStatus()) {
        MsCalcCursorPos();
        MsNumberDrawProcess();
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1ACFD8", MsBattleExe);

int func_001AE4A8(int flag, int v) {
    if (flag) {
        return MsGetFileSize(0xE, 0xB, v);
    }
    GetCD()->f10(0xE);
    return GetCD()->f14(v);
}

s8 MsBattleGetStatus(void) {
    return D_00317300;
}

s8 func_001AE520(void) {
    return D_003193EC;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1ACFD8", func_001AE530);

int func_001AE5D8(void) {
    switch (D_003172F0.f105) {
    case 1:
    case 2:
    case 3:
        if (D_003172F0.f10 == 21 || D_003172F0.f10 == 22 || D_003172F0.f10 == 1) {
            return 1;
        }
        break;
    case 0:
    default:
        if (D_003172F0.f20FC != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

s8 MsBattleGetMapCircleOn(void) {
    return D_0031733B;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1ACFD8", MsBattleEncountExe);

void MsWalkAbilityProcess(float dt) {
    int i;
    PartySlot *s;
    D_003172F0.f118 = D_003172F0.f118 + dt;
    if (D_003172F0.f11C < D_003172F0.f118) {
        D_003172F0.f118 = 0;
        for (i = 0; i < 18; i++) {
            if (MsGetSavePlyJoin(i) != 0) {
                s = MsGetSavePlayerPtr(i);
                if ((s->h4C >> 15) != 0) {
                    func_001BF470(i, 1);
                }
                if ((s->h4E & 1) != 0) {
                    func_001BF4C0(i, 1);
                }
            }
        }
    }
}

int MsBattleLabelExe(int a, int b, int c) {
    int h;
    int b1;
    int b2;

    if (MsBattleGetStatus() == 0 && MsFldGetScene(a, (int)&h, (int)&b1, (int)&b2) != 0) { /* DEBT(CAST): MsFldGetScene out-params declared as int */
        D_003172F0.f12 = 2;
        D_003172F0.h1986 = h;
        D_003172F0.pad1988[0] = b1; /* DEBT(TYPE): Rec172F0 in types.h has pad1988[2] at 0x1988 */
        D_003172F0.pad1988[1] = b2;
        D_003172F0.f104 = b;
        D_003172F0.f105 = c;
    }
    return -1;
}

int MsBattleExeClear(void) {
    s8 v = D_003172F0.f12;

    if (D_003172F0.f25 == 0) {
        D_003172F0.f12 = 0;
    }
    return v;
}

void func_001AEA68(int a) {
    if (MsFldGetScene(a, 0, 0, 0) != 0) {
        func_001ADA10(a >> 16, 0);
    }
}

int func_001AEAB0(int a) {
    u8 *p = MsFldGetScene(a, 0, 0, 0);
    if (p != 0) {
        return p[1] >> 4;
    }
    return 0;
}

int func_001AEAE8(int a, int v) {
    int r = 0;
    u8 *p = MsFldGetScene(a, 0, 0, 0);

    if (p) {
        u8 old = p[1];

        r = old >> 4;
        if (v < 0) {
            v = 0;
        } else if (v >= 16) {
            v = 15;
        }
        p[1] = (old & 0xF) + v * 16;
        func_001ADA10(a >> 16, 1);
    }
    return r;
}

int func_001AEB80(void) {
    if (MsBattleGetStatus() != 0 || D_00317302 != 0) {
        return 1;
    }
    return 0;
}

int MsBattleChrStart(void) {
    return MsGetChrTop() != 0;
}

int func_001AEBD8(void) {
    if (MsBattleGetStatus() != 0) {
        return (D_003172F0.pF8[D_003172F0.h1986].h0 << 16) | *D_003172F0.p12C;
    }
    return 0;
}

void func_001AEC30(int flag) {
    D_00317317 = flag & 1;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1ACFD8", MsBtlBridgeEvent2Btl);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1ACFD8", MsBtlBridgeBtl2Event);

int MsBattleGetChrDisposeFlag(void) {
    return 1;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1ACFD8", func_001AF2E8);

s8 MsBattleCursorType(void) {
    return D_003193ED;
}

int func_001AF320(void) {
    if (D_003172F0.f10 != 0) {
        return D_003172F0.h32[1].w18;
    }
    return 0;
}

u8 func_001AF348(void) {
    return D_003173F4;
}

int func_001AF358(void) {
    int r = 0;
    if (D_003172F0.f10 != 0 && D_003172F0.p120 != 0) {
        r = (D_003172F0.p120[0] << 16) + D_003172F0.p12C[0];
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1ACFD8", MsGetFileSize);

int MsBattleReadData(void) {
    int r = 0;
    int i = 0;
    while (MsBattleReadDataNB(i) != 0) {
        r = -1;
        GetCD()->f8(0);
        i++;
    }
    return r;
}

int MsBattleReadDataNB(int reset) {
    int r = 0;

    if (MsGetCheckEnglish()) {
        int cur = func_001BD360();

        if (cur != D_0065FF44) {
            r = -1;
            if (reset == 0) {
                D_0065FF68 = 0;
                D_0065FF6C = 0;
            }
            switch (D_0065FF68) {
            case 0:
                MsBattleExe(-1, 0, 0, 1);
                D_0065FF68 = 1;
                break;
            case 1:
                MsBtlReadSetScene();
                func_001AF990();
                D_0065FF68 = 2;
                break;
            case 2:
                if (func_001AF648(D_0065FF6C)) {
                    D_0065FF6C++;
                } else {
                    D_0065FF6C = 0;
                    D_0065FF68 = 3;
                }
                break;
            case 3:
                if (func_001AF948(D_0065FF6C)) {
                    D_0065FF6C++;
                } else {
                    D_0065FF6C = 0;
                    D_0065FF68 = 4;
                }
                break;
            case 4:
                MsImportantRead();
                D_0065FF68 = 5;
                break;
            case 5:
                MsWeaponNameRead();
                D_0065FF68 = 6;
                break;
            case 6:
                eiAbmSetLang();
                D_0065FF68 = 7;
                break;
            default:
                D_0065FF44 = cur;
                r = 0;
                break;
            }
        }
    }
    return r;
}

int func_001AF648(int which) {
    int r = -1;
    int id;

    switch (which) {
    case 0:
        D_003172F0.h98 = MsGetFileSize(13, 7, 2);
        if (D_003172F0.p5C == 0) {
            func_0011C348(0x40);
            D_003172F0.p5C = user_malloc(D_003172F0.h98, 5, D_0056E170, -1);
            MsMemCheckRegist(D_003172F0.p5C, D_003172F0.h98);
        }
        GetCD()->f0(2, D_003172F0.p5C, 0, 0);
        break;
    case 1:
        D_003172F0.h9A = MsGetFileSize(13, 7, 8);
        if (D_003172F0.p68 == 0) {
            func_0011C348(0x40);
            D_003172F0.p68 = user_malloc(D_003172F0.h9A, 5, D_0056E178, -1);
            MsMemCheckRegist(D_003172F0.p68, D_003172F0.h9A);
        }
        GetCD()->f0(8, D_003172F0.p68, 0, 0);
        break;
    case 2:
        D_003172F0.hA0 = MsGetFileSize(13, 7, 9);
        if (D_003172F0.p74 == 0) {
            func_0011C348(0x40);
            D_003172F0.p74 = user_malloc(D_003172F0.hA0, 5, D_0056E180, -1);
            MsMemCheckRegist(D_003172F0.p74, D_003172F0.hA0);
        }
        GetCD()->f0(9, D_003172F0.p74, 0, 0);
        break;
    case 3:
        D_003172F0.h9E = MsGetFileSize(13, 7, 13);
        if (D_003172F0.p70 == 0) {
            func_0011C348(0x40);
            D_003172F0.p70 = user_malloc(D_003172F0.h9E, 5, D_0056E190, -1);
            MsMemCheckRegist(D_003172F0.p70, D_003172F0.h9E);
        }
        GetCD()->f0(13, D_003172F0.p70, 0, 0);
        break;
    case 4:
        id = MsGetFileSize(13, 7, 19);
        if (D_003172F0.p60 == 0) {
            func_0011C348(0x40);
            D_003172F0.p60 = user_malloc(id, 5, D_0056E198, -1);
            MsMemCheckRegist(D_003172F0.p60, id);
        }
        GetCD()->f0(19, D_003172F0.p60, 0, 0);
        break;
    case 5:
        id = MsGetFileSize(13, 7, 20);
        if (D_003172F0.p64 == 0) {
            func_0011C348(0x40);
            D_003172F0.p64 = user_malloc(id, 5, D_0056E1A8, -1);
            MsMemCheckRegist(D_003172F0.p64, id);
        }
        GetCD()->f0(20, D_003172F0.p64, 0, 0);
        break;
    default:
        r = 0;
        break;
    }
    return r;
}

int func_001AF948(int idx) {
    s8 v = D_003172E0[idx];
    int r = 0;
    if (v >= 0) {
        r = -1;
        func_001DBBE0(v, 1);
    }
    return r;
}

void func_001AF990(void) {
    D_003172F0.h32[0] = D_003172F0.h32[1];
    D_003172F0.f10 = 0;
    D_003172F0.h32[1].handle = 0;
}
