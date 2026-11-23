#include "common.h"

typedef struct {
    u8 pad00[0x10];
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    u8 sub30[0x0C];
    float f3C;
    u8 pad40[0x0C];
    s32 w4C;
    s32 w50;
    u8 pad54[0x10];
    u8 b64;
    u8 b65;
    u8 b66;
    u8 pad67;
    u8 b68;
    u8 b69;
    u8 b6A;
    u8 b6B;
} Part9463;

extern s32 D_01B06630;
extern u8 D_01B0C420[];

extern float func_001ACED8(void);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern void *op_oef2_a_get(void *, int, int);
extern int func_002EFD78(void);

extern void func_01B018D0(int, int, int, Part9463 *);
extern void func_01B03A70(void);
extern void func_01B05118(void *, void *);
extern Part9463 *func_01B05F38(void);

void ovl_09463_0e20(void)
{
    int i;
    register s32 v0 __asm__("$2") = D_01B06630;

    if (v0 <= 0) {
        func_01B03A70();
        return;
    }
    i = 0;
    do {
        Part9463 *p = func_01B05F38();
        if (p == 0) {
            break;
        }
        func_01B05118(p->sub30, op_oef2_a_get(D_01B0C420, 9, 0));
        func_01B018D0(-1, (func_002EFD78() % 155) + 2, 0, p);
        p->f10 = (func_001ACED8() - 1.5f) * 0.5f;
        p->f14 = (func_001ACED8() - 1.0f) * 0.4f;
        p->f18 = (func_001ACED8() - 1.5f) * 0.5f;
        p->f1C = func_002B3DB0(3.1415927f);
        p->f20 = 0.0f;
        p->f24 = -0.02f;
        p->f28 = 0.0f;
        p->f2C = 1.0f;
        p->f3C = (func_002B3DF8(0.9f) + 0.1f) * 0.1f;
        p->w4C = 32;
        p->w50 = 32;
        p->b64 = 0xD0;
        p->b65 = 0x70;
        p->b66 = 0x20;
        p->b68 = 0xD0;
        p->b69 = 0x70;
        p->b6A = 0x20;
        p->b6B = 0;
        i++;
    } while (i < 2);
}
