/* tu_285 0x265f78-0x266a48: medium; ~Nkz (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/t6.h"
#include "ffx/u4.h"
#include "ffx/s6.h"
#include "ffx/v6.h"

int func_00265F78(int i)
{
    IntTab4 tab = D_00573AA8;

    return tab.v[i];
}

int func_00265FB8(int i)
{
    IntTab4 tab = D_00573AB8;

    return tab.v[i];
}

float func_00265FF8(void) {
    return 4.0f;
}

int func_00266008(int a)
{
    int r = 3;

    MsGetRamChrMag(5);
    switch (a) {
    case 0:
        r = 2;
        break;
    case 1:
        r = 2;
        break;
    case 2:
        r = 2;
        break;
    case 3:
        r = 2;
        break;
    case 4:
        r = 2;
        break;
    case 5:
        r = 2;
        break;
    case 6:
        r = 2;
        break;
    case 7:
        r = 2;
        break;
    case 8:
        r = 2;
        break;
    case 9:
        r = 2;
        break;
    case 10:
        r = 2;
        break;
    case 11:
        r = 2;
        break;
    case 12:
        r = 2;
        break;
    case 13:
        r = 2;
        break;
    case 14:
        r = 2;
        break;
    case 15:
        r = 2;
        break;
    case 16:
        r = 2;
        break;
    case 17:
        r = 4;
        break;
    case 18:
        r = 5;
        break;
    }
    return r;
}

void NkzSetLuluLimitTbl(int kind)
{
    int lv = MsGetRamChrMag(5);

    switch (kind) {
    case 0:
    case 1:
    case 2:
    case 3:
        if (lv < 35) {
            TOBtlSetLuluLimitTbl(D_00573B20);
        } else if (lv < 60) {
            TOBtlSetLuluLimitTbl(D_00573B38);
        } else if (lv < 100) {
            TOBtlSetLuluLimitTbl(D_00573B50);
        } else if (lv < 200) {
            TOBtlSetLuluLimitTbl(D_00573B68);
        } else if (lv < 255) {
            TOBtlSetLuluLimitTbl(D_00573B80);
        } else {
            TOBtlSetLuluLimitTbl(D_00573B98);
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        if (lv < 25) {
            TOBtlSetLuluLimitTbl(D_00573BB0);
        } else if (lv < 45) {
            TOBtlSetLuluLimitTbl(D_00573B20);
        } else if (lv < 90) {
            TOBtlSetLuluLimitTbl(D_00573B38);
        } else if (lv < 200) {
            TOBtlSetLuluLimitTbl(D_00573B50);
        } else if (lv < 255) {
            TOBtlSetLuluLimitTbl(D_00573B68);
        } else {
            TOBtlSetLuluLimitTbl(D_00573B98);
        }
        break;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
        if (lv < 40) {
            TOBtlSetLuluLimitTbl(D_00573BB0);
        } else if (lv < 75) {
            TOBtlSetLuluLimitTbl(D_00573B20);
        } else if (lv < 100) {
            TOBtlSetLuluLimitTbl(D_00573B38);
        } else if (lv < 200) {
            TOBtlSetLuluLimitTbl(D_00573B50);
        } else if (lv < 255) {
            TOBtlSetLuluLimitTbl(D_00573B68);
        } else {
            TOBtlSetLuluLimitTbl(D_00573B68);
        }
        break;
    case 15:
    case 16:
        if (lv < 30) {
            TOBtlSetLuluLimitTbl(D_00573BC8);
        } else if (lv < 50) {
            TOBtlSetLuluLimitTbl(D_00573B20);
        } else if (lv < 100) {
            TOBtlSetLuluLimitTbl(D_00573B38);
        } else if (lv < 200) {
            TOBtlSetLuluLimitTbl(D_00573B50);
        } else if (lv < 255) {
            TOBtlSetLuluLimitTbl(D_00573B68);
        } else {
            TOBtlSetLuluLimitTbl(D_00573B98);
        }
        break;
    case 17:
        if (lv < 50) {
            TOBtlSetLuluLimitTbl(D_00573BE0);
        } else if (lv < 75) {
            TOBtlSetLuluLimitTbl(D_00573BF8);
        } else if (lv < 100) {
            TOBtlSetLuluLimitTbl(D_00573C10);
        } else if (lv < 255) {
            TOBtlSetLuluLimitTbl(D_00573C28);
        } else {
            TOBtlSetLuluLimitTbl(D_00573C40);
        }
        break;
    case 18:
        if (lv < 40) {
            TOBtlSetLuluLimitTbl(D_00573C58);
        } else if (lv < 75) {
            TOBtlSetLuluLimitTbl(D_00573C70);
        } else if (lv < 150) {
            TOBtlSetLuluLimitTbl(D_00573BE0);
        } else if (lv < 255) {
            TOBtlSetLuluLimitTbl(D_00573C88);
        } else {
            TOBtlSetLuluLimitTbl(D_00573CA0);
        }
        break;
    }
}

INCLUDE_ASM("build/ee_asm/game/abm/abm_265F78", func_002664D8);

int abmap_special_sphere_select_check(int a, int b, S6Ent *o, int ch)
{
    int i;

    switch (a) {
    case 1:
        if (o->b16 == 0x12) {
            return 1;
        }
        break;
    case 2:
        if (o->b16 == 0x11) {
            return 1;
        }
        break;
    case 3:
        if (o->b16 == 0) {
            return 1;
        }
        break;
    case 4:
        if (o->b16 == 0x10) {
            return 1;
        }
        break;
    case 8:
        if (abmap_check_getpanel(ch, b) == 0 && o->b16 == 0xF && abmap_check_getpanel_other(ch, b) != 0) {
            return 1;
        }
        break;
    case 9:
        if (abmap_check_getpanel(ch, b) == 0 && o->b16 == 0xE && abmap_check_getpanel_other(ch, b) != 0) {
            return 1;
        }
        break;
    case 10:
        if (abmap_check_getpanel(ch, b) == 0 && o->b16 == 0xC && abmap_check_getpanel_other(ch, b) != 0) {
            return 1;
        }
        break;
    case 11:
        if (abmap_check_getpanel(ch, b) == 0 && o->b16 == 0xD && abmap_check_getpanel_other(ch, b) != 0) {
            return 1;
        }
        break;
    case 12:
        if (func_00257A08(ch) != b && abmap_check_getpanel(ch, b) != 0) {
            return 1;
        }
        break;
    case 13:
        if (func_00257A08(ch) != b && abmap_check_getpanel_other(ch, b) != 0) {
            return 1;
        }
        break;
    case 14:
        if (func_00257A08(ch) != b) {
            for (i = 0; i < 7; i++) {
                if (ch != i && MsGetSavePlyJoined(i) != 0 && func_00257A08(i) == b) {
                    return 1;
                }
            }
        }
        break;
    case 15:
        if (func_00257A08(ch) != b && !(o->h10 & 0x8000)) {
            return 1;
        }
        break;
    case 5:
    case 6:
    case 7:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
        if (o->b16 == 1) {
            return 1;
        }
        break;
    case 23:
        if ((u8)(o->b16 - 2) < 10) {
            return 1;
        }
        break;
    case 24:
        if (abmap_check_getpanel(ch, b) == 0 && (u8)(o->b16 - 2) < 10 && abmap_check_getpanel_other(ch, b) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

int abmap_para_get_special(int a, int b, int c)
{
    int i;

    switch (a) {
    case 1:
    case 2:
    case 3:
    case 4:
        func_00257958(1, b);
        abmap_snd_chg_panel1();
        return 1;
    case 5:
        func_00257958(0x19, b);
        abmap_snd_chg_panel0();
        return 1;
    case 6:
        func_00257958(0x23, b);
        abmap_snd_chg_panel0();
        return 1;
    case 7:
        func_00257958(0x24, b);
        abmap_snd_chg_panel0();
        return 1;
    case 12:
    case 13:
    case 14:
    case 15:
        func_002579D0(c, b);
        return 1;
    case 16:
        func_00257958(5, b);
        abmap_snd_chg_panel0();
        return 1;
    case 17:
        func_00257958(9, b);
        abmap_snd_chg_panel0();
        return 1;
    case 18:
        func_00257958(0xD, b);
        abmap_snd_chg_panel0();
        return 1;
    case 19:
        func_00257958(0x11, b);
        abmap_snd_chg_panel0();
        return 1;
    case 20:
        func_00257958(0x15, b);
        abmap_snd_chg_panel0();
        return 1;
    case 21:
        func_00257958(0x1D, b);
        abmap_snd_chg_panel0();
        return 1;
    case 22:
        func_00257958(0x21, b);
        abmap_snd_chg_panel0();
        return 1;
    case 23:
        func_00257958(1, b);
        for (i = 0; i < 7; i++) {
            func_002579A0(i, b);
        }
        abmap_snd_chg_panel1();
        return 1;
    case 8:
    case 9:
    case 10:
    case 11:
    case 24:
        func_00257960(c, b);
        return 1;
    }
    return 0;
}

int func_00266990(int a, int n)
{
    int r = func_002EC2A0(func_002EBBB0(func_002EBC70(func_002E9290(func_002EC1E8(n)), 0.25), 16.0));

    if (r == 0) {
        r = 1;
    }
    return r;
}

int func_002669E8(int a, int n)
{
    double d = func_002E9290(func_002EC1E8(n));
    int r = func_002EC2A0(func_002EBBB0(func_002EBF18(func_002EBBB0(d, d), 3.0), 10.0));

    if (r == 0) {
        r = 1;
    }
    return r;
}
