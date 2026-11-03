/* EE Battle-Effect Overlay: group 0x11, file 09383 (group_index 339) & file 09410 (group_index 366)
 * Load base: 0x01B00000, .text: 0x01B004E0..0x01B00868 (904 bytes, 17 functions)
 */
#include "../rcef_overlay.h"

extern void *D_01B004A0[];
extern u8 D_01B004A8[0x38];
extern u8 D_01B00870[];

void func_01B00518(W3Task *t);
void func_01B00560(W3Task *t);
void func_01B005C8(W3Task *t);
void func_01B00618(W3Task *t);
void func_01B00658(W3Task *t);
void func_01B00688(W3Task *t);
void func_01B00698(W3Task *t);

void func_01B004E0(W3Task *t)
{
    func_001A1D08(t, func_01B00518);
    func_001A1D50(t, func_001A2058);
}

void func_01B00518(W3Task *t)
{
    func_001A2B58(1);
    func_001A1D08(t, func_01B00560);
    func_001A1D50(t, func_001A2098);
}

void func_01B00560(W3Task *t)
{
    func_001A36D8(0, 0, 0, 64, 15);
    func_0019FF90(&D_00313CB0, func_01B00698);
    func_001A1D08(t, func_01B005C8);
    func_001A1DF0(t, 30);
}

void func_01B005C8(W3Task *t)
{
    func_001A3800(D_00313E50, 0);
    func_001A1D08(t, func_01B00618);
    func_001A1D50(t, func_001A21E0);
}

void func_01B00618(W3Task *t)
{
    func_001A37F0();
    func_001A1D08(t, func_01B00658);
    func_001A1D50(t, func_001A2210);
}

void func_01B00658(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B00688);
}

void func_01B00688(W3Task *t)
{
    t->flags |= 4;
}

void func_01B00698(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313CB0.targets[0], 3);
    func_001A1420(o, 0x40);
    o->scale[2] = o->scale[1] = o->scale[0] = 0.1f;
    o->scale[3] = 0;
    func_001A4288(0);
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B00688);
    func_001A1D50(t, func_001A20D8);
}

int func_01B00738(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B00870, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B004A0, D_01B004A8);
    func_0019FF90(&D_00313CB0, func_01B004E0);
    return 0;
}

int func_01B007A8(void)
{
    rcefMainProcRunAfter((W3ObjBig *)&D_00313CB0);
    return 0;
}

int func_01B007D0(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B007F8(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B00820(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B00848(void)
{
    return 0;
}

int func_01B00850(void)
{
    return 0;
}

int func_01B00858(void)
{
    return 0;
}

int func_01B00860(void)
{
    return 0;
}
