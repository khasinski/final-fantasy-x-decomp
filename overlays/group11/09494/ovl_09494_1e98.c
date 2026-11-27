#include "common.h"

typedef struct {
    u8 pad00[0x1F18];
    int w1F18;
    int w1F1C;
} ObjA310;

typedef struct {
    u32 pad00;
    int cnt;
    u8 pad08[0xD];
    u8 b15;
    u8 b16;
    u8 pad17[0xAD];
    void *pC4;
    void *pC8;
} ObjAE0;

extern ObjAE0 D_01B00AE0;
extern ObjA310 *D_01B0A310;

extern void *func_01B04DF0(int);
extern void func_00110648(void *, int);
extern void Ch_BindToElem(void *, void *, int);

void func_01B01E98(void)
{
    ObjA310 *s3 = D_01B0A310;
    ObjAE0 *s1 = &D_01B00AE0;
    void *s2 = 0;
    void *s0;

    if (s3->w1F1C != -1) {
        register void *t __asm__("$16") = func_01B04DF0(s3->w1F1C);
        register int a1 __asm__("$5") = 0;
        register u8 b21 __asm__("$2");
        register void *a0 __asm__("$4");
        __asm__("" : "+r"(t), "+r"(a1));
        b21 = 0x21;
        __asm__("" : "+r"(b21));
        a0 = t;
        __asm__("" : "+r"(a0) : "r"(b21));
        s1->b16 = b21;
        __asm__("" : "+r"(t) : : "memory");
        s2 = t;
        __asm__("" : "+r"(t));
        s1->pC8 = t;
        func_00110648(a0, a1);
        s1->cnt++;
    }
    s0 = func_01B04DF0(0x4029);
    s1->b15 = 0x20;
    s1->pC4 = s0;
    func_00110648(s0, 0);
    {
        register int c __asm__("$3") = s1->cnt + 1;
        s1->cnt = c;
    }
    if (s2 != 0) {
        Ch_BindToElem(s0, s2, (s3->w1F18 == 6) ? 4 : 5);
    }
}
