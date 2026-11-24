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
    u8 pad978[0x8];
    u8 b980[1];
} State9492_1610;

#define COPY_VEC4(dst, src) do { \
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory"); \
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory"); \
} while (0)

#define COPY_VEC4_B(dst, src) do { \
    MMI_COPY_LQ_A3(dst, src); \
    MMI_COPY_SQ_A3(dst); \
} while (0)

#define ADD7(x) ({ register float _r __asm__("$f0") = (x); register float _s __asm__("$f1") = 7.0f; __asm__("" : "+f"(_s) : "f"(_r)); _r = _r + _s; _r; })
#define F100() ({ float _h = 100.0f; __asm__("" : "+f"(_h)); _h; })
#define SP_OFF(off) ({ register u8 *_sp __asm__("$29"); __asm__("" : "=r"(_sp)); (float *)(_sp + (off)); })

extern void func_01B00FA0(float *, float *, float *);
extern void func_01B013C0(State9492_1610 *);
extern float func_01B02908(int);
extern void func_01B02A30(int, float *, int);
extern float func_01B02DA0(int);
extern void func_01B03DF0(float *);
extern void func_01B06080(float *, float *, float *);
extern void func_01B06188(float *, float *, float *);
extern float func_01B06268(float *, float *);
extern float func_01B06358(float, float);
extern int func_001ACEA0(void);

void func_01B01610(State9492_1610 *s1)
{
    float vec0[4];
    float vec1[4];
    float vec2[4];
    float vec3[4];
    float vec4[4];
    float vec5[4];
    float vec6[4];
    float vec7[4];
    float vec8[4];
    /* DEBT(FAKE): saved register pinning and scheduling barriers for exact match */
    register int s2 __asm__("$18");
    int flag;
    register float *pvec1 __asm__("$22");
    register float *pvec4 __asm__("$20");

    if (s1->w96C != -1) {
        func_01B013C0(s1);
        return;
    }

    if (s1->w954 >= s1->w958) {
        s2 = s1->b980[s1->w954 - 1];
    } else {
        s2 = s1->b980[s1->w954];
    }

    COPY_VEC4(vec0, s1->v7A0);
    pvec1 = vec1;
    func_01B02A30(s2, pvec1, 0);
    pvec4 = vec4;
    func_01B06080(pvec4, vec0, pvec1);
    vec4[0] = 0.0f;
    vec4[2] = 0.0f;

    if (s1->w954 + 1 < s1->w958) {
        int next = s1->b980[s1->w954 + 1];
        if (s2 != next) {
            double diff;
            func_01B02A30(next, vec3, 0);
            func_01B06080(vec5, vec0, vec3);
            vec5[1] = func_01B06358(vec4[1], vec5[1]);
            diff = (double)(vec5[1] - vec4[1]);
            if (diff < 0.0) {
                diff = -diff;
            }
            if (diff < 0.3490658700466156) {
                if (vec4[1] <= vec5[1]) {
                    s1->w950 = 0;
                } else {
                    s1->w950 = 1;
                }
            } else {
                if (vec4[1] <= vec5[1]) {
                    s1->w950 = 1;
                } else {
                    s1->w950 = 0;
                }
            }
        } else if (s1->w954 == 0) {
            int r = func_001ACEA0() & 1;
            __asm__("" : "+r"(r));
            if (r == 0) {
                s1->w950 = 1;
            } else {
                __asm__ volatile("");
                s1->w950 = 0;
            }
        }
    } else if (s1->w954 == 0) {
        if ((func_001ACEA0() & 1) == 0) {
            s1->w950 = 1;
        } else {
            s1->w950 = 0;
        }
    }

    {
        register float *pvec2_0 __asm__("$16") = vec2;
        register float *pvec2 __asm__("$23") = pvec2_0;
        register float *pvec6 __asm__("$19");
        register float *pvec7 __asm__("$21");
        __asm__("" : "+r"(pvec2));
        COPY_VEC4_B(pvec2, pvec1);
        {
            register float d __asm__("$f0") = ADD7(func_01B02DA0(s2));
            if (s1->w950 != 0) {
                d = -d;
            }
            *(volatile float *)&vec6[0] = d;
            {
                register float one __asm__("$f0") = 1.0f;
                __asm__ volatile("" : "+f"(one));
                pvec6 = vec6;
                __asm__ volatile("" : "+r"(pvec6) : "f"(one));
                *(volatile float *)&vec6[1] = 0.0f;
                {
                    register float *a0 __asm__("$4") = pvec4;
                    __asm__("" : "+r"(a0) : : "memory");
                    *(volatile float *)&vec6[3] = one;
                    __asm__ volatile("" : : : "memory");
                    {
                        register float *a1 __asm__("$5") = pvec2;
                        __asm__ volatile("" : "+r"(a1) : : "memory");
                        vec6[2] = 0.0f;
                        __asm__("" : "+r"(pvec6) : : "memory");
                        func_01B06188(a0, a1, pvec6);
                    }
                }
            }
        }

        __asm__ volatile("");
        flag = 0;
        __asm__ volatile("" : "+r"(flag));
        pvec7 = vec7;
        func_01B03DF0(pvec7);
        {
            int w974 = s1->w974;
            int _c1 = 1;
            __asm__("" : "+r"(_c1) : "r"(w974));
            if (w974 == _c1 && func_01B06268(pvec7, pvec2_0) > F100()) {
                register float f20 __asm__("$f20");
                COPY_VEC4(pvec2_0, pvec1);
                {
                    register float d __asm__("$f0") = ADD7(func_01B02DA0(s2));
                    if (s1->w950 == 0) {
                        d = -d;
                    }
                    *(volatile float *)&vec6[0] = d;
                    __asm__ volatile("" : : : "memory");
                    f20 = 1.0f;
                    __asm__("" : "+f"(f20));
                    vec6[1] = 0.0f;
                    vec6[2] = 0.0f;
                    vec6[3] = f20;
                }
                func_01B06188(pvec4, pvec2, SP_OFF(0x60));
                if (func_01B06268(pvec7, pvec2) > 100.0f) {
                    register float dist __asm__("$f2");
                    COPY_VEC4(pvec2_0, pvec1);
                    {
                        register int a0_s2 __asm__("$4") = s2;
                        __asm__("" : "+r"(a0_s2));
                        vec6[0] = 0.0f;
                        vec6[1] = 0.0f;
                        {
                            register float r __asm__("$f0") = func_01B02DA0(a0_s2);
                            register float s7 __asm__("$f1") = 7.0f;
                            register float *a0 __asm__("$4") = SP_OFF(0x40);
                            __asm__("" : "+f"(s7), "+r"(a0) : "f"(r));
                            *(volatile float *)&vec6[3] = f20;
                            {
                                register float *a1 __asm__("$5") = pvec2_0;
                                __asm__("" : "+r"(a1) : "f"(s7) : "memory");
                                r = r + s7;
                                vec6[2] = r;
                                func_01B06188(a0, a1, pvec6);
                            }
                        }
                    }
                    {
                        float *a0 = SP_OFF(0x70);
                        __asm__("" : "+r"(pvec2_0) : "r"(a0));
                        dist = func_01B06268(a0, pvec2_0);
                    }
                    if (dist > 100.0f) {
                        {
                            float *a0 = vec8;
                            float *a1 = vec0;
                            __asm__("" : "+r"(pvec2_0) : "r"(a0), "r"(a1));
                            func_01B00FA0(a0, a1, pvec2_0);
                        }
                        vec2[0] = vec8[0];
                        vec2[2] = vec8[2];
                        vec6[0] = 0.0f;
                        vec6[1] = 0.0f;
                        vec6[2] = 10.0f;
                        vec6[3] = f20;
                        func_01B06188(pvec4, pvec2_0, pvec6);
                        __asm__ volatile("");
                        flag = 1;
                    } else {
                        if (dist > 90.0f) {
                            vec6[0] = 0.0f;
                            vec6[1] = 0.0f;
                            vec6[2] = 10.0f;
                            vec6[3] = f20;
                            func_01B06188(pvec4, pvec2_0, pvec6);
                        }
                        __asm__ volatile("");
                        flag = 1;
                    }
                } else {
                    if (s1->w950 == 0) {
                        s1->w950 = 1;
                    } else {
                        s1->w950 = 0;
                    }
                }
            }
        }

        COPY_VEC4_B(s1->v760, pvec2);
        if (flag == 0) {
            register float f20 __asm__("$f20");
            {
                register float *a0 __asm__("$4") = pvec4;
                register float *a2 __asm__("$6") = pvec2_0;
                __asm__ volatile("" : "+r"(a0), "+r"(a2));
                f20 = 1.0f;
                __asm__ volatile("" : "+f"(f20));
                func_01B06080(a0, vec0, a2);
            }
            {
                register float *p750 __asm__("$18");
                __asm__ volatile("");
                p750 = s1->v750;
                __asm__ volatile("" : "+r"(p750));
                {
                    register float m32 __asm__("$f0") = -32.0f;
                    __asm__ volatile("" : "+f"(m32));
                    {
                        register float *a2 __asm__("$6") = SP_OFF(0x60);
                        __asm__ volatile("" : "+r"(a2));
                        *(volatile float *)&vec6[3] = f20;
                        {
                            register float *a0 __asm__("$4") = pvec4;
                            __asm__ volatile("" : "+r"(a0));
                            *(volatile float *)&vec6[2] = m32;
                            {
                                register float *a1 __asm__("$5") = pvec2_0;
                                __asm__ volatile("" : "+r"(a1));
                                vec4[0] = 0.0f;
                                vec4[2] = 0.0f;
                                vec6[0] = 0.0f;
                                vec6[1] = 0.0f;
                                func_01B06188(a0, a1, a2);
                            }
                        }
                    }
                }
                COPY_VEC4_B(p750, pvec2_0);
                if (s1->w974 == 1) {
                    register float r __asm__("$f0") = func_01B06268(pvec7, pvec2_0);
                    register float h100 __asm__("$f1") = 100.0f;
                    register float dist __asm__("$f2");
                    __asm__("" : "+f"(h100) : "f"(r));
                    dist = r;
                    __asm__("" : "+f"(dist) : "f"(h100));
                    {
                        register float *a0 __asm__("$4");
                        register float *a1 __asm__("$5");
                        register float *a2 __asm__("$6");
                        if (dist > h100) {
                            func_01B00FA0(vec8, vec0, pvec2_0);
                            {
                                register float f2 __asm__("$f2") = vec8[0];
                                register float f1 __asm__("$f1");
                                register float ten __asm__("$f0");
                                a0 = SP_OFF(0x40);
                                __asm__ volatile("" : "+f"(f2), "+r"(a0));
                                f1 = vec8[2];
                                __asm__ volatile("" : "+f"(f1));
                                a1 = p750;
                                __asm__ volatile("" : "+r"(a1));
                                ten = 10.0f;
                                __asm__ volatile("" : "+f"(ten));
                                a2 = pvec6;
                                __asm__ volatile("" : "+r"(a2));
                                s1->v750[0] = f2;
                                s1->v750[2] = f1;
                                vec6[2] = ten;
                                vec6[3] = f20;
                                goto do_6188;
                            }
                        } else {
                            a0 = SP_OFF(0x40);
                            if (dist > 90.0f) {
                                register float ten __asm__("$f0");
                                __asm__("" : "+r"(a0));
                                ten = 10.0f;
                                __asm__ volatile("" : "+f"(ten));
                                *(volatile float *)&vec6[3] = f20;
                                __asm__ volatile("" : : : "memory");
                                a1 = p750;
                                __asm__ volatile("" : "+r"(a1) : : "memory");
                                *(volatile float *)&vec6[2] = ten;
                                __asm__ volatile("" : : : "memory");
                                a2 = pvec6;
                                __asm__ volatile("" : "+r"(a2) : : "memory");
                            do_6188:
                                vec6[0] = 0.0f;
                                vec6[1] = 0.0f;
                                func_01B06188(a0, a1, a2);
                            }
                        }
                    }
                }
            }
        } else {
            COPY_VEC4_B(s1->v750, pvec2_0);
        }
    }

    s1->v720[0] = 0.0f;
    s1->v720[1] = func_01B02908(-1);
    __asm__ volatile("" : : : "memory");
    {
        register float *p730 __asm__("$2") = s1->v730;
        __asm__("" : "+r"(p730));
        *(volatile float *)&s1->v720[2] = 0.0f;
        __asm__ volatile("" : : : "memory");
        s1->v720[3] = 0.0f;
        COPY_VEC4_B(p730, pvec4);
    }
}
