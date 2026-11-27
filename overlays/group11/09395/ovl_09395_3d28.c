#include "common.h"

typedef struct AnimFrame { s16 offset; s16 duration; int unused; } AnimFrame;
typedef struct AnimData { int unused0; s16 count; u8 pad6[10]; AnimFrame frames[1]; } AnimData;
typedef struct AnimState {
    AnimData *data; AnimFrame *frame; s16 index; s16 padA; void *image; s16 timer; u8 pad12[14];
    float pos[4]; float scale; float rotation; int r, g, b; float alpha; u8 pad48[8];
} AnimState;

void *func_002EF0D0(void *, int, int);

void func_01B03D28(AnimState *p, AnimData *a)
{
    func_002EF0D0(p, 0, 0x50);
    p->data = a;
    p->frame = a->frames;
    p->image = (void *)(a->frames[0].offset + (int)a);
    p->timer = a->frames[0].duration;
    p->pos[0] = 0.0f;
    p->pos[1] = 0.0f;
    p->pos[2] = 0.0f;
    p->pos[3] = 1.0f;
    p->scale = 1.0f;
    p->r = p->g = p->b = 128;
    p->alpha = 1.0f;
}
