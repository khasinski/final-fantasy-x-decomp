/* tu_273 0x24b828-0x250d00: low; ~Tk (config/tu_map.tsv) */
#define TkMsImportantGet _hdr_TkMsImportantGet
#include "common.h"
#include "ffx/r5.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/s5.h"
#include "ffx/u2.h"
#include "ffx/u4.h"
#include "ffx/v5.h"
#include "ffx/w8.h"
#include "ffx/r6.h"
#include "ffx/s6.h"
#undef TkMsImportantGet
int TkMsImportantGet(int id);
void func_002274A0(int a, int b, int c, int d);

void func_0024B828(void)
{
    func_00227460(D_00573300, D_0069BEC8);
    func_00227460(D_00573310, D_0069BED0);
}

int func_0024B860(u32 *base, int i, int j) {
    u32 *p = base + i * 8;
    u32 *q = base + j * 8;
    int k;

    for (k = 0; k < 8; k++, p++, q++) {
        if (*p > *q) {
            return 1;
        }
        if (*p < *q) {
            return -1;
        }
    }
    return 0;
}

void func_0024B8C0(u32 *base, int i, int j) {
    u32 *p = base + i * 8;
    u32 *q = base + j * 8;
    int k;

    for (k = 7; k >= 0; k--) {
        u32 x = *p;
        u32 y = *q;

        *p++ = y;
        *q++ = x;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024B900);

void func_0024BC48(void)
{
    u16 *p;
    int ofs = 0;
    int i;
    int j;

    for (i = 0; i < 7; i++) {
        p = D_0069BEA8[i];
        for (j = 1; j >= 0; j--) {
            int n = *p++;

            func_0024B900(0x1D57300, ofs, n);
            ofs += n;
        }
    }
}

int func_0024BCE0(SysEntry *tbl, int i, int end) {
    for (;;) {
        if (i >= end) {
            return -1;
        }
        if (tbl[i].b2 != 0) {
            return i;
        }
        i++;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024BD20);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024BDF8);

int func_0024BEE8(u8 *buf, int ch, int start, int end) {
    for (;;) {
        if (start >= end) {
            return -1;
        }
        if (buf[start] == ch) {
            return start;
        }
        start++;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024BF18);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024C088);

void func_0024C1F8(Task *t, int x, int y) {
    x += 0xC;
    y += 1;
    func_002270F8(x + D_003260B8.x, y + D_003260B8.y + ((t->x48 - t->x32) << 5), 0);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024C238);

/* DEBT(FAKE) */
void func_0024C398(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    register s32 _cond __asm__("$3");
    s32 temp_19;
    s32 temp_7;
    s32 var_16;
    s32 var_17;
    s32 var_6;

    var_16 = -1;
    temp_19 = arg3 + D_003260B8.x;
    var_17 = arg4 + D_003260B8.y;
    var_6 = var_17;
    do {
        temp_7 = var_16 + arg2;
        func_0024C238(arg0, temp_19, var_6, temp_7, arg1);
        var_16 += 1;
        var_17 += 0x20;
        graphicUiRemapY2();
        var_6 = var_17;
    } while ((_cond = (var_16 < 0xA)) != 0);
}

void func_0024C438(Task *o) {
    if (o->b45 >= 0) {
        TkMenuCtrlSelFileWindow(o);
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024C458);

void func_0024C670(Task *o)
{
    int y;

    func_002492F0();
    func_002492F0();
    func_00225A38();
    func_00225920();
    y = D_003260B8.y;
    func_0024C458(D_0069BE40);
    if (o->x32 == o->x34) {
        func_002274A0(y - 8, 0x128, 0, o->x46);
        func_0024C398((s32)o, 0, o->x32, 0, -0x20);
    } else {
        func_002274A0(y - 8, 0x128, 1, o->x46);
        func_0024C398((s32)o, 1, o->x32, 0, -0x20);
        func_002274A0(y - 8, 0x128, 2, o->x46);
        func_0024C398((s32)o, 2, o->x34, 0, (-(o->x46 * 0x120)) / 4096 - 0x20);
    }
    func_00225908();
    if (o->b45 >= 0) {
        func_0024C1F8(o, 0, 0);
    }
    func_00225E88(D_00326108[0], D_00326108[1], D_00326108[2], D_00326108[3], o->x32, (u16)o->x3A, (u16)o->x30);
    func_00225B00();
}

int func_0024C7D0(void) { return 1; }

void func_0024C7D8(void)
{
    int one;
    Task *t = func_00243400();

    V5_INT0(func_002394F0)();
    one = 1; /* DEBT(FAKE): early constant load (found by the permuter) */
    D_0069BE74 = 0;
    t->x48 = 0;
    t->x32 = 0;
    t->x34 = 0;
    t->x0C = (s32)func_0024C438; /* DEBT(CAST): Task callbacks are typed s32 */
    t->x10 = (s32)func_0024C670;
    t->x14 = (s32)func_0024C7D0;
    t->b3E = one;
    t->b42 = 2;
    t->x30 = func_002249A8();
    t->b45 = -1;
    t->x3A = 9;
    D_0069BE40 = t;
    TkMenuMainRegistWindow(t);
    func_00227480(D_00573398);
    func_00227490(D_005733A0);
    func_00227490(D_005733A8);
}

void func_0024C898(void)
{
    if (D_0069BE40) {
        D_0069BE40->b41 = 1;
        D_0069BE40->x10 = 0;
        D_0069BE40 = 0;
    }
}

void func_0024C8C0(void)
{
    if (D_0069BE58) {
        D_0069BE58->b41 = 1;
        D_0069BE58->x10 = 0;
        D_0069BE58 = 0;
    }
}

void func_0024C8E8(void)
{
    if (D_0069BE5C) {
        D_0069BE5C->b41 = 1;
        D_0069BE5C->x10 = 0;
        D_0069BE5C = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", TkMenuItemRefresh);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_24B828/rodata", jtbl_005733B0);

int func_0024CB28(void) {
    return D_0069BE48;
}

int TkMenuImportantListMax(void) {
    return D_0069BE4C;
}

int func_0024CB48(void) {
    return D_0069BE44;
}

void func_0024CB58(int a0) {
    switch (a0) {
    case 0:
        TkMenuItemRefresh(2);
        break;
    case 1:
        TkMenuItemRefresh(1);
        break;
    case 2:
        TkMenuItemRefresh(3);
        break;
    case 3:
        TkMenuItemRefresh(6);
        break;
    }
}

int MsGetSaveSP(void) { return func_0024CB28(); }

int TOAmapGetItemType(int idx)
{
    SysEntry *e = SYS_TBL;

    e += idx;
    return e->h0;
}

int func_0024CBF0(int idx)
{
    SysEntry *e = SYS_TBL;

    e += idx;
    return e->b2;
}

int TkCalcImportantListMax(void)
{
    s32 pos;
    int n = 0;
    int id = 0xA000;

    while (MsImportantPtr(id, &pos)->b10 != 0xFF) {
        n++;
        id++;
    }
    D_0069BE4C = n;
    return n;
}

void TkMenuItemImportantRefresh(void)
{
    s32 pos;
    u16 *p = (u16 *)0x1D56B00;
    int i = 0;
    int max = TkMenuImportantListMax();

    for (; i < max; i++) {
        *p++ = 0;
    }
    D_0069BE44 = 0;
    p = (u16 *)0x1D56B00;
    for (i = 0; i < max; i++) {
        int id = i + 0xA000;

        if (TkMsImportantGet(id)) {
            OfsTbl *t = MsImportantPtr(id, &pos);

            p[t->pad13] = id;
            if (D_0069BE44 < t->pad13 + 1) {
                D_0069BE44 = t->pad13 + 1;
            }
        }
    }
}

int func_0024CD68(void) {
    return D_0069BE50;
}

int func_0024CD78(int p)
{
    ScriptRec *rec;
    SysEntry *e;
    OfsTbl *t;
    s32 buf;
    int cnt = 0;
    int lim;
    int i;
    u16 id;

    rec = (ScriptRec *)MsMenuStatusNum(0, 0); /* DEBT(CAST): declared as OfsTbl * */
    D_0069BE72 = -1;
    lim = TkMenuGetMP(p);
    e = SYS_TBL;
    for (i = 0; i < 512; i++) {
        e->h0 = 0;
        e->b2 = 0;
        e->b3 = 0;
        e++;
    }
    e = SYS_TBL;
    while (rec->op != 0xFF) {
        if (rec->flag == 0) {
            switch (rec->op) {
            case 0x40:
            case 0x41:
            case 0x44:
            case 0x45:
                id = rec->id;
                MsGetSavePlayerPtr(p);
                if (MsGetSaveCommand(p, id)) {
                    e->h0 = id;
                    e->b2 = 1;
                    t = MsGetRomPlyCommand(id, &buf);
                    if (((t->b22 >> 6) & 1) && !(lim < t->b25)) {
                        e->b3 = 1;
                        if (D_0069BE72 < 0) {
                            D_0069BE72 = cnt;
                        }
                    } else {
                        e->b3 = 0;
                    }
                    e++;
                    cnt++;
                }
                break;
            case 0x42:
            case 0x43:
                break;
            }
        }
        rec++;
    }
    D_0069BE50 = cnt;
    return cnt;
}

u8 func_0024CF20(int a0) {
    s32 buf;

    return TkMsGetRomItem(a0, &buf)->b5D;
}

int func_0024CF40(int a, int b) { return a < b; }

int func_0024CF48(int id, int idx, int flag) {
    s32 buf;
    OfsTbl *t = TkMsGetRomItem(id, &buf);
    int v = 0;

    switch (t->b28) {
    case 6:
        v = t->b2A * 50;
        break;
    case 7:
        v = ((MsGetSavePlayerPtr(idx)->b31 + t->b2A) >> 1) * t->b2A;
        break;
    case 8:
        if (flag == 0) {
            v = TkMenuGetMaxHP(idx) * t->b2A / 16;
        } else {
            v = TkMenuGetMaxMP(idx) * t->b2A / 16;
        }
        break;
    }
    return v;
}

int func_0024D038(int id, int idx) {
    s32 buf;
    OfsTbl *t = MsGetRomPlyCommand(id, &buf);
    int v = 0;

    switch (t->b28) {
    case 6:
        v = t->b2A * 50;
        break;
    case 7:
        v = ((MsGetSavePlayerPtr(idx)->b31 + t->b2A) >> 1) * t->b2A;
        break;
    case 8:
        v = TkMenuGetMaxHP(idx) * t->b2A / 16;
        break;
    }
    return v;
}

void func_0024D108(int a0, int a1) {
    int v = TkMenuGetHP(a0) + a1;

    if (v >= TkMenuGetMaxHP(a0)) {
        v = TkMenuGetMaxHP(a0);
    }
    TkMenuSetHP(a0, v);
}

extern u16 _m2c_func_0024D168_D_0069BE6A __asm__("D_0069BE6A");
u8 _m2c_func_0024D168_TkMenuGetPlayerFromIndex(int i) __asm__("TkMenuGetPlayerFromIndex");
u8 _m2c_func_0024D168_func_00242798(int i) __asm__("func_00242798");
/* DEBT(FAKE) */
void func_0024D168(s32 arg0) {
    u8 sp[0x10];
    OfsTbl *temp_2;
    s32 temp_2_2;
    s32 temp_2_4;
    s32 temp_5;
    register s32 var_16 __asm__("$16");
    register u32 var_2 __asm__("$2");
    u8 temp_2_3;
    u8 temp_2_5;
    register u32 temp_3 __asm__("$3");

    temp_5 = func_0024CF48((s32) _m2c_func_0024D168_D_0069BE6A, arg0, 0);
    if (D_0069BE6C == 1) {
        func_0024D108(arg0, temp_5);
        return;
    }
    temp_2 = TkMsGetRomItem((s32) _m2c_func_0024D168_D_0069BE6A, sp);
    __asm__ volatile("" : : : "$2");
    temp_3 = (u8) temp_2->b22;
    var_2 = temp_3 >> 7;
    if (var_2 != 0) {
        var_16 = 0;
        temp_2_2 = TkMenuGetSummonListMax();
        if (temp_2_2 > 0) {
            do {
                temp_2_3 = _m2c_func_0024D168_func_00242798(var_16);
                var_16 += 1;
                func_0024D108((s32) temp_2_3, func_0024CF48((s32) _m2c_func_0024D168_D_0069BE6A, (s32) temp_2_3, 0));
            } while (var_16 < temp_2_2);
        }
        temp_3 = (u8) temp_2->b22;
        var_2 = temp_3 >> 6;
    } else {
        var_2 = temp_3 >> 6;
    }
    if (var_2 & 1) {
        __asm__ volatile("" : "+r"(var_16));
        var_16 = 0;
        temp_2_4 = func_00242818();
        if (temp_2_4 > 0) {
            do {
                temp_2_5 = _m2c_func_0024D168_TkMenuGetPlayerFromIndex(var_16);
                var_16 += 1;
                func_0024D108((s32) temp_2_5, func_0024CF48((s32) _m2c_func_0024D168_D_0069BE6A, (s32) temp_2_5, 0));
            } while (var_16 < temp_2_4);
        }
    }
}

extern u16 _m2c_func_0024D2B0_D_0069BE6A __asm__("D_0069BE6A");
u8 _m2c_func_0024D2B0_TkMenuGetPlayerFromIndex(int i) __asm__("TkMenuGetPlayerFromIndex");
u8 _m2c_func_0024D2B0_func_00242798(int i) __asm__("func_00242798");
/* DEBT(FAKE) */
void func_0024D2B0(s32 a, s32 idx) {
    u8 sp[0x10];
    OfsTbl *temp_2;
    s32 temp_2_2;
    s32 temp_2_4;
    s32 temp_5;
    register s32 var_16 __asm__("$16");
    register u32 var_2 __asm__("$2");
    u8 temp_2_3;
    u8 temp_2_5;
    register u32 temp_3 __asm__("$3");

    temp_5 = func_0024D038((s32) _m2c_func_0024D2B0_D_0069BE6A, idx);
    if (D_0069BE6C == 1) {
        func_0024D108(a, temp_5);
        return;
    }
    temp_2 = MsGetRomPlyCommand((s32) _m2c_func_0024D2B0_D_0069BE6A, sp);
    __asm__ volatile("" : : : "$2");
    temp_3 = (u8) temp_2->b22;
    var_2 = temp_3 >> 7;
    if (var_2 != 0) {
        var_16 = 0;
        temp_2_2 = TkMenuGetSummonListMax();
        if (temp_2_2 > 0) {
            do {
                temp_2_3 = _m2c_func_0024D2B0_func_00242798(var_16);
                var_16 += 1;
                func_0024D108((s32) temp_2_3, func_0024CF48((s32) _m2c_func_0024D2B0_D_0069BE6A, (s32) temp_2_3, 0));
            } while (var_16 < temp_2_2);
        }
        temp_3 = (u8) temp_2->b22;
        var_2 = temp_3 >> 6;
    } else {
        var_2 = temp_3 >> 6;
    }
    if (var_2 & 1) {
        __asm__ volatile("" : "+r"(var_16));
        var_16 = 0;
        temp_2_4 = func_00242818();
        if (temp_2_4 > 0) {
            do {
                temp_2_5 = _m2c_func_0024D2B0_TkMenuGetPlayerFromIndex(var_16);
                var_16 += 1;
                func_0024D108((s32) temp_2_5, func_0024CF48((s32) _m2c_func_0024D2B0_D_0069BE6A, (s32) temp_2_5, 0));
            } while (var_16 < temp_2_4);
        }
    }
}

void func_0024D3F0(int a0, int a1) {
    int v = TkMenuGetMP(a0) + a1;

    if (v >= TkMenuGetMaxMP(a0)) {
        v = TkMenuGetMaxMP(a0);
    }
    TkMenuSetMP(a0, v);
}

extern u16 _m2c_func_0024D450_D_0069BE6A __asm__("D_0069BE6A");
u8 _m2c_func_0024D450_TkMenuGetPlayerFromIndex(int i) __asm__("TkMenuGetPlayerFromIndex");
u8 _m2c_func_0024D450_func_00242798(int i) __asm__("func_00242798");
/* DEBT(FAKE) */
void func_0024D450(s32 arg0) {
    u8 sp[0x10];
    OfsTbl *temp_2;
    s32 temp_2_2;
    s32 temp_2_4;
    s32 temp_5;
    register s32 var_16 __asm__("$16");
    register u32 var_2 __asm__("$2");
    u8 temp_2_3;
    u8 temp_2_5;
    register u32 temp_3 __asm__("$3");

    temp_5 = func_0024CF48((s32) _m2c_func_0024D450_D_0069BE6A, arg0, 1);
    if (D_0069BE6C == 1) {
        func_0024D3F0(arg0, temp_5);
        return;
    }
    temp_2 = TkMsGetRomItem((s32) _m2c_func_0024D450_D_0069BE6A, sp);
    __asm__ volatile("" : : : "$2");
    temp_3 = (u8) temp_2->b22;
    var_2 = temp_3 >> 7;
    if (var_2 != 0) {
        var_16 = 0;
        temp_2_2 = TkMenuGetSummonListMax();
        if (temp_2_2 > 0) {
            do {
                temp_2_3 = _m2c_func_0024D450_func_00242798(var_16);
                var_16 += 1;
                func_0024D3F0((s32) temp_2_3, func_0024CF48((s32) _m2c_func_0024D450_D_0069BE6A, (s32) temp_2_3, 1));
            } while (var_16 < temp_2_2);
        }
        temp_3 = (u8) temp_2->b22;
        var_2 = temp_3 >> 6;
    } else {
        var_2 = temp_3 >> 6;
    }
    if (var_2 & 1) {
        __asm__ volatile("" : "+r"(var_16));
        var_16 = 0;
        temp_2_4 = func_00242818();
        if (temp_2_4 > 0) {
            do {
                temp_2_5 = _m2c_func_0024D450_TkMenuGetPlayerFromIndex(var_16);
                var_16 += 1;
                func_0024D3F0((s32) temp_2_5, func_0024CF48((s32) _m2c_func_0024D450_D_0069BE6A, (s32) temp_2_5, 1));
            } while (var_16 < temp_2_4);
        }
    }
}

int func_0024D598(int a0, int a1, int a2)
{
    int r = 0;

    switch (a0) {
    case 0:
        r = func_0024CF40(TkMenuGetHP(a2), TkMenuGetMaxHP(a2));
        break;
    case 1:
        r = func_0024CF40(TkMenuGetMP(a2), TkMenuGetMaxMP(a2));
        break;
    case 2:
        r = func_0024CF40(TkMenuGetHP(a2), TkMenuGetMaxHP(a2));
        r |= func_0024CF40(TkMenuGetMP(a2), TkMenuGetMaxMP(a2));
        break;
    case 3:
        r = 1;
        break;
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024D6A0);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024D888);

void func_0024DA50(void) {
}

void func_0024DA58(Task *o)
{
    s32 *state = &o->state;
    u16 held;
    u16 trig;
    int n;

    func_00220318();
    held = TOMenuGetControlPadRep();
    trig = TOMenuGetControlPadTrg();
    func_00243508(o);
    switch (o->state) {
    case 0:
        o->b45 = 0;
        *state = 1;
        break;
    case 1:
        if (o->x52 == 0x1000) {
            *state = 4;
        }
        break;
    case 2:
        o->b45 = -1;
        *state = 3;
        break;
    case 4:
        *state = 5;
        break;
    case 5:
        if (o->ext[0] == 0) {
            n = func_00242818();
        } else {
            n = TkMenuGetSummonListMax();
        }
        if (trig & 0x20) {
            if ((D_0069BE6C == 0 && D_0069BE68 != 0) || (D_0069BE6C == 1 && ((D_0069BE68 >> o->x48) & 1))) {
                *state = 6;
                return;
            }
            SndSepPlaySimple(0x80000003);
            return;
        } else if (trig & 0x40) {
            PLAY_SE(0x80000004);
            *state = 8;
        } else if (n >= 2) {
            if (D_0069BE6C == 1) {
                if (held & 0x4000) {
                    PLAY_SE(0x80000001);
                    o->x48 += 1;
                    if (o->x48 >= n) {
                        o->x48 = 0;
                    }
                } else if (held & 0x1000) {
                    PLAY_SE(0x80000001);
                    o->x48 -= 1;
                    if (o->x48 < 0) {
                        o->x48 = n - 1;
                    }
                }
            }
        }
        break;
    case 6:
        o->b45 = 1;
        D_0069BE70[o->ext[0]] = o->x48;
        *state = 7;
        break;
    case 8:
        o->b45 = -1;
        D_0069BE70[o->ext[0]] = o->x48;
        *state = 9;
        break;
    case 10:
        *state = 11;
        break;
    case 11:
        *state = 12;
        break;
    case 3:
    case 7:
    case 9:
    case 12:
        break;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024DCD0);

int func_0024E1B0(void)
{
    return 1;
}

int func_0024E1B8(void)
{
    return 1;
}

u8 _m2c_func_0024E1C0_TkMenuGetPlayerFromIndex(int i) __asm__("TkMenuGetPlayerFromIndex");
u8 _m2c_func_0024E1C0_func_00242798(int i) __asm__("func_00242798");
extern s32 _m2c_func_0024E1C0_func_0024DA58 __asm__("func_0024DA58");
extern s32 _m2c_func_0024E1C0_func_0024DCD0 __asm__("func_0024DCD0");
void func_0024E1C0(s32 a, s32 b, s32 c) {
    Task *temp_2;
    s32 temp_2_2;
    s32 temp_2_4;
    s32 temp_2_5;
    s32 temp_2_7;
    s32 var_16;
    s32 var_16_2;
    s32 var_19;
    u8 temp_2_3;
    u8 temp_2_6;

    var_19 = 0x77;
    temp_2 = func_00243400();
    D_0069BE60 = temp_2;
    if (a == 0) {
        var_16 = 0;
        temp_2_2 = func_00242818();
        if (a < temp_2_2) {
            do {
                temp_2_3 = _m2c_func_0024E1C0_TkMenuGetPlayerFromIndex(var_16);
                var_16 += 1;
                temp_2_4 = func_002454E0(TOGetSaveChrName((s32) temp_2_3));
                var_19 = (var_19 < temp_2_4) ? temp_2_4 : var_19;
            } while (var_16 < temp_2_2);
        }
    } else {
        var_16_2 = 0;
        temp_2_5 = TkMenuGetSummonListMax();
        if (temp_2_5 > 0) {
            do {
                temp_2_6 = _m2c_func_0024E1C0_func_00242798(var_16_2);
                var_16_2 += 1;
                temp_2_7 = func_002454E0(TOGetSaveChrName((s32) temp_2_6));
                var_19 = (var_19 < temp_2_7) ? temp_2_7 : var_19;
            } while (var_16_2 < temp_2_5);
        }
    }
    temp_2->ext[1] = b;
    temp_2->cb = func_0024DA50;
    temp_2->x0C = (s32) &_m2c_func_0024E1C0_func_0024DA58;
    temp_2->ext[2] = c;
    temp_2->ext[0] = a;
    temp_2->x10 = (s32) &_m2c_func_0024E1C0_func_0024DCD0;
    temp_2->x14 = (s32) func_0024E1B0;
    temp_2->x1C = (s32) func_0024E1B8;
    temp_2->b3E = 2;
    temp_2->x54 = 0x155;
    temp_2->x48 = (s16) D_0069BE70[a];
    temp_2->ext[4] = var_19;
    TkMenuMainRegistWindow(temp_2);
}

void func_0024E358(void)
{
    if (D_0069BE60) {
        D_0069BE60->b41 = 1;
        D_0069BE60 = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024E378);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024E540);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_24B828/rodata", jtbl_005734B0);

void func_0024EBF8(Task *obj)
{
    obj->state = 0;
    if (D_0069BE5C != 0) {
        D_0069BE5C->b45 = 0;
        D_0069BE5C->state = 3;
    }
}

void func_0024EC20(Task *obj)
{
    obj->state = 0;
    if (D_0069BE40 != 0) {
        D_0069BE40->b45 = 0;
        D_0069BE40->state = 3;
    }
}

void func_0024EC48(Task *obj)
{
    obj->state = 0;
    if (D_0069BE58 != 0) {
        D_0069BE58->b45 = 0;
        D_0069BE58->state = 3;
    }
}

void func_0024EC70(Task *obj)
{
    func_0024EC48(obj);
}

int func_0024EC78(int a, int idx)
{
    SysEntry *e = SYS_TBL;

    e += idx;
    return e->b3;
}

void func_0024EC90(void)
{
    if (D_0069BE60 != 0) {
        D_0069BE60->b45 = 0;
        D_0069BE60->state = 0;
    }
}

void func_0024ECB8(void)
{
    if (D_0069BE58 != 0) {
        D_0069BE58->b45 = 0;
        D_0069BE58->state = 0;
    }
}

void func_0024ECE0(void) {
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024ECE8);

void func_0024EFC8(Task *t, int x, int y)
{
    int draw;
    int idx = t->b45;

    if (idx >= t->b42) {
        idx = t->b42 - 1;
    }
    if (!(((t->b45 >= t->b42 && t->b42 != 2) || t->b45 < 0) && D_0069BED8 == 0)) {
        if (t->ext[idx] != 0) {
            x += 0xFF;
        }
        y += (t->x48 - t->x32) << 5;
        draw = 1;
        if (D_0069BED8 == 2) {
            if ((func_00242040() / 2) & 1) {
                if (t->b45 > 0) {
                    draw = 0;
                }
            }
        }
        if (draw) {
            func_002270F8(x + 0xC, y + 1, 0);
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024F0E0);

int func_0024F3E0(void)
{
    return 1;
}

int func_0024F3E8(int a, int idx)
{
    SysEntry *e = SYS_TBL;

    e += idx;
    return e->b3;
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024F400);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", TkMenuCtrlItem);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_24B828/rodata", jtbl_00573510);

void func_00250040(void)
{
    D_0069BE54++;
}

void func_00250058(void) {
    func_00241F70(1);
    func_0024B828();
    TOSeqGetRect(1, D_005735F8, &D_0069BEE0[0], &D_0069BEE0[1], &D_0069BEE0[2], &D_0069BEE0[3]);
}

s32 _m2c_func_002500A0_func_0024E540() __asm__("func_0024E540");
s32 _m2c_func_002500A0_func_0024F0E0() __asm__("func_0024F0E0");
/* DEBT(CAST) */
Task *func_002500A0(s32 a) {
    Task *temp_2;

    temp_2 = func_00243400();
    temp_2->x0C = &_m2c_func_002500A0_func_0024E540;
    temp_2->x10 = (s32) &_m2c_func_002500A0_func_0024F0E0;
    temp_2->x14 = (s32) func_0024F3E0;
    temp_2->b3E = 1;
    temp_2->b3F = 0;
    temp_2->x48 = 0;
    temp_2->x32 = 0;
    temp_2->x34 = 0;
    temp_2->b42 = 1;
    temp_2->b43 = (u8) a;
    temp_2->ext[0] = 0;
    temp_2->ext[1] = 0;
    switch (a) {                                    /* irregular */
    case 0:
        (*(u8 *)((u8 *)(D_0069BE70) + (0))) = 0;
        (*(s8 *)((u8 *)(D_0069BE70) + (1))) = 0;
        temp_2->x30 = (s16) ((s32) (func_0024CB28() + 1) / 2);
        temp_2->ext[0xF] = func_0024CB28();
        temp_2->b36 = 3;
        temp_2->x3A = 0xA;
        temp_2->x4A = 0x1D;
        temp_2->x4C = 0x32;
        break;
    case 1:
        temp_2->b42 = 1;
        temp_2->x30 = (s16) ((s32) (func_0024CB48() + 1) / 2);
        temp_2->ext[0xF] = func_0024CB48();
        temp_2->x3A = 0xA;
        temp_2->x4A = 0x1D;
        temp_2->x4C = 0x32;
        temp_2->b36 = 0;
        break;
    case 2:
        temp_2->x1C = (s32) &func_0024EC78;
        temp_2->b36 = 3;
        temp_2->x3A = 9;
        temp_2->x4A = 0x1D;
        temp_2->x4C = 0x50;
        temp_2->b42 = 1;
        (*(u8 *)((u8 *)(D_0069BE70) + (0))) = 0;
        (*(s8 *)((u8 *)(D_0069BE70) + (1))) = 0;
        break;
    }
    TkMenuMainRegistWindow(temp_2);
    func_00227480(D_005733A0);
    func_00227490(D_00573398);
    return temp_2;
}
int func_00250248(int a, int b)
{
    int r = 1;

    if (b == 3 && func_0024CB48() == 0) {
        r = 0;
    }
    return r;
}

void func_00250280(Task *t)
{
    int a[4];
    int b[4];

    t->x1C = 0;
    D_0069BED8 = 0;
    D_0069BE74 = 0;
    TkMenuItemRefresh(0);
    TkCalcImportantListMax();
    TkMenuItemImportantRefresh();
    D_0069BE58 = func_002500A0(0);
    D_0069BE5C = 0;
    D_0069BE40 = 0;
    func_00227490(D_005733A0);
    a[0] = func_00249478(0);
    a[1] = func_00249478(1);
    a[2] = func_00249478(9);
    a[3] = func_00249478(2);
    b[0] = func_00249700(0);
    b[1] = func_00249700(1);
    b[2] = func_00249700(9);
    b[3] = func_00249700(2);
    func_002375F8((int)func_00250248, (int)a, (int)b, 4, 2); /* DEBT(CAST): declared with int parameters */
    func_00237690();
    func_00237790(0);
    func_0024ECE0();
    D_0069BED4 = 1;
    func_0020DC20(1);
    TOSeqStartScene(1, D_00573608);
    TOSeqStartScene(1, D_005733A8);
}

void func_002503B8(void) {
    func_0024C8C0();
    func_0024C8E8();
    func_0024C898();
    TOSeqStopScene(1, D_005733A8);
    TOSeqStopScene(1, D_00573610);
    func_0024E358();
    func_0024C8E8();
    func_0024E358();
    func_0024C898();
    func_00237818();
}

void func_00250428(void)
{
    func_00241F70(0);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", TkMenuCtrlAbility);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_24B828/rodata", jtbl_00573620);

void func_00250970(void)
{
    int n;

    D_0069BE54++;
    n = TkMenuGetCurrentPlayer();
    if ((func_00242900() >> n) & 1) {
        func_00124F08();
        TOMenuOpenPktBuffTmp();
        func_001F0328(D_00326DA0.x, D_00326DA0.y + 0x31, 0x200, D_00326DAE, D_00326D98, D_00326DA4);
        TOMenuDrawKickTmp();
        func_00124F08();
    }
    func_002014E0(n, 0, 0x31);
}

void func_00250A18(void) {
    TkMn2GetWShopPos();
    TkMn2GetIShopPos();
    TOSeqGetRect(1, D_00573670, &D_0069BEE8[0], &D_0069BEE8[1], &D_0069BEE8[2], &D_0069BEE8[3]);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_00250A60);

void func_00250CB8(void) {
    func_0024C8C0();
    func_0024C8E8();
    func_0024E358();
    func_00237818();
    TOSeqStopScene(1, D_00573618);
}

void func_00250CF8(void) {
}
