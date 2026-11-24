/* tu_272 0x249928-0x24b828: low; ~Tk (config/tu_map.tsv) */
#define D_0069BCE4 _hdr_D_0069BCE4
#define SndSepPlaySimple _hdr_SndSepPlaySimple
#define func_00241FB0 _hdr_func_00241FB0
#define TkMenuGetCurrentPlayer _hdr_TkMenuGetCurrentPlayer
#include "common.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/s5.h"
#include "ffx/s6.h"
#include "ffx/u4.h"
#include "ffx/r5.h"
#include "ffx/v5.h"
#undef D_0069BCE4
#undef SndSepPlaySimple
#undef func_00241FB0
#undef TkMenuGetCurrentPlayer
extern s16 D_0069BCE4;
int SndSepPlaySimple(u32 id);
int func_00241FB0(int a);
int TkMenuGetCurrentPlayer(void);

typedef struct {
    s8 c[2];
} ColonStr;

extern ColonStr D_00573288;
extern char D_00573290[];
extern char D_00573298[];
extern s16 D_0069BE08[];
extern s16 D_0069BE18[];
extern s16 D_0069BE28;
int TkMenuMainGetMenuActiveMask(void);
void func_0024AF68(int a, int b, int c, int d, int e);

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

int TkMn2SetMainFrameRatioDiff(int a);
int TkMn2GetMainFrameRatio(void);
int func_0024AE50(int i);
int func_0024AE78(int i);
int func_0024AE68(void);
extern int func_00241FD0();
int func_00242818(void);
void func_00242930(int a);
void func_00242A90(void);
void func_00242A40(void);
int MsGetSavePlyJoin(int chr);
void TkMsSetSaveParamAll(void);
void TkMenuExchangePlayerPos(int a, int b);
void TkMenuMainFreeWindowGroup(int a);
int TkMenuGetDrawShadeRatio(void);

void TkMenuCtrlMain(Task *o)
{
    s32 *state;
    int st;
    int rep;
    int trg;
    int r;

    func_00220318();
    rep = TOMenuGetControlPadRep();
    trg = TOMenuGetControlPadTrg();
    D_0069BCE4 += 0xAA;
    if (D_0069BCE4 >= 0x1000) {
        D_0069BCE4 = 0x1000;
    }
    st = o->x1C;
    state = &o->x1C;
again:
    switch (st) {
    case 0:
        TkMn2SetMainFrameRatioDiff(-0x10);
        *state = 1;
        break;
    case 1:
        if (D_0069BCE4 >= 0x1000 && D_0069BE28 == 0) {
            *state = 2;
        }
        break;
    case 2:
    case 3:
        func_00241FD0(0);
        *state = 4;
        break;
    case 4:
        *state = 5;
    case 5:
        if (trg & 0x20) {
            if (func_0024AE50(D_0069BCE8) != 0) {
                SndSepPlaySimple(0x80000001);
                if (func_0024AE38(D_0069BCE8) == 6) {
                    st = 0xA;
                    goto again;
                }
                if (func_0024AE78(D_0069BCE8) == 0) {
                    r = ((int (*)(int))func_00249AA8)(D_0069BCE8);
                    if (r == 3) {
                        *state = 0x1B;
                        st = 0x1B;
                        goto again;
                    }
                    if (r == 9) {
                        *state = 0x1F;
                        st = 0x1F;
                        goto again;
                    }
                    *state = 0x19;
                    st = 0x19;
                    goto again;
                }
                if (func_0024AE78(D_0069BCE8) == 2) {
                    func_00241FD0(1);
                } else {
                    func_00241FD0(0);
                    if (TkMenuGetCurrentPlayerPos() >= func_00242818()) {
                        func_00242930(func_00242818() - 1);
                    }
                }
                *state = 6;
            } else {
                SndSepPlaySimple(0x80000003);
            }
        } else if (trg & 0x40) {
            SndSepPlaySimple(0x80000004);
            *state = 0x23;
        } else if (rep & 0x1000) {
            SndSepPlaySimple(0x80000001);
            D_0069BCE8--;
            if (D_0069BCE8 < 0) {
                D_0069BCE8 = func_0024AE68() - 1;
            }
            TkMenuSetHelpMessage(TkMenuMainHelp(func_0024AE38(D_0069BCE8)));
        } else if (rep & 0x4000) {
            SndSepPlaySimple(0x80000001);
            D_0069BCE8++;
            if (D_0069BCE8 >= func_0024AE68()) {
                D_0069BCE8 = 0;
            }
            TkMenuSetHelpMessage(TkMenuMainHelp(func_0024AE38(D_0069BCE8)));
        }
        break;
    case 6:
        D_0069BCEC = TkMenuGetCurrentPlayer();
        *state = 7;
    case 7:
        if (trg & 0x20) {
            if (TkMenuGetCurrentPlayerPos() < func_00242818()) {
                SndSepPlaySimple(0x80000001);
                r = ((int (*)(int))func_00249AA8)(D_0069BCE8);
                if (r == 3) {
                    *state = 0x1B;
                    st = 0x1B;
                    goto again;
                }
                if (r == 9) {
                    *state = 0x1F;
                    st = 0x1F;
                    goto again;
                }
                *state = 0x19;
                st = 0x19;
                goto again;
            }
            SndSepPlaySimple(0x80000003);
        } else if (trg & 0x40) {
            SndSepPlaySimple(0x80000004);
            *state = 8;
        } else if (TkMenuGetPlayerListMax2() >= 2) {
            if (rep & 0x1000) {
                SndSepPlaySimple(0x80000001);
                func_00242A90();
            } else if (rep & 0x4000) {
                SndSepPlaySimple(0x80000001);
                func_00242A40();
            } else {
                break;
            }
            D_0069BCEC = TkMenuGetCurrentPlayer();
        }
        break;
    case 8:
        D_0069BCEC = -1;
        *state = 9;
        goto case9;
    case 10:
        D_0069BD00[0] = TkMenuGetCurrentPlayerPos();
        D_0069BD00[1] = -1;
        *state = 0xC;
        break;
    case 11:
        D_0069BD00[1] = -1;
        *state = 0xC;
        break;
    case 12:
        *state = 0xD;
        break;
    case 13:
        *state = 0xE;
        break;
    case 14:
        if (trg & 0x20) {
            if (MsGetSavePlyJoin(TkMenuGetPlayerFromIndex2(D_0069BD00[0])) != 0) {
                SndSepPlaySimple(0x80000001);
                *state = 0x11;
            } else {
                SndSepPlaySimple(0x80000003);
            }
        } else if (trg & 0x40) {
            SndSepPlaySimple(0x80000004);
            *state = 0xF;
        } else if (rep & 0x4000) {
            SndSepPlaySimple(0x80000001);
            D_0069BD00[0]++;
            if (D_0069BD00[0] >= TkMenuGetPlayerListMax2()) {
                D_0069BD00[0] = 0;
            }
        } else if (rep & 0x1000) {
            SndSepPlaySimple(0x80000001);
            D_0069BD00[0]--;
            if (D_0069BD00[0] < 0) {
                D_0069BD00[0] = TkMenuGetPlayerListMax2() - 1;
            }
        }
        break;
    case 15:
        D_0069BD00[0] = -1;
        D_0069BD00[1] = -1;
        *state = 0x10;
    case 16:
        TkMsSetSaveParamAll();
        *state = 3;
        break;
    case 17:
        D_0069BD00[1] = D_0069BD00[0];
        *state = 0x12;
    case 18:
        *state = 0x13;
        break;
    case 19:
        *state = 0x14;
    case 20:
        if (trg & 0x20) {
            if (D_0069BD00[0] != D_0069BD00[1] &&
                MsGetSavePlyJoin(TkMenuGetPlayerFromIndex2(D_0069BD00[1])) != 0) {
                SndSepPlaySimple(0x80000001);
                *state = 0x15;
            } else {
                SndSepPlaySimple(0x80000003);
            }
        } else if (trg & 0x40) {
            SndSepPlaySimple(0x80000004);
            *state = 0x17;
        } else if (rep & 0x1000) {
            SndSepPlaySimple(0x80000001);
            D_0069BD00[1]--;
            if (D_0069BD00[1] < 0) {
                D_0069BD00[1] = TkMenuGetPlayerListMax2() - 1;
            }
        } else if (rep & 0x4000) {
            SndSepPlaySimple(0x80000001);
            D_0069BD00[1]++;
            if (D_0069BD00[1] >= TkMenuGetPlayerListMax2()) {
                D_0069BD00[1] = 0;
            }
        }
        break;
    case 21:
        TkMenuExchangePlayerPos(D_0069BD00[0], D_0069BD00[1]);
        D_0069BD00[0] = D_0069BD00[1];
        D_0069BD00[1] = -1;
        *state = 0x16;
    case 22:
        *state = 0xB;
        break;
    case 23:
        *state = 0x18;
    case 24:
        *state = 0xB;
        break;
    case 25:
        TkMsSetSaveParamAll();
        *state = 0x1A;
        break;
    case 26:
        if (D_0069BCF4 != 0) {
            TkMenuMainFreeWindowGroup(0);
            TkMenuMainFreeWindowGroup(3);
            *state = 2;
        }
        break;
    case 27:
        func_00241FB0(0xA);
        *state = 0x1C;
        break;
    case 28:
        if (TkMenuGetDrawShadeRatio() >= 0x80) {
            TkMenuMainActiveMenu(0x13, 0);
            TkMenuMainSleepMenu(1);
            *state = 0x1D;
        }
        break;
    case 29:
        if (D_0069BCF4 != 0) {
            TkMenuMainFreeWindowGroup(0);
            TkMenuMainFreeWindowGroup(3);
            func_00241FB0(-0xA);
            *state = 0x1E;
        }
        break;
    case 31:
        func_00241FB0(0xA);
        *state = 0x20;
        break;
    case 32:
        if (TkMenuGetDrawShadeRatio() >= 0x80) {
            TkMenuMainActiveMenu(0xB, 0);
            TkMenuMainSleepMenu(1);
            *state = 0x21;
        }
        break;
    case 33:
        if (D_0069BCF4 != 0) {
            TkMenuMainFreeWindowGroup(0);
            TkMenuMainFreeWindowGroup(3);
            func_00241FB0(-0xA);
            *state = 0x22;
        }
        break;
    case 30:
    case 34:
        if (TkMenuGetDrawShadeRatio() > 0) {
            break;
        }
    case 9:
    case9:
        *state = 2;
        break;
    case 35:
        *state = 0x24;
    case 36:
        if (TOMenuGetFirstReadEndFlag() != 0) {
            TkMn2SetMainFrameRatioDiff(0x10);
            *state = 0x25;
        }
        break;
    case 37:
        if (TkMn2GetMainFrameRatio() >= 0x80) {
            *state = 0x26;
        }
        break;
    case 38:
        TkMenuMainRemoveMenu(1);
        break;
    }
}

int TkMenuGetPlayerListMax2(void);
extern s16 D_00324204;
extern s16 D_00324206;
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

void func_0024AD20(u32 val, int x, int y, int c1, int c2)
{
    char buf1[16];
    ColonStr buf2 = D_00573288;
    u32 mins;
    u32 hrs;

    x -= 0x12;
    mins = (val / 60) % 60;
    hrs = val / 3600;
    hrs = hrs < 1000 ? hrs : 999;
    func_002F0008(buf1, D_00573290, mins);
    func_001F64F8(buf1, x, y, c1);
    x -= 0xA;
    func_001F64F8((char *)&buf2, x, y, c2);
    x -= 0x1E;
    func_002F0008(buf1, D_00573298, hrs);
    func_001F64F8(buf1, x, y, c1);
}

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

void func_0024AE90(void)
{
    int i;

    if (D_0069BCF4 != 0) {
        D_0069BCF8 += 0x155;
        if (D_0069BCF8 > 0x1000) {
            D_0069BCF8 = 0x1000;
        }
        D_0069BE28 = 0x1000;
        for (i = 0; i < 8; i++) {
            if (D_0069BE08[i] != 0) {
                D_0069BE08[i]--;
            } else {
                D_0069BE18[i] += 0xE3;
                if (D_0069BE18[i] > 0x1000) {
                    D_0069BE18[i] = 0x1000;
                }
            }
            D_0069BE28 &= D_0069BE18[i];
        }
    } else {
        D_0069BCF8 -= 0x155;
        if (D_0069BCF8 < 0) {
            D_0069BCF8 = 0;
        }
    }
}

extern u8 D_00326D78[];
extern s32 D_0069BCF0;
int TkMenuMainMes(int id);
int func_00138A98(void);
int TkMenuSummonEnableMask(void);
Task *func_00243400(void);
void TkMenuMainRegistWindow(Task *t);

extern s16 D_00324230;
extern s16 D_00324232;
extern s16 D_00324234;
extern s16 D_00324236;
extern s32 D_0032423C;
extern s32 D_00324240;
void TOMakePktBoxXYWHRGBA(int x, int y, int w, int h, int r, int g, int b, int a);
void func_001FF398(int x, int y, int w, int h, u32 c0, u32 c1);
void func_001F3850(int mes, int x, int y, int col, int alpha);

extern s16 D_00324238;

static inline int tk_lerp_4096(int a, int b, int t)
{
    return (a * t + b * (0x1000 - t)) / 0x1000;
}

void func_0024AF68(int idx, int x, int y_unused, int dy_unused, int ratio)
{
    int alpha = ratio / 32;
    int py = tk_lerp_4096(D_00324232 + idx * D_00324238, 3, ratio);
    int id;
    int disabled;

    TOMakePktBoxXYWHRGBA(x + D_00324230 + 4, py + 4, D_00324234, D_00324236, 0, 0, 0, alpha);
    func_001FF398(x + D_00324230, py, D_00324234, D_00324236,
                  (D_0032423C & 0xFFFFFF) | (alpha << 24),
                  (D_00324240 & 0xFFFFFF) | (alpha << 24));
    id = func_0024AE38(idx);
    disabled = func_0024AE50(idx) == 0;
    func_001F3850(TkMenuMainMes(id), x + D_00324230 + 0xF, py + 2, disabled, alpha);
    if (idx == D_0069BCE8 && ratio == 0x1000) {
        func_001FE7F8(0, x + D_00324230 + 0xF, py + 2);
    }
}

void func_0024B140(void)
{
    int i;

    if ((TkMenuMainGetMenuActiveMask() & 0x80800) == 0) {
        func_00124F08();
        TOMenuOpenPktBuffTmp();
        if (D_0069BCF8 != 0) {
            for (i = 0; i < func_0024AE68(); i++) {
                if (i != D_0069BCE8) {
                    func_0024AF68(i, 0, 0, -0x14, D_0069BCF8);
                }
            }
        }
        func_0024AF68(D_0069BCE8, 0, 0, -0x14, D_0069BCF8);
        TOMenuDrawKickTmp();
        func_00124F08();
    }
}

typedef struct {
    s32 w0;
    s16 h4;
    s16 h6;
} MainCmdEntry;

void TkMenuAppearMainCmdWindow(int flag, int mode)
{
    MainCmdEntry tmp[32];
    int i;
    int count;
    int mask;
    int story;
    Task *t;

    D_0069BCE8 = 0;
    D_0069BCF0 = 0;
    D_0069BCEC = -1;
    switch (mode) {
    case 14:
        D_0069BD08[0].w0 = 0xE;
        D_0069BD08[0].h4 = 1;
        D_0069BD08[0].h6 = 0;
        D_0069BE2C = 1;
        D_0069BCF4 = 0;
        break;
    case 24:
        D_0069BD08[0].w0 = 0x37;
        D_0069BD08[0].h4 = 1;
        D_0069BD08[0].h6 = 0;
        D_0069BE2C = 1;
        D_0069BCF4 = 0;
        break;
    case 12:
        D_0069BD08[0].w0 = 0xD;
        D_0069BD08[0].h4 = 1;
        D_0069BD08[0].h6 = 0;
        D_0069BE2C = 1;
        D_0069BCF4 = 0;
        break;
    case 13:
        D_0069BD08[0].w0 = 0xC;
        D_0069BD08[0].h4 = 1;
        D_0069BD08[0].h6 = 0;
        D_0069BE2C = 1;
        D_0069BCF4 = 0;
        break;
    case 15:
        D_0069BD08[0].w0 = 0xA;
        D_0069BD08[0].h4 = 1;
        D_0069BD08[0].h6 = 0;
        D_0069BE2C = 1;
        D_0069BCF4 = 0;
        break;
    case 16:
        D_0069BD08[0].w0 = 0xB;
        D_0069BD08[0].h4 = 1;
        D_0069BD08[0].h6 = 0;
        D_0069BE2C = 1;
        D_0069BCF4 = 0;
        break;
    case 1:
    default:
        count = 0;
        story = func_0014AC00();
        mask = 0x11;
        if (story == 0 || story >= 0xD2) {
            mask |= 4;
        }
        mask |= 0x8000;
        if (story == 0 || story >= 0x43) {
            mask |= 8;
        }
        if (story == 0 || story >= 0x448) {
            mask |= 0x80;
        }
        mask |= 0x302;
        if (story == 0 || story >= 0xD9) {
            if ((func_00138A98() & 0x40) == 0 && TkMenuGetPlayerListMax2() >= 2) {
                mask |= 0x40;
            }
        }
        if (TkMenuSummonEnableMask() != 0 && (story >= 0xD0 || story == 0)) {
            mask |= 0x20;
        }
        func_002EF0D0(tmp, 0, sizeof(tmp));
        for (i = 0; i < 32; i++) {
            if ((mask >> i) & 1) {
                tmp[D_00326D78[i]].w0 = i;
                tmp[D_00326D78[i]].h4 = 1;
                switch (i) {
                case 2:
                case 3:
                case 4:
                case 15:
                    tmp[D_00326D78[i]].h6 = 2;
                    break;
                case 1:
                    tmp[D_00326D78[i]].h6 = 1;
                    break;
                default:
                    tmp[D_00326D78[i]].h6 = 0;
                    break;
                }
            }
        }
        for (i = 0; i < 32; i++) {
            if (tmp[i].h4 == 1) {
                *(MainCmdEntry *)&D_0069BD08[count] = tmp[i];
                count++;
            }
        }
        D_0069BE2C = count;
        break;
    }
    TkMenuSetHelpMessage(0);
    TkMenuSetHelpMessage(TkMenuMainHelp(func_0024AE38(D_0069BCE8)));
    if (flag != 0) {
        D_0069BCF8 = 0x3000;
    } else {
        D_0069BCF8 = 0;
    }
    for (i = 0; i < 8; i++) {
        D_0069BE08[i] = i * 4;
        D_0069BE18[i] = 0;
    }
    t = func_00243400();
    D_0069BCE0 = t;
    t->x0C = (s32)func_0024AE90;
    t->x10 = (s32)func_0024B140;
    t->b36 = 2;
    t->b3E = 7;
    t->cb = 0;
    t->x14 = 0;
    t->x18 = 0;
    t->x1C = 0;
    for (i = 0; i < func_0024AE68(); i++) {
        int w = func_002454E0(TkMenuMainMes(func_0024AE38(i)));
        if (D_0069BCF0 < w) {
            D_0069BCF0 = w;
        }
    }
    TkMenuMainRegistWindow(t);
}

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
