#include "common.h"

extern u32 D_01B092D8;
extern u8 D_01B092E0[];
extern void *D_01B09324;
extern u8 *D_01B093A8;

int func_0011ABB8(void);
int func_01B05D28(void *a0, void *a1);
void func_001CDDD8(u32 a0);

void func_01B018E8(void)
{
    u8 *s0 = D_01B093A8;
    int v1;

    if (func_0011ABB8() == 0) {
        v1 = func_01B05D28(D_01B092E0, D_01B09324);
    } else {
        v1 = 0;
    }
    if (v1 == 1 && *(int *)(s0 + 0x2498) == 1) {
        func_001CDDD8(D_01B092D8);
    }
}
