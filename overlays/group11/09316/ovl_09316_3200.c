/* EE Battle-Effect Overlay: group 0x11, file 09316 (0x01B03200..0x01B03380)
 * Shared across open battle-effect containers (2 functions, 384 bytes)
 */
#include "common.h"

typedef struct Node3200 Node3200;
struct Node3200 {
    void **vtable;       /* 0x00 */
    Node3200 *prev;      /* 0x04 */
    Node3200 *next;      /* 0x08 */
    Node3200 *child_h;   /* 0x0C */
    Node3200 *child_t;   /* 0x10 */
    Node3200 *parent;    /* 0x14 */
    u16 child_cnt;       /* 0x18 */
    u8 flag1A;           /* 0x1A */
    u8 flag1B;           /* 0x1B */
    u8 pad1C[4];         /* 0x1C */
    u8 items[8][0xA0];   /* 0x20 */
    int count;           /* 0x520 */
    int chr;             /* 0x524 */
    int unk528;          /* 0x528 */
};

typedef struct CtorArg3200 {
    Node3200 *self;
    Node3200 *parent;
    int unk08;
    int chr;
} CtorArg3200;

extern void *D_01B01DA0[];

u8 *func_001E4F58(int chr, int *out_cnt);
void func_01B04A38(void *m);
void func_01B04BE0(void *m);
void func_01B04AD8(void *m);

void func_01B03200(CtorArg3200 *a0)
{
    struct {
        u8 *item;
        Node3200 *parent;
        int idx;
        u8 flag;
    } m;
    Node3200 *s = a0->self;
    Node3200 *p = a0->parent;
    u8 *list;
    int i;
    u8 *it;

    s->vtable = D_01B01DA0;
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
    s->unk528 = a0->unk08;
    s->chr = a0->chr;
    list = func_001E4F58(a0->chr, &s->count);
    for (i = 0; i < s->count; i++) {
        int idx = list[i];
        m.item = s->items[i];
        m.parent = a0->parent;
        m.idx = idx;
        m.flag = 0;
        func_01B04A38(&m);
    }
}

void func_01B03308(Node3200 **a0)
{
    u8 *m0;
    u8 *m1;
    Node3200 *s = *a0;
    u8 *it = s->items[0];
    int i;

    for (i = 0; i < s->count; i++, it += 0xA0) {
        m0 = it;
        func_01B04BE0(&m0);
        m1 = it;
        func_01B04AD8(&m1);
    }
}
