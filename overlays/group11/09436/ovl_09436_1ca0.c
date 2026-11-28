#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

extern u8 *D_01B09358;
extern u8 D_01B09290[];

extern void func_002DD128(float *);
extern void func_01B064F8(float *, float);
extern float func_01B06068(float, float, float, float, float);
extern void func_01B06B70(void *, float *, float *);
extern float func_002B3DB0(float);
extern void func_01B05548(void *, void *, s32, s32, s32, s32, float);

typedef struct {
    float p00[4];
    float p10[4];
    float p20[4];
    float p30[4];
    u8 unk40[0x130];
    u8 unk170[0x228];
    s32 unk398;
    s32 pad39C;
    s32 unk3A0;
    s32 unk3A4;
    u8 pad3A8[0x8];
} Item1CA0;

void func_01B01CA0(void) {
    float mat[16];
    float vec[4];
    u8 *s = D_01B09358;
    Item1CA0 *it;
    s32 i;

    func_002DD128(mat);
    func_01B064F8(mat, 0.06f);

    it = (Item1CA0 *)(s + 0x1220);
    for (i = 0; i < 16; it++, i++) {
        if (it->unk3A0 > 0) {
            float t;
            s32 j;

            it->unk3A0--;
            t = (float)it->unk3A0 / (float)it->unk3A4;
            for (j = 0; j < 3; j++) {
                vec[j] = func_01B06068(it->p30[j], it->p20[j], it->p10[j], it->p00[j], t);
            }
            func_01B06B70(it->unk170, mat, vec);
            if (it->unk3A0 == 0) {
                u8 *obj = it->unk40;
                func_01B05548(D_01B09290, obj, 1, 0, 0, 0, (func_002B3DB0(0.5f) + 1.0f) * 0.3f);
                *(float *)(obj + 0xC4) = *(float *)(s + 0xFB4);
                copy_vec(it->unk40 + 0xD0, it->p30);
                *(float *)(obj + 0xD4) -= 0.5f;
            }
        } else if (it->unk398 > 0) {
            it->unk398 /= 2;
            func_01B06B70(it->unk170, mat, it->p30);
        }
    }
}
