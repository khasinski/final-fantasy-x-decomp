#include "common.h"

typedef struct {
    u8 pad00[0x10];
    float f10, f14, f18;
    u8 pad1C[0x04];
    float f20, f24, f28;
    u8 pad2C[0x04];
    int w30, w34, w38;
    u8 pad3C[0x38];
    float f74;
    u8 pad78[0x18];
    int w90, w94, w98, w9C;
    int wA0, wA4, wA8, wAC;
    float fB0, fB4;
    u8 padB8[0x08];
} PtObj2;

extern char D_01B037B0[];

extern int func_01B02BC0(char *, ...);
extern PtObj2 *func_01B03300(void *, void *);
extern float func_002D56C0(float);
extern void func_002DD998(float *, float *, float);
extern int func_002EFD78(void);

void func_01B01850(void *pool, void *tex, float *pos, float *dir)
{
    float v[4];
    float s;
    PtObj2 *p = func_01B03300(pool, tex);
    if (p == 0) {
        func_01B02BC0(D_01B037B0);
        return;
    }
    func_002DD998(v, dir, (((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f) * 0.1f + 0.1f);
    p->w34 = 24;
    p->w30 = 24;
    p->w38 = 12;
    p->f10 = pos[0] + (((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f);
    p->f14 = pos[1] + (((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f);
    p->f18 = pos[2] + (((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f);
    p->f20 = v[0];
    p->f24 = v[1];
    p->f28 = v[2];
    p->f74 = func_002D56C0(((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 360.0f);
    p->w90 = 0x81;
    p->w94 = 0x86;
    p->w98 = 0x8D;
    p->w9C = 0x08;
    p->wA0 = 0x71;
    p->wA4 = 0x84;
    p->wA8 = 0xA7;
    p->wAC = 0;
    s = (((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 0.03125f + 0.0625f) * 1.4f;
    p->fB0 = s;
    p->fB4 = s * 2.0f;
}
