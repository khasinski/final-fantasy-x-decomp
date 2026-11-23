/* tu_273 0x24b828-0x250d00: low; ~Tk (config/tu_map.tsv) */
#define TkMsImportantGet _hdr_TkMsImportantGet
#define TkMenuGetArmor _hdr_TkMenuGetArmor
#define TkMenuGetWeapon _hdr_TkMenuGetWeapon
#define func_002346D8 _hdr_func_002346D8
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
#undef func_002346D8
#undef TkMenuGetWeapon
#undef TkMenuGetArmor
#undef TkMsImportantGet
Task *func_002346D8(int a, int b);
int TkMsImportantGet(int id);
int TkMenuGetArmor(int idx);
int TkMenuGetWeapon(int idx);
void func_00237E28(int x, int y, void *w);
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

void func_0024BD20(void) {
    SysEntry *table = (SysEntry *)0x1d57300;
    int next = 0;
    int count = func_002249A8();
    int i;
    for (i = 0; i < count; i++) {
        if (table[i].b2 == 0) {
            unsigned char tmp;
            next = func_0024BCE0(table, next < i + 1 ? i + 1 : next, count);
            if (next < 0) break;
            func_001C03B0(table[i].h0, table[next].h0);
            tmp = table[i].b2;
            table[i].b2 = table[next].b2;
            table[next].b2 = tmp;
        }
    }
    func_002394F0();
}

void func_0024BDF8(void) {
    s32 buf;
    SysEntry *e = (SysEntry *)0x1d57300;
    int i;
    int j;
    int count = func_002249A8();

    for (i = 0; i < 7; i++) {
        for (j = 1; j >= 0; j--) {
            D_0069BEA8[i][j] = 0;
        }
    }
    for (i = 0; i < count; i++, e++) {
        Unk1BFED8 *w = MsGetSaveWeapon(e->h0, &buf);
        int c = w->b4;
        if (c < 7) {
            int b = w->b5 != 0;
            D_0069BEA8[c][b]++;
        }
    }
}

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

int func_0024BF18(void)
{
    u8 owner[0x400];
    s32 buf;
    SysEntry *table = (SysEntry *)0x1D57300;
    int count = func_002249A8();
    int i;
    int j;
    int pos = 0;

    for (i = 0; i < count; i++) {
        Unk1BFED8 *w = MsGetSaveWeapon(table[i].h0, &buf);
        owner[i] = w->b4;
    }
    for (i = 0; i < 7; i++) {
        int n = D_0069BEA8[i][0] + D_0069BEA8[i][1];
        int next = pos + n - 1;
        for (j = 0; j < n; j++) {
            if (owner[pos + j] != i) {
                u8 tmp;
                next = func_0024BEE8(owner, i, next + 1, count);
                if (next < 0) {
                    return 0;
                }
                func_001C03B0(table[pos + j].h0, table[next].h0);
                tmp = owner[pos + j];
                owner[pos + j] = owner[next];
                owner[next] = tmp;
            }
        }
        pos += n;
    }
    return 1;
}

int func_0024C088(void)
{
    u8 kind[0x400];
    s32 buf;
    SysEntry *table = (SysEntry *)0x1D57300;
    int count = func_002249A8();
    int i;
    int j;
    int pos;

    for (i = 0; i < count; i++) {
        Unk1BFED8 *w = MsGetSaveWeapon(table[i].h0, &buf);
        kind[i] = w->b5 != 0;
    }
    pos = 0;
    for (i = 0; i < 7; i++) {
        int n = D_0069BEA8[i][0];
        int next = pos + n - 1;
        for (j = 0; j < n; j++) {
            if (kind[pos + j] != 0) {
                u8 tmp;
                next = func_0024BEE8(kind, 0, next + 1, count);
                if (next < 0) {
                    return 0;
                }
                func_001C03B0(table[pos + j].h0, table[next].h0);
                tmp = kind[pos + j];
                kind[pos + j] = kind[next];
                kind[next] = tmp;
            }
        }
        pos += n + D_0069BEA8[i][1];
    }
    return 1;
}

void func_0024C1F8(Task *t, int x, int y) {
    x += 0xC;
    y += 1;
    func_002270F8(x + D_003260B8.x, y + D_003260B8.y + ((t->x48 - t->x32) << 5), 0);
}

void func_00226A40(void *r, int x, int y, int d);

void func_0024C238(Task *t, int x, int y, int i, int b)
{
    u8 *e = (u8 *)0x01D57300;
    FlagRec rec;
    s32 buf;

    if (b == 0) {
        y -= t->x46 / 0x80;
    }
    if (i < 0 || i >= (u16)t->x30) {
        return;
    }
    rec = D_003261A0;
    e += i * 4;
    rec.rect[0] = x;
    rec.rect[1] = y;
    func_00226D88(x, y, 0);
    func_00226E10(x + D_00325878[0] + 0x58, y + D_00325878[1], 0xD7);
    if (t->b45 > 0 && i == t->x2C) {
        func_002270F8(x + 2, y - 1, 1);
    }
    if (e[2] != 0) {
        func_00226A40(MsGetSaveWeapon(*(u16 *)e, &buf), x, y, 0);
        graphicUiRemapY2();
    }
}

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

u8 *MsSaveItemNumBuffer(s32 *max);
int TkMenuSummonEnableMask(void);

int TkMenuItemRefresh(int mode)
{
    s32 max;
    s32 buf;
    SysEntry *e = (SysEntry *)0x1D57300;
    u16 *numTbl = (u16 *)0x1D56F00;
    u16 *typeBuf;
    u8 *numBuf;
    int i;

    TkMenuGetCurrentPlayer();
    for (i = 0; i < 512; i++) {
        e->h0 = 0;
        e->b2 = 0;
        e->b3 = 0;
        *numTbl = 0;
        e++;
        numTbl++;
    }
    typeBuf = (u16 *)MsSaveItemTypeBuffer(&max);
    numBuf = MsSaveItemNumBuffer(&max);
    e = (SysEntry *)0x1D57300;
    numTbl = (u16 *)0x1D56F00;
    D_0069BE72 = -1;
    D_0069BE48 = 0;
    for (i = 0; i < max; i++) {
        u16 id = *typeBuf++;
        u8 num = *numBuf++;
        OfsTbl *rom = TkMsGetRomItem(id, &buf);
        int idx = id & 0xFF;

        switch (mode) {
        case 0:
        case 4: {
            int flag;

            if (num == 0) {
                e++;
                break;
            }
            if (rom->flags & 1) {
                if (!((rom->b22 >> 7) & 1) || ((rom->b22 >> 6) & 1) || TkMenuSummonEnableMask() != 0) {
                    flag = 1;
                } else {
                    flag = 0;
                }
            } else {
                flag = 0;
            }
            if (mode == 4) {
                flag = 1;
            }
            if (num == 0) {
                flag = 0;
            }
            if (flag != 0 && D_0069BE72 < 0) {
                D_0069BE72 = i;
            }
            e->h0 = id;
            e->b2 = num;
            e->b3 = flag;
            numTbl[idx] = num;
            e++;
            break;
        }
        case 6:
            if (num != 0 && rom->b5D != 0xFF) {
                e->h0 = id;
                e->b2 = num;
                e->b3 = 0;
                numTbl[idx] = num;
                e++;
            }
            break;
        case 1:
        case 2:
        case 3:
        case 5:
            break;
        }
    }
    D_0069BE48 = ((u32)e - 0x1D57300) >> 2;
}

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

extern u16 D_0069BE6A;
extern u8 D_0069BE6D;

int func_0024D6A0(int id)
{
    s32 buf;
    OfsTbl *t;
    int ret;
    u16 mask = 0;
    int i;
    int n;

    D_0069BE6A = id;
    t = TkMsGetRomItem(id, &buf);
    ret = 0;
    switch (t->pad23) {
    case 1:
        D_0069BE6D = 0;
        break;
    case 2:
        D_0069BE6D = 1;
        break;
    case 3:
        D_0069BE6D = 2;
        break;
    default:
        D_0069BE6D = 0;
        break;
    }
    if ((t->b22 >> 4) & 1) {
        D_0069BE6D = 3;
    }
    switch ((t->h1A >> 2) & 3) {
    case 0:
        D_0069BE6C = 1;
        break;
    case 1:
    case 2:
        D_0069BE6C = 0;
        break;
    case 3:
        D_0069BE6C = 1;
        break;
    default:
        D_0069BE6C = 1;
        break;
    }
    if ((t->b22 >> 7) & 1) {
        n = TkMenuGetSummonListMax();
        for (i = 0; i < n; i++) {
            int ch = func_00242798(i);
            if (func_0024D598(D_0069BE6D, D_0069BE6C, ch)) {
                mask |= 1 << i;
            }
        }
        ret = 1;
    }
    if ((t->b22 >> 6) & 1) {
        n = func_00242818();
        for (i = 0; i < n; i++) {
            int ch = TkMenuGetPlayerFromIndex(i);
            if (func_0024D598(D_0069BE6D, D_0069BE6C, ch)) {
                mask |= 1 << i;
            }
        }
        ret = 0;
    }
    D_0069BE68 = mask;
    return ret;
}

int func_0024D888(int id)
{
    s32 buf;
    OfsTbl *t;
    int ret;
    int mask = 0;
    int i;
    int n;

    D_0069BE6A = id;
    t = MsGetRomPlyCommand(id, &buf);
    ret = 0;
    switch (t->pad23) {
    case 1:
        D_0069BE6D = 0;
        break;
    case 2:
        D_0069BE6D = 1;
        break;
    case 3:
        D_0069BE6D = 2;
        break;
    default:
        D_0069BE6D = 0;
        break;
    }
    switch ((t->h1A >> 2) & 3) {
    case 0:
        D_0069BE6C = 1;
        break;
    case 1:
    case 2:
        D_0069BE6C = 0;
        break;
    case 3:
        D_0069BE6C = 1;
        break;
    default:
        D_0069BE6C = 1;
        break;
    }
    if ((t->b22 >> 7) & 1) {
        n = TkMenuGetSummonListMax();
        for (i = 0; i < n; i++) {
            int ch = func_00242798(i);
            if (func_0024D598(D_0069BE6D, D_0069BE6C, ch)) {
                mask |= 1 << i;
            }
        }
        ret = 1;
    }
    if ((t->b22 >> 6) & 1) {
        n = func_00242818();
        for (i = 0; i < n; i++) {
            int ch = TkMenuGetPlayerFromIndex(i);
            if (func_0024D598(D_0069BE6D, D_0069BE6C, ch)) {
                mask |= 1 << i;
            }
        }
        ret = 0;
    }
    D_0069BE68 = mask;
    return ret;
}

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

void func_0024E378(Task *o)
{
    void *help = 0;
    SysEntry *e;
    int cur;
    int idx;

    cur = o->b45;
    if (cur < 0) {
        cur = 0;
    }
    if (cur >= o->b42) {
        cur = o->b42 - 1;
    }
    idx = o->x48 * 2 + o->ext[cur];
    if (o->ext[15] != 0) {
        switch (o->b43) {
        case 0:
            e = SYS_TBL;
            e += idx;
            if (e->b2 != 0) {
                help = TkMenuGetItemHelp(e->h0);
            }
            break;
        case 1:
            if (idx < TkMenuImportantListMax()) {
                idx = ((u16 *)0x1D56B00)[idx];

                if (idx != 0 && TkMsImportantGet(idx) != 0) {
                    help = TOMenuGetGetImportantHelp(idx);
                } else {
                    help = 0;
                }
            }
            break;
        case 2:
            if (idx < func_0024CD68()) {
                e = SYS_TBL;
                e += idx;
                switch (e->b2) {
                case 1:
                    help = TkMenuGetCommandHelp(e->h0);
                    break;
                case 2:
                    help = MsGetMenuChrInfo(e->h0, 0);
                    break;
                }
            }
            break;
        }
    }
    if (o->b45 >= 0) {
        TkMenuSetHelpMessage(help);
    }
}

void func_002429E0(int a);

void func_0024E540(Task *o)
{
    u16 pad;
    u16 rep;
    u16 trg;
    s32 *state;
    int st;

    pad = func_00220318();
    rep = TOMenuGetControlPadRep();
    trg = TOMenuGetControlPadTrg();
    if (o->b45 < 0) {
        return;
    }
    state = &o->state;
    st = *state;
loop:
    switch (st) {
    case 1:
        o->b45 = 0;
        /* fallthrough */
    case 0:
        func_0024E378(o);
        *state = 2;
        break;
    case 3:
        *state = 4;
        break;
    case 2: {
        if (o->ext[15] != 0 && (trg & 0x20)) {
            if (o->x1C != 0) {
                if (((int (*)(Task *, int, int))o->x1C)(o, o->x48 * 2 + o->ext[0], o->b45) == 0) {
                    ((int (*)(int))SndSepPlaySimple)(0x80000003);
                    break;
                }
            }
            ((int (*)(int))SndSepPlaySimple)(0x80000001);
            *state = 17;
            break;
        }
        if (trg & 0x40) {
            ((int (*)(int))SndSepPlaySimple)(0x80000004);
            *state = 19;
            break;
        }
        if (o->ext[15] == 0) {
            break;
        }
        if (trg & 0x8000) {
            if (o->ext[o->b45] != 0) {
                ((int (*)(int))SndSepPlaySimple)(0x80000001);
                o->ext[o->b45] = !o->ext[o->b45];
                func_0024E378(o);
            }
        } else if (trg & 0x2000) {
            if (o->ext[o->b45] == 0) {
                if (o->x48 * 2 < o->ext[15] - 1) {
                    ((int (*)(int))SndSepPlaySimple)(0x80000001);
                    o->ext[o->b45] = !o->ext[o->b45];
                    func_0024E378(o);
                } else if (o->x48 != 0) {
                    ((int (*)(int))SndSepPlaySimple)(0x80000001);
                    o->x48--;
                    o->ext[o->b45] = !o->ext[o->b45];
                    func_0024E378(o);
                }
            }
        } else if ((rep & 0x1000) && o->x48 > 0) {
            ((int (*)(int))SndSepPlaySimple)(0x80000001);
            o->x48--;
            func_0024E378(o);
            if (o->x48 < o->x32) {
                func_002429E0(0);
                st = 9;
                goto loop;
            }
        } else if ((rep & 0x4000) && o->x48 < (u16)o->x30 - 1) {
            ((int (*)(int))SndSepPlaySimple)(0x80000001);
            o->x48++;
            if (o->x48 * 2 + o->ext[o->b45] >= o->ext[15]) {
                o->ext[o->b45] = 0;
            }
            func_0024E378(o);
            if (o->x48 >= o->x32 + (u16)o->x3A) {
                func_002429E0(0);
                st = 13;
                goto loop;
            }
        } else if ((rep & 1) && pad == 1 && o->x48 > 0) {
            int ny = o->x32 - (u16)o->x3A;

            if (ny < 0) {
                ny = 0;
            }
            if (ny != o->x32) {
                o->x34 = ny;
                func_002429E0(0);
                st = 10;
                goto loop;
            }
        } else if ((rep & 2) && pad == 2 && o->x48 < (u16)o->x30 - 1) {
            int max_top = (u16)o->x30 - (u16)o->x3A;
            int ny = o->x32 + (u16)o->x3A;

            if (ny >= max_top) {
                ny = max_top;
                if (ny < 0) {
                    ny = 0;
                }
            }
            if (ny != o->x32) {
                o->x34 = ny;
                func_002429E0(0);
                st = 14;
                goto loop;
            }
        }
        break;
    }
    case 9:
        trg = 0;
        ((int (*)(int))SndSepPlaySimple)(0x80000001);
        o->x46 = 0x1000;
        *state = 11;
        o->x34 = o->x32 = o->x32 - 1;
        st = 11;
        goto loop;
    case 10:
        trg = 0;
        ((int (*)(int))SndSepPlaySimple)(0x80000001);
        o->x46 = 0x1000;
        *state = 12;
        st = 12;
        goto loop;
    case 11:
        o->x46 -= 0x333;
        if (o->x46 <= 0 || (trg & 0x1000)) {
            trg = 0;
            o->x46 = 0;
            o->x48 -= o->x32 - o->x34;
            o->x32 = o->x34;
            func_0024E378(o);
            ((int (*)(int))func_002429E0)(1);
            *state = 2;
            st = 2;
            goto loop;
        }
        break;
    case 12:
        o->x46 -= 0x111;
        if (o->x46 <= 0) {
            trg = 0;
            o->x46 = 0;
            o->x48 -= o->x32 - o->x34;
            o->x32 = o->x34;
            func_0024E378(o);
            ((int (*)(int))func_002429E0)(1);
            *state = 2;
            st = 2;
            goto loop;
        }
        break;
    case 13:
        trg = 0;
        ((int (*)(int))SndSepPlaySimple)(0x80000001);
        o->x46 = -0x1000;
        *state = 15;
        o->x34 = o->x32 = o->x32 + 1;
        st = 15;
        goto loop;
    case 14:
        trg = 0;
        ((int (*)(int))SndSepPlaySimple)(0x80000001);
        o->x46 = -0x1000;
        *state = 16;
        st = 16;
        goto loop;
    case 15:
        o->x46 += 0x333;
        if (o->x46 >= 0 || (trg & 0x4000)) {
            o->x46 = 0;
            o->x48 += o->x34 - o->x32;
            o->x32 = o->x34;
            if (o->x48 * 2 + o->ext[o->b45] >= o->ext[15]) {
                o->ext[o->b45] = 0;
            }
            trg = 0;
            func_0024E378(o);
            ((int (*)(int))func_002429E0)(1);
            *state = 2;
            st = 2;
            goto loop;
        }
        break;
    case 16:
        o->x46 += 0x111;
        if (o->x46 >= 0) {
            o->x46 = 0;
            o->x48 += o->x34 - o->x32;
            o->x32 = o->x34;
            if (o->x48 * 2 + o->ext[o->b45] >= o->ext[15]) {
                o->ext[o->b45] = 0;
            }
            trg = 0;
            func_0024E378(o);
            ((int (*)(int))func_002429E0)(1);
            *state = 2;
            st = 2;
            goto loop;
        }
        break;
    case 17: {
        int n;

        ((struct { u8 pad[0x2C]; s16 arr[2]; } *)o)->arr[o->b45] = o->x48;
        if (++o->b45 >= o->b42) {
            *state = 18;
            st = 18;
            goto loop;
        }
        o->ext[o->b45] = o->ext[o->b45 - 1];
        n = o->b42 - 1;
        o->ext[o->b45 + n] = o->x32;
        *state = 2;
        break;
    }
    case 19:
        o->b45--;
        if (o->b45 < 0) {
            *state = 20;
            st = 20;
            goto loop;
        }
        o->x48 = ((struct { u8 pad[0x2C]; s16 arr[2]; } *)o)->arr[o->b45];
        o->x34 = o->x32 = o->ext[o->b45 + o->b42];
        *state = 2;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 18:
    case 20:
        break;
    }
}

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

void func_00226770(int a, int b, int c, int d);

void func_0024ECE8(Task *t, int x, int y, int idx, int mode)
{
    s32 pos;
    SysEntry *e;
    OfsTbl *cmd;
    int dim;

    switch (mode) {
    case 0:
        y -= t->x46 / 0x80;
        idx += t->x32 * 2;
        break;
    case 1:
        idx += t->x34 * 2;
        break;
    case 2:
        idx += t->x32 * 2;
        break;
    }
    switch (t->b43) {
    case 0:
        if (idx < 0 || idx >= func_0024CB28()) {
            return;
        }
        e = SYS_TBL;
        e += idx;
        dim = e->b3 == 0;
        func_00226D88(x, y, 0xA);
        if (e->b2 != 0) {
            func_00226890(e->h0, x, y, dim);
            func_00226C78(x + 0xD3, y + 6, e->b2, dim);
        }
        break;
    case 1:
        if (idx < 0 || idx >= TkMenuImportantListMax()) {
            return;
        }
        idx = ((u16 *)0x1D56B00)[idx];
        if (idx != 0 && TkMsImportantGet(idx) != 0) {
            func_00226D88(x, y, 1);
            func_00226920(idx, x, y, 0);
        }
        break;
    case 2:
        e = SYS_TBL;
        e += idx;
        if (idx < 0 || idx >= func_0024CD68()) {
            return;
        }
        dim = e->b3 == 0;
        switch (e->b2) {
        case 1:
            cmd = MsGetRomPlyCommand(e->h0, &pos);
            func_00226D88(x, y, 0x12);
            func_00226770(e->h0, x, y, dim);
            if (cmd->b25 != 0) {
                func_00226C78(x + 0xD3, y + 6, cmd->b25, dim);
            }
            break;
        case 2:
            func_00226D88(x, y, 2);
            break;
        }
        break;
    }
    if (t->b42 == 2 && t->b45 > 0 && t->x2C * 2 + t->ext[0] == idx) {
        if ((func_00242040() / 2) & 1) {
            func_002270F8(x + 2, y + 1, 0);
        }
    }
}

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

extern u16 D_0036F0F0[];
u8 *MsSaveItemNumBuffer(int *n);

void func_0024F400(void)
{
    u16 counts[256];
    int size;
    u16 *types;
    u8 *numbers;
    int i = 0;
    SysEntry *item = SYS_TBL;
    u16 *order;
    int type;
    types = (u16 *)MsSaveItemTypeBuffer(&size);
    numbers = MsSaveItemNumBuffer(&size);
    for (; i < 256; i++) {
        types[i] = 0xFF;
        numbers[i] = 0;
        counts[i] = 0;
    }
    for (i = 0; i < func_0024CB28(); i++, item++) {
        int quantity;
        int index = item->h0;
        quantity = item->b2;
        index &= 0xFFF;
        if (quantity != 0) counts[index] = item->b2;
    }
    order = D_0036F0F0;
    while ((type = *order++) != 0xFFFF) {
        if (counts[type & 0xFFF] != 0) {
            *types++ = type;
            *numbers++ = counts[type & 0xFFF];
        }
    }
    TkMenuItemRefresh(4);
}

extern Task *D_0069BE64;
int TkMenuMainGetMenuActiveMask(void);
void func_002376B0(int a, int *b, int *c, int d, int e);
int func_00237858(int a);
int func_00237870(int a);
void func_002377F0(void);
void func_002377C8(void);
void func_00237838(void);

void TkMenuCtrlItem(Task *o)
{
    s32 *state = &o->x1C;
    int st;

    func_00220318();
    TOMenuGetControlPadRep();
    TOMenuGetControlPadTrg();
    st = *state;
loop:
    switch (st) {
    case 0:
        *state = 1;
        break;
    case 1:
        *state = 2;
        break;
    case 2:
        D_0069BED8 = 0;
        func_0024ECB8();
        D_0069BE58->b42 = 1;
        D_0069BE58->x1C = (s32)func_0024F3E8;
        TkMenuItemRefresh(0);
        func_0024ECE0();
        *state = 3;
        break;
    case 3:
        *state = 4;
        break;
    case 5:
        D_0069BED8 = 0;
        func_0024ECB8();
        /* fallthrough */
    case 4:
        *state = 6;
        break;
    case 6:
        D_0069BED8 = 0;
        if (D_0069BE58->b45 < 0) {
            *state = 19;
        }
        if (D_0069BE58->b45 > 0) {
            *state = 11;
            st = 11;
            goto loop;
        }
        break;
    case 7:
        ((void (*)(int))TkMenuItemRefresh)(0);
        ((void (*)(int, int))TkMenuMainActiveMenu)(23, 0);
        *state = 8;
        /* fallthrough */
    case 8:
        if ((TkMenuMainGetMenuActiveMask() & 0x800000) == 0) {
            *state = 9;
        }
        break;
    case 9:
        *state = 10;
        /* fallthrough */
    case 10:
        *state = 5;
        break;
    case 11: {
        s32 buf;
        SysEntry *e = (SysEntry *)0x1D57300;

        e += D_0069BE58->x48 * 2 + D_0069BE58->ext[0];
        if (((u8 *)MsGetRomItem(e->h0, &buf))[0x22] & 8) {
            D_0069BED8 = 1;
            st = 7;
            goto loop;
        } else {
            int side = 2;
            int kind = func_0024D6A0(e->h0);

            if (D_0069BE58->ext[0] != 0) {
                side = 1;
            }
            D_0069BED8 = 2;
            TkMenuMainFreeWindowGroup(0);
            func_0024E1C0(kind, D_0069BE6D, side);
            *state = 13;
        }
        break;
    }
    case 12: {
        s32 buf;
        SysEntry *e = (SysEntry *)0x1D57300;

        e += D_0069BE58->x48 * 2 + D_0069BE58->ext[0];
        if (((u8 *)MsGetRomItem(e->h0, &buf))[0x22] & 8) {
            D_0069BED8 = 1;
            st = 7;
            goto loop;
        }
        func_0024D6A0(e->h0);
        *state = 13;
        break;
    }
    case 13:
        if (D_0069BE60->b45 < 0) {
            D_0069BED8 = 0;
            func_0024E358();
            *state = 5;
            break;
        }
        if (D_0069BE60->b45 > 0) {
            *state = 14;
        }
        break;
    case 14: {
        int target;

        if (D_0069BE60->ext[0] == 0) {
            target = TkMenuGetPlayerFromIndex(D_0069BE60->x48);
        } else {
            target = func_00242798(D_0069BE60->x48);
        }
        switch (D_0069BE6D) {
        case 0:
            SndSepPlaySimple(0x80000062);
            func_0024D168(target);
            break;
        case 1:
            SndSepPlaySimple(0x80000062);
            func_0024D450(target);
            break;
        case 2:
            SndSepPlaySimple(0x80000062);
            func_0024D168(target);
            func_0024D450(target);
            break;
        case 3:
            ((int (*)(int))SndSepPlaySimple)(0x80000001);
            *state = 17;
            st = 17;
            goto loop;
        }
        st = 15;
        goto loop;
    }
    case 15: {
        SysEntry *e;

        MsSaveItemUse(D_0069BE6A, -1);
        ((void (*)(int))TkMenuItemRefresh)(0);
        e = (SysEntry *)0x1D57300;
        e += D_0069BE58->x48 * 2 + D_0069BE58->ext[0];
        if (e->b2 != 0) {
            func_0024EC90();
            *state = 12;
            break;
        }
        func_0024E358();
        *state = 5;
        break;
    }
    case 16:
        *state = 5;
        break;
    case 19:
        *state = 20;
        break;
    case 20:
        ((void (*)(int))TkMenuItemRefresh)(4);
        *state = 52;
        st = 52;
        goto loop;
    case 17: {
        Task **p = &D_0069BE64;

        *p = func_002346D8(0, func_00242798(D_0069BE60->x48));
        *state = 18;
        break;
    }
    case 18:
        if ((u16)D_0069BE64->x30 != 0) {
            D_0069BE64->b41 = 1;
            *state = 15;
        }
        break;
    case 21: {
        int a[4];
        int b[4];

        a[1] = func_00249478(3);
        a[0] = func_00249478(4);
        b[1] = func_00249700(3);
        b[0] = func_00249700(4);
        func_002376B0(0, a, b, 2, 2);
        func_00237858(-0x199);
        func_00237870(0x199);
        *state = 22;
        break;
    }
    case 22:
        *state = 23;
        break;
    case 24:
        func_002377F0();
        /* fallthrough */
    case 23:
        ((void (*)(int))TkMenuItemRefresh)(4);
        *state = 25;
        break;
    case 25:
        if (D_00326034->b45 < 0) {
            *state = 50;
            break;
        }
        if (D_00326034->b45 > 0) {
            switch (D_00326034->x48) {
            case 1:
                st = 28;
                goto loop;
            case 0:
                st = 26;
                goto loop;
            }
        }
        break;
    case 26:
        func_0024ECB8();
        D_0069BE58->b42 = 2;
        D_0069BE58->x1C = 0;
        ((void (*)(int))TkMenuItemRefresh)(4);
        *state = 27;
        /* fallthrough */
    case 27:
        if (D_0069BE58->b45 < 0) {
            *state = 24;
            break;
        }
        if (D_0069BE58->b45 >= D_0069BE58->b42) {
            int size;
            u16 *types = (u16 *)MsSaveItemTypeBuffer(&size);
            u8 *nums = MsSaveItemNumBuffer(&size);
            int i0 = D_0069BE58->x2C * 2 + D_0069BE58->ext[0];
            int i1 = D_0069BE58->x2E * 2 + D_0069BE58->ext[1];
            u16 t0 = types[i0];
            u16 t1 = types[i1];
            u8 n0 = nums[i0];
            u8 n1 = nums[i1];

            types[i0] = t1;
            nums[i0] = n1;
            types[i1] = t0;
            nums[i1] = n0;
            TkMenuItemRefresh(4);
            D_0069BE58->ext[0] = D_0069BE58->ext[1];
            st = 26;
            goto loop;
        }
        break;
    case 28:
        func_0024F400();
        *state = 29;
        /* fallthrough */
    case 29:
        *state = 24;
        st = 24;
        goto loop;
    case 52:
        func_002377C8();
        func_00237858(0x199);
        *state = 53;
        break;
    case 53:
        switch (D_00326030->x48) {
        case 0:
        case 1:
            if (D_0069BE58 == 0) {
                TkMenuItemRefresh(4);
                D_0069BE58 = func_002500A0(0);
                D_0069BE58->b45 = -1;
            }
            func_0024C8E8();
            func_0024C898();
            break;
        case 2:
            if (D_0069BE40 == 0) {
                func_0024C7D8();
            }
            func_0024C8C0();
            func_0024C8E8();
            break;
        case 3:
            if (D_0069BE5C == 0) {
                D_0069BE5C = func_002500A0(1);
                D_0069BE5C->b45 = -1;
            }
            func_0024C898();
            func_0024C8C0();
            break;
        }
        if (D_00326030->b45 < 0) {
            *state = 54;
        }
        if (D_00326030->b45 > 0) {
            switch (D_00326030->x48) {
            case 0:
                *state = 2;
                break;
            case 1:
                *state = 21;
                break;
            case 2:
                *state = 30;
                break;
            case 3:
                *state = 44;
                break;
            }
        }
        break;
    case 30: {
        int a[4];
        int b[4];

        a[1] = func_00249478(12);
        a[0] = func_00249478(13);
        b[1] = func_00249700(12);
        b[0] = func_00249700(13);
        func_002376B0(0, a, b, 2, 2);
        func_00237858(-0x199);
        func_00237870(0x199);
        *state = 31;
        break;
    }
    case 31:
        *state = 32;
        break;
    case 33:
        func_002377F0();
        /* fallthrough */
    case 32:
        V5_INT0(func_002394F0)();
        *state = 34;
        break;
    case 34:
        if (D_00326034->b45 < 0) {
            *state = 35;
            break;
        }
        if (D_00326034->b45 > 0) {
            switch (D_00326034->x48) {
            case 0:
                st = 38;
                goto loop;
            case 1:
                st = 37;
                goto loop;
            }
        }
        break;
    case 35:
        func_00237870(-0x199);
        func_00237858(0x199);
        func_00237838();
        V5_INT0(func_002394F0)();
        *state = 36;
        /* fallthrough */
    case 36:
        *state = 52;
        break;
    case 37:
        func_0024BD20();
        func_0024BDF8();
        if (func_0024BF18() != 0) {
            func_0024C088();
            func_0024BC48();
        }
        st = 33;
        goto loop;
    case 38:
        D_0069BE74 = 1;
        D_0069BE40->b45 = 0;
        D_0069BE40->state = 0;
        D_0069BE40->b37 = 0;
        *state = 39;
        /* fallthrough */
    case 39:
        if (D_0069BE40->b45 < 0) {
            *state = 40;
        }
        if (D_0069BE40->b45 >= 2) {
            st = 42;
            goto loop;
        }
        break;
    case 40:
        D_0069BE40->b45 = -1;
        D_0069BE40->state = 0;
        *state = 41;
        /* fallthrough */
    case 41:
        *state = 33;
        D_0069BE74 = 0;
        break;
    case 42: {
        SysEntry *tbl = (SysEntry *)0x1D57300;
        u16 b = tbl[D_0069BE40->x48].h0;
        u16 a = tbl[D_0069BE40->x2C].h0;

        if (b == a) {
            SndSepPlaySimple(0x80000003);
        } else {
            SndSepPlaySimple(0x80000001);
            func_001C03B0(b, a);
        }
        V5_INT0(func_002394F0)();
        *state = 43;
        /* fallthrough */
    }
    case 43:
        st = 38;
        goto loop;
    case 44:
        D_0069BE5C->b45 = 0;
        *state = 45;
        break;
    case 45:
        *state = 46;
        break;
    case 46:
        *state = 47;
        break;
    case 47:
        if (D_0069BE5C->b45 != 0) {
            *state = 48;
        }
        break;
    case 48:
        D_0069BE5C->state = 0;
        D_0069BE5C->b45 = -1;
        *state = 49;
        break;
    case 50:
        func_00237870(-0x199);
        func_00237858(0x199);
        func_00237838();
        ((void (*)(int))TkMenuItemRefresh)(4);
        *state = 51;
        /* fallthrough */
    case 49:
    case 51:
        *state = 52;
        break;
    case 54:
        *state = 55;
        /* fallthrough */
    case 55:
        *state = 56;
        /* fallthrough */
    case 56:
        TkMenuMainSleepMenu(3);
        TkMenuMainActiveMenu(1, 0);
        break;
    }
}

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

extern s16 D_0069BE78[];
extern s16 D_0069BE88[];
extern s16 D_0069BE98[];

void TkMenuCtrlAbility(Task *o)
{
    s32 buf;
    s32 *state = &o->x1C;
    u16 pad;
    u16 rep;
    int st;

    pad = func_00220318();
    rep = TOMenuGetControlPadRep();
    TOMenuGetControlPadTrg();
    func_0024B620(0, &D_003258C8, &D_003258CC, &D_003258D0, &D_003258D4);
    st = *state;
loop:
    switch (st) {
    case 0:
        *state = 1;
        break;
    case 1:
        *state = 2;
        break;
    case 3:
        func_0024ECB8();
        /* fallthrough */
    case 2:
        *state = 4;
        break;
    case 4:
        if (D_0069BE58->b45 > 0) {
            *state = 7;
            break;
        }
        if (D_0069BE58->b45 < 0) {
            func_0024C8C0();
            *state = 5;
            break;
        }
        if (func_00242818() < 2) {
            break;
        }
        if (func_002429D0() == 0) {
            break;
        }
        if ((rep & 4) && pad == 4) {
            int p;

            SndSepPlaySimple(0x80000004);
            p = TkMenuGetCurrentPlayer();
            D_0069BE78[p] = D_0069BE58->x48;
            D_0069BE88[p] = D_0069BE58->ext[0];
            D_0069BE98[p] = D_0069BE58->x32;
            func_002429F0();
            func_0024CD78(TkMenuGetCurrentPlayer());
            D_0069BE58->x30 = (func_0024CD68() + 1) / 2;
            D_0069BE58->ext[15] = func_0024CD68();
            p = TkMenuGetCurrentPlayer();
            if (D_0069BE78[p] >= 0) {
                D_0069BE58->x48 = D_0069BE78[p];
                D_0069BE58->ext[0] = D_0069BE88[p];
                D_0069BE58->x34 = D_0069BE58->x32 = D_0069BE98[p];
            } else {
                func_0024ECE0();
            }
            func_0024E378(D_0069BE58);
        } else if ((rep & 8) && pad == 8) {
            int p;

            SndSepPlaySimple(0x80000004);
            p = TkMenuGetCurrentPlayer();
            D_0069BE78[p] = D_0069BE58->x48;
            D_0069BE88[p] = D_0069BE58->ext[0];
            D_0069BE98[p] = D_0069BE58->x32;
            func_00242980();
            func_0024CD78(TkMenuGetCurrentPlayer());
            D_0069BE58->x30 = (func_0024CD68() + 1) / 2;
            D_0069BE58->ext[15] = func_0024CD68();
            p = TkMenuGetCurrentPlayer();
            if (D_0069BE78[p] >= 0) {
                D_0069BE58->x48 = D_0069BE78[p];
                D_0069BE58->ext[0] = D_0069BE88[p];
                D_0069BE58->x34 = D_0069BE58->x32 = D_0069BE98[p];
            } else {
                func_0024ECE0();
            }
            func_0024E378(D_0069BE58);
        }
        break;
    case 5:
        *state = 6;
        /* fallthrough */
    case 6:
        *state = 16;
        st = 16;
        goto loop;
    case 7: {
        SysEntry *tbl = (SysEntry *)0x1D57300;
        int side = 2;
        int idx = D_0069BE58->x48 * 2 + D_0069BE58->ext[0];
        int kind;

        tbl += idx;
        kind = func_0024D888(tbl->h0);

        if (D_0069BE58->ext[0] != 0) {
            side = 1;
        }
        TkMenuMainFreeWindowGroup(0);
        func_0024E1C0(kind, D_0069BE6D, side);
        *state = 8;
        break;
    }
    case 10:
        func_0024EC90();
        /* fallthrough */
    case 8:
    case 9:
        *state = 11;
        break;
    case 11:
        if (D_0069BE60->b45 > 0) {
            *state = 12;
        }
        if (D_0069BE60->b45 < 0) {
            *state = 14;
        }
        break;
    case 12:
        *state = 13;
        /* fallthrough */
    case 13: {
        int p = TkMenuGetCurrentPlayer();
        int mp = TkMenuGetMP(p);
        int cost = MsGetRomPlyCommand(D_0069BE6A, &buf)->b25;
        int target;

        mp -= cost;
        TkMenuSetMP(p, mp);
        if (D_0069BE60->ext[0] == 0) {
            target = TkMenuGetPlayerFromIndex(D_0069BE60->x48);
        } else {
            target = func_00242798(D_0069BE60->x48);
        }
        switch (D_0069BE6D) {
        case 0:
            SndSepPlaySimple(0x80000062);
            func_0024D2B0(target, p);
            break;
        case 1:
            break;
        case 2:
            SndSepPlaySimple(0x80000062);
            func_0024D2B0(target, p);
            break;
        }
        func_0024CD78(p);
        if (mp < cost) {
            st = 14;
            goto loop;
        }
        func_0024D888(D_0069BE6A);
        st = 10;
        goto loop;
    }
    case 14:
        func_0024E358();
        *state = 15;
        break;
    case 15:
        *state = 3;
        break;
    case 16:
        *state = 17;
        /* fallthrough */
    case 17:
        *state = 18;
        /* fallthrough */
    case 18:
        TkMenuMainSleepMenu(2);
        TkMenuMainActiveMenu(1, 0);
        TOSeqStopScene(1, D_00573618);
        break;
    }
}

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

extern s16 D_0069BE78[];
extern s16 D_0069BE88[];
extern s16 D_0069BE98[];

void func_00250A60(Task *t)
{
    s16 arr0[8];
    s16 arr1[8];
    int i;

    D_0069BED8 = 2;
    t->x1C = 0;
    D_0069BE58 = func_002500A0(2);
    func_0024ECB8();
    func_0024ECE0();
    for (i = 0; i < 8; i++) {
        int n;

        func_0024CD78(i);
        n = (D_0069BE50 + 1) / 2;
        if (D_0069BE72 < 0) {
            D_0069BE72 = 0;
        }
        D_0069BE78[i] = D_0069BE72 / 2;
        D_0069BE88[i] = D_0069BE72 & 1;
        D_0069BE98[i] = D_0069BE78[i] - ((u16)D_0069BE58->x3A >> 1) + 1;
        arr0[i] = n;
        arr1[i] = D_0069BE50;
        if (D_0069BE98[i] >= n - (u16)D_0069BE58->x3A) {
            D_0069BE98[i] = n - (u16)D_0069BE58->x3A;
        }
        if (D_0069BE98[i] < 0) {
            D_0069BE98[i] = 0;
        }
    }
    D_0069BE58->x48 = D_0069BE78[TkMenuGetCurrentPlayer()];
    D_0069BE58->ext[0] = D_0069BE88[TkMenuGetCurrentPlayer()];
    D_0069BE58->x34 = D_0069BE58->x32 = D_0069BE98[TkMenuGetCurrentPlayer()];
    D_0069BE58->x30 = arr0[TkMenuGetCurrentPlayer()];
    D_0069BE58->ext[15] = arr1[TkMenuGetCurrentPlayer()];
    func_0024CD78(TkMenuGetCurrentPlayer());
    D_0069BED4 = 0;
    func_0020DC20(1);
    TOSeqStartScene(1, D_00573608);
    TOSeqStartScene(1, D_00573618);
}

void func_00250CB8(void) {
    func_0024C8C0();
    func_0024C8E8();
    func_0024E358();
    func_00237818();
    TOSeqStopScene(1, D_00573618);
}

void func_00250CF8(void) {
}
