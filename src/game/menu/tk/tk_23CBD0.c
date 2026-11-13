/* tu_266 0x23cbd0-0x2414f0: medium; ~Tk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r5.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/s5.h"
#include "ffx/u4.h"
#include "ffx/v5.h"

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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23CBD0", func_0023CE38);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23CBD0", func_0023CF70);

typedef struct SaveDataBody {
    u8 d[0x64B8];
} SaveDataBody;

void func_0023D190(SaveDataBody *dst, u8 *src)
{
    *dst = *(SaveDataBody *)(src + 0x40);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23CBD0", func_0023D268);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23CBD0", func_0023D4B8);

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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23CBD0", TkMenuCtrlSelFileWindow);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_23CBD0/rodata", jtbl_00572D00);

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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23CBD0", func_0023E6B0);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23CBD0", func_0023E798);

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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23CBD0", func_0023EA68);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_23CBD0/rodata", jtbl_00572D50);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23CBD0", func_0023EB20);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23CBD0", func_0023EC50);

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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23CBD0", func_0023ED88);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_23CBD0/rodata", jtbl_00572D70);

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
