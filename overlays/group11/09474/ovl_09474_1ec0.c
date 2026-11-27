#include "common.h"

typedef struct {
    u8 pad00[0xEDC];
    int wEDC;
} OvlWork;

extern int D_01B0A2F0;
extern u8 D_01B0A2F8[];
extern void *D_01B0A33C;
extern OvlWork *D_01B0A480;

extern void func_001CDDD8(int);
extern int func_01B061B0(void *, void *);

void func_01B01EC0(void)
{
    OvlWork *s0 = D_01B0A480;

    if (func_01B061B0(D_01B0A2F8, D_01B0A33C) == 1 && s0->wEDC == 1) {
        func_001CDDD8(D_01B0A2F0);
    }
}
