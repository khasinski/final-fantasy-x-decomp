#include "common.h"

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad0[0x60];
    float f60;
    float f64;
    float f68;
    u8 pad6C[0x54];
    float rotC0[4];
    float pos[4];
    u8 padE0[0x50];
} OvlObj;

typedef struct {
    u8 pad0[0x0E];
    u8 b0E;
} OvlSub08;

typedef struct {
    u8 pad0[0x08];
    OvlSub08 *p08;
    u8 pad0C[0x158];
    float *p164;
} OvlArg;

typedef struct {
    OvlObj obj[9];
    u8 padAB0[0x120];
    float vecBD0[4][4];
    float vecC10[4][4];
    u8 padC50[0x80];
    float vecCD0[4];
    u8 bufCE0[0x1E8];
    float fEC8;
    int fECC;
    int fED0;
} OvlState;

extern u8 D_01B0A2F8;
extern OvlState *D_01B0A480;
extern int D_01B0A48C;

extern void func_00173650(void *);
extern int func_002B2E10(void *, int, int, int);
extern void func_002DCE08(void *, void *, void *);
extern void func_002DD128(void *);
extern void func_002DD3C0(void *, void *, void *);
extern void func_002DD948(void *, void *);
extern void func_01B02598(void);
extern void func_01B060D0(void *, void *, int, int, int, int, float);
extern void func_01B09780(void *, int);

void func_01B027D8(void) {
    OvlState *s = D_01B0A480;
    D_01B0A48C = func_002B2E10(func_01B02598, 0, 0, 0);
    s->fECC = 50;
    s->fED0 = 0;
}

void func_01B02828(void) {
    int c[4];
    OvlState *s = D_01B0A480;
    OvlObj *obj;
    u8 *p;

    obj = &s->obj[8];
    func_01B060D0(&D_01B0A2F8, obj, 8, 0, 0, 0, 0.01f);
    copy_vec(obj->pos, s->vecCD0);
    obj->rotC0[0] = -1.57079637f;
    obj->rotC0[1] = s->fEC8;
    obj->pos[1] -= 30.0f;

    p = s->bufCE0;
    p[0x87] = 0x40;
    *(int *)(p + 0x88) = 0x82;
    p[0x98] = 0x44;
    p[0x83] = 0;
    p[0x82] = 0;
    p[0x81] = 0;
    p[0x80] = 0;
    p[0x84] = 0;
    p[0x85] = 0;
    p[0x86] = 0;
    p[0x99] = 0;
    func_01B09780(p, 20);

    c[0] = 0;
    c[1] = 0;
    c[2] = 0;
    c[3] = 128;
    func_00173650(c);
}

void func_01B02928(OvlArg *a0, OvlObj *a1) {
    float mat[16];
    float v[4];
    OvlState *s = D_01B0A480;
    int idx = a0->p08->b0E;
    float *src = a0->p164;
    float *dst1 = s->vecBD0[idx];
    float *dst2 = s->vecC10[idx];

    func_002DD128(mat);
    mat[0] = a1->f60;
    mat[5] = a1->f64;
    mat[10] = a1->f68;
    func_002DD3C0(mat, mat, a1->rotC0);
    func_002DD948(&mat[12], a1->pos);
    v[0] = src[0];
    v[1] = src[1];
    v[2] = src[2];
    v[3] = 1.0f;
    func_002DCE08(v, mat, v);
    dst1[0] = v[0];
    dst1[1] = v[1];
    dst1[2] = v[2];
    dst1[3] = 10.0f;
    dst2[0] = 0.5f;
    dst2[1] = 0.5f;
    dst2[2] = 0.5f;
    dst2[3] = 1.0f;
}
