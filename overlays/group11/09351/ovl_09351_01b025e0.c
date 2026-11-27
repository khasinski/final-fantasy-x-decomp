#include "common.h"

typedef union {
    u_long128 q;
    float f[4];
} Vec4Q;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    Vec4Q vecD0;
} ObjDF50;

typedef struct {
    u8 pad00[0xC14];
    float fC14;
    u8 padC18[0x18];
    Vec4Q vecC30;
    u8 padC40[0x60];
    int wCA0;
    float fCA4;
    int wCA8;
    int wCAC;
    int wCB0;
    float fCB4;
    int wCB8;
    int wCBC;
    u8 padCC0[0x18E0];
    u8 sub25A0[0x40];
    u8 pad25E0[0x358];
    float f2938;
} State9351;

extern u8 D_01B0D6B8[];
extern ObjDF50 D_01B0DF50;
extern State9351 *D_01B0E828;

extern void func_00118098(int, int);
extern void func_01B08B18(void *, void *, int, int, int, int, float);
extern void func_01B0A690(void);
extern void func_01B0CA38(void *, int, int, float, float);

static inline void copy_vec(void *dst, void *src)
{
    register u_long128 *d __asm__("$3") = (u_long128 *)dst;
    register u_long128 *s __asm__("$2") = (u_long128 *)src;
    register u_long128 v __asm__("$7");
    __asm__ volatile("" : "+r"(d), "+r"(s));
    v = *s;
    *d = v;
    __asm__ volatile("" : : "m"(*d));
}

void func_01B025E0(void)
{
    func_01B0A690();
}

void func_01B025E8(void)
{
    func_00118098(0, 0x10000);
    func_00118098(1, 0x20000);
    func_01B0CA38(D_01B0E828->sub25A0, 30, 0, 1.0f, 0.5f);
}

void func_01B02638(void)
{
    State9351 *s = D_01B0E828;

    s->wCA0 = 0;
    s->fCA4 = -6.0f;
    s->wCA8 = 0;
    s->wCAC = 0;
    s->wCB0 = 0;
    s->fCB4 = 0.1f;
    s->wCB8 = 0;
    s->wCBC = 0;
}

void func_01B02678(void)
{
    State9351 *s = D_01B0E828;

    s->fCA4 += s->fCB4;
    s->fC14 += s->fCA4;
}

void func_01B026A0(void)
{
    State9351 *s = D_01B0E828;

    s->fCA4 = -2.0f;
    s->fCB4 = 0.066666603f;
    s->wCA0 = 0;
    s->fC14 = s->vecC30.f[1] - 60.0f;
    s->wCA8 = 0;
    s->wCAC = 0;
    s->wCB0 = 0;
    s->wCB8 = 0;
    __asm__ volatile("" : : "m"(s->wCB8));
    s->wCBC = 0;
}

void func_01B026F8(void)
{
    State9351 *s = D_01B0E828;
    ObjDF50 *o = &D_01B0DF50;

    func_01B08B18(D_01B0D6B8, o, 7, 0, 0, 0, 0.12f);
    copy_vec(&o->vecD0, &s->vecC30);
    o->fC4 = s->f2938;
    o->vecD0.f[1] -= 1.0f;
}
