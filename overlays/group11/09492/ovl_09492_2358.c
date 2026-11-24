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
    u8 pad7D0[0x18C];
    int f95C;
    int f960;
} Sub2358;

extern u8 g_data_620[];
extern u8 g_data_630[];
extern u8 g_state_9078[];

extern void func_ovl_1610(Sub2358 *);
extern void func_ovl_2a30(int, void *, int);
extern void func_ovl_4418(int, void *, void *);
extern float func_ovl_6358(float, float);

void func_01B02358(Sub2358 *s)
{
    float ang;
    void *tbl;

    func_ovl_1610(s);
    ang = func_ovl_6358(s->v720[1], s->v730[1]);
    if (s->v720[1] <= ang) {
        tbl = g_data_620;
    } else {
        tbl = g_data_630;
    }
    func_ovl_4418(-1, g_state_9078, tbl);
    func_ovl_2a30(-1, s->v7B0, 0);
    {
        register void *d __asm__("$4") = s->v7C0;
        void *src = s->v7A0;
        __asm__("" : "+r"(d));
        copy_vec4_a3(d, src);
    }
    {
        register int v __asm__("$3") = 0x1A;
        __asm__("" : "+r"(v));
        s->f960 = v;
        s->f95C = v;
    }
}
