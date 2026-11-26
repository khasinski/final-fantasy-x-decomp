#include "iopsound.h"

typedef struct {
    s32 val;
    s32 delta;
    s32 cnt;
} FadeParam;

extern s32 D_019328;
extern FadeParam D_122440;

void func_009298(s32 time, s32 target) {
    s32 val;
    FadeParam *p;

    val = target << 12;
    val |= 0x800;

    if (D_019328 != 120) {
        time *= 60;
        time /= 50;
    }

    p = &D_122440;
    val -= p->val;
    p->delta = val / time;
    p->cnt = time;
}
