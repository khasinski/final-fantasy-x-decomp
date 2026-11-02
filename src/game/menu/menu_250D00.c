/* tu_274 0x250d00-0x250f68: low; ~Tk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/s6.h"
#include "ffx/u4.h"
#include "ffx/v5.h"

INCLUDE_ASM("build/ee_asm/game/menu/menu_250D00", TkMenuCtrlHelp);

void func_00250DF8(void) {
    func_00124F08();
    TOMenuOpenPktBuffTmp();
    TODrawScissorXYWH(0, 0, 0x1FF, 0x19F);
    func_001F0328(0, 0, 0x200, 0x1A0, 0x80000000, 0x80000000);
    TOMenuDrawKickTmp();
    func_00124F08();
    D_0030E078();
    func_00124F08();
    func_0020EC88();
}

void func_00250E78(void)
{
    D_0069BEF0 = 0;
    D_0069BEF4 = 0;
    D_0030E070();
}

void func_00250EA8(Task *t, int v) {
    D_0069BEF8 = v & 0xFFFF;
    D_0069BEF4 = v & 0xFFF;
    t->x1C = 0;
}

void func_00250EC8(void)
{
    D_0030E07C();
}

void TOMenuTermHelp(void)
{
    if (D_0069BEF4 == 3) {
        SndSepPlaySimple(0x8000006C);
    } else {
        SndSepPlaySimple(0x80000004);
    }
    TkMenuMainSleepMenu(11);
    if (D_0069BEF0 == 0) {
        TkMenuMainActiveMenu(1, 0);
    }
    D_0069BEF4 = 0;
}
