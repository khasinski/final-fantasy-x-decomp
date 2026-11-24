/* tu_244 0x21d048-0x21f9a8: low; ~TOBtlMakeStatusBuff (config/tu_map.tsv) */
#define func_0021D820 _hdr_func_0021D820
#define toTarget _hdr_toTarget
#define D_003249C0 _hdr_D_003249C0
#define MsMenuBitStatus _hdr_MsMenuBitStatus
#define MsMenuCountStatus _hdr_MsMenuCountStatus
#define MsMenuBitStatus2 _hdr_MsMenuBitStatus2
#define MsGetChrLimitGauge _hdr_MsGetChrLimitGauge
#define MsGetChrLimitGaugeMax _hdr_MsGetChrLimitGaugeMax
#define MsGetChrDist _hdr_MsGetChrDist
#define MsGetChrCursorFlag _hdr_MsGetChrCursorFlag
#define _TOBtlGetTargetPad _hdr__TOBtlGetTargetPad
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
#undef D_003249C0
#undef MsMenuBitStatus
#undef MsMenuCountStatus
#undef MsMenuBitStatus2
#undef MsGetChrLimitGauge
#undef MsGetChrLimitGaugeMax
#undef MsGetChrDist
#undef MsGetChrCursorFlag
#undef _TOBtlGetTargetPad

typedef struct {
    s16 h0;
    u16 h2;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 pad14[0x1C];
    s32 w84;
    s32 w88;
    s32 w8C;
    s32 w90;
    s32 w94;
    s32 w98;
    s32 w9C;
    s32 wA0;
    s32 wA4;
    s32 wA8;
    s16 hAC;
    u8 padAE[2];
    s32 ally_bits[20];
    s16 h100;
    u8 pad102[2];
    s32 enemy_bits[8];
    s16 h124;
    s16 h126;
    s32 *p128;
    s16 h12C;
    s16 h12E;
    s16 h130;
    s16 h132;
} R4InitFull;

typedef struct {
    u8 pad00[0x02];
    s8 b02;
    u8 pad03[0x0A - 0x03];
    s8 b0A;
    s8 b0B;
    u16 h0C;
    s16 h0E[4];
    s16 h16[4];
    u8 pad1E[2];
    s16 *p20;
    s32 w24;
    u8 pad28[0x38 - 0x28];
    s16 h38;
    s16 h3A;
    u8 pad3C[0x40 - 0x3C];
    s16 h40;
    s16 h42;
    u8 pad44[0xC4 - 0x44];
    s16 hC4;
    s16 hC6;
    s32 wC8;
} R4RecFull;

extern R4InitFull toTarget;
extern R4RecFull D_003249C0[];
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
    R4RecFull *r;

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

void TOBtlMakeTargetGroupBit(void)
{
    s32 buf;
    u8 *com = (u8 *)MsGetComData(toTarget.h2, &buf);
    s32 *grp_arr = (s32 *)toTarget.pad14;
    int grp;
    int i;

    func_002EF0D0(grp_arr, 0, 0x70);
    grp = (*(u16 *)(com + 0x1A) >> 2) & 3;
    toTarget.w10 = grp;
    switch (grp) {
    case 0:
        for (i = 0; i < 0x1C; i++) {
            if ((toTarget.wC >> i) & 1) {
                grp_arr[i] = 1 << i;
            }
        }
        break;
    case 2:
        *(s32 *)((u8 *)&toTarget + 0x14) = toTarget.w4;
        *(s32 *)((u8 *)&toTarget + 0x64) = toTarget.w8;
        break;
    case 1:
        for (i = 0; i < 0x14; i++) {
            if ((toTarget.w4 >> i) & 1) {
                grp_arr[MsGetChrGroup(i)] |= 1 << i;
            }
        }
        for (i = 0x14; i < 0x1C; i++) {
            if ((toTarget.w8 >> i) & 1) {
                int g = MsGetChrGroup(i) + 0x14;

                ((s32 *)toTarget.pad14)[g] |= 1 << i;
            }
        }
        break;
    case 3:
        grp_arr[(u16)toTarget.h0] = 1 << (u16)toTarget.h0;
        break;
    }
}

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

typedef struct {
    u16 v[4][4];
} PadDirTbl;

extern PadDirTbl D_00571148;

int TOBtlSearchRevNearTarget(void);
void MsSetBtlTarget(u16, s32);
void MsResetBtlTarget(int);
void TOBtlSetPrevAction(void);
int TOBtlSetNextAction(int, int);

void TOBtlMakeTargetTargetBit(void)
{
    s32 buf;
    u8 *com;
    int i;
    int bit;
    R4RecFull *r;

    func_002EF0D0(toTarget.ally_bits, 0, 0x50);
    func_002EF0D0(toTarget.enemy_bits, 0, 0x20);
    com = (u8 *)MsGetComData(toTarget.h2, &buf);
    toTarget.wA4 = toTarget.w84 & toTarget.wA0 & toTarget.w98 & toTarget.w9C;
    toTarget.hAC = 0;
    toTarget.h100 = 0;
    switch (toTarget.w10) {
    case 0:
        for (i = 0; i < D_00692008; i++) {
            bit = toTarget.wA4 & ((s32 *)toTarget.pad14)[D_00692010[i]];
            if (bit != 0) {
                toTarget.ally_bits[toTarget.hAC++] = bit;
            }
        }
        for (i = 0; i < D_00692020; i++) {
            bit = toTarget.wA4 & ((s32 *)toTarget.pad14)[D_00692028[i]];
            if (bit != 0) {
                toTarget.enemy_bits[toTarget.h100++] = bit;
            }
        }
        break;
    case 2:
        if (toTarget.wA4 & toTarget.pad14[0]) {
            toTarget.ally_bits[0] = toTarget.wA4 & toTarget.pad14[0];
            toTarget.hAC = 1;
        }
        if (toTarget.wA4 & toTarget.pad14[0x14]) {
            toTarget.enemy_bits[0] = toTarget.wA4 & toTarget.pad14[0x14];
            toTarget.h100 = 1;
        }
        break;
    case 1:
        for (i = 0; i < 8; i++) {
            if (toTarget.wA4 & ((s32 *)toTarget.pad14)[i]) {
                toTarget.ally_bits[toTarget.hAC++] = toTarget.wA4 & ((s32 *)toTarget.pad14)[i];
            }
        }
        for (i = 0; i < 8; i++) {
            if (toTarget.wA4 & ((s32 *)toTarget.pad14)[i + 0x14]) {
                toTarget.enemy_bits[toTarget.h100++] = toTarget.wA4 & ((s32 *)toTarget.pad14)[i + 0x14];
            }
        }
        break;
    case 3:
        if ((u16)toTarget.h0 < 0x14) {
            toTarget.ally_bits[0] = 1 << (u16)toTarget.h0;
            toTarget.hAC = 1;
        }
        if ((u16)toTarget.h0 >= 0x14 && (u16)toTarget.h0 < 0x1C) {
            toTarget.enemy_bits[0] = 1 << (u16)toTarget.h0;
            toTarget.h100 = 1;
        }
        break;
    }

    toTarget.h12C = 0;
    if ((*(u16 *)(com + 0x1A) >> 1) & 1) {
        toTarget.h130 = 1;
        toTarget.p128 = toTarget.enemy_bits;
        toTarget.h126 = toTarget.h100;
    } else {
        toTarget.h130 = 0;
        toTarget.h126 = toTarget.hAC;
        toTarget.p128 = toTarget.ally_bits;
        if (toTarget.w10 == 0) {
            for (i = 0; i < toTarget.h126; i++) {
                if (toTarget.p128[i] == (1 << (u16)toTarget.h0)) {
                    toTarget.h12C = i;
                    break;
                }
            }
        }
    }

    if ((*(u16 *)(com + 0x1A) >> 5) & 1) {
        toTarget.h12E = 1;
    } else {
        toTarget.h12E = 0;
    }

    toTarget.wA8 = toTarget.p128[toTarget.h12C];
    if (toTarget.w10 == 0 || toTarget.w10 == 3) {
        for (i = 0; i < 0x1C; i++) {
            if ((toTarget.wA8 >> i) & 1) {
                toTarget.h124 = i;
            }
        }
    } else {
        toTarget.h124 = 0xFF;
    }

    r = (R4RecFull *)D_003249C0;
    r[D_00325020].wC8 = toTarget.wA8;
    r[D_00325020].hC4 = toTarget.h130;
    r[D_00325020].hC6 = toTarget.w10;
    r[D_00325020].h42 = toTarget.h12C;
}

void _TOBtlGetTargetPad(s16 *arg)
{
    PadDirTbl tbl = D_00571148;
    int type;
    s16 prev_idx;
    s16 prev_side;
    int i;
    R4RecFull *r;

    type = MsBattleCursorType() & 0xFF;
    prev_idx = toTarget.h12C;
    prev_side = toTarget.h130;
    if (D_003238D0.h16 & tbl.v[type][0]) {
        toTarget.h12C--;
    }
    if (D_003238D0.h16 & tbl.v[type][1]) {
        toTarget.h12C++;
    }
    if (toTarget.h12C < 0) {
        toTarget.h12C = toTarget.h126 - 1;
    }
    if (toTarget.h12C >= toTarget.h126) {
        toTarget.h12C = 0;
    }
    if ((D_003238D0.h14 & tbl.v[type][2]) || (D_003238D0.h14 & tbl.v[type][3])) {
        if (toTarget.h12E == 1) {
            if (toTarget.h130 == 0) {
                if (toTarget.h100 > 0) {
                    s16 old = toTarget.h12C;
                    toTarget.h126 = toTarget.h100;
                    toTarget.p128 = toTarget.enemy_bits;
                    toTarget.h12C = TOBtlSearchRevNearTarget();
                    toTarget.h132 = old;
                    toTarget.h130 = 1;
                }
            } else {
                if (toTarget.hAC > 0) {
                    s16 old = toTarget.h12C;
                    toTarget.h126 = toTarget.hAC;
                    toTarget.p128 = toTarget.ally_bits;
                    toTarget.h12C = TOBtlSearchRevNearTarget();
                    toTarget.h132 = old;
                    toTarget.h130 = 0;
                }
            }
        }
    }
    if (toTarget.h12C != prev_idx || toTarget.h130 != prev_side) {
        func_002D70D8(1);
    }
    toTarget.wA8 = toTarget.p128[toTarget.h12C];
    if (toTarget.w10 == 0 || toTarget.w10 == 3) {
        for (i = 0; i < 0x1C; i++) {
            if ((toTarget.wA8 >> i) & 1) {
                toTarget.h124 = i;
            }
        }
    } else {
        toTarget.h124 = 0xFF;
    }
    r = (R4RecFull *)D_003249C0;
    r[D_00325020].h42 = toTarget.h12C;
    r[D_00325020].wC8 = toTarget.wA8;
    r[D_00325020].hC4 = toTarget.h130;
    MsSetBtlTarget(toTarget.h0, toTarget.wA8);
    if (D_003238D0.h14 & 0x40) {
        MsResetBtlTarget(arg[4]);
        TOBtlSetPrevAction();
        func_002D70D8(4);
    } else if (D_003238D0.h14 & 0x20) {
        if (TOBtlSetNextAction(arg[4], 0x3115) >= 0) {
            func_002D70D8(1);
        } else {
            func_002D70D8(3);
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", TOBtlSearchRevNearTarget);

typedef struct {
    s16 h00;
    s16 h02;
    s16 h04[4];
    u16 h0C[4];
    u16 h14;
    s16 h16;
    s16 h18;
    s16 h1A;
    s32 w1C;
    s16 h20;
    s16 h22;
} CursorSaveSlot;

extern u8 D_006906A0[];
extern CursorSaveSlot D_006906B8[][10];

void func_0021ECC0(void)
{
    u16 cmd = D_003249C0[1].h0C;
    int i, j;

    if (cmd == 0xFFFE || cmd == 0xFFFF || cmd == 0x3002) {
        return;
    }
    for (i = 0; i <= D_00325020; i++) {
        D_006906B8[D_003252A4][i].h00 = D_003249C0[i].b02;
        D_006906B8[D_003252A4][i].h02 = D_003249C0[i].b0A;
        for (j = 0; j < D_003249C0[i].b0A; j++) {
            D_006906B8[D_003252A4][i].h04[j] = D_003249C0[i].h0E[j];
            D_006906B8[D_003252A4][i].h0C[j] = D_003249C0[i].h16[j];
        }
        {
            R4RecFull *src = &D_003249C0[i];
            D_006906B8[D_003252A4][i].h14 = src->h0C;
            D_006906B8[D_003252A4][i].w1C = src->wC8;
            D_006906B8[D_003252A4][i].h18 = src->hC4;
            D_006906B8[D_003252A4][i].h1A = src->hC6;
            D_006906B8[D_003252A4][i].h20 = src->h42;
            D_006906B8[D_003252A4][i].h16 = src->h40;
        }
    }
    D_006906A0[D_003252A4] = 1;
}

void TOBtlSetDefaultCursorPos(void)
{
    int found = 0;
    int i, j;

    if (((R4RecFull *)D_003249C0)[D_00325020].h0C != D_006906B8[D_003252A4][D_00325020].h14) {
        return;
    }
    if (((R4RecFull *)D_003249C0)[D_00325020].b02 == 0) {
        for (i = 0; i < ((R4RecFull *)D_003249C0)[D_00325020].w24; i++) {
            if (D_006906B8[D_003252A4][D_00325020].h0C[((R4RecFull *)D_003249C0)[D_00325020].b0B] ==
                ((R4RecFull *)D_003249C0)[D_00325020].p20[i]) {
                found = 1;
                break;
            }
        }
        if (found == 1) {
            D_003249C0[D_00325020].b02 = D_006906B8[D_003252A4][D_00325020].h00;
            D_003249C0[D_00325020].h0E[D_003249C0[D_00325020].b0B] = i;
            D_003249C0[D_00325020].h16[D_003249C0[D_00325020].b0B] = D_006906B8[D_003252A4][D_00325020].h0C[D_003249C0[i].b0B];
            D_003249C0[D_00325020].h0C = D_006906B8[D_003252A4][D_00325020].h14;
            {
                R4RecFull *cur = &D_003249C0[D_00325020];
                cur->h40 = (i / cur->h38) * cur->h38 - cur->h38;
                if (cur->w24 < cur->h38 * cur->h3A) {
                    cur->h40 = 0;
                } else {
                    if (i < cur->h38) {
                        cur->h40 = 0;
                    }
                    if (i > ((cur->w24 + cur->h38 - 1) / cur->h38) * cur->h38 - cur->h38 - 1) {
                        cur->h40 = ((cur->w24 + cur->h38 - 1) / cur->h38) * cur->h38 - cur->h38 * cur->h3A;
                    }
                }
            }
            {
                R4RecFull *cur2 = &D_003249C0[D_00325020];
                cur2->h42 = i;
                cur2->wC8 = D_006906B8[D_003252A4][D_00325020].w1C;
            }
        } else {
            D_003249C0[D_00325020].h42 = 0;
            D_003249C0[D_00325020].h40 = 0;
        }
    }
    if (D_003249C0[D_00325020].b02 == 1) {
        if (D_006906B8[D_003252A4][D_00325020].w1C != 0) {
            switch (D_006906B8[D_003252A4][D_00325020].h1A) {
            case 0:
                if (D_006906B8[D_003252A4][D_00325020].h18 == 0) {
                    for (i = 0; i < 0x14; i++) {
                        if (toTarget.ally_bits[i] == D_006906B8[D_003252A4][D_00325020].w1C) {
                            toTarget.wA8 = toTarget.ally_bits[i];
                            toTarget.h12C = i;
                            toTarget.h130 = 0;
                            for (j = 0; j < 0x14; j++) {
                                if ((toTarget.wA8 >> j) & 1) {
                                    toTarget.h124 = j;
                                }
                            }
                            toTarget.h126 = toTarget.hAC;
                            toTarget.p128 = toTarget.ally_bits;
                            break;
                        }
                    }
                } else {
                    for (i = 0; i < 8; i++) {
                        if (toTarget.enemy_bits[i] == D_006906B8[D_003252A4][D_00325020].w1C) {
                            toTarget.wA8 = toTarget.enemy_bits[i];
                            toTarget.h130 = 1;
                            toTarget.h12C = i;
                            for (j = 0x14; j < 0x1C; j++) {
                                if ((toTarget.wA8 >> j) & 1) {
                                    toTarget.h124 = j;
                                }
                            }
                            toTarget.h126 = toTarget.h100;
                            toTarget.p128 = toTarget.enemy_bits;
                            break;
                        }
                    }
                }
                break;
            case 2:
                if (D_006906B8[D_003252A4][D_00325020].h18 == 0) {
                    toTarget.wA8 = toTarget.ally_bits[0];
                    toTarget.h126 = toTarget.hAC;
                    toTarget.h124 = 0xFF;
                    toTarget.p128 = toTarget.ally_bits;
                    toTarget.h12C = 0;
                    toTarget.h130 = 0;
                } else {
                    s32 b = toTarget.enemy_bits[0];
                    toTarget.h130 = 1;
                    toTarget.h126 = toTarget.h100;
                    toTarget.wA8 = b;
                    toTarget.h124 = 0xFF;
                    toTarget.p128 = toTarget.enemy_bits;
                    toTarget.h12C = 0;
                }
                break;
            case 1:
                if (D_006906B8[D_003252A4][D_00325020].h18 == 0) {
                    for (i = 0; i < toTarget.hAC; i++) {
                        if (D_006906B8[D_003252A4][D_00325020].w1C & toTarget.ally_bits[i]) {
                            toTarget.h12C = i;
                            toTarget.h126 = toTarget.hAC;
                            toTarget.wA8 = toTarget.ally_bits[i];
                            toTarget.h124 = 0xFF;
                            toTarget.p128 = toTarget.ally_bits;
                            toTarget.h130 = 0;
                            break;
                        }
                    }
                } else {
                    for (i = 0; i < toTarget.h100; i++) {
                        if (D_006906B8[D_003252A4][D_00325020].w1C & toTarget.enemy_bits[i]) {
                            toTarget.h130 = 1;
                            toTarget.h12C = i;
                            toTarget.wA8 = toTarget.enemy_bits[i];
                            toTarget.h124 = 0xFF;
                            toTarget.p128 = toTarget.enemy_bits;
                            toTarget.h126 = toTarget.h100;
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
}

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

void TOBtlDrawDamageValue2(void)
{
    int sp;
    int i;

    func_002EF0D0(&sp, 0, 4);
    func_001F56E8();
    for (i = 0; i < D_00692450; i++) {
        R4Ent16 *base = D_00692050;
        R4Ent16 *e = &base[i];

        if ((u32)e->w8 < 10) {
            func_001F3140(e->w8, e->x, e->y, e->bC, e->bD, e->bE, e->bF);
        } else if (e->w8 == 0x3D) {
            func_001F30E8(0, e->x, e->y, e->bF);
        } else if (e->w8 == 0x3C) {
            func_001F30E8(1, e->x, e->y, e->bF);
        } else if (e->w8 == 0x3B) {
            func_001F30E8(2, e->x, e->y, e->bF);
        } else if (e->w8 == 0x3A) {
            func_001F30E8(3, e->x, e->y, e->bF);
        }
    }
    D_00692450 = 0;
}

void TOBtlDrawChangeSeqAnm0(int p, int x, int y)
{
    TOMakePktSampleBlueWindowXY2(x, y, x + 0xA2, y + 0x2C);
    TOMkpShapeXY(p + 0x1B8, x + 2, y + 2);
    TOMkpEasyMesFontLCenter(func_0021F940(p), x + 0x61, y + 2);
    TOBtlDrawParamPlate(p, x + 2, y + 0x17);
}

extern s16 D_0032432C;
extern s16 D_0032432E;
extern u8 D_00324330;
extern u8 D_00324331;
extern u8 D_00324332;
extern u8 D_00324333;
extern s16 D_00324334;
extern s16 D_00324336;
extern s16 D_00324338;
extern s16 D_0032433A;
extern s16 D_0032433C;
extern s16 D_0032433E;
extern s16 D_00324340;
extern s16 D_00324342;
extern s16 D_00324344;
extern s16 D_00324346;

void TOBtlDrawParamPlate(int id, int x, int y)
{
    s16 r0[4];
    u8 col[4];
    s16 p20[2];
    s16 p30[2];
    s16 p40[2];
    s16 p50[2];
    s16 p60[4];
    s16 p70[4];

    r0[0] = x;
    r0[1] = y;
    r0[2] = D_0032432C;
    r0[3] = D_0032432E;
    col[0] = D_00324330;
    col[1] = D_00324331;
    col[2] = D_00324332;
    col[3] = D_00324333;
    p20[0] = D_00324334 + x;
    p20[1] = D_00324336 + y;
    p30[0] = D_00324338 + x;
    p30[1] = D_0032433A + y;
    p40[0] = D_0032433C + x;
    p40[1] = D_0032433E + y;
    p50[0] = D_00324340 + x;
    p50[1] = D_00324342 + y;
    p60[0] = D_00324344 + x;
    p60[1] = D_00324346 + y;
    p60[2] = D_00324348;
    p60[3] = D_0032434A;
    p70[0] = D_00324350 + p60[0];
    p70[1] = D_00324352 + p60[1];
    p70[2] = D_00324354;
    p70[3] = D_00324356;

    TOMakePktBoxXYWHRGBA(r0[0], r0[1], r0[2], r0[3], col[0], col[1], col[2], col[3]);
    TOMkpShapeXY(0xE9, p20[0], p20[1]);
    func_001F5E80(func_0021F8C0(id), p30[0], p30[1], func_0021F960(func_0021F8C0(id), func_0021F900(id)));
    TOMkpShapeXY(0xEA, p40[0], p40[1]);
    func_001F5E80(func_0021F8E0(id), p50[0], p50[1], 0);
    TOBtlDrawLimitGauge(id, p60[0], p60[1]);
}

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
