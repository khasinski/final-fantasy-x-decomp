#include "common.h"

typedef struct {
    u8 pad00[0x18];
    u32 state;
    void *f1C;
    u8 pad20[0xC];
    int f2C;
    int f30;
} ObjA628;

typedef struct {
    void *p00;
    ObjA628 *obj;
} MsgA628;

extern void func_01B115E0(void *);
extern void func_01B116C0(void *);
extern void func_01B1ADC8(void *);

void func_01B0A628(MsgA628 *a0)
{
    ObjA628 *s0 = a0->obj;
    void *m0[4];
    void *m1[4];
    void *m2[4];
    void *m3[4];
    void *m4[4];
    void *m5[4];

loop:
    switch (s0->state) {
    case 0:
        break;
    case 1:
        break;
    case 10:
        s0->state = 11;
        break;
    case 11:
        m0[0] = s0->f1C;
        func_01B115E0(m0);
        if (m0[1] != 0) {
            s0->state = 20;
            goto loop;
        }
        break;
    case 20:
        {
            void **p = m1;
            m1[0] = s0->f1C;
            p[1] = (void *)0xB9;
            func_01B116C0(p);
        }
        s0->state++;
        break;
    case 21:
        break;
    case 30:
        {
            void **p = m1;
            m1[0] = s0->f1C;
            p[1] = (void *)0xBA;
            func_01B116C0(p);
        }
        s0->state++;
        break;
    case 31:
        m1[0] = s0->f1C;
        func_01B115E0(m1);
        if (m1[1] != 0) {
            s0->state = 40;
            goto loop;
        }
        break;
    case 40:
        {
            void **p = m2;
            m2[0] = s0->f1C;
            p[1] = (void *)0xBB;
            func_01B116C0(p);
        }
        s0->state++;
        break;
    case 41:
        break;
    case 50:
        {
            void **p = m2;
            m2[0] = s0->f1C;
            p[1] = (void *)0xBE;
            func_01B116C0(p);
        }
        s0->state++;
        break;
    case 51:
        m2[0] = s0->f1C;
        func_01B115E0(m2);
        if (m2[1] != 0) {
            void **p = m3;
            m3[0] = s0->f1C;
            p[1] = (void *)0xBC;
            func_01B116C0(p);
            s0->state++;
        }
        break;
    case 52:
        break;
    case 60:
        {
            void **p = m3;
            m3[0] = s0->f1C;
            p[1] = (void *)0xBD;
            func_01B116C0(p);
        }
        s0->state++;
        break;
    case 61:
        m3[0] = s0->f1C;
        func_01B115E0(m3);
        if (m3[1] != 0) {
            void **p = m4;
            m4[0] = s0->f1C;
            p[1] = (void *)0xBC;
            func_01B116C0(p);
            s0->state++;
        }
        break;
    case 62:
        break;
    case 10000:
        m5[0] = a0->p00;
        func_01B1ADC8(m5);
        break;
    }

    s0->f2C++;
    s0->f30++;
}
