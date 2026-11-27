#include "common.h"

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
    u8 pad1C[0xF4];
    int w110;
    int w114;
    int w118;
    float f11C;
    u8 pad120[0x20];
    int w140;
    int w144;
    int w148;
    int w14C;
    u8 f150[0x10];
    u8 f160[0x10];
    u8 f170[0x10];
    u8 f180[0x50];
    u8 f1D0[0x10];
    float f1E0;
    float f1E4;
    float f1E8;
    int w1EC;
    int w1F0;
    int w1F4;
    int w1F8;
    int w1FC;
    int w200;
    int w204;
} Node;

typedef struct {
    Node *n;
    float f04;
    int w08;
} Arg4148;

typedef struct {
    Node *n;
    Node *p;
    int w08;
    int w0C;
    int w10;
    int w14;
    int w18;
    int w1C;
} Arg4178;

typedef struct {
    Node *n;
} Arg42B8;

extern u8 D_01B020E0[];
extern void func_001072F8(int, int, void *);
extern void func_00110C30(int, int, float);
extern void func_002DD068(void *, void *, float);
extern void func_002DD0B0(void *, void *);

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

void func_01B04148(Arg4148 *a)
{
    Node *n = a->n;
    n->w1FC = 1;
    n->w200 = 0;
    n->f1E4 = a->f04 - n->f1E8;
    n->f1E0 = n->f1E8;
    n->w204 = a->w08;
}
