#include "common.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0x60];
    float f60;
    float f64;
    float f68;
    float f6C;
    s16 h70;
    s16 h72;
    s16 h74;
    s16 h76;
    u8 pad78[0x08];
    float m80[16];
    float fC0;
    float fC4;
    u8 padC8[0x08];
    Vec4 vD0;
    u8 padE0[0x24];
    void *p104;
    u8 pad108[0x10];
    int w118;
    u8 pad11C[0x04];
    int w120;
    u8 pad124[0x02];
    u8 b126;
    u8 pad127[0x09];
} SubObj;

typedef struct {
    u8 pad00[0x5F0];
    SubObj s5F0;    /* 0x5F0 */
    u8 pad720[0x130];
    SubObj s850;    /* 0x850 */
    u8 pad980[0x11D0];
    u8 f1B50[0x40]; /* 0x1B50 */
    Vec4 v1B90;     /* 0x1B90 */
    Vec4 v1BA0;     /* 0x1BA0 */
    u8 f1BB0[0x30]; /* 0x1BB0 */
    Vec4 v1BE0;     /* 0x1BE0 */
    Vec4 v1BF0;     /* 0x1BF0 */
    Vec4 v1C00;     /* 0x1C00 */
    Vec4 v1C10;     /* 0x1C10 */
    Vec4 v1C20;     /* 0x1C20 */
    Vec4 v1C30;     /* 0x1C30 */
    Vec4 v1C40;     /* 0x1C40 */
    u8 pad1C50[0x2C0];
    float f1F10;    /* 0x1F10 */
    int w1F14;      /* 0x1F14 */
    int w1F18;      /* 0x1F18 */
    int w1F1C;      /* 0x1F1C */
    int w1F20;      /* 0x1F20 */
} Ovl09494Work;

extern u8 D_01B0A228[];
extern Ovl09494Work *D_01B0A310;
extern int D_01B0A328;

extern void func_001072C0(int, int, int);
extern void func_00110310(int, float);
extern void func_002DCE08(void *, void *, void *);
extern void func_002DCF48(void *, void *);

extern int func_01B03630(int);
extern void func_01B03918(int, void *);
extern void func_01B03CE8(int, int, void *);
extern void func_01B04A58(int, void *);
extern void func_01B04EB8(void *, void *);
extern void func_01B04FD8(int, void *, void *);
extern int func_01B06108(void *, void *, int, int, int, int, float);
extern void func_01B06578(void *, void *);
extern float func_01B08320(void);

void func_01B028B8(SubObj *o);
void func_01B02A88(SubObj *o);

void func_01B02790(void)
{
    func_01B04A58(1, 0);
}

void func_01B027A0(void)
{
    Ovl09494Work *w = D_01B0A310;
    float a;
    float b;
    int h;

    func_01B03918(2, &w->v1C10);
    a = w->f1F10 + 2.3561945f;
    if (a > 3.1415927f) {
        a -= 6.2831855f;
    } else if (a < -3.1415927f) {
        a += 6.2831855f;
    }
    h = func_01B03630(2);
    b = 4.712389f - a;
    if (b > 3.1415927f) {
        b -= 6.2831855f;
    } else if (b < -3.1415927f) {
        b += 6.2831855f;
    }
    func_00110310(h, b);
}

void func_01B028B8(SubObj *o)
{
    float m0[16];
    float m1[16];
    Vec4 off;
    float s;

    func_01B04EB8(m0, m1);
    func_002DCF48(o->m80, m1);
    off.x = 0.0f;
    off.y = 0.0f;
    off.z = 5.0f;
    off.w = 1.0f;
    func_002DCE08(&o->vD0, o->m80, &off);
    o->vD0.w = 1.0f;
    s = func_01B08320() * 0.00100000005f;
    o->f6C = s;
    o->f68 = s;
    o->f64 = s;
    o->f60 = s;
    if (o->w118 >= 0x1C) {
        int a;
        if (o->w120 > 0) {
            o->w120--;
        }
        a = (o->w120 << 12) / 6;
        o->h76 = a;
        o->h74 = a;
        o->h72 = a;
        o->h70 = a;
    }
}

void func_01B029B0(void)
{
    Ovl09494Work *w = D_01B0A310;
    SubObj *s;
    int h;

    copy_vec(&w->v1BA0, &w->v1C10);
    h = func_01B03630(1);
    if (w->w1F1C != -1) {
        func_001072C0(h, 0, 0);
    }
    s = &w->s850;
    func_001072C0(h, func_01B03630(-1), 0x12);
    func_01B06108(D_01B0A228, s, 7, 0, 0, 0, 0.00100000005f);
    s->p104 = (void *)func_01B028B8;
    s->b126 = 2;
    s->w120 = 6;
}

int func_01B02A78(void)
{
    return D_01B0A328 == 0;
}

void func_01B02A88(SubObj *o)
{
    func_01B03CE8(1, 6, &o->vD0);
    o->p104 = 0;
}

void func_01B02AC0(void)
{
    Ovl09494Work *w = D_01B0A310;
    SubObj *s = &w->s5F0;

    func_01B06108(D_01B0A228, s, 5, 12, 0, 0, 0.00700000022f);
    s->fC0 = 0.785398185f;
    s->p104 = (void *)func_01B02A88;
    s->fC4 = w->f1F10;
}

void func_01B02B40(void)
{
    func_001072C0(func_01B03630(1), 0, 0);
}

void func_01B02B68(void)
{
    func_01B06578(D_01B0A228, &D_01B0A310->s850);
}
