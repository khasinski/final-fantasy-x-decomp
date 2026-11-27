#include "common.h"

typedef struct AnimFrame { s16 offset; s16 duration; int unused; } AnimFrame;
typedef struct AnimData { int unused0; s16 count; u8 pad6[10]; AnimFrame frames[1]; } AnimData;
typedef struct AnimState {
    AnimData *data; AnimFrame *frame; s16 index; s16 padA; void *image; s16 timer; u8 pad12[14];
    float pos[4]; float scale; float rotation; int r, g, b; float alpha; u8 pad48[8];
} AnimState;
typedef struct Particle {
    int active; u8 pad4[12]; float pos[4]; float velocity[4]; int life, remaining, flags; int pad3C;
    AnimState anim; int color0[4]; int color1[4]; float scale0, scale1; u8 padB8[8];
} Particle;
typedef struct Pool {
    int count; Particle *items; u8 pad8[8]; int gravity_on; float gravity; int drag_on; float drag; int matrix_on; u8 pad24[12]; float matrix[16];
} Pool;

int func_01B045C8(Pool *p)
{
    int i;
    int n = 0;
    Particle *q = p->items;
    for (i = 0; i < p->count; i++, q++) {
        if (q->active != 0) n++;
    }
    return n;
}
