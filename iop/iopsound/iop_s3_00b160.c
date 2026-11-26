#include "iopsound.h"

extern volatile u32 D_05A050;
extern volatile s32 D_018718;

extern void func_00FDF4(s32, void *, s32);

s32 func_00B160(s32 ch) {
    func_00FDF4(ch, NULL, 0);
    D_05A050 &= ~(1 << ch);
    if (D_05A050 == 0) {
        D_018718++;
    }
    return D_018718;
}
