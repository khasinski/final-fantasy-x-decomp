/* tu_269 0x242040-0x2454c0: low; ~Tk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/s5.h"
#include "ffx/u4.h"
#include "ffx/v5.h"
#include "ffx/r5.h"

u8 func_00242040(void) {
    return D_0069A804;
}

void func_00242050(void) {
}

void func_00242058(void) {
}

void func_00242060(int n, int y, int h)
{
    func_002DAB10(D_0069BC00, (s16)(y / 64), 8, 0, 0, 0, 0x200, (s16)(h / 2048));
    func_002F8660(0);
    func_002DA610(0, 0);
    func_002DADD0(D_0069BC00, n);
    func_002DA610(0, 0);
}

void func_00242108(int n, int y, int h)
{
    func_002DA928(D_0069BC70, (s16)(y / 64), 8, 0, 0, 0, 0x200, (s16)(h / 2048));
    func_002F8660(0);
    func_002DA610(0, 0);
    func_002DAC50(D_0069BC70, n);
    func_002DA610(0, 0);
}

void func_002421B0(int n, int y, int size)
{
    func_002DAB10(D_0069BC00, (s16)(y / 64), 8, 1, 0, 0, 0x200, (s16)(size / 0x600));
    func_002F8660(0);
    func_002DA610(0, 0);
    func_002DADD0(D_0069BC00, n);
    func_002DA610(0, 0);
}

void func_00242258(int n, int y, int size)
{
    func_002DA928(D_0069BC70, (s16)(y / 64), 8, 1, 0, 0, 0x200, (s16)(size / 0x600));
    func_002F8660(0);
    func_002DA610(0, 0);
    func_002DAC50(D_0069BC70, n);
    func_002DA610(0, 0);
}

void func_00242300(int n, int y)
{
    func_002DA928(D_0069BC70, (s16)(y / 64), 4, 0x13, 0, 0, 0x100, 0x100);
    func_002F8660(0);
    func_002DA610(0, 0);
    func_002DAC50(D_0069BC70, n);
    func_002DA610(0, 0);
}

int func_00242390(void) {
    return D_0069BBC0;
}

int TkMenuSummonEnableMask(void) {
    return D_0069BBF0;
}

s32 func_002423B0(int idx) { return func_00124828()->vBC; }

u8 TkMenuGetWeapon(int idx) { return MsGetSavePlayerPtr(idx)->f2D; }

u8 *func_002423F0(int idx) { return func_00124828()->blk3D48; }

int func_00242410(u16 *a0, int a1) { return (a0[a1 / 16] >> (a1 % 16)) & 1; }

u8 TkMenuGetArmor(int idx) { return MsGetSavePlayerPtr(idx)->f2E; }

int func_00242468(int id) { return func_001BE7B8(id); }

int func_00242488(int a0) { return MsGetNextAP(a0) - func_001BE5C0(a0); }

int func_002424C8(void) { return MsGetGIL(); }

int TkMsImportantGet(void) { return MsImportantGet(); }

s32 TkMenuGetHP(int idx) { return MsGetSavePlayerPtr(idx)->v1C; }

void TkMenuSetHP(int idx, int v) {
    PartySlot *s = MsGetSavePlayerPtr(idx);

    s->v1C = v;
    if (v != 0) {
        s->b3D = 0;
    }
}

s32 TkMenuGetMaxHP(int idx) { return MsGetSavePlayerPtr(idx)->v24; }

u8 func_00242578(int idx) { return MsGetSavePlayerPtr(idx)->b39; }

u8 func_00242598(int idx) { return MsGetSavePlayerPtr(idx)->b3A; }

s32 TkMenuGetMP(int idx) { return MsGetSavePlayerPtr(idx)->v20; }

void TkMenuSetMP(int idx, int v) { MsGetSavePlayerPtr(idx)->v20 = v; }

s32 TkMenuGetMaxMP(int idx) { return MsGetSavePlayerPtr(idx)->v28; }

void func_00242620(int v) {
    D_0069BB9C = v;
}

int func_00242630(void) {
    return D_0069BB98;
}

void func_00242640(int idx, int v) { MsGetSavePlayerPtr(idx)->f3B = v; }

void func_00242668(void) { func_00258B48(); }

OfsTbl *TkMsGetRomItem(int id, s32 *out)
{
    s32 pos;
    int k = V5_CALL0_func_0013A398() != 0;
    OfsTbl *t = MsGetRomItem(id, &pos);

    pos += t->a[k].x;
    *out = pos;
    return t;
}

u8 TkMenuGetPlayerFromIndex(int i) {
    i = i < 0 ? 0 : (i > func_00242818() - 1 ? func_00242818() - 1 : i);
    return D_0069BBA0[i];
}

int TkMenuGetPlayerFromIndex2(int i) {
    i = i < 0 ? 0 : (i > TkMenuGetPlayerListMax2() - 1 ? TkMenuGetPlayerListMax2() - 1 : i);
    return D_0069BBA0[i];
}

u8 func_00242798(int i) {
    i = i < 0 ? 0 : (i > D_0069BBE4 - 1 ? D_0069BBE4 - 1 : i);
    return D_0069BBC8[i];
}

u8 func_002427D0(int i) {
    i = i < 0 ? 0 : (i > D_0069BBEC - 1 ? D_0069BBEC - 1 : i);
    return D_0069BBD8[i];
}

int func_00242808(void) {
    return D_0069BBEC;
}

int func_00242818(void) {
    if (func_00241FE0()) {
        return D_0069BBAC;
    }
    return D_0069BBA8;
}

int TkMenuGetPlayerListMax2(void) {
    return D_0069BBAC;
}

int TkMenuGetSummonListMax(void) {
    return D_0069BBE4;
}

int func_00242870(void) {
    return D_0069BBB0;
}

void func_00242880(void) {
    int i;
    u8 c;

    D_0069BBB8 = 0;
    for (i = 0; i < func_00242870(); i++) {
        c = D_0069BBA0[i];
        if (c != 0xFF) {
            D_0069BBB8 |= 1 << c;
        }
    }
}

int func_00242900(void) {
    return D_0069BBB8;
}

u8 TkMenuGetCurrentPlayer(void) {
    return D_0069BBA0[D_0069BBB4];
}

void func_00242930(int v) {
    D_0069BBB4 = v;
}

int func_00242940(void) {
    return D_0069BBC8[D_0069BBE8];
}

int TkMenuGetCurrentPlayerPos(void) {
    return D_0069BBB4;
}

int func_00242970(void) {
    return D_0069BBE8;
}

void func_00242980(void)
{
    D_0069BBB4++;
    if (D_0069BBB4 >= func_00242818()) {
        D_0069BBB4 = 0;
    }
    D_0069BBBC = 1;
}

int func_002429D0(void) {
    return D_0069A7F8;
}

void func_002429E0(void) {
    D_0069A7F8 = 1;
}

void func_002429F0(void)
{
    D_0069BBB4--;
    if (D_0069BBB4 < 0) {
        D_0069BBB4 = func_00242818() - 1;
    }
    D_0069BBBC = -1;
}

void func_00242A40(void)
{
    D_0069BBB4++;
    if (D_0069BBB4 >= TkMenuGetPlayerListMax2()) {
        D_0069BBB4 = 0;
    }
    D_0069BBBC = 1;
}

void func_00242A90(void)
{
    D_0069BBB4--;
    if (D_0069BBB4 < 0) {
        D_0069BBB4 = TkMenuGetPlayerListMax2() - 1;
    }
    D_0069BBBC = -1;
}

void func_00242AE0(void) {
    D_0069BBE8++;
    if (D_0069BBE8 >= D_0069BBE4) {
        D_0069BBE8 = 0;
    }
    D_0069BBF4 = 1;
}

void func_00242B18(void) {
    D_0069BBE8--;
    if (D_0069BBE8 < 0) {
        D_0069BBE8 = D_0069BBE4 - 1;
    }
    D_0069BBF4 = -1;
}

s8 func_00242B50(void) {
    return D_0069BBBC;
}

s8 func_00242B60(void) {
    return D_0069BBF4;
}

int TkMenuGetItemHelp(int id) {
    s32 pos;
    int sel = func_0013A398(id);
    OfsTbl *t = MsGetRomItem(id, &pos);

    if (sel != 0) {
        sel = 1;
    }
    pos += t->b[sel].x;
    return pos;
}

int func_00242BD0(int id)
{
    int a = TkMenuGetHP(id);
    int b = TkMenuGetMaxHP(id);

    if (MsGetSavePlyJoin(id) == 0 && MsGetSavePlyJoined(id) == 1) {
        return 1;
    }
    return MsCalcWeakLevel(a, b) > 0 ? 2 : 0;
}

int func_00242C58(int id)
{
    int a = TkMenuGetHP(id);
    int b = TkMenuGetMaxHP(id);

    if (MsGetSavePlyJoin(id) == 0 && func_00241FE0() == 0) {
        return 1;
    }
    if (MsGetSavePlyJoin(id) == 0 && MsGetSavePlyJoined(id) == 1) {
        return 1;
    }
    return MsCalcWeakLevel(a, b) > 0 ? 2 : 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_242040", func_00242D00);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_242040", TkMenuExchangePlayerPos);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_242040", func_00243088);

/* DEBT(CAST) */
void func_00243298(void *arg0) {
    s32 *var_5;
    s32 var_6;

    var_6 = 0xF;
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    (*(s32 *)((u8 *)(arg0) + (4))) = 0;
    (*(s32 *)((u8 *)(arg0) + (8))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0xC))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x10))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x14))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x18))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x1C))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x46))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x38))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x48))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x3A))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x37))) = 1;
    (*(s32 *)((u8 *)(arg0) + (0x24))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x28))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x2C))) = -1;
    (*(s16 *)((u8 *)(arg0) + (0x30))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x32))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x34))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x36))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x3E))) = 1;
    (*(s8 *)((u8 *)(arg0) + (0x42))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x43))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x2E))) = -1;
    (*(s8 *)((u8 *)(arg0) + (0x3F))) = 1;
    (*(s8 *)((u8 *)(arg0) + (0x44))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x40))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x41))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x45))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x4A))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x4C))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x4E))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x50))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x52))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x54))) = 0;
    var_5 = arg0 + 0x94;
    do {
        *var_5 = 0;
        var_6 -= 1;
        var_5 = (s32 *)((u8 *)var_5 - (4));
    } while (var_6 >= 0);
}

Task *func_00243360(Task *t) {
    func_00243298(t);
    return t;
}

void TkMenuMainFreeWindow(Task *o) {
    func_00243298(o);
    o->b40 = 0;
    o->state = 0;
}

void func_002433B8(Task *o) {
    if (o != 0) {
        o->b45 = 0;
        o->state = 0;
    }
}

void TkMenuMainRegistWindow(Task *o) {
    o->b40 = 1;
    o->state = 0;
    if (o->cb != 0) {
        o->cb();
    }
}

Task *func_00243400(void)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (D_0069A880[i].b40 == 0) {
            return func_00243360(&D_0069A880[i]);
        }
    }
    return 0;
}

int func_00243450(void)
{
    int i;
    int n = 0;

    for (i = 0; i < 32; i++) {
        if (!D_0069A880[i].b40) {
            n++;
        }
    }
    return n;
}

void TkMenuMainFreeWindowGroup(int a0)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (D_0069A880[i].b40 == 1 && D_0069A880[i].b36 == a0) {
            TkMenuMainFreeWindow(&D_0069A880[i]);
        }
    }
}

void func_00243508(Task *o) {
    o->x52 += o->x54;
    if (o->x52 < 0) {
        o->x52 = 0;
    }
    if (o->x52 >= 0x1000) {
        o->x52 = 0x1000;
    }
}

void func_00243548(int owner)
{
    Task *t;
    int r;
    int i;

    for (i = 0; i < 16; i++) {
        t = &D_0069A880[i];
        if (t->b3F != owner) {
            continue;
        }
        if (t->x0C != 0) {
            ((void (*)(Task *))t->x0C)(t); /* DEBT(TYPE): Task callback slots are typed s32 */
        }
        if (t->b41 == 0) {
            continue;
        }
        r = 1;
        if (t->x14 != 0) {
            r = ((int (*)(Task *))t->x14)(t);
        }
        if (r == 0) {
            continue;
        }
        if (t->x18 != 0) {
            ((void (*)(Task *))t->x18)(t);
        } else {
            TkMenuMainFreeWindow(t);
        }
    }
}

void func_00243600(int layer)
{
    int i;

    if (D_0032643C != 1 || layer < 6) {
        func_00124F08();
        TOMenuOpenPktBuffTmp();
        TODrawScissorXYWH(0, 0, 0x1FF, 0x19F);
        func_0020D830(1, layer);
        TOMenuDrawKickTmp();
        func_00124F08();
        for (i = 0; i < 16; i++) {
            if (D_0069A880[i].b3E == layer && D_0069A880[i].x10 != 0) {
                ((void (*)(Task *))D_0069A880[i].x10)(&D_0069A880[i]);
            }
        }
    }
}

void func_002436D0(void)
{
    int i;

    for (i = 0; i < 32; i++) {
        i = i < 0 ? 0 : (i < 32 ? i : 31);
        func_00243298(&D_0069A880[i]);
    }
}

int TkMenuMainRemoveMenu(int i) /* DEBT(TYPE): declared int, no value returned */
{
    U4Obj14 *o;
    int j;

    j = i < 0 ? 0 : (i > 24 ? 24 : i);
    o = (U4Obj14 *)D_0069A808[j]; /* DEBT(CAST): D_0069A808 is declared int[] in q6.h */
    D_0069A808[j] = 0;
    if (o != 0 && o->fn14 != 0) {
        o->fn14(o);
    }
    D_0069A86C &= ~(1 << j);
}

void TkMenuSetHelpMessage(int a) {
    if (a != TkMenuHelpMessage) {
        D_0069BB90 = TkMenuHelpMessage;
        TkMenuHelpMessage = a;
        D_0069BB94 = 0;
    }
}

void func_00243800(void)
{
    func_00249A08();
    D_0069BB94 += 0x555;
    D_0069BB98 += D_0069BB9C;
    D_0069BB98 = D_0069BB98 < 0 ? 0 : (D_0069BB98 > 0x1000 ? 0x1000 : D_0069BB98);
    if (D_0069BB94 >= 0x1000) {
        D_0069BB94 = 0x1000;
    }
}

/* DEBT(CAST): integer-width views follow the existing shared interfaces. */
void func_00243880(void)
{
    if (!(TkMenuMainGetMenuActiveMask() & 0x80800))
    {
        func_00124F08();
        TOMenuOpenPktBuffTmp();
        CALL_TODrawMenuPlateXYWC2_Rfix_INT(0x45, 0x46, (s32) D_00324248, (s32) D_0032424A, (s32) D_0032424C, (u32) D_00324250, (u32) D_00324254);
        CALL_TODrawMenuPlateXYWC2_Rfix_INT(6, 7, (s32) D_0032425C, (s32) D_0032425E, (s32) D_00324260, (u32) D_00324264, (u32) D_00324268);
        TOMkpShapeXY(0x3E, D_00324248 + 0x50, (s32) D_0032424A);
        if (TkMenuHelpMessage != 0)
        {
            func_001F37C8(TkMenuHelpMessage, D_0032425C + D_0032426C, D_0032425E + D_0032426E);
        }
        TOMenuDrawKickTmp();
        func_00124F08();
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_242040", func_002439A0);

void func_00243A40(void) {
}

void func_00243A48(Task *o)
{
    s32 *state = &o->x1C;

    func_00220318();
    TOMenuGetControlPadTrg();
    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        if (TkCdReadSync(1) == 0) {
            if ((D_0069A87C & 0xFFFF0000) == 0x800000) {
                *state = 5;
            } else {
                *state = 9;
            }
        }
        break;
    case 2:
        *state = 3;
        break;
    case 3:
        if (TkCdReadSync(1) == 0) {
            *state = 4;
        }
        break;
    case 5:
        func_0020CD30(0x12, 0xC, 0x1D36B00);
        *state = 6;
        break;
    case 6:
        if (func_0020CDB8() == 0) {
            *state = 7;
        }
        break;
    case 7:
        func_0020CD30(func_0020BEE0(), 0xD, 0x1D3EB00);
        *state = 8;
        break;
    case 8:
        if (func_0020CDB8() == 0) {
            TOMenuAtelStart();
            *state = 9;
        }
        break;
    case 9:
        func_0020CD30(0x12, 0x12, 0x1CC0000);
        *state = 11;
        break;
    case 11:
        if (func_0020CDB8() != 0) {
            break;
        }
    case 4:
        *state = 13;
        break;
    case 13:
        func_0020CD30(0x12, 0x10, 0x1C80000);
        *state = 15;
        break;
    case 15:
        if (func_0020CDB8() == 0) {
            *state = 17;
        }
        break;
    case 17:
        func_0020CD30(0x12, 0x11, 0x1CA0000);
        *state = 19;
        break;
    case 19:
        if (func_0020CDB8() == 0) {
            *state = 22;
        }
        break;
    case 22:
        TkCdReadNB(0x2A, 0, 0x1D60000);
        *state = 23;
        break;
    case 23:
        if (TkCdReadSync(1) == 0) {
            D_0069A86C &= 0xFFFFFFFE;
            *state = 24;
        }
        break;
    case 24:
        D_00326439 = 1;
        break;
    }
}

void func_00243CA8(void) {
}

void func_00243CB0(void) {
}

void TkMenuMainSleepMenu(int i)
{
    U4Obj18 *o;
    int j;

    j = i < 0 ? 0 : (i > 24 ? 24 : i);
    o = (U4Obj18 *)D_0069A808[j]; /* DEBT(CAST): D_0069A808 is declared int[] in q6.h */
    if (o != 0) {
        if (o->b18 == 1 && o->fn10 != 0) {
            o->fn10(o);
        }
        o->b18 = 0;
        o->b19 = 0;
        D_0069A86C &= ~(1 << j);
    }
}

void func_00243D58(int i, V5Proc *p)
{
    int j;

    if (i >= 0) {
        if (i > 24) {
            j = 24;
        } else {
            j = i;
        }
    } else {
        j = 0;
    }
    p->w1C = 0;
    D_0069A808[j] = (int)p; /* DEBT(CAST): D_0069A808 is declared int[] in q6.h */
    p->b18 = 0;
    p->b19 = 0;
    if (p != 0 && p->fn8 != 0) {
        p->fn8(p, D_0069A87C);
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_242040", TkMenuMainActiveMenu);

/* DEBT(CAST): the process table exposes object pointers as integer handles and flags as a byte view. */
void func_00243EA8(void)
{
    int (*update)(int);
    int *entry;
    int handle;
    int index;

    index = 0;
    func_00243548(0);
    entry = D_0069A808;
    do {
        handle = *entry;
        if (handle != 0 && !((D_0069A870 >> index) & 1) && (*(u32 *)&((V5Proc *)handle)->b18 & 0xFF00FF)) {
            update = ((V5Proc *)handle)->update;
            if (update != 0) {
                update(handle);
            }
        }
        index++;
        entry++;
    } while (index < 0x19);
    func_00243548(1);
    func_00243548(2);
    func_00243548(3);
    func_00243548(4);
    func_00243548(5);
    func_00243548(6);
    func_00243548(7);
    func_00243548(8);
    TOSeqCtrl(1);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_242040", func_00243F90);

void func_00244150(void) {
    int i;

    for (i = 0; i < 25; i++) {
        TkMenuMainRemoveMenu(i);
    }
}

void _m2c_func_00244188_func_002429E0(s32) __asm__("func_002429E0");
void _m2c_func_00244188_func_002436D0() __asm__("func_002436D0");
void func_00244188(void) {
    s32 i;
    for (i = 0; i < 25; i++) {
        D_0069A808[i] = 0;
    }
    D_0069A86C = 0;
    D_0069A870 = 0;
    D_0069A874 = 0;
    _m2c_func_00244188_func_002436D0();
    _m2c_func_00244188_func_002429E0(1);
}

u32 func_002441E8(void) {
    u32 r = D_0069A86C;

    if (TkCdReadSync(1)) {
        r |= 0x80000000;
    }
    if (r == 0) {
        r = 0x80000000;
        if (AtelIsCallbackQue() != 1) {
            r = 0;
        }
    }
    return r;
}

int TkMenuMainGetMenuActiveMask(void) {
    return D_0069A86C;
}

void TkMn2SetMainFrameRatioDiff(int v) {
    D_0069BCD0 = v;
}

int TkMn2GetMainFrameRatio(void) {
    return D_0069BCD4;
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_242040", func_00244278);

void func_00244608(void) {
    int i;
    int src = 0x1B00000;
    int dst = 0xBC000;

    for (i = 0; i < 13; i++) {
        func_00242060(src, dst, 0x10000);
        src += 0x10000;
        dst += 0x4000;
    }
}

void func_00244678(void) {
    int i;
    int src = 0x1B00000;
    int dst = 0x68000;

    for (i = 0; i < 7; i++) {
        func_00242060(src, dst, 0x10000);
        src += 0x10000;
        dst += 0x4000;
    }
}

void func_002446E8(void)
{
    U4Rec28 *r = Sg_GetDBuffDC(&D_0069A874);
    int src;
    int dst = 0x1BD0000;
    int i;

    D_0069A874 &= 1;
    r += D_0069A874;
    src = r->w10 & 0x1FF;
    src <<= 11;
    for (i = 0; i < 13; i++) {
        func_002421B0(dst, src, 0xC000);
        dst += 0xC000;
        src += 0x4000;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_242040", func_00244780);

void func_002448C8(void) {
    int i;
    int src = 0x1B00000;
    int dst = 0xBC000;

    for (i = 0; i < 13; i++) {
        func_00242108(src, dst, 0x10000);
        src += 0x10000;
        dst += 0x4000;
    }
}

void func_00244938(void) {
    int i;
    int src = 0x1B00000;
    int dst = 0x68000;

    for (i = 0; i < 7; i++) {
        func_00242108(src, dst, 0x10000);
        src += 0x10000;
        dst += 0x4000;
    }
}

void func_002449A8(U4DispEnv *env)
{
    unsigned long dispfb = env->dispfb;
    unsigned long display;

    dispfb += 0x8000UL << 31;
    display = env->display;
    GS_DISPFB2 = dispfb;
    display |= 0x8000000;
    GS_DISPLAY2 = display;
}

void func_002449E0(U4DispEnv *env, int i)
{
    U4DispEnv *e;
    unsigned long disp;

    func_002F8660(0);
    func_002DB640((u8 *)env, i);
    e = &env[i & 1];
    disp = e->display;
    GS_PMODE = e->pmode | 0x8021;
    GS_DISPFB1 = e->dispfb;
    GS_DISPFB2 = e->dispfb;
    GS_DISPLAY2 = disp;
    disp -= 0x1000; /* DEBT(ORDER): in-place update keeps the register allocation */
    GS_DISPLAY1 = disp;
    func_002DA610(0, 0);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_242040", func_00244A90);

void TkMenuRefreshPartyList(void) {
    func_00242D00(0);
    func_00243088(0);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_242040", func_00244F00);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_242040", TkMenuStart);

void func_00245450(void) {
}

u32 func_00245458(void) { return 0x1D4EB00; }

u32 func_00245468(void) { return 0x1E00000; }

void *func_00245470(int *p) {
    void *r = Sg_GetDBuffDC(0);

    if (p) {
        *p = D_0069BBF8;
    }
    return r;
}

int TOMenuGetFirstReadEndFlag(void) {
    return D_00326439;
}
