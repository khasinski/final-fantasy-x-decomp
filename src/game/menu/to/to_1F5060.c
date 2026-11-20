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

void *func_001F59F0(void *list, u8 *s, int x, int y, int a, int r, int g, int b, int alpha)
{
    Qword *p = (Qword *)list;
    int ch;
    int u0;
    int v0;
    int csa0;
    int csa1;

    if (*s < 0x30) {
        ch = s[1] + 0xA0;
    } else {
        ch = *s - 0x30;
    }
    u0 = ((ch % 24) / 2) * 10;
    v0 = (ch / 24) * 12;
    csa0 = (a & 0xF) * 2 + (ch & 1);
    csa1 = ((a >> 4) & 0xF) * 2 + (ch & 1);

    p->ul64[0] = 0xE0AB400000008001UL;
    p->ul64[1] = 0x43431EE43431EEUL;
    p++;
    p = (Qword *)func_001FB9D0((GsAdPacket *)p, 0x3D80, 2, 0x13, 7, 8, 1, 0, 0x2EBC, 0, 0, 0, 1);
    p = (Qword *)func_001FB9D0((GsAdPacket *)p, 0x3D80, 2, 0x14, 7, 8, 1, 0, 0x2EBC, 0, 0, csa1, 0);
    p = (Qword *)func_001FBB30((Quad32 *)p, r, g, b, alpha);
    p = (Qword *)func_001FBAF0((Quad32 *)p, u0, v0);
    p = (Qword *)func_001FBBB0((Quad32 *)p, x + 1, y + 1);
    p = (Qword *)func_001FBAF0((Quad32 *)p, u0 + 10, v0 + 12);
    p = (Qword *)func_001FBBB0((Quad32 *)p, x + 11, y + 13);
    p = (Qword *)func_001FB9D0((GsAdPacket *)p, 0x3D80, 2, 0x13, 7, 8, 1, 0, 0x2EB8, 0, 0, 0, 1);
    p = (Qword *)func_001FB9D0((GsAdPacket *)p, 0x3D80, 2, 0x14, 7, 8, 1, 0, 0x2EB8, 0, 0, csa0, 0);
    p = (Qword *)func_001FBB30((Quad32 *)p, r, g, b, alpha);
    p = (Qword *)func_001FBAF0((Quad32 *)p, u0, v0);
    p = (Qword *)func_001FBBB0((Quad32 *)p, x, y);
    p = (Qword *)func_001FBAF0((Quad32 *)p, u0 + 10, v0 + 12);
    p = (Qword *)func_001FBBB0((Quad32 *)p, x + 10, y + 12);
    return p;
}

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

void *TOAdpFontM_ASCII(void *list, int str, int x, int y, int a, int r, int g, int b, int alpha)
{
    Qword *p = (Qword *)list;
    char *s = (char *)str;
    int ch = *s - 0x20;
    int u0 = ((ch % 24) / 2) * 10;
    int v0 = (ch / 24) * 12 + 0x90;
    int csa0 = (a & 0xF) * 2 + (ch & 1);
    int csa1 = ((a >> 4) & 0xF) * 2 + (ch & 1);

    p->ul64[0] = 0xE0AB400000008001UL;
    p->ul64[1] = 0x43431EE43431EEUL;
    p++;
    p = (Qword *)func_001FB9D0((GsAdPacket *)p, 0x3D80, 2, 0x13, 7, 8, 1, 0, 0x2EBC, 0, 0, 0, 1);
    p = (Qword *)func_001FB9D0((GsAdPacket *)p, 0x3D80, 2, 0x14, 7, 8, 1, 0, 0x2EBC, 0, 0, csa1, 0);
    p = (Qword *)func_001FBB30((Quad32 *)p, r, g, b, alpha);
    p = (Qword *)func_001FBAF0((Quad32 *)p, u0, v0);
    p = (Qword *)func_001FBBB0((Quad32 *)p, x + 1, y + 1);
    p = (Qword *)func_001FBAF0((Quad32 *)p, u0 + 10, v0 + 12);
    p = (Qword *)func_001FBBB0((Quad32 *)p, x + 11, y + 13);
    p = (Qword *)func_001FB9D0((GsAdPacket *)p, 0x3D80, 2, 0x13, 7, 8, 1, 0, 0x2EB8, 0, 0, 0, 1);
    p = (Qword *)func_001FB9D0((GsAdPacket *)p, 0x3D80, 2, 0x14, 7, 8, 1, 0, 0x2EB8, 0, 0, csa0, 0);
    p = (Qword *)func_001FBB30((Quad32 *)p, r, g, b, alpha);
    p = (Qword *)func_001FBAF0((Quad32 *)p, u0, v0);
    p = (Qword *)func_001FBBB0((Quad32 *)p, x, y);
    p = (Qword *)func_001FBAF0((Quad32 *)p, u0 + 10, v0 + 12);
    p = (Qword *)func_001FBBB0((Quad32 *)p, x + 10, y + 12);
    return p;
}

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

void *func_001F66E8(void *list, int str, int x, int y, int a, int r, int g, int b, int alpha)
{
    Qword *p = (Qword *)list;
    char *s = (char *)str;
    int ch = *s - 0x20;
    int u0 = ((ch % 32) / 2) * 8;
    int v0 = (ch / 32) * 10 + 0xC0;
    int csa0 = (a & 0xF) * 2 + (ch & 1);
    int csa1 = ((a >> 4) & 0xF) * 2 + (ch & 1);

    p->ul64[0] = 0xE0AB400000008001UL;
    p->ul64[1] = 0x43431EE43431EEUL;
    p++;
    p = (Qword *)func_001FB9D0((GsAdPacket *)p, 0x3D80, 2, 0x13, 7, 8, 1, 0, 0x2EBC, 0, 0, 0, 1);
    p = (Qword *)func_001FB9D0((GsAdPacket *)p, 0x3D80, 2, 0x14, 7, 8, 1, 0, 0x2EBC, 0, 0, csa1, 0);
    p = (Qword *)func_001FBB30((Quad32 *)p, r, g, b, alpha);
    p = (Qword *)func_001FBAF0((Quad32 *)p, u0, v0);
    p = (Qword *)func_001FBBB0((Quad32 *)p, x + 1, y + 1);
    p = (Qword *)func_001FBAF0((Quad32 *)p, u0 + 8, v0 + 10);
    p = (Qword *)func_001FBBB0((Quad32 *)p, x + 9, y + 11);
    p = (Qword *)func_001FB9D0((GsAdPacket *)p, 0x3D80, 2, 0x13, 7, 8, 1, 0, 0x2EB8, 0, 0, 0, 1);
    p = (Qword *)func_001FB9D0((GsAdPacket *)p, 0x3D80, 2, 0x14, 7, 8, 1, 0, 0x2EB8, 0, 0, csa0, 0);
    p = (Qword *)func_001FBB30((Quad32 *)p, r, g, b, alpha);
    p = (Qword *)func_001FBAF0((Quad32 *)p, u0, v0);
    p = (Qword *)func_001FBBB0((Quad32 *)p, x, y);
    p = (Qword *)func_001FBAF0((Quad32 *)p, u0 + 8, v0 + 10);
    p = (Qword *)func_001FBBB0((Quad32 *)p, x + 8, y + 10);
    return p;
}

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

void *func_001F6BD8(void *list, char *s, int x, int y, int a, int r, int g, int b, int alpha)
{
    Qword *p = (Qword *)list;
    int ch = *s - 0x20;
    int u0 = ((ch % 32) / 2) * 8;
    int v0 = (ch / 32) * 8 + 0xF0;
    int csa0 = (a & 0xF) * 2 + (ch & 1);
    int csa1 = ((a >> 4) & 0xF) * 2 + (ch & 1);

    p->ul64[0] = 0xE0AB400000008001UL;
    p->ul64[1] = 0x43431EE43431EEUL;
    p++;
    p = (Qword *)func_001FB9D0((GsAdPacket *)p, 0x3D80, 2, 0x13, 7, 8, 1, 0, 0x2EBC, 0, 0, 0, 1);
    p = (Qword *)func_001FB9D0((GsAdPacket *)p, 0x3D80, 2, 0x14, 7, 8, 1, 0, 0x2EBC, 0, 0, csa1, 0);
    p = (Qword *)func_001FBB30((Quad32 *)p, r, g, b, alpha);
    p = (Qword *)func_001FBAF0((Quad32 *)p, u0, v0);
    p = (Qword *)func_001FBBB0((Quad32 *)p, x + 1, y + 1);
    p = (Qword *)func_001FBAF0((Quad32 *)p, u0 + 8, v0 + 8);
    p = (Qword *)func_001FBBB0((Quad32 *)p, x + 9, y + 9);
    p = (Qword *)func_001FB9D0((GsAdPacket *)p, 0x3D80, 2, 0x13, 7, 8, 1, 0, 0x2EB8, 0, 0, 0, 1);
    p = (Qword *)func_001FB9D0((GsAdPacket *)p, 0x3D80, 2, 0x14, 7, 8, 1, 0, 0x2EB8, 0, 0, csa0, 0);
    p = (Qword *)func_001FBB30((Quad32 *)p, r, g, b, alpha);
    p = (Qword *)func_001FBAF0((Quad32 *)p, u0, v0);
    p = (Qword *)func_001FBBB0((Quad32 *)p, x, y);
    p = (Qword *)func_001FBAF0((Quad32 *)p, u0 + 8, v0 + 8);
    p = (Qword *)func_001FBBB0((Quad32 *)p, x + 8, y + 8);
    return p;
}

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

extern R4CharInfo D_00323930;
extern TextItem D_00323918;

void *func_001F7798(void *list, int a, int b, int c)
{
    R4CharInfo *glyph = &D_00323930;
    TextItem *it;

    func_002EF0D0(glyph, 0, 0x20);
    func_002EF0D0(&D_00323918, 0, 0x14);
    InvokedFromSelectCursor = list;
    it = &D_00323918;
    it->x = b;
    it->y = c;
    it->col[0] = 0x80;
    it->col[1] = 0x80;
    it->col[2] = 0x80;
    it->col[3] = 0x80;
    it->f13 = 0;
    it->f12 = 0;
    func_00204CA8(a, glyph);
    func_001F11E0(it, glyph);
    func_001F0EC0(it, glyph);
    it->x += glyph->h10 + 2;
    return InvokedFromSelectCursor;
}

void *func_001F7898(void *list, int a, int b, int c)
{
    return func_001F7920(list, a, b, c, 0, 0x80, 0x80, 0x80, 0x80);
}

void *func_001F78C8(void *list, void *a, int b, int c, int d)
{
    return func_001F7920(list, (int)a, b, c, d, 0x80, 0x80, 0x80, 0x80);
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

void *func_001F8138(void *list, int number, int x, int y, int style)
{
    char buf[32];
    u8 *s;
    TextItem *it;
    R4CharInfo *glyph = &D_00323930;
    func_002EF0D0(glyph, 0, 32);
    func_002EF0D0(&D_00323918, 0, 20);
    InvokedFromSelectCursor = list;
    func_002F0008(buf, D_0056FF90, number);
    it = &D_00323918;
    it->x = x;
    it->y = y;
    it->col[0] = 0x80;
    it->col[1] = 0x80;
    it->col[2] = 0x80;
    it->col[3] = 0x80;
    it->f12 = 0;
    it->f13 = style;
    for (s = (u8 *)buf; *s; s = TOSkipCode(s)) {
        func_0020E468(s, glyph);
        func_001F1F60(it, glyph);
    }
    return InvokedFromSelectCursor;
}

void *func_001F8258(void *list, int number, int x, int y, int style)
{
    char buf[32];
    u8 *s;
    TextItem *it;
    R4CharInfo *glyph = &D_00323930;
    func_002EF0D0(glyph, 0, 32);
    func_002EF0D0(&D_00323918, 0, 20);
    InvokedFromSelectCursor = list;
    func_002F0008(buf, D_0056FF90, number);
    x -= func_002F0840(buf) * 11;
    it = &D_00323918;
    it->x = x;
    it->y = y;
    it->col[0] = 0x80;
    it->col[1] = 0x80;
    it->col[2] = 0x80;
    it->col[3] = 0x80;
    it->f12 = 0;
    it->f13 = style;
    for (s = (u8 *)buf; *s; s = TOSkipCode(s)) {
        func_0020E468(s, glyph);
        func_001F1F60(it, glyph);
    }
    return InvokedFromSelectCursor;
}

void *func_001F8390(void *list, int v, int x, int y, int d)
{
    char buf[32];

    func_002F0008(buf, D_0056FF90, v);
    return func_001F78C8(list, buf, x - func_002F0840(buf) * 12, y, d);
}
