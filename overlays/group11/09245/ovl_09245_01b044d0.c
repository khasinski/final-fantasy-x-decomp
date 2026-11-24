#include "common.h"

typedef struct Node44D0 Node44D0;
struct Node44D0 {
    void *vtable;     /* 0x00 */
    Node44D0 *prev;   /* 0x04 */
    Node44D0 *next;   /* 0x08 */
    Node44D0 *last;   /* 0x0C */
    Node44D0 *first;  /* 0x10 */
    Node44D0 *parent; /* 0x14 */
    u16 count;        /* 0x18 */
    u8 tag;           /* 0x1A */
    u8 f1B;           /* 0x1B */
    float f1C;        /* 0x1C */
    float f20;        /* 0x20 */
    float f24;        /* 0x24 */
    float f28;        /* 0x28 */
    float f2C;        /* 0x2C */
    u8 f30;           /* 0x30 */
};

typedef struct {
    Node44D0 *node;
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    int f18;
} Msg44D0;

typedef struct {
    Node44D0 *node;
    Node44D0 *parent;
} Msg4530;

extern u8 D_01B025B0[];

void func_01B044D0(Msg44D0 *a0)
{
    Node44D0 *n = a0->node;

    n->f1C = a0->f04;
    n->f20 = a0->f08 - a0->f04;
    n->f24 = a0->f0C;
    n->f28 = a0->f10 - a0->f0C;
    n->f2C = a0->f14;
    n->f30 |= 1;
    if (a0->f18 != 0) {
        n->f30 |= 2;
    }
}

void func_01B04530(Msg4530 *a0)
{
    Node44D0 *n = a0->node;
    Node44D0 *p = a0->parent;

    n->vtable = D_01B025B0;
    n->tag = 0xFF;
    n->first = n;
    n->last = n;
    n->parent = p;
    n->f1B = 0;

    if (p != 0) {
        n->prev = p;
        n->next = p->first;
        if (p->first == p) {
            p->last = n;
        } else {
            p->first->prev = n;
        }
        p->first = n;
        p->count++;
    }

    n->f30 = 0;
}
