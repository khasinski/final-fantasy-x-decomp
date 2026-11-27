#include "common.h"

typedef struct {
    u8 pad00[0x30];
    void *p30;
    void *p34;
} Node12320;

typedef struct {
    Node12320 *node;
    void *parent;
    void *p08;
    void *p0C;
} Msg12320;

extern void func_01B12568(Msg12320 *);

void func_01B12320(register Msg12320 *s0)
{
    func_01B12568(s0);
    s0->node->p30 = s0->p08;
    s0->node->p34 = s0->p0C;
}
