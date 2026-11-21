/* Shared P6 -O2 helper: character group node init (hash a3c1ad, 272B). */
#include "p6_overlay.h"

typedef struct {
    u8 pad00[0xA0];
} P6ChrSlot;

typedef struct {
    P6Node node;            /* 0x000 */
    u8 pad1C[4];            /* 0x01C */
    P6ChrSlot slots[8];     /* 0x020 */
    int count;              /* 0x520 */
    u8 *ids;                /* 0x524 */
    void *w528;             /* 0x528 */
    int w52C;               /* 0x52C */
    u8 b530;                /* 0x530 */
} P6ChrGroup;

typedef struct {
    P6ChrGroup *obj;        /* 0x00 */
    P6Node *parent;         /* 0x04 */
    int w08;                /* 0x08 */
    void *w0C;              /* 0x0C */
    u8 b10;                 /* 0x10 */
} P6ChrGroupArg;

typedef struct {
    void *w00;
    void *w04;
    int w08;
    u8 b0C;
} P6ChrSlotArg;

extern P6NodeVt D_01B025B0;
extern void func_01B04870(void *);
extern u8 *func_001E53D0(int, int *);

void func_01B032C0(P6ChrGroupArg *arg)
{
    P6ChrSlotArg msg;
    P6ChrGroup *s0 = arg->obj;
    P6Node *parent = arg->parent;
    int i;

    s0->node.vt = &D_01B025B0;
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
    /* DEBT(FAKE): volatile store/load preserves sw w528 before lw arg->w08. */
    *(void * volatile *)&s0->w528 = arg->w0C;
    s0->w52C = *(volatile int *)&arg->w08;
    s0->b530 = arg->b10;
    if (s0->b530 & 1) {
        s0->ids = func_001E53D0(s0->w52C, &s0->count);
    } else {
        s0->ids = func_001E53D0(s0->w52C, &s0->count);
    }
    for (i = 0; i < s0->count; i++) {
        int id = s0->ids[i];
        msg.w00 = &s0->slots[i];
        msg.w04 = arg->parent;
        msg.w08 = id;
        msg.b0C = 0;
        func_01B04870(&msg);
    }
}
