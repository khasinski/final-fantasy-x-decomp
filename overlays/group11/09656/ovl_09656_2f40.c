#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

extern u8 *D_01B0A988;
extern s32 D_01B00B50[];
extern u8 D_01B0A860[];
extern u8 D_01B0A968[];

extern void func_01B037C8(s32, float *, s32);
extern float func_01B036A0(s32);
extern s32 func_001ACEA0(void);
extern float func_002B3DB0(float);
extern s32 func_01B060E8(void *, void *, s32, s32, s32, s32, float);
extern void func_01B066A8(void);
extern s32 func_01B03578(s32);
extern void func_01B04A38(s32, s32);
extern void func_01B05508(void *, s32);
extern void func_01B045D0(s32);

void func_01B02F40(void) {
    float v[4];
    u8 *base = D_01B0A988;
    u8 *obj = base + 0xBE0;
    s32 i;

    for (i = 0; i < D_01B00B50[1]; i++) {
        float y;
        s32 delay;
        s32 j;

        func_01B037C8(i, v, 5);
        y = func_01B036A0(i);
        delay = func_001ACEA0() % 5;

        for (j = 0; j < 3; j++) {
            float spd = (func_002B3DB0(0.2f) + 1.0f) * 0.2f;
            func_01B060E8(D_01B0A860, obj, 9, delay, 0, 0, spd);
            copy_vec(obj + 0xD0, v);
            *(float *)(obj + 0xE0) = func_002B3DB0(20.0f);
            *(float *)(obj + 0xE4) = func_002B3DB0(20.0f);
            *(float *)(obj + 0xE8) = func_002B3DB0(10.0f);
            *(float *)(obj + 0xC4) = y;
            if (j == 2) {
                *(void **)(obj + 0x100) = (void *)func_01B066A8;
                *(s32 *)(obj + 0x120) = func_01B03578(i);
            }
            delay += (func_001ACEA0() % 10) + 5;
            obj += 0x130;
        }
    }

    func_01B04A38(-1, 0);
    func_01B05508(D_01B0A968, 0);
    func_01B045D0(1);
}
