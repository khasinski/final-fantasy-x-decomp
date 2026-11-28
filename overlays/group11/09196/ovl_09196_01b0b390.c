#include "common.h"

typedef struct {
    u8 pad00[0x1C];
    u16 cap;            /* 0x1C */
    u16 stride;         /* 0x1E */
    u32 base;           /* 0x20 */
    u32 p24;            /* 0x24 */
    u32 p28;            /* 0x28 */
    u16 h2C;            /* 0x2C */
    u16 h2E;            /* 0x2E */
    u16 widx;           /* 0x30 */
    u16 used;           /* 0x32 */
    u16 ridx;           /* 0x34 */
} Obj3E28;

typedef struct {
    Obj3E28 *obj;       /* 0x00 */
    u16 n;              /* 0x04 */
    u16 out_n1;         /* 0x06 */
    u16 out_n2;         /* 0x08 */
    u16 pad0A;
    u32 out_p1;         /* 0x0C */
    u32 out_p2;         /* 0x10 */
} Arg3E28;

void func_01B0A8D8(Arg3E28 *a)
{
    Obj3E28 *o = a->obj;
    u16 n = a->n;
    register u32 cap __asm__("$11");
    u16 widx;
    u16 end;

    __asm__("" : "+r"(n));
    cap = o->cap;
    __asm__("" : "+r"(cap));
    if (n > (u16)cap) {
        a->out_n1 = 0;
        return;
    }

    widx = o->widx;
    __asm__("" : "+r"(widx));
    {
        register u32 st __asm__("$2") = o->stride;
        register u32 bs __asm__("$3") = o->base;
        a->out_p1 = bs + widx * st;
    }
    end = widx + n;

    if (end <= (u16)cap) {
        a->out_n1 = n;
        a->out_n2 = 0;
        if (end == o->cap) {
            o->widx = 0;
        } else {
            o->widx = end;
        }
    } else {
        register u32 tmp1 __asm__("$4") = cap - widx;
        register u32 bs2 __asm__("$3") = o->base;
        a->out_n1 = tmp1;
        a->out_p2 = bs2;
        a->out_n2 = o->cap - tmp1;
        o->widx = end - o->cap;
    }

    if (o->used < o->cap) {
        o->used += a->n;
        if (o->used > o->cap) {
            o->used = o->cap;
        }
    } else {
        o->ridx = o->widx;
    }

    {
        register u32 r0 __asm__("$3") = o->ridx;
        register u32 stride2 __asm__("$11") = o->stride;
        register u32 base2 __asm__("$8") = o->base;
        register u32 sum16 __asm__("$7");
        register int cmp __asm__("$4");
        register u16 tmp __asm__("$2");
        r0 = base2 + r0 * stride2;
        o->p24 = r0;
        tmp = o->ridx + o->used;
        sum16 = tmp;
        cmp = ((u16)sum16 > o->cap);
        if (cmp) {
            o->h2C = o->cap - o->ridx;
            o->h2E = o->used - (o->cap - o->ridx);
            o->p28 = base2;
        } else {
            o->h2C = o->used;
            o->h2E = 0;
            o->p28 = o->used * stride2 + base2;
        }
    }
}
