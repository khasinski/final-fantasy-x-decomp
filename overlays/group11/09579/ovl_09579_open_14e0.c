#include "rcef_overlay.h"

#define VEC3_COPY(d, a) \
    __asm__ volatile(".set noreorder\n\tlqc2 $vf31, 0(%1)\n\tsqc2 $vf31, 0(%0)\n\t.set reorder" : : "r"(d), "r"(a) : "memory")

extern int D_01B01AB8;
extern float D_01B01AC0;

extern void func_01B00A68(W3Task *);
extern void func_01B015B0(W3Task *);
extern void func_0019FFD0(RcefMainCtx *, RcefObj *, int, int);
void func_001A0000_m(RcefMainCtx *, RcefObj *, int) __asm__("func_001A0000");

void func_01B014E0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    o->unk170[2] = 1.0f;
    o->scale[0] = 1.0f;
    o->scale[1] = 1.0f;
    o->scale[2] = 1.0f;
    o->scale[3] = 0.0f;
    o->unk170[0] = 1.0f;
    o->unk170[1] = 1.0f;
    o->unk170[3] = 0.0f;
    o->unk18C = 1.0f / (float)(D_01B01AB8 / 4);
    func_0019FFD0(&D_00313CB0, o, 0, 3);
    func_001A1D08(t, func_01B015B0);
    func_001A1DF0(t, D_01B01AB8 / 4);
}

void func_01B015B0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int dur = D_01B01AB8 - (D_01B01AB8 / 4);

    o->unk18C = -1.0f / (float)dur;
    func_001A1D08(t, func_01B00A68);
    func_001A1DF0(t, dur);
}

void func_01B01630(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float pos[4];
    float vel[4];
    float rotz;
    float sc;
    RcefObj *parent;

    parent = (RcefObj *)t->frame[t->sp].count;
    VEC3_COPY(pos, parent->pos);
    vel[0] = (float)func_002EFD78() * 4.6566128730773926e-10f - 0.5f;
    vel[1] = (float)func_002EFD78() * 4.6566128730773926e-10f - 0.5f;
    vel[2] = (float)func_002EFD78() * 4.6566128730773926e-10f - 0.5f;
    rotz = (float)func_002EFD78() * 4.6566128730773926e-10f * 360.0f;
    sc = (float)func_002EFD78() * 4.6566128730773926e-10f * 0.24f + 0.08f;
    o->flagsBC |= 0x4000;
    o->pos[0] = pos[0];
    o->pos[1] = pos[1];
    o->pos[2] = pos[2];
    o->pos_w = 0;
    o->vel[0] = vel[0];
    o->vel[1] = vel[1];
    o->vel[2] = vel[2];
    o->vel[3] = 0.0f;
    o->rot[0] = 0.0f;
    o->rot[1] = 0.0f;
    o->rot[2] = rotz;
    o->rot_w = 0;
    o->scale[0] = sc;
    o->scale[1] = sc;
    o->scale[2] = sc;
    o->scale[3] = 0.0f;
    o->unk170[3] = D_01B01AC0;
    o->unk180[0] = 0.0f;
    o->unk180[1] = 0.0f;
    o->unk180[2] = 0.0f;
    o->unk18C = -0.05f;
    func_001A0000_m(&D_00313CB0, o, 1);
    func_001A1D08(t, func_01B00A68);
    func_001A1DF0(t, 20);
}
