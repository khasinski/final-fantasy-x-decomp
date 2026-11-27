#include "common.h"

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} OvlTask;

typedef struct {
    u8 pad000[0xCD0];
    u_long128 vCD0;
    u8 padCE0[0x1E0];
    OvlTask *pEC0;
    u8 padEC4[0x4];
    float fEC8;
    u8 padECC[0x8];
    s32 wED4;
} WorkA480;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    u_long128 vD0;
} EffObj;

extern WorkA480 *D_01B0A480;
extern u8 D_01B0A2F8[];

extern EffObj *func_01B0A260(void);
extern void func_01B060D0(void *, EffObj *, int, int, int, int, float);
extern OvlTask *func_01B05D70(void *);
extern void func_01B05DF0(void *);
extern void func_01B05F38(OvlTask *);

static __inline__ void copy_q(void *dst, void *src)
{
    register void *d __asm__("$3") = dst;
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(d) : "memory");
}

void func_01B02F08(void)
{
    WorkA480 *w = D_01B0A480;
    EffObj *e;

    if (--w->wED4 > 0) {
        return;
    }
    w->wED4 = 100;

    e = func_01B0A260();
    if (e != 0) {
        func_01B060D0(D_01B0A2F8, e, 1, 0, 0, 0, 0.01f);
        copy_q(&e->vD0, &w->vCD0);
        e->fC4 = w->fEC8;

        e = func_01B0A260();
        if (e != 0) {
            func_01B060D0(D_01B0A2F8, e, 0, 0, 0, 0, 0.02f);
            copy_q(&e->vD0, &w->vCD0);
            e->fC4 = w->fEC8;
        }
    }
}

void func_01B02FF8(void)
{
    WorkA480 *s2 = D_01B0A480;
    OvlTask *s0;

    s2->wED4 = 1;
    s0 = func_01B05D70((void *)func_01B02F08);
    s0->b18 = 1;
    func_01B05F38(s0);
    s2->pEC0 = s0;
}

void func_01B03058(void)
{
    WorkA480 *s0 = D_01B0A480;

    if (s0->pEC0 != 0) {
        func_01B05DF0(s0->pEC0);
        s0->pEC0 = 0;
    }
}
