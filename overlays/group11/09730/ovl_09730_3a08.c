#include "common.h"

typedef struct {
    int w00;
    int w04;
    int w08;
    u8 pad0C[0x14];
    u8 s20[0x40];
    u8 s60[0x40];
} Elem3A08;

extern void *D_01B007A0;
extern void *D_01B007AC;
extern int D_01B00AA4;
extern int D_01B032C0;
extern int D_01B032C4;

extern void func_00294968(void *, void *, int);
extern void func_01B03820(void *);
extern void func_001C5E90(void *, int, int);
extern void func_01B038D0(void *);

int func_01B03A08(Elem3A08 *a0)
{
    Elem3A08 *p = a0;
    int i;

    for (i = 0; i < D_01B032C4; i++, p++) {
        if (p->w08 != 0) {
            if (p->w08 == 35) {
                func_00294968(D_01B007AC, p->s60, 256);
            }
            func_01B03820(p->s20);
            {
                register int z0 __asm__("$6") = 0;
                __asm__("" : : "r"(z0));
                if (--p->w08 == 20) {
                    register void *a __asm__("$4");
                    if (++D_01B032C4 > D_01B032C0) {
                        D_01B032C4 = D_01B032C0;
                    }
                    a = D_01B007A0;
                    __asm__("" : : "r"(a), "r"(z0));
                    func_001C5E90(a, p->w00, z0);
                }
            }
            if (p->w08 == 0) {
                register int dummy __asm__("$2") = D_01B032C4;
                __asm__("" : : "r"(dummy));
                func_01B038D0(p->s20);
            }
        }
    }
    p = a0;
    for (i = 0; i < D_01B032C0; i++, p++) {
        if (p->w08 != 0) {
            return 1;
        }
    }
    D_01B00AA4 = 1;
    return 0;
}
