#include "common.h"
#include "vu0.h"

extern s32 D_01B0C064;
extern s32 D_01B0C084;
extern s32 D_01B0C0A4;
extern u8 *D_01B0C0B0;

extern void func_01B04DA8(s32, void *, s32);
extern float func_01B04C80(s32);
extern void func_01B06018(s32, void *);
extern void func_01B06598(s32, void *, void *);
extern void func_01B05B10(s32, s32);
extern void func_01B05A70(s32, s32);
extern void func_01B059E8(s32, s32);
extern void func_01B08500(void *, void *, void *);
extern void func_01B01060(void);

void func_01B036E8(void) {
    float sp0[4];
    float sp10[4];
    float sp20[4];
    u8 *s0 = D_01B0C0B0;

    func_01B04DA8(-1, sp0, 0);
    MMI_COPY_LQ_A3(s0 + 0x970, sp0);
    MMI_COPY_SQ_A3(s0 + 0x970);
    sp10[0] = 0.0f;
    sp10[1] = func_01B04C80(-1);
    sp10[2] = 0.0f;
    sp10[3] = 0.0f;
    MMI_COPY_LQ_A3(s0 + 0x910, sp10);
    MMI_COPY_SQ_A3(s0 + 0x910);
    MMI_COPY_LQ_A3(s0 + 0x920, sp0);
    MMI_COPY_SQ_A3(s0 + 0x920);
    func_01B06018(-1, s0 + 0x850);
    func_01B06598(-1, s0 + 0x850, sp10);
    MMI_COPY_LQ_A3(s0 + 0x880, s0 + 0x920);
    MMI_COPY_SQ_A3(s0 + 0x880);
    func_01B05B10(-1, 1);
    func_01B05A70(-1, 0);
    func_01B059E8(-1, 0);

    *(float *)(s0 + 0x85C8) = sp10[1];
    MMI_COPY_LQ_A3(s0 + 0x980, sp0);
    MMI_COPY_SQ_A3(s0 + 0x980);
    sp20[0] = 0.0f;
    sp20[1] = 0.0f;
    sp20[2] = 15.0f;
    func_01B08500(sp10, s0 + 0x980, sp20);

    MMI_COPY_LQ_A3(s0 + 0x990, sp0);
    MMI_COPY_SQ_A3(s0 + 0x990);
    sp20[0] = 0.0f;
    sp20[1] = 0.0f;
    sp20[2] = 24.0f;
    func_01B08500(sp10, s0 + 0x990, sp20);

    func_01B01060();
    *(s32 *)(s0 + 0x85EC) = 0;
    *(s32 *)(s0 + 0x9CC) = 0;
    *(s32 *)(s0 + 0x9A0) = 0;
    *(s32 *)(s0 + 0x9A4) = 0;
    *(s32 *)(s0 + 0x9A8) = 0;
    *(s32 *)(s0 + 0x9AC) = 0;
    *(s32 *)(s0 + 0x9B0) = 0;
    *(s32 *)(s0 + 0x9B4) = 0;
    *(s32 *)(s0 + 0x9B8) = 0;
    *(s32 *)(s0 + 0x9BC) = 0;
    *(s32 *)(s0 + 0x9C0) = 0;
    *(s32 *)(s0 + 0x9C4) = 0;
    *(float *)(s0 + 0x9C8) = 0.0f;
    *(void **)(s0 + 0x85C4) = 0;
    D_01B0C064 = 1;
    *(void **)(s0 + 0x85C0) = 0;
    D_01B0C084 = 1;
    D_01B0C0A4 = 1;
}
