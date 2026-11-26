#include "iopsound.h"

extern volatile s32 D_05A11C;
extern s32 D_05AA60[];
extern s32 D_0193A8;
extern void func_000CD0(void);

s32 func_00F188(void) {
    u32 sysclock[2];
    s32 count;
    u32 start;
    s32 diff;

    count = 1;
    imp_thbase_34(sysclock);
    start = sysclock[0] >> 1;
    if (D_05A11C != 0) {
        sysclock[0] >>= 8;
        if ((s32)sysclock[0] < D_05A11C) {
            sysclock[0] += 0x01000000;
        }
        count = (s32)(sysclock[0] - D_05A11C) / 600;
    }
    D_05A11C = sysclock[0];
    do {
        func_000CD0();
        count--;
    } while (count > 0);
    imp_thbase_34(sysclock);
    diff = (s32)(start - (sysclock[0] >> 1));
    D_05AA60[3] = D_05AA60[2];
    D_05AA60[2] = D_05AA60[1];
    D_05AA60[1] = D_05AA60[0];
    if (diff <= 0) {
        diff = -diff;
    }
    D_05AA60[0] = diff * 2;
    D_0193A8 = D_05AA60[0] + D_05AA60[1] + D_05AA60[2] + D_05AA60[3];
    return 153600;
}
