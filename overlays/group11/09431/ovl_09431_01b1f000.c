#include "common.h"

typedef struct MsgF000 MsgF000;
typedef struct NodeF000 NodeF000;

struct NodeF000 {
    void **vtable;   /* 0x00 */
    u8 pad04[0x04];  /* 0x04 */
    NodeF000 *next;  /* 0x08 */
    u8 pad0C[0x04];  /* 0x0C */
    NodeF000 *first; /* 0x10 */
    u8 pad14[0x06];  /* 0x14 */
    u8 tag;          /* 0x1A */
    u8 pad1B[0x05];  /* 0x1B */
    float v20[3];    /* 0x20 */
    float f2C;       /* 0x2C */
    NodeF000 *p30;   /* 0x30 */
};

struct MsgF000 {
    NodeF000 *node;
    u8 flags;
    u8 tag;
    u8 pad[10];
};

typedef struct {
    void *p0;
    u16 h4;
    u16 h6;
    u8 pad8[4];
    u8 *pC;
} QueryF000;

extern void g_fn_1f758(void *);
extern void g_fn_1f1c0(void *);
extern void func_002DD0B0(void *, void *);

void func_01B1F000(MsgF000 *a0)
{
    NodeF000 *node = a0->node;

    if (node->tag == a0->tag) {
        a0->flags = 0;
    } else {
        NodeF000 *c = node->first;
        while (c != node) {
            a0->node = c;
            c = c->next;
            ((void (*)(MsgF000 *))a0->node->vtable[7])(a0);
        }
        a0->node = node;
        node->tag = a0->tag;
        a0->flags = 1;
    }

    if (a0->flags & 1) {
        QueryF000 m0;
        MsgF000 m1;
        void *m2[4];
        NodeF000 *s0 = a0->node;

        m1.node = s0->p30;
        m1.tag = a0->tag;
        ((void (*)(MsgF000 *))m1.node->vtable[7])(&m1);

        m0.p0 = s0->p30;
        g_fn_1f758(&m0);
        if (m0.h4 == 0) {
            m2[0] = s0->p30;
            m2[1] = s0->v20;
            g_fn_1f1c0(m2);
        } else {
            func_002DD0B0(s0->v20, m0.pC + (m0.h6 * 0x10 - 0x10));
            s0->f2C = 1.0f;
        }
    }
}
