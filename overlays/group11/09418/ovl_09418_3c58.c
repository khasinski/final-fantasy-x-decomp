#include "common.h"

typedef struct {
    u8 pad00[0x20];
    float x;
    float y;
    float z;
    float w;
} Mat30;

typedef struct {
    u8 pad00[0x20];
    u8 f20[0xA0];
    u8 fC0[0x20];
    float fE0[4];
    u8 padF0[0x14];
    u8 b104;
    u8 pad105[0xB];
    u32 state;
    u32 cnt;
} Obj3C58;

typedef struct {
    void *p00;
    Obj3C58 *p04;
} TaskArg3C58;

typedef struct {
    u8 pad00[0x20];
    int w20;
    int w24;
    int w28;
} Obj15A0;

typedef struct {
    void *p00;
    void *p04;
} Arg2;

typedef struct {
    void *p00;
    void *p04;
    void *p08;
    u8 b0C;
} Arg4;

typedef struct {
    void *p00;
    void *p04;
    void *p08;
    void *p0C;
    void *p10;
    void *p14;
} Arg6P;

typedef struct {
    void *p00;
    void *p04;
    void *p08;
    void *p0C;
    void *p10;
    int p14;
} Arg6I;

extern u8 (*D_01B005E4)[0x100];
extern u8 D_01B00900[];
extern u8 D_01B00930[];
extern u8 D_01B00B58[];
extern u8 D_01B00B78[];
extern u8 D_01B00CA0[];
extern u8 D_01B00DA0[2][0x100];
extern Obj15A0 D_01B015A0;
extern Mat30 D_01B016F0[6];
extern u8 D_01B01BD0[];
extern u8 D_01B01D20[2][0x150];
extern u8 D_01B0F4D0[];
extern void *D_01B0F4FC;

extern float Sg_GetSuimen(void);
extern void func_002DD0B0(void *, void *);
extern void func_01B05D18(void *);
extern void func_01B08AB8(void *);
extern void func_01B08F88(void *);
extern void func_01B0A6B0(void *);
extern void func_01B0C048(void *);
extern void func_01B0C098(void *);
extern void func_01B0C1A0(void *);
extern void func_01B0D0A0(void *);

void func_01B03C58(TaskArg3C58 *a0)
{
    Obj3C58 *fp = a0->p04;
    union {
        struct {
            Arg4 a0;
            Arg6P a1;
        } s;
        Arg6I c;
    } u;
    void *tmp30;
    void *tmp34;
    void *tmp38;
    void *tmp3C;
    void *tmp40;

    switch (fp->state) {
    case 0: {
        void *f20 = fp->f20;
        void *b58 = D_01B00B58;
        u8 one = 1;
        register void *a0_sp __asm__("$4");
        __asm__("" : "+r"(one) : "r"(f20), "r"(b58));
        u.s.a0.b0C = one;
        __asm__("" : : : "memory");
        a0_sp = &u.s.a0;
        __asm__("" : "+r"(a0_sp) : : "memory");
        u.s.a0.p00 = f20;
        u.s.a0.p04 = b58;
        u.s.a0.p08 = 0;
        func_01B05D18(a0_sp);

        u.s.a0.p00 = fp->fC0;
        u.s.a0.p04 = b58;
        u.s.a0.p08 = f20;
        func_01B08F88(&u.s.a0);

        fp->b104 = 1;
        fp->state = 10;
        fp->cnt = 0;
        break;
    }
    case 10:
        if (fp->cnt < 4) {
            break;
        }
        fp->state = 11;
    case 11: {
        register void *b58 __asm__("$19");
        register void *bd0 __asm__("$18");
        if (fp->cnt < 80) {
            break;
        }
        u.s.a0.p00 = &D_01B016F0[1];
        b58 = D_01B00B58;
        u.s.a0.p04 = b58;
        func_01B08AB8(&u.s.a0);
        D_01B016F0[1].x = 1.0f;
        D_01B016F0[1].y = 1.0f;
        D_01B016F0[1].z = 1.0f;
        D_01B016F0[1].w = 0.06000000238f;

        u.s.a0.p00 = &D_01B016F0[2];
        u.s.a0.p04 = b58;
        func_01B08AB8(&u.s.a0);
        func_002DD0B0(&D_01B016F0[2].x, fp->fE0);
        {
            float y = Sg_GetSuimen() - 20.1f;
            Arg6P *p;
            bd0 = D_01B01BD0;
            u.s.a1.p00 = bd0;
            p = &u.s.a1;
            D_01B016F0[2].y = y;
            p->p04 = b58;
            p->p08 = D_01B00930;
            p->p0C = &D_01B016F0[2];
            p->p10 = D_01B00900;
            p->p14 = &D_01B016F0[1];
            func_01B0A6B0(p);
        }

        u.c.p00 = D_01B00CA0;
        u.c.p04 = D_01B00B78;
        u.c.p08 = bd0;
        u.c.p0C = D_01B0F4FC;
        u.c.p10 = D_01B0F4D0;
        u.c.p14 = 2;
        func_01B0C048(&u.c);

        fp->state++;
        break;
    }
    case 12:
        if (fp->fE0[1] < Sg_GetSuimen()) {
            break;
        }
        {
            int i;
            tmp30 = D_01B00CA0;
            func_01B0C1A0(&tmp30);
            tmp34 = D_01B00CA0;
            func_01B0C098(&tmp34);
            for (i = 0; i < 7; i++) {
                tmp38 = (void *)((i << 8) + (u32)D_01B005E4);
                func_01B0C1A0(&tmp38);
                tmp3C = (void *)((i << 8) + (u32)D_01B005E4);
                func_01B0C098(&tmp3C);
            }
        }
        u.s.a0.p00 = &D_01B016F0[3];
        u.s.a0.p04 = D_01B00B58;
        func_01B08AB8(&u.s.a0);
        D_01B016F0[3].x = 1.0f;
        D_01B016F0[3].y = 1.0f;
        D_01B016F0[3].z = 1.0f;
        D_01B016F0[3].w = 0.1f;

        u.s.a0.p00 = &D_01B016F0[4];
        u.s.a0.p04 = D_01B00B58;
        func_01B08AB8(&u.s.a0);
        func_002DD0B0(&D_01B016F0[4].x, fp->fE0);
        D_01B016F0[4].y += D_01B016F0[3].y * 30.0f;

        u.c.p00 = D_01B01D20[0];
        u.c.p04 = D_01B00B58;
        u.c.p08 = D_01B00930;
        u.c.p0C = &D_01B016F0[4];
        u.c.p10 = D_01B00900;
        u.c.p14 = (int)&D_01B016F0[3];
        func_01B0A6B0(&u.c);

        u.c.p00 = D_01B00DA0[0];
        u.c.p04 = D_01B00B78;
        u.c.p08 = D_01B01D20[0];
        u.c.p0C = D_01B0F4FC;
        u.c.p10 = D_01B0F4D0;
        u.c.p14 = 0;
        func_01B0C048(&u.c);

        D_01B016F0[5].x = -101.5192413f;
        D_01B016F0[5].y = -140.0f;
        D_01B016F0[5].z = 119.7922821f;
        D_01B015A0.w20 = 0;
        D_01B015A0.w24 = -33280;
        D_01B015A0.w28 = 0;

        u.c.p00 = D_01B00DA0[1];
        u.c.p04 = D_01B00B78;
        u.c.p08 = D_01B01D20[1];
        u.c.p0C = D_01B0F4FC;
        u.c.p10 = D_01B0F4D0;
        u.c.p14 = 9;
        func_01B0C048(&u.c);

        fp->state = 10000;
        break;
    case 10000:
        tmp40 = a0->p00;
        func_01B0D0A0(&tmp40);
        break;
    }
    fp->cnt++;
}
