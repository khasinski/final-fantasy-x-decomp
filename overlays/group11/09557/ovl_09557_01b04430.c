#include "common.h"

typedef struct MsgB860 MsgB860;
typedef struct NodeB860 NodeB860;

struct NodeB860 {
    void **vtable;  /* 0x00 */
    u8 pad04[0x04]; /* 0x04 */
    NodeB860 *next; /* 0x08 */
    u8 pad0C[0x04]; /* 0x0C */
    NodeB860 *first;/* 0x10 */
    u8 pad14[0x06]; /* 0x14 */
    u8 tag;         /* 0x1A */
    u8 pad1B;       /* 0x1B */
    float f1C;      /* 0x1C */
    float f20;      /* 0x20 */
    float f24;      /* 0x24 */
    float f28;      /* 0x28 */
    float f2C;      /* 0x2C */
    float f30;      /* 0x30 */
    float f34;      /* 0x34 */
    float f38;      /* 0x38 */
    float f3C;      /* 0x3C */
    u8 flags;       /* 0x40 */
};

struct MsgB860 {
    NodeB860 *node;
    u8 flags;
    u8 tag;
};

extern float func_001ACED8(void);
extern int func_001ACEA0(void);
extern void func_001AAC18(float, float);
extern void func_01B0BA60(void *);
extern void func_01B0B840(void *);

void func_01B0B860(MsgB860 *a0)
{
    void *m0;
    void *m1;
    NodeB860 *node = a0->node;

    if (node->tag == a0->tag) {
        a0->flags = 0;
    } else {
        NodeB860 *c = node->first;
        while (c != node) {
            a0->node = c;
            c = c->next;
            ((void (*)(MsgB860 *))a0->node->vtable[7])(a0);
        }
        a0->node = node;
        node->tag = a0->tag;
        a0->flags = 1;
    }

    if (a0->flags & 1) {
        node = a0->node;
        if (node->flags & 1) {
            if (node->f2C-- != 0.0f) {
                float r = func_001ACED8() - 0.99f;
                int s1 = 1 - (func_001ACEA0() & 2);
                float x = (node->f1C + node->f20 * r) * (float)s1;
                int s2i = 1 - (func_001ACEA0() & 2);
                float y = (node->f24 + node->f28 * r) * (float)s2i;
                float amp = node->f38 - (node->f2C / node->f30) * node->f3C;
                node->f34 = amp;
                func_001AAC18(x * amp, y * amp);
            } else {
                node->flags &= ~1;
                if (node->flags & 2) {
                    m0 = node;
                    func_01B0BA60(&m0);
                    m1 = node;
                    func_01B0B840(&m1);
                }
            }
        } else {
            func_001AAC18(0.0f, 0.0f);
        }
    }
}
