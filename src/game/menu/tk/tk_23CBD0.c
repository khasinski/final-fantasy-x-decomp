/* tu_266 0x23cbd0-0x2414f0: medium; ~Tk (config/tu_map.tsv) */
#define TkMenuCtrlSelFileWindow _hdr_TkMenuCtrlSelFileWindow
#include "common.h"
#include "ffx/r5.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/s5.h"
#include "ffx/u4.h"
#include "ffx/v5.h"
#undef TkMenuCtrlSelFileWindow
void TkMenuCtrlSelFileWindow(Task *t);

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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23CBD0", func_0023D750);

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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23CBD0", func_0023F298);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_23CBD0/rodata", jtbl_00572DB0);

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
