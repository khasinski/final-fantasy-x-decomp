#include "common.h"

typedef struct Node9D08 Node9D08;
struct Node9D08 {
    u8 pad00[0x20];
    int v20[3];
    u8 pad2C[0x04];
    int v30[3];
    Node9D08 *p3C;
};

typedef struct {
    Node9D08 *node;
    u8 flags;
    u8 tag;
} Msg9D08;

extern void func_01B09F58(Msg9D08 *);
extern void func_01B09E90(Node9D08 *, u8);

void func_01B09D08(register Msg9D08 *s0)
{
    func_01B09F58(s0);
    if (!(s0->flags & 1)) {
        return;
    }
    {
        Node9D08 *n = s0->node;
        Node9D08 *p = n->p3C;

        func_01B09E90(n->p3C, s0->tag);
        n->v20[0] = p->v20[0] + n->v30[0];
        n->v20[1] = p->v20[1] + n->v30[1];
        n->v20[2] = p->v20[2] + n->v30[2];
    }
}
