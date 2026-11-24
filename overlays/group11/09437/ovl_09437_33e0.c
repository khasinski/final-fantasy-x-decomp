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

typedef struct {
    u8 pad00[0xC0];
    float rot[3];
    u8 padCC[0x4];
    Vec4 pos;
    u8 padE0[0x50];
} OvlObj; /* size 0x130 */

typedef struct {
    OvlObj obj[22]; /* 0x0000..0x1A20 */
    u8 pad1A20[0x170];
    Vec4 v1B90;     /* 0x1B90 */
    Vec4 v1BA0;     /* 0x1BA0 */
    u8 pad1BB0[0x60];
    Vec4 v1C10;     /* 0x1C10 */
    u8 pad1C20[0x10];
    Vec4 v1C30;     /* 0x1C30 */
    u8 pad1C40[0x1D0];
    u8 f1E10[0x100];/* 0x1E10 */
    float f1F10;    /* 0x1F10 */
    u8 pad1F14[0x18];
    s32 w1F2C;      /* 0x1F2C */
} Ovl09437Work;

extern Ovl09437Work *D_01B0A5F0;
extern u8 D_01B0A508[];

extern s32 func_01B063E8(void *, void *, s32, s32, s32, void *, float);
extern void func_01B09C50(void *, s32, s32, float, float);

void func_01B033E0(void) {
    Ovl09437Work *w = D_01B0A5F0;
    OvlObj *o;

    copy_vec(&w->v1BA0, &w->v1C10);
    o = &w->obj[9];
    func_01B063E8(D_01B0A508, o, 9, 96, 0, 0, 0.016f);
    copy_vec(&o->pos, &w->v1C10);
    o->rot[1] = w->f1F10;
    func_01B09C50(w->f1E10, 30, 60, 0.5f, 1.0f);
}

void func_01B03488(void) {
    Ovl09437Work *w = D_01B0A5F0;

    copy_vec(&w->v1C30, &w->v1BA0);
    w->v1C30.y = w->v1C10.y - 100.0f;
    wrap_angle(&w->v1B90.x, 3.1415927f);
    w->w1F2C = 20;
}
