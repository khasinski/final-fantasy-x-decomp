#include "iopsound.h"

extern s32 D_019378;
extern s32 D_019310;

s32 func_0111B4(s32 *arg) {
    D_019310 = *arg;
    imp_thsemap_7(D_019378);
    return *arg;
}
