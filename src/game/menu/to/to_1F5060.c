/* tu_221 0x1f5060-0x1f8418: low; ~TOAdpMenuIconWeaponName2 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/r4.h"
#include "ffx/s4.h"
#include "ffx/t4.h"
#include "ffx/v4.h"
#include "ffx/u3.h"

void *func_001F5060(void *list, int id, int x, int y, int d)
{
    int base;
    OfsTbl *t = MsGetComData(id, &base);
    int ofs = base + t->a[0].x;

    y++;
    list = TOAddPktMenuIcon(list, x + 0xC, y, t->b14);
    return func_001F41C0(list, ofs, x + 0x1D, y, d);
}

void *func_001F50F8(void *list, int id, int x, int y, int d)
{
    int base;
    OfsTbl *t = MsGetRomItem(id, &base);
    int ofs = base + t->a[0].x;

    y++;
    list = TOAddPktMenuIcon(list, x + 0xC, y, t->b14);
    return func_001F41C0(list, ofs, x + 0x1D, y, d);
}

void *TOAdpMenuIconWeaponName2(void *list, R4Item *it, int x, int y, int d)
{
    int text;

    text = MsWeaponName(it->h0, it->b4, MsGetSaveConfigHiragana(), 0);
    list = TOAddPktMenuIcon(list, x + 0xC, y + 1, it->b5 + it->b4 * 2 + 1);
    list = func_001F41C0(list, text, x + 0x1D, y + 1, d);
    if (it->b4 == it->b6) {
        list = TOAddPktMenuIcon(list, x + 0xC, y + 1, 0x31);
    }
    return list;
}

void *func_001F5290(void *list, int id, int x, int y, int d)
{
    int buf;
    R4Item *it = (R4Item *)MsGetSaveWeapon(id, &buf); /* DEBT(TYPE): record type of the table behind MsGetSaveWeapon */
    int y1 = y + 1;
    int ofs = func_001C0040(id);

    list = TOAddPktMenuIcon(list, x + 0xC, y1, (it->b5 + it->b4 * 2 + 1) & 0xFF);
    list = func_001F41C0(list, ofs, x + 0x1D, y1, d);
    if (it->b4 == it->b6) {
        list = TOAddPktMenuIcon(list, x + 0xC, y1, 0x31);
    }
    return list;
}

void *func_001F5380(void *list, int id, int x, int y, int d)
{
    int base;
    OfsTbl *t = MsGetRomAbility(id, &base);
    int ofs = base + t->a[0].x;

    y++;
    list = TOAddPktMenuIcon(list, x + 0xC, y, t->b68);
    return func_001F41C0(list, ofs, x + 0x1D, y, d);
}

void *func_001F5418(void *list, int id, int x, int y, int d)
{
    int base;
    OfsTbl *t = MsImportantPtr(id, &base);
    int ofs = base + t->a[0].x;

    y++;
    list = TOAddPktMenuIcon(list, x + 0xC, y, t->b12);
    return func_001F41C0(list, ofs, x + 0x1D, y, d);
}

void *func_001F54B0(void *list, int id, int x, int y, int d)
{
    int ofs = TOGetSaveChrName(id);

    y++;
    list = TOAddPktMenuIcon(list, x + 0xC, y, 0x13);
    return func_001F41C0(list, ofs, x + 0x1D, y, d);
}

void func_001F5538(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F5060(InvokedFromSelectCursor, a, b, c, d);
    func_001EFA30();
}

void func_001F5580(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F50F8(InvokedFromSelectCursor, a, b, c, d);
    func_001EFA30();
}

void func_001F55C8(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F5290(InvokedFromSelectCursor, a, b, c, d);
    func_001EFA30();
}

void func_001F5610(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F5380(InvokedFromSelectCursor, a, b, c, d);
    func_001EFA30();
}

void func_001F5658(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F5418(InvokedFromSelectCursor, a, b, c, d);
    func_001EFA30();
}

void func_001F56A0(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F54B0(InvokedFromSelectCursor, a, b, c, d);
    func_001EFA30();
}

void func_001F56E8(void)
{
    InvokedFromSelectCursor = func_001F5718(InvokedFromSelectCursor);
    func_001EFA30();
}

void *func_001F5718(void *list)
{
    Qword *p = (Qword *)list;

    GIFP_AD_TAG(p, 5);
    GIFP_AD(p, 0, 0x3F);
    GIFP_AD(p, 0x8000000044UL, 0x42);
    GIFP_AD(p, 0xF, 0x47);
    GIFP_AD(p, 0x60, 0x14);
    GIFP_AD(p, 5, 8);
    return p;
}

void func_001F5790(int a, int b, int c)
{
    InvokedFromSelectCursor = func_001F5918(InvokedFromSelectCursor, a, b, c, 0, 0x80, 0x80, 0x80, 0x80);
    func_001EFA30();
}

void func_001F57E8(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F5918(InvokedFromSelectCursor, a, b, c, d, 0x80, 0x80, 0x80, 0x80);
    func_001EFA30();
}

void func_001F5848(int a, int b, int c, int d, int e)
{
    InvokedFromSelectCursor = func_001F5918(InvokedFromSelectCursor, a, b, c, d, 0x80, 0x80, 0x80, e);
    func_001EFA30();
}

void func_001F58A8(int a, int b, int c, int d, int e, int f, int g, int h)
{
    InvokedFromSelectCursor = func_001F5918(InvokedFromSelectCursor, a, b, c, d, e, f, g, h);
    func_001EFA30();
}

void *func_001F5918(void *list, int str, int x, int y, int a, int b, int c, int d, int e)
{
    u8 *s = (u8 *)str; /* DEBT(CAST): prototype takes the string as int */

    list = func_001F5718(list);
    while (*s != 0) {
        list = func_001F59F0(list, s, x, y, a, b, c, d, e);
        x += 12;
        s = TOSkipCode(s);
    }
    return list;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F5060", func_001F59F0);

void TOMkpEasyStrFontM(int a, int b, int c)
{
    InvokedFromSelectCursor = func_001F5FF0(InvokedFromSelectCursor, a, b, c, 0, 0x80, 0x80, 0x80, 0x80);
    func_001EFA30();
}

void func_001F5D08(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F5FF0(InvokedFromSelectCursor, a, b, c, d, 0x80, 0x80, 0x80, 0x80);
    func_001EFA30();
}

void func_001F5D68(int a, int b, int c, int d, int e)
{
    InvokedFromSelectCursor = func_001F5FF0(InvokedFromSelectCursor, a, b, c, d, 0x80, 0x80, 0x80, e);
    func_001EFA30();
}

void func_001F5DC8(int a, int b, int c, int d, int e, int f, int g, int h)
{
    InvokedFromSelectCursor = func_001F5FF0(InvokedFromSelectCursor, a, b, c, d, e, f, g, h);
    func_001EFA30();
}

void func_001F5E38(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F5EC8(InvokedFromSelectCursor, a, b, c, d);
}

void func_001F5E80(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F5F50(InvokedFromSelectCursor, a, b, c, d);
}

void *func_001F5EC8(void *list, int n, int x, int y, int d)
{
    char buf[32];

    func_002F0008(buf, D_0056FF90, n);
    return func_001F5FF0(list, (int)buf, x, y, d, 0x80, 0x80, 0x80, 0x80); /* DEBT(CAST): 2nd parameter is the string */
}

void *func_001F5F50(void *list, int n, int x, int y, int d)
{
    char buf[32];

    func_002F0008(buf, D_0056FF90, n);
    x += 2;
    return func_001F5FF0(list, (int)buf, x - func_002F0840(buf) * 12, y, d, 0x80, 0x80, 0x80, 0x80); /* DEBT(CAST): 2nd parameter is the string */
}

void *func_001F5FF0(void *list, int str, int x, int y, int a, int b, int c, int d, int e)
{
    char *s = (char *)str; /* DEBT(CAST): prototype takes the string as int */

    list = func_001F5718(list);
    while (*s != 0) {
        list = TOAdpFontM_ASCII(list, (int)s, x, y, a, b, c, d, e);
        s++;
        x += 12;
    }
    return list;
}

void func_001F60B0(int a, int b, int c)
{
    InvokedFromSelectCursor = TOAdpFontM_ASCII(InvokedFromSelectCursor, a, b, c, 0, 0x80, 0x80, 0x80, 0x80);
    func_001EFA30();
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F5060", TOAdpFontM_ASCII);

void func_001F63B8(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F6400(InvokedFromSelectCursor, a, b, c, d);
}

void *func_001F6400(void *list, int n, int x, int y, int d)
{
    char buf[32];

    func_002F0008(buf, D_0056FF90, n);
    x += 2;
    return func_001F6628(list, (int)buf, x - func_002F0840(buf) * 10, y, d, 0x80, 0x80, 0x80, 0x80); /* DEBT(CAST): 2nd parameter is the string */
}

void func_001F64A0(int a, int b, int c)
{
    InvokedFromSelectCursor = func_001F6628(InvokedFromSelectCursor, a, b, c, 0, 0x80, 0x80, 0x80, 0x80);
    func_001EFA30();
}

void func_001F64F8(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F6628(InvokedFromSelectCursor, a, b, c, d, 0x80, 0x80, 0x80, 0x80);
    func_001EFA30();
}

void func_001F6558(int a, int b, int c, int d, int e)
{
    InvokedFromSelectCursor = func_001F6628(InvokedFromSelectCursor, a, b, c, d, 0x80, 0x80, 0x80, e);
    func_001EFA30();
}

void func_001F65B8(int a, int b, int c, int d, int e, int f, int g, int h)
{
    InvokedFromSelectCursor = func_001F6628(InvokedFromSelectCursor, a, b, c, d, e, f, g, h);
    func_001EFA30();
}

void *func_001F6628(void *list, int str, int x, int y, int a, int b, int c, int d, int e)
{
    char *s = (char *)str; /* DEBT(CAST): prototype takes the string as int */

    list = func_001F5718(list);
    while (*s != 0) {
        list = func_001F66E8(list, (int)s, x, y, a, b, c, d, e);
        s++;
        x += 10;
    }
    return list;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F5060", func_001F66E8);

void func_001F6990(int a, int b, int c)
{
    InvokedFromSelectCursor = func_001F6B18(InvokedFromSelectCursor, a, b, c, 0, 0x80, 0x80, 0x80, 0x80);
    func_001EFA30();
}

void func_001F69E8(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F6B18(InvokedFromSelectCursor, a, b, c, d, 0x80, 0x80, 0x80, 0x80);
    func_001EFA30();
}

void func_001F6A48(int a, int b, int c, int d, int e)
{
    InvokedFromSelectCursor = func_001F6B18(InvokedFromSelectCursor, a, b, c, d, 0x80, 0x80, 0x80, e);
    func_001EFA30();
}

void func_001F6AA8(int a, int b, int c, int d, int e, int f, int g, int h)
{
    InvokedFromSelectCursor = func_001F6B18(InvokedFromSelectCursor, a, b, c, d, e, f, g, h);
    func_001EFA30();
}

void *func_001F6B18(void *list, int a, int b, int c, int d, int e, int f, int g, int h)
{
    char *s = (char *)a; /* DEBT(TYPE): the text is passed as int */

    list = func_001F5718(list);
    while (*s != 0) {
        list = func_001F6BD8(list, s, b, c, d, e, f, g, h);
        s++;
        b += 10;
    }
    return list;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F5060", func_001F6BD8);

void TOInitAddPkt(void)
{
    D_0032363C = 0;
}

void TOSetAddPkt(void)
{
    D_0032363C = 1;
}

u64 func_001F6EA0(void)
{
    return 0x2005D40621313E00UL;
}

s32 func_001F6EC0(void)
{
    return 0x2EDC;
}

void *func_001F6EC8(void *list)
{
    InvokedFromSelectCursor = list;
    GIF_CUR()->ul64[0] = 0x1000000000008005UL;
    GIF_CUR()->ul64[1] = 0xE;
    GIF_NEXT();
    func_001FB290();
    GIF_AD(0x019F000001FF0000UL, 0x40);
    GIF_AD(0, 0x08);
    GIF_AD(0x8000000044UL, 0x42);
    GIF_AD(0xF, 0x47);
    return InvokedFromSelectCursor;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F5060", func_001F6F88);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F5060", func_001F7378);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F5060", func_001F7798);

void *func_001F7898(void *list, int a, int b, int c)
{
    return func_001F7920(list, a, b, c, 0, 0x80, 0x80, 0x80, 0x80);
}

void *func_001F78C8(void *list, int a, int b, int c, int d)
{
    return func_001F7920(list, a, b, c, d, 0x80, 0x80, 0x80, 0x80);
}

void *func_001F78F8(void *list, int a, int b, int c, int d, int e)
{
    return func_001F7920(list, a, b, c, d, 0x80, 0x80, 0x80, e);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F5060", func_001F7920);

void *func_001F7B38(void *list, int a, int b, int c, int d)
{
    return func_001F7BC8(list, a, b, c, d, 0, 0x80, 0x80, 0x80, 0x80);
}

void *func_001F7B68(void *list, int a, int b, int c, int d, int e)
{
    return func_001F7BC8(list, a, b, c, d, e, 0x80, 0x80, 0x80, 0x80);
}

void *func_001F7B98(void *list, int a, int b, int c, int d, int e, int f)
{
    return func_001F7BC8(list, a, b, c, d, e, 0x80, 0x80, 0x80, f);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F5060", func_001F7BC8);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F5060", TOAddPktChangeMacro);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F5060", func_001F7FC0);

void *func_001F80D0(void *list, int id, int x, int y, int d)
{
    char buf[64];

    func_0020E508(id, buf);
    return func_001F7FC0(list, buf, x, y, d);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F5060", func_001F8138);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F5060", func_001F8258);

void *func_001F8390(void *list, int v, int x, int y, int d)
{
    char buf[32];

    func_002F0008(buf, D_0056FF90, v);
    return func_001F78C8(list, (int)buf, x - func_002F0840(buf) * 12, y, d); /* DEBT(CAST): text passed as int */
}
