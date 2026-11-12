/* tu_243 0x218a78-0x21d048: low; ~TOBtlDrawInfoWin (config/tu_map.tsv) */
#define func_0021BAB8 _hdr_func_0021BAB8
#define func_001FCB88 _hdr_func_001FCB88
#define D_00692658 _hdr_D_00692658
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
#undef D_00692658

int func_001FCB88(float f, int x, int y, u32 c);

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

extern InfoWinParam D_00692508;
extern LimitTimerState D_00692658;

INCLUDE_ASM("build/ee_asm/game/menu/to/to_218A78", func_00218A78);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_218A78", TOBtlInitInfoWinMes);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_218A78", TOBtlCtrlInfoWinMes);

void TOBtlDrawInfoWinMes(void)
{
    int i;

    if (D_003249AD != 0 && (*(s32 *)MsGetSaveMenu() >> 10) & 1) { /* DEBT(CAST): flag word untyped */
        func_001F1D60(D_006925B6, D_006925B8, D_006925BA, D_006925BC);
        for (i = 0; i < 4; i++) {
            if ((&D_00692560)[i].h0 != 0) { /* DEBT(TYPE): D_00692560 is the first of 4 records */
                func_001F37C8((&D_00692560)[i].w10, (&D_00692560)[i].hA, (&D_00692560)[i].hC);
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
    if (size[0] < D_00692560.h6) {
        D_00692560.h0 = 8;
    } else {
        D_00692560.h0 = 2;
    }
    D_006925B0 = 1;
    D_00692560.hA = D_006925B2;
    D_00692560.hC = D_006925B4;
    D_00692560.hE = size[0];
    D_00692560.w10 = text;
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

INCLUDE_ASM("build/ee_asm/game/menu/to/to_218A78", func_002198D8);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_218A78", func_00219DA0);

s16 func_00219F40(void)
{
    return D_006925C0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_218A78", TOBtlInitLibraWindow);

void func_0021A128(void)
{
    switch (D_006925C0) {
    case 0:
        break;
    case 1:
        TOSeqStartSceneDrawContinue(2, D_00570F10);
        D_006925C0++;
        break;
    case 2:
        if (TOSeqCheckTermScene(2, D_00570F10) == 1) {
            D_006925C0++;
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
        D_006925C0++;
        break;
    case 7:
        TOSeqStopScene(2, D_00570F10);
        D_006925C0++;
        break;
    case 8:
        D_006925C0 = 0;
        break;
    }
}

void func_0021A200(void)
{
    switch (D_006925C0) {
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
    D_006925C0 = 1;
    (&D_006925C0)[1] = v;
    func_00219DA0(v);
}

void func_0021A2A0(void)
{
    D_006925C0 = 6;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_218A78", _TOBtlDrawLibraLeft);

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

void TOBtlCtrlAuronLimitWindow(void)
{
    u16 key;
    s8 flag;
    float x;

    switch (D_00692678.state) {
    case 0:
        break;
    case 1:
        D_0069066C = 0;
        TOSeqStartSceneDrawContinue(2, D_00570F90);
        D_00692678.state++;
        break;
    case 2:
        if (TOSeqCheckTermScene(2, D_00570F90) == 1) {
            TOSeqStartScene(2, D_00570F98);
            D_00692678.state++;
        }
        break;
    case 3:
        TOBtlStandbyLimitTimer();
        D_00692678.state++;
        break;
    case 4:
        TOBtlStartLimitTimer();
        if (func_0021AA78() <= 0.0f) {
            D_00692678.state = 7;
            break;
        }
        key = D_003238E4;
        if (key != 0) {
            if (key == D_00692678.w10[D_00692678.h8]) {
                D_00692678.h8++;
            } else {
                func_002D70D8(0x69);
                D_00692678.h8 = 0;
            }
            if (D_00692678.h8 >= D_00692678.wC) {
                D_00692678.state = 5;
            }
        }
        break;
    case 5:
        TOBtlStopLimitTimer();
        D_0069066C = 1;
        TOSeqStartScene(2, D_00570FA0);
        func_002D70D8(0x68);
        D_00692678.state = 6;
        break;
    case 6:
        if (TOSeqCheckTermScene(2, D_00570FA0) == 1) {
            TOSeqStopScene(2, D_00570F90);
            TOSeqStopScene(2, D_00570F98);
            D_00692678.state = 9;
        }
        break;
    case 7:
        TOBtlStopLimitTimer();
        D_0069066C = 0;
        D_00692678.state = 8;
        break;
    case 8:
        TOSeqStopScene(2, D_00570F90);
        TOSeqStopScene(2, D_00570F98);
        D_00692678.state = 9;
        break;
    case 9:
        D_00692678.state++;
        break;
    case 10:
        flag = D_0069066C;
        x = func_0021AA78();
        func_001E35D8(2, flag, x, func_0021AA88());
        TOBtlInitLimitTimer();
        D_00692678.state = 0;
        break;
    }
}

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

void TOBtlCtrlLuluLimitWindow(void)
{
    DirSeq8 cw = D_005710B0;
    DirSeq8 ccw = D_005710B8;
    int dir = 0xFF;
    int i;
    u8 x;
    u8 y;
    s8 first;
    int goal;
    s8 n;
    u8 level;
    float f;

    switch (D_006926A8.state) {
    case 0:
        break;
    case 1:
        TOSeqStartSceneDrawContinue(2, D_005710C0);
        D_006926A8.state++;
        break;
    case 2:
        if (TOSeqCheckTermScene(2, D_005710C0) == 1) {
            TOSeqStartScene(2, D_005710C8);
            D_006926A8.state++;
        }
        break;
    case 3:
        TOBtlStartLimitTimer();
        D_006926A8.state++;
        break;
    case 4:
        if (func_0021AA78() <= 0.0f) {
            D_006926A8.state = 6;
            break;
        }
        for (i = 0; i < 2; i++) {
            if (i == 0) {
                x = TkGetControlerAnalogHist(0, 0, 0, -1);
                y = TkGetControlerAnalogHist(0, 0, 1, -1);
            } else {
                x = TkGetControlerAnalogHist(0, 0, 0, 0);
                y = TkGetControlerAnalogHist(0, 0, 1, 0);
            }
            if (x >= 0xA0 && y < 0x60) {
                dir = 4;
            } else if (x >= 0xA0 && y >= 0xA0) {
                dir = 5;
            } else if (x < 0x60 && y >= 0xA0) {
                dir = 6;
            } else if (x < 0x60 && y < 0x60) {
                dir = 7;
            }
            if (dir != 0xFF) {
                n = D_006926A8.count;
                if (n == 0) {
                    D_006926A8.seq[0] = dir;
                    D_006926A8.count++;
                } else if (D_006926A8.seq[n - 1] != dir) {
                    D_006926A8.seq[D_006926A8.count++] = dir;
                }
            }
        }
        if (D_006926A8.count >= 5) {
            first = D_006926A8.seq[0];
            if (func_002EEE88(D_006926A8.seq, &cw.d[first - 4], 5) == 0
                || func_002EEE88(D_006926A8.seq, &ccw.d[7 - first], 5) == 0) {
                TOSeqStartScene(2, D_005710D0);
                if (D_006926A8.b17 >= 0x10) {
                    D_006926A8.b17 = 0x10;
                } else if (++D_006926A8.b16 >= D_006926D8[D_006926A8.b17]) {
                    D_006926A8.b17++;
                }
            }
            func_002EEFCC(D_006926A8.seq, &D_006926A8.seq[4], 12);
            D_006926A8.count = 0;
        }
        goal = D_006926A8.h6 / 16 * D_006926A8.b17;
        if (D_006926A8.h14 < goal) {
            D_006926A8.h14 += 3;
        } else {
            D_006926A8.h14 = goal;
        }
        break;
    case 5:
        break;
    case 6:
        TOBtlStopLimitTimer();
        TOBtlInitLimitTimer();
        level = D_006926A8.b17;
        f = func_0021AA78();
        func_001E35D8(5, level, f, func_0021AA88());
        D_006926A8.state = 7;
        break;
    case 7:
        D_006926A8.state++;
        break;
    case 8:
        TOSeqStopScene(2, D_005710C0);
        TOSeqStopScene(2, D_005710C8);
        D_006926A8.state++;
        break;
    case 9:
        D_006926A8.state = 0;
        break;
    }
}

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

INCLUDE_ASM("build/ee_asm/game/menu/to/to_218A78", func_0021BDC8);

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

INCLUDE_ASM("build/ee_asm/game/menu/to/to_218A78", TOBtlInitStatusWin);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_218A78", TOBtlCtrlStatusWin);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_218A78", TOBtlDrawStatusWin);

void func_0021D038(s8 v)
{
    D_006928A0 = v;
}
