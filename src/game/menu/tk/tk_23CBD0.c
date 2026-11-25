/* tu_266 0x23cbd0-0x2414f0: medium; ~Tk (config/tu_map.tsv) */
#define TkMenuCtrlSelFileWindow _hdr_TkMenuCtrlSelFileWindow
#define TOMenuCloseYesNoWindow _hdr_TOMenuCloseYesNoWindow
#define func_002D9030 _hdr_func_002D9030
#include "common.h"
#include "ffx/r5.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/s5.h"
#include "ffx/u4.h"
#include "ffx/v5.h"
#undef TkMenuCtrlSelFileWindow
#undef TOMenuCloseYesNoWindow
#undef func_002D9030
void TkMenuCtrlSelFileWindow(Task *t);
int TOMenuCloseYesNoWindow(void);
int func_002D9030(int);

void func_0023CBD0(char *dst, int n)
{
    char buf[64];

    func_002F0008(buf, D_00326F58, n);
    *(U4Str2 *)dst = D_00572CB0; /* DEBT(CAST): strcpy(dst, "/") expanded by the builtin */
    func_002F032C(dst, buf);
    func_002F032C(dst, D_00572CB0.c);
    func_002F032C(dst, buf);
}

void func_0023CC50(char *dst, int n)
{
    char buf[64];

    func_002F0008(buf, D_00326F58, n);
    *(U4Str2 *)dst = D_00572CB0; /* DEBT(CAST): dst starts as a copy of the 2-byte string */
    func_002F032C(dst, buf);
    func_002F032C(dst, D_00572CB0.c);
    func_002F0008(buf, D_00326EF0, n);
    func_002F032C(dst, buf);
}

void func_0023CCF0(char *dst, int a1)
{
    char buf[0x40];

    func_002F0008(buf, D_00326EF0, a1);
    func_002F072C(dst, buf);
}

void func_0023CD30(char *dst, int n)
{
    char buf[64];

    func_002F0008(buf, D_00326F58, n);
    *(U4Str2 *)dst = D_00572CB0; /* DEBT(CAST): dst starts as a copy of the 2-byte string */
    func_002F032C(dst, buf);
    func_002F032C(dst, D_00572CB0.c);
    func_002F032C(dst, D_00572CB8);
}

void func_0023CDB0(char *dst, int n)
{
    char buf[64];

    func_002F0008(buf, D_00326F58, n);
    *(U4Str2 *)dst = D_00572CB0; /* DEBT(CAST): dst starts as a copy of the 2-byte string */
    func_002F032C(dst, buf);
}

/* DEBT(NAME): 64-byte records at the fixed address 0x01D5E400 (99 entries) */
void *func_0023CE08(int n)
{
    int i;

    if (n >= 0) {
        if (n > 98) {
            i = 98;
        } else {
            i = n;
        }
    } else {
        i = 0;
    }
    return (char *)0x1D5E400 + i * 64; /* DEBT(CAST): record type unknown */
}

extern char D_00572CC8[], D_00572CD0[], D_00326F38[];
extern unsigned char D_00326F20[];
void func_0023CE38(char *dst, int number, int digits, int pad)
{
    char buf[16];
    char code[3];
    char *s;
    int started;
    if (digits == 3) func_002F0008(buf, D_00572CC8, number);
    if (digits == 2) func_002F0008(buf, D_00572CD0, number);
    s = buf;
    *dst = 0;
    started = 0;
    while (digits > 0) {
        if (digits != 1 && *s == '0' && pad != 0 && started == 0) {
            func_002F032C(dst, D_00326F38);
        } else {
            code[0] = D_00326F20[0];
            code[1] = D_00326F20[1] + (unsigned char)*s - '0';
            code[2] = 0;
            func_002F032C(dst, code);
            started = 1;
        }
        digits--;
        s++;
    }
}

extern char D_00326F00[];
extern char D_00326F10[];
extern char D_00326F28[];
extern char D_00326F48[];
extern char D_00326F50[];

void func_0023CF70(char *dst, int slot, int secs, int area)
{
    char buf[0x40];
    int m = (secs / 60) % 60;
    int h = secs / 3600;

    if (h >= 1000) {
        h = 999;
    }
    func_002F072C(dst, D_00326F00);
    if (func_0020B850() == 0) {
        func_002F032C(dst, D_00326F38);
        func_002F032C(dst, D_00326F10);
    }
    func_002F032C(dst, D_00326F38);
    func_002F032C(dst, D_00326F48);
    func_0023CE38(buf, slot + 1, 2, 0);
    func_002F032C(dst, buf);
    func_002F032C(dst, D_00326F50);
    func_002F032C(dst, D_00326F38);
    if (func_0020B850() == 0) {
        func_002F032C(dst, D_00326F38);
    } else {
        func_0023CE38(buf, h, 3, 1);
        func_002F032C(dst, buf);
        func_002F032C(dst, D_00326F28);
        func_0023CE38(buf, m, 2, 0);
        func_002F032C(dst, buf);
    }
    if (func_0020B850() == 0 && func_001BD360() == 0) {
        func_00208458((void *)AtelGetSaveDicName(area, func_001BD360()), buf);
        func_002F032C(dst, buf);
    } else {
        u8 *tbl = (u8 *)func_00206ED8(func_001BD360());
        func_00208458(tbl + *(u16 *)(tbl + area * 4 + 2), buf);
        func_002F032C(dst, buf);
    }
}

typedef struct SaveDataBody {
    u8 d[0x64B8];
} SaveDataBody;

void func_0023D190(SaveDataBody *dst, u8 *src)
{
    *dst = *(SaveDataBody *)(src + 0x40);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23CBD0", func_0023D268);

typedef struct Blk40 { u8 d[0x40]; } Blk40;
typedef struct Blk30 { u8 d[0x30]; } Blk30;
typedef struct Blk10 { u8 d[0x10]; } Blk10;
extern Blk40 D_00326330;
extern Blk30 D_00326370, D_003263A0;
extern Blk10 D_003263D0;
void func_0023CF70(char *arg0, int arg1, int arg2, int arg3);

typedef struct McIconSys {
    u8 head[4];
    u8 pad4[2];
    u16 h6;
    u8 pad8[4];
    s32 wC;
    Blk40 b10;
    Blk30 b50;
    Blk30 b80;
    Blk10 bB0;
    char title[0x44];
    char icon1[0x40];
    char icon2[0x40];
    char icon3[0x40];
} McIconSys;

void func_0023D4B8(int arg0, int arg1, int arg2)
{
    char buf[0x100];
    McIconSys *sys = (McIconSys *)0x01D5E000;

    func_002EF0D0(sys, 0, 0x3C4);
    sys->head[0] = 'P';
    sys->head[1] = 'S';
    sys->head[2] = '2';
    sys->head[3] = 'D';
    sys->h6 = 0x20;
    sys->wC = 0x60;
    sys->b10 = D_00326330;
    sys->b50 = D_00326370;
    sys->b80 = D_003263A0;
    sys->bB0 = D_003263D0;
    func_0023CF70(buf, arg0, arg1, arg2);
    func_002F072C(sys->title, buf);
    func_0023CCF0(buf, arg0);
    func_002F072C(sys->icon1, buf);
    func_002F072C(sys->icon2, buf);
    func_002F072C(sys->icon3, buf);
}

void func_0023D748(void) {
}

extern s32 D_0069A65C;
void func_001FA548(int, int, int, int);
void TOMkpShapeXY(int, int, int);
void func_001F3808(int, int, int, int);

void func_0023D750(void)
{
    s16 w0;
    s16 h0;
    s16 w1;
    s16 h1;
    s16 winW;
    s16 totalH;
    s16 maxW;
    s16 winX;
    s16 winY;
    int textX;
    int textY;
    int i;

    func_00124F08();
    TOMenuOpenPktBuffTmp();
    _TOGetMessageWH(0, (u8 *)func_00220960(0x2000), &w0, &h0, 0, 0);
    winW = w0;
    h0 += 10;
    totalH = h0;
    _TOGetMessageWH(0, (u8 *)func_00220960(0x2001), &w1, &h1, 0, 0);
    maxW = w1;
    totalH += 20;
    _TOGetMessageWH(0, (u8 *)func_00220960(0x2002), &w1, &h1, 0, 0);
    if (maxW < w1) {
        maxW = w1;
    }
    totalH += 20;
    totalH += 0x1D;
    winW += 0x3E;
    winX = (0x200 - winW) / 2;
    winY = (0x1A0 - totalH) / 2;
    textX = (0x200 - maxW) / 2;
    {
        int dy = h0 + 0xD;
        textY = winY + dy;
    }
    func_001FA548(winX, winY, winW, totalH);
    TOMkpShapeXY(0x2B, winX + 8, winY + 8);
    func_001F3808(func_00220960(0x2000), winX + 0x2E, winY + 0xD, 0);
    for (i = 0; i < 2; i++, textY += 20) {
        int gray = (D_0069A660[i] == 0);
        func_001F3808(func_00220960(0x2001 + i), textX, textY, gray);
        if (i == D_0069A65C) {
            func_001FE7F8(0, textX, textY);
        }
    }
    TOMenuDrawKickTmp();
    func_00124F08();
}

extern u16 D_0069A684;
extern s32 D_00572CD8;
extern s32 _m2c_func_0023E938_D_00572CE0 __asm__("D_00572CE0");
extern s32 _m2c_func_0023E938_D_00572CE8 __asm__("D_00572CE8");
extern s32 _m2c_func_0023E938_D_00572CF0 __asm__("D_00572CF0");

void func_0023D990(Task *o)
{
    s16 w;
    s16 h;
    int text;
    int i;
    int tw;

    if (D_0069A688 == 1) {
        text = func_00220960(0x2000);
    } else {
        text = func_00220960(0x2000);
    }
    _TOGetMessageWH(0, (u8 *)text, &w, &h, 0, 0);
    o->state = 0;
    D_0069A684 = 0;
    for (i = 0; i < 2; i++) {
        tw = func_002454E0((u8 *)func_00220960(0x2001 + i));
        if (D_0069A684 < tw) {
            D_0069A684 = tw;
        }
    }
    TOSeqStartScene(1, &D_00572CD8);
    TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CE0);
    TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CE8);
    TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CF0);
}

int func_0023DA88(void) { return 1; }

Task *func_0023DA90(int v) {
    Task *t = func_00243400();

    D_0069A64C = t;
    t->ext[0] = v;
    t->cb = func_0023D990;
    t->x0C = (s32)func_0023D748; /* DEBT(CAST): Task callbacks are typed s32 */
    t->x10 = (s32)func_0023D750;
    t->x14 = (s32)func_0023DA88;
    t->b3E = 1;
    TkMenuMainRegistWindow(t);
    return t;
}

void func_0023DB10(void) {
    if (D_0069A64C) {
        D_0069A64C->b41 = 1;
        D_0069A64C = 0;
    }
}

int func_0023DB30(int a, int i) {
    int ret;

    if (D_0069A688 != 0) {
        i = D_0069A690[i];
        if (i >= 0) {
            if (i < 3 || i == 4) {
                return 1;
            }
        }
        ret = 0;
    } else {
        ret = D_0069A690[i] == 1;
    }
    return ret;
}

void func_0023DB90(void) {
}

Task *func_0023DB98(void) {
    Task *t = func_00243400();

    D_0069A658 = t;
    t->cb = 0;
    t->x0C = 0;
    t->x14 = 0;
    t->x1C = 0;
    t->x10 = (s32)func_0023DB90; /* DEBT(CAST): Task callbacks are typed s32 */
    t->b3E = 4;
    TkMenuMainRegistWindow(t);
    return t;
}

void func_0023DBF8(void) {
    if (D_0069A658) {
        D_0069A658->b41 = 1;
        D_0069A658 = 0;
    }
}

void func_002006E0(int text, int x, int y, int a3);
void func_00200798(int text, int x, int y, int a3);

void func_0023DC18(Task *o)
{
    s16 w;
    s16 h;
    int r;
    int x;

    func_00124F08();
    TOMenuOpenPktBuffTmp();
    r = func_00242630();
    if (r == 0) {
        return;
    }
    if (func_0020B850() == 0 && func_001BD360() == 0) {
        x = (r * 0x19E + ((0x1000 - r) << 9)) / 4096;
    } else {
        _TOGetMessageWH(0, (u8 *)func_002493D0(o->ext[0] + 0x2001), &w, &h, 0, 0);
        x = ((0x1E2 - w) * r + ((0x1000 - r) << 9)) / 4096;
    }
    if (func_0020B850() == 0 && func_001BD360() == 0) {
        func_002006E0(func_002493D0(o->ext[0] + 0x2001), x, 0x20, 0);
    } else {
        func_00200798(func_002493D0(o->ext[0] + 0x2001), x, 0x20, 0);
    }
    TOMenuDrawKickTmp();
    func_00124F08();
}

Task *func_0023DD60(int v) {
    Task *t = func_00243400();

    t->ext[0] = v;
    D_0069A648 = t;
    t->cb = 0;
    t->x0C = 0;
    t->x14 = 0;
    t->x1C = 0;
    t->x10 = (s32)func_0023DC18; /* DEBT(CAST): Task callbacks are typed s32 */
    t->b3E = 4;
    TkMenuMainRegistWindow(t);
    return t;
}

void func_0023DDD0(void) {
    if (D_0069A648) {
        D_0069A648->b41 = 1;
        D_0069A648 = 0;
    }
}

void TkMenuRestartSelFileWindow(Task *o) {
    if (o != 0) {
        o->state = 1;
    }
}

void TkMenuCtrlSelFileWindow(Task *t)
{
    s32 *state = &t->state;
    u32 pad = func_00220318();
    u32 rep = TOMenuGetControlPadRep();
    u32 trg = TOMenuGetControlPadTrg();
    int st = *state;

loop:
    switch (st) {
    case 0:
        *state = 2;
        break;
    case 1:
        t->b45 = 0;
        *state = 2;
        break;
    case 2:
        if (trg & 0x20) {
            if (t->x1C != 0) {
                if (((int (*)(Task *, int, int))t->x1C)(t, t->x48, t->b45) != 0) {
                    if (t->b45 == t->b42 - 1) {
                        if (t->b37 != 0) {
                            SndSepPlaySimple(0x80000001);
                        }
                    } else {
                        SndSepPlaySimple(0x80000001);
                    }
                    *state = 0xF;
                } else {
                    SndSepPlaySimple(0x80000003);
                    return;
                }
            } else {
                if (t->b45 == t->b42 - 1) {
                    if (t->b37 != 0) {
                        SndSepPlaySimple(0x80000001);
                    }
                } else {
                    SndSepPlaySimple(0x80000001);
                }
                *state = 0xF;
            }
        } else if (trg & 0x40) {
            PLAY_SE(0x80000004);
            *state = 0x11;
        } else if ((rep & 0x1000) && t->x48 > 0) {
            PLAY_SE(0x80000001);
            t->x48--;
            if (t->x48 < t->x32) {
                st = 7;
                goto loop;
            }
        } else if ((rep & 0x4000) && t->x48 < (u16)t->x30 - 1) {
            PLAY_SE(0x80000001);
            t->x48++;
            if (t->x48 >= t->x32 + (u16)t->x3A) {
                st = 0xB;
                goto loop;
            }
        } else {
            int next;

            if ((rep & 1) && pad == 1 && t->x48 > 0) {
                next = t->x32 - (u16)t->x3A;

                if (next < 0) {
                    next = 0;
                }
                if (next != t->x32) {
                    t->x34 = next;
                    st = 8;
                    goto loop;
                }
            }
            if ((rep & 2) && pad == 2 && t->x48 < (u16)t->x30 - 1) {
                int maxTop = (u16)t->x30 - (u16)t->x3A;

                next = t->x32 + (u16)t->x3A;
                if (next >= maxTop) {
                    next = maxTop;
                    if (next < 0) {
                        next = 0;
                    }
                }
                if (next != t->x32) {
                    t->x34 = next;
                    st = 0xC;
                    goto loop;
                }
            }
        }
        break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 0x10:
    case 0x12:
        break;
    case 7:
        trg = 0;
        PLAY_SE(0x80000001);
        t->x46 = 0x1000;
        t->x32--;
        t->x34 = t->x32;
        *state = 9;
        st = 9;
        goto loop;
    case 8:
        trg = 0;
        PLAY_SE(0x80000001);
        t->x46 = 0x1000;
        *state = 0xA;
        st = 0xA;
        goto loop;
    case 9:
        t->x46 -= 0x199;
        if (t->x46 <= 0 || (trg & 0x1000)) {
            trg = 0;
            t->x48 -= t->x32 - t->x34;
            t->x32 = t->x34;
            t->x46 = 0;
            *state = 2;
            st = 2;
            goto loop;
        }
        break;
    case 0xA:
        t->x46 -= 0x111;
        if (t->x46 <= 0) {
            t->x48 -= t->x32 - t->x34;
            t->x32 = t->x34;
            t->x46 = 0;
            *state = 2;
            st = 2;
            goto loop;
        }
        break;
    case 0xB:
        trg = 0;
        PLAY_SE(0x80000001);
        t->x46 = -0x1000;
        t->x32++;
        t->x34 = t->x32;
        *state = 0xD;
        st = 0xD;
        goto loop;
    case 0xC:
        trg = 0;
        PLAY_SE(0x80000001);
        t->x46 = -0x1000;
        *state = 0xE;
        st = 0xE;
        goto loop;
    case 0xD:
        t->x46 += 0x199;
        if (t->x46 >= 0 || (trg & 0x4000)) {
            trg = 0;
            t->x48 += t->x34 - t->x32;
            t->x32 = t->x34;
            t->x46 = 0;
            *state = 2;
            st = 2;
            goto loop;
        }
        break;
    case 0xE:
        t->x46 += 0x111;
        if (t->x46 >= 0) {
            t->x48 += t->x34 - t->x32;
            t->x32 = t->x34;
            t->x46 = 0;
            *state = 2;
            st = 2;
            goto loop;
        }
        break;
    case 0xF:
        *(s16 *)((u8 *)t + (t->b45 << 1) + 0x2C) = t->x48;
        t->b45++;
        if (t->b45 < t->b42) {
            *state = 2;
            break;
        }
        *state = 0x10;
        st = 0x10;
        goto loop;
    case 0x11:
        t->b45--;
        if (t->b45 >= 0) {
            *state = 2;
            break;
        }
        *state = 0x12;
        st = 0x12;
        goto loop;
    }
}

int func_0023E310(int sel, int a) {
    switch (sel) {
    case 1:
        return a + 0x20;
    case 2:
        func_002493D0(0x2019);
        break;
    case 0:
    case 4:
        func_002493D0(0x2014);
        break;
    default:
        func_002493D0(0x202A);
        break;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23CBD0", func_0023E390);

void func_0023E660(Task *o, int a1, int a2) { func_00246210(a1, a2 + (o->x48 - o->x32) * 15, 0x1B8); }

void func_0023E688(Task *o, int a1, int a2) { func_00246220(a1, a2 + (o->x48 - o->x32) * 15, 0x80); }

void func_001FFDA0(void);
void func_001FFE00(int id, int x, int y);

void func_0023E6B0(Task *o, int x, int y)
{
    u8 state = D_0069A690[o->x48];
    u8 *rec = func_0023CE08(o->x48);
    int i;

    if (state == 1) {
        func_001FFDA0();
        TOMakePktScissor(0, 0, 0x1FF, 0x19F);
        for (i = 5; i < 12; i++) {
            if (rec[i] != 0xFF) {
                int id = rec[i];

                if (id == 6 && rec[0x1E] != 0) {
                    id = 7;
                }
                func_001FFE00(id, x, y);
                x += 0x3B;
            }
        }
    }
}

void func_0023E390(Task *o, int x, int y, int idx, int mode);
void func_00200A58(int a0, int a1, int a2, int a3, int t0, int t1, int t2);

void func_0023E798(Task *o)
{
    int i;
    int y = 0x5A;

    func_00124F08();
    TOMenuOpenPktBuffTmp();
    TOMakePktScissor(0, 0x5A, 0x1FF, 0x146);
    if (o->x32 == o->x34) {
        y = 0x2A;
        for (i = -1; i < 6; i++, y += 0x30) {
            func_0023E390(o, 0x1E, y, i, 0);
        }
    } else {
        for (i = 0; i < 5; i++, y += 0x30) {
            func_0023E390(o, 0x1E, y, i, 2);
        }
        i = 0;
        {
            register int d __asm__("$2") = (o->x46 * 0xEC) / 4096;
            register int c __asm__("$3");
            __asm__ volatile("" : "+r"(d));
            c = 0x5A;
            __asm__ volatile("" : "+r"(c));
            y = c - d;
        }
        for (; i < 5; i++, y += 0x30) {
            func_0023E390(o, 0x1E, y, i, 1);
        }
    }
    TODrawScissorXYWH(0, 0, 0x1FF, 0x19F);
    func_0023E6B0(o, 0x2A, 0x153);
    func_001FE7F8(0, 0x1E, (o->x48 - o->x32) * 0x30 + 0x5A);
    func_00200A58(0x1E3, 0x52, 0xA, 0xFC, o->x32, (u16)o->x3A, (u16)o->x30);
    TOMenuDrawKickTmp();
    func_00124F08();
}

void func_0023E928(Task *o) { o->state = 0; }

int func_0023E930(void) { return 1; }

extern s32 _m2c_func_0023E938_D_00572CE0 __asm__("D_00572CE0");
extern s32 _m2c_func_0023E938_D_00572CE8 __asm__("D_00572CE8");
extern s32 _m2c_func_0023E938_D_00572CF0 __asm__("D_00572CF0");
void _m2c_func_0023E938_func_0023DB30() __asm__("func_0023DB30");
void _m2c_func_0023E938_func_0023E798() __asm__("func_0023E798");
Task *func_0023E938(s32 arg0) {
    Task *temp_2;

    temp_2 = func_00243400();
    D_0069A644 = temp_2;
    if (D_0069A688 != 0) {
        TkMenuSetHelpMessage(func_002493D0(0x2004));
    } else {
        TkMenuSetHelpMessage(func_002493D0(0x201F));
    }
    temp_2->ext[0] = arg0;
    temp_2->cb = func_0023E928;
    temp_2->x0C = (s32) TkMenuCtrlSelFileWindow;
    temp_2->x10 = (s32) &_m2c_func_0023E938_func_0023E798;
    temp_2->x14 = (s32) func_0023E930;
    temp_2->x1C = (s32) &_m2c_func_0023E938_func_0023DB30;
    temp_2->x30 = 0x63;
    temp_2->x48 = 0;
    temp_2->x32 = 0;
    temp_2->x3A = 5;
    temp_2->b42 = 1;
    temp_2->b3E = 1;
    TkMenuMainRegistWindow(temp_2);
    TOSeqStartScene(1, &_m2c_func_0023E938_D_00572CE0);
    TOSeqStartScene(1, &_m2c_func_0023E938_D_00572CE8);
    TOSeqStartScene(1, &_m2c_func_0023E938_D_00572CF0);
    return temp_2;
}

void func_0023EA48(void) {
    if (D_0069A644) {
        D_0069A644->b41 = 1;
        D_0069A644 = 0;
    }
}

extern s32 D_0069A670;

void func_0023EA68(int a0, int a1)
{
    int i;
    u8 *p;

    D_0069A670 = 0;
    p = D_0069A690;
    for (i = 0; i < 99; i++, p++) {
        switch (*p) {
        case 0:
        case 3:
            *p = 0;
            break;
        case 1:
        case 2:
        case 4:
            break;
        }
    }
    p = D_0069A690;
    for (i = 0; i < 99; i++, p++) {
        switch (*p) {
        case 0:
            if (a0 >= a1) {
                a0 -= a1;
            } else {
                *p = 3;
            }
            break;
        case 1:
            D_0069A670 = 1;
            break;
        case 2:
        case 3:
        case 4:
            break;
        }
    }
}

extern s32 D_0069A664;

void func_0023EB20(void)
{
    int res;
    int port;

    if (D_0069A686 != 0) {
        port = 1;
    } else {
        port = 0;
    }
    switch (D_0069A687) {
    case 0:
        if (func_002D8AC8(1, 0, 0) == 0) {
            break;
        }
        D_0069A687 = 1;
    case 1:
        if (func_002D9050(port, &D_0069A664, 0, 0) != 0) {
            break;
        }
        D_0069A687 = 2;
    case 2:
        if (func_002D8AC8(1, 0, &res) == 1) {
            if (res == 0 && D_0069A664 == 2) {
                D_0069A660[port] = 1;
            } else {
                D_0069A660[port] = 0;
            }
            D_0069A687 = 0;
            D_0069A686 = D_0069A686 == 0;
        }
        break;
    }
}

int func_0023EC50(void)
{
    int res;
    int port;
    int ret;

    if (D_0069A686 != 0) {
        port = 1;
    } else {
        port = 0;
    }
    ret = 1;
    if (D_0069A687 == 2) {
        int r;

        ret = 0;
        r = func_002D8AC8(1, 0, &res);
        if (r == 1) {
            if (res == 0 && D_0069A664 == 2) {
                D_0069A660[port] = 1;
            } else {
                D_0069A660[port] = 0;
            }
            ret = 1;
            D_0069A687 = 0;
            D_0069A686 = D_0069A686 == 0;
        }
        if (r < 0) {
            ret = 1;
        }
    }
    return ret;
}

void func_0023ED40(void) {
    D_0069A686 = 0;
    D_0069A687 = 0;
}

void func_0023ED58(int v) {
    D_0069A7C0 = 0;
    D_0069A7C1 = 0;
    D_0069A678 = 0;
    D_0069A67C = 0;
    D_0069A648->ext[0] = v;
}

extern s32 D_0030B170[];
extern u8 D_0069A6F8[];
extern u8 D_0069A780[];
extern u32 D_0069A790;
extern s32 D_0032648C;
extern s32 D_0069A7C4;
extern s32 D_0069A66C;
extern s32 D_0069A668;
extern s32 D_0069A674;
extern s32 D_0069A65C;
int func_002D8E40(char *, int, int, void *);
int func_002D8D28(char *, int);
int func_002D8FA0(int);

int func_0023ED88(int port)
{
    char path[0x80];
    int res2;
    int res4;
    int res6;
    int res8;
    int resB;
    int ret = 0;

    func_0023CBD0(path, D_0069A7C0);
loop:
    switch (D_0069A7C1) {
    case 0:
        if (func_002D8AC8(1, 0, 0) == 0) {
            break;
        }
        D_0069A7C1 = 1;
    case 1:
    case_1: {
        int r;

        D_0069A690[D_0069A7C0] = 0;
        D_0069A6F8[D_0069A7C0] = 0;
        if (((D_0030B170[D_0069A7C0 / 32] >> (D_0069A7C0 % 32)) & 1) == 0) {
            D_0069A7C1 = 9;
            goto loop;
        }
        r = func_002D8E40(path, 0, 1, D_0069A780);
        if (r != 0) {
            if (r < 0) {
                ret = -1;
            }
            break;
        }
        D_0069A7C1 = 2;
    }
    case 2:
        if (func_002D8AC8(1, 0, &res2) != 1) {
            break;
        }
        if (res2 > 0) {
            D_0069A6F8[D_0069A7C0] += ((u32)D_0069A790 + 0x3FF) / 1024;
            D_0069A6F8[D_0069A7C0] += 1;
            D_0069A6F8[D_0069A7C0] += (D_0032648C + 0x3FF) / 1024;
            D_0069A6F8[D_0069A7C0] += 4;
            if (D_0069A790 == 0x64F8) {
                D_0069A7C1 = 3;
            } else {
                D_0069A690[D_0069A7C0] = 2;
                D_0069A7C1 = 9;
                goto loop;
            }
        } else {
            if (res2 == -4 || res2 == -2 || res2 == 0) {
                D_0069A690[D_0069A7C0] = 2;
                D_0069A7C1 = 9;
                goto loop;
            }
            ret = -1;
            break;
        }
    case 3: {
        int r = func_002D8D28(path, 1);

        if (r != 0) {
            if (r < 0) {
                ret = -1;
            }
            break;
        }
        D_0069A7C1 = 4;
    }
    case 4:
        if (func_002D8AC8(1, 0, &res4) != 1) {
            break;
        }
        if (res4 < 0) {
            ret = -1;
            break;
        }
        D_0069A7C4 = res4;
        D_0069A7C1 = 5;
    case 5: {
        int r = func_002D8CD0(D_0069A7C4, (s32)func_0023CE08(D_0069A7C0), 0x40);

        if (r != 0) {
            if (r < 0) {
                ret = -1;
            }
            break;
        }
        D_0069A7C1 = 6;
    }
    case 6:
        if (func_002D8AC8(1, 0, &res6) != 1) {
            break;
        }
        D_0069A7C1 = 7;
        if (res6 < 0) {
            break;
        }
        if (res6 == 0x40) {
            if (((u8 *)func_0023CE08(D_0069A7C0))[0x1D] == 1) {
                u32 *rec = func_0023CE08(D_0069A7C0);

                D_0069A690[D_0069A7C0] = 1;
                if ((u32)D_0069A678 < rec[0]) {
                    D_0069A678 = rec[0];
                    D_0069A67C = D_0069A7C0;
                }
            } else {
                D_0069A690[D_0069A7C0] = 2;
            }
        } else {
            D_0069A690[D_0069A7C0] = 2;
        }
    case 7: {
        int r = func_002D8FA0(D_0069A7C4);

        if (r != 0) {
            if (r < 0) {
                ret = -1;
            }
            break;
        }
        D_0069A7C1 = 8;
    }
    case 8:
        if (func_002D8AC8(1, 0, &res8) != 1) {
            break;
        }
        if (res8 < 0 && res8 != -4) {
            ret = -1;
        }
        D_0069A7C1 = 9;
        goto loop;
    case 9:
        if (++D_0069A7C0 < 99) {
            D_0069A7C1 = 1;
            func_0023CBD0(path, D_0069A7C0);
            goto case_1;
        }
        D_0069A7C1 = 10;
    case 10: {
        int r = func_002D9050(port, 0, &D_0069A66C, &D_0069A668);

        if (r != 0) {
            if (r < 0) {
                ret = -1;
            }
            break;
        }
        D_0069A7C1 = 11;
    }
    case 11:
        if (func_002D8AC8(1, 0, &resB) != 1) {
            break;
        }
        D_0069A7C1 = 12;
        ret = 1;
        if (resB == 0) {
            if (D_0069A668 == 0) {
                D_0069A66C = 0x2000;
            }
        } else {
            ret = -1;
            if (resB == -2) {
                D_0069A66C = 0x2000;
                ret = 1;
            }
        }
        func_0023EA68(D_0069A66C, D_0069A7C8);
        break;
    case 12:
        ret = D_0069A674;
        break;
    }
    D_0069A674 = ret;
    if (ret < 0) {
        func_0023ED58(D_0069A65C);
    }
    return ret;
}

extern char D_0030B180[];
extern u8 D_0030B280[];
extern char D_0030B2A0[];
extern s32 D_0069A7D0;
extern s32 D_0069A75C;
extern s32 D_0069A680;
void func_00242620(int);
void func_002D9208(char *, char *);
int func_002D8EC8(void);
int func_002D8D90(char *);
int func_002510A0(int, void *);
void TOMenuHelpSetExtMode(int, int);
int TkMn2GetMenuMode(void);
int TkMn2GetMainFrameRatio(void);
void TOSwapInternationalEnvInit(int);

void func_0023F298(Task *t)
{
    s32 *state = &t->x1C;
    u32 pad = func_00220318();
    u32 rep = TOMenuGetControlPadRep();
    u32 trg = TOMenuGetControlPadTrg();
    int st = *state;

loop:
    switch (st) {
    case 0:
        func_0023ED40();
        func_0023DB98();
        *state = 1;
        D_0069A65C = 0;
        D_0069A660[0] = 0;
        D_0069A660[1] = 0;
        break;
    case 1:
        *state = 3;
    case 3:
        func_0023EB20();
        if (D_0069A686 != 0) {
            *state = 4;
        }
        break;
    case 4:
        func_0023EB20();
        if (D_0069A686 == 0) {
            *state = 5;
        }
        break;
    case 5:
        func_0023EB20();
        if (D_0069A686 != 0) {
            *state = 6;
        }
        break;
    case 6:
        func_0023EB20();
        if (D_0069A686 == 0) {
            func_0023DD60(0);
            *state = 8;
        }
        break;
    case 7:
        func_0023ED40();
        D_0069A660[0] = 0;
        D_0069A660[1] = 0;
        func_00242620(-0x200);
        *state = 8;
        break;
    case 8:
        GetCD();
        *state = 9;
        st = 9;
        goto loop;
    case 9:
        TkMenuSetHelpMessage((u8 *)func_002493D0(0x2000));
        *state = 10;
        func_0023DA90((int)t);
        break;
    case 10:
        func_0023EB20();
        if (trg & 0x20) {
            if (D_0069A660[D_0069A65C] != 0) {
                PLAY_SE(0x80000001);
                func_002D9030(D_0069A65C);
                *state = 0x10;
            } else {
                PLAY_SE(0x80000003);
            }
        } else if (trg & 0x40) {
            PLAY_SE(0x80000004);
            func_0023DB10();
            if (D_0069A688 != 0 && D_0069A7CC == 0) {
                st = 0xB;
                goto loop;
            }
            st = 0x6D;
            goto loop;
        } else if (rep & 0x5000) {
            PLAY_SE(0x80000001);
            D_0069A65C = (D_0069A65C == 0);
        }
        break;
    case 0xB: {
        int a = func_002493D0(0x202F);
        int b = func_002493D0(0x2006);
        int c = func_002493D0(0x2007);

        TkMenuSetHelpMessage(0);
        func_00236940(a, b, c);
        *state = 0xC;
        break;
    }
    case 0xC: {
        Task *w = TOMenuGetYesNoWindow();

        if (w->b45 < 0) {
            TOMenuCloseYesNoWindow();
            st = 7;
            goto loop;
        }
        if (w->b45 != 0) {
            int sel = w->x48;
            TOMenuCloseYesNoWindow();
            st = (sel == 0) ? 0x6D : 7;
            goto loop;
        }
        break;
    }
    case 0xD: {
        int msg;

        func_0023ED40();
        func_0023EA48();
        TkMenuSetHelpMessage(0);
        TOMenuCloseYesNoWindow();
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CE0);
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CE8);
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CF0);
        if (D_0069A65C != 0) {
            msg = func_002493D0(0x202D);
        } else {
            msg = func_002493D0(0x200A);
        }
        func_00242620(-0x200);
        func_00236960(msg, 0, 0);
        *state = 0xF;
        break;
    }
    case 0xE: {
        int msg;

        func_0023ED40();
        TkMenuSetHelpMessage(0);
        func_0023EA48();
        TOMenuCloseYesNoWindow();
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CE0);
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CE8);
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CF0);
        if (D_0069A65C != 0) {
            msg = func_002493D0(0x2030);
        } else {
            msg = func_002493D0(0x2012);
        }
        func_00236960(msg, 0, 0);
        *state = 0xF;
        break;
    }
    case 0xF:
        func_0023EB20();
        if (trg != 0) {
            TOMenuCloseYesNoWindow();
            func_00242620(-0x200);
            PLAY_SE(0x80000001);
            *state = 7;
        }
        break;
    case 0x10: {
        s32 *p_d0 = &D_0069A7D0;

        *p_d0 = func_002369A0(func_002493D0(0x2010), 0, 0);
        func_00242620(0x200);
        func_0023ED58(D_0069A65C);
        func_0023DB10();
        TkMenuSetHelpMessage((u8 *)func_002493D0(0x2011));
        *state = 0x14;
        break;
    }
    case 0x11:
        func_00242620(0x200);
        func_0023ED58(D_0069A65C);
        func_0023DB10();
        func_0023EA48();
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CE0);
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CE8);
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CF0);
        TkMenuSetHelpMessage((u8 *)func_002493D0(0x2011));
        *state = 0x12;
        break;
    case 0x12: {
        int r = func_002D9050(D_0069A65C, &D_0069A664, 0, 0);

        if (r == 0) {
            *state = 0x13;
        }
        if (r < 0) {
            *state = 0xE;
        }
        break;
    }
    case 0x13: {
        int res;
        int r = func_002D8AC8(1, 0, &res);

        if (r == 1) {
            if (res >= -2 && D_0069A664 == 2) {
                *state = 0x14;
            } else {
                *state = 0xE;
            }
        }
        if (r < 0) {
            *state = 0xE;
        }
        break;
    }
    case 0x14:
        *state = 0x15;
    case 0x15: {
        int res;

        if (func_002D8AC8(1, 0, &res) != 0) {
            *state = 0x16;
            st = 0x16;
            goto loop;
        }
        break;
    }
    case 0x16: {
        int i;

        for (i = 3; i >= 0; i--) {
            D_0030B170[i] = 0;
        }
        func_002D9208(D_0030B180, D_00326F58);
        if (func_002D8E40(D_0030B180, 0, 1, D_0030B280) == 0) {
            *state = 0x18;
            st = 0x18;
            goto loop;
        }
        *state = 0xE;
        break;
    }
    case 0x17:
        if (func_002D8E40(D_0030B180, 1, 1, D_0030B280) == 0) {
            *state = 0x18;
            st = 0x18;
            goto loop;
        }
        *state = 0xE;
        /* fallthrough? No, look at line 491: sw $2, 0($19) falls through to case 0x18! */
    case 0x18: {
        int res;
        int r = func_002D8AC8(1, 0, &res);

        if (r == 0) {
            break;
        }
        if (r < 0) {
            *state = 0xE;
        }
        if (res == 1) {
            int n = func_002D9270(D_0030B2A0);

            D_0030B170[n / 32] |= 1 << n;
            *state = 0x17;
            st = 0x17;
            goto loop;
        }
        if (res == 0 || res == -2) {
            *state = 0x19;
            st = 0x19;
            goto loop;
        }
        *state = 0xE;
        break;
    }
    case 0x19: {
        int r = func_002D9050(D_0069A65C, 0, 0, 0);

        if (r == 0) {
            *state = 0x1A;
            st = 0x1A;
            goto loop;
        }
        if (r < 0) {
            *state = 0xE;
        }
        break;
    }
    case 0x1A: {
        int res;
        int r = func_002D8AC8(1, 0, &res);

        if (r == 1) {
            if (res == 0 || res == -2) {
                *state = 0x1B;
            } else {
                *state = 0xE;
            }
        }
        if (r < 0) {
            *state = 0xE;
        }
        /* fallthrough to case 0x1B! */
    }
    case 0x1B: {
        int r = func_0023ED88(D_0069A65C);

        if (r < 0) {
            *state = 0xE;
            break;
        }
        if (func_00242630() == 0x1000 && r != 0 && TOMenuGetFirstReadEndFlag() == 1) {
            *state = 0x1E;
        }
        break;
    }
    case 0x1C:
        func_00242620(-0x200);
        *state = 0x1D;
        break;
    case 0x1D:
        if (func_00242630() == 0) {
            *state = 7;
        }
        break;
    case 0x1E: {
        int r;

        TOMenuCloseYesNoWindow();
        if (func_002D8A00(D_0069A65C) < 0) {
            D_0069A680 = D_0069A67C;
        } else {
            D_0069A680 = func_002D8A00(D_0069A65C);
        }
        r = func_002D9050(D_0069A65C, 0, 0, 0);
        if (r == 0) {
            *state = 0x1F;
            st = 0x1F;
            goto loop;
        }
        if (r < 0) {
            *state = 0xE;
        }
        break;
    }
    case 0x1F: {
        int res;
        int r = func_002D8AC8(1, 0, &res);

        if (r == 1) {
            if (res == 0) {
                *state = 0x20;
                st = 0x20;
                goto loop;
            }
            *state = 0xE;
        }
        if (r < 0) {
            *state = 0xE;
        }
        break;
    }
    case 0x20:
        if (D_0069A688 != 0) {
            if (D_0069A670 != 0 || D_0069A66C >= D_0069A7C8) {
                *state = 0x21;
                st = 0x21;
                goto loop;
            }
            PLAY_SE(0x80000003);
            {
                int msg = (D_0069A65C != 0) ? func_002493D0(0x202E) : func_002493D0(0x202B);

                func_00242620(-0x200);
                func_00236940(msg, 0, 0);
                TkMenuSetHelpMessage(0);
                *state = 0x22;
            }
        } else {
            if (D_0069A670 == 0) {
                int msg;

                PLAY_SE(0x80000003);
                msg = (D_0069A65C != 0) ? func_002493D0(0x2031) : func_002493D0(0x2013);
                func_00236940(msg, 0, 0);
                TkMenuSetHelpMessage(0);
                *state = 0x22;
            } else {
                *state = 0x21;
                st = 0x21;
                goto loop;
            }
        }
        break;
    case 0x22:
        func_0023ED40();
        *state = 0x23;
        break;
    case 0x23:
        func_0023EB20();
        if (D_0069A660[D_0069A65C] == 0) {
            TOMenuCloseYesNoWindow();
            func_00242620(-0x200);
            *state = 0xD;
        } else if (D_00326038->b45 != 0) {
            TOMenuCloseYesNoWindow();
            func_00242620(-0x200);
            *state = 7;
        }
        break;
    case 0x21: {
        Task *w;

        PLAY_SE(0x80000010);
        func_0023E938((int)t);
        w = D_0069A644;
        w->x48 = D_0069A680;
        w->x32 = (u16)D_0069A680 - ((u16)w->x3A >> 1);
        if (w->x32 >= (u16)w->x30 - (u16)w->x3A) {
            w->x32 = (u16)w->x30 - (u16)w->x3A;
        }
        if (D_0069A644->x32 < 0) {
            D_0069A644->x32 = 0;
        }
        D_0069A644->x34 = D_0069A644->x32;
        func_0023ED40();
        *state = 0x25;
        break;
    }
    case 0x24:
        func_002433B8(D_0069A644);
        func_0023ED40();
        if (D_0069A688 != 0) {
            TkMenuSetHelpMessage((u8 *)func_002493D0(0x2004));
        } else {
            TkMenuSetHelpMessage((u8 *)func_002493D0(0x201F));
        }
        *state = 0x25;
    case 0x25:
        func_0023EB20();
        if (D_0069A660[D_0069A65C] == 0) {
            *state = 0xD;
        } else if (D_0069A644->b45 > 0) {
            D_0069A75C = *(s16 *)((u8 *)D_0069A644 + 0x2C);
            if (D_0069A688 != 0) {
                *state = 0x27;
            } else {
                *state = 0x60;
            }
        } else if (D_0069A644->b45 < 0) {
            func_0023EA48();
            TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CE0);
            TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CE8);
            TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CF0);
            *state = 0x1C;
        }
        break;
    case 0x27:
        if (D_0069A690[D_0069A75C] != 1 && D_0069A690[D_0069A75C] != 2) {
            *state = 0x2B;
            st = 0x2B;
            goto loop;
        }
        {
            int need = D_0069A7C8 - D_0069A6F8[D_0069A75C];

            if (D_0069A690[D_0069A75C] == 2 && D_0069A66C < need) {
                int msg;

                PLAY_SE(0x80000003);
                msg = (D_0069A65C != 0) ? func_002493D0(0x202E) : func_002493D0(0x202B);
                func_00236940(msg, 0, 0);
                TkMenuSetHelpMessage(0);
                *state = 0x26;
            } else {
                int a = func_002493D0(0x2005);
                int b = func_002493D0(0x2006);
                int c = func_002493D0(0x2007);

                func_00236940(a, b, c);
                *state = 0x28;
            }
        }
        break;
    case 0x26:
        func_0023EB20();
        if (D_0069A660[D_0069A65C] == 0) {
            TOMenuCloseYesNoWindow();
            func_0023EA48();
            func_00242620(-0x200);
            TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CE0);
            TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CE8);
            TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CF0);
            *state = 0xD;
        } else if (D_00326038->b45 != 0) {
            TOMenuCloseYesNoWindow();
            *state = 0x29;
            st = 0x29;
            goto loop;
        }
        break;
    case 0x28:
        func_0023EB20();
        if (D_0069A660[D_0069A65C] == 0) {
            TOMenuCloseYesNoWindow();
            *state = 0xD;
        } else if (D_00326038->b45 != 0) {
            if (D_00326038->x48 != 0 || D_00326038->b45 < 0) {
                TOMenuCloseYesNoWindow();
                *state = 0x29;
                st = 0x29;
                goto loop;
            }
            TOMenuCloseYesNoWindow();
            *state = 0x3F;
            st = 0x3F;
            goto loop;
        }
        break;
    case 0x29:
        *state = 0x2A;
        goto L_2A;
    case 0x2B:
        *state = 0x2C;
    case 0x2C:
        if (func_0023EC50() != 0) {
            *state = 0x2D;
            st = 0x2D;
            goto loop;
        }
        break;
    case 0x2D: {
        int r = func_002D9050(D_0069A65C, &D_0069A664, 0, &D_0069A668);

        if (r == 0) {
            *state = 0x2E;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x2E: {
        int res;
        int r = func_002D8AC8(1, 0, &res);

        if (r == 1) {
            if (res != 0 || D_0069A664 != 2) {
                *state = 0x5E;
            }
            if (D_0069A668 != 0) {
                *state = 0x3F;
            } else {
                *state = 0x2F;
                st = 0x2F;
                goto loop;
            }
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x2F: {
        int r = func_002D9050(D_0069A65C, &D_0069A664, 0, &D_0069A668);

        if (r == 0) {
            *state = 0x30;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x30: {
        int res;
        int r = func_002D8AC8(1, 0, &res);

        if (r == 1) {
            if (res != 0 || D_0069A664 != 2) {
                *state = 0x5E;
            }
            if (D_0069A668 != 0) {
                *state = 0x3F;
            } else {
                *state = 0x31;
                st = 0x31;
                goto loop;
            }
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x31:
        *state = 0x32;
    case 0x32:
        if (func_0023EC50() != 0) {
            *state = 0x33;
            st = 0x33;
            goto loop;
        }
        break;
    case 0x33: {
        int a = func_002493D0(D_0069A65C + 0x200B);
        int b = func_002493D0(0x2006);
        int c = func_002493D0(0x2007);

        func_00236940(a, b, c);
        *state = 0x34;
        break;
    }
    case 0x34:
        func_0023EB20();
        if (D_0069A660[D_0069A65C] == 0) {
            TOMenuCloseYesNoWindow();
            *state = 0xD;
        } else if (D_00326038->b45 != 0) {
            if (D_00326038->x48 != 0 || D_00326038->b45 < 0) {
                TOMenuCloseYesNoWindow();
                *state = 0x35;
                st = 0x35;
                goto loop;
            }
            TOMenuCloseYesNoWindow();
            *state = 0x37;
            st = 0x37;
            goto loop;
        }
        break;
    case 0x35:
        *state = 0x36;
        goto L_2A;
    case 0x37:
        *state = 0x38;
    case 0x38:
        if (func_0023EC50() != 0) {
            *state = 0x39;
            st = 0x39;
            goto loop;
        }
        break;
    case 0x39: {
        s32 *p_d0 = &D_0069A7D0;
        int r = func_002D8EC8();

        TkMenuSetHelpMessage((u8 *)func_002493D0(0x200D));
        *p_d0 = func_002369A0(func_002493D0(0x2010), 0, 0);
        if (r == 0) {
            *state = 0x3A;
        }
        break;
    }
    case 0x3A: {
        int res;

        if (func_002D8AC8(1, 0, &res) == 1) {
            if (res != 0) {
                *state = 0x3D;
                st = 0x3D;
                goto loop;
            }
            *state = 0x3B;
            st = 0x3B;
            goto loop;
        }
        break;
    }
    case 0x3B:
        TOMenuCloseYesNoWindow();
        *state = 0x3C;
        st = 0x3C;
        goto loop;
    case 0x3C:
        *state = 0x3F;
        st = 0x3F;
        goto loop;
    case 0x3D:
        TOMenuCloseYesNoWindow();
        func_00236940(func_002493D0(0x200F), 0, 0);
        func_0023EA48();
        TkMenuSetHelpMessage(0);
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CE0);
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CE8);
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CF0);
        *state = 0x3E;
        break;
    case 0x3F: {
        s32 *p_d0 = &D_0069A7D0;

        TkMenuSetHelpMessage((u8 *)func_002493D0(0x2009));
        *p_d0 = func_002369A0(func_002493D0(0x2010), 0, 0);
        func_0023EC50();
        *state = 0x40;
        break;
    }
    case 0x40:
        if (func_0023EC50() != 0) {
            *state = 0x41;
            st = 0x41;
            goto loop;
        }
        break;
    case 0x41: {
        char buf[0x80];
        int r;

        func_0023CDB0(buf, D_0069A75C);
        r = func_002D8E40(buf, 0, 1, D_0069A780);
        if (r == 0) {
            *state = 0x42;
            st = 0x42;
            goto loop;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x42: {
        int res;
        int r = func_002D8AC8(1, 0, &res);

        if (r == 1) {
            if (res > 0) {
                *state = 0x45;
                st = 0x45;
                goto loop;
            }
            if (res == -4 || res == 0) {
                *state = 0x43;
                st = 0x43;
                goto loop;
            }
            *state = 0x5E;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x43: {
        char buf[0x80];
        int r;

        func_0023CDB0(buf, D_0069A75C);
        r = func_002D8D90(buf);
        if (r == 0) {
            *state = 0x44;
            st = 0x44;
            goto loop;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x44: {
        int res;
        int r = func_002D8AC8(1, 0, &res);

        if (r == 1) {
            if (res == -4 || res == 0) {
                *state = 0x45;
                st = 0x45;
                goto loop;
            }
            *state = 0x5E;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x45: {
        char buf[0x80];
        int r;

        func_0023CC50(buf, D_0069A75C);
        r = func_002D8E40(buf, 0, 1, D_0069A780);
        if (r == 0) {
            *state = 0x46;
            st = 0x46;
            goto loop;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x46: {
        int res;
        int r = func_002D8AC8(1, 0, &res);

        if (r == 1) {
            if (res > 0) {
                if ((D_0069A790 + 0x3FF) / 1024 == (D_0032648C + 0x3FF) / 1024) {
                    *state = 0x4D;
                    st = 0x4D;
                    goto loop;
                }
                *state = 0x47;
                st = 0x47;
                goto loop;
            }
            if (res == -4 || res == 0) {
                *state = 0x47;
                st = 0x47;
                goto loop;
            }
            *state = 0x5E;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x47: {
        char buf[0x80];
        int r;

        func_0023CC50(buf, D_0069A75C);
        r = func_002D8D28(buf, 0x202);
        if (r == 0) {
            *state = 0x48;
            st = 0x48;
            goto loop;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x48: {
        int res;
        int r = func_002D8AC8(1, 0, &res);

        if (r == 1) {
            if (res >= 0) {
                D_0069A7C4 = res;
                *state = 0x49;
                st = 0x49;
                goto loop;
            }
            *state = 0x5E;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x49: {
        int sz = D_0032648C;
        int r = func_002D8C78(D_0069A7C4, 0x01D60000, sz);

        if (r == 0) {
            *state = 0x4A;
            st = 0x4A;
            goto loop;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x4A: {
        int res;
        int r = func_002D8AC8(1, 0, &res);

        if (r == 1) {
            if (res >= 0) {
                *state = 0x4B;
                st = 0x4B;
                goto loop;
            }
            break;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x4B: {
        int r = func_002D8FA0(D_0069A7C4);

        if (r == 0) {
            *state = 0x4C;
            st = 0x4C;
            goto loop;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x4C: {
        int res;
        int r = func_002D8AC8(1, 0, &res);

        if (r == 1) {
            if (res >= 0) {
                *state = 0x4D;
                st = 0x4D;
                goto loop;
            }
            *state = 0x5E;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x4D: {
        char buf[0x80];
        int r;

        func_0023CD30(buf, D_0069A75C);
        r = func_002D8D28(buf, 0x202);
        if (r == 0) {
            *state = 0x4E;
            st = 0x4E;
            goto loop;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x4E: {
        int res;
        int r = func_002D8AC8(1, 0, &res);

        if (r == 1) {
            if (res >= 0) {
                D_0069A7C4 = res;
                *state = 0x4F;
                st = 0x4F;
                goto loop;
            }
            *state = 0x5E;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x4F: {
        int area = func_001487D0();
        void *save = func_00124828();
        int secs = func_0023D268((void *)0x01D57B00, save, D_0069A75C);
        int r;

        func_0023D4B8(D_0069A75C, secs, area);
        r = func_002D8C78(D_0069A7C4, 0x01D5E000, 0x3C4);
        if (r == 0) {
            *state = 0x50;
            st = 0x50;
            goto loop;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x50: {
        int res;
        int r = func_002D8AC8(1, 0, &res);

        if (r == 1) {
            if (res >= 0) {
                *state = 0x51;
                st = 0x51;
                goto loop;
            }
            break;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x51: {
        int r = func_002D8FA0(D_0069A7C4);

        if (r == 0) {
            *state = 0x52;
            st = 0x52;
            goto loop;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x52: {
        int res;
        int r = func_002D8AC8(1, 0, &res);

        if (r == 1) {
            if (res >= 0) {
                *state = 0x53;
                st = 0x53;
                goto loop;
            }
            *state = 0x5E;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x53: {
        char buf[0x80];
        int r;

        func_0023CBD0(buf, D_0069A75C);
        r = func_002D8D28(buf, 0x202);
        if (r == 0) {
            *state = 0x54;
            st = 0x54;
            goto loop;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x54: {
        int res;
        int r = func_002D8AC8(1, 0, &res);

        if (r == 1) {
            if (res >= 0) {
                D_0069A7C4 = res;
                *state = 0x55;
                st = 0x55;
                goto loop;
            }
            *state = 0x5E;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x55: {
        int r = func_002D8C78(D_0069A7C4, 0x01D57B00, 0x64F8);

        if (r == 0) {
            *state = 0x56;
            st = 0x56;
            goto loop;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x56: {
        int res;
        int r = func_002D8AC8(1, 0, &res);

        if (r == 1) {
            if (res >= 0) {
                *state = 0x57;
                st = 0x57;
                goto loop;
            }
            break;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x57: {
        int r = func_002D8FA0(D_0069A7C4);

        if (r == 0) {
            *state = 0x58;
            st = 0x58;
            goto loop;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x58: {
        int res;
        int r = func_002D8AC8(1, 0, &res);

        if (r == 1) {
            if (res >= 0) {
                *state = 0x59;
                st = 0x59;
                goto loop;
            }
            *state = 0x5E;
        }
        if (r < 0) {
            *state = 0x5E;
        }
        break;
    }
    case 0x59:
        *state = 0x5A;
        break;
    case 0x5A:
        if (func_002D9050(D_0069A65C, 0, &D_0069A66C, 0) == 0) {
            *state = 0x5B;
            st = 0x5B;
            goto loop;
        }
        break;
    case 0x5B: {
        int res;

        if (func_002D8AC8(1, 0, &res) == 1) {
            if (res == 0) {
                *state = 0x5C;
            } else if (res != -2) {
                *state = 0x5E;
            } else {
                D_0069A66C = 0x2000;
                *state = 0x5E;
            }
            func_0023EA68(D_0069A66C, D_0069A7C8);
        }
        break;
    }
    case 0x5C:
        TOMenuCloseYesNoWindow();
        memcpy(func_0023CE08(D_0069A75C), (void *)0x01D57B00, 0x40);
        D_0069A690[D_0069A75C] = 1;
        D_0069A7CC = 1;
        func_002D89E8(D_0069A65C, D_0069A75C);
        PLAY_SE(0x8000002B);
        *state = 0x5D;
    case 0x5D:
        func_0023EA68(D_0069A66C, D_0069A7C8);
    case 0x2A:
    case 0x36:
    L_2A:
        *state = 0x24;
        break;
    case 0x5E:
        TOMenuCloseYesNoWindow();
        func_00236940(func_002493D0(0x2015), 0, 0);
        func_0023EA48();
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CE0);
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CE8);
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CF0);
        TkMenuSetHelpMessage(0);
        *state = 0x5F;
        break;
    case 0x60:
        *state = 0x61;
    case 0x61:
        if (func_0023EC50() != 0) {
            *state = 0x62;
        }
        break;
    case 0x62: {
        s32 *p_d0 = &D_0069A7D0;
        char buf[0x80];
        int r;

        TkMenuSetHelpMessage((u8 *)func_002493D0(0x2008));
        *p_d0 = func_002369A0(func_002493D0(0x2010), 0, 0);
        func_0023CBD0(buf, D_0069A75C);
        r = func_002D8D28(buf, 1);
        if (r == 0) {
            *state = 0x63;
            st = 0x63;
            goto loop;
        }
        if (r < 0) {
            *state = 0x6A;
        }
        break;
    }
    case 0x63: {
        int res;
        int r = func_002D8AC8(1, 0, &res);

        if (r == 1) {
            if (res >= 0) {
                D_0069A7C4 = res;
                *state = 0x64;
                st = 0x64;
                goto loop;
            }
            *state = 0x6A;
        }
        if (r < 0) {
            *state = 0x6A;
        }
        break;
    }
    case 0x64: {
        int r = func_002D8CD0(D_0069A7C4, 0x01D57B00, 0x64F8);

        if (r == 0) {
            *state = 0x65;
            st = 0x65;
            goto loop;
        }
        if (r < 0) {
            *state = 0x6A;
        }
        break;
    }
    case 0x65: {
        int res;
        int r = func_002D8AC8(1, 0, &res);

        if (r == 1) {
            if (res >= 0) {
                *state = 0x66;
                st = 0x66;
                goto loop;
            }
            break;
        }
        if (r < 0) {
            *state = 0x6A;
        }
        break;
    }
    case 0x66: {
        int r = func_002D8FA0(D_0069A7C4);

        if (r == 0) {
            *state = 0x67;
            st = 0x67;
            goto loop;
        }
        if (r < 0) {
            *state = 0x6A;
        }
        break;
    }
    case 0x67: {
        int res;
        int r = func_002D8AC8(1, 0, &res);

        if (r == 1) {
            if (res >= 0) {
                *state = 0x68;
                st = 0x68;
                goto loop;
            }
            *state = 0x6A;
        }
        if (r < 0) {
            *state = 0x6A;
        }
        break;
    }
    case 0x68: {
        typedef struct { u8 pad[4]; s32 x; } Off4;
        u8 *rec = func_0023CE08(D_0069A75C);

        if (*(u16 *)(rec + 0x1A) != 0) {
            u16 crc = *(u16 *)0x01D5DFF4;

            ((Off4 *)0x01D5DFF0)->x = 0;
            if (*(u16 *)(rec + 0x1A) != (u16)func_002510A0(0x64B8, (void *)0x01D57B40) || *(u16 *)(rec + 0x1A) != crc) {
                *state = 0x6B;
                break;
            }
        } else {
            if (*(u16 *)0x01D5DFF4 != 0) {
                *state = 0x6B;
                break;
            }
        }
        PLAY_SE(0x8000006A);
        D_0069A7CC = 1;
        func_002D89E8(D_0069A65C, D_0069A75C);
        func_0023EA48();
        TOMenuCloseYesNoWindow();
        func_0023D190((SaveDataBody *)func_00124828(), (u8 *)0x01D57B00);
        TkMenuSetHelpMessage((u8 *)func_002493D0(0x2008));
        TkRefreshSoundMode();
        TkRefreshHDD();
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CE0);
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CE8);
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CF0);
        func_00242668();
        *state = 0x69;
        break;
    }
    case 0x69:
        D_003263E0 = 1;
        *state = 0x6D;
        break;
    case 0x6A:
        TOMenuCloseYesNoWindow();
        func_00236940(func_002493D0(0x2016), 0, 0);
        func_0023EA48();
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CE0);
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CE8);
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CF0);
        TkMenuSetHelpMessage(0);
        PLAY_SE(0x80000003);
        *state = 0x6C;
        break;
    case 0x6B:
        TOMenuCloseYesNoWindow();
        func_00236940(func_002493D0(0x201D), 0, 0);
        func_0023EA48();
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CE0);
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CE8);
        TOSeqStopScene(1, &_m2c_func_0023E938_D_00572CF0);
        TkMenuSetHelpMessage(0);
        PLAY_SE(0x80000003);
        *state = 0x6C;
        break;
    case 0x3E:
    case 0x5F:
    case 0x6C:
        if (D_00326038->b45 != 0) {
            TOMenuCloseYesNoWindow();
            *state = 7;
        }
        break;
    case 0x6D:
        TOMenuHelpSetExtMode(0, D_0069A7CC);
        if ((TkMn2GetMenuMode() & 0xFFFF0000) != 0) {
            TkMn2SetMainFrameRatioDiff(0x10);
        }
        *state = 0x6E;
    case 0x6E:
        if ((TkMn2GetMenuMode() & 0xFFFF0000) != 0) {
            if (TkMn2GetMainFrameRatio() < 0x80) {
                break;
            }
            *state = 0x6F;
            break;
        }
        *state = 0x6F;
    case 0x6F:
        if (TOGetFFXLangSwapFlag() == 1 && D_003263E0 == 1) {
            TOSwapInternationalEnvInit(func_001BD360());
            *state = 0x70;
        } else {
            *state = 0x71;
        }
        break;
    case 0x70:
        if (TOSwapInternationalEnvExecNonBlock() == 1) {
            D_003263E0 = 0;
            *state = 0x71;
        }
        break;
    case 0x71: {
        int _pad;
        __asm__("" : : "m"(_pad));
        func_0023DDD0();
        if (D_0069A688 != 0) {
            TkMenuMainSleepMenu(0xF);
            TkMenuMainActiveMenu(1, 0);
        } else {
            TkMenuMainSleepMenu(0x10);
        }
        break;
    }
    case 2:
        break;
    }
}


void func_00241240(void) {
}

void func_00241248(void) {
    D_0069A7C8 = func_0014F168();
}

void func_00241270(void) {
}

void func_00241278(Task *t)
{
    int i;

    D_0069A7CC = 0;
    func_002D89C8(1);
    D_0069A640 = 0;
    t->x1C = 0;
    for (i = 0; i < 2; i++) {
        D_0069A660[i] = 0;
    }
    func_0023ED40();
    D_0069A688 = 1;
    func_00241F70(0);
    TkMn2SetMainFrameRatioDiff(-0x10);
}

void func_00241308(Task *t)
{
    int i;

    D_0069A7CC = 0;
    func_002D89C8(1);
    D_0069A640 = 0;
    t->x1C = 0;
    for (i = 0; i < 2; i++) {
        D_0069A660[i] = 0;
    }
    func_0023ED40();
    D_0069A688 = 0;
    func_00241F70(0);
    TkMn2SetMainFrameRatioDiff(-0x10);
}

void func_00241390(void) {
}

void func_00241398(void) { func_002D89C8(0); }

void func_002413A0(int a0) { func_002D89E8(a0, -1); }

void func_002413A8(void) {
    func_002413A0(0);
    func_002413A0(1);
}

void func_002413C8(void) {
}

void TOMenuMakeSaveFileName(void)
{
    switch (func_0020B850()) {
    case 0:
        func_002F072C(D_00326F58, D_00326E50);
        break;
    case 1:
        func_002F072C(D_00326F58, D_00326E60);
        break;
    case 2:
        func_002F072C(D_00326F58, D_00326E70);
        break;
    case 3:
        func_002F072C(D_00326F58, D_00326E80);
        break;
    case 4:
        func_002F072C(D_00326F58, D_00326EB0);
        break;
    case 5:
        func_002F072C(D_00326F58, D_00326EA0);
        break;
    case 6:
        func_002F072C(D_00326F58, D_00326E90);
        break;
    case 16:
        func_002F072C(D_00326F58, D_00326E50);
        break;
    case 17:
        func_002F072C(D_00326F58, D_00326EC0);
        break;
    case 18:
        func_002F072C(D_00326F58, D_00326ED0);
        break;
    }
    func_002F032C(D_00326F58, D_00326EE0);
    D_003263E0 = 0;
}
