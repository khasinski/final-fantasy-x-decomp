#include "common.h"

typedef union {
    u_long128 q;
    float f[4];
} Vec4Q;

typedef struct {
    u8 pad00[0x30];
    Vec4Q vec30;
    u8 pad40[0x106];
    u8 b146;
} ObjA880;

typedef struct {
    int w00;
    int w04;
    u8 b08;
    u8 b09;
    u8 b0A;
    u8 pad0B;
    u16 h0C;
    u16 h0E;
    int w10;
    int w14;
    u8 b18;
    u8 b19;
    u8 b1A;
    u8 b1B;
    u8 b1C;
    u8 b1D;
    u8 b1E;
    u8 b1F;
    void *p20;
    u8 pad24[0x10];
    void *p34;
    int w38;
    int w3C;
    u16 h40;
    u16 h42;
    int w44;
    int w48;
} Sub28C0;

typedef struct {
    u8 pad00[0xC30];
    Vec4Q vecC30;
    u8 padC40[0x1C80];
    Sub28C0 sub28C0;
    u8 pad290C[0x2C];
    float f2938;
} State9351;

extern State9351 *D_01B0E828;
extern void *D_01B0E830;

extern int func_001038F8(void);
extern void *func_002B7B20(void *, void *);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);
extern void func_01B078C8(void *, void *);
extern void func_01B0A550(int);
extern ObjA880 *func_01B0A880(int);

void func_01B022D0(void)
{
    State9351 *s = D_01B0E828;
    ObjA880 *obj;

    func_01B0A550(0);
    obj = func_01B0A880(0);
    obj->b146 = 1;
    func_002DD128(obj);
    func_002DD318(obj, obj, s->f2938);
    {
        u_long128 *d = &obj->vec30.q;
        u_long128 *src = &s->vecC30.q;
        register u_long128 v __asm__("$7");
        __asm__ volatile("" : "+r"(d), "+r"(src));
        v = *src;
        *d = v;
        __asm__ volatile("" : : "m"(*d));
    }
}

void func_01B02340(void)
{
    Sub28C0 *sub = &D_01B0E828->sub28C0;

    sub->w00 = 524;
    sub->w04 = func_001038F8();
    sub->b08 = 0;
    sub->b09 = 128;
    sub->b0A = 0;
    sub->h0C = 0;
    sub->h0E = 0;
    sub->w10 = 0;
    sub->w14 = 0;
    sub->b18 = 76;
    sub->b19 = 76;
    sub->b1A = 76;
    sub->b1B = 128;
    sub->b1C = 0;
    sub->b1D = 0;
    sub->b1E = 0;
    sub->b1F = 0;
    sub->p20 = 0;
    sub->p34 = 0;
    sub->w38 = 0;
    sub->w3C = 0;
    sub->h40 = 0;
    sub->h42 = 0;
    sub->w44 = 0;
    sub->w48 = 0;
}

void func_01B023E0(void *a0, void *a1)
{
    float m0[4][4];
    float m1[4][4];
    float m2[4][4];
    Sub28C0 *sub;

    func_01B078C8(m1, m2);
    func_002DCE38(m0, m2, a1);
    func_002DCE38(m0, m1, m0);
    sub = &D_01B0E828->sub28C0;
    sub->p34 = D_01B0E830;
    sub->p20 = m0;
    sub->w44 = 0;
    D_01B0E830 = func_002B7B20(a0, sub);
}
