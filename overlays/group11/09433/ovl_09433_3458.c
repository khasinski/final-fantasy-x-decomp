#include "common.h"

typedef struct {
    u8 pad00[0x18];
    u32 phase;          /* 0x18 */
    u8 pad1C[0x0C];
    int timer;          /* 0x28 */
} State3458;

typedef struct {
    void *node;         /* 0x00 */
    State3458 *state;   /* 0x04 */
} Arg3458;

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
} Obj2CF0;

typedef struct {
    u8 pad00[0x20];
    float f20;
    float f24;
    float f28;
    float f2C;
} Obj2A40;

typedef struct {
    u8 pad00[0x54];
    void *p54;
    void *p58;
    u8 pad5C[0x08];
    u32 w64;
} Obj930;

typedef struct {
    void *a0;
    void *a1;
} Call2;

typedef struct {
    void *a0;
    void *a1;
    u32 a2;
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
    void *a2;
    u16 a3;
    u16 a4;
    void *a5;
} Call4110;

typedef struct {
    void *a0;
    u32 out;
} Call5A80;

extern void *g_500;
extern u8 g_690[];
extern u8 g_6c0[];
extern u8 g_8e8[];
extern u8 g_908[];
extern Obj930 g_930;
extern u8 g_29a0[];
extern Obj2A40 g_2a40[2];
extern u8 g_2aa0[];
extern u8 g_2bf0[];
extern Obj2CF0 g_2cf0;
extern u8 g_e8d0[];
extern void *g_e8fc;

extern void func_1B08D60(void *);
extern void func_1B05FC0(void *);
extern void func_1B08E90(void *);
extern void func_1B05B60(void *);
extern void func_1B09A18(void *);
extern void func_1B05E38(void *);
extern void func_1B0ABA0(void *);
extern void func_1B0C538(void *);
extern void func_1B04110(void *);
extern void *func_002B49A0(void *, int, int);
extern void func_1B08F70(void *);
extern void func_1B05A80(void *);
extern void func_1B06060(void *);
extern void func_1B0D590(void *);

static inline void call_8d60(void *a0, void *a1)
{
    Call2 c;
    c.a0 = a0;
    c.a1 = a1;
    func_1B08D60(&c);
}

static inline void call_5fc0(void *a0, void *a1, u32 a2, u8 a3)
{
    Call4B c;
    c.a0 = a0;
    c.a1 = a1;
    c.a2 = a2;
    c.a3 = a3;
    func_1B05FC0(&c);
}

static inline void call_8e90(void *a0, void *a1, float a2)
{
    Call4F c;
    c.a0 = a0;
    c.a1 = a1;
    c.a2 = a2;
    func_1B08E90(&c);
}

static inline void call_5b60(void *a0, void *a1)
{
    Call2 c;
    c.a0 = a0;
    c.a1 = a1;
    func_1B05B60(&c);
}

static inline void call_9a18(void *a0, void *a1)
{
    Call2 c;
    c.a0 = a0;
    c.a1 = a1;
    func_1B09A18(&c);
}

static inline void call_5e38(void *a0, void *a1)
{
    Call2 c;
    c.a0 = a0;
    c.a1 = a1;
    func_1B05E38(&c);
}

static inline void call_aba0(void *a0, void *a1, void *a3, Obj2A40 *pb, float f2C)
{
    Call6 c;
    register Call6 *p __asm__("$2");
    register void *r2 __asm__("$3");
    register void *r4 __asm__("$5");
    float half = f2C;
    __asm__ __volatile__("" : "+f"(half));
    r2 = g_6c0;
    c.a0 = a0;
    p = &c;
    pb->f28 = 1.0f;
    __asm__ __volatile__("" : "+f"(half) : : "memory");
    pb->f2C = half;
    __asm__ __volatile__("" : "+r"(r2) : : "memory");
    r4 = g_690;
    p->a1 = a1;
    __asm__ __volatile__("" : "+r"(r2), "+r"(r4) : : "memory");
    p->a2 = r2;
    {
        register Call6 *a0r __asm__("$4") = p;
        __asm__ __volatile__("" : "+r"(a0r) : : "memory");
        c.a3 = a3;
        p->a4 = r4;
        c.a5 = pb;
        __asm__ __volatile__("" : : : "memory");
        pb->f24 = 1.0f;
        pb->f20 = 1.0f;
        func_1B0ABA0(a0r);
    }
}

static inline void call_c538(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
    Call6 c;
    c.a0 = a0;
    c.a1 = a1;
    c.a2 = a2;
    c.a3 = a3;
    c.a4 = a4;
    c.a5 = a5;
    func_1B0C538(&c);
}

static inline void call_4110(void *a0, void *a5, void *a2, u16 a3, u16 a4, void *a1)
{
    Call4110 c;
    register void *r5 __asm__("$3") = a5;
    register void *r1 __asm__("$2") = a1;
    c.a0 = a0;
    c.a1 = r1;
    c.a2 = a2;
    c.a3 = a3;
    c.a4 = a4;
    c.a5 = r5;
    func_1B04110(&c);
}

static inline void call_8f70(void *a0, void *a1, float a2, float a3)
{
    Call4F c;
    c.a0 = a0;
    c.a1 = a1;
    c.a2 = a2;
    c.a3 = a3;
    func_1B08F70(&c);
}

static inline u32 call_5a80(void *a0)
{
    Call5A80 c;
    c.a0 = a0;
    func_1B05A80(&c);
    return c.out;
}

static inline void call_6060(void *a0)
{
    void *p = a0;
    func_1B06060(&p);
}

static inline void call_d590(void *a0)
{
    void *p = a0;
    func_1B0D590(&p);
}

void func_01B03458(Arg3458 *arg)
{
    State3458 *s = arg->state;

top:
    switch (s->phase) {
    case 0: {
        void *a29a0 = g_29a0;
        call_8d60(&g_2cf0, g_908);
        call_5fc0(a29a0, g_8e8, 20, 1);
        s->phase = 10;
        goto top;
    }

    case 10: {
        void *a29a0 = g_29a0;
        g_2cf0.f6C = 0.5f;
        g_2cf0.f68 = 0.5f;
        g_2cf0.f64 = 0.5f;
        g_2cf0.f60 = 0.5f;
        g_2cf0.f38 = 0.5f;
        g_2cf0.f34 = 0.5f;
        g_2cf0.f30 = 0.5f;
        call_8e90(&g_2cf0, 0, 0.01f);
        call_5b60(a29a0, (void *)0x10791000);
        s->phase++;
        s->timer = 0;
        break;
    }

    case 11: {
        Obj2A40 *pa;
        Obj2A40 *pb;
        void *p2aa0;
        void *p2bf0;
        if (s->timer < 30) {
            break;
        }
        pa = &g_2a40[0];
        pb = &g_2a40[1];
        p2aa0 = g_2aa0;
        p2bf0 = g_2bf0;
        call_9a18(pa, g_8e8);
        call_5e38(g_29a0, &pa->f20);
        pa->f24 -= 5.0f;
        pa->f2C = 1.0f;

        call_9a18(pb, g_8e8);
        call_aba0(p2aa0, g_8e8, pa, pb, 0.5f);
        call_c538(p2bf0, g_908, p2aa0, g_e8fc, g_e8d0, 0);
        s->phase = 20;
        s->timer = 0;
        goto top;
    }

    case 20:
        if (s->timer < 150) {
            break;
        }
        call_4110(&g_930, g_29a0, 0, 0, 0, g_908);
        g_930.p54 = func_002B49A0(g_500, 9, 0);
        g_930.p58 = func_002B49A0(g_500, 9, 0);
        s->phase++;
        s->timer = 0;
        break;

    case 21:
        if (s->timer < 90) {
            break;
        }
        g_2cf0.f6C = 1.0f;
        g_2cf0.f68 = 1.0f;
        g_2cf0.f64 = 1.0f;
        g_2cf0.f60 = 1.0f;
        g_2cf0.f38 = 1.0f;
        g_2cf0.f34 = 1.0f;
        g_2cf0.f30 = 1.0f;
        call_8f70(&g_2cf0, 0, 0.01f, 1.0f);
        g_930.w64 = 1;
        s->phase++;
        break;

    case 22:
        if (call_5a80(g_29a0) != 0) {
            s->phase = 10000;
        }
        break;

    case 10000:
        call_6060(g_29a0);
        call_d590(arg->node);
        break;
    }

    s->timer++;
}
