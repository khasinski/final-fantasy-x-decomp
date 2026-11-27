#include "common.h"

extern u32 D_01B09288;
extern u8 D_01B09290[];
extern void *D_01B092D4;
extern u32 D_01B0934C;
extern u8 *D_01B09358;

int func_01B05628(void *a0, void *a1);
void func_001CDDD8(u32 a0);
int func_01B029D8(int a0);
int func_001BBCF8(u32 a0, int a1);
void func_01B03F38(int a0, int a1, int a2);

void func_01B01078(void)
{
    u8 *s0 = D_01B09358;

    if (func_01B05628(D_01B09290, D_01B092D4) == 1) {
        if (*(int *)(s0 + 0x54C8) == 1) {
            func_001CDDD8(D_01B09288);
        }
    }
}

void func_01B010E0(void)
{
    u8 *s1 = D_01B09358;

    *(int *)(s1 + 0x54C0) = func_001BBCF8(D_01B09288, func_01B029D8(0));
    func_01B03F38(*(int *)(s1 + 0x54A4), 10, 4);
    *(int *)(s1 + 0x54C8) = 0;
    *(int *)(s1 + 0x54BC) = -1;
    D_01B0934C = 1;
}
