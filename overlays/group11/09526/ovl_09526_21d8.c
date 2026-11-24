#include "common.h"

typedef struct {
    void *p0;
    void *work;
} OvlTask;

typedef struct {
    u8 pad00[0x18];
    u32 state;          /* 0x18 */
    int w1C;            /* 0x1C */
    int timer;          /* 0x20 */
    u8 pad24[0xC];
    u8 s30[0x20];       /* 0x30 */
    u8 s50[0x520];      /* 0x50 */
    u8 s570[0x58];      /* 0x570 */
    void *w5C8;         /* 0x5C8 */
    u8 pad5CC[0x44];
    u8 s610[0x20];      /* 0x610 */
    u8 s630[0x10];      /* 0x630 */
    u8 s640[0x20];      /* 0x640 */
    float f660, f664, f668, f66C; /* 0x660..0x66C */
    u8 s670[0x20];      /* 0x670 */
    float f690, f694, f698, f69C; /* 0x690..0x69C */
    u8 s6A0[0x30];      /* 0x6A0 */
    float f6D0, f6D4, f6D8; /* 0x6D0..0x6D8 */
    u8 pad6DC[0x64];
    u8 s740[0x150];     /* 0x740 */
    void *w890;         /* 0x890 */
    int w894;           /* 0x894 */
    u8 pad898[0x8];
    u8 s8A0[0x160];     /* 0x8A0 */
    u8 sA00[0x160];     /* 0xA00 */
    u8 sB60[0x100];     /* 0xB60 */
    u8 sC60[0x100];     /* 0xC60 */
    u8 sD60[0x38];      /* 0xD60 */
    u8 sD98[0x38];      /* 0xD98 */
    u8 sDD0[0x18];      /* 0xDD0 */
    int wDE8;           /* 0xDE8 */
} Ovl9526Work;

typedef struct {
    u8 pad00[0x20];
    float f20, f24, f28, f2C;
    float f30, f34, f38, f3C;
    u8 pad40[0x10];
    float f50, f54, f58, f5C;
    float f60, f64, f68, f6C;
} Ovl9526ObjAE0;

typedef struct {
    void *p0;
    void *p4;
    void *p8;
    u8 bC;
} Arg4428;

typedef struct {
    void *p0;
    void *p4;
    void *p8;
    void *pC;
    u8 b10;
} Arg2E78;

typedef struct {
    void *p0;
    void *p4;
    void *p8;
    void *pC;
    void *p10;
} Arg5;

typedef struct {
    void *p0;
    void *p4;
    void *p8;
    void *pC;
    void *p10;
    int w14;
} Arg6i;

typedef struct {
    void *p0;
    int w4;
    float f8;
} Arg72F8;

typedef struct {
    void *p0;
    int w4;
    float f8;
    float fC;
} Arg73D8;

extern void *D_01B006B8;
extern void *D_01B006C0;
extern u8 D_01B006D0;
extern u8 D_01B007E0[];
extern u8 D_01B00810[];
extern u8 D_01B00840[];
extern u8 D_01B00870[];
extern u8 D_01B00A98[];
extern u8 D_01B00AB8[];
extern Ovl9526ObjAE0 D_01B00AE0;
extern u8 D_01B0EA10[];
extern void *D_01B0EA3C;

extern int func_001D3A70(void *);
extern void func_001C5E90(void *, int, int);

extern void func_01B04428(void *);
extern void func_01B02E78(void *);
extern void func_01B07E80(void *);
extern void func_01B04150(void *);
extern void func_01B0AF58(void *);
extern void func_01B08350(void *);
extern void func_01B02A90(void *);
extern void func_01B0C678(void *);
extern void func_01B071C8(void *);
extern void func_01B072F8(void *);
extern void func_01B0BE08(void *);
extern void func_01B0BDD0(void *);
extern void func_01B02168(void *, void *);
extern void func_01B073D8(void *);
extern void func_01B03058(void *);
extern void func_01B02F88(void *);
extern void func_01B045D0(void *);
extern void func_01B044C8(void *);
extern void func_01B0D6D0(void *);

static inline void call_4428(void *p0, void *p4, void *p8, u8 bC)
{
    Arg4428 a;
    a.p4 = p4;
    a.p8 = p8;
    a.p0 = p0;
    a.bC = bC;
    func_01B04428(&a);
}

static inline void call_2e78(void *p0, void *p4, void *p8, void *pC, u8 b10)
{
    Arg2E78 a;
    a.p4 = p4;
    *(volatile void **)&a.p0 = p0;
    *(volatile void **)&a.p8 = p8;
    *(volatile void **)&a.pC = pC;
    a.b10 = b10;
    func_01B02E78(&a);
}

static inline void call_7e80(void *p0, void *p4)
{
    void *a[2];
    a[0] = p0;
    a[1] = p4;
    func_01B07E80(a);
}

static inline void call_4150(void *p0, void *p4)
{
    void *a[2];
    a[0] = p0;
    a[1] = p4;
    func_01B04150(a);
}

static inline void call_af58(void *p0, void *p4, void *p8, void *pC, void *p10)
{
    Arg5 a;
    a.p8 = p8;
    a.pC = pC;
    a.p10 = p10;
    a.p0 = p0;
    a.p4 = p4;
    func_01B0AF58(&a);
}

static inline void call_8350(void *p0, void *p4, void *p8)
{
    void *a[3];
    a[1] = p4;
    a[2] = p8;
    a[0] = p0;
    func_01B08350(a);
}

static inline void call_2a90(void *p0, void *p4, void *p8, void *pC, void *p10)
{
    Arg5 a;
    *(volatile void **)&a.pC = pC;
    *(volatile void **)&a.p10 = p10;
    a.p0 = p0;
    *(volatile void **)&a.p4 = p4;
    a.p8 = p8;
    func_01B02A90(&a);
}

static inline void call_c678(void *p0, void *p4, void *p8, void *pC, void *p10, int w14)
{
    Arg6i a;
    *(volatile void **)&a.p8 = p8;
    *(volatile void **)&a.p0 = p0;
    *(volatile void **)&a.pC = pC;
    a.p10 = p10;
    a.w14 = w14;
    a.p4 = p4;
    func_01B0C678(&a);
}

static inline void call_c678_b(void *p0, void *p4, void *p8, void *pC, void *p10, int w14)
{
    Arg6i a;
    a.p4 = p4;
    *(volatile void **)&a.p0 = p0;
    *(volatile void **)&a.p8 = p8;
    *(volatile void **)&a.pC = pC;
    a.p10 = p10;
    a.w14 = w14;
    func_01B0C678(&a);
}

static inline void call_71c8(void *p0, void *p4)
{
    void *a[2];
    a[1] = p4;
    a[0] = p0;
    func_01B071C8(a);
}

static inline void call_72f8(void *p0, int w4, float f8)
{
    Arg72F8 a;
    a.p0 = p0;
    a.f8 = f8;
    a.w4 = w4;
    func_01B072F8(&a);
}

static inline void call_be08(void *p0, void *p4, void *p8, void *pC, void *p10, int w14)
{
    Arg6i a;
    a.p4 = p4;
    a.p8 = p8;
    a.pC = pC;
    a.p10 = p10;
    a.p0 = p0;
    a.w14 = w14;
    func_01B0BE08(&a);
}

static inline void call_bdd0(void *p0, void *p4)
{
    void *a[2];
    a[0] = p0;
    a[1] = p4;
    func_01B0BDD0(a);
}

static inline void call_73d8(void *p0, int w4, float f8, float fC)
{
    Arg73D8 a;
    a.p0 = p0;
    a.w4 = w4;
    a.f8 = f8;
    a.fC = fC;
    func_01B073D8(&a);
}

static inline void set_ae0(Ovl9526ObjAE0 *o, float z, float p1, float one)
{
    o->f5C = z;
    o->f54 = z;
    o->f50 = z;
    o->f24 = z;
    o->f58 = p1;
    o->f20 = z;
    o->f28 = p1;
    o->f6C = one;
    o->f68 = one;
    o->f64 = one;
    o->f60 = one;
    o->f38 = one;
    o->f34 = one;
    o->f30 = one;
}

void func_01B021D8(OvlTask *task)
{
    volatile u32 pad[4];
    void *d0;
    void *d1;
    void *d2;
    void *d3;
    void *d4;
    register Ovl9526Work *s __asm__("$22") = (Ovl9526Work *)task->work;

top:
    switch (s->state) {
    case 0:
        call_4428(s->s570, D_01B00A98, D_01B006C0, 0);
        call_2e78(s->s30, D_01B00A98, D_01B006C0, 0, 0);
        call_7e80(s->s610, D_01B00A98);
        call_4150(s->s50, s->s630);
        call_af58(s->s740, D_01B00A98, D_01B007E0, D_01B00840, D_01B00810);
        s->w890 = s->w5C8;
        s->w894 = 12;
        call_8350(s->s6A0, D_01B00A98, s->s740);
        if (func_001D3A70(D_01B006C0) == 0x7A) {
            s->f6D0 = 1.0f;
            s->f6D4 = -0.2f;
            s->f6D8 = 1.0f;
        } else {
            s->f6D0 = 1.25f;
            s->f6D4 = -0.2f;
            s->f6D8 = -0.4f;
        }
        call_7e80(s->s640, D_01B00A98);
        {
            register float f0 __asm__("$f0") = 1.0f;
            register float f1 __asm__("$f1") = 0.15f;
            *(volatile float *)&s->f668 = f0;
            *(volatile float *)&s->f66C = f1;
            __asm__("" : "+f"(f0) : "f"(f1) : "memory");
            s->f664 = f0;
            s->f660 = f0;
        }
        call_2a90(s->s8A0, D_01B00A98, s->s6A0, s->s640, s->s610);
        call_c678(s->sB60, D_01B00AB8, s->s8A0, D_01B0EA3C, D_01B0EA10, 1);
        call_71c8(&D_01B00AE0, D_01B00AB8);
        D_01B00AE0.f6C = 0.5f;
        D_01B00AE0.f68 = 0.5f;
        D_01B00AE0.f64 = 0.5f;
        D_01B00AE0.f60 = 0.5f;
        D_01B00AE0.f38 = 0.5f;
        D_01B00AE0.f34 = 0.5f;
        D_01B00AE0.f30 = 0.5f;
        call_72f8(&D_01B00AE0, 0, 0.025f);
        call_be08(s->sD60, D_01B00A98, D_01B00870, s->s6A0, D_01B006B8, 0);
        call_bdd0(s->sD60, 0);
        func_01B02168(s->sDD0, s->s570);
        s->state = 10;
        goto top;
    case 10:
        s->timer = 25;
        s->state = 11;
    case 11:
        if (s->timer > 0) {
            break;
        }
        call_7e80(s->s670, D_01B00A98);
        {
            float f204 = 2.0400002f;
            void *p6A0 = s->s6A0;
            s->f690 = 1.0f;
            s->f694 = 1.0f;
            s->f698 = 1.0f;
            s->f69C = f204;
            __asm__("" : "+r"(p6A0) : "f"(f204) : "memory");
            { register void *p610 __asm__("$21") = s->s610; call_2a90(s->sA00, D_01B00A98, p610, s->s670, p6A0); }
        }
        call_c678_b(s->sC60, D_01B00AB8, s->sA00, D_01B0EA3C, D_01B0EA10, 0);
        func_001C5E90(D_01B006C0, D_01B006D0, 0);
        call_be08(s->sD98, D_01B00A98, D_01B00870, s->s610, D_01B006B8, 1);
        call_bdd0(s->sD98, 0);
        set_ae0(&D_01B00AE0, 0.0f, 0.1f, 1.0f);
        call_73d8(&D_01B00AE0, 0, 0.015f, 1.0f);
        s->state = 0x2710;
        goto top;
    case 0x2710:
        if (s->wDE8 == 0x4E20) {
            d0 = s->s30;
            func_01B03058(&d0);
            d1 = s->s30;
            func_01B02F88(&d1);
            d2 = s->s570;
            func_01B045D0(&d2);
            d3 = s->s570;
            func_01B044C8(&d3);
            d4 = task->p0;
            func_01B0D6D0(&d4);
        }
        break;
    }

    s->timer--;
    s->w1C++;
}
