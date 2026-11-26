#include "common.h"

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float fD0;
    float fD4;
    float fD8;
    float fDC;
    u8 padE0[0x30];
    void *p110;
} OvlSub;

typedef struct {
    u8 pad00[0x980];
    OvlSub sub;
    u8 padA94[0x27C];
    u8 fD10[0x30];
    u_long128 vD40;
    u8 padD50[0x200];
    float fF50[4];
    u_long128 vF60;
    u_long128 vF70;
    u8 padF80[0x46D0];
    u8 f5650[0xC0];
    float f5710;
} OvlWork;

extern u8 D_01B00748[];
extern u8 D_01B08D60[];
extern OvlWork *D_01B08E28;
extern u8 D_01B0F3A0[];

extern void func_01B03968(int, void *);
extern void func_01B03EE8(int, void *, void *);
extern void func_01B047A0(void *, void *, void *);
extern void func_01B05018(void *, void *, int, int, float, int, int);

void ovl_09493_1018(void)
{
    OvlWork *s0 = D_01B08E28;
    OvlSub *s1 = &s0->sub;
    u_long128 *src;

    func_01B05018(D_01B08D60, s1, 8, 0, 0.15f, 0, 0);
    src = &s0->vF70;
    {
        register u_long128 *dst __asm__("$3") = (u_long128 *)&s1->fD0;
        register u_long128 _t __asm__("$7");
        __asm__("" : "+r"(src), "+r"(dst));
        _t = *src;
        *dst = _t;
        __asm__("" : : : "memory");
    }
    {
        float y = s1->fD4 - 2.0f;
        s1->fC4 = s0->f5710;
        s1->fD4 = y;
    }
    func_01B047A0(s0->f5650, D_01B0F3A0, D_01B00748);
    s1->p110 = s0->f5650;
    s0->fF50[0] = 0.0f;
    s0->fF50[2] = 0.0f;
    s0->fF50[3] = 0.0f;
    s0->fF50[1] = s0->f5710;
    func_01B03EE8(-1, s0->fD10, s0->fF50);
    {
        u_long128 *dst = &s0->vD40;
        register u_long128 _t __asm__("$7");
        __asm__("" : "+r"(dst));
        _t = *src;
        *dst = _t;
        __asm__("" : : : "memory");
    }
    {
        u_long128 *dst = &s0->vF60;
        register u_long128 _t __asm__("$7");
        __asm__("" : "+r"(dst));
        _t = *src;
        *dst = _t;
        __asm__("" : : : "memory");
    }
    func_01B03968(-1, s0->fD10);
}
