#include "common.h"

typedef struct {
    u8 pad00[0x5730];
    int w5730;
} OvlWork;

extern int D_01B08D58;
extern u8 D_01B08D60[];
extern void *D_01B08DA4;
extern OvlWork *D_01B08E28;

extern void func_001CDDD8(int);
extern void func_01B03968(int, void *);
extern int func_01B050F8(void *, void *);

void ovl_09493_0f18(void)
{
    OvlWork *s0 = D_01B08E28;

    if (func_01B050F8(D_01B08D60, D_01B08DA4) == 1 && s0->w5730 == 1) {
        func_01B03968(-1, 0);
        func_001CDDD8(D_01B08D58);
    }
}
