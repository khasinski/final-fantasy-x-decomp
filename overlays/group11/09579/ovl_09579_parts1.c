#include "rcef_overlay.h"
W3Task *func_0019FF90_t(RcefMainCtx *, W3TaskFn) __asm__("func_0019FF90");
void func_0019FFD0(RcefMainCtx *, RcefObj *, int, int);
extern int D_01B01AC4;
extern int D_01B01ABC;
extern int D_01B01BD0[];
void func_01B00970(W3Task *);
void func_01B01898(W3Task *);
void func_01B017E0(W3Task *);
void func_01B00EA8(W3Task *);
void func_01B00A68(W3Task *);
void func_01B00B20(W3Task *);

void func_01B00A78(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    func_001A1378(o, D_00313CB0.caster, 72);
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
    func_001A1D08(t, func_01B00B20);
    func_001A1DF0(t, 70);
}

void func_01B00B20(W3Task *t)
{
    ((RcefObj *)t)->unk18C = -0.1f;
    func_001A1D08(t, func_01B00A68);
    func_001A1DF0(t, 10);
}
