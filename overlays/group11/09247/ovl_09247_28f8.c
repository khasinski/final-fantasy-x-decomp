#include "common.h"

typedef struct {
    u8 pad00[0x54];
    void *p54;
} Sub28F8;

typedef struct {
    u8 pad00[0x18];
    Sub28F8 *sub;
    int flag;
} Obj28F8;

typedef struct {
    void *p00;
    Obj28F8 *obj;
} Arg28F8;

extern int func_001CE1A8(void *);
extern void func_001CE050(void *, int);
extern void func_001CE2F0(void *, int);
extern void func_01B0E360(void *);
extern void func_01B0E408(void **);
extern void func_01B0E768(void *);
extern u8 D_01B00C20[];

void func_01B028F8(Arg28F8 *a)
{
    Obj28F8 *o = a->obj;
    void *tmp;

    if (o->flag != 0) {
        return;
    }
    if (func_001CE1A8(o->sub->p54) != 0) {
        register Sub28F8 *sub __asm__("$3");
        func_001CE050(o->sub->p54, 0xB3);
        sub = o->sub;
        func_001CE2F0(sub->p54, 6);
        tmp = a->p00;
        func_01B0E408(&tmp);
    }
}

void func_01B02970(Obj28F8 *o, Sub28F8 *sub)
{
    void *args[3];

    args[0] = o;
    args[1] = (void *)func_01B028F8;
    args[2] = o;
    func_01B0E360(args);

    args[0] = D_01B00C20;
    args[1] = o;
    func_01B0E768(args);

    o->sub = sub;
    func_001CE050(sub->p54, 0xB2);
    o->flag = 0;
}
