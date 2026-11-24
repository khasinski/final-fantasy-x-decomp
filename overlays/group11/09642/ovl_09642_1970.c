#include "common.h"

typedef struct {
    float x, y, z, w;
} VecF;

typedef struct {
    u8 pad00[0x960];
    VecF v960;
    u8 pad970[0x3D8];
    float fD48;
    u8 padD4C[0x18];
    int fD64;
} Work1970;

typedef struct {
    float f00, f04, f08, f0C;
    float f10, f14, f18, f1C;
    float f20, f24, f28, f2C;
    u8 f30[0x0C];
    float f3C;
    u8 pad40[0x0C];
    int f4C, f50, f54;
    u8 pad58[0x08];
    int f60;
    u8 pad64[0x07];
    u8 f6B;
} Particle1970;

extern u8 D_01B08FE0[];
extern Work1970 *D_01B09148;

extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern int func_002EFD78(void);
extern void func_01B02578(int, int, int, void *);
extern int *func_01B04F88(void *, int);
extern void func_01B05830(void *, void *, void *);
extern void func_01B05DC0(void *, int);
extern Particle1970 *func_01B08638(void);

void func_01B01970(void)
{
    VecF v0;
    VecF v1;
    VecF v2;
    Work1970 *w = D_01B09148;

    v0.x = 0.0f;
    v0.y = w->fD48;
    v0.z = 0.0f;
    v0.w = 0.0f;
    v1.x = 1.0f;
    v1.y = 0.0f;
    v1.z = 0.0f;
    v1.w = 1.0f;
    func_01B05830(&v0, &w->v960, &v1);

    if (w->fD64 > 0) {
        int *ptr;
        int tex;
        int i;

        w->fD64--;
        ptr = func_01B04F88(D_01B08FE0, 3);
        tex = *ptr;
        for (i = 0; i < 2; i++) {
            Particle1970 *p = func_01B08638();
            if (p == 0) {
                break;
            }
            func_01B05DC0(p->f30, tex);
            func_01B02578(1, func_002EFD78() % 0x65 + 3, 0, &v2);
            p->f00 = v2.x + func_002B3DB0(5.0f);
            p->f04 = v2.y + func_002B3DB0(5.0f);
            p->f08 = v2.z + func_002B3DB0(5.0f);
            p->f0C = 1.0f;
            p->f10 = func_002B3DB0(0.25f);
            p->f14 = func_002B3DB0(0.25f);
            p->f18 = func_002B3DB0(0.25f);
            p->f1C = func_002B3DB0(3.14159274f);
            p->f20 = 0.0f;
            p->f24 = 0.01f;
            p->f28 = 0.0f;
            p->f2C = 1.0f;
            {
                float r = func_002B3DF8(0.8f) + 0.8f;
                p->f4C = 0x20;
                p->f50 = 0x10;
                p->f54 = -0x10;
                p->f60 = 0;
                __asm__("" : "+r"(p));
                p->f3C = r * 0.02f;
                p->f6B = 0;
            }
        }
    }
}
