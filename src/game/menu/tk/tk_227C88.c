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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_227C88", TkSetLegendAbility);

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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_227C88", func_00228240);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_227C88", TkMn2WeaponBuySellWindow);

void TkMn2InitWork(void)
{
    D_00693848 = 0;
    D_00693854 = 0;
    D_003257E0 = 0;
    D_00693858 = 0;
    D_0069385C = 1;
}
