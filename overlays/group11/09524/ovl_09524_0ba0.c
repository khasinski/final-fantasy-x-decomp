/* 09524 camera/effect setup (268 B). */

#include "common.h"

typedef struct {
    float cur[4];
    float start[4];
    float end[4];
    int timer;
    int duration;
    u8 pad38[0x8];
} LightSlot9524;

typedef struct {
    LightSlot9524 dir[3];
    LightSlot9524 col[4];
} Light9524;

extern Light9524 g_75d0;
extern void ovl_6bc8(Light9524 *, int, float *, int);
extern void ovl_6bf8(Light9524 *, int, float *, int);

typedef struct {
    float x, y, z, w;
} Vec4;

void ovl_09524_0ba0(void)
{
    Vec4 v0;
    Vec4 v1;
    float zero = 0.0f;
    Light9524 *l = &g_75d0;
    register float *vp __asm__("$17");
    float two;

    {
        float f = -2.3911011f;
        register Light9524 *a0_ __asm__("$4") = l;
        __asm__("" : "+f"(zero));
        __asm__("" : "+f"(zero));
        __asm__("" : "=r"(vp) : "r"(a0_), "f"(zero));
        v0.x = zero;
        __asm__("" : "+f"(f) : "r"(vp));
        v0.y = f;
        ovl_6bc8(a0_, 1, &v0.x, 1);
    }

    v0.x = zero;
    v0.y = 1.7453293f;
    ovl_6bc8(l, 2, &v0.x, 1);

    two = 2.0f;
    __asm__("" : "+f"(two));
    {
        register LightSlot9524 *s __asm__("$2") = &l->col[1];
        vp = &v1.x;
        __asm__("" : "+r"(s) : "f"(two));
        __asm__("" : "+r"(vp) : "r"(s));
        {
            register Light9524 *a0_ __asm__("$4") = l;
            __asm__ volatile("" : "+r"(a0_) : "r"(vp));
            *(volatile float *)&l->col[1].cur[0] = two;
            {
                register float *a2_ __asm__("$6") = vp;
                __asm__ volatile("" : "+r"(a2_) : "r"(a0_));
                *(volatile float *)&s->cur[2] = two;
                {
                    register int a1_ __asm__("$5") = 1;
                    __asm__ volatile("" : "+r"(a1_) : "r"(a2_));
                    *(volatile float *)&s->cur[1] = two;
                    {
                        register int a3_ __asm__("$7") = 5;
                        __asm__ volatile("" : "+r"(a3_) : "r"(a1_));
                        *(volatile float *)&l->col[2].cur[0] = two;
                        s = &l->col[2];
                        __asm__ volatile("" : "+r"(s) : "r"(a3_), "f"(two));
                        *(volatile float *)&s->cur[2] = two;
                        *(volatile float *)&s->cur[1] = two;
                        *(volatile float *)&l->col[3].cur[0] = zero;
                        s = &l->col[3];
                        __asm__ volatile("" : "+r"(s) : "f"(zero));
                        *(volatile float *)&s->cur[2] = zero;
                        *(volatile float *)&s->cur[1] = zero;
                        v1.x = zero;
                        v1.y = zero;
                        v1.z = zero;
                        ovl_6bf8(a0_, a1_, a2_, a3_);
                    }
                }
            }
        }
        ovl_6bf8(l, 2, vp, 5);
        ovl_6bf8(l, 3, vp, 5);
    }
}
