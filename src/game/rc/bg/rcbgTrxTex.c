/* tu_159 0x19a1a0-0x19a708: medium; rcbgTrxTex (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/w3.h"
#include "ffx/s2.h"
#include "ffx/v2.h"

void func_0019A1A0(W3Img *img, int v)
{
    img->i3C = v;
}

int func_0019A1A8(W3Img *img)
{
    return img->i30;
}

void rcbgTrxDraw(W3Img *img)
{
    if (img->i3C != -1) {
        func_0019A2E0(img);
        img->i3C = -1;
    }
}

R2Qw *func_0019A1F8(W3Img *img, R2Qw *p)
{
    p->tag.qwc = 5;
    p->tag.id = 0x1000;
    p->tag.addr = 0;
    p->tag.pad = 0;
    p++;
    p->d.lo = 0x1000000000008004;
    p->d.hi = 0xE;
    p++;
    p->d.lo = img->reg18;
    p->d.hi = 0x50;
    p++;
    p->d.lo = img->reg20;
    p->d.hi = 0x51;
    p++;
    p->d.lo = img->reg28;
    p->d.hi = 0x52;
    p++;
    p->d.lo = 0;
    p->d.hi = 0x53;
    p++;
    p->tag.qwc = img->stride / 16;
    p->tag.id = 0x3000;
    p->tag.addr = (u32)func_0019A3F0(img, img->i3C);
    p->tag.pad = 0;
    return p + 1;
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgTrxTex", func_0019A2E0);

u8 *func_0019A3F0(W3Img *img, int n)
{
    return img->buf + img->stride * n;
}

int func_0019A408(W3Img *o, int n) {
    return (int)(o->buf + o->stride * n + 0x10); /* DEBT(CAST): K&R prototype returns int */
}

void func_0019A420(W3Img *o) {
    int i;
    R2Qw *q;
    u32 w;
    for (i = 0; i < o->i30; i++) {
        q = (R2Qw *)func_0019A3F0(o, i); /* DEBT(CAST) */
        w = ((u32)(o->stride - 0x10) >> 4) | 0x8000;
        q->d.hi = 0;
        q->d.lo = w | ((u64)0x8000 << 44);
    }
}

void *func_0019A4A8(void) {
    void *p = _rcAlloc(0xA0, D_0056DB70, 0x18);

    func_0019A510(p);
    return p;
}

void func_0019A4E8(void *p) {
    func_0019A578(p);
    func_0018FC10(p);
}

void func_0019A510(void *p) {
    S2Obj9A *o = p;

    o->w0 = 0x20003;
    o->p4 = func_0019A4E8;
    o->w8 = 0;
    o->pC = func_0019A6A8;
    o->h12 = 0;
    o->h10 = 0;
    o->w14 = -1;
    o->f18 = 0;
    func_00199F40(o->sub20);
    func_00199F40(o->sub60);
}

void func_0019A578(void *p) {
    S2Obj9A *o = p;

    func_00199F90(o->sub20);
    func_00199F90(o->sub60);
}

void func_0019A5A8(void) {
}

void func_0019A5B0(void *p, int v) {
    S2Obj9A *o = p;

    func_0019A1A0(o->sub20, v);
    func_0019A1A0(o->sub60, v);
}

int func_0019A5F0(void *p)
{
    S2Obj9A *o = p;

    return func_0019A1A8((W3Img *)o->sub20);
}

void func_0019A610(void *p, V2Tex0 tex)
{
    S2Obj9A *o = p;
    int tbp = tex.tbp0;
    int tbw = tex.tbw;
    int cbp = tex.cbp;

    *(V2Tex0 *)&o->f18 = tex; /* DEBT(CAST): S2Obj9A.f18 holds the TEX0 value */
    func_0019A078(o->sub20, tbp, tbw, 0x13, 0, 0, o->h10, o->h12);
    func_0019A078(o->sub60, cbp, 1, 0, 0, 0, 0x10, 0x10);
}

void func_0019A6A8(void *p)
{
    S2Obj9A *o = p;

    rcbgTrxDraw((W3Img *)o->sub60);
    rcbgTrxDraw((W3Img *)o->sub20);
}

void *func_0019A6D8(void) {
    S2Obj9A *o = func_0019A4A8();

    o->w0 = 0x20006;
    return o;
}
