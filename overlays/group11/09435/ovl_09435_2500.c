#include "common.h"

static __inline__ void copy_vec4_a3(void *dst, void *src)
{
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0x720];
    float v720[4];
    float v730[4];
    u8 pad740[0x60];
    float v7A0[4];
    float v7B0[4];
    float v7C0[4];
    u8 pad7D0[0x190];
    int f960;
    int f964;
} Sub2500;

extern u8 D_01B006C0[];
extern u8 D_01B006D0[];
extern u8 D_01B09228[];

extern void func_01B01790(Sub2500 *);
extern void func_01B02BD8(int, void *, int);
extern void func_01B045C0(int, void *, void *);
extern float func_01B06500(float, float);

void func_01B02500(Sub2500 *s)
{
    float ang;
    void *tbl;

    func_01B01790(s);
    ang = func_01B06500(s->v720[1], s->v730[1]);
    if (s->v720[1] <= ang) {
        tbl = D_01B006C0;
    } else {
        tbl = D_01B006D0;
    }
    func_01B045C0(-1, D_01B09228, tbl);
    func_01B02BD8(-1, s->v7B0, 0);
    {
        register void *d __asm__("$4") = s->v7C0;
        void *src = s->v7A0;
        __asm__("" : "+r"(d));
        copy_vec4_a3(d, src);
    }
    {
        register int v __asm__("$3") = 0x1A;
        __asm__("" : "+r"(v));
        s->f964 = v;
        s->f960 = v;
    }
}
