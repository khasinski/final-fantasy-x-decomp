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
    u8 pad7B0[0x1A4];
    s32 w954;
    s32 w958;
    s32 w95C;
    u8 pad960[0x10];
    s32 w970;
    s32 w974;
    s32 w978;
    s32 w97C;
} State9435_1518;

#define COPY_VEC4(dst, src) do { \
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory"); \
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory"); \
} while (0)

#define COPY_VEC4_BOTH(dst, src) do { \
    MMI_COPY_LQ_A3(dst, src); \
    MMI_COPY_SQ_A3(dst); \
} while (0)

extern float D_01B00500[][4];
extern float D_01B005D0[][4];

extern float func_01B02AB0(int);
extern void func_01B02BD8(int, float *, int);
extern void func_01B06228(float *, float *, float *);
extern void func_01B06330(float *, float *, float *);
extern float func_01B06500(float, float);

void func_01B01518(State9435_1518 *s1)
{
    float v0[4];
    float v1[4];
    float v2[4];
    float v3[4];
    float v4[4];
    float *p0;

    if (s1->w970 != -2) {
        p0 = D_01B00500[s1->w970];
    } else {
        p0 = D_01B005D0[s1->w974];
        v3[0] = 0.0f;
        v3[1] = func_01B02AB0(0);
        v3[2] = 0.0f;
        v3[3] = 0.0f;
        func_01B02BD8(0, v0, 0);
        v1[0] = p0[0];
        v1[1] = 0.0f;
        v1[2] = p0[1];
        v1[3] = 1.0f;
        func_01B06330(v3, v0, v1);
        v4[0] = v0[0];
        v4[1] = v0[2];
        func_01B02BD8(0, v0, 0);
        v1[0] = p0[2];
        v1[1] = 0.0f;
        v1[2] = p0[3];
        v1[3] = 1.0f;
        func_01B06330(v3, v0, v1);
        v4[2] = v0[0];
        v4[3] = v0[2];
        p0 = v4;
    }

    if (s1->w97C != 0 && (s1->w958 & 1) == 0) {
        v1[0] = p0[2];
        v1[2] = p0[3];
    } else {
        v1[0] = p0[0];
        v1[2] = p0[1];
    }

    /* DEBT(FAKE): regalloc/scheduling barriers for exact match */
    __asm__("" : "+r"(p0));
    __asm__("" : "+r"(p0));
    __asm__("" : "+r"(p0));
    COPY_VEC4(v0, s1->v7A0);
    {
        register float f0 __asm__("$f0") = v0[1];
        register float *a0 __asm__("$4") = v3;
        register float one __asm__("$f20");
        register float *a2 __asm__("$6");
        register float *a1 __asm__("$5");
        __asm__ volatile("" : "+f"(f0), "+r"(a0));
        one = 1.0f;
        a2 = v1;
        __asm__ volatile("" : "+f"(one), "+r"(a2));
        *(volatile float *)&v1[1] = f0;
        a1 = v0;
        __asm__("" : "+r"(a1) : : "memory");
        v1[3] = one;
        func_01B06228(a0, a1, a2);
        *(volatile float *)&v3[0] = 0.0f;
        {
            register float *p760 __asm__("$4");
            register float *pv2 __asm__("$3");
            register float half __asm__("$f3");
            register float f2 __asm__("$f2");
            register float f1 __asm__("$f1");
            __asm__ volatile("" : : : "memory");
            p760 = s1->v760;
            __asm__ volatile("" : "+r"(p760));
            *(volatile float *)&v3[2] = 0.0f;
            __asm__ volatile("" : : : "memory");
            pv2 = v2;
            __asm__ volatile("" : "+r"(pv2));
            half = 0.5f;
            __asm__ volatile("" : "+f"(half));
            f2 = p0[0];
            v2[0] = f2 + (p0[2] - f2) * half;
            f1 = v0[1];
            v2[1] = f1;
            f1 = p0[1];
            __asm__ volatile("" : "+f"(f1));
            {
                register float p03 __asm__("$f0") = p0[3];
                __asm__ volatile("" : "+f"(p03));
                *(volatile float *)&v2[3] = one;
                __asm__ volatile("" : : : "memory");
                v2[2] = f1 + (p03 - f1) * half;
            }
            COPY_VEC4_BOTH(p760, pv2);
        }
    }
    COPY_VEC4_BOTH(s1->v750, v1);

    s1->v720[0] = 0.0f;
    s1->v720[1] = func_01B02AB0(-1);
    __asm__ volatile("" : : : "memory");
    {
        register float *p730 __asm__("$2") = s1->v730;
        __asm__("" : "+r"(p730));
        s1->v720[2] = 0.0f;
        s1->v720[3] = 0.0f;
        COPY_VEC4_BOTH(p730, v3);
    }

    func_01B02BD8(0, v1, 0);
    func_01B06228(v3, v0, v1);
    if (s1->v730[1] <= func_01B06500(s1->v730[1], v3[1])) {
        s1->w954 = 0;
    } else {
        s1->w954 = 1;
    }
}
