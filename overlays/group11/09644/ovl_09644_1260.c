#include "common.h"

typedef struct {
    u8 pad00[0xEDC];
    int wEDC;
} OvlWork;

extern int D_01B08940;
extern u8 D_01B08948[];
extern void *D_01B0898C;
extern OvlWork *D_01B08A90;

extern void func_001CDDD8(int);
extern int func_01B04800(void *, void *);

void ovl_09644_1260(void)
{
    OvlWork *s0 = D_01B08A90;

    if (func_01B04800(D_01B08948, D_01B0898C) == 1 && s0->wEDC == 1) {
        func_001CDDD8(D_01B08940);
    }
}
