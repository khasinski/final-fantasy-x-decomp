/* tu_226 0x201760-0x2021e8: medium; unk_201760 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/u3.h"
#include "ffx/s4.h"
#include "ffx/t4.h"
#include "ffx/v4.h"

INCLUDE_ASM("build/ee_asm/game/menu/menu_201760", func_00201760);

INCLUDE_ASM("build/ee_asm/game/menu/menu_201760", func_002018D8);

void *func_00201A68(void *list, int a, int x, int y)
{
    list = func_001FF020(list, 0xDA, 0xDB, x, y, 0xD5, 0x80000000, 0x80000000);
    return func_00201760(list, a, x + 0x15, y + 5, 0x80808080);
}

void *func_00201AE0(void *list, int a, int x, int y, u32 c0, u32 c1)
{
    list = func_001FF020(list, 0xDA, 0xDB, x, y, 0xD5, c0 & 0xFF000000, c1 & 0xFF000000);
    return func_00201760(list, a, x + 0x15, y + 5, c0 & 0xFF000000);
}

void func_00201B60(int x, int y, int w)
{
    int y1 = y - 4;

    TOMkpShapeXY(0x1F4, x - 7, y1);
    TOMkpShapeXY(0x1F6, x + w - 8, y1);
    func_001FE298(0x1F5, x, y1, w, 0, 0x80808080, 0x80808080);
}

float func_00201BE0(int a, int b)
{
    float r = 1.0f - (float)a / (float)b;

    return 1.0f - r * r;
}

float func_00201C18(s32 a, s32 b)
{
    float r = (float)a / (float)b;
    return r * r;
}

float func_00201C40(s32 arg0, s32 arg1)
{
    float angle;

    angle = (float)arg0 / (float)arg1;
    angle = 1.0f - angle;
    angle *= 3.1415927f;
    if (angle > 3.1415927f)
    {
        angle = 3.1415927f;
    }
    if (angle < 0.0f)
    {
        angle = 0.0f;
    }
    angle = func_002E8648(angle);
    angle += 1.0f;
    return angle * 0.5f;
}

void func_00201CD0(void)
{
    int i;

    for (i = 0; i < 16; i++) {
        func_002EF0D0(&D_006672D8[i], 0, 0x10);
    }
}

void func_00201D20(int i, int v)
{
    if (i < 0x10) {
        D_006672D8[i].hE = v;
    }
}

void func_00201D48(int i, int x, int y, int v)
{
    if (i < 16) {
        if (x == D_006672D8[i].h2 && y == D_006672D8[i].h4) {
            return;
        }
        D_006672D8[i].h0 = 1;
        D_006672D8[i].h2 = x;
        D_006672D8[i].h4 = y;
        if (D_006672D8[i].hE != 1) {
            D_006672D8[i].h6 = v;
            D_006672D8[i].h8 = 0;
            D_006672D8[i].hC = v / 14 + 2;
            D_006672D8[i].hA = 0;
        }
    }
}

void func_00201DE8(int i, int x, int y, int v)
{
    if (i < 16) {
        if (x == D_006672D8[i].h2 && y == D_006672D8[i].h4) {
            return;
        }
        D_006672D8[i].h0 = 1;
        D_006672D8[i].h2 = x;
        D_006672D8[i].h4 = y;
        if (D_006672D8[i].hE != 1) {
            D_006672D8[i].h6 = v;
            D_006672D8[i].h8 = v;
            D_006672D8[i].hC = 10;
            D_006672D8[i].hA = 10;
        }
    }
}

void func_00201E78(int i, int x, int y, int v)
{
    if (i < 16) {
        if (x == D_006672D8[i].h2 && y == D_006672D8[i].h4) {
            return;
        }
        D_006672D8[i].h0 = 1;
        D_006672D8[i].h2 = x;
        D_006672D8[i].h4 = y;
        if (D_006672D8[i].hE == 0) {
            D_006672D8[i].h6 = v;
            D_006672D8[i].h8 = 0;
            D_006672D8[i].hC = v / 14 + 2;
            D_006672D8[i].hA = 0;
            D_006672D8[i].hE = 1;
        }
    }
}

void func_00201F20(int i)
{
    if (i < 16) {
        func_002EF0D0(&D_006672D8[i], 0, 0x10);
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/menu_201760", func_00201F50);

/* Text window measuring helpers (TextWin). Module guess: meswin.c-like. */

INCLUDE_ASM("build/ee_asm/game/menu/menu_201760", func_002020A0);
