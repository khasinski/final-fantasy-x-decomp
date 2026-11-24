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
    u8 pad980[0xB60];
    float f14E0;
    float f14E4;
    u8 pad14E8[0x58];
    float f1540;
    float f1544;
    u8 pad1548[0x18];
    float vec1560[4];
    float vec1570[4];
    u8 pad1580[0x2C];
    OvlTimer timer15AC;
    u8 pad15BC[0x3C];
    OvlWave wave15F8;
    u8 pad1628[0x08];
    u8 buf1630[0x90];
    u8 buf16C0[0x180];
    float f1840;
} OvlState;

extern u8 D_01B0AA48;
extern OvlState *D_01B0AB88;

extern void func_00110CA8(void *, int);
extern void *func_01B03810(int, int);
extern void func_01B062B0(void *, void *, int, int, int, int, float);
extern void func_01B09960(void *, int);
extern void func_01B09A68(void *, int);
extern void func_01B09D48(void *, int, int, float, float);
extern void func_01B0A518(void *, int);

void func_01B03368(void) {
    OvlState *s = D_01B0AB88;
    float y;
    s->f14E0 = s->f1540;
    y = s->vec1570[1] - 120.0f;
    s->f1544 = y;
    s->vec1560[1] = y;
    s->f14E4 = y;
}

void func_01B03398(void) {
    OvlState *s = D_01B0AB88;
    float y = s->f1544 + 1.5f;
    s->f1544 = y;
    s->vec1560[1] += 1.5f;
    s->f14E4 = y;
}

void func_01B033C8(void) {
    OvlState *s = D_01B0AB88;
    OvlObj *obj = &s->obj850;
    OvlTimer *timer;
    OvlWave *wave;
    u8 *p;
    float y;

    func_01B062B0(&D_01B0AA48, obj, 2, 21, 0, 0, 0.3f);
    copy_vec(obj->pos, s->vec1570);
    obj->fC4 = s->f1840;
    obj->pos[1] -= 2.0f;

    timer = &s->timer15AC;
    s->timer15AC.f00 = 0;
    timer->f04 = 40;
    timer->f08 = 0;
    timer->f0C = 50;
    s->vec1560[1] = s->vec1570[1];
    y = s->vec1570[1] - 9.0f;
    s->f1544 = y;
    s->f14E4 = y;
    func_01B09960(timer, 1);

    wave = &s->wave15F8;
    func_01B09A68(wave, 25);
    wave->f2C |= 3;
    wave->f24 = 22;
    wave->f04 = 1.0f;
    wave->f08 = 1.0f;
    wave->f10 = 4.0f;
    wave->f18 = 0.0f;
    wave->f14 = 4.0f;
    wave->f0C = 0.0f;

    p = s->buf16C0;
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
    func_01B0A518(p, 48);

    func_01B09D48(s->buf1630, 16, 180, 0.5f, 1.0f);
}

void func_01B03568(void) {
    OvlState *s = D_01B0AB88;
    float y = s->vec1570[1];
    s->f1544 = y;
    s->f14E4 = y;
}

void func_01B03580(void) {
    func_00110CA8(func_01B03810(0, 0), 1);
}

void func_01B035A8(void) {
    func_00110CA8(func_01B03810(0, 0), 0);
}
