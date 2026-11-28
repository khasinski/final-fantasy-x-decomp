#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

extern u8 *D_01B0C888;
extern u8 D_01B0C700[];

extern s32 func_01B07E80(void *, void *, s32, s32, s32, s32, float);
extern void func_01B067D0(s32, void *);
extern void func_01B06D50(s32, void *, void *);

void func_01B03F70(void) {
    u8 *s = D_01B0C888;
    u8 *obj = s + 0x260;
    register u8 *p8d0 __asm__("$18");

    func_01B07E80(D_01B0C700, obj, 2, 0, 0, 0, 0.2f);
    copy_vec(s + 0x330, s + 0x9F0);
    *(float *)(obj + 0xC4) = *(float *)(s + 0x8608);
    *(float *)(obj + 0xD4) -= 120.0f;

    copy_vec(s + 0x980, s + 0x9F0);
    *(float *)(s + 0x984) -= 100.0f;

    p8d0 = s + 0x8D0;
    func_01B067D0(1, p8d0);
    copy_vec(s + 0x990, s + 0x970);
    copy_vec(s + 0x9A0, s + 0x980);
    func_01B06D50(1, p8d0, s + 0x990);
    copy_vec(s + 0x900, s + 0x9A0);
}
