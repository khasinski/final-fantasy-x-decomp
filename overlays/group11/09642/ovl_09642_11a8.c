#include "common.h"

static __inline__ void copy_vec4_a3(void *dst, void *src)
{
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

#define copy_vec4_a3_m(dst, src) do { \
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory"); \
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory"); \
} while (0)

typedef struct {
    float x, y, z, w;
} VecF;

typedef struct {
    u8 pad00[0x850];
    u8 f850[0x30];
    VecF v880;
    u8 f890[0x30];
    VecF v8C0;
    u8 pad8D0[0x40];
    VecF v910;
    VecF v920;
    VecF v930;
    VecF v940;
    u8 pad950[0x20];
    VecF v970;
    VecF v980;
    VecF v990;
    u8 pad9A0[0x3A8];
    float fD48;
    u8 padD4C[0x20];
    int fD6C;
} Work11A8;

extern int D_01B090FC;
extern int D_01B0911C;
extern int D_01B0913C;
extern Work11A8 *D_01B09148;

extern float func_01B01FB0(int);
extern void func_01B020D8(int, void *, int);
extern void func_01B02D18(int, int);
extern void func_01B02DA0(int, int);
extern void func_01B02E40(int, int);
extern void func_01B03348(int, void *);
extern void func_01B038C8(int, void *, void *);
extern void func_01B05830(void *, void *, void *);

void func_01B011A8(void)
{
    VecF v0;
    VecF v1;
    VecF v2;
    Work11A8 *w = D_01B09148;

    func_01B020D8(0, &v0, 0);
    copy_vec4_a3(&w->v970, &v0);
    v1.x = 0.0f;
    {
        float y = func_01B01FB0(0);
        void *dst;
        register VecF *pv1 __asm__("$19");
        v1.y = y;
        __asm__("" : : "m"(v1.y));
        dst = &w->v910;
        __asm__("" : "+r"(dst));
        v1.z = 0.0f;
        __asm__("" : : "m"(v1.z));
        pv1 = &v1;
        __asm__("" : "+r"(pv1));
        v1.w = 0.0f;
        copy_vec4_a3_m(dst, pv1);
        copy_vec4_a3(&w->v920, &v0);
        func_01B03348(0, w->f850);
        func_01B038C8(0, w->f850, pv1);
        copy_vec4_a3(&w->v880, &w->v920);
        {
            register VecF *dst930 __asm__("$3") = &w->v930;
            __asm__("" : "+r"(dst930));
            copy_vec4_a3_m(dst930, pv1);
        }
        copy_vec4_a3(&w->v940, &v0);
        func_01B03348(-1, w->f890);
        func_01B038C8(-1, w->f890, pv1);
        copy_vec4_a3(&w->v8C0, &w->v940);
        func_01B02E40(-1, 1);
        func_01B02DA0(-1, 0);
        func_01B02D18(-1, 0);
        w->fD48 = v1.y;
        copy_vec4_a3(&w->v980, &w->v920);
        v2.x = 0.0f;
        v2.y = 0.0f;
        v2.z = 15.0f;
        func_01B05830(pv1, &w->v980, &v2);
        copy_vec4_a3(&w->v990, &w->v920);
        v2.x = 0.0f;
        v2.y = 0.0f;
        v2.z = 24.0f;
        func_01B05830(pv1, &w->v990, &v2);
    }
    w->fD6C = 0;
    D_01B090FC = 1;
    D_01B0911C = 1;
    D_01B0913C = 1;
}
