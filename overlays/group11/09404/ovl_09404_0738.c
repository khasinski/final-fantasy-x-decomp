/* EE Battle-Effect Overlay: group 0x11, file 09404 (part 1: 0x01B00738..0x01B00D68, 15 functions) */
#include "rcef_overlay.h"

extern RcefObj *D_01B01370;
extern s32 D_01B01374;
extern s32 D_00313E48;

void func_001A3740(int r0, int g0, int b0, int a0, int r1, int g1, int b1, int a1, int frames);

void func_01B00788(W3Task *t);
void func_01B007D0(W3Task *t);
void func_01B00840(W3Task *t);
void func_01B00880(W3Task *t);
void func_01B008F0(W3Task *t);
void func_01B00938(W3Task *t);
void func_01B009F8(W3Task *t);
void func_01B00A40(W3Task *t);
void func_01B00AD0(W3Task *t);
void func_01B00B38(W3Task *t);
void func_01B00BA8(W3Task *t);
void func_01B00BE8(W3Task *t);
void func_01B00BF8(W3Task *t);
void func_01B00CB0(W3Task *t);
extern void func_01B00D68(W3Task *t);
extern void func_01B011B0(W3Task *t);

void func_01B00738(W3Task *t)
{
    D_01B01370 = 0;
    D_01B01374 = 60;
    func_001A1D08(t, func_01B00788);
    func_001A1D50(t, func_001A2058);
}

void func_01B00788(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t, func_01B00880);
    func_001A1D50(t, func_001A2098);
}

void func_01B007D0(W3Task *t)
{
    int caster = D_00313E48;

    func_001A2B80(caster, 184);
    func_001A1D08(t, func_01B00840);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B00840(W3Task *t)
{
    func_001A2B80(D_00313E48, 185);
    func_001A1D08(t, func_01B00880);
}

void func_01B00880(W3Task *t)
{
    func_001A36D8(0, 0, 0, 0x40, 15);
    func_001A4288(0);
    func_0019FF90(&D_00313CB0, func_01B00BF8);
    func_001A1D08(t, func_01B008F0);
    func_001A1DF0(t, 36);
}

void func_01B008F0(W3Task *t)
{
    func_001A2B80(D_00313E48, 186);
    func_001A1D08(t, func_01B00938);
    func_001A1DF0(t, 24);
}

void func_01B00938(W3Task *t)
{
    int caster = D_00313CB0.caster;
    RcefObj *r;

    func_001A3740(0xFF, 0xFF, 0xFF, 0x80, 0, 0, 0, 0x40, 8);
    func_0019FF90(&D_00313CB0, func_01B00CB0);
    r = func_0019FF90(&D_00313CB0, func_01B00D68);
    D_01B01370 = r;
    func_001A1D08(t, func_01B009F8);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B009F8(W3Task *t)
{
    func_001A2B80(D_00313E48, 187);
    func_001A1D08(t, func_01B00A40);
    func_001A1DF0(t, 30);
}

void func_01B00A40(W3Task *t)
{
    func_001A3740(0xFF, 0xFF, 0xFF, 0x80, 0, 0, 0, 0x40, 12);
    func_001A4288(1);
    func_001A3800(-5, 0);
    func_0019FF90(&D_00313CB0, func_01B011B0);
    func_001A1D08(t, func_01B00AD0);
    func_001A1D50(t, func_001A2210);
}

void func_01B00AD0(W3Task *t)
{
    func_001A3740(0, 0, 0, 0x40, 0, 0, 0, 0, 15);
    func_001A1D08(t, func_01B00B38);
    func_001A1DF0(t, 20);
}

void func_01B00B38(W3Task *t)
{
    int caster = D_00313E48;

    func_001A2B80(caster, 188);
    func_001A1D08(t, func_01B00BA8);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B00BA8(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B00BE8);
    func_001A1D50(t, func_001A21E0);
}

void func_01B00BE8(W3Task *t)
{
    t->flags |= 4;
}

void func_01B00BF8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313CB0.caster, 6);
    o->pos[0] = 0.0f;
    o->pos[1] = 0.0f;
    o->pos[2] = -20.0f;
    o->pos_w = 0;
    o->rot[0] = -15.0f;
    o->rot[1] = 0.0f;
    o->rot[2] = 0.0f;
    o->rot_w = 0;
    o->scale[2] = o->scale[1] = o->scale[0] = 0.25f;
    o->scale[3] = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 3);
    func_001A1D08(t, func_01B00BE8);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00CB0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313CB0.caster, 6);
    o->pos[0] = 0.0f;
    o->pos[1] = 0.0f;
    o->pos[2] = -13.0f;
    o->pos_w = 0;
    o->rot[0] = -15.0f;
    o->rot[1] = 0.0f;
    o->rot[2] = 0.0f;
    o->rot_w = 0;
    o->scale[2] = o->scale[1] = o->scale[0] = 0.15f;
    o->scale[3] = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 1);
    func_001A1D08(t, func_01B00BE8);
    func_001A1D50(t, func_001A20D8);
}
