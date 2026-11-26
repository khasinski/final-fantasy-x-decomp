#include "common.h"

typedef struct Slot9397_D {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    float fD0;
    float fD4;
    float fD8;
    float fDC;
    u8 padE0[0x24];
    void (*p104)(struct Slot9397_D *);
    u8 pad108[0x18];
    int w120;
    u8 pad124[0xD1C];
} Slot9397_D;

typedef struct {
    u8 pad00[0x80];
    u8 b80;
    u8 b81;
    u8 b82;
    u8 b83;
    u8 b84;
    u8 b85;
    u8 b86;
    u8 b87;
    int w88;
    u8 pad8C[0xC];
    u8 b98;
    u8 b99;
    u8 pad9A[0x6];
} SubE60_9397_D;

typedef struct {
    u8 pad00[0x4];
    float f04;
    float f08;
    int w0C;
    float f10;
    float f14;
    int w18;
    u8 pad1C[0x10];
    u16 h2C;
    u8 pad2E[0x2];
} Sub10E0_9397_D;

typedef struct {
    float f00;
    u8 pad04[0x3C];
} Sub1150_9397_D;

typedef struct {
    u8 pad000[0x1C0];
    u8 sub1C0[0x10];
    u8 sub1D0[0x10];
    u8 sub1E0[0x40];
    u8 sub220[0x10];
    u8 sub230[0x10];
    u8 sub240[0x10];
    u8 sub250[0x20];
} Sub1190_9397_D;

typedef struct {
    u_long128 q00;
    u8 pad10[0x10];
    float f20;
    float f24;
    int w28;
    int w2C;
    int w30;
    u8 pad34[0xC];
} Sub1400_9397_D;

typedef struct {
    Slot9397_D slot0;
    int wE40;
    float fE44;
    int wE48;
    int wE4C;
    u_long128 qE50;
    SubE60_9397_D subE60[4];
    Sub10E0_9397_D sub10E0;
    u8 pad1110[0x40];
    Sub1150_9397_D sub1150;
    Sub1190_9397_D sub1190;
    Sub1400_9397_D sub1400[1];
    void *p1440;
} Obj9397_D;

extern u8 D_01B09D38[];
extern Obj9397_D *D_01B09E00;
extern u8 *D_01B09E04;
extern void func_01B02D48(Slot9397_D *);

extern void func_01B05FF0(void *, void *, int, int, int, void *, float);
extern void func_01B08FF0(void *, int);
extern void func_01B09160(void *, int);
extern float func_002B3DF8(float);
extern int func_002EFD78(void);
extern float func_01B06AD8(float, float, float, float);
extern void func_01B03C20(int, void *);
extern void func_01B04F20(int, void *);
extern void func_01B04F80(void *);
extern int func_01B03518(int);
extern void func_0010D380(int, int, int);
extern int func_0010D3A8(int, int, int);
extern void func_01B01848(int, void *, void *, void *, void *, void *, int);
extern void func_01B05D10(void *);
extern void *func_01B05C90(void *);
extern void func_01B05E58(void *);
extern void func_01B09988(void *, int, void *, int);
extern void func_01B099B8(void *, int, void *, int);
extern void func_01B09440(void *, int, int, float, float);
extern void func_01B06460(void *, void *);

static __inline__ void copy_vec(void *dst, const void *src)
{
    register u_long128 *dp __asm__("$3") = (u_long128 *)dst;
    register const u_long128 *sp __asm__("$2") = (const u_long128 *)src;
    register u_long128 t __asm__("$7");
    __asm__ volatile("" : "+r"(dp), "+r"(sp) : : "memory");
    t = *(const volatile u_long128 *)sp;
    *(volatile u_long128 *)dp = t;
    __asm__ volatile("" : : : "memory");
}

void func_01B02D90(Slot9397_D *a0)
{
    a0->w120 = 60;
    a0->p104 = func_01B02D48;
}

void func_01B02DA8(void)
{
    Obj9397_D *s0 = D_01B09E00;
    SubE60_9397_D *v0;

    func_01B05FF0(D_01B09D38, &s0->slot0, 0, 0, 500, func_01B02D90, 0.3f);
    copy_vec(&s0->slot0.fD0, &s0->qE50);
    s0->slot0.fD4 -= 20.0f;
    s0->slot0.fC4 = s0->fE44;
    v0 = &s0->subE60[0];
    v0->w88 = 0;
    v0->b82 = 0xFF;
    v0->b81 = 0xFF;
    v0->b80 = 0xFF;
    v0->b83 = 0x80;
    v0->b87 = 0;
    v0->b86 = 0;
    v0->b85 = 0;
    v0->b84 = 0;
    v0->b98 = 0x48;
    v0->b99 = 0;
    func_01B08FF0(v0, 60);
}

void func_01B02E70(void)
{
    Sub10E0_9397_D *s0 = &D_01B09E00->sub10E0;

    func_01B09160(s0, 85);
    s0->h2C |= 3;
    s0->f04 = 0.2f;
    s0->f08 = 0.1f;
    s0->f10 = 5.0f;
    s0->f14 = 3.0f;
    s0->w18 = 0;
    s0->w0C = 0;
}

int func_01B02EF0(void)
{
    Obj9397_D *v1 = D_01B09E00;
    Sub1400_9397_D *s0 = v1->sub1400;
    int a0 = 1;
    int i;

    for (i = 0; i < 1; i++, s0++) {
        if (s0->w30 == 0) {
            s0->w28--;
            if (s0->w28 == 0) {
                int r;
                s0->f24 = func_002B3DF8(20.0f) + 20.0f;
                r = (func_002EFD78() % 21) + 20;
                s0->w30 = 1;
                s0->w2C = r;
                s0->w28 = r;
            }
            s0->f20 = func_01B06AD8(0.0f, s0->f24, 0.0f, (float)s0->w28 / (float)s0->w2C);
            a0 = 0;
        } else {
            s0->f20 += 0.35f;
            if (s0->f20 > 190.0f) {
                s0->f20 = 190.0f;
            } else {
                a0 = 0;
            }
        }
    }
    return a0;
}

void func_01B03030(void *a0)
{
    float m0[4][4];
    float m1[4][4];
    float m2[4][4];
    Obj9397_D *s4 = D_01B09E00;
    int s3;
    int s0;

    s3 = func_01B02EF0();
    func_01B03C20(-1, m0);
    func_01B04F20(-1, m1);
    func_01B04F80(m2);
    s0 = func_01B03518(-1);
    func_0010D380(s0, -1, 0x3C00);
    func_0010D3A8(s0, -1, 0x2EE0);
    func_01B01848(s0, D_01B09E04, m0, m1, m2, s4->sub1400, 1);
    func_0010D380(s0, -1, -1);
    func_0010D3A8(s0, -1, -1);
    if (s3 == 1) {
        func_01B05D10(a0);
        s4->p1440 = 0;
    }
}

void func_01B03138(void)
{
    float v[4];
    Obj9397_D *s0;
    Sub1400_9397_D *p;
    register const u_long128 *vp __asm__("$4");
    register int one __asm__("$5");
    int i;

    float f3;

    vp = (const u_long128 *)v;
    __asm__("" : "+r"(vp));
    v[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = -90000.0f;
    one = 1;
    __asm__("" : "+r"(one));
    s0 = D_01B09E00;
    p = s0->sub1400;
    i = 0;
    __asm__("" : "+r"(i));
    v[3] = 1.0f;
    do {
        register u_long128 t __asm__("$7") = *(const volatile u_long128 *)vp;
        *(volatile u_long128 *)&p->q00 = t;
        __asm__ volatile("" : : : "memory");
        p->w28 = one;
        p->f20 = 0.0f;
        p->w30 = 0;
        p++;
        __asm__("" : "+r"(p));
        i--;
    } while (i >= 0);
    s0->p1440 = func_01B05C90(func_01B03030);
    func_01B05E58(s0->p1440);
}

void func_01B031D0(void)
{
    Obj9397_D *s1 = D_01B09E00;
    Sub1190_9397_D *s0 = &s1->sub1190;

    func_01B09988(s0, 0, s0->sub1C0, 30);
    func_01B09988(s0, 1, s0->sub1D0, 30);
    func_01B09988(s0, 2, s0->sub1E0, 30);
    func_01B099B8(s0, 0, s0->sub220, 30);
    func_01B099B8(s0, 1, s0->sub230, 30);
    func_01B099B8(s0, 2, s0->sub240, 30);
    func_01B099B8(s0, 3, s0->sub250, 30);
    func_01B09440(&s1->sub1150, 30, 0, 0.5f, 1.0f);
    s1->sub1150.f00 = 0.65f;
}

void func_01B032C0(void)
{
    Obj9397_D *s0 = D_01B09E00;

    func_01B06460(D_01B09D38, &s0->slot0);
    if (s0->p1440 != 0) {
        func_01B05D10(s0->p1440);
        s0->p1440 = 0;
    }
}
