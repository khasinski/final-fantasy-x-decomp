#include "rcef_overlay.h"
extern int D_00313E48;
void func_0019FDF0(void *);
extern int D_01B01B20;
extern void *D_01B00540[];
extern u8 D_01B00548[];
extern u8 D_01B01C70[];
void func_01B00580(W3Task *t);
void func_01B007D0(W3Task *t);
void func_01B00818(W3Task *t);
void func_01B00860(W3Task *t);
void func_01B00980(W3Task *t);
void func_01B009C8(W3Task *t);
void func_01B00A38(W3Task *t);
void func_01B00A78(W3Task *t);

void func_01B00980(W3Task *t)
{
    func_001A2B80(D_00313E48, 179);
    func_001A1D08(t, func_01B009C8);
    func_001A1DF0(t, 60);
}

void func_01B009C8(W3Task *t)
{
    int caster = D_00313E48;
    func_001A2B80(caster, 180);
    func_001A1D08(t, func_01B00A38);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B00A38(W3Task *t)
{
    D_01B01B20 = 1;
    func_001A2B68();
    func_001A1D08(t, func_01B00A78);
}

void func_01B00A78(W3Task *t)
{
    t->flags |= 4;
}
