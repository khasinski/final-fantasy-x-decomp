#include "common.h"

static inline void copy_vec(void *src, void *dst)
{
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

static inline void copy_vec_a0(void *src, void *dst)
{
    register void *s __asm__("$4") = src;
    __asm__ volatile("lq $7, 0(%0)" : : "r"(s) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0xB00];
    float vecB00[4];
    u8 padB10[0x30];
    float vecB40[4];
    u8 padB50[0x90];
    float vecBE0[4];
    u8 padBF0[0x10];
    float vecC00[4];
    u8 padC10[0x20C];
    int wE1C;
} OvlState;

extern void *D_01B00D74;
extern int D_01B09550;
extern u8 D_01B09558[];
extern void *D_01B0959C;
extern u8 D_01B095A0[];
extern u8 D_01B09600[];
extern u8 D_01B09660[];
extern u8 D_01B09680[];
extern OvlState *D_01B096A0;
extern void *D_01B096A4;

extern void func_001CDDD8(int);
extern void func_01B01CC0(void);
extern void func_01B044B0(void *);
extern void func_01B05050(void *);
extern int func_01B05410(void *, void *);
extern void func_01B066B8(void);
extern void func_01B06EE0(void);
extern int func_01B088E0(void *);

void func_01B01A20(void *a0)
{
    OvlState *s = D_01B096A0;
    int r;

    func_01B066B8();
    D_01B00D74 = D_01B096A4;
    r = func_01B088E0(D_01B095A0);
    func_01B088E0(D_01B09600);
    if (r == 0) {
        copy_vec(s->vecBE0, s->vecB00);
        {
            register void *src __asm__("$4") = s->vecC00;
            register void *dst __asm__("$2");
            __asm__("" : "+r"(src));
            dst = s->vecB40;
            __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
            __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
        }
        func_01B044B0(D_01B09660);
        func_01B044B0(D_01B09680);
        func_01B06EE0();
    } else {
        s->wE1C = 1;
        func_01B01CC0();
        func_01B05050(a0);
    }
}

void func_01B01AF0(void)
{
    OvlState *s = D_01B096A0;

    if (func_01B05410(D_01B09558, D_01B0959C) == 1 && s->wE1C == 1) {
        func_001CDDD8(D_01B09550);
    }
}
