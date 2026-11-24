#include "common.h"

typedef struct {
    u8 pad00[0x10];
    float f10, f14, f18;
    u8 pad1C[0x04];
    float f20, f24, f28;
    u8 pad2C[0x08];
    int w34;
    u8 pad38[0x38];
    float f70;
    u8 pad74[0x04];
    int w78, w7C, w80;
    float f84;
    u8 pad88[0x38];
} PtObj;

extern char D_01B037B0[];

extern int func_01B02BC0(char *, ...);
extern PtObj *func_01B03300(void *, void *);
extern void func_002DD998(float *, float *, float);
extern int func_002EFD78(void);

void func_01B013C8(void *pool, void *tex, float *pos, float *dir)
{
    float v[4];
    PtObj *p = func_01B03300(pool, tex);
    if (p == 0) {
        func_01B02BC0(D_01B037B0);
        return;
    }
    func_002DD998(v, dir, (((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f) + 1.902639031f);
    p->w34 = 16;
    p->f10 = pos[0] + (((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f) * 1.5;
    p->f14 = pos[1] + (((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f) * 1.5;
    p->f18 = pos[2] + (((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f) * 1.5;
    p->f20 = v[0];
    p->f24 = v[1];
    p->f28 = v[2];
    p->f70 = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 0.00625f + 0.001;
    p->w78 = 0x80;
    p->w7C = 0x80;
    p->w80 = 0x80;
    p->f84 = 1.0f;
}
