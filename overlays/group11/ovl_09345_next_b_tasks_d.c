/* Battle-effect overlay 09345: byte-exact C helpers and callbacks. */
#include "../rcef_overlay.h"
void func_01B01008(W3Task *t);
void func_01B016C8(W3Task *t);
void func_01B01700(W3Task *t);
void func_01B017A8(W3Task *t);
void func_01B01608(W3Task *t)
{
    func_001A4288(1);
    func_001A1D08(t,func_01B01008);
    func_001A1D50(t,func_001A20D8);
}

void func_01B01650(W3Task *t)
{
    RcefObj *o=(RcefObj *)t;
    func_001A1420(o,0x40);
    o->scale[2]=o->scale[1]=o->scale[0]=0.05f;
    o->scale[3]=0;
    rcefMainKickPar(&D_00313CB0,o,0,2);
    func_001A1D08(t,func_01B01008);
    func_001A1D50(t,func_001A20D8);
}

void func_01B016C8(W3Task *t)
{
    func_001A1D08(t,func_01B01700);
    func_001A1DF0(t,30);
}

void func_01B01700(W3Task *t)
{
    int i;
    for(i=0;i<D_00313CB0.target_count;i++)func_001A3800(D_00313CB0.targets[i],8);
    func_001A1D08(t,func_01B017A8);
    func_001A1DF0(t,23);
}

void func_01B017A8(W3Task *t)
{
    int i;
    for(i=0;i<D_00313CB0.target_count;i++)func_001A3800(D_00313CB0.targets[i],0);
    t->flags |= 4;
}
