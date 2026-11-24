#include "common.h"

static __inline__ void copy_vec4_a3(void *dst, void *src)
{
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0x56];
    u8 b56;
} Arg2590;

typedef struct {
    u8 pad00[0x720];
    float v720[4];
    float v730[4];
    float v740[4];
    u8 pad750[0x208];
    int f958;
    int f95C;
    int f960;
    int f964;
    int f968;
    int f96C;
} Sub2590;

typedef struct {
    u8 pad00[0x280];
    Sub2590 sub;
} Work2590;

extern Work2590 *D_01B09248;
extern u8 D_01B09228[];
extern u8 D_01B0ED00[];

extern void func_01B01CD8(Sub2590 *);
extern int func_01B01E48(Sub2590 *);
extern int func_01B01EA0(Sub2590 *);
extern int func_01B01FF0(Sub2590 *);
extern int func_01B02220(Sub2590 *);
extern void func_01B02358(Sub2590 *);
extern void func_01B02500(Sub2590 *);
extern void func_01B02B68(int, float);
extern void func_01B02BD8(int, void *, int);
extern void func_01B04918(void *, int);
extern void func_01B04BE8(void *, int, void *, int);
extern float func_01B06500(float, float);

void func_01B02590(Arg2590 *a0)
{
    float pos[4];
    Sub2590 *s = &D_01B09248->sub;

    switch (s->f96C) {
    case 0:
        func_01B01CD8(s);
        s->f96C = 1;
        s->f958++;
        break;
    case 1:
        {
            int r1 = func_01B01FF0(s);
            int r2 = func_01B01E48(s);
            if (r2 == 1 || r1 == 1) {
                func_01B02358(s);
                s->f96C = 2;
            }
        }
        break;
    case 2:
        {
            int r1 = func_01B02220(s);
            if (r1 == 1) {
                if (s->f958 < s->f95C) {
                    s->f96C = 0;
                } else {
                    func_01B04918(D_01B09228, 0);
                    a0->b56 = r1;
                }
            } else if (s->f960 == 0x17) {
                func_01B02BD8(-1, pos, 0);
                func_01B04BE8(D_01B0ED00, 0, pos, 0x100);
                {
                    register void *d __asm__("$4") = s->v740;
                    __asm__("" : "+r"(d));
                    copy_vec4_a3(d, s->v730);
                }
                {
                    register int ten __asm__("$3") = 10;
                    s->f968 = ten;
                }
            }
        }
        break;
    case 3:
        func_01B01CD8(s);
        s->f96C = 4;
        break;
    case 4:
        {
            int r1 = func_01B01FF0(s);
            int r2 = func_01B01EA0(s);
            if (r2 == 1 || r1 == 1) {
                func_01B02500(s);
                s->f96C = 2;
            }
        }
        break;
    }

    if (s->f968 > 0) {
        float ang;
        float t;
        s->f968--;
        ang = func_01B06500(s->v720[1], s->v740[1]);
        t = (float)s->f968 / 10.0f;
        ang = ang * (1.0f - t) + s->v720[1] * t;
        if (ang > 3.14159274f) {
            ang -= 6.28318548f;
        } else if (ang < -3.14159274f) {
            ang += 6.28318548f;
        }
        func_01B02B68(-1, ang);
    }
}
