#include "iopsound.h"

extern volatile s32 D_018718;

s32 func_00FFCC(s32 *arg) {
    if (arg[0] != 0) {
        s32 target = arg[1];
    loop:
        if (D_018718 != target) {
            imp_thbase_33(1000);
            goto loop;
        }
    }
    return D_018718;
}
