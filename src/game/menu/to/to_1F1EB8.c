/* tu_218 0x1f1eb8-0x1f3280: low; ~To (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r4.h"
#include "ffx/v4.h"
#include "ffx/q5.h"

void func_001F1EB8(void)
{
    GIF_AD_TAG(5);
    GIF_AD(0, 0x3F);
    GIF_AD(0x8000000044UL, 0x42);
    GIF_AD(0xF, 0x47);
    GIF_AD(0x60, 0x14);
    GIF_AD(5, 8);
    func_001EFA30();
}

void func_001F1F60(TextItem *it, R4CharInfo *ci)
{
    func_001F2140(it, ci);
    func_001F1FD8(it, ci);
    if ((ci->h16 & 1) || (ci->h16 & 2)) {
        func_001F22B8(it, ci);
    }
    it->x += ci->h10 + 1;
}

void func_001F1FD8(TextItem *it, R4CharInfo *ci)
{
    GIF_CUR()->ul64[0] = 0x90AB400000008001UL;
    GIF_CUR()->ul64[1] = 0x43431EEEEUL;
    GIF_NEXT();
    GIF_AD(0x8000000044UL, 0x42);
    GIF_AD(0x3000F, 0x47);
    GIF_AD(0x2005D705A1313D80UL, 6);
    GIF_AD(((u64)ci->h2 << 20) | ((u64)0x2EB8 << 37) | ((u64)((it->f13 & 0xF) * 2 + ci->h4) << 56), 0x16);
    locNameTmpSetLanguage(it->col[0], it->col[1], it->col[2], it->col[3]);
    func_001FB550(ci->h6, ci->h8);
    func_001FB678(it->x, it->y);
    func_001FB550(ci->hA, ci->hC);
    func_001FB678(it->x + ci->h10, it->y + ci->h12);
    func_001EFA30();
}

void func_001F2140(TextItem *it, R4CharInfo *ci)
{
    GIF_CUR()->ul64[0] = 0x90AB400000008001UL;
    GIF_CUR()->ul64[1] = 0x43431EEEEUL;
    GIF_NEXT();
    GIF_AD(0x8000000044UL, 0x42);
    GIF_AD(0x3000F, 0x47);
    GIF_AD(0x4005D785A1313D80UL, 6);
    GIF_AD(((u64)((it->f13 >> 4) * 2 + ci->h4) << 56) | 0x5D785A1413D80UL, 6);
    locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
    func_001FB550(ci->h6, ci->h8);
    func_001FB678(it->x + 2, it->y + 1);
    func_001FB550(ci->hA, ci->hC);
    func_001FB678(it->x + ci->h10 + 2, it->y + ci->h12 + 1);
    func_001EFA30();
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F1EB8", func_001F22B8);

void func_001F23E8(void)
{
    GIF_AD_TAG(6);
    GIF_AD(0, 0x3F);
    GIF_AD(0xF, 0x47);
    GIF_AD(0x8000000044UL, 0x42);
    GIF_AD(0x2005D40621313E00UL, 6);
    GIF_AD(0x60, 0x14);
    GIF_AD(0, 8);
    func_001EFA30();
}

void func_001F24B8(int a, int b, int c)
{
    TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    if (c == 0) {
        TOMkpShapeXY(0x2D, a, b);
    }
    func_001EFA30();
}

void func_001F2520(int sbp, int dbp, int psm)
{
    GIF_CUR()->ul64[0] = 0x4000000000008001UL;
    GIF_CUR()->ul64[1] = 0xEEEE;
    GIF_NEXT();
    GIF_AD(GS_SET_BITBLTBUF(sbp, 8, psm, dbp, 8, psm), 0x50);
    GIF_AD(0, 0x51);
    GIF_AD(0xE000000200UL, 0x52);
    GIF_AD(2, 0x53);
    func_001EFA30();
}

void func_001F25D8(R4Quad *q, int x, int y, int w, int h)
{
    q->x[0] = q->x[2] = x;
    q->x[1] = q->x[3] = x + w;
    q->y[0] = q->y[1] = y;
    q->y[2] = q->y[3] = y + h;
}

void func_001F2608(R4Quad *q, int x0, int y0, int x1, int y1)
{
    q->x[0] = q->x[2] = x0;
    q->x[1] = q->x[3] = x1;
    q->y[0] = q->y[1] = y0;
    q->y[2] = q->y[3] = y1;
}

void func_001F2630(R4Quad *q, u32 i, u8 r, u8 g, u8 b, u8 a)
{
    if (i < 4) {
        q->r[i] = r;
        q->g[i] = g;
        q->b[i] = b;
        q->a[i] = a;
    } else {
        q->r[0] = q->r[1] = q->r[2] = q->r[3] = r;
        q->g[0] = q->g[1] = q->g[2] = q->g[3] = g;
        q->b[0] = q->b[1] = q->b[2] = q->b[3] = b;
        q->a[0] = q->a[1] = q->a[2] = q->a[3] = a;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F1EB8", func_001F26B0);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F1EB8", func_001F2840);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F1EB8", func_001F2A98);

void ToMakeBtlEasyEdgeFontChrName(int x0, int y0, int x1, int y1, u32 c0, u32 c1)
{
    int r0 = c0 & 0xFF;
    int g0 = (c0 >> 8) & 0xFF;
    int b0 = (c0 >> 16) & 0xFF;
    int a0 = c0 >> 24;
    int r1 = c1 & 0xFF;
    int g1 = (c1 >> 8) & 0xFF;
    int b1 = (c1 >> 16) & 0xFF;
    int a1 = c1 >> 24;

    GIF_CUR()->ul64[0] = 0x6024C00000008001UL;
    GIF_CUR()->ul64[1] = 0x4141EE;
    GIF_NEXT();
    GIF_AD(0x8000000044UL, 0x42);
    GIF_AD(0xF, 0x47);
    locNameTmpSetLanguage(r0, g0, b0, a0);
    func_001FB6B0(x0, y0, 1);
    locNameTmpSetLanguage(r1, g1, b1, a1);
    func_001FB6B0(x1, y1, 1);
    func_001EFA30();
}

void func_001F2E60(int x0, int y0, int x1, int y1, int z)
{
    GIF_CUR()->ul64[0] = 0x6020C00000008001UL;
    GIF_CUR()->ul64[1] = 0x4141EE;
    GIF_NEXT();
    GIF_AD(0x8000000044UL, 0x42);
    GIF_AD(0x32001, 0x47);
    locNameTmpSetLanguage(0, 0, 0, 0);
    func_001FB6B0(x0, y0, z);
    locNameTmpSetLanguage(0, 0, 0, 0);
    func_001FB6B0(x1, y1, z);
    func_001EFA30();
}

void func_001F2F68(void)
{
    InvokedFromSelectCursor = func_001F6EC8(InvokedFromSelectCursor);
    func_001EFA30();
}

void func_001F2F98(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F6F88(InvokedFromSelectCursor, a, b, c, d);
    func_001EFA30();
}

void func_001F2FE0(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F8258(InvokedFromSelectCursor, a, b, c, d);
    func_001EFA30();
}

void func_001F3028(u8 *s, int b, int c)
{
    InvokedFromSelectCursor = func_001F9D50(InvokedFromSelectCursor, s[1] - 0x34, b, c);
    func_001EFA30();
}

void func_001F3068(int a, int b, u8 c)
{
    InvokedFromSelectCursor = TOAddPktMenuIcon(InvokedFromSelectCursor, a, b, c);
    func_001EFA30();
}

void func_001F30A8(int a, int b, int c)
{
    InvokedFromSelectCursor = func_001F9938(InvokedFromSelectCursor, a, b, c);
    func_001EFA30();
}

void func_001F30E8(int a, int b, int c, u8 d)
{
    InvokedFromSelectCursor = func_001F9B48(InvokedFromSelectCursor, a, b, c, 0x80, 0x80, 0x80, d);
    func_001EFA30();
}

void func_001F3140(int a, int b, int c, u8 d, u8 e, u8 f, u8 g)
{
    InvokedFromSelectCursor = func_001F9960(InvokedFromSelectCursor, a, b, c, d, e, f, g);
    func_001EFA30();
}

void func_001F31A0(int a, int b, int c)
{
    InvokedFromSelectCursor = func_001F9D50(InvokedFromSelectCursor, a, b, c);
    func_001EFA30();
}

void func_001F31E0(int a, int b, int c, u8 d)
{
    InvokedFromSelectCursor = func_001F9200(InvokedFromSelectCursor, a, b, c, 0x80, 0x80, 0x80, d);
    func_001EFA30();
}

void func_001F3238(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F7378(InvokedFromSelectCursor, a, b, c, d);
    func_001EFA30();
}
