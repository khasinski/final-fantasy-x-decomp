#include "common.h"

typedef struct {
    u8 pad00[0x18];
    int state;
    int timer;
    u8 pad20[0x10];
    u8 v30[0x20];
    int w50;
    int w54;
    u8 pad58[0x290];
    int flags;
} Obj9557;

typedef struct {
    void *p0;
    void *p4;
    void *p8;
} Msg3;

typedef struct {
    void *p0;
    void *p4;
} Msg2;

typedef struct {
    void *p0;
    Obj9557 *o;
} TaskArg;

extern u8 D_01B00A10[];
extern void func_01B029E8(void);
extern void func_01B0F148(void *);
extern void func_01B0F1F0(void *);
extern void func_01B0F550(void *);
extern void func_002DD0B0(void *, void *);

void func_01B02C48(Obj9557 *o, int a1, int a2, void *a3)
{
    Msg3 m;
    m.p0 = o;
    m.p4 = (void *)func_01B029E8;
    m.p8 = o;
    func_01B0F148(&m);
    m.p0 = D_01B00A10;
    m.p4 = o;
    func_01B0F550(&m);
    func_002DD0B0(o->v30, a3);
    o->w54 = a2;
    o->w50 = a1;
    o->state = 0;
}

void func_01B02CD8(TaskArg *a)
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
