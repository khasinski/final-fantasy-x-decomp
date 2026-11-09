/* tu_270 0x2454c0-0x249328: low; ~Tk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r5.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/u4.h"
#include "ffx/v5.h"

u32 func_002454C0(void) { return 0x1D57B00; }

void *func_002454D0(void) {
    return D_00573078;
}

int func_002454E0(u8 *s) { return func_00205DF0(s); }

int func_00245500(void) { return func_0020E2C8(); }

int func_00245520(u8 *text, int font) { return func_00205E40(font, text); }

void func_00245548(void)
{
    func_00124F08();
    D_0069BCD8 = D_0069BCDC = (u8 *)Sg_PacketGetPtr(); /* DEBT(CAST): getter returns s32 */
}

void TkMenuDrawScissorClear(void) { func_00245978(0, 0, 0x1FF, 0x19F); }

void func_00245598(void)
{
    CmdRec *p = (CmdRec *)D_0069BCDC; /* DEBT(CAST): D_0069BCDC is u8 * elsewhere */

    p->b3 = 0x70;
    p->w0 = 0;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2454C0", func_002455C0);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2454C0", func_00245658);

void func_002457F8(int id, int x, int y, int w, int h)
{
    func_00247408(x, y, id);
    func_00247408(x + w - 0x10, y, id + 1);
    func_00247408(x, y + h - 0x10, id + 2);
    func_00247408(x + w - 0x10, y + h - 0x10, id + 3);
    func_002476C8(func_00247F48(id + 4, D_003264A0), x + 0x10, y, w - 0x20);
    func_00247640(func_00247F48(id + 5, D_003264A0), x, y + 0x10, h - 0x20);
    func_00247750(func_00247F48(id + 6, D_003264A0), x + 0x10, y + 0x10, w - 0x20, h - 0x20);
    func_00247640(func_00247F48(id + 7, D_003264A0), x + w - 0x10, y + 0x10, h - 0x20);
    func_002476C8(func_00247F48(id + 8, D_003264A0), x + 0x10, y + h - 0x10, w - 0x20);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2454C0", func_00245978);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2454C0", TkMenuDrawRect);

void func_00245B68(int a, int b, int c)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001F87D8(p + 0x10, a, b, c);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00245BF0(int a, int b) {
    u8 *p = D_0069BCDC;
    DmaTag *tag = (DmaTag *)p;
    u32 n;
    int y = b - 3; /* DEBT(ORDER): temporaries steer argument evaluation order */
    int x = a - 0x16;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = func_001F85A8(p + 0x10, x, y, 0);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->qwc = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00245C70(int a, int b, int c)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001F87D8(p + 0x10, a, b, c);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00245CF8(void) {
}

void func_00245D00(int a, int b, int c)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_00248910(p + 0x10, a, b, 0x20, c, 0);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00245D90(int a, int b, int c)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_00248910(p + 0x10, a, b, 0x24, c, 0);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00245E20(int a, int b, int c)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_00248910(p + 0x10, a, b, 0x26, c, 0x1);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00245EB0(int a, int b, int c)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_00248910(p + 0x10, a, b, 0x22, c, 0x1);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00245F40(int a, int b, int c)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_00248B30(p + 0x10, a, b, 0x20, c, 0);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00245FD0(int a, int b, int c)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_00248B30(p + 0x10, a, b, 0x24, c, 0);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00246060(int a, int b, int c)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_00248B30(p + 0x10, a, b, 0x26, c, 0x1);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_002460F0(int a, int b, int c)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_00248B30(p + 0x10, a, b, 0x22, c, 0x1);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00246180(int a, int b, int c, int d)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_00248F98(p + 0x10, a, b, c, d);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00246210(int a0, int a1, int a2) { func_00245B68(a0, a1, a2); }

void func_00246218(int a0, int a1, int a2) { func_00245B68(a0, a1, a2); }

void func_00246220(int a0, int a1, int a2) { func_00247408(a0, a1, 0); }

void func_00246228(void) {
}

void func_00246230(int a0, int a1, int a2) { func_00247880(a0, a1, 0); }

void func_00246238(int a, int b, int c)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001F7898(p + 0x10, a, b, c);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_002462C0(int a, int b, int c, int d)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001F7B38(p + 0x10, b, a, c, d);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00246348(char *s, int x, int y, int a)
{
    CmdRec *c = (CmdRec *)D_0069BCDC; /* DEBT(CAST): D_0069BCDC is u8 * elsewhere */
    u8 *end;
    int n;

    if (func_002F0840(s) != 0) {
        D_0069BCDC = (u8 *)(c + 1);
        end = func_001F41C0(c + 1, s, x, y, a);
        D_0069BCDC = end;
        n = (u32)(end - (u8 *)c + 15) / 16 - 1;
        c->b3 = 0x10;
        c->b2 = 0;
        c->w0 = n;
        c->w4 = 0;
        c->w8 = 0;
        c->wC = n | 0x50000000;
    }
}

void func_00246408(u8 *s, int y, int a, int b)
{
    CmdRec *c = (CmdRec *)D_0069BCDC; /* DEBT(CAST): D_0069BCDC is u8 * elsewhere */
    u8 *end;
    int n;

    D_0069BCDC = (u8 *)(c + 1);
    end = func_001F78C8(D_0069BCDC, s, y - func_002454E0(s), a, b);
    D_0069BCDC = end;
    n = (u32)(end - (u8 *)c + 15) / 16 - 1;
    c->b3 = 0x10;
    c->b2 = 0;
    c->w0 = n;
    c->w4 = 0;
    c->w8 = 0;
    c->wC = n | 0x50000000;
}

void func_002464C0(int a, int b, int c, int d, int e)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001F78F8(p + 0x10, a, b, c, d, e);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00246558(int a, int b, int c)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001F7798(p + 0x10, a, b, c);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_002465E0(int a, int b, int c, int d)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001F8138(p + 0x10, a, b, c, d);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00246670(int a, int b, int c, int d)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001F8258(p + 0x10, a, b, c, d);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00246700(int a, int b, int c, int d)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001F8390(p + 0x10, a, b, c, d);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00246790(int a, int b, int c)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001F7FC0(p + 0x10, a, b, c, 0);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00246818(int a, int b, int c, int d)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001F7FC0(p + 0x10, a, b, c, d);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_002468A8(int a, int b, int c)
{
    u8 *p;
    CmdRec *tag;
    u32 n;
    u16 w = ((int (*)(int))func_00245500)(a);

    p = D_0069BCDC;
    tag = (CmdRec *)p;
    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001F7FC0(p + 0x10, a, b - w, c, 0);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00246958(int a, int b, int c, int d)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001F8E30(p + 0x10, a, b, c, d);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_002469E8(int a, int b, int c, int d)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001F8ED8(p + 0x10, a, b, c, d);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00246A78(int a, int b, int c, int d)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001F8FE8(p + 0x10, a, b, c, d);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00246B08(int a, int b, int c, int d)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001F9138(p + 0x10, a, b, c, d);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00246B98(int a, int b, int c, int d)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001F9090(p + 0x10, a, b, c, d);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00246C28(int a, int b, int c, int d)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001F8D88(p + 0x10, a, b, c, d);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00246CB8(int a, int b, int c)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001F8BD8(p + 0x10, a, b, c);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2454C0", func_00246D40);

void func_00246E30(int x, int y, int w, int h)
{
    CmdRec *c = (CmdRec *)D_0069BCDC; /* DEBT(CAST): D_0069BCDC is u8 * elsewhere */
    u8 *end;
    int n;

    D_0069BCDC = (u8 *)(c + 1);
    end = func_001F6F88(c + 1, x, y, x + w - 1, y + h - 1);
    D_0069BCDC = end;
    n = (u32)(end - (u8 *)c + 15) / 16 - 1;
    c->b3 = 0x10;
    c->b2 = 0;
    c->w0 = n;
    c->w4 = 0;
    c->w8 = 0;
    c->wC = n | 0x50000000;
}

void func_00246EC0(int a, int b, int c)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001F9350(p + 0x10, a, b, c);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00246F48(int a) {
    u8 *p = D_0069BCDC;
    DmaTag *tag = (DmaTag *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = func_001F91D8(p + 0x10, 0, a, 0x200);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->qwc = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00246FC8(int a, int b, int c)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001F91D8(p + 0x10, a, b, c);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2454C0", func_00247050);

void func_00247138(int a, int b) {
    u8 *p = D_0069BCDC;
    DmaTag *tag = (DmaTag *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = func_002417D8(p + 0x10, a, b);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->qwc = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2454C0", func_002471B8);

void func_002472A8(Task *o) {
    int b = o->x14;
    int a = o->x1C;

    o->x1C = a - 10;
    o->x14 = b + 10;
    func_002471B8(o);
    o->x14 = b;
    o->x1C = a;
}

void func_00247300(int a, int b) {
    u8 *p = D_0069BCDC;
    DmaTag *tag = (DmaTag *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = func_001F8800(p + 0x10, a, b);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->qwc = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00247380(int a, int b, int c)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001F9548(p + 0x10, a, b, c);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00247408(int a, int b, int c)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_00248558(p + 0x10, a, b, c);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00247490(int a, int b, int c, int d)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_00248590(p + 0x10, a, b, c, d);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00247520(int a, int b, int c, int d)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_00248608(p + 0x10, a, b, c, d);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_002475B0(int a, int b, int c, int d)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_002485D0(p + 0x10, a, b, c, d);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00247640(void *a, int b, int c, int d)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_00248E18(p + 0x10, d, a, b, c);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_002476C8(void *a, int b, int c, int d)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_00248D50(p + 0x10, d, a, b, c);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00247750(void *a, int b, int c, int d, int e)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_00248ED8(p + 0x10, d, e, a, b, c);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2454C0", func_002477E0);

void func_00247880(int a, int b, int c)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_00248738(p + 0x10, a, b, c);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00247908(int a, int b, int c, int d)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_00248770(p + 0x10, a, b, c, d);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00247998(int a, int b, int c)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_00248820(p + 0x10, a, b, c);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00247A20(int a, int b, int c, int d)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_00248858(p + 0x10, a, b, c, d);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00247AB0(int a, int b, int c)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_00248898(p + 0x10, a, b, c);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00247B38(int a, int b, int c, int d)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_002488D0(p + 0x10, a, b, c, d);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00247BC8(int x, int y, int z)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_00248648(p + 0x10, x, y, z);
    n = (u32)(D_0069BCDC - p);
    n += 15;
    n = (n >> 4) - 1; /* DEBT(FAKE): split keeps the original register use */
    tag->b3 = 0x10;
    tag->w0 = n;
    tag->b2 = 0;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | n;
    TkMenuDrawRect(x, y, 0x5E, 2, 0x40808080, 0x40808080);
    TkMenuDrawRect(x, y + 0x3B, 0x5E, 2, 0x40808080, 0x40808080);
    TkMenuDrawRect(x, y + 2, 0xB, 0x39, 0x40808080, 0x40808080);
    TkMenuDrawRect(x + 0x53, y + 2, 0xB, 0x39, 0x40808080, 0x40808080);
}

void func_00247CF8(int x, int y, int z, int w)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_00248680(p + 0x10, x, y, z, w);
    n = (u32)(D_0069BCDC - p);
    n += 15;
    n = (n >> 4) - 1; /* DEBT(FAKE): split keeps the original register use */
    tag->b3 = 0x10;
    tag->w0 = n;
    tag->b2 = 0;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | n;
    TkMenuDrawRect(x, y, 0x5E, 2, 0x40808080, 0x40808080);
    TkMenuDrawRect(x, y + 0x3B, 0x5E, 2, 0x40808080, 0x40808080);
    TkMenuDrawRect(x, y + 2, 0xB, 0x39, 0x40808080, 0x40808080);
    TkMenuDrawRect(x + 0x53, y + 2, 0xB, 0x39, 0x40808080, 0x40808080);
}

void func_00247E30(int a, int b, int c)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_002486C0(p + 0x10, a, b, c);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void func_00247EB8(int a, int b, int c, int d)
{
    u8 *p = D_0069BCDC;
    CmdRec *tag = (CmdRec *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_002486F8(p + 0x10, a, b, c, d);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->w0 = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

void *func_00247F48(u32 i, int *tbl) {
    int *p;

    if (i >= tbl[0]) {
        return 0;
    }
    p = tbl + i;
    return (u8 *)tbl + p[1];
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2454C0", func_00247F70);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2454C0", func_00248168);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2454C0", func_00248350);

int func_00248558(void *a0, int a1, int a2, int a3) { return func_00247F70(a0, 0, a1, a2, a3, 0, 0, 0x80); }

int func_00248590(void *a0, int a1, int a2, int a3, int a4) { return func_00247F70(a0, 0, a1, a2, a3, 0, 0, a4); }

int func_002485D0(void *a0, int a1, int a2, int a3) { return func_00247F70(a0, 0, a1, a2, a3, 8, 0, 0x80); }

int func_00248608(void *a0, int a1, int a2, int a3, int a4) { return func_00247F70(a0, 0, a1, a2, a3, 8, 0, a4); }

int func_00248648(void *a0, int a1, int a2, int a3) { return func_00247F70(a0, 1, a1, a2, a3, 0, 0, 0x80); }

int func_00248680(void *a0, int a1, int a2, int a3, int a4) { return func_00247F70(a0, 1, a1, a2, a3, 0, 0, a4); }

int func_002486C0(void *a0, int a1, int a2, int a3) { return func_00247F70(a0, 2, a1, a2, a3, 0, 0, 0x80); }

int func_002486F8(void *a0, int a1, int a2, int a3, int a4) { return func_00247F70(a0, 2, a1, a2, a3, 0, 0, a4); }

int func_00248738(void *a0, int a1, int a2, int a3) { return func_00248168(a0, 0, a1, a2, a3, 0, 0, 0x80); }

int func_00248770(void *a0, int a1, int a2, int a3, int a4) { return func_00248168(a0, 0, a1, a2, a3, 0, 0, a4); }

int func_002487B0(void *a0, int a1, int a2, int a3) { return func_00248168(a0, 1, a1, a2, a3, 0, 0, 0x80); }

int func_002487E8(void *a0, int a1, int a2, int a3) { return func_00248168(a0, 2, a1, a2, a3, 0, 0, 0x80); }

int func_00248820(void *a0, int a1, int a2, int a3) { return func_00248350(a0, 0, a1, a2, a3, 0, 0, 0x80); }

int func_00248858(void *a0, int a1, int a2, int a3, int a4) { return func_00248350(a0, 0, a1, a2, a3, 0, 0, a4); }

int func_00248898(void *a0, int a1, int a2, int a3) { return func_00248350(a0, 0, a1, a2, a3, 8, 0, 0x80); }

int func_002488D0(void *a0, int a1, int a2, int a3, int a4) { return func_00248350(a0, 0, a1, a2, a3, 8, 0, a4); }

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2454C0", func_00248910);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2454C0", func_00248B30);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2454C0", func_00248D50);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2454C0", func_00248E18);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2454C0", func_00248ED8);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2454C0", func_00248F98);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2454C0", func_00249108);

void func_002491D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 (*arg6)(s32, s32, s32)) {
    s32 temp_3;
    s32 temp_4;
    s32 temp_6;
    s32 var_16;
    s32 var_17;
    s32 var_18;
    s32 var_2;
    s32 var_7;

    var_7 = arg3;
    var_2 = (arg5 < 0) ? -arg5 : arg5;
    temp_6 = var_2 + 0xFFF;
    temp_4 = ((s32)temp_6 / 4096);
    var_18 = arg4 - temp_4;
    var_17 = arg1 - (temp_4 * arg2);
    if (arg5 != 0) {
        temp_3 = arg2 * arg5;
        var_7 += temp_4 * 2;
        var_17 += ((s32)temp_3 / 4096);
    }
    if (var_7 > 0) {
        var_16 = var_7;
        do {
            var_16 -= 1;
            arg6(var_18, arg0, var_17);
            var_17 += arg2;
            var_18 += 1;
        } while (var_16 != 0);
    }
}

void func_002492A0(u8 *buf) /* DEBT(TYPE): argument unused, the global is reread */
{
    u32 *h = func_002DB6D8(1);

    *h |= 0x40;
    func_00124F08();
    func_002F8660(0);
    func_002DBA28(h, (int)D_0069BCD8); /* DEBT(CAST): b is a buffer address */
}

void func_002492F0(void)
{
    TkMenuDrawScissorClear();
    func_00245598();
    func_002492A0(D_0069BCD8);
    func_00124F08();
    func_00245548();
}
