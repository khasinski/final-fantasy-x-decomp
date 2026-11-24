#include "common.h"

typedef struct {
    u8 pad00[0x10];
    float f10, f14, f18;
    u8 pad1C[0x04];
    float f20, f24, f28;
    int w2C;
    u8 pad30[0x04];
    int w34;
    u8 pad38[0x38];
    float f70;
    float f74;
    int w78, w7C, w80;
    u8 pad84[0x3C];
} PtObj;

extern char D_01B04028[];

extern int func_01B03408(char *, ...);
extern PtObj *func_01B03B48(void *, void *);
extern float func_002D56C0(float);
extern void func_002DD998(float *, float *, float);
extern int func_002EFD78(void);

PtObj *func_01B01658(void *pool, void *tex, float *pos)
{
    PtObj *p = func_01B03B48(pool, tex);
    if (p == 0) {
        func_01B03408(D_01B04028);
        return 0;
    }
    p->w34 = 32;
    p->f10 = pos[0] + (((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f) * 7.5;
    p->f14 = pos[1] + (((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f) * 7.5;
    p->f18 = pos[2] + (((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f) * 7.5;
    p->f20 = -0.04906800017f;
    p->f24 = 0.0f;
    p->f28 = 0.9987949729f;
    p->w2C = 0;
    func_002DD998(&p->f20, &p->f20, 0.5f);
    p->f74 = func_002D56C0(((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 360.0f);
    p->f70 = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 0.005625 + 0.001;
    p->w78 = 0x80;
    p->w7C = 0x80;
    p->w80 = 0x80;
    return p;
}

PtObj *func_01B018D0(void *pool, void *tex, float *pos)
{
    PtObj *p = func_01B03B48(pool, tex);
    if (p == 0) {
        func_01B03408(D_01B04028);
        return 0;
    }
    p->w34 = 32;
    p->f10 = pos[0] + (((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f) * 4.549999833106995;
    p->f14 = pos[1] + (((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f) * 4.549999833106995;
    p->f18 = pos[2] + (((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f) * 4.549999833106995;
    p->f20 = -0.04906800017f;
    p->f24 = 0.0f;
    p->f28 = 0.9987949729f;
    p->w2C = 0;
    func_002DD998(&p->f20, &p->f20, 0.5f);
    p->f20 += (((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f) * 0.5f;
    p->f24 += (((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f) * 0.5f;
    p->f28 += (((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f) * 0.5f;
    p->f74 = func_002D56C0(((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 360.0f);
    p->f70 = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 0.005 + 0.001;
    p->w78 = 0x80;
    p->w7C = 0x80;
    p->w80 = 0x80;
    return p;
}
