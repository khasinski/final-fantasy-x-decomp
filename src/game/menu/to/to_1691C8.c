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

typedef struct {
    u8 pad0[0x20];
    s16 h20;
    s16 h22;
    u8 pad24[7];
    s8 b2B;
} To16AB78Arg;

extern int (**D_0030E098)(int);

int func_0016AB78(To16AB78Arg *p)
{
    int r;

    if (p->h20 < 0) {
        return 0;
    }
    r = D_0030E098[p->h20](p->h22);
    switch (p->b2B) {
    case 0:
        if (r == 0) {
            return 1;
        }
        break;
    case 1:
        if (r != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016AC00);
INCLUDE_RODATA("build/ee_asm/game/menu/to/to_1691C8/rodata", jtbl_0056C080);

void func_0016B4E0(void)
{
    extern s32 D_0030E05C, D_0030E0D0, D_0030E0D4, D_0030E0D8;
    extern s32 dvd_hdd_copy_system_cnf_buff;
    extern void (**D_0030E064)(void);

    D_0030E0C8 = 0;
    D_00597E30 = 0;
    D_0030E0CC = 0;
    D_0030E0A8 = 0;
    D_00597A0C = 0;
    D_0030E0AC = 0;
    D_0030E0B0 = 0;
    D_0030E0B8 = 0;
    D_0030E0C0 = 0;
    D_0030E0BC = 0;
    D_0030E060 = 0;
    D_0030E0D0 = 0;
    D_0030E0D8 = 0;
    D_0030E0D4 = 0;
    dvd_hdd_copy_system_cnf_buff = 0;
    D_0030E05C = 0;
    if (D_0030E064 != 0) {
        D_0030E064[1]();
        D_0030E064 = 0;
    }
    D_0030E068 = 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016B5B0);
INCLUDE_RODATA("build/ee_asm/game/menu/to/to_1691C8/rodata", jtbl_0056C0A0);

void func_0016B7D8(void)
{
    s32 *hdr = (s32 *)D_0030E0C8;

    if (hdr != 0) {
        D_0030E0A8 = (u8 *)hdr + hdr[2];
        D_00597A0C = hdr[1];
        D_0030E0AC = (u8 *)hdr + hdr[3];
        D_0030E0B0 = (u8 *)hdr + hdr[4];
        D_0030E0B4 = (u8 *)hdr + hdr[5];
    }
}

typedef struct {
    s32 off;
    s16 cnt;
    s16 pad;
} To16B838Hdr;

typedef struct {
    u8 pad0[0x114];
    u16 h114;
    u16 h116;
    s32 w118;
    s32 w11C;
    u16 h120;
    u16 h122;
    u8 pad124[0x14];
} To16B838Ent;

extern s32 _m2c_D_0030E0A8 __asm__("D_0030E0A8");
extern s32 _m2c_D_0030E0C8 __asm__("D_0030E0C8");

void func_0016B838(void)
{
    To16B838Hdr *hdr = (To16B838Hdr *)((D_00597A14 * 8) + _m2c_D_0030E0A8);
    int j;
    int n = hdr->cnt;
    To16B838Ent *p = (To16B838Ent *)(_m2c_D_0030E0C8 + hdr->off);

    for (j = 0; j < n; j++, p++) {
        p->h114 = p->h120;
        p->h116 = p->h122;
        p->w118 = 0;
        p->w11C = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016B898);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016BA00);

extern char D_0056C118[];

int func_0016BB88(int a0, int a1)
{
    int max = func_00220808();
    int ret;

    if (a0 == 0) {
        D_00597A24 = 0;
    }
    a1 = ((a1 + 0x3F) / 64) * 64;
    ret = func_00220800() + D_00597A24;
    D_00597A24 += a1;
    if (D_00597A24 >= max) {
        ((void (*)(int, char *, char *, int, int))yiAssert)(0, D_0056C020, D_0056C118, D_00597A24, max); /* DEBT(CAST) */
    }
    return ret;
}

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
    return func_0016CAC8(id)->v50;
}

int func_0016CB58(int id) {
    return func_0016CAC8(id)->v58;
}

int func_0016CB78(int id) {
    return func_0016CAC8(id)->v54;
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
