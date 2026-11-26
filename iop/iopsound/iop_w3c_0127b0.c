#include "iopsound.h"

extern s32 D_06D238;
extern s32 D_06D23C;

s32 func_0127B0(s32 *arg) {
    D_06D23C = *arg;
    imp_thsemap_7(D_06D238);
    return 0;
}
