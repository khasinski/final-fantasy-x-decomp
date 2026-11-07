/* tu_110 0x1691c8-0x16cd98: low; ~TOMenuMainHelpSleep (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/g1.h"

int func_001691C8(void) {
    return get_hdd_inst_info();
}

void func_001691E8(void)
{
    /* DEBT(ORDER): independent resets preserve original address/store scheduling. */
    D_0030E0C8 = 0;
    D_0030E0CC = 0;
    D_0030E0BC = 0;
    D_00597E30 = 0;
    D_0030E0A8 = 0;
    D_00597A0C = 0;
    D_0030E0AC = 0;
    D_0030E0B0 = 0;
    D_0030E0B4 = 0;
    D_0030E0B8 = 0;
    D_00597A24 = 0;
    D_0030E0C0 = 0;
    D_00597A18 = 0;
    D_00597A1A = 0;
    D_00597A1C = 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_00169278);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_001694E8);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_00169B10);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016A048);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016A268);
INCLUDE_RODATA("build/ee_asm/game/menu/to/to_1691C8/rodata", jtbl_0056C040);
INCLUDE_RODATA("build/ee_asm/game/menu/to/to_1691C8/rodata", jtbl_0056C060);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016AA88);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016AB78);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016AC00);
INCLUDE_RODATA("build/ee_asm/game/menu/to/to_1691C8/rodata", jtbl_0056C080);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016B4E0);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016B5B0);
INCLUDE_RODATA("build/ee_asm/game/menu/to/to_1691C8/rodata", jtbl_0056C0A0);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016B7D8);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016B838);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016B898);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016BA00);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016BB88);

void func_0016BC30(int a) {
    D_00597A24 -= ((a + 0x3F) / 64) * 64;
    if (D_00597A24 < 0) {
        yiAssert(0, D_0056C020, D_0056C140);
    }
}

void func_0016BC80(int v) {
    D_0030E068 = v;
}

int func_0016BC90(void) {
    return D_0030E068 != 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016BCA0);
INCLUDE_RODATA("build/ee_asm/game/menu/to/to_1691C8/rodata", jtbl_0056C160);

int func_0016C318(void) {
    return D_0030E060;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016C328);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016C688);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016C920);

PartySlot *func_0016CAC8(int id) {
    return MsGetSavePlayerPtr(id);
}

int func_0016CAE8(void) {
    int a = MsGetSaveBattleCount();

    return a - TkGetEncountCounterEventStart();
}

int func_0016CB18(void) {
    return MsGetSaveBattleCount();
}

int func_0016CB38(int id) {
    return *(int *)((u8 *)func_0016CAC8(id) + 0x50); /* DEBT(CAST): PartySlot lacks this member */
}

int func_0016CB58(int id) {
    return *(int *)((u8 *)func_0016CAC8(id) + 0x58); /* DEBT(CAST): PartySlot lacks this member */
}

int func_0016CB78(int id) {
    return *(int *)((u8 *)func_0016CAC8(id) + 0x54); /* DEBT(CAST): PartySlot lacks this member */
}

/* Character-record accessors: MsGetSaveCommand(chr, id) flag tests (ids 0x30xx) and ChrRec1D8 field getters (D_0030E0C0[i]). */

int func_0016CB98(int a) {
    return func_001BFE30(a);
}

int func_0016CBB8(void) {
    return MsImportantGet();
}

int func_0016CBD8(void) {
    return MsGetGIL();
}

s8 func_0016CBF8(int i) {
    return ((s8 *)MsGetSaveEventFlag())[i];
}

s32 func_0016CC28(s32 arg0) {
    return ((s8) *(s8 *)(MsGetSaveEventFlag() + (((s32)arg0 / 8))) >> (arg0 & 7)) & 1;
}

int func_0016CC78(void) {
    return func_0014AC00();
}

int func_0016CC98(void) {
    return func_0014AF20();
}

int func_0016CCB8(int i) {
    return MsGetMonsterCapture(i);
}

int func_0016CCD8(void) {
    return hdd_rmode_get();
}

int func_0016CCF8(void) {
    if (D_00597A18 & 0x20) {
        return 1;
    }
    return 0;
}

/* DEBT(FAKE) */
s32 func_0016CD10(void) {
    register s32 var_2 __asm__("$2");

    var_2 = 0;
    if (D_0030E0C5 != 0) {
        var_2 = ((D_00597A18 | D_00597A1C) & 0xF000) != 0;
    }
    return var_2;
}

int func_0016CD48(int id) {
    return MsGetSavePlyJoin(id) == 1;
}

int func_0016CD70(void) {
    if (D_00597A18 & 0x40) {
        return 1;
    }
    return 0;
}

int func_0016CD88(void) {
    return D_00597A04;
}
