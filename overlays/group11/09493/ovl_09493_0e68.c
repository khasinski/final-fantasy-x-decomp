#include "common.h"

typedef struct {
    u8 pad00[0xD40];
    u_long128 vD40;
    u8 padD50[0x210];
    u_long128 vF60;
    u8 padF70[0x47C0];
    int w5730;
} OvlWork;

extern void *D_01B00A94;
extern u8 D_01B08DA8[];
extern u8 D_01B08E08[];
extern OvlWork *D_01B08E28;
extern void *D_01B08E2C;

extern void func_01B01010(void);
extern int func_01B04198(void *);
extern void func_01B04D38(void *);
extern void func_01B063A0(void);
extern int func_01B085C8(void *);

void ovl_09493_0e68(void *a0)
{
    OvlWork *s1 = D_01B08E28;
    int s0;
    int v0;

    func_01B063A0();
    D_01B00A94 = D_01B08E2C;
    s0 = func_01B085C8(D_01B08DA8);
    v0 = func_01B04198(D_01B08E08);
    if (s0 != 0 && v0 != 0) {
        s1->w5730 = 1;
        func_01B01010();
        func_01B04D38(a0);
    } else {
        register u_long128 *src __asm__("$3") = &s1->vF60;
        register u_long128 *dst __asm__("$2") = &s1->vD40;
        register u_long128 _t __asm__("$7");
        __asm__("" : "+r"(src));
        __asm__("" : "+r"(dst));
        _t = *src;
        *dst = _t;
        __asm__("" : : : "memory");
    }
}
