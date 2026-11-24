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
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    Vec4 pos;
    u8 padE0[0x50];
} OvlObj; /* size 0x130 */

typedef struct {
    s32 w00;
    s32 w04;
    s32 w08;
    s32 w0C;
} OvlSubBFC;

typedef struct {
    u8 pad00[0x4];
    float f04;
    float f08;
    s32 w0C;
    float f10;
    float f14;
    s32 w18;
    u8 pad1C[0x8];
    s32 w24;
    u8 pad28[0x4];
    u16 h2C;
} OvlSubC18;

typedef struct {
    OvlObj obj[8]; /* 0x000..0x980 */
    u8 f980[0x40]; /* 0x980 */
    Vec4 v9C0;     /* 0x9C0 */
    u8 pad9D0[0x30];
    Vec4 vA00;     /* 0xA00 */
    u8 padA10[0x30];
    Vec4 vA40;     /* 0xA40 */
    Vec4 vA50;     /* 0xA50 */
    Vec4 vA60;     /* 0xA60 */
    u8 padA70[0x18C];
    OvlSubBFC sBFC;/* 0xBFC */
    u8 padC0C[0xC];
    OvlSubC18 sC18;/* 0xC18 */
    u8 padC48[0x38];
    u8 fC80[0x24C4];/* 0xC80 */
    void *p3144;   /* 0x3144 */
    float f3148;   /* 0x3148 */
    s32 w314C;     /* 0x314C */
} Ovl09631Work;

extern Ovl09631Work *D_01B0A1E0;
extern u8 D_01B0A0B8[];

extern void func_01B05138(s32, void *, void *);
extern void func_002DD128(void *);
extern float func_002B3DB0(float);
extern void func_002DD318(void *, void *, float);
extern float func_002B3DF8(float);
extern void func_002DCE08(void *, void *, void *);
extern float func_01B06D50(float, float, float, float);
extern s32 func_002EFD78(void);
extern void func_00118098(s32, s32);
extern void func_01B05760(void *);
extern void func_01B019A8(void *, s32);
extern void func_01B09E70(void *, s32, s32, float, float);
extern void func_01B057B8(s32);
extern void func_01B05F88(void *);
extern void func_01B066D8(void *, void *);
extern s32 func_01B06268(void *, void *, s32, s32, s32, s32, float);
extern void func_01B09A88(void *, s32);
extern void func_01B09B90(void *, s32);

void func_01B030C0(void) {
    Ovl09631Work *w = D_01B0A1E0;
    float mtx[4][4];
    float vec[4];
    float t;
    float val;
    s32 cnt;

    wrap_angle(&w->vA40.y, 0.031415928f);

    func_01B05138(-1, w->f980, &w->vA40);

    {
        OvlObj *sub = &w->obj[6];
        sub->pos.y += 8.333333f;
        cnt = --w->w314C;
        sub = &w->obj[7];
        sub->pos.y += 8.333333f;
    }
    w->vA50.y += 8.333333f;

    if (cnt == 0) {
        func_002DD128(mtx);
        func_002DD318(mtx, mtx, func_002B3DB0(3.1415927f));
        vec[0] = 0.0f;
        vec[1] = 0.0f;
        vec[2] = func_002B3DF8(10.0f) + 30.0f;
        vec[3] = 1.0f;
        func_002DCE08(vec, mtx, vec);
        w->w314C = 40;
        w->vA00.x = w->vA50.x + vec[0];
        w->vA00.y = w->vA50.y + 50.0f;
        w->vA00.z = w->vA50.z + vec[2];
        w->vA00.w = 20.0f;
    }

    t = (float)w->w314C / 40.0f;
    w->vA00.y = (w->vA50.y - 100.0f) * (1.0f - t) + (w->vA50.y + 100.0f) * t;
    val = func_01B06D50(0.0f, 1.0f, 0.0f, t);
    w->v9C0.z = val;
    w->v9C0.y = val;
    w->v9C0.x = val;

    func_00118098(0, func_002EFD78() % 0x8000);
    func_00118098(1, func_002EFD78() % 0x8000);
}

void func_01B03330(void) {
    u8 buf[16];
    Ovl09631Work *w = D_01B0A1E0;

    func_01B05760(buf);
    func_01B019A8(buf, 20);
    func_01B09E70(w->fC80, 20, 0, 0.0f, 1.0f);
    func_01B057B8(0);
}

void func_01B03390(void) {
    Ovl09631Work *w = D_01B0A1E0;

    if (w->p3144 != 0) {
        func_01B05F88(w->p3144);
        w->p3144 = 0;
    }
}
