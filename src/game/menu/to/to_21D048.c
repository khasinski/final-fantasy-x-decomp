/* tu_244 0x21d048-0x21f9a8: low; ~TOBtlMakeStatusBuff (config/tu_map.tsv) */
#define func_0021D820 _hdr_func_0021D820
#define toTarget _hdr_toTarget
#define MsMenuBitStatus _hdr_MsMenuBitStatus
#define MsMenuCountStatus _hdr_MsMenuCountStatus
#define MsMenuBitStatus2 _hdr_MsMenuBitStatus2
#define MsGetChrLimitGauge _hdr_MsGetChrLimitGauge
#define MsGetChrLimitGaugeMax _hdr_MsGetChrLimitGaugeMax
#define MsGetChrDist _hdr_MsGetChrDist
#define MsGetChrCursorFlag _hdr_MsGetChrCursorFlag
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/v4.h"
#include "ffx/r5.h"
#include "ffx/u3.h"
#include "ffx/s4.h"
#include "ffx/g2.h"
#undef func_0021D820
#undef toTarget
#undef MsMenuBitStatus
#undef MsMenuCountStatus
#undef MsMenuBitStatus2
#undef MsGetChrLimitGauge
#undef MsGetChrLimitGaugeMax
#undef MsGetChrDist
#undef MsGetChrCursorFlag

typedef struct {
    s16 h0;
    u16 h2;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
    u8 pad14[0x84 - 0x14];
    s32 w84;
    s32 w88;
    s32 w8C;
    s32 w90;
    s32 w94;
    s32 w98;
    s32 w9C;
    s32 wA0;
    u8 padA4[0x134 - 0xA4];
} R4InitFull;

extern R4InitFull toTarget;
extern s16 D_00324348;
extern s16 D_0032434A;
extern s16 D_00324350;
extern s16 D_00324352;
extern s16 D_00324356;

int MsMenuBitStatus(int id);
u8 *MsMenuCountStatus(int id);
int MsMenuBitStatus2(int id);
int MsGetStatusThreat(int id);
int MsGetChrLimitGauge(int id);
int MsGetChrLimitGaugeMax(int id);
void MsGetChrGroundPos(int id, int *x, int *y);
int MsGetChrDist(int id);
int MsGetChrCursorFlag(int id);
void func_001F56E8(void);
void func_001F3140(int a, int b, int c, int d, int e, int f, int g);
void func_001F30E8(int a, int b, int c, int d);

int TOBtlMakeStatusBuff(int id, s16 *out)
{
    int count = 0;
    int i;
    int bits = MsMenuBitStatus(id);
    u8 *cnts;

    for (i = 0; i < 12; i++) {
        if (i == 11) {
            if (MsGetStatusThreat(id) == 1) {
                out[count] = 0x1011;
                count++;
            }
        } else if ((bits >> i) & 1) {
            out[count] = i + 0x1006;
            count++;
        }
    }
    cnts = MsMenuCountStatus(id);
    for (i = 0; i < 13; i++) {
        if (cnts[i] != 0) {
            out[count] = i + 0x1012;
            count++;
        }
    }
    bits = MsMenuBitStatus2(id);
    for (i = 0; i < 15; i++) {
        if ((bits >> i) & 1) {
            out[count] = i + 0x1020;
            count++;
        }
    }
    return count;
}

void func_0021D1B0(int val, int x, int y)
{
    V4Rect4 r1;
    V4Rect4 r2;

    r1.v[0] = x;
    r1.v[1] = y;
    r1.v[2] = D_00324348;
    r1.v[3] = D_0032434A;
    r2.v[0] = x + D_00324350 - 1;
    r2.v[1] = y + D_00324352;
    r2.v[2] = D_00324354;
    r2.v[3] = D_00324356;
    TOMakePktBoxXYWHRGBA(r1.v[0], r1.v[1], r1.v[2], r1.v[3], 0, 0, 0, 0x80);
    if (D_00324354 != 0 && val != 0) {
        if (val >= D_00324354) {
            TOMakePktBoxXYWHRGBA(r2.v[0], r2.v[1], r2.v[2], r2.v[3], 0xF7, 0x79, 0x2E, 0x80);
        } else {
            func_001F0580(r2.v[0], r2.v[1], val, r2.v[3], 0x808AF8FF, 0x801777E3, r2.v[2]);
        }
    }
}

void TOBtlInitEnemyLimit(void)
{
    int i;

    func_002EF0D0(D_006928A8, 0, 0x80);
    for (i = 0; i < D_00692020; i++) {
        if (D_00692028[i] != 0xFF && func_001B7028(D_00692028[i]) == 1) {
            int cur = MsGetChrLimitGauge(D_00692028[i]);
            int max = MsGetChrLimitGaugeMax(D_00692028[i]);
            int val = (cur * D_00324354) / max;

            D_006928A8[i].w0 = val;
            D_006928A8[i].w4 = val;
        }
    }
}

void TOBtlCtrlEnemyLimit(void)
{
    int i;

    for (i = 0; i < D_00692020; i++) {
        if (D_00692028[i] != 0xFF && func_001B7028(D_00692028[i]) == 1) {
            if (MsGetChrLimitGaugeMax(D_00692028[i]) > 0) {
                int cur = MsGetChrLimitGauge(D_00692028[i]);
                int max = MsGetChrLimitGaugeMax(D_00692028[i]);

                D_006928A8[i].w0 = (cur * D_00324354) / max;
            } else {
                D_006928A8[i].w0 = 0;
            }
            if (D_006928A8[i].w4 < D_006928A8[i].w0) {
                D_006928A8[i].w4 += 6;
            }
            if (D_006928A8[i].w4 > D_006928A8[i].w0) {
                D_006928A8[i].w4 = D_006928A8[i].w0;
            }
        }
    }
}

void TOBtlDrawEnemyLimit(void)
{
    int x;
    int y;
    int i;

    TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    for (i = 0; i < D_00692020; i++) {
        if (D_00692028[i] != 0xFF && func_001B7028(D_00692028[i]) == 1) {
            MsGetChrGroundPos(D_00692028[i], &x, &y);
            func_0021D1B0(D_006928A8[i].w4, x - D_00324354 / 2, y);
        }
    }
}

void TOBtlInitChrNum(void)
{
    u16 *ids;
    int i;

    ids = TOGetSaveWindow(0, 9, &D_00692008);
    for (i = 0; i < D_00692008; i++) {
        D_00692010[i] = ids[i];
    }
    ids = TOGetSaveWindow(0, 0xB, &D_00692020);
    for (i = 0; i < D_00692020; i++) {
        D_00692028[i] = ids[i];
    }
}

void func_0021D6C8(void)
{
    u16 *ids;
    int i;

    ids = TOGetSaveWindow(0, 9, &D_00692008);
    for (i = 0; i < D_00692008; i++) {
        D_00692010[i] = ids[i];
    }
    ids = TOGetSaveWindow(0, 0xB, &D_00692020);
    for (i = 0; i < D_00692020; i++) {
        D_00692028[i] = ids[i];
    }
}

void func_0021D7A0(int a, int b)
{
    R4Rec *r;

    func_002EF0D0(&toTarget, 0, 0x134);
    toTarget.h0 = a;
    toTarget.h2 = b;
    r = &D_003249C0[D_00325020];
    r->h42 = 0;
    r->wC8 = 0;
}

int func_0021D820(void)
{
    int i;

    for (i = 0; i < D_00692008; i++) {
        toTarget.w4 |= 1 << D_00692010[i];
    }
    for (i = 0; i < D_00692020; i++) {
        toTarget.w8 |= 1 << D_00692028[i];
    }
    toTarget.wC = toTarget.w4 | toTarget.w8;
    return D_00692008 + D_00692020;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", TOBtlMakeTargetGroupBit);

void TOBtlMakeTargetChrStatusBit(void)
{
    int i;

    toTarget.w84 = 0;
    toTarget.w88 = 0;
    toTarget.w8C = 0;
    toTarget.w9C = 0;
    toTarget.w98 = 0;
    for (i = 0; i < 0x1C; i++) {
        if ((toTarget.wC >> i) & 1) {
            if (MsGetChrCursorFlag(i) == 1) {
                toTarget.w84 |= 1 << i;
            }
            switch (MsGetChrEventFlag(i, toTarget.h2)) {
            case 0:
                toTarget.w8C |= 1 << i;
                break;
            case 1:
                toTarget.w88 |= 1 << i;
                break;
            case 2:
                break;
            }
            if (MsGetChrDist(i) == 0) {
                toTarget.w9C |= 1 << i;
            }
            if (MsGetChrStatDeath(i) == 0) {
                toTarget.w98 |= 1 << i;
            }
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", func_0021DBF0);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", TOBtlMakeTargetTargetBit);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", _TOBtlGetTargetPad);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", TOBtlSearchRevNearTarget);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", func_0021ECC0);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", TOBtlSetDefaultCursorPos);

void graphicGetTime(void)
{
    D_003249B8 = 0;
    func_002EF0D0(D_00692928, 0, 0x20);
}

void QuickConfigMenuDraw(void)
{
    int i;

    for (i = 0; i < D_003249B8; i++) {
        func_001FE7F8(D_00692928[i].h0, D_00692928[i].h4, D_00692928[i].h6);
    }
    D_003249B8 = 0;
}

void func_0021F448(int a, s16 b, s16 c)
{
    if (D_003249B8 < 4) {
        D_00692928[D_003249B8].h0 = a;
        D_00692928[D_003249B8].h4 = b;
        D_00692928[D_003249B8].h6 = c;
        D_003249B8++;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", TOBtlDrawDamageValue2);

void TOBtlDrawChangeSeqAnm0(int p, int x, int y)
{
    TOMakePktSampleBlueWindowXY2(x, y, x + 0xA2, y + 0x2C);
    TOMkpShapeXY(p + 0x1B8, x + 2, y + 2);
    TOMkpEasyMesFontLCenter(func_0021F940(p), x + 0x61, y + 2);
    TOBtlDrawParamPlate(p, x + 2, y + 0x17);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", TOBtlDrawParamPlate);

s32 func_0021F8C0(int id)
{
    return MsGetRamChrHP(id);
}

s32 func_0021F8E0(int id)
{
    return MsGetRamChrMP(id);
}

s32 func_0021F900(int id)
{
    return MsGetRamChrHPmax(id);
}

s32 func_0021F920(int id)
{
    return MsGetRamChrMPmax(id);
}

int func_0021F940(int a)
{
    return TOGetSaveChrName(a);
}

/* DEBT(FAKE) */
s32 func_0021F960(void) {
    register s32 temp_2 __asm__("$3");

    temp_2 = MsCalcWeakLevel();
    if (temp_2 < 3) {
        if (temp_2 <= 0) {
            __asm__ volatile("");
            return 0;
        }
        return 2;
    }
    if (temp_2 == 3) {
        __asm__ volatile("");
        return 0x53;
    }
    return 0;
}
