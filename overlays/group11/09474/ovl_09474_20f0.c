#include "common.h"

typedef struct {
    u8 pad00[0x30];
    u_long128 v30;
    u8 pad40[0x106];
    u8 b146;
} OvlObj;

typedef struct {
    u8 pad00[0xC60];
    u_long128 vC60;
    u8 padC70[0x258];
    float fEC8;
} OvlWork;

extern OvlWork *D_01B0A480;

extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);
extern void func_01B07B08(int);
extern OvlObj *func_01B07E38(int);

void func_01B020F0(void)
{
    OvlWork *s1 = D_01B0A480;
    OvlObj *s0;

    func_01B07B08(0);
    s0 = func_01B07E38(0);
    s0->b146 = 1;
    func_002DD128(s0);
    func_002DD318(s0, s0, s1->fEC8);
    {
        u_long128 *dst = &s0->v30;
        u_long128 *src = &s1->vC60;
        register u_long128 _t __asm__("$7");
        __asm__("" : "+r"(dst), "+r"(src));
        _t = *src;
        *dst = _t;
        __asm__("" : : : "memory");
    }
}
