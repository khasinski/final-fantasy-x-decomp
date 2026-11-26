#include "iopsound.h"

extern void func_00E0A4(void *);

extern u8 *D_018754;

void func_00E308(s32 pan) {
    u8 *p = D_018754 + 112;

    *(s32 *)(p + 92) = (pan + 64) << 12;
    *(s32 *)(p + 100) = 0;
    func_00E0A4(p);
}

void func_00E344(s32 frames, s32 target) {
    u8 *p = D_018754 + 112;
    s32 diff;

    diff = ((target + 64) << 12) - *(s32 *)(p + 92);
    *(s32 *)(p + 100) = frames;
    *(s32 *)(p + 96) = diff / frames;
}
