#include "common.h"

typedef struct {
    u8 pad00[0x1C];
    u16 cap;
    u16 stride;
    u32 base;
    u32 p24;
    u32 p28;
    u16 h2C;
    u16 h2E;
    u16 widx;
    u16 used;
    u16 ridx;
} ObjA928;

typedef struct {
    ObjA928 *obj;
    u16 n;
    u16 out_n1;
    u16 out_n2;
    u16 pad0A;
    u32 out_p1;
    u32 out_p2;
} ArgA928;

typedef struct {
    ObjA928 *obj;
    u16 cnt;
} ArgAA58;

void func_01B0A928(ArgA928 *a)
{
    ObjA928 *o = a->obj;
    u16 n = a->n;
    u16 widx;
    u16 end;

    __asm__("" : "+r"(n));
    if (n > o->cap) {
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

    if (end <= o->cap) {
        a->out_n1 = n;
        a->out_n2 = 0;
        if (end == o->cap) {
            o->widx = 0;
        } else {
            o->widx = end;
        }
    } else {
        u16 tmp1 = o->cap - widx;
        u16 tmp2 = n - (o->cap - widx);
        a->out_n1 = tmp1;
        a->out_n2 = tmp2;
        a->out_p2 = o->base;
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

void func_01B0AA58(ArgAA58 *arg)
{
    ObjA928 *p = arg->obj;
    s32 cnt = arg->cnt;

    if (cnt < p->h2C) {
        p->h2C -= cnt;
        p->p24 += cnt * p->stride;
    } else {
        cnt -= p->h2C;
        if (cnt >= p->h2E) {
            p->h2E = 0;
            p->h2C = 0;
        } else {
            p->h2C = p->h2E - cnt;
            p->p24 = cnt * p->stride;
            p->h2E = 0;
            p->p28 = p->p24 + p->h2C * p->stride;
        }
    }
}
