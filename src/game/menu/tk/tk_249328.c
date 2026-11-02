/* tu_271 0x249328-0x249928: low; ~Tk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/r5.h"
#include "ffx/u4.h"
#include "ffx/v5.h"
#include "ffx/s5.h"
#include "ffx/s6.h"

int TkMenuMainMes(int a0) { return MsMenuGetText(9, a0, MsGetSaveConfigHiragana()); }

int TkMenuMenu1Mes(int a0) { return MsMenuGetText(1, a0, MsGetSaveConfigHiragana()); }

int func_00249398(int a0) { return MsMenuGetText(2, a0, MsGetSaveConfigHiragana()); }

int func_002493D0(int a0) { return MsMenuGetText(3, a0, MsGetSaveConfigHiragana()); }

int func_00249408(int a0) { return MsMenuGetText(6, a0, MsGetSaveConfigHiragana()); }

int TkMenuConfigMes(int a0) { return MsMenuGetText(7, a0, MsGetSaveConfigHiragana()); }

int func_00249478(int a0) { return MsMenuGetText(8, a0, MsGetSaveConfigHiragana()); }

int func_002494B0(int a0) { return MsMenuGetText(10, a0, MsGetSaveConfigHiragana()); }

int func_002494E8(int a0) { return MsMenuGetText(11, a0, MsGetSaveConfigHiragana()); }

int func_00249520(int a0) { return MsMenuGetText(12, a0, MsGetSaveConfigHiragana()); }

int func_00249558(int a0) { return MsMenuGetText(5, a0, MsGetSaveConfigHiragana()); }

int TkMenuMainHelp(int a0) { return MsMenuGetHelp(9, a0, MsGetSaveConfigHiragana()); }

int TkMenuMenu1Help(int a0) { return MsMenuGetHelp(1, a0, MsGetSaveConfigHiragana()); }

int func_00249600(int a0) { return MsMenuGetHelp(2, a0, MsGetSaveConfigHiragana()); }

int func_00249638(int a0) { return MsMenuGetHelp(3, a0, MsGetSaveConfigHiragana()); }

int func_00249670(int a0) { return MsMenuGetHelp(6, a0, MsGetSaveConfigHiragana()); }

int TkMenuConfigHelp(int a0) {
    int v = MsGetSaveConfigHiragana();

    if (func_001BD360() == 0) {
        return MsMenuGetHelp(7, a0, v);
    }
    return MsMenuGetHelp(0xE, a0, v);
}

int func_00249700(int a0) { return MsMenuGetHelp(8, a0, MsGetSaveConfigHiragana()); }

int func_00249738(int a0) { return MsMenuGetHelp(10, a0, MsGetSaveConfigHiragana()); }

int func_00249770(int a0) { return MsMenuGetHelp(11, a0, MsGetSaveConfigHiragana()); }

int func_002497A8(int a0) { return MsMenuGetHelp(12, a0, MsGetSaveConfigHiragana()); }

int func_002497E0(int a0) { return MsMenuGetHelp(5, a0, MsGetSaveConfigHiragana()); }

int TOMenuGetGetImportantHelp(int id) {
    s32 pos;
    int sel = func_0013A398(id) != 0;
    OfsTbl *t = MsImportantPtr(id, &pos);

    pos += t->b[sel].x;
    return pos;
}

int func_00249878(int id) {
    s32 pos;
    int sel = func_0013A398(id) != 0;
    OfsTbl *t = MsImportantPtr(id, &pos);

    pos += t->a[sel].x;
    return pos;
}

int func_002498D0(int id) {
    s32 pos;
    int sel = func_0013A398(id) != 0;
    OfsTbl *t = MsGetRomPlyCommand(id, &pos);

    pos += t->a[sel].x;
    return pos;
}
