/* EE Battle-Effect Overlay: group 0x11, file 09237 (part 2)
 * Load base: 0x01B00000, .text: 0x01B008E8..0x01B00E10 (7 functions)
 */
#include "rcef_overlay.h"

extern int D_01B01390;
extern int D_01B01394;
extern float D_01B013B0[4];
extern float D_01B013D0[4];

void func_0019FFD0(RcefMainCtx *ctx, RcefObj *o, int a2, int a3);
W3Task *func_0019FF90_t(RcefMainCtx *ctx, W3TaskFn fn) __asm__("func_0019FF90");

void func_01B00920(W3Task *t);
void func_01B009D8(W3Task *t);
void func_01B00AC0(W3Task *t);
void func_01B00B00(W3Task *t);
void func_01B00B10(W3Task *t);
void func_01B00BB8(W3Task *t);
void func_01B00E10(W3Task *t);
void func_01B010F0(W3Task *t);

void func_01B008E8(W3Task *t)
{
    func_001A4288(0);
    func_001A1D20(t, func_01B00920);
}

void func_01B00920(W3Task *t)
{
    if (D_01B01390 >= 0x14) {
        func_001A1D08(t, func_01B009D8);
        func_001A1DF0(t, D_01B01394 - 0x23);
    } else {
        func_0019FF90_t(&D_00313CB0, func_01B00BB8);
        func_0019FF90_t(&D_00313CB0, func_01B00BB8);
        func_0019FF90_t(&D_00313CB0, func_01B00BB8);
        D_01B01390++;
    }
}

void func_01B009D8(W3Task *t)
{
    int i;
    W3Task *r;

    func_001A4288(1);
    for (i = 0; i < D_00313CB0.target_count; i++) {
        func_001A3800(D_00313CB0.targets[i], 0);
        r = func_0019FF90_t(&D_00313CB0, func_01B010F0);
        r->frame[r->sp].count = i;
    }
    func_001A1D08(t, func_01B00AC0);
    func_001A1D50(t, func_001A21E0);
}

void func_01B00AC0(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B00B00);
    func_001A1D50(t, func_001A2348);
}

void func_01B00B00(W3Task *t)
{
    t->flags |= 4;
}

void func_01B00B10(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A1378(o, D_00313CB0.caster, 0x119);
    func_001A1420(o, 0x10);
    o->pos[0] = 0;
    o->pos[1] = 0;
    o->pos_w = 0;
    o->scale[3] = 0;
    o->pos[2] = -10.0f;
    o->scale[0] = 0.5f;
    o->scale[1] = 0.5f;
    o->scale[2] = 0.5f;
    func_0019FFD0(&D_00313CB0, o, 0, 1);
    func_001A1D08(t, func_01B00B00);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00BB8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float ang;
    float sc;
    float spd;
    float s;

    t->frame[t->sp].count = 0;
    t->frame[t->sp].arg1 = func_002EFD78() % 256;
    *(int *)((t->sp << 4) + (int)t + 0x34) = 0;
    ang = (float)func_002EFD78() * 4.656612873077393e-10f * 360.0f;
    sc = (float)func_002EFD78() * 4.656612873077393e-10f * 0.2f + 0.1f;
    spd = 0.2f / (float)D_01B01394;
    o->flagsBC |= 0x4000;
    o->pos[0] = D_01B013B0[0];
    o->pos[1] = D_01B013B0[1];
    o->pos[2] = D_01B013B0[2];
    o->pos_w = 0;
    o->rot[0] = 0;
    o->rot[1] = 0;
    o->rot[2] = ang;
    o->rot_w = 0;
    o->scale[0] = sc;
    o->scale[1] = sc;
    o->scale[2] = sc;
    o->scale[3] = 0;
    o->unk140[0] = spd;
    o->unk140[1] = spd;
    o->unk140[2] = spd;
    o->unk14C_w = 0;
    s = (float)func_002EFD78() * 4.656612873077393e-10f * 0.4f + 0.6f;
    o->vel[0] = D_01B013D0[0] * s;
    o->vel[1] = D_01B013D0[1] * s;
    o->vel[2] = D_01B013D0[2] * s;
    o->vel[3] = 0;
    o->unk18C = 0;
    o->unk170[0] = 0.609375f;
    o->unk170[1] = 0.6640625f;
    o->unk170[2] = 0.4140625f;
    o->unk170[3] = 1.0f;
    o->unk180[0] = -0.546875f / (float)D_01B01394;
    o->unk180[1] = -0.5859375f / (float)D_01B01394;
    o->unk180[2] = -0.390625f / (float)D_01B01394;
    func_001A0000((RcefObj *)&D_00313CB0, (void *)o, 0);
    func_001A1D20(t, func_01B00E10);
}
