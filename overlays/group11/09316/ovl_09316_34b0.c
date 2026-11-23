/* EE Battle-Effect Overlay: group 0x11, file 09316 (0x01B034B0..0x01B03630)
 * Shared across open battle-effect containers (3 functions, 372 bytes)
 */
#include "common.h"

typedef struct Node34C8 Node34C8;
struct Node34C8 {
    void **vtable;       /* 0x00 */
    Node34C8 *prev;      /* 0x04 */
    Node34C8 *next;      /* 0x08 */
    Node34C8 *child_h;   /* 0x0C */
    Node34C8 *child_t;   /* 0x10 */
    Node34C8 *parent;    /* 0x14 */
    u16 child_cnt;       /* 0x18 */
    u8 flag1A;           /* 0x1A */
    u8 flag1B;           /* 0x1B */
    int p1C;             /* 0x1C */
    void *f20;           /* 0x20 */
    int flags;           /* 0x24 */
};

typedef struct CtorArg34C8 {
    Node34C8 *self;
    Node34C8 *parent;
    int p1C;
    void *f20;
} CtorArg34C8;

typedef struct UpdArg3540 {
    Node34C8 *obj;
    u8 f4;
    u8 f5;
} UpdArg3540;

extern void *D_01B01DC0[];

void func_00103788(int a0);
void func_01B03448(void *m);
void func_01B03308(void *m);
void func_01B03668(void *m);
void func_01B03538(void *m);

void func_01B034B0(Node34C8 **a0)
{
    (*a0)->flags |= 1;
}

void func_01B034C8(CtorArg34C8 *a0)
{
    Node34C8 *s = a0->self;
    Node34C8 *p = a0->parent;

    s->vtable = D_01B01DC0;
    s->flag1A = 0xFF;
    s->child_t = s;
    s->child_h = s;
    s->parent = p;
    s->flag1B = 0;
    if (p != 0) {
        s->prev = p;
        s->next = p->child_t;
        if (p->child_t == p) {
            p->child_h = s;
        } else {
            p->child_t->prev = s;
        }
        p->child_t = s;
        p->child_cnt++;
    }
    s->p1C = a0->p1C;
    s->f20 = a0->f20;
}

void func_01B03538(void *m)
{
    (void)m;
}

void func_01B03540(UpdArg3540 *a0)
{
    void *m0;
    void *m1;
    void *m2;
    void *m3;
    Node34C8 *s = a0->obj;
    Node34C8 *c;

    if (s->flag1A == a0->f5) {
        a0->f4 = 0;
    } else {
        c = s->child_t;
        while (c != s) {
            a0->obj = c;
            c = c->next;
            ((void (*)(UpdArg3540 *))a0->obj->vtable[7])(a0);
        }
        a0->obj = s;
        s->flag1A = a0->f5;
        a0->f4 = 1;
    }

    if (a0->f4 & 1) {
        Node34C8 *o = a0->obj;
        func_00103788((int)o->f20);
        if (o->flags & 1) {
            m0 = (void *)o->p1C;
            func_01B03448(&m0);
            m1 = (void *)o->p1C;
            func_01B03308(&m1);
            m2 = o;
            func_01B03668(&m2);
            m3 = o;
            func_01B03538(&m3);
        }
    }
}
