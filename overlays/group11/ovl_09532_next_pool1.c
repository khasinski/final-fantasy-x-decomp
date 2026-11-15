#include "common.h"
typedef struct AnimFrame { s16 offset; s16 duration; int unused; } AnimFrame;
typedef struct AnimData { int unused0; s16 count; u8 pad6[10]; AnimFrame frames[1]; } AnimData;
typedef struct AnimState {
    AnimData *data; AnimFrame *frame; s16 index; s16 padA; void *image; s16 timer; u8 pad12[14];
    float pos[4]; float scale; float rotation; int r,g,b; float alpha; u8 pad48[8];
} AnimState;
typedef struct Particle {
    int active; u8 pad4[12]; float pos[4]; float velocity[4]; int life, remaining, flags; int pad3C;
    AnimState anim; int color0[4]; int color1[4]; float scale0,scale1; u8 padB8[8];
} Particle;
typedef struct Pool {
    int count; Particle *items; u8 pad8[8]; int gravity_on; float gravity; int drag_on; float drag; int matrix_on; u8 pad24[12]; float matrix[16];
} Pool;
void *func_002EF0D0(void *,int,int);
void func_002DD0C0(void *,void *);
void func_002DD0B0(void *,void *);
void func_002DCE08(void *,void *,void *);
double func_002ED038(float);
double func_002E9290(double);
float func_002EC440(double);
void func_01B01420(AnimState *, AnimData *);
int func_01B014A8(AnimState *, void *, int, float);
void func_01B01698(Particle *,AnimData *);
void func_01B016F8(Particle *);
int func_01B01728(Particle *);

void func_01B01698(Particle *p, AnimData *a)
{
    p->active = 1;
    p->remaining = 60;
    func_01B01420(&p->anim,a);
    p->pos[0] = 0.0f;
    p->pos[1] = 0.0f;
    p->pos[2] = 0.0f;
    p->pos[3] = 1.0f;
    p->velocity[0] = 0.0f;
    p->velocity[1] = 0.0f;
    p->velocity[2] = 0.0f;
    p->velocity[3] = 0.0f;
}

void func_01B016F8(Particle *p)
{
    func_002EF0D0(p,0,0xC0);
    p->active = 0;
}
