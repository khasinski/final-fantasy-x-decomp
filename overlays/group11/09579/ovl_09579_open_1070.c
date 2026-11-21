#include "rcef_overlay.h"

#define VEC3_COPY(d, a) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tsqc2 $vf31, 0(%0)" : : "r"(d), "r"(a) : "memory")

W3Task *func_0019FF90_t(RcefMainCtx *, W3TaskFn) __asm__("func_0019FF90");

extern float D_01B01AA0[3];
extern int D_01B01AB4;

extern void func_01B00B68(RcefObj *, float, int, int);
extern void func_01B01400(W3Task *);
extern void func_01B014D8(W3Task *);
extern void func_01B014E0(W3Task *);

extern float func_001A3620(int, float, float, float);

void func_01B01070(W3Task *t)
{
    float pos[4];
    float vel[4];
    float ang;
    RcefObj *o;
    int i;

    ang = func_001A3620(1, D_01B01AA0[1], D_01B01AA0[2], (float)D_01B01AB4 / 38.0f);
    o = (RcefObj *)func_0019FF90_t(&D_00313CB0, func_01B01400);
    func_01B00B68(o, ang, 0, 2);
    if ((D_01B01AB4 & 0xF) == 0) {
        VEC3_COPY(pos, o->pos);
        VEC3_COPY(vel, o->vel);
        o = (RcefObj *)func_0019FF90_t(&D_00313CB0, func_01B014E0);
        o->pos[0] = pos[0];
        o->pos[1] = pos[1];
        o->pos[2] = pos[2];
        /* DEBT(CAST): RcefObj::pos_w is typed int; float store keeps strict-aliasing order with pos[0..2] */
        *(float *)&o->pos_w = 0.0f;
        o->vel[0] = vel[0];
        o->vel[1] = vel[1];
        o->vel[2] = vel[2];
        o->vel[3] = 0.0f;
    }
    for (i = 1; i < 2; i++) {
        RcefObj *o3 = (RcefObj *)func_0019FF90_t(&D_00313CB0, func_01B014D8);
        func_01B00B68(o3, ang, i, 2);
    }
    D_01B01AB4++;
    if (D_01B01AB4 >= 39) {
        t->flags |= 4;
    }
}
