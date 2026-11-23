#include "common.h"

typedef struct S6DA8Sub20 {
    u8 pad00[0x54];
    s32 s54;
} S6DA8Sub20;

typedef struct S6DA8Obj {
    u8 pad00[0x18];
    s32 s18;
    u32 u1C;
    S6DA8Sub20 *p20;
} S6DA8Obj;

typedef struct S6DA8Ctx {
    void *p00;
    S6DA8Obj *obj;
} S6DA8Ctx;

extern void *D_01B007B8;
extern u8 D_01B00B80[];

extern s32 func_001CE1A8(s32 a0);
extern void func_001CE050(s32 a0, s32 a1);
extern void func_001C5E90(void *a0, s32 a1, s32 a2);
extern void func_001C69C8(s32 a0, s32 a1, s32 a2);
extern void func_001CE2F0(s32 a0, s32 a1);
extern void func_01B16B40(void *a0);
extern void func_01B16A98(void *a0);
extern void func_01B16EA0(void *a0);

void func_01B06DA8(S6DA8Ctx *a0)
{
    void *m0;
    S6DA8Obj *s0 = a0->obj;
    S6DA8Sub20 *p;
    s32 motion;

    switch (s0->u1C) {
    case 0:
        if (func_001CE1A8(s0->p20->s54)) {
            p = s0->p20;
            motion = 24;
            goto set_motion;
        }
        break;
    case 50:
        p = s0->p20;
        motion = 64;
        goto set_motion;
    case 51:
        __asm__("" : "+r"(s0));
        if (func_001CE1A8(s0->p20->s54)) {
            motion = 24;
            p = s0->p20;
            goto set_motion;
        }
        break;
    case 1:
    case 52:
        if (func_001CE1A8(s0->p20->s54)) {
            register u32 next __asm__("$3");
            p = s0->p20;
            motion = 25;
set_motion:
            func_001CE050(p->s54, motion);
            next = s0->u1C + 1;
            s0->u1C = next;
        }
        break;
    case 10000:
        func_001C5E90(D_01B007B8, s0->p20->s54, 2);
        {
            register S6DA8Sub20 *q __asm__("$3") = s0->p20;
            func_001C69C8(q->s54, 15, 1);
        }
        s0->u1C++;
        /* fallthrough */
    case 10001:
        if (func_001CE1A8(s0->p20->s54)) {
            func_001CE2F0(s0->p20->s54, 0);
            func_001CE2F0(s0->p20->s54, 5);
            m0 = a0->p00;
            func_01B16B40(&m0);
            s0->u1C = 20000;
        }
        break;
    }

    s0->s18--;
}

void func_01B06F40(S6DA8Obj *a0, S6DA8Sub20 *a1)
{
    void *m[4];

    m[0] = a0;
    m[1] = func_01B06DA8;
    m[2] = a0;
    func_01B16A98(m);

    m[0] = D_01B00B80;
    m[1] = a0;
    func_01B16EA0(m);

    func_001CE050(a1->s54, 64);
    a0->p20 = a1;
    a0->u1C = 0;
}
