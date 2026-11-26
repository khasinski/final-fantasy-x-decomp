#include "iopsound.h"

extern volatile s32 D_05A150;
extern s32 D_05A158[];
extern s32 D_05A1D8;
extern void func_010028(void *, s32, s32, s32);

void func_00EFEC(void) {
    if (D_05A150 != 0) {
        D_05A150 = 0;
        func_010028(D_05A158, D_05A1D8, 64, 0);
    }
}
