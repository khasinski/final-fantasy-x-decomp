/* Battle-effect overlay 09345: byte-exact C helpers and callbacks. */
#include "../rcef_overlay.h"
extern s32 D_00313E48;
void func_001A2C88(int, int, int, int);
void func_01B00A20(W3Task *t);
void func_01B00A68(W3Task *t);
void func_01B00AB0(W3Task *t);
void func_01B00B08(W3Task *t);
void func_01B00B40(W3Task *t);
void func_01B00BA8(W3Task *t);
void func_01B01170(W3Task *t);
void func_01B00A20(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t,func_01B00AB0);
    func_001A1D50(t,func_001A2098);
}

void func_01B00A68(W3Task *t)
{
    func_001A2B80(D_00313E48,0x79);
    func_001A1D08(t,func_01B00AB0);
    func_001A1DF0(t,30);
}

void func_01B00AB0(W3Task *t)
{
    func_001A2C88(D_00313CB0.caster,D_00313CB0.targets[0],2,2);
    func_001A1D08(t,func_01B00B40);
    func_001A1DF0(t,6);
}

void func_01B00B08(W3Task *t)
{
    func_001A1D08(t,func_01B00B40);
    func_001A1DF0(t,20);
}

void func_01B00B40(W3Task *t)
{
    func_001A2B80(D_00313CB0.caster,0xb0);
    func_0019FF90(&D_00313CB0,func_01B01170);
    func_001A1D08(t,func_01B00BA8);
    func_001A1DF0(t,3);
}
