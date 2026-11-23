/* 09411 particle burst spawn (596 B). */

#include "vu0.h"

typedef unsigned int u128 __attribute__((mode(TI)));

typedef struct {
    u8 pad00[0x10];
    u128 vec10;
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    float f34;
    int w38;
    int w3C;
    u8 pad40[0x0B];
    u8 b4B;
    u8 pad4C[0x04];
    s16 h50;
} OvlPart7650;

extern u8 g_ovl_res[];
extern int func_002EFD78(void);
extern void *func_002B49A0(void *, int, int);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern OvlPart7650 *fn_ovl_7650(void);
extern void fn_ovl_52d0(OvlPart7650 *, void *);

void ovl_09411_0f10(u128 *src)
{
    int i;
    int n = func_002EFD78() % 3 + 1;
    OvlPart7650 *p;

    for (i = 0; i < n; i++) {
        p = fn_ovl_7650();
        if (p == 0) {
            return;
        }
        fn_ovl_52d0(p, func_002B49A0(g_ovl_res, 9, 0));
        MMI_COPY_LQ_A3(&p->vec10, src);
        MMI_COPY_SQ_A3(&p->vec10);
        p->f20 = func_002B3DB0(0.4f);
        p->f24 = func_002B3DB0(0.4f);
        p->f28 = func_002B3DB0(0.4f);
        p->f2C = func_002B3DB0(6.2831855f);
        {
            float t = (func_002B3DF8(0.5f) + 1.0f) * 0.1f;
            p->f34 = -10.0f;
            p->w38 = -1;
            p->w3C = 0;
            p->b4B = 0x20;
            p->h50 = 1;
            p->f30 = t;
        }
    }

    for (i = 0; i < 3; i++) {
        p = fn_ovl_7650();
        if (p == 0) {
            return;
        }
        fn_ovl_52d0(p, func_002B49A0(g_ovl_res, 9, 1));
        MMI_COPY_LQ_A3(&p->vec10, src);
        MMI_COPY_SQ_A3(&p->vec10);
        p->f20 = func_002B3DB0(2.0f);
        p->f24 = 2.0f;
        p->f28 = func_002B3DB0(2.0f);
        p->f2C = func_002B3DB0(6.2831855f);
        {
            float t = (func_002B3DF8(0.5f) + 1.0f) * 0.005f;
            p->f34 = -10.0f;
            p->w38 = 0x10;
            p->w3C = 0x10;
            p->b4B = 0;
            p->h50 = 1;
            p->f30 = t;
        }
    }
}
