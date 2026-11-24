#include "common.h"

typedef struct {
    u8 pad00[0x9C];
    u32 w9C;
    u16 hA0;
    u16 hA2;
    u8 padA4[0x8];
    u8 bAC;
} Node5DB0;

void func_01B05DB0(void *arg)
{
    struct {
        Node5DB0 *n;
        struct {
            u16 h00;
            u16 h02;
            u32 w04;
            u8 b08;
        } *src;
    } *p = arg;
    Node5DB0 *n = p->n;

    n->hA0 = p->src->h00;
    n->w9C = p->src->w04;
    n->hA2 = p->src->h02;
    n->bAC = p->src->b08;
}
