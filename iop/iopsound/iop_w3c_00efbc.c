#include "iopsound.h"

extern volatile s32 D_05A158[];
extern volatile s32 D_05A150;

void func_00EFBC(s32 idx, s32 val) {
    D_05A158[idx] = val;
    D_05A150++;
}
