/* EE Battle-Effect Overlay: group 0x11, file 09380 (group_index 336)
 * Load base: 0x01B00000, .text: 0x01B00468..0x01B007B0
 *
 * Small effect scene: falling mote on the first target.
 */
#include "../rcef_overlay.h"

extern u8 D_01B00428[8];
extern u8 D_01B00430[8];
extern u8 D_01B007C0[8];

void func_01B004A0(W3Task *t);
void func_01B004E8(W3Task *t);
void func_01B00538(W3Task *t);
void func_01B00588(W3Task *t);
void func_01B005B8(W3Task *t);
void func_01B005C8(W3Task *t);

void func_01B00468(W3Task *t)
{
    W3Task *task = t;

    func_001A1D08(task, func_01B004A0);
    func_001A1D50(task, func_001A2058);
}

void func_01B004A0(W3Task *t)
{
    W3Task *task = t;

    func_001A2B58(1);
    func_001A1D08(task, func_01B004E8);
    func_001A1D50(task, func_001A2098);
}

void func_01B004E8(W3Task *t)
{
    W3Task *task = t;

    func_0019FF90(&D_00313CB0, func_01B005C8);
    func_001A1D08(task, func_01B00538);
    func_001A1DF0(task, 30);
}

void func_01B00538(W3Task *t)
{
    W3Task *task = t;

    func_001A3800(D_00313E50, 0);
    func_001A1D08(task, func_01B00588);
    func_001A1D50(task, func_001A21E0);
}

void func_01B00588(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B005B8);
}

void func_01B005B8(W3Task *t)
{
    t->flags |= 4;
}

/* falling mote on the first target */
void func_01B005C8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313CB0.targets[0], 6);
    func_001A1420(o, 64);
    o->pos[0] = 0;
    o->pos[1] = -2.0f;
    o->pos[2] = 0;
    o->pos_w = 0;
    o->scale[0] = 0.06f;
    o->scale[1] = 0.06f;
    o->scale[2] = 0.06f;
    o->scale[3] = 0;
    func_001A4288(0);
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B005B8);
    func_001A1D50(t, func_001A20D8);
}

int func_01B00680(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B007C0, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B00428, D_01B00430);
    func_0019FF90(&D_00313CB0, func_01B00468);
    return 0;
}

int func_01B006F0(void)
{
    func_0019FDF0(&D_00313CB0);
    return 0;
}

int func_01B00718(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B00740(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B00768(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B00790(void)
{
    return 0;
}

int func_01B00798(void)
{
    return 0;
}

int func_01B007A0(void)
{
    return 0;
}

int func_01B007A8(void)
{
    return 0;
}
