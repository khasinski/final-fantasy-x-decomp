/* Battle-effect overlay 09345: 0x01B01018..0x01B01604 */
#include "rcef_overlay.h"
#include "vu0.h"

extern float D_01B01970[][4];
extern int D_01B019B0[];

void func_001A1378(RcefObj *o, int chr, int bone);
void func_0019FFD0(RcefMainCtx *ctx, RcefObj *o, int a2, int a3);
float func_001A31D0(int chr);
W3Task *func_0019FF90_t(RcefMainCtx *ctx, W3TaskFn fn) __asm__("func_0019FF90");

void func_01B01008(W3Task *t);
void func_01B011D0(W3Task *t);
void func_01B01288(W3Task *t);
void func_01B01468(W3Task *t);
void func_01B01590(W3Task *t);
void func_01B01608(W3Task *t);
void func_01B01650(W3Task *t);

#define VEC3_COPY(d, s) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tsqc2 $vf31, 0(%0)" : : "r"(d), "r"(s) : "memory")

void func_01B01018(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    RcefMainCtx *c = &D_00313CB0;

    func_001A1378(o, c->caster, 0x18);
    o->pos[0] = 0.0f;
    o->pos[1] = 23.0f;
    o->pos[2] = 0.0f;
    o->pos_w = 0;
    o->rot[0] = 180.0f;
    o->rot[1] = 0.0f;
    o->rot[2] = 0.0f;
    o->rot[3] = 0;
    o->scale[0] = 0.1f;
    o->scale[1] = 0.1f;
    o->scale[2] = 0.1f;
    o->scale[3] = 0;
    func_0019FFD0(c, o, 0, 3);
    func_001A1D08(t, func_01B01008);
    func_001A1D50(t, func_001A20D8);
}

void func_01B010D0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    RcefMainCtx *c = &D_00313CB0;

    func_001A1378(o, c->caster, 0x25);
    o->pos[0] = 0.0f;
    o->pos[1] = -23.0f;
    o->pos[2] = 0.0f;
    o->pos_w = 0;
    o->scale[0] = 0.1f;
    o->scale[1] = 0.1f;
    o->scale[2] = 0.1f;
    o->scale[3] = 0;
    func_0019FFD0(c, o, 0, 3);
    func_001A1D08(t, func_01B01008);
    func_001A1D50(t, func_001A20D8);
}

void func_01B01170(W3Task *t)
{
    RcefMainCtx *c = &D_00313CB0;

    func_0019FF90(c, func_01B011D0);
    func_0019FF90(c, func_01B01288);
    t->flags |= 4;
}

void func_01B011D0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    RcefMainCtx *c = &D_00313CB0;

    func_001A1378(o, c->caster, 0x18);
    o->pos[0] = 0.0f;
    o->pos[1] = 23.0f;
    o->pos[2] = 0.0f;
    o->pos_w = 0;
    o->rot[0] = 180.0f;
    o->rot[1] = 0.0f;
    o->rot[2] = 0.0f;
    o->rot[3] = 0;
    o->scale[0] = 0.02f;
    o->scale[1] = 0.02f;
    o->scale[2] = 0.02f;
    o->scale[3] = 0;
    func_0019FFD0(c, o, 0, 4);
    func_001A1D08(t, func_01B01008);
    func_001A1D50(t, func_001A20D8);
}

void func_01B01288(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    RcefMainCtx *c = &D_00313CB0;

    func_001A1378(o, c->caster, 0x25);
    o->pos[0] = 0.0f;
    o->pos[1] = -23.0f;
    o->pos[2] = 0.0f;
    o->pos_w = 0;
    o->scale[0] = 0.02f;
    o->scale[1] = 0.02f;
    o->scale[2] = 0.02f;
    o->scale[3] = 0;
    func_0019FFD0(c, o, 0, 4);
    func_001A1D08(t, func_01B01008);
    func_001A1D50(t, func_001A20D8);
}

void func_01B01328(W3Task *t)
{
    float p0[4];
    float p1[4];
    float vel[4];
    float acc[4];
    RcefObj *o = (RcefObj *)t;
    int idx = t->frame[t->sp].count;
    float g = 0.6f;
    float z;

    VEC3_COPY(p0, o->pos);
    VEC3_COPY(p1, D_01B01970[idx]);
    VEC3_SUB(vel, p1, p0);
    VEC3_SCALE(vel, vel, 1.0f / 30.0f);
    vel[1] -= 9.6f;
    z = 0.0f;
    acc[3] = z;
    acc[2] = z;
    acc[0] = z;
    acc[1] = g;
    o->vel[0] = vel[0];
    o->vel[1] = vel[1];
    o->vel[2] = vel[2];
    o->vel[3] = z;
    o->acc[0] = z;
    o->acc[1] = g;
    o->acc[2] = z;
    o->acc[3] = z;
    o->scale[0] = 0.06f;
    o->scale[1] = 0.06f;
    o->scale[2] = 0.06f;
    o->scale[3] = z;
    func_0019FFD0(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B01468);
    func_001A1DF0(t, 20);
}

void func_01B01468(W3Task *t)
{
    int idx = t->frame[t->sp].count;
    RcefObj *o;
    float ang;
    float *p;

    if (idx & 1) {
        o = (RcefObj *)func_0019FF90_t(&D_00313CB0, func_01B01650);
    } else {
        o = (RcefObj *)func_0019FF90_t(&D_00313CB0, func_01B01590);
    }
    ang = func_001A31D0(D_01B019B0[idx / 2]);
    p = D_01B01970[idx];
    o->pos[0] = p[0];
    o->pos[1] = p[1] - 0.1f;
    o->pos[2] = p[2];
    ((float *)&o->pos_w)[0] = 0.0f;
    o->rot[0] = 0.0f;
    o->rot[1] = (-ang - 1.5707964f) * 57.29578f;
    o->rot[2] = 0.0f;
    o->rot[3] = 0;
    func_001A1D08(t, func_01B01008);
    func_001A1DF0(t, 10);
}

void func_01B01590(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A1420(o, 0x40);
    o->scale[0] = 0.05f;
    o->scale[1] = 0.05f;
    o->scale[2] = 0.05f;
    o->scale[3] = 0;
    func_0019FFD0(&D_00313CB0, o, 0, 2);
    func_001A1D08(t, func_01B01608);
    func_001A1DF0(t, 9);
}
