#include "common.h"

typedef struct {
    u8 pad00[0x56];
    u8 b56;
} OvlArg;

typedef struct {
    u8 pad00[0xD10];
    u8 fD10[0x240];
    float fF50[4];
    float fF60[4];
    float fF70[4];
    u8 padF80[0x20];
    float fFA0[4];
    float fFB0[4];
    u8 padFC0[0x4760];
    int w5720;
    int w5724;
} OvlWork;

extern OvlWork *D_01B08E28;

extern void func_01B012E8(void);
extern void func_01B03EE8(int, void *, void *);
extern float func_01B05B90(float, float, float, float, float, float);
extern float func_01B06020(float, float);

void ovl_09493_13a0(OvlArg *arg)
{
    register OvlWork *s2 __asm__("$18") = D_01B08E28;
    float t;
    int i;
    float ang;

    if (s2->w5720 > 0) {
        s2->w5720 -= 1;
    }
    t = (float)s2->w5720 / (float)s2->w5724;
    for (i = 0; i < 3; i++) {
        float d = s2->fFA0[i] - s2->fF70[i];
        s2->fF60[i] = s2->fF70[i] + func_01B05B90(d, d * 0.99f, d * 1.1f, d * 0.8f, 0.0f, t);
    }
    ang = func_01B06020(s2->fF50[1], s2->fFB0[1]) * (1.0f - t) + s2->fF50[1] * t;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    s2->fF50[1] = ang;
    func_01B03EE8(-1, s2->fD10, s2->fF50);
    if (s2->w5720 == 50) {
        func_01B012E8();
    }
    if (s2->w5720 <= 0) {
        register u_long128 *src __asm__("$22") = (u_long128 *)s2->fFA0;
        register u_long128 *dst __asm__("$21") = (u_long128 *)s2->fF60;
        register u_long128 _t __asm__("$7");
        __asm__("" : "+r"(src), "+r"(dst));
        _t = *src;
        *dst = _t;
        __asm__("" : : : "memory");
        arg->b56 = 1;
    }
}
