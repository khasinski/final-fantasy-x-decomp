#include "common.h"
#include "vu0.h"

#define copy_vec_m(dst, src) do { \
    MMI_COPY_LQ_A3(dst, src); \
    MMI_COPY_SQ_A3(dst); \
} while (0)

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

extern u8 *D_01B093A8;
extern u8 D_01B092E0[];

extern void func_01B060B8(void *, void *);
extern s32 func_01B05C48(void *, void *, float, s32, s32, s32, void *);
extern void func_01B061E8(void);
extern void func_01B08C48(void *, s32);

void func_01B02B80(void) {
    u8 *s = D_01B093A8;
    u8 *obj;
    u8 *p;
    register float c04 __asm__("$f20") = 0.04f;

    func_01B060B8(D_01B092E0, s);

    obj = s + 0x130;
    func_01B05C48(D_01B092E0, obj, c04, 1, 0, 0, 0);
    copy_vec(s + 0x200, s + 0x1900);
    *(float *)(obj + 0xC4) = *(float *)(s + 0x2488);
    *(float *)(obj + 0xD4) -= 0.5f;

    obj = s + 0x390;
    func_01B05C48(D_01B092E0, obj, c04, 3, 0, 0, (void *)func_01B061E8);
    copy_vec(s + 0x460, s + 0x1900);
    *(float *)(obj + 0xC4) = *(float *)(s + 0x2488);
    *(float *)(obj + 0xD4) -= 0.5f;

    p = s + 0x1920;
    p[0x82] = 0xFF;
    p[0x81] = 0xFF;
    p[0x80] = 0xFF;
    p[0x83] = 0x80;
    p[0x84] = 0xFF;
    p[0x85] = 0xFF;
    p[0x86] = 0xFF;
    p[0x87] = 0;
    *(s32 *)(p + 0x88) = 0;
    p[0x98] = 0x48;
    p[0x99] = 0;
    func_01B08C48(p, 0x1E);
}
