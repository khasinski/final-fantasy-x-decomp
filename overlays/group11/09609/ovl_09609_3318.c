#include "common.h"

typedef unsigned long u64;

typedef union {
    u_long128 q;
    u64 d[2];
    u32 w[4];
} Qword;

typedef struct {
    s32 count;
    u8 *data;
} ReelTbl3318;

typedef struct {
    ReelTbl3318 *tbl;
    s32 pos;
    s32 speed;
    s32 timer;
    s32 target;
    s32 unk14;
    s32 state;
} Reel3318;

extern u64 D_006F2CE0[];

extern void func_002DA610(s32, s32);
extern void *func_002DB6D8(s32);
extern void func_002DBA28(void *, void *);
extern void func_01B02B30(s32, s32, s32, s32, s32, s32, s32);
extern void func_01B03068(s32, s32);

void func_01B03318(Reel3318 *r, s32 x, s32 y) {
    void *ch;
    Qword *p;
    s32 x0, x1, y0, y1;
    s32 idx, draw_y, i;
    ReelTbl3318 *tbl;
    u8 *data;

    func_002DA610(0, 0);
    ch = func_002DB6D8(2);

    p = (Qword *)0x70000000;
    x0 = x;
    x1 = x + 0x37;
    y0 = y;
    y1 = y + 0x69;
    if (x0 > 0x200) {
        x0 = 0;
        x1 = 0x200;
    } else {
        if (x0 < 0) x0 = 0;
        if (x1 > 0x200) x1 = 0x200;
    }

    if (y0 > 0x1A0) {
        y0 = 0;
        y1 = 0x1A0;
    } else {
        if (y0 < 0) y0 = 0;
        if (y1 > 0x1A0) y1 = 0x1A0;
    }

    p->q = 0;
    p->w[0] = 0x70000002;
    p++;

    p->q = 0;
    p->d[0] = 0x1000000000008001ULL;
    p->d[1] = 0xEULL;
    p++;

    p->d[0] = (u64)x0 | ((u64)x1 << 16) | ((u64)y0 << 32) | ((u64)y1 << 48);
    p->d[1] = 0x40ULL;

    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);

    idx = r->pos >> 16;
    draw_y = (y << 4) - (((r->pos & 0xFFFF) * 0x23) >> 12);
    tbl = r->tbl;
    data = tbl->data;

    r->unk14++;
    if (r->unk14 > 3) {
        r->unk14 = -3;
    }

    for (i = 0; i < 4; i++) {
        s32 sym = data[idx];
        s32 rgb;
        if (sym == 10) {
            s32 d = 3;
            rgb = r->unk14;
            if (rgb < 0) rgb = -rgb;
            rgb = (rgb * 0x80 + (d - rgb) * 0xF0) / d;
        } else {
            rgb = 0x80;
        }
        func_01B02B30(sym, x, draw_y, 0x37, 0x23, rgb, 0x80);
        idx++;
        if (idx >= tbl->count) {
            idx = 0;
        }
        draw_y += 0x230;
    }

    func_002DA610(0, 0);
    ch = func_002DB6D8(2);

    p = (Qword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x70000002;
    p++;

    p->q = 0;
    p->d[0] = 0x1000000000008001ULL;
    p->d[1] = 0xEULL;
    p++;

    p->d[0] = D_006F2CE0[10];
    p->d[1] = 0x40ULL;

    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);

    func_01B03068(x, y);
}
