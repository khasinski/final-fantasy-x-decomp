/* tu_242 0x2180a0-0x218a78: low; ~TOBtlCtrlHelpWin (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/u3.h"
#include "ffx/g3.h"
#include "ffx/v4.h"

void func_002180A0(void)
{
    D_003249AB = 0;
    func_002EF0D0(D_00692480, 0, 0x80);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2180A0", TOBtlCtrlHelpWin);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2180A0", func_00218330);

/* DEBT(CAST): the flag word behind MsGetSaveMenu() is untyped */
void func_00218470(void)
{
    D_003249AB = 1;
    if ((*(s32 *)MsGetSaveMenu() >> 10) & 1) {
        TOSeqStartSceneNoErase(2, D_00570E28);
    }
}

/* DEBT(CAST): the flag word behind MsGetSaveMenu() is untyped */
void func_002184B8(void)
{
    D_003249AB = 0;
    if ((*(s32 *)MsGetSaveMenu() >> 10) & 1) {
        TOSeqStopScene(2, D_00570E28);
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2180A0", func_00218500);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2180A0", TOBtlSetTargetHelpMes);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2180A0", TOBtlSetChangeHelpMes);

void func_002188A0(char *s)
{
    if (s != 0) {
        func_002EF0D0(D_00692480, 0, 0x80);
        func_002F072C(D_00692480, s);
        _TOGetMessageWH(0, (u8 *)D_00692480, D_00692478, &D_0069247A, 0, 0);
    }
}

void func_00218928(void)
{
    D_003249AC = 0;
    D_00692500 = 0xFF;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2180A0", TOBtlCtrlInfoWin);
