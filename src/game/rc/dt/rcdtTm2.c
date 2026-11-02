/* tu_168 0x19f190-0x19fc00: medium; rcdtTm2 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/v2.h"

W3Obj50 *func_0019F190(void) {
    W3Obj50 *p = _rcAlloc(0x50, D_0056DDB8, 27);

    rcdtTm2Init(p);
    return p;
}

void func_0019F1D0(W3Obj50 *p) {
    rcdtTm2Fini(p);
    func_0018FC10(p);
}

void rcdtTm2Init(W3Obj50 *p) {
    func_002EF0D0(p, 0, 0x50);
}

void rcdtTm2Fini(W3Obj50 *o) {
    if (o->p40 != 0) {
        func_0018FC10(o->p40);
        o->p40 = 0;
    }
    if (o->p44 != 0) {
        func_0018FC10(o->p44);
        o->p44 = 0;
    }
}

int func_0019F258(W3Obj50 *o, char *file, int swizzle) {
    W3Pair *blk;
    W3Reader *rd;
    Tim2Img *t = (Tim2Img *)o; /* DEBT(CAST): W3Obj50 is the opaque view of the image */
    Tim2Pic *pic = &t->pic;
    int size;
    int ofs;
    int w;
    int h;

    blk = rcdtChunkNew();
    if (rcdtChunkLoadFromFile(blk, file) == 0) {
        if (blk != 0) {
            rcdtChunkDelete(blk);
        }
        func_0018F5E8(D_0056DDC8, D_0056DDB8, 63);
        func_0018F5E8(D_0056DDE0);
        return 0;
    }
    rcdtTm2Fini(o);
    rd = func_0019D648();
    rcdtParseSet(rd, blk);
    func_0019DE78(rd, t->fileHdr, 0x10);
    func_0019DE78(rd, pic, 0x30);
    t->texType = func_0019FB60((Obj19FB60 *)pic);
    w = pic->width;
    h = pic->height;
    switch (pic->imageType) {
    case 4:
        size = w * h / 2;
        break;
    case 5:
        size = w * h;
        break;
    default:
        func_0018F5E8(D_0056DDC8, D_0056DDB8, 88);
        func_0018F5E8(D_0056DDF0);
        return 0;
    }
    ofs = pic->headerSize + 0x10;
    func_0019D9F8(rd, ofs);
    t->image = _rcAlloc(size, D_0056DDB8, 94);
    func_0019DE78(rd, t->image, size);
    func_0019D9F8(rd, ofs + pic->imageSize);
    t->clut = _rcAlloc(pic->clutSize, D_0056DDB8, 99);
    func_0019DE78(rd, t->clut, pic->clutSize);
    if (swizzle != 0) {
        rcefMainInit(t->clut);
    }
    if (rd != 0) {
        func_0019D688((W3Pair *)rd); /* DEBT(CAST): declared with W3Pair, deletes the reader */
    }
    if (blk != 0) {
        rcdtChunkDelete(blk);
    }
    return 1;
}

int func_0019F460(W3Obj50 *o, char *file) {
    return func_0019F258(o, file, 1);
}

int func_0019F480(W3Obj50 *o, char *file) {
    return func_0019F258(o, file, 0);
}

/* sends the whole image to GS memory at bp */
void func_0019F4A0(Tim2Img *t, int bp, int bw) {
    Tim2Pic *pic = &t->pic;
    u8 li[0x60];

    /* DEBT(TYPE): s2.h declares the GS load-image setup with int parameters, the casts give its short ones */
    func_002DA928(li, bp, (short)bw, (short)t->texType, 0, 0, (short)pic->width, (short)pic->height);
    func_002F8660(0);
    func_002DAC50(li, (int)t->image); /* DEBT(TYPE): declared with an int source */
    func_002DA610(0, 0);
}

/* sends the w x h block at (x, y) of the image to GS memory at bp, position (dx, dy) */
void func_0019F510(Tim2Img *t, int bp, int bw, int x, int y, int w, int h, int dx, int dy) {
    u8 li[0x60];
    int bw8 = (w + 7) & ~7;
    int bh2 = (h + 1) & ~1;
    u8 *buf;

    buf = _rcCalloc(1, bw8 * bh2, D_0056DDB8, 162);
    func_0019F658(t, buf, x, y, w, h);
    /* DEBT(TYPE): s2.h declares the GS load-image setup with int parameters, the casts give its short ones */
    func_002DA928(li, bp, (short)bw, (short)t->texType, (short)dx, (short)dy, (short)bw8, (short)bh2);
    func_002F8660(0);
    func_002DAC50(li, (int)buf); /* DEBT(TYPE): declared with an int source */
    func_002DA610(0, 0);
    func_0018FC10(buf);
}

INCLUDE_ASM("build/ee_asm/game/rc/dt/rcdtTm2", func_0019F658);

INCLUDE_ASM("build/ee_asm/game/rc/dt/rcdtTm2", func_0019F6F8);

INCLUDE_ASM("build/ee_asm/game/rc/dt/rcdtTm2", func_0019F880);

INCLUDE_ASM("build/ee_asm/game/rc/dt/rcdtTm2", func_0019F9E8);

int func_0019FB60(Obj19FB60 *o) {
    int v = 0;

    if (o->sel != 0) {
        v = D_00313C90[o->sel - 1];
    }
    return v;
}

INCLUDE_ASM("build/ee_asm/game/rc/dt/rcdtTm2", rcefMainInit);

INCLUDE_ASM("build/ee_asm/game/rc/dt/rcdtTm2", func_0019FBF8);
