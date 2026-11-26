#include "common.h"

typedef struct {
    u8 pad00[0xF60];
    u8 fF60[0x10];
    u_long128 vF70;
    u8 padF80[0x20];
    u_long128 vFA0;
    float fFB0[4];
    u8 fFC0[0x4750];
    float f5710;
    u8 pad5714[0x0C];
    int w5720;
    int w5724;
    int w5728;
} OvlWork;

extern OvlWork *D_01B08E28;

extern int func_00297C28(int, int, int, int, int, int, int);
extern int func_01B02540(int);
extern void func_01B02D40(void *);
extern void func_01B05D48(void *, void *, void *);
extern void func_01B05E50(void *, void *, void *);
extern void func_01B05EF0(void *, void *);

void ovl_09493_1120(void)
{
    struct {
        u_long128 sp00;
        float sp10[4];
        float sp20[4];
    } s;
    OvlWork *s0 = D_01B08E28;

    {
        register u_long128 *src __asm__("$3") = &s0->vF70;
        register u_long128 _t __asm__("$7");
        __asm__("" : "+r"(src));
        _t = *(volatile u_long128 *)src;
        *(volatile u_long128 *)&s.sp00 = _t;
        __asm__("" : : : "memory");
    }
    s.sp20[0] = 0.0f;
    s.sp20[1] = s0->f5710;
    s.sp10[1] = -10.0f;
    s.sp10[2] = 30.0f;
    s.sp10[3] = 1.0f;
    s.sp20[2] = 0.0f;
    s.sp20[3] = 0.0f;
    s.sp10[0] = 0.0f;
    func_01B05E50(s.sp20, &s.sp00, s.sp10);
    s0->fFB0[1] = s0->f5710;
    func_01B05EF0(s0->fF60, &s.sp00);
    {
        register int n __asm__("$3") = 60;
        u_long128 *dst;
        register u_long128 _t __asm__("$7");
        __asm__("" : "+r"(n) : : "memory");
        dst = &s0->vFA0;
        __asm__("" : "+r"(dst) : : "memory");
        _t = *(volatile u_long128 *)&s.sp00;
        *(volatile u_long128 *)dst = _t;
        __asm__("" : : : "memory");
        s0->w5720 = n;
        s0->w5724 = n;
    }
    func_01B02D40(s0->fFC0);
    func_01B05D48(s0->fFB0, &s.sp00, s0->fFC0);
    s0->w5728 = func_00297C28(func_01B02540(-1), 0, 0, 0, 0, 0, 0);
}
