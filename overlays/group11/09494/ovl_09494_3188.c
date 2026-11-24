#include "common.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

static inline void wrap_angle(float *p, float d) {
    float a = *p + d;
    if (a > 3.1415927f) {
        a -= 6.2831855f;
    } else if (a < -3.1415927f) {
        a += 6.2831855f;
    }
    *p = a;
}

static inline void lerp_vec(Vec4 *dst, Vec4 *a, Vec4 *b, float t) {
    Vec4 tmp;
    float *pt = &tmp.x;
    float *pb = &b->x;
    float *pa = &a->x;
    float s = 1.0f - t;
    s32 i;
    for (i = 2; i >= 0; i--) {
        *pt++ = *pa++ * s + *pb++ * t;
    }
    tmp.w = 1.0f;
    copy_vec(dst, &tmp);
}

typedef struct {
    u8 pad00[0x1B50];
    u8 f1B50[0x40]; /* 0x1B50 */
    Vec4 v1B90;     /* 0x1B90 */
    Vec4 v1BA0;     /* 0x1BA0 */
    u8 pad1BB0[0x60];
    Vec4 v1C10;     /* 0x1C10 */
    u8 pad1C20[0x10];
    Vec4 v1C30;     /* 0x1C30 */
    u8 pad1C40[0x1D0];
    u8 f1E10[0x100];/* 0x1E10 */
    u8 pad1F10[0x18];
    s32 w1F28;      /* 0x1F28 */
} Ovl09494Work;

extern Ovl09494Work *D_01B0A310;
extern u8 D_01B00768[];
extern u8 D_01B00790[];

extern void func_01B04FD8(s32, void *, void *);
extern void func_01B09970(void *, s32, s32, float, float);
extern float func_01B06CE8(void *, s32, s32, float);
extern float func_01B07210(void *, s32, s32, float);

void func_01B03188(void) {
    Ovl09494Work *w = D_01B0A310;

    copy_vec(&w->v1BA0, &w->v1C10);
    func_01B09970(w->f1E10, 30, 60, 0.5f, 1.0f);
}

void func_01B031C0(void) {
    Ovl09494Work *w = D_01B0A310;

    copy_vec(&w->v1C30, &w->v1BA0);
    w->v1C30.y = w->v1C10.y - 80.0f;
    wrap_angle(&w->v1B90.x, 3.1415927f);
    w->w1F28 = 60;
}

void func_01B03260(void) {
    Ovl09494Work *w = D_01B0A310;

    if (w->w1F28 > 0) {
        float t;
        float a;
        w->w1F28--;
        t = (float)w->w1F28 / 60.0f;
        t = func_01B06CE8(D_01B00768, 8, 1, t * 8.0f);
        lerp_vec(&w->v1BA0, &w->v1C10, &w->v1C30, t);
        a = (float)w->w1F28 / 60.0f;
        a = func_01B07210(D_01B00790, 12, 1, a * 12.0f);
        if (a > 3.1415927f) {
            a -= 6.2831855f;
        } else if (a < -3.1415927f) {
            a += 6.2831855f;
        }
        w->v1B90.x = a;
        func_01B04FD8(-1, w->f1B50, &w->v1B90);
        if (w->w1F28 == 0) {
            func_01B09970(w->f1E10, 30, 0, 0.5f, 1.0f);
        }
    }
}
