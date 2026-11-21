/* Shared P6 -O2 helper: 64-slot character group node init (hash 00bd78, 272B). */
#include "p6_overlay.h"

typedef struct {
    u8 pad00[0xA0];
} P6ChrSlot;

typedef struct {
    P6Node node;            /* 0x0000 */
    u8 pad1C[4];            /* 0x001C */
    P6ChrSlot slots[64];    /* 0x0020 */
    int count;              /* 0x2820 */
    u8 *ids;                /* 0x2824 */
    void *w2828;            /* 0x2828 */
    int w282C;              /* 0x282C */
    u8 b2830;               /* 0x2830 */
} P6ChrGroup64;

typedef struct {
    P6ChrGroup64 *obj;      /* 0x00 */
    P6Node *parent;         /* 0x04 */
    int w08;                /* 0x08 */
    void *w0C;              /* 0x0C */
    u8 b10;                 /* 0x10 */
} P6ChrGroupArg64;

typedef struct {
    void *w00;
    void *w04;
    int w08;
    u8 b0C;
} P6ChrSlotArg;

extern P6NodeVt D_01B0EBF0;
extern void func_01B10E90(void *);
extern u8 *func_001E5728(int, int *, int);

void func_01B0F8E0(P6ChrGroupArg64 *arg)
{
    P6ChrSlotArg msg;
    P6ChrGroup64 *s0 = arg->obj;
    P6Node *parent = arg->parent;
    int i;

    s0->node.vt = &D_01B0EBF0;
    s0->node.mark = 255;
    s0->node.first = s0->node.last = &s0->node;
    s0->node.parent = parent;
    s0->node.b1B = 0;
    if (parent != 0) {
        s0->node.next = parent;
        s0->node.prev = parent->last;
        if (parent->last == parent) {
            parent->first = &s0->node;
        } else {
            parent->last->next = &s0->node;
        }
        parent->last = &s0->node;
        parent->count++;
    }
    /* DEBT(FAKE): volatile store/load preserves sw w2828 before lw arg->w08. */
    *(void * volatile *)&s0->w2828 = arg->w0C;
    s0->w282C = *(volatile int *)&arg->w08;
    s0->b2830 = arg->b10;
    s0->ids = func_001E5728(s0->w282C, &s0->count, 1);
    for (i = 0; i < s0->count; i++) {
        int id = s0->ids[i];
        msg.w00 = &s0->slots[i];
        msg.w04 = arg->parent;
        msg.w08 = id;
        msg.b0C = 0;
        func_01B10E90(&msg);
    }
}
