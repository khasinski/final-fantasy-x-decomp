#include "rcef_overlay.h"
extern int D_00313E48;
void func_0019FDF0(void *);
extern int D_01B01ABC;
extern void *D_01B00540[];
extern u8 D_01B00548[];
extern u8 D_01B01C10[];
void func_01B00580(W3Task *t);
void func_01B007C0(W3Task *t);
void func_01B00808(W3Task *t);
void func_01B00850(W3Task *t);
void func_01B00970(W3Task *t);
void func_01B009B8(W3Task *t);
void func_01B00A28(W3Task *t);
void func_01B00A68(W3Task *t);

void func_01B00970(W3Task *t)
{
    func_001A2B80(D_00313E48, 193);
    func_001A1D08(t, func_01B009B8);
    func_001A1DF0(t, 90);
}

void func_01B009B8(W3Task *t)
{
    int caster = D_00313E48;
    func_001A2B80(caster, 194);
    func_001A1D08(t, func_01B00A28);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B00A28(W3Task *t)
{
    D_01B01ABC = 1;
    func_001A2B68();
    func_001A1D08(t, func_01B00A68);
}

void func_01B00A68(W3Task *t)
{
    t->flags |= 4;
}
