#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

extern u8 *D_01B0A988;
extern void *D_01B0A98C;

extern void func_01B06F20(float *, float *, float *);
extern void func_002DD128(float (*)[4]);
extern void func_002DD3C0(float (*)[4], float (*)[4], float *);
extern void func_002DCF48(float (*)[4], float (*)[4]);
extern void func_00173B90(void *, s32, s32, s32, float (*)[4], float *, float *, s32);

void func_01B013D8(void) {
    float m0[4][4];
    float m1[4][4];
    float v0[4];
    float rot[4];
    float off[4];
    float p0[4];
    float p1[4];
    u8 *s3 = D_01B0A988;
    float ang;

    off[0] = 31.433401f;
    off[1] = 0.0f;
    off[2] = 0.418806f;
    off[3] = 1.0f;

    rot[0] = 0.0f;
    ang = *(float *)(s3 + 0x2B04) - 1.2217306f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    rot[1] = ang;
    rot[2] = 0.0f;
    rot[3] = 0.0f;

    copy_vec(v0, s3 + 0x2B10);
    func_01B06F20(rot, v0, off);

    ang = *(float *)(s3 + 0x2B04) - 1.7453293f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    rot[1] = ang;

    func_002DD128(m0);
    func_002DD3C0(m0, m0, rot);
    {
        float scale = 0.1f;
        register float *dst __asm__("$2") = m0[3];
        s32 sc;
        __asm__("mfc1 %0, %1" : "=r"(sc) : "f"(scale), "r"(dst));
        VU0_LQC2(1, 0, v0);
        VU0_QMTC2(2, sc);
        VU0_OP("vmulx.xyz $vf1, $vf1, $vf2");
        VU0_SQC2(1, 0, dst);
    }
    func_002DCF48(m1, m0);

    p0[0] = -4.9f;
    p0[1] = 0.0f;
    p0[2] = -4.9f;
    p0[3] = 1.0f;
    p1[0] = 4.8f;
    p1[1] = 0.0f;
    p1[2] = 4.8f;
    p1[3] = 1.0f;
    func_00173B90(D_01B0A98C, 0x80000, 0, 0, m1, p0, p1, 1);

    {
        register u8 *d0 __asm__("$3") = s3 + 0x2B80;
        MMI_COPY_LQ_A3(d0, p0);
        MMI_COPY_SQ_A3(d0);
    }
    {
        register u8 *d1 __asm__("$2") = s3 + 0x2B90;
        MMI_COPY_LQ_A3(d1, p1);
        MMI_COPY_SQ_A3(d1);
    }
}
