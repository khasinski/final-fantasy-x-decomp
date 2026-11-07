/* tu_231 0x209460-0x20cc98: low; ~TOSetExeWindowArea (config/tu_map.tsv) */
#define TODrawMessageWindowForMenu _hdr_TODrawMessageWindowForMenu
#define TODrawMessageWindow _hdr_TODrawMessageWindow
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/t4.h"
#include "ffx/u3.h"
#include "ffx/v4.h"
#include "ffx/s4.h"
#undef TODrawMessageWindow
#undef TODrawMessageWindowForMenu

void func_00209460(s32 i)
{
    func_002EF0D0(D_0066B508[i], 0, 0x5C);
}

void TOSetExeWindowArea(int a)
{
    int i;

    if (a == 0) {
        for (i = 7; i >= 0; i--) {
            D_0066B508[i] = (MenuSlot *)&D_0066AF48[i]; /* DEBT(CAST) */
        }
    } else {
        for (i = 7; i >= 0; i--) {
            D_0066B508[i] = (MenuSlot *)&D_0066B228[i]; /* DEBT(CAST) */
        }
    }
}

void func_00209508(UiWidget *w)
{
    w->f06 = 0x1000;
    w->cur[0] = w->target[0];
    w->cur[1] = w->target[1];
    w->cur[2] = w->target[2];
    w->cur[3] = w->target[3];
}

MenuSlot *func_00209538(s32 idx)
{
    return D_0066B508[idx];
}

void TOOpenWindow(int i)
{
    MenuSlot *s = D_0066B508[i];

    s->w00 = 1;
    s->state = 0;
    s->fn[0](s);
    s = D_0066B508[i];
    s->state = 1;
    s->fn[5] = s->fn[1];
}

int TOControlWindow(int i)
{
    MenuSlot *m = D_0066B508[i];

    if (m->w00 == 0) {
        return 0;
    }
    return m->fn[5]();
}

int TOCloseWindow(int i)
{
    MenuSlot *s = D_0066B508[i];

    if (s->w00 != 0) {
        s->state = 3;
        s->fn[5] = s->fn[3];
    }
}

s16 func_00209630(s32 i)
{
    return D_0066B508[i]->w04;
}

void TODrawWindow(int i)
{
    MenuSlot *s = D_0066B508[i];

    if (s->w00 != 0) {
        s->fn[6](s);
    }
}

s32 func_00209690(s32 i, s16 v)
{
    D_0066B508[i]->state = v;
    return 0;
}

int TOGetWindowStatus(int i)
{
    return D_0066B508[i]->state;
}

int func_002096D0(int i, int v)
{
    MenuSlot *s = D_0066B508[i];

    s->w04 = v;
    TOInitWindowCallBack(s);
}

void func_002096F0(int i, int x, int y, int w, int h)
{
    MenuSlot *m = D_0066B508[i];

    m->w = w;
    m->h = h;
    m->x = x;
    m->y = y;
    m->x1 = x + w;
    m->y1 = y + h;
}

void func_00209728(s32 i, s32 *x, s32 *y, s32 *w, s32 *h)
{
    MenuSlot *s = D_0066B508[i];

    *x = s->x;
    *y = s->y;
    *w = s->w;
    *h = s->h;
}

void func_00209760(s32 i, u8 a, u8 b, u8 c, u8 d)
{
    D_0066B508[i]->b36 = a;
    D_0066B508[i]->b37 = b;
    D_0066B508[i]->b38 = c;
    D_0066B508[i]->b39 = d;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_209460", TOInit);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_209460", TOReset1);

void func_00209B68(void)
{
    func_0020DD38();
    TkMenuInitSeq();
    TkMenuSetSceneDataAdrs(0, (TblEntry *)D_0066B5A0); /* DEBT(CAST): table is typed as bytes elsewhere */
    TkMenuSetSceneDataAdrs(1, (TblEntry *)D_0066BDA0); /* DEBT(CAST) */
    TkMenuSetSceneDataAdrs(2, (TblEntry *)D_00670DA0); /* DEBT(CAST) */
    TOSeqInitParam();
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_209460", TOSeqInitParam);

void TOSetExeMessageWindowArea(int a)
{
    int i;

    if (a == 0) {
        for (i = 7; i >= 0; i--) {
            D_0068F0A8[i] = (MenuSlot *)&D_0068EEE8[i]; /* DEBT(CAST) */
        }
    } else {
        for (i = 7; i >= 0; i--) {
            D_0068F0A8[i] = (MenuSlot *)&D_0068EFC8[i]; /* DEBT(CAST) */
        }
    }
    func_0020A7A8(a);
    TOSetExeWindowArea(a);
    TOSetExeMessageArea(a);
}

void func_0020A758(void) {
}

/* DEBT(FAKE) */
s32 TOGetInternationalBaseDicType(void) {
    register s32 var_3 __asm__("$3");

    if (func_0020B850() == 0) {
        var_3 = (func_001BD360() == 0) ? 0 : 4;
    } else {
        var_3 = 4;
    }
    return var_3;
}

s32 func_0020A798(void)
{
    return D_0068EEDC;
}

void func_0020A7A8(s32 v)
{
    D_0068EEDC = v;
}

void func_0020A7B8(void)
{
    int i;

    for (i = 0; i < 8; i++) {
        R4PT(i)->p10->h0 = 0;
        R4PT(i)->p14->h0 = 0;
        R4PT(i)->p18->b0 = 0;
        R4PT(i)->p10->h8 = 0;
        R4PT(i)->p14->h2C = 0;
        R4PT(i)->p18->b1 = 0;
    }
}

void func_0020A818(void) {
}

int TOInitMessageWindow(int i) /* DEBT(TYPE): declared int, no return value in the asm */
{
    func_002EF0D0(D_0068F0A8[i], 0, 0x1C);
    R4PT(i)->p10 = (R4Hdr *)func_00209538(i); /* DEBT(CAST): R4Hdr is the R4Ptrs view of MenuSlot */
    R4PT(i)->p14 = (R4Cmd *)func_002043D0(i); /* DEBT(CAST): R4Cmd is the R4Ptrs view of MenuCmd */
    R4PT(i)->p18 = (R4Info *)func_002043E8(i); /* DEBT(CAST): R4Info is the R4Ptrs view of SlotZ */
    func_002EF0D0(R4PT(i)->p10, 0, 0x5C);
    func_00204168(i);
    R4PT(i)->p10->h2 = i;
    R4PT(i)->p14->h4 = i;
    D_0068F0A8[i]->w04 = -1;
    R4PT(i)->p14->fDC = (MenuFn)func_00207AA0;
}

int TOOpenMessageWindow(int w)
{
    D_0068F0A8[w]->w00 = 1;
    TOOpenWindow(w);
    TOOpenMessage(w);
}

void TOCloseMessageWindow(int i)
{
    TOCloseWindow(i);
    TOCloseMessage(i);
}

void func_0020A948(int i)
{
    R4PT(i)->p10->h0 = 0;
    R4PT(i)->p14->h0 = 0;
    R4PT(i)->p18->b0 = 0;
    R4PT(i)->p10->h8 = 0;
    R4PT(i)->p14->h2C = 0;
    R4PT(i)->p18->b1 = 0;
}

void func_0020A998(void)
{
    int i;
    int r;

    TOGetPadStatus();
    for (i = 0; i < 8; i++) {
        if (D_0068F0A8[i]->w00 != 0) {
            r = TOControlWindow(i);
            TOControlMessage(i);
            if (r != 0) {
                TOSetMessageFunc(i, R4PT(i)->p10->h8);
            }
            if (D_0068F0A8[i]->w06 == 1) {
                TOGetControlPadStatus(i);
            }
        }
    }
}

s32 *_m2c_TODrawMessageWindow_MsGetSaveMenu() __asm__("MsGetSaveMenu");
void _m2c_TODrawMessageWindow_TODrawBtlWindow() __asm__("TODrawBtlWindow");
void _m2c_TODrawMessageWindow_TODrawKick() __asm__("TODrawKick");
void _m2c_TODrawMessageWindow_TODrawMessage(s32) __asm__("TODrawMessage");
void _m2c_TODrawMessageWindow_TODrawWindow(s32) __asm__("TODrawWindow");
void _m2c_TODrawMessageWindow_TOInitAddPkt() __asm__("TOInitAddPkt");
void _m2c_TODrawMessageWindow_TOMakePktScissor(s32, s32, s32, s32) __asm__("TOMakePktScissor");
void _m2c_TODrawMessageWindow_TOSetAddPkt() __asm__("TOSetAddPkt");
void _m2c_TODrawMessageWindow_TOSetPktBuffAdrs(s32, s32, s32) __asm__("TOSetPktBuffAdrs");
void _m2c_TODrawMessageWindow_TOTransTexture() __asm__("TOTransTexture");
void _m2c_TODrawMessageWindow_func_001EF940() __asm__("func_001EF940");
void _m2c_TODrawMessageWindow_func_001EF978() __asm__("func_001EF978");
void _m2c_TODrawMessageWindow_func_001EFB08() __asm__("func_001EFB08");
void _m2c_TODrawMessageWindow_func_001FC3C8(s32, s32) __asm__("func_001FC3C8");
void _m2c_TODrawMessageWindow_func_0020B520(void *) __asm__("func_0020B520");
void _m2c_TODrawMessageWindow_func_0020E5F0() __asm__("func_0020E5F0");
void _m2c_TODrawMessageWindow_func_0020EC88() __asm__("func_0020EC88");
/* DEBT(CAST) */
void TODrawMessageWindow(void) {
    u8 sp[0x10];
    MenuSlot **var_17;
    s16 temp_2;
    s32 var_16;
    void *temp_4;

    var_16 = 0;
    _m2c_TODrawMessageWindow_TOSetAddPkt();
    _m2c_TODrawMessageWindow_TOTransTexture();
    _m2c_TODrawMessageWindow_TOSetPktBuffAdrs(0x01F00000, 0x100000, 0xF0000);
    _m2c_TODrawMessageWindow_func_001EF940();
    _m2c_TODrawMessageWindow_func_0020B520(sp);
    _m2c_TODrawMessageWindow_TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    _m2c_TODrawMessageWindow_func_001EFB08();
    var_17 = D_0068F0A8;
    do {
        if ((((s32) *_m2c_TODrawMessageWindow_MsGetSaveMenu() >> 9) & 1) || (temp_4 = (*(void **)((u8 *)(*var_17) + (0x14))), ((*(s32 *)((u8 *)(temp_4) + (8))) != 2)) || ((temp_2 = (*(s16 *)((u8 *)(temp_4) + (0x1A))), (temp_2 != 1)) && (temp_2 != 3)) || ((*(u16 *)((u8 *)(temp_4) + (0x10))) == 0x4000) || ((*(s16 *)((u8 *)(temp_4) + (0xC))) != 0) || (D_0068EEDC != 0)) {
            _m2c_TODrawMessageWindow_TODrawWindow(var_16);
            _m2c_TODrawMessageWindow_TODrawMessage(var_16);
        }
        var_16 += 1;
        var_17 = (MenuSlot **)((u8 *)var_17 + (4));
    } while (var_16 < 8);
    _m2c_TODrawMessageWindow_TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    _m2c_TODrawMessageWindow_TODrawBtlWindow();
    _m2c_TODrawMessageWindow_TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    _m2c_TODrawMessageWindow_func_0020E5F0();
    _m2c_TODrawMessageWindow_TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    if (D_00323958 != 0) {
        _m2c_TODrawMessageWindow_func_001FC3C8(0xA, 0x172);
    }
    _m2c_TODrawMessageWindow_func_001EF978();
    _m2c_TODrawMessageWindow_TODrawKick();
    D_003238D0.pad00[0] = 1;
    _m2c_TODrawMessageWindow_TOInitAddPkt();
    _m2c_TODrawMessageWindow_func_0020EC88();
}

void func_0020AC10(void)
{
    int i;
    int r;

    for (i = 0; i < 8; i++) {
        if (D_0068F0A8[i]->w00 != 0) {
            r = TOControlWindow(i);
            TOControlMessage(i);
            if (r != 0) {
                TOSetMessageFunc(i, R4PT(i)->p10->h8);
            }
            if (D_0068F0A8[i]->w06 == 1) {
                TOGetControlPadStatus(i);
            }
        }
    }
}

s32 *_m2c_TODrawMessageWindowForMenu_MsGetSaveMenu() __asm__("MsGetSaveMenu");
s32 _m2c_TODrawMessageWindowForMenu_TODrawKick() __asm__("TODrawKick");
s32 _m2c_TODrawMessageWindowForMenu_TODrawMessage(s32) __asm__("TODrawMessage");
s32 _m2c_TODrawMessageWindowForMenu_TODrawWindow(s32) __asm__("TODrawWindow");
s32 _m2c_TODrawMessageWindowForMenu_TOMakePktScissor(s32, s32, s32, s32) __asm__("TOMakePktScissor");
s32 _m2c_TODrawMessageWindowForMenu_TOSetPktBuffAdrs(s32, s32, s32) __asm__("TOSetPktBuffAdrs");
s32 _m2c_TODrawMessageWindowForMenu_func_001EF940() __asm__("func_001EF940");
s32 _m2c_TODrawMessageWindowForMenu_func_001EF978() __asm__("func_001EF978");
s32 _m2c_TODrawMessageWindowForMenu_func_001EFB08() __asm__("func_001EFB08");
s32 _m2c_TODrawMessageWindowForMenu_func_0020B520(void *) __asm__("func_0020B520");
/* DEBT(CAST) */
void TODrawMessageWindowForMenu(void) {
    u8 sp[0x10];
    MenuSlot **var_17;
    s16 temp_2;
    s32 var_16;
    void *temp_4;

    var_16 = 0;
    _m2c_TODrawMessageWindowForMenu_TOSetPktBuffAdrs(0x01F00000, 0x100000, 0xF0000);
    _m2c_TODrawMessageWindowForMenu_func_001EF940();
    _m2c_TODrawMessageWindowForMenu_func_0020B520(sp);
    _m2c_TODrawMessageWindowForMenu_TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    _m2c_TODrawMessageWindowForMenu_func_001EFB08();
    var_17 = D_0068F0A8;
    do {
        if ((((s32) *_m2c_TODrawMessageWindowForMenu_MsGetSaveMenu() >> 9) & 1) || (temp_4 = (*(void **)((u8 *)(*var_17) + (0x14))), ((*(s32 *)((u8 *)(temp_4) + (8))) != 2)) || ((temp_2 = (*(s16 *)((u8 *)(temp_4) + (0x1A))), (temp_2 != 1)) && (temp_2 != 3)) || ((*(u16 *)((u8 *)(temp_4) + (0x10))) == 0x4000) || ((*(s16 *)((u8 *)(temp_4) + (0xC))) != 0) || (D_0068EEDC != 0)) {
            _m2c_TODrawMessageWindowForMenu_TODrawWindow(var_16);
            _m2c_TODrawMessageWindowForMenu_TODrawMessage(var_16);
        }
        var_16 += 1;
        var_17 = (MenuSlot **)((u8 *)var_17 + (4));
    } while (var_16 < 8);
    _m2c_TODrawMessageWindowForMenu_TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    _m2c_TODrawMessageWindowForMenu_func_001EF978();
    _m2c_TODrawMessageWindowForMenu_TODrawKick();
    D_003238D0.pad00[0] = 1;
}

void TOAllCloseMessageWindow(void)
{
    int i;

    for (i = 0; i < 8; i++) {
        TOCloseWindow(i);
        TOCloseMessage(i);
    }
}

void func_0020AE58(void)
{
    int i;

    for (i = 0; i < 8; i++) {
        R4PT(i)->p10->h0 = 0;
        R4PT(i)->p14->h0 = 0;
        R4PT(i)->p18->b0 = 0;
        R4PT(i)->p10->h8 = 0;
        R4PT(i)->p14->h2C = 0;
        R4PT(i)->p18->b1 = 0;
    }
}

void func_0020AEB8(int i, int mode, int v)
{
    func_002096D0(i, mode);
    TOSetMessageType(i, v);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_209460", TOSetMessageWindowPosition);
INCLUDE_RODATA("build/ee_asm/game/menu/to/to_209460/rodata", jtbl_00570840);

void TOSetMessageWindowPositionRect(int i, int align, int x, int y, int w, int h)
{
    switch (align) {
    case 0:
        break;
    case 4:
        x -= w / 2;
        y -= h / 2;
        break;
    case 2:
        x -= w;
        break;
    case 3:
        x -= w;
        /* fallthrough */
    case 1:
        y -= h;
        break;
    }
    w = R4_CLAMP(w, 0, 0x1FF);
    h = R4_CLAMP(h, 4, 0x19B);
    x = R4_CLAMP(x, 0, 0x1FF - w);
    y = R4_CLAMP(y, 4, 0x19B - h);
    func_0020B308(i, x, y, w, h);
}

int func_0020B238(int font, u8 *text)
{
    s16 size[2];
    int k = R4PT(font)->p10->h4;
    s16 x = D_00323848[k].x + D_00323848[k].w;
    s16 y = D_00323848[k].y + D_00323848[k].h;

    _TOGetMessageWH(font, text, &size[0], &size[1], R4PT(font)->p14->h1A, 0);
    x += R4PT(font)->p14->h3C;
    y += R4PT(font)->p14->h3E;
    return (y << 16) | x;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_209460", func_0020B308);

void TOSetSelectMessageWindow(int i, int a, int b, int c)
{
    R4PT(i)->p14->h1C = 1;
    R4PT(i)->p18->b1 = 0;
    R4PT(i)->p18->b2 = a;
    R4PT(i)->p18->b3 = b;
    R4PT(i)->p18->b7 = 0;
    R4PT(i)->p18->b6 = c;
    R4PT(i)->p14->fDC = TOFuncPadMessageSelect;
}

void func_0020B478(int i, int x, int y, int v)
{
    int n;

    if (x < 8) {
        n = x;
        if (n < 0) {
            n = 0;
        }
    } else {
        n = 7;
    }
    if (y < 8) {
        if (y < 0) {
            y = 0;
        }
    } else {
        y = 7;
    }
    R4PT(i)->p18->b2 = n;
    R4PT(i)->p18->b3 = y;
    R4PT(i)->p18->w10 = v;
    R4PT(i)->p14->fDC = TOFuncPadMessageInputValue;
    R4PT(i)->p18->wC = v;
}

void TOSetMessageWindowPriority(int i, int v)
{
    D_0068F0A8[i]->w04 = v;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_209460", func_0020B520);

int func_0020B6A8(int i)
{
    int j;

    for (j = 0; j < 8; j++) {
        D_0068F0A8[j]->w06 = 0;
    }
    D_0068F0A8[i]->w06 = 1;
}

void func_0020B6F0(s32 v)
{
    D_0068EEE0 = v;
}

s32 TOGetMessageWindowMode(void)
{
    return D_0068EEE0;
}

void func_0020B710(void)
{
    switch (FFXGetLang()) {
    case 0:
        switch (func_002D9880()) {
        case 0:
            D_0068F190 = 0;
            D_0068F194 = 1;
            D_0068F198 = 0;
            break;
        case 1:
            D_0068F190 = 0x11;
            D_0068F194 = 1;
            D_0068F198 = 0;
            break;
        case 2:
            D_0068F190 = 0x12;
            D_0068F194 = 1;
            D_0068F198 = 0;
            break;
        }
        break;
    case 1:
        D_0068F190 = 1;
        D_0068F194 = 0;
        D_0068F198 = 0;
        break;
    case 6:
        D_0068F190 = 2;
        D_0068F194 = 0;
        D_0068F198 = 1;
        break;
    case 2:
        D_0068F190 = 3;
        D_0068F194 = 0;
        D_0068F198 = 1;
        break;
    case 3:
        D_0068F190 = 4;
        D_0068F194 = 0;
        D_0068F198 = 1;
        break;
    case 4:
        D_0068F190 = 5;
        D_0068F194 = 0;
        D_0068F198 = 1;
        break;
    case 5:
        D_0068F190 = 6;
        D_0068F194 = 0;
        D_0068F198 = 1;
        break;
    }
}

s32 func_0020B850(void)
{
    return D_0068F190;
}

s32 TOGetFFXLangSwapFlag(void)
{
    return D_0068F194;
}

s32 TOGetFFXVideoMode(void)
{
    return D_0068F198;
}

s32 func_0020B880(int i)
{
    return D_0066B530[i].w0;
}

s32 TOGetFontWidthTblAdrs(int i)
{
    return D_0066B530[i].w4;
}

s32 func_0020B8B0(void)
{
    return D_0066B590;
}

u32 func_0020B8C0(void)
{
    return D_0066B594;
}

s32 func_0020B8D0(void)
{
    return D_0066B58C;
}

s32 func_0020B8E0(void)
{
    return D_0066B588;
}

s32 func_0020B8F0(void)
{
    return D_0066B598;
}

void *func_0020B900(void)
{
    return &D_0066B5A0;
}

void *func_0020B910(void)
{
    return &D_0066BDA0;
}

void *func_0020B920(void)
{
    return &D_00670DA0;
}

void TOSwapInternationalEnvInit(int a)
{
    MsSetSaveConfigEnglish_void(a);
    D_003238A8 = 0;
    switch (a) {
    case 1:
        D_003238AC = 4;
        break;
    default:
        D_003238AC = 0x12;
        break;
    }
    D_003238B0 = 0;
    D_003238B4 = 0;
    D_003238B8 = 0;
}

/* DEBT(CAST): shared declarations retain untyped handles or buffers at these calls. */
s32 TOSwapInternationalEnvExec(void)
{
    D_003238B4 = 1;
    func_0020CC20((s8 *) D_003238AC, 0xB, func_0020B8B0());
    func_0020CC20((s8 *) D_003238AC, 0xA, func_0020B8C0());
    func_0020CC20((s8 *) D_003238AC, 0xF, func_0020B8D0());
    func_0020CC20((s8 *) D_003238AC, 0xE, func_0020B8E0());
    func_0020CC20((s8 *) D_003238AC, 8, func_0020B8F0());
    func_0020CC20((s8 *) D_003238AC, 6, D_00324140);
    func_0020CC20((s8 *) D_003238AC, 5, TOGetFFXToAlbhedTblAdrs());
    func_0020CC20((s8 *) D_003238AC, 7, D_00323960);
    func_0020DC78(2);
    func_0020CC20((s8 *) D_003238AC, 0x16, D_00670DA0);
    TkMenuSetSceneDataAdrs(2, (TblEntry *) D_00670DA0);
    TOSeqInitParam();
    MsBattleReadData();
    D_003238B4 = 0;
    D_003238B0 = 1;
    return 1;
}

s32 TOSwapInternationalEnvExecNonBlock(void)
{
    s32 *st = &D_003238A8;

    switch (*st) {
    case 0:
        D_003238B4 = 1;
        *st = 1;
        break;
    case 1:
        *st = 2;
        break;
    case 2:
        func_0020CD30(D_003238AC, 0xB, func_0020B8B0());
        *st = 3;
        break;
    case 3:
        if (func_0020CDB8() == 0) {
            *st = 4;
        }
        break;
    case 4:
        func_0020CD30(D_003238AC, 0xA, func_0020B8C0());
        *st = 5;
        break;
    case 5:
        if (func_0020CDB8() == 0) {
            *st = 6;
        }
        break;
    case 6:
        func_0020CD30(D_003238AC, 0xF, func_0020B8D0());
        *st = 7;
        break;
    case 7:
        if (func_0020CDB8() == 0) {
            *st = 8;
        }
        break;
    case 8:
        func_0020CD30(D_003238AC, 0xE, func_0020B8E0());
        *st = 9;
        break;
    case 9:
        if (func_0020CDB8() == 0) {
            *st = 10;
        }
        break;
    case 10:
        func_0020CD30(D_003238AC, 8, func_0020B8F0());
        *st = 11;
        break;
    case 11:
        if (func_0020CDB8() == 0) {
            *st = 12;
        }
        break;
    case 12:
        func_0020CD30(D_003238AC, 6, (int)D_00324140); /* DEBT(CAST): buffer address passed as int */
        *st = 13;
        break;
    case 13:
        if (func_0020CDB8() == 0) {
            *st = 14;
        }
        break;
    case 14:
        func_0020CD30(D_003238AC, 5, (int)TOGetFFXToAlbhedTblAdrs()); /* DEBT(CAST): buffer address passed as int */
        *st = 15;
        break;
    case 15:
        if (func_0020CDB8() == 0) {
            *st = 16;
        }
        break;
    case 16:
        func_0020CD30(D_003238AC, 7, (int)D_00323960); /* DEBT(CAST): buffer address passed as int */
        *st = 17;
        break;
    case 17:
        if (func_0020CDB8() == 0) {
            *st = 18;
        }
        break;
    case 18:
        func_0020DC78(2);
        *st = 19;
        /* fallthrough */
    case 19:
        func_0020CD30(D_003238AC, 0x16, (int)D_00670DA0); /* DEBT(CAST): buffer address passed as int */
        *st = 20;
        break;
    case 20:
        if (func_0020CDB8() == 0) {
            *st = 21;
        }
        break;
    case 21:
        TkMenuSetSceneDataAdrs(2, (TblEntry *)D_00670DA0); /* DEBT(CAST): table loaded into a byte buffer */
        TOSeqInitParam();
        *st = 22;
        break;
    case 22:
        *st = 23;
        D_003238B8 = 0;
        break;
    case 23:
        if (MsBattleReadDataNB(D_003238B8) != 0) {
            *st = 24;
        } else {
            *st = 26;
        }
        break;
    case 24:
        if (GetCD()->f8(1) == 0) {
            *st = 25;
        }
        break;
    case 25:
        *st = 23;
        D_003238B8++;
        break;
    case 26:
        *st = 27;
        break;
    case 27:
        *st = 28;
        break;
    case 28:
        D_003238B0 = 1;
        D_003238B4 = 0;
        break;
    }
    if (D_00323958) {
        TODapsSetPos(0x1E, 0x1E);
        TODapsPrintf(D_005708A0, D_003238A8);
        TODapsPrintf(D_005708B0, D_003238B8);
    }
    return D_003238B0;
}

s32 func_0020BED0(void)
{
    return D_003238B4;
}

int func_0020BEE0(void)
{
    int r = TOGetFFXLangSwapFlag();

    if (r == 1 && func_001BD360() == r) {
        return 4;
    }
    return 0x12;
}

void TOSwapInternationalEnvInitMenu(int a)
{
    MsSetSaveConfigEnglish_void(a);
    D_003238BC = 0;
    switch (a) {
    case 1:
        D_003238C0 = 4;
        break;
    default:
        D_003238C0 = 0x12;
        break;
    }
    D_003238C4 = 0;
}

int TOSwapInternationalEnvExecMenu(void)
{
    s32 *st = &D_003238BC;

    switch (*st) {
    case 0:
        *st = 1;
        break;
    case 1:
        *st = 2;
        break;
    case 2:
        func_0020CD30(D_003238C0, 0xD, 0x1D3EB00);
        *st = 3;
        break;
    case 3:
        if (func_0020CDB8() == 0) {
            *st = 6;
        }
        break;
    case 6:
        D_003238C4 = 1;
        break;
    }
    return D_003238C4;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_209460", TOSwapInternationalMessageWindow);

int TOGetSaveChrName(int i)
{
    if (i >= 20) {
        return (int)func_001BB190(i); /* DEBT(CAST) */
    }
    if (func_0020B850() == 0 && func_001BD360() == 0) {
        func_0014D718((u8 *)MsGetSaveChrName(i), D_0068F1A0[i]);
        return (int)D_0068F1A0[i]; /* DEBT(CAST): returns the record address */
    }
    return (int)MsGetSaveChrName(i); /* DEBT(CAST) */
}

void TOInitPadData(void)
{
    func_002EF0D0(&D_003238D0, 0, 0x40);
    D_003238D0.b1E = 0x80;
    D_003238D0.b1F = 0x80;
    D_003238D0.b20 = 0x80;
    D_003238D0.b21 = 0x80;
}

/* DEBT(TYPE): buffer addresses are stored in the s32 members of R4Rec16 */
INCLUDE_ASM("build/ee_asm/game/menu/to/to_209460", TOFTCTransfer);
INCLUDE_RODATA("build/ee_asm/game/menu/to/to_209460/rodata", jtbl_00570960);

void TOTransImageHL(u32 addr, int dbp, int psm, int x, int y, int w, int h)
{
    Qword tag[2];
    u32 *ch = func_002DB6D8(2);
    int size;
    int qwc;
    int bw;

    tag[0].ul128 = 0;
    tag[0].ui32[0] = 0x30000006;
    tag[0].ui32[1] = (u32)D_0068F0D0;
    switch (psm) {
    case 0:
        size = w * (h << 2);
        break;
    case 1:
        size = w * ((h << 1) + h); /* DEBT(ORDER): h scaled first (as shifts) so it is not folded into w * h */
        break;
    case 2:
    case 10:
        size = w * (h << 1);
        break;
    case 19:
    case 27:
        size = w * h;
        break;
    case 20:
    case 36:
    case 44:
        size = w / 2 * h;
        break;
    }
    bw = w / 64;
    qwc = size / 16;
    if (bw == 0) {
        bw = 1;
    }
    tag[1].ul128 = 0;
    tag[1].ui32[1] = addr;
    D_0068F0D0[0] = 0x1000000000000004;
    D_0068F0D0[1] = 0xE;
    D_0068F0D0[2] = ((u64)dbp << 32) | ((u64)bw << 48) | ((u64)psm << 56);
    D_0068F0D0[3] = 0x50;
    D_0068F0D0[4] = ((u64)x << 32) | ((u64)y << 48);
    D_0068F0D0[5] = 0x51;
    D_0068F0D0[6] = w | ((u64)h << 32);
    D_0068F0D0[7] = 0x52;
    D_0068F0D0[8] = 0;
    D_0068F0D0[9] = 0x53;
    D_0068F0D0[10] = qwc | 0x8000 | ((u64)0x8000 << 44);
    D_0068F0D0[11] = 0x54;
    tag[1].ui32[0] = qwc;
    func_002F8660(0);
    func_002DA610(0, 0);
    func_002DBA28(ch, (int)tag); /* DEBT(CAST): chain address passed as int */
    func_002DA610(0, 0);
}

void func_0020C660(int dst, int a, int b, int c, int d, int e, int f)
{
    u8 ctx[0x70];

    func_002DAB10_s(ctx, a, e / 64, b, c, d, e, f);
    func_002F8660(0);
    func_002DA610(0, 0);
    func_002DADD0(ctx, dst);
    func_002DA610(0, 0);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_209460", func_0020C700);

void TOTransTexture(void)
{
    R4Rec16 *temp_2;

    temp_2 = &D_0066B530[TOGetInternationalBaseDicType()];
    TOTransImageHL((u32) temp_2->w0, 0x3C00, 0x14, 0, 0, (s32) temp_2->hC, (s32) temp_2->hE);
    if (MsBattleGetStatus() != 0)
    {
        if (func_001AF320() != 0)
        {
            TOTransImageHL((u32) D_0066B530[2].w0, 0x3D00, 0x14, 0, 0, (s32) D_0066B530[2].hC, (s32) D_0066B530[2].hE);
        }
        if (func_0020B850() == 0)
        {
            TOTransImageHL((u32) D_0066B530[4].w0, 0x3D40, 0x14, 0, 0, (s32) D_0066B530[4].hC, (s32) D_0066B530[4].hE);
        }
    }
    else if (func_0014D7C0() != 0)
    {
        TOTransImageHL((u32) D_0066B530[1].w0, 0x3D00, 0x14, 0, 0, (s32) D_0066B530[1].hC, (s32) D_0066B530[1].hE);
    }
    TOTransImageHL(D_0066B584, 0x3D80, 0x14, 0, 0, 0x80, 0x100);
    TOTransImageHL((u32) D_0066B588, 0x3DC0, 0x14, 0, 0, 0x100, 0x80);
    TOTransImageHL((u32) D_0066B590, 0x3E00, 0x13, 0, 0, 0x100, 0x100);
    TOTransImageHL(func_0020B8C0(), 0x3F00, 0x13, 0, 0, 0x100, 0x100);
    TOTransImageHL((u32) D_0066B598, 0x2EA0, 0, 0, 0, 0x40, 0x40);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_209460", func_0020CA38);

void func_0020CBE8(void)
{
    TOTransImageHL(func_0020B8C0(), 0x3F00, 0x13, 0, 0, 0x100, 0x100);
}

void func_0020CC20(const char *name, int id, void *buf)
{
    SysVt *vt = GetCD();

    vt->f10(name);
    vt->f0(id, buf, 0, 0);
    vt->f8(0);
}
