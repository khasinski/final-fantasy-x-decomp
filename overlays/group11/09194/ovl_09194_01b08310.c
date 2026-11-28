#include "common.h"

typedef struct {
    u8 pad00[0x1C];
    u8 *buf;
    s16 max;
    u16 stride;
    u16 head;
    u16 count;
    u16 tail;
} RingBuf;

typedef struct {
    RingBuf *ring;
    u16 out1;
    u16 out2;
    u8 *ptr1;
    u8 *ptr2;
} RingRead;

void func_01B08310(RingRead *a2)
{
    RingBuf *a1 = a2->ring;
    u8 *buf = a1->buf;

    a2->ptr1 = buf + a1->tail * a1->stride;
    if (a1->max < (u16)(a1->tail + a1->count)) {
        a2->out1 = a1->max - a1->tail;
        a2->out2 = a1->count - a2->out1;
        a2->ptr2 = buf;
    } else {
        a2->out1 = a1->count;
        a2->out2 = 0;
        a2->ptr2 = buf + a1->count * a1->stride;
    }
}
