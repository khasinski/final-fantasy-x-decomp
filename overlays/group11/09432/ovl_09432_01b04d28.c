#include "common.h"

typedef struct {
    void *p00;
    void *p04;
} OvlCtx;

typedef struct {
    u8 pad00[0x18];
    u32 state18;
    u8 pad1C[0x2B4];
} OvlSub2D0;

typedef struct {
    u8 pad00[0x18];
    u32 state18;
    int timer1C;
    int cnt20;
    void *p24;
    u8 pad28[0xA8];
    OvlSub2D0 sub[12];
} OvlA;

typedef struct {
    u8 pad00[0x18];
    u32 state18;
    int timer1C;
    void *p20;
} OvlB;

extern u8 D_01B00B50;

extern void func_01B045A8(void *);
extern void func_01B06A58(void *);
extern void func_01B06B38(void *);
extern void func_01B0E668(void *);
extern void func_01B0E6E8(void *);
extern void func_01B0E710(void *);
extern void func_01B0EA70(void *);

void func_01B04D28(OvlA *a0, void *a1) {
    struct {
        void *p00;
        void *p04;
        void *p08;
    } arg;
    int i;

    arg.p00 = a0;
    arg.p04 = func_01B045A8;
    arg.p08 = a0;
    func_01B0E668(&arg);

    arg.p00 = &D_01B00B50;
    arg.p04 = a0;
    func_01B0EA70(&arg);

    for (i = 11; i >= 0; i--) {
        a0->sub[i].state18 = 20000;
    }
    a0->p24 = a1;
    a0->cnt20 = 0;
    a0->timer1C = 0;
    a0->state18 = 0;
}

void func_01B04DC0(OvlCtx *a0) {
    struct {
        void *p00;
        int res;
        int pad08;
        int pad0C;
    } arg0;
    struct {
        void *p00;
        int p04;
        int pad08;
        int pad0C;
    } arg10;
    void *tmp20;
    void *tmp24;
    OvlB *s = a0->p04;

    switch (s->state18) {
    case 0:
        arg0.p00 = s->p20;
        func_01B06A58(&arg0);
        if (arg0.res != 0) {
            void **q = (void **)&arg10;
            arg10.p00 = s->p20;
            q[1] = (void *)0x108E101B;
            func_01B06B38(q);
            s->timer1C = 240;
            s->state18 = 10;
        }
        break;
    case 10:
        if (s->timer1C == 0) {
            tmp20 = a0->p00;
            func_01B0E710(&tmp20);
            tmp24 = a0->p00;
            func_01B0E6E8(&tmp24);
            s->state18 = 20000;
        }
        break;
    }
    s->timer1C--;
}

void func_01B04EA0(OvlB *a0, void *a1) {
    struct {
        void *p00;
        void *p04;
        void *p08;
    } arg;

    arg.p00 = a0;
    arg.p04 = func_01B04DC0;
    arg.p08 = a0;
    func_01B0E668(&arg);

    arg.p00 = &D_01B00B50;
    arg.p04 = a0;
    func_01B0EA70(&arg);

    arg.p00 = a1;
    arg.p04 = (void *)0x108E101A;
    func_01B06B38(&arg);

    a0->p20 = a1;
    a0->state18 = 0;
}
