/* tu_227 0x2021e8-0x207648: medium; ~TOGetFFXToAlbhedTblAdrs (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/s4.h"
#include "ffx/t4.h"
#include "ffx/v4.h"
#include "ffx/u3.h"

void *TOGetFFXToAlbhedTblAdrs(void)
{
    return &D_006673D8;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", func_002021F8);

void TOSetAlbhedFlg(int v)
{
    if (v == -1) {
        D_0031D1E0 = 0;
    } else if ((u32)v < 0x1A) {
        D_003194D0.f3D10 |= 1 << v;
    } else if (v == 0xFF) {
        D_0031D1E0 = 0x3FFFFFF;
    }
}

s32 func_002023C0(void)
{
    return D_0031D1E0;
}

void *func_002023D0(void)
{
    return &D_005700B0;
}

int TOGetGroup(u8 c)
{
    switch (c) {
    case 0:
    case 1:
    case 2:
    case 3:
        return 1;
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 13:
    case 14:
    case 16:
        return 2;
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
        return 3;
    default:
        return 4;
    }
}

u8 *TOSkipCode(u8 *s)
{
    switch (*s) {
    case 0:
        break;
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 13:
    case 14:
    case 16:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
        s += 2;
        break;
    default:
        s += 1;
        break;
    }
    return s;
}

void func_00202468(u8 *text, TextWin *win, TextItem *out)
{
    s16 size[2];

    switch (text[0]) {
    case 7:
        if ((u8)(text[1] + 0x20) < 0x10) {
            out->x += text[1] - 0xE0;
        } else {
            _TOGetMessageWH(win->font, text + 2, &size[0], &size[1], win->style, 0x103);
            if (text[1] == 0x31) {
                out->x = win->x0 + (win->x1 - win->x0 - size[0]) / 2;
            }
            if (text[1] == 0x32) {
                out->x = win->x1 - size[0];
            }
            if ((s8)(text[1] - 0x40) >= 0) {
                out->x = win->x0 + (text[1] - 0x40) * 4;
            }
        }
        break;
    case 8:
    case 9:
    case 10:
        break;
    case 11:
        out->x += func_002083E8(text[1]);
        break;
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
        break;
    }
}

void func_002025A8(u8 *text, TextWin *win, TextItem *out)
{
    s16 size[2];

    switch (text[0]) {
    case 7:
        if ((u8)(text[1] + 0x20) < 0x10) {
            out->x += text[1] - 0xE0;
        } else {
            _TOGetMessageWH(win->font, text + 2, &size[0], &size[1], win->style, 0x103);
            if (text[1] == 0x38 && win->f24 == 0) {
                func_00203EE8(win, win->cur + 2, out);
            }
            if (text[1] == 0x31) {
                func_00203EE8(win, win->cur + 2, out);
            }
            if (text[1] == 0x32) {
                out->x = win->x1 - size[0];
            }
            if ((s8)(text[1] - 0x40) >= 0) {
                out->x = win->x0 + (text[1] - 0x40) * 4;
            }
        }
        break;
    case 9:
        if (text[1] == 0x30) {
            win->f9C = 0;
        }
        if (text[1] < 0xC0) {
            if (text[1] != 0x30) {
                win->f9C = text[1] - 0x30;
            }
        }
        if (text[1] >= 0xC0) {
            win->fA4 = text[1] - 0xC0;
        }
        break;
    case 10:
        if ((text[1] & 0xF) != 0) {
            out->f13 = (out->f13 & 0xF0) | ((text[1] & 0xF) - 1);
        }
        if ((text[1] & 0xF0) >= 0x40) {
            out->f13 = (out->f13 & 0xF) | ((text[1] & 0xF0) - 0x40);
        }
        break;
    case 11:
        func_001F31A0(text[1], out->x, out->y);
        win->f8C++;
        if (win->f9C == 0 && win->f90 < win->f98) {
            win->f90++;
        }
        out->x += func_002083E8(text[1]);
        break;
    case 14:
        if ((u8)(text[1] - 0x30) < 4) {
            out->f12 = text[1] - 0x30;
        }
        if (out->f12 == 3 && text[1] == 0x41) {
            out->x += 5;
        }
        if (text[1] == 0x40) {
            out->f12 = 3;
        }
        if (text[1] == 0x41) {
            out->f12 = 1;
        }
        break;
    case 8:
    case 12:
    case 13:
    case 15:
    case 16:
        break;
    }
}

/* DEBT(ORDER): the handlers go through temporaries so all loads come before the stores */
void TOInitMessageCallBack(MenuCmd *m)
{
    MenuFn f0 = D_00323648[m->x08].fn[0];
    MenuFn f1 = D_00323648[m->x08].fn[1];
    MenuFn f2 = D_00323648[m->x08].fn[2];
    MenuFn f3 = D_00323648[m->x08].fn[3];
    MenuFn f4 = D_00323648[m->x08].fn[4];

    m->fn[0] = f0;
    m->fn[1] = f1;
    m->fn[2] = f2;
    m->fn[3] = f3;
    m->fn[4] = f4;
    if (TOGetMessageWindowMode() == 1) {
        m->f10C = _TODrawMovieMessageWaitNamesp;
    } else {
        m->f10C = D_00323648[m->x08].f14;
    }
    {
        MenuFn f5 = D_00323648[m->x08].f18;
        MenuFn f6 = D_00323648[m->x08].f1C;

        m->fD8 = f6;
        m->fD4 = f5;
    }
}

int func_00202940(void)
{
    return 0;
}

int func_00202948(TextWin *win)
{
    win->y0 -= 12;
    win->f2C = 1;
    win->fF4 = win->fE4;
    return 0;
}

int _TOInitMessageWaitNormal(TextWin *win)
{
    win->f90 = 0;
    win->fA4 = 0;
    switch (func_0020B850()) {
    case 0:
    case 1:
    case 16:
    case 17:
    case 18:
        win->f9C = 30;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        win->f9C = 25;
        break;
    }
    win->f98 = TOGetWordCount(win->font, win->f84);
    win->fF8 = _TOInitMessageWaitNormal;
    win->col[0] = 0x80;
    win->col[1] = 0x80;
    win->col[2] = 0x80;
    win->col[3] = 0x80;
    win->f2E = 1;
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", func_00202A10);

s32 func_00202AD8(MenuCmd *m)
{
    m->fn[8] = func_00202AD8;
    if (m->w12 == 1) {
        func_00204C60(m->id);
    }
    return 0;
}

s32 func_00202B18(MenuCmd *m)
{
    m->state = 4;
    m->fn[9] = func_00202B18;
    return 0;
}

int func_00202B38(TextWin *win)
{
    win->f00 = 0;
    win->f2C = 0;
    win->f2E = 0;
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", _TODrawMessageWaitNormal);

int func_00202E98(TextWin *win)
{
    _TOGetMessageWH(win->font, win->text, &win->textW, &win->textH, win->style, 0x100);
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", _TOSetNewPageMessageNormal);

s32 _TOInitMessageNoWaitNormal(MenuCmd *m)
{
    m->x90 = 0;
    if (TOGetFFXVideoMode()) {
        m->x9C = 0x19;
    } else {
        m->x9C = 0x1E;
    }
    m->x98 = TOGetWordCount(m->id, m->x84);
    m->fn[6] = _TOInitMessageNoWaitNormal;
    return 0;
}

int func_00203108(MenuCmd *m)
{
    m->state = 2;
    m->x90 = m->x98;
    m->fn[5] = func_00202940;
    m->fn[7] = func_00202A10;
    return 0;
}

s32 func_00203138(MenuCmd *m)
{
    m->sub = 2;
    if (*m->text == 0) {
        m->sub = 3;
    }
    m->fn[8] = func_00203138;
    return 0;
}

s32 func_00203168(MenuCmd *m)
{
    m->state = 4;
    m->fn[9] = func_00203168;
    return 0;
}

s32 func_00203188(MenuCmd *m)
{
    m->w00 = 0;
    m->state = 0;
    return 0;
}

int func_00203198(void)
{
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", _TOFirstInitMessageNamesp);

int _TOInitMessageWaitNamesp(R4Menu *o)
{
    o->w90 = 0;
    o->wA0 = 0;
    o->wA4 = 0;
    if (TOGetFFXVideoMode() != 0) {
        o->w9C = 0x19;
    } else {
        o->w9C = 0x1E;
    }
    o->fF8 = _TOInitMessageWaitNormal;
    o->b48 = 0x80;
    o->b49 = 0x80;
    o->b4A = 0x80;
    o->b4B = 0x80;
    o->h2E = 1;
    return 0;
}

s32 func_00203358(MenuCmd *m)
{
    m->x90 = (m->x90 > m->x98) ? m->x98 : (m->x90 < 0) ? 0 : m->x90;
    if (m->x90 >= m->x98 && m->xA4 == 0) {
        m->sub = m->state = 2;
        if (*m->text == 0) {
            m->sub = 3;
        }
        m->fn[5] = func_00202AD8;
        m->fn[7] = func_00203358;
    }
    func_00203FC0(m);
    m->x90 = (m->x90 > m->x98) ? m->x98 : (m->x90 < 0) ? 0 : m->x90;
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", _TODrawMessageWaitNamesp);

s32 func_002037F0(MenuCmd *m)
{
    m->fn[9] = func_00202B18;
    m->b4B -= 0x10;
    m->state = 4;
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", _TODrawMovieMessageWaitNamesp);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", _TOSetNewPageMessageNamesp);

void func_00203EE8(TextWin *win, u8 *text, TextItem *out)
{
    s16 size[2];

    _TOGetMessageWH(win->font, text, &size[0], &size[1], win->style, 0x103);
    out->x = win->x0 + (win->x1 - win->x0 - size[0]) / 2;
}

void func_00203F58(TextWin *win, int unused, TextItem *out)
{
    out->x = win->x0;
}

void func_00203F68(TextWin *win, u8 *text, TextItem *out)
{
    s16 size[2];

    _TOGetMessageWH(win->font, text, &size[0], &size[1], win->style, 3);
    out->x = win->x1 - size[0];
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", func_00203FC0);

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

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", TODrawMessage);

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

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", TOGetWordCount);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", TOGetWordCountLimit);

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

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2021E8", TOSetMessageAuto);

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
