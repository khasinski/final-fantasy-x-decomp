#include "common.h"

extern u8 D_01B0BB70[];
extern u8 *D_01B0BC98;

void func_01B07010(void *a0);
void func_01B07760(void *a0, void *a1);

void func_01B04078(void)
{
    u8 *s1 = D_01B0BC98;

    if (*(void **)(s1 + 0x3BF0) != 0) {
        func_01B07010(*(void **)(s1 + 0x3BF0));
        *(void **)(s1 + 0x3BF0) = 0;
    }
    func_01B07760(D_01B0BB70, s1 + 0x5F0);
    func_01B07760(D_01B0BB70, s1 + 0x980);
}
