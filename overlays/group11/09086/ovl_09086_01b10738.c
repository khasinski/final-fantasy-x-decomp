#include "common.h"

typedef struct Msg10738 Msg10738;
typedef struct Node10738 Node10738;

typedef struct {
    u8 pad00[0x1C];
    void (*fn1C)(Msg10738 *);
} Vtable10738;

struct Node10738 {
    Vtable10738 *vtable;
    u8 pad04[0x1C];
    u8 v20[0x10];
    Node10738 *p30;
    Node10738 *p34;
};

struct Msg10738 {
    Node10738 *node;
    u8 flags;
    u8 tag;
    u8 pad06[0x0A];
};

extern void func_01B10A30(Msg10738 *);
extern void func_002DD020(void *, void *, void *);

void func_01B10738(register Msg10738 *s0)
{
    func_01B10A30(s0);
    if (!(s0->flags & 1)) {
        return;
    }
    {
        Node10738 *n;
        Msg10738 m;

        n = s0->node;
        m.tag = s0->tag;
        m.node = n->p30;
        m.node->vtable->fn1C(&m);

        m.node = n->p34;
        m.node->vtable->fn1C(&m);

        func_002DD020(n->v20, (u8 *)n->p30 + 0x20, (u8 *)n->p34 + 0x20);
    }
}
