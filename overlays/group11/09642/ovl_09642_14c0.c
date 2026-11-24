#include "common.h"

typedef struct {
    u8 pad00[0x04];
    int f04;
    u8 pad08[0x0D];
    u8 f15;
    u8 pad16[0xAE];
    int fC4;
} Obj9B0;

extern Obj9B0 D_01B009B0;

extern int func_00110648(int, int);
extern int func_01B036E0(int);

int func_01B014C0(void)
{
    Obj9B0 *o = &D_01B009B0;
    int h;
    int r;

    __asm__("" : "+r"(o));
    h = func_01B036E0(0x3013);
    o->fC4 = h;
    o->f15 = 0x20;
    r = func_00110648(h, 0);
    o->f04 = 2;
    return r;
}
