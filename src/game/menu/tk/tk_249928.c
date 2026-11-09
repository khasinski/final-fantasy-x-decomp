/* tu_272 0x249928-0x24b828: low; ~Tk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/s5.h"
#include "ffx/s6.h"
#include "ffx/u4.h"
#include "ffx/r5.h"
#include "ffx/v5.h"

int TkMenuGetCommandHelp(int id) {
    s32 pos;
    int sel = func_0013A398(id) != 0;
    OfsTbl *t = MsGetRomPlyCommand(id, &pos);

    pos += t->b[sel].x;
    return pos;
}

void func_00249988(int a, int b, int c) {
    u8 *p = D_0069BCDC;
    DmaTag *tag = (DmaTag *)p;
    u32 n;

    D_0069BCDC = p + 0x10;
    D_0069BCDC = (u8 *)func_001FE170(p + 0x10, c, a, b);
    n = ((u32)(D_0069BCDC - p) + 15) >> 4;
    tag->b3 = 0x10;
    tag->b2 = 0;
    tag->qwc = n - 1;
    tag->w4 = 0;
    tag->w8 = 0;
    tag->wC = 0x50000000 | (n - 1);
}

int func_00249A08(void) {
    return D_0069BCF8;
}

void TkMn2GetMainPos(void)
{
    func_002273A0(D_00573090, D_00326DA8);
    func_00227460(D_005730A0, &D_00326DA0);
    func_00227460(D_005730B0, D_0069BE30);
    func_002273A0(D_005730C0, D_0069BE38);
    D_00326D98 = TkMn2SeqGetColor(D_005730D0);
    D_00326DA4 = TkMn2SeqGetColor(D_005730E0);
}

int func_00249AA8(void)
{
    int r;

    D_0069BCEC = -1;
    r = func_0024AE38();
    switch (r) {
    case 10:
        TkMenuMainActiveMenu(15, 0);
        TkMenuMainSleepMenu(1);
        break;
    case 20:
        TkMenuMainActiveMenu(20, 0);
        TkMenuMainSleepMenu(1);
        break;
    case 4:
        TkMenuMainActiveMenu(6, 0);
        TkMenuMainSleepMenu(1);
        break;
    case 2:
        TkMenuMainActiveMenu(4, 0);
        TkMenuMainSleepMenu(1);
        break;
    case 0:
        TkMenuMainActiveMenu(3, 0);
        TkMenuMainSleepMenu(1);
        break;
    case 5:
        TkMenuMainActiveMenu(7, 0);
        TkMenuMainSleepMenu(1);
        break;
    case 1:
        TkMenuMainActiveMenu(2, 0);
        TkMenuMainSleepMenu(1);
        break;
    case 8:
        TkMenuMainActiveMenu(10, 0);
        TkMenuMainSleepMenu(1);
        break;
    case 15:
        TkMenuMainActiveMenu(21, 0);
        TkMenuMainSleepMenu(1);
        break;
    case 7:
        TkMenuMainActiveMenu(9, 0);
        TkMenuMainSleepMenu(1);
        break;
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_249928", TkMenuCtrlMain);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_249928/rodata", jtbl_00573150);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_249928", func_0024A4A0);

void func_0024AB60(void)
{
    func_00241FA0(0);
    func_00241FB0(0);
    TkMenuSetHelpMessage(TkMenuMainHelp(func_0024AE38(0)));
    D_0069BCE4 = 0;
    func_00241F70(0);
}

void func_0024ABA8(void)
{
    extern int func_00241FD0(); /* DEBT(TYPE): defined void in c_241240.c, int return matches the original register use */

    TkMenuSetHelpMessage(TkMenuMainHelp(func_0024AE38(D_0069BCE8)));
    D_0069BD00[0] = -1;
    D_0069BD00[1] = -1;
    D_0069BCF4 = 1;
    func_00241FD0(0);
    D_0032643C = 0;
    func_0020DC20(1);
    switch (D_0069BE2C) {
    case 6:
        TOSeqStartScene(1, D_00573240);
        break;
    case 7:
        TOSeqStartScene(1, D_00573248);
        break;
    case 8:
        TOSeqStartScene(1, D_00573250);
        break;
    case 9:
        TOSeqStartScene(1, D_00573258);
        break;
    case 10:
        TOSeqStartScene(1, D_00573260);
        break;
    default:
        TOSeqStartScene(1, D_00573268);
        break;
    }
}

void func_0024ACC8(void) {
    D_0069BCF4 = 0;
    func_0020DBC8(1);
}

void func_0024ACD8(void) {
    if (D_0069BCE0) {
        D_0069BCE0->b41 = 1;
        D_0069BCE0 = 0;
    }
    func_00241F70(0);
}

int func_0024ACF8(void) { return TkMenuGetPlayerFromIndex2(TkMenuGetCurrentPlayerPos()); }

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_249928", func_0024AD20);

int func_0024AE38(int i) {
    return D_0069BD08[i].w0;
}

int func_0024AE50(int i) {
    return D_0069BD08[i].h4;
}

int func_0024AE68(void) {
    return D_0069BE2C;
}

int func_0024AE78(int i) {
    return D_0069BD08[i].h6;
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_249928", func_0024AE90);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_249928", func_0024AF68);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_249928", func_0024B140);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_249928", TkMenuAppearMainCmdWindow);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_249928/rodata", jtbl_005732A0);

void func_0024B620(void) {
}

void func_0024B628(void) {
}

void func_0024B630(void) {
}

void func_0024B638(void)
{
    int pad[2]; /* DEBT(PADDING): unused frame */
}

void func_0024B648(void) {
}

void func_0024B650(void) {
}

void TkMenuCtrlAbilityMap2(Task *o) {
    s32 *state = &o->x1C;
    int st;

    func_00220318();
    TOMenuGetControlPadRep();
    TOMenuGetControlPadTrg();
    st = o->x1C;
    /* DEBT(GOTO): state machine re-dispatches with goto (no loop alignment in the original) */
again:
    switch (st) {
    case 0:
        if (TOMenuGetFirstReadEndFlag() != 0) {
            func_00264B20();
            *state = 1;
            st = 1;
            goto again;
        }
        break;
    case 1:
        eiAbmCalc();
        break;
    }
}

void func_0024B6E8(Task *o) {
    func_00124F08();
    TOMenuOpenPktBuffTmp();
    TODrawScissorXYWH(0, 0, 0x1FF, 0x19F);
    func_001F0328(0, 0, 0x1FF, 0x19F, 0x80000000, 0x80000000);
    TOMenuDrawKickTmp();
    func_00124F08();
    func_002492F0();
    func_002492F0();
    if (o->x1C != 0) {
        func_002659F8();
    }
    func_002492F0();
    func_002455C0();
    func_002492F0();
}

void func_0024B788(Task *t) {
    t->x1C = 0;
    func_00241F70(0);
    D_00326438 = 1;
}

void func_0024B7B8(void) {
    func_002653D8();
    D_00326438 = 0;
}

void func_0024B7E0(void) { eiAbmTerm(); }

void func_0024B7E8(void) { func_0025AE38(); }

void TOMenuTermAbilityMap2(void) {
    func_00241F70(0);
    SndSepPlaySimple(0x80000001);
    TkMenuMainSleepMenu(0x13);
    TkMenuMainActiveMenu(1, 0);
}
