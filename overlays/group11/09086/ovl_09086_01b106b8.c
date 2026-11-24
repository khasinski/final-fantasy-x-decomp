#include "common.h"

typedef struct {
    u8 pad00[0x30];
    void *p30;
    void *p34;
} Node106B8;

typedef struct {
    Node106B8 *node;
    void *parent;
    void *p08;
    void *p0C;
} Msg106B8;

extern void func_01B108F8(Msg106B8 *);

void func_01B106B8(register Msg106B8 *s0)
{
    func_01B108F8(s0);
    s0->node->p30 = s0->p08;
    s0->node->p34 = s0->p0C;
}
