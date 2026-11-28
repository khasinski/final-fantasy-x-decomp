#include "p6_overlay.h"

typedef struct ObjA780 {
    P6Node node;        /* 0x00 */
    u8 pad1C[4];
    float v[4];         /* 0x20 */
    float f30;          /* 0x30 */
    float f34;          /* 0x34 */
    float f38;          /* 0x38 */
} ObjA780;

extern void func_01B0AB78(P6Iter *);
extern void func_002DD020(void *, void *, void *);
extern void func_01B0ABB8(void *, void *, float);
extern void func_01B0AC00(void *, void *, void *);
extern void func_002DD0B0(void *, void *);

void func_01B0A780(register P6Iter *s0)
{
    float v[4];
    float w[4];
    ObjA780 *o;
    ObjA780 *p;
    float t;
    float k;

    func_01B0AB78(s0);
    if (!((u8)(s0->done & 1))) {
        return;
    }
    o = (ObjA780 *)s0->cur;
    p = (ObjA780 *)o->node.parent;
    func_002DD020(v, p->v, o->v);
    if (v[1] > o->f38) {
        v[1] = v[1] - o->f38;
        t = v[1] / o->v[1];
        func_01B0ABB8(w, o->v, t);
        func_01B0AC00(v, o->v, w);
        k = -o->f30;
        o->v[1] = w[1] * k;
        v[1] = o->f38 + w[1] * k;
        k = o->f34;
        o->v[0] = w[0] * k;
        o->v[2] = w[2] * k;
        v[0] = v[0] + (p->v[0] + w[0] * k);
        v[2] = v[2] + (p->v[2] + w[2] * k);
    }
    func_002DD0B0(p->v, v);
}
