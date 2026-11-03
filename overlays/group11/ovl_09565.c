/* EE Battle-Effect Overlay: group 0x11, file 09565
 * Load base: 0x01B00000, .text: 0x01B00558..0x01B00A88 (1328 bytes, 21 functions)
 */
#include "../rcef_overlay.h"

extern void *D_01B00518[];
extern u8 D_01B00520[0x38];
extern u8 D_01B00A90[];

void func_01B00590(W3Task *t);
void func_01B005D8(W3Task *t);
void func_01B00628(W3Task *t);
void func_01B00678(W3Task *t);
void func_01B006B8(W3Task *t);
void func_01B00708(W3Task *t);
void func_01B00738(W3Task *t);
void func_01B00748(W3Task *t);
void func_01B007F8(W3Task *t);
void func_01B008A8(W3Task *t);
void func_01B00918(W3Task *t);

void func_01B00558(W3Task *t)
{
    func_001A1D08(t, func_01B00590);
    func_001A1D50(t, func_001A2058);
}

void func_01B00590(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t, func_01B005D8);
    func_001A1D50(t, func_001A2098);
}

void func_01B005D8(W3Task *t)
{
    func_0019FF90(&D_00313CB0, func_01B008A8);
    func_001A1D08(t, func_01B00628);
    func_001A1DF0(t, 70);
}

void func_01B00628(W3Task *t)
{
    func_0019FF90(&D_00313CB0, func_01B00748);
    func_001A1D08(t, func_01B00678);
    func_001A1DF0(t, 5);
}

void func_01B00678(W3Task *t)
{
    func_001A4288(0);
    func_001A1D08(t, func_01B006B8);
    func_001A1DF0(t, 54);
}

void func_01B006B8(W3Task *t)
{
    func_0019FF90(&D_00313CB0, func_01B007F8);
    func_001A1D08(t, func_01B00708);
    func_001A1D50(t, func_001A21E0);
}

void func_01B00708(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B00738);
}

void func_01B00738(W3Task *t)
{
    t->flags |= 4;
}

void func_01B00748(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A1378(o, D_00313CB0.caster, 35);
    func_001A1420(o, 0x10);
    o->pos[0] = 0.0f;
    o->pos[1] = -2.0f;
    o->pos[2] = 0.0f;
    o->pos_w = 0;
    o->scale[2] = o->scale[1] = o->scale[0] = 0.13f;
    o->scale[3] = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 1);
    func_001A1D08(t, func_01B00738);
    func_001A1D50(t, func_001A20D8);
}

void func_01B007F8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313CB0.caster, 0);
    func_001A1420(o, 0x10);
    o->rot[0] = 0.0f;
    o->rot[1] = 180.0f;
    o->rot[2] = 0.0f;
    o->rot_w = 0;
    o->scale[2] = o->scale[1] = o->scale[0] = 0.13f;
    o->scale[3] = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B00738);
    func_001A1D50(t, func_001A20D8);
}

void func_01B008A8(W3Task *t)
{
    int caster = D_00313CB0.caster;

    func_001A2B80(caster, 186);
    func_001A1D08(t, func_01B00918);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B00918(W3Task *t)
{
    func_001A2B80(D_00313CB0.caster, 187);
    t->flags |= 4;
}

int func_01B00958(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B00A90, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B00518, D_01B00520);
    func_0019FF90(&D_00313CB0, func_01B00558);
    return 0;
}

int func_01B009C8(void)
{
    rcefMainProcRunAfter((W3ObjBig *)&D_00313CB0);
    return 0;
}

int func_01B009F0(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B00A18(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B00A40(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B00A68(void)
{
    return 0;
}

int func_01B00A70(void)
{
    return 0;
}

int func_01B00A78(void)
{
    return 0;
}

int func_01B00A80(void)
{
    return 0;
}
