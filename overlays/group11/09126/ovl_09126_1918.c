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

extern s32 D_01B004D8;
extern s32 D_01B004E0;
extern u8 D_01B004F0;
extern u8 D_01B00600[];
extern u8 D_01B00690[];
extern u8 D_01B008A0[];
extern u8 D_01B008B8[];
extern u8 D_01B008D8[];
extern u8 D_01B00940[];
extern u8 D_01B009D0[];
extern u8 D_01B00B20[];
extern u8 D_01B00B90[];
extern ObjC30 D_01B00C30;
extern u8 D_01B0DDF0[];
extern s32 D_01B0DE1C;

extern int func_001C5E90(s32, s32, s32);

extern int func_01B015C8(u32);
extern void func_01B03490(void *);
extern void func_01B03730(void *);
extern void func_01B064D0(void *);
extern void func_01B06600(void *);
extern void func_01B066E0(void *);
extern void func_01B07188(void *);
extern void func_01B098F8(void *);
extern void func_01B0B1B0(void *);
extern void func_01B0B1E8(void *);
extern void func_01B0BA58(void *);
extern void func_01B0CA08(void *);
extern void func_01B0CAB0(void *);
extern void func_01B0CE10(void *);

void ovl_09126_1918(Task9126 *a0)
{
    ObjC30 *o = &D_01B00C30;
    Work9126 *w = a0->work;
    float t;
    void *p[5];

    t = w->f580 + (1.0f / 30.0f);
    w->f580 = t;
    switch (w->state) {
    case 0:
        if (t >= 0.25f) {
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

            p[0] = o;
            p[1] = 0;
            *(float *)&p[2] = 0.05f;
            *(float *)&p[3] = 1.0f;
            func_01B066E0(p);

            p[4] = a0->w00;
            func_01B0CAB0(&p[4]);
        }
        break;
    }
}
