/* tu_179 0x1acfd8-0x1af9e8: low; ~Ms (config/tu_map.tsv) */
#define MsBattleFree _hdr_MsBattleFree
#define MsBtlListEncount _hdr_MsBtlListEncount
#define MsFldGetScene _hdr_MsFldGetScene
#define MsSetCountryName _hdr_MsSetCountryName
#define func_002D9868 _hdr_func_002D9868
#define func_002D9880 _hdr_func_002D9880
#define func_002D97C8 _hdr_func_002D97C8
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q4.h"
#include "ffx/s2.h"
#include "ffx/v2.h"
#include "ffx/u2.h"
#include "ffx/g2.h"
#undef MsBattleFree
#undef MsBtlListEncount
#undef MsFldGetScene
#undef MsSetCountryName
#undef func_002D9868
#undef func_002D9880
#undef func_002D97C8

int MsBtlListFieldNum(int a);
u8 *MsBtlListEncount(int a);
u8 *func_001B3448(int a, int b);
int func_002D9868(void);
int func_002D9880(void);
void func_002D97C8(int a);
int func_204CC78(void *a, int *b);
extern u8 D_0056E020[];
extern u8 D_0056E030[];
extern u8 D_00319440[];
extern u8 D_003172D0[];
extern s32 D_00319460;

void MsBattleMemInit(void) {
    D_0065FF40 = 0;
    MsStructClear(&D_003172F0, 0x2148);
    MsEtEffectReadInit();
}

int MsSetCountryName(char *s) {
    int r = 0;
    switch (FFXGetLang()) {
    case 0:
        r = 0;
        if (s != 0) {
            func_002F0008(s, D_0056DFC8);
        }
        break;
    case 1:
        r = 0;
        if (s != 0) {
            func_002F0008(s, D_0056DFD0);
        }
        break;
    case 2:
        r = 1;
        if (s != 0) {
            func_002F0008(s, D_0056DFD8);
        }
        break;
    case 3:
        r = 1;
        if (s != 0) {
            func_002F0008(s, D_0056DFE0);
        }
        break;
    case 4:
        r = 1;
        if (s != 0) {
            func_002F0008(s, D_0056DFE8);
        }
        break;
    case 5:
        r = 1;
        if (s != 0) {
            func_002F0008(s, D_0056DFF0);
        }
        break;
    case 6:
        r = 1;
        if (s != 0) {
            func_002F0008(s, D_0056DFF8);
        }
        break;
    }
    return r;
}

void MsDebugInfoRead(void) {
    int status;
    D_00319460 = func_002D9868();
    if (FFXIsDebug() != 0) {
        func_002F0008((char *)D_00319440, (char *)D_0056E020, D_003172D0);
        D_0065FF40 = func_204CC78(D_00319440, &status);
        if (status != 0) {
            func_002F0008((char *)D_00319440, (char *)D_0056E030, Sg_GetUserName(), D_003172D0);
            D_0065FF40 = func_204CC78(D_00319440, &status);
        }
        if (func_002D9880() != 0) {
            func_002D97C8(0);
            MsSetSaveConfigEnglish(1);
        }
        ((int (*)(void *))MsSetCountryName)(D_00319438);
    }
}

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

typedef struct {
    u8 pad0[0x12];
    s8 f12;
    u8 pad13[0x12];
    u8 f25;
    u8 pad26[0xF];
    s8 f35;
    u8 pad36[0x1D];
    u8 f53;
    u8 pad54[0x24];
    void *f78;
    void *f7C;
    void *f80;
    void *f84;
    void *f88;
    u8 pad8C[4];
    void *f90;
    void *f94;
    u8 pad98[0xA];
    u16 fA2;
    u16 fA4;
    u16 fA6;
    u16 fA8;
    u16 fAA;
    u8 padAC[2];
    u16 fAE;
    u16 fB0;
    u8 padB2[0x42];
    void *fF4;
    u8 padF8[0xA];
    s16 f102;
    u8 pad104[0x140F];
    u8 f1513;
    u8 pad1514[4];
    float f1518;
    u8 pad151C[0x46A];
    s16 f1986;
    s8 f1988;
    s8 f1989;
} BtlInitGS; /* DEBT(NAME): offset view of GameState for MsBattleInit */

extern char D_0056E0B0[], D_0056E0C0[], D_0056E0D0[], D_0056E0D8[], D_0056E0E8[], D_0056E0F8[], D_0056E100[], D_0056E108[];
extern int func_001BD360(void);
extern void MsInitParamData(void);
extern void func_001AFA80(void);
extern void func_001B8B20(void);
extern void func_001DF1C0(void);
extern void func_001DBB90(void);
extern void MsNumberInit(void);
extern void func_001CEC58(void);
extern void func_001D9F58(int);
extern void func_001E1AC0(void);
extern void MsEventEffectInit(void);
extern void MsImportantInit(void);
extern void func_001DDA30(void);
extern void func_001CCC30(void);
extern void MsBtlGetInit(void);
extern void MsMemCheckInit(void);
extern void func_0011C348(int);
extern int MsGetCheckEnglish(void);
extern int func_001AF948(int);
extern void MsFieldItemRead(void);
extern void MsSetSaveStartGame(void);
extern void func_001BE348(void);
extern void func_20512F0(void);
extern void MsBattleInitAtEvent(int);
extern void func_204B058(int, int, int, int, int);
extern void MsMemCheckSum(int);
extern void func_001BCE30(void);
extern void MsDebugFullCommand(void);
extern void func_001BCBA8(void);
extern void MsDebugFullGill(void);

#define BTL_INIT_GS ((BtlInitGS *)&D_003172F0) /* DEBT(CAST): GameState offset view */

void MsBattleInit(void)
{
    int i = 0;

    D_0065FF44 = func_001BD360();
    MsInitParamData();
    func_001AFA80();
    func_001B8B20();
    func_001DF1C0();
    func_001E0328();
    func_001DBB90();
    MsAtelRegistInit();
    MsNumberInit();
    func_001CEC58();
    func_001D9F58(0);
    func_001E1AC0();
    MsEventEffectInit();
    MsImportantInit();
    func_001DDA30();
    func_001CCC30();
    MsBtlGetInit();
    MsMemCheckInit();

    GetCD()->f10(0xD);
    BTL_INIT_GS->f102 = GetCD()->f14(0);
    func_0011C348(0x40);
    BTL_INIT_GS->fF4 = user_malloc(BTL_INIT_GS->f102, 5, D_0056E0B0, -1);
    MsMemCheckRegist(BTL_INIT_GS->fF4, BTL_INIT_GS->f102);
    GetCD()->f0(0, BTL_INIT_GS->fF4, 0, 0);
    GetCD()->f8(0);

    BTL_INIT_GS->fA4 = GetCD()->f14(0xB);
    func_0011C348(0x40);
    BTL_INIT_GS->f7C = user_malloc(BTL_INIT_GS->fA4, 5, D_0056E0C0, -1);
    MsMemCheckRegist(BTL_INIT_GS->f7C, BTL_INIT_GS->fA4);
    GetCD()->f0(0xB, BTL_INIT_GS->f7C, 0, 0);
    GetCD()->f8(0);

    BTL_INIT_GS->fA2 = GetCD()->f14(0xE);
    func_0011C348(0x40);
    BTL_INIT_GS->f78 = user_malloc(BTL_INIT_GS->fA2, 5, D_0056E0D0, -1);
    MsMemCheckRegist(BTL_INIT_GS->f78, BTL_INIT_GS->fA2);
    GetCD()->f0(0xE, BTL_INIT_GS->f78, 0, 0);
    GetCD()->f8(0);

    BTL_INIT_GS->fA6 = GetCD()->f14(0x1C);
    func_0011C348(0x40);
    BTL_INIT_GS->f80 = user_malloc(BTL_INIT_GS->fA6, 5, D_0056E0D8, -1);
    MsMemCheckRegist(BTL_INIT_GS->f80, BTL_INIT_GS->fA6);
    GetCD()->f0(0x1C, BTL_INIT_GS->f80, 0, 0);
    GetCD()->f8(0);

    BTL_INIT_GS->fA8 = GetCD()->f14(0x1D);
    func_0011C348(0x40);
    BTL_INIT_GS->f88 = user_malloc(BTL_INIT_GS->fA8, 5, D_0056E0E8, -1);
    MsMemCheckRegist(BTL_INIT_GS->f88, BTL_INIT_GS->fA8);
    GetCD()->f0(0x1D, BTL_INIT_GS->f88, 0, 0);
    GetCD()->f8(0);

    BTL_INIT_GS->fAA = GetCD()->f14(0x1E);
    func_0011C348(0x40);
    BTL_INIT_GS->f84 = user_malloc(BTL_INIT_GS->fAA, 5, D_0056E0F8, -1);
    MsMemCheckRegist(BTL_INIT_GS->f84, BTL_INIT_GS->fAA);
    GetCD()->f0(0x1E, BTL_INIT_GS->f84, 0, 0);
    GetCD()->f8(0);

    GetCD()->f10(0x2F);
    BTL_INIT_GS->fB0 = GetCD()->f14(5);
    func_0011C348(0x40);
    BTL_INIT_GS->f94 = user_malloc(BTL_INIT_GS->fB0, 5, D_0056E100, -1);
    MsMemCheckRegist(BTL_INIT_GS->f94, BTL_INIT_GS->fB0);
    GetCD()->f0(5, BTL_INIT_GS->f94, 0, 0);
    GetCD()->f8(0);

    BTL_INIT_GS->fAE = GetCD()->f14(6);
    func_0011C348(0x40);
    BTL_INIT_GS->f90 = user_malloc(BTL_INIT_GS->fAE, 5, D_0056E108, -1);
    MsMemCheckRegist(BTL_INIT_GS->f90, BTL_INIT_GS->fAE);
    GetCD()->f0(6, BTL_INIT_GS->f90, 0, 0);
    GetCD()->f8(0);

    while (func_001AF648(i) != 0) {
        i++;
        GetCD()->f8(0);
    }

    func_001DBBE0(7, 0);
    func_001DBBE0(9, 0);
    func_001DBBE0(3, 0);
    if (MsGetCheckEnglish() != 0) {
        func_001DBBE0(0xE, 0);
        func_001DBBE0(0xF, 0);
        func_001DBBE0(0x10, 0);
    }

    i = 0;
    while (func_001AF948(i) != 0) {
        i++;
        GetCD()->f8(0);
    }

    MsImportantRead();
    GetCD()->f8(0);
    MsFieldItemRead();
    GetCD()->f8(0);
    MsWeaponNameRead();
    GetCD()->f8(0);
    MsSetSaveStartGame();
    BTL_INIT_GS->f1513 = 1;
    BTL_INIT_GS->f1518 = -14.0f;
    BTL_INIT_GS->f53 = 0xFF;
    func_001B3388();
    if (FFXIsDebug() != 0) {
        func_001BE348();
        func_20512F0();
    }
    MsBattleExe(-1, 0, 0, 1);
    GetCD()->f8(0);
    MsBtlReadSetScene();
    func_001AF990();
    MsBattleInitAtEvent(0);
    func_0011AB80(1);
    if (D_0065FF40 != 0) {
        MsBattleLabelExe(D_0065FF40, 0, 0);
        if (FFXIsDebug() != 0) {
            func_204B058(BTL_INIT_GS->f1986, BTL_INIT_GS->f1988, BTL_INIT_GS->f1989, (u32)D_0065FF40 >> 16, D_0065FF40 & 0xFFFF);
        }
        BTL_INIT_GS->f12 = BTL_INIT_GS->f25;
    } else {
        BTL_INIT_GS->f12 = 0;
    }
    MsMemCheckSum(0x70000);
    if (BTL_INIT_GS->f35 != 0) {
        func_001BCE30();
        MsDebugFullCommand();
        func_001BCBA8();
        MsDebugFullGill();
    }
}

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

void func_001ADA10(int a, int b) {
    int fld = MsBtlListFieldNum(a);
    int i;
    int j;
    u8 *enc;
    if (fld >= 0) {
        enc = MsBtlListEncount(fld);
        for (i = 0; i < enc[1]; i++) {
            u8 *p = func_001B3448(fld, i);
            u8 *q = p + 5;
            int sum = 0;
            for (j = 0; j < p[0]; j++, q += 2) {
                if (b == 0) {
                    q[1] = (q[1] & 0xF) | ((q[1] & 0xF) << 4);
                }
                sum += q[1] >> 4;
            }
            p[4] = sum;
        }
    }
}

u8 *MsFldGetScene(u32 a, int *out_fld, int *out_i, int *out_j) {
    u16 target = a & 0xFFFF;
    int fld = MsBtlListFieldNum(a >> 16);
    int i;
    int j;
    u8 *enc;
    if (fld >= 0) {
        enc = MsBtlListEncount(fld);
        for (i = 0; i < enc[1]; i++) {
            u8 *p = func_001B3448(fld, i);
            u8 *q = p + 5;
            for (j = 0; j < p[0]; j++, q += 2) {
                if (target == q[0]) {
                    if (out_fld != 0) {
                        *out_fld = fld;
                    }
                    if (out_i != 0) {
                        *out_i = i;
                    }
                    if (out_j != 0) {
                        *out_j = j;
                    }
                    return q;
                }
            }
        }
    }
    return 0;
}

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

void MsBattleFree(void) {
    if (D_003172F0.f10 != 0) {
        MsSaveEncountCheck();
        Sg_IdSetEffectTableIndex(0);
        func_001ADEF0();
        MsNumberFreeMem();
        MsBtlFreeItemMem();
        MsBattleSpecialFree();
        MsSEPbattleClear();
        MsBtlReadSceneFree();
        MsEtEffectStop();
        MsDebugCameraSleepInit();
        TOClearBtlWindow();
        MsBtlBridgeBtl2Event();
        func_001ADEA8(1);
        MsBtlChrFreeAll();
        MsAtelRegistFree();
        func_001CCC40();
        func_001B41A0();
        D_003172F0.f1752 = 0;
        D_003172F0.f10 = 0;
        D_003172F0.h2078 = 0;
    }
}

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

typedef struct {
    u8 pad00[0x10];
    s8 f10;
    u8 pad11[1];
    s8 f12;
    s8 f13;
    s8 f14;
    u8 pad15[1];
    s8 f16;
    s8 f17;
    s8 f18;
    u8 pad19[3];
    s32 f1C;
    s32 f20;
    u8 pad24[0x0A];
    s8 f2E;
    u8 pad2F[0x1A];
    s8 f49;
    u8 pad4A[0x0A];
    s8 f54;
    u8 pad55[3];
    s8 f58;
    s8 f59;
    u8 pad5A[1];
    s8 f5B;
    u8 pad5C[0x5C];
    void *fB8;
    u8 padBC[0x18];
    struct {
        u16 f0;
        u16 f2;
        void *f4;
    } fD4;
    u8 padDC[0x29];
    s8 f105;
    u8 pad106[0x1A];
    u8 *f120;
    void *f124;
    u8 *f128;
    u8 *f12C;
    u8 pad130[0x13E0];
    s8 f1510;
    s8 f1511;
    s8 f1512;
    u8 pad1513[1];
    float f1514;
    u8 pad1518[4];
    s8 f151C;
    s8 f151D;
    s8 f151E;
    u8 pad151F[0xA9];
    s32 f15C8;
    s32 f15CC;
    u8 pad15D0[0x182];
    s8 f1752;
    s8 f1753;
    u8 pad1754[7];
    s8 f175B;
    u8 pad175C[0x228];
    s16 f1984;
    s16 f1986;
    u8 f1988;
    u8 f1989;
    char f198A[0x10];
    u8 pad199A[0x65E];
    s32 f1FF8;
    s32 f1FFC;
    s32 f2000;
    s32 f2004;
    s32 f2008;
    s32 f200C;
    s32 f2010;
    s32 f2014;
    s32 f2018;
    s32 f201C;
    s32 f2020;
    s32 f2024;
    s32 f2028;
    s32 f202C;
    s32 f2030;
    u8 pad2034[0x44];
    s16 f2078;
    s16 f207A;
    u8 pad207C[2];
    s16 f207E;
    u8 pad2080[0x7C];
    s8 f20FC;
    s8 f20FD;
    u8 pad20FE[2];
    s8 f2100;
    s8 f2101;
    s8 f2102;
    s8 f2103;
    s8 f2104;
    s8 f2105;
    s8 f2106;
    s8 f2107;
    s8 f2108;
    s8 f2109;
    s8 f210A;
    s8 f210B;
    s8 f210C;
    s8 f210D;
    s8 f210E;
    u8 f210F;
    u8 f2110;
    u8 f2111;
    s8 f2112;
    s8 f2113;
    s8 f2114;
    s8 f2115;
    s8 f2116;
    s8 f2117;
    s8 f2118;
    s8 f2119;
    s8 f211A;
    s8 f211B;
    s8 f211C;
    s8 f211D;
    u8 pad211E[1];
    s8 f211F;
    u8 pad2120[1];
    s8 f2121;
    s8 f2122;
    s8 f2123;
    s8 f2124;
    s8 f2125;
    s8 f2126;
    s8 f2127;
    s8 f2128;
    u8 pad2129[1];
    s8 f212A;
    s8 f212B;
    s8 f212C;
    s8 f212D;
    s8 f212E;
    s8 f212F;
    s8 f2130;
    u8 pad2131[1];
    s8 f2132;
    s8 f2133;
    s8 f2134;
    s8 f2135;
    s8 f2136;
    u8 pad2137[1];
    s8 f2138;
    s8 f2139;
    u8 pad213A[5];
    s8 f213F;
    s8 f2140;
    s8 f2141;
    s8 f2142;
    s8 f2143;
    s8 f2144;
    s8 f2145;
    s8 f2146;
} BtlExeGS; /* DEBT(NAME): GameState offset view for MsBattleExe */

extern char D_0065FF48[];
extern char D_0056E118[];
extern char D_0056E138[];
extern char D_0056E140[];
extern void MsEventEffectFree(void);
extern int func_001B34B8(int, int *, int *);
extern int func_001AE4A8(int, int);
extern void Sg_Blur(int);
extern void MsScreenFocusResetAll(void);
extern void func_00117E38(int);
extern void func_00116030(int);
extern void Sg_SetPlayer(int);
extern void MsBattleFree(void);
extern void MsSEP3Dinit(void);
extern void func_001AD9C8(int);
extern void func_001E1528(void);
extern void func_001CE970(void);
extern void func_001A6C78(int);
extern void func_001CC798(void);
extern void MsComBufInit(void);
extern void MsStoneInit(void);
extern int Sg_SetKeepFps(int);
extern void MsBtlChrGetMem(void);
extern void MsBtlGetItemMem(void);
extern void MsNumberGetMem(void);
extern void func_001DC850(void);
extern void MsSetItemWindow(void);
extern void func_00214790(void);
extern void MsEtEffectSet(void);
extern int func_001AE530(int, int *);
extern void MsEtEffectEncount(int, int);
extern void func_001463F0(int);
extern void MsBtlReadManage(void);

#define BTL_EXE_GS ((BtlExeGS *)&D_003172F0) /* DEBT(CAST): GameState offset view */

void MsBattleExe(int flag, int field, int enc, int grp)
{
    int file;
    int sz;
    void *buf;
    u8 *p;
    int i;
    int eff;
    int eff_arg;

    if (FFXIsDebug() != 0 && flag == 0) {
        func_002F0008(D_0065FF48, D_0056E118, D_00319438);
        SsSetProjectBase(D_0065FF48);
    }
    MsEventEffectFree();
    BTL_EXE_GS->f12 = 0;
    file = func_001B34B8(field, &enc, &grp);
    sz = func_001AE4A8(flag, file);
    if (sz == 0) {
        return;
    }
    {
        u8 *e = func_001B3448(field, enc);
        BTL_EXE_GS->f1984 = e[1] + (e[2] << 8);
    }
    if (flag != 0) {
        buf = BTL_EXE_GS->fB8;
        if (buf == 0) {
            func_0011C348(0x40);
            buf = user_malloc(sz, 5, D_0056E138, -1);
            MsMemCheckRegist(buf, sz);
        }
    } else {
        Sg_Blur(0);
        MsScreenFocusResetAll();
        func_00117E38(0);
        func_00116030(1);
        Sg_SetPlayer(0);
        MsBattleFree();
        func_0011C348(0x40);
        buf = user_malloc(sz, 5, D_0056E138, -1);
    }
    {
        struct { u16 f0; u16 f2; void *f4; } *d4 = (void *)((u8 *)&D_003172F0 + 0xD4); /* DEBT(CAST): sub-struct at 0xD4 */
        d4->f2 = sz;
        d4->f4 = buf;
    }
    func_001AFA80();
    func_001DF1C0();
    MsSEP3Dinit();
    func_001AD9C8(0);
    func_001E1528();
    func_001CE970();
    func_001A6C78(BTL_EXE_GS->f54);
    func_001CC798();
    MsComBufInit();
    MsStoneInit();

    BTL_EXE_GS->f2112 = -1;
    BTL_EXE_GS->f2113 = -1;
    BTL_EXE_GS->f210F = 0xFF;
    BTL_EXE_GS->f2110 = 0xFF;
    BTL_EXE_GS->f2111 = 0xFF;
    BTL_EXE_GS->f2114 = -1;
    BTL_EXE_GS->f1988 = enc;
    BTL_EXE_GS->f1989 = grp;
    BTL_EXE_GS->f1C = file;
    BTL_EXE_GS->f1752 = 0;
    BTL_EXE_GS->f2078 = 0;
    BTL_EXE_GS->f15C8 = 0;
    BTL_EXE_GS->f15CC = 0;
    BTL_EXE_GS->f1753 = 0;
    BTL_EXE_GS->f175B = 0;
    BTL_EXE_GS->f20FC = 0;
    BTL_EXE_GS->f2109 = flag;
    BTL_EXE_GS->f210C = 0;
    BTL_EXE_GS->f2106 = 0;
    BTL_EXE_GS->f2108 = 0;
    BTL_EXE_GS->f1512 = 0;
    BTL_EXE_GS->f13 = 0;
    BTL_EXE_GS->f2121 = 0;
    BTL_EXE_GS->f14 = 0;
    BTL_EXE_GS->f2115 = 0;
    BTL_EXE_GS->f212B = 0;
    BTL_EXE_GS->f210B = 0;
    BTL_EXE_GS->f1510 = 0;
    BTL_EXE_GS->f1511 = 0;
    BTL_EXE_GS->f1986 = field;
    BTL_EXE_GS->f16 = 0;
    BTL_EXE_GS->f17 = 0;
    BTL_EXE_GS->f1514 = 0.5f;
    BTL_EXE_GS->f200C = 0xFF;
    BTL_EXE_GS->f2024 = -1;
    BTL_EXE_GS->f202C = -1;
    BTL_EXE_GS->f2119 = -1;
    BTL_EXE_GS->f210D = 1;
    BTL_EXE_GS->f2130 = 1;
    BTL_EXE_GS->f18 = 0;
    BTL_EXE_GS->f151E = 0;
    BTL_EXE_GS->f151C = 0;
    BTL_EXE_GS->f151D = 0;
    BTL_EXE_GS->f1FF8 = 0;
    BTL_EXE_GS->f1FFC = 0;
    BTL_EXE_GS->f2000 = 0;
    BTL_EXE_GS->f2004 = 0;
    BTL_EXE_GS->f2008 = 0;
    BTL_EXE_GS->f2020 = 0;
    BTL_EXE_GS->f2028 = 0;
    BTL_EXE_GS->f2030 = 0;
    BTL_EXE_GS->f210E = 0;
    BTL_EXE_GS->f2E = 0;
    BTL_EXE_GS->f49 = 0;
    BTL_EXE_GS->f2132 = 0;
    BTL_EXE_GS->f210A = 0;
    BTL_EXE_GS->f2116 = 0;
    BTL_EXE_GS->f2117 = 0;
    BTL_EXE_GS->f2118 = 0;
    BTL_EXE_GS->f2133 = 0;
    BTL_EXE_GS->f2134 = 0;
    BTL_EXE_GS->f2135 = 0;
    BTL_EXE_GS->f2136 = 0;
    BTL_EXE_GS->f2138 = 0;
    BTL_EXE_GS->f2139 = 0;
    BTL_EXE_GS->f213F = 0;
    BTL_EXE_GS->f2142 = 1;
    BTL_EXE_GS->f2140 = 0;
    BTL_EXE_GS->f2141 = 0;
    BTL_EXE_GS->f2143 = 0;
    BTL_EXE_GS->f2144 = 0;
    BTL_EXE_GS->f2145 = 0;
    BTL_EXE_GS->f2146 = 0;
    BTL_EXE_GS->f207A = 0;
    if (FFXGetLang() == 5) {
        BTL_EXE_GS->f207E = 0x2C8;
    } else {
        BTL_EXE_GS->f207E = 0x29E;
    }
    BTL_EXE_GS->f201C = -1;
    BTL_EXE_GS->f212C = 1;
    BTL_EXE_GS->f2100 = 0;
    BTL_EXE_GS->f211A = 0;
    BTL_EXE_GS->f211B = 0;
    BTL_EXE_GS->f211C = 0;
    BTL_EXE_GS->f211D = 0;
    BTL_EXE_GS->f211F = 0;
    BTL_EXE_GS->f2121 = 0;
    BTL_EXE_GS->f2125 = 0;
    BTL_EXE_GS->f2107 = 0;
    BTL_EXE_GS->f20 = 0;
    BTL_EXE_GS->f2122 = 0;
    BTL_EXE_GS->f2010 = 0;
    BTL_EXE_GS->f2014 = 0;
    BTL_EXE_GS->f2018 = 0;
    BTL_EXE_GS->f2123 = 0;
    BTL_EXE_GS->f2124 = 0;
    BTL_EXE_GS->f20FD = 0;
    BTL_EXE_GS->f212D = 0;
    BTL_EXE_GS->f58 = 0;
    BTL_EXE_GS->f59 = 0;
    BTL_EXE_GS->f5B = 0;
    BTL_EXE_GS->f2126 = 0;
    BTL_EXE_GS->f2101 = 0;
    BTL_EXE_GS->f2102 = 0;
    BTL_EXE_GS->f2103 = 0;
    BTL_EXE_GS->f2104 = 0;
    BTL_EXE_GS->f2105 = 0;
    BTL_EXE_GS->f2127 = 0;
    BTL_EXE_GS->f212A = 0;
    BTL_EXE_GS->f212E = 0;
    BTL_EXE_GS->f212F = 0;

    BTL_EXE_GS->f120 = MsBtlListField(field);
    BTL_EXE_GS->f124 = MsBtlListEncount(field);
    p = func_001B3448(field, enc);
    BTL_EXE_GS->f128 = p;
    BTL_EXE_GS->f12C = p + 5;
    BTL_EXE_GS->f12C += grp * 2;
    if (flag == 0 && FFXIsDebug() != 0) {
        func_204B058(field, enc, grp, *(s16 *)BTL_EXE_GS->f120, BTL_EXE_GS->f12C[0]);
    }
    for (i = 0; i < 8; i++) {
        BTL_EXE_GS->f198A[i] = *(BTL_EXE_GS->f120 + i + 6);
    }
    BTL_EXE_GS->f198A[i] = 0;
    func_002F0008(BTL_EXE_GS->f198A, D_0056E140, BTL_EXE_GS->f198A, BTL_EXE_GS->f12C[0]);
    if (flag != 0) {
        BTL_EXE_GS->f10 = 5;
    } else {
        BTL_EXE_GS->f2128 = Sg_SetKeepFps(0);
        MsBtlChrGetMem();
        MsBtlGetItemMem();
        MsNumberGetMem();
        func_001DC850();
        MsSetItemWindow();
        func_00214790();
        MsEtEffectSet();
        eff = func_001AE530(BTL_EXE_GS->f105, &eff_arg);
        if (eff >= 0) {
            MsEtEffectEncount(eff, eff_arg);
        }
        func_001463F0(BTL_EXE_GS->f1984);
        BTL_EXE_GS->f10 = 4;
    }
    MsBtlReadManage();
}

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

int func_001AE530(int a, int *out) {
    int r = -1;
    int v = 0;
    int x = func_0014AD88();
    switch (a) {
    case -1:
        break;
    case 1:
    case 2:
    case 3:
        if (x == 0) {
            r = 1;
            v = 0x65;
        } else {
            r = 3;
            v = 0x3F;
        }
        break;
    case 0:
    default:
        if (x == 0) {
            r = 0;
            v = 0x31;
        } else {
            r = 2;
            v = 0x31;
        }
        break;
    }
    if (out != 0) {
        *out = v;
    }
    return r;
}

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

typedef struct {
    u8 pad00[0x12];
    s8 f12;
    u8 pad13[0x14];
    s8 f27;
    u8 pad28[0xDE];
    u8 f106;
    u8 f107;
    float f108;
    float f10C;
    float f110;
    float f114;
    u8 pad118[0x186E];
    s16 f1986;
    u8 f1988;
    u8 f1989;
} BtlEncGS;

typedef struct {
    u8 pad0[0x3D14];
    s32 f3D14;
} SaveData3D14;

extern int brnd(int);
extern int func_00117E28(int);

#define BTL_ENC_GS ((BtlEncGS *)&D_003172F0)

int MsBattleEncountExe(int field_id, int enc, float dt)
{
    int fld = MsBtlListFieldNum(field_id);
    u8 *enc_tbl;
    u8 *p;
    int step;

    if (BTL_ENC_GS->f12 == 2) {
        return 0;
    }
    if (fld < 0) {
        return 0;
    }
    if ((double)dt == 0.0) {
        return 0;
    }
    if (BTL_ENC_GS->f107 == 0) {
        return 0;
    }
    enc_tbl = MsBtlListEncount(fld);
    if (enc < 0 || enc >= enc_tbl[1]) {
        return 0;
    }
    p = func_001B3448(fld, enc);
    if (p[3] == 0) {
        return 0;
    }
    if (p[4] == 0) {
        return 0;
    }
    BTL_ENC_GS->f108 += dt;
    BTL_ENC_GS->f10C += dt;
    BTL_ENC_GS->f106 = p[3];
    step = (int)((double)BTL_ENC_GS->f10C / 10.0);
    while ((double)BTL_ENC_GS->f108 > 10.0) {
        u8 rate = p[3];
        if (step > (rate >> 1)) {
            step -= (rate >> 1);
            step = (step << 8) / (rate * 4);
            BTL_ENC_GS->f110 *= (float)(256 - step);
            BTL_ENC_GS->f114 *= 256.0f;
            if ((brnd(0) & 0xFF) < step) {
                int r = brnd(1) % p[4];
                int sum = 0;
                u8 *q = p + 5;
                int i;
                for (i = 0; i < p[0]; i++, q += 2) {
                    sum += q[1] >> 4;
                    if (r < sum) {
                        if (BTL_ENC_GS->f27 != 0) {
                            func_00117E28(3);
                            ((SaveData3D14 *)&D_003194D0)->f3D14++;
                        } else {
                            BTL_ENC_GS->f12 = 1;
                        }
                        BTL_ENC_GS->f1986 = fld;
                        BTL_ENC_GS->f1988 = enc;
                        BTL_ENC_GS->f1989 = i;
                        func_001AD9C8(1);
                        return -1;
                    }
                }
            }
        }
        BTL_ENC_GS->f108 -= 10.0;
    }
    return 0;
}

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

typedef struct {
    void *chr;
    s32 f04;
    u8 pad08[4];
    u8 b0C;
    u8 b0D;
    u8 pad0E[2];
    s8 f10;
    u8 pad11;
    s8 f12;
    u8 pad13[8];
    u8 b1B;
    u8 b1C;
    u8 pad1D[4];
    u8 b21;
    u8 b22;
} BridgeChr;

extern int _br_func_001489F0(void) __asm__("func_001489F0");
extern int _br_AtelGetEventBindIdFromID(int) __asm__("AtelGetEventBindIdFromID");
extern int _br_AtelGetEventCharIDFromID(int) __asm__("AtelGetEventCharIDFromID");
extern void *_br_AtelGetEventCharHandleFromID(int) __asm__("AtelGetEventCharHandleFromID");
extern int _br_AtelGetEventActorLinkWork(int) __asm__("AtelGetEventActorLinkWork");
extern int _br_AtelGetBindPCFromID(int) __asm__("AtelGetBindPCFromID");
extern int _br_AtelGetHideStatusFromID(int) __asm__("AtelGetHideStatusFromID");
extern int _br_AtelGetKeepBattlePartyFromID(int) __asm__("AtelGetKeepBattlePartyFromID");
extern void _br_AtelSetEventActorLinkWork(int, int) __asm__("AtelSetEventActorLinkWork");
extern BridgeChr *_br_MsGetWeapon(int, int) __asm__("MsGetWeapon");
extern int _br_func_00148D78(int, int) __asm__("func_00148D78");
extern void *_br_AtelGetEventElemHandleFromID(int, int) __asm__("AtelGetEventElemHandleFromID");
extern int _br_func_00148CB0(int, int) __asm__("func_00148CB0");
extern void _br_MsStatusEffectClear(int) __asm__("MsStatusEffectClear");
extern void _br_Ch_SetThickness(void *, float) __asm__("Ch_SetThickness");
extern void _br_func_00117D58(void *, int) __asm__("func_00117D58");
extern void _br_Ch_ClutEnable(void *, int) __asm__("Ch_ClutEnable");
extern void _br_Ch_ClutDispose(void *) __asm__("Ch_ClutDispose");
extern void _br_func_00110738(void *, int) __asm__("func_00110738");
extern void _br_func_00110718(void *, int) __asm__("func_00110718");
extern void _br_func_001B51A0(int, int) __asm__("func_001B51A0");
extern int _br_AtelGetEventElemStatus(int, int) __asm__("AtelGetEventElemStatus");
extern void _br_AtelSetEventElemHandleFromID(int, int, void *) __asm__("AtelSetEventElemHandleFromID");
extern void _br_AtelSetEventElemPosFromID(int, int, int) __asm__("AtelSetEventElemPosFromID");
extern void _br_AtelSetEventElemCharIDFromID(int, int, int) __asm__("AtelSetEventElemCharIDFromID");
extern void _br_AtelSetEventElemStatus(int, int, int) __asm__("AtelSetEventElemStatus");
extern void _br_func_001B4538(void *) __asm__("func_001B4538");
extern void _br_graphicLevelGetNameHash(void *, int) __asm__("graphicLevelGetNameHash");
extern void _br_AtelSetEventCharHandleFromID(int, void *) __asm__("AtelSetEventCharHandleFromID");

void MsBtlBridgeEvent2Btl(void)
{
    int not_found;
    int n = _br_func_001489F0();
    int i;

    for (i = 0; i < n; i++) {
        int bind_id;
        void *handle;
        int chr_idx;
        int char_id;
        int link;
        int pc;

        not_found = -1;
        bind_id = _br_AtelGetEventBindIdFromID(i);
        chr_idx = 0xFF;
        char_id = _br_AtelGetEventCharIDFromID(i);
        handle = _br_AtelGetEventCharHandleFromID(i);
        link = _br_AtelGetEventActorLinkWork(i);
        pc = _br_AtelGetBindPCFromID(i);

        if (bind_id == 1 && handle != 0) {
            BridgeChr *found;
            link |= 2;
            found = 0;
            if ((u32)pc != 0xFFFFFFFFU) {
                if (pc >= 0) {
                    if (pc < 0x1C) {
                        BridgeChr *c = (BridgeChr *)MsGetChr(pc);
                        int cid = c->f04;
                        if (c->f10 != 0 && c->chr == 0 && cid == char_id) {
                            chr_idx = pc;
                            found = c;
                        }
                    }
                }
            }
            if (found == 0) {
                int j;
                for (j = 0; j < 0x1F; j++) {
                    BridgeChr *c = (BridgeChr *)MsGetChr(j);
                    int cid = c->f04;
                    if (c->f10 != 0 && c->chr == 0 && cid == char_id) {
                        chr_idx = j;
                        found = c;
                        break;
                    }
                }
            }
            if (found != 0) {
                int w;
                for (w = 0; w < 2; w++) {
                    register BridgeChr *wp __asm__("$17") = _br_MsGetWeapon(chr_idx, w);
                    register int wid __asm__("$21") = _br_func_00148D78(i, w);
                    register void *wh __asm__("$16") = _br_AtelGetEventElemHandleFromID(i, w);
                    if (wid != 0 && wh != 0) {
                        int ok = 0;
                        int st = _br_func_00148CB0(i, w);
                        if (wp->chr == 0) {
                            *(volatile s8 *)&wp->b0D = st;
                            ok = 1;
                            *(void * volatile *)&wp->chr = wh;
                            *(volatile int *)&wp->f04 = wid;
                        }
                        if (!ok) {
                            if (w == 0) {
                                link |= 0x10;
                            } else {
                                link |= 0x20;
                            }
                        }
                    }
                }
                not_found = 0;
                found->chr = handle;
            }
            if (not_found != 0) {
                link |= 0x01;
                link |= 0x10;
                link |= 0x20;
            }
        }
        _br_AtelSetEventActorLinkWork(i, link & 0xFF);
    }
}

void MsBtlBridgeBtl2Event(void) {
    int flag;
    int count;
    int i;

    for (i = 0; i < 0x1F; i++) {
        _br_MsStatusEffectClear(i);
    }
    for (i = 0; i < 0x5D; i++) {
        register BridgeChr *c __asm__("$3") = (BridgeChr *)MsGetChr(i);
        register void *h __asm__("$17");
        __asm__("" : "+r"(c));
        h = c->chr;
        if (h != 0 && c->f12 == 0) {
            _br_Ch_SetThickness(h, -1.0f);
            _br_func_00117D58(h, 1);
            _br_Ch_ClutEnable(h, 0);
            _br_Ch_ClutDispose(h);
            _br_func_00110738(h, 0);
            _br_func_00110718(h, 0);
        }
    }
    _br_func_001B51A0(6, 0);
    count = _br_func_001489F0();
    for (i = 0; i < count; i++) {
        int bind_id;
        int chr_idx;
        int char_id;
        register void *handle __asm__("$17");
        int link;
        register int pc __asm__("$18");
        int hide;
        int keep;

        flag = -1;
        bind_id = _br_AtelGetEventBindIdFromID(i);
        chr_idx = 0xFF;
        char_id = _br_AtelGetEventCharIDFromID(i);
        handle = _br_AtelGetEventCharHandleFromID(i);
        link = _br_AtelGetEventActorLinkWork(i);
        pc = _br_AtelGetBindPCFromID(i);
        hide = _br_AtelGetHideStatusFromID(i);
        keep = _br_AtelGetKeepBattlePartyFromID(i);

        if (bind_id == 1 && handle != 0) {
            BridgeChr *c = 0;
            int j;
            if ((u32)pc != 0xFFFFFFFFU) {
                if (pc >= 0) {
                    if (pc < 0x1C) {
                        BridgeChr *tmp = (BridgeChr *)MsGetChr(pc);
                        void *th = tmp->chr;
                        int tid = tmp->f04;
                        if (th != 0 && tid == char_id) {
                            chr_idx = pc;
                            c = tmp;
                        }
                    }
                }
            }
            if (c == 0) {
                for (j = 0; j < 0x1F; j++) {
                    BridgeChr *tmp = (BridgeChr *)MsGetChr(j);
                    void *th = tmp->chr;
                    int tid = tmp->f04;
                    if (th != 0 && tid == char_id) {
                        chr_idx = j;
                        c = tmp;
                        break;
                    }
                }
            }
            if (c != 0) {
                int k;
                if (keep != 0) {
                    register int found __asm__("$19") = 0;
                    for (j = 0; j < 3; j++) {
                        if (D_003172F0.f1FC5[j] == c->b0C) {
                            found = 1;
                            break;
                        }
                    }
                    hide = -2;
                    if (found != 0) {
                        hide = 0;
                    }
                }
                if (c->b1C != 0) {
                    hide = 0;
                }
                if (c->b1B == 0) {
                    hide = -1;
                }
                for (k = 0; k < 2; k++) {
                    if (_br_AtelGetEventElemStatus(i, k) != 0) {
                        BridgeChr *w = _br_MsGetWeapon(chr_idx, k);
                        void *wh = w->chr;
                        int wid = w->f04;
                        int pos = w->b0D;
                        if (wh != 0 && wid != 0) {
                            _br_AtelSetEventElemHandleFromID(i, k, wh);
                            _br_AtelSetEventElemPosFromID(i, k, pos);
                            _br_AtelSetEventElemCharIDFromID(i, k, wid);
                            _br_AtelSetEventElemStatus(i, k, 1);
                            _br_func_001B4538(w);
                            if (hide != 0) {
                                _br_graphicLevelGetNameHash(wh, 1);
                            } else {
                                _br_graphicLevelGetNameHash(wh, 0);
                            }
                            w->b22 = 0;
                            __asm__("" : : "m"(w->b22));
                            w->chr = 0;
                        } else {
                            _br_AtelSetEventElemHandleFromID(i, k, 0);
                            _br_AtelSetEventElemPosFromID(i, k, 0);
                            _br_AtelSetEventElemCharIDFromID(i, k, 0);
                            _br_AtelSetEventElemStatus(i, k, 0);
                        }
                    }
                }
                _br_AtelSetEventCharHandleFromID(i, c->chr);
                _br_func_001B4538(c);
                {
                    void *h = c->chr;
                    c->chr = 0;
                    c->b22 = 0;
                    if (hide != 0) {
                        link |= 0x40;
                        _br_graphicLevelGetNameHash(h, 1);
                    } else {
                        _br_graphicLevelGetNameHash(h, 0);
                    }
                    flag = 0;
                }
                if (link & 0x80) {
                    c->b21 = 0;
                }
            }
            if (flag != 0) {
                link |= 4;
            }
        }
        _br_AtelSetEventActorLinkWork(i, link & 0xFF);
    }
}

int MsBattleGetChrDisposeFlag(void) {
    return 1;
}

extern void yiGetBattleCenter(float *v);

void func_001AF2E8(u_long128 *dst)
{
    volatile u_long128 *p = (volatile u_long128 *)&D_003172F0; /* DEBT(CAST) */
    if (*((s8 *)p + 0x212D) != 0) {
        register u_long128 t __asm__("$8") = *p; /* DEBT(FAKE) */
        *dst = t;
    } else {
        yiGetBattleCenter((float *)dst);
    }
}

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

int MsGetFileSize(int a, int b, int c) {
    int sz2 = 0;
    int sz1;
    GetCD()->f10(a);
    sz1 = GetCD()->f14(c);
    if (MsGetCheckEnglish() != 0) {
        GetCD()->f10(b);
        sz2 = GetCD()->f14(c);
        if (func_001BD360() == 0) {
            GetCD()->f10(a);
        }
    }
    return (sz1 > sz2) ? sz1 : sz2;
}

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
