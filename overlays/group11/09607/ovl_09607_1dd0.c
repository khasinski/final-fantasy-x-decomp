#include "common.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0x30];
    Vec4 v30;
    u8 pad40[0x106];
    u8 b146;
} Obj9058;

typedef struct {
    int w00;
    int w04;
    u8 b08;
    u8 b09;
    u8 b0A;
    u8 pad0B;
    s16 h0C;
    s16 h0E;
    int w10;
    int w14;
    u8 b18;
    u8 b19;
    u8 b1A;
    u8 b1B;
    u8 b1C;
    u8 b1D;
    u8 b1E;
    u8 b1F;
    void *p20;
    u8 pad24[0x10];
    int w34;
    int w38;
    int w3C;
    s16 h40;
    s16 h42;
    int w44;
    int w48;
} Sub3B80;

typedef struct {
    u8 pad00[0x2B20];
    Vec4 v2B20;
    u8 pad2B30[0x1050];
    Sub3B80 s3B80;
    u8 pad3BCC[0x28];
    float f3BF4;
} Work9607;

extern Work9607 *D_01B0BC98;

extern int func_001038F8(void);
extern void func_002B7B20(void *, void *);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);
extern void func_01B060A0(void *, void *);
extern void func_01B08D28(int);
extern Obj9058 *func_01B09058(int);

void func_01B01DD0(void)
{
    Work9607 *w = D_01B0BC98;
    Obj9058 *o;

    func_01B08D28(0);
    o = func_01B09058(0);
    o->b146 = 1;
    func_002DD128(o);
    func_002DD318(o, o, w->f3BF4);
    copy_vec(&o->v30, &w->v2B20);
}

void func_01B01E40(void)
{
    Sub3B80 *s = &D_01B0BC98->s3B80;

    s->w00 = 0x20C;
    s->w04 = func_001038F8();
    s->b08 = 0;
    s->b09 = 0x80;
    s->b0A = 0;
    s->h0C = 0;
    s->h0E = 0;
    s->w10 = 0;
    s->w14 = 0;
    s->b18 = 0x4C;
    s->b19 = 0x4C;
    s->b1A = 0x4C;
    s->b1B = 0x80;
    s->b1C = 0;
    s->b1D = 0;
    s->b1E = 0;
    s->b1F = 0;
    s->p20 = 0;
    s->w34 = 0;
    s->w38 = 0;
    s->w3C = 0;
    s->h40 = 0;
    s->h42 = 0;
    s->w44 = 0;
    s->w48 = 0;
}

void func_01B01EE0(void *a0, void *a1)
{
    float m0[16];
    float m1[16];
    float m2[16];
    Sub3B80 *s;

    func_01B060A0(m1, m2);
    func_002DCE38(m0, m2, a1);
    func_002DCE38(m0, m1, m0);
    s = &D_01B0BC98->s3B80;
    s->p20 = m0;
    func_002B7B20(a0, s);
}
