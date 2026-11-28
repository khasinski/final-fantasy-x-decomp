#include "common.h"

typedef struct {
    u8 pad0[0x1C];
    u8 *buf;        /* 0x1C */
    s16 cap;        /* 0x20 */
    u16 stride;     /* 0x22 */
    u16 head;       /* 0x24 */
    u16 count;      /* 0x26 */
    u16 tail;       /* 0x28 */
} RingB430;

typedef struct {
    RingB430 *ring; /* 0x00 */
    u16 req;        /* 0x04 */
    u16 out1;       /* 0x06 */
    u16 out2;       /* 0x08 */
    u16 pad0A;
    u8 *ptr1;       /* 0x0C */
    u8 *ptr2;       /* 0x10 */
} ReqB430;

void ovl_09194_01b0b430(ReqB430 *a2) {
    RingB430 *r = a2->ring;
    u16 req = a2->req;
    s32 cap = r->cap;
    register RingB430 *t2 __asm__("$10") = r;
    u16 cap_u;
    u16 head;
    u16 next;
    u8 *buf;

    __asm__ volatile("" : "+r"(t2));
    cap_u = r->cap;
    if (cap < req) {
        a2->out1 = 0;
        return;
    }

    head = r->head;
    next = head + req;
    buf = r->buf;
    a2->ptr1 = buf + head * r->stride;
    if ((s32)next <= cap) {
        a2->out2 = 0;
        a2->out1 = a2->req;
        if ((s32)next == r->cap) {
            r->head = 0;
        } else {
            r->head = next;
        }
    } else {
        u32 n1 = cap_u - head;
        a2->ptr2 = buf;
        a2->out1 = n1;
        a2->out2 = (u16)r->cap - n1;
        r->head = next - (u16)r->cap;
    }

    {
        register s32 cap2 __asm__("$4") = t2->cap;
        register u32 cnt __asm__("$3");
        register u16 cap2_u __asm__("$7");
        s32 cmp0;
        __asm__ volatile("" : : "r"(cap2));
        cnt = t2->count;
        cmp0 = ((s32)cnt < cap2);
        __asm__ volatile("" : : "r"(cmp0) : "memory");
        cap2_u = t2->cap;
        if (cmp0) {
            register s32 sum __asm__("$2") = cnt + a2->req;
            register s32 cmp __asm__("$3") = (cap2 < (s32)(u16)sum);
            r->count = sum;
            if (cmp) {
                r->count = cap2_u;
            }
        } else {
            r->tail = r->head;
        }
    }
}
