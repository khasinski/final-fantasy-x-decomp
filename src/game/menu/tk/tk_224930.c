/* tu_250 0x224930-0x226bf0: low; ~Tk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r5.h"
#include "ffx/q5.h"
#include "ffx/w7.h"
#include "ffx/u3.h"
#include "ffx/v5.h"
#include "ffx/g3.h"
#include "ffx/u4.h"

s32 func_00224930(void)
{
    return D_00693848;
}

s32 func_00224940(void)
{
    return D_00693854;
}

int func_00224950(int a0, int a1) { return ((a0 << 1) * (a1 + 2)) / 4; }

int func_00224978(int a0, int a1) { return a0 + a0 * a1 / 32; }

s32 func_00224998(void)
{
    return D_00693858;
}

s32 func_002249A8(void)
{
    return D_0069385C;
}

int func_002249B8(R5ChoiceList *choices)
{
    u16 value = choices->entries[choices->selection - 1];
    int result = 0;

    /* DEBT(ORDER): accumulate the zero-entry flag before the 0xFF sentinel check. */
    if (value == 0) {
        result |= 1;
    }
    if (value == 0xFF) {
        result = 1;
    }
    return result;
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_224930", func_002249E8);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_224930/rodata", jtbl_00571320);

void func_002253E8(int a0) { func_002249E8(a0, 0); }

void func_002253F0(int a0, int a1) { func_002249E8(a0, a1); }

void func_002253F8(s32 a, s32 b, s32 c, s32 d)
{
    D_003257E8[0] = a;
    D_003257F0[0] = b;
    D_003257F8[0] = c;
    D_00325800[0] = d;
}

void func_00225420(void)
{
    int i;

    for (i = 1; i > 0; i--) {
        D_003257E8[i] = D_003257E8[i - 1];
        D_003257F0[i] = D_003257F0[i - 1];
        D_003257F8[i] = D_003257F8[i - 1];
        D_00325800[i] = D_00325800[i - 1];
    }
}

void func_00225498(void)
{
    int i;

    for (i = 0; i < 1; i++) {
        D_003257E8[i] = D_003257E8[i + 1];
        D_003257F0[i] = D_003257F0[i + 1];
        D_003257F8[i] = D_003257F8[i + 1];
        D_00325800[i] = D_00325800[i + 1];
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_224930", func_00225500);

u8 TkMn2GetOverDriveId(int idx) { return MsGetSavePlayerPtr(idx)->b38; }

void func_00225620(int idx, int v) { MsGetSavePlayerPtr(idx)->b38 = v; }

s32 func_00225648(int idx) { return MsGetSavePlayerPtr(idx)->v88; }

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_224930", func_00225668);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_224930", func_00225718);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_224930", func_00225800);

void func_00225908(void) { func_00225800(0, 0, 0x1FF, 0x19F); }

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_224930", func_00225920);

void func_002259B8(void)
{
    CmdRec *p = D_0069384C;

    p->b3 = 0x70;
    D_0069384C = p + 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0;
    p->w0 = 0;
}

void func_002259E8(int a0) {
    u32 *p = func_002DB6D8(1);

    *p |= 0x40;
    func_002F8660(0);
    func_002DBA28(p, a0);
}

void func_00225A38(void) { func_00124F08(); }

void func_00225A40(int a)
{
    u32 used = (u32)D_0069384C - (u32)D_00693850; /* DEBT(TYPE): high-water marks kept as addresses */
    u32 cur;

    if ((u32)D_00693854 < used) {
        D_00693854 = used;
    }
    cur = (u32)D_0069384C;
    if ((u32)D_00693848 < cur) {
        D_00693848 = cur;
    }
    if (a != 0) {
        func_00225908();
    }
    func_002259B8();
    func_00225A38();
    if ((u32)D_0069384C < 0x2000000) {
        func_002259E8((int)D_00693850);
    } else {
        func_002EF240(D_00571378);
    }
    func_00225920();
}

void func_00225AF8(void) { func_00225A40(1); }

void func_00225B00(void) {
    func_00225A40(1);
    func_00225A38();
}

void graphicUiRemapY2(void) {
    func_00225A40(0);
    func_00225A38();
}

void func_00225B40(int a, int b, int c)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_00200040(p + 1, c, a, b, D_003257E8[0], D_003257F0[0], D_003257F8[0], D_00325800[0]);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00225BE8(int a, int x, int y, int v)
{
    CmdRec *p = D_0069384C;
    u32 n;

    func_00201D48(a, x, y, v);
    D_0069384C = p + 1;
    D_0069384C = func_00201F50(a, p + 1);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00225C70(int a, int x, int y, int v)
{
    CmdRec *p = D_0069384C;
    u32 n;

    func_00201DE8(a, x, y, v);
    D_0069384C = p + 1;
    D_0069384C = func_00201F50(a, p + 1);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_224930", func_00225CF8);

void func_00225DE0(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_00225CF8(p + 1, a, b, c, d);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00225E70(int a0) {
    if (a0 != 0) {
        func_001FFDE0();
    } else {
        func_001FFDC0();
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_224930", func_00225E88);

void func_00225F30(int x, int y, int k)
{
    CmdRec *p;
    u32 n;

    if ((func_00242900() >> k) & 1) {
        func_00225718(x + ((s16 *)&D_00326DA0)[0], y + ((s16 *)&D_00326DA0)[1], /* DEBT(CAST): S6Pt is not visible here */
                      0x200, D_00326DAE, D_00326D98, D_00326DA4);
    }
    p = D_0069384C;
    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_00200C58(p + 1, k, x, y);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

int func_00226018(int x, int y, int k) /* DEBT(TYPE): declared int in u4.h, no value returned */
{
    CmdRec *p;
    u32 n;

    if ((func_00242900() >> k) & 1) {
        func_00225718(x + ((s16 *)&D_00326DA0)[0], y + ((s16 *)&D_00326DA0)[1], /* DEBT(CAST): S6Pt is not visible here */
                      0x200, D_00326DAE, D_00326D98, D_00326DA4);
    }
    p = D_0069384C;
    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_00200F98(p + 1, k, x, y);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226100(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_00201250(p + 1, c, a, b, d);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226188(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_00201410(p + 1, c, a, b, d);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226210(int a, int b, int c)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_00201A68(p + 1, c, a, b);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226290(int a, int b, int c)
{
    CmdRec *p;
    u32 col = D_003257E8[0] | (D_003257F0[0] << 8) | (D_003257F8[0] << 16) | (D_00325800[0] << 24);
    u32 n;

    p = D_0069384C;
    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_00201AE0(p + 1, c, a, b, col, col);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226350(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F4260(p + 1, c, a, b, d, D_003257E8[0], D_003257F0[0], D_003257F8[0], D_00325800[0]);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226400(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F4350(p + 1, 0, c, a, b, d, D_003257E8[0], D_003257F0[0], D_003257F8[0], D_00325800[0]);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void TkMn2SetMacroParam(int a0, int a1, int a2) {
    TOMenuSetMacroCommandType(0, a0, a1);
    TOMenuSetMacroCommandValue(0, a0, a2);
}

void func_002264F8(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F5918(p + 1, c, a, b, d, D_003257E8[0], D_003257F0[0], D_003257F8[0], D_00325800[0]);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_002265A8(int x, int y, u8 *text, int d)
{
    int w = func_0020E7E0(text);
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F5918(p + 1, (int)text, x - w, y, d, D_003257E8[0], D_003257F0[0], D_003257F8[0], D_00325800[0]);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226688(int id, int x, int y, int z)
{
    CmdRec *p;
    u32 n;

    if (id == 100) {
        func_00226350(x, y, TkMn2GetCommandName(0x30FF), z);
        return;
    }
    p = D_0069384C;
    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F9138(p + 1, id, x, y, z);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226770(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F5060(p + 1, a, b, c, d);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226800(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F5380(p + 1, a, b, c, d);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226890(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F50F8(p + 1, a, b, c, d);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226920(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F5418(p + 1, a, b, c, d);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_002269B0(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F5290(p + 1, a, b, c, d);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226A40(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)TOAdpMenuIconWeaponName2(p + 1, a, b, c, d);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

u16 func_00226AD0(u8 *text) { return func_00205ED8(text); }

int func_00226AF0(u8 *text) { return func_00205ED8(text); }

void func_00226B10(int x, int y, u8 *text, int d)
{
    int w = func_00226AD0(text);
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F4260(p + 1, (int)text, x - w, y, d, D_003257E8[0], D_003257F0[0], D_003257F8[0], D_00325800[0]);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}
