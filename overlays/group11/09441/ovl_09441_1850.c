#include "common.h"

extern u8 D_01B09328[];
extern u8 D_01B09388[];
extern u8 *D_01B093A8;

int func_01B08B48(void *a0);
int func_0011ABB8(void);
int func_01B04DC8(void *a0);
void func_01B01A80(void);
void func_01B05968(void *a0);

void func_01B01850(void *a0)
{
    u8 *s1 = D_01B093A8;
    int s0 = func_01B08B48(D_01B09328);

    if (func_0011ABB8() == 0) {
        int r = func_01B04DC8(D_01B09388);
        if (s0 != 0 && r != 0) {
            *(int *)(s1 + 0x2498) = 1;
            func_01B01A80();
            func_01B05968(a0);
        }
    }
}
