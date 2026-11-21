#include "rcef_overlay.h"

W3Task *func_0019FF90_t(RcefMainCtx *, W3TaskFn) __asm__("func_0019FF90");

extern float D_01B01AA4;
extern int D_01B01AB4;
extern int D_01B01AB8;
extern float D_01B01AC0;

extern void func_01B00B68(RcefObj *, float, int, int);
extern void func_01B014D8(W3Task *);
extern void func_01B01630(W3Task *);

void func_01B011F8(W3Task *t)
{
    int i;
    int n = 20;
    float a;
    float ang;

    a = (float)(n - D_01B01AB4) / (float)n;
    D_01B01AC0 = a;
    if (a < 0.0f) {
        D_01B01AC0 = 0.0f;
    }
    ang = D_01B01AA4;
    for (i = 0; i < 2; i++) {
        RcefObj *o = (RcefObj *)func_0019FF90_t(&D_00313CB0, func_01B014D8);
        func_01B00B68(o, ang, i, 2);
    }
    D_01B01AB4++;
    if (D_01B01AB8 + 20 < D_01B01AB4) {
        t->flags |= 4;
    }
}

void func_01B01300(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float alpha;
    int cnt;

    alpha = D_01B01AC0 * 0.4f;
    cnt = t->frame[t->sp].count;
    if ((func_002EFD78() & 0xF) == 0) {
        W3Task *c = func_0019FF90_t(&D_00313CB0, func_01B01630);
        c->frame[c->sp].count = (int)t;
    }
    cnt++;
    if (cnt >= D_01B01AB8) {
        t->flags |= 4;
    } else {
        if (D_01B01AB8 - 5 < cnt) {
            alpha *= (float)(D_01B01AB8 - cnt) / 5.0f;
        }
        t->frame[t->sp].count = cnt;
    }
    o->unk170[3] = alpha;
}
