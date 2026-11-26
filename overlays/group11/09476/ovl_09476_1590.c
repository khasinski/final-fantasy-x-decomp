#include "common.h"

typedef struct {
    u8 pad00[0xC0];
    float fC0;
    float fC4;
    float fC8;
    u8 padCC[0x04];
    float fD0;
    float fD4;
    float fD8;
    float fDC;
    float fE0;
    float fE4;
    float fE8;
} OvlSub;

typedef struct {
    u8 pad00[0x390];
    OvlSub sub;
    u8 pad47C[0xAF4];
    u_long128 vF70;
    u8 fF80[0x2400];
    float f3380;
} OvlWork;

extern u8 D_01B014F8[];
extern u8 D_01B087A0[];
extern OvlWork *D_01B08868;

extern void func_01B00DC8(void *);
extern void *func_01B04430(void *);
extern void func_01B045F8(void *);
extern void func_01B04790(void *, void *, int, int, float, int, int);

void ovl_09476_1590(void)
{
    OvlWork *s1 = D_01B08868;
    OvlSub *s0 = &s1->sub;
    float ang;

    func_01B04790(D_01B087A0, s0, 3, 4, 0.025f, 0, 0);
    {
        register u_long128 *dst __asm__("$3") = (u_long128 *)&s0->fD0;
        register u_long128 *src __asm__("$2");
        register u_long128 _t __asm__("$7");
        __asm__("" : "+r"(dst) : : "memory");
        src = &s1->vF70;
        __asm__("" : "+r"(src));
        _t = *src;
        *dst = _t;
        __asm__("" : : : "memory");
    }
    s0->fC0 = -0.174532935f;
    ang = s1->f3380 + 3.45575213f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    s0->fC4 = ang;
    s0->fC8 = -0.628318548f;
    s0->fD4 -= 22.0f;
    s0->fE0 = 5.0f;
    s0->fE8 = 5.0f;
    func_01B00DC8(s1->fF80);
    func_01B045F8(func_01B04430(D_01B014F8));
}
