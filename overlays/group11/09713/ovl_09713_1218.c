#include "common.h"

typedef struct {
    u8 pad00[0x10];
    float pos[4];
    float vel[4];
    int max_life;
    int life;
    int flags;
    u8 pad3c[0x34];
    float scale;
    float rot;
    int rgb[3];
} PartItem;

extern float D_01B00830;
extern float D_01B00838;
extern float D_01B00840;
extern float D_01B00848;
extern char D_01B049E8[];

extern int func_01B027D8(char *, ...);
extern PartItem *func_01B02F30(void *, void *);
extern float func_002D56C0(float);
extern int func_002EFD78(void);

void func_01B01218(void *a0, void *a1, float *a2)
{
    PartItem *p;

    p = func_01B02F30(a0, a1);
    if (p == 0) {
        func_01B027D8(D_01B049E8);
        return;
    }
    p->flags = 2;
    p->max_life = p->life = (int)D_01B00838;
    p->pos[0] = a2[0] + D_01B00848 * ((((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f);
    p->pos[1] = a2[1] + D_01B00848 * ((((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f);
    p->pos[2] = a2[2] + D_01B00848 * ((((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f);
    p->vel[0] = D_01B00840 * ((((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f);
    p->vel[1] = D_01B00840 * ((((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f);
    p->vel[2] = D_01B00840 * ((((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f);
    p->rot = func_002D56C0(((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 360.0f);
    p->scale = D_01B00830 * 0.899999976f + (D_01B00830 * 0.100000001f) * ((float)(func_002EFD78() & 0x7FFF) / 32767.0f);
    p->rgb[0] = 0xFF;
    p->rgb[1] = 0x20;
    p->rgb[2] = 0x20;
}
