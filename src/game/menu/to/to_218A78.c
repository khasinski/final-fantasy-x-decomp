/* tu_243 0x218a78-0x21d048: low; ~TOBtlDrawInfoWin (config/tu_map.tsv) */
#define func_0021BAB8 _hdr_func_0021BAB8
#define func_001FCB88 _hdr_func_001FCB88
#define MsMenuBitStatus _hdr_MsMenuBitStatus
#define MsMenuCountStatus _hdr_MsMenuCountStatus
#define MsMenuBitStatus2 _hdr_MsMenuBitStatus2
#define MsGetChrLimitGauge _hdr_MsGetChrLimitGauge
#define MsGetChrLimitGaugeMax _hdr_MsGetChrLimitGaugeMax
#define D_00692658 _hdr_D_00692658
#define D_00692560 _hdr_D_00692560
#define D_00692478 _hdr_D_00692478
#define D_006925C0 _hdr_D_006925C0
#include "common.h"
#include "ffx/g3.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/u3.h"
#include "ffx/v4.h"
#include "ffx/r4.h"
#include "ffx/s4.h"
#include "ffx/text.h"
#include "ffx/t4.h"
#undef func_0021BAB8
#undef func_001FCB88
#undef MsMenuBitStatus
#undef MsMenuCountStatus
#undef MsMenuBitStatus2
#undef MsGetChrLimitGauge
#undef MsGetChrLimitGaugeMax
#undef D_00692658
#undef D_00692560
#undef D_00692478
#undef D_006925C0

int func_001FCB88(float f, int x, int y, u32 c);
int MsMenuBitStatus(int id);
u8 *MsMenuCountStatus(int id);
int MsMenuBitStatus2(int id);
int MsGetChrLimitGauge(int id);
int MsGetChrLimitGaugeMax(int id);

typedef struct InfoWinParam {
    s16 h0;
    s16 h2;
    s16 h4;
    s16 h6;
    u16 h8[38];
    s16 h54;
    s16 h56;
} InfoWinParam;

typedef struct LimitTimerState {
    s32 on;
    s16 x4;
    s16 x6;
    s32 w8;
    float fC;
    float f10;
    float f14;
    float f18;
} LimitTimerState;

typedef struct Popup {
    s16 h0;
    s16 h2;
    s16 h4;
    s16 h6;
    s16 h8;
    s16 hA;
    s16 hC;
    s16 hE;
    s32 w10;
} Popup;

extern u16 D_00692478;
extern u16 D_00692502;
extern InfoWinParam D_00692508;
extern Popup D_00692560[4];
extern LimitTimerState D_00692658;

extern char D_00570E30[];
extern void func_002198D8(int x, int y, int w, int h, int c);
void func_00219688(int id, int kind, int x, int y);
void func_00219798(int a, int x, int y);

void func_00218A78(int id, int x, int y)
{
    s16 h;
    s16 y1;
    s16 x1;
    int y2;
    int f0;
    int f1;
    int f2;
    int f3;

    if (D_003249AC != 0) {
        f0 = func_002195F8(id, 0);
        f1 = func_002195F8(id, 1);
        f2 = func_002195F8(id, 2);
        f3 = func_002195F8(id, 3);
        h = 0x16;
        if (f0 != 0) {
            h = 0x26;
        }
        if (f1 != 0) {
            h += 0x10;
        }
        if (f2 != 0) {
            h += 0x10;
        }
        if (f3 != 0) {
            h += 0x10;
        }
        if (func_0020B850() == 0 && func_001BD360() == 0) {
            if (D_00692508.h6 > 0) {
                h += 0x12;
            }
        } else {
            if (D_00692508.h6 > 0) {
                h += 0x18;
            }
        }
        TODrawScissorXYWH(0, 0, 0x1FF, 0x19F);
        func_001FA7D0(x, y, 0xA9, h);
        TOMkpShapeXY(0x1AA, x + 0x24, y);
        y1 = y + 3;
        x1 = x + 3;
        y2 = y1 + 2;
        TOMkpShapeXY(0xE9, x1 + 2, y2);
        func_001F63B8(MsGetRamChrHP(id), x1 + 0x54, y2, 0);
        func_001F64A0((int)D_00570E30, x1 + 0x5A, y2);
        func_001F63B8(MsGetRamChrHPmax(id), x1 + 0xA0, y2, 0);
        {
            register int tmp __asm__("$2") = y1 + 0x10;
            y1 = tmp;
        }
        if (f0 != 0) {
            func_002198D8(x1, y1, 0xA3, 0x10, 0);
            func_002198D8(x1, y1, 0xA3, 1, 6);
            func_00219688(id, 0, x1, y1);
            y1 += 0x10;
        }
        if (f1 != 0) {
            func_002198D8(x1, y1, 0xA3, 0x10, 1);
            func_002198D8(x1, y1, 0xA3, 1, 6);
            func_00219688(id, 1, x1, y1);
            y1 += 0x10;
        }
        if (f2 != 0) {
            func_002198D8(x1, y1, 0xA3, 0x10, 2);
            func_002198D8(x1, y1, 0xA3, 1, 6);
            func_00219688(id, 2, x1, y1);
            y1 += 0x10;
        }
        if (f3 != 0) {
            func_002198D8(x1, y1, 0xA3, 0x10, 3);
            func_002198D8(x1, y1, 0xA3, 1, 6);
            func_00219688(id, 3, x1, y1);
            y1 += 0x10;
        }
        if (D_00692508.h6 > 0) {
            y1 += 2;
            if (func_0020B850() == 0 && func_001BD360() == 0) {
                func_002198D8(x1, y1, 0xA3, 0x10, 5);
            } else {
                func_002198D8(x1, y1, 0xA3, 0x16, 5);
            }
            ((int (*)(int, int, int))func_00219798)(id, x1, y1 + 2);
        }
    }
}

extern s16 D_006925B2;
extern s16 D_006925B4;
extern s16 D_006925B6;
extern s16 D_006925B8;
extern s16 D_006925BA;
extern s16 D_006925BC;

INCLUDE_ASM("build/ee_asm/game/menu/to/to_218A78", TOBtlInitInfoWinMes);

extern s8 D_00325020;
void TOBtlSetInfoWinMes(int a);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_218A78", TOBtlCtrlInfoWinMes);

void TOBtlDrawInfoWinMes(void)
{
    int i;

    if (D_003249AD != 0 && (*(s32 *)MsGetSaveMenu() >> 10) & 1) { /* DEBT(CAST): flag word untyped */
        func_001F1D60(D_006925B6, D_006925B8, D_006925BA, D_006925BC);
        for (i = 0; i < 4; i++) {
            if (D_00692560[i].h0 != 0) {
                func_001F37C8(D_00692560[i].w10, D_00692560[i].hA, D_00692560[i].hC);
            }
        }
        TODrawScissorXYWH(0, 0, 0x1FF, 0x19F);
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_218A78", TOBtlSetInfoWinParam);

void TOBtlSetInfoWinMes(int a)
{
    s16 size[2];
    int text;

    TOBtlInitInfoWinMes(a);
    text = MsGetMenuChrInfo(a, 1);
    _TOGetMessageWH(0, (u8 *)text, &size[0], &size[1], 0, 0); /* DEBT(CAST): message text comes back as int */
    if (size[0] < D_00692560[0].h6) {
        D_00692560[0].h0 = 8;
    } else {
        D_00692560[0].h0 = 2;
    }
    D_006925B0 = 1;
    D_00692560[0].hA = D_006925B2;
    D_00692560[0].hC = D_006925B4;
    D_00692560[0].hE = size[0];
    D_00692560[0].w10 = text;
}

int func_002195F8(int id, int kind)
{
    int r;

    switch (kind) {
    case 0:
        r = U3_ID_CALL(func_001DC280, id);
        break;
    case 1:
        r = U3_ID_CALL(func_001DC220, id);
        break;
    case 2:
        r = U3_ID_CALL(func_001DC240, id);
        break;
    case 3:
        r = U3_ID_CALL(func_001DC260, id);
        break;
    }
    return r;
}

void func_00219688(int id, int kind, int x, int y)
{
    V4Rect4 icon = D_00570E38;
    V4Rect4 mark = D_00570E40;
    u32 f = func_002195F8(id, kind);

    TOMkpShapeXY(icon.v[kind], x + 0x18, y);
    if (!(f & 1)) {
        TOMkpShapeXY(mark.v[0], x + 0x18, y);
    }
    if (!((f >> 2) & 1)) {
        TOMkpShapeXY(mark.v[1], x + 0x18, y);
    }
    if (!((f >> 3) & 1)) {
        TOMkpShapeXY(mark.v[2], x + 0x18, y);
    }
    if (!((f >> 1) & 1)) {
        TOMkpShapeXY(mark.v[3], x + 0x18, y);
    }
}

void func_00219798(int a, int x, int y)
{
    int w[2];
    u8 *text;

    if (--D_00692508.h2 == -1) {
        D_00692508.h2 = 0x14;
        if (++D_00692508.h4 == D_00692508.h6) {
            D_00692508.h4 = 0;
        }
    }
    text = (u8 *)MsMenuGetText(1, D_00692508.h8[D_00692508.h4], 1);
    if (func_0020B850() == 0 && func_001BD360() == 0) {
        func_0020E788(text, &w[0]);
        func_001F5790((int)text, x + (0xA9 - w[0]) / 2, y);
    } else {
        _TOGetMessageWH(0, text, (s16 *)&w[0], (s16 *)&w[1], 0, 0);
        func_001F37C8((int)text, x + (0xA9 - w[0]) / 2, y);
    }
}

typedef struct {
    u8 c[7][4][4];
} LibraBarPal;

extern LibraBarPal D_00570E48;

void func_002198D8(int x, int y, int w, int h, int col)
{
    R4Quad q;
    LibraBarPal pal = D_00570E48;
    s16 mid = w - 0x50;
    int x2;

    func_001F25D8(&q, x, y, 0x28, h);
    func_001F2630(&q, 0, pal.c[col][0][0], pal.c[col][0][1], pal.c[col][0][2], pal.c[col][0][3]);
    func_001F2630(&q, 1, pal.c[col][1][0], pal.c[col][1][1], pal.c[col][1][2], pal.c[col][1][3]);
    func_001F2630(&q, 2, pal.c[col][0][0], pal.c[col][0][1], pal.c[col][0][2], pal.c[col][0][3]);
    func_001F2630(&q, 3, pal.c[col][1][0], pal.c[col][1][1], pal.c[col][1][2], pal.c[col][1][3]);
    func_001F26B0(&q);

    x2 = x + 0x28;
    func_001F25D8(&q, x2, y, mid, h);
    func_001F2630(&q, 0, pal.c[col][1][0], pal.c[col][1][1], pal.c[col][1][2], pal.c[col][1][3]);
    func_001F2630(&q, 1, pal.c[col][2][0], pal.c[col][2][1], pal.c[col][2][2], pal.c[col][2][3]);
    func_001F2630(&q, 2, pal.c[col][1][0], pal.c[col][1][1], pal.c[col][1][2], pal.c[col][1][3]);
    func_001F2630(&q, 3, pal.c[col][2][0], pal.c[col][2][1], pal.c[col][2][2], pal.c[col][2][3]);
    func_001F26B0(&q);

    func_001F25D8(&q, x2 + mid, y, 0x28, h);
    func_001F2630(&q, 0, pal.c[col][2][0], pal.c[col][2][1], pal.c[col][2][2], pal.c[col][2][3]);
    func_001F2630(&q, 1, pal.c[col][3][0], pal.c[col][3][1], pal.c[col][3][2], pal.c[col][3][3]);
    func_001F2630(&q, 2, pal.c[col][2][0], pal.c[col][2][1], pal.c[col][2][2], pal.c[col][2][3]);
    func_001F2630(&q, 3, pal.c[col][3][0], pal.c[col][3][1], pal.c[col][3][2], pal.c[col][3][3]);
    func_001F26B0(&q);
}

typedef struct LibraState {
    s16 h0;
    s16 h2;
    s16 h4;
    s16 h6;
    s16 h8;
    u16 hA[36];
    s16 h52;
    s16 h54;
    s16 h56;
    s16 h58;
} LibraState;

extern LibraState D_006925C0;

void func_00219DA0(int v)
{
    int i;
    u8 *p;
    u16 b;

    D_006925C0.h4 = 20;
    D_006925C0.h2 = v;
    D_006925C0.h6 = 0;
    D_006925C0.h8 = 0;
    D_006925C0.h56 = MsGetRamChrHP(v);
    D_006925C0.h58 = MsGetRamChrHPmax(v);
    p = (u8 *)((int (*)(int))func_001DC300)(v);
    for (i = 0; i < 12; i++) {
        if (i == 11) {
            if (p[11] == 0) {
                D_006925C0.hA[D_006925C0.h8++] = 0x1011;
            }
        } else {
            if (p[i] == 0xFF) {
                D_006925C0.hA[D_006925C0.h8++] = i + 0x1006;
            }
        }
    }
    p = (u8 *)((int (*)(int))func_001DC320)(v);
    for (i = 0; i < 13; i++) {
        if (p[i] == 0xFF) {
            D_006925C0.hA[D_006925C0.h8++] = i + 0x1012;
        }
    }
    b = ((u16 (*)(int))func_001DC340)(v);
    for (i = 0; i < 15; i++) {
        if (i != 9 && ((b >> i) & 1)) {
            D_006925C0.hA[D_006925C0.h8++] = i + 0x1020;
        }
    }
}

s16 func_00219F40(void)
{
    return D_006925C0.h0;
}

extern char D_00570EB8[];
extern char D_00570EC0[];
extern char D_00570EC8[];
extern char D_00570ED0[];
extern char D_00570ED8[];
extern char D_00570EE0[];
extern char D_00570EE8[];
extern char D_00570EF0[];
extern char D_00570EF8[];
extern char D_00570F00[];
extern char D_00570F08[];
extern s16 D_0069261C;
extern s16 D_0069261E __asm__("D_0069261C+2");
extern s16 D_00692620;
extern s16 D_00692622;
extern s16 D_00692624;
extern s16 D_00692626;
extern s16 D_00692628;
extern s16 D_0069262A;
extern s16 D_0069262C;
extern s16 D_0069262E;
extern s16 D_00692630;
extern s16 D_00692632;
extern s16 D_00692634;
extern s16 D_00692636;
extern s16 D_00692638;
extern s16 D_0069263A;
extern s16 D_0069263C;
extern s16 D_0069263E;
extern s16 D_00692640;
extern s16 D_00692642;
extern s16 D_00692644;
extern s16 D_00692646;
extern s16 D_00692648;
extern s16 D_0069264A;
extern s16 D_0069264C;
extern s16 D_0069264E;
extern s16 D_00692650;
extern s16 D_00692652;
extern s16 D_00692654;

void TOBtlInitLibraWindow(void)
{
    TOSeqGetRect(2, D_00570EB8, &D_0069261A, &D_0069261C, &D_0069261E, &D_00692620);
    TOSeqGetRect(2, D_00570EC0, &D_00692622, &D_00692624, &D_00692626, &D_00692628);
    TOSeqGetPoint(2, D_00570EC8, &D_0069262A, &D_0069262C);
    TOSeqGetPoint(2, D_00570ED0, &D_0069262E, &D_00692630);
    TOSeqGetPoint(2, D_00570ED8, &D_00692632, &D_00692634);
    TOSeqGetPoint(2, D_00570EE0, &D_00692636, &D_00692638);
    TOSeqGetPoint(2, D_00570EE8, &D_0069263A, &D_0069263C);
    TOSeqGetPoint(2, D_00570EF0, &D_0069263E, &D_00692640);
    TOSeqGetPoint(2, D_00570EF8, &D_00692642, &D_00692644);
    TOSeqGetRect(2, D_00570F00, &D_00692646, &D_00692648, &D_0069264A, &D_0069264C);
    TOSeqGetRect(2, D_00570F08, &D_0069264E, &D_00692650, &D_00692652, &D_00692654);
    func_002EF0D0(&D_006925C0, 0, 0x5A);
    D_006925C0.h0 = 0;
}

void func_0021A128(void)
{
    switch (D_006925C0.h0) {
    case 0:
        break;
    case 1:
        TOSeqStartSceneDrawContinue(2, D_00570F10);
        D_006925C0.h0++;
        break;
    case 2:
        if (TOSeqCheckTermScene(2, D_00570F10) == 1) {
            D_006925C0.h0++;
        }
        break;
    case 4:
        if (!(D_003238E4 & 0x20)) {
            break;
        }
        func_002D70D8(1);
        /* fallthrough */
    case 3:
    case 6:
        D_006925C0.h0++;
        break;
    case 7:
        TOSeqStopScene(2, D_00570F10);
        D_006925C0.h0++;
        break;
    case 8:
        D_006925C0.h0 = 0;
        break;
    }
}

void func_0021A200(void)
{
    switch (D_006925C0.h0) {
    case 0:
    case 1:
    case 2:
        break;
    case 3:
    case 4:
    case 5:
    case 6:
        _TOBtlDrawLibraLeft(D_0069261A, D_0069261C);
        _TOBtlDrawLibraRight(D_0069261A, D_0069261C);
        break;
    case 7:
    case 8:
        break;
    }
}

void func_0021A280(int v)
{
    D_006925C0.h0 = 1;
    D_006925C0.h2 = v;
    func_00219DA0(v);
}

void func_0021A2A0(void)
{
    D_006925C0.h0 = 6;
}

extern s16 D_00692622, D_00692624, D_00692626, D_0069262A, D_0069262C;
extern s16 D_0069262E, D_00692630, D_00692632, D_00692634, D_00692636, D_00692638;
extern s16 D_0069263A, D_0069263C, D_0069263E, D_00692640, D_00692642, D_00692644;
extern s16 D_00692646, D_00692648, D_0069264A;
extern char D_00570E30[];

extern void _void_func_001F63B8(int, int, int, int) __asm__("func_001F63B8"); /* DEBT(TYPE): funcs.h declares int */

void _TOBtlDrawLibraLeft(s32 x, s32 y)
{
    s16 dim[2];
    int px;
    int py;
    int py1;
    int i;

    _TOGetMessageWH(0, (u8 *)func_001BB190(D_006925C0.h2), &dim[0], &dim[1], 0, 0);
    func_001F3808((void *)func_001BB190(D_006925C0.h2), x + D_00692622 + (D_00692626 - dim[0]) / 2, y + D_00692624, 0);
    px = x + D_0069262A;
    py = y + D_0069262C;
    func_001F0328(px, py, 0x9D, 0xE, 0x42000000, 0x42000000);
    TOMkpShapeXY(0xE9, px, py);
    py1 = py + 1;
    _void_func_001F63B8(MsGetRamChrHP(D_006925C0.h2), px + 0x50, py1, 0);
    func_001F64A0((int)D_00570E30, px + 0x55, py1);
    _void_func_001F63B8(MsGetRamChrHPmax(D_006925C0.h2), px + 0x9B, py1, 0);
    TOMkpShapeXY(0x1F8, D_0069261A + D_0069262E, D_0069261C + D_00692630);
    func_001F5E80(MsGetRamChrStr(D_006925C0.h2), x + D_00692632, y + D_00692634, 0);
    TOMkpShapeXY(0x1F9, D_0069261A + D_00692636, D_0069261C + D_00692638);
    func_001F5E80(MsGetRamChrMag(D_006925C0.h2), x + D_0069263A, y + D_0069263C, 0);
    px = x + D_0069263E;
    py = y + D_00692640;
    for (i = 0; i < 4; i++) {
        func_002198D8(px, py, 0xA3, 0x10, i);
        func_002198D8(px, py, 0xA3, 1, 6);
        func_00219688(D_006925C0.h2, i, px, py);
        py += 0x10;
    }
    func_002198D8(px, py, 0xA3, 1, 6);
    TOMkpShapeXY(0x1FA, x + D_00692642, y + D_00692644);
    if (D_006925C0.h8 > 0) {
        int text;
        D_006925C0.h4--;
        if (D_006925C0.h4 == -1) {
            D_006925C0.h4 = 20;
            D_006925C0.h6++;
            if (D_006925C0.h6 == D_006925C0.h8) {
                D_006925C0.h6 = 0;
            }
        }
        text = MsMenuGetText(1, ((u16 *)((u8 *)&D_006925C0 + 0xA))[D_006925C0.h6], 1);
        _TOGetMessageWH(0, (u8 *)text, &dim[0], &dim[1], 0, 0);
        func_001F3808(text, x + D_00692646 + (D_0069264A - dim[0]) / 2, y + D_00692648, 0);
    }
}

void _TOBtlDrawLibraRight(s32 a, s32 b)
{
    s16 dimensions[2];
    s32 widthDiff;
    s32 heightDiff;
    u8 *text;

    /* DEBT(CAST): legacy resource API exposes a text address as an int handle. */
    text = (u8 *)MsGetMenuChrInfo((s32) D_006925C2, 2);
    _TOGetMessageWH(0, text, &dimensions[0], &dimensions[1], 0, 0);
    /* DEBT(ORDER): independent width/height differences retain original scheduling. */
    widthDiff = D_00692652 - dimensions[0];
    /* DEBT(CAST): unsigned halfword read followed by signed height conversion. */
    heightDiff = D_00692654 - (s16) (u16) dimensions[1];
    func_001F37C8((s32) text, a + D_0069264E + widthDiff / 2, b + D_00692650 + heightDiff / 2);
}

void TOBtlInitLimitTimer(void)
{
    R4Fx *fx = (R4Fx *)&D_00692658; /* DEBT(CAST): FxState hides the words at +8/+C */

    fx->w8 = 0;
    fx->wC = 0;
    fx->f10 = 0;
    fx->f14 = 0;
    fx->f18 = 0;
    TOSeqGetPoint(2, D_00570F78, &fx->x4, &fx->x6);
    fx->on = 0;
    if (SndIsSepPlay(0x8000004E) != 0) {
        SndSepStop(0x8000004E);
    }
}

void func_0021A7A8(s16 a, s16 b)
{
    D_00692658.x4 = a;
    D_00692658.x6 = b;
}

void func_0021A7C0(float f)
{
    D_00692658.f10 = f;
    D_00692658.f14 = f;
    D_00692658.f18 = f;
    D_00692658.on = 1;
}

void TOBtlCtrlLimitTimer(void)
{
    int r;

    if (D_00692658.on == 2) {
        D_00692658.fC += 1.0f;
        if (TOGetFFXVideoMode() == 0) {
            D_00692658.f14 = D_00692658.f10 - D_00692658.fC / 30.0f;
        } else {
            D_00692658.f14 = D_00692658.f10 - D_00692658.fC / 25.0f;
        }
        if (D_00692658.f14 <= 0.0) {
            D_00692658.f14 = 0.0f;
            D_00692658.f18 = 0.0f;
        } else {
            r = func_001ACEA0() % 10;
            D_00692658.f18 = (float)((int)(D_00692658.f14 * 10.0f) * 10 + r) / 100.0f;
        }
    }
}


int func_0021A8F0(void)
{
    if (D_00692658.on != 0) {
        if (D_00692658.f18 < 1.0) {
            return func_001FCB88(D_00692658.f18, D_00692658.x4, D_00692658.x6, 0x80008080);
        } else {
            return func_001FCB88(D_00692658.f18, D_00692658.x4, D_00692658.x6, 0x80808080);
        }
    }
}

void TOBtlStartLimitTimer(void)
{
    if (D_00692658.on != 2) {
        D_00692658.on = 2;
        if (SndIsSepPlay(0x8000004E) != 0) {
            return;
        }
        SndSepPlaySimple(0x8000004E);
    }
}

void TOBtlStopLimitTimer(void)
{
    D_00692658.on = 1;
    if (SndIsSepPlay(0x8000004E)) {
        SndSepStop(0x8000004E);
    }
}

void TOBtlStandbyLimitTimer(void)
{
    D_00692658.on = 1;
    if (SndIsSepPlay(0x8000004E)) {
        SndSepStop(0x8000004E);
    }
}

void TOBtlClearLimitTimer(void)
{
    D_00692658.on = 0;
    if (SndIsSepPlay(0x8000004E)) {
        SndSepStop(0x8000004E);
    }
}

float func_0021AA78(void)
{
    return D_0069266C;
}

float func_0021AA88(void)
{
    return D_00692668;
}

s16 func_0021AA98(void)
{
    return D_00692678.state;
}

void TOBtlInitAuronLimitWindow(void)
{
    TOSeqGetNum(2, D_00570F80, &D_00692656);
    TOInitPadData();
    TOBtlInitLimitTimer();
    func_002EF0D0(&D_00692678, 0, sizeof(D_00692678));
    D_00692678.state = 0;
    TOSeqGetPoint(2, D_00570F88, &D_00692678.h2, &D_00692678.h4);
    D_00692678.h8 = 0;
    D_00692678.h6 = 4;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_218A78", TOBtlCtrlAuronLimitWindow);
INCLUDE_RODATA("build/ee_asm/game/menu/to/to_218A78/rodata", jtbl_00570FB0);

void func_0021AD80(void)
{
    s16 size[2];
    int id;
    int i;

    switch (D_00692678.state) {
    case 0:
    case 1:
    case 2:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        break;
    case 3:
    case 4:
        for (i = D_00692678.h8; i < D_00692678.wC; i++) {
            func_001FC770(D_00692678.w10[i], D_00692678.h2 + i * 30, D_00692678.h4);
        }
        id = MsGetRomBtlText(0x3011, 0);
        _TOGetMessageWH(0, (u8 *)id, &size[0], &size[1], 0, 0); /* DEBT(CAST): message text comes back as int */
        func_001F3808(id, (0x200 - size[0]) / 2, D_00692656, 0);
        break;
    }
}

void func_0021AEB0(int kind)
{
    int sel = 0;

    switch (kind) {
    case 0x22:
        sel = 0;
        break;
    case 0x32:
        sel = 1;
        break;
    case 0x42:
        sel = 2;
        break;
    case 0x52:
        sel = 3;
        break;
    }
    func_0021A7C0(func_00265F30(sel));
    D_00692678.w10 = (u16 *)func_00265F48(sel);
    for (D_00692678.wC = 0; D_00692678.w10[D_00692678.wC] != 0xFFFF; D_00692678.wC++) {
    }
    D_00692678.state = 1;
}

void func_0021AF88(void)
{
    D_00692678.state = 9;
}

s16 func_0021AF98(void)
{
    return D_00692690.state;
}

void TOBtlInitTidusLimitWindow(void)
{
    TOSeqGetNum(2, D_00570F80, &D_00692656);
    TOInitPadData();
    TOBtlInitLimitTimer();
    func_002EF0D0(&D_00692690, 0, sizeof(D_00692690));
    D_00692690.state = 0;
    TOSeqGetPoint(2, D_00571010, &D_00692690.h2, &D_00692690.h4);
    TOSeqGetNum(2, D_00571018, &D_00692690.h6);
    TOSeqGetColor(2, D_00571020, &D_00692690.w14);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_218A78", TOBtlCtrlTidusLimitWindow);
INCLUDE_RODATA("build/ee_asm/game/menu/to/to_218A78/rodata", jtbl_00571030);

void func_0021B358(void)
{
    s16 size[2];
    int id;

    switch (D_00692690.state) {
    case 0:
    case 1:
    case 2:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        break;
    case 3:
    case 4:
        func_00201B60(D_00692690.h2, D_00692690.h4, D_00692690.h6);
        func_001F0328(D_00692690.h8, D_00692690.h4, D_00692690.hC, 9, D_00692690.w14, D_00692690.w14);
        TOMkpShapeXY(0x1DD, D_00692690.hE, D_00692690.h4);
        id = MsGetRomBtlText(0x3010, 0);
        _TOGetMessageWH(0, (u8 *)id, &size[0], &size[1], 0, 0); /* DEBT(CAST): message text comes back as int */
        func_001F3808(id, (0x200 - size[0]) / 2, D_00692656, 0);
        break;
    }
}

void TOBtlOpenTidusLimitWindow(int kind)
{
    int sel = 0;

    switch (kind) {
    case 0x20:
        sel = 0;
        break;
    case 0x30:
        sel = 1;
        break;
    case 0x40:
        sel = 2;
        break;
    case 0x50:
        sel = 3;
        break;
    }
    func_0021A7C0(func_00265F60(sel));
    D_00692690.h10 = func_00265F78(sel);
    D_00692690.hE = D_00692690.h2;
    D_00692690.hC = func_00265FB8(sel);
    D_00692690.h8 = D_00692690.h2 + D_00692690.h6 / 2 - D_00692690.hC / 2;
    D_00692690.hA = D_00692690.h2 + D_00692690.h6 / 2 + D_00692690.hC / 2;
    D_00692690.state = 1;
}

void func_0021B528(void)
{
    D_00692690.state = 9;
}

s16 func_0021B538(void)
{
    return D_006926A8.state;
}

void TOBtlInitLuluLimitWindow(void)
{
    TOSeqGetNum(2, D_00570F80, &D_00692656);
    TOInitPadData();
    TOBtlInitLimitTimer();
    func_002EF0D0(&D_006926A8, 0, sizeof(D_006926A8));
    D_006926A8.state = 0;
    TOSeqGetPoint(2, D_00571090, &D_006926A8.h2, &D_006926A8.h4);
    D_006926A8.h6 = 0xC0;
    TOSeqGetColor(2, D_00571098, &D_006926A8.w8);
    TOSeqGetColor(2, D_005710A0, &D_006926A8.wC);
    TOSeqGetPoint(2, D_005710A8, &D_006926A8.h10, &D_006926A8.h12);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_218A78", TOBtlCtrlLuluLimitWindow);
INCLUDE_RODATA("build/ee_asm/game/menu/to/to_218A78/rodata", jtbl_005710E0);

void func_0021B9C8(void)
{
    s16 size[2];
    int id;

    switch (D_006926A8.state) {
    case 0:
    case 1:
    case 2:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        break;
    case 3:
    case 4:
        func_001FCC88(D_006926A8.b17, D_006926A8.h10, D_006926A8.h12, 0x80808080);
        func_001F0580(D_006926A8.h2, D_006926A8.h4, D_006926A8.h14, 9, D_006926A8.w8, D_006926A8.wC, D_006926A8.h6);
        func_00201B60(D_006926A8.h2, D_006926A8.h4, D_006926A8.h6);
        id = MsGetRomBtlText(0x3012, 0);
        _TOGetMessageWH(0, (u8 *)id, &size[0], &size[1], 0, 0); /* DEBT(CAST): message text comes back as int */
        func_001F3808(id, (0x200 - size[0]) / 2, D_00692656, 0);
        break;
    }
}

void _m2c_func_0021BAB8_NkzSetLuluLimitTbl(s32) __asm__("NkzSetLuluLimitTbl");
void _m2c_func_0021BAB8_func_0021A7C0(float) __asm__("func_0021A7C0");
float _m2c_func_0021BAB8_func_00265FF8(s32) __asm__("func_00265FF8");
void func_0021BAB8(s32 arg0) {
    s32 temp_16;

    temp_16 = arg0 - 0x3078;
    _m2c_func_0021BAB8_func_0021A7C0(_m2c_func_0021BAB8_func_00265FF8(temp_16));
    _m2c_func_0021BAB8_NkzSetLuluLimitTbl(temp_16);
    D_006926A8.b17 = 1;
    D_006926A8.b16 = *D_006926D8;
    D_006926A8.h14 = 3;
    D_006926A8.state = 1;
}

void func_0021BB20(void)
{
    D_006926A8.state = 7;
}

void TOBtlSetLuluLimitTbl(u8 *s)
{
    int i;

    for (i = 0; i < 16; i++) {
        if (i == 0) {
            D_006926D8[0] = s[0] - '0';
        } else {
            int n = s[i] - '0';

            D_006926D8[i] = D_006926D8[i - 1] + n;
        }
    }
}

void TOBtlInitWakkaLimitWindow(void)
{
    TOInitPadData();
    TOSeqGetNum(2, D_00570F80, &D_00692656);
    D_003249AE = 0;
}

void func_0021BBC8(void)
{
    TOBtlCloseSignWindow();
    TOSeqStartSceneDrawContinue(2, D_00571138);
    D_003249AE = 1;
}

void TOBtlCloseWakkaLimitWindow(void)
{
    TOSeqStopScene(2, D_00571138);
    D_003249AE = 0;
}

int func_0021BC30(void)
{
    if (D_003249AE == 1) {
        return TOSeqCheckTermScene(2, D_00571138);
    }
    return 0;
}

void TOBtlStartWakkaSuccessAnm(void)
{
    TOSeqStartScene(2, D_00570FA0);
    func_002D70D8(0x68);
}

int func_0021BC98(void)
{
    return TOSeqCheckTermScene(2, D_00570FA0);
}

void TOBtlDrawWakkaLimitWindow(void)
{
    s16 size[2];
    int text;

    if (D_003249AE != 0) {
        TOTransTexture();
        TOTransImageHL(func_0020B8C0(), 0x3F00, 0x13, 0, 0, 0x100, 0x100);
        TOSetPktBuffAdrs(0x1F00000, 0x100000, 0xF0000);
        func_001EF940();
        TOSeqDraw(2, 4);
        if (TOSeqGetSceneStatus(2, D_00571138) == 3) {
            text = MsGetRomBtlText(0x3013, 0);
            _TOGetMessageWH(0, (u8 *)text, &size[0], &size[1], 0, 0); /* DEBT(CAST): message text comes as int */
            func_001F3808(text, (0x200 - size[0]) / 2, D_00692656, 0);
        }
        func_001EF978();
        TODrawKick();
    }
}

void func_0021BDC0(void) {
}

void func_0021BDC8(R4Wk *o) {
    R4Rgb3 t = D_00571140;
    o->h3C -= func_00208060();
    o->f78 = func_0021BDC0;
}

void func_0021BE28(R4Wk *o)
{
    R4Rgb3 t = D_00571140;

    if (D_003249B4 == 0) {
        D_00690674 = o->h3C;
    }
    o->h3C += func_00208060();
    o->f78 = func_0021BDC0;
}

void TODrawCommandValue(int owner, int id, int kind, int x, int y, int c)
{
    int base;
    int text;
    OfsTbl *t = MsGetComData(id, &base);

    switch (kind) {
    case 0x100:
        text = MsGetCommandMP(owner, t);
        break;
    case 0x200:
        text = func_001BFE30(id);
        break;
    }
    if (text != 0) {
        func_001F35D0(2, text, x, y, c);
    }
}

typedef struct {
    u8 pad00[0xC];
    s32 hp;
    s32 hp_disp;
    s32 hp_step;
    u8 hp_flag;
    u8 pad19[0xB];
    s32 mp;
    s32 mp_disp;
    s32 mp_step;
    u8 mp_flag;
    u8 pad31[3];
    s32 lim;
    s32 lim_disp;
    s16 timer;
    s16 pad3E;
    s16 st_cnt;
    u16 st_buf[0x27];
} BtlStatusWinEnt;

extern u16 D_006926E8[3];
extern BtlStatusWinEnt D_006926F0[3];
int TOBtlMakeStatusBuff(int id, u16 *buf);

void TOBtlInitStatusWin(void)
{
    s32 count;
    u16 *ids;
    int i;

    func_002EF0D0(D_006926F0, 0, sizeof(D_006926F0));
    ids = TOGetSaveWindow(0, 0x12, &count);
    for (i = 0; i < 3; i++) {
        D_006926E8[i] = ids[i];
    }
    for (i = 0; i < 3; i++) {
        if (D_006926E8[i] != 0xFF) {
            int v;
            int g;
            int gmax;

            D_006926F0[i].hp_disp = D_006926F0[i].hp = MsGetRamChrHP(D_006926E8[i]);
            D_006926F0[i].hp_step = 0;
            D_006926F0[i].hp_flag = 0;

            D_006926F0[i].mp_disp = D_006926F0[i].mp = MsGetRamChrMP(D_006926E8[i]);
            D_006926F0[i].mp_step = 0;
            D_006926F0[i].mp_flag = 0;

            g = MsGetChrLimitGauge(D_006926E8[i]);
            gmax = MsGetChrLimitGaugeMax(D_006926E8[i]);
            D_006926F0[i].lim_disp = D_006926F0[i].lim = (g * D_00324354) / gmax;
            D_006926F0[i].st_cnt = TOBtlMakeStatusBuff(D_006926E8[i], D_006926F0[i].st_buf);
            D_006926F0[i].timer = 0x14;
        }
    }
}

typedef struct {
    u8 pad00[0xC];
    u16 h0C;
    u8 pad0E[0xCC - 0xE];
} R4Rec_0C; /* DEBT(NAME): R4Rec offset +0xC view */

void func_0021D038(s8 v);
extern u8 func_0021F960(int, int);

void TOBtlCtrlStatusWin(void)
{
    s32 dummy;
    s32 count;
    u16 *ids;
    int i;

    if (D_003252A4 == 0xFF) {
        func_0021D038(3);
    } else {
        u8 *com = (u8 *)MsGetComData(((R4Rec_0C *)D_003249C0)[D_00325020].h0C, &dummy); /* DEBT(CAST): com data byte view */
        u8 b = com[0x22];
        if (b & 1) {
            int mode = (b >> 1) & 3;
            if (D_006928A0 != mode) {
                TOBtlInitStatusWin();
            }
            func_0021D038(mode);
        } else {
            TOBtlInitStatusWin();
            func_0021D038(3);
        }
    }

    ids = TOGetSaveWindow(0, 0x12, &count);
    if (func_002EEE88(ids, D_006926E8, 6) != 0) {
        TOBtlInitStatusWin();
    }

    for (i = 0; i < 3; i++) {
        if (D_006926E8[i] != 0xFF) {
            int hp = MsGetRamChrHP(D_006926E8[i]);
            int mp = MsGetRamChrMP(D_006926E8[i]);
            int hp_max = MsGetRamChrHPmax(D_006926E8[i]);
            MsGetRamChrMPmax(D_006926E8[i]);

            if (hp != D_006926F0[i].hp) {
                int diff = hp - D_006926F0[i].hp;
                D_006926F0[i].hp_flag = 10;
                D_006926F0[i].hp_step = diff / 10;
                D_006926F0[i].hp = hp;
            }
            if ((s8)D_006926F0[i].hp_flag > 0) {
                D_006926F0[i].hp_disp += D_006926F0[i].hp_step;
                D_006926F0[i].hp_flag--;
            } else {
                D_006926F0[i].hp_disp = hp;
                D_006926F0[i].hp_step = 0;
                D_006926F0[i].hp_flag = 0;
            }
            D_006926F0[i].pad19[0] = func_0021F960(D_006926F0[i].hp_disp, hp_max);

            if (mp != D_006926F0[i].mp) {
                int diff = mp - D_006926F0[i].mp;
                D_006926F0[i].mp_flag = 10;
                D_006926F0[i].mp_step = diff / 10;
                D_006926F0[i].mp = mp;
            }
            if ((s8)D_006926F0[i].mp_flag > 0) {
                D_006926F0[i].mp_disp += D_006926F0[i].mp_step;
                D_006926F0[i].mp_flag--;
            } else {
                D_006926F0[i].mp_disp = mp;
                D_006926F0[i].mp_step = 0;
                D_006926F0[i].mp_flag = 0;
            }
            D_006926F0[i].pad31[0] = 0;

            if (MsGetChrLimitGaugeMax(D_006926E8[i]) > 0) {
                int g = MsGetChrLimitGauge(D_006926E8[i]);
                int gmax = MsGetChrLimitGaugeMax(D_006926E8[i]);
                D_006926F0[i].lim = (g * D_00324354) / gmax;
            } else {
                D_006926F0[i].lim = 0;
            }
            if (D_006926F0[i].lim_disp < D_006926F0[i].lim) {
                D_006926F0[i].lim_disp += 6;
            }
            if (D_006926F0[i].lim_disp > D_006926F0[i].lim) {
                D_006926F0[i].lim_disp = D_006926F0[i].lim;
            }
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_218A78", TOBtlDrawStatusWin);

void func_0021D038(s8 v)
{
    D_006928A0 = v;
}
