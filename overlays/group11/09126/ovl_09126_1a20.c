#include "common.h"

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0x30];
    float f30;
    float f34;
    float f38;
    u8 pad3C[0x24];
    float f60;
    float f64;
    float f68;
    float f6C;
} ObjC30;

typedef struct {
    u8 pad00[0x20];
    u8 sub20[0x100];
    u8 sub120[0x100];
    u8 sub220[0x20];
    Vec4 pos240;
    u8 sub250[0x20];
    Vec4 pos270;
    u8 sub280[0x20];
    Vec4 scale2A0;
    u8 sub2B0[0x20];
    Vec4 scale2D0;
    u8 sub2E0[0x150];
    u8 sub430[0x150];
    float f580;
    u16 state;
} Work9126;

typedef struct {
    void *w00;
    Work9126 *work;
} Task9126;

typedef struct {
    void *p00;
    void *p04;
    void *p08;
    void *p0C;
} Args16;

extern s32 D_01B004E0;
extern u8 D_01B00690[];
extern u8 D_01B008B8[];
extern u8 D_01B008D8[];
extern u8 D_01B00940[];
extern u8 D_01B00B90[];
extern ObjC30 D_01B00C30;
extern u8 D_01B0DDF0[];
extern s32 D_01B0DE1C;

extern int func_001C5E90(s32, s32, s32);
extern void func_01B03490(void *);
extern void func_01B066E0(void *);
extern void func_01B07188(void *);
extern void func_01B098F8(void *);
extern void func_01B0BA58(void *);
extern void func_01B0CAB0(void *);

void ovl_09126_1a20(Task9126 *a0)
{
    union {
        Args16 args;
        void *m0[10];
    } u;
    void *end_p;
    ObjC30 *o = &D_01B00C30;
    Work9126 *w = a0->work;
    float t;

    t = w->f580 + (1.0f / 30.0f);
    w->f580 = t;
    switch (w->state) {
    case 0:
        if (t >= 0.25f) {
            u.args.p00 = w->sub250;
            u.args.p04 = D_01B008B8;
            func_01B07188(&u.args);

            u.args.p00 = D_01B00B90;
            u.args.p04 = &w->pos270;
            u.args.p08 = (void *)1;
            func_01B03490(&u.args);

            {
                float y = w->pos270.y - 0.2f;
                u.args.p00 = w->sub2B0;
                u.args.p04 = D_01B008B8;
                w->pos270.y = y;
                func_01B07188(&u.args);
            }

            {
                float one = 1.0f;
                register void *c690 __asm__("$3") = D_01B00690;
                register void *c940 __asm__("$5") = D_01B00940;
                u.m0[4] = w->sub430;
                {
                    void **v0 = u.m0 + 4;
                    *(volatile float *)&w->scale2D0.w = one;
                    v0[1] = D_01B008B8;
                    v0[2] = c690;
                    *(void * volatile *)&u.m0[7] = w->sub250;
                    v0[4] = c940;
                    u.m0[9] = w->sub2B0;
                    w->scale2D0.y = one;
                    w->scale2D0.z = one;
                    w->scale2D0.x = one;
                    func_01B098F8(v0);
                }
            }

            {
                struct { void *a, *b, *c; s32 d; void *e; int f; } *b = (void *)&u.args;
                b->a = w->sub120;
                b->b = D_01B008D8;
                b->c = w->sub430;
                b->d = D_01B0DE1C;
                b->e = D_01B0DDF0;
                b->f = 0;
                func_01B0BA58(b);
            }

            func_001C5E90(D_01B004E0, -5, 0);
            w->state++;
        }
        break;
    case 1:
        if (t >= 1.0f) {
            o->f6C = 1.0f;
            o->f68 = 1.0f;
            o->f64 = 1.0f;
            o->f60 = 1.0f;
            o->f38 = 1.0f;
            o->f34 = 1.0f;
            o->f30 = 1.0f;

            u.args.p00 = o;
            u.args.p04 = 0;
            *(float *)&u.args.p08 = 0.05f;
            *(float *)&u.args.p0C = 1.0f;
            func_01B066E0(&u.args);

            end_p = a0->w00;
            func_01B0CAB0(&end_p);
        }
        break;
    }
}
