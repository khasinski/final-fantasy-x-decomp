#include "iopsound.h"

extern void func_00CCCC(void *, s32, s32);

extern s32 D_018714;
extern u8 *D_0192F0;

typedef struct {
    u8 pad0[24];
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    u8 pad28[112 - 40];
} StreamSlot;

extern StreamSlot *D_018754;

s32 func_0107CC(s32 *arg) {
    u8 *p;
    u8 *end;

    D_018714 = 1 << *arg;
    p = D_0192F0;
    end = p + 5568;
    do {
        *(s32 *)(p + 104) |= 2;
        p += 116;
    } while (p < end);

    if (D_018754[0].f1C != 0) {
        func_00CCCC(&D_018754[0], D_018754[0].f24, 1);
        if (D_018754[0].f18 & 1) {
            func_00CCCC(&D_018754[0], D_018754[0].f24 + 1, 2);
        }
    }

    if (D_018754[1].f1C != 0) {
        func_00CCCC(&D_018754[1], D_018754[1].f24 | 0x80000000, 1);
        if (D_018754[1].f18 & 1) {
            func_00CCCC(&D_018754[1], (D_018754[1].f24 + 1) | 0x80000000, 2);
        }
    }
    return *arg;
}
