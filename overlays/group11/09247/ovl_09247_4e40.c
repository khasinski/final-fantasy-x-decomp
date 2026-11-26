#include "p6_overlay.h"

typedef struct {
    P6Node node;
    void *p1C;
    void *p20;
    void *p24;
    int flags;
} Obj4DB0;

typedef struct {
    P6Node *obj;
    u8 flag;
    u8 mark;
} Arg4E48;

extern void func_00103788(void *);
extern void func_01B04C08(void **);
extern void func_01B04D48(void **);
extern void func_01B04F90(void **);
extern void func_01B06710(void **);
extern void func_01B06818(void **);

void func_01B04E40(void **a)
{
    (void)a;
}

void func_01B04E48(Arg4E48 *a)
{
    P6Node *o = a->obj;

    if (o->mark == a->mark) {
        a->flag = 0;
    } else {
        P6Node *c = o->last;
        while (c != o) {
            a->obj = c;
            c = c->prev;
            ((void (**)(Arg4E48 *))a->obj->vt)[7](a);
        }
        a->obj = o;
        o->mark = a->mark;
        a->flag = 1;
    }

    if (a->flag & 1) {
        Obj4DB0 *obj = (Obj4DB0 *)a->obj;
        func_00103788(obj->p24);
        if (obj->flags & 1) {
            void *t0 = obj->p1C;
            void *t1;
            void *t2;
            void *t3;
            void *t4;
            void *t5;
            func_01B06818(&t0);
            t1 = obj->p1C;
            func_01B06710(&t1);
            t2 = obj->p20;
            func_01B04D48(&t2);
            t3 = obj->p20;
            func_01B04C08(&t3);
            t4 = obj;
            func_01B04F90(&t4);
            t5 = obj;
            func_01B04E40(&t5);
        }
    }
}
