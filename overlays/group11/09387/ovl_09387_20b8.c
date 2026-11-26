#include "common.h"

typedef struct {
    u8 pad00[0x18];
    u32 phase;          /* 0x18 */
    u8 pad1C[0x0C];
    int total;          /* 0x28 */
    int timer;          /* 0x2C */
} State20B8;

typedef struct {
    void *node;         /* 0x00 */
    State20B8 *state;   /* 0x04 */
} Arg20B8;

typedef struct {
    u8 pad00[0x30];
    float f30;
    float f34;
    float f38;
    u8 pad3C[0x24];
    float f60;
    float f64;
    float f68;
    float f6C;
} ObjA90;

typedef struct {
    u8 pad00[0x20];
    float f20;
    float f24;
    float f28;
    float f2C;
} ObjVec;

typedef struct {
    u8 pad00[0x14C];
    u8 b14C;
} ObjFlag14C;

typedef struct {
    void *a0;
    void *a1;
    void *a2;
    void *a3;
    u8 a4;
} Call5B;

typedef struct {
    void *a0;
    void *a1;
    void *a2;
    u8 a3;
} Call4B;

typedef struct {
    void *a0;
    void *a1;
    float a2;
    float a3;
} Call4F;

typedef struct {
    void *a0;
    void *a1;
    void *a2;
    void *a3;
    void *a4;
    void *a5;
} Call6;

typedef struct {
    void *a0;
    void *a1;
    u32 a2;
} Call3;

typedef struct {
    void *a0;
    void *a1;
} Call2;

extern void *g_668;
extern void *g_66c;
extern void *g_670;
extern u8 g_790[];
extern u8 g_7f0[];
extern u8 g_820[];
extern u8 g_a48[];
extern u8 g_a68[];
extern ObjA90 g_a90;
extern u8 g_b50[];
extern u8 g_1090[];
extern ObjVec g_1130[2];
extern ObjVec g_1190[2];
extern ObjVec g_11f0[2];
extern ObjFlag14C g_1250;
extern ObjFlag14C g_13a0;
extern ObjFlag14C g_14f0;
extern u8 g_1640[];
extern u8 g_1740[];
extern u8 g_1840[];
extern u8 g_1940[];
extern u8 g_1978[];
extern u8 g_19b0[];
extern u8 g_d390[];
extern void *g_d3bc;

extern void func_1B02D08(void *);
extern void func_1B042B8(void *);
extern void func_1B07058(void *);
extern void func_1B03E90(void *);
extern void func_1B07188(void *);
extern void func_1B07D10(void *);
extern void func_1B03DB0(void *);
extern void func_1B08E98(void *);
extern void func_1B0AFF8(void *);
extern void func_1B0A788(void *);
extern void func_1B0A750(void *);
extern int func_001CE050(void *, int);
extern int func_002D02E8(void *, int, int, int);
extern int func_002D0570(int);
extern void func_002EF0D0(void *, int, int);
extern void func_1B03C60(void *);
extern void func_1B04130(void *);
extern void func_1B07268(void *);
extern void func_1B03D40(void *);
extern void func_1B04460(void *);
extern void func_1B04358(void *);
extern void func_1B0C050(void *);

static inline void call_2d08(void *a0, void *a1, void *a2, void *a3, u8 a4) {
    Call5B c; c.a0 = a0; c.a1 = a1; c.a2 = a2; c.a3 = a3; c.a4 = a4; func_1B02D08(&c);
}
static inline void call_42b8(void *a0, void *a1, void *a2, u8 a3) {
    Call4B c; c.a0 = a0; c.a1 = a1; c.a2 = a2; c.a3 = a3; func_1B042B8(&c);
}
static inline void call_7058(void *a0, void *a1) {
    Call2 c; c.a0 = a0; c.a1 = a1; func_1B07058(&c);
}
static inline void call_3e90(void *a0, void *a1) {
    Call2 c; c.a0 = a0; c.a1 = a1; func_1B03E90(&c);
}
static inline void call_7188(void *a0, void *a1, float a2) {
    Call4F c; c.a0 = a0; c.a1 = a1; c.a2 = a2; func_1B07188(&c);
}
static inline void call_7d10(void *a0, void *a1) {
    Call2 c; c.a0 = a0; c.a1 = a1; func_1B07D10(&c);
}
static inline void call_3db0(void *a0, void *a1, void *a2) {
    Call3 c; c.a0 = a0; c.a1 = a1; c.a2 = (u32)a2; func_1B03DB0(&c);
}
static inline void call_8e98(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5) {
    Call6 c; c.a0 = a0; c.a1 = a1; c.a2 = a2; c.a3 = a3; c.a4 = a4; c.a5 = a5; func_1B08E98(&c);
}
static inline void call_7d10_v(void *a0, void *a1) {
    Call2 c;
    Call2 *p = &c;
    c.a0 = a0;
    *(void * volatile *)&p->a1 = a1;
    func_1B07D10(p);
}
static inline void call_7d10_pb(ObjVec *pb, void *a1, ObjVec *pa, float one) {
    Call2 c;
    Call2 *p = &c;
    register float f0 __asm__("$f0") = pa->f24;
    register float f1 __asm__("$f1");
    void *two;
    register Call2 *a0r __asm__("$4") = p;
    __asm__ __volatile__("" : "+r"(a0r) : "f"(f0));
    f1 = 4.0f;
    __asm__ __volatile__("" : "+f"(f1) : "r"(a0r));
    two = (void *)2;
    __asm__ __volatile__("" : : "r"(two), "f"(f1));
    *(volatile float *)&pa->f2C = one;
    __asm__ __volatile__("" : : "m"(pa->f2C));
    f0 -= f1;
    __asm__ __volatile__("" : "+f"(f0));
    c.a0 = pb;
    *(void * volatile *)&p->a1 = a1;
    __asm__("" : "+f"(f0) : "m"(p->a1));
    pa->f24 = f0;
    func_1B07D10(a0r);
}
static inline void call_8e98_51(void *a0, void *a1, void *a3, ObjVec *pb, float one, float f2C) {
    Call6 c;
    register Call6 *p __asm__("$2");
    register void *r2 __asm__("$3");
    register void *r4 __asm__("$5");
    float w = f2C;
    __asm__ __volatile__("" : "+f"(w));
    r2 = g_820;
    p = &c;
    c.a0 = a0;
    __asm__("" : "+r"(r2) : "r"(p) : "memory");
    pb->f28 = one;
    __asm__("" : "+f"(w) : "r"(p) : "memory");
    pb->f2C = w;
    __asm__("" : : "r"(p) : "memory");
    r4 = g_7f0;
    p->a2 = r2;
    __asm__("" : "+r"(r4) : : "memory");
    c.a3 = a3;
    __asm__("" : : : "memory");
    {
        register Call6 *a0r __asm__("$4") = p;
        __asm__("" : "+r"(a0r) : : "memory");
        p->a4 = r4;
        c.a5 = pb;
        __asm__("" : : : "memory");
        pb->f20 = one;
        __asm__("" : : : "memory");
        pb->f24 = one;
        __asm__("" : "+r"(a0r) : : "memory");
        p->a1 = a1;
        func_1B08E98(a0r);
    }
}
static inline void call_aff8_51(void *a0, void *a1, ObjFlag14C *a2, void *a4, void *a5) {
    Call6 c;
    Call6 *p = &c;
    register void *r3 __asm__("$6");
    register void *r1 __asm__("$3");
    register void *r4 __asm__("$5");
    register u8 one_b __asm__("$2");
    c.a0 = a0;
    {
        register void **gp __asm__("$2") = &g_d3bc;
        r3 = *gp;
    }
    __asm__("" : "+r"(r3) : "m"(c.a0));
    r1 = a1;
    one_b = 1;
    __asm__("" : "+r"(one_b) : "r"(r3));
    __asm__("" : "+r"(r1) : "r"(one_b));
    *(volatile u8 *)&a2->b14C = one_b;
    r4 = a4;
    __asm__("" : "+r"(r1) : "m"(a2->b14C));
    *(void * volatile *)&p->a1 = r1;
    __asm__("" : "+r"(r3) : "m"(p->a1));
    c.a3 = r3;
    __asm__ __volatile__("" : : "m"(c.a3));
    {
        register Call6 *a0r __asm__("$4") = p;
        __asm__("" : "+r"(r4) : "r"(a0r));
        *(void * volatile *)&p->a4 = r4;
        c.a2 = a2;
        p->a5 = a5;
        func_1B0AFF8(a0r);
    }
}
static inline void call_a788_51(void *a1, void *a2, void *a5) {
    Call6 c;
    Call6 *p = &c;
    register void *r4 __asm__("$5") = g_668;
    register void *r3 __asm__("$2") = g_790;
    void *a0;
    __asm__ __volatile__("" : "+r"(r4));
    __asm__ __volatile__("" : "+r"(r3));
    *(void * volatile *)&p->a1 = a1;
    __asm__ __volatile__("" : : "m"(p->a1));
    a0 = g_19b0;
    c.a2 = a2;
    __asm__("" : "+r"(r3) : "r"(a0), "m"(c.a2));
    *(void * volatile *)&p->a3 = r3;
    __asm__ __volatile__("" : : "m"(p->a3));
    {
        register Call6 *a0r __asm__("$4") = p;
        __asm__("" : "+r"(r4) : "r"(a0r));
        c.a4 = r4;
        p->a5 = a5;
        c.a0 = a0;
        func_1B0A788(a0r);
    }
}
static inline void call_aff8(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5) {
    Call6 c; c.a0 = a0; c.a1 = a1; c.a2 = a2; c.a3 = a3; c.a4 = a4; c.a5 = a5; func_1B0AFF8(&c);
}
static inline void call_a788(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5) {
    Call6 c; c.a0 = a0; c.a1 = a1; c.a2 = a2; c.a3 = a3; c.a4 = a4; c.a5 = a5; func_1B0A788(&c);
}
static inline void call_a750(void *a0, void *a1) {
    Call2 c; c.a0 = a0; c.a1 = a1; func_1B0A750(&c);
}
static inline void call_3c60(void *a0, void *a1, float a2) {
    Call4F c; c.a0 = a0; c.a1 = a1; c.a2 = a2; func_1B03C60(&c);
}
static inline void call_4130(void *a0, void *a1) {
    Call2 c; c.a0 = a0; c.a1 = a1; func_1B04130(&c);
}
static inline void call_7268(void *a0, void *a1, float a2, float a3) {
    Call4F c; c.a0 = a0; c.a1 = a1; c.a2 = a2; c.a3 = a3; func_1B07268(&c);
}
static inline void call_3d40(void *a0, void *a1, u32 a2) {
    Call3 c; c.a0 = a0; c.a1 = a1; c.a2 = a2; func_1B03D40(&c);
}
static inline void call_4460(void *a0) { void *p = a0; func_1B04460(&p); }
static inline void call_4358(void *a0) { void *p = a0; func_1B04358(&p); }
static inline void call_c050(void *a0) { void *p = a0; func_1B0C050(&p); }

void func_01B020B8(Arg20B8 *arg)
{
    State20B8 *s = arg->state;

    switch (s->phase) {
    case 0: {
        void *pb50 = g_b50;
        void *pa48 = g_a48;
        void *p1090;
        call_2d08(pb50, pa48, g_66c, 0, 1);
        p1090 = g_1090;
        call_42b8(p1090, pa48, g_670, 0);
        call_7058(&g_a90, g_a68);
        call_3e90(p1090, (void *)0x49);
        s->phase = 10;
        break;
    }

    case 10: {
        ObjVec *pa;
        ObjVec *pb;
        void *pa48;
        ObjFlag14C *p1250;
        void *p1640;
        void *p1940;

        g_a90.f6C = 0.5f;
        g_a90.f68 = 0.5f;
        g_a90.f64 = 0.5f;
        g_a90.f60 = 0.5f;
        g_a90.f38 = 0.5f;
        g_a90.f34 = 0.5f;
        g_a90.f30 = 0.5f;
        call_7188(&g_a90, 0, 0.02f);

        pa = &g_1130[0];
        pb = &g_1130[1];
        pa48 = g_a48;
        p1250 = &g_1250;
        p1640 = g_1640;

        call_7d10(pa, pa48);
        call_3db0(g_1090, (void *)1, &pa->f20);
        pa->f2C = 1.0f;

        call_7d10(pb, pa48);
        pb->f20 = 1.0f;
        pb->f24 = 1.0f;
        pb->f28 = 1.0f;
        pb->f2C = 0.26f;

        call_8e98(p1250, pa48, g_820, pa, g_7f0, pb);

        p1250->b14C = 1;
        call_aff8(p1640, g_a68, p1250, g_d3bc, g_d390, (void *)1);

        p1940 = g_1940;
        call_a788(p1940, pa48, p1250, g_790, g_668, 0);
        call_a750(p1940, 0);

        s->timer = 0;
        s->phase = 30;
        break;
    }

    case 30:
        if (s->timer < 170) {
            break;
        }
        func_001CE050(g_670, 0x4A);
        func_002D02E8(g_668, 8, 10, 2);
        s->timer = 0;
        s->phase = 60;
        break;

    case 60: {
        ObjVec *pa;
        ObjVec *pb;
        void *pa48;
        ObjFlag14C *p13a0;
        void *p1740;
        void *p1978;

        if (s->timer < 0) {
            break;
        }
        if (func_002D0570(2) != 0) {
            break;
        }

        pa = &g_1190[0];
        pb = &g_1190[1];
        pa48 = g_a48;
        p13a0 = &g_13a0;
        p1740 = g_1740;

        call_7d10(pa, pa48);
        call_3db0(g_1090, (void *)1, &pa->f20);
        pa->f2C = 1.0f;

        call_7d10(pb, pa48);
        pb->f20 = 1.0f;
        pb->f24 = 1.0f;
        pb->f28 = 1.0f;
        pb->f2C = 0.25f;

        call_8e98(p13a0, pa48, g_820, pa, g_7f0, pb);

        p13a0->b14C = 1;
        call_aff8(p1740, g_a68, p13a0, g_d3bc, g_d390, 0);

        p1978 = g_1978;
        call_a788(p1978, pa48, p13a0, g_790, g_668, (void *)1);
        call_a750(p1978, 0);

        s->timer = 0;
        s->phase = 50;
        break;
    }

    case 50: {
        float buf[4];
        if (s->total < 280) {
            break;
        }
        func_002EF0D0(buf, 0, 16);
        buf[1] = 30.0f;
        call_3c60(g_1090, buf, 0.02f);

        s->phase++;
        s->timer = 0;
        break;
    }

    case 51: {
        ObjVec *pa;
        ObjVec *pb;
        ObjFlag14C *p14f0;
        void *p1840;

        if (s->total < 330) {
            break;
        }

        {
            void *pa48;
            float one;
            pa = &g_11f0[0];
            pa48 = g_a48;
            p14f0 = &g_14f0;
            p1840 = g_1840;

            call_7d10_v(pa, pa48);
            one = 1.0f;
            __asm__ __volatile__("" : "+f"(one));
            call_4130(g_1090, &pa->f20);

            pb = &g_11f0[1];
            call_7d10_pb(pb, g_a48, pa, one);
            call_8e98_51(p14f0, pa48, pa, pb, one, 0.35f);

            call_aff8_51(p1840, g_a68, p14f0, g_d390, (void *)2);
            call_a788_51(g_a48, p14f0, (void *)2);
            call_a750(g_19b0, 0);
        }

        s->phase++;
        s->timer = 0;
        break;
    }

    case 52:
        if (s->timer < 90) {
            break;
        }
        g_a90.f6C = 1.0f;
        g_a90.f68 = 1.0f;
        g_a90.f64 = 1.0f;
        g_a90.f60 = 1.0f;
        g_a90.f38 = 1.0f;
        g_a90.f34 = 1.0f;
        g_a90.f30 = 1.0f;
        call_7268(&g_a90, 0, 0.01f, 1.0f);

        s->phase++;
        break;

    case 53:
        if (s->timer < 120) {
            break;
        }
        call_3d40(g_1090, 0, 30);

        s->timer = 0;
        s->phase = 10000;
        break;

    case 10000:
        if (s->timer < 30) {
            break;
        }
        call_4460(g_1090);
        call_4358(g_1090);
        call_c050(arg->node);
        break;
    }

    s->total++;
    s->timer++;
}
