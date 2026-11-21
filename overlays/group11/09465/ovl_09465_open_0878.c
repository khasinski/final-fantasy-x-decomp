#include "rcef_overlay.h"

W3Task *func_0019FF90_t(RcefMainCtx *, W3TaskFn) __asm__("func_0019FF90");
extern void func_001A4370(int, int);

extern int D_01B01AF4;
extern void func_01B009A0(W3Task *);
extern void func_01B00ED8(W3Task *);
extern void func_01B01810(W3Task *);

void func_01B00878(W3Task *t)
{
    int caster;
    int i;

    caster = D_00313CB0.caster;
    for (i = 0; i < D_01B01AF4; i++) {
        W3Task *c = func_0019FF90_t(&D_00313CB0, func_01B01810);
        c->frame[c->sp].count = i;
    }
    func_001A4288(0);
    func_001A4370(0, 0);
    func_0019FF90_t(&D_00313CB0, func_01B00ED8);
    func_001A1D08(t, func_01B009A0);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}
