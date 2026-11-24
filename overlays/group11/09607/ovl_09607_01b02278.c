#include "common.h"
#include "vu0.h"

typedef struct Ovl09607Sub {
    u8 pad00[0x104];
    void *p104;         /* 0x104 */
    u8 pad108[0x18];
    int w120;           /* 0x120 */
    u8 pad124[0xC];
} Ovl09607Sub; /* size 0x130 */

typedef struct Ovl09607Item {
    u8 pad00[0xD0];
    float pos[4];       /* 0xD0 */
    u8 padE0[0x50];
    float p0[4];        /* 0x130 */
    float p1[4];        /* 0x140 */
    float p2[4];        /* 0x150 */
    float p3[4];        /* 0x160 */
    u8 pad170[0x10];
    float t;            /* 0x180 */
    float dt;           /* 0x184 */
    int cnt;            /* 0x188 */
    u8 pad18C[0x4];
} Ovl09607Item; /* size 0x190 */

typedef struct Ovl09607Part {
    float pos[4];       /* 0x00 */
    float f10;          /* 0x10 */
    float f14;          /* 0x14 */
    float f18;          /* 0x18 */
    float f1C;          /* 0x1C */
    float f20;          /* 0x20 */
    float f24;          /* 0x24 */
    float f28;          /* 0x28 */
    float f2C;          /* 0x2C */
    u8 b30[0xC];        /* 0x30 */
    float f3C;          /* 0x3C */
    int w40;            /* 0x40 */
    u8 pad44[0x8];
    int w4C;            /* 0x4C */
    int w50;            /* 0x50 */
    u8 pad54[0x4];
    int w58;            /* 0x58 */
    int w5C;            /* 0x5C */
    int w60;            /* 0x60 */
} Ovl09607Part;

typedef struct Ovl09607Work {
    u8 pad00[0x2860];
    Ovl09607Sub sub[2]; /* 0x2860, 0x2990 */
    u8 pad2AC0[0xE0];
    Ovl09607Item item[2]; /* 0x2BA0 */
} Ovl09607Work;

extern u8 D_01B02260[];
extern u8 D_01B0BB70[];
extern Ovl09607Work *D_01B0BC98;

float func_002B3DB0(float a0);

void func_01B07010(int a0);
void func_01B072F0(void *a0, void *a1, int a2, int a3, int a4, int a5, float a6);
void func_01B07760(void *a0, void *a1);
int *func_01B07880(void *a0, int a1);
float func_01B07E10(float a0, float a1, float a2, float a3, float a4);
void func_01B086B8(void *a0, int a1);
Ovl09607Part *func_01B0B1C8(void);

static inline void copy_vec(void *dst, void *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

void func_01B02278(void)
{
    Ovl09607Work *w = D_01B0BC98;
    Ovl09607Sub *s;

    s = &w->sub[0];
    func_01B072F0(D_01B0BB70, s, 1, 0, 0, 0, 0.05f);
    s->w120 = 0x11;
    s->p104 = D_01B02260;

    s = &w->sub[1];
    func_01B072F0(D_01B0BB70, s, 1, 0, 0, 0, 0.05f);
    {
        register int v __asm__("$3") = 0x37;
        s->p104 = D_01B02260;
        s->w120 = v;
    }
}

void func_01B02338(int a0)
{
    float v[4];
    Ovl09607Work *w = D_01B0BC98;
    Ovl09607Item *it;
    int i;
    int done = 0;

    it = w->item;
    for (i = 0; i < 2; i++, it++) {
        int j;
        it->t += it->dt;
        if (it->t > 1.0f) {
            it->t = 1.0f;
        }
        v[0] = func_01B07E10(it->p0[0], it->p1[0], it->p2[0], it->p3[0], it->t);
        v[1] = func_01B07E10(it->p0[1], it->p1[1], it->p2[1], it->p3[1], it->t);
        v[2] = func_01B07E10(it->p0[2], it->p1[2], it->p2[2], it->p3[2], it->t);
        v[3] = 1.0f;
        copy_vec(it->pos, v);

        if (it->cnt == 0) {
            func_01B07760(D_01B0BB70, it);
            done = 1;
        } else {
            it->cnt--;
        }

        for (j = 0; j < 4; j++) {
            Ovl09607Part *p = func_01B0B1C8();
            if (p == 0) {
                break;
            }
            func_01B086B8(p->b30, *func_01B07880(D_01B0BB70, 5));
            copy_vec(p->pos, v);
            p->pos[0] += func_002B3DB0(8.0f);
            p->pos[1] += func_002B3DB0(8.0f);
            p->pos[2] += func_002B3DB0(8.0f);
            p->f10 = func_002B3DB0(1.0f);
            p->f14 = func_002B3DB0(1.0f);
            p->f18 = func_002B3DB0(1.0f);
            p->f1C = func_002B3DB0(3.1415927f);
            p->f20 = 0.0f;
            p->f24 = -0.1f;
            p->f28 = 0.0f;
            p->f2C = 1.0f;
            p->f3C = (func_002B3DB0(0.2f) + 1.0f) * 0.08f;
            p->w40 = 0;
            p->w58 = 0x10;
            p->w5C = 0;
            p->w4C = 0x10;
            p->w50 = 0;
            p->w60 = 0;
        }
    }
    if (done == 1) {
        func_01B07010(a0);
    }
}
