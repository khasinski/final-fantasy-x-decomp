/* tu_225 0x200c58-0x201760: low; unk_200C58 (config/tu_map.tsv) */
#define TODrawMenuPlateXYWC2_Rfix _hdr_TODrawMenuPlateXYWC2_Rfix
#define func_001F64F8 _hdr_func_001F64F8
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/u3.h"
#include "ffx/v4.h"
#include "ffx/r4.h"
#undef func_001F64F8
#undef TODrawMenuPlateXYWC2_Rfix

extern void TODrawMenuPlateXYWC2_Rfix(int, int, int, int, int, int, int);
extern void func_001F3808(int, int, int, int);
extern void func_001F5E80(int, int, int, int);
extern void func_001F64F8(const char *, int, int, int);
extern s16 D_00324208, D_00324214, D_00324216, D_00324218, D_0032421A;
extern s16 D_0032421C, D_0032421E, D_00324220, D_00324222, D_00324224, D_00324226;
extern s16 D_00324228, D_0032422A, D_0032422C, D_0032422E;
extern s32 D_0032420C, D_00324210, D_003242E4, D_003242E8;
extern char D_005700A0[], D_005700A8[];

void *func_00200C58(void *list, int a, int b, int c)
{
    char buf[0x20];
    int w = D_00324208;

    InvokedFromSelectCursor = list;
    if (a >= 0 && a < 8) {
        TODrawMenuPlateXYWC2_Rfix(4, 5, b, c, w, D_0032420C, D_00324210);
        func_001F3808(TOGetSaveChrName(a), b + D_00324214, c + D_00324216, func_00242C58(a));
        TOMkpShapeXY(0x21, b + D_00324218, c + D_0032421A);
        func_002F0008(buf, D_005700A0, TkMenuGetHP(a), TkMenuGetMaxHP(a));
        func_001F64F8(buf, b + D_0032421C, c + D_0032421E, 0x25);
        TOMkpShapeXY(0x22, b + D_00324220, c + D_00324222);
        func_002F0008(buf, D_005700A8, TkMenuGetMP(a), TkMenuGetMaxMP(a));
        func_001F64F8(buf, b + D_00324224, c + D_00324226, 0x25);
        func_001FE298(0xE7, 0, c, 0x200, 0, 0x80808080, 0x80808080);
        TOMkpShapeXY(0x107, b + D_00324228 + 0x68, c + D_0032422A);
        func_001F5E80(func_00242468(a), b + D_00324228 + D_0032422C, c + D_0032422A + D_0032422E, 0);
        func_001F63B8(MsGetNextAP(a) - func_001BE5C0(a), b + D_00324228 + 0x8B, c + D_0032422A - 0xD, 0x25);
    } else {
        TODrawMenuPlateXYWC2_Rfix(0xCC, 0xCD, b, c, w, D_0032420C, D_00324210);
        TOMkpShapeXY(0xE9, b + D_00324218, c + D_0032421A);
        TOMkpShapeXY(0xEA, b + D_00324220, c + D_00324222);
        func_001FE298(0xE7, 0, c, 0x200, 0, 0x80808080, 0x80808080);
        TOMkpShapeXY(0x107, b + D_00324228 + 0x68, c + D_0032422A);
    }
    return InvokedFromSelectCursor;
}

void *func_00200F98(void *list, int a, int b, int c)
{
    char buf[0x20];
    int w = D_00324208;

    InvokedFromSelectCursor = list;
    if (a >= 0 && a < 8) {
        TODrawMenuPlateXYWC2_Rfix(4, 5, b, c, w, D_0032420C, D_00324210);
        func_001F3808(TOGetSaveChrName(a), b + D_00324214, c + D_00324216, func_00242C58(a));
        TOMkpShapeXY(0x21, b + D_00324218, c + D_0032421A);
        func_002F0008(buf, D_005700A0, TkMenuGetHP(a), TkMenuGetMaxHP(a));
        func_001F64F8(buf, b + D_0032421C, c + D_0032421E, 0x25);
        TOMkpShapeXY(0x22, b + D_00324220, c + D_00324222);
        func_002F0008(buf, D_005700A8, TkMenuGetMP(a), TkMenuGetMaxMP(a));
        func_001F64F8(buf, b + D_00324224, c + D_00324226, 0x25);
        func_001FE298(0xE7, 0, c, 0x200, 0, 0x80808080, 0x80808080);
    } else {
        TODrawMenuPlateXYWC2_Rfix(0xCC, 0xCD, b, c, w, D_0032420C, D_00324210);
        TOMkpShapeXY(0xE9, b + D_00324218, c + D_0032421A);
        TOMkpShapeXY(0xEA, b + D_00324220, c + D_00324222);
        func_001FE298(0xE7, 0, c, 0x200, 0, 0x80808080, 0x80808080);
    }
    return InvokedFromSelectCursor;
}

void *func_00201210(void *list, int a, int b, int c)
{
    return func_00201250(list, a, b, c, 0);
}

void *func_00201230(void *list, int a, int b, int c)
{
    return func_00201410(list, a, b, c, 1);
}

void *func_00201250(void *list, int a, int b, int c, int d)
{
    char buf[0x20];

    InvokedFromSelectCursor = list;
    TODrawMenuPlateXYWC2_Rfix(0xCC, 0xCD, b, c, D_00324208, D_003242E4, D_003242E8);
    func_001F3808(TOGetSaveChrName(a), b + D_00324214, c + D_00324216, d);
    TOMkpShapeXY(0xE9, b + D_00324218, c + D_0032421A);
    func_002F0008(buf, D_005700A0, TkMenuGetHP(a), TkMenuGetMaxHP(a));
    func_001F64F8(buf, b + D_0032421C, c + D_0032421E, 0x25);
    TOMkpShapeXY(0xEA, b + D_00324220, c + D_00324222);
    func_002F0008(buf, D_005700A8, TkMenuGetMP(a), TkMenuGetMaxMP(a));
    func_001F64F8(buf, b + D_00324224, c + D_00324226, 0x25);
    func_001FE298(0xE7, b, c, 0x200, 0, 0x80808080, 0x80808080);
    return InvokedFromSelectCursor;
}

void *func_00201410(void *list, int a, int b, int c, int d)
{
    char buf[0x20];

    InvokedFromSelectCursor = list;
    TODrawMenuPlateXYWC2_Rfix(0xCC, 0xCD, b, c, D_00324208, D_003242E4, D_003242E8);
    func_001F3808(TOGetSaveChrName(a), b + D_00324214, c + D_00324216, d);
    func_001FE298(0xE7, b, c, 0x200, 0, 0x80808080, 0x80808080);
    return InvokedFromSelectCursor;
}

void func_002014E0(int a, int b, int c)
{
    char buf[0x20];
    int w = D_00324208;

    TOMenuOpenPktBuffTmp();
    TODrawMenuPlateXYWC2_Rfix(4, 5, b, c, w, D_0032420C, D_00324210);
    func_001F3808(TOGetSaveChrName(a), b + D_00324214, c + D_00324216, func_00242C58(a));
    TOMkpShapeXY(0x21, b + D_00324218, c + D_0032421A);
    func_002F0008(buf, D_005700A0, TkMenuGetHP(a), TkMenuGetMaxHP(a));
    func_001F64F8(buf, b + D_0032421C, c + D_0032421E, 0x25);
    TOMkpShapeXY(0x22, b + D_00324220, c + D_00324222);
    func_002F0008(buf, D_005700A8, TkMenuGetMP(a), TkMenuGetMaxMP(a));
    func_001F64F8(buf, b + D_00324224, c + D_00324226, 0x25);
    TOMakePktBoxXYWHRGBA(0, c + 0x21, 0x200, 3, 0, 0, 0, 0x80);
    TOMkpShapeXY(0x107, b + D_00324228 + 0x68, c + D_0032422A);
    func_001F5E80(func_00242468(a), b + D_00324228 + D_0032422C, c + D_0032422A + D_0032422E, 0);
    func_001F63B8(MsGetNextAP(a) - func_001BE5C0(a), b + D_00324228 + 0x8B, c + D_0032422A - 0xD, 0x25);
    TOMenuDrawKickTmp();
}
