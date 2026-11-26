#include "common.h"

typedef struct {
    u8 pad00[0xB90];
    u8 fB90[0xE0];
    u_long128 vC70;
    u_long128 vC80;
    u8 padC90[0x20];
    u_long128 vCB0;
    float fCC0;
    float fCC4;
    float fCC8;
    float fCCC;
} OvlWork;

extern OvlWork *D_01B08A90;

extern void func_01B02B38(int, int);
extern void func_01B03070(int, void *);
extern void func_01B035F0(int, void *, void *);

void ovl_09644_17b0(void)
{
    OvlWork *s0 = D_01B08A90;
    void *s1 = s0->fB90;
    register u_long128 *pCB0 __asm__("$6");

    func_01B03070(2, s1);
    pCB0 = &s0->vCB0;
    {
        u_long128 *src = &s0->vC70;
        register u_long128 _t __asm__("$7");
        __asm__("" : "+r"(pCB0), "+r"(src));
        _t = *src;
        *pCB0 = _t;
        __asm__("" : : : "memory");
    }
    {
        u_long128 *dst = (u_long128 *)&s0->fCC0;
        u_long128 *src = &s0->vC80;
        register u_long128 _t __asm__("$7");
        __asm__("" : "+r"(dst), "+r"(src));
        _t = *src;
        *dst = _t;
        __asm__("" : : : "memory");
    }
    func_01B035F0(2, s1, pCB0);
    s0->fCC4 -= 5.0f;
    func_01B02B38(2, 0);
}
