#include "common.h"

typedef struct MsgDEA8 MsgDEA8;
typedef struct NodeDEA8 NodeDEA8;

struct NodeDEA8 {
    void **vtable;   /* 0x00 */
    u8 pad04[0x04];  /* 0x04 */
    NodeDEA8 *next;  /* 0x08 */
    u8 pad0C[0x04];  /* 0x0C */
    NodeDEA8 *first; /* 0x10 */
    u8 pad14[0x06];  /* 0x14 */
    u8 tag;          /* 0x1A */
    u8 pad1B[0x05];  /* 0x1B */
    u8 v20[0x0C];    /* 0x20 */
    float f2C;       /* 0x2C */
    NodeDEA8 *p30;   /* 0x30 */
};

struct MsgDEA8 {
    NodeDEA8 *node;
    u8 flags;
    u8 tag;
    u8 pad06[0x0A];
};

typedef struct {
    void *p0;
    void *p4;
    void *p8;
} ArgDEA8;

extern u8 D_01B00A40[];
extern void func_01B0E040(ArgDEA8 *);

void func_01B0DEA8(MsgDEA8 *a0)
{
    NodeDEA8 *node = a0->node;

    if (node->tag == a0->tag) {
        a0->flags = 0;
    } else {
        NodeDEA8 *c = node->first;
        while (c != node) {
            a0->node = c;
            c = c->next;
            ((void (*)(MsgDEA8 *))a0->node->vtable[7])(a0);
        }
        a0->node = node;
        node->tag = a0->tag;
        a0->flags = 1;
    }

    if (a0->flags & 1) {
        NodeDEA8 *s0 = a0->node;
        if (s0->p30 != 0) {
            MsgDEA8 m;
            ArgDEA8 arg;
            m.node = s0->p30;
            m.tag = a0->tag;
            ((void (*)(MsgDEA8 *))m.node->vtable[7])(&m);
            arg.p0 = s0->p30;
            arg.p4 = s0->v20;
            arg.p8 = D_01B00A40;
            func_01B0E040(&arg);
            s0->f2C = 1.0f;
        }
    }
}
