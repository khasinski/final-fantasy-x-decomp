#include "common.h"

typedef struct Msg10DF8 Msg10DF8;
typedef struct Node10DF8 Node10DF8;

typedef struct {
    u8 pad00[0x1C];
    void (*fn1C)(Msg10DF8 *);
} Vtable10DF8;

struct Node10DF8 {
    Vtable10DF8 *vtable;
    u8 pad04[0x1C];
    u8 v20[0x10];
    Node10DF8 *p30;
    Node10DF8 *p34;
};

struct Msg10DF8 {
    Node10DF8 *node;
    u8 flags;
    u8 tag;
    u8 pad06[0x0A];
};

extern void func_01B110F8(Msg10DF8 *);
extern void func_002DCE08(void *, void *, void *);

void func_01B10DF8(register Msg10DF8 *s0)
{
    func_01B110F8(s0);
    if (!(s0->flags & 1)) {
        return;
    }
    {
        Node10DF8 *n;
        Msg10DF8 m1;
        Msg10DF8 m2;

        n = s0->node;
        m1.node = n->p30;
        m1.tag = s0->tag;
        m1.node->vtable->fn1C(&m1);

        m2.node = n->p34;
        m2.tag = s0->tag;
        m2.node->vtable->fn1C(&m2);

        func_002DCE08(n->v20, (u8 *)n->p34 + 0xA0, (u8 *)n->p30 + 0x20);
    }
}
