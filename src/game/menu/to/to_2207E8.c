/* tu_247 0x2207e8-0x220f30: medium; ~TOMenuOpenPktBuffTmp (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r5.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/u3.h"
#include "ffx/v4.h"

void func_002207E8(void) {
}

u32 func_002207F0(void)
{
    return 0x1C80000; /* DEBT(TYPE): constant of unknown meaning (address/size?) */
}

u32 func_002207F8(void)
{
    return 0x100000; /* DEBT(TYPE): constant of unknown meaning (address/size?) */
}

u32 func_00220800(void)
{
    return 0x800000; /* DEBT(TYPE): constant of unknown meaning (address/size?) */
}

u32 func_00220808(void)
{
    return 0x200000; /* DEBT(TYPE): constant of unknown meaning (address/size?) */
}

u32 func_00220810(void)
{
    return 0x1D80000; /* DEBT(TYPE): constant of unknown meaning (address/size?) */
}

u32 func_00220818(void)
{
    return 0x80000; /* DEBT(TYPE): constant of unknown meaning (address/size?) */
}

u32 func_00220820(void)
{
    return 0x1E00000; /* DEBT(TYPE): constant of unknown meaning (address/size?) */
}

u32 func_00220828(void)
{
    return 0x100000; /* DEBT(TYPE): constant of unknown meaning (address/size?) */
}

u32 func_00220830(void)
{
    return 0x1F00000; /* DEBT(TYPE): constant of unknown meaning (address/size?) */
}

u32 func_00220838(void)
{
    return 0x100000; /* DEBT(TYPE): constant of unknown meaning (address/size?) */
}

u32 func_00220840(void)
{
    return 0x1C80000; /* DEBT(TYPE): constant of unknown meaning (address/size?) */
}

u32 func_00220848(void)
{
    return 0x20000; /* DEBT(TYPE): constant of unknown meaning (address/size?) */
}

u32 func_00220850(void)
{
    return 0x2ED0; /* DEBT(TYPE): constant of unknown meaning */
}

u32 func_00220858(void)
{
    return 0x1CA0000; /* DEBT(TYPE): constant of unknown meaning (address/size?) */
}

u32 func_00220860(void)
{
    return 0x20000; /* DEBT(TYPE): constant of unknown meaning (address/size?) */
}

u32 func_00220868(void)
{
    return 0x2ED4; /* DEBT(TYPE): constant of unknown meaning */
}

void TOMenuOpenPktBuffTmp(void)
{
    TOSetPktBuffAdrs(0x1D80000, 0x80000, 0x75300);
    func_001EF940();
}

void TOMenuDrawKickTmp(void)
{
    func_001EF978();
    TODrawKick();
}

int func_002208B8(int id)
{
    return MsMenuGetText(9, id, MsGetSaveConfigHiragana());
}

int func_002208F0(int id)
{
    return MsMenuGetText(1, id, MsGetSaveConfigHiragana());
}

int func_00220928(int id)
{
    return MsMenuGetText(2, id, MsGetSaveConfigHiragana());
}

int func_00220960(int id)
{
    return MsMenuGetText(3, id, MsGetSaveConfigHiragana());
}

int func_00220998(int id)
{
    return MsMenuGetText(6, id, MsGetSaveConfigHiragana());
}

int func_002209D0(int id)
{
    return MsMenuGetText(7, id, MsGetSaveConfigHiragana());
}

int func_00220A08(int id)
{
    return MsMenuGetText(8, id, MsGetSaveConfigHiragana());
}

int TOMenuGetNameMes(int id)
{
    return MsMenuGetText(10, id, MsGetSaveConfigHiragana());
}

int func_00220A78(int id)
{
    return MsMenuGetText(11, id, MsGetSaveConfigHiragana());
}

int TOMenuGetSummonMes(int id)
{
    return MsMenuGetText(12, id, MsGetSaveConfigHiragana());
}

int func_00220AE8(int id)
{
    return MsMenuGetText(5, id, MsGetSaveConfigHiragana());
}

int func_00220B20(int id)
{
    return MsMenuGetHelp(9, id, MsGetSaveConfigHiragana());
}

int func_00220B58(int id)
{
    return MsMenuGetHelp(1, id, MsGetSaveConfigHiragana());
}

int func_00220B90(int id)
{
    return MsMenuGetHelp(2, id, MsGetSaveConfigHiragana());
}

int func_00220BC8(int id)
{
    return MsMenuGetHelp(3, id, MsGetSaveConfigHiragana());
}

int func_00220C00(int id)
{
    return MsMenuGetHelp(6, id, MsGetSaveConfigHiragana());
}

int func_00220C38(int id)
{
    return MsMenuGetHelp(7, id, MsGetSaveConfigHiragana());
}

int func_00220C70(int id)
{
    return MsMenuGetHelp(8, id, MsGetSaveConfigHiragana());
}

int func_00220CA8(int id)
{
    return MsMenuGetHelp(10, id, MsGetSaveConfigHiragana());
}

int func_00220CE0(int id)
{
    return MsMenuGetHelp(11, id, MsGetSaveConfigHiragana());
}

int func_00220D18(int id)
{
    return MsMenuGetHelp(12, id, MsGetSaveConfigHiragana());
}

int func_00220D50(int id)
{
    return MsMenuGetHelp(5, id, MsGetSaveConfigHiragana());
}

int func_00220D88(int id)
{
    s32 pos;
    int sel = func_0013A398(id) != 0;
    OfsTbl *t = MsImportantPtr(id, &pos);

    pos += t->b[sel].x;
    return pos;
}

int func_00220DE8(int id)
{
    s32 pos;
    int sel = func_0013A398(id) != 0;
    OfsTbl *t = MsImportantPtr(id, &pos);

    pos += t->a[sel].x;
    return pos;
}

int func_00220E40(int id)
{
    s32 pos;
    int sel = func_0013A398(id) != 0;
    OfsTbl *t = MsGetRomPlyCommand(id, &pos);

    pos += t->a[sel].x;
    return pos;
}

int func_00220E98(int id)
{
    s32 pos;
    int sel = func_0013A398(id) != 0;
    OfsTbl *t = MsGetRomPlyCommand(id, &pos);

    pos += t->b[sel].x;
    return pos;
}

void TOMenuHelpSetExtMode(s32 a, s32 b)
{
    D_0032579C = a;
    D_003257A0 = b;
}

s32 func_00220F10(void)
{
    return D_0032579C;
}

s32 func_00220F20(void)
{
    return D_003257A0;
}
