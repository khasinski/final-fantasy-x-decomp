#include "common.h"

typedef struct {
    u8 pad00[0x12C];
    void *p12C;
    u8 pad130[0x10];
    void *p140;
    void *p144;
    void *p148;
    u8 f14C;
} Node11B58;

typedef struct {
    Node11B58 *node;
    void *parent;
    void *p08;
    void *p0C;
    void *p10;
    void *p14;
} Msg11B58;

extern void func_01B12130(Msg11B58 *);
extern void func_01B12108(void *);

void func_01B11B58(register Msg11B58 *s0)
{
    Node11B58 *n = s0->node;

    func_01B12130(s0);
    func_01B12108(s0->p0C);
    func_01B12108(s0->p10);
    func_01B12108(s0->p14);
    n->p140 = s0->p0C;
    n->p148 = s0->p10;
    n->p144 = s0->p14;
    n->p12C = s0->p08;
    n->f14C = 0;
}
