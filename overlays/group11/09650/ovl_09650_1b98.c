#include "common.h"

static inline void copy_vec(void *src, void *dst)
{
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0x9B0];
    float vec9B0[4];
    u8 pad9C0[0x10];
    float vec9D0[4];
    u8 pad9E0[0x58AC];
    int w628C;
} OvlState;

extern void *D_01B00B74;
extern int D_01B0A348;
extern u8 D_01B0A350[];
extern void *D_01B0A394;
extern u8 D_01B0A398[];
extern u8 D_01B0A3F8[];
extern u8 D_01B0A458[];
extern OvlState *D_01B0A478;
extern void *D_01B0A480;

extern void func_001CDDD8(int);
extern void func_01B01E38(void);
extern void func_01B05380(void *);
extern void func_01B05F20(void *);
extern int func_01B062E0(void *, void *);
extern void func_01B07588(void);
extern void func_01B07DB0(void);
extern int func_01B097B0(void *);

void func_01B01B98(void *a0)
{
    OvlState *s = D_01B0A478;
    int r;

    func_01B07588();
    D_01B00B74 = D_01B0A480;
    r = func_01B097B0(D_01B0A398);
    func_01B097B0(D_01B0A3F8);
    if (r == 0) {
        {
            register void *src __asm__("$2") = s->vec9D0;
            register void *dst __asm__("$3");
            __asm__("" : "+r"(src));
            dst = s->vec9B0;
            __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
            __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
        }
        func_01B05380(D_01B0A458);
        func_01B07DB0();
    } else {
        s->w628C = 1;
        func_01B01E38();
        func_01B05F20(a0);
    }
}

void func_01B01C48(void)
{
    OvlState *s = D_01B0A478;

    if (func_01B062E0(D_01B0A350, D_01B0A394) == 1 && s->w628C == 1) {
        func_001CDDD8(D_01B0A348);
    }
}
