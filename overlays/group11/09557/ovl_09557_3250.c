#include "common.h"

typedef struct {
    u8 pad00[0x18];
    int state;
    int timer;
    u8 pad20[0x2C8];
    int flags;
} Obj9557;

typedef struct {
    void *p0;
    Obj9557 *o;
} TaskArg;

extern void func_01B0F1F0(void *);

void func_01B03250(TaskArg *a)
{
    Obj9557 *o = a->o;
retry:
    switch (o->state) {
    case 0:
        if (o->flags & 4) {
            o->state = 10000;
            goto retry;
        }
        break;
    case 10000:
        {
            struct { u8 pad[0x10]; void *t; } s;
            s.t = a->p0;
            func_01B0F1F0(&s.t);
            o->state = 20000;
        }
        break;
    }
    o->timer--;
}
