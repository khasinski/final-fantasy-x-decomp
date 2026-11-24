#include "common.h"

typedef struct {
    void *p00;
    void *p04;
} OvlCtx;

typedef struct {
    u8 pad00[0x18];
    u32 state18;
    int timer1C;
    void *p20;
} OvlSmall;

extern u8 D_01B009E0;

extern void func_01B0A388(void *);
extern void func_01B0A468(void *);
extern void func_01B11900(void *);
extern void func_01B11980(void *);
extern void func_01B119A8(void *);
extern void func_01B11D08(void *);

void func_01B088D8(OvlCtx *a0) {
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
    OvlSmall *s = a0->p04;

    switch (s->state18) {
    case 0:
        arg0.p00 = s->p20;
        func_01B0A388(&arg0);
        if (arg0.res != 0) {
            void **q = (void **)&arg10;
            q[0] = s->p20;
            q[1] = (void *)0x4B;
            func_01B0A468(q);
            s->state18++;
        }
        break;
    case 1:
        break;
    case 10000:
        tmp20 = a0->p00;
        func_01B119A8(&tmp20);
        tmp24 = a0->p00;
        func_01B11980(&tmp24);
        s->state18 = 20000;
        break;
    }
    s->timer1C--;
}

void func_01B089A0(OvlSmall *a0, void *a1) {
    struct {
        void *p00;
        void *p04;
        void *p08;
    } arg;

    arg.p00 = a0;
    arg.p04 = func_01B088D8;
    arg.p08 = a0;
    func_01B11900(&arg);

    arg.p00 = &D_01B009E0;
    arg.p04 = a0;
    func_01B11D08(&arg);

    arg.p00 = a1;
    arg.p04 = (void *)0x4A;
    func_01B0A468(&arg);

    a0->p20 = a1;
    a0->state18 = 0;
}
