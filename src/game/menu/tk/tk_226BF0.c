/* tu_251 0x226bf0-0x227c88: low; ~Tk (config/tu_map.tsv) */
#define func_00226890 _hdr_func_00226890
#include "common.h"
#include "ffx/r5.h"
#include "ffx/w7.h"
#include "ffx/u3.h"
#include "ffx/v5.h"
#include "ffx/q5.h"
#include "ffx/s5.h"
#undef func_00226890
extern void func_00226890(int, int, int, int);

void func_00226BF0(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F3C58(p + 1, c, a, b, d);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226C78(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F5F50(p + 1, c, a, b, d);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226D00(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F6400(p + 1, c, a, b, d);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226D88(int a, int b, int c)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F4C58(p + 1, a, b, c);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226E10(int a, int b, int c)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001FE170(p + 1, c, a, b);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226E90(DrawArgs *a)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001FF020(p + 1, a->p10, a->p14, a->x, a->y, a->w, a->p8, a->pC);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226F28(DrawArgs *a)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001FF0F8(p + 1, a->p10, a->p14, a->x, a->y, a->w, a->p8, a->pC);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226FC0(DrawArgs *r) { func_00225718(r->x, r->y, r->w, r->h, r->p8, r->pC); }

void func_00226FE0(DrawArgs *a)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001FA320(p + 1, a->x, a->y, a->w, a->h, a->p8, a->pC);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00227070(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F5290(p + 1, c, a, b, d);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_002270F8(int a, int b, int c)
{
    CmdRec *p;
    u32 n;

    if (!(func_00242040() & 2) || c == 0) {
        p = D_0069384C;
        D_0069384C = p + 1;
        D_0069384C = func_001FE578(p + 1, 0, a, b);
        n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
        p->b3 = 0x10;
        p->b2 = 0;
        p->w0 = n - 1;
        p->w4 = 0;
        p->w8 = 0;
        p->wC = 0x50000000 | (n - 1);
    }
}

void func_002271B0(int x, int y, int w, int h, int id, int e, int k)
{
    u8 *s = (u8 *)MsGetSavePlayerPtr(id); /* DEBT(CAST): byte table view of the party slot */

    func_00226D88(x, y, 0x10);
    func_00226E10(x + w + 0x58, y + h, 0x10A);
    func_00226350(x + 0x1D, y + 1, func_00220A78(e), 0);
    func_00226C78(x + 0xD3, y + 6, s[k], 0);
}

void TkMn2GetCommonPlate(void *o_, const void *a1, const void *a2, const void *a3, int t0, int t1) {
    FlagRec *o = o_;

    func_002273A0(a1, o->rect);
    o->x08 = TkMn2SeqGetColor(a2);
    o->x0C = TkMn2SeqGetColor(a3);
    o->x10 = t0;
    o->x14 = t1;
}

void func_00227310(int a0, FlagRec *o, const void *a2, const void *a3, const void *t0, int t1, int t2) {
    func_002273C0(a0, a2, o->rect);
    o->x08 = func_002273F8(a0, a3);
    o->x0C = func_002273F8(a0, t0);
    o->x10 = t1;
    o->x14 = t2;
}

void func_002273A0(const void *name, void *rect_) {
    s16 *rect = rect_;

    TOSeqGetRect(1, name, rect, rect + 1, rect + 2, rect + 3);
}

void func_002273C0(int a0, const void *a1, s16 *rect) { TOSeqGetRect(a0, a1, rect, rect + 1, rect + 2, rect + 3); }

int TkMn2SeqGetColor(const void *id) {
    int v;

    TOSeqGetColor(1, id, &v);
    return v;
}

int func_002273F8(int a0, const void *a1) {
    int v;

    TOSeqGetColor(a0, a1, &v);
    return v;
}

s16 TkMn2SeqGetNum(const void *id) {
    s16 v;

    TOSeqGetNum(1, id, &v);
    return v;
}

s16 TkMn2SeqGetNumCustom(int a0, const void *a1) {
    s16 v;

    TOSeqGetNum(a0, a1, &v);
    return v;
}

void func_00227460(const void *name, void *out_) {
    s16 *out = out_;

    TOSeqGetPoint(1, name, out, out + 1);
}

void func_00227478(int a0, const void *a1, s16 *out) { TOSeqGetPoint(a0, a1, out, out + 1); }

void func_00227480(const void *name) { TOSeqStartScene(1, name); }

void func_00227490(const void *name) { TOSeqStopScene(1, name); }

void func_002274A0(int y, int h, int mode, int ratio)
{
    int y1;
    int h1;
    int dy;

    switch (mode) {
    case 1:
        dy = (h * (ratio < 0 ? -ratio : ratio)) / 4096;
        if (ratio >= 0) {
            y1 = y + (h - dy);
        } else {
            y1 = y;
        }
        h1 = dy - 2;
        if (h1 < 0) {
            h1 = 0;
        }
        break;
    case 2:
        dy = (h * (ratio < 0 ? -ratio : ratio)) / 4096;
        if (ratio >= 0) {
            y1 = y;
        } else {
            y1 = y + dy + 2;
        }
        h1 = h - dy;
        if (h1 < 0) {
            h1 = 0;
        }
        break;
    case 0:
    default:
        y1 = y;
        h1 = h;
        break;
    }
    func_00225800(0, y1, 0x200, h1 - 1);
}

void TkMn2DumpPlate(DrawArgs *a)
{
    func_002EF240(D_00571390, a->x);
    func_002EF240(D_00571398, a->y);
    func_002EF240(D_005713A0, a->w);
    func_002EF240(D_005713A8, a->h);
    func_002EF240(D_005713B0, a->p8);
    func_002EF240(D_005713C0, a->pC);
}

int TkMn2GetCommandName(int id) {
    s32 pos;
    int sel = func_0013A398(id) != 0;
    OfsTbl *t = MsGetRomPlyCommand(id, &pos);

    pos += t->a[sel].x;
    return pos;
}

int TkMn2GetCommandHelp(int id) {
    s32 pos;
    int sel = func_0013A398(id) != 0;
    OfsTbl *t = MsGetRomPlyCommand(id, &pos);

    pos += t->b[sel].x;
    return pos;
}

int TkMn2GetItemHelp(int id) {
    s32 pos;
    int sel = func_0013A398(id);
    OfsTbl *t = MsGetRomItem(id, &pos);

    if (sel != 0) {
        sel = 1;
    }
    pos += t->b[sel].x;
    return pos;
}

int TkMn2GetAbilityHelp(int id) {
    s32 pos;
    int sel = func_0013A398(id) != 0;
    OfsTbl *t = MsGetRomAbility(id, &pos);

    pos += t->b[sel].x;
    return pos;
}

int func_00227768(int id) {
    s32 pos;
    int sel = func_0013A398(id) != 0;
    OfsTbl *t = MsGetRomAbility(id, &pos);

    pos += t->a[sel].x;
    return pos;
}

int func_002277C0(int a0) { return MsMenuGetText(5, a0, MsGetSaveConfigHiragana()); }

extern s16 D_00325878[2];

void func_002277F8(int x, int y, int id, int cost)
{
    FlagRec plate = D_00325A40;
    int px;
    int py;

    plate.rect[0] = x;
    plate.rect[1] = y;
    func_00226FE0((DrawArgs *)&plate);
    px = x + D_00325A58[0];
    py = y + D_00325A58[1];
    func_00226D88(px, py, 8);
    func_00226E10(px + D_00325878[0] + 0x58, py + D_00325878[1], 0xD7);
    func_00226E10(x + D_00325A60[0] + 0x10, y + D_00325A60[1], 0xFF);
    px = x + D_00325A58[0];
    py = y + D_00325A58[1];
    if (id >= 0) {
        int val = func_001BFE30(id);
        register int one __asm__("$16") = 1;
        int lack = val < cost;
        int x2;
        int x3;
        int y3;

        func_00226890(id, px, py, lack);
        x2 = x + D_00325A60[0];
        py = y + D_00325A60[1];
        px = x2 + 0x10;
        func_00226C78(x2 + D_00325A68[0], py + D_00325A68[1], val, lack);
        val -= cost;
        x3 = px + D_00325A70[0] - 0x10;
        y3 = py + D_00325A70[1];
        if (lack == one) {
            func_002265A8(x3, y3, TkMenuMainMes(0x15), 1);
        } else {
            func_00226C78(x3, y3, val, lack);
        }
    }
}

void func_00227A08(int x, int y, int id, int cost)
{
    FlagRec plate = D_00325AD0;
    int px;
    int py;

    plate.rect[0] = x;
    plate.rect[1] = y;
    func_00226FE0((DrawArgs *)&plate);
    func_00226210(plate.rect[0] - D_00325AC8[0], plate.rect[1] - D_00325AC8[1], 8);
    func_00226210(plate.rect[0] + D_00325AF0[0] - D_00325AD0.rect[0],
                  plate.rect[1] + D_00325AF0[1] - D_00325AD0.rect[1], 9);
    px = x + D_00325AE8[0];
    py = y + D_00325AE8[1];
    func_00226E10(px + D_00325878[0] + 0x58, py + D_00325878[1], 0x10B);
    {
        register int ox __asm__("$5") = D_00325AD0.rect[0] - 0x10;
        px = (x + D_00325AF8[0]) - ox;
        py = (y + D_00325AF8[1]) - D_00325AD0.rect[1];
    }
    func_00226E10(px, py, 0xFF);
    if (id >= 0) {
        int val = func_001BFE30(id);
        register int one __asm__("$17") = 1;
        int lack;

        x += D_00325AE8[0];
        y += D_00325AE8[1];
        func_00226C78(x + 0xD3, y + 6, cost, 0);
        lack = val < cost;
        func_00226890(id, x, y, 0);
        func_00226C78(px + D_00325B08[0] - 0x10, py + D_00325B08[1], val, 0);
        val -= cost;
        x = px + D_00325B10[0] - 0x10;
        y = py + D_00325B10[1];
        if (lack == one) {
            func_002265A8(x, y, TkMenuMainMes(0x15), 0);
        } else {
            func_00226C78(x, y, val, 0);
        }
    }
}
