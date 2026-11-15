#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/s4.h"
#include "ffx/t4.h"
#include "ffx/v4.h"
#include "ffx/u3.h"

u8 *func_00204080(u8 *s, int n)
{
    while (n != 0) {
        u8 c = *s;

        if (c <= 2) {
            n--;
        }
        if (c >= 0x26) {
            n--;
        }
        s = TOSkipCode(s);
    }
    return s;
}

void *func_002040E8(void)
{
    return &D_005702D0;
}

void func_002040F8(int i)
{
    int j;

    for (j = 0; j < 32; j++) {
        D_0066AB00[i][j]->b1 = D_0066AB00[i][j]->b0;
    }
    for (j = 0; j < 32; j++) {
        D_0066AB00[i][j]->b0 = -1;
    }
}

void func_00204168(int i)
{
    int j;

    func_002EF0D0(D_00668740[i], 0, 0x110);
    func_002EF0D0(D_00669AE0[i], 0, 0x138);
    D_00668740[i]->slot = D_00669AE0[i];
    for (j = 0; j < 32; j++) {
        D_0066AB00[i][j]->b1 = D_0066AB00[i][j]->b0;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", TOSetExeMessageArea);

void TOInitMacroCmd(int r)
{
    int c;

    for (c = 0; c < 32; c++) {
        D_0066AB00[r][c]->b0 = -1;
        D_0066AB00[r][c]->b1 = -1;
        D_0066AB00[r][c]->w4 = -1;
    }
}

MenuCmd *func_002043D0(s32 idx)
{
    return D_00668740[idx];
}

SlotZ *func_002043E8(s32 idx)
{
    return D_00669AE0[idx];
}

void TOOpenMessage(int i)
{
    D_00668740[i]->w00 = 1;
    D_00668740[i]->state = 0;
    D_00668740[i]->fn[0](D_00668740[i]);
    D_00668740[i]->fn[5] = D_00668740[i]->fn[1];
    D_00668740[i]->fD8(D_00668740[i]);
}

int TOControlMessage(int i)
{
    MenuCmd *c = D_00668740[i];

    if (c->w00 != 1) {
        return 0;
    }
    if (c->fn[5] == 0) {
        return 0;
    }
    return c->fn[5](c);
}

int TOCloseMessage(int i)
{
    MenuCmd *m = D_00668740[i];

    if (m->w00 != 0) {
        m->state = 3;
        m->fn[5] = m->fn[3];
    }
}

void TODrawSelectCursor(int);
void TODrawMessage(int id)
{
    if (D_00668740[id]->w00 == 0) {
        return;
    }
    if (*(s16 *)D_00668740[id]->pad02 == 1) {
        return;
    }
    {
        if (D_00668740[id]->w1E == 1 && TOGetWindowStatus(id) == 2 && D_00668740[id]->w1C == 2) {
            TODrawSelectCursor(id);
        }
        if (TOGetMessageWindowMode() == 1) {
            _TODrawMovieMessageWaitNamesp(D_00668740[id]);
        } else {
            D_00668740[id]->f10C(D_00668740[id]);
        }
        if (D_00668740[id]->w1E == 1 && TOGetWindowStatus(id) == 2 && D_00668740[id]->w1C == 1) {
            TODrawSelectCursor(id);
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", TODrawSelectCursor);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", TOSetMessageType);

void TOSetMessageFunc(s32 i, s32 k)
{
    MenuCmd *m = D_00668740[i];

    if (m->w00 != 0) {
        if (m->fn[k] != 0) {
            m->fn[5] = m->fn[k];
        }
    }
}

int TOGetWordCount(int id, int address)
{
    u8 *s = (u8 *)address;
    int count = 0;
    while (*s >= 3) {
        switch (TOGetGroup(*s)) {
        case 4:
            count++;
            break;
        case 2:
            if (*s == 0x10 && (unsigned)(s[1] - 0x50) < 0x10)
                count += TOGetChangeMacroWordCount(id, s);
            if (*s == 0xB) count++;
            if (*s == 9 && s[1] >= 0xC0) count++;
            break;
        case 3:
            count += TOGetChangeMacroWordCount(id, s);
            break;
        }
        s = TOSkipCode(s);
    }
    return count;
}

int TOGetWordCountLimit(int id, int address, int limit)
{
    u8 *s = (u8 *)address;
    int count = 0;
    while (*s > limit) {
        switch (TOGetGroup(*s)) {
        case 4:
            count++;
            break;
        case 2:
            if (*s == 0x10 && (unsigned)(s[1] - 0x50) < 0x10)
                count += TOGetChangeMacroWordCount(id, s);
            if (*s == 0xB) count++;
            if (*s == 9 && s[1] >= 0xC0) count++;
            break;
        case 3:
            count += TOGetChangeMacroWordCount(id, s);
            break;
        }
        s = TOSkipCode(s);
    }
    return count;
}

u8 *TOGetPageEndAddress(u8 *s)
{
    while (*s > 2) {
        s = TOSkipCode(s);
    }
    return s;
}

void func_00204C60(int i)
{
    MenuCmd *m = D_00668740[i];

    if (*m->text != 0) {
        m->fD8(m);
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", func_00204CA8);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", TOGetFontInfoInterMode);

u8 *func_00205228(u8 *s, int flags, int *width)
{
    return func_002052F8(s, flags, width, TOGetInternationalBaseDicType());
}

u8 *func_00205278(u8 *s, int flags, int *width, int d)
{
    if (func_0020B850() == 0 && d == 0) {
        return func_002052F8(s, flags, width, 0);
    }
    return func_002052F8(s, flags, width, 4);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", func_002052F8);

int func_00205480(u8 *s)
{
    int n = 0;

    while (*s) {
        if (*s == 0x10 && s[1] != 0xFF) {
            n++;
        }
        s = TOSkipCode(s);
    }
    return n;
}

/* DEBT(CAST) */
s32 TOSetMessageAuto(s32 w, s32 a, s32 b) {
    MenuCmd **temp_20;
    MenuCmd *temp_2_3;
    MenuCmd *temp_3;
    MenuCmd *temp_3_2;
    MenuCmd *temp_4;
    s32 temp_2;
    s32 temp_2_2;
    s32 var_17;

    var_17 = b;
    temp_2 = TOGetFFXLangSwapFlag();
    if ((temp_2 == 1) && (func_001BD360() == temp_2)) {
        var_17 = ((D_00323954 ^ 1) == 0) ? a : var_17;
    }
    temp_20 = &D_00668740[w];
    temp_3 = *temp_20;
    (*(s32 *)((u8 *)(temp_3) + (0x4C))) = a;
    (*(s32 *)((u8 *)(temp_3) + (0x64))) = var_17;
    (*(s32 *)((u8 *)(temp_3) + (0x50))) = a;
    (*(s32 *)((u8 *)(temp_3) + (0x68))) = var_17;
    temp_2_2 = TOGetFFXLangSwapFlag();
    if ((temp_2_2 == 1) && (func_001BD360() == temp_2_2)) {
        temp_2_3 = *temp_20;
        (*(s32 *)((u8 *)(temp_2_3) + (0x80))) = (s32) (*(s32 *)((u8 *)(temp_2_3) + (0x64)));
        temp_2_3->x84 = (*(s32 *)((u8 *)(temp_2_3) + (0x68)));
    } else {
        temp_3_2 = D_00668740[w];
        (*(s32 *)((u8 *)(temp_3_2) + (0x80))) = (s32) (*(s32 *)((u8 *)(temp_3_2) + (0x4C)));
        temp_3_2->x84 = (*(s32 *)((u8 *)(temp_3_2) + (0x50)));
    }
    (*(s16 *)((u8 *)(D_00668740[w]) + (0x20))) = 0;
    if (MsGetSaveConfigCreditName() == 1) {
        (*(s16 *)((u8 *)(D_00668740[w]) + (0x22))) = 1;
    } else {
        (*(s16 *)((u8 *)(D_00668740[w]) + (0x22))) = 0;
    }
    temp_4 = D_00668740[w];
    return temp_4->fD4(temp_4);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", TOSwapRenewMessage);

void func_002059C8(int i, u8 *text)
{
    D_00668740[i]->x84 = (s32)text;
    D_00668740[i]->text = TOGetPageEndAddress(text);
}

void func_00205A10(int i, int x, int y, int w, int h)
{
    MenuCmd *m = D_00668740[i];

    m->w = w;
    m->h = h;
    m->x = x;
    m->y = y;
    m->x1 = x + w;
    m->y1 = y + h;
}

void graphicFontGetScreenWH(s16 *rect, int x, int y, int w, int h)
{
    rect[0] = x;
    rect[1] = y;
    rect[2] = x + w;
    rect[3] = y + h;
}

int func_00205A68(int i)
{
    SlotZ *z = D_00669AE0[i];

    if (z->b1 != 2) {
        return -1;
    }
    return z->b7;
}

u8 *func_00205AA0(int i)
{
    SlotZ *z = D_00669AE0[i];

    if (z->b1 != 2) {
        return 0;
    }
    return z->x18;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", TOGetPadStatus);

void TOGetControlPadStatus(int i)
{
    MenuCmd *m = D_00668740[i];

    if (m->state == 2) {
        m->fDC(i);
    }
}

int TOGetMessageStatus(int i)
{
    return D_00668740[i]->sub;
}

void func_00205D98(s32 i, s16 v)
{
    D_00668740[i]->sub = v;
}

int func_00205DB8(int i)
{
    return D_00669AE0[i]->b1;
}

void func_00205DD8(void) {
}

int func_00205DE0(int v)
{
    return 0x640064;
}

int func_00205DF0(u8 *s)
{
    int total = 0;
    int w;

    while (*s) {
        s = func_00205228(s, 0, &w);
        total += w;
    }
    return total;
}

int func_00205E40(int font, u8 *text)
{
    s16 size[2];

    _TOGetMessageWH(font, text, &size[0], &size[1], 0, 0);
    return (size[1] << 16) | size[0];
}

int func_00205E78(u8 *s, int d)
{
    int total = 0;
    int w;

    while (*s) {
        s = func_00205278(s, 0, &w, d);
        total += w;
    }
    return total;
}

int func_00205ED8(u8 *text)
{
    s16 size[2];

    _TOGetMessageWH(0, text, &size[0], &size[1], 0, 0);
    return (size[1] << 16) | size[0];
}

int func_00205F18(int font, u8 *text)
{
    s16 size[2];

    _TOGetMessageWH(font, text, &size[0], &size[1], 0, 0);
    return (size[1] << 16) | size[0];
}

int TOGetEasyMesWHFontL(u8 *text, int *w, int *h)
{
    s16 size[2];

    _TOGetMessageWH(0, text, &size[0], &size[1], 0, 0);
    *w = size[0];
    *h = size[1];
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", _TOGetMessageWH);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", _TOScanSelecterWH);

void func_00206860(int r, int c, int v)
{
    D_0066AB00[r][c]->b0 = v;
}

void func_00206888(int r, int c, int v)
{
    D_0066AB00[r][c]->w4 = v;
}

int TOBtlSetMacroCommandType(int r, int c, int v)
{
    D_0066AB00[r][c]->b0 = v;
    D_0066AB00[r][c]->b1 = v;
}

void TOBtlSetMacroCommandValue(int r, int c, int v)
{
    D_0066AB00[r][c]->w4 = v;
}

int TOMenuSetMacroCommandType(int r, int c, int v)
{
    D_0066AB00[r][c]->b1 = v;
}

int TOMenuSetMacroCommandValue(int r, int c, int v)
{
    D_0066AB00[r][c]->w4 = v;
}

int func_00206958(int r, int c)
{
    return D_0066AB00[r][c]->w4;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", func_00206980);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", TOGetChangeMacroAddress);
INCLUDE_RODATA("build/ee_asm/game/menu/to/to_2021E8/rodata", jtbl_005702F0);

s32 func_00206EB0(int a, int b)
{
    /* ids start at 19 */
    return (D_0066AF00[b]->w - 19)[a];
}

s32 func_00206ED8(int i)
{
    return D_0066AF00[i]->w[11];
}

int TOGetChangeMacroWordCount(int a, u8 *b)
{
    int n = 0;
    u8 *s = TOGetChangeMacroAddress(a, b);

    if (s == 0) {
        return 0;
    }
    while (*s != 0) {
        if (TOGetGroup(*s) == 3) {
            n += TOGetChangeMacroWordCount(a, s);
        }
        if (*s >= 0x26) {
            n++;
        }
        s = TOSkipCode(s);
    }
    return n;
}

int TOGetChangeMacroWidth(int a, u8 *b, int flags)
{
    int w = 0;
    int n = 0;
    u8 *s = TOGetChangeMacroAddress(a, b);

    if (s == 0) {
        return 0;
    }
    while (*s != 0) {
        if (TOGetGroup(*s) == 3) {
            n += TOGetChangeMacroWidth(a, s, flags);
            s = TOSkipCode(s);
        } else if (*s == 7 && (u8)(s[1] - 0xE1) < 0xF) { /* 0xE1..0xEF */
            n += s[1] - 0xE0;
            s = TOSkipCode(s);
        } else {
            s = func_00205228(s, flags, &w);
            n += w;
        }
    }
    return n;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", func_002070A8);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", TODrawChangeMacro2);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", TODrawMovieChangeMacro2);

char *func_00207538(U3NumFmt *f)
{
    char buf[0x20];
    char *s;
    char *d;
    int n;
    int i;

    func_002F0008(buf, D_00570340, f->w4);
    n = func_002F0840(buf);
    s = buf;
    d = D_00667620;
    for (i = 0; n > 0; i++, n--) {
        if (n % 3 == 0 && i > 0 && f->b1 == 2) {
            *d++ = 0x46;
        }
        *d++ = *s++;
    }
    *d = 0;
    return D_00667620;
}

int func_002075F8(int i)
{
    if (D_00668740[i]->w1E == 1) {
        SlotZ *z = D_00669AE0[i];

        if (z->b1 > 0) {
            return z->b2;
        }
    }
    return -1;
}
