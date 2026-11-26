#include "common.h"

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
} SubE60_9397;

typedef struct {
    u8 pad00[0x10];
    float f10;
    u8 pad14[0x2C];
} Sub1110_9397;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    u_long128 qD0;
    float fE0;
    float fE4;
    float fE8;
} Spawn9397;

typedef struct {
    u8 pad00[0x2C];
    int w2C;
} TaskArg9397;

typedef struct {
    u8 pad0000[0xE44];
    float fE44;
    u8 pad0E48[0x8];
    u_long128 qE50;
    SubE60_9397 subE60[4];
    u8 pad10E0[0x30];
    Sub1110_9397 sub1110;
    u8 pad1150[0x40];
    u8 sub1190[0x2B8];
    float f1448;
    int w144C;
    int w1450;
    int w1454;
    int w1458;
} Obj9397_B;

extern int D_01B006F8[];
extern int D_01B00708[];
extern u8 D_01B09D38[];
extern Obj9397_B *D_01B09E00;
extern void func_01B02788(void);

extern void func_01B08FF0(void *, int);
extern void func_01B09440(void *, int, int, float, float);
extern void func_01B099B8(void *, int, float *, int);
extern void func_01B09988(void *, int, float *, int);
extern void *func_01B05C90(void *);
extern void func_01B05E58(void *);
extern int func_002EFD78(void);
extern Spawn9397 *func_01B096C8(void);
extern void func_01B05FF0(void *, void *, int, int, int, int, float);
extern float func_002B3DB0(float);

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

void func_01B02920(void)
{
    float v3[4];
    float v2[2];
    Obj9397_B *v1 = D_01B09E00;
    SubE60_9397 *s0 = v1->subE60;
    Sub1110_9397 *s6 = &v1->sub1110;
    u8 *s5 = v1->sub1190;
    int i;

    for (i = 0; i < 4; i++, s0++) {
        s0->b82 = 0xFF;
        s0->b81 = 0xFF;
        s0->b80 = 0xFF;
        s0->b83 = 0x80;
        s0->b87 = 0;
        s0->b86 = 0;
        s0->b85 = 0;
        s0->b84 = 0;
        s0->w88 = D_01B006F8[i];
        s0->b98 = 0x48;
        s0->b99 = 0;
        func_01B08FF0(s0, D_01B00708[i]);
    }

    func_01B09440(s6, 30, 0, 1.0f, 0.5f);
    s6->f10 = 0.65f;

    v3[0] = 0.0f;
    v3[1] = 0.0f;
    v3[2] = 0.0f;
    func_01B099B8(s5, 0, v3, 1);
    func_01B099B8(s5, 1, v3, 1);
    func_01B099B8(s5, 3, v3, 1);

    v3[0] = 1.0f;
    v3[1] = 0.8196078539f;
    v3[2] = 0.6823529601f;
    func_01B099B8(s5, 2, v3, 1);

    v2[0] = -1.500983119f;
    v2[1] = 0.0f;
    func_01B09988(s5, 2, v2, 1);
}

void func_01B02AF0(void)
{
    Obj9397_B *v0 = D_01B09E00;

    v0->w144C = 120;
    v0->w1454 = 185;
    v0->w1458 = 185;
    v0->w1450 = 120;
    v0->f1448 = 0.0f;
    func_01B05E58(func_01B05C90(func_01B02788));
}

void func_01B02B38(TaskArg9397 *a0)
{
    Obj9397_B *s1 = D_01B09E00;
    Spawn9397 *s0;

    a0->w2C--;
    if (a0->w2C > 0) {
        return;
    }

    a0->w2C = (func_002EFD78() % 11) + 10;
    s0 = func_01B096C8();
    if (s0 != 0) {
        func_01B05FF0(D_01B09D38, s0, 1, 0, 0, 0, 0.2f);
        copy_vec(&s0->qD0, &s1->qE50);
        s0->fC4 = s1->fE44;
        s0->fE0 = func_002B3DB0(30.0f);
        s0->fE4 = func_002B3DB0(10.0f) + -30.0f;
        s0->fE8 = func_002B3DB0(30.0f);
    }
}
