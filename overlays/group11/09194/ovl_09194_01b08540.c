#include "common.h"

typedef struct Msg8540 Msg8540;
typedef struct Node8540 Node8540;

struct Node8540 {
    void **vtable;   /* 0x00 */
    u8 pad04[0x04];  /* 0x04 */
    Node8540 *next;  /* 0x08 */
    u8 pad0C[0x04];  /* 0x0C */
    Node8540 *first; /* 0x10 */
    u8 pad14[0x06];  /* 0x14 */
    u8 tag;          /* 0x1A */
    u8 pad1B[0x05];  /* 0x1B */
    u8 v20[0xB0];    /* 0x20 */
    u8 mD0[0x30];    /* 0xD0 */
    u8 v100[0x130];  /* 0x100 */
    u8 v230[0x10];   /* 0x230 */
    Node8540 *p240;  /* 0x240 */
    u8 pad244[0x0C];
    u8 v250[0x10];   /* 0x250 */
    int w260;        /* 0x260 */
    u8 flags264;     /* 0x264 */
};

struct Msg8540 {
    Node8540 *node;
    u8 flags;
    u8 tag;
    u8 pad06[0x0A];
};

extern void func_001A7840(int, int, void *);
extern void func_002DCE08(void *, void *, void *);

void func_01B08540(Msg8540 *a0)
{
    Node8540 *node = a0->node;

    if (node->tag == a0->tag) {
        a0->flags = 0;
    } else {
        Node8540 *c = node->first;
        while (c != node) {
            a0->node = c;
            c = c->next;
            ((void (*)(Msg8540 *))a0->node->vtable[7])(a0);
        }
        a0->node = node;
        node->tag = a0->tag;
        a0->flags = 1;
    }

    if (a0->flags & 1) {
        Node8540 *s0 = a0->node;
        if (s0->flags264 & 1) {
            if (s0->flags264 & 2) {
                func_001A7840(s0->w260, 0, s0->v250);
            } else if (s0->p240 != 0) {
                Msg8540 m;
                m.node = s0->p240;
                m.tag = a0->tag;
                ((void (*)(Msg8540 *))m.node->vtable[7])(&m);
                func_001A7840(s0->w260, 0, s0->p240->v20);
            }
        } else {
            func_002DCE08(s0->v20, s0->mD0, s0->v230);
            func_001A7840(s0->w260, 0, s0->v100);
        }
        func_001A7840(s0->w260, 1, s0->v20);
    }
}
