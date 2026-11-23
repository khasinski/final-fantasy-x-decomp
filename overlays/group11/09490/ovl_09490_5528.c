#include "common.h"

extern s32 func_01B048D0(s32);
extern void func_001148B8(s32);

void func_01B05528(s32 arg0) {
    func_001148B8(func_01B048D0(arg0));
}
