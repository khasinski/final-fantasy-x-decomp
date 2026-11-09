/* tu_263 0x237888-0x23a450: low; ~Tk (config/tu_map.tsv) */
#define func_0023A298 _hdr_func_0023A298
#define func_00238718 _hdr_func_00238718
#define func_00238C48 _hdr_func_00238C48
#include "common.h"
#include "ffx/r5.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/u4.h"
#include "ffx/v5.h"
#include "ffx/s5.h"
#include "ffx/s6.h"
#include "ffx/u3.h"
#undef func_00238718
#undef func_00238C48
#undef func_0023A298

void func_00237888(void)
{
    int vals[4];
    int maxs[4];

    vals[0] = TkMenuMainMes(0x16);
    vals[1] = TkMenuMainMes(0x17);
    vals[2] = TkMenuMainMes(0x18);
    maxs[0] = TkMenuMainHelp(0x16);
    maxs[1] = TkMenuMainHelp(0x17);
    maxs[2] = TkMenuMainHelp(0x18);
    D_00693FD0 = 0;
    D_00693FD4 = 0;
    FUNC_00237630(0, vals, maxs, 3, 2, D_0032628C);
    func_002397D8();
}

int TkMn2GetWShopPos(void) /* DEBT(TYPE): declared int in funcs.h, no value returned */
{
    func_002273A0(D_00572420, D_003260B0);
    func_002273A0(D_00572430, D_00326108);
    func_002273A0(D_00572440, &D_003260C0);
    func_002273A0(D_00572450, D_003260C8);
    func_002273A0(D_00572460, D_003260E8);
    func_002273A0(D_00572470, D_00326078);
    func_002273A0(D_00572480, D_00326088);
    func_00227460(D_00572490, &D_00326110);
    func_00227460(D_005724A0, D_00326070);
    func_00227460(D_005724B0, &D_003260B8);
    func_00227460(D_005724C0, D_00326080);
    func_00227460(D_005724D0, D_00326090);
    func_00227460(D_005724E0, D_00694098);
    func_00227460(D_005724F0, D_00326100);
    func_00227460(D_00572500, D_003260E0);
    func_00227460(D_00572510, D_003260D0);
    func_00227460(D_00572520, D_003260D8);
    func_00227460(D_00572530, D_003260F0);
    func_00227460(D_00572540, D_003260F8);
    D_00694094 = TkMn2SeqGetColor(D_00572550);
    D_0069409C = TkMn2SeqGetColor(D_00572560);
    D_006940A0 = TkMn2SeqGetColor(D_00572570);
    D_00326064 = TkMn2SeqGetColor(D_00572580);
    D_00326068 = TkMn2SeqGetColor(D_00572590);
    TkMn2GetCommonPlate(&D_00326098, D_00572420, D_00572580, D_00572590, 0xd8, 0xd9);
    TkMn2GetCommonPlate(&D_00326118, D_00572440, D_005725A0, D_005725B0, 0, 0);
    TkMn2GetCommonPlate(&D_00326130, D_00572450, D_00572550, D_00572550, 0, 0);
    D_003260C0.y += 0x30;
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_237888", func_00237BE0);

int func_00237C88(int a0) {
    s32 buf;
    Unk1BFED8 *p = MsGetSaveWeapon(a0, &buf);
    int b4 = p->b4;
    int b5 = p->b5;
    int old1C = TkMenuGetHP(b4);
    int old20 = TkMenuGetMP(b4);
    int b2D2E;
    int r = 0;

    if (b5 != 0) {
        b2D2E = TkMenuGetArmor(b4);
    } else {
        b2D2E = TkMenuGetWeapon(b4);
    }
    MsEquipSaveWeapon(b4, b5, a0);
    TkMsSetSaveParam(b4);
    if (TkMenuGetHP(b4) < old1C) {
        r |= 1;
    }
    if (TkMenuGetMP(b4) < old20) {
        r |= 2;
    }
    MsEquipSaveWeapon(b4, b5, b2D2E);
    TkMsSetSaveParam(b4);
    TkMenuSetHP(b4, old1C);
    TkMenuSetMP(b4, old20);
    return r;
}

void func_00237D88(int a0) {
    s32 buf;
    Unk1BFED8 *p = MsGetSaveWeapon(a0, &buf);
    int b5 = p->b5;
    int b4 = p->b4;

    if (b5 != 0) {
        TkMenuGetArmor(b4);
    } else {
        TkMenuGetWeapon(b4);
    }
    MsEquipSaveWeapon(b4, b5, a0);
    TkMsSetSaveParam(b4);
}

void *func_00237E00(int a)
{
    return func_00228220(a & 0xFFF, D_00694090);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_237888", func_00237E28);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_237888", func_00237F28);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_237888", func_002381F0);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_237888", func_002382D0);

/* DEBT(FAKE) */
s32 func_002383F8(void) {
    register s32 v0 __asm__("$2");
    s32 temp_16;

    v0 = D_00693FF4;
    if (v0 == 0) {
        __asm__ volatile("" : "=r"(v0));
        return 0;
    }
    temp_16 = func_002381F0();
    return MsGetGIL() >= temp_16;
}

void func_00238440(Task *t)
{
    D_00694084 = -1;
    if (D_00326030->b45 > 0 && D_00326030->x48 != 2) {
        TkMenuCtrlSelFileWindow(t);
        if (t->x48 >= 0) {
            U4IdList *l = func_00228220(D_00694080, D_0069408C);

            D_00694084 = ((u8 *)func_00237E00(l->ids[t->x48]))[4]; /* DEBT(CAST): record with a byte at 4 */
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_237888", func_002384D8);

void func_00238630(int a, int b, int c, int x, int y, int d)
{
    int i;

    x += D_003260B8.x;
    y += D_003260B8.y;
    for (i = -1; i < 10; i++) {
        func_002384D8(a, x, y, i + c, b, d);
        graphicUiRemapY2();
        y += 32;
    }
}

void func_002386D8(Task *t, int x, int y) {
    x += 0xC;
    y += 1;
    func_002270F8(x + D_003260B8.x, y + D_003260B8.y + ((t->x48 - t->x32) << 5), 0);
}

void _m2c_func_00238718_func_00225908() __asm__("func_00225908");
void _m2c_func_00238718_func_00225920() __asm__("func_00225920");
void _m2c_func_00238718_func_00225A38() __asm__("func_00225A38");
void _m2c_func_00238718_func_00225B00() __asm__("func_00225B00");
void _m2c_func_00238718_func_00225E88(s16, s16, s16, s16, s16, u16, u16) __asm__("func_00225E88");
void _m2c_func_00238718_func_002274A0(s16, s32, s32, s16) __asm__("func_002274A0");
s32 _m2c_func_00238718_func_00228220(s32, s32) __asm__("func_00228220");
void _m2c_func_00238718_func_00238630(void *, s32, s16, s32, s32, s32) __asm__("func_00238630");
void _m2c_func_00238718_func_002386D8(void *, s32, s32) __asm__("func_002386D8");
void _m2c_func_00238718_func_002492F0() __asm__("func_002492F0");
extern s16 _m2c_func_00238718_D_003260BA __asm__("D_003260BA");
void func_00238718(Task *arg0) {
    s16 temp_17;
    s32 temp_18;
    s32 temp_2;

    _m2c_func_00238718_func_002492F0();
    _m2c_func_00238718_func_002492F0();
    _m2c_func_00238718_func_00225A38();
    _m2c_func_00238718_func_00225920();
    temp_18 = _m2c_func_00238718_func_00228220(D_00694080, D_0069408C);
    temp_17 = _m2c_func_00238718_D_003260BA;
    if (arg0->x32 == arg0->x34) {
        _m2c_func_00238718_func_002274A0(temp_17, 0x120, 0, arg0->x46);
        _m2c_func_00238718_func_00238630(arg0, 0, arg0->x32, 0, -0x20, temp_18);
    } else {
        _m2c_func_00238718_func_002274A0(temp_17, 0x120, 1, arg0->x46);
        _m2c_func_00238718_func_00238630(arg0, 1, arg0->x32, 0, -0x20, temp_18);
        _m2c_func_00238718_func_002274A0(temp_17, 0x120, 2, arg0->x46);
        temp_2 = -(arg0->x46 * 0x120);
        _m2c_func_00238718_func_00238630(arg0, 2, arg0->x34, 0, (((s32)temp_2 / 4096)) - 0x20, temp_18);
    }
    _m2c_func_00238718_func_00225908();
    if (D_00326030->b45 > 0) {
        _m2c_func_00238718_func_002386D8(arg0, 0, 0);
    }
    _m2c_func_00238718_func_00225E88(D_00326108[0], D_00326108[1], D_00326108[2], D_00326108[3], arg0->x32, arg0->x3A, arg0->x30);
    _m2c_func_00238718_func_00225B00();
}

int func_00238898(void) { return 1; }

Task *func_002388A0(void)
{
    Task *t = func_00243400();

    t->b3E = 3;
    t->b42 = 1;
    t->x48 = 0;
    t->x32 = 0;
    t->x34 = 0;
    t->x0C = (s32)func_00238440; /* DEBT(CAST): Task callbacks are typed s32 */
    t->x10 = (s32)func_00238718;
    t->x14 = (s32)func_00238898;
    t->x30 = D_00693FF0;
    t->b37 = 0;
    t->b45 = -1;
    t->state = 0;
    t->x3A = 9;
    D_00693FD0 = t;
    TkMenuMainRegistWindow(t);
    return t;
}

void func_00238940(void) {
    Task *t;

    if (D_00693FD0) {
        D_00693FD0->b41 = 1;
        t = D_00693FD0;
        D_00693FD0 = 0;
        t->x10 = 0;
    }
}

void func_00238968(Task *t)
{
    s32 buf[4];
    Unk1BFED8 *r;
    SysEntry *tbl;

    D_00694084 = -1;
    if (D_00326030->b45 > 0 && D_00326030->x48 != 2) {
        TkMenuCtrlSelFileWindow(t);
        tbl = SYS_TBL;
        if (t->x48 >= 0) {
            tbl += t->x48;
            if (tbl->h0 != 0) {
                r = MsGetSaveWeapon(tbl->h0, buf);
                if (r->b2 != 0) {
                    D_00694084 = r->b4;
                }
            }
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_237888", func_00238A08);

void func_00238B60(int a, int b, int c, int x, int y, int d)
{
    int i;

    x += D_003260B8.x;
    y += D_003260B8.y;
    for (i = -1; i < 10; i++) {
        func_00238A08(a, x, y, i + c, b, d);
        graphicUiRemapY2();
        y += 32;
    }
}

void func_00238C08(Task *t, int x, int y) {
    x += 0xC;
    y += 1;
    func_002270F8(x + D_003260B8.x, y + D_003260B8.y + ((t->x48 - t->x32) << 5), 0);
}

void _m2c_func_00238C48_func_00225908() __asm__("func_00225908");
void _m2c_func_00238C48_func_00225920() __asm__("func_00225920");
void _m2c_func_00238C48_func_00225A38() __asm__("func_00225A38");
void _m2c_func_00238C48_func_00225B00() __asm__("func_00225B00");
void _m2c_func_00238C48_func_00225E88(s16, s16, s16, s16, s16, u16, u16) __asm__("func_00225E88");
void _m2c_func_00238C48_func_002274A0(s16, s32, s32, s16) __asm__("func_002274A0");
s32 _m2c_func_00238C48_func_00228220(s32, s32) __asm__("func_00228220");
void _m2c_func_00238C48_func_00238B60(void *, s32, s16, s32, s32, s32) __asm__("func_00238B60");
void _m2c_func_00238C48_func_00238C08(void *, s32, s32) __asm__("func_00238C08");
void _m2c_func_00238C48_func_002492F0() __asm__("func_002492F0");
extern s16 _m2c_func_00238C48_D_003260BA __asm__("D_003260BA");
void func_00238C48(Task *arg0) {
    s16 temp_17;
    s32 temp_18;
    s32 temp_2;

    _m2c_func_00238C48_func_002492F0();
    _m2c_func_00238C48_func_002492F0();
    _m2c_func_00238C48_func_00225A38();
    _m2c_func_00238C48_func_00225920();
    temp_18 = _m2c_func_00238C48_func_00228220(D_00694080, D_0069408C);
    temp_17 = _m2c_func_00238C48_D_003260BA;
    if (arg0->x32 == arg0->x34) {
        _m2c_func_00238C48_func_002274A0(temp_17, 0x120, 0, arg0->x46);
        _m2c_func_00238C48_func_00238B60(arg0, 0, arg0->x32, 0, -0x20, temp_18);
    } else {
        _m2c_func_00238C48_func_002274A0(temp_17, 0x120, 1, arg0->x46);
        _m2c_func_00238C48_func_00238B60(arg0, 1, arg0->x32, 0, -0x20, temp_18);
        _m2c_func_00238C48_func_002274A0(temp_17, 0x120, 2, arg0->x46);
        temp_2 = -(arg0->x46 * 0x120);
        _m2c_func_00238C48_func_00238B60(arg0, 2, arg0->x34, 0, (((s32)temp_2 / 4096)) - 0x20, temp_18);
    }
    _m2c_func_00238C48_func_00225908();
    if (D_00326030->b45 > 0) {
        _m2c_func_00238C48_func_00238C08(arg0, 0, 0);
    }
    _m2c_func_00238C48_func_00225E88(D_00326108[0], D_00326108[1], D_00326108[2], D_00326108[3], arg0->x32, arg0->x3A, arg0->x30);
    _m2c_func_00238C48_func_00225B00();
}

int func_00238DC8(void) { return 1; }

int func_00238DD0(int a, int idx)
{
    SysEntry *e = SYS_TBL;

    e += idx;
    return e->h0 != 0;
}
void func_00238DF0(void)
{
    int three;
    int one;
    Task *t = func_00243400();

    three = 3; /* DEBT(FAKE): early constant loads */
    t->x48 = 0;
    one = 1;
    t->x32 = 0;
    t->x34 = 0;
    t->x0C = (s32)func_00238968; /* DEBT(CAST): Task callbacks are typed s32 */
    t->x10 = (s32)func_00238C48;
    t->x14 = (s32)func_00238DC8;
    t->x1C = (s32)func_00238DD0;
    t->b3E = three;
    t->b42 = one;
    t->x30 = func_002249A8();
    t->b37 = 0;
    t->b45 = -1;
    t->state = 0;
    t->x3A = 9;
    D_00693FD4 = t;
    TkMenuMainRegistWindow(t);
    func_00237BE0(t);
}

void func_00238E98(void) {
    Task *t;

    if (D_00693FD4) {
        D_00693FD4->b41 = 1;
        t = D_00693FD4;
        D_00693FD4 = 0;
        t->x10 = 0;
    }
}

void func_00238EC0(Task *o)
{
    s32 *state = &o->state;
    Task *t;
    Task *cur;
    int a, b;
    int st;
    int n;
    int q;
    int r;
    s16 shown;

    n = o->ext[2];
    func_00220318();
    TOMenuGetControlPadRep();
    TOMenuGetControlPadTrg();
    q = MsGetGIL() / n;
    st = o->state;
    /* DEBT(GOTO): state machine re-dispatches with goto (no loop alignment in the original) */
again:
    {
        switch (st) {
        case 0:
            *state = 1;
        case 1:
            st = 2;
            goto again;
        case 2:
            a = TkMenuMainMes(0x1B);
            b = TkMenuMainMes(0x1C);
            func_00236940(a, b, TkMenuMainMes(0x1D));
            t = TOMenuGetYesNoWindow();
            t->b37 = 0;
            t->b3E = 5;
            r = func_00236228(t);
            r = -r / 2 - 0xD4;
            t->ext[2] = r + D_003260C2;
            *state = 3;
        case 3:
            cur = TOMenuGetYesNoWindow();
            if (cur->b45 < 0) {
                TOMenuCloseYesNoWindow();
                st = 6;
                goto again;
            }
            if (cur->b45 == 0) {
                return;
            }
            shown = cur->x48;
            TOMenuCloseYesNoWindow();
            st = 4;
            if (shown != 0) {
                SndSepPlaySimple(0x80000001);
                st = 6;
            }
            goto again;
        case 4:
            SndSepPlaySimple(0x8000000E);
            D_00693FF8 = func_001C0598((Unk1BFED8 *)o->ext[1]);
            MsPayGIL(o->ext[2]);
            o->b45 = 1;
            *state = 5;
            return;
        case 6:
            o->b45 = -1;
            *state = 7;
            return;
        case 5:
        case 7:
        default:
            return;
        }
    }
}

void func_00239070(Task *t) {
    func_002492F0();
    func_002492F0();
    func_00225A38();
    func_00225920();
    TkMn2WeaponBuySellWindow(D_003260C0.x, D_003260C0.y, t->ext[1], t->ext[2], t->ext[4]);
    func_00225B00();
}

int func_002390D0(void) { return 1; }

Task *func_002390D8(Task *src)
{
    Task *t = func_00243400();
    u16 *tbl = func_00228220(D_00694080, D_0069408C);

    t->x0C = (s32)func_00238EC0; /* DEBT(CAST): Task callbacks are typed s32 */
    t->x10 = (s32)func_00239070;
    t->b3E = 4;
    t->ext[0] = (s32)src; /* DEBT(CAST): ext slots are typed s32 */
    t->x14 = (s32)func_002390D0;
    tbl += src->x48;
    t->ext[1] = (s32)func_00237E00(tbl[1]);
    t->ext[2] = func_002381F0(t->ext[1]);
    t->ext[3] = 1;
    t->ext[4] = MsGetGIL();
    t->x48 = 1;
    D_00693FD8 = t;
    TkMenuMainRegistWindow(t);
    return t;
}

void func_002391A0(void) {
    Task *t;

    if (D_00693FD8) {
        D_00693FD8->b41 = 1;
        t = D_00693FD8;
        D_00693FD8 = 0;
        t->x10 = 0;
    }
}

void func_002391C8(Task *o)
{
    s32 *state = &o->state;
    s32 buf;
    Task *t;
    Task *cur;
    int a, b;
    int st;
    int r;
    s16 shown;

    func_00220318();
    TOMenuGetControlPadRep();
    TOMenuGetControlPadTrg();
    st = o->state;
    for (;;) {
        switch (st) {
        case 0:
            *state = 1;
            return;
        case 1:
            st = 2;
            continue;
        case 2:
            MsGetSaveWeapon(o->ext[5], &buf);
            func_002F072C(D_00694000, (char *)buf);
            TkMn2SetMacroParam(0, 0, (int)D_00694000);
            a = TkMenuMainMes(0x29);
            b = TkMenuMainMes(0x1C);
            func_00236940(a, b, TkMenuMainMes(0x1D));
            t = TOMenuGetYesNoWindow();
            t->b37 = 0;
            t->b3E = 5;
            r = func_00236228(t);
            r = -r / 2 - 0xD4;
            t->ext[2] = r + D_003260C2;
            *state = 3;
        case 3:
            cur = TOMenuGetYesNoWindow();
            if (cur->b45 < 0) {
                TOMenuCloseYesNoWindow();
                st = 6;
                continue;
            }
            if (cur->b45 == 0) {
                return;
            }
            shown = cur->x48;
            TOMenuCloseYesNoWindow();
            st = 4;
            if (shown != 0) {
                SndSepPlaySimple(0x80000001);
                st = 6;
            }
            continue;
        case 4:
            o->b45 = 1;
            *state = 5;
            return;
        case 6:
            o->b45 = -1;
            *state = 7;
            return;
        case 5:
        case 7:
        default:
            return;
        }
    }
}

void func_00239370(Task *t) {
    func_002492F0();
    func_002492F0();
    func_00225A38();
    func_00225920();
    TkMn2WeaponBuySellWindow(D_003260C0.x, D_003260C0.y, t->ext[1], -t->ext[2], t->ext[4]);
    func_00225B00();
}

int func_002393D0(void) { return 1; }

Task *func_002393D8(Task *src)
{
    Task *t = func_00243400();
    s32 pos;
    int id;

    func_00228220(D_00694080, D_0069408C);
    id = SYS_TBL[src->x48].h0;
    t->ext[0] = (s32)src; /* DEBT(CAST): ext slots are typed s32 */
    t->x0C = (s32)func_002391C8; /* DEBT(CAST): Task callbacks are typed s32 */
    t->x10 = (s32)func_00239370;
    t->x14 = (s32)func_002393D0;
    t->b3E = 4;
    t->ext[1] = (s32)MsGetSaveWeapon(id, &pos);
    t->ext[2] = func_002382D0(t->ext[1]);
    t->ext[3] = 1;
    t->ext[4] = MsGetGIL();
    t->ext[5] = id;
    t->x48 = 1;
    D_00693FDC = t;
    TkMenuMainRegistWindow(t);
    return t;
}

void func_002394C0(void) {
    Task *t;

    if (D_00693FDC) {
        D_00693FDC->b41 = 1;
        t = D_00693FDC;
        D_00693FDC = 0;
        t->x10 = 0;
    }
}

void func_002394E8(void) { func_002253E8(0x13); }

void func_002394F0(void) { func_002253E8(0x15); }

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_237888", func_002394F8);

void func_002395F8(void)
{
    Task *t;

    if (D_00693FD0 != 0) {
        ((int (*)(Task *))TkMenuRestartSelFileWindow)(D_00693FD0); /* DEBT(CAST): the original call site sees an int-returning declaration */
        t = D_00693FD0;
        t->state = 0;
        t->b45 = 0;
    }
}

void func_00239638(void)
{
    if (D_00693FD4 != 0) {
        if (D_00693FD4->x48 >= (u16)D_00693FD4->x30) {
            D_00693FD4->x48 = (u16)D_00693FD4->x30 - 1;
        }
        if (D_00693FD4->x48 < D_00693FD4->x32) {
            D_00693FD4->x32 = D_00693FD4->x48;
        }
        if (D_00693FD4->x48 >= D_00693FD4->x32 + (u16)D_00693FD4->x3A) {
            D_00693FD4->x32 = D_00693FD4->x48 - (u16)D_00693FD4->x3A - 1;
            if (D_00693FD4->x32 < 0) {
                D_00693FD4->x32 = 0;
            }
        }
        D_00693FD4->x34 = D_00693FD4->x32;
        ((int (*)(Task *))TkMenuRestartSelFileWindow)(D_00693FD4);
        D_00693FD4->state = 0;
        D_00693FD4->b45 = 0;
    }
}

void func_002396F0(void) {
}

void func_002396F8(void)
{
    int n = MsGetGIL();

    func_002492F0();
    func_002492F0();
    func_00225A38();
    ((void (*)(void))func_00225920)(); /* DEBT(CAST): the original call site sees a void declaration */
    func_00226018(D_00326110.x, D_00326110.y, D_00694084);
    if (D_00693FD0 != 0) {
        func_00237F28(D_00693FD0, 1);
    } else if (D_00693FD4 != 0) {
        func_00237F28(D_00693FD4, 0);
    }
    func_00227C88(D_003261D0[0], D_003261D0[1], n);
    func_00225B00();
}

int func_002397A8(void) { return 1; }

void func_002397B0(void) {
    Task *t;

    if (D_00693FE0) {
        D_00693FE0->b41 = 1;
        t = D_00693FE0;
        D_00693FE0 = 0;
        t->x10 = 0;
    }
}

Task *func_002397D8(void) {
    Task *t = func_00243400();

    t->b3E = 1;
    t->x0C = (s32)func_002396F0; /* DEBT(CAST): Task callbacks are typed s32 */
    t->x10 = (s32)func_002396F8;
    t->x14 = (s32)func_002397A8;
    D_00693FE0 = t;
    TkMenuMainRegistWindow(t);
    return t;
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_237888", func_00239840);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_237888/rodata", jtbl_00572610);

void func_0023A110(void) {
    func_002492F0();
    func_002492F0();
    func_00225A38();
    func_00225920();
    func_00225B00();
    func_0023A298();
}

void func_0023A150(void) { TkMn2GetIShopPos(); TkMn2GetWShopPos(); TkMn2GetStatusPos(); }

void func_0023A178(int a, int b) {
    D_00694080 = b;
    D_00694084 = -1;
    func_00227480(D_005726A8);
    func_00227480(D_005726B0);
}

void func_0023A1B8(void) {
    func_002397B0();
    TkMsSetSaveParamAll();
    func_00227490(D_005726A8);
    func_00227490(D_005726B0);
}

void func_0023A1F0(void) {
}

void func_0023A1F8(int a, Task *t)
{
    char buf[32];
    char *s;

    if (t != 0) {
        func_002F0008(buf, D_005726B8, t->state);
        s = buf;
    } else {
        s = D_005726C0;
    }
    TODapsPrintf(D_005726C8, a, s);
}

void func_0023A250(int a0, Sub1C *a1)
{
    char buf[0x20];

    func_002F0008(buf, D_005726B8, a1->f1C);
    TODapsPrintf(D_005726C8, a0, buf);
}

void _m2c_func_0023A298_TODapsSetPos(int x, int y) __asm__("TODapsSetPos");
s32 _m2c_func_0023A298_func_0014B0A0(void) __asm__("func_0014B0A0");
extern s32 _m2c_func_0023A298_D_00326040 __asm__("D_00326040");
extern s32 _m2c_func_0023A298_D_005726D0 __asm__("D_005726D0");
extern s32 _m2c_func_0023A298_D_005726D8 __asm__("D_005726D8");
extern s32 _m2c_func_0023A298_D_005726E8 __asm__("D_005726E8");
extern s32 _m2c_func_0023A298_D_005726F8 __asm__("D_005726F8");
extern s32 _m2c_func_0023A298_D_00572708 __asm__("D_00572708");
extern s32 _m2c_func_0023A298_D_00572718 __asm__("D_00572718");
extern s32 _m2c_func_0023A298_D_00572728 __asm__("D_00572728");
extern s32 _m2c_func_0023A298_D_00572738 __asm__("D_00572738");
extern s32 _m2c_func_0023A298_D_00572748 __asm__("D_00572748");
extern s32 _m2c_func_0023A298_D_00572758 __asm__("D_00572758");
extern s32 _m2c_func_0023A298_D_00572760 __asm__("D_00572760");
extern s32 _m2c_func_0023A298_D_00572768 __asm__("D_00572768");
extern s32 _m2c_func_0023A298_D_00572770 __asm__("D_00572770");
extern s32 _m2c_func_0023A298_D_00572778 __asm__("D_00572778");
extern s32 _m2c_func_0023A298_D_00572780 __asm__("D_00572780");
extern s32 _m2c_func_0023A298_D_00572788 __asm__("D_00572788");
void func_0023A298(void) {
    s32 temp_17;
    s32 temp_18;
    s32 temp_19;

    temp_17 = func_00220318();
    temp_18 = TOMenuGetControlPadRep();
    temp_19 = TOMenuGetControlPadTrg();
    if (func_0020D540() != 0) {
        _m2c_func_0023A298_TODapsSetPos(0x138, 0xB0);
        TODapsPrintf(&_m2c_func_0023A298_D_005726D0);
        TODapsPrintf(&_m2c_func_0023A298_D_005726D8, func_00224930());
        TODapsPrintf(&_m2c_func_0023A298_D_005726E8, func_00243450());
        TODapsPrintf(&_m2c_func_0023A298_D_005726F8, func_00242040());
        __asm__ volatile("" : : : "memory");
        TODapsPrintf(&_m2c_func_0023A298_D_00572708, D_00694080);
        TODapsPrintf(&_m2c_func_0023A298_D_00572718, _m2c_func_0023A298_func_0014B0A0());
        TODapsPrintf(&_m2c_func_0023A298_D_00572728, temp_17);
        TODapsPrintf(&_m2c_func_0023A298_D_00572738, temp_18);
        TODapsPrintf(&_m2c_func_0023A298_D_00572748, temp_19);
        __asm__ volatile("" : : : "memory");
        func_0023A1F8(&_m2c_func_0023A298_D_00572758, D_00326030);
        func_0023A1F8(&_m2c_func_0023A298_D_00572760, D_00693FD0);
        func_0023A1F8(&_m2c_func_0023A298_D_00572768, D_00693FD4);
        func_0023A1F8(&_m2c_func_0023A298_D_00572770, D_00693FD8);
        func_0023A1F8(&_m2c_func_0023A298_D_00572778, D_00693FDC);
        func_0023A1F8(&_m2c_func_0023A298_D_00572780, D_00693FE0);
        func_0023A250(&_m2c_func_0023A298_D_00572788, &_m2c_func_0023A298_D_00326040);
    }
}
