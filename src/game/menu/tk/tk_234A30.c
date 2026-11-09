/* tu_260 0x234a30-0x235c38: low; ~Tk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r5.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/s5.h"
#include "ffx/u4.h"
#include "ffx/v5.h"

void func_00234A30(void)
{
    if (func_002D92C8() == 1) {
        TkMn2GetCommonPlate(&D_00693F78, D_00572230, D_00572240, D_00572250, 0xCC, 0xCD);
        D_00693FBC = V5_TkMn2SeqGetNum_int(D_00572260);
    } else {
        TkMn2GetCommonPlate(&D_00693F78, D_00572270, D_00572240, D_00572250, 0xCC, 0xCD);
        D_00693FBC = V5_TkMn2SeqGetNum_int(D_00572288);
    }
    func_002273A0(D_005722A0, D_00693F90);
    func_002273A0(D_005722B0, D_00693FA0);
    func_002273A0(D_005722C0, D_00693FC0);
    func_00227460(D_005722D0, D_00693F98);
    func_00227460(D_005722E0, D_00693FB0);
    func_00227460(D_005722F0, D_00693FA8);
    D_00693FB4 = TkMn2SeqGetColor(D_00572300);
    D_00693FB8 = TkMn2SeqGetColor(D_00572310);
    D_00693FC8 = TkMn2SeqGetColor(D_00572320);
    D_00693FCC = TkMn2SeqGetColor(D_00572330);
}

void func_00234B98(FlagRec *o) {
    PadState *p = MsGetSaveMenu();

    o->x0C = 1;
    if (p->flags & 1) {
        o->x08 = 0;
    } else {
        o->x08 = 1;
    }
    TkRefreshSoundMode();
}

void func_00234BD8(FlagRec *o) {
    PadState *p = MsGetSaveMenu();

    switch (o->x08) {
    case 1:
        p->flags &= 0xFFFFFF7F;
        p->flags &= 0xFFFFFFFE;
        break;
    case 0:
    default:
        p->flags &= 0xFFFFFF7F;
        p->flags |= 1;
        break;
    }
    TkRefreshSoundMode();
}

void func_00234C50(FlagRec *o) {
    PadState *p = MsGetSaveMenu();

    o->x0C = 1;
    if ((p->flags >> 8) & 1) {
        o->x08 = 0;
    } else {
        o->x08 = 1;
    }
}

void func_00234C98(FlagRec *o) {
    PadState *p = MsGetSaveMenu();
    FlagRec *q = func_00235320(1);

    if (o->x08 == 0) {
        p->flags |= 0x100;
        q->x0C = 1;
    } else {
        p->flags &= 0xFFFFFEFF;
        q->x0C = 0;
    }
}

void func_00234D10(FlagRec *o) {
    PadState *p = MsGetSaveMenu();

    if ((p->flags >> 8) & 1) {
        o->x0C = 1;
    } else {
        o->x0C = 0;
    }
    if ((p->flags >> 9) & 1) {
        o->x08 = 0;
    } else {
        o->x08 = 1;
    }
}

void func_00234D78(FlagRec *o) {
    PadState *p = MsGetSaveMenu();

    if ((p->flags >> 8) & 1) {
        o->x0C = 1;
    } else {
        o->x0C = 0;
    }
    if (o->x08 == 0) {
        p->flags |= 0x200;
    } else {
        p->flags &= 0xFFFFFDFF;
    }
}

void func_00234DF0(FlagRec *o) {
    PadState *p = MsGetSaveMenu();

    if ((p->flags >> 5) & 1) {
        o->x08 = 0;
    } else {
        o->x08 = 1;
    }
    o->x0C = 1;
    if (((p->flags >> 8) & 1) == 0) {
        o->x0C = 0;
    }
}

void func_00234E58(FlagRec *o) {
    PadState *p = MsGetSaveMenu();

    if (o->x08 == 0) {
        p->flags |= 0x20;
    } else {
        p->flags &= 0xFFFFFFDF;
    }
}

void func_00234EB0(FlagRec *o) {
    PadState *p = MsGetSaveMenu();

    if ((p->flags >> 1) & 1) {
        o->x08 = 1;
    } else {
        o->x08 = 0;
    }
}

void func_00234EF8(FlagRec *o) {
    PadState *p = MsGetSaveMenu();

    if (o->x08 == 0) {
        p->flags &= 0xFFFFFFFD;
    } else {
        p->flags |= 2;
    }
}

void func_00234F50(FlagRec *o) {
    PadState *p = MsGetSaveMenu();

    if ((p->flags >> 10) & 1) {
        o->x08 = 0;
    } else {
        o->x08 = 1;
    }
}

void func_00234F98(FlagRec *o) {
    PadState *p = MsGetSaveMenu();

    if (o->x08 == 0) {
        p->flags |= 0x400;
    } else {
        p->flags &= 0xFFFFFBFF;
    }
}

void func_00234FF0(FlagRec *o) {
    PadState *p = MsGetSaveMenu();

    if ((p->flags >> 11) & 1) {
        o->x08 = 0;
    } else {
        o->x08 = 1;
    }
}

void func_00235038(FlagRec *o) {
    PadState *p = MsGetSaveMenu();

    if (o->x08 == 0) {
        p->flags |= 0x800;
    } else {
        p->flags &= 0xFFFFF7FF;
    }
}

void func_00235090(FlagRec *o) {
    PadState *p = MsGetSaveMenu();

    if ((p->flags >> 6) & 1) {
        o->x08 = 0;
    } else {
        o->x08 = 1;
    }
}

void func_002350D8(FlagRec *o) {
    PadState *p = MsGetSaveMenu();

    if (o->x08 == 0) {
        p->flags |= 0x40;
    } else {
        p->flags &= 0xFFFFFFBF;
    }
}

void func_00235130(FlagRec *o) {
    PadState *p = MsGetSaveMenu();

    if ((p->flags >> 4) & 1) {
        o->x08 = 0;
    } else {
        o->x08 = 1;
    }
    TkSetControlerActuatorMode();
    if (func_002D27B8(0, 0) == 0) {
        o->x0C = 0;
    } else {
        o->x0C = 1;
    }
}

void func_002351A0(FlagRec *o) {
    PadState *p = MsGetSaveMenu();

    if (o->x08 == 0) {
        p->flags |= 0x10;
    } else {
        p->flags &= 0xFFFFFFEF;
    }
    TkSetControlerActuatorMode();
}

void func_002351F8(FlagRec *o) {
    if (func_001BD360() == 1) {
        o->x08 = 0;
    } else {
        o->x08 = 1;
    }
}

void func_00235230(FlagRec *o) {
    if (o->x08 == 0) {
        MsSetSaveConfigEnglish(1);
    } else {
        MsSetSaveConfigEnglish(0);
    }
}

void func_00235250(FlagRec *o) {
    PadState *p = MsGetSaveMenu();

    if ((p->flags >> 13) & 1) {
        o->x08 = 0;
    } else {
        o->x08 = 1;
    }
    if (func_00167D50() == 3) {
        o->x0C = 0;
    } else {
        int r = get_hdd_inst_info();

        if (r == 1) {
            o->x0C = r;
        } else {
            o->x0C = 0;
        }
    }
}

void func_002352C8(FlagRec *o)
{
    PadState *p = MsGetSaveMenu();
    int f;

    TkGetFFXCofingAdrs();
    f = o->x08 == 0;
    p->flags = (p->flags & 0xFFFFDFFF) | (f << 13);
    TkRefreshHDD();
}

FlagRec *func_00235320(int i) {
    return D_00693F70[i];
}

void func_00235338(void)
{
    do {
        D_00693F68--;
        if ((s8)D_00693F68 < 0) {
            /* DEBT(CAST): this routine reads only the low byte of the word count. */
            D_00693F68 = *(u8 *)&D_00693F6C - 1;
        }
    } while (D_00693F70[(s8)D_00693F68]->x0C != 1);
}

void func_00235390(void)
{
    s32 next;

    do
    {
        next = D_00693F68 + 1;
        D_00693F68 = (u8) next;
        if ((s8) next >= D_00693F6C)
        {
            D_00693F68 = 0;
        }
    } while (D_00693F70[(s8) D_00693F68]->x0C != 1);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_234A30", TkMenuCtrlConfig);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_234A30/rodata", jtbl_00572340);

void func_00235710(void) { func_002270F8(); }

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_234A30", func_00235718);

int func_002359F8() /* DEBT(TYPE): declared int (), no value returned; a caller passes an argument */
{
    int i;

    for (i = 0; i < *(int *)&D_00693F6C; i++) { /* DEBT(CAST): q6.h declares it u8, read as a word */
        func_00235718(0, 0, i);
        ((int (*)(void))graphicUiRemapY2)(); /* DEBT(CAST): the original call site sees an int-returning declaration */
    }
}

void func_00235A60(int a0) {
    func_002492F0();
    func_002492F0();
    func_00225A38();
    func_00225920();
    func_002359F8(a0);
    func_00225B00();
}

void func_00235AA8(void) {
    if (func_0020B850() == 0) {
        if (func_002D92C8() == 1) {
            D_00693F6C = 10;
            D_00693F70 = D_00325FB8;
        } else {
            D_00693F6C = 9;
            D_00693F70 = D_00325FE0;
        }
    } else {
        if (func_002D92C8() == 1) {
            D_00693F6C = 9;
            D_00693F70 = D_00325F70;
        } else {
            D_00693F6C = 8;
            D_00693F70 = D_00325F98;
        }
    }
    func_00234A30();
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_234A30", func_00235B48);

void func_00235C08(void) {
    func_00227490(&D_00572370);
    func_00227490(&D_00572378);
}

void func_00235C30(void) {
}
