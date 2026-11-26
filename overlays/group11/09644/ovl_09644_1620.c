#include "common.h"

typedef struct {
    u8 pad000[0xCD0];
    u_long128 vCD0;
    u8 padCE0[0x1E8];
    float fEC8;
    u8 padECC[0x8];
    s32 wED4;
} Work8A90;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    u_long128 vD0;
} EffObj;

extern Work8A90 *D_01B08A90;
extern u8 D_01B08948[];

extern EffObj *func_01B088B0(void);
extern void func_01B04720(void *, EffObj *, int, int, int, int, float);

static __inline__ void copy_q(void *dst, void *src)
{
    register void *d __asm__("$3") = dst;
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(d) : "memory");
}

void func_01B01620(void)
{
    Work8A90 *w = D_01B08A90;
    EffObj *e;

    if (--w->wED4 > 0) {
        return;
    }
    w->wED4 = 100;

    e = func_01B088B0();
    if (e != 0) {
        func_01B04720(D_01B08948, e, 1, 0, 0, 0, 0.01f);
        copy_q(&e->vD0, &w->vCD0);
        e->fC4 = w->fEC8;

        e = func_01B088B0();
        if (e != 0) {
            func_01B04720(D_01B08948, e, 0, 0, 0, 0, 0.02f);
            copy_q(&e->vD0, &w->vCD0);
            e->fC4 = w->fEC8;
        }
    }
}
