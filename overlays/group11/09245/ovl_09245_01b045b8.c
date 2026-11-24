#include "common.h"

typedef struct Msg45B8 Msg45B8;
typedef struct Node45B8 Node45B8;

struct Node45B8 {
    void **vtable;  /* 0x00 */
    u8 pad04[0x04]; /* 0x04 */
    Node45B8 *next; /* 0x08 */
    u8 pad0C[0x04]; /* 0x0C */
    Node45B8 *first;/* 0x10 */
    u8 pad14[0x06]; /* 0x14 */
    u8 tag;         /* 0x1A */
    u8 pad1B;       /* 0x1B */
    float f1C;      /* 0x1C */
    float f20;      /* 0x20 */
    float f24;      /* 0x24 */
    float f28;      /* 0x28 */
    float f2C;      /* 0x2C */
    u8 flags;       /* 0x30 */
};

struct Msg45B8 {
    Node45B8 *node;
    u8 flags;
    u8 tag;
};

extern float func_001ACED8(void);
extern int func_001ACEA0(void);
extern void func_001AAC18(float, float);
extern void func_01B04778(void *);
extern void func_01B04598(void *);

void func_01B045B8(Msg45B8 *a0)
{
    void *m0;
    void *m1;
    Node45B8 *node = a0->node;

    if (node->tag == a0->tag) {
        a0->flags = 0;
    } else {
        Node45B8 *c = node->first;
        while (c != node) {
            a0->node = c;
            c = c->next;
            ((void (*)(Msg45B8 *))a0->node->vtable[7])(a0);
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
                func_001AAC18(x, y);
            } else {
                node->flags &= ~1;
                if (node->flags & 2) {
                    m0 = node;
                    func_01B04778(&m0);
                    m1 = node;
                    func_01B04598(&m1);
                }
            }
        }
    }
}
