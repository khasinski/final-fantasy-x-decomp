/* tu_244 0x21d048-0x21f9a8: low; ~TOBtlMakeStatusBuff (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/v4.h"
#include "ffx/r5.h"
#include "ffx/u3.h"

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", TOBtlMakeStatusBuff);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", func_0021D1B0);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", TOBtlInitEnemyLimit);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", TOBtlCtrlEnemyLimit);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", TOBtlDrawEnemyLimit);

void TOBtlInitChrNum(void)
{
    u16 *ids;
    int i;

    ids = TOGetSaveWindow(0, 9, &D_00692008);
    for (i = 0; i < D_00692008; i++) {
        D_00692010[i] = ids[i];
    }
    ids = TOGetSaveWindow(0, 0xB, &D_00692020);
    for (i = 0; i < D_00692020; i++) {
        D_00692028[i] = ids[i];
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", func_0021D6C8);

void func_0021D7A0(int a, int b)
{
    R4Rec *r;

    func_002EF0D0(&toTarget, 0, 0x134);
    toTarget.h0 = a;
    toTarget.h2 = b;
    r = &D_003249C0[D_00325020];
    r->h42 = 0;
    r->wC8 = 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", func_0021D820);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", TOBtlMakeTargetGroupBit);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", TOBtlMakeTargetChrStatusBit);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", func_0021DBF0);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", TOBtlMakeTargetTargetBit);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", _TOBtlGetTargetPad);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", TOBtlSearchRevNearTarget);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", func_0021ECC0);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", TOBtlSetDefaultCursorPos);

void graphicGetTime(void)
{
    D_003249B8 = 0;
    func_002EF0D0(D_00692928, 0, 0x20);
}

void QuickConfigMenuDraw(void)
{
    int i;

    for (i = 0; i < D_003249B8; i++) {
        func_001FE7F8(D_00692928[i].h0, D_00692928[i].h4, D_00692928[i].h6);
    }
    D_003249B8 = 0;
}

void func_0021F448(int a, s16 b, s16 c)
{
    if (D_003249B8 < 4) {
        D_00692928[D_003249B8].h0 = a;
        D_00692928[D_003249B8].h4 = b;
        D_00692928[D_003249B8].h6 = c;
        D_003249B8++;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", TOBtlDrawDamageValue2);

void TOBtlDrawChangeSeqAnm0(int p, int x, int y)
{
    TOMakePktSampleBlueWindowXY2(x, y, x + 0xA2, y + 0x2C);
    TOMkpShapeXY(p + 0x1B8, x + 2, y + 2);
    TOMkpEasyMesFontLCenter(func_0021F940(p), x + 0x61, y + 2);
    TOBtlDrawParamPlate(p, x + 2, y + 0x17);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", TOBtlDrawParamPlate);

s32 func_0021F8C0(int id)
{
    return MsGetRamChrHP(id);
}

s32 func_0021F8E0(int id)
{
    return MsGetRamChrMP(id);
}

s32 func_0021F900(int id)
{
    return MsGetRamChrHPmax(id);
}

s32 func_0021F920(int id)
{
    return MsGetRamChrMPmax(id);
}

int func_0021F940(int a)
{
    return TOGetSaveChrName(a);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21D048", func_0021F960);
