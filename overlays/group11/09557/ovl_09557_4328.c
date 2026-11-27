#include "common.h"

typedef struct {
    u8 pad00[0x1C];
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    u8 pad34[0x04];
    float f38;
    float f3C;
    u8 b40;
} Target4328;

typedef struct {
    Target4328 *dst;
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    int w20;
} Arg4328;

typedef struct Node {
    void *vtbl;
    struct Node *prev;
    struct Node *next;
    struct Node *head;
    struct Node *tail;
    struct Node *parent;
    u16 count;
    u8 b1A;
    u8 b1B;
    u8 pad1C[0x18];
    int w34;
    u8 pad38[0x08];
    u8 b40;
} Node;

typedef struct {
    Node *n;
    Node *p;
} Arg43A8;

extern u8 D_01B02310[];
extern float func_001AAC18(float, float);

void func_01B04328(Arg4328 *a)
{
    Target4328 *d = a->dst;
    d->f1C = a->f04;
    d->f20 = a->f08 - a->f04;
    d->f24 = a->f0C;
    d->f28 = a->f10 - a->f0C;
    d->f30 = a->f1C;
    d->f2C = a->f1C;
    d->f38 = a->f18;
    d->f3C = a->f18 - a->f14;
    d->b40 |= 1;
    if (a->w20 != 0) {
        d->b40 |= 2;
    }
}

static inline void init_node(Node *n, Node *p, void *vtbl)
{
    n->vtbl = vtbl;
    n->b1A = 0xFF;
    n->tail = n;
    n->head = n;
    n->parent = p;
    n->b1B = 0;
    if (p != 0) {
        n->prev = p;
        n->next = p->tail;
        if (p->tail == p) {
            p->head = n;
        } else {
            p->tail->prev = n;
        }
        p->tail = n;
        p->count++;
    }
}

void func_01B043A8(Arg43A8 *a)
{
    Node *n = a->n;
    init_node(n, a->p, D_01B02310);
    n->b40 = 0;
    n->w34 = 0;
}
