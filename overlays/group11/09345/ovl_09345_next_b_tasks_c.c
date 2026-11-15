/* Battle-effect overlay 09345: byte-exact C helpers and callbacks. */
#include "rcef_overlay.h"
extern s32 D_00313E48;
void func_01B00F58(W3Task *t);
void func_01B00FC8(W3Task *t);
void func_01B01008(W3Task *t);
void func_01B00F58(W3Task *t)
{
    int caster=D_00313E48;
    func_001A2B80(caster,0xb2);
    func_001A1D08(t,func_01B00FC8);
    func_001A1D50(t,func_001A2148);
    t->frame[t->sp].count=caster;
}

void func_01B00FC8(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t,func_01B01008);
    func_001A1D50(t,func_001A21E0);
}

void func_01B01008(W3Task *t)
{
    t->flags |= 4;
}
