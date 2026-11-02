/* EE Battle-Effect Overlay: group 0x11, file 09381 (group_index 337) & file 09408 (group_index 364)
 * Load base: 0x01B00000, .text: 0x01B004B8..0x01B00858 (928 bytes, 17 functions)
 */
#include "../rcef_overlay.h"

extern void *D_01B00478[];
extern u8 D_01B00480[0x38];
extern u8 D_01B00860[];

void func_01B004F0(W3Task *t);
void func_01B00538(W3Task *t);
void func_01B005A0(W3Task *t);
void func_01B005F0(W3Task *t);
void func_01B00630(W3Task *t);
void func_01B00660(W3Task *t);
void func_01B00670(W3Task *t);

void func_01B004B8(W3Task *t)
{
    func_001A1D08(t, func_01B004F0);
    func_001A1D50(t, func_001A2058);
}

void func_01B004F0(W3Task *t)
{
    func_001A2B58(1);
    func_001A1D08(t, func_01B00538);
    func_001A1D50(t, func_001A2098);
}

void func_01B00538(W3Task *t)
{
    func_001A36D8(0, 0, 0, 64, 15);
    func_0019FF90(&D_00313CB0, func_01B00670);
    func_001A1D08(t, func_01B005A0);
    func_001A1DF0(t, 30);
}

void func_01B005A0(W3Task *t)
{
    func_001A3800(D_00313E50, 0);
    func_001A1D08(t, func_01B005F0);
    func_001A1D50(t, func_001A21E0);
}

void func_01B005F0(W3Task *t)
{
    func_001A37F0();
    func_001A1D08(t, func_01B00630);
    func_001A1D50(t, func_001A2210);
}

void func_01B00630(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B00660);
}

void func_01B00660(W3Task *t)
{
    t->flags |= 4;
}

void func_01B00670(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A4288(0);
    func_001A13A0(o, D_00313CB0.targets[0], 6);
    func_001A1420(o, 0x40);
    o->pos[0] = 0.0f;
    o->pos[1] = -2.0f;
    o->pos[2] = 0.0f;
    o->pos_w = 0;
    o->scale[2] = o->scale[1] = o->scale[0] = 0.08f;
    o->scale_w = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B00660);
    func_001A1D50(t, func_001A20D8);
}

int func_01B00728(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B00860, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B00478, D_01B00480);
    func_0019FF90(&D_00313CB0, func_01B004B8);
    return 0;
}

int func_01B00798(void)
{
    rcefMainProcRunAfter((W3ObjBig *)&D_00313CB0);
    return 0;
}

int func_01B007C0(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B007E8(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B00810(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B00838(void)
{
    return 0;
}

int func_01B00840(void)
{
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
