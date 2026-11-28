#include "common.h"

typedef struct {
    u8 pad00[0x1E];
    u16 stride;
    u32 pad20;
    u32 f24;
    u32 f28;
    u16 f2C;
    u16 f2E;
} Ring10110;

typedef struct {
    Ring10110 *ring;
    u16 req;
} Arg10110;

void func_01B10110(Arg10110 *a0)
{
    Ring10110 *a1 = a0->ring;
    int req = a0->req;
    int cur = a1->f2C;

    if (req < cur) {
        a1->f2C = cur - req;
        a1->f24 += req * a1->stride;
        return;
    }

    req -= cur;
    if (req >= (int)a1->f2E) {
        a1->f2E = 0;
        a1->f2C = 0;
        return;
    }

    a1->f2C = a1->f2E - req;
    a1->f2E = 0;
    a1->f24 = req * a1->stride;
    a1->f28 = a1->f2C * a1->stride + a1->f24;
}
