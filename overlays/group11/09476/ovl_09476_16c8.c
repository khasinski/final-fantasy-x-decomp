#include "common.h"

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float fD0;
    float fD4;
    float fD8;
    float fDC;
} OvlObj;

extern u8 D_01B087A0[];

extern float func_002B3DF8(float);
extern void func_01B04790(void *, void *, int, int, float, int, int);
extern OvlObj *func_01B08708(void);

void ovl_09476_16c8(OvlObj *s1)
{
    OvlObj *s0 = func_01B08708();

    if (s0 != 0) {
        float r = (func_002B3DF8(1.0f) + 0.5f) * 0.02f;
        func_01B04790(D_01B087A0, s0, 4, 0, r, 0, 0);
        {
            register u_long128 *dst __asm__("$3") = (u_long128 *)&s0->fD0;
            register u_long128 *src __asm__("$2");
            register u_long128 _t __asm__("$7");
            __asm__("" : "+r"(dst) : : "memory");
            src = (u_long128 *)&s1->fD0;
            __asm__("" : "+r"(src));
            _t = *src;
            *dst = _t;
            __asm__("" : : : "memory");
        }
        s0->fD4 -= 1.0f;
        s0->fC4 = s1->fC4;
    }
}
