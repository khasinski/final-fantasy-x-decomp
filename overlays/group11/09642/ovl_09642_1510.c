#include "common.h"

typedef struct {
    u8 pad00[0xAE0];
    int fAE0;
    int fAE4;
    int fAE8;
    int fAEC;
    u8 padAF0[0x90];
    u8 fB80[0x10];
} Work1510;

extern Work1510 *D_01B09148;

extern void func_00118098(int, int);
extern void func_01B08218(void *, int);
extern void func_01B08368(void *, int, int, float, float);

void func_01B01510(void)
{
    u8 *w = (u8 *)D_01B09148;

    func_01B08368(w + 0xB80, 1, 0, 1.0f, 0.5f);
    *(int *)(w + 0xAE0) = 0;
    w += 0xAE0;
    {
        register int a1 __asm__("$5") = 0x96;
        register u8 *a0 __asm__("$4") = w;
        __asm__("" : "+r"(a1));
        __asm__("" : "+r"(a0));
        *(int *)(w + 4) = 0x64;
        __asm__("" : : "m"(*(int *)(w + 4)));
        *(int *)(w + 8) = 0;
        *(int *)(w + 12) = 0;
        func_01B08218(a0, a1);
    }
    __asm__("" : : "r"(w));
    func_00118098(0, 0x10000);
    func_00118098(1, 0x8000);
}
