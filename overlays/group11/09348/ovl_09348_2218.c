#include "common.h"

static inline void copy_vec(void *src, void *dst)
{
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0x1540];
    float vec1540[4];
    u8 pad1550[0x2F0];
    float f1840;
} OvlState;

extern OvlState *D_01B0AB88;

extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);
extern void func_01B07CE8(int);
extern u8 *func_01B08018(int);

void func_01B02218(void)
{
    OvlState *s = D_01B0AB88;
    u8 *p;

    func_01B07CE8(0);
    p = func_01B08018(0);
    p[0x146] = 1;
    func_002DD128(p);
    func_002DD318(p, p, s->f1840);
    copy_vec(s->vec1540, p + 0x30);
}
