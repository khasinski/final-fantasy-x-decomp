/* tu_222 0x1f8418-0x1fa0e8: medium; ~TOAddPktMenuIcon (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/r4.h"
#include "ffx/u3.h"
#include "ffx/v4.h"
#include "ffx/t4.h"

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F8418", func_001F8418);

void *func_001F85A8(void *list, int a, int b, int c)
{
    return func_001F8418(list, a, b, c, 0x80, 0x80, 0x80, 0x80);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F8418", func_001F85D0);

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

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F8418", func_001F8860);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F8418", func_001F8BD8);

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

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F8418", func_001F9378);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F8418", func_001F9548);

void *TOAddPktMenuIcon(void *list, int a, int b, u8 c)
{
    return TOAddPktMenuIconRGBA(list, a, b, c, 0x80, 0x80, 0x80, 0x80);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F8418", TOAddPktMenuIconRGBA);

void *func_001F9938(void *list, int a, int b, int c)
{
    return func_001F9B48(list, a, b, c, 0x80, 0x80, 0x80, 0x80);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F8418", func_001F9960);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F8418", func_001F9B48);

void *func_001F9D50(void *list, int a, int b, int c)
{
    return func_001F9D78(list, a, b, c, 0x80, 0x80, 0x80, 0x80);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F8418", func_001F9D78);

void func_001FA0B0(int a, int b)
{
    InvokedFromSelectCursor = func_001F8800(InvokedFromSelectCursor, a, b);
    func_001EFA30();
}
