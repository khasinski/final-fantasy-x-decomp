#include "common.h"
#include "vu0.h"

typedef unsigned long u_long64;

typedef struct S0fb8SubA8 {
    s16 h00;
    s16 h02;
    s16 h04;
} S0fb8SubA8;

typedef struct S0fb8Curve {
    s16 h00;
    u8 pad02[6];
    void *p08;
    void *p0C;
} S0fb8Curve;

typedef struct S0fb8Node {
    u8 pad00[0x1E];
    u8 b1E;
    u8 pad1F[0x1D];
    float f3C;
    float f40;
    u8 pad44[4];
    float f48;
    u8 pad4C[0x44];
    float f90;
    float f94;
    float f98;
    u8 pad9C[0x0C];
    S0fb8SubA8 *pA8;
    u8 padAC[4];
    u16 hB0;
    u8 padB2[6];
    s16 hB8;
    u8 padBA[2];
    S0fb8Curve *pBC;
    u8 padC0[8];
    u32 uC8;
} S0fb8Node;

typedef struct S0fb8Obj {
    u16 h00;
    u16 h02;
    u32 u04;
    u_long64 u08;
    void *p10;
    void *p14;
    u32 u18;
    void *p1C;
    u8 pad20[0x20];
    u8 mat40[0x40];
    u8 mat80[0x40];
    u8 matC0[0x40];
    u8 pad100[0x120];
    S0fb8Node *p220;
    u8 pad224[0x9C];
    u8 mat2C0[0x40];
} S0fb8Obj;

typedef struct S0fb8Ctx {
    u8 pad00[0x20];
    S0fb8Node *p20;
    u8 pad24[4];
    float (*p28)[4];
    u8 pad2C[0x28];
    void *p54;
    u8 pad58[8];
    void *p60[1];
} S0fb8Ctx;

typedef struct S0fb8Res {
    u8 pad00[0x10];
    s16 h10;
} S0fb8Res;

S0fb8Node *func_002960D0(S0fb8Ctx *ctx, S0fb8Node *node, s32 idx);
void func_002B5FE8(float *dst, void *p08, void *p0C, s32 h00, float t);
void func_002B57D0(void *mat, float s);
void func_002B5348(void *dst, void *src, void *p30, void *p90);
S0fb8Res *func_002B49A0(void *a0, s32 a1, s32 a2);
void *func_002A48D8(S0fb8Obj *obj, S0fb8Node *node, void *mat40);
void *func_002CD590(void *res, S0fb8Obj *obj);
void func_002B5978(void *p40, void *p90, float f);

void func_01B00FB8(S0fb8Obj *obj_arg, S0fb8Ctx *ctx_arg)
{
    register S0fb8Obj *obj __asm__("$18") = obj_arg;
    register S0fb8Ctx *ctx __asm__("$23") = ctx_arg;
    register S0fb8Node *node __asm__("$19");
    register S0fb8SubA8 *sub __asm__("$21");
    register S0fb8Node *tmp __asm__("$17");
    register S0fb8Curve *curve __asm__("$17");
    s32 count;
    float step;
    float t;
    register s32 i __asm__("$20");
    register float (*pts)[4] __asm__("$16");
    register void *matC0 __asm__("$22");
    register S0fb8Node *node2 __asm__("$17");
    void *p40;
    S0fb8Res *res;
    void *mtx_ret;
    void *res_data;

    node = obj->p220;
    sub = node->pA8;
    if (sub->h00 != 0) {
        tmp = func_002960D0(ctx, node, sub->h00);
    } else {
        tmp = node;
    }

    count = (s32)node->f40;
    i = 0;
    step = 1.0f / node->f48;
    curve = tmp->pBC;
    t = 0.0f;
    pts = ctx->p28;
    if (count > 0) {
        matC0 = obj->matC0;
        do {
            func_002B5FE8(*pts, curve->p08, curve->p0C, curve->h00, t);
            i++;
            pts++;
            t += step;
        } while (i < count);
    } else {
        matC0 = obj->matC0;
    }

    node2 = func_002960D0(ctx, node, node->hB8);
    func_002B57D0(matC0, 1.0f);
    func_002B5348(matC0, matC0, (u8 *)node2 + 0x30, (u8 *)node2 + 0x90);
    node2 = func_002960D0(ctx, node, sub->h04);
    if (node2 == ctx->p20) {
        return;
    }

    i = 0;
    {
        register u32 b1e __asm__("$2") = node->b1E;
        register u8 *p __asm__("$2") = (u8 *)ctx + (b1e << 2);
        __asm__("" : "+r"(p));
        res = func_002B49A0(*(void **)(p + 0x60), 4, sub->h02);
    }
    {
        register void *res_r __asm__("$2") = res;
        register s32 h10 __asm__("$4") = ((S0fb8Res *)res_r)->h10;
        register u16 c128 __asm__("$3") = 128;
        register void *m40_init __asm__("$6");
        register void *rd __asm__("$4");
        __asm__("" : "+r"(h10), "+r"(c128));
        obj->h02 = c128;
        __asm__ volatile("" : : : "memory");
        m40_init = obj->mat40;
        __asm__ volatile("" : "+r"(m40_init));
        rd = (void *)((u32)h10 + (u32)res_r);
        __asm__("" : "+r"(rd));
        res_data = rd;
        {
            register void *a1_tmp __asm__("$5") = node;
            register void *a0_tmp __asm__("$4");
            __asm__ volatile("" : "+r"(a1_tmp));
            a0_tmp = obj;
            __asm__ volatile("" : "+r"(a0_tmp));
            {
                register u32 uc8 __asm__("$2") = node->uC8;
                register void *p54 __asm__("$3") = ctx->p54;
                __asm__ volatile("" : "+r"(uc8), "+r"(p54));
                obj->u08 = 0;
                __asm__ volatile("" : : : "memory");
                obj->u04 = uc8;
                __asm__ volatile("" : : : "memory");
                obj->p10 = m40_init;
                __asm__ volatile("" : : : "memory");
                obj->p14 = p54;
                obj->p1C = m40_init;
            }
            mtx_ret = func_002A48D8(a0_tmp, a1_tmp, m40_init);
        }
    }

    pts = ctx->p28;
    if (count > 0) {
        register void *pos __asm__("$21") = (u8 *)obj + 0xB0;
        p40 = (u8 *)node2 + 0x40;
        do {
            VU0_LQC2(27, 0, pts);
            VU0_LQC2(28, 0, matC0);
            VU0_LQC2(29, 0x10, matC0);
            VU0_LQC2(30, 0x20, matC0);
            VU0_LQC2(31, 0x30, matC0);
            VU0_OP("vmulax.xyzw ACC, $vf28, $vf27x");
            VU0_OP("vmadday.xyzw ACC, $vf29, $vf27y");
            VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf27z");
            VU0_OP("vmaddw.xyzw $vf26, $vf31, $vf0w");
            VU0_SQC2(26, 0, pos);

            if (*(float *)((u8 *)obj + 0xB4) > node->f94) {
                node->hB0 |= 0x1000;
                node2->hB0 |= 0x1000;
                goto after_loop;
            }

            {
                register u32 *m80 __asm__("$4") = (u32 *)obj->mat80;
                register float sc __asm__("$f1") = node->f3C;
                register float c4096 __asm__("$f0") = (1.0f / 4096.0f);
                register u32 sc_bits __asm__("$3");
                register u32 one_bits __asm__("$2");
                __asm__ volatile("" : "+r"(m80), "+f"(sc), "+f"(c4096));
                sc *= c4096;
                MIPS_MFC1(sc_bits, sc);
                one_bits = 0x3F800000;
                __asm__ volatile("" : "+r"(one_bits));
                MMI_SQ_ZERO(0, m80);
                MMI_SQ_ZERO(0x10, m80);
                MMI_SQ_ZERO(0x20, m80);
                MMI_SQ_ZERO(0x30, m80);
                m80[0] = sc_bits;
                __asm__ volatile("" : : : "memory");
                m80[5] = sc_bits;
                __asm__ volatile("" : : : "memory");
                m80[10] = sc_bits;
                __asm__ volatile("" : : : "memory");
                m80[15] = one_bits;

                {
                    register void *mr __asm__("$2") = mtx_ret;
                    __asm__ volatile("" : "+r"(mr));
                    VU0_LQC2(27, 0, pts);
                    VU0_LQC2(28, 0, mr);
                    VU0_LQC2(29, 0x10, mr);
                    VU0_LQC2(30, 0x20, mr);
                    VU0_LQC2(31, 0x30, mr);
                    VU0_OP("vmulax.xyzw ACC, $vf28, $vf27x");
                    VU0_OP("vmadday.xyzw ACC, $vf29, $vf27y");
                    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf27z");
                    VU0_OP("vmaddw.xyzw $vf26, $vf31, $vf0w");
                    VU0_SQC2(26, 0, pos);
                }

                {
                    register void *m40 __asm__("$3");
                    register void *m2C0 __asm__("$2");
                    __asm__ volatile("" : "+r"(obj));
                    m40 = obj->mat40;
                    m2C0 = obj->mat2C0;
                    __asm__ volatile("" : "+r"(m40), "+r"(m2C0));
                    VU0_LQC2(28, 0, m2C0);
                    VU0_LQC2(29, 0x10, m2C0);
                    VU0_LQC2(30, 0x20, m2C0);
                    VU0_LQC2(31, 0x30, m2C0);
                    VU0_LQC2(24, 0, m80);
                    VU0_LQC2(25, 0x10, m80);
                    VU0_LQC2(26, 0x20, m80);
                    VU0_LQC2(27, 0x30, m80);
                    VU0_OP("vmulax.xyzw ACC, $vf28, $vf24x");
                    VU0_OP("vmadday.xyzw ACC, $vf29, $vf24y");
                    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf24z");
                    VU0_OP("vmaddw.xyzw $vf24, $vf31, $vf24w");
                    VU0_OP("vmulax.xyzw ACC, $vf28, $vf25x");
                    VU0_OP("vmadday.xyzw ACC, $vf29, $vf25y");
                    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf25z");
                    VU0_OP("vmaddw.xyzw $vf25, $vf31, $vf25w");
                    VU0_OP("vmulax.xyzw ACC, $vf28, $vf26x");
                    VU0_OP("vmadday.xyzw ACC, $vf29, $vf26y");
                    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf26z");
                    VU0_OP("vmaddw.xyzw $vf26, $vf31, $vf26w");
                    VU0_OP("vmulax.xyzw ACC, $vf28, $vf27x");
                    VU0_OP("vmadday.xyzw ACC, $vf29, $vf27y");
                    VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf27z");
                    VU0_OP("vmaddw.xyzw $vf27, $vf31, $vf27w");
                    VU0_SQC2(24, 0, m40);
                    VU0_SQC2(25, 0x10, m40);
                    VU0_SQC2(26, 0x20, m40);
                    VU0_SQC2(27, 0x30, m40);
                }
            }
            __asm__ volatile("" : : "r"(p40));
            __asm__ volatile("" : : "r"(p40));
            __asm__ volatile("" : : "r"(p40));
            obj->p14 = func_002CD590(res_data, obj);
            i++;
            pts++;
        } while (i < count);
    } else {
        p40 = (u8 *)node2 + 0x40;
    }
    pts--;

after_loop:
    node2->f90 = (*pts)[0];
    node2->f94 = (*pts)[1];
    node2->f98 = (*pts)[2];
    func_002B5978(p40, (u8 *)node2 + 0x90, 16.0f);
    ctx->p54 = obj->p14;
}
