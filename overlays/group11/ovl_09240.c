/* EE Battle-Effect Overlay: group 0x11, file 09240 (group_index 196) & file 09378 (group_index 334)
 * Load base: 0x01B00000, .text: 0x01B005D0..0x01B00968 (920 bytes, 17 functions)
 */
#include "../rcef_overlay.h"

extern void *D_01B00590[];
extern u8 D_01B00598[0x38];
extern u8 D_01B00970[];

void func_01B00608(W3Task *t);
void func_01B00650(W3Task *t);
void func_01B006B8(W3Task *t);
void func_01B00708(W3Task *t);
void func_01B00748(W3Task *t);
void func_01B00788(W3Task *t);
void func_01B00798(W3Task *t);

void func_01B005D0(W3Task *t)
{
    func_001A1D08(t, func_01B00608);
    func_001A1D50(t, func_001A2058);
}

void func_01B00608(W3Task *t)
{
    func_001A2B58(1);
    func_001A1D08(t, func_01B00650);
    func_001A1D50(t, func_001A2098);
}

void func_01B00650(W3Task *t)
{
    func_001A36D8(0, 0, 0, 64, 15);
    func_0019FF90(&D_00313CB0, func_01B00798);
    func_001A1D08(t, func_01B006B8);
    func_001A1DF0(t, 30);
}

void func_01B006B8(W3Task *t)
{
    func_001A3800(D_00313E50, 0);
    func_001A1D08(t, func_01B00708);
    func_001A1D50(t, func_001A21E0);
}

void func_01B00708(W3Task *t)
{
    func_001A37F0();
    func_001A1D08(t, func_01B00748);
    func_001A1D50(t, func_001A2210);
}

void func_01B00748(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B00788);
    func_001A1D50(t, func_001A21E0);
}

void func_01B00788(W3Task *t)
{
    t->flags |= 4;
}

void func_01B00798(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313CB0.targets[0], 3);
    func_001A1420(o, 0x40);
    o->scale[2] = o->scale[1] = o->scale[0] = 0.07f;
    o->scale[3] = 0;
    func_001A4288(0);
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B00788);
    func_001A1D50(t, func_001A20D8);
}

int func_01B00838(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B00970, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B00590, D_01B00598);
    func_0019FF90(&D_00313CB0, func_01B005D0);
    return 0;
}

int func_01B008A8(void)
{
    rcefMainProcRunAfter((W3ObjBig *)&D_00313CB0);
    return 0;
}

int func_01B008D0(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B008F8(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B00920(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B00948(void)
{
    return 0;
}

int func_01B00950(void)
{
    return 0;
}

int func_01B00958(void)
{
    return 0;
}

int func_01B00960(void)
{
    return 0;
}
