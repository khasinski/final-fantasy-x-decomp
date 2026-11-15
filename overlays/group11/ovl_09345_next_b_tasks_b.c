/* Battle-effect overlay 09345: byte-exact C helpers and callbacks. */
#include "../rcef_overlay.h"
void func_001A2C88(int, int, int, int);
void func_01B00D28(W3Task *t);
void func_01B00DA8(W3Task *t);
void func_01B00DF8(W3Task *t);
void func_01B01170(W3Task *t);
void func_01B00D28(W3Task *t)
{
    int caster=D_00313CB0.caster;
    func_001A2C88(caster,D_00313CB0.targets[D_00313CB0.target_count-1],2,2);
    func_001A2B80(caster,0xb1);
    func_001A1D08(t,func_01B00DA8);
    func_001A1DF0(t,12);
}

void func_01B00DA8(W3Task *t)
{
    func_0019FF90(&D_00313CB0,func_01B01170);
    func_001A1D08(t,func_01B00DF8);
    func_001A1DF0(t,3);
}
