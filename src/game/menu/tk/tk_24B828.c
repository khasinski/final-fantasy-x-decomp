/* tu_273 0x24b828-0x250d00: low; ~Tk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r5.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/s5.h"
#include "ffx/u4.h"
#include "ffx/v5.h"
#include "ffx/w8.h"
#include "ffx/r6.h"
#include "ffx/s6.h"

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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024C398);

void func_0024C438(Task *o) {
    if (o->b45 >= 0) {
        TkMenuCtrlSelFileWindow(o);
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024C458);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024C670);

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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", TkMenuItemImportantRefresh);

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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024D168);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024D2B0);

void func_0024D3F0(int a0, int a1) {
    int v = TkMenuGetMP(a0) + a1;

    if (v >= TkMenuGetMaxMP(a0)) {
        v = TkMenuGetMaxMP(a0);
    }
    TkMenuSetMP(a0, v);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024D450);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024D598);

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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024E1C0);

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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_0024EFC8);

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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_24B828", func_002500A0);

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
    TOSeqStopScene(1, (int)D_005733A8); /* DEBT(CAST): address passed as int */
    TOSeqStopScene(1, (int)D_00573610);
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
    TOSeqStopScene(1, (int)D_00573618); /* DEBT(CAST): address passed as int */
}

void func_00250CF8(void) {
}
