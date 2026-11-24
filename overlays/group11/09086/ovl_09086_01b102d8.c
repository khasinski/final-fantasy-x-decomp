#include "common.h"

typedef struct Node102D8 Node102D8;
struct Node102D8 {
    u8 pad00[0x14];
    Node102D8 *parent;
    u8 pad18[0x08];
    u8 v20[0x10];
};

typedef struct {
    Node102D8 *node;
    u8 flags;
} Msg102D8;

extern void func_01B10470(Msg102D8 *);
extern void func_002DD020(void *, void *, void *);

void func_01B102D8(register Msg102D8 *s0)
{
    func_01B10470(s0);
    if (!(s0->flags & 1)) {
        return;
    }
    {
        Node102D8 *p;
        int dummy;

        p = s0->node->parent;
        func_002DD020(p->v20, p->v20, s0->node->v20);
        dummy = 0;
    }
}
