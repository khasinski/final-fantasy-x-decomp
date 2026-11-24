#include "common.h"

static __inline__ void copy_vec4_a3(void *dst, void *src)
{
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0x30];
    float v30[4];
    u8 pad40[0x106];
    u8 f146;
} Obj1358;

typedef struct {
    u8 pad00[0x920];
    float v920[4];
    u8 pad930[0x418];
    float fD48;
} Work1358;

extern Work1358 *D_01B09148;

extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);
extern void func_01B06430(int);
extern Obj1358 *func_01B06760(int);

void func_01B01358(void)
{
    Work1358 *w = D_01B09148;
    Obj1358 *o;

    func_01B06430(0);
    o = func_01B06760(0);
    o->f146 = 1;
    func_002DD128(o);
    func_002DD318(o, o, w->fD48);
    copy_vec4_a3(o->v30, w->v920);
}
