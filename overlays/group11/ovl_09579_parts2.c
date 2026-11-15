#include "../rcef_overlay.h"
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

void func_01B017E0(W3Task *t)
{
    int i = t->frame[t->sp].count;
    W3Task *r;
    if (D_01B01BD0[i] != 0) {
        func_001A3800(D_00313CB0.targets[i], 0);
        r = func_0019FF90_t(&D_00313CB0, func_01B01898);
        r->frame[r->sp].count = i;
        t->flags |= 4;
    }
    if (D_01B01ABC != 0) {
        t->flags |= 4;
    }
}

void func_01B01898(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int chr = D_00313CB0.targets[t->frame[t->sp].count];
    func_001A4288(1);
    func_001A13A0(o, chr, 6);
    func_001A1420(o, 0x10);
    o->scale[0] = 0.18f;
    o->scale[1] = 0.18f;
    o->scale[2] = 0.18f;
    o->scale[3] = 0.0f;
    func_0019FFD0(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B00A68);
    func_001A1D50(t, func_001A20D8);
}
