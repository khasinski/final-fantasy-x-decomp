/* tu_222 0x1f8418-0x1fa0e8: medium; ~TOAddPktMenuIcon (config/tu_map.tsv) */
#include "common.h"
#define func_001F8418 _proto_func_001F8418
#define func_001F85D0 _proto_func_001F85D0
#define func_001F9378 _proto_func_001F9378
#define func_001F9B48 _proto_func_001F9B48
#define func_001F9D78 _proto_func_001F9D78
#define TOAddPktMenuIconRGBA _proto_TOAddPktMenuIconRGBA
#include "ffx/q5.h"
#include "ffx/r4.h"
#undef func_001F8418
#undef func_001F85D0
#undef func_001F9378
#undef func_001F9B48
#undef func_001F9D78
#undef TOAddPktMenuIconRGBA
#include "ffx/u3.h"
#include "ffx/v4.h"
#include "ffx/t4.h"

void *func_001F9378(void *list, int x, int y, int w, u8 r, u8 g, u8 b, u8 a);
void *func_001F9548(void *list, int x, int y, int idx);
void *TOAddPktMenuIconRGBA(void *list, int x, int y, u8 icon, u8 r, u8 g, u8 b, u8 a);
void *func_001F9B48(void *list, int a, int b, int c, u8 d, u8 e, u8 f, u8 g);
void *func_001F9D78(void *list, int a, int b, int c, u8 d, u8 e, u8 f, u8 g);
extern void *InvokedFromSelectCursor;




void *func_001F8418(void *list, int a, int b, int c, u8 d, u8 e, u8 f, u8 g)
{
    InvokedFromSelectCursor = list;
    GIF_CUR()->ul64[0] = 0x80AF400000008001UL;
    GIF_CUR()->ul64[1] = 0x43431EEEUL;
    GIF_NEXT();
    func_001FB2C0(0, 1, 0, 1, 0x80);
    GIF_AD(0xF, 0x47);
    GIF_AD(0x4005D40621313E00UL, 6);
    locNameTmpSetLanguage(d, e, f, g);
    if (c == 0) {
        func_001FB550(0x40, 0);
        func_001FB678(a - 0x24, b);
        func_001FB550(0x62, 0x12);
        func_001FB678(a - 2, b + 0x12);
    }
    if (c == 1) {
        func_001FB550(0x62, 0);
        func_001FB678(a, b);
        func_001FB550(0x40, 0x12);
        func_001FB678(a + 0x22, b + 0x12);
    }
    return InvokedFromSelectCursor;
}

void *func_001F85A8(void *list, int a, int b, int c)
{
    return func_001F8418(list, a, b, c, 0x80, 0x80, 0x80, 0x80);
}

void *func_001F85D0(void *list, int a, int b, int c, u8 d, u8 e, u8 f, u8 g)
{
    InvokedFromSelectCursor = list;
    GIF_CUR()->ul64[0] = 0x3000000000000001UL;
    GIF_CUR()->ul64[1] = 0xEEE;
    GIF_NEXT();
    func_001FB2C0(0, 1, 0, 1, 0x80);
    GIF_AD(0xF, 0x47);
    GIF_AD(0x4005D40621313E00UL, 6);
    GIF_CUR()->ul64[0] = 0x50AF400000008003UL;
    GIF_CUR()->ul64[1] = 0x43431;
    GIF_NEXT();
    locNameTmpSetLanguage(d, e, f, g);
    func_001FB550(0x67, 0);
    func_001FB678(a - 0xE, b - 3);
    func_001FB550(0x75, 0x13);
    func_001FB678(a, b + 0x10);
    locNameTmpSetLanguage(d, e, f, g);
    func_001FB550(0x75, 0);
    func_001FB678(a, b - 3);
    func_001FB550(0x78, 0x13);
    func_001FB678(a + c, b + 0x10);
    locNameTmpSetLanguage(d, e, f, g);
    func_001FB550(0x79, 0);
    func_001FB678(a + c, b - 3);
    func_001FB550(0x85, 0x13);
    func_001FB678(a + c + 0xC, b + 0x10);
    return InvokedFromSelectCursor;
}

void *func_001F87D8(void *list, int a, int b, int c)
{
    return func_001F85D0(list, a, b, c, 0x80, 0x80, 0x80, 0x80);
}

void *func_001F8800(void *list, int x, int y)
{
    list = func_001F9548(list, x, y, 8);
    list = func_001F9548(list, x - 0x14, y + 3, 3);
    return func_001F9548(list, x - 0x10, y + 4, 2);
}

void *func_001F8860(void *list, int x, int y, int w, int h)
{
    w -= 0x16;
    h -= 9;
    InvokedFromSelectCursor = list;
    GIF_CUR()->ul64[0] = 0x1000000000000001UL;
    GIF_CUR()->ul64[1] = 0xE;
    GIF_NEXT();
    GIF_AD(0x4005D40621313E00UL, 6);
    GIF_CUR()->ul64[0] = 0x50AB400000008009UL;
    GIF_CUR()->ul64[1] = 0x43431;
    GIF_NEXT();

    locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
    func_001FB550(0xD8, 0x28);
    func_001FB678(x, y);
    func_001FB550(0xE3, 0x2C);
    func_001FB678(x + 0xB, y + 4);

    locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
    func_001FB550(0xE3, 0x28);
    func_001FB678(x + 0xB, y);
    func_001FB550(0xE6, 0x2C);
    func_001FB678(x + 0xB + w, y + 4);

    locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
    func_001FB550(0xE7, 0x28);
    func_001FB678(x + 0xB + w, y);
    func_001FB550(0xF2, 0x2C);
    func_001FB678(x + 0xB + w + 0xB, y + 4);

    locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
    func_001FB550(0xD8, 0x2C);
    func_001FB678(x, y + 4);
    func_001FB550(0xE3, 0x2F);
    func_001FB678(x + 0xB, y + 4 + h);

    locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
    func_001FB550(0xE3, 0x2C);
    func_001FB678(x + 0xB, y + 4);
    func_001FB550(0xE6, 0x2F);
    func_001FB678(x + 0xB + w, y + 4 + h);

    locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
    func_001FB550(0xE7, 0x2C);
    func_001FB678(x + 0xB + w, y + 4);
    func_001FB550(0xF2, 0x2F);
    func_001FB678(x + 0xB + w + 0xB, y + 4 + h);

    locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
    func_001FB550(0xD8, 0x30);
    func_001FB678(x, y + 4 + h);
    func_001FB550(0xE2, 0x35);
    func_001FB678(x + 0xB, y + 4 + h + 5);

    locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
    func_001FB550(0xE3, 0x30);
    func_001FB678(x + 0xB, y + 4 + h);
    func_001FB550(0xE6, 0x35);
    func_001FB678(x + 0xB + w, y + 4 + h + 5);

    locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
    func_001FB550(0xE7, 0x30);
    func_001FB678(x + 0xB + w, y + 4 + h);
    func_001FB550(0xF2, 0x35);
    func_001FB678(x + 0xB + w + 0xB, y + 4 + h + 5);

    return InvokedFromSelectCursor;
}

void *func_001F8BD8(void *list, int x, int y, int w)
{
    int ww;

    InvokedFromSelectCursor = list;
    GIF_CUR()->ul64[0] = 0x00AF400000008001UL;
    GIF_CUR()->ul64[1] = 0x434314343143431EUL;
    GIF_NEXT();
    GIF_AD(0x4005D40621313E00UL, 6);
    ww = w - 0xA;
    if (ww < 0) {
        ww = 0;
    }
    locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
    func_001FB550(0x90, 0x28);
    func_001FB678(x, y);
    func_001FB550(0x97, 0x36);
    func_001FB678(x + 7, y + 0xE);
    locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
    func_001FB550(0x97, 0x28);
    func_001FB678(x + 5, y);
    func_001FB550(0xC9, 0x36);
    func_001FB678(x + 7 + ww, y + 0xE);
    locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
    func_001FB550(0xCA, 0x28);
    func_001FB678(x + 5 + ww, y);
    func_001FB550(0xD1, 0x36);
    func_001FB678(x + 7 + ww + 7, y + 0xE);
    return InvokedFromSelectCursor;
}

void func_001F8D88(void *draw_list, s32 text_id, s32 x, s32 y, s32 style)
{
    int base;
    OfsTbl *table;
    int text;
    u16 offset;
    void *list;

    table = MsGetComData(text_id, &base);
    /* DEBT(CAST): read the packed pair of 16-bit offsets through its word view. */
    offset = (u16)*(u32 *)&table->a[0];
    InvokedFromSelectCursor = draw_list;
    text = base + offset;
    list = TOAddPktMenuIcon(draw_list, x + 3, y + 1, table->b14);
    InvokedFromSelectCursor = list;
    InvokedFromSelectCursor = func_001F41C0(list, text, x + 0x16, y, style);
}

void func_001F8E30(void *draw_list, s32 text_id, s32 x, s32 y, s32 style)
{
    int base;
    OfsTbl *table;
    int text;
    u16 offset;
    void *list;

    table = MsGetRomItem(text_id, &base);
    /* DEBT(CAST): read the packed pair of 16-bit offsets through its word view. */
    offset = (u16)*(u32 *)&table->a[0];
    InvokedFromSelectCursor = draw_list;
    text = base + offset;
    list = TOAddPktMenuIcon(draw_list, x + 3, y + 1, table->b14);
    InvokedFromSelectCursor = list;
    InvokedFromSelectCursor = func_001F41C0(list, text, x + 0x16, y, style);
}

void *func_001F8ED8(void *list, int id, int x, int y, int d)
{
    s32 base;
    Unk1BFED8 *it = MsGetSaveWeapon(id, &base);
    int text = func_001C0040(id);

    InvokedFromSelectCursor = list;
    InvokedFromSelectCursor = TOAddPktMenuIcon(list, x + 3, y + 1, it->b5 + it->b4 * 2 + 1);
    InvokedFromSelectCursor = func_001F41C0(InvokedFromSelectCursor, text, x + 0x16, y, d);
    if (it->b4 == it->b6) {
        InvokedFromSelectCursor = TOAddPktMenuIcon(InvokedFromSelectCursor, x + 3, y + 1, 0x31);
    }
    return InvokedFromSelectCursor;
}

void func_001F8FE8(void *draw_list, s32 text_id, s32 x, s32 y, s32 style)
{
    int base;
    OfsTbl *table;
    int text;
    u16 offset;
    void *list;

    table = MsGetRomAbility(text_id, &base);
    /* DEBT(CAST): read the packed pair of 16-bit offsets through its word view. */
    offset = (u16)*(u32 *)&table->a[0];
    InvokedFromSelectCursor = draw_list;
    text = base + offset;
    list = TOAddPktMenuIcon(draw_list, x + 3, y + 1, table->b68);
    InvokedFromSelectCursor = list;
    InvokedFromSelectCursor = func_001F78C8(list, text, x + 0x16, y, style);
}

void func_001F9090(void *draw_list, s32 text_id, s32 x, s32 y, s32 style)
{
    int base;
    OfsTbl *table;
    int text;
    u16 offset;
    void *list;

    table = MsImportantPtr(text_id, &base);
    /* DEBT(CAST): read the packed pair of 16-bit offsets through its word view. */
    offset = (u16)*(u32 *)&table->a[0];
    InvokedFromSelectCursor = draw_list;
    text = base + offset;
    list = TOAddPktMenuIcon(draw_list, x + 3, y + 1, table->b12);
    InvokedFromSelectCursor = list;
    InvokedFromSelectCursor = func_001F78C8(list, text, x + 0x16, y, style);
}

void *func_001F9138(void *list, int id, int x, int y, int d)
{
    int ofs = TOGetSaveChrName(id);

    InvokedFromSelectCursor = list;
    InvokedFromSelectCursor = TOAddPktMenuIcon(list, x + 3, y + 1, 0x13);
    InvokedFromSelectCursor = func_001F78C8(InvokedFromSelectCursor, ofs, x + 0x16, y, d);
    return InvokedFromSelectCursor;
}

void *func_001F91D8(void *list, int a, int b, int c)
{
    return func_001F9200(list, a, b, c, 0x80, 0x80, 0x80, 0x80);
}

void *func_001F9200(void *list, int x, int y, int w, int r, int g, int b, u8 a) /* colour arguments unused */
{
    InvokedFromSelectCursor = list;
    GIF_CUR()->ul64[0] = 0x1000000000000002UL;
    GIF_CUR()->ul64[1] = 0xE;
    GIF_NEXT();
    GIF_AD(0x4005D40621313E00UL, 6);
    GIF_AD(GS_SET_SCISSOR(0, 0x1FF, 0, 0x19F), 0x40);
    GIF_CUR()->ul64[0] = 0x50A3400000008001UL;
    GIF_CUR()->ul64[1] = 0x441EE;
    GIF_NEXT();
    func_001FB2C0(0, 1, 0, 1, 0x80);
    func_001FB358(1, 7, 0, 0, 0, 0, 0, 0);
    locNameTmpSetLanguage(0, 0, 0, 0x80);
    func_001FB678(x, y);
    func_001FB678(x + w, y + 0x13);
    return InvokedFromSelectCursor;
}

void *func_001F9350(void *list, int a, int b, int c)
{
    return func_001F9378(list, a, b, c, 0x80, 0x80, 0x80, 0x80);
}

void *func_001F9378(void *list, int x, int y, int w, u8 r, u8 g, u8 b, u8 a)
{
    InvokedFromSelectCursor = list;
    GIF_CUR()->ul64[0] = 0x00AF400000008001UL;
    GIF_CUR()->ul64[1] = 0x434314343143431EUL;
    GIF_NEXT();
    GIF_AD(0x4005D40621313E00UL, 6);
    w -= 0x18;
    locNameTmpSetLanguage(r, g, b, a);
    func_001FB550(0x70, 0x28);
    func_001FB678(x, y);
    func_001FB550(0x7C, 0x3A);
    func_001FB678(x + 0xC, y + 0x12);
    locNameTmpSetLanguage(r, g, b, a);
    func_001FB550(0x7C, 0x28);
    func_001FB678(x + 0xC, y);
    func_001FB550(0x7F, 0x3A);
    func_001FB678(x + 0xC + w, y + 0x12);
    locNameTmpSetLanguage(r, g, b, a);
    func_001FB550(0x80, 0x28);
    func_001FB678(x + 0xC + w, y);
    func_001FB550(0x8C, 0x3A);
    func_001FB678(x + 0xC + w + 0xC, y + 0x12);
    return InvokedFromSelectCursor;
}

typedef struct {
    s16 v[13][4];
} IconBox13;
extern IconBox13 D_0056FF98;

#undef InvokedFromSelectCursor

void *func_001F9548(void *list, int x, int y, int idx)
{
    IconBox13 tbl = D_0056FF98;

    InvokedFromSelectCursor = list;
    GIF_CUR()->ul64[0] = 0x60AF400000008001UL;
    GIF_CUR()->ul64[1] = 0x43431EUL;
    GIF_NEXT();
    GIF_AD(0x2005D40621313E00UL, 6);
    locNameTmpSetLanguage(0x80, 0x80, 0x80, 0x80);
    func_001FB550(tbl.v[idx][0], tbl.v[idx][1]);
    func_001FB6B0(x, y, 1);
    func_001FB550(tbl.v[idx][0] + tbl.v[idx][2], tbl.v[idx][1] + tbl.v[idx][3]);
    func_001FB678(x + tbl.v[idx][2], y + tbl.v[idx][3]);
    return InvokedFromSelectCursor;
}
#undef InvokedFromSelectCursor


void *TOAddPktMenuIcon(void *list, int a, int b, u8 c)
{
    return TOAddPktMenuIconRGBA(list, a, b, c, 0x80, 0x80, 0x80, 0x80);
}

void *TOAddPktMenuIconRGBA(void *list, int x, int y, u8 icon, u8 r, u8 g, u8 b, u8 a)
{
    int csa;
    int u;
    int v;

    InvokedFromSelectCursor = list;
    GIF_CUR()->ul64[0] = 0x70AF400000008001UL;
    GIF_CUR()->ul64[1] = 0x43431EEUL;
    GIF_NEXT();
    csa = icon & 0xF;
    func_001FB3C0(0x3DC0, 4, 0x13, 8, 7, 1, 0, 0x2EC0 + (icon / 16) * 4, 0, 0, 0, 2);
    func_001FB3C0(0x3DC0, 4, 0x14, 8, 7, 1, 0, 0x2EC0, 0, 0, csa, 0);
    locNameTmpSetLanguage(r, g, b, a);
    func_001FB550((icon % 17U) * 0xF, (icon / 17U) * 0x12);
    func_001FB678(x, y);
    u = (icon % 17U) * 0xF;
    v = (icon / 17U) * 0x12;
    __asm__("" : : "r"(u), "r"(v));
    func_001FB550(u + 0xF, v + 0x12);
    func_001FB678(x + 0xF, y + 0x12);
    return InvokedFromSelectCursor;
}

void *func_001F9938(void *list, int a, int b, int c)
{
    return func_001F9B48(list, a, b, c, 0x80, 0x80, 0x80, 0x80);
}

#undef InvokedFromSelectCursor
extern void *__g_InvokedFromSelectCursor __asm__("InvokedFromSelectCursor.NON_MATCHING");
#define InvokedFromSelectCursor __g_InvokedFromSelectCursor
void *func_001F9960(void *list, int a, int b, int c, u8 d, u8 e, u8 f, u8 g)
{
    int u = (a % 5) * 0xC + 0x70;
    int v = (a / 5) * 0x10 + 0x40;

    InvokedFromSelectCursor = list;
    GIF_CUR()->ul64[0] = 0x1000000000000006UL;
    GIF_CUR()->ul64[1] = 0xE;
    GIF_NEXT();
    func_001FB290();
    GIF_AD(GS_SET_SCISSOR(0, 0x1FF, 0, 0x19F), 0x40);
    GIF_AD(0, 8);
    GIF_AD(0x8000000044UL, 0x42);
    GIF_AD(0xF, 0x47);
    GIF_AD(0x4005D48621313F00UL, 6);
    GIF_CUR()->ul64[0] = 0x50AB400000008001UL;
    GIF_CUR()->ul64[1] = 0x43431;
    GIF_NEXT();
    locNameTmpSetLanguage(d, e, f, g);
    func_001FB550(u, v);
    func_001FB678(b, c);
    func_001FB550(u + 0xC, v + 0x10);
    func_001FB678(b + 0xC, c + 0x10);
    return InvokedFromSelectCursor;
}
#undef InvokedFromSelectCursor


typedef struct {
    s16 v[4][4];
} IconBox4;
extern IconBox4 D_00570000;

void *func_001F9B48(void *list, int a, int b, int c, u8 d, u8 e, u8 f, u8 g)
{
    IconBox4 tbl;

    InvokedFromSelectCursor = list;
    GIF_CUR()->ul64[0] = 0x80AB400000008001UL;
    GIF_CUR()->ul64[1] = 0x43431EEEUL;
    GIF_NEXT();
    tbl = D_00570000;
    func_001FB2C0(0, 1, 0, 1, 0x80);
    func_001FB3C0(0x3DC0, 4, 0x13, 8, 7, 1, 0, 0x2ECC, 0, 0, 0, 2);
    func_001FB3C0(0x3DC0, 4, 0x14, 8, 7, 1, 0, 0x2ECC, 0, 0, 0xD - a, 0);
    locNameTmpSetLanguage(d, e, f, g);
    func_001FB550(tbl.v[a][0], tbl.v[a][1]);
    func_001FB678(b, c);
    func_001FB550(tbl.v[a][2], tbl.v[a][3]);
    func_001FB678(b + tbl.v[a][2] - tbl.v[a][0], c + tbl.v[a][3] - tbl.v[a][1]);
    return InvokedFromSelectCursor;
}
#undef InvokedFromSelectCursor

void *func_001F9D50(void *list, int a, int b, int c)
{
    return func_001F9D78(list, a, b, c, 0x80, 0x80, 0x80, 0x80);
}

extern void *__g_InvokedFromSelectCursor2 __asm__("0x006632C0");
#define InvokedFromSelectCursor __g_InvokedFromSelectCursor2
#define RGBA32(r, g, b, a) ((r) | ((g) << 8) | ((b) << 16) | ((a) << 24))
void *func_001F9D78(void *list, int a, int b, int c, u8 r, u8 g, u8 b_col, u8 a_col)
{
    InvokedFromSelectCursor = list;
    if (a >= 0x40 && a < 0x50) {
        a &= 0xF;
        if (a & 1) {
            func_001FE240(0x259, b, c, RGBA32(r, g, b_col, a_col), RGBA32(r, g, b_col, a_col));
        } else {
            func_001FE240(0x258, b, c, RGBA32(r, g, b_col, a_col), RGBA32(r, g, b_col, a_col));
        }
        if (a & 2) {
            func_001FE240(0x25B, b, c, RGBA32(r, g, b_col, a_col), RGBA32(r, g, b_col, a_col));
        } else {
            func_001FE240(0x25A, b, c, RGBA32(r, g, b_col, a_col), RGBA32(r, g, b_col, a_col));
        }
        if (a & 4) {
            func_001FE240(0x25D, b, c, RGBA32(r, g, b_col, a_col), RGBA32(r, g, b_col, a_col));
        } else {
            func_001FE240(0x25C, b, c, RGBA32(r, g, b_col, a_col), RGBA32(r, g, b_col, a_col));
        }
        if (a & 8) {
            func_001FE240(0x25F, b, c, RGBA32(r, g, b_col, a_col), RGBA32(r, g, b_col, a_col));
        } else {
            func_001FE240(0x25E, b, c, RGBA32(r, g, b_col, a_col), RGBA32(r, g, b_col, a_col));
        }
    }
    if (a >= 0x30 && a < 0x3A) {
        if (func_0020B850() == 0 && func_001BD360() == 1) {
            if (a >= 0x31 && a <= 0x32) {
                if (a == 0x31) {
                    func_001FE240(0x262, b, c, RGBA32(r, g, b_col, a_col), RGBA32(r, g, b_col, a_col));
                }
                if (a == 0x32) {
                    func_001FE240(0x261, b, c, RGBA32(r, g, b_col, a_col), RGBA32(r, g, b_col, a_col));
                }
            } else {
                func_001FE240(a + 0x230, b, c, RGBA32(r, g, b_col, a_col), RGBA32(r, g, b_col, a_col));
            }
        } else {
            func_001FE240(a + 0x230, b, c, RGBA32(r, g, b_col, a_col), RGBA32(r, g, b_col, a_col));
        }
    }
    if (a == 0x60) {
        func_001FE240(0x270, b, c, RGBA32(r, g, b_col, a_col), RGBA32(r, g, b_col, a_col));
    }
    return InvokedFromSelectCursor;
}
#undef InvokedFromSelectCursor


void func_001FA0B0(int a, int b)
{
    InvokedFromSelectCursor = func_001F8800(InvokedFromSelectCursor, a, b);
    func_001EFA30();
}
