/* EE Battle-Effect Overlay: group 0x11, file 09231
 * Load base: 0x01B00000, .text: 0x01B004B8..0x01B009D8 (1312 bytes, 18 functions)
 */
#include "../rcef_overlay.h"

extern void *D_01B00478[];
extern u8 D_01B00480[0x38];
extern u8 D_01B009E0[];

void func_01B00500(W3Task *t);
void func_01B00548(W3Task *t);
void func_01B00590(W3Task *t);
void func_01B00620(W3Task *t);
void func_01B00690(W3Task *t);
void func_01B006D0(W3Task *t);
void func_01B00708(W3Task *t);
void func_01B00718(W3Task *t);
void func_01B007F0(W3Task *t);

void func_01B004B8(W3Task *t)
{
    func_001A42D0(2, 0);
    func_001A1D08(t, func_01B00500);
    func_001A1D50(t, func_001A2058);
}

void func_01B00500(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t, func_01B00548);
    func_001A1D50(t, func_001A2098);
}

void func_01B00548(W3Task *t)
{
    func_001A2B80(D_00313CB0.caster, 186);
    func_001A1D08(t, func_01B00590);
    func_001A1DF0(t, 20);
}

void func_01B00590(W3Task *t)
{
    int caster = D_00313CB0.caster;

    func_0019FF90(&D_00313CB0, func_01B00718);
    func_0019FF90(&D_00313CB0, func_01B007F0);
    func_001A1D08(t, func_01B00620);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B00620(W3Task *t)
{
    int caster = D_00313CB0.caster;

    func_001A2B80(caster, 188);
    func_001A1D08(t, func_01B00690);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B00690(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B006D0);
    func_001A1D50(t, func_001A21E0);
}

void func_01B006D0(W3Task *t)
{
    func_001A1D08(t, func_01B00708);
    func_001A1D50(t, func_01B006D0);
}

void func_01B00708(W3Task *t)
{
    t->flags |= 4;
}

void func_01B00718(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A4288(0);
    func_001A4310(2);
    func_001A1378(o, D_00313CB0.caster, 18);
    o->pos[0] = 0.0f;
    o->pos[1] = 2.5f;
    o->pos[2] = -6.0f;
    o->pos_w = 0;
    o->rot[0] = 0.0f;
    o->rot[1] = 180.0f;
    o->rot[2] = 0.0f;
    o->rot_w = 0;
    o->scale[2] = o->scale[1] = o->scale[0] = 0.15f;
    o->scale[3] = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 1);
    func_001A1D08(t, func_01B00708);
    func_001A1D50(t, func_001A20D8);
}

void func_01B007F0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int target = D_00313CB0.targets[0];

    func_001A4288(1);
    func_001A13A0(o, target, 6);
    func_001A1420(o, 0x10);
    o->scale[2] = o->scale[1] = o->scale[0] = 0.2f;
    o->scale[3] = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A3800(target, 0);
    func_001A1D08(t, func_01B00708);
    func_001A1D50(t, func_001A20D8);
}

int func_01B008A8(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B009E0, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B00478, D_01B00480);
    func_0019FF90(&D_00313CB0, func_01B004B8);
    return 0;
}

int func_01B00918(void)
{
    rcefMainProcRunAfter((W3ObjBig *)&D_00313CB0);
    return 0;
}

int func_01B00940(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B00968(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B00990(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B009B8(void)
{
    return 0;
}

int func_01B009C0(void)
{
    return 0;
}

int func_01B009C8(void)
{
    return 0;
}

int func_01B009D0(void)
{
    return 0;
}
