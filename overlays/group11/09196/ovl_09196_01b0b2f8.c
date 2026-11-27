#include "common.h"

typedef struct RingNode {
    void *vtbl;
    struct RingNode *prev;
    struct RingNode *next;
    struct RingNode *head;
    struct RingNode *tail;
    struct RingNode *parent;
    u16 count;
    u8 b1A;
    u8 b1B;
    u16 cap;        /* 0x1C */
    u16 elemSize;   /* 0x1E */
    u8 *data;       /* 0x20 */
    u8 *readPtr1;   /* 0x24 */
    u8 *readPtr2;   /* 0x28 */
    u16 readCnt1;   /* 0x2C */
    u16 readCnt2;   /* 0x2E */
    u16 writeIdx;   /* 0x30 */
    u16 used;       /* 0x32 */
    u16 readIdx;    /* 0x34 */
    u16 pad36;
    void *p38;      /* 0x38 */
} RingNode;

typedef struct ArgB2F8 {
    RingNode *n;
    RingNode *p;
    u8 *data;
    u16 cap;
    u16 elemSize;
    void *p38;
} ArgB2F8;

typedef struct ArgB390 {
    RingNode *buf;  /* 0x00 */
    u16 req;        /* 0x04 */
    u16 cnt1;       /* 0x06 */
    u16 cnt2;       /* 0x08 */
    u16 pad0A;
    u8 *ptr1;       /* 0x0C */
    u8 *ptr2;       /* 0x10 */
} ArgB390;

extern u8 D_01B05D70[];

void func_01B0B2F8(ArgB2F8 *a)
{
    RingNode *n = a->n;
    RingNode *p = a->p;
    n->vtbl = D_01B05D70;
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
    a->n->cap = a->cap;
    a->n->p38 = a->p38;
    a->n->data = a->data;
    a->n->elemSize = a->elemSize;
    a->n->used = 0;
    a->n->writeIdx = 0;
    a->n->readIdx = 0;
}
