#include "common.h"

typedef struct {
    u8 pad00[0x30];
    float f30;
    float f34;
    float f38;
} SubA_AE08;

typedef struct {
    u8 pad00[0x34];
    u8 f34;
    u8 pad35[0x1F];
    u8 f54;
} SubB_AE08;

typedef struct {
    u8 pad00[0x34];
    float f34;
} SubC_AE08;

typedef struct {
    u8 pad00[0x18];
    u32 state;      /* 0x18 */
    SubA_AE08 *p1C; /* 0x1C */
    SubA_AE08 *p20; /* 0x20 */
    SubB_AE08 *p24; /* 0x24 */
    SubB_AE08 *p28; /* 0x28 */
    SubC_AE08 *p2C; /* 0x2C */
    u8 pad30[0x0C]; /* 0x30 */
    int f3C;        /* 0x3C */
    int f40;        /* 0x40 */
} ObjAE08;

typedef struct {
    void *p00;
    ObjAE08 *obj;
} MsgAE08;

typedef struct {
    void *a;
    void *b;
    void *c;
} Arg3AE08;

extern u8 D_01B00CD8[];
extern void func_01B1AD20(void *);
extern void func_01B1ADC8(void *);
extern void func_01B1B128(void *);

void func_01B0AE08(MsgAE08 *a0)
{
    ObjAE08 *s0 = a0->obj;
    SubA_AE08 *a3 = s0->p1C;
    SubA_AE08 *t1 = s0->p20;
    SubB_AE08 *t0 = s0->p24;
    SubB_AE08 *a2 = s0->p28;
    SubC_AE08 *t2 = s0->p2C;

top:
    switch (s0->state) {
    case 0:
        a3->f30 = 30.0f;
        a3->f34 = 1.0f;
        a3->f38 = 5.0f;
        t1->f30 = 30.0f;
        t1->f34 = 1.0f;
        t1->f38 = 20.0f;
        t0->f34 |= 0x18;
        a2->f34 |= 0x10;
        s0->state++;
        break;
    case 10:
        t0->f54 |= 1;
        s0->state++;
        break;
    case 11:
        a2->f54 |= 1;
        s0->state++;
        break;
    case 12:
        a2->f54 |= 1;
        s0->f40 = 0;
        s0->state++;
        break;
    case 13:
        if (s0->f40 >= 5) {
            s0->state = 20;
            goto top;
        }
        break;
    case 20:
        s0->state = 21;
        break;
    case 30:
        s0->state = 31;
    case 31:
        t2->f34 += 4.0f;
        break;
    case 10000:
        {
            void *m = a0->p00;
            func_01B1ADC8(&m);
        }
        break;
    }

    s0->f40++;
    s0->f3C++;
}

void func_01B0AFE8(ObjAE08 *a0, SubB_AE08 *a1, SubB_AE08 *a2, SubA_AE08 *a3, SubA_AE08 *t0, SubC_AE08 *t1)
{
    Arg3AE08 m;

    m.a = a0;
    m.b = func_01B0AE08;
    m.c = a0;
    func_01B1AD20(&m);

    m.a = D_01B00CD8;
    m.b = a0;
    func_01B1B128(&m);

    a0->p1C = a3;
    a0->p20 = t0;
    a0->p24 = a1;
    a0->p28 = a2;
    a0->p2C = t1;
    a0->f3C = 0;
    a0->state = 0;
}
