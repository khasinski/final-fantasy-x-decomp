#include "p9_overlay.h"

/* Interpolator setup (family F9, TU rank 42, file09206). */

P9Track *func_01B0A0D0(P9Lerp *obj, int sel);
float func_01B08E88(float a, float b);

void func_01B09D00(P9Lerp *obj, int sel, float *src, int count, int n)
{
    P9Track *t = func_01B0A0D0(obj, sel);

    t->src = src;
    t->count = count;
    t->total = n * count;
    t->type = 3;
    t->pos = 0.0f;
    t->step = 1.0f / n;
}

void func_01B09D78(P9Lerp *obj, int sel, float *src, float *arg, int count, int n)
{
    P9Track *t = func_01B0A0D0(obj, sel);

    t->src = src;
    t->arg = arg;
    t->count = count;
    t->total = n * count;
    t->type = 4;
    t->pos = 0.0f;
    t->step = 1.0f / t->total;
}

void func_01B09E00(P9Lerp *obj, int sel, float *src, int count, int n)
{
    P9Track *t = func_01B0A0D0(obj, sel);

    if (sel == 0) {
        t->ref = &obj->ref0;
    } else {
        t->ref = &obj->ref1;
    }
    t->src = src;
    t->count = count;
    t->total = n * count;
    t->type = 5;
    t->pos = 0.0f;
    t->step = 1.0f / n;
}

void func_01B09EA8(P9Lerp *obj, int sel, float *src, float *arg, int count, int n)
{
    P9Track *t = func_01B0A0D0(obj, sel);

    if (sel == 0) {
        t->ref = &obj->ref0;
    } else {
        t->ref = &obj->ref1;
    }
    t->src = src;
    t->arg = arg;
    t->count = count;
    t->total = n * count;
    t->type = 6;
    t->pos = 0.0f;
    t->step = 1.0f / t->total;
}

void func_01B09F60(P9Lerp *obj, int n, float from, float to)
{
    P9Ramp *r = &obj->ramp[0];

    r->a = func_01B08E88(from, to);
    r->b = from;
    r->end = to;
    r->len = n;
    r->left = n;
    r->type = 1;
}

void func_01B09FC8(P9Lerp *obj, float *table, int count, int n)
{
    P9Ramp *r = &obj->ramp[0];

    r->table = table;
    r->type = 2;
    r->len = count;
    r->left = n * count;
    r->a = 0.0f;
    r->b = 1.0f / n;
}

void func_01B0A010(P9Lerp *obj, float *table, int count, int n)
{
    P9Ramp *r = &obj->ramp[1];

    r->table = table;
    r->type = 1;
    r->len = count;
    r->left = n * count;
    r->a = 0.0f;
    r->b = 1.0f / n;
}

void func_01B0A058(P9Lerp *obj)
{
    obj->track[0].type = 0;
    obj->track[1].type = 0;
    obj->ramp[0].type = 0;
    obj->ramp[1].type = 0;
}

void func_01B0A070(P9Lerp *obj, int a, int b, float x, float y)
{
    P9Pt *p = &obj->pt;

    p->x = x;
    p->y = y;
    p->a = a;
    p->b = b;
    obj->on = 1;
}

void func_01B0A090(P9Lerp *obj)
{
    obj->on = 0;
}
