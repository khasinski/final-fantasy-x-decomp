#include "p6_overlay.h"
#include "vu0.h"

extern void *D_01B00048;
extern void *func_002B2F30(void *, int, int, int);
extern void func_002DD038(void *, void *, void *);
extern void func_01B04368(void *);

typedef struct {
    P6Node node;        /* 0x00 */
    u8 pad1C[4];
    float v20[4];       /* 0x20 */
    float v30[4];       /* 0x30 */
    float v40[4];       /* 0x40 */
    float t50;          /* 0x50 */
    float dt54;         /* 0x54 */
    int cnt58;          /* 0x58 */
    u16 flags5C;        /* 0x5C */
    u8 b5E;             /* 0x5E */
} Obj4120;

void func_01B04120(P6Iter *it)
{
    P6Node *n = it->cur;
    P6Node *c;
    Obj4120 *o;
    int col[4];
    void *msg;

    if (n->mark == it->mark) {
        it->done = 0;
    } else {
        c = n->last;
        while (c != n) {
            it->cur = c;
            c = c->prev;
            it->cur->vt->fn[7](it);
        }
        it->cur = n;
        n->mark = it->mark;
        it->done = 1;
    }

    if (it->done & 1) {
        o = (Obj4120 *)it->cur;
        if (o->cnt58 != 0) {
            float *p20 = o->v20;
            float *p40 = o->v40;
            float *p50 = &o->t50;
            VU0_LQC2_INPUTS(30, p40, p20, p50);
            VU0_LQC2(31, 0x0, p20);
            VU0_LQC2(29, 0x0, p50);
            VU0_OP("vmuly.xyzw $vf30, $vf30, $vf29y");
            VU0_OP("vadd.xyzw $vf31, $vf31, $vf30");
            VU0_SQC2(31, 0x0, p20);
            VU0_OP("vftoi0.xyzw $vf31, $vf31");
            VU0_SQC2(31, 0x0, col);
            VU0_OP("vaddy.x $vf29, $vf29, $vf29y");
            VU0_SQC2(29, 0x0, p50);
            D_01B00048 = func_002B2F30(
                D_01B00048,
                (col[0] | (col[2] << 16)) | ((col[3] << 24) | (col[1] << 8)),
                o->b5E,
                0x80
            );
            if (o->t50 >= 0.999f) {
                func_002DD038(p20, o->v30, p40);
                o->t50 = 0.0f;
                o->cnt58--;
            }
        } else if (o->flags5C & 1) {
            msg = o;
            func_01B04368(&msg);
        }
    }
}

typedef struct {
    Obj4120 *o;
    float dt;
    int cnt;
} Arg42A8;

void func_01B042A8(Arg42A8 *a)
{
    Obj4120 *o = a->o;
    func_002DD038(o->v40, o->v30, o->v20);
    o->dt54 = a->dt;
    o->cnt58 = a->cnt;
    o->t50 = 0.0f;
}
