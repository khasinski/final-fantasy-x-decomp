#define D_003238D0 _hdr_D_003238D0
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/s4.h"
#include "ffx/t4.h"
#include "ffx/v4.h"
#include "ffx/u3.h"
#undef D_003238D0

typedef struct {
    /* 0x00 */ s8 b0;
    /* 0x01 */ s8 b1;
    /* 0x02 */ s8 timer[16];
    /* 0x12 */ u16 h12;
    /* 0x14 */ u16 h14;
    /* 0x16 */ u16 h16;
    /* 0x18 */ u8 pad18[6];
    /* 0x1E */ u8 b1E;
    /* 0x1F */ u8 b1F;
    /* 0x20 */ u8 b20;
    /* 0x21 */ u8 b21;
    /* 0x22 */ u16 h22;
    /* 0x24 */ u16 h24;
    /* 0x26 */ u16 h26;
    /* 0x28 */ u8 pad28[0x18];
} ToPadBlock;
extern ToPadBlock D_003238D0;

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

typedef struct {
    u8 pad[0x138];
} SlotZFull;

extern MenuCmd D_00667640[];
extern MenuCmd D_00667EC0[];
extern SlotZFull D_00668760[];
extern SlotZFull D_00669120[];
extern Cell D_00669B00[][32];
extern Cell D_0066A300[][32];

void TOSetExeMessageArea(s32 a)
{
    int i, j;

    if (a == 0) {
        for (i = 0; i < 8; i++) {
            D_00668740[i] = &D_00667640[i];
            D_00669AE0[i] = (SlotZ *)&D_00668760[i];
        }
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 32; j++) {
                D_0066AB00[i][j] = &D_00669B00[i][j];
            }
        }
    } else {
        for (i = 0; i < 8; i++) {
            D_00668740[i] = &D_00667EC0[i];
            D_00669AE0[i] = (SlotZ *)&D_00669120[i];
        }
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 32; j++) {
                D_0066AB00[i][j] = &D_0066A300[i][j];
            }
        }
    }
}

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

extern UiFrame D_00323918;
void func_001F0328(int x, int y, int w, int h, u32 c0, u32 c1);

void TODrawSelectCursor(int i)
{
    UiFrame *p = &D_00323918;

    func_002EF0D0(p, 0, 0x14);
    if (D_00668740[i]->state == 2) {
        if (D_00669AE0[i]->b1 == 0) {
            D_00669AE0[i]->b1 = 1;
        }
    }
    if (D_00669AE0[i]->b1 == 1) {
        p->col.r = 0x70;
        p->col.g = 0x70;
        p->col.b = 0x10;
        p->col.a = 0x80;
        p->box.x0 = ((TextWin *)D_00668740[i])->x0 + D_00669AE0[i]->ent[D_00669AE0[i]->b2].h4;
        p->box.y0 = ((TextWin *)D_00668740[i])->y0 + D_00669AE0[i]->ent[D_00669AE0[i]->b2].h6 - 2;
        p->box.x1 = p->box.x0 + D_00669AE0[i]->ent[D_00669AE0[i]->b2].h2;
        p->box.y1 = p->box.y0 + 2;
        if (D_00668740[i]->w1C == 2) {
            if (func_0020B850() == 0 && func_001BD360() == 0) {
                func_001F0328(p->box.x0, p->box.y0 - 0x12, 0xC, 0x16, 0x80008080, 0x80008080);
            } else {
                func_001F0328(p->box.x0, p->box.y0 - 0x12, 8, 0x14, 0x80008080, 0x80008080);
            }
        } else {
            func_001FE7F8(0, p->box.x0, p->box.y0 - 0x14);
        }
    }
}

void TOInitMessageCallBack(MenuCmd *m);

int TOSetMessageType(int i, int v)
{
    D_00668740[i]->x08 = v & 0xF;
    if (v & 0x4000) {
        D_00668740[i]->h10 = 0x4000;
    } else {
        D_00668740[i]->h10 = 0;
    }
    if (v & 0x2000) {
        if (v & 0x8000) {
            D_00668740[i]->h1A = 3;
        } else {
            D_00668740[i]->h1A = 1;
        }
    } else {
        D_00668740[i]->h1A = 0;
    }
    if (v & 0x1000) {
        D_00668740[i]->h0C = 1;
    } else {
        D_00668740[i]->h0C = 0;
    }
    if (v & 0x400) {
        D_00668740[i]->w12 = 1;
    } else {
        D_00668740[i]->w12 = 0;
    }
    if (!((*(s32 *)MsGetSaveMenu() >> 8) & 1)) {
        D_00668740[i]->h0C = 1;
    }
    if (D_00668740[i]->x08 == 3) {
        if (v & 0x8000) {
            D_00668740[i]->h1A = 3;
        } else {
            D_00668740[i]->h1A = 1;
        }
    }
    TOInitMessageCallBack(D_00668740[i]);
    return 0;
}

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

typedef struct {
    s16 h00;
    s16 h02;
    s16 h04;
    s16 h06;
    s32 w08;
    u8 pad0C[4];
    u16 h10;
    u8 pad12[8];
    s16 h1A;
    s16 h1C;
    s16 h1E;
    s16 h20;
    s16 h22;
    s16 h24;
    s16 h26;
    s16 h28;
    s16 h2A;
    u8 pad2C[4];
    u16 h30;
    u16 h32;
    u8 pad34[4];
    s16 h38;
    s16 h3A;
    s16 h3C;
    s16 h3E;
    u8 x40[0x44];
    u8 *p84;
    u8 pad88[8];
    s32 w90;
    s32 w94;
    s32 w98;
    u8 pad9C[0xD4 - 0x9C];
    s32 (*fD4)();
} RenewMsgCmd;

extern u8 D_00323910[];
int TOGetMessageWindowMode(void);
void _TOScanSelecterWH(int a, u8 *s, int b, int c);
int TOGetChangeMacroWidth(int a, u8 *s, int b);
u8 *TOGetChangeMacroAddress(int a, u8 *s);

int TOSwapRenewMessage(MenuCmd *mc)
{
    RenewMsgCmd *m = (RenewMsgCmd *)mc; /* DEBT(CAST): MenuCmd lacks layout fields */
    s16 w = 0;
    s16 h = 0;
    u8 *p;

    m->fD4(m);
    p = m->p84;
    if (m->w08 == 0) {
        int cnt;
        s16 gx, gy;

        m->h02 = 0;
        cnt = TOGetWordCount(m->h04, p);
        m->w98 = cnt;
        m->w90 = cnt;
        m->w94 = cnt;
        _TOGetMessageWH(m->h04, p, &m->h3C, &m->h3E, m->h1A, 1);
        if (TOGetMessageWindowMode() == 1) {
            gx = m->h30 + (m->h38 - m->h3C) / 2;
            gy = 1;
        } else {
            gx = m->h30 + (m->h38 - m->h3C) / 2;
            gy = m->h32 + (m->h3A - m->h3E) / 2;
        }
        graphicFontGetScreenWH(m->x40, gx, gy, m->h3C, m->h3E);
        if (m->h1E == 1) {
            _TOScanSelecterWH(m->h04, m->p84, m->h1A, 1);
        }
    } else {
        m->h24 = TOGetWordCountLimit(m->h04, p, 3);
        m->h28 = m->h24;
        if (m->h24 > 0) {
            m->h28 += TOGetWordCountLimit(m->h04, D_00323910, 0);
        }
        if (m->h22 == 1) {
            p = (u8 *)_TOGetMessageWH(m->h04, p, &w, &h, m->h1A, m->h10 | 3);
            if (w > 0) {
                w += TOGetChangeMacroWidth(m->h04, D_00323910, m->h1A);
            }
            m->h2A = w;
            _TOGetMessageWH(m->h04, p, &m->h3C, &m->h3E, m->h1A, m->h10 | 1);
            m->h3C += w;
            m->w90 = m->h28;
        } else {
            p = (u8 *)_TOGetMessageWH(m->h04, p, &w, &h, m->h1A, m->h10 | 3);
            _TOGetMessageWH(m->h04, p, &m->h3C, &m->h3E, m->h1A, m->h10 | 1);
        }
        graphicFontGetScreenWH(m->x40, (s16)(m->h30 + (m->h38 - m->h3C) / 2), (s16)(m->h32 + (m->h3A - m->h3E) / 2), m->h3C, m->h3E);
        m->w98 = TOGetWordCount(m->h04, m->p84);
        if (m->h22 == 1 && m->h24 > 0) {
            m->w98 += TOGetWordCount(0, TOGetChangeMacroAddress(0, D_00323910));
        }
        if (m->h24 > 0) {
            if (m->h22 == 1) {
                if (m->w98 == m->h28) {
                    m->h02 = 1;
                }
            } else {
                if (m->w98 == m->h24) {
                    m->h02 = 1;
                }
            }
        }
        m->w90 = m->w98;
        m->w94 = m->w98;
        if (m->h1E == 1) {
            _TOScanSelecterWH(m->h04, m->p84, m->h1A, 1);
        }
    }
    return 0;
}

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

void TOGetPadStatus(void)
{
    int i;
    u16 mask;
    u16 *p_cur;
    u16 *p_trg;
    u16 *p_rep;
    u16 old12 = D_003238D0.h12;
    u16 old22 = D_003238D0.h22;

    D_003238D0.h12 = 0;
    D_003238D0.h14 = 0;
    D_003238D0.h16 = 0;
    D_003238D0.h22 = 0;
    D_003238D0.h24 = 0;
    D_003238D0.h26 = 0;
    if (D_003238D0.b0 == 0 && D_003238D0.b1 == 0) {
        return;
    }
    D_003238D0.h12 = TkGetControlerHist(0, 0, 0);
    D_003238D0.h14 = D_003238D0.h12 & (old12 ^ D_003238D0.h12);
    D_003238D0.b1E = TkGetControlerAnalogHist(0, 0, 2, 0);
    D_003238D0.b1F = TkGetControlerAnalogHist(0, 0, 3, 0);
    D_003238D0.h22 = D_003238D0.h12 & 0xFFF;
    if (D_003238D0.b1F < 0x18) {
        D_003238D0.h22 |= 0x1000;
    }
    if (D_003238D0.b1F > 0xE8) {
        D_003238D0.h22 |= 0x4000;
    }
    if (D_003238D0.b1E < 0x18) {
        D_003238D0.h22 |= 0x8000;
    }
    if (D_003238D0.b1E > 0xE8) {
        D_003238D0.h22 |= 0x2000;
    }
    D_003238D0.h24 = D_003238D0.h22 & (old22 ^ D_003238D0.h22);
    if ((D_003238D0.h12 & 0xF000) == 0) {
        p_cur = &D_003238D0.h22;
        p_trg = &D_003238D0.h24;
        p_rep = &D_003238D0.h26;
    } else {
        p_cur = &D_003238D0.h12;
        p_trg = &D_003238D0.h14;
        p_rep = &D_003238D0.h16;
    }
    for (i = 0; i < 16; i++) {
        mask = 1 << i;
        if (mask == 0x800 || mask == 0x100) {
            continue;
        }
        if ((*p_trg & mask) && D_003238D0.timer[i] == 0) {
            *p_rep |= mask;
        }
        if (!(*p_trg & mask)) {
            D_003238D0.timer[i]++;
        }
        if (!(*p_cur & mask)) {
            D_003238D0.timer[i] = 0;
        }
        if (D_003238D0.timer[i] == 7) {
            *p_rep |= mask;
            D_003238D0.timer[i] = 4;
        }
    }
    if ((D_003238D0.h12 & 0xF000) == 0) {
        D_003238D0.h12 = D_003238D0.h22;
        D_003238D0.h14 = D_003238D0.h24;
        D_003238D0.h16 = D_003238D0.h26;
    } else {
        D_003238D0.h22 = D_003238D0.h12;
        D_003238D0.h24 = D_003238D0.h14;
        D_003238D0.h26 = D_003238D0.h16;
    }
    D_003238D0.b0 = 0;
}

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

void func_002021F8(u8 *s, u8 *buf);
void func_00207988(int a, int b, int c, int d, int e);
s32 _TOIntToMes(int a, u8 *b, int c, int d) __asm__("TOIntToMes");

typedef struct {
    s16 flag;
    s16 w;
    s16 x;
    s16 y;
} SelEnt;

typedef struct {
    u8 pad00[4];
    s8 b4;
    s8 b5;
    u8 pad06[2];
    s16 h08;
    u8 pad0A[2];
    s32 w0C;
    u8 pad10[0x28];
    SelEnt ent[16];
} SlotZSel;

int _TOGetMessageWH(int id, u8 *s, s16 *outW, s16 *outH, int a4, int a5)
{
    u8 buf[0x10];
    u8 numBuf[0x20];
    s16 subW;
    s16 subH;
    int charW;
    int maxW = 0;
    int maxH = 0;
    int curW = 0;
    int lineSp;
    int flagHi = a5 & 0xFF00;
    int running = 1;
    int curH;
    int padFlag;

    a5 &= 0xF;
    if (a4 == 1 || a4 == 3) {
        lineSp = 4;
    } else {
        lineSp = 2;
    }
    curH = lineSp + 18;
    padFlag = (a4 == 3);
    do {
        switch (TOGetGroup(*s)) {
        case 4:
            if (id >= 0 && ((RenewMsgCmd *)D_00668740[id])->h10 == 0x4000) {
                func_002021F8(s, buf);
                func_00205228(buf, a4, &charW);
            } else {
                func_00205228(s, a4, &charW);
            }
            curW += charW;
            break;
        case 1:
            if (padFlag == 1 && curW > 0) {
                curW += 5;
            }
            if (curW > maxW) {
                maxW = curW;
            }
            curW = 0;
            switch (*s) {
            case 0:
                if (curH > maxH) {
                    maxH = curH;
                }
                running = 0;
                break;
            case 1:
            case 2:
                if (curH > maxH) {
                    maxH = curH;
                }
                curH = lineSp + 18;
                if (a5 != 0) {
                    running = 0;
                }
                break;
            case 3:
                curH += 18 + lineSp;
                if (a5 == 3) {
                    if (curH > maxH) {
                        maxH = curH;
                        running = 0;
                    }
                }
                break;
            }
            break;
        case 2:
            if (*s == 7) {
                if (id >= 0 && s[1] == 0x38 && ((RenewMsgCmd *)D_00668740[id])->h24 == 0) {
                    ((s16 *)D_00668740[id])[7] = 1;
                }
                if ((s8)(s[1] - 0x40) >= 0) {
                    curW = (s[1] - 0x40) * 4;
                }
                if ((u8)(s[1] + 0x1F) < 0xF) {
                    curW += s[1] - 0xE0;
                }
            } else {
                if (*s == 0xE) {
                    if (s[1] == 0x40 && padFlag == 0) {
                        padFlag = 1;
                    }
                    if (s[1] == 0x41 && padFlag == 1 && curW > 0) {
                        curW += 5;
                        padFlag = 0;
                    }
                }
                if (*s == 0xB) {
                    curW += func_002083E8(s[1]);
                }
                if (*s == 0x10 && id >= 0) {
                    if (s[1] >= 0x50 && s[1] < 0x60) {
                        _TOIntToMes(((s32 *)D_00669AE0[id])[3], numBuf, s[1] - 0x4F, 1);
                        _TOGetMessageWH(id, numBuf, &subW, &subH, a4, 0);
                        D_00668740[id]->w1E = 1;
                        curW += subW;
                    }
                    if (!(flagHi & 0x100) && s[1] != 0xFF) {
                        D_00668740[id]->w1E = 1;
                    }
                }
            }
            break;
        case 3:
            curW += TOGetChangeMacroWidth(id, s, a4);
            break;
        }
        s = TOSkipCode(s);
    } while (running != 0);
    *outW = maxW;
    *outH = maxH - lineSp;
    return (int)s;
}

void _TOScanSelecterWH(int id, u8 *s, int a2, int a3)
{
    u8 numBuf[0x20];
    u8 buf[0x10];
    s16 subW;
    s16 subH;
    int charW;
    int mode = a3 & 0xF;
    int maxH = 0;
    int lineSp;
    SelEnt *curEnt = 0;
    int curW = 0;
    int running = 1;
    int curH;
    int i;

    if (a2 == 1 || a2 == 3) {
        lineSp = 4;
    } else {
        lineSp = 2;
    }
    ((SlotZSel *)D_00669AE0[id])->b4 = 0;
    ((SlotZSel *)D_00669AE0[id])->b5 = 0;
    curH = lineSp + 18;
    do {
        switch (TOGetGroup(*s)) {
        case 4:
            if (((RenewMsgCmd *)D_00668740[id])->h10 == 0x4000) {
                func_002021F8(s, buf);
                func_00205228(buf, a2, &charW);
            } else {
                func_00205228(s, a2, &charW);
            }
            curW += charW;
            break;
        case 1:
            if (curEnt != 0) {
                curEnt->w = curW - (u16)curEnt->x;
                curEnt = 0;
            }
            curW = 0;
            if (((s16 *)D_00668740[id])[7] == 1) {
                _TOGetMessageWH(id, s + 1, &subW, &subH, a2, 3);
                curW = (((s16 *)D_00668740[id])[0x22] - ((s16 *)D_00668740[id])[0x20] - subW) / 2;
            }
            switch (*s) {
            case 0:
                running = 0;
                break;
            case 1:
            case 2:
                curH = lineSp + 18;
                if (mode != 0) {
                    running = 0;
                }
                break;
            case 3:
                curH += 18 + lineSp;
                if (mode == 3) {
                    if (curH > maxH) {
                        maxH = curH;
                        running = 0;
                    }
                }
                break;
            }
            break;
        case 2:
            if (*s == 7) {
                _TOGetMessageWH(id, s + 2, &subW, &subH, a2, 3);
                if (s[1] == 0x38) {
                    curW = (((s16 *)D_00668740[id])[0x22] - ((s16 *)D_00668740[id])[0x20] - subW) / 2;
                } else {
                    if (s[1] == 0x31) {
                        curW = (((s16 *)D_00668740[id])[0x22] - ((s16 *)D_00668740[id])[0x20] - subW) / 2;
                    }
                    if ((s8)(s[1] - 0x40) >= 0) {
                        curW = (s[1] - 0x40) * 4;
                    }
                    if ((u8)(s[1] + 0x1F) < 0xF) {
                        curW += s[1] - 0xE0;
                    }
                }
            } else {
                if (*s == 0xB) {
                    curW += func_002083E8(s[1]);
                }
                if (*s == 0x10) {
                    if (s[1] >= 0x50 && s[1] < 0x60) {
                        _TOIntToMes(((SlotZSel *)D_00669AE0[id])->w0C, numBuf, s[1] - 0x4F, 1);
                        _TOGetMessageWH(id, numBuf, &subW, &subH, a2, 0);
                        func_00207988(id, s[1] - 0x4F, curW, curH, subW);
                        curW += subW;
                    } else {
                        if (curEnt != 0) {
                            curEnt->w = curW - (u16)curEnt->x;
                            curEnt = 0;
                        }
                        if (s[1] != 0xFF) {
                            ((SlotZSel *)D_00669AE0[id])->b5++;
                            curEnt = &((SlotZSel *)D_00669AE0[id])->ent[s[1] - 0x30];
                            curEnt->flag = 1;
                            curEnt->w = 0;
                            curEnt->x = curW;
                            curEnt->y = curH;
                        }
                    }
                }
            }
            break;
        case 3:
            curW += TOGetChangeMacroWidth(id, s, a2);
            break;
        }
        s = TOSkipCode(s);
    } while (running != 0);
    ((SlotZSel *)D_00669AE0[id])->h08 = 0;
    for (i = 0; i < ((SlotZSel *)D_00669AE0[id])->b5; i++) {
        if (((SlotZSel *)D_00669AE0[id])->ent[i].w > ((SlotZSel *)D_00669AE0[id])->h08) {
            ((SlotZSel *)D_00669AE0[id])->h08 = ((SlotZSel *)D_00669AE0[id])->ent[i].w;
        }
    }
}

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

extern void *D_0066AF40;

void func_00206980(void)
{
    int i;

    D_0066AF40 = (void *)TODVDFileReadAuto(0x12, 4);
    D_0066AF00[0] = D_0066AF40;
    for (i = 0; i < 16; i++) {
        if (((s32 *)D_0066AF40)[i] > 0) {
            D_0066AF00[0]->w[i] = (s32)D_0066AF40 + ((s32 *)D_0066AF40)[i];
        } else {
            D_0066AF00[0]->w[i] = 0;
        }
    }
    if (TOGetFFXLangSwapFlag() == 1) {
        s32 *p = (s32 *)TODVDFileReadAuto(4, 4);
        D_0066AF40 = p;
        D_0066AF00[1] = (void *)p;
        for (i = 0; i < 16; i++) {
            if (((s32 *)D_0066AF40)[i] > 0) {
                ((s32 *)D_0066AF00[1])[i] = (s32)D_0066AF40 + ((s32 *)D_0066AF40)[i];
            } else {
                ((s32 *)D_0066AF00[1])[i] = 0;
            }
        }
    }
}

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

extern u8 D_00323930[];
void func_00204CA8(u8 *s, void *out);
void TOMakePktFont1612(TextItem *item, void *info);

int func_002070A8(int id, u8 *s, TextItem *item, int count, int limit)
{
    func_002EF0D0(D_00323930, 0, 0x20);
    s = TOGetChangeMacroAddress(id, s);
    if (s == 0) {
        return 0;
    }
    while (*s != 0 && count < limit) {
        if (*s == 7) {
            if (s[1] >= 0xE0 && s[1] < 0xF0) {
                item->x += s[1] - 0xE0;
            }
            s = TOSkipCode(s);
        } else if (TOGetGroup(*s) == 3) {
            count = func_002070A8(id, s, item, count, limit);
            s = TOSkipCode(s);
        } else {
            func_00204CA8(s, D_00323930);
            count++;
            TOMakePktFont1612(item, D_00323930);
            s = TOSkipCode(s);
        }
    }
    return count;
}

void TOMakePktMovieFont1612(TextItem *item, void *info);

void TODrawChangeMacro2(MenuCmd *m, u8 *s, TextItem *item)
{
    func_002EF0D0(D_00323930, 0, 0x20);
    s = TOGetChangeMacroAddress(m->id, s);
    if (s == 0) {
        return;
    }
    while (*s != 0 && m->x8C < m->x90) {
        if (*s == 7) {
            if (s[1] >= 0xE0 && s[1] < 0xF0) {
                item->x += s[1] - 0xE0;
            }
            s = TOSkipCode(s);
        } else if (TOGetGroup(*s) == 3) {
            TODrawChangeMacro2(m, s, item);
            s = TOSkipCode(s);
        } else {
            func_00204CA8(s, D_00323930);
            TOMakePktFont1612(item, D_00323930);
            s = TOSkipCode(s);
            m->x8C++;
            if (m->xA4 == 0 && m->x9C == 0 && m->x90 < m->x98) {
                m->x90++;
            }
        }
    }
}

void TODrawMovieChangeMacro2(MenuCmd *m, u8 *s, TextItem *item)
{
    func_002EF0D0(D_00323930, 0, 0x20);
    s = TOGetChangeMacroAddress(m->id, s);
    if (s == 0) {
        return;
    }
    while (*s != 0 && m->x8C < m->x90) {
        if (*s == 7) {
            if (s[1] >= 0xE0 && s[1] < 0xF0) {
                item->x += s[1] - 0xE0;
            }
            s = TOSkipCode(s);
        } else if (TOGetGroup(*s) == 3) {
            TODrawChangeMacro2(m, s, item);
            s = TOSkipCode(s);
        } else {
            func_00204CA8(s, D_00323930);
            TOMakePktMovieFont1612(item, D_00323930);
            s = TOSkipCode(s);
            m->x8C++;
            if (m->xA4 == 0 && m->x9C == 0 && m->x90 < m->x98) {
                m->x90++;
            }
        }
    }
}

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
