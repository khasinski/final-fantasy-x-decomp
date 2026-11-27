#include "common.h"

typedef struct {
    u8 pad00[0x18];
    u32 state;
    float f1C;
    float f20;
    int w24;
    u32 w28;
} State4120;

typedef struct {
    void *p00;
    State4120 *p04;
} Arg4120;

typedef struct {
    u8 pad00[0x20];
    float f20;
    float f24;
    float f28;
    float f2C;
} Obj30;

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
    int w0C;
    void *p10;
    int w14;
} Arg6I;

extern u32 D_01B005D8;
extern u32 D_01B005DC;
extern u32 D_01B005E0;
extern u32 D_01B005E4;
extern u32 D_01B005E8;
extern int D_01B005F0[];
extern u32 D_01B00610[];
extern u_long128 D_01B00630[];
extern u_long128 D_01B006A0[];
extern u_long128 D_01B00710[];
extern u8 D_01B008A0[];
extern u8 D_01B00900[];
extern u8 D_01B00930[];
extern u8 D_01B00B58[];
extern u8 D_01B00B78[];
extern u8 D_01B00BA0[];
extern Obj30 D_01B016F0;
extern u8 D_01B01A80[];
extern u8 D_01B0F4D0[];
extern int D_01B0F4FC;

extern float Sg_GetSuimen(void);
extern void func_01B08AB8(void *);
extern void func_01B099F8(void *);
extern void func_01B0A6B0(void *);
extern void func_01B0C048(void *);
extern void func_01B0C098(void *);
extern void func_01B0C1A0(void *);
extern void func_01B0D0A0(void *);

void func_01B04120(Arg4120 *a0)
{
    union {
        struct {
            Arg4 a0;
            Arg6P a1;
        } s;
        Arg6P p;
        Arg6I c;
    } u;
    void *p30;
    void *p34;
    void *p38;
    State4120 *s7 = a0->p04;

    s7->f1C += 1.0f / 30.0f;
    s7->f20 += 1.0f / 30.0f;
    switch (s7->state) {
    case 0:
        s7->state = 10;
    case 10: {
        Arg6P *p;
        u.s.a0.p00 = &D_01B016F0;
        u.s.a0.p04 = D_01B00B58;
        func_01B08AB8(&u.s.a0);
        u.s.a1.p00 = D_01B01A80;
        p = &u.s.a1;
        D_01B016F0.f20 = 1.0f;
        D_01B016F0.f24 = 1.0f;
        D_01B016F0.f28 = 1.0f;
        D_01B016F0.f2C = 0.01f;
        p->p04 = D_01B00B58;
        p->p08 = D_01B00930;
        p->p0C = D_01B008A0;
        p->p10 = D_01B00900;
        p->p14 = &D_01B016F0;
        func_01B0A6B0(p);
        u.c.p00 = D_01B00BA0;
        u.c.p04 = D_01B00B78;
        u.c.p08 = D_01B01A80;
        u.c.w0C = D_01B0F4FC;
        u.c.p10 = D_01B0F4D0;
        u.c.w14 = 3;
        func_01B0C048(&u.c);
        s7->w28 = 0;
        s7->state = 1000;
        s7->w24 = 0;
        break;
    }
    case 1000:
        if (s7->w28 >= D_01B00610[s7->w24]) {
            u.s.a0.p00 = (void *)(s7->w24 * 0x30 + D_01B005DC);
            u.s.a0.p04 = D_01B00B58;
            func_01B08AB8(&u.s.a0);
            {
                int idx = s7->w24;
                u.s.a0.p04 = D_01B00B58;
                *(u_long128 *)(idx * 0x30 + D_01B005DC + 0x20) = D_01B00710[idx];
                u.s.a0.p00 = (void *)(idx * 0x30 + D_01B005D8);
                func_01B08AB8(&u.s.a0);
            }
            *(u_long128 *)(s7->w24 * 0x30 + D_01B005D8 + 0x20) = D_01B00630[s7->w24];
            {
                float y = Sg_GetSuimen();
                register u32 v1 __asm__("$3") = s7->w24;
                float c = 0.1f;
                register u32 b5e0 __asm__("$2");
                register u32 b5d8 __asm__("$5");
                __asm__("" : "+r"(v1) : "f"(c));
                v1 *= 0x30;
                __asm__("" : "+r"(v1) : : "memory");
                b5e0 = D_01B005E0;
                b5d8 = D_01B005D8;
                __asm__("" : "+r"(b5d8) : "r"(b5e0));
                __asm__("" : "+f"(y) : "r"(b5d8));
                y -= c;
                __asm__("" : "+r"(b5d8), "+r"(b5e0) : "f"(y) : "memory");
                u.s.a0.p04 = D_01B00B58;
                __asm__("" : "+r"(b5e0) : : "memory");
                b5e0 = v1 + b5e0;
                v1 = v1 + b5d8;
                __asm__("" : "+r"(v1) : "r"(b5e0));
                *(float *)(v1 + 0x24) = y;
                u.s.a0.p00 = (void *)b5e0;
                func_01B099F8(&u.s.a0);
            }
            {
                int idx = s7->w24;
                register u_long128 q __asm__("$3") = D_01B006A0[idx];
                register void *p930 __asm__("$5") = D_01B00930;
                __asm__("" : "+r"(q), "+r"(p930));
                u.p.p04 = D_01B00B58;
                *(u_long128 *)(idx * 0x30 + D_01B005E0 + 0x20) = q;
                u.p.p08 = p930;
                u.p.p0C = (void *)(idx * 0x30 + D_01B005D8);
                u.p.p10 = (void *)(idx * 0x30 + D_01B005E0);
                u.p.p00 = (void *)(idx * 0x150 + D_01B005E8);
                u.p.p14 = (void *)(idx * 0x30 + D_01B005DC);
                func_01B0A6B0(&u.p);
            }
            {
                int idx = s7->w24;
                u.c.p00 = (void *)(idx * 0x100 + D_01B005E4);
                u.c.p04 = D_01B00B78;
                u.c.p08 = (void *)(idx * 0x150 + D_01B005E8);
                u.c.w0C = D_01B0F4FC;
                u.c.p10 = D_01B0F4D0;
                u.c.w14 = D_01B005F0[idx];
                func_01B0C048(&u.c);
            }
            s7->w24++;
            if (s7->w24 >= 7) {
                s7->state++;
            }
        }
        break;
    case 1001:
        if ((int)s7->w28 >= 35) {
            p30 = D_01B00BA0;
            func_01B0C1A0(&p30);
            p34 = D_01B00BA0;
            func_01B0C098(&p34);
            s7->state = 10000;
        }
        break;
    case 10000:
        p38 = a0->p00;
        func_01B0D0A0(&p38);
        break;
    }
    s7->w28++;
}
