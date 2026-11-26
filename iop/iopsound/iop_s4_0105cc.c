#include "iopsound.h"

extern s32 D_019328;

s32 func_0105CC(s32 *arg) {
    D_019328 = (*arg != 0) ? 100 : 120;
    return *arg;
}
