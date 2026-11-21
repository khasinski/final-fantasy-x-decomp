#include "rcef_overlay.h"

W3Task *func_0019FF90_t(RcefMainCtx *, W3TaskFn) __asm__("func_0019FF90");

extern int D_01B01AC4;
extern void rcef_0970(W3Task *);
extern void rcef_0ea8(W3Task *);
extern void func_01B017E0(W3Task *);

void func_01B00850(W3Task *t)
{
    int caster;
    int i;

    caster = D_00313CB0.caster;
    for (i = 0; i < D_01B01AC4; i++) {
        W3Task *c = func_0019FF90_t(&D_00313CB0, func_01B017E0);
        c->frame[c->sp].count = i;
    }
    func_001A4288(0);
    func_0019FF90_t(&D_00313CB0, rcef_0ea8);
    func_001A1D08(t, rcef_0970);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}
