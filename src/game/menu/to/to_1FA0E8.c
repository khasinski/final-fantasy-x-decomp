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

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_001FA988);

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

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_001FBE20);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_001FBFB8);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_001FC1F0);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_001FC3C8);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_001FC770);

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

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_001FD260);

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

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", TOMkpShapePartIndexXYWHC2);

void func_001FDD78(int a, int b, int c, int d, int e, int f, int g)
{
    InvokedFromSelectCursor = TOMkpShapePartIndexXYWHC2(InvokedFromSelectCursor, a, b, c, d, e, f, g);
    func_001EFA30();
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_001FDDD8);

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

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_001FE2F8);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_001FE578);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_001FE7F8);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_001FECB8);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_001FEE30);

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

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_001FF398);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_001FF500);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_001FF828);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_001FF9F0);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_001FFBC8);

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

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_001FFE50);

void func_001FFFF0(int a, int b, int c)
{
    InvokedFromSelectCursor = func_00200040(InvokedFromSelectCursor, a, b, c, 0x80, 0x80, 0x80, 0x80);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_00200040);

void func_002002D0(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_00200318(InvokedFromSelectCursor, a, b, c, d);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1FA0E8", func_00200318);
