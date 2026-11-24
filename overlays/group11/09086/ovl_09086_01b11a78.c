#include "common.h"

typedef struct Node11A78 Node11A78;
struct Node11A78 {
    u8 pad00[0x14];
    Node11A78 *parent;
    u8 pad18[0x08];
    int v[4];
};

typedef struct {
    Node11A78 *node;
    u8 flags;
} Msg11A78;

extern void func_01B11C40(Msg11A78 *);

void func_01B11A78(register Msg11A78 *s0)
{
    func_01B11C40(s0);
    if (!(s0->flags & 1)) {
        return;
    }
    {
        Node11A78 *n = s0->node;
        Node11A78 *p = n->parent;
        p->v[0] += n->v[0];
        p->v[1] += n->v[1];
        p->v[2] += n->v[2];
        p->v[3] += n->v[3];
    }
}
