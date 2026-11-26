#include "iopsound.h"

extern u8 D_0193B1;

s32 func_010754(s32 *arg) {
    D_0193B1 = (u8)*arg;
    return *arg;
}
