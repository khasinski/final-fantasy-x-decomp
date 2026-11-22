/* tu_227 0x2021e8-0x207648: medium; ~TOGetFFXToAlbhedTblAdrs (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/s4.h"
#include "ffx/t4.h"
#include "ffx/v4.h"
#include "ffx/u3.h"

typedef struct ToItem {
    /* 0x00 */ V4Rgba4 col;
    /* 0x04 */ U3Rect box;
    /* 0x0C */ u8 pad0C[6];
    /* 0x12 */ u8 f12;
    /* 0x13 */ u8 f13;
} ToItem;

typedef struct ToWin {
    /* 0x00 */ s16 h00;
    /* 0x02 */ s16 h02;
    /* 0x04 */ s16 font;
    /* 0x06 */ u8 pad06[8];
    /* 0x0E */ s16 h0E;
    /* 0x10 */ u16 h10;
    /* 0x12 */ u8 pad12[8];
    /* 0x1A */ s16 style;
    /* 0x1C */ s16 h1C;
    /* 0x1E */ s16 h1E;
    /* 0x20 */ s16 h20;
    /* 0x22 */ s16 h22;
    /* 0x24 */ s16 h24;
    /* 0x26 */ s16 h26;
    /* 0x28 */ s16 h28;
    /* 0x2A */ s16 h2A;
    /* 0x2C */ s16 h2C;
    /* 0x2E */ s16 h2E;
    /* 0x30 */ s16 h30;
    /* 0x32 */ s16 h32;
    /* 0x34 */ s16 h34;
    /* 0x36 */ s16 h36;
    /* 0x38 */ s16 h38;
    /* 0x3A */ s16 h3A;
    /* 0x3C */ s16 h3C;
    /* 0x3E */ s16 h3E;
    /* 0x40 */ U3Rect box40;
    /* 0x48 */ V4Rgba4 col48;
    /* 0x4C */ s32 w4C;
    /* 0x50 */ u8 *p50;
    /* 0x54 */ u8 *p54;
    /* 0x58 */ u8 pad58[0x10];
    /* 0x68 */ u8 *p68;
    /* 0x6C */ u8 *p6C;
    /* 0x70 */ u8 pad70[0xC];
    /* 0x7C */ u8 *cur;
    /* 0x80 */ u8 *p80;
    /* 0x84 */ u8 *p84;
    /* 0x88 */ u8 *p88;
    /* 0x8C */ s32 w8C;
    /* 0x90 */ s32 w90;
    /* 0x94 */ s32 w94;
    /* 0x98 */ s32 w98;
    /* 0x9C */ s32 w9C;
    /* 0xA0 */ s32 wA0;
    /* 0xA4 */ s32 wA4;
    /* 0xA8 */ ToItem itemA8;
    /* 0xBC */ ToItem itemBC;
    /* 0xD0 */ u8 padD0[0x24];
    /* 0xF4 */ s32 wF4;
    /* 0xF8 */ s32 wF8;
    /* 0xFC */ s32 wFC;
} ToWin;

extern u8 D_00323910[];
int TOGetChangeMacroWidth(int a, u8 *b, int c);

void *TOGetFFXToAlbhedTblAdrs(void)
{
    return &D_006673D8;
}

typedef struct AlbhedEnt {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} AlbhedEnt;

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

s32 _m2c_func_00202A10_func_00203FC0() __asm__("func_00203FC0");
/* DEBT(FAKE) */
s32 func_00202A10(MenuCmd *arg0) {
    register s32 temp_2 __asm__("$2");
    s32 temp_4;
    register s32 temp_4_2 __asm__("$4");
    s32 temp_5;
    s32 var_3;
    s32 var_3_2;

    temp_4 = arg0->x98;
    temp_5 = arg0->x90;
    var_3 = temp_4;
    if (temp_4 >= temp_5) {
        var_3 = temp_5;
        if (var_3 < 0) {
            var_3 = 0;
        }
    }
    arg0->x90 = var_3;
    if (var_3 >= temp_4) {
        arg0->sub = arg0->state = 2;
        if (*arg0->text == 0) {
            arg0->sub = 3;
        }
        arg0->fn[5] = func_00202AD8;
        arg0->fn[7] = func_00202A10;
    }
    _m2c_func_00202A10_func_00203FC0(arg0);
    temp_2 = arg0->x98;
    temp_4_2 = arg0->x90;
    var_3_2 = temp_2;
    __asm__ volatile("" : "+r"(temp_2), "+r"(var_3_2), "+r"(temp_4_2));
    if (temp_2 >= temp_4_2) {
        var_3_2 = temp_4_2;
        __asm__ volatile("" : "+r"(var_3_2));
        if (var_3_2 < 0) {
            var_3_2 = 0;
        }
    }
    arg0->x90 = var_3_2;
    return 0;
}

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

typedef struct TextWinCopy20 {
    u8 b[0x14];
} TextWinCopy20;

typedef struct TextWinEx {
    /* 0x00 */ s16 f00;
    /* 0x02 */ u8 pad02[2];
    /* 0x04 */ s16 font;
    /* 0x06 */ u8 pad06[0x14];
    /* 0x1A */ s16 style;
    /* 0x1C */ s16 f1C;
    /* 0x1E */ s16 f1E;
    /* 0x20 */ u8 pad20[0xC];
    /* 0x2C */ s16 f2C;
    /* 0x2E */ s16 f2E;
    /* 0x30 */ s16 f30;
    /* 0x32 */ s16 f32;
    /* 0x34 */ u8 pad34[4];
    /* 0x38 */ s16 textW;
    /* 0x3A */ s16 textH;
    /* 0x3C */ s16 f3C;
    /* 0x3E */ s16 f3E;
    /* 0x40 */ s16 scr[4];
    /* 0x48 */ u8 pad48[8];
    /* 0x50 */ u8 *p50;
    /* 0x54 */ u8 *p54;
    /* 0x58 */ u8 pad58[0x10];
    /* 0x68 */ u8 *p68;
    /* 0x6C */ u8 *p6C;
    /* 0x70 */ u8 pad70[0x14];
    /* 0x84 */ u8 *p84;
    /* 0x88 */ u8 *p88;
    /* 0x8C */ s32 f8C;
    /* 0x90 */ s32 f90;
    /* 0x94 */ s32 f94;
    /* 0x98 */ s32 f98;
    /* 0x9C */ s32 f9C;
    /* 0xA0 */ u8 padA0[8];
    /* 0xA8 */ TextWinCopy20 dstA8;
    /* 0xBC */ TextWinCopy20 srcBC;
    /* 0xD0 */ u8 padD0[0x24];
    /* 0xF4 */ s32 fF4;
    /* 0xF8 */ s32 fF8;
    /* 0xFC */ s32 fFC;
} TextWinEx;

int _TOSetNewPageMessageNormal(TextWinEx *win)
{
    s16 x;
    s16 y;

    if (win->p88 != 0) {
        win->p84 = win->p88 + 1;
    }
    win->p88 = (u8 *)TOGetPageEndAddress(win->p84);
    if (win->p54 != 0) {
        win->p50 = win->p54 + 1;
    }
    win->p54 = (u8 *)TOGetPageEndAddress(win->p50);
    if (win->p6C != 0) {
        win->p68 = win->p6C + 1;
    }
    win->p6C = (u8 *)TOGetPageEndAddress(win->p68);
    win->f90 = 0;
    win->f94 = 0;
    win->f98 = TOGetWordCount(win->font, (int)win->p84); /* DEBT(CAST): ptr as int */
    if (win->f9C == 0) {
        win->f90++;
    }
    _TOGetMessageWH(win->font, win->p84, &win->f3C, &win->f3E, win->style, 1);
    if (TOGetMessageWindowMode() == 1) {
        x = win->f30 + (win->textW - win->f3C) / 2;
        y = 1;
    } else {
        x = win->f30 + (win->textW - win->f3C) / 2;
        y = win->f32 + (win->textH - win->f3E) / 2;
    }
    graphicFontGetScreenWH(win->scr, x, y, win->f3C, win->f3E);
    if (win->f1E == 1) {
        _TOScanSelecterWH(win->font, win->p84, win->style, 1);
    }
    win->f2C = 1;
    win->f2E = 1;
    win->fF4 = win->fFC;
    win->dstA8 = win->srcBC;
    return 0;
}

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

int _TOFirstInitMessageNamesp(ToWin *win)
{
    s16 w = 0;
    s16 h = 0;
    u8 *p;
    s16 w0;

    win->h38 = 0;
    win->h3A = 0;
    win->h3C = 0;
    win->h3E = 0;
    p = win->p80;
    while (*p != 0) {
        p = (u8 *)_TOGetMessageWH(win->font, p, &w, &h, win->style, win->h10 | 3);
        if (win->h22 == 1) {
            if (w > 0) {
                w += TOGetChangeMacroWidth(0, D_00323910, win->style);
            }
            w0 = w;
            h = 0;
        } else {
            h = 0;
            w0 = 0;
        }
        p = (u8 *)_TOGetMessageWH(win->font, p, &w, &h, win->style, win->h10 | 1);
        if (win->h38 < w0 + w) {
            win->h38 = w0 + w;
        }
        if (win->h3A < h) {
            win->h3A = h;
        }
    }
    return 0;
}

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

int _TOSetNewPageMessageNamesp(ToWin *win)
{
    s16 w = 0;
    s16 h = 0;
    u8 *p;
    s16 x;
    s16 y;

    if (win->p88 != 0) {
        win->p84 = win->p88 + 1;
    }
    win->p88 = (u8 *)TOGetPageEndAddress(win->p84);
    p = win->p84;
    if (win->p54 != 0) {
        win->p50 = win->p54 + 1;
    }
    win->p54 = (u8 *)TOGetPageEndAddress(win->p50);
    if (win->p6C != 0) {
        win->p68 = win->p6C + 1;
    }
    win->p6C = (u8 *)TOGetPageEndAddress(win->p68);
    win->h24 = TOGetWordCountLimit(win->font, p, 3);
    win->h28 = win->h24;
    if (win->h24 > 0) {
        win->h28 += TOGetWordCountLimit(win->font, D_00323910, 0);
    }
    if (win->h22 == 1) {
        p = (u8 *)_TOGetMessageWH(win->font, p, &w, &h, win->style, win->h10 | 3);
        if (w > 0) {
            w += TOGetChangeMacroWidth(win->font, D_00323910, win->style);
        }
        win->h2A = w;
        _TOGetMessageWH(win->font, p, &win->h3C, &win->h3E, win->style, win->h10 | 1);
        win->h3C += w;
        win->w90 = win->h28;
    } else {
        p = (u8 *)_TOGetMessageWH(win->font, p, &w, &h, win->style, win->h10 | 3);
        _TOGetMessageWH(win->font, p, &win->h3C, &win->h3E, win->style, win->h10 | 1);
        win->w90 = win->h28;
    }
    if (win->w9C == 0) {
        win->w90++;
    }
    win->w94 = 0;
    win->w98 = TOGetWordCount(win->font, (int)win->p84); /* DEBT(CAST): ptr as int */
    if (win->h22 == 1) {
        if (win->h24 > 0) {
            win->w98 += TOGetWordCount(0, (int)TOGetChangeMacroAddress(0, D_00323910)); /* DEBT(CAST): ptr as int */
        }
    }
    if (win->h24 > 0) {
        s16 cnt = win->h24;
        if (win->h22 == 1) {
            cnt = win->h28;
        }
        if (win->w98 == cnt) {
            win->h02 = 1;
        }
    }
    x = win->h30 + (win->h38 - win->h3C) / 2;
    y = win->h32 + (win->h3A - win->h3E) / 2;
    graphicFontGetScreenWH(&win->box40, x, y, win->h3C, win->h3E);
    if (win->h28 > 0) {
        win->h0E = 0;
    }
    if (win->h1E == 1 && win->h1C > 0) {
        _TOScanSelecterWH(win->font, win->p84, win->style, 1);
    }
    win->h2C = 1;
    win->h2E = 1;
    win->wF4 = win->wFC;
    win->itemA8 = win->itemBC;
    return 0;
}

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
