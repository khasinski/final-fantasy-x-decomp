#include "common.h"

extern s32 func_01B048D0(s32);
extern float func_001109E0(s32);
extern float func_001107D0(s32);

float func_01B04DF8(s32 arg0) {
    s32 x = func_01B048D0(arg0);

    return func_001109E0(x) * func_001107D0(x);
}
