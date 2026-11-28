#include "common.h"
#include "vu0.h"

extern u8 D_01B0BF48[];
extern u8 *D_01B0C0B0;
extern u8 D_01B11810[];

extern void func_01B02538(void);
extern void func_01B06478(void *, void *);
extern void func_002DD128(void *);
extern void func_002DD3C0(void *, void *, void *);
extern void func_002DCE38(void *, void *, void *);
extern void *func_002B49A0(void *, s32, s32);
extern void func_01B01840(void *, void *, void *, s32, s32, s32);
extern void func_01B07B38(void *, void *);
extern void func_01B08500(void *, void *, void *);
extern void func_00118098(s32, s32);
extern s32 func_001ACEA0(void);
extern void func_01B06598(s32, void *, void *);
extern void *func_01B07368(void *);
extern void func_01B07530(void *);

void func_01B04200(void) {
    float m0[16];
    float m1[16];
    float m2[16];
    u8 *s2 = D_01B0C0B0;
    float *p = (float *)(s2 + 0x9B4);
    float ang;
    s32 i;

    ang = *p + 0.015707964f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    *p = ang;
    func_01B02538();

    func_01B06478(m1, m2);
    func_002DD128(m0);
    m0[10] = 0.002f;
    m0[5] = 0.002f;
    m0[0] = 0.002f;
    func_002DD3C0(m0, m0, s2 + 0x81D0);
    MMI_COPY_LQ_A3(&m0[12], s2 + 0x81E0);
    MMI_COPY_SQ_A3(&m0[12]);
    func_002DCE38(m0, m2, m0);
    func_002DCE38(m0, m1, m0);

    for (i = 0; i < 20; i++) {
        void *q = func_002B49A0(D_01B11810, 4, i);
        func_01B01840(q, m0, D_01B0C0B0 + 0x9D0 + i * 0x600, 0x50, 0x80, 0x20);
    }
}

void func_01B04380(void) {
    float sp0[4];
    float sp10[4];
    u8 *s1 = D_01B0C0B0;
    void *s0;

    func_01B07B38(D_01B0BF48, s1 + 0x390);
    MMI_COPY_LQ_A3(s1 + 0x81D0, s1 + 0x910);
    MMI_COPY_SQ_A3(s1 + 0x81D0);
    MMI_COPY_LQ_A3(s1 + 0x81E0, s1 + 0x920);
    MMI_COPY_SQ_A3(s1 + 0x81E0);
    sp0[0] = 0.0f;
    sp0[1] = -16.0f;
    sp0[2] = -2.0f;
    func_01B08500(s1 + 0x81D0, s1 + 0x81E0, sp0);

    *(s32 *)(s1 + 0x9C0) = 0;
    *(s32 *)(s1 + 0x9C8) = 0;
    *(float *)(s1 + 0x9B0) = -0.75f;
    *(float *)(s1 + 0x9B4) = 1.0f;
    *(float *)(s1 + 0x9C4) = 0.62831855f;
    func_00118098(0, 0x50000);
    func_00118098(1, 0x50000);

    if (func_001ACEA0() & 1) {
        float ang1;
        float ang2;
        MMI_COPY_LQ_A3(sp10, s1 + 0x910);
        MMI_COPY_SQ_A3(sp10);
        ang1 = sp10[1] - 1.0995574f;
        if (ang1 > 3.1415927f) {
            ang1 -= 6.2831855f;
        } else if (ang1 < -3.1415927f) {
            ang1 += 6.2831855f;
        }
        sp10[1] = ang1;
        func_01B06598(-1, s1 + 0x850, sp10);
        func_01B06598(1, s1 + 0x890, sp10);

        ang2 = *(float *)(s1 + 0x914) - 1.5707964f;
        if (ang2 > 3.1415927f) {
            ang2 -= 6.2831855f;
        } else if (ang2 < -3.1415927f) {
            ang2 += 6.2831855f;
        }
        sp10[1] = ang2;
        sp0[0] = 0.0f;
        sp0[1] = 0.6f;
        sp0[2] = 1.5f;
        func_01B08500(sp10, s1 + 0x920, sp0);
        MMI_COPY_LQ_A3(s1 + 0x940, s1 + 0x920);
        MMI_COPY_SQ_A3(s1 + 0x940);
        *(s32 *)(s1 + 0x85E8) = 1;
    } else {
        *(s32 *)(s1 + 0x85E8) = 0;
    }

    s0 = func_01B07368((void *)func_01B04200);
    func_01B07530(s0);
    *(void **)(s1 + 0x85C0) = s0;
}
