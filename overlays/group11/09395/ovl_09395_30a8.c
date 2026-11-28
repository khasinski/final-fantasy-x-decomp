#include "common.h"

extern u8 *D_01B00F54;
extern s32 D_01B00F58;
extern s32 D_01B00F60[];

extern void func_001C69C8(u32, s32, s32);

s32 func_01B030A8(s32 a0) {
    if (a0 > D_01B00F58 - 1) {
        return 1;
    }
    if (D_01B00F60[a0] == 0) {
        return 1;
    }
    func_001C69C8(D_01B00F54[a0], 5, 1);
    return 1;
}
