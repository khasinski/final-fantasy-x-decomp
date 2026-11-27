#include "common.h"

typedef struct {
    float f[4];
} Vec4Q;

typedef struct {
    u8 pad00[0xC0];
    float fC0;
    float fC4;
    u8 padC8[0x08];
    Vec4Q vecD0;
    u8 padE0[0x08];
    float fE8;
    u8 padEC[0x44];
} Item130;

typedef struct {
    Item130 items[8];
    u8 pad980[0x70];
    Vec4Q vec9F0;
    u8 padA00[0x5878];
    float f6278;
} OvlState;

extern u8 D_01B0BC30[];
extern OvlState *D_01B0BD58;

extern void func_01B07648(void *, void *, int, int, int, int, float);

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

void func_01B036E8(void)
{
    Item130 *it = &D_01B0BD58->items[4];
    OvlState *s = D_01B0BD58;

    func_01B07648(D_01B0BC30, it, 4, 0, 0, 0, 0.12f);
    copy_vec(&s->items[4].vecD0, &s->vec9F0);
    it->fC4 = s->f6278;
    it->fE8 = 95.0f;
    it->vecD0.f[1] -= 1.0f;
}
