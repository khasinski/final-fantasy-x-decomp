#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

extern u8 *D_01B0AB88;
extern u8 D_01B0AA08[];
extern u8 D_01B0AA48[];

extern s32 func_01B062B0(void *, void *, s32, s32, s32, s32, float);

void func_01B02738(void) {
    u8 *s = D_01B0AB88;
    u8 *obj;
    float f1840 = *(float *)(s + 0x1840);
    float y;

    obj = s + 0x390;
    func_01B062B0(D_01B0AA08, obj, 0, 0, 0, 0, 0.04f);
    copy_vec(s + 0x460, s + 0x1580);
    *(float *)(obj + 0xC4) = f1840;
    *(float *)(obj + 0xD4) += 65.0f;

    obj = s + 0x5F0;
    func_01B062B0(D_01B0AA48, obj, 0, 0, 0, 0, 0.04f);
    copy_vec(s + 0x6C0, s + 0x1580);
    *(float *)(obj + 0xC4) = f1840;
    *(float *)(obj + 0xD4) += 65.0f;

    *(float *)(s + 0x1848) = 0.0f;
    y = *(float *)(s + 0x1544) + 1.5f;
    *(float *)(s + 0x1544) = y;
    *(float *)(s + 0x14E4) = y;
}
