#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x720];
    float v720[4];
    float v730[4];
    u8 pad740[0x10];
    float v750[4];
    float v760[4];
    u8 pad770[0x30];
    float v7A0[4];
    u8 pad7B0[0x1A0];
    s32 w950;
    s32 w954;
    s32 w958;
    u8 pad95C[0x10];
    s32 w96C;
    s32 w970;
    s32 w974;
    s32 w978;
} State9492_13C0;

#define COPY_VEC4(dst, src) do { \
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory"); \
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory"); \
} while (0)

#define COPY_VEC4_BOTH(dst, src) do { \
    MMI_COPY_LQ_A3(dst, src); \
    MMI_COPY_SQ_A3(dst); \
} while (0)

extern float D_01B004C0[][4];
extern float D_01B004F0[][4];
extern float D_01B00520[][4];
extern float D_01B00530[][4];

extern float func_01B02908(int);
extern void func_01B02A30(int, float *, int);
extern void func_01B06080(float *, float *, float *);
extern void func_01B06188(float *, float *, float *);
extern float func_01B06358(float, float);

void func_01B013C0(State9492_13C0 *s2)
{
    float v0[4];
    float v1[4];
    float v2[4];
    float v3[4];
    float v4[4];
    float v5[4];
    float *p3;
    float *p4;
    float *pv1;

    if (s2->w96C != -2) {
        p3 = D_01B004C0[s2->w96C];
        p4 = D_01B004F0[s2->w96C];
    } else {
        p3 = D_01B00520[s2->w970];
        p4 = D_01B00530[s2->w970];
        v3[0] = 0.0f;
        v3[1] = func_01B02908(0);
        v3[2] = 0.0f;
        v3[3] = 0.0f;
        func_01B02A30(0, v4, 0);
        func_01B06188(v3, v4, p3);
        p3 = v4;
        func_01B02A30(0, v5, 0);
        func_01B06188(v3, v5, p4);
        p4 = v5;
    }

    pv1 = v1;
    if (s2->w978 != 0 && (s2->w954 & 1) == 0) {
        COPY_VEC4(pv1, p4);
    } else {
        COPY_VEC4(pv1, p3);
    }

    COPY_VEC4(v0, s2->v7A0);
    {
        /* DEBT(FAKE): scheduling/regalloc tie */
        register float one __asm__("$f20") = 1.0f;
        register float *a0 __asm__("$4") = v3;
        register float *a2 __asm__("$6") = pv1;
        register float *a1 __asm__("$5") = v0;
        __asm__("" : "+f"(one), "+r"(a0), "+r"(a2), "+r"(a1));
        v1[3] = one;
        func_01B06080(a0, a1, a2);
        v3[0] = 0.0f;
        {
            register float *p760 __asm__("$4") = s2->v760;
            register float *pv2 __asm__("$3") = v2;
            register float half __asm__("$f3") = 0.5f;
            register float f1 __asm__("$f1");
            register float f2 __asm__("$f2");
            __asm__("" : "+r"(p760));
            v3[2] = 0.0f;
            __asm__("" : "+r"(pv2));
            f1 = p3[0];
            v2[0] = f1 + (p4[0] - f1) * half;
            f2 = p3[1];
            v2[1] = f2 + (p4[1] - f2) * half;
            f1 = p3[2];
            v2[2] = f1 + (p4[2] - f1) * half;
            v2[3] = one;
            COPY_VEC4_BOTH(p760, pv2);
        }
    }
    COPY_VEC4_BOTH(s2->v750, pv1);

    s2->v720[0] = 0.0f;
    s2->v720[1] = func_01B02908(-1);
    __asm__ volatile("" : : : "memory");
    {
        register float *p730 __asm__("$2") = s2->v730;
        __asm__("" : "+r"(p730));
        s2->v720[2] = 0.0f;
        s2->v720[3] = 0.0f;
        COPY_VEC4_BOTH(p730, v3);
    }

    func_01B02A30(0, pv1, 0);
    func_01B06080(v3, v0, pv1);
    if (s2->v730[1] <= func_01B06358(s2->v730[1], v3[1])) {
        s2->w950 = 0;
    } else {
        s2->w950 = 1;
    }
}
