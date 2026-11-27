#include "common.h"

typedef struct {
    u8 *p00;
    u8 b04;
    u8 pad05[3];
    float f08;
    u16 h0C;
    u16 h0E;
    u16 h10;
    u8 b12;
} Arg4DC8;

typedef struct Node4E48 {
    void *vtbl;
    struct Node4E48 *prev;
    struct Node4E48 *next;
    struct Node4E48 *tail;
    struct Node4E48 *head;
    struct Node4E48 *parent;
    u16 count;
    u8 b1A;
    u8 b1B;
} Node4E48;

typedef struct {
    Node4E48 *node;
    Node4E48 *parent;
} Arg4E48;

extern u8 D_01B02890[];

void func_01B04DC8(Arg4DC8 *a0)
{
    u8 *a3 = a0->p00;
    u8 flags = a3[0x2B] | 1;
    u16 h0C;
    u16 h10;

    a3[0x2A] = a0->b04;
    h0C = a0->h0C;
    *(u16 *)(a3 + 0x26) = h0C;
    *(float *)(a3 + 0x2C) = a0->f08;
    h10 = a0->h10;
    *(float *)(a3 + 0x1C) = (float)(s16)h0C;
    *(u16 *)(a3 + 0x28) = h10;
    *(u16 *)(a3 + 0x24) = a0->h0E - (h0C + h10);
    a3[0x2B] = flags;
    *(float *)(a3 + 0x20) = (float)(s16)h10;
    if (a0->b12 != 0) {
        a3[0x2B] = flags | 2;
    }
}

void func_01B04E48(Arg4E48 *a0)
{
    Node4E48 *n = a0->node;
    Node4E48 *p = a0->parent;

    n->vtbl = D_01B02890;
    n->b1A = 0xFF;
    n->head = n;
    n->tail = n;
    n->parent = p;
    n->b1B = 0;
    if (p != 0) {
        n->prev = p;
        n->next = p->head;
        if (p->head == p) {
            p->tail = n;
        } else {
            p->head->prev = n;
        }
        p->head = n;
        p->count++;
    }
}
