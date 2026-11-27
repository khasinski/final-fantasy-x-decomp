#include "common.h"

extern u8 D_01B023A0;

extern int func_002DD0B0(void *, void *);
extern void func_002DD0C0(void *, void *);

typedef struct Node {
    void *vtbl;
    struct Node *next;
    struct Node *prev;
    struct Node *first;
    struct Node *last;
    struct Node *parent;
    u16 count;
    u8 flag1A;
    u8 flag1B;
    u8 pad1C[0x44];
    float m60[4][4];
    float mA0[4][4];
    float mE0[4][4];
    u8 pad120[0x10];
    float v130[4];
} Node;

typedef struct {
    Node *node;
    Node *parent;
    Node *src;
} NodeArgs;

int func_01B03BA8(NodeArgs *args)
{
    Node *n = args->node;
    Node *p = args->parent;

    n->vtbl = &D_01B023A0;
    n->flag1A = 0xFF;
    n->last = n;
    n->first = n;
    n->parent = p;
    n->flag1B = 0;
    if (p != 0) {
        n->next = p;
        n->prev = p->last;
        if (p->last == p) {
            p->first = n;
        } else {
            p->last->next = n;
        }
        p->last = n;
        p->count++;
    }
    func_002DD0C0(n->m60, args->src->m60);
    func_002DD0C0(n->mA0, args->src->mA0);
    func_002DD0C0(n->mE0, args->src->mE0);
    return func_002DD0B0(n->v130, args->src->v130);
}
