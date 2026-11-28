#include "common.h"

typedef struct {
    s32 unk0;
    s32 count;
} Cnt1160;

extern u8 *D_01B09358;
extern Cnt1160 D_01B008F8;

extern void func_01B02C28(s32, float *, s32);
extern float func_01B06420(void *, float *);
extern void func_01B06278(float *, float *, float *);

void func_01B01160(void) {
    float v0[4];
    float v1[4];
    float v2[4];
    u8 *s = D_01B09358;
    float best = 10000.0f;
    s32 best_idx = 0;
    s32 i;

    for (i = 0; i < D_01B008F8.count; i++) {
        float d;
        func_01B02C28(i, v0, 0);
        d = func_01B06420(s + 0xF70, v0);
        if (d < best) {
            best = d;
            best_idx = i;
        }
    }

    func_01B02C28(-1, v1, 0);
    func_01B02C28(best_idx, v0, 0);
    func_01B06278(v2, v1, v0);
    *(s32 *)(s + 0x54A4) = best_idx;
    *(float *)(s + 0x54A0) = v2[1];
}
