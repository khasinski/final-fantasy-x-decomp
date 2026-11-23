#include "common.h"

typedef struct {
    u8 pad00[0xA8];
    s32 wA8;
    u8 padAC[0x4];
    s16 hB0;
} Struct6450;

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
    s32 w88;
    u8 pad8C[0xC];
    u8 b98;
    u8 b99;
} Struct6510;

typedef struct {
    u8 pad00[0x2C];
    void *p2C;
} Struct6638;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    float fD0;
    float fD4;
    float fD8;
    u8 padDC[0x28];
    void *p104;
    u8 pad108[0x8];
    void *p110;
} Struct6680;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} Task9463;

extern u8 D_01B00040[];
extern u8 D_01B004F0[];
extern u8 D_01B00508[];
extern u8 D_01B042F0[];
extern Struct6450 D_01B06450;
extern Struct6510 D_01B06510;
extern u8 D_01B065B0[];
extern s32 D_01B06630;
extern u8 *D_01B06634;
extern Struct6638 D_01B06638;
extern Struct6680 D_01B06680;
extern u8 *D_01B067B0;
extern u8 *D_01B067B4;
extern u8 D_01B0C420[];
extern u8 D_01B6A180[];

extern void *func_002B49A0(void *, s32, s32);
extern void func_01B00D28(void);
extern void func_01B00D58(void);
extern void func_01B00E20(void);
extern void func_01B01038(void);
extern float func_01B01308(s32);
extern void func_01B01430(s32, float *, s32);
extern float func_01B017A0(s32);
extern void func_01B025B0(s32, s32, float, float, float);
extern void func_01B02E18(s32, void *, void *);
extern void func_01B03260(s32);
extern void func_01B034D8(void *, void *, void *);
extern Task9463 *func_01B039F0(void (*)(void));
extern void func_01B03BB8(Task9463 *);
extern void func_01B03C78(void *, void *, void *, s32);
extern void func_01B03D50(void *, void *, s32, s32, float, s32, void *);
extern void func_01B04A80(float *, float *, float *);
extern void func_01B04B88(float *, float *, float *);
extern float func_01B04C28(float *, float *);
extern void func_01B05788(void *, s32, float *, float, float, float, s32);
extern void func_01B05AB0(void *, s32, s32);
extern void func_01B05C68(void *, float, float, s32, s32);
extern void func_01B05EA0(void *, s32);

s32 func_01B00980(void) {
    float vec0[4];
    float vec1[4];
    float vec2[4];
    float vec3[4];
    s32 n;
    s32 t;
    u8 *base;
    u8 *p;
    Struct6638 *s6638;
    Task9463 *task;

    base = D_01B6A180;
    D_01B067B0 = base;
    D_01B067B4 = base + 0x40000;
    D_01B06634 = base + 0x140000;
    s6638 = &D_01B06638;

    s6638->p2C = func_002B49A0(D_01B0C420, 8, 0);
    func_01B03C78(s6638, D_01B00040, D_01B067B0, 0x40000);

    func_01B01430(-1, vec0, 0);
    {
        float *pvec1 = vec1;
        func_01B01430(0, pvec1, 0);
        vec1[1] = vec0[1];
        func_01B04A80(vec2, vec0, pvec1);
        vec2[0] = 0.0f;
        vec3[0] = 0.0f;
        vec3[1] = 0.0f;
        vec3[2] = func_01B017A0(0);
        func_01B04B88(vec2, pvec1, vec3);

        n = (s32)(func_01B04C28(vec0, pvec1) / 3.0f);
        func_01B03D50(s6638, &D_01B06680, 0, n + 3, 0.07f, 2, D_01B042F0);
        func_01B01430(-1, &D_01B06680.fD0, 3);
        D_01B06680.fC4 = func_01B01308(-1);
        D_01B06680.fD4 -= 20.0f;
        D_01B06680.p104 = func_01B01038;

        p = base + 0x188000;
        func_01B034D8(p, D_01B0C420, D_01B004F0);
        D_01B06680.p110 = p;
        D_01B06680.fD0 = vec1[0];
        D_01B06680.fD8 = vec1[2];

        func_01B05788(&D_01B06450, -1, pvec1, 0.25f, 0.7f, 1.0f, n);
    }
    func_01B02E18(-1, &D_01B06450, D_01B00508);
    D_01B06450.hB0 = 1;
    D_01B06450.wA8 = 9;
    func_01B025B0(-1, n, 2.0f, 0.3f, 0.3f);

    {
        Struct6510 *s6510 = &D_01B06510;
        register u8 cff __asm__("$2") = 0xFF;
        register s32 dur __asm__("$6");
        register u8 c80 __asm__("$3");
        register u8 c48 __asm__("$7");
        register Struct6510 *a0 __asm__("$4");
        __asm__("" : "+r"(s6510), "+r"(cff));
        dur = n + 5;
        c80 = 0x80;
        c48 = 0x48;
        __asm__("" : "+r"(dur), "+r"(c80), "+r"(c48) : "r"(cff));
        *(volatile u8 *)&s6510->b80 = cff;
        a0 = s6510;
        *(volatile u8 *)&s6510->b83 = c80;
        *(volatile s32 *)&s6510->w88 = dur;
        *(volatile u8 *)&s6510->b98 = c48;
        *(volatile u8 *)&s6510->b82 = cff;
        *(volatile u8 *)&s6510->b81 = cff;
        *(volatile u8 *)&s6510->b87 = 0;
        *(volatile u8 *)&s6510->b86 = 0;
        *(volatile u8 *)&s6510->b85 = 0;
        *(volatile u8 *)&s6510->b84 = 0;
        __asm__("" : "+r"(s6510) : "m"(s6510->b84));
        s6510->b99 = 0;
        func_01B05AB0(a0, 0x14, dur);
        D_01B06630 = s6510->w88;
    }
    t = 16;
    if (6 >= n) {
        t = 9;
    }
    func_01B05C68(D_01B065B0, 1.0f, 0.5f, t, 0);
    func_01B05C68(D_01B065B0 + 0x40, 0.5f, 1.0f, 16, t + n - 1);
    func_01B03260(1);

    task = func_01B039F0(func_01B00D28);
    task->b18 = 1;
    func_01B03BB8(task);

    func_01B03BB8(func_01B039F0(func_01B00E20));
    func_01B05EA0(base + 0x180000, 0x100);

    task = func_01B039F0(func_01B00D58);
    task->b18 = 2;
    func_01B03BB8(task);

    return 0;
}
