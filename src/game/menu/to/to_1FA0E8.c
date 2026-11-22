/* tu_223 0x1fa0e8-0x2004d0: low; ~locNameTmpSetLanguage (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/r4.h"
#include "ffx/t4.h"
#include "ffx/v4.h"
#include "ffx/w6.h"
#include "ffx/u3.h"
#include "ffx/s4.h"

void *func_001FA0E8(void *list, int x0, int y0, int w, int h)
{
    TexRect *t = TEX_RECT(0xC8);

    w -= x0;
    h -= y0;
    list = func_001FE1C8(list, 0xC8, x0, y0, 0, 0, D_003241C4, D_003241C4);
    list = func_001FE1C8(list, 0xC9, x0 + t->w, y0, w - t->w, 0, D_003241C4, D_003241C8);
    list = func_001FE1C8(list, 0xCA, x0, y0 + t->h, 0, h - t->h, D_003241C4, D_003241C4);
    return func_001FE1C8(list, 0xCB, x0 + t->w, y0 + t->h, w - t->w, h - t->h, D_003241C4, D_003241C8);
}

void *func_001FA208(void *list, int x, int y, int w, int h)
{
    TexRect *t = TEX_RECT(0xC8);

    list = func_001FE1C8(list, 0xC8, x, y, 0, 0, D_003241C4, D_003241C4);
    list = func_001FE1C8(list, 0xC9, x + t->w, y, w - t->w, 0, D_003241C4, D_003241C8);
    list = func_001FE1C8(list, 0xCA, x, y + t->h, 0, h - t->h, D_003241C4, D_003241C4);
    return func_001FE1C8(list, 0xCB, x + t->w, y + t->h, w - t->w, h - t->h, D_003241C4, D_003241C8);
}

void *func_001FA320(void *list, int x, int y, int w, int h, u32 c0, u32 c1)
{
    TexRect *t = TEX_RECT(0xC8);

    list = func_001FE1C8(list, 0xC8, x, y, 0, 0, c0, c0);
    list = func_001FE1C8(list, 0xC9, x + t->w, y, w - t->w, 0, c0, c1);
    list = func_001FE1C8(list, 0xCA, x, y + t->h, 0, h - t->h, c0, c0);
    return func_001FE1C8(list, 0xCB, x + t->w, y + t->h, w - t->w, h - t->h, c0, c1);
}

void func_001FA440(int x0, int y0, int w, int h)
{
    TexRect *t = TEX_RECT(0xC8);

    w -= x0;
    h -= y0;
    func_001FE298(0xC8, x0, y0, 0, 0, D_003241C4, D_003241C4);
    func_001FE298(0xC9, x0 + t->w, y0, w - t->w, 0, D_003241C4, D_003241C8);
    func_001FE298(0xCA, x0, y0 + t->h, 0, h - t->h, D_003241C4, D_003241C4);
    func_001FE298(0xCB, x0 + t->w, y0 + t->h, w - t->w, h - t->h, D_003241C4, D_003241C8);
    func_001EFA30();
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_001FA548);

void func_001FA6C0(int x, int y, int w, int h, int c0, int c1)
{
    TexRect *t;

    if (w < 16) {
        w = 16;
    }
    t = TEX_RECT(0xC8);
    func_001FE298(0xC8, x, y, 0, 0, c0, c0);
    func_001FE298(0xC9, x + t->w, y, w - t->w, 0, c0, c1);
    func_001FE298(0xCA, x, y + t->h, 0, h - t->h, c0, c0);
    func_001FE298(0xCB, x + t->w, y + t->h, w - t->w, h - t->h, c0, c1);
    func_001EFA30();
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_001FA7D0);

/* GS display-list helpers: wrappers appending SCE_GS_SET_* packets at the cursor InvokedFromSelectCursor.
 * Module name unknown (no source-file string found nearby). */

void func_001FA988(int u0, int v0, int w, int h, int x0, int y0)
{
    GIF_CUR()->ul64[0] = 0x1000000000008005UL;
    GIF_CUR()->ul64[1] = 0xE;
    GIF_NEXT();
    func_001FB290();
    func_001FB310(0, 0x1FF, 0, 0x19F);
    func_001FB2C0(0, 1, 0, 1, 0x80);
    GIF_AD(0xF, 0x47);
    GIF_AD(0x2005D40621313E00UL, 6);
    GIF_CUR()->ul64[0] = 0x50AF400000008001UL;
    GIF_CUR()->ul64[1] = 0x43431;
    GIF_NEXT();
    locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
    func_001FB550(u0, v0);
    func_001FB678(x0, y0);
    func_001FB550(u0 + w + 1, v0 + h + 1);
    func_001FB678(x0 + w + 1, y0 + h + 1);
    func_001EFA30();
}

void func_001FAB08(void)
{
    GIF_CUR()->ul64[0] = 0x1000000000000006UL;
    GIF_CUR()->ul64[1] = 0xE;
    GIF_NEXT();
    func_001FB290();
    GIF_AD(GS_SET_SCISSOR(0, 0x1FF, 0, 0x19F), 0x40);
    GIF_AD(0, 8);
    GIF_AD(0x8000000044UL, 0x42);
    GIF_AD(0xF, 0x47);
    GIF_AD(0x4005D48621313F00UL, 6);
    func_001EFA30();
}

void func_001FABF0(u8 kind, s16 x, s16 y)
{
    func_001EFDF8(x, y, x + 16, y + 14, 0x20, 0x20, 0x80, 0x80);
}

void func_001FAC20(int a, int b, int c)
{
    InvokedFromSelectCursor = func_001F9548(InvokedFromSelectCursor, a, b, c);
    func_001EFA30();
}

void func_001FAC60(int x0, int y0, int x1, int y1, int x2, int y2, u32 c1, u32 c0)
{
    GIF_CUR()->ul64[0] = 0x80A5C00000008001UL;
    GIF_CUR()->ul64[1] = 0x414141EE;
    GIF_NEXT();
    GIF_AD(0x8000000044UL, 0x42);
    GIF_AD(0xF, 0x47);
    func_001FB618(c0);
    func_001FB6B0(x0, y0, 1);
    func_001FB618(c1);
    func_001FB6B0(x1, y1, 1);
    func_001FB618(c1);
    func_001FB6B0(x2, y2, 1);
    func_001EFA30();
}

void func_001FAD78(int fbp, int fbw, int psm, int fbmsk)
{
    InvokedFromSelectCursor = func_001FB8B0(InvokedFromSelectCursor, fbp, fbw, psm, fbmsk);
}

void func_001FADC0(int x, int y)
{
    InvokedFromSelectCursor = func_001FB8E0(InvokedFromSelectCursor, x, y);
}

void func_001FADF8(void)
{
    InvokedFromSelectCursor = func_001FB900(InvokedFromSelectCursor);
}

void func_001FAE28(int a, int b, int c, int d, int fix)
{
    InvokedFromSelectCursor = func_001FB918(InvokedFromSelectCursor, a, b, c, d, fix);
}

void func_001FAE78(int x0, int x1, int y0, int y1)
{
    InvokedFromSelectCursor = func_001FB950(InvokedFromSelectCursor, x0, x1, y0, y1);
}

void func_001FAEC0(int ate, int atst, int aref, int afail, int date, int datm, int zte, int ztst)
{
    InvokedFromSelectCursor = func_001FB980(InvokedFromSelectCursor, ate, atst, aref, afail, date, datm, zte, ztst);
}

void func_001FAF28(int tbp0, int tbw, int psm, int tw, int th, int tcc, int tfx, int cbp, int cpsm, int csm, int csa, int cld)
{
    InvokedFromSelectCursor = func_001FB9D0(InvokedFromSelectCursor, tbp0, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld);
}

void func_001FAFD0(int lcm, int mxl, int mmag, int mmin, int mtba, int l, int k)
{
    InvokedFromSelectCursor = func_001FBA50(InvokedFromSelectCursor, lcm, mxl, mmag, mmin, mtba, l, k);
}

void func_001FB030(int wms, int wmt, int minu, int maxu, int minv, int maxv)
{
    InvokedFromSelectCursor = func_001FBA98(InvokedFromSelectCursor, wms, wmt, minu, maxu, minv, maxv);
}

void func_001FB088(u64 colclamp)
{
    InvokedFromSelectCursor = func_001FBAD8(InvokedFromSelectCursor, colclamp);
}

void func_001FB0B8(s32 x, s32 y)
{
    InvokedFromSelectCursor = func_001FBAF0(InvokedFromSelectCursor, x, y);
}

void func_001FB0F0(s32 a, s32 b, s32 c, s32 d)
{
    InvokedFromSelectCursor = func_001FBB30(InvokedFromSelectCursor, a, b, c, d);
}

void func_001FB138(u32 rgba)
{
    InvokedFromSelectCursor = func_001FBB48(InvokedFromSelectCursor, rgba);
}

void func_001FB168(s32 x, s32 y)
{
    InvokedFromSelectCursor = func_001FBBB0(InvokedFromSelectCursor, x, y);
}

void func_001FB1A0(s32 x, s32 y, s32 z)
{
    InvokedFromSelectCursor = func_001FBBE0(InvokedFromSelectCursor, x, y, z);
}

void func_001FB1E0(u64 fba)
{
    InvokedFromSelectCursor = func_001FBC40(InvokedFromSelectCursor, fba);
}

void func_001FB210(int fbp, int fbw, int psm, int fbmsk)
{
    InvokedFromSelectCursor = func_001FB8B0(InvokedFromSelectCursor, fbp, fbw, psm, fbmsk);
}

void func_001FB258(int x, int y)
{
    InvokedFromSelectCursor = func_001FB8E0(InvokedFromSelectCursor, x, y);
}

void func_001FB290(void)
{
    InvokedFromSelectCursor = func_001FB900(InvokedFromSelectCursor);
}

void func_001FB2C0(int a, int b, int c, int d, int fix)
{
    InvokedFromSelectCursor = func_001FB918(InvokedFromSelectCursor, a, b, c, d, fix);
}

void func_001FB310(int x0, int x1, int y0, int y1)
{
    InvokedFromSelectCursor = func_001FB950(InvokedFromSelectCursor, x0, x1, y0, y1);
}

void func_001FB358(int ate, int atst, int aref, int afail, int date, int datm, int zte, int ztst)
{
    InvokedFromSelectCursor = func_001FB980(InvokedFromSelectCursor, ate, atst, aref, afail, date, datm, zte, ztst);
}

void func_001FB3C0(int tbp0, int tbw, int psm, int tw, int th, int tcc, int tfx, int cbp, int cpsm, int csm, int csa, int cld)
{
    InvokedFromSelectCursor = func_001FB9D0(InvokedFromSelectCursor, tbp0, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld);
}

void func_001FB468(int lcm, int mxl, int mmag, int mmin, int mtba, int l, int k)
{
    InvokedFromSelectCursor = func_001FBA50(InvokedFromSelectCursor, lcm, mxl, mmag, mmin, mtba, l, k);
}

void func_001FB4C8(int wms, int wmt, int minu, int maxu, int minv, int maxv)
{
    InvokedFromSelectCursor = func_001FBA98(InvokedFromSelectCursor, wms, wmt, minu, maxu, minv, maxv);
}

void func_001FB520(u64 colclamp)
{
    InvokedFromSelectCursor = func_001FBAD8(InvokedFromSelectCursor, colclamp);
}

void func_001FB550(s32 x, s32 y)
{
    InvokedFromSelectCursor = func_001FBAF0(InvokedFromSelectCursor, x, y);
}

void func_001FB588(s32 x, s32 xo, s32 y, s32 yo)
{
    InvokedFromSelectCursor = func_001FBB10(InvokedFromSelectCursor, x, xo, y, yo);
}

void locNameTmpSetLanguage(s32 a, s32 b, s32 c, s32 d)
{
    InvokedFromSelectCursor = func_001FBB30(InvokedFromSelectCursor, a, b, c, d);
}

void func_001FB618(u32 rgba)
{
    InvokedFromSelectCursor = func_001FBB48(InvokedFromSelectCursor, rgba);
}

void func_001FB648(u32 rgba)
{
    InvokedFromSelectCursor = func_001FBB48(InvokedFromSelectCursor, rgba);
}

void func_001FB678(s32 x, s32 y)
{
    InvokedFromSelectCursor = func_001FBBB0(InvokedFromSelectCursor, x, y);
}

void func_001FB6B0(s32 x, s32 y, s32 z)
{
    InvokedFromSelectCursor = func_001FBBE0(InvokedFromSelectCursor, x, y, z);
}

void func_001FB6F0(s32 x, s32 y, s32 z, s32 w)
{
    InvokedFromSelectCursor = func_001FBC10(InvokedFromSelectCursor, x, y, z, w);
}

void func_001FB738(s32 a, s32 b)
{
    InvokedFromSelectCursor = func_001FBB78(InvokedFromSelectCursor, a, b);
}

void func_001FB770(s32 a, s32 b, s32 c)
{
    InvokedFromSelectCursor = func_001FBB98(InvokedFromSelectCursor, a, b, c);
}

void func_001FB7B0(u64 fba)
{
    InvokedFromSelectCursor = func_001FBC40(InvokedFromSelectCursor, fba);
}

void func_001FB7E0(int zbp, int psm, int zmsk)
{
    InvokedFromSelectCursor = func_001FBC58(InvokedFromSelectCursor, zbp, psm, zmsk);
}

void func_001FB820(int fog)
{
    InvokedFromSelectCursor = func_001FBC80(InvokedFromSelectCursor, fog);
}

void func_001FB850(int r, int g, int b)
{
    InvokedFromSelectCursor = func_001FBC98(InvokedFromSelectCursor, r, g, b);
}

void func_001FB890(int mode)
{
    mode--;
    if ((u32)mode < 2) {
        D_00323640 = mode;
    }
}

GsAdPacket *func_001FB8B0(GsAdPacket *p, int fbp, int fbw, int psm, int fbmsk)
{
    p->data = SCE_GS_SET_FRAME(fbp, fbw, psm, fbmsk);
    p->reg = GS_REG_FRAME_1;
    return p + 1;
}

GsAdPacket *func_001FB8E0(GsAdPacket *p, int x, int y)
{
    p->data = SCE_GS_SET_XYOFFSET(x, y);
    p->reg = GS_REG_XYOFFSET_1;
    return p + 1;
}

GsAdPacket *func_001FB900(GsAdPacket *p)
{
    p->data = 0;
    p->reg = GS_REG_TEXFLUSH;
    return p + 1;
}

GsAdPacket *func_001FB918(GsAdPacket *p, int a, int b, int c, int d, int fix)
{
    p->data = SCE_GS_SET_ALPHA(a, b, c, d, fix);
    p->reg = GS_REG_ALPHA_1;
    return p + 1;
}

GsAdPacket *func_001FB950(GsAdPacket *p, int x0, int x1, int y0, int y1)
{
    p->data = SCE_GS_SET_SCISSOR(x0, x1, y0, y1);
    p->reg = GS_REG_SCISSOR_1;
    return p + 1;
}

GsAdPacket *func_001FB980(GsAdPacket *p, int ate, int atst, int aref, int afail, int date, int datm, int zte, int ztst)
{
    p->data = SCE_GS_SET_TEST(ate, atst, aref, afail, date, datm, zte, ztst);
    p->reg = GS_REG_TEST_1;
    return p + 1;
}

/* GS A+D / quad packet builders (SCE_GS_SET_FRAME/ALPHA/TEST/TEX0/... equivalents).
 * Module name unknown. */

GsAdPacket *func_001FB9D0(GsAdPacket *p, int tbp0, int tbw, int psm, int tw, int th, int tcc, int tfx, int cbp, int cpsm, int csm, int csa, int cld)
{
    p->data = SCE_GS_SET_TEX0(tbp0, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld);
    p->reg = GS_REG_TEX0_1;
    return p + 1;
}

GsAdPacket *func_001FBA50(GsAdPacket *p, int lcm, int mxl, int mmag, int mmin, int mtba, int l, int k)
{
    p->data = SCE_GS_SET_TEX1(lcm, mxl, mmag, mmin, mtba, l, k);
    p->reg = GS_REG_TEX1_1;
    return p + 1;
}

GsAdPacket *func_001FBA98(GsAdPacket *p, int wms, int wmt, int minu, int maxu, int minv, int maxv)
{
    p->data = SCE_GS_SET_CLAMP(wms, wmt, minu, maxu, minv, maxv);
    p->reg = GS_REG_CLAMP_1;
    return p + 1;
}

GsAdPacket *func_001FBAD8(GsAdPacket *p, u64 colclamp)
{
    p->data = colclamp;
    p->reg = GS_REG_COLCLAMP;
    return p + 1;
}

Quad32 *func_001FBAF0(Quad32 *p, s32 x, s32 y)
{
    p->w[0] = (x << 4) + 8;
    p->w[1] = (y << 4) + 8;
    return p + 1;
}

Quad32 *func_001FBB10(Quad32 *p, s32 x, s32 xo, s32 y, s32 yo)
{
    p->w[0] = (x << 4) + xo;
    p->w[1] = (y << 4) + yo;
    return p + 1;
}

Quad32 *func_001FBB30(Quad32 *p, s32 a, s32 b, s32 c, s32 d)
{
    p->w[0] = a;
    p->w[1] = b;
    p->w[2] = c;
    p->w[3] = d;
    return p + 1;
}

Quad32 *func_001FBB48(Quad32 *p, u32 rgba)
{
    p->w[0] = rgba & 0xFF;
    p->w[1] = (rgba >> 8) & 0xFF;
    p->w[2] = (rgba >> 16) & 0xFF;
    p->w[3] = rgba >> 24;
    return p + 1;
}

Quad32 *func_001FBB78(Quad32 *p, s32 a, s32 b)
{
    p->w[0] = a;
    p->w[1] = b;
    p->w[2] = 0x10;
    p->w[3] = 0;
    return p + 1;
}

Quad32 *func_001FBB98(Quad32 *p, s32 a, s32 b, s32 c)
{
    p->w[0] = a;
    p->w[1] = b;
    p->w[2] = c;
    p->w[3] = 0;
    return p + 1;
}

Quad32 *func_001FBBB0(Quad32 *p, s32 x, s32 y)
{
    p->w[0] = (x + 0x700) << 4;
    p->w[1] = (y + 0x730) << 4;
    p->w[2] = 0x10;
    p->w[3] = 0;
    return p + 1;
}

Quad32 *func_001FBBE0(Quad32 *p, s32 x, s32 y, s32 z)
{
    p->w[0] = (x + 0x700) << 4;
    p->w[1] = (y + 0x730) << 4;
    p->w[2] = z << 4;
    p->w[3] = 0;
    return p + 1;
}

Quad32 *func_001FBC10(Quad32 *p, s32 x, s32 y, s32 z, s32 w)
{
    p->w[0] = (x + 0x700) << 4;
    p->w[1] = (y + 0x730) << 4;
    p->w[2] = z << 4;
    p->w[3] = w << 4;
    return p + 1;
}

GsAdPacket *func_001FBC40(GsAdPacket *p, u64 fba)
{
    p->data = fba;
    p->reg = GS_REG_FBA_1;
    return p + 1;
}

GsAdPacket *func_001FBC58(GsAdPacket *p, int zbp, int psm, int zmsk)
{
    p->data = SCE_GS_SET_ZBUF(zbp, psm, zmsk);
    p->reg = GS_REG_ZBUF_1;
    return p + 1;
}

GsAdPacket *func_001FBC80(GsAdPacket *p, int fog)
{
    p->data = (u64)fog << 56;
    p->reg = GS_REG_FOG;
    return p + 1;
}

GsAdPacket *func_001FBC98(GsAdPacket *p, int r, int g, int b)
{
    p->data = (u64)r | ((u64)g << 8) | ((u64)b << 16);
    p->reg = GS_REG_FOGCOL;
    return p + 1;
}

void func_001FBCC0(int a)
{
    GIF_CUR()->ul64[0] = 0x1000000000008001UL;
    GIF_CUR()->ul64[1] = 0xE;
    GIF_NEXT();
    GIF_CUR()->ul64[0] = a;
    GIF_CUR()->ul64[1] = 0x4A;
    GIF_NEXT();
}

void func_001FBD00(void) {
}

void func_001FBD08(int x0, int y0, int x1, int y1, int z)
{
    GIF_CUR()->ul64[0] = 0x6023400000008001UL;
    GIF_CUR()->ul64[1] = 0x441EEE;
    GIF_NEXT();
    GIF_AD(GS_SET_SCISSOR(0, 0x1FF, 0, 0x19F), 0x40);
    GIF_AD(0x8000000044UL, 0x42);
    GIF_AD(0x32001, 0x47);
    locNameTmpSetLanguage(0, 0, 0, 0);
    func_001FB6B0(x0, y0, z);
    func_001FB6B0(x1, y1, z);
    func_001EFA30();
}

void func_001FBE20(int x, int y, int n)
{
    float dy;

    GIF_CUR()->ul64[0] = 0x1000000000000003UL;
    GIF_CUR()->ul64[1] = 0xE;
    GIF_NEXT();
    func_001FB2C0(0, 1, 0, 1, 0x80);
    GIF_AD(0x3000F, 0x47);
    GIF_AD(0x2005D48621313F00UL, 6);
    GIF_CUR()->ul64[0] = 0x30A3400000008001UL;
    GIF_CUR()->ul64[1] = 0x441;
    GIF_NEXT();
    dy = n * 10.0f;
    locNameTmpSetLanguage(0xE3, 0xE3, 0xE3, 0x80);
    if (n == 0) {
        func_001FB678(x, y);
    } else {
        func_001FB678(x, (int)(y + dy));
    }
    if (n == 8) {
        func_001FB678(x + 2, y + 0xAC);
    } else {
        func_001FB678(x + 2, (int)(y + dy + 80.0f));
    }
    func_001EFA30();
}

void func_001FBFB8(int x, int y, int w, int h, int total, int page, int pos)
{
    int ix1;
    int ix2;
    int iy2;
    int iy1;
    double dx1;
    double dx2;
    double dy1;
    double dy2;
    int x2;
    int y2;

    x2 = x + w;
    y2 = y + h;
    ix1 = x + 1;
    iy1 = y + 1;
    ix2 = x2 - 1;
    iy2 = y2 - 1;
    dx1 = ix1;
    dy1 = iy1;
    dx2 = ix2;
    dy2 = iy2;

    if (page < total) {
        double step = (dy2 - dy1) / (double)total;
        dy1 += step * (double)pos;
        dy2 = dy1 + step * (double)page;
        if (pos == 0) {
            dy1 = iy1;
        }
        if (pos + page >= total) {
            dy2 = iy2;
        }
        func_001EFDF8(x, y, x2, y2, 0x70, 0x70, 0x70, 0x80);
        func_001EFDF8(ix1, iy1, ix2, iy2, 0, 0, 0, 0x80);
        func_001EFDF8((int)dx1, (int)dy1, (int)dx2, (int)dy2, 0xC0, 0xC0, 0xC0, 0x80);
        func_001EFA30();
    }
}

void func_001FC1F0(int x, int y, int scale, int alpha)
{
    float fx, fy, x0, y0, x1, y1, dw, dh;

    GIF_CUR()->ul64[0] = 0x1000000000000004UL;
    GIF_CUR()->ul64[1] = 0xE;
    GIF_NEXT();
    GIF_AD(GS_SET_SCISSOR(0, 0x1FF, 0, 0x19F), 0x40);
    GIF_AD(0x4005D48621313F00UL, 6);
    GIF_AD(0x8000000044UL, 0x42);
    GIF_AD(0xF, 0x47);
    fx = x;
    fy = y;
    dw = ((scale * 32) / 100) * 0.5f;
    dh = ((scale * 11) / 100) * 0.5f;
    x0 = fx - dw;
    x1 = fx + dw;
    y0 = fy - dh;
    y1 = fy + dh;
    GIF_CUR()->ul64[0] = 0x50AF400000008001UL;
    GIF_CUR()->ul64[1] = 0x43431;
    GIF_NEXT();
    locNameTmpSetLanguage(0x80, 0x80, 0x80, alpha);
    func_001FB550(0xDF, 0x8D);
    func_001FB678((int)x0, (int)y0);
    func_001FB550(0xFF, 0x98);
    func_001FB678((int)x1, (int)y1);
    func_001EFA30();
}

void func_001FC3C8(int x, int y)
{
    s16 bx;
    s16 by;

    if (D_003238D0.h12 & 0xF000) {
        if (D_003238D0.h12 & 0x1000) {
            TOMkpShapeXY(0x259, x, y);
        } else {
            TOMkpShapeXY(0x258, x, y);
        }
        if (D_003238D0.h12 & 0x2000) {
            TOMkpShapeXY(0x25B, x, y);
        } else {
            TOMkpShapeXY(0x25A, x, y);
        }
        if (D_003238D0.h12 & 0x4000) {
            TOMkpShapeXY(0x25D, x, y);
        } else {
            TOMkpShapeXY(0x25C, x, y);
        }
        if (D_003238D0.h12 & 0x8000) {
            TOMkpShapeXY(0x25F, x, y);
        } else {
            TOMkpShapeXY(0x25E, x, y);
        }
    } else {
        if (D_003238D0.b1F < 0x40) {
            TOMkpShapeXY(0x259, x, y);
        } else {
            TOMkpShapeXY(0x258, x, y);
        }
        if (D_003238D0.b1E >= 0xC1) {
            TOMkpShapeXY(0x25B, x, y);
        } else {
            TOMkpShapeXY(0x25A, x, y);
        }
        if (D_003238D0.b1F >= 0xC1) {
            TOMkpShapeXY(0x25D, x, y);
        } else {
            TOMkpShapeXY(0x25C, x, y);
        }
        if (D_003238D0.b1E < 0x40) {
            TOMkpShapeXY(0x25F, x, y);
        } else {
            TOMkpShapeXY(0x25E, x, y);
        }
    }

    bx = x + 0x14;
    by = y;
    if (D_003238D0.h12 & 0x10) {
        TOMkpShapeXY(0x260, bx, by);
    }
    if (func_0020B850() == 0 && func_001BD360() == 1) {
        if (D_003238D0.h12 & 0x20) {
            TOMkpShapeXY(0x262, bx + 0x12, by);
        }
        if (D_003238D0.h12 & 0x40) {
            TOMkpShapeXY(0x261, bx + 0x24, by);
        }
    } else {
        if (D_003238D0.h12 & 0x20) {
            TOMkpShapeXY(0x261, bx + 0x12, by);
        }
        if (D_003238D0.h12 & 0x40) {
            TOMkpShapeXY(0x262, bx + 0x24, by);
        }
    }
    if (D_003238D0.h12 & 0x80) {
        TOMkpShapeXY(0x263, bx + 0x36, by);
    }

    bx = x;
    by = y + 0x14;
    if (D_003238D0.h12 & 0x4) {
        TOMkpShapeXY(0x264, bx, by);
    }
    if (D_003238D0.h12 & 0x8) {
        TOMkpShapeXY(0x265, bx + 0x18, by);
    }
    if (D_003238D0.h12 & 0x1) {
        TOMkpShapeXY(0x266, bx + 0x30, by);
    }
    if (D_003238D0.h12 & 0x2) {
        TOMkpShapeXY(0x267, bx + 0x48, by);
    }
    if (D_003238D0.h12 & 0x800) {
        TOMkpShapeXY(0x268, bx + 0x60, by);
    }
    if (D_003238D0.h12 & 0x100) {
        TOMkpShapeXY(0x269, bx + 0x8E, by);
    }
    func_001EFA30();
}

void func_001FC770(int pad0, int x, int y)
{
    u16 pad = pad0;
    if (pad & 0xF000) {
        if (pad & 0x1000) {
            TOMkpShapeXY(0x259, x, y);
        } else {
            TOMkpShapeXY(0x258, x, y);
        }
        if (pad & 0x2000) {
            TOMkpShapeXY(0x25B, x, y);
        } else {
            TOMkpShapeXY(0x25A, x, y);
        }
        if (pad & 0x4000) {
            TOMkpShapeXY(0x25D, x, y);
        } else {
            TOMkpShapeXY(0x25C, x, y);
        }
        if (pad & 0x8000) {
            TOMkpShapeXY(0x25F, x, y);
        } else {
            TOMkpShapeXY(0x25E, x, y);
        }
    }
    if (pad & 0x10) {
        TOMkpShapeXY(0x260, x, y);
    }
    if (func_0020B850() == 0 && func_001BD360() == 1) {
        if (pad & 0x20) {
            TOMkpShapeXY(0x262, x, y);
        }
        if (pad & 0x40) {
            TOMkpShapeXY(0x261, x, y);
        }
    } else {
        if (pad & 0x20) {
            TOMkpShapeXY(0x261, x, y);
        }
        if (pad & 0x40) {
            TOMkpShapeXY(0x262, x, y);
        }
    }
    if (pad & 0x80) {
        TOMkpShapeXY(0x263, x, y);
    }
    if (pad & 0x4) {
        TOMkpShapeXY(0x264, x, y);
    }
    if (pad & 0x8) {
        TOMkpShapeXY(0x265, x, y);
    }
    if (pad & 0x1) {
        TOMkpShapeXY(0x266, x, y);
    }
    if (pad & 0x2) {
        TOMkpShapeXY(0x267, x, y);
    }
    if (pad & 0x800) {
        TOMkpShapeXY(0x268, x, y);
    }
    if (pad & 0x100) {
        TOMkpShapeXY(0x269, x, y);
    }
    func_001EFA30();
}

int func_001FC9B0(int n, int x, int y)
{
    V4IconTbl a = D_00570020;
    V4IconTbl2 b = D_00570068;

    if (n >= 0) {
        TOMkpShapeXY(a.id[n][0], x, y);
        TOMkpShapeXY(a.id[n][1], x, y);
        TOMkpShapeXY(a.id[n][2], x, y);
        TOMkpShapeXY(a.id[n][3], x, y);
    }
    if ((u32)(n - 0x10) < 0x7F1) {
        TOMkpShapeXY(b.id[n - 0x10], x, y);
    }
    return func_001EFA30();
}

void func_001FCB88(int b, int c, u32 rgba)
{
    char buf[0x10];
    int i;

    func_002F0008(buf, D_00570080, ((int (*)(void))func_002ED038)());
    for (i = 0; i < 16 && buf[i] != 0; i++, b += 20) {
        if (buf[i] >= '0' && buf[i] <= '9') {
            func_001FE240(buf[i] + 0x1B0, b, c, rgba, rgba);
        }
        if (buf[i] == '.') {
            func_001FE240(0x1DF, b, c, rgba, rgba);
        }
    }
    func_001EFA30();
}

void func_001FCC88(int a, int b, int c, u32 rgba)
{
    char buf[0x10];
    int i;

    func_002F0008(buf, D_00570088, a);
    for (i = 0; i < 8 && buf[i] != 0; i++, b += 16) {
        if (buf[i] >= '0' && buf[i] <= '9') {
            func_001FE240(buf[i] + 0x1BA, b, c, rgba, rgba);
        }
    }
    func_001EFA30();
}

typedef struct {
    u8 pad0[0x60];
    unsigned long f60 : 9;
    unsigned long pad60 : 55;
    u8 pad68[0x168];
    unsigned long f1D0 : 9;
    unsigned long pad1D0 : 55;
} To1FCD48DBuff;

extern s32 D_006672D4;

void func_001FCD48(void)
{
    To1FCD48DBuff *p = Sg_GetDBuffDC(&D_006672D4);

    if (D_006672D4 & 1) {
        D_006672D0 = p->f1D0;
    } else {
        D_006672D0 = p->f60;
    }
    GIF_AD_TAG(1);
    func_001FB210(0, 8, 0, 0);
}

void func_001FCDD8(void)
{
    GIF_CUR()->ul64[0] = 0x1000000000008001UL;
    GIF_CUR()->ul64[1] = 0xE;
    GIF_NEXT();
    func_001FB210(D_006672D0, 8, 1, 0);
}

void func_001FCE18(int x0, int y0, int x1, int y1, int u0, int v0, int u1, int v1, int a)
{
    GIF_CUR()->ul64[0] = 0x1000000000008004UL;
    GIF_CUR()->ul64[1] = 0xE;
    GIF_NEXT();
    func_001FB290();
    func_001FB2C0(0, 1, 0, 1, 0x80);
    GIF_AD(0xF, 0x47);
    GIF_AD(0x624020000UL, 6);
    GIF_CUR()->ul64[0] = 0x50AB400000008001UL;
    GIF_CUR()->ul64[1] = 0x43431;
    GIF_NEXT();
    locNameTmpSetLanguage(0x80, 0x80, 0x80, a);
    func_001FB550(u0, v0);
    func_001FB678(x0, y0);
    func_001FB550(u1, v1);
    func_001FB678(x1, y1);
    func_001EFA30();
}

void func_001FCF88(UiPrim *p)
{
    u32 c0 = p->col0;
    u32 c1 = p->col1;
    int r0 = c0 & 0xFF;
    int g0 = (c0 >> 8) & 0xFF;
    int b0 = (c0 >> 16) & 0xFF;
    int a0 = c0 >> 24;
    int r1 = c1 & 0xFF;
    int g1 = (c1 >> 8) & 0xFF;
    int b1 = (c1 >> 16) & 0xFF;
    int a1 = c1 >> 24;

    GIF_CUR()->ul64[0] = 0x60A4C00000008001UL;
    GIF_CUR()->ul64[1] = 0x4141EE;
    GIF_NEXT();
    GIF_AD(0x8000000044UL, 0x42);
    GIF_AD(0xF, 0x47);
    locNameTmpSetLanguage(r0, g0, b0, a0);
    func_001FB6B0(p->x, p->y, 1);
    locNameTmpSetLanguage(r1, g1, b1, a1);
    func_001FB6B0(p->p10, p->p12, 1);
    func_001EFA30();
}

void func_001FD0A0(UiPrim *p)
{
    u32 c0 = p->col0;
    u32 c1 = p->col1;
    int r0 = c0 & 0xFF;
    int g0 = (c0 >> 8) & 0xFF;
    int b0 = (c0 >> 16) & 0xFF;
    int a0 = c0 >> 24;
    int r1 = c1 & 0xFF;
    int g1 = (c1 >> 8) & 0xFF;
    int b1 = (c1 >> 16) & 0xFF;
    int a1 = c1 >> 24;

    GIF_CUR()->ul64[0] = 0xA0A6400000008001UL;
    GIF_CUR()->ul64[1] = 0x41414141EEUL;
    GIF_NEXT();
    GIF_AD(0x8000000044UL, 0x42);
    GIF_AD(0xF, 0x47);
    locNameTmpSetLanguage(r0, g0, b0, a0);
    func_001FB6B0(p->x, p->y, 1);
    locNameTmpSetLanguage(r1, g1, b1, a1);
    func_001FB6B0(p->x + p->p10, p->y, 1);
    locNameTmpSetLanguage(r0, g0, b0, a0);
    func_001FB6B0(p->x, p->y + p->p12, 1);
    locNameTmpSetLanguage(r1, g1, b1, a1);
    func_001FB6B0(p->x + p->p10, p->y + p->p12, 1);
    func_001EFA30();
}

typedef struct {
    u8 u;
    u8 v;
    s8 dx;
    s8 dy;
    u16 w;
    u16 h;
    u16 flipX;
    u16 flipY;
} ShapePart12;

void func_001FD260(UiPrim *p)
{
    u32 *hdr;
    ShapePart12 *part;
    int tbp, cbp;
    u32 col;
    int r, g, b, a;
    u32 i;

    if (p->p14.u < 0xC8) {
        hdr = (u32 *)func_001FD6F0(p->p14.u);
        part = (ShapePart12 *)(hdr + 1);
        tbp = 0x3E00;
        cbp = 0x2EA0;
    }
    if (p->p14.u >= 0xC8 && p->p14.u < 0x190) {
        hdr = (u32 *)func_001FD6F0(p->p14.u - 0xC8);
        part = (ShapePart12 *)(hdr + 1);
        tbp = 0x3E00;
        cbp = 0x2EA0;
    }
    if (p->p14.u >= 0x190 && p->p14.u < 0x258) {
        hdr = (u32 *)func_001FD718(p->p14.u - 0x190);
        part = (ShapePart12 *)(hdr + 1);
        tbp = 0x3F00;
        cbp = 0x2EA4;
    }
    col = p->col0;
    r = col & 0xFF;
    g = (col >> 8) & 0xFF;
    b = (col >> 16) & 0xFF;
    a = col >> 24;
    GIF_CUR()->ul64[0] = 0x3000000000000001UL;
    GIF_CUR()->ul64[1] = 0xEEE;
    GIF_NEXT();
    GIF_AD(0x8000000044UL, 0x42);
    GIF_AD(0xF, 0x47);
    GIF_AD(SCE_GS_SET_TEX0(tbp, 4, 0x13, 8, 8, 1, 0, cbp, 0, 0, 0, 1), 6);
    for (i = 0; i < *hdr; i++, part++) {
        double dx0, dx1, dy0, dy1;
        int x0, x1, y0, y1;

        GIF_CUR()->ul64[0] = 0x60AB400000008001UL;
        GIF_CUR()->ul64[1] = 0x431431;
        GIF_NEXT();
        dx0 = part->dx;
        dx1 = part->dx + part->w;
        dy0 = part->dy;
        dy1 = part->dy + part->h;
        if (p->p10 != 100) {
            dx0 = (dx0 / 100.0) * p->p10;
            dx1 = (dx1 / 100.0) * p->p10;
        }
        if (p->p12 != 100) {
            dy0 = (dy0 / 100.0) * p->p12;
            dy1 = (dy1 / 100.0) * p->p12;
        }
        if (part->flipX == 1) {
            x0 = (int)dx1 + p->x;
            x1 = (int)dx0 + p->x;
        } else {
            x0 = (int)dx0 + p->x;
            x1 = (int)dx1 + p->x;
        }
        if (part->flipY == 1) {
            y0 = (int)dy1 + p->y;
            y1 = (int)dy0 + p->y;
        } else {
            y0 = (int)dy0 + p->y;
            y1 = (int)dy1 + p->y;
        }
        locNameTmpSetLanguage(r, g, b, a);
        func_001FB550(part->u, part->v);
        func_001FB6B0(x0, y0, 1);
        locNameTmpSetLanguage(r, g, b, a);
        func_001FB550(part->u + (part->w - 1), part->v + (part->h - 1));
        func_001FB6B0(x1, y1, 1);
    }
    func_001EFA30();
}

void TOMakePktSeqPrimMes(R4Msg *m)
{
    TOMkpEasyStrFontM((int)D_00570090, m->hC, m->hE); /* DEBT(CAST): prototype takes the string as int */
    func_001EFA30();
}

void TOMakePktSeqPrimFunc(R4Msg *m)
{
    TOBtlDrawChangeSeqAnm0(m->h1C, m->hC, m->hE);
    func_001EFA30();
}

void *func_001FD6C8(OffsetTable *tbl, u32 index)
{
    if (index >= tbl->count) {
        return 0;
    }
    return (u8 *)tbl + tbl->offset[index];
}

int func_001FD6F0(u32 id)
{
    return (int)func_001FD6C8(&D_00321328, id); /* DEBT(TYPE): prototype says int */
}

int func_001FD718(u32 id)
{
    return (int)func_001FD6C8(&D_00322190, id); /* DEBT(TYPE): prototype says int */
}

int func_001FD740(u32 id)
{
    return (int)func_001FD6C8(&D_00323440, id); /* DEBT(TYPE): prototype says int */
}

int func_001FD768(u32 id)
{
    int r; /* left unset when id is out of every range, as in the original */

    if (id < 0xC7) {
        r = func_001FD6F0(id);
    }
    if (id - 0xC8 < 0xC7) {
        r = func_001FD6F0(id - 0xC8);
    }
    if (id - 0x190 < 0xC7) {
        r = func_001FD718(id - 0x190);
    }
    if (id - 0x258 < 0x32) {
        r = func_001FD740(id - 0x258);
    }
    return r;
}

GsAdPacket * func_001FD7F8(GsAdPacket *p)
{
    return func_001FD818(p);
}

GsAdPacket *func_001FD818(GsAdPacket *p)
{
    p->data = SCE_GIF_SET_TAG(1, 0, 0, 0, 0, 3);
    p->reg = 0xEEE;
    p = func_001FB918(p + 1, 0, 1, 0, 1, 0x80);
    p = func_001FB980(p, 1, 7, 0, 0, 0, 0, 0, 0);
    return func_001FB9D0(p, 0x3E00, 4, 0x13, 8, 8, 1, 0, 0x2EA0, 0, 0, 0, 1);
}

GsAdPacket *func_001FD8C8(GsAdPacket *p)
{
    p->data = SCE_GIF_SET_TAG(1, 0, 0, 0, 0, 3);
    p->reg = 0xEEE;
    p = func_001FB918(p + 1, 0, 1, 0, 1, 0x80);
    p = func_001FB980(p, 1, 7, 0, 0, 0, 0, 0, 0);
    return func_001FB9D0(p, 0x3F00, 4, 0x13, 8, 8, 1, 0, 0x2EA4, 0, 0, 0, 1);
}

GsAdPacket *func_001FD978(GsAdPacket *p)
{
    p->data = SCE_GIF_SET_TAG(1, 0, 0, 0, 0, 4);
    p->reg = 0xEEEE;
    p = func_001FB918(p + 1, 0, 1, 0, 1, 0x80);
    p = func_001FB980(p, 1, 7, 0, 0, 0, 0, 0, 0);
    p = func_001FB9D0(p, 0x3DC0, 4, 0x13, 8, 7, 1, 0, 0x2ECC, 0, 0, 0, 2);
    return func_001FB9D0(p, 0x3DC0, 4, 0x14, 8, 7, 1, 0, 0x2ECC, 0, 0, 2, 0);
}

void *TOMkpShapePartIndexXYWHC2(void *list, int id, int x, int y, int w, int h, int c0, int c1)
{
    Qword *p = list;
    u32 *hdr;
    ShapePart12 *part;
    u32 i;
    int x0, x1, y0, y1;

    if (w == 0 || h == 0) {
        return p;
    }
    if ((u32)id < 0xC7) {
        p = (Qword *)func_001FD7F8((GsAdPacket *)p);
        hdr = (u32 *)func_001FD6F0(id);
    }
    if ((u32)(id - 0xC8) < 0xC7) {
        p = (Qword *)func_001FD818((GsAdPacket *)p);
        hdr = (u32 *)func_001FD6F0(id - 0xC8);
    }
    if ((u32)(id - 0x190) < 0xC7) {
        p = (Qword *)func_001FD8C8((GsAdPacket *)p);
        hdr = (u32 *)func_001FD718(id - 0x190);
    }
    if ((u32)(id - 0x258) < 0x32) {
        p = (Qword *)func_001FD978((GsAdPacket *)p);
        hdr = (u32 *)func_001FD740(id - 0x258);
    }
    part = (ShapePart12 *)(hdr + 1);
    for (i = 0; i < *hdr; i++, part++) {
        if (part->flipX == 1) {
            x0 = part->dx + x + w;
            x1 = part->dx + x;
        } else {
            x0 = part->dx + x;
            x1 = x0 + w;
        }
        if (part->flipY == 1) {
            y0 = part->dy + y + h;
            y1 = part->dy + y;
        } else {
            y0 = part->dy + y;
            y1 = y0 + h;
        }
        p->ul64[0] = 0xC0AE400000008001UL;
        p->ul64[1] = 0x431431431431UL;
        p++;
        p = (Qword *)func_001FBB48((Quad32 *)p, c0);
        p->ui32[0] = (part->u << 4) + 8;
        p->ui32[1] = (part->v << 4) + 8;
        p++;
        p = (Qword *)func_001FBBB0((Quad32 *)p, x0, y0);
        p = (Qword *)func_001FBB48((Quad32 *)p, c1);
        p->ui32[0] = ((part->u + w - 1) << 4) + 8;
        p->ui32[1] = (part->v << 4) + 8;
        p++;
        p = (Qword *)func_001FBBB0((Quad32 *)p, x1, y0);
        p = (Qword *)func_001FBB48((Quad32 *)p, c0);
        p->ui32[0] = (part->u << 4) + 8;
        p->ui32[1] = ((part->v + part->h - 1) << 4) + 8;
        p++;
        p = (Qword *)func_001FBBB0((Quad32 *)p, x0, y1);
        p = (Qword *)func_001FBB48((Quad32 *)p, c1);
        p->ui32[0] = ((part->u + w - 1) << 4) + 8;
        p->ui32[1] = ((part->v + part->h - 1) << 4) + 8;
        p++;
        p = (Qword *)func_001FBBB0((Quad32 *)p, x1, y1);
    }
    return p;
}

void func_001FDD78(int a, int b, int c, int d, int e, int f, int g)
{
    InvokedFromSelectCursor = TOMkpShapePartIndexXYWHC2(InvokedFromSelectCursor, a, b, c, d, e, f, g);
    func_001EFA30();
}

void *func_001FDDD8(void *list, int id, int x, int y, int w, int h, u32 c0, u32 c1)
{
    Qword *p = list;
    u32 *hdr;
    ShapePart12 *part;
    int pw, ph;
    u32 i;
    int x0, x1, y0, y1;

    if ((u32)id < 0xC7) {
        p = (Qword *)func_001FD7F8((GsAdPacket *)p);
        hdr = (u32 *)func_001FD6F0(id);
    }
    if ((u32)(id - 0xC8) < 0xC7) {
        p = (Qword *)func_001FD818((GsAdPacket *)p);
        hdr = (u32 *)func_001FD6F0(id - 0xC8);
    }
    if ((u32)(id - 0x190) < 0xC7) {
        p = (Qword *)func_001FD8C8((GsAdPacket *)p);
        hdr = (u32 *)func_001FD718(id - 0x190);
    }
    if ((u32)(id - 0x258) < 0x32) {
        p = (Qword *)func_001FD978((GsAdPacket *)p);
        hdr = (u32 *)func_001FD740(id - 0x258);
    }
    part = (ShapePart12 *)(hdr + 1);
    pw = w;
    ph = h;
    for (i = 0; i < *hdr; i++, part++) {
        if (w == 0) {
            pw = part->w;
        }
        if (h == 0) {
            ph = part->h;
        }
        if (part->flipX == 1) {
            x0 = part->dx + x + pw;
            x1 = part->dx + x;
        } else {
            x0 = part->dx + x;
            x1 = x0 + pw;
        }
        if (part->flipY == 1) {
            y0 = part->dy + y + ph;
            y1 = part->dy + y;
        } else {
            y0 = part->dy + y;
            y1 = y0 + ph;
        }
        p->ul64[0] = 0xC0AE400000008001UL;
        p->ul64[1] = 0x431431431431UL;
        p++;
        p = (Qword *)func_001FBB48((Quad32 *)p, c0);
        p->ui32[0] = (part->u << 4) + 8;
        p->ui32[1] = (part->v << 4) + 8;
        p++;
        p = (Qword *)func_001FBBB0((Quad32 *)p, x0, y0);
        p = (Qword *)func_001FBB48((Quad32 *)p, c1);
        if (w == 0) {
            p->ui32[0] = ((part->u + part->w) << 4) + 8;
        } else {
            p->ui32[0] = ((part->u + part->w - 1) << 4) + 8;
        }
        p->ui32[1] = (part->v << 4) + 8;
        p++;
        p = (Qword *)func_001FBBB0((Quad32 *)p, x1, y0);
        p = (Qword *)func_001FBB48((Quad32 *)p, c0);
        p->ui32[0] = (part->u << 4) + 8;
        if (h == 0) {
            p->ui32[1] = ((part->v + part->h) << 4) + 8;
        } else {
            p->ui32[1] = ((part->v + part->h - 1) << 4) + 8;
        }
        p++;
        p = (Qword *)func_001FBBB0((Quad32 *)p, x0, y1);
        p = (Qword *)func_001FBB48((Quad32 *)p, c1);
        if (w == 0) {
            p->ui32[0] = ((part->u + part->w) << 4) + 8;
        } else {
            p->ui32[0] = ((part->u + part->w - 1) << 4) + 8;
        }
        if (h == 0) {
            p->ui32[1] = ((part->v + part->h) << 4) + 8;
        } else {
            p->ui32[1] = ((part->v + part->h - 1) << 4) + 8;
        }
        p++;
        p = (Qword *)func_001FBBB0((Quad32 *)p, x1, y1);
    }
    return p;
}

void *func_001FE170(void *list, int b, int c, int d)
{
    return func_001FDDD8(list, b, c, d, 0, 0, 0x80808080, 0x80808080);
}

void *func_001FE1A0(void *list, int b, int c, int d, u32 e, u32 f)
{
    return func_001FDDD8(list, b, c, d, 0, 0, e, f);
}

void *func_001FE1C8(void *list, int b, int c, int d, int e, int f, u32 g, u32 h)
{
    return func_001FDDD8(list, b, c, d, e, f, g, h);
}

void TOMkpShapeXY(int a, int b, int c)
{
    InvokedFromSelectCursor = func_001FDDD8(InvokedFromSelectCursor, a, b, c, 0, 0, 0x80808080, 0x80808080);
    func_001EFA30();
}

void func_001FE240(int a, int b, int c, int d, int e)
{
    InvokedFromSelectCursor = func_001FDDD8(InvokedFromSelectCursor, a, b, c, 0, 0, d, e);
    func_001EFA30();
}

void func_001FE298(int a, int b, int c, int d, int e, int f, int g)
{
    InvokedFromSelectCursor = func_001FDDD8(InvokedFromSelectCursor, a, b, c, d, e, f, g);
    func_001EFA30();
}

extern u32 D_003241CC;
extern u32 D_003241D0;
extern u32 D_003241D4;

Qword *func_001FE2F8(Qword *p, int mode, int x, int y)
{
    u32 col = D_003241CC;
    int r = col & 0xFF;
    int g = (col >> 8) & 0xFF;
    int b = (col >> 16) & 0xFF;
    int a = col >> 24;
    int id;
    u32 *hdr;
    ShapePart12 *part;
    u32 i;

    if (mode == 0) {
        id = 8;
    }
    if (mode == 1) {
        id = 9;
    }
    hdr = (u32 *)func_001FD6F0(id);
    p->ul64[0] = 0x3000000000000001UL;
    p->ul64[1] = 0xEEE;
    p++;
    p->ul64[0] = 0x8000000044UL;
    p->ul64[1] = 0x42;
    p++;
    p->ul64[0] = 0xF;
    p->ul64[1] = 0x47;
    p++;
    p->ul64[0] = 0x2005D40621313E00UL;
    p->ul64[1] = 6;
    p++;
    part = (ShapePart12 *)(hdr + 1);
    for (i = 0; i < *hdr; i++, part++) {
        Quad32 *q;

        p->ul64[0] = 0x60AB400000008001UL;
        p->ul64[1] = 0x431431;
        p++;
        if (i == 0) {
            q = func_001FBB30((Quad32 *)p, r, g, b, a);
            q = func_001FBAF0(q, part->u, part->v);
            q = func_001FBBE0(q, x + part->dx, y + part->dy, 1);
            q = func_001FBB30(q, r, g, b, a);
            q = func_001FBAF0(q, part->u + (part->w - 1), part->v + (part->h - 1));
            p = (Qword *)func_001FBBE0(q, x + part->dx + part->w, y + part->dy + part->h, 1);
        } else {
            q = func_001FBB30((Quad32 *)p, 0x80, 0x80, 0x80, 0x80);
            q = func_001FBAF0(q, part->u, part->v);
            q = func_001FBBE0(q, x + part->dx, y + part->dy, 1);
            q = func_001FBB30(q, 0x80, 0x80, 0x80, 0x80);
            q = func_001FBAF0(q, part->u + (part->w - 1), part->v + (part->h - 1));
            p = (Qword *)func_001FBBE0(q, x + part->dx + part->w, y + part->dy + part->h, 1);
        }
    }
    return p;
}

CmdRec *func_001FE578(CmdRec *p_in, int mode, int x, int y)
{
    Qword *p = (Qword *)p_in; /* DEBT(CAST): CmdRec and Qword are both 16-byte GIF packet entries */
    u32 col = D_003241CC;
    int r = col & 0xFF;
    int g = (col >> 8) & 0xFF;
    int b = (col >> 16) & 0xFF;
    int a = col >> 24;
    int id;
    u32 *hdr;
    ShapePart12 *part;
    u32 i;

    if (mode == 0) {
        id = 0x2D;
    }
    if (mode == 1) {
        id = 9;
    }
    hdr = (u32 *)func_001FD6F0(id);
    p->ul64[0] = 0x3000000000000001UL;
    p->ul64[1] = 0xEEE;
    p++;
    p->ul64[0] = 0x8000000044UL;
    p->ul64[1] = 0x42;
    p++;
    p->ul64[0] = 0xF;
    p->ul64[1] = 0x47;
    p++;
    p->ul64[0] = 0x2005D40621313E00UL;
    p->ul64[1] = 6;
    p++;
    part = (ShapePart12 *)(hdr + 1);
    for (i = 0; i < *hdr; i++, part++) {
        Quad32 *q;

        p->ul64[0] = 0x60AB400000008001UL;
        p->ul64[1] = 0x431431;
        p++;
        if (i == 0) {
            q = func_001FBB30((Quad32 *)p, r, g, b, a);
            q = func_001FBAF0(q, part->u, part->v);
            q = func_001FBBE0(q, x + part->dx, y + part->dy, 1);
            q = func_001FBB30(q, r, g, b, a);
            q = func_001FBAF0(q, part->u + (part->w - 1), part->v + (part->h - 1));
            p = (Qword *)func_001FBBE0(q, x + part->dx + part->w, y + part->dy + part->h, 1);
        } else {
            q = func_001FBB30((Quad32 *)p, 0x80, 0x80, 0x80, 0x80);
            q = func_001FBAF0(q, part->u, part->v);
            q = func_001FBBE0(q, x + part->dx, y + part->dy, 1);
            q = func_001FBB30(q, 0x80, 0x80, 0x80, 0x80);
            q = func_001FBAF0(q, part->u + (part->w - 1), part->v + (part->h - 1));
            p = (Qword *)func_001FBBE0(q, x + part->dx + part->w, y + part->dy + part->h, 1);
        }
    }
    return (CmdRec *)p;
}

void func_001FE7F8(int mode, int x, int y)
{
    int r, g, b, a;
    int id;
    int flag;
    u32 *hdr;
    ShapePart12 *part;
    u32 i;

    if (mode == 0) {
        id = 0x2D;
        r = D_003241CC & 0xFF;
        g = (D_003241CC >> 8) & 0xFF;
        b = (D_003241CC >> 16) & 0xFF;
        a = D_003241CC >> 24;
        flag = 0;
    }
    if (mode == 4) {
        id = 8;
        if (x < 0x22) {
            x = 0x22;
        }
        if (y < 9) {
            y = 9;
        }
        if (x > 0x200) {
            x = 0x200;
        }
        if (y > 0x197) {
            y = 0x197;
        }
        r = D_003241D0 & 0xFF;
        g = (D_003241D0 >> 8) & 0xFF;
        b = (D_003241D0 >> 16) & 0xFF;
        a = D_003241D0 >> 24;
        flag = 0;
    }
    if (mode == 5) {
        id = 9;
        if (x < 0) {
            x = 0;
        }
        if (y < 9) {
            y = 9;
        }
        if (x > 0x200) {
            x = 0x1DE;
        }
        if (y > 0x197) {
            y = 0x197;
        }
        r = D_003241D4 & 0xFF;
        g = (D_003241D4 >> 8) & 0xFF;
        b = (D_003241D4 >> 16) & 0xFF;
        a = D_003241D4 >> 24;
        flag = 0;
    }
    hdr = (u32 *)func_001FD6F0(id);
    TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    GIF_CUR()->ul64[0] = 0x3000000000000001UL;
    GIF_CUR()->ul64[1] = 0xEEE;
    GIF_NEXT();
    GIF_AD(0x8000000044UL, 0x42);
    GIF_AD(0xF, 0x47);
    GIF_AD(0x2005D40621313E00UL, 6);
    part = (ShapePart12 *)(hdr + 1);
    for (i = 0; i < *hdr; i++, part++) {
        GIF_CUR()->ul64[0] = 0x60AB400000008001UL;
        GIF_CUR()->ul64[1] = 0x431431;
        GIF_NEXT();
        if (flag == 1) {
            if (i == 0) {
                locNameTmpSetLanguage(r, g, b, a);
                func_001FB550(part->u, part->v);
                func_001FB770(x + (part->dx << 4), y + (part->dy << 4), 1);
                locNameTmpSetLanguage(r, g, b, a);
                func_001FB550(part->u + (part->w - 1), part->v + (part->h - 1));
                func_001FB770(x + (part->dx << 4) + (part->w << 4), y + (part->dy << 4) + (part->h << 4), 1);
            } else {
                locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
                func_001FB550(part->u, part->v);
                func_001FB770(x + (part->dx << 4), y + (part->dy << 4), 1);
                locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
                func_001FB550(part->u + (part->w - 1), part->v + (part->h - 1));
                func_001FB770(x + (part->dx << 4) + (part->w << 4), y + (part->dy << 4) + (part->h << 4), 1);
            }
        } else {
            if (i == 0) {
                locNameTmpSetLanguage(r, g, b, a);
                func_001FB550(part->u, part->v);
                func_001FB6B0(x + part->dx, y + part->dy, 1);
                locNameTmpSetLanguage(r, g, b, a);
                func_001FB550(part->u + (part->w - 1), part->v + (part->h - 1));
                func_001FB6B0(x + part->dx + part->w, y + part->dy + part->h, 1);
            } else {
                locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
                func_001FB550(part->u, part->v);
                func_001FB6B0(x + part->dx, y + part->dy, 1);
                locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
                func_001FB550(part->u + (part->w - 1), part->v + (part->h - 1));
                func_001FB6B0(x + part->dx + part->w, y + part->dy + part->h, 1);
            }
        }
    }
    func_001EFA30();
}

void func_001FEE30(int a, int b, int c);

void func_001FECB8(int a, int x, int y)
{
    int r;

    GIF_CUR()->ul64[0] = 0x3000000000000001UL;
    GIF_CUR()->ul64[1] = 0xEEE;
    GIF_NEXT();
    GIF_AD(0x8000000044UL, 0x42);
    GIF_AD(0xF, 0x47);
    if (a < 0xC8) {
        GIF_AD(0x2005D40621313E00UL, 6);
        r = func_001FD6F0(a);
    }
    if ((u32)(a - 0xC8) < 0xC8) {
        GIF_AD(0x2005D40621313E00UL, 6);
        r = func_001FD6F0(a - 0xC8);
    }
    if (a >= 0x190) {
        GIF_AD(0x2005D48621313F00UL, 6);
        r = func_001FD718(a - 0x190);
    }
    func_001FEE30(r, x, y);
}

void func_001FEE30(int a, int x, int y)
{
    u32 *hdr = (u32 *)a;
    ShapePart12 *part = (ShapePart12 *)(hdr + 1);
    u32 i;
    int x0, x1, y0, y1;

    for (i = 0; i < *hdr; i++, part++) {
        GIF_CUR()->ul64[0] = 0x60AB400000008001UL;
        GIF_CUR()->ul64[1] = 0x431431;
        GIF_NEXT();
        if (part->flipX == 1) {
            x1 = (part->dx << 4) + x;
            x0 = ((part->dx + part->w) << 4) + x;
        } else {
            x0 = (part->dx << 4) + x;
            x1 = ((part->dx + part->w) << 4) + x;
        }
        if (part->flipY == 1) {
            y1 = (part->dy << 4) + y;
            y0 = ((part->dy + part->h) << 4) + y;
        } else {
            y0 = (part->dy << 4) + y;
            y1 = ((part->dy + part->h) << 4) + y;
        }
        locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
        func_001FB550(part->u, part->v);
        GIF_CUR()->ui32[0] = x0;
        GIF_CUR()->ui32[1] = y0;
        GIF_CUR()->ui32[2] = 0x10;
        GIF_CUR()->ui32[3] = 0;
        GIF_NEXT();
        locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
        func_001FB550(part->u + (part->w - 1), part->v + (part->h - 1));
        GIF_CUR()->ui32[0] = x1;
        GIF_CUR()->ui32[1] = y1;
        GIF_CUR()->ui32[2] = 0x10;
        GIF_CUR()->ui32[3] = 0;
        GIF_NEXT();
    }
    func_001EFA30();
}

/* draw texture a, then texture b stretched to fill the rest of width w */
void *func_001FF020(void *list, int a, int b, int x, int y, int w, u32 c0, u32 c1)
{
    TexRect *t = TEX_RECT(a);

    list = func_001FDDD8(list, a, x, y, 0, 0, c0, c0);
    return func_001FDDD8(list, b, x + t->w, y, w - t->w, 0, c0, c1);
}

/* draw texture a stretched to width w minus texture b, then b at the right end */
void *func_001FF0F8(void *list, int a, int b, int x, int y, int w, u32 c0, u32 c1)
{
    TexRect *t = TEX_RECT(b);

    list = func_001FDDD8(list, a, x, y, w - t->w, 0, c0, c1);
    return func_001FDDD8(list, b, x + w - t->w, y, 0, 0, c1, c1);
}

void func_001FF1D8(int a, int b, int x, int y, int w, u32 c0, u32 c1)
{
    TexRect *t = TEX_RECT(a);

    InvokedFromSelectCursor = func_001FDDD8(InvokedFromSelectCursor, a, x, y, 0, 0, c0, c0);
    InvokedFromSelectCursor = func_001FDDD8(InvokedFromSelectCursor, b, x + t->w, y, w - t->w, 0, c0, c1);
}

void TODrawMenuPlateXYWC2_Rfix(int a, int b, int x, int y, int w, u32 c0, u32 c1)
{
    TexRect *t = TEX_RECT(b);

    InvokedFromSelectCursor = func_001FDDD8(InvokedFromSelectCursor, a, x, y, w - t->w, 0, c0, c1);
    InvokedFromSelectCursor = func_001FDDD8(InvokedFromSelectCursor, b, x + w - t->w, y, 0, 0, c1, c1);
}

void func_001FF398(int x, int y, int w, int h, int c0, int c1)
{
    GIF_CUR()->ul64[0] = 0x3000000000000001UL;
    GIF_CUR()->ul64[1] = 0xEEE;
    GIF_NEXT();
    GIF_AD(0x8000000044UL, 0x42);
    GIF_AD(0xF, 0x47);
    GIF_AD(0x2005D40621313E00UL, 6);
    GIF_CUR()->ul64[0] = 0x80A6400000008001UL;
    GIF_CUR()->ul64[1] = 0x41414141;
    GIF_NEXT();
    func_001FB618(c0);
    func_001FB678(x, y);
    func_001FB618(c1);
    func_001FB678(x + w, y);
    func_001FB618(c0);
    func_001FB678(x, y + h);
    func_001FB618(c1);
    func_001FB678(x + w, y + h);
    func_001EFA30();
}

typedef struct TexRect8 {
    u8 u;
    u8 v;
    u16 pad;
    u16 w;
    u16 h;
} TexRect8;

void func_001FF500(int x, int y, int w, int h, u32 c0, u32 c1)
{
    void *p[2];
    TexRect8 *t[2];

    p[0] = (void *)func_001FD6F0(4);
    t[0] = (TexRect8 *)((u8 *)p[0] + 4);
    p[1] = (void *)func_001FD6F0(5);
    t[1] = (TexRect8 *)((u8 *)p[1] + 4);
    GIF_CUR()->ul64[0] = 0x3000000000000001UL;
    GIF_CUR()->ul64[1] = 0xEEE;
    GIF_NEXT();
    GIF_AD(0x8000000044UL, 0x42);
    GIF_AD(0xF, 0x47);
    GIF_AD(0x2005D40621313E00UL, 6);
    GIF_CUR()->ul64[0] = 0xC0AE400000000001UL;
    GIF_CUR()->ul64[1] = 0x431431431431UL;
    GIF_NEXT();
    func_001FB618(c0);
    func_001FB550(t[0]->u, t[0]->v);
    func_001FB678(x, y);
    func_001FB618(c1);
    func_001FB550(t[0]->u + t[0]->w, t[0]->v);
    func_001FB678(x + (w - t[1]->w), y);
    func_001FB618(c0);
    func_001FB550(t[0]->u, t[0]->v + t[0]->h);
    func_001FB678(x, y + t[0]->h);
    func_001FB618(c1);
    func_001FB550(t[0]->u + t[0]->w, t[0]->v + t[0]->h);
    func_001FB678(x + (w - t[1]->w), y + t[0]->h);
    x += w - t[1]->w;
    GIF_CUR()->ul64[0] = 0xC0AE400000008001UL;
    GIF_CUR()->ul64[1] = 0x431431431431UL;
    GIF_NEXT();
    func_001FB618(c1);
    func_001FB550(t[1]->u, t[1]->v);
    func_001FB678(x, y);
    func_001FB618(c1);
    func_001FB550(t[1]->u + t[1]->w, t[1]->v);
    func_001FB678(x + t[1]->w, y);
    func_001FB618(c1);
    func_001FB550(t[1]->u, t[1]->v + t[1]->h);
    func_001FB678(x, y + t[1]->h);
    func_001FB618(c1);
    func_001FB550(t[1]->u + t[1]->w, t[1]->v + t[1]->h);
    func_001FB678(x + t[1]->w, y + t[1]->h);
    func_001EFA30();
}

void func_001FF828(int x, int y)
{
    GIF_CUR()->ul64[0] = 0x1000000000000004UL;
    GIF_CUR()->ul64[1] = 0xE;
    GIF_NEXT();
    GIF_AD(GS_SET_SCISSOR(0, 0x1FF, 0, 0x19F), 0x40);
    GIF_AD(0x4005D48621313F00UL, 6);
    GIF_AD(0x8000000044UL, 0x42);
    GIF_AD(0xF, 0x47);
    GIF_CUR()->ul64[0] = 0x30AE400000008004UL;
    GIF_CUR()->ul64[1] = 0x431;
    GIF_NEXT();
    locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
    func_001FB550(0, 0);
    func_001FB678(x, y);
    locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
    func_001FB550(0xB2, 0);
    func_001FB678(x + 0xB2, y);
    locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
    func_001FB550(0, 0x41);
    func_001FB678(x, y + 0x41);
    locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
    func_001FB550(0xB2, 0x41);
    func_001FB678(x + 0xB2, y + 0x41);
    func_001EFA30();
}

void func_001FF9F0(int x, int y, int a)
{
    GIF_CUR()->ul64[0] = 0x1000000000000004UL;
    GIF_CUR()->ul64[1] = 0xE;
    GIF_NEXT();
    GIF_AD(GS_SET_SCISSOR(0, 0x1FF, 0, 0x19F), 0x40);
    GIF_AD(0x4005D48621313F00UL, 6);
    GIF_AD(0x8000000044UL, 0x42);
    GIF_AD(0xF, 0x47);
    GIF_CUR()->ul64[0] = 0x30AE400000008004UL;
    GIF_CUR()->ul64[1] = 0x431;
    GIF_NEXT();
    locNameTmpSetLanguage(0x80, 0x80, 0x80, a);
    func_001FB550(0, 0);
    func_001FB678(x, y);
    locNameTmpSetLanguage(0x80, 0x80, 0x80, a);
    func_001FB550(0xB2, 0);
    func_001FB678(x + 0xB2, y);
    locNameTmpSetLanguage(0x80, 0x80, 0x80, a);
    func_001FB550(0, 0x41);
    func_001FB678(x, y + 0x41);
    locNameTmpSetLanguage(0x80, 0x80, 0x80, a);
    func_001FB550(0xB2, 0x41);
    func_001FB678(x + 0xB2, y + 0x41);
    func_001EFA30();
}

void func_001FFBC8(int x, int y, int scale, int alpha)
{
    float fx, fy, x0, y0, x1, y1, dw, dh;

    GIF_CUR()->ul64[0] = 0x1000000000000004UL;
    GIF_CUR()->ul64[1] = 0xE;
    GIF_NEXT();
    GIF_AD(GS_SET_SCISSOR(0, 0x1FF, 0, 0x19F), 0x40);
    GIF_AD(0x4005D48621313F00UL, 6);
    GIF_AD(0x8000000044UL, 0x42);
    GIF_AD(0xF, 0x47);
    fx = x;
    fy = y;
    dw = ((scale * 0xB2) / 100) * 0.5f;
    dh = ((scale * 0x41) / 100) * 0.5f;
    x0 = fx - dw;
    x1 = fx + dw;
    y0 = fy - dh;
    y1 = fy + dh;
    GIF_CUR()->ul64[0] = 0x50AF400000008001UL;
    GIF_CUR()->ul64[1] = 0x43431;
    GIF_NEXT();
    locNameTmpSetLanguage(0x80, 0x80, 0x80, alpha);
    func_001FB550(0, 0);
    func_001FB678((int)x0, (int)y0);
    func_001FB550(0xB2, 0x41);
    func_001FB678((int)x1, (int)y1);
    func_001EFA30();
}

void func_001FFDA0(void)
{
    TOTransImageHL(0x1CC0000, 0x3100, 0x13, 0, 0, 0x100, 0x80);
}

void func_001FFDC0(void)
{
    TOTransImageHL(0x1C80000, 0x3A00, 0x13, 0, 0, 0x200, 0x100);
}

void func_001FFDE0(void)
{
    TOTransImageHL(0x1CA0000, 0x3800, 0x13, 0, 0, 0x200, 0x100);
}

void func_001FFE00(int a, int b, int c)
{
    InvokedFromSelectCursor = func_001FFE50(InvokedFromSelectCursor, a, b, c, 0x80, 0x80, 0x80, 0x80);
}

void *func_001FFE50(void *list, int a, int b, int c, int d, int e, int f, int g)
{
    GsAdPacket *p = list;
    int v, u;

    if ((u32)a >= 8) {
        return p;
    }
    p->data = 0x1000000000000002UL;
    p->reg = 0xE;
    p = func_001FB980(p + 1, 1, 7, 0, 0, 0, 0, 0, 0);
    p = func_001FB9D0(p, 0x3100, 4, 0x13, 8, 7, 1, 0, 0x2ED8, 0, 0, 0, 2);
    p->data = 0x508F400000008001UL;
    p->reg = 0x43431;
    p = (GsAdPacket *)func_001FBB30((Quad32 *)(p + 1), d, e, f, g);
    v = (a / 4) * 64;
    u = (a % 4) * 64;
    p = (GsAdPacket *)func_001FBAF0((Quad32 *)p, u, v);
    p = (GsAdPacket *)func_001FBBB0((Quad32 *)p, b, c);
    p = (GsAdPacket *)func_001FBAF0((Quad32 *)p, u + 64, v + 64);
    return func_001FBBB0((Quad32 *)p, b + 64, c + 64);
}

void func_001FFFF0(int a, int b, int c)
{
    InvokedFromSelectCursor = func_00200040(InvokedFromSelectCursor, a, b, c, 0x80, 0x80, 0x80, 0x80);
}

extern u8 func_0014ABB0(void);

void *func_00200040(void *list, int id, int x, int y, int r, int g, int b, int a)
{
    GsAdPacket *p = list;
    int u, v;

    if ((u32)id >= 0x12) {
        return p;
    }
    p->data = 0x70AF400000008001UL;
    p->reg = 0x43431EE;
    p++;
    p->data = 0xF;
    p->reg = 0x47;
    p++;
    if ((u32)id < 7) {
        p = func_001FB9D0(p, 0x3A00, 8, 0x13, 9, 8, 1, 0, 0x2ED0, 0, 0, 0, 2);
        if (id == 6 && func_0014ABB0() == 1) {
            id = 7;
        }
        p = (GsAdPacket *)func_001FBB30((Quad32 *)p, r, g, b, a);
        u = (id % 4) * 0x5B;
        v = (id / 4) * 0x62;
        p = (GsAdPacket *)func_001FBAF0((Quad32 *)p, u, v);
        p = (GsAdPacket *)func_001FBBB0((Quad32 *)p, x, y);
        p = (GsAdPacket *)func_001FBAF0((Quad32 *)p, u + 0x5B, v + 0x62);
        p = (GsAdPacket *)func_001FBBB0((Quad32 *)p, x + 0x5B, y + 0x62);
    } else {
        p = func_001FB9D0(p, 0x3800, 8, 0x13, 9, 8, 1, 0, 0x2ED4, 0, 0, 0, 2);
        id -= 8;
        p = (GsAdPacket *)func_001FBB30((Quad32 *)p, r, g, b, a);
        p = (GsAdPacket *)func_001FBAF0((Quad32 *)p, (id % 5) * 0x5B, (id / 5) * 0x62);
        p = (GsAdPacket *)func_001FBBB0((Quad32 *)p, x, y);
        p = (GsAdPacket *)func_001FBAF0((Quad32 *)p, (id % 5) * 0x5B + 0x5B, (id / 5) * 0x62 + 0x62);
        p = (GsAdPacket *)func_001FBBB0((Quad32 *)p, x + 0x5B, y + 0x62);
    }
    return p;
}

void func_002002D0(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_00200318(InvokedFromSelectCursor, a, b, c, d);
}

void *func_00200318(void *list, int a, int b, int c, int d)
{
    GsAdPacket *p = list;

    p[0].data = 0xF0AE400000008001UL;
    p[0].reg = 0x431431431431EEEUL;
    p[1].data = 0x8000000044UL;
    p[1].reg = 0x42;
    p[2].data = 0x70000;
    p[2].reg = 0x47;
    p = func_001FB9D0(p + 3, 0x3800, 8, 0x13, 9, 9, 1, 0, 0x2EAC, 0, 0, 0, 2);
    p = (GsAdPacket *)func_001FBB48((Quad32 *)p, c);
    p = (GsAdPacket *)func_001FBAF0((Quad32 *)p, 0, 0);
    p = (GsAdPacket *)func_001FBC10((Quad32 *)p, a, b, 0x400, 0xC8);
    p = (GsAdPacket *)func_001FBB48((Quad32 *)p, d);
    p = (GsAdPacket *)func_001FBAF0((Quad32 *)p, 0x200, 0);
    p = (GsAdPacket *)func_001FBC10((Quad32 *)p, a + 0x200, b, 0x400, 0xC8);
    p = (GsAdPacket *)func_001FBB48((Quad32 *)p, c);
    p = (GsAdPacket *)func_001FBAF0((Quad32 *)p, 0, 0x200);
    p = (GsAdPacket *)func_001FBBE0((Quad32 *)p, a, b + 0x200, 0x400);
    p = (GsAdPacket *)func_001FBB48((Quad32 *)p, d);
    p = (GsAdPacket *)func_001FBAF0((Quad32 *)p, 0x200, 0x1A0);
    return func_001FBBE0((Quad32 *)p, a + 0x200, b + 0x1A0, 0x400);
}
