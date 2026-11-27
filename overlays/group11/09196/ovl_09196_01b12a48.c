#include "common.h"

typedef struct {
    u8 pad00[0x30];
    void *p30;
    void *p34;
} Node12A48;

typedef struct {
    Node12A48 *node;
    void *parent;
    void *p08;
    void *p0C;
} Msg12A48;

extern void g_fn_12c88(Msg12A48 *);

void func_01B12A48(register Msg12A48 *s0)
{
    g_fn_12c88(s0);
    s0->node->p30 = s0->p08;
    s0->node->p34 = s0->p0C;
}
