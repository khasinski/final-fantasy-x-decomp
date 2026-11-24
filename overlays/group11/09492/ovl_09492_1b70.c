#include "common.h"

#define COPY_VEC4(dst, src) do { \
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory"); \
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory"); \
} while (0)

static __inline__ void copy_vec4_a3(void *dst, void *src)
{
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0x730];
    float v730[4];
    float v740[4];
    float v750[4];
    float v760[4];
    float v770[4];
    u8 pad780[0x20];
    float v7A0[4];
    float v7B0[4];
    float v7C0[4];
    u8 pad7D0[0x184];
    int f954;
    int f958;
    int f95C;
    int f960;
    int f964;
    u8 pad968[0x10];
    int f978;
} Sub1B70;

extern u8 D_01B09078[];
extern u8 D_01B00590[];

extern void func_01B02A30(int, void *, int);
extern void func_01B01610(Sub1B70 *);
extern void func_01B04418(int, void *, void *);
extern float func_01B06228(void *, void *);

void func_01B01B70(Sub1B70 *s)
{
    float tmp[4];
    int frames;

    if (s->f954 == 0) {
        func_01B02A30(-1, s->v7A0, 0);
        func_01B01610(s);
        {
            register void *d __asm__("$3") = s->v740;
            register void *src __asm__("$2") = s->v730;
            int six;
            int one;
            __asm__("" : "+r"(d));
            copy_vec4_a3(d, src);
            six = 6;
            __asm__("" : : "r"(src));
            one = 1;
            __asm__("" : : "r"(d));
            s->f964 = six;
            s->f978 = one;
            func_01B04418(-1, D_01B09078, D_01B00590);
        }
    }
    func_01B02A30(-1, tmp, 0);
    {
        float dist = func_01B06228(tmp, s->v750);
        register void *p770 __asm__("$6") = s->v770;
        register void *p760 __asm__("$5") = s->v760;
        __asm__("" : "+r"(p770), "+r"(p760));
        frames = (int)(dist / 3.5f);
        if (frames > 300) {
            frames = 300;
        }
        frames++;
        s->f960 = frames;
        s->f95C = frames;
        copy_vec4_a3(p770, p760);
        {
            register void *d __asm__("$2") = s->v7B0;
            __asm__("" : "+r"(d));
            copy_vec4_a3(d, tmp);
        }
        {
            register void *d __asm__("$3") = s->v7C0;
            __asm__("" : "+r"(d));
            copy_vec4_a3(d, p770);
        }
        COPY_VEC4(s->v7A0, s->v750);
    }
}
