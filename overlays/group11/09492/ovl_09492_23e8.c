#include "common.h"

static __inline__ void copy_vec4_a3(void *dst, void *src)
{
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0x56];
    u8 b56;
} Arg23E8;

typedef struct {
    u8 pad00[0x720];
    float v720[4];
    float v730[4];
    float v740[4];
    u8 pad750[0x204];
    int f954;
    int f958;
    int f95C;
    int f960;
    int f964;
    int f968;
} Sub23E8;

typedef struct {
    u8 pad00[0x280];
    Sub23E8 sub;
} Work23E8;

extern Work23E8 *D_01B09098;
extern u8 D_01B09078[];
extern u8 D_01B0EA20[];

extern void func_01B01B70(Sub23E8 *);
extern int func_01B01C88(Sub23E8 *);
extern int func_01B01CE0(Sub23E8 *);
extern int func_01B01E18(Sub23E8 *);
extern int func_01B02078(Sub23E8 *);
extern void func_01B021B0(Sub23E8 *);
extern void func_01B02358(Sub23E8 *);
extern void func_01B029C0(int, float);
extern void func_01B02A30(int, void *, int);
extern void func_01B04770(void *, int);
extern void func_01B04A40(void *, int, void *, int);
extern float func_01B06358(float, float);

void func_01B023E8(Arg23E8 *a0)
{
    float pos[4];
    Sub23E8 *s = &D_01B09098->sub;

    switch (s->f968) {
    case 0:
        func_01B01B70(s);
        s->f968 = 1;
        s->f954++;
        break;
    case 1:
        {
            int r1 = func_01B01E18(s);
            int r2 = func_01B01C88(s);
            if (r2 == 1 || r1 == 1) {
                func_01B021B0(s);
                s->f968 = 2;
            }
        }
        break;
    case 2:
        {
            int r1 = func_01B02078(s);
            if (r1 == 1) {
                if (s->f954 < s->f958) {
                    s->f968 = 0;
                } else {
                    func_01B04770(D_01B09078, 0);
                    a0->b56 = r1;
                }
            } else if (s->f95C == 0x17) {
                func_01B02A30(-1, pos, 0);
                func_01B04A40(D_01B0EA20, 2, pos, 0x100);
                {
                    register void *d __asm__("$4") = s->v740;
                    __asm__("" : "+r"(d));
                    copy_vec4_a3(d, s->v730);
                }
                {
                    register int ten __asm__("$3") = 10;
                    s->f964 = ten;
                }
            }
        }
        break;
    case 3:
        func_01B01B70(s);
        s->f968 = 4;
        break;
    case 4:
        {
            int r1 = func_01B01E18(s);
            int r2 = func_01B01CE0(s);
            if (r2 == 1 || r1 == 1) {
                func_01B02358(s);
                s->f968 = 2;
            }
        }
        break;
    }

    if (s->f964 > 0) {
        float ang;
        float t;
        s->f964--;
        ang = func_01B06358(s->v720[1], s->v740[1]);
        t = (float)s->f964 / 10.0f;
        ang = ang * (1.0f - t) + s->v720[1] * t;
        if (ang > 3.14159274f) {
            ang -= 6.28318548f;
        } else if (ang < -3.14159274f) {
            ang += 6.28318548f;
        }
        func_01B029C0(-1, ang);
    }
}
