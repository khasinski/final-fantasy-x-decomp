#include "common.h"

typedef struct {
    u8 pad00[0xB00];
    u_long128 vB00;
    u8 padB10[0x30];
    u_long128 vB40;
    u8 padB50[0x30];
    u_long128 vB80;
    u8 padB90[0x30];
    u_long128 vBC0;
    u8 padBD0[0x90];
    u_long128 vC60;
    u8 padC70[0x10];
    u_long128 vC80;
    u8 padC90[0x10];
    u_long128 vCA0;
    u8 padCB0[0x10];
    u_long128 vCC0;
    u8 padCD0[0x20C];
    int wEDC;
} OvlWork;

extern void *D_01B00CA4;
extern u8 D_01B08990[];
extern u8 D_01B089F0[];
extern u8 D_01B08A50[];
extern u8 D_01B08A70[];
extern OvlWork *D_01B08A90;
extern void *D_01B08A94;

extern void func_01B01478(void);
extern void func_01B038A0(void *);
extern void func_01B04440(void *);
extern void func_01B05AA8(void);
extern void func_01B062D0(void);
extern int func_01B07CD0(void *);

static __inline__ void copy_q(u_long128 *dst, u_long128 *src)
{
    register u_long128 _t __asm__("$7");
    __asm__("" : "+r"(dst), "+r"(src));
    _t = *src;
    *dst = _t;
    __asm__("" : : : "memory");
}

void ovl_09644_1170(void *s2)
{
    OvlWork *s1 = D_01B08A90;
    int s0;

    func_01B05AA8();
    D_01B00CA4 = D_01B08A94;
    s0 = func_01B07CD0(D_01B08990);
    func_01B07CD0(D_01B089F0);
    if (s0 == 0) {
        {
            register u_long128 *dst __asm__("$3") = &s1->vB00;
            register u_long128 *src __asm__("$2") = &s1->vC60;
            register u_long128 _t __asm__("$7");
            __asm__("" : "+r"(dst) : : "memory");
            __asm__("" : "+r"(src));
            _t = *src;
            *dst = _t;
            __asm__("" : : : "memory");
        }
        {
            register u_long128 *dst __asm__("$4") = &s1->vB40;
            register u_long128 *src __asm__("$2") = &s1->vC80;
            register u_long128 _t __asm__("$7");
            __asm__("" : "+r"(dst) : : "memory");
            __asm__("" : "+r"(src));
            _t = *src;
            *dst = _t;
            __asm__("" : : : "memory");
        }
        {
            register u_long128 *dst __asm__("$3") = &s1->vB80;
            register u_long128 *src __asm__("$2") = &s1->vCA0;
            register u_long128 _t __asm__("$7");
            __asm__("" : "+r"(dst) : : "memory");
            __asm__("" : "+r"(src));
            _t = *src;
            *dst = _t;
            __asm__("" : : : "memory");
        }
        {
            register u_long128 *src __asm__("$4") = &s1->vCC0;
            register u_long128 *dst __asm__("$2") = &s1->vBC0;
            register u_long128 _t __asm__("$7");
            __asm__("" : "+r"(src) : : "memory");
            __asm__("" : "+r"(dst));
            _t = *src;
            *dst = _t;
            __asm__("" : : : "memory");
        }
        func_01B038A0(D_01B08A50);
        func_01B038A0(D_01B08A70);
        func_01B062D0();
    } else {
        s1->wEDC = 1;
        func_01B01478();
        func_01B04440(s2);
    }
}
