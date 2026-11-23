#include "common.h"

extern u8 D_01C03DD0;

extern s32 func_002B49A0(void *, s32, s32);
extern void func_00294C78(s32, s32);

void func_01B05C10(void) {
    func_00294C78(func_002B49A0(&D_01C03DD0, 6, 12), 120);
}
