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
    u8 padE0[0x24];
    void *f104;
    int f108;
    void *f10C;
    u8 pad110[0x08];
    int f118;
    u8 pad11C[0x14];
} OvlObj;

typedef struct {
    float pos[4];
    float vx;
    float vy;
    float vz;
    int vw;
    float ax;
    float ay;
    float az;
    float aw;
    u8 pad30[0x0C];
    float scale;
    u8 pad40[0x0C];
    int f4C;
    int f50;
    u8 pad54[0x14];
    u8 b68;
    u8 b69;
    u8 b6A;
    u8 b6B;
} OvlPtcl;

typedef struct {
    OvlObj obj[9];
    void *arrAB0[5];
    u8 padAC4[0x0C];
    float matAD0[16];
    u8 padB10[0xC0];
    float vecBD0[4][4];
    float vecC10[4][4];
    u8 padC50[0x80];
    float vecCD0[4];
    u8 bufCE0[0x160];
    u8 bufE40[0x84];
    void *fEC4;
    float fEC8;
    int fECC;
    int fED0;
    int fED4;
    int fED8;
} OvlState;

extern u8 D_01B0A2F8;
extern OvlState *D_01B0A480;
extern int D_01B0A48C;
extern u8 D_01B0FA30;

extern void func_002B2F18(int);
extern float func_002B3DB0(float);
extern int func_002B49A0(void *, int, int);
extern void func_01B016B0(float, int);
extern void func_01B022D8(void *);
extern void func_01B060D0(void *, void *, int, int, int, int, float);
extern void func_01B07498(void *, int);
extern OvlPtcl *func_01B09D10(void);

void func_01B02310(OvlObj *a0) {
    OvlPtcl *p;
    int t;
    float vz;

    if (a0->f118 >= 0x79) {
        a0->f104 = 0;
        return;
    }
    func_01B022D8(a0->pos);
    p = func_01B09D10();
    if (p == 0) {
        return;
    }
    t = func_002B49A0(&D_01B0FA30, 9, 0);
    func_01B07498((u8 *)p + 0x30, t);
    copy_vec(p->pos, a0->pos);
    p->vx = func_002B3DB0(0.03f);
    p->vy = func_002B3DB0(0.04f) + 0.1f;
    vz = func_002B3DB0(0.03f);
    p->vz = vz;
    p->vw = 0;
    p->ax = p->vx * -0.01f;
    p->ay = 0.003f;
    p->az = vz * -0.01f;
    p->aw = 1.0f;
    p->scale = 0.1f;
    p->f4C = 24;
    p->f50 = 0;
    p->b68 = 0x60;
    p->b69 = 0x60;
    p->b6B = 0x50;
}

void func_01B02448(OvlObj *a0) {
    func_01B022D8(a0->pos);
    a0->f104 = 0;
}

void func_01B02478(void) {
    OvlState *s = D_01B0A480;
    OvlObj *obj;

    obj = &s->obj[4];
    func_01B060D0(&D_01B0A2F8, obj, 4, 0, 0, 0, 0.012f);
    copy_vec(obj->pos, s->vecCD0);
    obj->rotC0[1] = s->fEC8;
    obj->pos[1] -= 0.7f;

    obj = &s->obj[3];
    func_01B060D0(&D_01B0A2F8, obj, 3, 58, 0, 0, 0.045f);
    obj->f104 = func_01B02310;
    obj->rotC0[1] = s->fEC8;

    obj = &s->obj[2];
    func_01B060D0(&D_01B0A2F8, obj, 2, 58, 0, 0, 0.045f);
    obj->f104 = func_01B02448;
    obj->rotC0[1] = s->fEC8;
}

void func_01B02598(void) {
    OvlState *s = D_01B0A480;
    float f = 0.0f;
    int a = 128;

    if (s->fECC > 0) {
        s->fECC--;
    }
    switch (s->fED0) {
    case 0: {
        int v = s->fECC;
        int n = 50;
        float t = (float)v / 50.0f;
        a = (v * 128) / n;
        f = (1.0f - t) * 1.57079637f + t * f;
        if (v == 0) {
            s->fECC = n;
            s->fED0 = 1;
        }
        break;
    }
    case 1: {
        int v = s->fECC;
        int n = 50;
        float t = (float)v / 50.0f;
        a = ((n - v) * 128) / n;
        f = (1.0f - t) * f + t * 1.57079637f;
        if (v == 0) {
            func_002B2F18(D_01B0A48C);
            D_01B0A48C = -1;
            s->fED0++;
        }
        break;
    }
    }
    func_01B016B0(f, a);
}
