/* tu_241 0x216fa0-0x2180a0: low; ~inputSetInputInfoToCurrentFrame (config/tu_map.tsv) */
#define TODrawMenuPlateXYWC2_Rfix _hdr_TODrawMenuPlateXYWC2_Rfix
#define func_00216FA0 _hdr_func_00216FA0
#define D_00692458 _hdr_D_00692458
#include "common.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/t4.h"
#include "ffx/u3.h"
#include "ffx/v4.h"
#include "ffx/q5.h"
#undef TODrawMenuPlateXYWC2_Rfix
#undef func_00216FA0
#undef D_00692458

int TODrawMenuPlateXYWC2_Rfix(int a, int b, int x, int y, int w, u32 c0, u32 c1);

typedef struct {
    s32 w0;
    s32 w4;
    u8 *w8;
    s16 hC;
    s16 hE;
} R4Rec16Ptr;

extern R4Rec16Ptr D_00692458[];

void func_00216FA0(int i)
{
    D_00692458[i].w0 = 0;
    D_00692458[i].w4 = 7;
    D_00692458[i].w8 = 0;
    D_00692458[i].hC = 0;
    D_00692458[i].hE = 0;
}

void func_00216FD8(int a) {
}

void func_00216FE0(int i)
{
    if (D_00692458[i].w0 != 0) {
        TODrawMenuPlateXYWC2_Rfix(0x45, 0x46, D_00324248, D_0032424A, D_0032424C, D_00324250, D_00324254);
        TODrawMenuPlateXYWC2_Rfix(6, 7, D_0032425C, D_0032425E, D_00324260, 0x40000000, 0x40000000);
        TOMkpShapeXY(0x3E, D_00324248 + 0x50, D_0032424A);
        func_001F3A80(D_00692458[i].w4, (int)D_00692458[i].w8, (0x200 - D_00692458[i].hC) / 2, 0xC, 0, 1, 0x80, 0x80, 0x80, 0x80);
    }
}

int func_002170F8(int i, int text)
{
    func_00216FA0(i);
    D_00692458[i].w0 = 1;
    D_00692458[i].w4 = 7;
    D_00692458[i].w8 = (u8 *)text;
    _TOGetMessageWH(7, (u8 *)text, &D_00692458[i].hC, &D_00692458[i].hE, 1, 0);
    return 1;
}

void func_00217180(int i)
{
    D_00692458[i].w0 = 0;
}

void TOBtlCloseSimpleHelpMes(void)
{
    func_00217180(0);
}

int TOBtlOpenSignWindow(u16 id)
{
    int base;
    OfsTbl *t = MsGetComData(id, &base);

    if (!((t->flags >> 2) & 1)) {
        return 0;
    }
    func_002170F8(1, base + t->a[0].x);
    return 1;
}

void TOBtlCloseSignWindow(void)
{
    func_00217180(1);
}

int func_00217200(int a, int b)
{
    TOBtlSetMacroCommandType(7, 0, 0);
    TOBtlSetMacroCommandValue(7, 0, TOGetSaveChrName(a));
    func_002170F8(0, MsGetRomBtlText(b, 0));
    return 7;
}

int func_00217270(int a, int b)
{
    TOBtlSetMacroCommandType(7, 0, 0);
    TOBtlSetMacroCommandValue(7, 0, TOGetSaveChrName(a));
    TOBtlSetMacroCommandType(7, 1, 0);
    TOBtlSetMacroCommandValue(7, 1, MsMenuGetText(1, b + 0x1033, 0));
    func_002170F8(0, MsGetRomBtlText(0x300F, 0));
    return 7;
}

int func_00217310(int a, int n)
{
    int text;

    TOBtlSetMacroCommandType(7, 0, 0x33);
    TOBtlSetMacroCommandValue(7, 0, a);
    TOBtlSetMacroCommandType(7, 1, 1);
    TOBtlSetMacroCommandValue(7, 1, n);
    if (n == -1) {
        text = MsGetRomBtlText(0x3007, 0);
    }
    if (n == 0) {
        text = MsGetRomBtlText(0x3008, 0);
    }
    if (n == 1) {
        text = MsGetRomBtlText(0x3005, 0);
    }
    if (n >= 2) {
        text = MsGetRomBtlText(0x3006, 0);
    }
    func_002170F8(0, text);
    return 7;
}

int func_00217400(int a)
{
    int s;

    TOBtlSetMacroCommandType(7, 0, 1);
    TOBtlSetMacroCommandValue(7, 0, a);
    if (a < 0) {
        s = MsGetRomBtlText(0x301A, 0);
    }
    if (a == 0) {
        s = MsGetRomBtlText(0x3019, 0);
    }
    if (a > 0) {
        s = MsGetRomBtlText(0x3018, 0);
    }
    func_002170F8(0, s);
    return 7;
}

int func_00217498(void)
{
    func_002170F8(0, MsGetRomBtlText(0x3002, 0));
    return 7;
}

int func_002174C8(void)
{
    func_002170F8(0, MsGetRomBtlText(0x3003, 0));
    return 7;
}

int TOBtlDrawCaptureMonsterMessageWindow(int a, int b)
{
    TOBtlSetMacroCommandType(7, 0, 0);
    TOBtlSetMacroCommandValue(7, 0, func_001BB190(a));
    func_002170F8(0, MsGetRomBtlText(b, 0));
    return 7;
}

int TOBtlDrawLearningMessageWindow(int a, int b)
{
    int base;
    OfsTbl *t;
    int ofs;

    TOBtlSetMacroCommandType(7, 0, 0);
    TOBtlSetMacroCommandValue(7, 0, TOGetSaveChrName(a));
    t = MsGetComData(b, &base);
    ofs = base + t->a[0].x;
    TOBtlSetMacroCommandType(7, 1, 0);
    TOBtlSetMacroCommandValue(7, 1, ofs);
    func_002170F8(0, MsGetRomBtlText(0x300D, 0));
    return 7;
}

void func_00217610(int w, int x, int px, int py, int align)
{
    TOInitMessageWindow(w);
    func_0020AEB8(w, 0, 0);
    TOSetMessageAuto(w, x, x);
    TOSetMessageWindowPosition(w, align, px, py);
    TOSetMessageWindowPriority(w, 4);
    func_0020B6A8(w);
    TOOpenMessageWindow(w);
}

void func_002176B0(int w, int x)
{
    TOInitMessageWindow(w);
    func_0020AEB8(w, 1, 0x2002);
    TOSetMessageAuto(w, x, x);
    TOSetMessageWindowPosition(w, 4, 0x100, 0x1C0);
    TOSetMessageWindowPriority(w, 4);
    func_0020B6A8(w);
    TOOpenMessageWindow(w);
}

void TODrawAMES_CENTERMES(int w, int x)
{
    TOInitMessageWindow(w);
    func_0020AEB8(w, 1, 0x2402);
    TOSetMessageAuto(w, x, x);
    TOSetMessageWindowPosition(w, 4, 0x100, 0xE0);
    TOSetMessageWindowPriority(w, 4);
    func_0020B6A8(w);
    TOOpenMessageWindow(w);
}

void func_002177B0(int w, int x)
{
    TOInitMessageWindow(w);
    func_0020AEB8(w, 1, 0x6002);
    TOSetMessageAuto(w, x, x);
    TOSetMessageWindowPosition(w, 4, 0x100, 0x1C0);
    TOSetMessageWindowPriority(w, 4);
    func_0020B6A8(w);
    TOOpenMessageWindow(w);
}

void func_00217830(int w, int a, int b, int c)
{
    TOInitMessageWindow(w);
    func_0020AEB8(w, 10, 0x2000);
    TOSetMessageAuto(w, a, a);
    func_00205A10(w, 0, 12, 0x200, 12);
    TOSetMessageWindowPosition(w, 4, b, c);
    TOSetMessageWindowPriority(w, 4);
    func_0020B6A8(w);
    TOOpenMessageWindow(w);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_216FA0", func_002178E0);

int TOBtlSetDamageValue(s16 x, s16 y, int w8, u8 c0, u8 c1, u8 c2, u8 c3)
{
    R4Ent16 *e;

    if (D_00692450 >= 0x3F) {
        return -1;
    }
    e = &D_00692050[D_00692450];
    e->bF = c3;
    e->x = x;
    e->y = y;
    e->bC = c0;
    e->bD = c1;
    e->bE = c2;
    e->w8 = w8;
    return D_00692450 = D_00692450 + 1;
}

int func_00217CD0(s16 x, s16 y, int w4, int w8, u8 c0, u8 c1, u8 c2, u8 c3)
{
    R4Ent16 *e;

    if (D_00692450 >= 0x3F) {
        return -1;
    }
    e = &D_00692050[D_00692450];
    e->bF = c3;
    e->x = x;
    e->y = y;
    e->bC = c0;
    e->bD = c1;
    e->bE = c2;
    e->w8 = w8;
    e->w4 = w4;
    return D_00692450 = D_00692450 + 1;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_216FA0", func_00217D50);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_216FA0", TOBtlDrawLimitGauge);
