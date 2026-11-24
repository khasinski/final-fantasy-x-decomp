#include "common.h"

static __inline__ void copy_vec4_a3(void *dst, void *src)
{
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0x880];
    float v880[4];
    u8 pad890[0x30];
    float v8C0[4];
    u8 pad8D0[0x30];
    float v900[4];
    u8 pad910[0x10];
    float v920[4];
    u8 pad930[0x10];
    float v940[4];
    u8 pad950[0x10];
    float v960[4];
    u8 pad970[0x3FC];
    int fD6C;
} Work1058;

extern void *D_01B00BC4;
extern u8 D_01B09028[];
extern u8 D_01B09088[];
extern u8 D_01B090E8[];
extern u8 D_01B09108[];
extern u8 D_01B09128[];
extern Work1058 *D_01B09148;
extern void *D_01B0914C;

extern void func_01B03B78(void *);
extern void func_01B04718(void *);
extern void func_01B05D80(void);
extern void func_01B065A8(void);
extern int func_01B07FA8(void *);

void func_01B01058(void *a0)
{
    Work1058 *w = D_01B09148;
    int r;

    func_01B05D80();
    D_01B00BC4 = D_01B0914C;
    r = func_01B07FA8(D_01B09028);
    func_01B07FA8(D_01B09088);
    if (r == 0) {
        copy_vec4_a3(w->v880, w->v920);
        copy_vec4_a3(w->v8C0, w->v940);
        {
            register void *src __asm__("$3") = w->v960;
            register void *dst __asm__("$2");
            __asm__("" : "+r"(src));
            dst = w->v900;
            __asm__("" : "+r"(dst) : "r"(src));
            __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
            __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
        }
        func_01B03B78(D_01B090E8);
        func_01B03B78(D_01B09108);
        func_01B03B78(D_01B09128);
        func_01B065A8();
    } else {
        w->fD6C = 1;
        func_01B04718(a0);
    }
}
