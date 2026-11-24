#include "common.h"

typedef struct {
    void *p00;
    void *p04;
} OvlCtx;

typedef struct {
    u8 pad00[0xE50];
    u8 *pE50;
    u8 bufE54[0x18];
    u32 stateE6C;
    int timerE70;
    int cntE74;
    int alphaE78;
    int flagE7C;
    void *pE80;
} OvlEmitter;

typedef struct {
    u8 pad00[0x18];
    u32 state18;
    int timer1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    u8 buf30[0x20];
    float f50;
    float f54;
    float f58;
    float f5C;
    u8 pad60[0x102C];
    int f108C;
    u8 pad1090[0x10];
    void *p10A0;
} OvlSubA;

extern void *D_01B00618;
extern u8 D_01B009E0;

extern float func_001ACED8(void);
extern void *func_002B49A0(void *, int, int);
extern void func_01B07788(void *);
extern void func_01B0A350(void *);
extern void func_01B11900(void *);
extern void func_01B11980(void *);
extern void func_01B119A8(void *);
extern void func_01B11D08(void *);

void func_01B07C60(OvlEmitter *a0, void *a1) {
    struct {
        void *p00;
        void *p04;
        void *p08;
    } arg;
    u8 *pE54 = a0->bufE54;

    arg.p00 = pE54;
    arg.p04 = func_01B07788;
    arg.p08 = a0;
    func_01B11900(&arg);

    arg.p00 = &D_01B009E0;
    arg.p04 = pE54;
    func_01B11D08(&arg);

    a0->flagE7C = 0;
    a0->pE50 = func_002B49A0(D_01B00618, 9, 0);
    a0->pE80 = a1;
    a0->stateE6C = 0;
}

void func_01B07CF0(OvlCtx *a0) {
    struct {
        void *p00;
        int p04;
        int p08;
        int pad0C;
    } arg0;
    void *tmp10;
    void *tmp14;
    OvlSubA *s = a0->p04;

    s->f50 = s->f28 + (0.5f - (func_001ACED8() - 0.99f)) * 3.0f;
    s->f58 = s->f2C + (0.5f - (func_001ACED8() - 0.99f)) * 3.0f;

retry:
    switch (s->state18) {
    case 0:
        s->timer1C = 30;
        s->state18 = 1;
        break;
    case 1:
        if (s->timer1C <= 0) {
            s->state18 = 20;
            goto retry;
        }
        break;
    case 20:
        s->f24 = 0.005f;
        s->f20 = 0.05f;
        s->timer1C = 180;
        s->state18 = 21;
        /* fallthrough */
    case 21:
        if (s->timer1C <= 0) {
            arg0.p00 = s->p10A0;
            arg0.p04 = 0;
            arg0.p08 = 64;
            func_01B0A350(&arg0);
            s->f108C = 1;
            s->timer1C = 64;
            s->state18++;
            /* fallthrough */
        } else {
            break;
        }
    case 22:
        if (s->timer1C <= 0) {
            s->state18 = 10000;
            goto retry;
        }
        break;
    case 10000:
        tmp10 = a0->p00;
        func_01B119A8(&tmp10);
        tmp14 = a0->p00;
        func_01B11980(&tmp14);
        s->state18 = 20000;
        break;
    }
    s->timer1C--;
}
