/* tu_253 0x228b08-0x22b9f8: medium; ~Tk (config/tu_map.tsv) */
#define func_0022B598 _hdr_func_0022B598
#include "common.h"
#include "ffx/r5.h"
#include "ffx/q5.h"
#include "ffx/w7.h"
#include "ffx/s5.h"
#include "ffx/u3.h"
#include "ffx/u4.h"
#include "ffx/v5.h"
#undef func_0022B598

void TkMn2InitStatusBG(void)
{
    D_00693A74 = 0;
    D_00693A76 = 0;
}

void TMn2SetStatusBGDiff(s16 v)
{
    D_00693A74 = v;
}

void TkMn2CalcStatusBGRatio(void)
{
    D_00693A76 += D_00693A74;
    D_00693A76 = D_00693A76 < 0 ? 0 : (D_00693A76 > 0x1000 ? 0x1000 : D_00693A76);
}

s16 func_00228B80(void)
{
    return D_00693A76;
}

void func_00228B90(s16 *dst, int a1)
{
    if (a1) {
        dst[0] = D_006939A8[0] + D_006938B8[0];
        dst[1] = D_006939A8[1] + D_006938B8[1];
    } else {
        dst[0] = D_00693960[0] + D_006938B8[0];
        dst[1] = D_00693960[1] + D_006938B8[1];
    }
}

void func_00228BE8(s16 *dst, int a1)
{
    if (a1) {
        dst[0] = D_006939C0[0] + D_006938B8[0];
        dst[1] = D_006939C0[1] + D_006938B8[1];
    } else {
        dst[0] = D_00693978[0] + D_006938B8[0];
        dst[1] = D_00693978[1] + D_006938B8[1];
    }
}

int TkMn2GetStatusPos(void) /* DEBT(TYPE): declared int in funcs.h, no value returned */
{
    D_0032587C = ((u32 (*)(const void *))TkMn2SeqGetColor)(D_00571470); /* DEBT(TYPE): stored into u32 without conversion */
    D_00325880 = ((u32 (*)(const void *))TkMn2SeqGetColor)(D_00571480);
    func_002273A0(D_00571490, D_00693880);
    func_00227460(D_005714A0, D_00693888);
    func_002273A0(D_005714B0, D_00693890);
    func_002273A0(D_005714C0, D_003258B8);
    func_002273A0(D_005714D0, D_003258C0);
    func_002273A0(D_005714E0, D_006938B0);
    func_00227460(D_005714F0, D_00693A70);
    func_002273A0(D_00571500, D_00693A30);
    func_00227460(D_00571508, D_00693A38);
    D_00693A3C = TkMn2SeqGetColor(D_00571510);
    D_00693A40 = TkMn2SeqGetColor(D_00571520);
    D_00693898 = TkMn2SeqGetColor(D_00571530);
    D_0069389C = TkMn2SeqGetColor(D_00571540);
    D_006938A0 = TkMn2SeqGetColor(D_00571550);
    D_006938A4 = TkMn2SeqGetColor(D_00571560);
    D_006938A8 = TkMn2SeqGetColor(D_00571570);
    D_00693A2C = TkMn2SeqGetColor(D_00571580);
    func_00227460(D_00571590, D_006938D8);
    func_00227460(D_005715A0, D_006938E0);
    func_00227460(D_005715B0, D_00325878);
    D_006938E4 = V5_TkMn2SeqGetNum_int(D_005715C0);
    TkMn2GetCommonPlate(&D_006938E8, D_005715D0, D_005715E0, D_005715F0, 0xd8, 0xd9);
    TkMn2GetCommonPlate(&D_00693900, D_00571600, D_00571610, D_00571620, 0xd8, 0xd9);
    TkMn2GetCommonPlate(&D_00693918, D_00571630, D_00571640, D_00571650, 0x109, 0xd9);
    TkMn2GetCommonPlate(&D_00693930, D_00571660, D_00571670, D_00571670, 0x109, 0xd9);
    TkMn2GetCommonPlate(&D_00693948, D_005714B0, D_00571530, D_00571530, 0, 0);
    TkMn2GetCommonPlate(D_00693960, D_005714C0, D_00571540, D_00571550, 0xda, 0xdb);
    TkMn2GetCommonPlate(D_00693978, D_005714D0, D_00571560, D_00571570, 0, 0);
    TkMn2GetCommonPlate(&D_006939D8, D_005714E0, D_00571530, D_00571530, 0xde, 0xdf);
    TkMn2GetCommonPlate(&D_00325888, D_00571680, D_00571690, D_005716A0, 0xd8, 0xd9);
    func_00227460(D_005716B0, D_003258A0);
    func_00227460(D_005716C0, D_003258A8);
    func_00227460(D_005714A0, D_00693A28);
    D_00693A44 = V5_TkMn2SeqGetNum_int(D_005716D0);
    D_00693990 = D_00693948;
    *(FlagRec *)D_006939A8 = *(FlagRec *)D_00693960; /* DEBT(CAST): declared u16[] in r5.h */
    *(FlagRec *)D_006939C0 = *(FlagRec *)D_00693978;
    D_006939F0 = D_006939D8;
    D_00693990.rect[1] += D_00693A44;
    ((FlagRec *)D_006939A8)->rect[1] += D_00693A44;
    ((FlagRec *)D_006939C0)->rect[1] += D_00693A44;
    D_006939F0.rect[1] += D_00693A44;
    func_00227460(D_005716E0, D_00693A08);
    func_00227460(D_005716F0, D_00693A10);
    func_00227460(D_00571700, D_00693A18);
    func_00227460(D_00571710, D_00693A20);
    func_00227460(D_00571720, D_006938B8);
    func_00227460(D_00571730, D_006938C0);
    func_00227460(D_00571740, D_006938C8);
    func_00227460(D_005716F0, D_006938D0);
    D_00693A5C = V5_TkMn2SeqGetNum_int(D_00571750);
    D_00693A60 = V5_TkMn2SeqGetNum_int(D_00571760);
    D_00693A64 = V5_TkMn2SeqGetNum_int(D_00571770);
    func_00227460(D_00571780, D_00693A68);
    func_002273A0(D_00571790, D_00693A48);
    func_00227460(D_005717A0, D_00693A50);
    func_00227460(D_005717B0, D_00693A58);
    func_00227460(D_005717C0, D_003258B0);
}

int func_002292B8(int x, int dir) {
    if (dir < 0) {
        x = 0x1000 - func_00125D90(0x1000 - x);
    } else {
        x = func_00125D90(x);
    }
    return x;
}

extern s32 D_003258C8, D_003258CC, D_003258D0, D_003258D4;
extern char D_005717D0[];
extern int TOMenuGetFirstReadEndFlag(void);
extern void TkMenuMainFreeWindowGroup(int);
extern int func_00242818(void);
extern int func_002429D0(void);
extern void func_002429F0(void);
extern void func_00242980(void);
extern void TkMenuCloseStatusPageWindow(int);
extern void TkMenuMainSleepMenu(int);

void TkMenuCtrlStatus(Task *t)
{
    s32 *st = &t->x1C;
    int pad = func_00220318();
    int rep = TOMenuGetControlPadRep();
    int trg = TOMenuGetControlPadTrg();

    func_00225500(0, &D_003258C8, &D_003258CC, &D_003258D0, &D_003258D4);
    TkMn2CalcStatusBGRatio();

    switch (*st) {
    case 0:
        if (TOMenuGetFirstReadEndFlag() != 0) {
            *st = 1;
        }
        break;
    case 1:
        *st = 2;
        break;
    case 3:
        TMn2SetStatusBGDiff(-0x155);
        func_00227490(D_005717D0);
        /* fallthrough */
    case 2:
        *st = 4;
        break;
    case 4:
        if (trg & 0x20) {
            SndSepPlaySimple(0x80000001);
            TkMenuMainFreeWindowGroup(0);
            *st = 5;
        } else if (trg & 0x40) {
            SndSepPlaySimple(0x80000004);
            *st = 0x11;
        } else if (func_00242818() >= 2 && func_002429D0() != 0) {
            if ((rep & 4) && pad == 4) {
                SndSepPlaySimple(0x80000004);
                func_002429F0();
            } else if ((rep & 8) && pad == 8) {
                SndSepPlaySimple(0x80000004);
                func_00242980();
            }
        }
        break;
    case 5:
        TMn2SetStatusBGDiff(0x155);
        func_00227480(D_005717D0);
        TkMenuOpenStatusPageWindow(0, 0, 0, 0);
        *st = 6;
        break;
    case 6:
        if (trg & 0x20) {
            SndSepPlaySimple(0x80000001);
            TkMenuCloseStatusPageWindow(0);
            *st = 7;
        } else if (trg & 0x40) {
            SndSepPlaySimple(0x80000004);
            TkMenuCloseStatusPageWindow(0);
            *st = 3;
        }
        break;
    case 7:
        TkMenuOpenStatusPageWindow(0, 1, 0x40, 0);
        *st = 8;
        break;
    case 8:
        if (trg & 0x20) {
            SndSepPlaySimple(0x80000001);
            TkMenuCloseStatusPageWindow(1);
            *st = 9;
        } else if (trg & 0x40) {
            SndSepPlaySimple(0x80000004);
            TkMenuCloseStatusPageWindow(1);
            *st = 3;
        }
        break;
    case 9:
        TkMenuOpenStatusPageWindow(0, 2, 0x41, 0);
        *st = 10;
        break;
    case 10:
        if (trg & 0x20) {
            SndSepPlaySimple(0x80000001);
            TkMenuCloseStatusPageWindow(2);
            *st = 11;
        } else if (trg & 0x40) {
            SndSepPlaySimple(0x80000004);
            TkMenuCloseStatusPageWindow(2);
            *st = 3;
        }
        break;
    case 11:
        TkMenuOpenStatusPageWindow(0, 3, 0x45, 0);
        *st = 12;
        break;
    case 12:
        if (trg & 0x20) {
            SndSepPlaySimple(0x80000001);
            TkMenuCloseStatusPageWindow(3);
            *st = 13;
        } else if (trg & 0x40) {
            SndSepPlaySimple(0x80000004);
            TkMenuCloseStatusPageWindow(3);
            *st = 3;
        }
        break;
    case 13:
        TkMenuOpenStatusPageWindow(0, 4, 0x44, 0);
        *st = 14;
        break;
    case 14:
        if (trg & 0x20) {
            SndSepPlaySimple(0x80000001);
            TkMenuCloseStatusPageWindow(4);
            *st = 15;
        } else if (trg & 0x40) {
            SndSepPlaySimple(0x80000004);
            TkMenuCloseStatusPageWindow(4);
            *st = 3;
        }
        break;
    case 16:
        if (trg & 0x20) {
            SndSepPlaySimple(0x80000001);
            TkMenuCloseStatusPageWindow(5);
            *st = 3;
        } else if (trg & 0x40) {
            SndSepPlaySimple(0x80000004);
            TkMenuCloseStatusPageWindow(5);
            *st = 3;
        }
        break;
    case 15:
        *st = 3;
        break;
    case 17:
        *st = 18;
        break;
    case 18:
        *st = 19;
        break;
    case 19:
        TkMenuMainSleepMenu(6);
        ((u8 *)D_00693878)[0x41] = 1;
        if (t->x20 == 0) {
            TkMenuMainActiveMenu(1, 0);
        }
        break;
    }
}

extern s16 D_003258B2;
extern s16 D_00693A6A;

void func_002297A0(int a, int b)
{
    u32 alpha;
    int y;
    u32 c0;
    u32 c1;

    alpha = a >> 5;
    alpha <<= 24;
    if (alpha != 0) {
        c0 = D_0032587C;
        c1 = D_00325880;
        c0 &= 0xFFFFFF;
        c1 &= 0xFFFFFF;
        c0 |= alpha;
        c1 |= alpha;
        switch (b) {
        case 4:
            y = 0x25;
            break;
        case 1:
            y = D_003258B2;
            break;
        default:
            y = D_00693A6A;
            break;
        }
        func_00225718(0, y, 0x200, 0x1A0 - y, c0, c1);
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_228B08", func_00229820);

void func_002299A8(int x, int y, int a, int b, int c)
{
    int alpha;
    int x2;

    b = TkMenuGetPlayerFromIndex(b);
    c = TkMenuGetPlayerFromIndex(c);
    func_00225800(x, y, D_00693A60, D_00693A64);
    if (TOMenuGetFirstReadEndFlag() != 0) {
        func_00225B40(x, y, b);
    }
    if (a != 0) {
        alpha = (0x1000 - (a < 0 ? -a : a)) >> 5;
        x2 = x + (a * D_00693A60) / 4096;
        func_00225420();
        func_002253F8(0x80, 0x80, 0x80, alpha);
        if (TOMenuGetFirstReadEndFlag() != 0) {
            func_00225B40(x2, y, c);
        }
        func_00225498();
    }
    func_00225908();
}

void func_00229AC8(int x, int y, int a, int b, int c)
{
    int alpha;
    int x2;

    b = func_00242798(b);
    c = func_00242798(c);
    func_00225800(x, y, D_00693A60, D_00693A64);
    if (TOMenuGetFirstReadEndFlag() != 0) {
        func_00225B40(x, y, b);
    }
    if (a != 0) {
        alpha = (0x1000 - (a < 0 ? -a : a)) >> 5;
        x2 = x + (a * D_00693A60) / 4096;
        func_00225420();
        func_002253F8(0x80, 0x80, 0x80, alpha);
        if (TOMenuGetFirstReadEndFlag() != 0) {
            func_00225B40(x2, y, c);
        }
        func_00225498();
    }
    func_00225908();
}

void func_00229BE8(int x, int y, int a, int b, int c)
{
    int alpha;
    int x2;

    func_00225800(x, y, D_00693A60, D_00693A64);
    if (TOMenuGetFirstReadEndFlag() != 0) {
        func_00225B40(x, y, b);
    }
    if (a != 0) {
        alpha = (0x1000 - (a < 0 ? -a : a)) >> 5;
        x2 = x + (a * D_00693A60) / 4096;
        func_00225420();
        func_002253F8(0x80, 0x80, 0x80, alpha);
        if (TOMenuGetFirstReadEndFlag() != 0) {
            func_00225B40(x2, y, c);
        }
        func_00225498();
    }
    func_00225908();
}

void func_00229CE8(int dx, int dy, U3Box *dst, U3Box *src, int size)
{
    *dst = *src;
    dst->x += dx;
    dst->y += dy;
    if (size) {
        dst->w = D_00693900.w;
        dst->h = D_00693900.h;
    }
}

extern u16 D_00693A78[];

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_228B08", func_00229D58);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_228B08", func_00229F98);

extern s16 _s16_D_006938B8[2] __asm__("D_006938B8");
extern s16 _s16_D_00693960[2] __asm__("D_00693960");

void func_0022A3F8(int x, int y, int idx)
{
    int dx = x + (D_00693A70[0] - _s16_D_00693960[0]);
    int dy = y + (D_00693A70[1] - _s16_D_00693960[1]);
    FlagRec r0 = D_00693948;
    FlagRec r1 = *(FlagRec *)_s16_D_00693960;
    FlagRec r2 = *(FlagRec *)D_00693978;
    FlagRec r3 = D_006939D8;

    r0.rect[0] += dx;
    r1.rect[0] += dx;
    r2.rect[0] += dx;
    r3.rect[0] += dx;
    r0.rect[1] += dy;
    r1.rect[1] += dy;
    r2.rect[1] += dy;
    r3.rect[1] += dy;
    func_00226FE0((DrawArgs *)&r0);
    func_00226E90((DrawArgs *)&r1);
    func_00226FC0((DrawArgs *)&r2);
    func_00226F28((DrawArgs *)&r3);
    func_00226E10(r2.rect[0] + 0x58, r2.rect[1], 0xD7);
    func_00226350(r1.rect[0] + _s16_D_006938B8[0], r1.rect[1] + _s16_D_006938B8[1],
                  idx < D_00693A98 ? func_00220A78(0x15) : func_00220A78(0x16), 0);
    {
        u16 cmd = D_00693A78[idx];
        register int ox __asm__("$6") = _s16_D_006938B8[0];
        register int oy __asm__("$7") = _s16_D_006938B8[1];
        register int tx __asm__("$2") = r2.rect[0];
        register int ty __asm__("$5") = r2.rect[1];
        func_00226350(tx + ox, ty + oy, TkMn2GetCommandName(cmd), 0);
    }
}

void func_0022A688(int unused, int a)
{
    int n = D_00693A98 + D_00693A9A;
    int step;
    int y;
    int i;

    if (n < 4) {
        step = D_00693A44;
    } else {
        step = D_00693A44 - 4;
    }
    y = 0;
    for (i = 0; i < n; i++) {
        func_0022A3F8(a, y, i);
        y += step;
    }
}

void func_0022A728(int a, int b, int c, int mode)
{
    switch (mode) {
    case 0:
        break;
    case 1:
    case 3:
        func_0022F720(D_00693888[0], D_00693888[1]);
        break;
    case 2:
        break;
    }
}

void func_00229F98(int, int);

void func_0022A768(int x, int y, int chr, int mode, int *p4, int *p5, int *p6, int *p7, int t52)
{
    int s2 = (func_002292B8(t52, 1) * 0x155) / 0x1000;

    func_00242C58(chr);
    switch (mode) {
    case 0:
        chr = TkMenuGetCurrentPlayer();
        ((int (*)(int))func_00225E70)(0); /* DEBT(TYPE): header declares void, compiled as returning int */
        func_002299A8(x + D_00693A68[0], y + D_00693A68[1], *p4, *p5, *p6);
        break;
    case 3:
        chr = func_00242940();
        break;
    case 1:
        chr = func_00242940();
        ((int (*)(int))func_00225E70)(1);
        func_00229AC8(x + D_003258B0[0], y + D_003258B0[1], *p4, *p5, *p6);
        break;
    }
    switch (mode) {
    case 0:
        func_00229F98(chr, s2);
        func_00229D58(s2 + D_006938E8.rect[0], D_006938E8.rect[1], chr);
    case 2:
        func_00225F30(D_00693880[0], D_00693880[1], chr);
        break;
    case 3:
        func_00229D58(s2 + D_00693900.x, D_00693900.y, chr);
        break;
    case 1:
        func_00229D58(s2 + D_00693900.x, D_00693900.y, chr);
        func_0022A688(chr, s2);
        break;
    }
    func_00225AF8();
}

typedef struct { s32 a; s32 b; } StatEntry;
extern StatEntry D_00325808[];
extern void func_002271B0(int, int, int, int, int, int, int);
extern int func_00224950(int, int);
extern void graphicUiRemapY2(void);

void func_0022A9A0(int unused, int y, int chr, int t52)
{
    FlagRec r;
    int off;
    int sx;
    int sy;
    int i;
    int lt18;

    i = 0;
    off = (func_002292B8(t52, 1) * 0xD0) / 4096;
    sx = D_006938D8[0];
    sy = D_006938D8[1];
    while (1) {
        int a;
        int b;

        MsGetSavePlayerPtr(chr);
        a = D_00325808[i].a;
        b = D_00325808[i].b;
        if (a < 0) {
            break;
        }
        if (i == 4) {
            sx = D_006938E0[0];
            sy = D_006938E0[1];
        }
        func_002271B0(sx, y + sy + func_00224950(off, i % 4), D_00325878[0], D_00325878[1], chr, a, b);
        i++;
        sy += D_006938E4;
        graphicUiRemapY2();
    }
    if ((lt18 = (chr < 0x12), !lt18) || chr < 0xE) {
        r = D_00325888;
        r.rect[1] += y;
        func_00226FE0((DrawArgs *)&r);
        func_00226E10(D_00325888.rect[0] + D_003258A0[0], y + D_00325888.rect[1] + D_003258A0[1], 0xF3);
        func_00226350(D_00325888.rect[0] + D_003258A8[0], y + D_00325888.rect[1] + D_003258A8[1], func_00220A78(0x1A), 0);
    }
    func_00225B00();
}

void func_0022ABC8(void) {
}

void func_0022ABD0(void)
{
    int i;

    for (i = 5; i >= 0; i--) {
        D_00693860[i] = 0;
    }
    TkMn2GetStatusPos();
}

void func_0022AC08(Task *o, int a1)
{
    D_003258C8 = 0;
    D_003258CC = TkMenuGetCurrentPlayerPos();
    D_003258D0 = TkMenuGetCurrentPlayerPos();
    D_003258D4 = TkMenuGetCurrentPlayerPos();
    o->x20 = a1;
    o->x1C = 0;
    D_00693878 = func_0022ADB0();
    TkMn2InitStatusBG();
    func_00227480(D_00571830);
    func_00227480(D_00571838);
}

void func_0022AC90(void)
{
    int i;

    for (i = 0; i < 6; i++) {
        TkMenuCloseStatusPageWindow(i);
    }
    TkMn2InitStatusBG();
    func_00227490(D_00571838);
    func_00227490(D_005717D0);
}

void func_0022ACE8(void) {
}

void func_0022ACF0(Task *o) { func_00243508(o); }

void func_0022ACF8(Task *t)
{
    int v = TkMenuGetCurrentPlayer();

    func_002492F0();
    func_002492F0();
    func_00225A38();
    func_00225920_void();
    func_0022A768(0, 0, v, 0, &D_003258C8, &D_003258CC, &D_003258D0, &D_003258D4, t->x52);
    func_0022A9A0(0, 0, v, t->x52);
    func_002297A0(func_00228B80(), 0);
    func_00225B00();
}

int func_0022ADA8(void) { return 1; }

Task * func_0022ADB0(void)
{
    Task *t = func_00243400();

    t->x0C = (s32)func_0022ACF0;
    t->x10 = (s32)func_0022ACF8;
    t->x14 = (s32)func_0022ADA8;
    t->b3E = 0x2;
    t->b36 = 0x3;
    t->x54 = 0x155;
    TkMenuMainRegistWindow(t);
    return t;
}

void func_0022AE20(Task *o) {
    if (o->x54 != 0) {
        o->x52 += o->x54;
        if (o->x52 >= 0x1000) {
            o->x52 = 0x1000;
        }
        if (o->x52 <= 0) {
            o->x52 = 0;
        }
    }
}

int TkMenuGetCommandMax(R5Rec4 *p, int flag, int a2, int a3)
{
    int n = 0;

    if (flag == 0) {
        return 8;
    }
    while (p->b0 != 0xFF) {
        if (p->b0 == a2 && p->b1 == a3) {
            n++;
        }
        p++;
    }
    return n;
}

int TkMenuGetCommandOffset(R5Rec4 *p, int flag, int a2, int a3)
{
    int n = 0;

    if (flag == 0) {
        return 0;
    }
    while (p->b0 != 0xFF) {
        if (p->b0 == a2 && p->b1 == a3) {
            return n;
        }
        p++;
        n++;
    }
    return 0;
}

typedef struct { u8 b0; u8 b1; u16 h2; } TkCmdRec;
extern int MsGetSaveCommandMenuPanel(int);

void TkMenuFlushSummonCommand(int chr)
{
    s32 dummy;
    TkCmdRec *tbl;
    int n;
    int off;
    u16 cmd;
    int i;

    tbl = (TkCmdRec *)MsMenuStatusNum(0, &dummy);
    ((void (*)(void))func_002423F0)();

    n = TkMenuGetCommandMax((R5Rec4 *)tbl, 1, chr, 1);
    off = TkMenuGetCommandOffset((R5Rec4 *)tbl, 1, chr, 1);
    D_00693A98 = 0;
    for (i = 0; i < n; i++) {
        cmd = (tbl + off)[i].h2;
        if (MsGetSaveCommand(chr, cmd)) {
            D_00693A78[D_00693A98++] = cmd;
        }
    }

    n = TkMenuGetCommandMax((R5Rec4 *)tbl, 1, chr, 3);
    off = TkMenuGetCommandOffset((R5Rec4 *)tbl, 1, chr, 3);
    for (i = 0; i < n; i++) {
        cmd = (tbl + off)[i].h2;
        if (MsGetSaveCommand(chr, cmd)) {
            D_00693A78[D_00693A98++] = cmd;
        }
    }

    n = TkMenuGetCommandMax((R5Rec4 *)tbl, 1, chr, 4);
    off = TkMenuGetCommandOffset((R5Rec4 *)tbl, 1, chr, 4);
    for (i = 0; i < n; i++) {
        if (MsGetSaveCommand(chr, (tbl + off)[i].h2)) {
            D_00693A78[D_00693A98++] = (tbl + off)->h2;
            break;
        }
    }

    n = TkMenuGetCommandMax((R5Rec4 *)tbl, 1, chr, 5);
    off = TkMenuGetCommandOffset((R5Rec4 *)tbl, 1, chr, 5);
    for (i = 0; i < n; i++) {
        cmd = (tbl + off)[i].h2;
        if (MsGetSaveCommand(chr, cmd)) {
            D_00693A78[D_00693A98++] = cmd;
        }
    }

    n = TkMenuGetCommandMax((R5Rec4 *)tbl, 1, chr, 2);
    off = TkMenuGetCommandOffset((R5Rec4 *)tbl, 1, chr, 2);
    D_00693A9A = 0;
    for (i = 0; i < n; i++) {
        cmd = (tbl + off)[i].h2;
        if (MsGetSaveCommand(chr, cmd)) {
            D_00693A78[D_00693A98 + D_00693A9A] = cmd;
            D_00693A9A++;
        }
    }
}

int TkMenuGetDispCommand(int a0, int a1, int a2, int chr, int *out)
{
    s32 dummy;
    s32 dummy2;
    int count = 0;
    TkCmdRec *tbl;
    int n;
    int off;
    int ret;
    int i;

    tbl = (TkCmdRec *)MsMenuStatusNum(0, &dummy);
    n = TkMenuGetCommandMax((R5Rec4 *)tbl, a0, a1, a2);
    off = TkMenuGetCommandOffset((R5Rec4 *)tbl, a0, a1, a2);
    ret = n;
    for (i = 0; i < ret; i++) {
        out[i] = 0;
    }
    if (a1 == 1) {
        for (i = 0; i < n; i++) {
            register int c64 __asm__("$3") = 0x64;
            u16 id;
            int arg;

            __asm__("" : "+r"(c64));
            id = (tbl + i)[off].h2;
            arg = 0xF;
            if (id != c64) {
                __asm__("");
                arg = id;
            }
            if (MsGetSavePlyJoin(arg)) {
                *out = id;
            }
            out++;
        }
        return n;
    }
    if (a0 == 0) {
        int w = TkMenuGetWeapon(chr);
        int a = TkMenuGetArmor(chr);

        if (w != 0xFF) {
            u16 *p = (u16 *)((u8 *)MsGetSaveWeapon(w, &dummy2) + 0xE);
            for (i = 0; i < 4; i++) {
                u16 v = p[i];
                if (v != 0 && v != 0xFF) {
                    *out++ = v;
                }
            }
        }
        if (a != 0xFF) {
            u16 *p = (u16 *)((u8 *)MsGetSaveWeapon(a, &dummy2) + 0xE);
            for (i = 0; i < 4; i++) {
                u16 v = p[i];
                if (v != 0 && v != 0xFF) {
                    *out++ = v;
                }
            }
        }
    } else if (a1 < 0x48) {
        if (a1 < 0x40) {
            goto other_cmd;
        }
        MsGetSavePlayerPtr(chr);
        for (i = 0; i < n; i++) {
            u16 id = (tbl + i)[off].h2;
            if (MsGetSaveCommand(chr, id)) {
                *out++ = id;
                count++;
            } else if (chr < 8) {
                if (!MsGetSaveCommandMenuPanel(id)) {
                    ret--;
                } else {
                    out++;
                }
            }
        }
    } else {
    other_cmd:
        ((void (*)(void))func_002423F0)();
        for (i = 0; i < n; i++) {
            u16 id = (tbl + i)[off].h2;
            if (MsGetSaveCommand(chr, id)) {
                *out++ = id;
                count++;
            } else if (chr < 8) {
                if (!MsGetSaveCommandMenuPanel(id)) {
                    ret--;
                } else {
                    out++;
                }
            }
        }
    }
    return chr < 8 ? ret : count;
}

s32 _m2c_func_0022B598_TkMenuGetCurrentPlayer() __asm__("TkMenuGetCurrentPlayer");
s32 _m2c_func_0022B598_TkMenuGetDispCommand(s32, s32, s32, s32, s32 *) __asm__("TkMenuGetDispCommand");
s32 _m2c_func_0022B598_func_00224950(s32, s32) __asm__("func_00224950");
s32 _m2c_func_0022B598_func_00224978(s32, s32) __asm__("func_00224978");
void _m2c_func_0022B598_func_002253F8(s32, s32, s32, s32) __asm__("func_002253F8");
void _m2c_func_0022B598_func_00225420() __asm__("func_00225420");
void _m2c_func_0022B598_func_00225498() __asm__("func_00225498");
void _m2c_func_0022B598_func_00225920() __asm__("func_00225920");
void _m2c_func_0022B598_func_00225A38() __asm__("func_00225A38");
void _m2c_func_0022B598_func_00226290(s16, s32, s32) __asm__("func_00226290");
void _m2c_func_0022B598_func_00226688(s32, s32, s32, s32) __asm__("func_00226688");
void _m2c_func_0022B598_func_00226770(s32, s32, s32, s32) __asm__("func_00226770");
void _m2c_func_0022B598_func_00226800(s32, s32, s32, s32) __asm__("func_00226800");
void _m2c_func_0022B598_func_00226D88(s32, s32, s32) __asm__("func_00226D88");
void _m2c_func_0022B598_func_00226E10(s32, s32, s32) __asm__("func_00226E10");
s32 _m2c_func_0022B598_func_002292B8(s16, s16) __asm__("func_002292B8");
s32 _m2c_func_0022B598_func_00242940() __asm__("func_00242940");
void _m2c_func_0022B598_func_002492F0() __asm__("func_002492F0");
void _m2c_func_0022B598_graphicUiRemapY2() __asm__("graphicUiRemapY2");
/* DEBT(CAST) */
void func_0022B598(void *arg0) {
    u8 sp[0x60];
    s32 sp60;
    s32 sp64;
    s32 sp68;
    s32 var_17;
    s32 var_30;
    s32 *var_20;
    s32 temp_16;
    s32 temp_17;
    s32 temp_18;
    s32 temp_18_2;
    s32 temp_22;
    s32 temp_3;
    s32 temp_5;
    s32 var_16;
    s32 var_21;
    s32 var_23;
    s32 var_7;
    u32 var_19;

    sp60 = (*(s32 *)((u8 *)(arg0) + (0x58)));
    temp_18 = (*(s32 *)((u8 *)(arg0) + (0x5C)));
    sp64 = (*(s32 *)((u8 *)(arg0) + (0x60)));
    _m2c_func_0022B598_func_002492F0();
    _m2c_func_0022B598_func_002492F0();
    _m2c_func_0022B598_func_00225A38();
    _m2c_func_0022B598_func_00225920();
    if ((*(s32 *)((u8 *)(arg0) + (0x64))) == 0) {
        var_7 = _m2c_func_0022B598_TkMenuGetCurrentPlayer();
        var_30 = D_00693A58[1];
        var_23 = D_00693A5C;
        var_17 = D_00693A48[1];
    } else {
        var_7 = _m2c_func_0022B598_func_00242940();
        var_30 = D_00693A58[1] + 0xB;
        var_23 = D_00693A5C - 1;
        var_17 = D_00693A48[1] + 0xB;
    }
    temp_22 = _m2c_func_0022B598_TkMenuGetDispCommand(sp64, sp60, temp_18, var_7, sp);
    temp_5 = _m2c_func_0022B598_func_002292B8((*(s16 *)((u8 *)(arg0) + (0x52))), (*(s16 *)((u8 *)(arg0) + (0x54))));
    if ((*(s16 *)((u8 *)(arg0) + (0x54))) > 0) {
        temp_3 = temp_5 * 0xD0;
        sp68 = 0;
        var_21 = ((s32)temp_3 / 4096);
    } else {
        var_21 = 0;
        sp68 = ((s32)temp_5 / 16);
    }
    var_19 = 0;
    _m2c_func_0022B598_func_00225420();
    _m2c_func_0022B598_func_002253F8(0x80, 0x80, 0x80, (s32) ((u16) (*(s16 *)((u8 *)(arg0) + (0x52))) << 0x10) >> 0x15);
    _m2c_func_0022B598_func_00226290((*(s16 *)((u8 *)(D_00693A48) + (0))), var_17 + var_21, (*(s32 *)((u8 *)(arg0) + (0x68))));
    _m2c_func_0022B598_func_00225498();
    var_20 = sp;
    if (temp_22 > 0) {
        do {
            temp_18_2 = *var_20;
            temp_16 = (s32) (var_19 + (var_19 >> 0x1F)) >> 1;
            temp_17 = (var_23 * temp_16) + var_30 + _m2c_func_0022B598_func_00224950(var_21, temp_16);
            if (var_19 & 1) {
                var_16 = (*(s16 *)((u8 *)(D_00693A58) + (0))) + _m2c_func_0022B598_func_00224978(sp68, temp_16);
            } else {
                var_16 = *D_00693A50 - _m2c_func_0022B598_func_00224978(sp68, temp_16);
            }
            if ((temp_17 < 0x1A1) && (var_16 < 0x201) && (var_16 >= -0x200)) {
                _m2c_func_0022B598_func_00226D88(var_16, temp_17, 0x10);
                _m2c_func_0022B598_func_00226E10(var_16 + (*(s16 *)((u8 *)(D_00325878) + (0))) + 0x58, temp_17 + D_00325878[1], 0xD7);
                if (temp_18_2 != 0) {
                    if (sp60 == 1) {
                        _m2c_func_0022B598_func_00226688(temp_18_2, var_16 + 0xC, temp_17 + 1, 0);
                    } else if (sp64 == 0) {
                        _m2c_func_0022B598_func_00226800(temp_18_2, var_16, temp_17, 0);
                    } else {
                        _m2c_func_0022B598_func_00226770(temp_18_2, var_16, temp_17, 0);
                    }
                }
            }
            var_19 += 1;
            var_20 = (s32 *)((u8 *)var_20 + (4));
        } while ((s32) var_19 < temp_22);
    }
    _m2c_func_0022B598_graphicUiRemapY2();
}

void func_0022B878(void) {
}

int func_0022B880(Task *o) { return o->x52 == 0; }

Task *TkMenuOpenStatusPageWindow(int a, int idx, int c, int d)
{
    Task *t;
    int k;
    int prio;
    void (*cb)();

    k = 0;
    switch (idx) {
    case 0:
        k = 1;
        break;
    case 1:
        k = 2;
        break;
    case 2:
        k = 3;
        break;
    case 3:
        k = 5;
        break;
    case 4:
        k = 4;
        break;
    }
    t = func_00243400();
    D_00693860[idx] = t;
    /* DEBT(CAST): callbacks are stored as s32 in the task record */
    cb = (void (*)())func_0022B878;
    t->ext[0] = c;
    t->ext[1] = d;
    prio = idx + 3;
    t->ext[2] = idx;
    t->ext[3] = a;
    t->ext[4] = k;
    t->cb = cb;
    t->x0C = (s32)func_0022AE20;
    t->x10 = (s32)func_0022B598;
    t->x14 = (s32)func_0022B880;
    t->b3E = prio;
    t->x54 = 0xAA;
    TkMenuMainRegistWindow(t);
    return t;
}

void TkMenuCloseStatusPageWindow(int i)
{
    Task *t;

    if (D_00693860[i] != 0) {
        D_00693860[i]->b41 = 1;
        t = D_00693860[i];
        D_00693860[i] = 0;
        t->x54 = -0xAA;
    }
}
