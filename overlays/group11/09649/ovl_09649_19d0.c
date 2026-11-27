#include "common.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0x30];
    Vec4 v30;
    u8 pad40[0x106];
    u8 b146;
} Obj19D0;

typedef struct {
    u8 pad00[0x1480];
    Vec4 v1480;
    u8 pad1490[0x1CE8];
    float f3178;
} Work19D0;

extern Work19D0 *D_01B0B1F8;
extern void func_01B083F0(int);
extern Obj19D0 *func_01B08720(int);
extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);

void func_01B019D0(void)
{
    Work19D0 *w = D_01B0B1F8;
    Obj19D0 *o;
    func_01B083F0(0);
    o = func_01B08720(0);
    o->b146 = 1;
    func_002DD128(o);
    func_002DD318(o, o, w->f3178);
    copy_vec(&o->v30, &w->v1480);
}
