#include "common.h"

typedef struct MsgDCA8 MsgDCA8;
typedef struct NodeDCA8 NodeDCA8;

typedef struct {
    u8 pad00[0x1C];
    void (*fn1C)(MsgDCA8 *);
} VtableDCA8;

struct NodeDCA8 {
    VtableDCA8 *vtable; /* 0x00 */
    u8 pad04[0x04];     /* 0x04 */
    NodeDCA8 *next;     /* 0x08 */
    u8 pad0C[0x04];     /* 0x0C */
    NodeDCA8 *first;    /* 0x10 */
    u8 pad14[0x06];     /* 0x14 */
    u8 tag;             /* 0x1A */
    u8 pad1B[0x05];     /* 0x1B */
    u8 v20[0x10];       /* 0x20 */
    void *p30;          /* 0x30 */
    float f34;          /* 0x34 */
    int f38;            /* 0x38 */
};

struct MsgDCA8 {
    NodeDCA8 *node;
    u8 flags;
    u8 tag;
};

typedef struct {
    void *p0;
    void *p4;
    float f8;
    int fC;
} MsgF768;

extern void func_01B0F768(MsgF768 *);

void func_01B0DCA8(MsgDCA8 *a0)
{
    NodeDCA8 *node = a0->node;

    if (node->tag == a0->tag) {
        a0->flags = 0;
    } else {
        NodeDCA8 *c = node->first;
        while (c != node) {
            a0->node = c;
            c = c->next;
            a0->node->vtable->fn1C(a0);
        }
        a0->node = node;
        node->tag = a0->tag;
        a0->flags = 1;
    }

    if (a0->flags & 1) {
        NodeDCA8 *s0 = a0->node;
        if (s0->p30 != 0) {
            MsgF768 m;
            m.p0 = s0->p30;
            m.p4 = s0->v20;
            m.f8 = s0->f34;
            func_01B0F768(&m);
            if (m.fC != 0) {
                s0->f38 |= 1;
            } else {
                s0->f38 &= ~1;
            }
        }
    }
}
