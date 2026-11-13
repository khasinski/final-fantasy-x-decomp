/* tu_217 0x1ef910-0x1f1eb8: low; ~TODrawKick (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w5.h"
#include "ffx/r4.h"
#include "ffx/u3.h"
#include "ffx/v4.h"

void func_001EF910(void)
{
    func_001EFAD0(0x200, 0x1A0);
    D_006632B0 = func_002DB6D8(1);
}

/* DEBT(TYPE): declared int without a return value; a void callee would be tail-called by func_001EFA30 */
int func_001EF940(void)
{
    InvokedFromSelectCursor = (void *)D_006632B4; /* DEBT(CAST): D_006632B4 holds an address */
    GIF_CUR()->ul128 = 0;
    GIF_CUR()->ui32[0] = 0x70000000;
    GIF_NEXT();
    GIF_CUR()->ul128 = 0;
    GIF_NEXT();
}

void func_001EF978(void)
{
    u32 *buf = (u32 *)D_006632B4; /* DEBT(CAST): D_006632B4 holds an address */
    int n = ((char *)InvokedFromSelectCursor - (char *)buf) >> 4;

    buf[0] |= n - 1;
    buf[7] = (n - 2) | 0x50000000;
}

void TODrawKick(void)
{
    if ((((int)InvokedFromSelectCursor - D_006632B4) >> 4) >= 3) { /* DEBT(CAST): D_006632B4 holds an address */
        func_002F8660(0);
        func_002DA610_int(0, 0);
        func_002DBA28(D_006632B0, D_006632B4);
        func_002DA610(0, 0);
    }
}

/* DEBT(TYPE): int return, no value on the early exits (func_001EF940 is the tail call and is not sibcalled) */
int func_001EFA30(void)
{
    if (D_0032363C != 0) {
        if (!(InvokedFromSelectCursor < (void *)D_006632BC)) {
            func_001EF978();
            TODrawKick();
            return func_001EF940();
        }
    }
}

void *func_001EFA88(void)
{
    return InvokedFromSelectCursor;
}

void *func_001EFA98(void)
{
    return &D_006632D0;
}

void TOSetPktBuffAdrs(s32 base, s32 off1, s32 off2)
{
    D_006632B4 = base;
    D_006632B8 = base + off1;
    D_006632BC = base + off2;
}

void func_001EFAD0(s16 a, s16 b)
{
    D_00323638 = a;
    D_0032363A = b;
}

void func_001EFAE8(u16 *a, u16 *b)
{
    *a = D_00323638;
    *b = D_0032363A;
}

void func_001EFB08(void)
{
    GIF_AD_TAG(6);
    func_001FB290();
    func_001FB2C0(0, 1, 0, 1, 0x80);
    func_001FB358(1, 7, 0, 0, 0, 0, 0, 0);
    func_001FB3C0(0x3C00, 4, 0x13, 8, 9, 1, 0, 0x2EB8, 0, 0, 0, 1);
    func_001FB468(0, 0, 1, 1, 0, 0, 0);
    func_001FB4C8(1, 1, 0, 0, 0, 0);
    func_001EFA30();
}

void TOMakePktSampleBlueWindowXY2(int x0, int y0, int x1, int y1)
{
    GIF_CUR()->ul64[0] = 0x70A6400000008001UL;
    GIF_CUR()->ul64[1] = 0x441441E;
    GIF_NEXT();
    func_001FB2C0(0, 1, 0, 1, 0x80);
    locNameTmpSetLanguage(0x10, 0x10, 0x70, 0x58);
    func_001FB678(x0, y0);
    func_001FB678(x1, y0);
    locNameTmpSetLanguage(0x50, 0x50, 0x50, 0x60);
    func_001FB678(x0, y1);
    func_001FB678(x1, y1);
    func_001EFA30();
}

Quad32 *func_001EFCE0(GsAdPacket *p, int x0, int y0, int x1, int y1, int r, int g, int b, int a)
{
    Quad32 *q;

    p->data = 0x50A3400000008001UL;
    p->reg = 0x441EE;
    p = func_001FB918(p + 1, 0, 1, 0, 1, 0x80);
    p = func_001FB980(p, 1, 7, 0, 0, 0, 0, 0, 0);
    q = func_001FBB30((Quad32 *)p, r, g, b, a); /* DEBT(CAST): the packet continues with vertex quads */
    q = func_001FBBB0(q, x0, y0);
    return func_001FBBB0(q, x1, y1);
}

void func_001EFDF8(int x0, int y0, int x1, int y1, int r, int g, int b, int a)
{
    GIF_CUR()->ul64[0] = 0x50A3400000008001UL;
    GIF_CUR()->ul64[1] = 0x441EE;
    GIF_NEXT();
    func_001FB2C0(0, 1, 0, 1, 0x80);
    func_001FB358(1, 7, 0, 0, 0, 0, 0, 0);
    locNameTmpSetLanguage(r, g, b, a);
    func_001FB678(x0, y0);
    func_001FB678(x1, y1);
    func_001EFA30();
}

void TOMakePktBoxXYWHRGBA(int x, int y, int w, int h, int r, int g, int b, int a)
{
    GIF_CUR()->ul64[0] = 0x50A3400000008001UL;
    GIF_CUR()->ul64[1] = 0x441EE;
    GIF_NEXT();
    func_001FB2C0(0, 1, 0, 1, 0x80);
    func_001FB358(1, 7, 0, 0, 0, 0, 0, 0);
    locNameTmpSetLanguage(r, g, b, a);
    func_001FB678(x, y);
    func_001FB678(x + w, y + h);
    func_001EFA30();
}

void TOMakePktDirectBoxXYWH(int x, int y, int w, int h, int r, int g, int b, int a)
{
    GIF_CUR()->ul64[0] = 0x4003400000008001UL;
    GIF_CUR()->ul64[1] = 0x441E;
    GIF_NEXT();
    func_001FB358(1, 1, 0, 0, 0, 0, 0, 0);
    locNameTmpSetLanguage(r, g, b, a);
    func_001FB678(x, y);
    func_001FB678(x + w, y + h);
    func_001EFA30();
}

void func_001F0108(int x0, int y0, int x1, int y1, int r, int g, int b, int a)
{
    GIF_CUR()->ul64[0] = 0x50A3400000008001UL;
    GIF_CUR()->ul64[1] = 0x441EE;
    GIF_NEXT();
    func_001FB2C0(0, 1, 0, 1, 0x80);
    func_001FB358(1, 7, 0, 0, 0, 0, 0, 0);
    locNameTmpSetLanguage(r, g, b, a);
    func_001FB678(x0, y0);
    func_001FB678(x1, y1);
    func_001EFA30();
}

void func_001F0218(int x, int y, int w, int h, int r, int g, int b, int a)
{
    GIF_CUR()->ul64[0] = 0x50A3400000008001UL;
    GIF_CUR()->ul64[1] = 0x441EE;
    GIF_NEXT();
    func_001FB2C0(0, 1, 0, 1, 0x80);
    func_001FB358(1, 7, 0, 0, 0, 0, 0, 0);
    locNameTmpSetLanguage(r, g, b, a);
    func_001FB678(x, y);
    func_001FB678(x + w, y + h);
    func_001EFA30();
}

void func_001F0328(int x, int y, int w, int h, u32 c0, u32 c1)
{
    GIF_CUR()->ul64[0] = 0xA026400000008001UL;
    GIF_CUR()->ul64[1] = 0x41414141EEUL;
    GIF_NEXT();
    func_001FB2C0(0, 1, 0, 1, 0x80);
    func_001FB358(1, 7, 0, 0, 0, 0, 0, 0);
    func_001FB648(c0);
    func_001FB678(x, y);
    func_001FB648(c1);
    func_001FB678(x + w, y);
    func_001FB648(c0);
    func_001FB678(x, y + h);
    func_001FB648(c1);
    func_001FB678(x + w, y + h);
    func_001EFA30();
}

void func_001F0458(int x0, int y0, int x1, int y1, u32 c0, u32 c1)
{
    GIF_CUR()->ul64[0] = 0xA026400000008001UL;
    GIF_CUR()->ul64[1] = 0x41414141EEUL;
    GIF_NEXT();
    func_001FB2C0(0, 1, 0, 1, 0x80);
    func_001FB358(1, 7, 0, 0, 0, 0, 0, 0);
    func_001FB648(c0);
    func_001FB678(x0, y0);
    func_001FB648(c1);
    func_001FB678(x1, y0);
    func_001FB648(c0);
    func_001FB678(x0, y1);
    func_001FB648(c1);
    func_001FB678(x1, y1);
    func_001EFA30();
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1EF910", func_001F0580);

void func_001F0870(TextItem *, R4CharInfo *);
void func_001F0A20(TextItem *, R4CharInfo *);

void TOMakePktMovieFont1612(TextItem *it, R4CharInfo *ci)
{
    TextItem tmp = *it;

    tmp.y++;
    switch (it->f12) {
    case 1:
        func_001F0A20(it, ci);
        func_001F0A20(&tmp, ci);
        func_001F0870(it, ci);
        func_001F0870(&tmp, ci);
        it->x += ci->h10 + 4;
        break;
    case 3:
        func_001F1A48(it, ci);
        func_001F1A48(&tmp, ci);
        func_001F1850(it, ci);
        func_001F1850(&tmp, ci);
        it->x += ci->h10 + 4;
        break;
    default:
        func_001F0A20(it, ci);
        func_001F0A20(&tmp, ci);
        func_001F0870(it, ci);
        func_001F0870(&tmp, ci);
        it->x += ci->h10 + 4;
        break;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1EF910", func_001F0870);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1EF910", func_001F0A20);

void TOMakePktFont1612(TextItem *it, R4CharInfo *ci)
{
    switch (it->f12) {
    case 1:
        func_001F1408(it, ci);
        func_001F0D58(it, ci);
        it->x += ci->h10 + 4;
        break;
    case 3:
        func_001F1A48(it, ci);
        func_001F1850(it, ci);
        it->x += ci->h10 + 4;
        break;
    case 0:
    default:
        func_001F1028(it, ci);
        func_001F0D58(it, ci);
        it->x += ci->h10 + 2;
        break;
    }
}

void func_001F0D58(TextItem *it, R4CharInfo *ci)
{
    int cbp = 0x2EB8;
    int pal;

    GIF_CUR()->ul64[0] = 0x70AB400000008001UL;
    GIF_CUR()->ul64[1] = 0x43431EE;
    GIF_NEXT();
    pal = it->f13 & 0xF;
    if (pal >= 8) {
        cbp = 0x2EBC;
        pal -= 8;
    }
    func_001FB3C0(ci->h0, 2, 0x13, 7, 0xA, 1, 0, cbp, 0, 0, 0, 1);
    func_001FB3C0(ci->h0, 2, ci->h2, 7, 0xA, 1, 0, cbp, 0, 0, pal * 2 + ci->h4, 0);
    locNameTmpSetLanguage(it->col[0], it->col[1], it->col[2], it->col[3]);
    func_001FB550(ci->h6, ci->h8);
    func_001FB6B0(it->x, it->y + ci->hE, 1);
    func_001FB550(ci->hA, ci->hC);
    func_001FB678(it->x + ci->h10, it->y + ci->hE + ci->h12);
    func_001EFA30();
}

void func_001F0EC0(TextItem *it, R4CharInfo *ci)
{
    int cbp = 0x2EB8;
    int pal;

    GIF_CUR()->ul64[0] = 0x70AB400000008001UL;
    GIF_CUR()->ul64[1] = 0x43431EE;
    GIF_NEXT();
    pal = it->f13 & 0xF;
    if (pal >= 8) {
        cbp = 0x2EBC;
        pal -= 8;
    }
    func_001FB3C0(ci->h0, 2, 0x13, 7, 0xA, 1, 0, cbp, 0, 0, 0, 1);
    func_001FB3C0(ci->h0, 2, ci->h2, 7, 0xA, 1, 0, cbp, 0, 0, pal * 2 + ci->h4, 0);
    locNameTmpSetLanguage(it->col[0], it->col[1], it->col[2], it->col[3]);
    func_001FB550(ci->h6, ci->h8);
    func_001FB6B0(it->x, it->y + ci->hE, 1);
    func_001FB550(ci->hA, ci->hC);
    func_001FB678(it->x + ci->h10, it->y + ci->hE + ci->h12);
    func_001EFA30();
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1EF910", func_001F1028);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1EF910", func_001F11E0);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1EF910", func_001F1408);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1EF910", func_001F1630);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1EF910", func_001F1850);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1EF910", func_001F1A48);

void TOMakePktScissor(int x0, int y0, int x1, int y1)
{
    GIF_CUR()->ul64[0] = 0x1000000000008001UL;
    GIF_CUR()->ul64[1] = 0xE;
    GIF_NEXT();
    GIF_CUR()->ul64[0] = GS_SET_SCISSOR(x0, x1, y0, y1);
    GIF_CUR()->ul64[1] = 0x40;
    GIF_NEXT();
}

void func_001F1D60(int x0, int y0, int x1, int y1)
{
    GIF_CUR()->ul64[0] = 0x1000000000008001UL;
    GIF_CUR()->ul64[1] = 0xE;
    GIF_NEXT();
    GIF_CUR()->ul64[0] = GS_SET_SCISSOR(x0, x1, y0, y1);
    GIF_CUR()->ul64[1] = 0x40;
    GIF_NEXT();
}

void TODrawScissorXYWH(int x, int y, int w, int h)
{
    GIF_CUR()->ul64[0] = 0x1000000000008001UL;
    GIF_CUR()->ul64[1] = 0xE;
    GIF_NEXT();
    GIF_CUR()->ul64[0] = GS_SET_SCISSOR(x, x + w, y, y + h);
    GIF_CUR()->ul64[1] = 0x40;
    GIF_NEXT();
}

void func_001F1E18(int fbp, int fbw, int psm, int fbmsk)
{
    GIF_CUR()->ul64[0] = 0x1000000000008001UL;
    GIF_CUR()->ul64[1] = 0xE;
    GIF_NEXT();
    GIF_CUR()->ul64[0] = GS_SET_FRAME(fbp, fbw, psm, fbmsk);
    GIF_CUR()->ul64[1] = 0x4C;
    GIF_NEXT();
}

void func_001F1E70(int x, int y)
{
    GIF_CUR()->ul64[0] = 0x1000000000008001UL;
    GIF_CUR()->ul64[1] = 0xE;
    GIF_NEXT();
    GIF_CUR()->ul64[0] = ((u64)y << 32) | x;
    GIF_CUR()->ul64[1] = 0x18;
    GIF_NEXT();
}
