#include "common.h"

static inline void copy_vec(void *src, void *dst)
{
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

static inline void copy_vec_v1(void *src, void *dst)
{
    register void *d __asm__("$3") = dst;
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(d) : "memory");
}

typedef struct {
    u8 pad00[0xC0];
    float fC0;
    float fC4;
    u8 padC8[0x08];
    float vecD0[4];
} SubObj130;

typedef struct {
    u8 pad00[0x0C];
    float f0C;
    u8 pad10[0x0C];
    float f1C;
} SubObjD80;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} TaskObj;

typedef struct {
    SubObj130 sub000;
    u8 padE0[0x50];
    SubObj130 sub130;
    u8 pad210[0x770];
    SubObj130 sub980;
    u8 padA60[0xB0];
    u8 subB10[0xC0];
    float vecBD0[4];
    float vecBE0[4];
    float vecBF0[4];
    float vecC00[4];
    float vecC10[4];
    u8 padC20[0x160];
    SubObjD80 subD80;
    u8 padDA0[0x60];
    TaskObj *taskE00;
    int wE04;
    float fE08;
    int wE0C;
    int wE10;
    int wE14;
} OvlState;

extern u8 D_01B09558[];
extern OvlState *D_01B096A0;

extern void func_0010D380(void *, int, int);
extern void func_0010D3A8(void *, int, int);
extern void func_0010D4A0(void *, int);
extern void func_0010D4D8(void *, int);
extern void func_00173650(void *);

extern void *func_01B02858(int);
extern void func_01B03748(int, int);
extern void func_01B03C80(int, void *);
extern void func_01B04200(int, void *, void *);
extern void func_01B04828(void *);
extern TaskObj *func_01B04FD0(void *);
extern void func_01B05050(void *);
extern void func_01B05198(TaskObj *);
extern void func_01B05330(void *, void *, int, int, int, int, float);
extern void func_01B057A0(void *, void *);
extern void func_01B06168(float *, float *, float *);
extern void func_01B08CA0(void *, int, int, float, float);
extern SubObj130 *func_01B094C0(void);

void func_01B02230(void);

void func_01B020A8(void)
{
    OvlState *s = D_01B096A0;
    SubObj130 *m1 = &s->sub130;

    func_01B05330(D_01B09558, m1, 1, 0, 0, 0, 0.01f);
    copy_vec(s->vecC10, m1->vecD0);
    m1->fC4 = s->fE08;
    m1->vecD0[1] -= 3000.0f;

    func_01B05330(D_01B09558, &s->sub000, 0, 0, 0, 0, 0.02f);
    copy_vec_v1(s->vecC10, s->sub000.vecD0);
    s->sub000.fC4 = s->fE08;
    s->sub000.vecD0[1] -= 3000.0f;
}

void func_01B02198(void)
{
    u8 buf[0x10];
    OvlState *s = D_01B096A0;
    SubObjD80 *d = &s->subD80;

    func_01B08CA0(d, 1, 0, 0.0f, 0.3f);
    d->f0C = 0.0f;
    d->f1C = 1.0f;
    func_01B057A0(D_01B09558, &s->sub980);
    s->sub130.vecD0[1] = s->vecC10[1];
    s->sub000.vecD0[1] = s->vecC10[1];
    func_01B04828(buf);
    func_00173650(buf);
}

void func_01B02230(void)
{
    OvlState *s = D_01B096A0;
    SubObj130 *m;

    s->wE14--;
    if (s->wE14 > 0) {
        return;
    }
    s->wE14 = 100;
    m = func_01B094C0();
    if (m == 0) {
        return;
    }
    func_01B05330(D_01B09558, m, 1, 0, 0, 0, 0.01f);
    copy_vec_v1(s->vecC10, m->vecD0);
    m->fC4 = s->fE08;

    m = func_01B094C0();
    if (m == 0) {
        return;
    }
    func_01B05330(D_01B09558, m, 0, 0, 0, 0, 0.02f);
    copy_vec_v1(s->vecC10, m->vecD0);
    m->fC4 = s->fE08;
}

void func_01B02320(void)
{
    OvlState *s = D_01B096A0;
    TaskObj *t;

    s->wE14 = 1;
    t = func_01B04FD0(func_01B02230);
    t->b18 = 1;
    func_01B05198(t);
    s->taskE00 = t;
}

void func_01B02380(void)
{
    OvlState *s = D_01B096A0;

    if (s->taskE00 != 0) {
        func_01B05050(s->taskE00);
        s->taskE00 = 0;
    }
}

void func_01B023C0(void)
{
    OvlState *s = D_01B096A0;

    func_01B03C80(1, s->subB10);
    copy_vec(s->vecBD0, s->vecBF0);
    copy_vec(s->vecBE0, s->vecC00);
    func_01B04200(1, s->subB10, s->vecBF0);
    s->vecC00[1] -= 5.0f;
    func_01B03748(1, 0);
}

void func_01B02448(void)
{
    void *p = func_01B02858(1);

    func_0010D380(p, -1, 0x3540);
    func_0010D3A8(p, -1, 0x3BD0);
    func_0010D4A0(p, -1);
    func_0010D4D8(p, -1);
}

void func_01B024A8(void)
{
    float v0[4];
    float v1[4];
    OvlState *s = D_01B096A0;

    v0[0] = 0.0f;
    v0[1] = s->fE08;
    v0[2] = 0.0f;
    v0[3] = 0.0f;
    v1[0] = -20.0f;
    v1[1] = 0.0f;
    v1[2] = -10.0f;
    v1[3] = 1.0f;
    func_01B06168(v0, s->vecBE0, v1);
}
