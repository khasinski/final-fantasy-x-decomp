#include "common.h"

typedef struct {
    u8 pad00[0x30];
    float f30;
    float f34;
    float f38;
} SubA_AD20;

typedef struct {
    u8 pad00[0x34];
    u8 f34;
    u8 pad35[0x1F];
    u8 f54;
} SubB_AD20;

typedef struct {
    u8 pad00[0x34];
    float f34;
} SubC_AD20;

typedef struct {
    u8 pad00[0x18];
    u32 state;      /* 0x18 */
    SubA_AD20 *p1C; /* 0x1C */
    SubA_AD20 *p20; /* 0x20 */
    SubB_AD20 *p24; /* 0x24 */
    SubB_AD20 *p28; /* 0x28 */
    SubC_AD20 *p2C; /* 0x2C */
    u8 pad30[0x0C]; /* 0x30 */
    int f3C;        /* 0x3C */
    int f40;        /* 0x40 */
} ObjAD20;

typedef struct {
    void *p00;
    ObjAD20 *obj;
} MsgAD20;

typedef struct {
    void *a;
    void *b;
    void *c;
} Arg3AD20;

extern u8 D_01B00CE8[];
extern void func_01B1A2E8(void *);
extern void func_01B1A390(void *);
extern void func_01B1A6F0(void *);

void func_01B0AD20(MsgAD20 *a0)
{
    ObjAD20 *s0 = a0->obj;
    SubA_AD20 *a2 = s0->p1C;
    SubA_AD20 *t0 = s0->p20;
    SubB_AD20 *t2 = s0->p24;
    SubB_AD20 *a3 = s0->p28;
    SubC_AD20 *t1 = s0->p2C;

retry:
    switch (s0->state) {
    case 0:
        a2->f30 = 30.0f;
        a2->f34 = 1.0f;
        a2->f38 = 5.0f;
        t0->f30 = 30.0f;
        t0->f34 = 1.0f;
        t0->f38 = 20.0f;
        t2->f34 |= 0x18;
        a3->f34 |= 0x10;
        s0->state++;
        break;
    case 10:
        a3->f54 |= 1;
        s0->state++;
        break;
    case 11:
        s0->state = 12;
        break;
    case 12:
        s0->state = 13;
        s0->f40 = 0;
        break;
    case 13:
        if (s0->f40 >= 5) {
            s0->state = 20;
            goto retry;
        }
        break;
    case 20:
        s0->state = 21;
        break;
    case 30:
        s0->state = 31;
    case 31:
        t1->f34 += 4.0f;
        break;
    case 10000:
        {
            void *m = a0->p00;
            func_01B1A390(&m);
        }
        break;
    }

    s0->f40++;
    s0->f3C++;
}

void func_01B0AEF0(ObjAD20 *a0, SubB_AD20 *a1, SubB_AD20 *a2, SubA_AD20 *a3, SubA_AD20 *t0, SubC_AD20 *t1)
{
    Arg3AD20 m;

    m.a = a0;
    m.b = func_01B0AD20;
    m.c = a0;
    func_01B1A2E8(&m);

    m.a = D_01B00CE8;
    m.b = a0;
    func_01B1A6F0(&m);

    a3->f38 = 5.0f;
    a3->f30 = 30.0f;
    a3->f34 = 1.0f;
    t0->f30 = 30.0f;
    t0->f34 = 1.0f;
    t0->f38 = 20.0f;
    a1->f34 |= 0x18;
    a2->f34 |= 0x10;
    a1->f54 |= 1;
    a2->f54 |= 1;

    a0->p1C = a3;
    a0->p20 = t0;
    a0->p24 = a1;
    a0->p28 = a2;
    a0->p2C = t1;
    a0->f3C = 0;
    a0->state = 0;
}
