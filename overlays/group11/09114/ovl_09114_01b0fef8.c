#include "p6_overlay.h"

extern P6NodeVt g_vt_fef8;
extern void func_002DD0B0(void *, void *);

typedef struct {
    P6Node node;
    u16 h1C;
    u16 h1E;
    void *p20;
    u8 pad24[0x0C];
    u16 h30;
    u16 h32;
    u16 h34;
    u8 pad36[0x0A];
    u8 v40[0x10];
    u8 v50[0x10];
    u8 pad60[0x08];
    u32 w68;
    u32 w6C;
    u32 w70;
    u8 pad74[0x0C];
    u8 buf80[4];
} ObjFEF8;

typedef struct {
    ObjFEF8 *obj;
    P6Node *parent;
    void *p08;
    u16 h0C;
    u16 h0E;
    void *p10;
    void *p14;
} ArgFEF8;

void func_01B0FEF8(ArgFEF8 *a)
{
    register P6NodeVt *vt __asm__("$3") = &g_vt_fef8;
    ObjFEF8 *o = a->obj;
    P6Node *p = a->parent;

    a->h0C = 0x100;
    a->p08 = o->buf80;
    a->h0E = 0x40;
    o->node.vt = vt;
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
    {
        ObjFEF8 *o2 = a->obj;
        u16 h0C = a->h0C;
        register void *p08 __asm__("$6") = a->p08;
        void *p14;
        u16 h0E;
        o2->h1C = h0C;
        p14 = a->p14;
        h0E = a->h0E;
        o2->p20 = p08;
        o2->h1E = h0E;
        o2->h34 = 0;
        o2->h32 = 0;
        o2->h30 = 0;
        func_002DD0B0(o->v50, p14);
    }
    func_002DD0B0(o->v40, a->p10);
    o->w68 = 0;
    o->w70 = 0;
}
