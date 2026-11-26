#include "common.h"

typedef struct {
    u8 pad00[0x3388];
    int w3388;
} OvlWork;

extern int D_01B08798;
extern u8 D_01B087A0[];
extern void *D_01B087E4;
extern OvlWork *D_01B08868;

extern void func_001CDDD8(int);
extern int func_01B04870(void *, void *);

void ovl_09476_0ca0(void)
{
    OvlWork *s0 = D_01B08868;

    if (func_01B04870(D_01B087A0, D_01B087E4) == 1 && s0->w3388 == 1) {
        func_001CDDD8(D_01B08798);
    }
}
