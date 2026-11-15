#include "../rcef_overlay.h"
W3Task *func_0019FF90_t(RcefMainCtx *, W3TaskFn) __asm__("func_0019FF90");
void func_0019FFD0(RcefMainCtx *, RcefObj *, int, int);
extern int D_01B01B28;
extern int D_01B01B20;
extern int D_01B01C30[];
void func_01B00980(W3Task *);
void func_01B018F8(W3Task *);
void func_01B01840(W3Task *);
void func_01B00EE0(W3Task *);
void func_01B00A78(W3Task *);
void func_01B00B50(W3Task *);

void func_01B00A88(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    func_001A1378(o, D_00313CB0.caster, 73);
    func_001A1420(o, 0x100);
    o->pos[0] = 3.5f;
    o->pos[1] = 0.5f;
    o->pos[2] = 0.0f;
    o->pos_w = 0;
    o->rot[0] = 0.0f;
    o->rot[1] = -90.0f;
    o->rot[2] = 0.0f;
    o->rot_w = 0;
    o->scale[0] = 0.2f;
    o->scale[1] = 0.2f;
    o->scale[2] = 0.2f;
    o->scale[3] = 0.0f;
    func_0019FFD0(&D_00313CB0, o, 0, 2);
    func_001A1D08(t, func_01B00B50);
    func_001A1DF0(t, 70);
}

void func_01B00B50(W3Task *t)
{
    ((RcefObj *)t)->unk18C = -0.1f;
    func_001A1D08(t, func_01B00A78);
    func_001A1DF0(t, 10);
}
