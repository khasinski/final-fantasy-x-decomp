#include "common.h"

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad0[0xC0];
    float fC0;
    float fC4;
    u8 padC8[0x08];
    float pos[4];
    u8 padE0[0x50];
} OvlObj;

typedef struct {
    u8 pad0[0x04];
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    u8 pad1C[0x08];
    int f24;
    u8 pad28[0x04];
    u16 f2C;
    u16 f2E;
} OvlWave;

typedef struct {
    int f00;
    int f04;
    int f08;
    int f0C;
} OvlTimer;

typedef struct {
    u8 pad0[0x850];
    OvlObj obj850;
    u8 pad980[0xB80];
    float vec1500[4];
    float vec1510[4];
    u8 pad1520[0x2C];
    OvlTimer timer154C;
    u8 pad155C[0x3C];
    OvlWave wave1598;
    u8 pad15C8[0x08];
    u8 buf15D0[0xB0];
    u8 buf1680[0x180];
    float f1800;
} OvlState;

extern u8 D_01B0A448;
extern OvlState *D_01B0A568;

extern void func_01B05CB0(void *, void *, int, int, int, int, float);
extern void func_01B09360(void *, int);
extern void func_01B09468(void *, int);
extern void func_01B09748(void *, int, int, float, float);
extern void func_01B09F18(void *, int);

void func_01B02E00(void) {
    OvlState *s = D_01B0A568;
    s->vec1500[1] = s->vec1510[1] - 120.0f;
}

void func_01B02E20(void) {
    OvlState *s = D_01B0A568;
    s->vec1500[1] += 1.5f;
}

void func_01B02E40(void) {
    OvlState *s = D_01B0A568;
    OvlObj *obj = &s->obj850;
    OvlTimer *timer;
    OvlWave *wave;
    u8 *p;

    func_01B05CB0(&D_01B0A448, obj, 2, 21, 0, 0, 0.3f);
    copy_vec(obj->pos, s->vec1510);
    obj->fC4 = s->f1800;
    obj->pos[1] -= 2.0f;

    timer = &s->timer154C;
    s->timer154C.f00 = 0;
    timer->f04 = 40;
    timer->f08 = 0;
    timer->f0C = 50;
    s->vec1500[1] = s->vec1510[1];
    func_01B09360(timer, 1);

    wave = &s->wave1598;
    func_01B09468(wave, 25);
    wave->f2C |= 3;
    wave->f24 = 22;
    wave->f04 = 1.0f;
    wave->f08 = 1.0f;
    wave->f10 = 4.0f;
    wave->f18 = 0.0f;
    wave->f14 = 4.0f;
    wave->f0C = 0.0f;

    p = s->buf1680;
    p[0xF0] = 0x80;
    p[0xF1] = 0x80;
    p[0xF2] = 0x80;
    p[0xF3] = 0x40;
    *(u16 *)(p + 0x124) = 2;
    *(int *)(p + 0x11C) = -1;
    *(int *)(p + 0x120) = 0x5C;
    *(int *)(p + 0x110) = 0x76;
    *(float *)(p + 0xF8) = 0.0f;
    *(float *)(p + 0xFC) = 0.05f;
    *(float *)(p + 0x100) = 0.0f;
    func_01B09F18(p, 48);

    func_01B09748(s->buf15D0, 16, 180, 0.5f, 1.0f);
}
