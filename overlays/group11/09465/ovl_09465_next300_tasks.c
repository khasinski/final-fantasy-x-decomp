#include "rcef_overlay.h"
extern int D_00313E48;
extern int D_01B01AEC;
void func_01B009A0(W3Task *t);
void func_01B009E8(W3Task *t);
void func_01B00A58(W3Task *t);
void func_01B00A98(W3Task *t);

void func_01B009A0(W3Task *t)
{
    func_001A2B80(D_00313E48, 193);
    func_001A1D08(t, func_01B009E8);
    func_001A1DF0(t, 90);
}

void func_01B009E8(W3Task *t)
{
    int caster = D_00313E48;
    func_001A2B80(caster, 194);
    func_001A1D08(t, func_01B00A58);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B00A58(W3Task *t)
{
    D_01B01AEC = 1;
    func_001A2B68();
    func_001A1D08(t, func_01B00A98);
}

void func_01B00A98(W3Task *t)
{
    t->flags |= 4;
}

void func_0019FFD0(RcefMainCtx *, RcefObj *, int, int);
void func_01B00B50(W3Task *);
void func_01B00AA8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    func_001A1378(o, D_00313CB0.caster, 11);
    func_001A1420(o, 0x100);
    o->rot[0] = 0.0f;
    o->rot[1] = -90.0f;
    o->rot[2] = 0.0f;
    o->rot_w = 0;
    o->scale[0] = 0.1f;
    o->scale[1] = 0.1f;
    o->scale[2] = 0.1f;
    o->scale[3] = 0.0f;
    func_0019FFD0(&D_00313CB0, o, 0, 2);
    func_001A1D08(t, func_01B00B50);
    func_001A1DF0(t, 70);
}
void func_01B00B50(W3Task *t)
{
    ((RcefObj *)t)->unk18C = -0.1f;
    func_001A1D08(t, func_01B00A98);
    func_001A1DF0(t, 10);
}
