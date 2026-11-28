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

extern u8 *D_01B0A478;
extern s32 D_01B0A46C;

extern void func_01B038E0(s32, float *, s32);
extern float func_01B037B8(s32);
extern void func_01B04B50(s32, void *);
extern void func_01B050D0(s32, void *, void *);
extern void func_01B04520(s32, s32);
extern void *func_01B04010(void *);
extern s32 func_001AF358(void);
extern float func_01B03D30(void *);
extern void func_01B046E8(s32);
extern void func_01B01ED0(void);

void func_01B01CB0(void) {
    float v0[4];
    float v1[4];
    u8 *s = D_01B0A478;
    void *p;
    float y;

    func_01B038E0(-1, v0, 0);
    copy_vec(s + 0x9E0, v0);
    v1[0] = 0.0f;
    v1[1] = func_01B037B8(-1);
    v1[2] = 0.0f;
    v1[3] = 0.0f;
    copy_vec(s + 0x9C0, v1);
    copy_vec(s + 0x9D0, v0);

    func_01B04B50(-1, s + 0x980);
    func_01B050D0(-1, s + 0x980, v1);
    func_01B04520(-1, 0);

    p = func_01B04010(s + 0x9F0);
    if (func_001AF358() == 0x18B0046) {
        *(float *)(s + 0x9F4) = *(float *)(s + 0x9E4);
    } else {
        *(float *)(s + 0x9F4) = func_01B03D30(p);
    }
    *(float *)(s + 0x6278) = v1[1];
    func_01B046E8(0);
    func_01B01ED0();
    *(s32 *)(s + 0x6270) = 0;
    *(s32 *)(s + 0x6274) = 0;
    *(s32 *)(s + 0x628C) = 0;
    D_01B0A46C = 1;
}
