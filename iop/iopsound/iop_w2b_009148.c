#include "iopsound.h"

typedef struct {
    s32 val;
    s32 delta;
    s32 cnt;
} FadeParam;

extern s32 D_019328;
extern FadeParam D_122450;

void func_009148(s32 time, s32 target) {
    s32 val;
    FadeParam *p;

    val = target << 8;
    if (val > 0) {
        val += 0xff;
    }
    val <<= 12;
    val |= 0x800;

    if (D_019328 != 120) {
        time *= 60;
        time /= 50;
    }

    p = &D_122450;
    val -= p->val;
    p->delta = val / time;
    p->cnt = time;
}
