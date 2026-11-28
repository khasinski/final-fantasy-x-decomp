#include "common.h"

extern float D_01B00798;
extern float D_01B009F0[4];
extern u8 D_01B00A00[];
extern void *D_01B006A8;
extern u8 D_01B00BC8[];
extern u8 D_01B00A50[];
extern u8 D_01B00A80[];
extern int D_01B00AB4;

extern void func_01B01228(void *);
extern void func_00110830(void *, void *);
extern void func_01B03A38(void *);
extern void func_01B03780(void *, float);

int func_01B01D98(void)
{
    u8 unused[0xA0];
    float f = D_01B00798;

    (void)unused;
    D_01B009F0[0] = f;
    D_01B009F0[1] = f;
    D_01B009F0[2] = f;
    D_01B009F0[3] = 1.0f;
    func_01B01228(D_01B00A00);
    func_00110830(D_01B006A8, D_01B00A00);
    func_01B03A38(D_01B00BC8);
    func_01B03780(D_01B00A50, 5.0f);
    func_01B03780(D_01B00A80, 5.0f);
    return D_01B00AB4 == 0;
}
