/* tu_252 0x227c88-0x228b08: low; ~Tk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w7.h"
#include "ffx/s5.h"
#include "ffx/u3.h"
#include "ffx/v5.h"
#include "ffx/r5.h"
#include "ffx/u4.h"

void func_00227C88(int p, int x, int y)
{
    s32 v[2];

    TOSeqGetPoint(1, D_005713D0, (s16 *)&v[0], (s16 *)&v[1]); /* DEBT(CAST): filled as words here */
    func_00226E10(p + 0x60, x, 0xD5);
    func_00226E10(p + 0x60 + v[0], x, 0xD6);
    func_00226D00(p + D_00326278[0] - D_00326280[0] + 0x60, x + D_00326278[1] - D_00326280[1], y, 0x25);
}

void TkMsSetSaveParam(int idx) {
    int cur;
    int cur2;

    MsSetSaveParam(idx);
    cur = TkMenuGetHP(idx);
    if (TkMenuGetMaxHP(idx) < cur) {
        TkMenuSetHP(idx, TkMenuGetMaxHP(idx));
    }
    cur2 = TkMenuGetMP(idx);
    if (TkMenuGetMaxMP(idx) < cur2) {
        TkMenuSetMP(idx, TkMenuGetMaxMP(idx));
    }
}

void TkMsSetSaveParamAll(void) { func_001BE878(); }

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_227C88", func_00227DE8);

int TkMn2GetSummonGrow(void) {
    s32 buf;

    return MsGetRomSummonGrow(&buf);
}

int func_00227EA8(void)
{
    func_00227DE8();
    return D_003257E0;
}

int func_00227ED0(void) {
    s32 buf;

    return MsGetRomKaizou(&buf);
}

int func_00227EF0(void) {
    int v;

    MsGetRomKaizou(&v);
    return v;
}

extern char D_005713E0[];
extern char D_00571400[];
u16 *_m2c_MsGetSaveWeaponList(int, int, int, s32 *) __asm__("MsGetSaveWeaponList");

Unk1BFED8 *TkSetLegendAbility(int id)
{
    s32 count;
    s32 idx;
    u16 *list;
    Unk1BFED8 *w;

    list = _m2c_MsGetSaveWeaponList(id, -1, 0, &count);
    for (; count > 0; count--, list++) {
        w = MsGetSaveWeapon(*list, &idx);
        if (((w->b3 >> 2) & 1) && w->b4 == id) {
            func_002EF240(D_005713E0, id);
            return w;
        }
    }
    func_002EF240(D_00571400, id);
    return 0;
}

int func_00227FD8(int id, int sel)
{
    u16 *src;
    u16 *dst;
    Unk1BFED8 *rec;
    int ok;
    int i;

    sel--;
    switch (id) {
    case 0:
        src = D_0036E878[sel];
        break;
    case 1:
        src = D_0036E888[sel];
        break;
    case 2:
        src = D_0036E8D8[sel];
        break;
    case 3:
        src = D_0036E898[sel];
        break;
    case 4:
        src = D_0036E8A8[sel];
        break;
    case 5:
        src = D_0036E8B8[sel];
        break;
    case 6:
        src = D_0036E8C8[sel];
        break;
    case 7:
        src = D_0036E8E8[sel];
        break;
    case 8:
        src = D_0036E8F8[sel];
        break;
    case 9:
        src = D_0036E908[sel];
        break;
    case 10:
        src = D_0036E918[sel];
        break;
    case 11:
        src = D_0036E928[sel];
        break;
    case 12:
        src = D_0036E938[sel];
        break;
    case 13:
        src = D_0036E958[sel];
        break;
    case 14:
        src = D_0036E948[sel];
        break;
    case 15:
        src = D_0036E968[sel];
        break;
    case 16:
        src = D_0036E978[sel];
        break;
    case 17:
        src = D_0036E988[sel];
        break;
    default:
        src = 0;
        break;
    }
    ok = 0;
    rec = TkSetLegendAbility(id);
    if (rec != 0) {
        if (src != 0) {
            dst = rec->fE;
            for (i = 0; i < 4; i++) {
                *dst++ = *src++;
            }
            TkMsSetSaveParamAll();
            ok = 1;
        }
    }
    return ok;
}

int func_002281E0(void) { return func_00220820(); }

int func_00228200(void) { return func_00220828(); }

void *func_00228220(int a0, int a1) {
    s32 buf;

    return MsGetExcelData(a0, a1, &buf);
}

extern FlagRec _tk_D_003261E8 __asm__("D_003261E8"); /* DEBT(TYPE): header declares Pt16s */
extern void _tk_func_00226890(int, int, int, int) __asm__("func_00226890"); /* DEBT(TYPE): funcs.h declares int */

void func_00228240(int x, int y, int item, int count, int max_count, int unit_price, int gil)
{
    FlagRec plate;
    s32 pt0;
    s32 pt1;
    int px;
    int py;
    int rem;

    unit_price *= count;

    plate = _tk_D_003261E8;
    plate.rect[0] = x;
    plate.rect[1] = y;
    func_00226FE0((void *)&plate); /* DEBT(CAST): FlagRec* vs s16* */

    plate = D_00326200;
    plate.rect[0] = D_00326200.rect[0] + x - _tk_D_003261E8.rect[0];
    plate.rect[1] = D_00326200.rect[1] + y - _tk_D_003261E8.rect[1];
    func_00226FE0((void *)&plate);

    plate = D_00326218;
    plate.rect[0] = D_00326218.rect[0] + x - _tk_D_003261E8.rect[0];
    plate.rect[1] = D_00326218.rect[1] + y - _tk_D_003261E8.rect[1];
    func_00226FE0((void *)&plate);

    px = x + D_00326218.rect[0] - _tk_D_003261E8.rect[0] + D_003261C0[0];
    py = y + D_00326218.rect[1] - _tk_D_003261E8.rect[1] + D_003261C0[1];
    func_00226D88(px, py, 8);
    func_00226E10(px + D_00325878[0] + 0x58, py + D_00325878[1], 0xD7);
    _tk_func_00226890(item, px, py, 0);

    px = x + D_00326218.rect[0] - _tk_D_003261E8.rect[0] + D_00326230[0];
    py = y + D_00326218.rect[1] - _tk_D_003261E8.rect[1] + D_00326230[1];
    func_00226E10(px + 0x10, py, 0xFF);
    func_00226C78(px + D_00326258[0], py + D_00326258[1], count, 0);
    func_00226C78(px + D_00326260[0], py + D_00326260[1], max_count, 0);

    px = x + D_00326240[0] - _tk_D_003261E8.rect[0];
    py = y + D_00326240[1] - _tk_D_003261E8.rect[1];
    func_00226210(px, py, 0x14);
    TOSeqGetPoint(1, D_005713D0, (s16 *)&pt0, (s16 *)&pt1); /* DEBT(CAST): filled as words here */
    func_00226E10(px + D_00326248[0] + 0x60, py + D_00326248[1], 0xD5);
    func_00226E10(px + D_00326248[0] + 0x60 + pt0, py + D_00326248[1], 0xD6);
    func_00226E10(px + D_00326250[0] + 0x60, py + D_00326250[1], 0xD5);
    func_00226E10(px + D_00326250[0] + 0x60 + pt0, py + D_00326250[1], 0xD6);

    func_00226D00(
        x + D_00326240[0] - _tk_D_003261E8.rect[0] + D_00326248[0] + D_00326268[0],
        y + D_00326240[1] - _tk_D_003261E8.rect[1] + D_00326248[1] + D_00326268[1],
        unit_price < 0 ? -unit_price : unit_price,
        0x25);

    rem = gil - unit_price;
    func_00226D00(
        x + D_00326240[0] - _tk_D_003261E8.rect[0] + D_00326250[0] + D_00326270[0],
        y + D_00326240[1] - _tk_D_003261E8.rect[1] + D_00326250[1] + D_00326270[1],
        rem > 999999999 ? 999999999 : rem,
        0x25);
}

void TkMn2WeaponBuySellWindow(int x, int y, int item, int price, int gil)
{
    FlagRec plate;
    s32 pt0;
    s32 pt1;
    int px;
    int py;
    int rem;

    plate = D_00326118;
    plate.rect[0] = x;
    plate.rect[1] = y;
    func_00226FE0((void *)&plate); /* DEBT(CAST): FlagRec* vs s16* */

    plate = D_00326130;
    plate.rect[0] = D_00326130.rect[0] + x - D_00326118.rect[0];
    plate.rect[1] = D_00326130.rect[1] + y - D_00326118.rect[1];
    func_00226FE0((void *)&plate);

    px = x + D_00326130.rect[0] - D_00326118.rect[0] + D_00326100[0];
    py = y + D_00326130.rect[1] - D_00326118.rect[1] + D_00326100[1];
    func_00226D88(px, py, 8);
    func_00226E10(px + D_00325878[0] + 0x58, py + D_00325878[1], 0xD7);
    func_00226A40(item, px, py, 0);

    px = x + D_003260E8[0] - D_00326118.rect[0];
    py = y + D_003260E8[1] - D_00326118.rect[1];
    func_00226210(px, py, 0x14);
    TOSeqGetPoint(1, D_005713D0, (s16 *)&pt0, (s16 *)&pt1); /* DEBT(CAST): filled as words here */
    func_00226E10(px + D_003260D0[0] + 0x60, py + D_003260D0[1], 0xD5);
    func_00226E10(px + D_003260D0[0] + 0x60 + pt0, py + D_003260D0[1], 0xD6);
    func_00226E10(px + D_003260D8[0] + 0x60, py + D_003260D8[1], 0xD5);
    func_00226E10(px + D_003260D8[0] + 0x60 + pt0, py + D_003260D8[1], 0xD6);

    func_00226D00(
        x + D_003260E8[0] - D_00326118.rect[0] + D_00326248[0] + D_003260F0[0],
        y + D_003260E8[1] - D_00326118.rect[1] + D_00326248[1] + D_003260F0[1],
        price < 0 ? -price : price,
        0x25);

    rem = gil - price;
    func_00226D00(
        x + D_003260E8[0] - D_00326118.rect[0] + D_00326250[0] + D_003260F8[0],
        y + D_003260E8[1] - D_00326118.rect[1] + D_00326250[1] + D_003260F8[1],
        rem > 999999999 ? 999999999 : rem,
        0x25);
}

void TkMn2InitWork(void)
{
    D_00693848 = 0;
    D_00693854 = 0;
    D_003257E0 = 0;
    D_00693858 = 0;
    D_0069385C = 1;
}
