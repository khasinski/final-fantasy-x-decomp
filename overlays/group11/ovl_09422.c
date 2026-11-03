/* EE Battle-Effect Overlay: group 0x11, file 09422 (group_index 378)
 * Load base: 0x01B00000, .text: 0x01B00530..0x01B00930 (1024 bytes, 18 functions)
 */
#include "../rcef_overlay.h"

extern void *D_01B004F0[];
extern u8 D_01B004F8[0x38];
extern u8 D_01B00940[];

void func_01B00568(W3Task *t);
void func_01B005B0(W3Task *t);
void func_01B00600(W3Task *t);
void func_01B00650(W3Task *t);
void func_01B006A8(W3Task *t);
void func_01B006D8(W3Task *t);
void func_01B006E8(W3Task *t);
void func_01B00778(W3Task *t);

void func_01B00530(W3Task *t)
{
    func_001A1D08(t, func_01B00568);
    func_001A1D50(t, func_001A2058);
}

void func_01B00568(W3Task *t)
{
    func_001A2B58(1);
    func_001A1D08(t, func_01B005B0);
    func_001A1D50(t, func_001A2098);
}

void func_01B005B0(W3Task *t)
{
    func_0019FF90(&D_00313CB0, func_01B006E8);
    func_001A1D08(t, func_01B00600);
    func_001A1DF0(t, 15);
}

void func_01B00600(W3Task *t)
{
    func_0019FF90(&D_00313CB0, func_01B00778);
    func_001A1D08(t, func_01B00650);
    func_001A1DF0(t, 5);
}

void func_01B00650(W3Task *t)
{
    func_001C5E90(D_00313CB0.eff_id, D_00313CB0.targets[0], 0);
    func_001A1D08(t, func_01B006A8);
    func_001A1D50(t, func_001A21E0);
}

void func_01B006A8(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B006D8);
}

void func_01B006D8(W3Task *t)
{
    t->flags |= 4;
}

void func_01B006E8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313CB0.targets[0], 0);
    o->scale[2] = o->scale[1] = o->scale[0] = 0.05f;
    o->scale[3] = 0;
    func_001A4288(0);
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B006D8);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00778(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313CB0.targets[0], 0);
    o->scale[2] = o->scale[1] = o->scale[0] = 0.1f;
    o->scale[3] = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 1);
    func_001A1D08(t, func_01B006D8);
    func_001A1D50(t, func_001A20D8);
}

int func_01B00800(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B00940, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B004F0, D_01B004F8);
    func_0019FF90(&D_00313CB0, func_01B00530);
    return 0;
}

int func_01B00870(void)
{
    rcefMainProcRunAfter((W3ObjBig *)&D_00313CB0);
    return 0;
}

int func_01B00898(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B008C0(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B008E8(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B00910(void)
{
    return 0;
}

int func_01B00918(void)
{
    return 0;
}

int func_01B00920(void)
{
    return 0;
}

int func_01B00928(void)
{
    return 0;
}
