/* Shared 09128-family VU0 triangle/env-map renderer (1932 B, 10 containers). */
#include "common.h"
#include "vu0.h"

typedef unsigned long u_long64;

typedef union {
    u_long128 q;
    u_long64 d[2];
} Qword;

extern u32 g_pkt_cur;
extern float g_rot_vec[4];

extern void func_002DD128(float *mtx);
extern void func_002DD3C0(float *dst, float *src, float *rot);
extern u32 func_002ECF38(float z);
extern void func_002B2AD8(void *pkt, s32 qwc, u32 z, s32 flag);

static inline s32 div_alpha(s32 x, s32 d)
{
    return x / d;
}

#define LOAD_VTX_POS0(idx, vf_out, dst_out) { \
    register float *_d __asm__("$4") = (dst_out); \
    register u32 _off; \
    register s16 *_p __asm__("$2"); \
    register s32 t2 __asm__("$10"); \
    register s32 a3 __asm__("$7"); \
    register s32 t0 __asm__("$8"); \
    register s32 t1 __asm__("$9"); \
    __asm__ volatile("" : "+r"(_d)); \
    _off = (idx) * stride6; \
    _p = (s16 *)(fp + _off); \
    __asm__ volatile("" : "+r"(_p), "+r"(_d)); \
    t2 = 1; \
    __asm__("" : "+r"(t2) : "r"(_p), "r"(_d)); \
    a3 = _p[0]; \
    __asm__("" : "+r"(a3) : "r"(t2)); \
    t0 = _p[1]; \
    __asm__("" : "+r"(t0) : "r"(a3)); \
    t1 = _p[2]; \
    __asm__("" : "+r"(t1) : "r"(t0)); \
    MMI_OP3("pextlw", a3, t1, a3); \
    MMI_OP3("pextlw", t1, t2, t0); \
    MMI_OP3("pextlw", a3, t1, a3); \
    VU0_QMTC2_NI(31, a3); \
    VU0_OP("vitof0.xyzw $vf31, $vf31"); \
    VU0_OP("vmulax.xyzw ACC, $vf1, $vf31x"); \
    VU0_OP("vmadday.xyzw ACC, $vf2, $vf31y"); \
    VU0_OP("vmaddaz.xyzw ACC, $vf3, $vf31z"); \
    VU0_OP("vmaddw.xyzw $vf30, $vf4, $vf31w"); \
    VU0_OP("vdiv Q, $vf0w, $vf30w"); \
    VU0_OP("vwaitq"); \
    VU0_OP("vmulq.xyz $vf" #vf_out ", $vf30, Q"); \
    VU0_OP("vmulq.w $vf" #vf_out ", $vf0, Q"); \
    VU0_SQC2(vf_out, 0x0, _d); \
}

#define LOAD_VTX_POS(idx, vf_out, dst_out) { \
    register u32 _off __asm__("$2") = (idx) * stride6; \
    register s16 *_p __asm__("$3") = (s16 *)(fp + _off); \
    register float *_d __asm__("$2"); \
    register s32 t2 __asm__("$10"); \
    register s32 a3 __asm__("$7"); \
    register s32 t0 __asm__("$8"); \
    register s32 t1 __asm__("$9"); \
    __asm__ volatile("" : "+r"(_p)); \
    _d = (dst_out); \
    __asm__ volatile("" : "+r"(_p), "+r"(_d)); \
    t2 = 1; \
    __asm__("" : "+r"(t2) : "r"(_p), "r"(_d)); \
    a3 = _p[0]; \
    __asm__("" : "+r"(a3) : "r"(t2)); \
    t0 = _p[1]; \
    __asm__("" : "+r"(t0) : "r"(a3)); \
    t1 = _p[2]; \
    __asm__("" : "+r"(t1) : "r"(t0)); \
    MMI_OP3("pextlw", a3, t1, a3); \
    MMI_OP3("pextlw", t1, t2, t0); \
    MMI_OP3("pextlw", a3, t1, a3); \
    VU0_QMTC2_NI(31, a3); \
    VU0_OP("vitof0.xyzw $vf31, $vf31"); \
    VU0_OP("vmulax.xyzw ACC, $vf1, $vf31x"); \
    VU0_OP("vmadday.xyzw ACC, $vf2, $vf31y"); \
    VU0_OP("vmaddaz.xyzw ACC, $vf3, $vf31z"); \
    VU0_OP("vmaddw.xyzw $vf30, $vf4, $vf31w"); \
    VU0_OP("vdiv Q, $vf0w, $vf30w"); \
    VU0_OP("vwaitq"); \
    VU0_OP("vmulq.xyz $vf" #vf_out ", $vf30, Q"); \
    VU0_OP("vmulq.w $vf" #vf_out ", $vf0, Q"); \
    VU0_SQC2(vf_out, 0x0, _d); \
}

#define LOAD_VTX_UV(ptr, vf_w, dst_pkt, preg) { \
    register s16 *_p __asm__(preg) = (s16 *)(ptr); \
    register s32 t1 __asm__("$9") = 0x1000; \
    register s32 a3 __asm__("$7"); \
    register s32 t0 __asm__("$8"); \
    __asm__("" : "+r"(_p), "+r"(t1)); \
    a3 = _p[0]; \
    __asm__("" : "+r"(a3)); \
    t0 = _p[1]; \
    __asm__("" : "+r"(t0) : "r"(a3)); \
    MMI_OP3("pextlw", a3, t1, a3); \
    MMI_OP3Z("pextlw", t1, t0); \
    MMI_OP3("pextlw", a3, t1, a3); \
    VU0_QMTC2_NI(31, a3); \
    VU0_OP("vitof12.xyzw $vf31, $vf31"); \
    VU0_OP("vmulw.xyz $vf31, $vf31, $vf" #vf_w "w"); \
    VU0_SQC2(31, 0x0, dst_pkt); \
}

#define LOAD_VTX_NORM(ptr, vf_w, n_dst, t3_pkt, preg) { \
    register s16 *_p __asm__(preg) = (s16 *)(ptr); \
    register s32 t2 __asm__("$10"); \
    register s32 a3 __asm__("$7"); \
    register s32 t0 __asm__("$8"); \
    register s32 t1 __asm__("$9"); \
    __asm__ volatile("" : "+r"(_p)); \
    t2 = 0x1000; \
    __asm__("" : "+r"(t2) : "r"(_p)); \
    a3 = _p[0]; \
    __asm__("" : "+r"(a3) : "r"(t2)); \
    t0 = _p[1]; \
    __asm__("" : "+r"(t0) : "r"(a3)); \
    t1 = _p[2]; \
    __asm__("" : "+r"(t1) : "r"(t0)); \
    MMI_OP3("pextlw", a3, t1, a3); \
    MMI_OP3("pextlw", t1, t2, t0); \
    MMI_OP3("pextlw", a3, t1, a3); \
    VU0_QMTC2_NI(18, a3); \
    VU0_OP("vitof12.xyzw $vf18, $vf18"); \
    VU0_OP("vmulax.xyzw ACC, $vf5, $vf18x"); \
    VU0_OP("vmadday.xyzw ACC, $vf6, $vf18y"); \
    VU0_OP("vmaddaz.xyzw ACC, $vf7, $vf18z"); \
    VU0_OP("vmaddw.xyzw $vf31, $vf8, $vf18w"); \
    VU0_SQC2(31, 0x0, n_dst); \
    VU0_OP("vadd.xy $vf31, $vf31, $vf25"); \
    VU0_OP("vmul.xy $vf31, $vf31, $vf19"); \
    VU0_OP("vadd.z $vf31, $vf0, $vf25"); \
    VU0_OP("vmulw.xyz $vf31, $vf31, $vf" #vf_w "w"); \
    VU0_SQC2(31, 0x0, t3_pkt); \
}

void ovl_09128_45b8(u8 *model, void *mtx, u_long64 arg2, s32 alpha_scale_arg, s32 arg4)
{
    register s32 alpha_scale __asm__("$23") = alpha_scale_arg;
    float rot_mtx[16] __attribute__((aligned(16)));
    float vec_one[4] __attribute__((aligned(16)));
    float vec_half[4] __attribute__((aligned(16)));
    float v0_out[4] __attribute__((aligned(16)));
    float v1_out[4] __attribute__((aligned(16)));
    float v2_out[4] __attribute__((aligned(16)));
    float n_out[4] __attribute__((aligned(16)));
    u_long64 tex_mode;
    u8 *fp;
    u8 *s6;
    u8 *s3;
    u8 *s2;
    s32 rem;

    tex_mode = 5;
    if (*(u32 *)model & 4) {
        tex_mode = 0;
    }
    fp = model + *(u32 *)(model + 8);
    s6 = model + *(u32 *)(model + 12);
    {
        register u32 off4 __asm__("$9") = *(u32 *)(model + 4);
        s3 = model + off4;
    }
    s2 = (u8 *)*(volatile u32 *)&g_pkt_cur;

    func_002DD128(rot_mtx);
    func_002DD3C0(rot_mtx, rot_mtx, g_rot_vec);

    vec_one[0] = 1.0f;
    vec_one[1] = 1.0f;
    vec_one[2] = 1.0f;
    vec_one[3] = 0.0f;
    vec_half[0] = 0.5f;
    vec_half[1] = 0.5f;
    vec_half[2] = 0.0f;
    vec_half[3] = 0.0f;

    {
        register u32 c_i __asm__("$7");
        __asm__ volatile("" : : : "memory");
        c_i = 0x437F0000;
        VU0_CTC2_NI(21, c_i);
    }
    {
        register float *p1 __asm__("$3") = vec_one;
        register float *p2 __asm__("$2") = vec_half;
        __asm__ volatile("" : "+r"(p1), "+r"(p2));
        VU0_OP("vsub.xyzw $vf21, $vf0, $vf0");
        VU0_LQC2(25, 0x0, p1);
        VU0_LQC2(19, 0x0, p2);
    }
    {
        register u_long64 c_max __asm__("$7") = 0x4580000045800000ULL;
        VU0_QMTC2_NI(20, c_max);
    }
    VU0_LQC2(5, 0x00, rot_mtx);
    VU0_LQC2(6, 0x10, rot_mtx);
    VU0_LQC2(7, 0x20, rot_mtx);
    VU0_LQC2(8, 0x30, rot_mtx);
    VU0_LQC2(1, 0x00, mtx);
    VU0_LQC2(2, 0x10, mtx);
    VU0_LQC2(3, 0x20, mtx);
    VU0_LQC2(4, 0x30, mtx);

    rem = *(s16 *)(model + 0x10);
    if (rem > 0) {
        do {
            u8 *s0 = s3 + 0x10;
            if (*(s8 *)(s3 + 1) != 3) {
                return;
            }
            {
                register s32 s4 __asm__("$20") = 0;
                if (*(s16 *)(s3 + 2) > 0) {
                    float *p_v2;
                    float *p_v0;
                    float *p_v1;
                    p_v0 = v0_out;
                    p_v1 = v1_out;
                    p_v2 = v2_out;
                    do {
                        u8 *t3 = s2 + 0xE0;
                        u8 *t5 = s2;
                        register s32 s5 __asm__("$21");
                        register u32 stride6 __asm__("$12");
                        Qword *q;

                        s2 += 0x10;
                        q = (Qword *)s2;
                        q->q = 0;
                        q->d[0] = 0xC02DC00000008001ULL;
                        q->d[1] = 0x41241241268EULL;
                        s2 += 0x10;
                        *(u_long64 *)(s2 + 0) = 0x8000000044ULL;
                        *(u_long64 *)(s2 + 8) = 0x42ULL;
                        stride6 = 6;
                        __asm__("" : "+r"(stride6));
                        s2 += 0x10;
                        s5 = 0;
                        __asm__("" : "+r"(stride6) : "r"(s5));
                        *(u_long64 *)(s2 + 0) = tex_mode;
                        s2 += 0x10;
                        *(u_long64 *)(s2 + 0) = ((u_long64)*(u32 *)(s3 + 0xC) << 32) | *(u32 *)(s3 + 0x8);
                        q = (Qword *)t3;
                        q->q = 0;
                        s2 += 0x10;

                        q->d[0] = 0xB02DC00000008001ULL;
                        q->d[1] = 0x04124124126EULL;
                        t3 += 0x10;
                        *(u_long64 *)(t3 + 0) = 0x8000000048ULL;
                        *(u_long64 *)(t3 + 8) = 0x42ULL;
                        t3 += 0x10;
                        *(u_long64 *)(t3 + 0) = arg2;
                        t3 += 0x10;
                        __asm__ volatile("" : "+r"(t3) : : "memory");

                        /* Vertex 0 */
                        LOAD_VTX_POS0(*(u16 *)(s0 + 0x0C), 22, p_v0);
                        LOAD_VTX_UV(s0 + 0x14, 22, s2, "$3");
                        s2 += 0x10;
                        LOAD_VTX_NORM(s6 + *(u16 *)(s0 + 0x20) * stride6, 22, n_out, t3, "$2");
                        {
                            register float zero_f __asm__("$f1") = 0.0f;
                            __asm__("" : "+f"(zero_f));
                            if (n_out[2] > zero_f) {
                                s5 = 1;
                            }
                        }
                        t3 += 0x10;
                        *(u32 *)(s2 + 0) = s0[0];
                        *(u32 *)(s2 + 4) = s0[1];
                        *(u32 *)(s2 + 8) = s0[2];
                        *(s32 *)(s2 + 12) = div_alpha(s0[3] * alpha_scale, 128);
                        MMI_COPY_LQ_A3(t3, s2);
                        MMI_COPY_SQ_A3(t3);
                        t3 += 0x10;
                        s2 += 0x10;
                        VU0_OP("vftoi4.xyzw $vf31, $vf22");
                        VU0_SQC2(31, 0x0, s2);
                        MMI_COPY_LQ_A3(t3, s2);
                        MMI_COPY_SQ_A3(t3);
                        t3 += 0x10;
                        s2 += 0x10;

                        /* Vertex 1 */
                        LOAD_VTX_POS(*(u16 *)(s0 + 0x0E), 23, p_v1);
                        LOAD_VTX_UV(s0 + 0x18, 23, s2, "$2");
                        s2 += 0x10;
                        LOAD_VTX_NORM(s6 + *(u16 *)(s0 + 0x22) * stride6, 23, n_out, t3, "$3");
                        {
                            register float zero_f __asm__("$f1");
                            __asm__("" : "=f"(zero_f));
                            if (n_out[2] > zero_f) {
                                s5 = 1;
                            }
                        }
                        t3 += 0x10;
                        *(u32 *)(s2 + 0) = s0[4];
                        *(u32 *)(s2 + 4) = s0[5];
                        *(u32 *)(s2 + 8) = s0[6];
                        {
                            register s32 d128 __asm__("$3") = 128;
                            *(s32 *)(s2 + 12) = div_alpha(s0[7] * alpha_scale, d128);
                        }
                        MMI_COPY_LQ_A3(t3, s2);
                        MMI_COPY_SQ_A3(t3);
                        t3 += 0x10;
                        s2 += 0x10;
                        VU0_OP("vftoi4.xyzw $vf31, $vf23");
                        VU0_SQC2(31, 0x0, s2);
                        MMI_COPY_LQ_A3(t3, s2);
                        MMI_COPY_SQ_A3(t3);
                        t3 += 0x10;
                        s2 += 0x10;

                        /* Vertex 2 */
                        LOAD_VTX_POS(*(u16 *)(s0 + 0x10), 24, p_v2);
                        LOAD_VTX_UV(s0 + 0x1C, 24, s2, "$2");
                        s2 += 0x10;
                        LOAD_VTX_NORM(s6 + *(u16 *)(s0 + 0x24) * stride6, 24, n_out, t3, "$3");
                        {
                            register float zero_f __asm__("$f1");
                            __asm__("" : "=f"(zero_f));
                            if (n_out[2] > zero_f) {
                                s5 = 1;
                            }
                        }
                        t3 += 0x10;
                        *(u32 *)(s2 + 0) = s0[8];
                        *(u32 *)(s2 + 4) = s0[9];
                        *(u32 *)(s2 + 8) = s0[10];
                        {
                            register s32 d128 __asm__("$3") = 128;
                            *(s32 *)(s2 + 12) = div_alpha(s0[11] * alpha_scale, d128);
                        }
                        MMI_COPY_LQ_A3(t3, s2);
                        MMI_COPY_SQ_A3(t3);
                        t3 += 0x10;
                        s2 += 0x10;
                        VU0_OP("vftoi4.xyzw $vf31, $vf24");
                        VU0_SQC2(31, 0x0, s2);
                        MMI_COPY_LQ_A3(t3, s2);
                        MMI_COPY_SQ_A3(t3);
                        s2 += 0x10;

                        VU0_OP("vnop");
                        VU0_CTC2_NI_ZERO(16);
                        VU0_OP("vsub.xyw $vf30, $vf22, $vf21");
                        VU0_OP("vsub.xy $vf30, $vf20, $vf22");
                        VU0_OP("vsub.xyw $vf30, $vf23, $vf21");
                        VU0_OP("vsub.xy $vf30, $vf20, $vf23");
                        VU0_OP("vsub.xyw $vf30, $vf24, $vf21");
                        VU0_OP("vsub.xy $vf30, $vf20, $vf24");
                        VU0_OP("vnop");
                        VU0_OP("vnop");
                        VU0_OP("vnop");
                        VU0_OP("vnop");
                        VU0_OP("vnop");

                        {
                            register u32 clip __asm__("$7");
                            register u32 masked __asm__("$2");
                            VU0_CFC2_NI(clip, 16);
                            masked = clip & 0xC0;
                            if (masked == 0) {
                                u32 z = func_002ECF38((v0_out[2] + v1_out[2] + v2_out[2]) * (1.0f / 3.0f));
                                s32 qwc = 0x1A;
                                if (arg4 == 1 && s5 != 0) {
                                    qwc = 0x0E;
                                }
                                if (z <= 0x02FFFFFFU) {
                                    func_002B2AD8(t5, qwc, z / 0x3000U, 0);
                                }
                            }
                        }

                        s4++;
                        s2 += 0xC0;
                        s0 += 0x28;
                    } while (({ register s32 _c __asm__("$2") = *(s16 *)(s3 + 2); s4 < _c; }));
                }
            }
            rem -= *(s16 *)(s3 + 2);
            s3 = s0;
        } while (rem > 0);
    }

    g_pkt_cur = (u32)s2;
}
