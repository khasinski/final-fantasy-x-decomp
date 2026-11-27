#include "p6_overlay.h"

extern P6NodeVt g_vt_1f08;

typedef struct {
    P6Node node;
    u8 pad1C[0x10];
    float f2C;
    u8 pad30[0x10];
    void *p40;
    int w44;
    int w48;
    int w4C;
    int w50;
    int w54;
} Obj1F08;

typedef struct {
    Obj1F08 *obj;
    void *p04;
} Arg1F08;

typedef struct {
    Obj1F08 *obj;
    P6Node *parent;
    void *p08;
} Arg1F30;

void func_01B11F08(Arg1F08 *a)
{
    Obj1F08 *o = a->obj;

    o->node.vt = &g_vt_1f08;
    o->p40 = a->p04;
    o->w44 = 0;
    o->w54 = 0;
}

void func_01B11F30(Arg1F30 *a)
{
    Obj1F08 *o = a->obj;
    P6Node *p = a->parent;

    o->node.vt = &g_vt_1f08;
    o->node.mark = 0xFF;
    o->node.last = &o->node;
    o->node.first = &o->node;
    o->node.parent = p;
    o->node.b1B = 0;
    if (p != 0) {
        o->node.next = p;
        o->node.prev = p->last;
        if (p->last == p) {
            p->first = &o->node;
        } else {
            p->last->next = &o->node;
        }
        p->last = &o->node;
        p->count++;
    }
    o->p40 = a->p08;
    o->f2C = 1.0f;
    o->w48 = 0;
    o->w4C = 0;
    o->w50 = 0;
    o->w54 = 0;
    o->w44 = 0;
}
