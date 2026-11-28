#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

extern u8 *D_01B0A480;

extern void func_01B06F08(void *a0, void *a1, void *a2);
extern void func_01B04A20(s32 a0, void *a1);
extern void func_01B04FA0(s32 a0, void *a1, void *a2);
extern void func_01B044E8(s32 a0, s32 a1);

void func_01B03098(void) {
    float v0[4];
    float v1[4];
    u8 *s = D_01B0A480;
    u8 *p_c90;

    v0[0] = 0.0f;
    v0[1] = *(float *)(s + 0xEC8);
    v0[2] = 0.0f;
    v0[3] = 0.0f;
    v1[0] = -20.0f;
    v1[1] = 0.0f;
    v1[2] = -50.0f;
    v1[3] = 1.0f;
    func_01B06F08(v0, s + 0xC60, v1);

    func_01B04A20(1, s + 0xB50);
    p_c90 = s + 0xC90;
    copy_vec(p_c90, s + 0xC50);
    copy_vec(s + 0xCA0, s + 0xC60);
    func_01B04FA0(1, s + 0xB50, p_c90);
}
