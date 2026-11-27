#include "common.h"

extern u8 *D_01B0BC74;
extern u8 *D_01B0BD58;
extern u8 D_01B0BC30[];
extern int D_01B0BC28;

extern int func_01B07728(void *, void *);
extern void func_001CDDD8(int);

void func_01B02140(void)
{
    u8 *st = D_01B0BD58;

    if (func_01B07728(D_01B0BC30, D_01B0BC74) == 1 && *(int *)(st + 0x62B0) == 1) {
        func_001CDDD8(D_01B0BC28);
    }
}
