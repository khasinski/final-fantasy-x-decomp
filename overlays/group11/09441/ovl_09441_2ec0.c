#include "common.h"

extern u8 *func_001E4F58(s32, s32 *);
extern s32 func_01B030D8(s32);
extern s32 func_001E4E08(s32);

void func_01B02EC0(u8 *a0) {
    s32 n;
    u8 *list;
    u8 self;
    s32 done = 1;
    s32 i;

    list = func_001E4F58(9, &n);
    self = func_01B030D8(-1);
    for (i = 0; i < n; i++) {
        u8 c = list[i];
        if (c != self && func_001E4E08(c) != 0) {
            done = 0;
        }
    }
    if (done == 1) {
        a0[0x56] = 1;
    }
}
