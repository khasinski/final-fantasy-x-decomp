/* tu_158 0x199e00-0x19a1a0: medium; rcbgTrx (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/w3.h"
#include "ffx/s2.h"
#include "ffx/v2.h"

u8 *func_00199E00(W3Pool *p, int idx, int *w, int *h)
{
    return 0;
}

int func_00199E08(W3Pool *p, int idx, int x, int y)
{
    W3Voice *v = &p->voices[idx];
    int dx;
    int dy;
    int size[2];
    int w;
    int h;
    u8 *pix;
    u8 *pal;

    dx = x - v->i0C;
    dy = y - v->i10;
    w = v->i04;
    h = v->i08;
    size[0] = w;
    size[1] = h;
    if (dx < 0 || dy < 0 || dx >= w || dy >= h) {
        return 0;
    }
    pix = func_00199E00(p, idx, &size[0], &size[1]);
    pal = (u8 *)func_00193C80(v); /* DEBT(TYPE): returns the palette address as int */
    return pal[pix[dx + v->i24 + (dy + v->i28) * size[0]] * 4 + 3];
}

void *func_00199ED8(void) {
    void *p = _rcAlloc(0x40, D_0056DB60, 0x1C);

    func_00199F40(p);
    return p;
}

void func_00199F18(W3Img *img)
{
    func_00199F90(img);
    func_0018FC10(img);
}

void func_00199F40(W3Img *o) {
    o->id = 0x20002;
    o->dtor = func_00199F18;
    o->i08 = 0;
    o->fn0C = rcbgTrxDraw;
    o->flags = 0;
    o->reg28 = 0;
    o->reg20 = 0;
    o->reg18 = 0;
    o->i30 = 0;
    o->stride = 0;
    o->buf = 0;
    o->i3C = -1;
}

void func_00199F90(W3Img *img)
{
    if (img->flags & 1) {
        if (img->buf != 0) {
            func_0018FC10(img->buf);
            img->buf = 0;
        }
    }
}

void func_00199FD8(void *o, short a, short b, short c, short d, short e, short f, short g, int x) {
    func_0019A078(o, a, b, c, d, e, f, g);
    func_0019A100(o, c, f, g, x);
}

/* old-style definition: the shorts arrive promoted to int (callers use the int prototype) */
void func_0019A078(p, a, b, c, d, e, f, g)
    void *p;
    short a, b, c, d, e, f, g;
{
    W3Img *img = p;

    img->reg18 = (s64)a << 32 | (s64)b << 48 | (s64)c << 56;
    img->reg20 = (s64)d << 32 | (s64)e << 48;
    img->reg28 = (s64)f | (s64)g << 32;
}

void func_0019A100(void *p, short kind, short w, short h, int n)
{
    W3Img *img = p;

    img->i30 = n;
    switch (kind) {
    case 0x13:
        img->stride = w * h + 0x10;
        break;
    case 0:
        img->stride = w * h * 4 + 0x10;
        break;
    }
    img->buf = _rcAlloc(img->stride * img->i30, D_0056DB60, 0x6B);
    img->flags |= 1;
    func_0019A420(img);
}
