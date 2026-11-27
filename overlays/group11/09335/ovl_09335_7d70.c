#include "p1_overlay.h"

extern void func_01B07EE0(P1Ring *ring, P1Sub *sub);
extern void func_01B07FE0(void *work, P1Sub *sub, P1Th *th, int h212);

s16 *func_01B07D70(P1Th *th, s16 *pc)
{
    P1Sub *sub = th->sub;
    int n;
    P1Ring *ring;

    switch (th->op & 0xF000) {
    case 0x0000:
        n = pc[1];
        pc += 2;
        ring = op_malloc(th->heap, n * sizeof(P1RingEnt) + 16);
        sub->work = ring;
        ring->count = n;
        ring->head = 0;
        break;
    case 0x1000:
        th->m00[0][0] = th->m00[0][1] = pc[1] * 0.00390625f;
        pc += 2;
        th->m00[0][2] = sub->f3C * 0.00390625f;
        op_unit_m_scale2(th->m40, th->m00);
        func_002B5318(th->m40, th->m40, sub->rot);
        func_002B56D8(th->m00, opus_local_get(th, sub), th->m40);
        func_002B56D8(th->m00, th->m2C0, th->m00);
        func_01B07FE0(sub->work, sub, th, th->h212);
        break;
    case 0x2000:
        if (th->h212 == 0) {
            func_01B07EE0(opus_no_get(&th->obj300, sub, pc[1])->work, sub);
        }
        pc += 2;
        break;
    }
    return pc;
}
