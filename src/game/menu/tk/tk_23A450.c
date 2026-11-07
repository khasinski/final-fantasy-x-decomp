/* tu_264 0x23a450-0x23c658: medium; ~Tk (config/tu_map.tsv) */
#define func_0023C4B8 _hdr_func_0023C4B8
#include "common.h"
#include "ffx/r5.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/s5.h"
#include "ffx/s6.h"
#include "ffx/u4.h"
#include "ffx/u3.h"
#include "ffx/v5.h"
#undef func_0023C4B8

int TkMn2GetIShopPos(void) /* DEBT(TYPE): declared int in funcs.h, no value returned */
{
    /* DEBT(CAST): TkMn2GetCommonPlate takes the part names as int */
    /* DEBT(CAST): several targets are declared with other types in shared headers */
    func_002273A0(D_00572790, D_00326288);
    func_002273A0(D_005727A0, D_00326170);
    func_002273A0(D_005727B0, D_006940A8);
    func_002273A0(D_005727C0, D_006940B0);
    func_002273A0(D_005727D0, D_00326240);
    func_002273A0(D_005727E0, D_00326180);
    func_002273A0(D_005727F0, (s16 *)&D_003261D8);
    func_002273A0(D_00572800, D_006940B8);
    func_002273A0(D_00572810, D_006940C0);
    func_00227460(D_00572820, D_003261D0);
    func_00227460(D_00572830, D_003261C8);
    func_00227460(D_00572840, D_00326238);
    func_00227460(D_00572850, D_003261E0);
    func_00227460(D_00572860, D_003261B8);
    func_00227460(D_00572870, D_00326178);
    func_00227460(D_00572880, D_006940C8);
    func_00227460(D_00572890, D_00326248);
    func_00227460(D_005728A0, D_00326250);
    func_00227460(D_005728B0, D_00326268);
    func_00227460(D_005728C0, D_00326270);
    func_00227460(D_005728D0, D_006940D0);
    func_00227460(D_005728E0, D_006940D8);
    func_00227460(D_005728F0, D_003261C0);
    func_00227460(D_00572900, D_00326230);
    func_00227460(D_00572910, D_00326258);
    func_00227460(D_00572920, D_00326260);
    D_006940DC = TkMn2SeqGetColor((int)D_00572930);
    D_006940E0 = TkMn2SeqGetColor((int)D_00572940);
    D_006940E4 = TkMn2SeqGetColor((int)D_00572950);
    D_006940E8 = TkMn2SeqGetColor((int)D_00572960);
    D_006940EC = TkMn2SeqGetColor((int)D_00572970);
    D_006940F0 = TkMn2SeqGetColor((int)D_00572980);
    D_006940F4 = TkMn2SeqGetColor((int)D_00572990);
    D_006940F8 = TkMn2SeqGetColor((int)D_005729A0);
    D_006940FC = TkMn2SeqGetColor((int)D_005729B0);
    func_00227460(D_005729C0, D_00694138);
    func_00227460(D_005729D0, &D_00694140);
    func_002273A0(D_005729E0, D_00694148);
    D_00694100 = TkMn2SeqGetColor((int)D_005729F0);
    D_00694104 = TkMn2SeqGetColor((int)D_00572A00);
    func_00227460(D_00572A10, D_00326278);
    func_00227460(D_00572A20, D_00326280);
    TkMn2GetCommonPlate(&D_00326188, (int)D_005727B0, (int)D_00572930, (int)D_00572940, 0, 0);
    TkMn2GetCommonPlate(&D_003261A0, (int)D_005727F0, (int)D_00572950, (int)D_00572960, 0xda, 0xdb);
    TkMn2GetCommonPlate(&D_003261E8, (int)D_00572800, (int)D_005729F0, (int)D_00572A00, 0, 0);
    TkMn2GetCommonPlate(&D_00326200, (int)D_00572810, (int)D_00572990, (int)D_00572990, 0, 0);
    TkMn2GetCommonPlate(&D_00326218, (int)D_005727C0, (int)D_00572970, (int)D_00572980, 0xda, 0xdb);
}

void func_0023A8C8(void)
{
    int vals[4];
    int maxs[4];

    func_0023BDD0();
    vals[0] = TkMenuMainMes(0x16);
    vals[1] = TkMenuMainMes(0x17);
    vals[2] = TkMenuMainMes(0x18);
    maxs[0] = TkMenuMainHelp(0x16);
    maxs[1] = TkMenuMainHelp(0x17);
    maxs[2] = TkMenuMainHelp(0x18);
    FUNC_00237630(0, vals, maxs, 3, 2, D_0032628C);
    D_00694124 = 0;
    D_00694128 = 0;
}

int func_0023A960(int id)
{
    long r;

    r = func_002EAC30(*(u32 *)func_00228220(id & 0xFFF, D_00694118), func_0014B0A0()); /* DEBT(CAST): record starts with a u32 */
    r = func_002E9C38(r, 100);
    if (r == 0) {
        r = 1;
    }
    return r;
}

int func_0023A9C0(int a0)
{
    int *p = func_00228220(a0 & 0xFFF, D_00694118); /* DEBT(CAST): table returns void * */

    return func_00266DE8(D_00694110, *p);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23A450", func_0023AA00);

void func_0023AA90(Task *o)
{
    s32 *state;
    u16 held;
    u16 trig;
    int n;
    int q;
    int st;
    int d;

    d = o->ext[2];
    func_00220318();
    held = TOMenuGetControlPadRep();
    trig = TOMenuGetControlPadTrg();
    q = MsGetGIL() / d;
    n = q;
    if (n + o->ext[3] >= 100) {
        n = 99 - o->ext[3];
    }
    st = o->state;
    state = &o->state;
    /* DEBT(GOTO): state machine re-dispatches with goto (no loop alignment in the original) */
again:
    {
        switch (st) {
        case 0:
            *state = 1;
            return;
        case 1:
            st = 2;
            goto again;
        case 2:
            *state = 3;
        case 3:
            if (trig & 0x20) {
                st = 4;
                goto again;
            }
            if (trig & 0x40) {
                st = 6;
                goto again;
            }
            if (held & 0x4000) {
                if (o->x48 < 2) {
                    return;
                }
                PLAY_SE(0x80000001);
                o->x48 -= 10;
                if (o->x48 > 0) {
                    return;
                }
                o->x48 = 1;
                return;
            }
            if (held & 0x1000) {
                if (o->x48 >= n) {
                    return;
                }
                PLAY_SE(0x80000001);
                o->x48 += 10;
                if (n < o->x48) {
                    o->x48 = n;
                }
                return;
            }
            if (held & 0x8000) {
                if (o->x48 < 2) {
                    return;
                }
                PLAY_SE(0x80000001);
                o->x48 -= 1;
                return;
            }
            if (held & 0x2000) {
                if (o->x48 >= n) {
                    return;
                }
                PLAY_SE(0x80000001);
                o->x48 += 1;
            }
            return;
        case 4:
            o->b45 = 1;
            PLAY_SE(0x8000000E);
            MsSaveItemUse(o->ext[1], o->x48);
            MsPayGIL(o->x48 * o->ext[2]);
            st = 5;
            break;
        case 6:
            o->b45 = -1;
            PLAY_SE(0x80000004);
            st = 7;
            break;
        case 5:
        case 7:
        default:
            return;
        }
        *state = st;
    }
}

void func_0023ACD0(Task *t) {
    func_002492F0();
    func_002492F0();
    func_00225A38();
    func_00225920();
    func_00228240(D_003261E8.x, D_003261E8.y, t->ext[1], t->x48, t->x48 + t->ext[3], t->ext[2], t->ext[4]);
    func_00225B00();
}

int func_0023AD38(void) { return 1; }

Task *func_0023AD40(Task *src)
{
    Task *t = func_00243400();
    u16 *tbl = func_00228220(D_00694110, D_0069411C);

    t->b3E = 4;
    t->b36 = 3;
    t->ext[0] = (s32)src; /* DEBT(CAST): ext slots are typed s32 */
    t->x0C = (s32)func_0023AA90; /* DEBT(CAST): Task callbacks are typed s32 */
    t->x10 = (s32)func_0023ACD0;
    t->x14 = (s32)func_0023AD38;
    tbl += src->x48;
    t->ext[1] = tbl[1];
    t->ext[2] = func_0023A960(t->ext[1]);
    t->ext[3] = func_001BFE30(t->ext[1]);
    t->ext[4] = MsGetGIL();
    t->x48 = 1;
    D_0069412C = t;
    TkMenuMainRegistWindow(t);
    return t;
}

void func_0023AE10(void) {
    Task *t;

    if (D_0069412C) {
        D_0069412C->b41 = 1;
        t = D_0069412C;
        D_0069412C = 0;
        t->x10 = 0;
    }
}

void func_0023AE38(Task *o)
{
    s32 *state = &o->state;
    u16 held;
    u16 trig;
    int n;
    int st;

    func_00220318();
    held = TOMenuGetControlPadRep();
    trig = TOMenuGetControlPadTrg();
    n = o->ext[3];
    st = o->state;
    /* DEBT(GOTO): state machine re-dispatches with goto (no loop alignment in the original) */
again:
    {
        switch (st) {
        case 0:
            *state = 1;
            return;
        case 1:
            st = 2;
            goto again;
        case 2:
            *state = 3;
        case 3:
            if (trig & 0x20) {
                st = 4;
                goto again;
            }
            if (trig & 0x40) {
                st = 6;
                goto again;
            }
            if (held & 0x4000) {
                if (o->x48 < 2) {
                    return;
                }
                PLAY_SE(0x80000001);
                o->x48 -= 10;
                if (o->x48 > 0) {
                    return;
                }
                o->x48 = 1;
                return;
            }
            if (held & 0x1000) {
                if (o->x48 >= n) {
                    return;
                }
                PLAY_SE(0x80000001);
                o->x48 += 10;
                if (n < o->x48) {
                    o->x48 = n;
                }
                return;
            }
            if (held & 0x8000) {
                if (o->x48 < 2) {
                    return;
                }
                PLAY_SE(0x80000001);
                o->x48 -= 1;
                return;
            }
            if (held & 0x2000) {
                if (o->x48 >= n) {
                    return;
                }
                PLAY_SE(0x80000001);
                o->x48 += 1;
            }
            return;
        case 4:
            o->b45 = 1;
            PLAY_SE(0x8000000E);
            MsSaveItemUse(o->ext[1], -o->x48);
            MsPayGIL(o->x48 * -o->ext[2]);
            st = 5;
            break;
        case 6:
            o->b45 = -1;
            PLAY_SE(0x80000004);
            st = 7;
            break;
        case 5:
        case 7:
        default:
            return;
        }
        *state = st;
    }
}

void func_0023B040(Task *t) {
    int a, b; /* DEBT(ORDER): temporaries only steer load order */

    func_002492F0();
    func_002492F0();
    func_00225A38();
    func_00225920();
    a = -t->ext[2];
    b = t->ext[3] - t->x48;
    func_00228240(D_003261E8.x, D_003261E8.y, t->ext[1], t->x48, b, a, t->ext[4]);
    func_00225B00();
}

int func_0023B0B0(void) { return 1; }

Task *func_0023B0B8(Task *src)
{
    Pt16 *e = (Pt16 *)0x1D57300; /* DEBT(CAST): 4-byte table at a fixed address */
    Task *t;

    e = &e[src->x48];
    t = func_00243400();

    func_00228220(D_00694110, D_0069411C);
    t->b3E = 4;
    t->b36 = 3;
    t->ext[0] = (s32)src; /* DEBT(CAST): ext slots are typed s32 */
    t->x0C = (s32)func_0023AE38; /* DEBT(CAST): Task callbacks are typed s32 */
    t->x10 = (s32)func_0023B040;
    t->x14 = (s32)func_0023B0B0;
    t->ext[1] = e->x;
    t->ext[2] = func_0023A9C0(e->x);
    t->ext[3] = func_001BFE30(e->x);
    t->ext[4] = MsGetGIL();
    t->x48 = 1;
    D_00694130 = t;
    TkMenuMainRegistWindow(t);
    return t;
}

void func_0023B198(void) {
    Task *t;

    if (D_00694130) {
        D_00694130->b41 = 1;
        t = D_00694130;
        D_00694130 = 0;
        t->x10 = 0;
    }
}

void func_0023B1C0(Task *t)
{
    u16 *p;

    if (D_00326030->b45 > 0) {
        TkMenuCtrlSelFileWindow(t);
        p = func_00228220(D_00694110, D_0069411C);
        p += t->x48;
        TkMenuSetHelpMessage(TkMn2GetItemHelp(p[1]));
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23A450", func_0023B238);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23A450", func_0023B298);

void func_0023B3E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    s32 x;
    s32 i;
    s32 y;

    x = arg3 + D_003261D8.x;
    y = arg4 + D_003261D8.y;
    i = -1;
    do
    {
        func_0023B298(arg0, x, y, i + arg2, arg1, arg5);
        i += 1;
        graphicUiRemapY2();
        y += 0x20;
    } while (i < 0xB);
}

void func_0023B488(Task *t, int x, int y) {
    x += 0xC;
    y += 1;
    func_002270F8(x + D_003261D8.x, y + D_003261D8.y + ((t->x48 - t->x32) << 5), 0);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23A450", func_0023B4C8);

int func_0023B700(void) { return 1; }

Task *func_0023B708(void) {
    Task *temp_2;

    temp_2 = func_00243400();
    temp_2->b36 = temp_2->b3E = 3;
    temp_2->b42 = 1;
    temp_2->x48 = 0;
    temp_2->x32 = 0;
    temp_2->x34 = 0;
    temp_2->x0C = (s32) func_0023B1C0;
    temp_2->x10 = (s32) func_0023B4C8;
    temp_2->x14 = (s32) func_0023B700;
    temp_2->x30 = (s16) D_00694114;
    temp_2->b45 = -1;
    temp_2->b37 = 0;
    temp_2->x3A = 0xA;
    D_00694124 = temp_2;
    TkMenuMainRegistWindow(temp_2);
    func_00227480((s8 *) D_00572A70);
    return temp_2;
}

void func_0023B7B8(void)
{
    Task *t;

    if (D_00694124) {
        D_00694124->b41 = 1;
        t = D_00694124;
        t->b3E = 2;
        D_00694124 = 0;
        t->x10 = 0;
    }
    func_00227490(D_00572A70);
}

void func_0023B7F0(void) {
    if (D_00694124) {
        TkMenuRestartSelFileWindow(D_00694124);
    }
}

void func_0023B810(void *a)
{
    if (D_00326030->b45 > 0) {
        func_0022FCE0(a);
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23A450", func_0023B838);

void func_0023B940(int a, int b, int page, int x, int y)
{
    int i;
    int r = page * 2 - 1;
    int l = page * 2 - 2;

    y += D_00694138[1];
    for (i = 0; i < 12; i++) {
        func_0023B838(a, x + D_00694138[0], y, l, b);
        l += 2;
        func_0023B838(a, x + D_00694140, y, r, b);
        graphicUiRemapY2();
        y += 0x20;
        r += 2;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23A450", func_0023BA20);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23A450", func_0023BAA0);

int func_0023BC28(void) { return 1; }

int func_0023BC30(int a, int idx)
{
    SysEntry *e = SYS_TBL;

    e += idx;
    return e->b3;
}
Task *func_0023BC48(void)
{
    Task *t = func_00243400();

    func_002253E8(7);
    t->x48 = 0;
    t->x32 = 0;
    t->x34 = 0;
    t->x0C = (s32)func_0023B810; /* DEBT(CAST): Task callbacks are typed s32 */
    t->x10 = (s32)func_0023BAA0;
    t->x14 = (s32)func_0023BC28;
    t->x1C = (s32)func_0023BC30;
    t->b3E = 3;
    t->b36 = 3;
    t->b42 = 1;
    t->x30 = func_00224998();
    t->b45 = 0;
    t->b37 = 0;
    t->x3A = 10;
    D_00694128 = t;
    TkMenuMainRegistWindow(t);
    func_00227480(D_00572A78);
    return t;
}

void func_0023BD00(void) {
    Task *t;

    if (D_00694128) {
        D_00694128->b41 = 1;
        t = D_00694128;
        t->b3E = 2;
        D_00694128 = 0;
        t->x10 = 0;
        func_00227490((int)D_00572A78); /* DEBT(CAST): address passed as int */
    }
}

void func_0023BD40(void) {
    if (D_00694128) {
        func_002302E8(D_00694128);
    }
}

void func_0023BD60(void) {
}

void func_0023BD68(void)
{
    int n = MsGetGIL();

    func_002492F0();
    func_002492F0();
    func_00225A38();
    func_00225920();
    func_00227C88(D_003261D0[0], D_003261D0[1], n);
    func_00225B00();
}

int func_0023BDC8(void) { return 1; }

Task * func_0023BDD0(void)
{
    Task *t = func_00243400();

    t->x0C = (s32)func_0023BD60;
    t->x10 = (s32)func_0023BD68;
    t->x14 = (s32)func_0023BDC8;
    t->b3E = 0x2;
    t->b36 = 0x3;
    D_00694120 = t;
    TkMenuMainRegistWindow(t);
    return t;
}

void func_0023BE40(void) {
    Task *t;

    if (D_00694120) {
        D_00694120->b41 = 1;
        t = D_00694120;
        D_00694120 = 0;
        t->x10 = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_23A450", TkMenuCtrlWShop);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_23A450/rodata", jtbl_00572A80);

void func_0023C3E8(void) {
    func_002492F0();
    func_002492F0();
    func_00225A38();
    func_00225920();
    func_00225B00();
    func_0023C4B8();
}

void func_0023C428(void) { TkMn2GetIShopPos(); TkMn2GetWShopPos(); TkMn2GetStatusPos(); }

void func_0023C450(int a, int b) {
    D_00694110 = b;
    func_00227480((int)D_00572B08); /* DEBT(CAST): address passed as int */
}

void func_0023C468(void) {
    func_0023BE40();
    func_00237818();
    func_00227490((int)D_00572B08); /* DEBT(CAST): address passed as int */
    func_00227490((int)D_00572A78);
    func_00227490((int)D_00572A70);
}

void func_0023C4B0(void) {
}

void _m2c_func_0023C4B8_TODapsSetPos(int x, int y) __asm__("TODapsSetPos");
s32 _m2c_func_0023C4B8_func_0014B0A0(void) __asm__("func_0014B0A0");
extern s32 _m2c_func_0023C4B8_D_00326148 __asm__("D_00326148");
extern s32 _m2c_func_0023C4B8_D_00572B10 __asm__("D_00572B10");
extern s32 _m2c_func_0023C4B8_D_00572B18 __asm__("D_00572B18");
extern s32 _m2c_func_0023C4B8_D_00572B28 __asm__("D_00572B28");
extern s32 _m2c_func_0023C4B8_D_00572B38 __asm__("D_00572B38");
extern s32 _m2c_func_0023C4B8_D_00572B48 __asm__("D_00572B48");
extern s32 _m2c_func_0023C4B8_D_00572B58 __asm__("D_00572B58");
extern s32 _m2c_func_0023C4B8_D_00572B68 __asm__("D_00572B68");
extern s32 _m2c_func_0023C4B8_D_00572B78 __asm__("D_00572B78");
extern s32 _m2c_func_0023C4B8_D_00572B88 __asm__("D_00572B88");
extern s32 _m2c_func_0023C4B8_D_00572B98 __asm__("D_00572B98");
extern s32 _m2c_func_0023C4B8_D_00572BA0 __asm__("D_00572BA0");
extern s32 _m2c_func_0023C4B8_D_00572BA8 __asm__("D_00572BA8");
extern s32 _m2c_func_0023C4B8_D_00572BB0 __asm__("D_00572BB0");
extern s32 _m2c_func_0023C4B8_D_00572BB8 __asm__("D_00572BB8");
extern s32 _m2c_func_0023C4B8_D_00572BC0 __asm__("D_00572BC0");
void func_0023C4B8(void) {
    s32 temp_17;
    s32 temp_18;
    s32 temp_19;

    temp_17 = func_00220318();
    temp_18 = TOMenuGetControlPadRep();
    temp_19 = TOMenuGetControlPadTrg();
    if (func_0020D540() != 0) {
        _m2c_func_0023C4B8_TODapsSetPos(0x138, 0xB0);
        TODapsPrintf(&_m2c_func_0023C4B8_D_00572B10);
        TODapsPrintf(&_m2c_func_0023C4B8_D_00572B18, func_00224930());
        TODapsPrintf(&_m2c_func_0023C4B8_D_00572B28, func_00243450());
        TODapsPrintf(&_m2c_func_0023C4B8_D_00572B38, func_00242040());
        __asm__ volatile("" : : : "memory");
        TODapsPrintf(&_m2c_func_0023C4B8_D_00572B48, D_00694110);
        TODapsPrintf(&_m2c_func_0023C4B8_D_00572B58, _m2c_func_0023C4B8_func_0014B0A0());
        TODapsPrintf(&_m2c_func_0023C4B8_D_00572B68, temp_17);
        TODapsPrintf(&_m2c_func_0023C4B8_D_00572B78, temp_18);
        TODapsPrintf(&_m2c_func_0023C4B8_D_00572B88, temp_19);
        __asm__ volatile("" : : : "memory");
        func_0023A1F8(&_m2c_func_0023C4B8_D_00572B98, D_00326030);
        func_0023A1F8(&_m2c_func_0023C4B8_D_00572BA0, D_00694124);
        func_0023A1F8(&_m2c_func_0023C4B8_D_00572BA8, D_00694128);
        func_0023A1F8(&_m2c_func_0023C4B8_D_00572BB0, D_0069412C);
        func_0023A1F8(&_m2c_func_0023C4B8_D_00572BB8, D_00694130);
        func_0023A250(&_m2c_func_0023C4B8_D_00572BC0, &_m2c_func_0023C4B8_D_00326148);
    }
}
