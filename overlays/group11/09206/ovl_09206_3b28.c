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
} Obj3B28;

typedef struct {
    u8 pad00[0x960];
    Vec4 v960;
    u8 pad970[0x7C98];
    float f8608;
} Work3B28;

extern Work3B28 *D_01B0C888;
extern void func_01B098B8(int);
extern Obj3B28 *func_01B09BE8(int);
extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);

void func_01B03B28(void)
{
    Work3B28 *w = D_01B0C888;
    Obj3B28 *o;
    func_01B098B8(0);
    o = func_01B09BE8(0);
    o->b146 = 1;
    func_002DD128(o);
    func_002DD318(o, o, w->f8608);
    copy_vec(&o->v30, &w->v960);
}
