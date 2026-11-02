/* tu_265 0x23c658-0x23cbd0: medium; ~TOClearMessageWindowForMenu (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r5.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/s5.h"
#include "ffx/u4.h"
#include "ffx/v5.h"

void func_0023C658(void)
{
    Rec124828 *rec = func_00124828();
    Rec124828 *bak = D_0069A60C;
    char *name;
    int ofs;
    int i;

    for (i = 0; i < 18; i++) {
        name = (char *)MsGetSaveChrName(i);
        ofs = name - (char *)&D_003194D0;
        func_002F072C(name, (char *)D_0069A60C + ofs); /* DEBT(CAST): same offset inside the backup copy of D_003194D0 */
    }
    rec->xD1 = bak->xD1;
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23C658", TkMenuCtrlTuto);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_23C658/rodata", jtbl_00572C80);

void func_0023CB90(void) {
}

void func_0023CB98(Task *o) { o->x1C = 0; }

void func_0023CBA0(int a, int b) {
    D_00323954 = 1;
    D_0069A610 = b;
}

void func_0023CBB8(void) {
}

void func_0023CBC0(void) {
    D_00323954 = 0;
}
