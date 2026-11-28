#include "common.h"
#include "vu0.h"

extern s32 D_01B0BC8C;
extern u8 *D_01B0BC98;

extern void func_01B049D0(s32, void *, s32);
extern s32 func_01B05100(void *);
extern float func_01B04E20(s32);
extern void func_01B08020(void *, void *, void *);
extern void func_01B05C40(s32, void *);
extern void func_01B061C0(s32, void *, void *);
extern void func_01B08128(void *, void *, void *);
extern void func_01B01718(void);
extern void func_01B01968(void);

void func_01B015F8(void) {
    float sp0[4];
    float sp10[4];
    float sp20[4];
    u8 *s1 = D_01B0BC98;
    u8 *s3 = s1 + 0x2B20;
    u8 *s0;

    func_01B049D0(-1, sp0, 0);
    MMI_COPY_LQ_A3(s3, sp0);
    MMI_COPY_SQ_A3(s3);
    s0 = s1 + 0x2B30;
    *(float *)(s1 + 0x2B34) = func_01B04E20(func_01B05100(s0));
    func_01B08020(sp10, sp0, s0);
    sp10[0] = 0.0f;
    MMI_COPY_LQ_A3(s1 + 0x2B00, sp10);
    MMI_COPY_SQ_A3(s1 + 0x2B00);
    MMI_COPY_LQ_A3(s1 + 0x2B10, sp0);
    MMI_COPY_SQ_A3(s1 + 0x2B10);
    func_01B05C40(-1, s1 + 0x2AC0);
    func_01B061C0(-1, s1 + 0x2AC0, sp10);

    *(float *)(s1 + 0x3BF4) = sp10[1];
    sp20[0] = 0.0f;
    sp20[1] = 0.0f;
    sp20[2] = -60.0f;
    sp20[3] = 1.0f;
    MMI_COPY_LQ_A3(s1 + 0x2B50, s3);
    MMI_COPY_SQ_A3(s1 + 0x2B50);
    func_01B08128(sp10, s1 + 0x2B50, sp20);

    *(void **)(s1 + 0x3BF0) = 0;
    *(s32 *)(s1 + 0x3BF8) = 0;
    D_01B0BC8C = 1;
    func_01B01718();
    func_01B01968();
}
