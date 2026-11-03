/* EE Battle-Effect Overlay: group 0x11, file 09379 (group_index 335)
 * Load base: 0x01B00000, .text: 0x01B00558..0x01B008E0
 *
 * Small effect scene: single target ring mote.
 */
#include "../rcef_overlay.h"

extern u8 D_01B00518[8];
extern u8 D_01B00520[8];
extern u8 D_01B008F0[8];

void func_01B00590(W3Task *t);
void func_01B005D8(W3Task *t);
void func_01B00640(W3Task *t);
void func_01B00690(W3Task *t);
void func_01B006D0(W3Task *t);
void func_01B00700(W3Task *t);
void func_01B00710(W3Task *t);

void func_01B00558(W3Task *t)
{
    W3Task *task = t;

    func_001A1D08(task, func_01B00590);
    func_001A1D50(task, func_001A2058);
}

void func_01B00590(W3Task *t)
{
    W3Task *task = t;

    func_001A2B58(1);
    func_001A1D08(task, func_01B005D8);
    func_001A1D50(task, func_001A2098);
}

void func_01B005D8(W3Task *t)
{
    W3Task *task = t;

    func_001A36D8(48, 0, 48, 64, 15);
    func_0019FF90(&D_00313CB0, func_01B00710);
    func_001A1D08(task, func_01B00640);
    func_001A1DF0(task, 30);
}

void func_01B00640(W3Task *t)
{
    W3Task *task = t;

    func_001A3800(D_00313E50, 0);
    func_001A1D08(task, func_01B00690);
    func_001A1D50(task, func_001A21E0);
}

void func_01B00690(W3Task *t)
{
    W3Task *task = t;

    func_001A37F0();
    func_001A1D08(task, func_01B006D0);
    func_001A1D50(task, func_001A2210);
}

void func_01B006D0(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B00700);
}

void func_01B00700(W3Task *t)
{
    t->flags |= 4;
}

void func_01B00710(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313CB0.targets[0], 3);
    func_001A1420(o, 64);
    o->scale[0] = 0.1f;
    o->scale[1] = 0.1f;
    o->scale[2] = 0.1f;
    o->scale_w = 0;
    func_001A4288(0);
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B00700);
    func_001A1D50(t, func_001A20D8);
}

int func_01B007B0(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B008F0, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B00518, D_01B00520);
    func_0019FF90(&D_00313CB0, func_01B00558);
    return 0;
}

int func_01B00820(void)
{
    func_0019FDF0(&D_00313CB0);
    return 0;
}

int func_01B00848(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B00870(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B00898(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B008C0(void)
{
    return 0;
}

int func_01B008C8(void)
{
    return 0;
}

int func_01B008D0(void)
{
    return 0;
}

int func_01B008D8(void)
{
    return 0;
}
